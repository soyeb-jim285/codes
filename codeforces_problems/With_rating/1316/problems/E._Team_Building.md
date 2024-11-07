<h1 style='text-align: center;'> E. Team Building</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice, the president of club FCB, wants to build a team for the new volleyball tournament. The team should consist of $p$ players playing in $p$ different positions. She also recognizes the importance of audience support, so she wants to select $k$ people as part of the audience.

There are $n$ people in Byteland. Alice needs to select exactly $p$ players, one for each position, and exactly $k$ members of the audience from this pool of $n$ people. Her ultimate goal is to maximize the total strength of the club.

The $i$-th of the $n$ persons has an integer $a_{i}$ associated with him — the strength he adds to the club if he is selected as a member of the audience.

For each person $i$ and for each position $j$, Alice knows $s_{i, j}$  — the strength added by the $i$-th person to the club if he is selected to play in the $j$-th position.

Each person can be selected at most once as a player or a member of the audience. You have to choose exactly one player for each position.

Since Alice is busy, she needs you to help her find the maximum possible strength of the club that can be achieved by an optimal choice of players and the audience.

##### Input

The first line contains $3$ integers $n,p,k$ ($2 \leq n \leq 10^{5}, 1 \leq p \leq 7, 1 \le k, p+k \le n$).

The second line contains $n$ integers $a_{1},a_{2},\ldots,a_{n}$. ($1 \leq a_{i} \leq 10^{9}$).

The $i$-th of the next $n$ lines contains $p$ integers $s_{i, 1}, s_{i, 2}, \dots, s_{i, p}$. ($1 \leq s_{i,j} \leq 10^{9}$)

##### Output

Print a single integer ${res}$  — the maximum possible strength of the club.

## Examples

##### Input


```text
4 1 2
1 16 10 3
18
19
13
15
```
##### Output


```text
44
```
##### Input


```text
6 2 3
78 93 9 17 13 78
80 97
30 52
26 17
56 68
60 36
84 55
```
##### Output


```text
377
```
##### Input


```text
3 2 1
500 498 564
100002 3
422332 2
232323 1
```
##### Output


```text
422899
```
## Note

In the first sample, we can select person $1$ to play in the $1$-st position and persons $2$ and $3$ as audience members. Then the total strength of the club will be equal to $a_{2}+a_{3}+s_{1,1}$.



#### Tags 

#2300 #NOT OK #bitmasks #dp #greedy #sortings 

## Blogs
- [All Contest Problems](../CodeCraft-20_(Div._2).md)
- [CodeCraft-20 (Div. 2) (en)](../blogs/CodeCraft-20_(Div._2)_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
