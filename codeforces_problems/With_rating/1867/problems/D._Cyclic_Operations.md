<h1 style='text-align: center;'> D. Cyclic Operations</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Egor has an array $a$ of length $n$, initially consisting of zeros. However, he wanted to turn it into another array $b$ of length $n$.

Since Egor doesn't take easy paths, only the following operation can be used (possibly zero or several times):

* choose an array $l$ of length $k$ ($1 \leq l_i \leq n$, all $l_i$ are distinct) and change each element $a_{l_i}$ to $l_{(i\%k)+1}$ ($1 \leq i \leq k$).

He became interested in whether it is possible to get the array $b$ using only these operations. Since Egor is still a beginner programmer, he asked you to help him solve this problem.

The operation $\%$ means taking the remainder, that is, $a\%b$ is equal to the remainder of dividing the number $a$ by the number $b$.

### Input

The first line of the input contains an integer $t$ ($1 \leq t \leq 10^5$) - the number of test cases.

Each test case consists of two lines. The first line contains two integers $n$ and $k$ ($1 \leq k \leq n \leq 10^5$).

The second line contains the array $b_1, b_2, \ldots, b_n$ ($1 \leq b_i \leq n$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output "YES" (without quotes) if there is a way to get the array $b$ using only the given operation. Otherwise, output "NO" (without quotes). You can output each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes" and "YES" will be accepted as a positive answer.

## Example

### Input


```text
65 32 3 5 3 44 22 4 3 11 113 11 2 35 35 4 3 2 16 11 2 3 1 5 6
```
### Output

```text

YES
NO
YES
YES
NO
NO

```
## Note

Let's consider the first example: 

* Apply the operation with $l$ = $[1,2,3]$. Now $a$ = $[2,3,1,0,0]$.
* Apply the operation with $l$ = $[3,5,4]$. Now $a$ = $[2,3,5,3,4]$ = $b$.

 We see that it is possible to get the array $b$. Therefore, the answer is YES.In the second example, it can be proven that the array $b$ cannot be obtained, therefore the answer is NO.



#### Tags 

#1800 #NOT OK #brute_force #constructive_algorithms #dfs_and_similar #graphs #greedy #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_897_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Editorial (en)](../blogs/Editorial_(en).md)
