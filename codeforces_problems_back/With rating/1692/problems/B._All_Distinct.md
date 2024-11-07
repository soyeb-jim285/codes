<h1 style='text-align: center;'> B. All Distinct</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Sho has an array $a$ consisting of $n$ integers. An operation consists of choosing two distinct indices $i$ and $j$ and removing $a_i$ and $a_j$ from the array.

For example, for the array $[2, 3, 4, 2, 5]$, Sho can choose to remove indices $1$ and $3$. After this operation, the array becomes $[3, 2, 5]$. ## Note

 that after any operation, the length of the array is reduced by two.

After he made some operations, Sho has an array that has only distinct elements. In addition, he made operations such that the resulting array is the longest possible. 

More formally, the array after Sho has made his operations respects these criteria: 

* No pairs such that ($i < j$) and $a_i = a_j$ exist.
* The length of $a$ is maximized.

## Output

 the length of the final array.

## Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^3$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 50$) — the length of the array.

The second line of each test case contains $n$ integers $a_i$ ($1 \leq a_i \leq 10^4$) — the elements of the array.

## Output

For each test case, output a single integer — the length of the final array. Remember that in the final array, all elements are different, and its length is maximum.

## Example

## Input


```

462 2 2 3 3 359 1 9 9 1415 16 16 15410 100 1000 10000
```
## Output


```

2
1
2
4

```
## Note

For the first test case Sho can perform operations as follows: 

1. Choose indices $1$ and $5$ to remove. The array becomes $[2, 2, 2, 3, 3, 3] \rightarrow [2, 2, 3, 3]$.
2. Choose indices $1$ and $4$ to remove. The array becomes $[2, 2, 3, 3] \rightarrow [2, 3]$.

 The final array has a length of $2$, so the answer is $2$. It can be proven that Sho cannot obtain an array with a longer length.For the second test case Sho can perform operations as follows: 

1. Choose indices $3$ and $4$ to remove. The array becomes $[9, 1, 9, 9, 1] \rightarrow [9, 1, 1]$.
2. Choose indices $1$ and $3$ to remove. The array becomes $[9, 1, 1] \rightarrow [1]$.

 The final array has a length of $1$, so the answer is $1$. It can be proven that Sho cannot obtain an array with a longer length.

#### tags 

#800 #greedy #sortings 