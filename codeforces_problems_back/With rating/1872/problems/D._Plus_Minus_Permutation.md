<h1 style='text-align: center;'> D. Plus Minus Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given $3$ integers — $n$, $x$, $y$. Let's call the score of a permutation$^\dagger$ $p_1, \ldots, p_n$ the following value:

$$(p_{1 \cdot x} + p_{2 \cdot x} + \ldots + p_{\lfloor \frac{n}{x} \rfloor \cdot x}) - (p_{1 \cdot y} + p_{2 \cdot y} + \ldots + p_{\lfloor \frac{n}{y} \rfloor \cdot y})$$

In other words, the score of a permutation is the sum of $p_i$ for all indices $i$ divisible by $x$, minus the sum of $p_i$ for all indices $i$ divisible by $y$.

You need to find the maximum possible score among all permutations of length $n$.

For example, if $n = 7$, $x = 2$, $y = 3$, the maximum score is achieved by the permutation $[2,\color{red}{\underline{\color{black}{6}}},\color{blue}{\underline{\color{black}{1}}},\color{red}{\underline{\color{black}{7}}},5,\color{blue}{\underline{\color{red}{\underline{\color{black}{4}}}}},3]$ and is equal to $(6 + 7 + 4) - (1 + 4) = 17 - 5 = 12$.

$^\dagger$ A permutation of length $n$ is an array consisting of $n$ distinct integers from $1$ to $n$ in any order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation (the number $2$ appears twice in the array) and $[1,3,4]$ is also not a permutation ($n=3$, but the array contains $4$).

## Input

The first line of input contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

Then follows the description of each test case.

The only line of each test case description contains $3$ integers $n$, $x$, $y$ ($1 \le n \le 10^9$, $1 \le x, y \le n$).

## Output

For each test case, output a single integer — the maximum score among all permutations of length $n$.

## Example

## Input


```

87 2 312 6 39 1 92 2 2100 20 5024 4 61000000000 5575 254504 4 1
```
## Output


```

12
-3
44
0
393
87
179179179436104
-6

```
## Note

The first test case is explained in the problem statement above.

In the second test case, one of the optimal permutations will be $[12,11,\color{blue}{\underline{\color{black}{2}}},4,8,\color{blue}{\underline{\color{red}{\underline{\color{black}{9}}}}},10,6,\color{blue}{\underline{\color{black}{1}}},5,3,\color{blue}{\underline{\color{red}{\underline{\color{black}{7}}}}}]$. The score of this permutation is $(9 + 7) - (2 + 9 + 1 + 7) = -3$. It can be shown that a score greater than $-3$ can not be achieved. ## Note

 that the answer to the problem can be negative.

In the third test case, the score of the permutation will be $(p_1 + p_2 + \ldots + p_9) - p_9$. One of the optimal permutations for this case is $[9, 8, 7, 6, 5, 4, 3, 2, 1]$, and its score is $44$. It can be shown that a score greater than $44$ can not be achieved.

In the fourth test case, $x = y$, so the score of any permutation will be $0$.



#### tags 

#1200 #math 