<h1 style='text-align: center;'> H. Stack</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In this problem we'll use a stack which supports two types of operations:

* Push a given number on the stack.
* Pop two numbers from the stack, perform a given operation (addition or multiplication) on them and push the result on the stack.

You are given a string which describes the sequence of operations to be performed on the stack. *i*-th character corresponds to *i*-th operation:

* If *i*-th character is a digit, push the corresponding number on the stack.
* If *i*-th character is «+» or «*», perform the corresponding operation.

Initially the stack is empty. ## Output

 the topmost number on the stack after executing all given operations.

## Input

The only line of input contains a string of operations, consisting of characters «+», «*» and digits (0..9). The length of the string will be between 1 and 20 characters, inclusive.

The given sequence of operations is guaranteed to be correct, i.e. the stack will have at least two elements before every math operation. The numbers on the stack will never exceed 106. 

## Output

## Output

 a single number — the topmost element of the stack after performing all given operations.

## Examples

## Input


```
12+3*66*+  

```
## Output


```
45  

```
## Input


```
149  

```
## Output


```
9  

```
## Note

In the first case the stack will end up containing a single number — the result of calculating (1+2)*3+6*6.

In the second case there are no math operations, so the answer will be the last number pushed on the stack.



#### tags 

#1800 #*special #expression_parsing #implementation 