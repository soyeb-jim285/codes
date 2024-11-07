<h1 style='text-align: center;'> F. Teleporters</h1>

<h5 style='text-align: center;'>time limit per test: 7 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

There are $n+1$ teleporters on a straight line, located in points $0$, $a_1$, $a_2$, $a_3$, ..., $a_n$. It's possible to teleport from point $x$ to point $y$ if there are teleporters in both of those points, and it costs $(x-y)^2$ energy.

You want to install some additional teleporters so that it is possible to get from the point $0$ to the point $a_n$ (possibly through some other teleporters) spending no more than $m$ energy in total. Each teleporter you install must be located in an integer point.

What is the minimum number of teleporters you have to install?

###### Input

The first line contains one integer $n$ ($1 \le n \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_1 < a_2 < a_3 < \dots < a_n \le 10^9$).

The third line contains one integer $m$ ($a_n \le m \le 10^{18}$).

###### Output

Print one integer — the minimum number of teleporters you have to install so that it is possible to get from $0$ to $a_n$ spending at most $m$ energy. It can be shown that it's always possible under the constraints from the input format.

## Examples

###### Input


```text
2
1 5
7
```
###### Output


```text
2
```
###### Input


```text
2
1 5
6
```
###### Output


```text
3
```
###### Input


```text
1
5
5
```
###### Output


```text
4
```
###### Input


```text
1
1000000000
1000000043
```
###### Output


```text
999999978
```


#### Tags 

#2600 #NOT OK #binary_search #greedy 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_126_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
