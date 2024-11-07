<h1 style='text-align: center;'> E. Good Triples</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given a non-negative integer number $n$ ($n \ge 0$). Let's say a triple of non-negative integers $(a, b, c)$ is good if $a + b + c = n$, and $digsum(a) + digsum(b) + digsum(c) = digsum(n)$, where $digsum(x)$ is the sum of digits of number $x$.

For example, if $n = 26$, then the pair $(4, 12, 10)$ is good, because $4 + 12 + 10 = 26$, and $(4) + (1 + 2) + (1 + 0) = (2 + 6)$.

Your task is to find the number of good triples for the given number $n$. The order of the numbers in a triple matters. For example, the triples $(4, 12, 10)$ and $(10, 12, 4)$ are two different triples.

## Input

The first line of input contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Descriptions of test cases follow.

The first and only line of the test case contains one integer $n$ ($0 \le n \le 10^7$).

## Output

For each test case output one integer, the number of good triples for the given integer $n$. Order of integers in a triple matters.

## Example

## Input


```

121101234531419992718999999910000000
```
## Output


```

9
1
3
6
10
15
21
1350
166375
29160
1522435234375
3

```
## Note

In the first example, the good triples are $(0, 0, 11)$, $(0, 1, 10)$, $(0, 10, 1)$, $(0, 11, 0)$, $(1, 0, 10)$, $(1, 10, 0)$, $(10, 0, 1)$, $(10, 1, 0)$, $(11, 0, 0)$.

In the second example, there is only one good triple $(0, 0, 0)$.



#### tags 

#1600 #brute_force #combinatorics #number_theory 