<h1 style='text-align: center;'> F. Bomb</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Sparkle gives you two arrays $a$ and $b$ of length $n$. Initially, your score is $0$. In one operation, you can choose an integer $i$ and add $a_i$ to your score. Then, you must set $a_i$ = $\max(0, a_i - b_i)$.

You only have time to perform $k$ operations before Sparkle sets off a nuclear bomb! What is the maximum score you can acquire after $k$ operations?

### Input

The first line contains $t$ ($1 \leq t \leq 1000$) — the number of test cases.

The first line of each test case contains $n$ and $k$ ($1 \leq n \leq 2 \cdot 10^5, 1 \leq k \leq 10^9$) — the length of the arrays and the number of operations you can perform.

The following line contains $n$ integers $a_1, a_2, ... a_n$ ($1 \leq a_i \leq 10^9$).

The following line contains $n$ integers $b_1, b_2, ... b_n$ ($1 \leq b_i \leq 10^9$).

It is guaranteed that the sum of $n$ for all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output an integer, the maximum score you can acquire after $k$ operations.

## Example

### Input


```text
53 45 6 72 3 45 932 52 68 64 1418 14 53 24 85 10001 2 3 4 55 4 3 2 11 10000001000000110 63 3 5 10 6 8 6 8 7 76 1 7 4 1 1 8 9 3 1
```
### Output

```text

21
349
27
500000500000
47

```


#### Tags 

#NOT OK #binary_search #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_962_(Div._3).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Video Tutorial 2 (en)](../blogs/Video_Tutorial_2_(en).md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
- [Tutorial #3 (en)](../blogs/Tutorial_3_(en).md)
