<h1 style='text-align: center;'> A. Anti-knapsack</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two integers $n$ and $k$. You are asked to choose maximum number of distinct integers from $1$ to $n$ so that there is no subset of chosen numbers with sum equal to $k$.

A subset of a set is a set that can be obtained from initial one by removing some (possibly all or none) elements of it.

## Input

The first line contains the number of test cases $T$ ($1 \le T \le 100$).

Each of the next $T$ lines contains two integers $n$ and $k$ ($1 \le k \le n \le 1000$) — the description of test cases.

## Output

For each test case output two lines. In the first line output a single integer $m$ — the number of chosen integers.

In the second line output $m$ distinct integers from $1$ to $n$ — the chosen numbers.

If there are multiple answers, print any. You can print the numbers in any order.

## Example

## Input


```

3
3 2
5 3
1 1

```
## Output


```

2
3 1 
3
4 5 2 
0


```


#### tags 

#800 #constructive_algorithms #greedy 