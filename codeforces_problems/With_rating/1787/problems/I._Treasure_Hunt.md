<h1 style='text-align: center;'> I. Treasure Hunt</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Define the beauty value of a sequence $b_1,b_2,\ldots,b_c$ as the maximum value of $\sum\limits_{i=1}^{q}b_i + \sum\limits_{i=s}^{t}b_i$, where $q$, $s$, $t$ are all integers and $s > q$ or $t\leq q$. 
## Note

 that $b_i = 0$ when $i<1$ or $i>c$, $\sum\limits_{i=s}^{t}b_i = 0$ when $s>t$.

For example, when $b = [-1,-2,-3]$, we may have $q = 0$, $s = 3$, $t = 2$ so the beauty value is $0 + 0 = 0$. And when $b = [-1,2,-3]$, we have $q = s = t = 2$ so the beauty value is $1 + 2 = 3$.

You are given a sequence $a$ of length $n$, determine the sum of the beauty value of all non-empty subsegments $a_l,a_{l+1},\ldots,a_r$ ($1\leq l\leq r\leq n$) of the sequence $a$.

Print the answer modulo $998\,244\,353$.

### Input

Each test contains multiple test cases. The first line contains an integer $T$ ($1 \le T \le 10^4$) — the number of test cases.

The first line contains an integer $n$ ($1\le n\le 10^6$) — the length of $a$.

The second line contains $n$ integers $a_1,a_2,\ldots,a_n$ ($-10^6 \leq a_i \leq 10^6$) — the given sequence.

It's guaranteed that the sum of $n$ does not exceed $10^6$.

### Output

For each test case, print a line containing a single integer — the answer modulo $998\,244\,353$.

## Example

### Input


```text
4780 59 100 -52 -86 -62 758-48 -14 -26 43 -41 34 13 551742056 -60 62 13 88 -48 64 36 -10 19 94 25 -69 88 87 79 -70 74 -26 59
```
### Output

```text

5924
2548
148
98887

```
## Note

In the second test case, for the subsequence $[-26,43,-41,34,13]$, when $q=5$, $s=2$, $t=5$, $\sum\limits_{i=1}^{q}b_i + \sum\limits_{i=s}^{t}b_i = 23 + 49 = 72$.

In the third test case, there is only one non-empty consecutive subsequence $[74]$. When $q=1$, $s=1$, $t=1$, $\sum\limits_{i=1}^{q}b_i + \sum\limits_{i=s}^{t}b_i = 148$.



#### Tags 

#3400 #NOT OK #data_structures #divide_and_conquer #two_pointers 

## Blogs
- [All Contest Problems](../TypeDB_Forces_2023_(Div._1_+_Div._2,_Rated,_Prizes!).md)
- [Announcement #1 (en)](../blogs/Announcement_1_(en).md)
- [TypeDB Forces 2023 (en)](../blogs/TypeDB_Forces_2023_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
