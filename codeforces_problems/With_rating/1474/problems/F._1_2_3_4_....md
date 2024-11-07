<h1 style='text-align: center;'> F. 1 2 3 4 ...</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Igor had a sequence $d_1, d_2, \dots, d_n$ of integers. When Igor entered the classroom there was an integer $x$ written on the blackboard.

Igor generated sequence $p$ using the following algorithm: 

1. initially, $p = [x]$;
2. for each $1 \leq i \leq n$ he did the following operation $|d_i|$ times:
	* if $d_i \geq 0$, then he looked at the last element of $p$ (let it be $y$) and appended $y + 1$ to the end of $p$;
	* if $d_i < 0$, then he looked at the last element of $p$ (let it be $y$) and appended $y - 1$ to the end of $p$.

For example, if $x = 3$, and $d = [1, -1, 2]$, $p$ will be equal $[3, 4, 3, 4, 5]$.

Igor decided to calculate the length of the longest increasing subsequence of $p$ and the number of them.

A sequence $a$ is a subsequence of a sequence $b$ if $a$ can be obtained from $b$ by deletion of several (possibly, zero or all) elements.

A sequence $a$ is an increasing sequence if each element of $a$ (except the first one) is strictly greater than the previous element.

For $p = [3, 4, 3, 4, 5]$, the length of longest increasing subsequence is $3$ and there are $3$ of them: $[\underline{3}, \underline{4}, 3, 4, \underline{5}]$, $[\underline{3}, 4, 3, \underline{4}, \underline{5}]$, $[3, 4, \underline{3}, \underline{4}, \underline{5}]$.

###### Input

The first line contains a single integer $n$ ($1 \leq n \leq 50$) — the length of the sequence $d$.

The second line contains a single integer $x$ ($-10^9 \leq x \leq 10^9$) — the integer on the blackboard.

The third line contains $n$ integers $d_1, d_2, \ldots, d_n$ ($-10^9 \leq d_i \leq 10^9$).

###### Output

Print two integers: 

* the first integer should be equal to the length of the longest increasing subsequence of $p$;
* the second should be equal to the number of them modulo $998244353$.

You should print only the second number modulo $998244353$.

## Examples

###### Input


```text
3
3
1 -1 2
```
###### Output


```text
3 3
```
###### Input


```text
3
100
5 -3 6
```
###### Output


```text
9 7
```
###### Input


```text
3
1
999999999 0 1000000000
```
###### Output


```text
2000000000 1
```
###### Input


```text
5
34
1337 -146 42 -69 228
```
###### Output


```text
1393 3876
```
## Note

The first test case was explained in the statement.

In the second test case $p = [100, 101, 102, 103, 104, 105, 104, 103, 102, 103, 104, 105, 106, 107, 108]$.

In the third test case $p = [1, 2, \ldots, 2000000000]$.



#### Tags 

#3000 #NOT OK #dp #math #matrices 

## Blogs
- [All Contest Problems](../Codeforces_Round_696_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
