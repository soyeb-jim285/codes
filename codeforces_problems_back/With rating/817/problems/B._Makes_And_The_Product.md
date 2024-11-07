<h1 style='text-align: center;'> B. Makes And The Product</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

After returning from the army Makes received a gift — an array *a* consisting of *n* positive integer numbers. He hadn't been solving problems for a long time, so he became interested to answer a particular question: how many triples of indices (*i*,  *j*,  *k*) (*i* < *j* < *k*), such that *a**i*·*a**j*·*a**k* is minimum possible, are there in the array? Help him with it!

## Input

The first line of input contains a positive integer number *n* (3 ≤ *n* ≤ 105) — the number of elements in array *a*. The second line contains *n* positive integer numbers *a**i* (1 ≤ *a**i* ≤ 109) — the elements of a given array.

## Output

Print one number — the quantity of triples (*i*,  *j*,  *k*) such that *i*,  *j* and *k* are pairwise distinct and *a**i*·*a**j*·*a**k* is minimum possible.

## Examples

## Input


```
4  
1 1 1 1  

```
## Output


```
4  

```
## Input


```
5  
1 3 2 3 4  

```
## Output


```
2  

```
## Input


```
6  
1 3 3 1 3 2  

```
## Output


```
1  

```
## Note

In the first example Makes always chooses three ones out of four, and the number of ways to choose them is 4.

In the second example a triple of numbers (1, 2, 3) is chosen (numbers, not indices). Since there are two ways to choose an element 3, then the answer is 2.

In the third example a triple of numbers (1, 1, 2) is chosen, and there's only one way to choose indices.



#### tags 

#1500 #combinatorics #implementation #math #sortings 