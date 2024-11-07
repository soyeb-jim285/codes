<h1 style='text-align: center;'> D. Print a 1337-string...</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements.

You are given an integer $n$. 

You have to find a sequence $s$ consisting of digits $\{1, 3, 7\}$ such that it has exactly $n$ subsequences equal to $1337$.

For example, sequence $337133377$ has $6$ subsequences equal to $1337$: 

1. $337\underline{1}3\underline{3}\underline{3}7\underline{7}$ (you can remove the second and fifth characters);
2. $337\underline{1}\underline{3}3\underline{3}7\underline{7}$ (you can remove the third and fifth characters);
3. $337\underline{1}\underline{3}\underline{3}37\underline{7}$ (you can remove the fourth and fifth characters);
4. $337\underline{1}3\underline{3}\underline{3}\underline{7}7$ (you can remove the second and sixth characters);
5. $337\underline{1}\underline{3}3\underline{3}\underline{7}7$ (you can remove the third and sixth characters);
6. $337\underline{1}\underline{3}\underline{3}3\underline{7}7$ (you can remove the fourth and sixth characters).

Note that the length of the sequence $s$ must not exceed $10^5$.

You have to answer $t$ independent queries.

### Input

The first line contains one integer $t$ ($1 \le t \le 10$) — the number of queries. 

Next $t$ lines contains a description of queries: the $i$-th line contains one integer $n_i$ ($1 \le n_i \le 10^9$).

### Output

For the $i$-th query print one string $s_i$ ($1 \le |s_i| \le 10^5$) consisting of digits $\{1, 3, 7\}$. String $s_i$ must have exactly $n_i$ subsequences $1337$. If there are multiple such strings, print any of them.

## Example

### Input


```text
2
6
1
```
### Output


```text

113337
1337
```


#### Tags 

#1900 #NOT OK #combinatorics #constructive_algorithms #math #strings 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_70_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
