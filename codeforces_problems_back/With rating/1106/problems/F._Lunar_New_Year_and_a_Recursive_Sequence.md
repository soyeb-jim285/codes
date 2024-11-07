<h1 style='text-align: center;'> F. Lunar New Year and a Recursive Sequence</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Lunar New Year is approaching, and Bob received a gift from his friend recently — a recursive sequence! He loves this sequence very much and wants to play with it.

Let $f_1, f_2, \ldots, f_i, \ldots$ be an infinite sequence of positive integers. Bob knows that for $i > k$, $f_i$ can be obtained by the following recursive equation:

$$f_i = \left(f_{i - 1} ^ {b_1} \cdot f_{i - 2} ^ {b_2} \cdot \cdots \cdot f_{i - k} ^ {b_k}\right) \bmod p,$$

which in short is

$$f_i = \left(\prod_{j = 1}^{k} f_{i - j}^{b_j}\right) \bmod p,$$

where $p = 998\,244\,353$ (a widely-used prime), $b_1, b_2, \ldots, b_k$ are known integer constants, and $x \bmod y$ denotes the remainder of $x$ divided by $y$.

Bob lost the values of $f_1, f_2, \ldots, f_k$, which is extremely troublesome – these are the basis of the sequence! Luckily, Bob remembers the first $k - 1$ elements of the sequence: $f_1 = f_2 = \ldots = f_{k - 1} = 1$ and the $n$-th element: $f_n = m$. Please find any possible value of $f_k$. If no solution exists, just tell Bob that it is impossible to recover his favorite sequence, regardless of Bob's sadness.

## Input

The first line contains a positive integer $k$ ($1 \leq k \leq 100$), denoting the length of the sequence $b_1, b_2, \ldots, b_k$.

The second line contains $k$ positive integers $b_1, b_2, \ldots, b_k$ ($1 \leq b_i < p$).

The third line contains two positive integers $n$ and $m$ ($k < n \leq 10^9$, $1 \leq m < p$), which implies $f_n = m$.

## Output

## Output

 a possible value of $f_k$, where $f_k$ is a positive integer satisfying $1 \leq f_k < p$. If there are multiple answers, print any of them. If no such $f_k$ makes $f_n = m$, output $-1$ instead.

It is easy to show that if there are some possible values of $f_k$, there must be at least one satisfying $1 \leq f_k < p$.

## Examples

## Input


```

3
2 3 5
4 16

```
## Output


```

4

```
## Input


```

5
4 7 1 5 6
7 14187219

```
## Output


```

6

```
## Input


```

8
2 3 5 6 1 7 9 10
23333 1

```
## Output


```

1

```
## Input


```

1
2
88888 66666

```
## Output


```

-1

```
## Input


```

3
998244352 998244352 998244352
4 2

```
## Output


```

-1

```
## Input


```

10
283 463 213 777 346 201 463 283 102 999
2333333 6263423

```
## Output


```

382480067

```
## Note

In the first sample, we have $f_4 = f_3^2 \cdot f_2^3 \cdot f_1^5$. Therefore, applying $f_3 = 4$, we have $f_4 = 16$. ## Note

 that there can be multiple answers.

In the third sample, applying $f_7 = 1$ makes $f_{23333} = 1$.

In the fourth sample, no such $f_1$ makes $f_{88888} = 66666$. Therefore, we output $-1$ instead.



#### tags 

#2400 #math #matrices #number_theory 