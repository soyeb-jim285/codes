<h1 style='text-align: center;'> D. String Searching</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $s$ consisting of $n$ different strings. Each string consists of $m$ lowercase Latin letters.

You have to respond to $q$ queries. Each query contains a string $t$ of length $m+1$. Count the number of indices $i$, such that the string $t$ can be obtained from the string $s_i$, if it is allowed to insert one letter in an arbitrary position.

#### Input

The first line contains two integers $n$ and $m$ ($1 \le n \le 10^5$; $1 \le m \le 10$) — the number of strings in the array and the length of each string.

The following $n$ lines contain strings $s_i$. All of the given strings are different.

The next line contains a single integer $q$ ($1 \le q \le 10^5$) — the number of queries.

The following $q$ lines contain query strings $t$ of length $m + 1$.

#### Output

For each query, print the number of indices $i$, such that a string from the query can be obtained from the string $s_i$, if it is allowed to insert one letter in an arbitrary position.

## Examples

#### Input


```text
2 1
a
c
4
aa
ca
mm
cf
```
#### Output


```text
1
2
0
1
```
#### Input


```text
6 3
dba
abd
cbb
ada
add
bdd
5
ccbb
abdd
adba
bada
dddd
```
#### Output


```text
1
3
2
1
0
```
## Note

Explanation of the first test of the example:

* the string a can be transformed into aa by inserting one letter;
* both strings a and c can be transformed into ca by inserting one letter;
* neither a nor c can be transformed into mm by inserting one letter;
* c can be transformed into cf by inserting one letter.


#### Tags 

#NOT OK #*special #hashing 

## Blogs
- [All Contest Problems](../Kotlin_Heroes:_Episode_7.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
