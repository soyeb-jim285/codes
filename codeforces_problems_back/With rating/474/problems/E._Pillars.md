<h1 style='text-align: center;'> E. Pillars</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Marmot found a row with *n* pillars. The *i*-th pillar has the height of *h**i* meters. Starting from one pillar *i*1, Marmot wants to jump on the pillars *i*2, ..., *i**k*. (1 ≤ *i*1 < *i*2 < ... < *i**k* ≤ *n*). From a pillar *i* Marmot can jump on a pillar *j* only if *i* < *j* and |*h**i* - *h**j*| ≥ *d*, where |*x*| is the absolute value of the number *x*.

Now Marmot is asking you find out a jump sequence with maximal length and print it.

## Input

The first line contains two integers *n* and *d* (1 ≤ *n* ≤ 105, 0 ≤ *d* ≤ 109).

The second line contains *n* numbers *h*1, *h*2, ..., *h**n* (1 ≤ *h**i* ≤ 1015).

## Output

The first line should contain one integer *k*, the maximal length of a jump sequence.

The second line should contain *k* integers *i*1, *i*2, ..., *i**k* (1 ≤ *i*1 < *i*2 < ... < *i**k* ≤ *n*), representing the pillars' indices from the maximal length jump sequence.

If there is more than one maximal length jump sequence, print any.

## Examples

## Input


```
5 2  
1 3 6 7 4  

```
## Output


```
4  
1 2 3 5   

```
## Input


```
10 3  
2 1 3 6 9 11 7 3 20 18  

```
## Output


```
6  
1 4 6 7 8 9   

```
## Note

In the first example Marmot chooses the pillars 1, 2, 3, 5 with the heights 1, 3, 6, 4. Another jump sequence of length 4 is 1, 2, 4, 5.



#### tags 

#2000 #binary_search #data_structures #dp #sortings #trees 