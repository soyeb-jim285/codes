<h1 style='text-align: center;'> B. Segment Occurrences</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two strings $s$ and $t$, both consisting only of lowercase Latin letters.

The substring $s[l..r]$ is the string which is obtained by taking characters $s_l, s_{l + 1}, \dots, s_r$ without changing the order.

Each of the occurrences of string $a$ in a string $b$ is a position $i$ ($1 \le i \le |b| - |a| + 1$) such that $b[i..i + |a| - 1] = a$ ($|a|$ is the length of string $a$).

You are asked $q$ queries: for the $i$-th query you are required to calculate the number of occurrences of string $t$ in a substring $s[l_i..r_i]$.

##### Input

The first line contains three integer numbers $n$, $m$ and $q$ ($1 \le n, m \le 10^3$, $1 \le q \le 10^5$) — the length of string $s$, the length of string $t$ and the number of queries, respectively.

The second line is a string $s$ ($|s| = n$), consisting only of lowercase Latin letters.

The third line is a string $t$ ($|t| = m$), consisting only of lowercase Latin letters.

Each of the next $q$ lines contains two integer numbers $l_i$ and $r_i$ ($1 \le l_i \le r_i \le n$) — the arguments for the $i$-th query.

##### Output

Print $q$ lines — the $i$-th line should contain the answer to the $i$-th query, that is the number of occurrences of string $t$ in a substring $s[l_i..r_i]$.

## Examples

##### Input


```text
10 3 4  
codeforces  
for  
1 3  
3 10  
5 6  
5 7  

```
##### Output


```text
0  
1  
0  
1  

```
##### Input


```text
15 2 3  
abacabadabacaba  
ba  
1 15  
3 4  
2 14  

```
##### Output


```text
4  
0  
3  

```
##### Input


```text
3 5 2  
aaa  
baaab  
1 3  
1 1  

```
##### Output


```text
0  
0  

```
## Note

In the first example the queries are substrings: "cod", "deforces", "fo" and "for", respectively.



#### Tags 

#1300 #NOT OK #brute_force #implementation 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_48_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
