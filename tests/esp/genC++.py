import ast
from astoptimizer import Config, parse_ast, optimize_ast, compile_ast


# python name <-> C++ name
pythonToCppNames = {
	'high':	'HIGH',
	'down': 'DOWN',
	'gpio2_set': 'GPIO2_SET',
	'gpio2_toggle': 'GPIO2_TOGGLE',
	'wait': 'WAIT',
}

espConstants = {'high', 'down'}


# pass on constants
# return true if the constant is iterable, false elsewhere
def isIterable(node):
	if isinstance(node, ast.List):
		return True
	else:
		return False


# return the type of a node
def pythonToCppType(node):
	if isinstance(node, ast.List):
		content = pythonToCppType(node.elts[0])
		return 'std::vector<{}>'.format(content)
	if isinstance(node, ast.Num):
		return 'int'
	return "undifinedType"


	
	


class Test(ast.NodeVisitor):
		
	def __init__(self):
		pass
		
	# renders a espModule call in python to syscall in C++
	def espModule(self, node, name, args=None):
		res = ""
		res += pythonToCppNames[name]
			
		if ( args != None and name not in espConstants): # if negative, it's a constant
			res += "("
			l = [self.visit(i) for i in args]
			res += ", ".join(l)
			res += ")"
		return res
		
	def visit(self, node, name=""):
		res = ""
		if isinstance(node, ast.Assign):
			res+=self.visit_Assign(node)
		elif isinstance(node, ast.If):
			res+=self.visit_If(node)
		elif isinstance(node, ast.For):
			res+=self.visit_For(node)
		elif isinstance(node, ast.Name):
			res+=self.visit_Name(node)
		elif isinstance(node, ast.List):
			res+=self.visit_List(node, node.elts[0], name)
		elif isinstance(node, ast.Tuple):
			res+=self.visit_List(node, node.elts[0], name)
		elif isinstance(node, ast.Subscript):
			res+=self.visit_Subscript(node)
		elif isinstance(node, ast.Index):
			res+=self.visit(node.value)
		elif isinstance(node, ast.Expr):
			res+=self.visit_Expr(node)
		elif isinstance(node, ast.Num):
			res+=self.visit_Num(node)
		elif isinstance(node, ast.While):
			res+=self.visit_While(node)
		elif isinstance(node, ast.Compare):
			res+=self.visit_Compare(node)
		elif isinstance(node, ast.BinOp):
			res+=self.visit_BinOp(node)
		elif isinstance(node, ast.AugAssign):
			res+=self.visit_AugAssign(node)
		elif isinstance(node, ast.Attribute):
			res+=self.visit_Attribute(node)
		elif isinstance(node, ast.Call):
			res+=self.visit_Call(node)
		elif isinstance(node, ast.Module):
			pass
		else:
			return "[[[ERROR : {} not found]]]".format(node)
		return res
		
	def visit_If(self, node):
		res=""
		res+="if({})".format(self.visit(node.test))
		res+="{\n"
		res+=self.visit(node.body[0])
		res+="} else {\n"
		res+=self.visit(node.orelse[0])
		res+="}\n"
		return res
			
	def visit_Attribute(self, node, args=None):
		res = ""
		if self.visit(node.value) == "esp":
			res += self.espModule(node.value, node.attr,args)
		else:
			res += "[[[UNKNOWN MODULE {}]]]".format(self.visit(node.value))
		return res
			
	def visit_Name(self, node):
		res = ""
		res += "{}".format(node.id)
		return res
		
	def visit_Subscript(self, node):
		res = ""
		res += node.value.id+"["
		res += self.visit(node.slice)
		res += "]"
		return res
		
	def visit_List(self, node, elt, name):
		res = ";\n"
		for i in node.elts:
			res += "{}.push_back({});\n".format(name,self.visit(i))
		return res
		
	def visit_Num(self, node):
		res = "{}".format(node.n)
		return res
			
	def visit_Assign(self, node):
		res = ""
		for i in node.targets:
			cpptype = pythonToCppType(node.value)
			if isIterable(node.value):
				res += "{} {} {}\n".format(cpptype, self.visit(i), self.visit(node.value, self.visit(i)))
			else:
				res += "{} {} = {};\n".format(cpptype, self.visit(i), self.visit(node.value))
		return res
		
	def visit_For(self, node):
		res = "[TODO]\n"
		return res
		
	def visit_While(self, node):
		res = ""
		res += "while("
		res += self.visit(node.test)
		res += "){\n"
		for i in node.body:
			res += self.visit(i)
		res += "}"
		return res
		
	def visit_Compare(self, node):
		res = ""
		res += self.visit(node.left)
		res += " {} ".format(self.get_op(node.ops[0]))
		res += self.visit(node.comparators[0])
		return res
		
	def visit_Expr(self, node):
		res = ""
		res += self.visit(node.value)
		return res
		
	def visit_Call(self, node):
		res = ""
		if isinstance(node.func, ast.Attribute): # if we are in a module
			res += self.visit_Attribute(node.func, node.args)
		else:
			res += "[[[Visit_Expr TODO]]]"
		res += ";\n"
		return res
		
	def visit_AugAssign(self, node):
		res = ""
		res += node.target.id
		res += " "+self.get_op(node.op)+"= "
		res += self.visit_Num(node.value)
		return res +";"
		
	def get_op(self, node):
		if ( isinstance(node, ast.Lt) ):
			return "<"
		if ( isinstance(node, ast.Add) ):
			return "+"
		if ( isinstance(node, ast.Mult) ):
			return "*"
		if ( isinstance(node, ast.Mod) ):
			return "%"
		else:
			return "[TODO]"
		
	def visit_BinOp(self, node):
		res = ""
		res += self.visit(node.left)
		res += " {} ".format(self.get_op(node.op))
		res += self.visit(node.right)
		return res
	
	def visit_Module(self, node):
		res = """
#include <vector>
#include "syscall.h"
#include "interface.h"

int main(){
		"""
		for i in ast.iter_child_nodes(node):
			res += self.visit(i)
		res += """
	return 0;
}	
"""
		return res


def draw_ast(t,f):
	from astmonkey import visitors, transformers
	node = ast.parse(source)
	node = transformers.ParentNodeTransformer().visit(node)
	visitor = visitors.GraphNodeVisitor()
	visitor.visit(node)
	visitor.graph.write_png(f)



if __name__ == "__main__":
	import sys
	if len(sys.argv) != 2:
		print("usage : genC++.py sourceFile.py")
	else:
		t = Test()
		config = Config('builtin_funcs', 'pythonbin')
		
		# read source file
		sourceFile = open(sys.argv[1], "r")
		source = "\n".join(sourceFile.readlines())
		sourceFile.close()
		tree = parse_ast(source)
		#~ draw_ast(source, "a.png")
		tree = optimize_ast(tree, config)
		#~ draw_ast(tree, "b.png")
		print(t.visit_Module(tree))


