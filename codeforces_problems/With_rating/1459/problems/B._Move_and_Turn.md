<h1 style='text-align: center;'> B. Move and Turn</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

A robot is standing at the origin of the infinite two-dimensional plane. Each second the robot moves exactly $1$ meter in one of the four cardinal directions: north, south, west, and east. For the first step the robot can choose any of the four directions, but then at the end of every second it has to turn 90 degrees left or right with respect to the direction it just moved in. For example, if the robot has just moved north or south, the next step it takes has to be either west or east, and vice versa.

The robot makes exactly $n$ steps from its starting position according to the rules above. How many different points can the robot arrive to at the end? The final orientation of the robot can be ignored.

##### Input

The only line contains a single integer $n$ ($1 \leq n \leq 1000$) — the number of steps the robot makes.

##### Output

Print a single integer — the number of different possible locations after exactly $n$ steps.

## Examples

##### Input


```text
1
```
##### Output


```text
4
```
##### Input


```text
2
```
##### Output


```text
4
```
##### Input


```text
3
```
##### Output


```text
12
```
## Note

In the first sample case, the robot will end up 1 meter north, south, west, or east depending on its initial direction.

In the second sample case, the robot will always end up $\sqrt{2}$ meters north-west, north-east, south-west, or south-east.



#### Tags 

#1300 #NOT OK #dp #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_691_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
