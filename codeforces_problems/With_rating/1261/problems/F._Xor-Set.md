<h1 style='text-align: center;'> F. Xor-Set</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two sets of integers: $A$ and $B$. You need to output the sum of elements in the set $C = \{x | x = a \oplus b, a \in A, b \in B\}$ modulo $998244353$, where $\oplus$ denotes the [bitwise XOR operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR). Each number should be counted only once.

For example, if $A = \{2, 3\}$ and $B = \{2, 3\}$ you should count integer $1$ only once, despite the fact that you can get it as $3 \oplus 2$ and as $2 \oplus 3$. So the answer for this case is equal to $1 + 0 = 1$.

Let's call a segment $[l; r]$ a set of integers $\{l, l+1, \dots, r\}$.

The set $A$ is given as a union of $n_A$ segments, the set $B$ is given as a union of $n_B$ segments.

#### Input

The first line contains a single integer $n_A$ ($1 \le n_A \le 100$).

The $i$-th of the next $n_A$ lines contains two integers $l_i$ and $r_i$ ($1 \le l_i \le r_i \le 10^{18}$), describing a segment of values of set $A$.

The next line contains a single integer $n_B$ ($1 \le n_B \le 100$).

The $i$-th of the next $n_B$ lines contains two integers $l_j$ and $r_j$ ($1 \le l_j \le r_j \le 10^{18}$), describing a segment of values of set $B$.

## Note

 that segments in both sets may intersect.

#### Output

Print one integer — the sum of all elements in set $C = \{x | x = a \oplus b, a \in A, b \in B\}$ modulo $998244353$.

## Examples

#### Input


```text
2
3 5
5 8
3
1 2
1 9
2 9
```
#### Output


```text
112
```
#### Input


```text
1
1 9
2
2 4
2 10
```
#### Output


```text
120
```
## Note

In the second example, we can discover that the set $C = \{0,1,\dots,15\}$, which means that all numbers between $0$ and $15$ can be represented as $a \oplus b$.



#### Tags 

#3100 #NOT OK #bitmasks #divide_and_conquer #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_602_(Div._1,_based_on_Technocup_2020_Elimination_Round_3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
