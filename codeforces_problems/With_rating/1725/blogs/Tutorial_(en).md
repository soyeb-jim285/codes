# Tutorial_(en)

[1725A. Accumulation of Dominoes](../problems/A._Accumulation_of_Dominoes.md)
--------------------------------------------------------------------------------

Author: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")  
Developer: [nandonathaniel](https://codeforces.com/profile/nandonathaniel "Expert nandonathaniel")  
Editorialist: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")

 **Tutorial**
### [1725A - Accumulation of Dominoes](../problems/A._Accumulation_of_Dominoes.md "COMPFEST 14 - Preliminary Online Mirror (Unrated, ICPC Rules, Teams Preferred)")

We can divide the dominoes into two types: 

* Horizontal dominoes. A domino is horizontal if and only if it consists of tiles that are on the same row.
* Vertical dominoes. A domino is vertical if and only if it consists of tiles that are on the same column.

For an arbitrary tile in the grid that is not on the rightmost column, the integer in it is always exactly $1$ less than the integer in the tile that is directly to the right of it. So we can see that all possible horizontal dominoes are always tight. 

For an arbitrary tile in the grid that is not on the bottommost row, the integer in it is always exactly $M$ less than the integer in the tile that is directly to the bottom of it. So we can see that all possible vertical dominoes are tight if and only if $M=1$.

We can calculate that there are $N \times (M-1)$ horizontal dominoes and $(N-1) \times M$ vertical dominoes.

Therefore, we can get the following solution: 

* If $M > 1$, then there are $N \times (M-1)$ tight dominoes.
* If $M = 1$, then there are $N-1$ tight dominoes.

Time complexity: $O(1)$

[1725B. Basketball Together](../problems/B._Basketball_Together.md)
---------------------------------------------------------------------------

Author: [FerdiHS](https://codeforces.com/profile/FerdiHS "Expert FerdiHS")  
Developer: [muhammadhasan01](https://codeforces.com/profile/muhammadhasan01 "Master muhammadhasan01")  
Editorialist: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")

 **Tutorial**
### [1725B - Basketball Together](../problems/B._Basketball_Together.md "COMPFEST 14 - Preliminary Online Mirror (Unrated, ICPC Rules, Teams Preferred)")

For a team of $c$ players with a biggest power of $b$, the total power of the team is $b \times c$. So for a team with a biggest power of $b$ to win, it needs to have at least $\lceil \frac{D+1}{b} \rceil$ players.

For each player $i$, we can calculate a value $f(i)$ which means a team that has player $i$ as its biggest power needs to have at least $f(i)$ players to win. We can see that the bigger the value of $P_i$, the smaller the value of $f(i)$.

We can also see that if a formed team is said to have a fixed biggest power and a fixed number of players, the powers of the players that are less than the biggest power do not affect the total power of the team. So those players can be anyone.

Using the information above, we can form the teams using a greedy method. We iterate through each candidate player starting from the biggest $P_i$ and form new teams with each next biggest candidate player power as each team's biggest power. We do that while maintaining the total number of extra players required to make all formed teams win. We stop once the number of remaining players is not enough for the total number of extra players required.

Time complexity: $O(N \log N)$

[1725C. Circular Mirror](../problems/C._Circular_Mirror.md)
-----------------------------------------------------------------------

Author: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")  
Developer: [steven.novaryo](https://codeforces.com/profile/steven.novaryo "Candidate Master steven.novaryo")  
Editorialist: [steven.novaryo](https://codeforces.com/profile/steven.novaryo "Candidate Master steven.novaryo")

 **Tutorial**
### [1725C - Circular Mirror](../problems/C._Circular_Mirror.md "COMPFEST 14 - Preliminary Online Mirror (Unrated, ICPC Rules, Teams Preferred)")

Let's represent the mirror as a circle with $N$ points at the circumference. First, one should notice that a circumscribed triangle (triangle whose vertices lie on the circumference of a circle) is a right triangle if only if one side of the triangle is the diameter of the circle. That means, for a single colour, there exists a right triangle with this colour if and only if both of the following conditions are satisfied: 

* There exists two diametrically opposite points with this colour.
* This colour occurs in $3$ or more points.

Let's call a pair of diametrically opposite points as a diameter pair. From the information above, we can see that if we colour the points in a diameter pair with the same colour, all other points must not have that colour. If that condition is satisfied for all diameter pairs, there cannot be a right triangle with the same colour.

Let's find the number of diameter pairs in the circle and the number of points that do not belong to a diameter pair. Let the two values be $cntPair$ and $cntAlone$. One can find $cntPair$ and $cntAlone$ with two pointers or binary search using the prefix sum of the array $D$.

To find the number of colouring configurations, we can iterate $i$ from $0$ to $\min(cntPair, M)$. In each iteration, we calculate the number of configurations that have exactly $i$ diameter pairs with the same colour on both of their points. It is calculated as follows: 

* There are $\binom{cntPair}{i}$ ways to choose which diameter pairs have the same colour.
* Notice that each diameter pair with the same colour must have a different colour from each other. So there are $\binom{M}{i} \times i!$ ways to choose which colour is assigned to each diameter pair with the same colour.
* There are only $M-i$ available colours for colouring the remaining points. Each diameter pair with different colours can be coloured in $(M-i) \times (M-i-1)$ ways and each of the remaining points can be coloured in $M-i$ ways.
* So the total number of ways for a single value of $i$ is: $$\binom{cntPair}{i} \times \binom{M}{i} \times i! \times ((M-i) \times (M-i-1))^{cntPair-i} \times (M-i)^{cntAlone}$$

Time complexity: $O((N+M) \log N)$

[1725D. Deducing Sortability](../problems/D._Deducing_Sortability.md)
----------------------------------------------------------------------------

Author: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")  
Developer: [TakeMe](https://codeforces.com/profile/TakeMe "Expert TakeMe"), [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")  
Editorialist: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")

 **Tutorial**
### [1725D - Deducing Sortability](../problems/D._Deducing_Sortability.md "COMPFEST 14 - Preliminary Online Mirror (Unrated, ICPC Rules, Teams Preferred)")

Define an array as distinctable if and only if Pak Chanek can do zero or more operations to make the elements of the array different from each other. Finding a sortable array $A$ of size $N$ with the minimum possible sum of elements is the same as finding a distinctable array $A$ of size $N$ with the minimum possible sum and permuting its elements.

Define a value $k'$ as being reachable from a value $k$ if and only if we can do zero or more operations to the value $k$ to turn it into $k'$.

To construct a distinctable array of size $N$ with the minimum possible sum, we can do a greedy method. Initially, the array $A$ is empty. Then, do the following iteration multiple times sequentially for each value $k$ from $1$, $2$, $3$, and so on until $A$ has $N$ elements: 

1. Consider each value $k'$ that is reachable from $k$.
2. Let's say there are $w$ values $k'$ that has not been used as the final value for each of the previous elements of $A$.
3. Append $w$ new elements with value $k$ to $A$ and assign the final value for each of the new elements with each of the usable values of $k'$.
4. In the case where appending $w$ new elements makes the size of $A$ exceed $N$, we choose only some of the usable values of $k'$ to make the size of $A$ exactly $N$.

Notice that while choosing the final values for each value $k$, there is only one way to do it for each iteration except the last iteration. For the last iteration, it can be obtained that in order to get the lexicographically minimum array, we choose the usable final values that are the largest ones.

It can be obtained that each value that is reachable from $k$ is in the form of $x \times 2^y$ for some positive integer $x$ and some non-negative integer $y$ satisfying $x+y=k$.

For a pair $(x, y)$, if we choose an even integer for $x$, we can always find another pair $(x_2, y_2)$ such that $x_2 \times 2^{y_2} = x \times 2^y$ and $x_2+y_2 \leq x+y$. From the logic of the greedy method, we can see that choosing an even integer for $x$ is always not optimal.

For two distinct pairs $(x_1, y_1)$ and $(x_2, y_2)$, if both $x_1$ and $x_2$ are odd, then $x_1 \times 2^{y_1} \neq x_2 \times 2^{y_2}$ always holds.

Using the knowledge above, we can see that during the greedy method, the usable final values for a value $k$ are all the ones with odd values of $x$, which there are $\lceil \frac{k}{2} \rceil$ of them. From this, we can see that in our greedy method, we only do $O(\sqrt N)$ iterations. So, we can get the sum of elements in our constructed array $A$ in $O(\sqrt N)$.

To answer each query, we need to find the $P_i$-th smallest final value in the array and find which value produces it.

We can construct an array $F_0, F_1, F_2, \ldots$ of size $O(\sqrt N)$. This means for each $i$, there are $F_i$ values $x \times 2^y$ with $y=i$, namely the ones with the values of $x$ being the $F_i$ smallest positive odd integers.

We can convert each value $x \times 2^y$ into $x' \times 2^{y'}$ such that all values of $x'$ have the same MSB (Most Significant Bit). After converting, sorting the values $x' \times 2^{y'}$ is the same as sorting the pairs $(y', x')$.

We can construct a two-dimensional array $G$ of size $O(\sqrt N) \times O(\log N)$ with $G_{i,j}$ representing the number of final values with $y' = i$ and $y = i-j$.

To find the $P_i$-th smallest final value, firstly we find its value of $y'$ with binary search using array $G$.

Now, for some integer $d$, we need to find the $d$-th smallest value of $x'$ for all final values with a certain value of $y'$. To find it, we do a binary search on a value $m$ with each iteration checking whether there are at least $d$ values of $x'$ that are less than or equal to $m$. Each iteration of the binary search can be computed by iterating $O(\log N)$ values in $G$ and using simple math.

To find which value produces a certain final value, we just convert it back into $x \times 2^y$ and find the value of $x+y$.

Time complexity: $O(\sqrt N \log N + Q \log^2N)$

Challenge: find the solution for $N \leq 10^{18}$.

[1725E. Electrical Efficiency](../problems/E._Electrical_Efficiency.md)
-----------------------------------------------------------------------------

Author: [steven.novaryo](https://codeforces.com/profile/steven.novaryo "Candidate Master steven.novaryo")  
Developer: [steven.novaryo](https://codeforces.com/profile/steven.novaryo "Candidate Master steven.novaryo")  
Editorialist: [rama_pang](https://codeforces.com/profile/rama_pang "International Grandmaster rama_pang")

 **Tutorial**Tutorial is loading...[1725F. Field Photography](../problems/F._Field_Photography.md)
-------------------------------------------------------------------------

Author: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")  
Developer: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")  
Editorialist: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")

 **Tutorial**
### [1725F - Field Photography](../problems/F._Field_Photography.md "COMPFEST 14 - Preliminary Online Mirror (Unrated, ICPC Rules, Teams Preferred)")

Let's consider some value of $W_j$. Let $b$ be the LSB (Least Significant Bit) of $W_j$. Which means $b$ is the minimum number such that the bit in index $b$ in the binary representation of $W_j$ is active. Note: the bits are indexed from $0$ from the right.

For a sequence of operations, define $\text{dis}(i)$ as how many tiles to the east the final positions of the contestants in row $i$ compared to their initial position. Specifically, if their final positions are more to the west, then $\text{dis}(i)$ is negative.

Notice that each move we make must be a distance that is a multiple of $2^b$. Because if we move a distance that is not a multiple of $2^b$, at least one of the bits with indices smaller than $b$ will be activated, which we do not want. This means $\text{dis}(i)$ must be a multiple of $2^b$.

However, we can make each $\text{dis}(i)$ to be any integer that is a multiple of $2^b$ while making $Z = W_j$ by doing the following strategy: 

1. Only do moves with distances of exactly $2^b$ to move the contestants in each row to their final positions.
2. Move one row with a distance of $W_j$ to the east, then to the west.

Using the knowledge above, we can see that for each row $i$, there are three cases: 

* If $R_i-L_i+1 \geq 2^b$, then each column can be occupied.
* Else, if $(L_i \mod 2^b) \leq (R_i \mod 2^b)$, then only each column $c$ such that $(L_i \mod 2^b) \leq (c \mod 2^b) \leq (R_i \mod 2^b)$ can be occupied.
* Else, then only each column $c$ such that $(L_i \mod 2^b) \leq (c \mod 2^b)$ or $(c \mod 2^b) \leq (R_i \mod 2^b)$ can be occupied.

We can see that each row has at most two subsegments of the segment $[0, 2^b-1]$ denoting the occupiable columns modulo $2^b$. Now we just need to find the position that intersects the most subsegments. To solve this, we can use line sweep.

To handle the $Q$ queries, notice that the number of possible distinct values for the LSB of $W_j$ are only $\lfloor \log_2 10^9 \rfloor + 1 = 30$. So we can precompute the answer for each of the $30$ possible LSB, then answer the queries using the precomputed answers.

Time complexity: $O(N\log N \log \max(W) + Q \log \max(W))$

[1725G. Garage](../problems/G._Garage.md)
--------------------------------------------------------------

Author: [Nyse](https://codeforces.com/profile/Nyse "Expert Nyse")  
Developer: [Nyse](https://codeforces.com/profile/Nyse "Expert Nyse")  
Editorialist: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")

 **Tutorial**Tutorial is loading...[1725H. Hot Black Hot White](../problems/H._Hot_Black_Hot_White.md)
---------------------------------------------------------------------------

Author: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")  
Developer: [steven.novaryo](https://codeforces.com/profile/steven.novaryo "Candidate Master steven.novaryo")  
Editorialist: [steven.novaryo](https://codeforces.com/profile/steven.novaryo "Candidate Master steven.novaryo")

 **Tutorial**
### [1725H - Hot Black Hot White](../problems/H._Hot_Black_Hot_White.md "COMPFEST 14 - Preliminary Online Mirror (Unrated, ICPC Rules, Teams Preferred)")

Notice that $10 \equiv 1 \mod 3$. Hence, if $k$ denotes the number of digits in $A_j$, $\text{concat}(A_i, A_j) \mod 3= (A_i \times 10^k + A_j) \mod 3 = (A_i \times 1^k + A_j) \mod 3 = (A_i + A_j) \mod 3$.

Then one can simplify the equation that determines the reaction of stone $i$ and stone $j$ as follows. $$ \begin{align} \text{concat}(A_i, A_j) \times \text{concat}(A_j, A_i) + A_i A_j & \equiv Z \mod 3 \\\ (A_i + A_j) (A_i + A_j) + A_i A_j & \equiv Z \mod 3 \\\ A_i^2 + 2 A_i A_j + A_j^2 + A_i A_j & \equiv Z \mod 3 \\\ A_i^2 + A_j^2 + 3 A_i A_j & \equiv Z \mod 3 \\\ A_i^2 + A_j^2 & \equiv Z \mod 3 \\\ \end{align} $$ One can see that:

* $0^2 = 0 \equiv 0 \mod 3$.
* $1^2 = 1 \equiv 1 \mod 3$.
* $2^2 = 4 \equiv 1 \mod 3$.

So the value of $A_i^2 \mod 3$ is either $0$ or $1$.

We can get a construction that consists of the two following cases:

* If there are at least $\frac{N}{2}$ stones having $A_i^2 \equiv 0 \mod 3$, then we can colour the stones such that one of the colours only occurs in all stones with $A_i^2 \equiv 0 \mod 3$. In this construction, there is no pair of stones with different colours that both have $A_i^2 \equiv 1 \mod 3$. So we can assign $Z=2$.
* If there are less than $\frac{N}{2}$ stones having $A_i^2 \equiv 0 \mod 3$, then there are at least $\frac{N}{2}$ stones having $A_i^2 \equiv 1 \mod 3$, so we can colour the stones such that one of the colours only occurs in all stones with $A_i^2 \equiv 1 \mod 3$. In this construction, there is no pair of stones with different colours that both have $A_i^2 \equiv 0 \mod 3$. So we can assign $Z=0$.

Time complexity: $O(N)$

[1725I. Imitating the Key Tree](../problems/I._Imitating_the_Key_Tree.md)
------------------------------------------------------------------------------

Author: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")  
Developer: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")  
Editorialist: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")

 **Tutorial**
### [1725I - Imitating the Key Tree](../problems/I._Imitating_the_Key_Tree.md "COMPFEST 14 - Preliminary Online Mirror (Unrated, ICPC Rules, Teams Preferred)")

Let's say we have two graphs, each having $N$ vertices. Initially, there are no edges. We want to make the first graph into a graph that satisfies the condition of the problem and make the second graph into the key tree with a weight assignment that corresponds to the first graph.

Sequentially for each $k$ from $1$ to $2N-2$, do all of the following:

* Add an edge with weight $k$ to the first graph.
* Choose one of the following:
	+ Add an edge with weight $k$ to the second graph.
	+ Do nothing.

In order to make the second graph into the key tree, we must add exactly $N-1$ edges to it throughout the process and the $i$-th edge added is edge $i$ of the key tree.

In an iteration, if we choose to not add an edge to the second graph, it can be obtained that the edge added to the first graph must not merge any biconnected components. Let's call this type of edge in the first graph an idle edge.

Otherwise, if we choose to add an edge to the second graph, it can be obtained that the following must be satisfied:

* Let $c_1$ and $c_2$ be the connected components of the second graph that are merged by adding the new edge.
* The edge added to the first graph must merge exactly two biconnected components, each of them containing vertices with the same indices as the ones in each of $c_1$ and $c_2$.
* Let's call this type of edge in the first graph a connector edge. We can see that there must be exactly $N-1$ connector edges in the first graph.

The only way to make it such that adding an edge connects exactly two biconnected components is to already have exactly one existing edge connecting the two biconnected components. Let's call this type of existing edge a helper edge.

It can be obtained that an edge cannot be a helper edge of more than one connector edge. Because we only have $2N-2$ edges for the first graph, those edges must only consist of $N-1$ connector edges and $N-1$ helper edges. This means all helper edges must be idle edges. But it can be obtained that each helper edge in our construction is always an idle edge.

The $i$-th connector edge and its corresponding helper edge must connect the two biconnected components that correspond to the two connected components merged using edge $i$ of the key tree. If the sizes of the connected components are $s_1$ and $s_2$, then there are $(s_1 \times s_2)^2$ possible pairs of connector and helper edges.

The number of ways to choose which edge to add in each iteration is the same as the number of ways to colour a sequence of $2N-2$ elements with $N-1$ colours (numbered from $1$ to $N-1$) such that:

* Each colour occurs in exactly $2$ elements.
* For each pair of colours $(i, j)$, if $i<j$, then the latest element with colour $i$ must occur earlier than the latest element with colour $j$.

We can see that the number of ways is $\frac{(2N-2)!}{(2!)^{N-1}\times (N-1)!}$. To get the answer to the problem, we just multiply this value by each of the $(s_1 \times s_2)^2$ for each merged pair of connected components in the key tree.

Time complexity: $O(N)$

[1725J. Journey](../problems/J._Journey.md)
---------------------------------------------------------------

Author: [gansixeneh](https://codeforces.com/profile/gansixeneh "Candidate Master gansixeneh")  
Developer: [gansixeneh](https://codeforces.com/profile/gansixeneh "Candidate Master gansixeneh"), [steven.novaryo](https://codeforces.com/profile/steven.novaryo "Candidate Master steven.novaryo")  
Editorialist: [rama_pang](https://codeforces.com/profile/rama_pang "International Grandmaster rama_pang")

 **Tutorial**
### [1725J - Journey](../problems/J._Journey.md "COMPFEST 14 - Preliminary Online Mirror (Unrated, ICPC Rules, Teams Preferred)")

For a journey, define $\text{cnt}(i)$ as a non-negative integer representing the number of times Pak Chanek traverses road $i$ throughout the journey.

First, let's solve the simpler problem where we cannot teleport. It can be obtained that the configuration of $\text{cnt}(i)$ for an optimal journey in this version of the problem is as follows:

* The roads with $\text{cnt}(i)=1$ form a simple path.
* Every other road outside of the path has $\text{cnt}(i)=2$.

If we add the ability to teleport at most once, the configuration of $\text{cnt}(i)$ is similar, but the roads with $\text{cnt}(i)=1$ form two distinct simple paths, with both paths not containing any common roads. Let's denote these two paths as $P_1$ and $P_2$.

Notice that $P_1$ and $P_2$ can only have either one common city or no common cities at all. It can be obtained that the optimal configuration for each case is as follows:

* If $P_1$ and $P_2$ have one common city, every other road outside of $P_1$ and $P_2$ must have $\text{cnt}(i)=2$.
* If $P_1$ and $P_2$ have no common cities, we have the opportunity to pick one road in the path between $P_1$ and $P_2$ and assign $\text{cnt}(i)=0$. Then, every other road must have $\text{cnt}(i)=2$.

It can be shown that for any configuration of $\text{cnt}(i)$ satisfying the constraints above, there always exists a valid journey that corresponds to that configuration. So we must find the configuration that results in the minimum time for each case.

For the first case, we can precompute a tree DP with rerooting and try each possible common city to get the optimal answer. For the second case, we can also precompute a tree DP with rerooting and try each possible road with $\text{cnt}(i)=0$ to get the optimal answer.

[1725K. Kingdom of Criticism](../problems/K._Kingdom_of_Criticism.md)
----------------------------------------------------------------------------

Author: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")  
Developer: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")  
Editorialist: [rama_pang](https://codeforces.com/profile/rama_pang "International Grandmaster rama_pang")

 **Tutorial**
### [1725K - Kingdom of Criticism](../problems/K._Kingdom_of_Criticism.md "COMPFEST 14 - Preliminary Online Mirror (Unrated, ICPC Rules, Teams Preferred)")

We can see that the changes in height for a single query of type $3$ are as follows:

* Each building with height $x$ such that $l \leq x \leq \frac{l+r}{2}$ is changed to have a height of $l-1$.
* Each building with height $x$ such that $\frac{l+r}{2} \leq x \leq r$ is changed to have a height of $r+1$.
* Note: since $r-l$ is odd, $\frac{l+r}{2}$ is not an integer. So there is no uncertainty here.

We can group the buildings into their heights, so buildings with the same height belong in the same group. We can maintain all the different groups in a set such that the groups are sorted by their heights. We can see that using this set, we can perform a type $3$ query by merging several groups into a single group with a certain height. Note that each time we merge $k$ groups, the number of groups decreases by $k-1$.

For each building, to maintain its height while doing all the merging of several groups and the changing of height of an entire group, we can use a simple disjoint-set data structure to make it such that we can request the height of any building quickly.

More specifically, each group is represented as a single connected component. The merging of several groups is equivalent to the merging of several connected components. The changing of height of an entire group can be done by changing the height of the representative building in a connected component.

However, a query of type $1$ can break our structure. Changing the height of a single building can make it leave its current group and join another group or make a new group. In order to not break our disjoint-set data structure, each time there is a type $1$ query, we can just leave the old building with the old height alone and make a new building with the new height. After this, each request for this building's height is referred to the new representation we just created. Each query of type $1$ creates one new building representation and can create at most one new group.

Using this solution, we can see that:

* A type $1$ query is done in $O(\log(N+Q))$ time because we have to make changes to the set. This query creates one new building representation and can create at most one new group.
* A type $2$ query is done in $O(1)$ time.
* A type $3$ query is done in $O(k\log(N+Q))$ time with $k$ being the number of groups we merge. This query decreases the number of groups by $k-1$.

Time complexity: $O((N+Q)\log(N+Q))$

Note: there is also an unintended solution using small-to-large with time complexity of $O((N+Q)\log^2(N+Q))$, but it needs optimisations in order to pass the time limit.

[1725L. Lemper Cooking Competition](../problems/L._Lemper_Cooking_Competition.md)
----------------------------------------------------------------------------------

Author: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")  
Developer: [steven.novaryo](https://codeforces.com/profile/steven.novaryo "Candidate Master steven.novaryo")  
Editorialist: [rama_pang](https://codeforces.com/profile/rama_pang "International Grandmaster rama_pang")

 **Tutorial**Tutorial is loading...[1725M. Moving Both Hands](../problems/M._Moving_Both_Hands.md)
-------------------------------------------------------------------------

Author: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")  
Developer: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")  
Editorialist: [rama_pang](https://codeforces.com/profile/rama_pang "International Grandmaster rama_pang")

 **Tutorial**Tutorial is loading...