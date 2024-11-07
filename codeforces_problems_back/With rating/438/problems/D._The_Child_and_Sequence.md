<h1 style='text-align: center;'> D. The Child and Sequence</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

At the children's day, the child came to Picks's house, and messed his house up. Picks was angry at him. A lot of important things were lost, in particular the favorite sequence of Picks.

Fortunately, Picks remembers how to repair the sequence. Initially he should create an integer array *a*[1], *a*[2], ..., *a*[*n*]. Then he should perform a sequence of *m* operations. An operation can be one of the following:

1. Print operation *l*, *r*. Picks should write down the value of ![](images/181f67ef3e318b079dbb2c95d35947d5188179ce.png).
2. Modulo operation *l*, *r*, *x*. Picks should perform assignment *a*[*i*] = *a*[*i*] *mod* *x* for each *i* (*l* ≤ *i* ≤ *r*).
3. Set operation *k*, *x*. Picks should set the value of *a*[*k*] to *x* (in other words perform an assignment *a*[*k*] = *x*).

Can you help Picks to perform the whole sequence of operations?

## Input

The first line of input contains two integer: *n*, *m* (1 ≤ *n*, *m* ≤ 105). The second line contains *n* integers, separated by space: *a*[1], *a*[2], ..., *a*[*n*] (1 ≤ *a*[*i*] ≤ 109) — initial value of array elements.

Each of the next *m* lines begins with a number *type* ![](images/b4a45bf5e1079434406980c012d730913aef22f2.png). 

* If *type* = 1, there will be two integers more in the line: *l*, *r* (1 ≤ *l* ≤ *r* ≤ *n*), which correspond the operation 1.
* If *type* = 2, there will be three integers more in the line: *l*, *r*, *x* (1 ≤ *l* ≤ *r* ≤ *n*; 1 ≤ *x* ≤ 109), which correspond the operation 2.
* If *type* = 3, there will be two integers more in the line: *k*, *x* (1 ≤ *k* ≤ *n*; 1 ≤ *x* ≤ 109), which correspond the operation 3.
## Output

For each operation 1, please print a line containing the answer. Notice that the answer may exceed the 32-bit integer.

## Examples

## Input


```
5 5  
1 2 3 4 5  
2 3 5 4  
3 3 5  
1 2 5  
2 1 3 3  
1 1 3  

```
## Output


```
8  
5  

```
## Input


```
10 10  
6 9 6 7 6 1 10 10 9 5  
1 3 9  
2 7 10 9  
2 5 10 8  
1 4 7  
3 3 7  
2 7 9 9  
1 2 4  
1 6 6  
1 5 9  
3 1 10  

```
## Output


```
49  
15  
23  
1  
9  

```
## Note

Consider the first testcase:

* At first, *a* = {1, 2, 3, 4, 5}.
* After operation 1, *a* = {1, 2, 3, 0, 1}.
* After operation 2, *a* = {1, 2, 5, 0, 1}.
* At operation 3, 2 + 5 + 0 + 1 = 8.
* After operation 4, *a* = {1, 2, 2, 0, 1}.
* At operation 5, 1 + 2 + 2 = 5.


#### tags 

#2300 #data_structures #math 