<h1 style='text-align: center;'> F. Koishi's Unconscious Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 12 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

As she closed the Satori's eye that could read minds, Koishi gained the ability to live in unconsciousness. Even she herself does not know what she is up to.— Subterranean AnimismKoishi is unconsciously permuting $n$ numbers: $1, 2, \ldots, n$.

She thinks the permutation $p$ is beautiful if $s=\sum\limits_{i=1}^{n-1} [p_i+1=p_{i+1}]$. $[x]$ equals to $1$ if $x$ holds, or $0$ otherwise.

For each $k\in[0,n-1]$, she wants to know the number of beautiful permutations of length $n$ satisfying $k=\sum\limits_{i=1}^{n-1}[p_i<p_{i+1}]$.

## Input

There is one line containing two intergers $n$ ($1 \leq n \leq 250\,000$) and $s$ ($0 \leq s < n$).

## Output

Print one line with $n$ intergers. The $i$-th integers represents the answer of $k=i-1$, modulo $998244353$.

## Examples

## Input


```

2 0

```
## Output


```

1 0

```
## Input


```

4 1

```
## Output


```

0 3 6 0

```
## Input


```

8 3

```
## Output


```

0 0 0 35 770 980 70 0

```
## Note

Let $f(p)=\sum\limits_{i=1}^{n-1}[p_i<p_{i+1}]$.

Testcase 1:

$[2,1]$ is the only beautiful permutation. And $f([2,1])=0$.

Testcase 2:

Beautiful permutations:

$[1,2,4,3]$, $[1,3,4,2]$, $[1,4,2,3]$, $[2,1,3,4]$, $[2,3,1,4]$, $[3,1,2,4]$, $[3,4,2,1]$, $[4,2,3,1]$, $[4,3,1,2]$. The first six of them satisfy $f(p)=2$, while others satisfy $f(p)=1$.



#### tags 

#3500 #fft #math 