<h1 style='text-align: center;'> G. Alphabetic Tree</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given $m$ strings and a tree on $n$ nodes. Each edge has some letter written on it.

You have to answer $q$ queries. Each query is described by $4$ integers $u$, $v$, $l$ and $r$. The answer to the query is the total number of occurrences of $str(u,v)$ in strings with indices from $l$ to $r$. $str(u,v)$ is defined as the string that is made by concatenating letters written on the edges on the shortest path from $u$ to $v$ (in order that they are traversed).

#### Input

The first line of the input contains three integers $n$, $m$ and $q$ ($2 \le n \le 10^5$, $1 \le m,q \le 10^5$).

The $i$-th of the following $n-1$ lines contains two integers $u_i, v_i$ and a lowercase Latin letter $c_i$ ($1 \le u_i, v_i \le n$, $u_i \neq v_i$), denoting the edge between nodes $u_i, v_i$ with a character $c_i$ on it. 

It's guaranteed that these edges form a tree.

The following $m$ lines contain the strings consisting of lowercase Latin letters. The total length of those strings does not exceed $10^5$.

Then $q$ lines follow, each containing four integers $u$, $v$, $l$ and $r$ ($1 \le u,v \le n$, $u \neq v$, $1 \le l \le r \le m$), denoting the queries. 

#### Output

For each query print a single integer — the answer to the query.

## Examples

#### Input


```text
2 5 3
1 2 a
aab
abab
aaa
b
a
2 1 1 5
1 2 1 3
2 1 3 5
```
#### Output


```text
8
7
4
```
#### Input


```text
9 5 6
1 2 a
2 7 c
1 3 b
3 4 b
4 6 b
3 5 a
5 8 b
5 9 c
ababa
cabbb
bac
bbbac
abacaba
2 7 1 4
2 5 1 5
6 3 4 4
6 9 4 5
5 7 3 5
5 3 1 5
```
#### Output


```text
3
4
2
1
1
10
```


#### Tags 

#3500 #NOT OK #binary_search #data_structures #dfs_and_similar #hashing #string_suffix_structures #strings #trees 

## Blogs
- [All Contest Problems](../Codeforces_Round_758_(Div.1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
