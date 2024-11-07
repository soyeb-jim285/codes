<h1 style='text-align: center;'> A. Walking Master</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

YunQian is standing on an infinite plane with the Cartesian coordinate system on it. In one move, she can move to the diagonally adjacent point on the top right or the adjacent point on the left.

That is, if she is standing on point $(x,y)$, she can either move to point $(x+1,y+1)$ or point $(x-1,y)$.

YunQian initially stands at point $(a,b)$ and wants to move to point $(c,d)$. Find the minimum number of moves she needs to make or declare that it is impossible.

## Input

The first line contains a single integer $t$ ($1\le t\le 10^4$) — the number of test cases. The description of test cases follows.

The first line and only line of each test case contain four integers $a$, $b$, $c$, $d$ ($-10^8\le a,b,c,d\le 10^8$).

## Output

For each test case, if it is possible to move from point $(a,b)$ to point $(c,d)$, output the minimum number of moves. Otherwise, output $-1$.

## Example

## Input


```

6-1 0 -1 20 0 4 5-2 -1 1 1-3 2 -3 22 -1 -1 -11 1 0 2
```
## Output


```

4
6
-1
0
3
3

```
## Note

In the first test case, one possible way using $4$ moves is $(-1,0)\to (0,1)\to (-1,1)\to (0,2)\to (-1,2)$. It can be proven that it is impossible to move from point $(-1,0)$ to point $(-1,2)$ in less than $4$ moves.



#### tags 

#800 #geometry #greedy #math 