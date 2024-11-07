<h1 style='text-align: center;'> F. Inverse Transformation</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A permutation scientist is studying a self-transforming permutation $a$ consisting of $n$ elements $a_1,a_2,\ldots,a_n$.

A permutation is a sequence of integers from $1$ to $n$ of length $n$ containing each number exactly once. For example, $[1]$, $[4, 3, 5, 1, 2]$ are permutations, while $[1, 1]$, $[4, 3, 1]$ are not.

The permutation transforms day by day. On each day, each element $x$ becomes $a_x$, that is, $a_x$ becomes $a_{a_x}$. Specifically: 

* on the first day, the permutation becomes $b$, where $b_x = a_{a_x}$;
* on the second day, the permutation becomes $c$, where $c_x = b_{b_x}$;
* $\ldots$

 For example, consider permutation $a = [2,3,1]$. On the first day, it becomes $[3,1,2]$. On the second day, it becomes $[2,3,1]$.You're given the permutation $a'$ on the $k$-th day.

Define $\sigma(x) = a_x$, and define $f(x)$ as the minimal positive integer $m$ such that $\sigma^m(x) = x$, where $\sigma^m(x)$ denotes $\underbrace{\sigma(\sigma(\ldots \sigma}_{m \text{ times}}(x) \ldots))$.

For example, if $a = [2,3,1]$, then $\sigma(1) = 2$, $\sigma^2(1) = \sigma(\sigma(1)) = \sigma(2) = 3$, $\sigma^3(1) = \sigma(\sigma(\sigma(1))) = \sigma(3) = 1$, so $f(1) = 3$. And if $a=[4,2,1,3]$, $\sigma(2) = 2$ so $f(2) = 1$; $\sigma(3) = 1$, $\sigma^2(3) = 4$, $\sigma^3(3) = 3$ so $f(3) = 3$.

Find the initial permutation $a$ such that $\sum\limits^n_{i=1} \dfrac{1}{f(i)}$ is minimum possible.

## Input

Each test contains multiple test cases. The first line contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains two integers $n$ and $k$ ($1 \le n \le 2 \cdot 10^5$; $1 \le k \le 10^9$) — the length of $a$, and the last day.

The second line contains $n$ integers $a'_1,a'_2,\ldots,a'_n$ ($1 \le a'_i \le n$) — the permutation on the $k$-th day.

It's guaranteed that the sum of $n$ does not exceed $2 \cdot 10^5$.

## Output

For each test case, if at least one initial $a$ consistent with the given $a'$ exists, print "YES", then print $n$ integers $a_1,a_2,\ldots,a_n$ — the initial permutation with the smallest sum $\sum\limits^n_{i=1} \dfrac{1}{f(i)}$. If there are multiple answers with the smallest sum, print any.

If there are no valid permutations, print "NO".

## Example

## Input


```

105 31 2 3 4 57 21 2 3 4 5 6 78 9981 2 3 4 5 6 7 86 16 3 5 4 1 24 84 2 1 39 11 5 4 8 7 6 3 2 95 99999992 3 4 5 17 978432204 6 1 2 7 5 33 10000000002 1 312 38 9 10 1 5 3 11 4 7 6 12 2
```
## Output


```

YES
2 3 4 1 5
YES
6 2 5 7 1 3 4
YES
2 3 4 5 6 7 8 1
YES
3 1 6 4 2 5
YES
4 2 1 3
NO
YES
3 4 5 1 2
YES
2 5 4 6 3 7 1
NO
YES
3 7 8 6 5 1 12 10 11 4 2 9

```
## Note

In the second test case, the initial permutation can be $a = [6,2,5,7,1,3,4]$, which becomes $[3,2,1,4,6,5,7]$ on the first day and $a' = [1,2,3,4,5,6,7]$ on the second day (the $k$-th day). Also, among all the permutations satisfying that, it has the minimum $\sum\limits^n_{i=1} \dfrac{1}{f(i)}$, which is $\dfrac{1}{4}+\dfrac{1}{1}+\dfrac{1}{4}+\dfrac{1}{2}+\dfrac{1}{4}+\dfrac{1}{4}+\dfrac{1}{2}=3$.

In the fifth test case, the initial permutation can be $a = [4,2,1,3]$, which becomes $[3,2,4,1]$ on the first day, $[4,2,1,3]$ on the second day, and so on. So it finally becomes $a' = [4,2,1,3]$ on the $8$-th day (the $k$-th day). And it has the minimum $\sum\limits^n_{i=1} \dfrac{1}{f(i)} = \dfrac{1}{3} + \dfrac{1}{1} + \dfrac{1}{3} + \dfrac{1}{3} = 2$.



#### tags 

#2500 #constructive_algorithms #implementation #math 