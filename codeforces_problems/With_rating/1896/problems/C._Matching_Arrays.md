<h1 style='text-align: center;'> C. Matching Arrays</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two arrays $a$ and $b$ of size $n$. The beauty of the arrays $a$ and $b$ is the number of indices $i$ such that $a_i > b_i$.

You are also given an integer $x$. Determine whether it is possible to rearrange the elements of $b$ such that the beauty of the arrays becomes $x$. If it is possible, output one valid rearrangement of $b$.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains two integers $n$ and $x$ ($1 \le n \le 2\cdot 10^5$, $0 \le x \le n$) — the size of arrays $a$ and $b$ and the desired beauty of the arrays.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 2n$) — the elements of array $a$.

The third line of each test case contains $n$ integers $b_1, b_2, \ldots, b_n$ ($1 \le b_i \le 2n$) — the elements of array $b$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot 10^5$.

### Output

For each test case, output "NO" if it is not possible to rearrange $b$ to make the beauty of the arrays equal to $x$.

Otherwise, output "YES". Then, on the next line, output $n$ integers which represent the rearrangement of $b$.

If there are multiple solutions, you may output any of them.

You can output "YES" and "NO" in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

## Example

### Input


```text
71 0121 1123 02 4 34 1 23 12 4 34 1 23 22 4 34 1 23 32 4 34 1 25 26 4 5 6 29 7 9 1 1
```
### Output

```text

YES
2
NO
NO
YES
2 4 1
YES
4 1 2
NO
YES
1 9 9 7 1

```
## Note

In test cases 1 and 2, the beauty of the arrays has to be $0$ since $a_1 = 1 \le 2 = b_1$.

In test cases 3, 4, 5 and 6, the only possible beauty of the arrays is $x = 1$ and $x = 2$. In particular, if $b$ is rearranged to $[2, 4, 1]$, then $a_3 = 3 > 1 = b_3$, so the beauty of the arrays is $1$. If $b$ is kept in the same order as given the input, then $a_2 = 4 > b_2 = 1$ and $a_3 = 3 > 2 = b_3$, so the beauty of the arrays is $2$.



#### Tags 

#1400 #NOT OK #binary_search #constructive_algorithms #greedy #sortings 

## Blogs
- [All Contest Problems](../CodeTON_Round_7_(Div._1_+_Div._2,_Rated,_Prizes!).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
