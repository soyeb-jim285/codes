<h1 style='text-align: center;'> E. Almost Fault-Tolerant Database</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are storing an integer array of length $m$ in a database. To maintain internal integrity and protect data, the database stores $n$ copies of this array.

Unfortunately, the recent incident may have altered the stored information in every copy in the database.

It's believed, that the incident altered at most two elements in every copy. You need to recover the original array based on the current state of the database.

In case there are multiple ways to restore the array, report any. If there is no array that differs from every copy in no more than two positions, report that as well.

##### Input

The first line contains integers $n$ and $m$ ($2 \le n$; $1 \le m$; $n \cdot m \le 250\,000$) — the number of copies and the size of the array.

Each of the following $n$ lines describes one of the currently stored copies in the database, it consists of $m$ integers $s_{i, 1}, s_{i, 2}, \dots, s_{i, m}$ ($1 \le s_{i, j} \le 10^9$).

##### Output

If there is an array consistent with all given copies, print "Yes" and then the array itself. The array must have length $m$ and contain integers between $1$ and $10^9$ only.

Otherwise, print "No".

If there are multiple possible arrays, print any of them.

## Examples

##### Input


```text
3 4
1 10 10 100
1 1 1 100
10 100 1 100
```
##### Output


```text
Yes
1 10 1 100
```
##### Input


```text
10 7
1 1 1 1 1 1 1
1 1 1 1 1 1 2
1 1 1 1 1 2 2
1 1 1 1 2 2 1
1 1 1 2 2 1 1
1 1 2 2 1 1 1
1 2 2 1 1 1 1
2 2 1 1 1 1 1
2 1 1 1 1 1 1
1 1 1 1 1 1 1
```
##### Output


```text
Yes
1 1 1 1 1 1 1
```
##### Input


```text
2 5
2 2 1 1 1
1 1 2 2 2
```
##### Output


```text
No
```
## Note

In the first example, the array $[1, 10, 1, 100]$ differs from first and second copies in just one position, and from the third copy in two positions.

In the second example, array $[1, 1, 1, 1, 1, 1, 1]$ is the same as the first copy and differs from all other copies in at most two positions.

In the third example, there is no array differing in at most two positions from every database's copy.



#### Tags 

#2500 #NOT OK #brute_force #constructive_algorithms #dfs_and_similar #greedy #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_704_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
