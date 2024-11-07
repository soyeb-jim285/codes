<h1 style='text-align: center;'> I. Plane Tiling</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given five integers $n$, $dx_1$, $dy_1$, $dx_2$ and $dy_2$. You have to select $n$ distinct pairs of integers $(x_i, y_i)$ in such a way that, for every possible pair of integers $(x, y)$, there exists exactly one triple of integers $(a, b, i)$ meeting the following constraints:

 $ \begin{cases} x \, = \, x_i + a \cdot dx_1 + b \cdot dx_2, \\\ y \, = \, y_i + a \cdot dy_1 + b \cdot dy_2. \end{cases} $ 
##### Input

The first line contains a single integer $n$ ($1 \le n \le 10^5$).

The second line contains two integers $dx_1$ and $dy_1$ ($-10^6 \le dx_1, dy_1 \le 10^6$).

The third line contains two integers $dx_2$ and $dy_2$ ($-10^6 \le dx_2, dy_2 \le 10^6$).

##### Output

If it is impossible to correctly select $n$ pairs of integers, print NO.

Otherwise, print YES in the first line, and then $n$ lines, the $i$-th of which contains two integers $x_i$ and $y_i$ ($-10^9 \le x_i, y_i \le 10^9$).

If there are multiple solutions, print any of them.

## Examples

##### Input


```text
4
2 0
0 2
```
##### Output


```text
YES
0 0
0 1
1 0
1 1
```
##### Input


```text
5
2 6
1 5
```
##### Output


```text
NO
```
##### Input


```text
2
3 4
1 2
```
##### Output


```text
YES
0 0
0 1
```


#### Tags 

#2500 #NOT OK #geometry #implementation #math 

## Blogs
- [All Contest Problems](../2020-2021_ICPC,_NERC,_Southern_and_Volga_Russian_Regional_Contest_(Online_Mirror,_ICPC_Rules).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial #1 (en)](../blogs/Tutorial_1_(en).md)
