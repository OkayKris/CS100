

# CS 100 Programming Project
## By John Huh (862013504) and Kristian De Castro (862025678)

# Introduction

~~We are developing a command shell that displays a command prompt for users to input commands that they want to execute. Commands can be separated by connectors (eg "||", "&&", or ";") which influence how they run. We will be using the composite pattern to represent the commands and operators in our program so that there will be no limit to the number of commands that can be chained together.~~

~~This time, we built upon our previously developed command shell that could take in commands and be separated by connectors, and added functionality with precedence, and the test command.  In this assignment, all we did was modify our makeTree function in the commandinput class to include precedence functionality.  For the test command, we created a new "test" class that interacts with the Connector class to perform the test command.~~

*UPDATE (6/9/19): Assignment 4*
Further expanding on our command shell, we now implemented the ability for input and output redirection. By manipulating the Connector class, we are able to add stream redirection to write standard output to a file and read from a file to standard input. We are also able to pipe commands, take the output of one command to become the input of another, for further processing.

#  Diagram
![UMLassn3](https://user-images.githubusercontent.com/46543413/58392691-1acc8380-7ff0-11e9-9dd4-583763729c35.jpg)


# Classes
~~1. Base
	* The base class is the foundation in which it declares the interface and the default behavior for its inherited classes~~
~~2. Rshell
	* Rshell is the command prompt that prompts the user with the "$" symbol. Users will type their commands here and press enter to execute~~
1. Connector
	* The connector class is the foundation for the 3 connectors that influence how commands are run
	* Also has the execute function which executes the stored command string, using execvp, waitpid, and fork
	1. AndCon (&&): This class allows the next command to execute only if the command preceding it succeeds
	* Has 2 pointers, one left and the other right to iterate down the tree
	2. OrCon (||): This class allows the next command to execute only if the command preceding it fails
	* Same as above
	3. PipeCon (|): This class allows the output of one command to be redirected to the input of another
	* This class utilizes the `pipe()` and `dup2()` functions to chain the output of one command to be the input of another
	4. ~~SemiCon (;): This class allows the command following a semicolon to always execute~~
2. CommandInput
	* This class takes in and stores commands from the input in assn2.cpp in its constructor and allows them to be evaluated and executed separated into a string vector when ecountering a semicolon
	* Has a makeTree Connector* function that takes in a full command string then iterates backwords through the string to create a root node pointer of Connector* class
	* In addition, we added an if statement case that recognizes precedence when a closed parenthesis is found in the user input.
3. test
	* This class taken in the written argument list from the Connector execute function and uses it to execute the test command when the executable string is equal to "test".
4. Redirector
	* This class controls the Input and Output Redirectors 
	* Includes its own execute function
	1. Overwrite redirector `>`
		* The overwrite redirector writes standard output to a file
	2. Addon redirector `>>`
		* The addon redirector appends standard output to a file
	3. Input redirector `<`
		* The input redirector reads from a file to standard output
#  Development & Testing Roadmap
####  ***Overview***
With this program, we want to create a terminal that can:
1. Output a command prompt to take in user commands
2. Read and evaluate the user command input
3. Execute the command using `waitpid`, `fork`, and `execvp` 
4. Recognize when and how to execute the test command
5. Recognize and execute precedence

#### ***Breakdown***
- [x] Build the test class
- [x] Implement it into the connector execute function
- [x] Implement parenthesis recognition in the makeTree function
- [x] Test precedence and test making sure they work individually and together
- [x] Create integration tests
- [x] Create google tests

#### ***Changelog***
- Removed SemCon subclass 
- Removed Prototypes/Research
- Removed RShell class and base classes
- Added Pipe Connector class
- Added Redirection superclass and overwrite (>), addon (>>), read (<) subclasses
- Updated Connector class to look for redirection cases
- Updated Readme according to assignment 4
