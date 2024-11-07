<h1 style='text-align: center;'> C. Johnny and Megan's Necklace</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Johnny's younger sister Megan had a birthday recently. Her brother has bought her a box signed as "Your beautiful necklace — do it yourself!". It contains many necklace parts and some magic glue. 

The necklace part is a chain connecting two pearls. Color of each pearl can be defined by a non-negative integer. The magic glue allows Megan to merge two pearls (possibly from the same necklace part) into one. The beauty of a connection of pearls in colors $u$ and $v$ is defined as follows: let $2^k$ be the greatest power of two dividing $u \oplus v$ — [exclusive or](https://en.wikipedia.org/wiki/Exclusive_or#Computer_science) of $u$ and $v$. Then the beauty equals $k$. If $u = v$, you may assume that beauty is equal to $20$.

Each pearl can be combined with another at most once. Merging two parts of a necklace connects them. Using the glue multiple times, Megan can finally build the necklace, which is a cycle made from connected necklace parts (so every pearl in the necklace is combined with precisely one other pearl in it). The beauty of such a necklace is the minimum beauty of a single connection in it. The girl wants to use all available necklace parts to build exactly one necklace consisting of all of them with the largest possible beauty. Help her!

## Input

The first line contains $n$ $(1 \leq n \leq 5 \cdot 10^5)$ — the number of necklace parts in the box. Each of the next $n$ lines contains two integers $a$ and $b$ $(0 \leq a, b < 2^{20})$, which denote colors of pearls presented in the necklace parts. Pearls in the $i$-th line have indices $2i - 1$ and $2i$ respectively.

## Output

The first line should contain a single integer $b$ denoting the maximum possible beauty of a necklace built from all given parts.

The following line should contain $2n$ distinct integers $p_i$ $(1 \leq p_i \leq 2n)$ — the indices of initial pearls in the order in which they appear on a cycle. Indices of pearls belonging to the same necklace part have to appear at neighboring positions in this permutation (so $1\,4\,3\,2$ is not a valid output, whereas $2\,1\,4\,3$ and $4\,3\,1\,2$ are). If there are many possible answers, you can print any.

## Examples

## Input


```

5
13 11
11 1
3 5
17 1
9 27

```
## Output


```

3
8 7 9 10 5 6 1 2 3 4 

```
## Input


```

5
13 11
11 1
3 5
17 1
7 29

```
## Output


```

2
8 7 10 9 5 6 4 3 2 1 

```
## Input


```

1
1 1

```
## Output


```

20
2 1 

```
## Note

In the first example the following pairs of pearls are combined: $(7, 9)$, $(10, 5)$, $(6, 1)$, $(2, 3)$ and $(4, 8)$. The beauties of connections equal correspondingly: $3$, $3$, $3$, $20$, $20$.

The following drawing shows this construction.

 ![](images/69d60d8bfa6bc79bd945ddb77b0979b45ae8d7f1.png) 

#### tags 

#2500 #binary_search #bitmasks #constructive_algorithms #dfs_and_similar #dsu #graphs 