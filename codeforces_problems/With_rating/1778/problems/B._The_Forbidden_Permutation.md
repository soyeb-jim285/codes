<h1 style='text-align: center;'> B. The Forbidden Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a permutation $p$ of length $n$, an array of $m$ distinct integers $a_1, a_2, \ldots, a_m$ ($1 \le a_i \le n$), and an integer $d$.

Let $\mathrm{pos}(x)$ be the index of $x$ in the permutation $p$. The array $a$ is not good if 

* $\mathrm{pos}(a_{i}) < \mathrm{pos}(a_{i + 1}) \le \mathrm{pos}(a_{i}) + d$ for all $1 \le i < m$.

For example, with the permutation $p = [4, 2, 1, 3, 6, 5]$ and $d = 2$: 

* $a = [2, 3, 6]$ is a not good array.
* $a = [2, 6, 5]$ is good because $\mathrm{pos}(a_1) = 2$, $\mathrm{pos}(a_2) = 5$, so the condition $\mathrm{pos}(a_2) \le \mathrm{pos}(a_1) + d$ is not satisfied.
* $a = [1, 6, 3]$ is good because $\mathrm{pos}(a_2) = 5$, $\mathrm{pos}(a_3) = 4$, so the condition $\mathrm{pos}(a_2) < \mathrm{pos}(a_3)$ is not satisfied.

In one move, you can swap two adjacent elements of the permutation $p$. What is the minimum number of moves needed such that the array $a$ becomes good? It can be shown that there always exists a sequence of moves so that the array $a$ becomes good.

A permutation is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array) and $[1,3,4]$ is also not a permutation ($n=3$, but there is $4$ in the array).

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains three integers $n$, $m$ and $d$ ($2\leq n \leq 10^5$, $2\leq m\leq n$, $1 \le d \le n$), the length of the permutation $p$, the length of the array $a$ and the value of $d$. 

The second line contains $n$ integers $p_1, p_2, \ldots, p_n$ ($1\leq p_i \leq n$, $p_i \ne p_j$ for $i \ne j$). 

The third line contains $m$ distinct integers $a_1, a_2, \ldots, a_m$ ($1\leq a_i \leq n$, $a_i \ne a_j$ for $i \ne j$).

The sum of $n$ over all test cases doesn't exceed $5 \cdot 10^5$.

### Output

For each test case, print the minimum number of moves needed such that the array $a$ becomes good.

## Example

### Input


```text
54 2 21 2 3 41 35 2 45 4 3 2 15 25 3 33 4 1 5 23 1 22 2 11 22 16 2 41 2 3 4 5 62 5
```
### Output

```text

1
3
2
0
2

```
## Note

In the first case, $pos(a_1)=1$, $pos(a_2)=3$. To make the array good, one way is to swap $p_3$ and $p_4$. After that, the array $a$ will be good because the condition $\mathrm{pos}(a_2) \le \mathrm{pos}(a_1) + d$ won't be satisfied.

In the second case, $pos(a_1)=1$, $pos(a_2)=4$. The $3$ moves could be: 

1. Swap $p_3$ and $p_4$.
2. Swap $p_2$ and $p_3$.
3. Swap $p_1$ and $p_2$.

 After these moves, the permutation $p$ will be $[2,5,4,3,1]$. The array $a$ will be good because the condition $\mathrm{pos}(a_1) < \mathrm{pos}(a_2)$ won't be satisfied. It can be shown that you can't make the array $a$ good with fewer moves.In the third case, $pos(a_1)=1$, $pos(a_2)=3$, $pos(a_3)=5$. The $2$ moves can be: 

1. Swap $p_4$ and $p_5$.
2. Swap $p_3$ and $p_4$.

 After these moves, the permutation $p$ will be $[3,4,2,1,5]$. The array $a$ will be good because the condition $\mathrm{pos}(a_2) < \mathrm{pos}(a_3)$ won't be satisfied. It can be shown that you can't make the array $a$ good with fewer moves.In the fourth case, $pos(a_1)=2$, $pos(a_2)=1$. The array $a$ is already good.

In the fifth case, $pos(a_1)=2$, $pos(a_2)=5$. The $2$ moves are: 

1. Swap $p_1$ and $p_2$.
2. Swap $p_5$ and $p_6$.


#### Tags 

#1300 #NOT OK #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_848_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
