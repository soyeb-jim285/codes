<h1 style='text-align: center;'> B. Difference Array</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ consisting of $n$ non-negative integers. It is guaranteed that $a$ is sorted from small to large.

For each operation, we generate a new array $b_i=a_{i+1}-a_{i}$ for $1 \le i < n$. Then we sort $b$ from small to large, replace $a$ with $b$, and decrease $n$ by $1$.

After performing $n-1$ operations, $n$ becomes $1$. You need to output the only integer in array $a$ (that is to say, you need to output $a_1$).

## Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1\le t\le 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains one integer $n$ ($2\le n\le 10^5$) — the length of the array $a$.

The second line contains $n$ integers $a_1,a_2,\dots,a_n$ ($0\le a_1\le \ldots\le a_n \le 5\cdot 10^5$) — the array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2.5\cdot 10^5$, and the sum of $a_n$ over all test cases does not exceed $5\cdot 10^5$.

## Output

For each test case, output the answer on a new line.

## Example

## Input


```

531 10 10044 8 9 1350 0 0 8 1362 4 8 16 32 6470 0 0 0 0 0 0
```
## Output


```

81
3
1
2
0

```
## Note

To simplify the notes, let $\operatorname{sort}(a)$ denote the array you get by sorting $a$ from small to large.

In the first test case, $a=[1,10,100]$ at first. After the first operation, $a=\operatorname{sort}([10-1,100-10])=[9,90]$. After the second operation, $a=\operatorname{sort}([90-9])=[81]$.

In the second test case, $a=[4,8,9,13]$ at first. After the first operation, $a=\operatorname{sort}([8-4,9-8,13-9])=[1,4,4]$. After the second operation, $a=\operatorname{sort}([4-1,4-4])=[0,3]$. After the last operation, $a=\operatorname{sort}([3-0])=[3]$.



#### tags 

#1900 #brute_force #data_structures #implementation #sortings 