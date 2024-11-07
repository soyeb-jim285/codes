<h1 style='text-align: center;'> E. Restorer Distance</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have to restore the wall. The wall consists of $N$ pillars of bricks, the height of the $i$-th pillar is initially equal to $h_{i}$, the height is measured in number of bricks. After the restoration all the $N$ pillars should have equal heights.

You are allowed the following operations:

* put a brick on top of one pillar, the cost of this operation is $A$;
* remove a brick from the top of one non-empty pillar, the cost of this operation is $R$;
* move a brick from the top of one non-empty pillar to the top of another pillar, the cost of this operation is $M$.

You cannot create additional pillars or ignore some of pre-existing pillars even if their height becomes $0$.

What is the minimal total cost of restoration, in other words, what is the minimal total cost to make all the pillars of equal height?

####### Input

The first line of input contains four integers $N$, $A$, $R$, $M$ ($1 \le N \le 10^{5}$, $0 \le A, R, M \le 10^{4}$) — the number of pillars and the costs of operations.

The second line contains $N$ integers $h_{i}$ ($0 \le h_{i} \le 10^{9}$) — initial heights of pillars.

####### Output

Print one integer — the minimal cost of restoration.

## Examples

####### Input


```text
3 1 100 100
1 3 8
```
####### Output


```text
12
```
####### Input


```text
3 100 1 100
1 3 8
```
####### Output


```text
9
```
####### Input


```text
3 100 100 1
1 3 8
```
####### Output


```text
4
```
####### Input


```text
5 1 2 4
5 5 3 6 5
```
####### Output


```text
4
```
####### Input


```text
5 1 2 2
5 5 3 6 5
```
####### Output


```text
3
```


#### Tags 

#2100 #NOT OK #binary_search #greedy #math #sortings #ternary_search 

## Blogs
- [All Contest Problems](../Codeforces_Round_643_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
