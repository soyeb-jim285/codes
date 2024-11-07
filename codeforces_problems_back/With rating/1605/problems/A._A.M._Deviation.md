<h1 style='text-align: center;'> A. A.M. Deviation</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A number $a_2$ is said to be the arithmetic mean of two numbers $a_1$ and $a_3$, if the following condition holds: $a_1 + a_3 = 2\cdot a_2$. 

We define an arithmetic mean deviation of three numbers $a_1$, $a_2$ and $a_3$ as follows: $d(a_1, a_2, a_3) = |a_1 + a_3 - 2 \cdot a_2|$.

Arithmetic means a lot to Jeevan. He has three numbers $a_1$, $a_2$ and $a_3$ and he wants to minimize the arithmetic mean deviation $d(a_1, a_2, a_3)$. To do so, he can perform the following operation any number of times (possibly zero):

* Choose $i, j$ from $\{1, 2, 3\}$ such that $i \ne j$ and increment $a_i$ by $1$ and decrement $a_j$ by $1$

Help Jeevan find out the minimum value of $d(a_1, a_2, a_3)$ that can be obtained after applying the operation any number of times.

## Input

The first line contains a single integer $t$ $(1 \le t \le 5000)$  — the number of test cases.

The first and only line of each test case contains three integers $a_1$, $a_2$ and $a_3$ $(1 \le a_1, a_2, a_3 \le 10^{8})$.

## Output

For each test case, output the minimum value of $d(a_1, a_2, a_3)$ that can be obtained after applying the operation any number of times.

## Example

## Input


```

3
3 4 5
2 2 6
1 6 5

```
## Output


```

0
1
0

```
## Note

## Note

 that after applying a few operations, the values of $a_1$, $a_2$ and $a_3$ may become negative.

In the first test case, $4$ is already the Arithmetic Mean of $3$ and $5$.

$d(3, 4, 5) = |3 + 5 - 2 \cdot 4| = 0$

In the second test case, we can apply the following operation:

$(2, 2, 6)$ $\xrightarrow[\text{increment $a_2$}]{\text{decrement $a_1$}}$ $(1, 3, 6)$

$d(1, 3, 6) = |1 + 6 - 2 \cdot 3| = 1$

It can be proven that answer can not be improved any further.

In the third test case, we can apply the following operations:

$(1, 6, 5)$ $\xrightarrow[\text{increment $a_3$}]{\text{decrement $a_2$}}$ $(1, 5, 6)$ $\xrightarrow[\text{increment $a_1$}]{\text{decrement $a_2$}}$ $(2, 4, 6)$

$d(2, 4, 6) = |2 + 6 - 2 \cdot 4| = 0$



#### tags 

#800 #math #number_theory 