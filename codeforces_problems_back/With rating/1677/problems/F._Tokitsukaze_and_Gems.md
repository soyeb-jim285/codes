<h1 style='text-align: center;'> F. Tokitsukaze and Gems</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Tokitsukaze has a sequence with length of $n$. She likes gems very much. There are $n$ kinds of gems. The gems of the $i$-th kind are on the $i$-th position, and there are $a_i$ gems of the same kind on that position. Define $G(l,r)$ as the multiset containing all gems on the segment $[l,r]$ (inclusive).

A multiset of gems can be represented as $S=[s_1,s_2,\ldots,s_n]$, which is a non-negative integer sequence of length $n$ and means that $S$ contains $s_i$ gems of the $i$-th kind in the multiset. A multiset $T=[t_1,t_2,\ldots,t_n]$ is a multisubset of $S=[s_1,s_2,\ldots,s_n]$ if and only if $t_i\le s_i$ for any $i$ satisfying $1\le i\le n$.

Now, given two positive integers $k$ and $p$, you need to calculate the result of

$$\sum_{l=1}^n \sum_{r=l}^n\sum\limits_{[t_1,t_2,\cdots,t_n] \subseteq G(l,r)}\left(\left(\sum_{i=1}^n p^{t_i}t_i^k\right)\left(\sum_{i=1}^n[t_i>0]\right)\right),$$

where $[t_i>0]=1$ if $t_i>0$ and $[t_i>0]=0$ if $t_i=0$.

Since the answer can be quite large, print it modulo $998\,244\,353$.

## Input

The first line contains three integers $n$, $k$ and $p$ ($1\le n \le 10^5$; $1\le k\le 10^5$; $2\le p\le 998\,244\,351$) — the length of the sequence, the numbers $k$ and $p$.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1\le a_i\le 998\,244\,351$) — the number of gems on the $i$-th position.

## Output

Print a single integers — the result modulo $998\,244\,353$.

## Examples

## Input


```

5 2 2
1 1 1 2 2

```
## Output


```

6428

```
## Input


```

6 2 2
2 2 2 2 2 3

```
## Output


```

338940

```


#### tags 

#3500 #dp #math 