<h1 style='text-align: center;'> D. Reverse Madness</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string $s$ of length $n$, containing lowercase Latin letters. 

Next you will be given a positive integer $k$ and two arrays, $l$ and $r$ of length $k$.

It is guaranteed that the following conditions hold for these 2 arrays: 

* $l_1 = 1$;
* $r_k = n$;
* $l_i \le r_i$, for each positive integer $i$ such that $1 \le i \le k$;
* $l_i = r_{i-1}+1$, for each positive integer $i$ such that $2 \le i \le k$;

Now you will be given a positive integer $q$ which represents the number of modifications you need to do on $s$.

Each modification is defined with one positive integer $x$: 

* Find an index $i$ such that $l_i \le x \le r_i$ (notice that such $i$ is unique).
* Let $a=\min(x, r_i+l_i-x)$ and let $b=\max(x, r_i+l_i-x)$.
* Reverse the substring of $s$ from index $a$ to index $b$.

Reversing the substring $[a, b]$ of a string $s$ means to make $s$ equal to $s_1, s_2, \dots, s_{a-1},\ s_b, s_{b-1}, \dots, s_{a+1}, s_a,\ s_{b+1}, s_{b+2}, \dots, s_{n-1}, s_n$.

Print $s$ after the last modification is finished.

### Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Description of the test cases follows.

The first line of each test case contains two integers $n$ and $k$ ($1 \le k \le n \le 2\cdot 10^5$) — the length of the string $s$, and the length of arrays $l$ and $r$.

The second line of each test case contains the string $s$ ($ |s| = n$) containing lowercase Latin letters — the initial string.

The third line of each test case contains $k$ positive integers $l_1, l_2, \dots, l_k$ ($1 \le l_i \le n$) — the array $l$.

The fourth line of each test case contains $k$ positive integers $r_1, r_2, \dots, r_k$ ($1 \le r_i \le n$) — the array $r$.

The fifth line of each test case contains a positive integer $q$ ($1 \le q \le 2 \cdot 10^5 $) — the number of modifications you need to do to $s$.

The sixth line of each test case contains $q$ positive integers $x_1, x_2, \dots, x_q$ ($1\le x_i \le n$) — the description of the modifications.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot10^5$. 

It is guaranteed that the sum of $q$ over all test cases does not exceed $2\cdot10^5$.

It is guaranteed that the conditions in the statement hold for the arrays $l$ and $r$.

### Output

For each test case, in a new line, output the string $s$ after the last modification is done.

## Example

### Input


```text
54 2abcd1 32 421 35 3abcde1 2 31 2 531 2 33 1gaf1322 210 1aghcdegdij11051 2 3 4 21 1a1111
```
### Output

```text

badc
abedc
gaf
jihgedcdga
a

```
## Note

In the first test case:

The initial string is "abcd". In the first modification, we have $x=1$. Since $l_1=1\leq x \leq r_1=2$, we find the index $i = 1$. We reverse the substring from index $x=1$ to $l_1+r_1-x=1+2-1=2$. After this modification, our string is "bacd". 

In the second modification (and the last modification), we have $x=3$. Since $l_2=3\leq x \leq r_2=4$, we find the index $i = 2$. We reverse the substring from index $x=3$ to $l_2+r_2-x=3+4-3=4$. After this modification, our string is "badc".

In the second test case:

The initial string is "abcde". In the first modification, we have $x=1$. Since $l_1=1\leq x \leq r_1=1$, we find the index $i = 1$. We reverse the substring from index $x=1$ to $l_1+r_1-x=1+1-1=1$. After this modification, our string hasn't changed ("abcde"). 

In the second modification, we have $x=2$. Since $l_2=2\leq x \leq r_2=2$, we find the index $i = 2$. We reverse the substring from index $x=2$ to $l_2+r_2-x=2+2-2=2$. After this modification, our string hasn't changed ("abcde"). 

In the third modification (and the last modification), we have $x=3$. Since $l_3=3\leq x \leq r_3=5$, we find the index $i = 3$. We reverse the substring from index $x=3$ to $l_3+r_3-x=3+5-3=5$. After this modification, our string is "abedc".



#### Tags 

#1600 #NOT OK #data_structures #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_900_(Div._3).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
