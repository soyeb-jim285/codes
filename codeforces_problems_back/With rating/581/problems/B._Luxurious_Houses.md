<h1 style='text-align: center;'> B. Luxurious Houses</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The capital of Berland has *n* multifloor buildings. The architect who built up the capital was very creative, so all the houses were built in one row.

Let's enumerate all the houses from left to right, starting with one. A house is considered to be luxurious if the number of floors in it is strictly greater than in all the houses with larger numbers. In other words, a house is luxurious if the number of floors in it is strictly greater than in all the houses, which are located to the right from it. In this task it is assumed that the heights of floors in the houses are the same.

The new architect is interested in *n* questions, *i*-th of them is about the following: "how many floors should be added to the *i*-th house to make it luxurious?" (for all *i* from 1 to *n*, inclusive). You need to help him cope with this task.

Note that all these questions are independent from each other — the answer to the question for house *i* does not affect other answers (i.e., the floors to the houses are not actually added).

## Input

The first line of the input contains a single number *n* (1 ≤ *n* ≤ 105) — the number of houses in the capital of Berland.

The second line contains *n* space-separated positive integers *h**i* (1 ≤ *h**i* ≤ 109), where *h**i* equals the number of floors in the *i*-th house. 

## Output

Print *n* integers *a*1, *a*2, ..., *a**n*, where number *a**i* is the number of floors that need to be added to the house number *i* to make it luxurious. If the house is already luxurious and nothing needs to be added to it, then *a**i* should be equal to zero.

All houses are numbered from left to right, starting from one.

## Examples

## Input


```
5  
1 2 3 1 2  

```
## Output


```
3 2 0 2 0 
```
## Input


```
4  
3 2 1 4  

```
## Output


```
2 3 4 0 
```


#### tags 

#1100 #implementation #math 