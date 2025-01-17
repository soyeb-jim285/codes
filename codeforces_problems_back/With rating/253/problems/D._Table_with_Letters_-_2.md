<h1 style='text-align: center;'> D. Table with Letters - 2</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya has recently started to learn English. Now he needs to remember how to write English letters. He isn't sure about some of them, so he decided to train a little.

He found a sheet of squared paper and began writing arbitrary English letters there. In the end Vasya wrote *n* lines containing *m* characters each. Thus, he got a rectangular *n* × *m* table, each cell of the table contained some English letter. Let's number the table rows from top to bottom with integers from 1 to *n*, and columns — from left to right with integers from 1 to *m*.

After that Vasya looked at the resulting rectangular table and wondered, how many subtables are there, that matches both following conditions:

* the subtable contains at most *k* cells with "a" letter;
* all letters, located in all four corner cells of the subtable, are equal.

 Formally, a subtable's definition is as follows. It is defined by four integers *x*1, *y*1, *x*2, *y*2 such that 1 ≤ *x*1 < *x*2 ≤ *n*, 1 ≤ *y*1 < *y*2 ≤ *m*. Then the subtable contains all such cells (*x*, *y*) (*x* is the row number, *y* is the column number), for which the following inequality holds *x*1 ≤ *x* ≤ *x*2, *y*1 ≤ *y* ≤ *y*2. The corner cells of the table are cells (*x*1, *y*1), (*x*1, *y*2), (*x*2, *y*1), (*x*2, *y*2).

Vasya is already too tired after he's been writing letters to a piece of paper. That's why he asks you to count the value he is interested in.

## Input

The first line contains three integers *n*, *m*, *k* (2 ≤ *n*, *m* ≤ 400; 0 ≤ *k* ≤ *n*·*m*).

Next *n* lines contain *m* characters each — the given table. Each character of the table is a lowercase English letter.

## Output

Print a single integer — the number of required subtables.

## Examples

## Input


```
3 4 4  
aabb  
baab  
baab  

```
## Output


```
2  

```
## Input


```
4 5 1  
ababa  
ccaca  
ccacb  
cbabc  

```
## Output


```
1  

```
## Note

There are two suitable subtables in the first sample: the first one's upper left corner is cell (2, 2) and lower right corner is cell (3, 3), the second one's upper left corner is cell (2, 1) and lower right corner is cell (3, 4).



#### tags 

#2000 #brute_force #two_pointers 