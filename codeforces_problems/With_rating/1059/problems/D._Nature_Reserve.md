<h1 style='text-align: center;'> D. Nature Reserve</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is a forest that we model as a plane and live $n$ rare animals. Animal number $i$ has its lair in the point $(x_{i}, y_{i})$. In order to protect them, a decision to build a nature reserve has been made.

The reserve must have a form of a circle containing all lairs. There is also a straight river flowing through the forest. All animals drink from this river, therefore it must have at least one common point with the reserve. On the other hand, ships constantly sail along the river, so the reserve must not have more than one common point with the river.

For convenience, scientists have made a transformation of coordinates so that the river is defined by $y = 0$. Check whether it is possible to build a reserve, and if possible, find the minimum possible radius of such a reserve.

##### Input

The first line contains one integer $n$ ($1 \le n \le 10^5$) — the number of animals. 

Each of the next $n$ lines contains two integers $x_{i}$, $y_{i}$ ($-10^7 \le x_{i}, y_{i} \le 10^7$) — the coordinates of the $i$-th animal's lair. It is guaranteed that $y_{i} \neq 0$. No two lairs coincide.

##### Output

If the reserve cannot be built, print $-1$. Otherwise print the minimum radius. Your answer will be accepted if absolute or relative error does not exceed $10^{-6}$.

Formally, let your answer be $a$, and the jury's answer be $b$. Your answer is considered correct if $\frac{|a - b|}{\max{(1, |b|)}} \le 10^{-6}$.

## Examples

##### Input


```text
1  
0 1  

```
##### Output


```text
0.5
```
##### Input


```text
3  
0 1  
0 2  
0 -3  

```
##### Output


```text
-1  

```
##### Input


```text
2  
0 1  
1 1  

```
##### Output


```text
0.625
```
## Note

In the first sample it is optimal to build the reserve with the radius equal to $0.5$ and the center in $(0,\ 0.5)$.

In the second sample it is impossible to build a reserve.

In the third sample it is optimal to build the reserve with the radius equal to $\frac{5}{8}$ and the center in $(\frac{1}{2},\ \frac{5}{8})$.



#### Tags 

#2200 #NOT OK #binary_search #geometry #ternary_search 

## Blogs
- [All Contest Problems](../Codeforces_Round_514_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
