Old People. New Challenge. mov pc,lr

### Structural Layout of Program ###
Each register is defined along with setters, and getter type operations only. (Increment and Decrement are debatable.)
ALU is defined with all operations as defined.
Databus is essentially identical to the registers, it just happens to remain connected to a large number of other registers.

Even though duck-type is not support in C++, strict var naming rules will make life easier.

### Naming Conventions ###
All registers will contain only one variable Content,
All registers will have getContent, setContent.
Since int is defined to be the fastest type usable, all operations will be done on ints. unless specified.
Databus transfer logic must be in processor class.

Parent class processor makes objects of each individual register, along with memory object, databus, and alu.

