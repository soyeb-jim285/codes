<h1 style='text-align: center;'> B. Frog Traveler</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Frog Gorf is traveling through Swamp kingdom. Unfortunately, after a poor jump, he fell into a well of $n$ meters depth. Now Gorf is on the bottom of the well and has a long way up.

The surface of the well's walls vary in quality: somewhere they are slippery, but somewhere have convenient ledges. In other words, if Gorf is on $x$ meters below ground level, then in one jump he can go up on any integer distance from $0$ to $a_x$ meters inclusive. (
## Note

 that Gorf can't jump down, only up).

Unfortunately, Gorf has to take a break after each jump (including jump on $0$ meters). And after jumping up to position $x$ meters below ground level, he'll slip exactly $b_x$ meters down while resting.

Calculate the minimum number of jumps Gorf needs to reach ground level.

##### Input

The first line contains a single integer $n$ ($1 \le n \le 300\,000$) — the depth of the well.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le i$), where $a_i$ is the maximum height Gorf can jump from $i$ meters below ground level.

The third line contains $n$ integers $b_1, b_2, \ldots, b_n$ ($0 \le b_i \le n - i$), where $b_i$ is the distance Gorf will slip down if he takes a break on $i$ meters below ground level.

##### Output

If Gorf can't reach ground level, print $-1$. Otherwise, firstly print integer $k$ — the minimum possible number of jumps.

Then print the sequence $d_1,\,d_2,\,\ldots,\,d_k$ where $d_j$ is the depth Gorf'll reach after the $j$-th jump, but before he'll slip down during the break. Ground level is equal to $0$.

If there are multiple answers, print any of them.

## Examples

##### Input


```text
3
0 2 2
1 1 0
```
##### Output


```text
2
1 0 
```
##### Input


```text
2
1 1
1 0
```
##### Output


```text
-1
```
##### Input


```text
10
0 1 2 3 5 5 6 7 8 5
9 8 7 1 5 4 3 2 0 0
```
##### Output


```text
3
9 4 0 
```
## Note

In the first example, Gorf is on the bottom of the well and jump to the height $1$ meter below ground level. After that he slip down by meter and stays on height $2$ meters below ground level. Now, from here, he can reach ground level in one jump.

In the second example, Gorf can jump to one meter below ground level, but will slip down back to the bottom of the well. That's why he can't reach ground level.

In the third example, Gorf can reach ground level only from the height $5$ meters below the ground level. And Gorf can reach this height using a series of jumps $10 \Rightarrow 9 \dashrightarrow 9 \Rightarrow 4 \dashrightarrow 5$ where $\Rightarrow$ is the jump and $\dashrightarrow$ is slipping during breaks.



#### Tags 

#1900 #NOT OK #data_structures #dfs_and_similar #dp #graphs #shortest_paths #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_751_(Div._1).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
