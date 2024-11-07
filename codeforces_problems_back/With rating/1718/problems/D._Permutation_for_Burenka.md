<h1 style='text-align: center;'> D. Permutation for Burenka</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

We call an array $a$ pure if all elements in it are pairwise distinct. For example, an array $[1, 7, 9]$ is pure, $[1, 3, 3, 7]$ isn't, because $3$ occurs twice in it.

A pure array $b$ is similar to a pure array $c$ if their lengths $n$ are the same and for all pairs of indices $l$, $r$, such that $1 \le l \le r \le n$, it's true that $$\operatorname{argmax}([b_l, b_{l + 1}, \ldots, b_r]) = \operatorname{argmax}([c_l, c_{l + 1}, \ldots, c_r]),$$ where $\operatorname{argmax}(x)$ is defined as the index of the largest element in $x$ (which is unique for pure arrays). For example, $\operatorname{argmax}([3, 4, 2]) = 2$, $\operatorname{argmax}([1337, 179, 57]) = 1$.

Recently, Tonya found out that Burenka really likes a permutation $p$ of length $n$. Tonya decided to please her and give her an array $a$ similar to $p$. He already fixed some elements of $a$, but exactly $k$ elements are missing (in these positions temporarily $a_i = 0$). It is guaranteed that $k \ge 2$. Also, he has a set $S$ of $k - 1$ numbers.

Tonya realized that he was missing one number to fill the empty places of $a$, so he decided to buy it. He has $q$ options to buy. Tonya thinks that the number $d$ suits him, if it is possible to replace all zeros in $a$ with numbers from $S$ and the number $d$, so that $a$ becomes a pure array similar to $p$. For each option of $d$, output whether this number is suitable for him or not.

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) is the number of test cases. The description of the test cases follows.

The first line of each test case contains a couple of integers $n$ and $q$ ($1 \le n, q \le 3 \cdot 10^5$).

The second line of each input test case contains $n$ integers $p_1, p_2, \ldots, p_n$ ($1 \le p_i \le n$) — the permutation Burenka likes.

The third line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le 10^6$) — elements of Tonya's array, where $0$ denotes a missing element. It is guaranteed that there are two indexes $i, j$ $(1 \le i, j \le n, i \ne j)$ such that $a_i = 0, a_j = 0$, which implies that $k \geq 2$.

The fourth line of each test case contains $k - 1$ distinct integers $s_1, s_2, \ldots, s_{k-1}$ ($1 \le s_i \le 10^6$) — elements of Tonya's set $S$.

Each of the next $q$ lines contains a single integer $d$ ($1 \le d \le 10^6$) — the number that Tonya plans to buy.

It is guaranteed that for each given $d$ it's possible to fill in the gaps in $a$ with numbers from $S$ and the number $d$ to get a pure array.

It is guaranteed that the sum of $n$ and the sum of $q$ in all tests does not exceed $3 \cdot 10^5$.

## Output

## Output

 $q$ lines. For each value $d$, print "YES" if there is a way to fill the array $a$ to make it similar to $p$, and "NO" otherwise.

## Example

## Input


```

44 31 4 3 25 0 7 069145 31 2 5 4 30 5 10 0 03 918115 21 4 3 2 50 0 0 0 07 9 1 561004 24 1 3 20 5 3 0246
```
## Output


```

YES
NO
NO
YES
YES
NO
YES
YES
NO
NO

```
## Note

In the first test case for $d = 9$, you can get $a = [5, 9, 7, 6]$, it can be proved that $a$ is similar to $p$, for $d=1$ and $d=4$ it can be proved that there is no answer.

In the second test case for $d = 1$, you can get $a = [1, 5, 10, 9, 3]$, for $d = 8$, you can get $a = [3, 5, 10, 9, 8]$, it can be proved that for $d = 11$ there is no answer.



#### tags 

#3300 #data_structures #graph_matchings #greedy #math #trees 