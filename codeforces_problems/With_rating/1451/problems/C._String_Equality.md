<h1 style='text-align: center;'> C. String Equality</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Ashish has two strings $a$ and $b$, each of length $n$, and an integer $k$. The strings only contain lowercase English letters.

He wants to convert string $a$ into string $b$ by performing some (possibly zero) operations on $a$.

In one move, he can either 

* choose an index $i$ ($1 \leq i\leq n-1$) and swap $a_i$ and $a_{i+1}$, or
* choose an index $i$ ($1 \leq i \leq n-k+1$) and if $a_i, a_{i+1}, \ldots, a_{i+k-1}$ are all equal to some character $c$ ($c \neq$ 'z'), replace each one with the next character $(c+1)$, that is, 'a' is replaced by 'b', 'b' is replaced by 'c' and so on.

## Note

 that he can perform any number of operations, and the operations can only be performed on string $a$. 

Help Ashish determine if it is possible to convert string $a$ into $b$ after performing some (possibly zero) operations on it.

### Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^5$) — the number of test cases. The description of each test case is as follows.

The first line of each test case contains two integers $n$ ($2 \leq n \leq 10^6$) and $k$ ($1 \leq k \leq n$).

The second line of each test case contains the string $a$ of length $n$ consisting of lowercase English letters.

The third line of each test case contains the string $b$ of length $n$ consisting of lowercase English letters.

It is guaranteed that the sum of values $n$ among all test cases does not exceed $10^6$.

### Output

For each test case, print "Yes" if Ashish can convert $a$ into $b$ after some moves, else print "No".

You may print the letters of the answer in any case (upper or lower).

## Example

### Input


```text
4
3 3
abc
bcd
4 2
abba
azza
2 1
zz
aa
6 2
aaabba
ddddcc
```
### Output


```text
No
Yes
No
Yes
```
## Note

In the first test case it can be shown that it is impossible to convert $a$ into $b$.

In the second test case,

"abba" $\xrightarrow{\text{inc}}$ "acca" $\xrightarrow{\text{inc}}$ $\ldots$ $\xrightarrow{\text{inc}}$ "azza".

Here "swap" denotes an operation of the first type, and "inc" denotes an operation of the second type.

In the fourth test case,

"aaabba" $\xrightarrow{\text{swap}}$ "aaabab" $\xrightarrow{\text{swap}}$ "aaaabb" $\xrightarrow{\text{inc}}$ $\ldots$ $\xrightarrow{\text{inc}}$ "ddaabb" $\xrightarrow{\text{inc}}$ $\ldots$ $\xrightarrow{\text{inc}}$ "ddddbb" $\xrightarrow{\text{inc}}$ $\ldots$ $\xrightarrow{\text{inc}}$ "ddddcc".



#### Tags 

#1400 #NOT OK #dp #greedy #hashing #implementation #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_685_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
