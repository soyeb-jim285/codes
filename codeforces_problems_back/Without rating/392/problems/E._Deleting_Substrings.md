<h1 style='text-align: center;'> E. Deleting Substrings</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

SmallR likes a game called "Deleting Substrings". In the game you are given a sequence of integers *w*, you can modify the sequence and get points. The only type of modification you can perform is (unexpected, right?) deleting substrings. More formally, you can choose several contiguous elements of *w* and delete them from the sequence. Let's denote the sequence of chosen elements as *w**l*, *w**l* + 1, ..., *w**r*. They must meet the conditions:

* the equality |*w**i* - *w**i* + 1| = 1 must hold for all *i* (*l* ≤ *i* < *r*);
* the inequality 2·*w**i* - *w**i* + 1 - *w**i* - 1 ≥ 0 must hold for all *i* (*l* < *i* < *r*).

After deleting the chosen substring of *w*, you gain *v**r* - *l* + 1 points. You can perform the described operation again and again while proper substrings exist. Also you can end the game at any time. Your task is to calculate the maximum total score you can get in the game.

## Input

The first line contains a single integer *n* (1 ≤ *n* ≤ 400) — the initial length of *w*. The second line contains *n* integers *v*1, *v*2, ..., *v**n* (0 ≤ |*v**i*| ≤ 2000) — the costs of operations. The next line contains *n* integers *w*1, *w*2, ..., *w**n* (1 ≤ *w**i* ≤ 109) — the initial *w*.

## Output

Print a single integer — the maximum total score you can get.

## Examples

## Input


```
3  
0 0 3  
1 2 1  

```
## Output


```
3
```
## Input


```
6  
1 4 5 6 7 1000  
2 1 1 2 2 3  

```
## Output


```
12
```


#### tags 

