<h1 style='text-align: center;'> C. Binary String Copying</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string $s$ consisting of $n$ characters 0 and/or 1.

You make $m$ copies of this string, let the $i$-th copy be the string $t_i$. Then you perform exactly one operation on each of the copies: for the $i$-th copy, you sort its substring $[l_i; r_i]$ (the substring from the $l_i$-th character to the $r_i$-th character, both endpoints inclusive). 
## Note

 that each operation affects only one copy, and each copy is affected by only one operation.

Your task is to calculate the number of different strings among $t_1, t_2, \ldots, t_m$. 
## Note

 that the initial string $s$ should be counted only if at least one of the copies stays the same after the operation.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains two integers $n$ and $m$ ($1 \le n, m \le 2 \cdot 10^5$) — the length of $s$ and the number of copies, respectively.

The second line contains $n$ characters 0 and/or 1 — the string $s$.

Then $m$ lines follow. The $i$-th of them contains two integers $l_i$ and $r_i$ ($1 \le l_i \le r_i \le n$) — the description of the operation applied to the $i$-th copy.

The sum of $n$ over all test cases doesn't exceed $2 \cdot 10^5$. The sum of $m$ over all test cases doesn't exceed $2 \cdot 10^5$.

### Output

Print one integer — the number of different strings among $t_1, t_2, \ldots, t_m$.

## Example

### Input


```text
36 51011001 21 32 45 51 66 41001112 21 41 31 21 101 1
```
### Output

```text

3
3
1

```
## Note

Consider the first example. Copies below are given in order of the input operations. Underlined substrings are substrings that are sorted:

1. 101100 $\rightarrow$ 011100;
2. 101100 $\rightarrow$ 011100;
3. 101100 $\rightarrow$ 101100;
4. 101100 $\rightarrow$ 101100;
5. 101100 $\rightarrow$ 000111.

There are three different strings among $t_1, t_2, t_3, t_4, t_5$: 000111, 011100 and 101100.

Consider the second example:

1. 100111 $\rightarrow$ 100111;
2. 100111 $\rightarrow$ 001111;
3. 100111 $\rightarrow$ 001111;
4. 100111 $\rightarrow$ 010111.

There are three different strings among $t_1, t_2, t_3, t_4$: 001111, 010111 and 100111.



#### Tags 

#1600 #NOT OK #binary_search #brute_force #data_structures #hashing #strings 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_152_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
