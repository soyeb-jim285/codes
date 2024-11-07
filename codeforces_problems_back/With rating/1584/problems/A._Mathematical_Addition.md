<h1 style='text-align: center;'> A. Mathematical Addition</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Ivan decided to prepare for the test on solving integer equations. He noticed that all tasks in the test have the following form:

* You are given two positive integers $u$ and $v$, find any pair of integers (not necessarily positive) $x$, $y$, such that: $$\frac{x}{u} + \frac{y}{v} = \frac{x + y}{u + v}.$$
* The solution $x = 0$, $y = 0$ is forbidden, so you should find any solution with $(x, y) \neq (0, 0)$.

Please help Ivan to solve some equations of this form.

## Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^3$) — the number of test cases. The next lines contain descriptions of test cases.

The only line of each test case contains two integers $u$ and $v$ ($1 \leq u, v \leq 10^9$) — the parameters of the equation.

## Output

For each test case print two integers $x$, $y$ — a possible solution to the equation. It should be satisfied that $-10^{18} \leq x, y \leq 10^{18}$ and $(x, y) \neq (0, 0)$.

We can show that an answer always exists. If there are multiple possible solutions you can print any.

## Example

## Input


```

4
1 1
2 3
3 5
6 9

```
## Output


```

-1 1
-4 9
-18 50
-4 9

```
## Note

In the first test case: $\frac{-1}{1} + \frac{1}{1} = 0 = \frac{-1 + 1}{1 + 1}$.

In the second test case: $\frac{-4}{2} + \frac{9}{3} = 1 = \frac{-4 + 9}{2 + 3}$.

In the third test case: $\frac{-18}{3} + \frac{50}{5} = 4 = \frac{-18 + 50}{3 + 5}$.

In the fourth test case: $\frac{-4}{6} + \frac{9}{9} = \frac{1}{3} = \frac{-4 + 9}{6 + 9}$.



#### tags 

#800 #math 