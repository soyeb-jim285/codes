<h1 style='text-align: center;'> G. Unequal Adjacent Elements</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ consisting of $n$ positive integers. 

Find any permutation $p$ of $[1,2,\dots,n]$ such that:

* $p_{i-2} < p_i$ for all $i$, where $3 \leq i \leq n$, and
* $a_{p_{i-1}} \neq a_{p_i}$ for all $i$, where $2 \leq i \leq n$.

Or report that no such permutation exists.

### Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^5$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($3 \leq n \leq 3 \cdot 10^5$) — the length of the array $a$.

The second line of each test case contains $n$ space-separated integers $a_1,a_2,\ldots,a_n$ ($1 \leq a_i \leq n$) — representing the array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $3 \cdot 10^5$.

### Output

For each test case, output "NO" if no such permutation exists, otherwise output "YES" in the first line and print the permutation $p$ in the next line.

In case there are multiple permutations, print any one of them.

You can output "YES" and "NO" in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive response).

## Example

### Input


```text
431 2 141 2 3 431 1 171 2 1 1 3 1 4
```
### Output

```text

YES
1 2 3
YES
3 1 4 2
NO
YES
1 2 3 5 4 7 6

```
## Note

In the first test case, $p=[1,2,3]$ is the only permutation of $[1,2,3]$ that satisfy the given constraints.

In the second test case, $[1,3,2,4]$, $[2,1,4,3]$ and some other permutations are also acceptable.

In the third test case, it can be proved that there does not exist any permutation of $[1,2,3]$ satisfying the given constraints.



#### Tags 

#3100 #NOT OK #constructive_algorithms #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_838_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
