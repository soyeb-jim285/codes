# Editorial_(en)


### [1253A - Single Push](../problems/A._Single_Push.md "Codeforces Round 600 (Div. 2)")

If we set $d_i = b_i - a_i$, we have to check that $d$ has the following form: $[0, 0, \ldots, 0, k, k, \ldots, k, 0, 0, \ldots, 0]$. Firstly check that there is no negative element in $d$.

Solution 1 : add $0$ to the beginning and the end of the array $d$, then check that there is at most two indices $i$ such that $d_i \neq d_{i+1}$.

Solution 2 : let $l$ be the smallest integer such that $d_l \neq 0$, and $r$ be the greatest integer such that $d_r \neq 0$. Check that for all $l \le i \le r$, $d_i = d_l$.

Complexity : $O(n)$ for each test case.

[Implementation (solution 1)](https://codeforces.com/https://pastebin.com/TCAqg38G)

 
### [1253B - Silly Mistake](../problems/B._Silly_Mistake.md "Codeforces Round 600 (Div. 2)")

We can solve this problem with a straightforward greedy solution: simulate the events in the order in which they occured, and as soon as the office is empty, end the current day and begin a new one.

We can prove that if there exists a valid solution, this greedy algorithm will find one (and furthermore, it will use maximum number of days, even if it wasn't required).

To do the simulation efficiently, we should maintain the state of each employee in an array (never went to the office today / in the office / left the office) and the number of employees currently in the office.

Each time we end a day, we have to reset all states of employees involved in the day (not all employees, otherwise the solution would be $O(n^2)$).

Final complexity is $O(n + e)$ where $e$ is the number of employees, or $O(n)$ if you compress the array beforehand.

[Implementation](https://codeforces.com/https://pastebin.com/whyCzpvV)

 
### [1253C - Sweets Eating](../problems/C._Sweets_Eating.md "Codeforces Round 600 (Div. 2)")

Let's sort array $a$. Now we can easily that if Yui wants to eat $k$ sweets, she has to eat sweets $k, k-1, \ldots, 1$ in this order, because of rearrangement inequality (put lower coefficients (day) on higher values (sugar concentration)).

A naive simulation of this strategy would have complexity $O(n^2)$, which is too slow.

Let's look what happens when we replace $k$ by $k+m$. During the first day, Yui will eat sweets $k+m, k+(m-1), \ldots, k+1$. Then, we reproduce the strategy used for $x_k$, but one day late : all coefficients are increased by $1$. 

Formally, $x_{k+m} - x_k = new + inc$ where $new = (a_{k+m} + \ldots + a_{k+1})$ because of new sweets eaten and $inc = (a_k + \ldots + a_1)$ because the coefficient of these sweets are all increased by $1$ (we eat them one day later).

We can derive the following formula : $x_k = (a_k + a_{k-1} + \ldots + a_1) + x_{k-m}$.

If we maintain the current prefix sum, and all previous answers computed in an array, we can compute all answers in $O(n)$.

Final complexity is $O(n \log n)$, because sorting is the slowest part of the solution.

[Implementation](https://codeforces.com/https://pastebin.com/3hZLq6sP)

 
### [1253D - Harmonious Graph](../problems/D._Harmonious_Graph.md "Codeforces Round 600 (Div. 2)")

For each connected component, let's find the weakest node $l$ and the biggest node $r$ in it (with one DFS per connected component).

If we look for all components at their intervals $[l\ ;\ r]$, we can see that two components should be connected in the resulting graph if and only if their intervals intersect. This leads to a $O(n^2 + m)$ naive solution : create a second graph where nodes represent components, add an edge between all pairs of components with intersecting intervals, and choose any spanning forest.

To optimize it, generate intervals in increasing order of $l$ (starting DFS in increasing order of nodes numbers). Look at them in this order, maintaining the biggest end $B$ seen. If $l \le B$, it is necessary to connect current interval to the interval ending at $B$ (hence increment answer).

It is quite easy to prove that doing only these connections is also sufficient (i.e. resulting graph will be harmonious).

Final complexity is $O(n + m)$.

[Implementation](https://codeforces.com/https://pastebin.com/Heb9bF7b)

 
### [1253E - Antenna Coverage](../problems/E._Antenna_Coverage.md "Codeforces Round 600 (Div. 2)")

We can add an antenna $(x=0, s=0)$. It will not modifiy the answer, because it would be non-optimal to increase the scope of this antenna.

Let $dp_x$ be the minimum cost to cover all positions from $x$ to $m$ inclusive, knowing that position $x$ is covered. We compute $dp$ in decreasing order of $x$.

Base case is $dp_m := 0$.

The default transition is $dp_x := (m - x)$.

If position $x+1$ is initially covered, $dp_x := dp_{x+1}$

Otherwise, let's consider all antennas and their initial intervals $[l_i; r_i]$. If $x < l_i$, let $u = (l_i - x - 1)$, then a possible transition is $dp_x := u + dp_{min(m, r_i + u)}$.

We take the minimum of all these transitions. Note that we always extend intervals as less as possible, but it's optimal because : 

* If after using this interval $i$, we use another interval $j$ (at the right of $i$), the time spent to extend $i$ could have been used to extend $j$ instead, which will be more optimal.
* If $i$ was the last interval used, we don't care because the default transition will take care of this case.

The final answer will be $dp_0$.

There are $O(m)$ states and $O(n)$ transitions, hence final complexity is $O(nm)$ with very low constant. $O(n^2 \cdot m)$ can also get AC because of very low constant.

[Implementation](https://codeforces.com/https://pastebin.com/6FeZb3XH)

 
### [1253F - Cheap Robot](../problems/F._Cheap_Robot.md "Codeforces Round 600 (Div. 2)")

Key insight 1: Since we always end on a central, at any time our robot have to be able to reach the nearest central.

Key insight 2: Since we always start from a central, from any node $u$, going to the nearest central, then going back to $u$ can't decrease the number of energy points in the battery.

—

Firstly, let's do a multi-source Dijkstra from all centrals. We denote $d_u$ the distance from node $u$ to the nearest central.

Consider a fixed capacity $c$. Suppose that we're on node $u$ with $x$ energy points remaining in the battery. Note that $x \le c - d_u$.

If $x < d_u$, we can't do anything, the robot is lost because it can't reach any central anymore.

Otherwise, if $x \ge d_u$, we can go to the nearest central, then go back to $u$, hence we can always consider than $x = c - d_u$.

This is a simple but very powerful observation that allows us to delete the battery level in states explored. Hence, we can now solve the problem in $O(m \log m + qm \log n)$, doing binary search on answer and simple DFS for each query.

—

We need to optimize this solution. Now, reaching a node $u$ will mean reaching it with $x \ge d_u$.

During exploration of nodes, the necessary and sufficient condition for being able to reach node $v$ from $u$, through an edge of weight $w$, is that $(c - d_u) - w \ge d_v$, i.e. $d_u + d_v + w \le c$.

Hence, if we replace the weight of each edge $(u, v, w)$ by $w' = d_u + d_v + w$, the problem is reduced to find a shortest path from $a_i$ to $b_i$, in terms of maximum weight over edges used (which will be the capacity required by this path).

Solution 1 (offline):

Sort edges by new weight. Add them progressively, maintaining connexity with DSU.

As soon as two endpoints of a query become connected, we should put current capacity (i.e. new weight of the last edge added) as answer for this query.

To effeciently detect this, we can put tokens on endpoints of each query, and each time we do union (of DSU), we make tokens go up to the parent. If we do union by rank, each token will move at most $O(\log n)$ times.

Solution 2 (online):

Let's construct a MST of the new graph with Kruskal.

It is well-known that in this particular MST, for every pair of nodes $(u, v)$, the only path from $u$ to $v$ will be a shortest path (in terms of maximum weight over the path).

Hence we just have to compute the weight of paths in a tree, which can be done with binary lifting.

These two solutions both run in $O(m \log m + q \log n)$. Implementation of solution 1 is a bit shorter, but solution 2 can deal with online queries.

* [Solution 1 (hugopm)](https://codeforces.com/https://pastebin.com/xrm0MU71)
* [Solution 2 (faremy)](https://codeforces.com/https://pastebin.com/J8c8x2Fg)
