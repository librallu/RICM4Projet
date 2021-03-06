In the previous week we had problems with shedskin. It have a 
strong dependance of the garbage collector and other python libraries.

It's problematic because it's to heavy to run on the ESP8266.

Some ways are possible :

- Making C/C++ modules that do nothing to replace calls to the garbage
  collector

- Implement an another Python to C++ compiler that runs a subset of python
  and translates it to c++


Python AST module
=================

With the python AST module, it's possible to parse and generate the Abstract
Syntax Tree of the input python program.

In our tests, we will work with the following python program :

.. code-block:: python

	l = [1,2,3]
	for i in l:
		print("hello {} !".format(i))

We can display the AST with the following code :

.. code-block:: python

	import ast


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

.. parsed-literal::
	Module(body=[Assign(targets=[Name(id='l', ctx=Store())], 
	value=List(elts=[Num(n=1), Num(n=2), Num(n=3)], ctx=Load())), 
	For(target=Name(id='i', ctx=Store()), iter=Name(id='l', ctx=Load()), 
	body=[Expr(value=Call(func=Name(id='print', ctx=Load()), 
	args=[Call(func=Attribute(value=Str(s='hello {} !'), 
	attr='format', ctx=Load()), args=[Name(id='i', ctx=Load())], 
	keywords=[], starargs=None, kwargs=None)], keywords=[], 
	starargs=None, kwargs=None))], orelse=[])])


With the module *astmonkey* , it's possible to generate a graphical tree
of parsing. 


The following code will generate the graphical AST :

.. code-block:: python

	from astmonkey import visitors, transformers
	
	source = """
	l = [1,2,3]
	for i in l:
		print("hello {} !".format(i))
	"""

	node = ast.parse(source)
	node = transformers.ParentNodeTransformer().visit(node)
	visitor = visitors.GraphNodeVisitor()
	visitor.visit(node)

	visitor.graph.write_png('graph.png')


We get the following output :

.. figure:: graph.png
	:alt: Graphical output of the AST
	:width: 90%

	Graphical output of the AST for the example program.



Now, we have a AST, it's possible to make some optimisations (with the *AST Optimizer* project),
That returns an equivalent AST that is optimized.

The next step is to make an interpreter that reads the AST and generate C++
code. If we continue on the C++ generation path, we can begin by adding
some native types in C++ like integers, Strings and lists because they
are widely used in python.

With this, we can make some python modules and python primitives to 
run the ESP features in python.

It will be a very restricted subset of python, therefore, it will be simple
and it will be possible to add some features in the future versions of the project.


To make human readable C++ outputs, it's possible to use the *indent* unix command
that indent properly a C/C++ file. 



Command to add the SDK in the compilation process
-------------------------------------------------

xtensa-lx106-elf-g++ -I/home/librallu/esp8266/esp-open-sdk/sdk/include -L/home/librallu/esp8266/esp-open-sdk/sdk/lib


Installation process
--------------------

- mkdir ~/esp8266/
- cp ~/esp8266/
- git clone https://github.com/pfalcon/esp-open-sdk
- sudo apt-get install make unrar autoconf automake libtool gcc g++ gperf \
    flex bison texinfo gawk ncurses-dev libexpat-dev python sed
- make STANDALONE=y
- cd esp-open-sdk/esptool
- sudo python setup.py install
- cd ~/esp8266
- git clone https://github.com/tommie/esptool-ck.git
- cd esptool-ck
- make




Shedskin module generation
==========================

This section enacts as a personnal note as much as a notice for further works on this project.

In order to clarify any further creation of module you can found below the sequence explained:

	- First: create a python file containing function interface only,
	example of a function with one argument returning a list
		def dummy_fun(toto):
			return[1]
	this is to help shedskin to perform a part of type inference (return type, here a list).
	
	- Next: create a simple python program with your function to make 
	shedskin able to perform the full type analysis (arguments),
	
	- Then: compile your python file containing your little program
	with the command shedskin -e my_program.py, this command will generate
	a my_program.cpp, my_program.hpp, and a makefile.
	
	- Finally you can complete the .cpp and .hpp with your personnal code
	implementing functions interfaces in C++
	

Useful Links
============

- https://pypi.python.org/pypi/astmonkey/0.1.1
- https://bitbucket.org/haypo/astoptimizer
- https://code.google.com/p/shedskin/wiki/docs#Compiling_a_Stand-Alone_Program
