<h1 style='text-align: center;'> E. Trips</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are $n$ persons who initially don't know each other. On each morning, two of them, who were not friends before, become friends.

We want to plan a trip for every evening of $m$ days. On each trip, you have to select a group of people that will go on the trip. For every person, one of the following should hold: 

* Either this person does not go on the trip,
* Or at least $k$ of his friends also go on the trip.

## Note

 that the friendship is not transitive. That is, if $a$ and $b$ are friends and $b$ and $c$ are friends, it does not necessarily imply that $a$ and $c$ are friends.

For each day, find the maximum number of people that can go on the trip on that day.

##### Input

The first line contains three integers $n$, $m$, and $k$ ($2 \leq n \leq 2 \cdot 10^5, 1 \leq m \leq 2 \cdot 10^5$, $1 \le k < n$) — the number of people, the number of days and the number of friends each person on the trip should have in the group.

The $i$-th ($1 \leq i \leq m$) of the next $m$ lines contains two integers $x$ and $y$ ($1\leq x, y\leq n$, $x\ne y$), meaning that persons $x$ and $y$ become friends on the morning of day $i$. It is guaranteed that $x$ and $y$ were not friends before.

##### Output

Print exactly $m$ lines, where the $i$-th of them ($1\leq i\leq m$) contains the maximum number of people that can go on the trip on the evening of the day $i$.

## Examples

##### Input


```text
4 4 2  
2 3  
1 2  
1 3  
1 4  

```
##### Output


```text
0  
0  
3  
3  

```
##### Input


```text
5 8 2  
2 1  
4 2  
5 4  
5 2  
4 3  
5 1  
4 1  
3 2  

```
##### Output


```text
0  
0  
0  
3  
3  
4  
4  
5  

```
##### Input


```text
5 7 2  
1 5  
3 2  
2 5  
3 4  
1 2  
5 3  
1 3  

```
##### Output


```text
0  
0  
0  
0  
3  
4  
4  

```
## Note

In the first example, 

* $1,2,3$ can go on day $3$ and $4$.

In the second example, 

* $2,4,5$ can go on day $4$ and $5$.
* $1,2,4,5$ can go on day $6$ and $7$.
* $1,2,3,4,5$ can go on day $8$.

In the third example, 

* $1,2,5$ can go on day $5$.
* $1,2,3,5$ can go on day $6$ and $7$.


#### Tags 

#2200 #NOT OK #graphs 

## Blogs
- [All Contest Problems](../Manthan,_Codefest_18_(rated,_Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
