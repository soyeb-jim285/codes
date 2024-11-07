<h1 style='text-align: center;'> B. Pashmak and Flowers</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Pashmak decided to give Parmida a pair of flowers from the garden. There are *n* flowers in the garden and the *i*-th of them has a beauty number *b**i*. Parmida is a very strange girl so she doesn't want to have the two most beautiful flowers necessarily. She wants to have those pairs of flowers that their beauty difference is maximal possible!

Your task is to write a program which calculates two things:

1. The maximum beauty difference of flowers that Pashmak can give to Parmida.
2. The number of ways that Pashmak can pick the flowers. Two ways are considered different if and only if there is at least one flower that is chosen in the first way and not chosen in the second way.
## Input

The first line of the input contains *n* (2 ≤ *n* ≤ 2·105). In the next line there are *n* space-separated integers *b*1, *b*2, ..., *b**n* (1 ≤ *b**i* ≤ 109).

## Output

The only line of output should contain two integers. The maximum beauty difference and the number of ways this may happen, respectively.

## Examples

## Input


```
2  
1 2  

```
## Output


```
1 1
```
## Input


```
3  
1 4 5  

```
## Output


```
4 1
```
## Input


```
5  
3 1 2 3 1  

```
## Output


```
2 4
```
## Note

In the third sample the maximum beauty difference is 2 and there are 4 ways to do this:

1. choosing the first and the second flowers;
2. choosing the first and the fifth flowers;
3. choosing the fourth and the second flowers;
4. choosing the fourth and the fifth flowers.


#### tags 

#1300 #combinatorics #implementation #sortings 