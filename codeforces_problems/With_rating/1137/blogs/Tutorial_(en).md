# Tutorial_(en)

Credits:

[1138A - Sushi for Two](https://codeforces.com/contest/1138/problem/A "Codeforces Round 545 (Div. 2)"), idea and development by [KAN](https://codeforces.com/profile/KAN "Grandmaster KAN")

[1138B - Circus](https://codeforces.com/contest/1138/problem/B "Codeforces Round 545 (Div. 2)"), idea by [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov"), development by [cdkrot](https://codeforces.com/profile/cdkrot "Grandmaster cdkrot")

[1137A - Skyscrapers](../problems/A._Skyscrapers.md "Codeforces Round 545 (Div. 1)"), idea by jury together, development: [achulkov2](https://codeforces.com/profile/achulkov2 "Expert achulkov2")

[1137B - Camp Schedule](../problems/B._Camp_Schedule.md "Codeforces Round 545 (Div. 1)"), idea and development by [wrg0ababd](https://codeforces.com/profile/wrg0ababd "Expert wrg0ababd")

[1137C - Museums Tour](../problems/C._Museums_Tour.md "Codeforces Round 545 (Div. 1)"), idea by [ch_egor](https://codeforces.com/profile/ch_egor "International Grandmaster ch_egor"), development by [qoo2p5](https://codeforces.com/profile/qoo2p5 "Grandmaster qoo2p5")

[1137D - Cooperative Game](../problems/D._Cooperative_Game.md "Codeforces Round 545 (Div. 1)"), idea and development by [mingaleg](https://codeforces.com/profile/mingaleg "Candidate Master mingaleg")

[1137E - Train Car Selection](../problems/E._Train_Car_Selection.md "Codeforces Round 545 (Div. 1)"), idea and development by [Schemtschik](https://codeforces.com/profile/Schemtschik "Candidate Master Schemtschik")

[1137F - Matches Are Not a Child's Play](../problems/F._Matches_Are_Not_a_Child's_Play_.md "Codeforces Round 545 (Div. 1)") , idea by [GlebsHP](https://codeforces.com/profile/GlebsHP "International Grandmaster GlebsHP"), development: [cdkrot](https://codeforces.com/profile/cdkrot "Grandmaster cdkrot")

And now the editorials:

 
### [1138A - Sushi for Two](https://codeforces.com/contest/1138/problem/A "Codeforces Round 545 (Div. 2)")

It is more or less obvious that the answer is the maximum among the minimums of the length of two consecutive segments of equal elements. As for implementation, just go from left to right and keep the last element, the length of the current segment and the length of the next segment. When the current element is not the same as the last element, update the answer.

 
### [1138B - Circus](https://codeforces.com/contest/1138/problem/B "Codeforces Round 545 (Div. 2)")

Note, that there are only four types of artists: «0; 0», «0; 1», «1; 0», «1; 1».

So the whole problem can be described with four integers — the number of artists of each type. Let's say, that there are $n_a$ «0; 0» artists, $n_b$ «0; 1» artists, $n_c$ «1; 0» artists, $n_d$ «1, 1» artists.

In the same manner, the selection of artists for the first performance can be described with four integers $0 \le a \le n_a$, $0 \le b \le n_b$, $0 \le c \le n_c$, $0 \le d \le n_d$.

Note, that we have some restrictions on $a$, $b$, $c$, $d$.

In particular, we need to select exactly half of the artists: $a + b + c + d = \frac{n}{2}$.

Also we have a requirement that the number of clowns in first performance ($c + d$) must be equal to number of acrobats in the second ($n_b - b + n_d - d$): $c + d = n_b - b + n_d - d$, so we have $b + c + 2d = n_b + n_d$.

This equations are necessary and sufficient. So we have 4 unknown variables and 2 equations. We can bruteforce any two variables, calculate using them other two variables. And if everything went well, print an answer.

Complexity: $\mathcal{O}(n^2$).

 Tutorial is loading... 
### [1137B - Camp Schedule](../problems/B._Camp_Schedule.md "Codeforces Round 545 (Div. 1)")

If we can't make any occurrences of string $t$ in string $s$ just output any permutation of $s$. 

Otherwise, we can show that there is an optimal answer $x$, such that it starts with a string $t$.

Suppose the opposite, then remove all characters of the string $s$ before the first occurrence of the string $t$ and insert them to the end. The number of occurrences clearly didn't decreased.

Obviously, we want to make the next occurrence of string $t$ in string $s$ as left as possible. If we decide to make it somewhere else, we can move out the extra characters and try to improve the answer. To achieve this, we need to find the largest suffix of the string $t$ that matches the prefix of string $t$ of the same length. It can be found by using the prefix function, z-function or hashes.

 
### [1137C - Museums Tour](../problems/C._Museums_Tour.md "Codeforces Round 545 (Div. 1)")

Let's build a graph where the vertices are ($u$, $t$) where u is the node for original graph and $t$ is a day modulo $d$ (days are indexed from $0$ to $d - 1$). 

Then connect ($u$, $t$) to ($v$, $(t + 1)\,mod\,d$) for all edges $(u, v)$ from original graph and find the strongly connected components of this graph. For each of the SCC compute the number of different opened museums in it. Then we just need to find a path with maximum cost that begins in SCC which contains ($1$, $0$). We can do it with a dynamic programming on the DAG.

The key fact is that if there is a path from ($u$, $j$) to ($u$, $j'$), then there is also a path from ($u$, $j'$) to ($u$, $j$) (simply go this path in original graph $d - 1$ times more), so we won't count some museum twice in the dynamic programming on this graph.

 
### [1137D - Cooperative Game](../problems/D._Cooperative_Game.md "Codeforces Round 545 (Div. 1)")

The count of friends you have in the problem was actually a misleading. Here is how to solve this problem with only three of them.

Let's name them $fast$, $slow$, $lazy$, and then consider the following process:

$fast$ and $slow$ moves forward, then $fast$ only, then $fast$ and $slow$ again and so on until at some moment they will appear in same vertex on cycle ($fast$ takes the lead, makes it to the cycle, circles there until $slow$ makes it to the cycle too, and then approaches him, reducing the distance between them by $1$ every $2$ moves).

Here you can notice, that $slow$ had no time to make even one full circle on cycle, because in that case $fast$ would managed to make at least two full circles and they would meet earlier. 

Let $r$ denote the distance from finish vertex to the one $fast$ and $slow$ met. Then $slow = t + x$ ($1$) and $fast = t + ?\cdot{}c + x$ ($2$). Also $fast = 2\cdot{}slow$ ($3$) as soon as $fast$ had a move at each step and $slow$ had only on the odd ones.

Substitute ($1$) and ($2$) into ($3$) and you would get $t + ?\cdot{}c + x = 2\cdot{}t + 2\cdot{}x$. Simplify it and take in modulo $c$ to get $-x \equiv t \pmod{c}$, i.e. if you would now apply $t$ moves to $fast$ and $slow$ they would end up in finish vertex, and if we instead somehow would manage to apply exactly $t$ moves to all friends, all of them would end up in the finish vertex. Here is the last bit of the solution: instead of trying to compute $t$ let's just move all friends until all of them would meet in one vertex — that vertex will be the finish one.

Described solution takes less than $2 \cdot (c + t)$ steps in the first stage and exactly $t$ steps in the second stage, so in total it would made less than $3 \cdot (c + t)$.

 
### [1137E - Train Car Selection](../problems/E._Train_Car_Selection.md "Codeforces Round 545 (Div. 1)")

There are many approaches to this problem, many of them having $\mathcal{O}(q \log q)$ time, but we will describe a purely linear solution.

First, notice that for every group of cars added together, we need only to care about the first car in this group — the remaining ones will never be the answer.

Second, notice that there are some cars appended to the head of the train, then all previous cars will never be answer again, so we can simply replace them with cars with $A_i = 0$.

So now we only need to care about operations of adding cars to the tail, and about adding the progression.

Suppose cars located at positions $x$ and have comfort $A_x$.

Then observe the lower-left convex hull of points $(x, A_x)$. One can see, that the points not lying on this hull will never be an answer.

Also note, that we can handle all progressions implicitly — suppose the progressions are described with $b_i$, $s_i$. Then let's simply store current sums of $b_i$ and $s_i$. Then the operation of adding progression can be done by simply adding to those sums, also we don't have to track the moment the cars are added, since we can simply subtract from $A_i$ based on sums at the moment of addition.

So when we add cars to the end we simply need to add point to the end and possibly drop some points from the end of the current convex hull. And when we add new progression, we may also need to drop some elements from the hull, but since it's the convex hull, the line coefficients between neighboring points are monotonous, so we need to drop only some points in the end of the hull.

 
### [1137F - Matches Are Not a Child's Play](../problems/F._Matches_Are_Not_a_Child's_Play_.md "Codeforces Round 545 (Div. 1)")

First, let's notice, that operation "compare" is redundant and can be implemented as two "when" operations (we didn't removed it from onsite olympiad's version as a possible hint).

Suppose we know the order of the burning vertices. How it will change after "up" operation? Actually, quite simply: let's notice, that the part from previous maximum to the new one will burn the last. Actually, everything except this path burns out in the same relative order as before, and then burns the path, in order from older maximum to the new one.

Let's say, that "up" paints it's path in the color i (and i++). Then to calculate when[v], let's first get the color of vertex v. And then when[v] equals to the number of vertices of smaller colors plus the number of vertices of the same color, but which will burn before this one. The latter is simply the number of vertices on the path from older maximum to the new one in the corresponding up query. 

To implement coloring on the path, we can use Heavy-Light-Decomposition. Inside every path of HLD let's store a set of segments of vertices of the same color. Then operation to color some path works in $O(\log^2 n)$, amortized. 

The number of vertices with smaller color can be calculated with a fenwick tree (which stores for color the number of such vertices).

There are also small technical details to handle: you need to account the original order of burning out, before all up's. But since each vertex changes it's color from zero to nonzero at most once, you can do it in O(number such vertices).

