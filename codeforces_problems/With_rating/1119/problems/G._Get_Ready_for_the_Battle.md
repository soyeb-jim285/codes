<h1 style='text-align: center;'> G. Get Ready for the Battle</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Recently Evlampy installed one interesting computer game, one of aspects of which is to split army into several groups and then fight with enemy's groups. Let us consider a simplified version of the battle.

In the nearest battle Evlampy should fight an enemy army that consists of $m$ groups, the $i$-th of which has $hp_i$ health points.

Evlampy's army consists of $n$ equal soldiers. Before each battle he should split his army in exactly $m$ groups (possibly, empty) so that the total size of the groups is $n$. The battle is played step-by-step. On each step each of Evlampy's groups attacks exactly one enemy group. Thus, each step is described with an array of $m$ integers $a_1, a_2, \ldots, a_m$, meaning that the $i$-th Evlampy's group attacks the $a_i$-th enemy group. Different groups can attack same group, on each step the array $a$ is chosen independently.

After each step the health points of each enemy group decreases by the total number of soldiers in Evlampy's groups that attacked this enemy group at this step. Enemy group is destroyed once its health points are zero or negative. Evlampy's soldiers do not lose health.

 ![](images/1321afe5b27acc9bf2dced645122257facbe607d.png) An example of a step. The numbers in green circles represent the number of soldiers in Evlampy's groups, the arrows represent attacks, the numbers in red circles represent health points of enemy groups, the blue numbers represent how much the health points will decrease after the step. Evlampy understands that the upcoming battle will take the whole night. He became sad because this way he won't have enough time to finish his homework. Now Evlampy wants you to write a program that will help him win in the smallest possible number of steps. Can you help him?

In other words, find the smallest number of steps needed to destroy all enemy groups and show a possible way of doing this. Find the requires splitting of the army into $m$ groups and the arrays $a$ for each step.

##### Input

The first line contains two integers $n$ and $m$ ($1 \leq m \leq n \leq 10^{6}$) — the number of soldiers in Evlampy's army and the number of groups in enemy army. $m$ is also equal to the maximum possible number of groups Evlampy can split the army to.

The second line contains $m$ integers $hp_1, hp_2, \ldots, hp_m$ ($1 \leq hp_i \leq 10^{6}$) — the health points of each of the enemy groups.

It is guaranteed that the sum of $hp_i$ does not exceed $10^{6}$.

##### Output

Print a single integer $t$ — the minimum possible number of steps needed to win the battle.

After that print $m$ integers $s_1, s_2, \ldots, s_m$ ($s_i \ge 0$, $s_1 + s_2 + \ldots + s_m = n$), meaning that the $i$-th group of Evlampy's army should contain $s_i$ soldiers.

In each of the next $t$ lines print $m$ integers $a_1, a_2, \ldots, a_m$ ($1 \le a_i \le m$) — the description of one step. The integers mean that on the corresponding step the $i$-th Evlampy's group should attack the $a_i$-th enemy group. It is allowed to attack an already destroyed group.

## Examples

##### Input


```text
13 7
6 4 3 7 2 1 5
```
##### Output


```text
3
0 1 2 3 1 2 4
2 6 2 4 4 2 4
3 1 7 1 7 7 1
3 1 5 3 7 5 1
```
##### Input


```text
6 5
3 3 3 3 3
```
##### Output


```text
3
3 3 0 0 0
1 2 3 4 5
3 4 5 5 5
5 5 5 5 5
```
##### Input


```text
7 4
1 5 9 2
```
##### Output


```text

3
1 2 4 0
1 4 2 3
2 3 3 3
3 3 3 3
```
## Note

The first example is shown below.

 ![](images/ecd0ec8058c79a59b35e2658cd6a87ff42964a89.png) 

#### Tags 

#3100 #NOT OK #constructive_algorithms #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_2.md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
