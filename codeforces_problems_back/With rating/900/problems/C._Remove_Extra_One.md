<h1 style='text-align: center;'> C. Remove Extra One</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a permutation *p* of length *n*. Remove one element from permutation to make the number of records the maximum possible.

We remind that in a sequence of numbers *a*1, *a*2, ..., *a**k* the element *a**i* is a record if for every integer *j* (1 ≤ *j* < *i*) the following holds: *a**j* < *a**i*. 

## Input

The first line contains the only integer *n* (1 ≤ *n* ≤ 105) — the length of the permutation.

The second line contains *n* integers *p*1, *p*2, ..., *p**n* (1 ≤ *p**i* ≤ *n*) — the permutation. All the integers are distinct.

## Output

Print the only integer — the element that should be removed to make the number of records the maximum possible. If there are multiple such elements, print the smallest one.

## Examples

## Input


```
1  
1  

```
## Output


```
1  

```
## Input


```
5  
5 1 2 3 4  

```
## Output


```
5  

```
## Note

In the first example the only element can be removed.



#### tags 

#1700 #brute_force #data_structures #math 