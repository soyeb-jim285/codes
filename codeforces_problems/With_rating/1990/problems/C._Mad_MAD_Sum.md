<h1 style='text-align: center;'> C. Mad MAD Sum</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

We define the $\operatorname{MAD}$ (Maximum Appearing Duplicate) in an array as the largest number that appears at least twice in the array. Specifically, if there is no number that appears at least twice, the $\operatorname{MAD}$ value is $0$.

For example, $\operatorname{MAD}([1, 2, 1]) = 1$, $\operatorname{MAD}([2, 2, 3, 3]) = 3$, $\operatorname{MAD}([1, 2, 3, 4]) = 0$.

You are given an array $a$ of size $n$. Initially, a variable $sum$ is set to $0$.

The following process will be executed in a sequential loop until all numbers in $a$ become $0$:

1. Set $sum := sum + \sum_{i=1}^{n} a_i$;
2. Let $b$ be an array of size $n$. Set $b_i :=\ \operatorname{MAD}([a_1, a_2, \ldots, a_i])$ for all $1 \le i \le n$, and then set $a_i := b_i$ for all $1 \le i \le n$.

Find the value of $sum$ after the process.

### Input

The first line contains an integer $t$ ($1 \leq t \leq 2 \cdot 10^4$) — the number of test cases.

For each test case: 

* The first line contains an integer $n$ ($1 \leq n \leq 2 \cdot 10^5$) — the size of the array $a$;
* The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq n$) — the elements of the array.

It is guaranteed that the sum of $n$ over all test cases will not exceed $2 \cdot 10^5$.

### Output

For each test case, output the value of $sum$ in a new line.

## Example

### Input


```text
41132 2 342 1 1 244 4 4 4
```
### Output

```text

1
13
9
40

```
## Note

In the first test case, $a=[1]$ initially.

In the first loop: 

1. Set $sum := sum + a_1 = 0+1=1$;
2. Set $b_1 :=\ \operatorname{MAD}([a_1])=\ \operatorname{MAD}([1])=0$, and then set $a_1 := b_1$.

After the first loop, $a=[0]$ and the process ends. The value of $sum$ after the process is $1$.

In the second test case, $a=[2,2,3]$ initially.

After the first loop, $a=[0,2,2]$ and $sum=7$.

After the second loop, $a=[0,0,2]$ and $sum=11$.

After the third loop, $a=[0,0,0]$ and $sum=13$. Then the process ends.

The value of $sum$ after the process is $13$.



#### Tags 

#1500 #NOT OK #brute_force #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_960_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
