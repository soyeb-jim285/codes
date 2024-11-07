<h1 style='text-align: center;'> C. Game Master</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

$n$ players are playing a game. 

There are two different maps in the game. For each player, we know his strength on each map. When two players fight on a specific map, the player with higher strength on that map always wins. No two players have the same strength on the same map. 

You are the game master and want to organize a tournament. There will be a total of $n-1$ battles. While there is more than one player in the tournament, choose any map and any two remaining players to fight on it. The player who loses will be eliminated from the tournament. 

In the end, exactly one player will remain, and he is declared the winner of the tournament. For each player determine if he can win the tournament.

### Input

The first line contains a single integer $t$ ($1 \le t \le 100$) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 10^5$) — the number of players.

The second line of each test case contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \leq a_i \leq 10^9$, $a_i \neq a_j$ for $i \neq j$), where $a_i$ is the strength of the $i$-th player on the first map. 

The third line of each test case contains $n$ integers $b_1, b_2, \dots, b_n$ ($1 \leq b_i \leq 10^9$, $b_i \neq b_j$ for $i \neq j$), where $b_i$ is the strength of the $i$-th player on the second map. 

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

### Output

For each test case print a string of length $n$. $i$-th character should be "1" if the $i$-th player can win the tournament, or "0" otherwise.

## Example

### Input


```text
3
4
1 2 3 4
1 2 3 4
4
11 12 20 21
44 22 11 30
1
1000000000
1000000000
```
### Output


```text
0001
1111
1
```
## Note

In the first test case, the $4$-th player will beat any other player on any game, so he will definitely win the tournament.

In the second test case, everyone can be a winner. 

In the third test case, there is only one player. Clearly, he will win the tournament.



#### Tags 

#1700 #NOT OK #data_structures #dfs_and_similar #dp #graphs #greedy #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_758_(Div.1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
