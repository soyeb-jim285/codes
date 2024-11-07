<h1 style='text-align: center;'> E. Long Way Home</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Stanley lives in a country that consists of $n$ cities (he lives in city $1$). There are bidirectional roads between some of the cities, and you know how long it takes to ride through each of them. Additionally, there is a flight between each pair of cities, the flight between cities $u$ and $v$ takes $(u - v)^2$ time.

Stanley is quite afraid of flying because of watching "Sully: Miracle on the Hudson" recently, so he can take at most $k$ flights. Stanley wants to know the minimum time of a journey to each of the $n$ cities from the city $1$.

###### Input

In the first line of input there are three integers $n$, $m$, and $k$ ($2 \leq n \leq 10^{5}$, $1 \leq m \leq 10^{5}$, $1 \leq k \leq 20$) — the number of cities, the number of roads, and the maximal number of flights Stanley can take.

The following $m$ lines describe the roads. Each contains three integers $u$, $v$, $w$ ($1 \leq u, v \leq n$, $u \neq v$, $1 \leq w \leq 10^{9}$) — the cities the road connects and the time it takes to ride through. 
## Note

 that some pairs of cities may be connected by more than one road.

###### Output

Print $n$ integers, $i$-th of which is equal to the minimum time of traveling to city $i$.

## Examples

###### Input


```text
3 1 2
1 3 1
```
###### Output


```text
0 1 1 
```
###### Input

```text

4 3 1
1 2 3
2 4 5
3 4 7

```
###### Output


```text
0 1 4 6 
```
###### Input

```text

2 1 1
2 1 893746473

```
###### Output


```text
0 1 
```
###### Input

```text

5 5 2
2 1 33
1 5 93
5 3 48
2 3 21
4 2 1

```
###### Output


```text

0 1 2 2 3 
```
## Note

In the first sample, it takes no time to get to city 1; to get to city 2 it is possible to use a flight between 1 and 2, which will take 1 unit of time; to city 3 you can get via a road from city 1, which will take 1 unit of time. 

In the second sample, it also takes no time to get to city 1. To get to city 2 Stanley should use a flight between 1 and 2, which will take 1 unit of time. To get to city 3 Stanley can ride between cities 1 and 2, which will take 3 units of time, and then use a flight between 2 and 3. To get to city 4 Stanley should use a flight between 1 and 2, then take a ride from 2 to 4, which will take 5 units of time.



#### Tags 

#2400 #NOT OK #data_structures #divide_and_conquer #dp #geometry #graphs #greedy #shortest_paths 

## Blogs
- [All Contest Problems](../Codeforces_Round_816_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
