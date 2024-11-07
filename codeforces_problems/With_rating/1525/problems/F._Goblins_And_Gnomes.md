<h1 style='text-align: center;'> F. Goblins And Gnomes</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Monocarp plays a computer game called "Goblins and Gnomes". In this game, he manages a large underground city of gnomes and defends it from hordes of goblins.

The city consists of $n$ halls and $m$ one-directional tunnels connecting them. The structure of tunnels has the following property: if a goblin leaves any hall, he cannot return to that hall. 

The city will be attacked by $k$ waves of goblins; during the $i$-th wave, $i$ goblins attack the city. Monocarp's goal is to pass all $k$ waves.

The $i$-th wave goes as follows: firstly, $i$ goblins appear in some halls of the city and pillage them; at most one goblin appears in each hall. Then, goblins start moving along the tunnels, pillaging all the halls in their path. 

Goblins are very greedy and cunning, so they choose their paths so that no two goblins pass through the same hall. Among all possible attack plans, they choose a plan which allows them to pillage the maximum number of halls. After goblins are done pillaging, they leave the city.

If all halls are pillaged during the wave — Monocarp loses the game. Otherwise, the city is restored. If some hall is pillaged during a wave, goblins are still interested in pillaging it during the next waves.

Before each wave, Monocarp can spend some time preparing to it. Monocarp doesn't have any strict time limits on his preparations (he decides when to call each wave by himself), but the longer he prepares for a wave, the fewer points he gets for passing it. If Monocarp prepares for the $i$-th wave for $t_i$ minutes, then he gets $\max(0, x_i - t_i \cdot y_i)$ points for passing it (obviously, if he doesn't lose in the process).

While preparing for a wave, Monocarp can block tunnels. He can spend one minute to either block all tunnels leading from some hall or block all tunnels leading to some hall. If Monocarp blocks a tunnel while preparing for a wave, it stays blocked during the next waves as well.

Help Monocarp to defend against all $k$ waves of goblins and get the maximum possible amount of points!

##### Input

The first line contains three integers $n$, $m$ and $k$ ($2 \le n \le 50$; $0 \le m \le \frac{n(n - 1)}{2}$; $1 \le k \le n - 1$) — the number of halls in the city, the number of tunnels and the number of goblin waves, correspondely.

Next $m$ lines describe tunnels. The $i$-th line contains two integers $u_i$ and $v_i$ ($1 \le u_i, v_i \le n$; $u_i \ne v_i$). It means that the tunnel goes from hall $u_i$ to hall $v_i$. The structure of tunnels has the following property: if a goblin leaves any hall, he cannot return to that hall. There is at most one tunnel between each pair of halls.

Next $k$ lines describe the scoring system. The $i$-th line contains two integers $x_i$ and $y_i$ ($1 \le x_i \le 10^9$; $1 \le y_i \le 10^9$). If Monocarp prepares for the $i$-th wave for $t_i$ minutes, then he gets $\max(0, x_i - t_i \cdot y_i)$ points for passing it.

##### Output

Print the optimal Monocarp's strategy in the following format:

At first, print one integer $a$ ($k \le a \le 2n + k$) — the number of actions Monocarp will perform. Next, print actions themselves in the order Monocarp performs them. The $i$-th action is described by a single integer $b_i$ ($-n \le b_i \le n$) using the following format:

* if $b_i > 0$ then Monocarp blocks all tunnels going out from the hall $b_i$;
* if $b_i < 0$ then Monocarp blocks all tunnels going into the hall $|b_i|$;
* if $b_i = 0$ then Monocarp calls the next goblin wave.

You can't repeat the same block action $b_i$ several times. Monocarp must survive all waves he calls (goblins shouldn't be able to pillage all halls). Monocarp should call exactly $k$ waves and earn the maximum possible number of points in total.

If there are several optimal strategies — print any of them.

## Examples

##### Input


```text
5 4 4
1 2
2 3
4 3
5 3
100 1
200 5
10 10
100 1
```
##### Output


```text
6
-2 -3 0 0 0 0 
```
##### Input


```text
5 4 4
1 2
2 3
4 3
5 3
100 100
200 5
10 10
100 1
```
##### Output


```text
6
0 -3 0 0 1 0
```
##### Input


```text
5 10 1
1 2
1 3
1 4
1 5
5 2
5 3
5 4
4 2
4 3
2 3
100 100
```
##### Output


```text
6
1 2 3 4 5 0
```
## Note

In the first example, Monocarp, firstly, block all tunnels going in hall $2$, secondly — all tunnels going in hall $3$, and after that calls all waves. He spent two minutes to prepare to wave $1$, so he gets $98$ points for it. He didn't prepare after that, that's why he gets maximum scores for each of next waves ($200$, $10$ and $100$). In total, Monocarp earns $408$ points.

In the second example, Monocarp calls for the first wave immediately and gets $100$ points. Before the second wave he blocks all tunnels going in hall $3$. He spent one minute preparing to the wave, so he gets $195$ points. Monocarp didn't prepare for the third wave, so he gets $10$ points by surviving it. Before the fourth wave he blocks all tunnels going out from hall $1$. He spent one minute, so he gets $99$ points for the fourth wave. In total, Monocarp earns $404$ points.

In the third example, it doesn't matter how many minutes Monocarp will spend before the wave, since he won't get any points for it. That's why he decides to block all tunnels in the city, spending $5$ minutes. He survived the wave though without getting any points.



#### Tags 

#2800 #NOT OK #brute_force #dp #flows #graph_matchings 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_109_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
