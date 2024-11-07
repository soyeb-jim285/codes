<h1 style='text-align: center;'> F. Jumping Around</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is an infinite pond that can be represented with a number line. There are $n$ rocks in the pond, numbered from $1$ to $n$. The $i$-th rock is located at an integer coordinate $a_i$. The coordinates of the rocks are pairwise distinct. The rocks are numbered in the increasing order of the coordinate, so $a_1 < a_2 < \dots < a_n$.

A robot frog sits on the rock number $s$. The frog is programmable. It has a base jumping distance parameter $d$. There also is a setting for the jumping distance range. If the jumping distance range is set to some integer $k$, then the frog can jump from some rock to any rock at a distance from $d - k$ to $d + k$ inclusive in any direction. The distance between two rocks is an absolute difference between their coordinates.

You are assigned a task to implement a feature for the frog. Given two integers $i$ and $k$ determine if the frog can reach a rock number $i$ from a rock number $s$ performing a sequence of jumps with the jumping distance range set to $k$. The sequence can be arbitrarily long or empty.

You will be given $q$ testcases for that feature, the $j$-th testcase consists of two integers $i$ and $k$. Print "Yes" if the $i$-th rock is reachable and "No" otherwise.

You can output "YES" and "NO" in any case (for example, strings "yEs", "yes", "Yes" and 'YES"' will be recognized as a positive answer).

###### Input

The first line contains four integers $n$, $q$, $s$ and $d$ ($1 \le n, q \le 2 \cdot 10^5$; $1 \le s \le n$; $1 \le d \le 10^6$) — the number of rocks, the number of testcases, the starting rock and the base jumping distance parameter.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^6$) — the coordinates of the rocks. The coordinates of the rocks are pairwise distinct. The rocks are numbered in the increasing order of distance from the land, so $a_1 < a_2 < \dots < a_n$.

Each of the next $q$ lines contains two integers $i$ and $k$ ($1 \le i \le n$; $1 \le k \le 10^6$) — the parameters to the testcase.

###### Output

For each of the testcases print an answer. If there is a sequence of jumps from a rock number $s$ to a rock number $i$ with the jumping distance range set to $k$, then print "Yes". Otherwise, print "No".

## Examples

###### Input


```text
7 4 4 5
1 5 10 13 20 22 28
4 1
7 2
7 3
3 2
```
###### Output


```text
Yes
No
Yes
Yes
```
###### Input


```text
10 8 6 11
1 2 4 7 8 9 11 13 19 20
2 13
5 8
8 1
6 15
1 15
2 7
7 6
8 9
```
###### Output


```text
Yes
Yes
No
Yes
Yes
Yes
Yes
Yes
```
###### Input


```text
6 9 6 6
1 2 4 9 18 19
2 17
1 18
5 4
2 11
5 17
6 8
4 3
3 3
6 6
```
###### Output


```text
Yes
Yes
Yes
Yes
Yes
Yes
No
No
Yes
```
###### Input


```text
4 1 1 10
1 8 10 19
2 1
```
###### Output


```text
Yes
```
## Note

Explanation of the first example:

In the first testcase the destination rock is the same as the starting rock, thus no jumps are required to reach it.

In the second testcase the frog can jump any distance in the range $[5 - 2; 5 + 2]$. Thus, it can reach rock number $5$ (by jumping $7$ to the right) and rock number $3$ (by jumping $3$ to the left). From rock number $3$ it can reach rock number $2$ (by jumping $5$ to the left). From rock number $2$ it can reach rock number $1$ (by jumping $4$ to the left). However, there is no way to reach rock number $7$.

In the third testcase the frog can jump any distance in the range $[5 - 3; 5 + 3]$. Thus, it can reach rock number $7$ by jumping to rock $5$ first and to $7$ afterwards.

The fourth testcase is shown in the explanation for the second testcase.



#### Tags 

#2700 #NOT OK #binary_search #data_structures #divide_and_conquer #dp #dsu #graphs #shortest_paths 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_111_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
