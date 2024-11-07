<h1 style='text-align: center;'> G. Euclid Guess</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's consider Euclid's algorithm for finding the [greatest common divisor](https://en.wikipedia.org/wiki/Greatest_common_divisor), where $t$ is a list:


```
  
function Euclid(a, b):  
    if a < b:  
        swap(a, b)  
  
    if b == 0:  
        return a  
  
    r = reminder from dividing a by b  
    if r > 0:  
        append r to the back of t  
  
    return Euclid(b, r)  

```
There is an array $p$ of pairs of positive integers that are not greater than $m$. Initially, the list $t$ is empty. Then the function is run on each pair in $p$. After that the list $t$ is shuffled and given to you.

You have to find an array $p$ of any size not greater than $2 \cdot 10^4$ that produces the given list $t$, or tell that no such array exists.

## Input

The first line contains two integers $n$ and $m$ ($1 \le n \le 10^3$, $1 \le m \le 10^9$) — the length of the array $t$ and the constraint for integers in pairs.

The second line contains $n$ integers $t_1, t_2, \ldots, t_n$ ($1 \le t_i \le m$) — the elements of the array $t$.

## Output

* If the answer does not exist, output $-1$.
* If the answer exists, in the first line output $k$ ($1 \le k \le 2 \cdot 10^4$) — the size of your array $p$, i. e. the number of pairs in the answer. The $i$-th of the next $k$ lines should contain two integers $a_i$ and $b_i$ ($1 \le a_i, b_i \le m$) — the $i$-th pair in $p$.

If there are multiple valid answers you can output any of them.

## Examples

## Input


```

7 20
1 8 1 6 3 2 3

```
## Output


```

3
19 11
15 9
3 7

```
## Input


```

2 10
7 1

```
## Output


```

-1
```
## Input


```

2 15
1 7

```
## Output


```

1
15 8

```
## Input


```

1 1000000000
845063470

```
## Output


```

-1
```
## Note

In the first sample let's consider the array $t$ for each pair: 

* $(19,\, 11)$: $t = [8, 3, 2, 1]$;
* $(15,\, 9)$: $t = [6, 3]$;
* $(3,\, 7)$: $t = [1]$.

So in total $t = [8, 3, 2, 1, 6, 3, 1]$, which is the same as the input $t$ (up to a permutation).

In the second test case it is impossible to find such array $p$ of pairs that all integers are not greater than $10$ and $t = [7, 1]$

In the third test case for the pair $(15,\, 8)$ array $t$ will be $[7, 1]$.



#### tags 

#2800 #constructive_algorithms #flows #graph_matchings #math #number_theory 