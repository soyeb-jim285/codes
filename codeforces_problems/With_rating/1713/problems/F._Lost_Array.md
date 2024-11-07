<h1 style='text-align: center;'> F. Lost Array</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

My orzlers, we can optimize this problem from $O(S^3)$ to $O\left(T^\frac{5}{9}\right)$!— Spyofgame, founder of Orzlim religionA long time ago, Spyofgame invented the famous array $a$ ($1$-indexed) of length $n$ that contains information about the world and life. After that, he decided to convert it into the matrix $b$ ($0$-indexed) of size $(n + 1) \times (n + 1)$ which contains information about the world, life and beyond.

Spyofgame converted $a$ into $b$ with the following rules.

* $b_{i,0} = 0$ if $0 \leq i \leq n$;
* $b_{0,i} = a_{i}$ if $1 \leq i \leq n$;
* $b_{i,j} = b_{i,j-1} \oplus b_{i-1,j}$ if $1 \leq i, j \leq n$.

Here $\oplus$ denotes the [bitwise XOR operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR).

Today, archaeologists have discovered the famous matrix $b$. However, many elements of the matrix has been lost. They only know the values of $b_{i,n}$ for $1 \leq i \leq n$ (note that these are some elements of the last column, not the last row).

The archaeologists want to know what a possible array of $a$ is. Can you help them reconstruct any array that could be $a$?

##### Input

The first line contains a single integer $n$ ($1 \leq n \leq 5 \cdot 10^5$).

The second line contains $n$ integers $b_{1,n}, b_{2,n}, \ldots, b_{n,n}$ ($0 \leq b_{i,n} < 2^{30}$).

##### Output

If some array $a$ is consistent with the information, print a line containing $n$ integers $a_1, a_2, \ldots, a_n$. If there are multiple solutions, output any.

If such an array does not exist, output $-1$ instead.

## Examples

##### Input


```text
3
0 2 1
```
##### Output


```text
1 2 3 
```
##### Input


```text
1
199633
```
##### Output


```text
199633 
```
##### Input


```text
10
346484077 532933626 858787727 369947090 299437981 416813461 865836801 141384800 157794568 691345607
```
##### Output


```text
725081944 922153789 481174947 427448285 516570428 509717938 855104873 280317429 281091129 1050390365 
```
## Note

If we let $a = [1,2,3]$, then $b$ will be:

 

| $\bf{0}$ | $\bf{1}$ | $\bf{2}$ | $\bf{3}$ |
| --- | --- | --- | --- |
| $\bf{0}$ | $1$ | $3$ | $0$ |
| $\bf{0}$ | $1$ | $2$ | $2$ |
| $\bf{0}$ | $1$ | $3$ | $1$ |

 The values of $b_{1,n}, b_{2,n}, \ldots, b_{n,n}$ generated are $[0,2,1]$ which is consistent with what the archaeologists have discovered.



#### Tags 

#2900 #NOT OK #bitmasks #combinatorics #constructive_algorithms #dp #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_812_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
