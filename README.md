# Expression Evaluator

<br/>

## About
The expression evaluator was my semester project for the Principles of Software Design class at IUPUI (CSCI-36300).
The class consisted of 4 assignments, each one building on the previous assignment. We started in Assignment 1 by
implementing a simple `Array` class, but eventually we built a system that can evaluate arbitrary math expressions.
Each assignment built on the previous one by adding more design patterns and features to the system. This is my final
code after we learned everything in class.

<br/>

## Design Patterns Used
* __Wrapper Facade__ - `Array` class
* __Template Method__  -`Unary` and `Binary` operands
* __Command__ - `Command` class hierarchy
* __Abstract Factory__ - `Flyweight_Expr_Factory` and `Postfix_Expr_Factory`
* __Flyweight__ - `Flyweight_Expr_Factory`
* __Composite__ - `Expr_Node` class hierarchy
* __Visitor__ - `Variable_Getter` and `Variable_Setter`
* __Builder__ - `Postfix_Builder` and `Tree_Builder`
* __Strategy__ - `Math_Expr`

_This is not an exhaustive list_

<br/>

## Compiling

Currently, the program must be compiled with a tool called [MPC](https://github.com/DOCGroup/MPC). The
provided `makefile` automatically builds the makefile with MPC and runs the makefile using the traditional
"make" command. However, you will need to install MPC onto the platform of your choice. Directions to install
MPC are included in its repository.

_I plan to replace MPC with just a traditional makefile in the future_

<br/>

## Usage

Running the program will display the following prompt:
```
Enter Math Expression:
```
Enter the math expression into the console, and press \<Enter\>. It will display the result of the expression below.
__All parts of the expression need to be separated by spaces.__ This was a requirement of the class project to make
the expressions easier to tokenize. So enter: `5 + 4` not `5+4`. The following operators are supported:
* __Addition:__ +
* __Subtraction:__ -
* __Multiplication:__ *
* __Division:__ /
* __Modulus:__ %
* __Parenthesis:__ () and []

The calculator only supports integers, so you cannot type in fractions like `6.2`. However, you can define variables
using the letters a-z and A-Z. When evaluating the expression, the program will prompt you for each variable, in alphabetical
order, before evaluating the expression. The same variable name will evaluate to the same value twice. For example:
```
Enter Math Expression: ( one * TwO + 5 ) / one
Variable "one" = 5
Variable "TwO" = 7
8
```
