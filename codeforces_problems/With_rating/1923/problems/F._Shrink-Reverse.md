<h1 style='text-align: center;'> F. Shrink-Reverse</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a binary string $s$ of length $n$ (a string consisting of $n$ characters, and each character is either 0 or 1).

Let's look at $s$ as at a binary representation of some integer, and name that integer as the value of string $s$. For example, the value of 000 is $0$, the value of 01101 is $13$, "100000" is $32$ and so on.

You can perform at most $k$ operations on $s$. Each operation should have one of the two following types: 

* SWAP: choose two indices $i < j$ in $s$ and swap $s_i$ with $s_j$;
* SHRINK-REVERSE: delete all leading zeroes from $s$ and reverse $s$.

 For example, after you perform SHRINK-REVERSE on 000101100, you'll get 001101.What is the minimum value of $s$ you can achieve by performing at most $k$ operations on $s$?

###### Input

The first line contains two integers $n$ and $k$ ($2 \le n \le 5 \cdot 10^5$; $1 \le k \le n$) — the length of the string $s$ and the maximum number of operations.

The second line contains the string $s$ of length $n$ consisting of characters 0 and/or 1. 

Additional constraint on the input: $s$ contains at least one 1.

###### Output

Print a single integer — the minimum value of $s$ you can achieve using no more than $k$ operations. Since the answer may be too large, print it modulo $10^{9} + 7$.

## Note

 that you need to minimize the original value, not the remainder.

## Examples

###### Input


```text
8 210010010
```
###### Output

```text

7

```
###### Input


```text
8 201101000
```
###### Output

```text

7

```
###### Input


```text
30 30111111111111111111111111111111
```
###### Output

```text

73741816

```
###### Input


```text
14 110110001111100
```
###### Output

```text

3197

```
## Note

In the first example, one of the optimal strategies is the following: 

1. 10010010 $\xrightarrow{\texttt{SWAP}}$ 00010110;
2. 00010110 $\xrightarrow{\texttt{SWAP}}$ 00000111.

 The value of 00000111 is $7$.In the second example, one of the optimal strategies is the following: 

1. 01101000 $\xrightarrow{\texttt{SHRINK}}$ 1101000 $\xrightarrow{\texttt{REVERSE}}$ 0001011;
2. 0001011 $\xrightarrow{\texttt{SWAP}}$ 0000111.

 The value of 0000111 is $7$.

#### Tags 

#2800 #NOT OK #binary_search #brute_force #greedy #hashing #implementation #string_suffix_structures #strings 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_162_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
