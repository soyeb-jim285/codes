<h1 style='text-align: center;'> D. Nene and the Mex Operator</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Nene gave you an array of integers $a_1, a_2, \ldots, a_n$ of length $n$.

You can perform the following operation no more than $5\cdot 10^5$ times (possibly zero):

* Choose two integers $l$ and $r$ such that $1 \le l \le r \le n$, compute $x$ as $\operatorname{MEX}(\{a_l, a_{l+1}, \ldots, a_r\})$, and simultaneously set $a_l:=x, a_{l+1}:=x, \ldots, a_r:=x$.

Here, $\operatorname{MEX}$ of a set of integers $\{c_1, c_2, \ldots, c_k\}$ is defined as the smallest non-negative integer $m$ which does not occur in the set $c$.

Your goal is to maximize the sum of the elements of the array $a$. Find the maximum sum and construct a sequence of operations that achieves this sum. 
## Note

 that you don't need to minimize the number of operations in this sequence, you only should use no more than $5\cdot 10^5$ operations in your solution.

###### Input

The first line contains an integer $n$ ($1 \le n \le 18$) — the length of the array $a$.

The second line contains $n$ integers $a_1,a_2,\ldots,a_n$ ($0\leq a_i \leq 10^7$) — the array $a$.

###### Output

In the first line, output two integers $s$ and $m$ ($0\le m\le 5\cdot 10^5$) — the maximum sum of elements of the array $a$ and the number of operations in your solution.

In the $i$-th of the following $m$ lines, output two integers $l$ and $r$ ($1 \le l \le r \le n$), representing the parameters of the $i$-th operation.

It can be shown that the maximum sum of elements of the array $a$ can always be obtained in no more than $5 \cdot 10^5$ operations.

## Examples

###### Input


```text
20 1
```
###### Output

```text

4 1
1 2

```
###### Input


```text
31 3 9
```
###### Output

```text

13 0

```
###### Input


```text
41 100 2 1
```
###### Output

```text

105 2
3 3
3 4

```
###### Input


```text
10
```
###### Output

```text

1 1
1 1

```
## Note

In the first example, after the operation with $l=1$ and $r=2$ the array $a$ becomes equal to $[2,2]$. It can be shown that it is impossible to achieve a larger sum of the elements of $a$, so the answer is $4$.

In the second example, the initial sum of elements is $13$ which can be shown to be the largest.

In the third example, the array $a$ changes as follows:

* after the first operation ($l=3$, $r=3$), the array $a$ becomes equal to $[1,100,0,1]$;
* after the second operation ($l=3$, $r=4$), the array $a$ becomes equal to $[1,100,2,2]$.

It can be shown that it is impossible to achieve a larger sum of the elements of $a$, so the answer is $105$.



#### Tags 

#2000 #NOT OK #bitmasks #brute_force #constructive_algorithms #divide_and_conquer #dp #greedy #implementation #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_939_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
