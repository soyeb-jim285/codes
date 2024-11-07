<h1 style='text-align: center;'> C. Dora and Search</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

As you know, the girl Dora is always looking for something. This time she was given a permutation, and she wants to find such a subsegment of it that none of the elements at its ends is either the minimum or the maximum of the entire subsegment. More formally, you are asked to find the numbers $l$ and $r$ $(1 \leq l \leq r \leq n)$ such that $a_l \neq \min(a_l, a_{l + 1}, \ldots, a_r)$, $a_l \neq \max(a_l, a_{l + 1}, \ldots, a_r)$ and $a_r \neq \min(a_l, a_{l + 1}, \ldots, a_r)$, $a_r \neq \max(a_l, a_{l + 1}, \ldots, a_r)$.

A permutation of length $n$ is an array consisting of $n$ distinct integers from $1$ to $n$ in any order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ occurs twice in the array) and $[1,3,4]$ is also not a permutation ($n=3$, but $4$ is present in the array).

Help Dora find such a subsegment, or tell her that such a subsegment does not exist.

### Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. Description of the test cases follows.

For each test case, the first line contains one integer $n$ ($1 \leq n \leq 2 \cdot 10^5$) — the length of permutation.

The second line contains $n$ distinct integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq n$) — the elements of permutation. 

It is guarented that the sum of $n$ over all test cases doesn't exceed $2 \cdot 10^5$.

### Output

For each test case, output $-1$ if the desired subsegment does not exist.

Otherwise, output two indexes $l, r$ such that $[a_{l}, a_{l + 1}, \ldots, a_{r}]$ satisfies all conditions.

If there are several solutions, then output any of them.

## Example

### Input


```text
431 2 342 1 4 371 3 2 4 6 5 762 3 6 5 4 1
```
### Output

```text

-1
1 4
2 6
-1

```
## Note

In the first and fourth test cases, it can be shown that there are no desired subsegments.

In the second test case, the subsegment $[1, 4]$ satisfies all the conditions, because $\max(a_1, a_2, a_3, a_4) = 4, \min(a_1, a_2, a_3, a_4) = 1$, as we see, all the conditions are met.

In the third test case, the subsegment $[2, 6]$ also satisfies all the conditions described.



#### Tags 

#1200 #NOT OK #constructive_algorithms #data_structures #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_852_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
