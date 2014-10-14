Old People. New Challenge. mov pc,lr

### Structural Layout of Program ###
*.h -> 
	class declaration of module.

*.cpp -> 
	class defination of every module.
	Must include processor.h
	must include *.h

	Only variable declaration happens in main.cpp
	
### Naming Conventions ###

	Every Module Contains Content.
	Make accessor, mutator in each.

	Each module contains global function defination & declaration of the Module's control signals.
	Any and all sub-modules required for control signals is extern.
	All externs are allocated memory in main.cpp globally.

	Do not forget to update all files.
