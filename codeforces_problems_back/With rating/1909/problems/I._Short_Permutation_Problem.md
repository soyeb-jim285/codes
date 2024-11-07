<h1 style='text-align: center;'> I. Short Permutation Problem</h1>

<h5 style='text-align: center;'>time limit per test: 7 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

[Xomu - Last Dance](https://soundcloud.com/xomuu/xomu-last-dance)⠀You are given an integer $n$.

For each $(m, k)$ such that $3 \leq m \leq n+1$ and $0 \leq k \leq n-1$, count the permutations of $[1, 2, ..., n]$ such that $p_i + p_{i+1} \geq m$ for exactly $k$ indices $i$, modulo $998\,244\,353$.

## Input

The input consists of a single line, which contains two integers $n$, $x$ ($2 \leq n \leq 4000$, $1 \leq x < 1\,000\,000\,007$).

## Output

Let $a_{m,k}$ be the answer for the pair $(m, k)$, modulo $998\,244\,353$.

Let $$\large S = \sum_{m=3}^{n+1} \sum_{k=0}^{n-1} a_{m,k}x^{mn+k}\phantom{0}.$$

## Output

 a single line with an integer: $S$ modulo $1\,000\,000\,007$.

## Note

 that using two different modulos is intentional. We want you to calculate all the $a_{m,k}$ modulo $998\,244\,353$, then treat them like integers in the range $[0, 998\,244\,352]$, and hash them modulo $1\,000\,000\,007$.

## Examples

## Input


```

3 2
```
## Output


```

77824

```
## Input


```

4 1000000000
```
## Output


```

30984329

```
## Input


```

8 327869541
```
## Output


```

85039220

```
## Input


```

4000 1149333
```
## Output


```

584870166

```
## Note

In the first test case, the answers for all $(m, k)$ are shown in the following table:

 

|  | $k = 0$ | $k = 1$ | $k = 2$ |
| --- | --- | --- | --- |
| $m = 3$ | $0$ | $0$ | $6$ |
| $m = 4$ | $0$ | $4$ | $2$ |

 * The answer for $(m, k) = (3, 2)$ is $6$, because for every permutation of length $3$, $a_i + a_{i+1} \geq 3$ exactly $2$ times.
* The answer for $(m, k) = (4, 2)$ is $2$. In fact, there are $2$ permutations of length $3$ such that $a_i + a_{i+1} \geq 4$ exactly $2$ times: $[1, 3, 2]$, $[2, 3, 1]$.

Therefore, the value to print is $2^9 \cdot 0 + 2^{10} \cdot 0 + 2^{11} \cdot 6 + 2^{12} \cdot 0 + 2^{13} \cdot 4 + 2^{14} \cdot 2 \equiv 77\,824 \phantom{0} (\text{mod} \phantom{0} 1\,000\,000\,007)$.

In the second test case, the answers for all $(m, k)$ are shown in the following table:

 

|  | $k = 0$ | $k = 1$ | $k = 2$ | $k = 3$ |
| --- | --- | --- | --- | --- |
| $m = 3$ | $0$ | $0$ | $0$ | $24$ |
| $m = 4$ | $0$ | $0$ | $12$ | $12$ |
| $m = 5$ | $0$ | $4$ | $16$ | $4$ |

 * The answer for $(m, k) = (5, 1)$ is $4$. In fact, there are $4$ permutations of length $4$ such that $a_i + a_{i+1} \geq 5$ exactly $1$ time: $[2, 1, 3, 4]$, $[3, 1, 2, 4]$, $[4, 2, 1, 3]$, $[4, 3, 1, 2]$.

In the third test case, the answers for all $(m, k)$ are shown in the following table:

 

|  | $k = 0$ | $k = 1$ | $k = 2$ | $k = 3$ | $k = 4$ | $k = 5$ | $k = 6$ | $k = 7$ |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| $m = 3$ | $0$ | $0$ | $0$ | $0$ | $0$ | $0$ | $0$ | $40320$ |
| $m = 4$ | $0$ | $0$ | $0$ | $0$ | $0$ | $0$ | $10080$ | $30240$ |
| $m = 5$ | $0$ | $0$ | $0$ | $0$ | $0$ | $1440$ | $17280$ | $21600$ |
| $m = 6$ | $0$ | $0$ | $0$ | $0$ | $480$ | $8640$ | $21600$ | $9600$ |
| $m = 7$ | $0$ | $0$ | $0$ | $96$ | $3456$ | $16416$ | $16896$ | $3456$ |
| $m = 8$ | $0$ | $0$ | $48$ | $2160$ | $12960$ | $18240$ | $6480$ | $432$ |
| $m = 9$ | $0$ | $16$ | $1152$ | $9648$ | $18688$ | $9648$ | $1152$ | $16$ |

 

#### tags 

#1900 #combinatorics #dp #fft #math 