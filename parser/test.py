import ast

from astmonkey import visitors, transformers

def parseprint(code, filename="<string>", mode="exec", **kwargs):
	"""Parse some code from a string and pretty-print it."""
	node = ast.parse(code, mode=mode) # An ode to the code
	print(ast.dump(node, **kwargs))

source = """
l = [1,2,3]
for i in l:
	print("hello {} !".format(i))
"""
parseprint(source)
node = ast.parse(source)
node = transformers.ParentNodeTransformer().visit(node)
visitor = visitors.GraphNodeVisitor()
visitor.visit(node)

visitor.graph.write_png('graph.png')
