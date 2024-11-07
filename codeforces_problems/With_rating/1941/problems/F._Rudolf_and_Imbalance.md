<h1 style='text-align: center;'> F. Rudolf and Imbalance</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Rudolf has prepared a set of $n$ problems with complexities $a_1 < a_2 < a_3 < \dots < a_n$. He is not entirely satisfied with the balance, so he wants to add at most one problem to fix it.

For this, Rudolf came up with $m$ models of problems and $k$ functions. The complexity of the $i$-th model is $d_i$, and the complexity of the $j$-th function is $f_j$. To create a problem, he selects values $i$ and $j$ ($1 \le i \le m$, $1 \le j \le k$) and by combining the $i$-th model with the $j$-th function, he obtains a new problem with complexity $d_i + f_j$ (a new element is inserted into the array $a$).

To determine the imbalance of the set, Rudolf sorts the complexities of the problems in ascending order and finds the largest value of $a_i - a_{i - 1}$ ($i > 1$).

What is the minimum value of imbalance that Rudolf can achieve by adding at most one problem, created according to the described rules?

### Input

The first line of the input contains a single integer $t$ ($1 \le t \le 10^4$) — the number of testcases.

The first line of each test case contains three integers $n$, $m$, and $k$ ($2 \le n \le 10^5$, $1 \le m, k \le 2 \cdot 10^5$) — the number of prepared problems, the number of models, and the number of functions, respectively.

The second line of each test case contains $n$ integers $a_1, a_2, a_3, \dots a_n$ ($1 \le a_i \le 2 \cdot 10^9$, $a_i < a_{i+1}$) — the complexities of the prepared problems.

The third line of each test case contains $m$ integers $d_1, d_2, d_3, \dots d_m$ ($1 \le d_i \le 10^9$) — the complexities of the models.

The fourth line of each test case contains $k$ integers $f_1, f_2, f_3, \dots f_k$ ($1 \le f_i \le 10^9$) — the complexities of the functions.

It is guaranteed that the sum of $n$ over all testcases does not exceed $10^5$.

It is guaranteed that the sum of $m$ over all testcases does not exceed $2 \cdot 10^5$.

It is guaranteed that the sum of $k$ over all testcases does not exceed $2 \cdot 10^5$.

### Output

For each testcase, output a single number — the minimum imbalance that Rudolf can achieve.

## Example

### Input


```text
75 5 55 10 15 20 2611 14 16 13 816 4 5 3 17 6 51 4 7 10 18 21 222 3 5 7 4 26 8 9 3 27 6 51 4 7 10 18 21 222 3 5 7 4 26 8 13 3 25 6 32 10 13 20 2511 6 10 16 14 56 17 154 2 211 12 14 1519 1410 68 4 23 10 16 18 21 22 29 309 13 16 154 22 4 74 214 15 14 520 1 15 1 12 5 11
```
### Output

```text

5
4
5
8
2
7
11

```


#### Tags 

#1800 #NOT OK #binary_search #greedy #sortings #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_933_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
- [../blogs/https:_codeforces.com_blog_entry_126654.md](../blogs/https:_codeforces.com_blog_entry_126654.md)
