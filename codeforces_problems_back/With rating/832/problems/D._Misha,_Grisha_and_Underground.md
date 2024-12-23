<h1 style='text-align: center;'> D. Misha, Grisha and Underground</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Misha and Grisha are funny boys, so they like to use new underground. The underground has *n* stations connected with *n* - 1 routes so that each route connects two stations, and it is possible to reach every station from any other.

The boys decided to have fun and came up with a plan. Namely, in some day in the morning Misha will ride the underground from station *s* to station *f* by the shortest path, and will draw with aerosol an ugly text "Misha was here" on every station he will pass through (including *s* and *f*). After that on the same day at evening Grisha will ride from station *t* to station *f* by the shortest path and will count stations with Misha's text. After that at night the underground workers will wash the texts out, because the underground should be clean. 

The boys have already chosen three stations *a*, *b* and *c* for each of several following days, one of them should be station *s* on that day, another should be station *f*, and the remaining should be station *t*. They became interested how they should choose these stations *s*, *f*, *t* so that the number Grisha will count is as large as possible. They asked you for help.

## Input

The first line contains two integers *n* and *q* (2 ≤ *n* ≤ 105, 1 ≤ *q* ≤ 105) — the number of stations and the number of days.

The second line contains *n* - 1 integers *p*2, *p*3, ..., *p**n* (1 ≤ *p**i* ≤ *n*). The integer *p**i* means that there is a route between stations *p**i* and *i*. It is guaranteed that it's possible to reach every station from any other.

The next *q* lines contains three integers *a*, *b* and *c* each (1 ≤ *a*, *b*, *c* ≤ *n*) — the ids of stations chosen by boys for some day. ## Note

 that some of these ids could be same.

## Output

Print *q* lines. In the *i*-th of these lines print the maximum possible number Grisha can get counting when the stations *s*, *t* and *f* are chosen optimally from the three stations on the *i*-th day.

## Examples

## Input


```
3 2  
1 1  
1 2 3  
2 3 3  

```
## Output


```
2  
3  

```
## Input


```
4 1  
1 2 3  
1 2 3  

```
## Output


```
2  

```
## Note

In the first example on the first day if *s* = 1, *f* = 2, *t* = 3, Misha would go on the route 1 ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) 2, and Grisha would go on the route 3 ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) 1 ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) 2. He would see the text at the stations 1 and 2. On the second day, if *s* = 3, *f* = 2, *t* = 3, both boys would go on the route 3 ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) 1 ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) 2. Grisha would see the text at 3 stations.

In the second examle if *s* = 1, *f* = 3, *t* = 2, Misha would go on the route 1 ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) 2 ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) 3, and Grisha would go on the route 2 ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) 3 and would see the text at both stations.



#### tags 

#1900 #dfs_and_similar #graphs #trees 