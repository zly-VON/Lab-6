*Lab 6, OOP*

# Store Simulation

Declared Classes:
* Tracker
* Store
* CustomerData
* Customer
* EmployeeData
* Employee
* Item
* Food
* Drink

## NEW
Now my simulation is a real simulation, it runs infinetely until I stop it. And when it is stopped, the statistcs about everything happened in the store 
will be shown.


## SOLID Principles
* Single-responsibility principle (SRP)
* Open-closed principle (OCP)
* Liskov substitution principle (LSP)
* Interface segregation principle (ISP)
* Dependency inversion Principle (DIP)

Given that some of the principles were already present in my code, I concentrated to implement the other.

Firstly, my code didn't respect the single-responsabilty principle. For example, Class store was responsible about the store finances and to track everything that 
happens in the store. So, I created another class responsible only for the things that happens inside the store. Other problem was that the class, for 
example the customer one, had some methods that should have been implemented by the employee class. Therefore I did the necessary changes in my code.

Next, I dismantled the chain of inheritance we had to do in some previous laboratory works. Instead I created where necessary some abstract classes. 
Now my classes don't depend on other concrete classes but on abstract classes.

Given that I hadn't any interface, just abstract classes, in my code, I did need to be worried about the interface segregation principle.
Also, my code respects the open-close principle, I can add, and I experienced doing it, new methods to my class without the need to modify old ones. 


## Design Patterns
* Builder
* Bridge

These are the main design pattern my code actually follows. There are also other ones that are followed, but I didn't mentioned them because they 
aren't respected at 100%.

## Refactoring 
The last things I made to make my code cleaner and understandable was refactoring.
Firstly, I divided my many lines of code in more files. So, that every class would have its own file. I eliminated the redundant lines, or wrote the same
logic of some of them in significantly less lines. Also, for the parts where the same code was repeated I created separate functions. 

I tried my best to structure logically my code.
