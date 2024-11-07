<h1 style='text-align: center;'> B. Mystic Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp is a little boy who lives in Byteland and he loves programming.

Recently, he found a permutation of length $n$. He has to come up with a mystic permutation. It has to be a new permutation such that it differs from the old one in each position.

More formally, if the old permutation is $p_1,p_2,\ldots,p_n$ and the new one is $q_1,q_2,\ldots,q_n$ it must hold that $$p_1\neq q_1, p_2\neq q_2, \ldots ,p_n\neq q_n.$$

Monocarp is afraid of lexicographically large permutations. Can you please help him to find the lexicographically minimal mystic permutation?

### Input

There are several test cases in the input data. The first line contains a single integer $t$ ($1\leq t\leq 200$) — the number of test cases. This is followed by the test cases description.

The first line of each test case contains a positive integer $n$ ($1\leq n\leq 1000$) — the length of the permutation.

The second line of each test case contains $n$ distinct positive integers $p_1, p_2, \ldots, p_n$ ($1 \leq p_i \leq n$). It's guaranteed that $p$ is a permutation, i. e. $p_i \neq p_j$ for all $i \neq j$. 

It is guaranteed that the sum of $n$ does not exceed $1000$ over all test cases.

### Output

For each test case, output $n$ positive integers — the lexicographically minimal mystic permutations. If such a permutation does not exist, output $-1$ instead.

## Example

### Input


```text
431 2 352 3 4 5 142 3 1 411
```
### Output

```text

2 3 1
1 2 3 4 5
1 2 4 3
-1

```
## Note

In the first test case possible permutations that are mystic are $[2,3,1]$ and $[3,1,2]$. Lexicographically smaller of the two is $[2,3,1]$.

In the second test case, $[1,2,3,4,5]$ is the lexicographically minimal permutation and it is also mystic.

In third test case possible mystic permutations are $[1,2,4,3]$, $[1,4,2,3]$, $[1,4,3,2]$, $[3,1,4,2]$, $[3,2,4,1]$, $[3,4,2,1]$, $[4,1,2,3]$, $[4,1,3,2]$ and $[4,3,2,1]$. The smallest one is $[1,2,4,3]$.



#### Tags 

#900 #OK #data_structures #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_798_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
