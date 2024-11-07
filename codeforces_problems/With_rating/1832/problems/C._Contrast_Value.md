<h1 style='text-align: center;'> C. Contrast Value</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

For an array of integers $[a_1, a_2, \dots, a_n]$, let's call the value $|a_1-a_2|+|a_2-a_3|+\cdots+|a_{n-1}-a_n|$ the contrast of the array. Note that the contrast of an array of size $1$ is equal to $0$.

You are given an array of integers $a$. Your task is to build an array of $b$ in such a way that all the following conditions are met:

* $b$ is not empty, i.e there is at least one element;
* $b$ is a subsequence of $a$, i.e $b$ can be produced by deleting some elements from $a$ (maybe zero);
* the contrast of $b$ is equal to the contrast of $a$.

What is the minimum possible size of the array $b$?

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \le n \le 3 \cdot 10^5$) — the size of the array $a$.

The second line contains $n$ integers $a_1, a_2, \cdot, a_n$ ($0 \le a_i \le 10^9$) — elements of the array itself.

The sum of $n$ over all test cases doesn't exceed $3 \cdot 10^5$.

### Output

For each test case, print a single integer — the minimum possible size of the array $b$.

## Example

### Input


```text
451 3 3 3 724 241 1 1 175 4 2 1 0 0 4
```
### Output

```text

2
2
1
3

```


#### Tags 

#1200 #OK #greedy #implementation 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_148_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
