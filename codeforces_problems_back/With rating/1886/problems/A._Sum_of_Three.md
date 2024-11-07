<h1 style='text-align: center;'> A. Sum of Three</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp has an integer $n$.

He wants to represent his number as a sum of three distinct positive integers $x$, $y$, and $z$. Additionally, Monocarp wants none of the numbers $x$, $y$, and $z$ to be divisible by $3$.

Your task is to help Monocarp to find any valid triplet of distinct positive integers $x$, $y$, and $z$, or report that such a triplet does not exist.

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of testcases.

The only line of each testcase contains a single integer $n$ ($1 \le n \le 10^{9}$).

## Output

For each testcase, if there is no valid triplet $x$, $y$, and $z$, print NO on the first line.

Otherwise, print YES on the first line. On the second line, print any valid triplet of distinct positive integers $x$, $y$, and $z$ such that $x + y + z = n$, and none of the printed numbers are divisible by $3$. If there are multiple valid triplets, you can print any of them.

## Example

## Input


```

4104159
```
## Output


```

YES
4 5 1
NO
YES
2 8 5
NO

```
## Note

In the first testcase, one of the valid triplets is $x = 4$, $y = 5$, $z = 1$. None of these numbers are divisible by three, and $4 + 5 + 1 = 10$.

In the second testcase, there is no valid triplet.

In the third testcase, one of the valid triplets is $x = 2$, $y = 8$, $z = 5$. None of these numbers are divisible by three, and $2 + 8 + 5 = 15$.

In the fourth testcase, there is no valid triplet.



#### tags 

#800 #brute_force #constructive_algorithms #math 