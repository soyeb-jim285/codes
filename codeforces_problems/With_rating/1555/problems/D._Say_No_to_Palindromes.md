<h1 style='text-align: center;'> D. Say No to Palindromes</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's call the string beautiful if it does not contain a substring of length at least $2$, which is a palindrome. Recall that a palindrome is a string that reads the same way from the first character to the last and from the last character to the first. For example, the strings a, bab, acca, bcabcbacb are palindromes, but the strings ab, abbbaa, cccb are not.

Let's define cost of a string as the minimum number of operations so that the string becomes beautiful, if in one operation it is allowed to change any character of the string to one of the first $3$ letters of the Latin alphabet (in lowercase).

You are given a string $s$ of length $n$, each character of the string is one of the first $3$ letters of the Latin alphabet (in lowercase).

You have to answer $m$ queries — calculate the cost of the substring of the string $s$ from $l_i$-th to $r_i$-th position, inclusive.

### Input

The first line contains two integers $n$ and $m$ ($1 \le n, m \le 2 \cdot 10^5$) — the length of the string $s$ and the number of queries.

The second line contains the string $s$, it consists of $n$ characters, each character one of the first $3$ Latin letters.

The following $m$ lines contain two integers $l_i$ and $r_i$ ($1 \le l_i \le r_i \le n$) — parameters of the $i$-th query.

### Output

For each query, print a single integer — the cost of the substring of the string $s$ from $l_i$-th to $r_i$-th position, inclusive.

## Example

### Input


```text
5 4
baacb
1 3
1 5
4 5
2 3
```
### Output


```text
1
2
0
1
```
## Note

Consider the queries of the example test.

* in the first query, the substring is baa, which can be changed to bac in one operation;
* in the second query, the substring is baacb, which can be changed to cbacb in two operations;
* in the third query, the substring is cb, which can be left unchanged;
* in the fourth query, the substring is aa, which can be changed to ba in one operation.


#### Tags 

#1600 #NOT OK #brute_force #constructive_algorithms #dp #strings 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_112_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
