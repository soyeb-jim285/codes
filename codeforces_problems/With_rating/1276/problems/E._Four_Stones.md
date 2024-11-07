<h1 style='text-align: center;'> E. Four Stones</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

There are four stones on an infinite line in integer coordinates $a_1, a_2, a_3, a_4$. The goal is to have the stones in coordinates $b_1, b_2, b_3, b_4$. The order of the stones does not matter, that is, a stone from any position $a_i$ can end up in at any position $b_j$, provided there is a required number of stones in each position (that is, if a coordinate $x$ appears $k$ times among numbers $b_1, \ldots, b_4$, there should be exactly $k$ stones at $x$ in the end).

We are allowed to move stones with the following operation: choose two stones at distinct positions $x$ and $y$ with at least one stone each, and move one stone from $x$ to $2y - x$. In other words, the operation moves a stone to a symmetric position relative to some other stone. At any moment it is allowed to have any number of stones at the same position.

Find any sequence of operations that achieves the goal, or determine that it is impossible. The sequence does not have to be shortest, but it may contain at most $1000$ operations.

##### Input

The first line contains four integers $a_1, \ldots, a_4$ ($-10^9 \leq a_i \leq 10^9$) — initial coordinates of the stones. There may be multiple stones sharing the same coordinate.

The second line contains four integers $b_1, \ldots, b_4$ ($-10^9 \leq b_i \leq 10^9$) — target coordinates of the stones. There may be multiple targets sharing the same coordinate.

##### Output

If there is no sequence of operations that achieves the goal, print a single integer $-1$. Otherwise, on the first line print a single integer $k$ ($0 \leq k \leq 1000$) — the number of operations in your sequence. On the next $k$ lines, describe the operations. The $i$-th of these lines should contain two integers $x_i$ and $y_i$ ($x_i \neq y_i$) — coordinates of the moved stone and the center of symmetry stone for the $i$-th operation.

For each operation $i$, there should at least one stone in each of the coordinates $x_i$ and $y_i$, and the resulting coordinate $2y_i - x_i$ must not exceed $10^{18}$ by absolute value.

If there are multiple suitable sequences, print any of them. It is guaranteed that if there is a suitable sequence of operations, then there is also a suitable sequence that satisfies all the additional requirement.

## Examples

##### Input


```text
0 1 2 3
3 5 6 8
```
##### Output


```text
3
1 3
2 5
0 3
```
##### Input


```text
0 0 0 0
1 1 1 1
```
##### Output


```text
-1
```
##### Input


```text
0 0 0 1
0 1 0 1
```
##### Output


```text
-1
```


#### Tags 

#3500 #NOT OK #constructive_algorithms 

## Blogs
- [All Contest Problems](../Codeforces_Round_606_(Div._1,_based_on_Technocup_2020_Elimination_Round_4).md)
- [Announcement (ru)](../blogs/Announcement_(ru).md)
- [Tutorial](../blogs/Tutorial.md)
