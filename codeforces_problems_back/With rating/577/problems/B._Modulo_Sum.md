<h1 style='text-align: center;'> B. Modulo Sum</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a sequence of numbers *a*1, *a*2, ..., *a**n*, and a number *m*.

Check if it is possible to choose a non-empty subsequence *a**i**j* such that the sum of numbers in this subsequence is divisible by *m*.

## Input

The first line contains two numbers, *n* and *m* (1 ≤ *n* ≤ 106, 2 ≤ *m* ≤ 103) — the size of the original sequence and the number such that sum should be divisible by it.

The second line contains *n* integers *a*1, *a*2, ..., *a**n* (0 ≤ *a**i* ≤ 109).

## Output

In the single line print either "YES" (without the quotes) if there exists the sought subsequence, or "NO" (without the quotes), if such subsequence doesn't exist.

## Examples

## Input


```
3 5  
1 2 3  

```
## Output


```
YES  

```
## Input


```
1 6  
5  

```
## Output


```
NO  

```
## Input


```
4 6  
3 1 1 3  

```
## Output


```
YES  

```
## Input


```
6 6  
5 5 5 5 5 5  

```
## Output


```
YES  

```
## Note

In the first sample test you can choose numbers 2 and 3, the sum of which is divisible by 5.

In the second sample test the single non-empty subsequence of numbers is a single number 5. Number 5 is not divisible by 6, that is, the sought subsequence doesn't exist.

In the third sample test you need to choose two numbers 3 on the ends.

In the fourth sample test you can take the whole subsequence.



#### tags 

#1900 #combinatorics #data_structures #dp #two_pointers 