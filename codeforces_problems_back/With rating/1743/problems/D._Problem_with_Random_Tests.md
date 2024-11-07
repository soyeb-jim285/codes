<h1 style='text-align: center;'> D. Problem with Random Tests</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given a string $s$ consisting of $n$ characters. Each character of $s$ is either 0 or 1.

A substring of $s$ is a contiguous subsequence of its characters.

You have to choose two substrings of $s$ (possibly intersecting, possibly the same, possibly non-intersecting — just any two substrings). After choosing them, you calculate the value of the chosen pair of substrings as follows:

* let $s_1$ be the first substring, $s_2$ be the second chosen substring, and $f(s_i)$ be the integer such that $s_i$ is its binary representation (for example, if $s_i$ is 11010, $f(s_i) = 26$);
* the value is the bitwise OR of $f(s_1)$ and $f(s_2)$.

Calculate the maximum possible value you can get, and print it in binary representation without leading zeroes.

## Input

The first line contains one integer $n$ — the number of characters in $s$.

The second line contains $s$ itself, consisting of exactly $n$ characters 0 and/or 1.

All non-example tests in this problem are generated randomly: every character of $s$ is chosen independently of other characters; for each character, the probability of it being 1 is exactly $\frac{1}{2}$.

This problem has exactly $40$ tests. Tests from $1$ to $3$ are the examples; tests from $4$ to $40$ are generated randomly. In tests from $4$ to $10$, $n = 5$; in tests from $11$ to $20$, $n = 1000$; in tests from $21$ to $40$, $n = 10^6$. 

Hacks are forbidden in this problem.

## Output

Print the maximum possible value you can get in binary representation without leading zeroes.

## Examples

## Input


```

5
11010

```
## Output


```

11111

```
## Input


```

7
1110010

```
## Output


```

1111110

```
## Input


```

4
0000

```
## Output


```

0

```
## Note

In the first example, you can choose the substrings 11010 and 101. $f(s_1) = 26$, $f(s_2) = 5$, their bitwise OR is $31$, and the binary representation of $31$ is 11111.

In the second example, you can choose the substrings 1110010 and 11100.



#### tags 

#1700 #brute_force #dp #greedy #probabilities 