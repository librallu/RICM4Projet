import ast

from astmonkey import visitors, transformers

def parseprint(code, filename="<string>", mode="exec", **kwargs):
	"""Parse some code from a string and pretty-print it."""
	node = ast.parse(code, mode=mode) # An ode to the code
	print(ast.dump(node, **kwargs))

source = """
l = k = [1,2,3]
i = a = 0
while i < 3:
	a = a+1
"""
parseprint(source)
node = ast.parse(source)
node = transformers.ParentNodeTransformer().visit(node)
visitor = visitors.GraphNodeVisitor()
visitor.visit(node)
visitor.graph.write_png('graph.png')
