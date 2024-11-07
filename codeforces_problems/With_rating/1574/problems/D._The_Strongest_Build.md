<h1 style='text-align: center;'> D. The Strongest Build</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Ivan is playing yet another roguelike computer game. He controls a single hero in the game. The hero has $n$ equipment slots. There is a list of $c_i$ items for the $i$-th slot, the $j$-th of them increases the hero strength by $a_{i,j}$. The items for each slot are pairwise distinct and are listed in the increasing order of their strength increase. So, $a_{i,1} < a_{i,2} < \dots < a_{i,c_i}$.

For each slot Ivan chooses exactly one item. Let the chosen item for the $i$-th slot be the $b_i$-th item in the corresponding list. The sequence of choices $[b_1, b_2, \dots, b_n]$ is called a build.

The strength of a build is the sum of the strength increases of the items in it. Some builds are banned from the game. There is a list of $m$ pairwise distinct banned builds. It's guaranteed that there's at least one build that's not banned.

What is the build with the maximum strength that is not banned from the game? If there are multiple builds with maximum strength, print any of them.

###### Input

The first line contains a single integer $n$ ($1 \le n \le 10$) — the number of equipment slots.

The $i$-th of the next $n$ lines contains the description of the items for the $i$-th slot. First, one integer $c_i$ ($1 \le c_i \le 2 \cdot 10^5$) — the number of items for the $i$-th slot. Then $c_i$ integers $a_{i,1}, a_{i,2}, \dots, a_{i,c_i}$ ($1 \le a_{i,1} < a_{i,2} < \dots < a_{i,c_i} \le 10^8$).

The sum of $c_i$ doesn't exceed $2 \cdot 10^5$.

The next line contains a single integer $m$ ($0 \le m \le 10^5$) — the number of banned builds.

Each of the next $m$ lines contains a description of a banned build — a sequence of $n$ integers $b_1, b_2, \dots, b_n$ ($1 \le b_i \le c_i$).

The builds are pairwise distinct, and there's at least one build that's not banned.

###### Output

Print the build with the maximum strength that is not banned from the game. If there are multiple builds with maximum strength, print any of them.

## Examples

###### Input


```text
3
3 1 2 3
2 1 5
3 2 4 6
2
3 2 3
3 2 2
```
###### Output


```text
2 2 3 
```
###### Input


```text
3
3 1 2 3
2 1 5
3 2 4 6
2
3 2 3
2 2 3
```
###### Output


```text
1 2 3
```
###### Input


```text
3
3 1 2 3
2 1 5
3 2 4 6
2
3 2 3
2 2 3
```
###### Output


```text
3 2 2
```
###### Input


```text
4
1 10
1 4
1 7
1 3
0
```
###### Output


```text
1 1 1 1 
```


#### Tags 

#2000 #NOT OK #binary_search #brute_force #data_structures #dfs_and_similar #graphs #greedy #hashing #implementation 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_114_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
