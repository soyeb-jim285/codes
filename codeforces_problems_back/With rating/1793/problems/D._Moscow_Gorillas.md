<h1 style='text-align: center;'> D. Moscow Gorillas</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In winter, the inhabitants of the Moscow Zoo are very bored, in particular, it concerns gorillas. You decided to entertain them and brought a permutation $p$ of length $n$ to the zoo.

A permutation of length $n$ is an array consisting of $n$ distinct integers from $1$ to $n$ in any order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ occurs twice in the array) and $[1,3,4]$ is also not a permutation ($n=3$, but $4$ is present in the array).

The gorillas had their own permutation $q$ of length $n$. They suggested that you count the number of pairs of integers $l, r$ ($1 \le l \le r \le n$) such that $\operatorname{MEX}([p_l, p_{l+1}, \ldots, p_r])=\operatorname{MEX}([q_l, q_{l+1}, \ldots, q_r])$.

The $\operatorname{MEX}$ of the sequence is the minimum integer positive number missing from this sequence. For example, $\operatorname{MEX}([1, 3]) = 2$, $\operatorname{MEX}([5]) = 1$, $\operatorname{MEX}([3, 1, 2, 6]) = 4$.

You do not want to risk your health, so you will not dare to refuse the gorillas.

## Input

The first line contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the permutations length.

The second line contains $n$ integers $p_1, p_2, \ldots, p_n$ ($1 \le p_i \le n$) — the elements of the permutation $p$.

The third line contains $n$ integers $q_1, q_2, \ldots, q_n$ ($1 \le q_i \le n$) — the elements of the permutation $q$.

## Output

Print a single integer — the number of suitable pairs $l$ and $r$.

## Examples

## Input


```

31 3 22 1 3
```
## Output


```

2

```
## Input


```

77 3 6 2 1 5 46 7 2 5 3 1 4
```
## Output


```

16

```
## Input


```

61 2 3 4 5 66 5 4 3 2 1
```
## Output


```

11

```
## Note

In the first example, two segments are correct – $[1, 3]$ with $\operatorname{MEX}$ equal to $4$ in both arrays and $[3, 3]$ with $\operatorname{MEX}$ equal to $1$ in both of arrays.

In the second example, for example, the segment $[1, 4]$ is correct, and the segment $[6, 7]$ isn't correct, because $\operatorname{MEX}(5, 4) \neq \operatorname{MEX}(1, 4)$.



#### tags 

#1800 #binary_search #dp #greedy #implementation #math #two_pointers 