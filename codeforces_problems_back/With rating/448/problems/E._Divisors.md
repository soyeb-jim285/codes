<h1 style='text-align: center;'> E. Divisors</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Bizon the Champion isn't just friendly, he also is a rigorous coder.

Let's define function *f*(*a*), where *a* is a sequence of integers. Function *f*(*a*) returns the following sequence: first all divisors of *a*1 go in the increasing order, then all divisors of *a*2 go in the increasing order, and so on till the last element of sequence *a*. For example, *f*([2, 9, 1]) = [1, 2, 1, 3, 9, 1].

Let's determine the sequence *X**i*, for integer *i* (*i* ≥ 0): *X*0 = [*X*] ([*X*] is a sequence consisting of a single number *X*), *X**i* = *f*(*X**i* - 1) (*i* > 0). For example, at *X* = 6 we get *X*0 = [6], *X*1 = [1, 2, 3, 6], *X*2 = [1, 1, 2, 1, 3, 1, 2, 3, 6].

Given the numbers *X* and *k*, find the sequence *X**k*. As the answer can be rather large, find only the first 105 elements of this sequence.

## Input

A single line contains two space-separated integers — *X* (1 ≤ *X* ≤ 1012) and *k* (0 ≤ *k* ≤ 1018).

## Output

Print the elements of the sequence *X**k* in a single line, separated by a space. If the number of elements exceeds 105, then print only the first 105 elements.

## Examples

## Input


```
6 1  

```
## Output


```
1 2 3 6   

```
## Input


```
4 2  

```
## Output


```
1 1 2 1 2 4   

```
## Input


```
10 3  

```
## Output


```
1 1 1 2 1 1 5 1 1 2 1 5 1 2 5 10   

```


#### tags 

#2200 #brute_force #dfs_and_similar #implementation #number_theory 