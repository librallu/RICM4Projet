
source = """
l = k = [1,2,3]
i = a = 0
while i < 2+1*2:
	a = a+1
"""

import ast
from astoptimizer import Config, parse_ast, optimize_ast, compile_ast
#~ from astmonkey import visitors, transformers


class Test(ast.NodeVisitor):
	
	def __init__(self):
		pass
		
	
		
	def visit(self, node):
		res = ""
		if isinstance(node, ast.Assign):
			res+=self.visit_Assign(node)
		elif isinstance(node, ast.For):
			res+=self.visit_For(node)
		elif isinstance(node, ast.Name):
			res+=self.visit_Name(node)
		elif isinstance(node, ast.List):
			res+=self.visit_List(node)
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
		elif isinstance(node, ast.Module):
			pass
		else:
			print("[[[ERROR : {} not found".format(node))
		return res
			
	def visit_Name(self, node):
		res = ""
		res += "{}".format(node.id)
		return res
		
	def visit_List(self, node):
		res = "["
		for i in node.elts:
			res += "{}, ".format(self.visit(i))
		res += "]"
		return res
		
	def visit_Num(self, node):
		res = "{}".format(node.n)
		return res
			
	def visit_Assign(self, node):
		res = ""
		for i in node.targets:
			res += "{} = {};\n".format(self.visit(i), self.visit(node.value))
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
		
		return res
		
	def get_op(self, node):
		if ( isinstance(node, ast.Lt) ):
			return "<"
		if ( isinstance(node, ast.Add) ):
			return "+"
		if ( isinstance(node, ast.Mult) ):
			return "*"
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
#include <cstdio>
#include <list>

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
	visitor = visitors.GraphNodeVisitor()
	visitor.visit(t)
	visitor.graph.write_png(f)


t = Test()
config = Config('builtin_funcs', 'pythonbin')
tree = parse_ast(source)
#~ draw_ast(tree, "a.png")
tree = optimize_ast(tree, config)
#~ draw_ast(tree, "b.png")
print(t.visit_Module(tree))


