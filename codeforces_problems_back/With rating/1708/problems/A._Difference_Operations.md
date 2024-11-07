<h1 style='text-align: center;'> A. Difference Operations</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ consisting of $n$ positive integers.

You are allowed to perform this operation any number of times (possibly, zero): 

* choose an index $i$ ($2 \le i \le n$), and change $a_i$ to $a_i - a_{i-1}$.

Is it possible to make $a_i=0$ for all $2\le i\le n$?

## Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1\le t\le 100$)  — the number of test cases. The description of the test cases follows.

The first line contains one integer $n$ ($2 \le n \le 100$) — the length of array $a$.

The second line contains $n$ integers $a_1,a_2,\ldots,a_n$ ($1 \le a_i \le 10^9$).

## Output

For each test case, print "YES" (without quotes), if it is possible to change $a_i$ to $0$ for all $2 \le i \le n$, and "NO" (without quotes) otherwise.

You can print letters in any case (upper or lower).

## Example

## Input


```

425 1031 2 341 1 1 199 9 8 2 4 4 3 5 3
```
## Output


```

YES
YES
YES
NO

```
## Note

In the first test case, the initial array is $[5,10]$. You can perform $2$ operations to reach the goal:

1. Choose $i=2$, and the array becomes $[5,5]$.
2. Choose $i=2$, and the array becomes $[5,0]$.

In the second test case, the initial array is $[1,2,3]$. You can perform $4$ operations to reach the goal: 

1. Choose $i=3$, and the array becomes $[1,2,1]$.
2. Choose $i=2$, and the array becomes $[1,1,1]$.
3. Choose $i=3$, and the array becomes $[1,1,0]$.
4. Choose $i=2$, and the array becomes $[1,0,0]$.

In the third test case, you can choose indices in the order $4$, $3$, $2$.



#### tags 

#800 #greedy #math 