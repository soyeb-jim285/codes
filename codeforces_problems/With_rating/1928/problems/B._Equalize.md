<h1 style='text-align: center;'> B. Equalize</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya has two hobbies — adding permutations$^{\dagger}$ to arrays and finding the most frequently occurring element. Recently, he found an array $a$ and decided to find out the maximum number of elements equal to the same number in the array $a$ that he can obtain after adding some permutation to the array $a$.

More formally, Vasya must choose exactly one permutation $p_1, p_2, p_3, \ldots, p_n$ of length $n$, and then change the elements of the array $a$ according to the rule $a_i := a_i + p_i$. After that, Vasya counts how many times each number occurs in the array $a$ and takes the maximum of these values. You need to determine the maximum value he can obtain.

$^{\dagger}$A permutation of length $n$ is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array), and $[1,3,4]$ is also not a permutation ($n=3$ but there is $4$ in the array).

### Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 2 \cdot 10^4$) — the number of test cases. Then follows the description of the test cases.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the length of the array $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$) — the elements of the array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output a single number — the maximum number of elements equal to the same number after the operation of adding a permutation.

## Example

### Input


```text
721 247 1 4 13103 102 10451 101 1 100 151 10 100 1000 123 131000000000 999999997 999999999
```
### Output

```text

2
2
3
2
1
1
2

```
## Note

In the first test case, it is optimal to choose $p = [2, 1]$. Then after applying the operation, the array $a$ will be $[3, 3]$, in which the number $3$ occurs twice, so the answer is $2$.

In the second test case, one of the optimal options is $p = [2, 3, 1, 4]$. After applying the operation, the array $a$ will be $[9, 4, 5, 5]$. Since the number $5$ occurs twice, the answer is $2$.



#### Tags 

#1200 #OK #binary_search #greedy #sortings #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_924_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
