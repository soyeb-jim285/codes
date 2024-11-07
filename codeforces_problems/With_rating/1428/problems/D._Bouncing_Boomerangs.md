<h1 style='text-align: center;'> D. Bouncing Boomerangs</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

To improve the boomerang throwing skills of the animals, Zookeeper has set up an $n \times n$ grid with some targets, where each row and each column has at most $2$ targets each. The rows are numbered from $1$ to $n$ from top to bottom, and the columns are numbered from $1$ to $n$ from left to right. 

 For each column, Zookeeper will throw a boomerang from the bottom of the column (below the grid) upwards. When the boomerang hits any target, it will bounce off, make a $90$ degree turn to the right and fly off in a straight line in its new direction. The boomerang can hit multiple targets and does not stop until it leaves the grid.

 

 ![](images/2edb4bdf2fa014aa216c6a12a6c8043f527379a0.png) In the above example, $n=6$ and the black crosses are the targets. The boomerang in column $1$ (blue arrows) bounces $2$ times while the boomerang in column $3$ (red arrows) bounces $3$ times.

 The boomerang in column $i$ hits exactly $a_i$ targets before flying out of the grid. It is known that $a_i \leq 3$.

However, Zookeeper has lost the original positions of the targets. Thus, he asks you to construct a valid configuration of targets that matches the number of hits for each column, or tell him that no such configuration exists. If multiple valid configurations exist, you may print any of them.

##### Input

The first line contains a single integer $n$ $(1 \leq n \leq 10^5)$.

 The next line contains $n$ integers $a_1,a_2,\ldots,a_n$ $(0 \leq a_i \leq 3)$.

##### Output

If no configuration of targets exist, print $-1$.

 Otherwise, on the first line print a single integer $t$ $(0 \leq t \leq 2n)$: the number of targets in your configuration. 

 Then print $t$ lines with two spaced integers each per line. Each line should contain two integers $r$ and $c$ $(1 \leq r,c \leq n)$, where $r$ is the target's row and $c$ is the target's column. All targets should be different. 

 Every row and every column in your configuration should have at most two targets each. 

## Examples

##### Input


```text
6
2 0 3 0 1 1
```
##### Output


```text
5
2 1
2 5
3 3
3 6
5 6
```
##### Input


```text
1
0
```
##### Output


```text
0
```
##### Input


```text
6
3 2 2 2 1 1
```
##### Output


```text
-1
```
## Note

For the first test, the answer configuration is the same as in the picture from the statement.

 For the second test, the boomerang is not supposed to hit anything, so we can place $0$ targets.

 For the third test, the following configuration of targets matches the number of hits, but is not allowed as row $3$ has $4$ targets.

 

 ![](images/f6c347d88a5e2a4ac5c1a4609348a7d4aa3a2c13.png) It can be shown for this test case that no valid configuration of targets will result in the given number of target hits.



#### Tags 

#1900 #NOT OK #constructive_algorithms #greedy #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Raif_Round_1_(Div._1_+_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
