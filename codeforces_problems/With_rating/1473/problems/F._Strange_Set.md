<h1 style='text-align: center;'> F. Strange Set</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 32 megabytes</h5>


## Note

 that the memory limit is unusual.

You are given an integer $n$ and two sequences $a_1, a_2, \dots, a_n$ and $b_1, b_2, \dots, b_n$.

Let's call a set of integers $S$ such that $S \subseteq \{1, 2, 3, \dots, n\}$ strange, if, for every element $i$ of $S$, the following condition is met: for every $j \in [1, i - 1]$, if $a_j$ divides $a_i$, then $j$ is also included in $S$. An empty set is always strange.

The cost of the set $S$ is $\sum\limits_{i \in S} b_i$. You have to calculate the maximum possible cost of a strange set.

##### Input

The first line contains one integer $n$ ($1 \le n \le 3000$).

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 100$).

The third line contains $n$ integers $b_1, b_2, \dots, b_n$ ($-10^5 \le b_i \le 10^5$).

##### Output

Print one integer — the maximum cost of a strange set.

## Examples

##### Input


```text
9
4 7 3 4 5 6 7 8 13
-2 3 -19 5 -6 7 -8 9 1
```
##### Output


```text
16
```
##### Input


```text
2
42 42
-37 13
```
##### Output


```text
0
```
##### Input


```text
2
42 42
13 -37
```
##### Output


```text
13
```
## Note

The strange set with the maximum cost in the first example is $\{1, 2, 4, 8, 9\}$.

The strange set with the maximum cost in the second example is empty.



#### Tags 

#2700 #NOT OK #flows #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_102_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
