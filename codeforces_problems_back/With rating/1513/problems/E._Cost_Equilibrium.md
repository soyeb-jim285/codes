<h1 style='text-align: center;'> E. Cost Equilibrium</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

An array is called beautiful if all the elements in the array are equal.

You can transform an array using the following steps any number of times: 

1. Choose two indices $i$ and $j$ ($1 \leq i,j \leq n$), and an integer $x$ ($1 \leq x \leq a_i$). Let $i$ be the source index and $j$ be the sink index.
2. Decrease the $i$-th element by $x$, and increase the $j$-th element by $x$. The resulting values at $i$-th and $j$-th index are $a_i-x$ and $a_j+x$ respectively.
3. The cost of this operation is $x \cdot |j-i| $.
4. Now the $i$-th index can no longer be the sink and the $j$-th index can no longer be the source.

 The total cost of a transformation is the sum of all the costs in step $3$.For example, array $[0, 2, 3, 3]$ can be transformed into a beautiful array $[2, 2, 2, 2]$ with total cost $1 \cdot |1-3| + 1 \cdot |1-4| = 5$.

An array is called balanced, if it can be transformed into a beautiful array, and the cost of such transformation is uniquely defined. In other words, the minimum cost of transformation into a beautiful array equals the maximum cost.

You are given an array $a_1, a_2, \ldots, a_n$ of length $n$, consisting of non-negative integers. Your task is to find the number of balanced arrays which are permutations of the given array. Two arrays are considered different, if elements at some position differ. Since the answer can be large, output it modulo $10^9 + 7$.

## Input

The first line contains a single integer $n$ ($1 \leq n \leq 10^5$) — the size of the array. 

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le 10^9$).

## Output

## Output

 a single integer — the number of balanced permutations modulo $10^9+7$.

## Examples

## Input


```

3
1 2 3

```
## Output


```

6
```
## Input


```

4
0 4 0 4

```
## Output


```

2
```
## Input


```

5
0 11 12 13 14

```
## Output


```

120
```
## Note

In the first example, $[1, 2, 3]$ is a valid permutation as we can consider the index with value $3$ as the source and index with value $1$ as the sink. Thus, after conversion we get a beautiful array $[2, 2, 2]$, and the total cost would be $2$. We can show that this is the only transformation of this array that leads to a beautiful array. Similarly, we can check for other permutations too.

In the second example, $[0, 0, 4, 4]$ and $[4, 4, 0, 0]$ are balanced permutations.

In the third example, all permutations are balanced.



#### tags 

#2300 #combinatorics #constructive_algorithms #math #sortings 