<h1 style='text-align: center;'> D. Towers</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The city of D consists of *n* towers, built consecutively on a straight line. The height of the tower that goes *i*-th (from left to right) in the sequence equals *h**i*. The city mayor decided to rebuild the city to make it beautiful. In a beautiful city all towers are are arranged in non-descending order of their height from left to right.

The rebuilding consists of performing several (perhaps zero) operations. An operation constitutes using a crane to take any tower and put it altogether on the top of some other neighboring tower. In other words, we can take the tower that stands *i*-th and put it on the top of either the (*i* - 1)-th tower (if it exists), or the (*i* + 1)-th tower (of it exists). The height of the resulting tower equals the sum of heights of the two towers that were put together. After that the two towers can't be split by any means, but more similar operations can be performed on the resulting tower. Note that after each operation the total number of towers on the straight line decreases by 1.

Help the mayor determine the minimum number of operations required to make the city beautiful.

## Input

The first line contains a single integer *n* (1 ≤ *n* ≤ 5000) — the number of towers in the city. The next line contains *n* space-separated integers: the *i*-th number *h**i* (1 ≤ *h**i* ≤ 105) determines the height of the tower that is *i*-th (from left to right) in the initial tower sequence.

## Output

Print a single integer — the minimum number of operations needed to make the city beautiful.

## Examples

## Input


```
5  
8 2 7 3 1  

```
## Output


```
3  

```
## Input


```
3  
5 2 1  

```
## Output


```
2  

```


#### tags 

#2100 #dp #greedy #two_pointers 