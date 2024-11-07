<h1 style='text-align: center;'> E. Fast Travel Text Editor</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given a string $s$, consisting of lowercase Latin letters.

There's a cursor, initially placed between two adjacent letters of the string. The cursor can't be placed before the first or after the last letter.

In one move, you can perform one of three actions: 

* move a cursor one position to the left (if that doesn't place it before the first letter);
* move a cursor one position to the right (if that doesn't place it after the last letter);
* let $x$ be the letter immediately to the left of the cursor, and $y$ be the letter immediately to the right of the cursor. Choose any pair of adjacent letters in the string such that the left of them is $x$ and the right of them is $y$, and move the cursor to the position between these two letters.

You are asked $m$ queries. In each query, you are given two integers $f$ and $t$, which correspond to two valid positions of the cursor in the string. In response to the query, you have to calculate the minimum number of operations required to move the cursor from position $f$ to position $t$.

##### Input

The first line contains a string $s$ ($2 \le |s| \le 5 \cdot 10^4$), consisting of lowercase Latin letters.

The second line contains a single integer $m$ ($1 \le m \le 5 \cdot 10^4$) — the number of queries.

The $i$-th of the next $m$ lines contains two integers $f$ and $t$ ($1 \le f, t \le |s| - 1$) — the initial and the target positions of the cursor in the $i$-th query. Position $x$ means that the cursor is between the $x$-th and the $(x+1)$-st letters of the string ($1$-indexed).

##### Output

For each query, print the minimum number of actions required to move the cursor from position $f$ to position $t$.

## Examples

##### Input


```text
codecode
3
1 7
3 5
3 6
```
##### Output


```text
3
2
2
```
##### Input


```text
abcdefghij
3
1 9
9 1
5 5
```
##### Output


```text
8
8
0
```
##### Input


```text
aaaaaaaaaaaa
4
10 8
3 7
6 1
11 11
```
##### Output


```text
1
1
1
0
```


#### Tags 

#2400 #NOT OK #data_structures #dfs_and_similar #graphs #shortest_paths 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_153_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
