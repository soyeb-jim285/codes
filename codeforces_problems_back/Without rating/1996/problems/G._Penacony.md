<h1 style='text-align: center;'> G. Penacony</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

On Penacony, The Land of the Dreams, there exists $n$ houses and $n$ roads. There exists a road between house $i$ and $i+1$ for all $1 \leq i \leq n-1$ and a road between house $n$ and house $1$. All roads are bidirectional. However, due to the crisis on Penacony, the overseeing family has gone into debt and may not be able to maintain all roads.

There are $m$ pairs of friendships between the residents of Penacony. If the resident living in house $a$ is friends with the resident living in house $b$, there must be a path between houses $a$ and $b$ through maintained roads. 

What is the minimum number of roads that must be maintained?

## Input

The first line contains $t$ ($1 \leq t \leq 10^4$) – the number of test cases.

The first line of each test case contains two integers $n$ and $m$ ($3 \leq n \leq 2 \cdot 10^5, 1 \leq m \leq 2 \cdot 10^5$) – the number of houses and the number of friendships.

The next $m$ lines contain two integers $a$ and $b$ ($1 \leq a < b \leq n$) – the resident in house $a$ is friends with the resident in house $b$. It is guaranteed all ($a, b$) are distinct.

It is guaranteed the sum of $n$ and $m$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output an integer, the minimum number of roads that must be maintained.

## Example

## Input


```

78 31 82 74 513 41 132 123 114 1010 22 33 410 43 85 102 104 104 11 35 23 51 45 22 51 3
```
## Output


```

4
7
2
7
2
3
3

```
## Note

For the first test case, the following roads must be maintained:

* $8 \leftarrow \rightarrow 1$
* $7 \leftarrow \rightarrow 8$
* $1 \leftarrow \rightarrow 2$
* $4 \leftarrow \rightarrow 5$


#### tags 

#brute_force #data_structures #greedy #hashing 