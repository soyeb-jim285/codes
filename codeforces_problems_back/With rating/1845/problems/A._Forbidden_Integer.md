<h1 style='text-align: center;'> A. Forbidden Integer</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an integer $n$, which you want to obtain. You have an unlimited supply of every integer from $1$ to $k$, except integer $x$ (there are no integer $x$ at all).

You are allowed to take an arbitrary amount of each of these integers (possibly, zero). Can you make the sum of taken integers equal to $n$?

If there are multiple answers, print any of them.

## Input

The first line contains a single integer $t$ ($1 \le t \le 100$) — the number of testcases.

The only line of each testcase contains three integers $n, k$ and $x$ ($1 \le x \le k \le n \le 100$).

## Output

For each test case, in the first line, print "YES" or "NO" — whether you can take an arbitrary amount of each integer from $1$ to $k$, except integer $x$, so that their sum is equal to $n$.

If you can, the second line should contain a single integer $m$ — the total amount of taken integers. The third line should contain $m$ integers — each of them from $1$ to $k$, not equal to $x$, and their sum is $n$.

If there are multiple answers, print any of them.

## Example

## Input


```

510 3 25 2 14 2 17 7 36 1 1
```
## Output


```

YES
6
3 1 1 1 1 3
NO
YES
2
2 2
YES
1
7
NO

```
## Note

Another possible answer for the first testcase is $[3, 3, 3, 1]$. ## Note

 that you don't have to minimize the amount of taken integers. There also exist other answers.

In the second testcase, you only have an unlimited supply of integer $2$. There is no way to get sum $5$ using only them.

In the fifth testcase, there are no integers available at all, so you can't get any positive sum.



#### tags 

#800 #constructive_algorithms #implementation #math #number_theory 