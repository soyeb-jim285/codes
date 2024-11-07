<h1 style='text-align: center;'> B. Minimize Inversions</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two permutations $a$ and $b$ of length $n$. A permutation is an array of $n$ elements from $1$ to $n$ where all elements are distinct. For example, an array [$2,1,3$] is a permutation, but [$0,1$] and [$1,3,1$] aren't.

You can (as many times as you want) choose two indices $i$ and $j$, then swap $a_i$ with $a_j$ and $b_i$ with $b_j$ simultaneously. 

You hate inversions, so you want to minimize the total number of inversions in both permutations.

An inversion in a permutation $p$ is a pair of indices $(i, j)$ such that $i < j$ and $p_i > p_j$. For example, if $p=[3,1,4,2,5]$ then there are $3$ inversions in it (the pairs of indices are $(1,2)$, $(1,4)$ and $(3,4)$).

### Input

The first line contains an integer $t$ ($1 \leq t \leq 20\,000$) — the number of test cases.

Each test case consists of three lines. The first line contains an integer $n$ ($1 \leq n \leq 2\cdot10^5$) — the length of the permutations $a$ and $b$. The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq n$) — permutation $a$. The third line contains $b$ in a similar format. 

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot10^5$.

### Output

For each test case, output two permutations $a'$ and $b'$ (in the same format as in the input) — the permutations after all operations. The total number of inversions in $a'$ and $b'$ should be the minimum possible among all pairs of permutations that can be obtained using operations from the statement.

If there are multiple solutions, print any of them.

## Example

### Input


```text
351 2 3 4 55 4 3 2 133 1 23 1 262 5 6 1 3 41 5 3 6 2 4
```
### Output

```text

3 2 5 1 4
3 4 1 5 2
1 2 3
1 2 3
2 3 4 6 5 1
1 2 4 3 5 6

```
## Note

In the first test case, the minimum possible number of inversions is $10$.

In the second test case, we can sort both permutations at the same time. For this, the following operations can be done:

* Swap the elements in the positions $1$ and $3$ in both permutations. After the operation, $a =$ [$2,1,3$], $b =$ [$2,1,3$].
* Swap the elements in the positions $1$ and $2$. After the operations, $a$ and $b$ are sorted.

In the third test case, the minimum possible number of inversions is $7$.



#### Tags 

#900 #NOT OK #constructive_algorithms #data_structures #greedy #implementation #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_922_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
