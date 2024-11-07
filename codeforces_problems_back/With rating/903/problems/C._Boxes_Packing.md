<h1 style='text-align: center;'> C. Boxes Packing</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Mishka has got *n* empty boxes. For every *i* (1 ≤ *i* ≤ *n*), *i*-th box is a cube with side length *a**i*.

Mishka can put a box *i* into another box *j* if the following conditions are met:

* *i*-th box is not put into another box;
* *j*-th box doesn't contain any other boxes;
* box *i* is smaller than box *j* (*a**i* < *a**j*).

Mishka can put boxes into each other an arbitrary number of times. He wants to minimize the number of visible boxes. A box is called visible iff it is not put into some another box.

Help Mishka to determine the minimum possible number of visible boxes!

## Input

The first line contains one integer *n* (1 ≤ *n* ≤ 5000) — the number of boxes Mishka has got.

The second line contains *n* integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 109), where *a**i* is the side length of *i*-th box.

## Output

Print the minimum possible number of visible boxes.

## Examples

## Input


```
3  
1 2 3  

```
## Output


```
1  

```
## Input


```
4  
4 2 4 3  

```
## Output


```
2  

```
## Note

In the first example it is possible to put box 1 into box 2, and 2 into 3.

In the second example Mishka can put box 2 into box 3, and box 4 into box 1.



#### tags 

#1200 #greedy 