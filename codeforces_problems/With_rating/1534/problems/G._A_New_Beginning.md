<h1 style='text-align: center;'> G. A New Beginning</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Annie has gotten bored of winning every coding contest and farming unlimited rating. Today, she is going to farm potatoes instead.

Annie's garden is an infinite 2D plane. She has $n$ potatoes to plant, and the $i$-th potato must be planted at $(x_i,y_i)$. Starting at the point $(0, 0)$, Annie begins walking, in one step she can travel one unit right or up (increasing her $x$ or $y$ coordinate by $1$ respectively). At any point $(X,Y)$ during her walk she can plant some potatoes at arbitrary points using her potato gun, consuming $\max(|X-x|,|Y-y|)$ units of energy in order to plant a potato at $(x,y)$. Find the minimum total energy required to plant every potato.

## Note

 that Annie may plant any number of potatoes from any point.

####### Input

The first line contains the integer $n$ ($1 \le n \le 800\,000$).

The next $n$ lines contain two integers $x_i$ and $y_i$ ($0 \le x_i,y_i \le 10^9$), representing the location of the $i$-th potato. It is possible that some potatoes should be planted in the same location.

####### Output

Print the minimum total energy to plant all potatoes.

## Examples

####### Input


```text
2
1 1
2 2
```
####### Output


```text
0
```
####### Input


```text
2
1 1
2 0
```
####### Output


```text
1
```
####### Input


```text
3
5 5
7 7
4 9
```
####### Output


```text
2
```
####### Input


```text
10
5 1
4 0
9 6
0 2
10 1
9 10
3 10
0 10
8 9
1 5
```
####### Output


```text
19
```
####### Input


```text
10
1 1
2 2
2 0
4 2
4 0
2 0
0 2
4 0
4 2
5 1
```
####### Output


```text
6
```
## Note

In example $1$, Annie can travel to each spot directly and plant a potato with no energy required.

In example $2$, moving to $(1,0)$, Annie plants the second potato using $1$ energy. Next, she travels to $(1,1)$ and plants the first potato with $0$ energy.



#### Tags 

#3300 #NOT OK #data_structures #dp #geometry #sortings 

## Blogs
- [All Contest Problems](../Codeforces_LATOKEN_Round_1_(Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
