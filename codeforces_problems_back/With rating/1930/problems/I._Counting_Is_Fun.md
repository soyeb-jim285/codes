<h1 style='text-align: center;'> I. Counting Is Fun</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a binary$^\dagger$ pattern $p$ of length $n$.

A binary string $q$ of the same length $n$ is called good if for every $i$ ($1 \leq i \leq n$), there exist indices $l$ and $r$ such that: 

* $1 \leq l \leq i \leq r \leq n$, and
* $p_i$ is a mode$^\ddagger$ of the string $q_lq_{l+1}\ldots q_r$.

Count the number of good binary strings modulo $998\,244\,353$.

$^\dagger$ A binary string is a string that only consists of characters $\mathtt{0}$ and $\mathtt{1}$.

$^\ddagger$ Character $c$ is a mode of string $t$ of length $m$ if the number of occurrences of $c$ in $t$ is at least $\lceil \frac{m}{2} \rceil$. For example, $\mathtt{0}$ is a mode of $\mathtt{010}$, $\mathtt{1}$ is not a mode of $\mathtt{010}$, and both $\mathtt{0}$ and $\mathtt{1}$ are modes of $\mathtt{011010}$.

## Input

The first line of input contains a single integer $n$ ($1 \le n \le 10^5$) — the length of the binary string $p$.

The second line of input contains a binary string $p$ of length $n$ consisting of characters 0 and 1.

## Output

## Output

 the number of good strings modulo $998\,244\,353$.

## Examples

## Input


```

10
```
## Output


```

1

```
## Input


```

3111
```
## Output


```

5

```
## Input


```

41011
```
## Output


```

9

```
## Input


```

6110001
```
## Output


```

36

```
## Input


```

12111010001111
```
## Output


```

2441

```
## Note

In the second example, the good strings are 

* $\mathtt{010}$;
* $\mathtt{011}$;
* $\mathtt{101}$;
* $\mathtt{110}$;
* $\mathtt{111}$.


#### tags 

#3500 #combinatorics 