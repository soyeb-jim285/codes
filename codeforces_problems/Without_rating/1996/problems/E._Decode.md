<h1 style='text-align: center;'> E. Decode</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In a desperate attempt to obtain your waifu favorite character, you have hacked into the source code of the game. After days of struggling, you finally find the binary string that encodes the gacha system of the game. In order to decode it, you must first solve the following problem. 

You are given a binary string $s$ of length $n$. For each pair of integers $(l, r)$ $(1 \leq l \leq r \leq n)$, count the number of pairs $(x, y)$ $(l \leq x \leq y \leq r)$ such that the amount of $\mathtt{0}$ equals the amount of $\mathtt{1}$ in the substring $s_xs_{x+1}...s_y$. 

### Output

 the sum of counts over all possible $(l, r)$ modulo $10^9+7$.

### Input

The first line contains $t$ ($1 \leq t \leq 1000$) — the number of test cases.

Each test case contains a binary string $s$ ($1 \leq |s| \leq 2 \cdot 10^5$). It is guaranteed $s$ only contains characters $\mathtt{0}$ and $\mathtt{1}$.

It is guaranteed the sum of $|s|$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output an integer, the answer modulo $10^9+7$.

## Example

### Input


```text
4000001010101110011100111000000111
```
### Output

```text

0
130
147
70

```


#### Tags 

#NOT OK #combinatorics #data_structures #implementation #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_962_(Div._3).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Video Tutorial 2 (en)](../blogs/Video_Tutorial_2_(en).md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
- [Tutorial #3 (en)](../blogs/Tutorial_3_(en).md)
