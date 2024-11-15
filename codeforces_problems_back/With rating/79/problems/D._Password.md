<h1 style='text-align: center;'> D. Password</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Finally Fox Ciel arrived in front of her castle!

She have to type a password to enter her castle. An input device attached to her castle is a bit unusual.

The input device is a 1 × *n* rectangle divided into *n* square panels. They are numbered 1 to *n* from left to right. Each panel has a state either ON or OFF. Initially all panels are in the OFF state. She can enter her castle if and only if *x*1-th, *x*2-th, ..., *x**k*-th panels are in the ON state and other panels are in the OFF state.

She is given an array *a*1, ..., *a**l*. In each move, she can perform the following operation: choose an index *i* (1 ≤ *i* ≤ *l*), choose consecutive *a**i* panels, and flip the states of those panels (i.e. ON → OFF, OFF → ON).

Unfortunately she forgets how to type the password with only above operations. Determine the minimal number of operations required to enter her castle.

## Input

The first line contains three integers *n*, *k* and *l* (1 ≤ *n* ≤ 10000, 1 ≤ *k* ≤ 10, 1 ≤ *l* ≤ 100), separated by single spaces.

The second line contains *k* integers *x*1, ..., *x**k* (1 ≤ *x*1 < *x*2 < ... < *x**k* ≤ *n*), separated by single spaces.

The third line contains *l* integers *a*1, ..., *a**l* (1 ≤ *a**i* ≤ *n*), separated by single spaces. It is possible that some elements of the array *a**i* are equal value.

## Output

Print the minimal number of moves required to type the password. If it's impossible, print -1.

## Examples

## Input


```
10 8 2  
1 2 3 5 6 7 8 9  
3 5  

```
## Output


```
2  

```
## Input


```
3 2 1  
1 2  
3  

```
## Output


```
-1  

```
## Note

One possible way to type the password in the first example is following: In the first move, choose 1st, 2nd, 3rd panels and flip those panels. In the second move, choose 5th, 6th, 7th, 8th, 9th panels and flip those panels.



#### tags 

#2800 #bitmasks #dp #shortest_paths 