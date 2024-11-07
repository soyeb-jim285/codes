# Tutorial_(en)

[1740A. Factorise N+M](../problems/A._Factorise_N+M.md)
----------------------------------------------------------------------

Author: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")  
Developer: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe") 

 **Tutorial**
### [1740A - Factorise N+M](../problems/A._Factorise_N+M.md "Codeforces Round 831 (Div. 1 + Div. 2)")

There are multiple solutions for this problem. We will discuss two of them.

One solution is to choose $m = n$. This always guarantees that $m$ is prime, because $n$ is always prime. And we can see that $n + m = n + n = 2n$, which is always not prime, because $n > 1$ always holds.

Another solution is to choose $m=7$. If $n$ is odd, then $n+m$ will be an even number greater than $2$ and therefore not prime. Otherwise $n$ is even. The only even number prime number is $2$ and it can be verified that $2+7=9$ is not a prime number.

Time complexity for each test case: $O(1)$

[1740B. Jumbo Extra Cheese 2](../problems/B._Jumbo_Extra_Cheese_2.md)
----------------------------------------------------------------------------

Author: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")  
Developer: [errorgorn](https://codeforces.com/profile/errorgorn "International Grandmaster errorgorn"), [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")

 **Tutorial**Tutorial is loading...[1740C. Bricks and Bags](../problems/C._Bricks_and_Bags.md)
-----------------------------------------------------------------------

Author: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")  
Developer: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe") 

 **Tutorial**
### [1740C - Bricks and Bags](../problems/C._Bricks_and_Bags.md "Codeforces Round 831 (Div. 1 + Div. 2)")

Firstly, sort $a$. From now on, we will always refer to the sorted array $a$.

Let $p_j$ be the index of the brick taken by Bu Dengklek from bag $j$. The configuration of $p_1,p_2,p_3$ must be in the form of one of the following: 

1. $p_1 < p_2 < p_3$
2. $p_1 > p_2 > p_3$
3. $p_2 < \min(p_1, p_3)$
4. $p_2 > \max(p_1, p_3)$

Let's look at the third case. Let's consider the case where $\min(p_1, p_3) > p_2+1$. If this is the case, let's look at all possible cases for the brick at index $p_2+1$. 

* If Pak Chanek puts brick $p_2+1$ into bag $1$, it is more optimal for Bu Dengklek to take that brick from bag $1$ instead of $p_1$ because $a_{p_2+1}-a_{p_2} \leq a_{p_1}-a_{p_2}$.
* If Pak Chanek puts brick $p_2+1$ into bag $2$, it is more optimal for Bu Dengklek to take that brick from bag $2$ instead of $p_2$ because $(a_{p_1}-a_{p_2+1})+(a_{p_3}-a_{p_2+1}) \leq (a_{p_1}-a_{p_2})+(a_{p_3}-a_{p_2})$.
* If Pak Chanek puts brick $p_2+1$ into bag $3$, it is more optimal for Bu Dengklek to take that brick from bag $3$ instead of $p_3$ because $a_{p_2+1}-a_{p_2} \leq a_{p_3}-a_{p_2}$.

This means, choosing $p_1,p_2,p_3$ such that $\min(p_1, p_3) > p_2+1$ is always less optimal for Bu Dengklek. Therefore, Bu Dengklek will take the bricks such that if $p_2 < \min(p_1, p_3)$, then $\min(p_1, p_3) = p_2 + 1$ also holds.

A similar logic can be used for the fourth case. So, we can obtain that Bu Dengklek will always take the bricks such that the configuration of $p_1,p_2,p_3$ is in the form of one of the following: 

1. $p_1 < p_2 < p_3$
2. $p_1 > p_2 > p_3$
3. $p_2 < \min(p_1, p_3)$ and $\min(p_1, p_3) = p_2 + 1$
4. $p_2 > \max(p_1, p_3)$ and $\max(p_1, p_3) = p_2 - 1$

In fact, Pak Chanek is always able to force it such that the bricks taken by Bu Dengklek form any configuration of $p_1,p_2,p_3$ that follows one of the constraints above. Let's look at one possible construction. For a configuration of $p_1,p_2,p_3$ construct an order of the bags $j_1,j_2,j_3$ such that $p_{j_1}<p_{j_2}<p_{j_3}$. Then, Pak Chanek can force Bu Dengklek to choose that configuration by doing the following: 

* Put the bricks at indices from $1$ to $p_{j_1}$ into bag $j_1$.
* Put the bricks at indices from $p_{j_1}+1$ to $p_{j_3}-1$ into bag $j_2$.
* Put the bricks at indices from $p_{j_3}$ to $n$ into bag $j_3$.

Therefore, we just need to find the values of $p_1,p_2,p_3$ satisfying the constraints above such that $|a_{p_1}-a_{p_2}|+|a_{p_2}-a_{p_3}|$ is maximised.

To maximise the final score, we can see that it is always more optimal to either use the third or the fourth case for $p_1,p_2,p_3$. For the third case, it is always more optimal to maximise $\max(p_1, p_3)$, so we should set $\max(p_1, p_3) = n$. A similar logic can be used for the fourth case to see that we should set $\min(p_1, p_3) = 1$.

Therefore, the maximum final score is the maximum of these two cases: 

* $(a_i-a_{i-1})+(a_i-a_1)$ with $3 \leq i \leq n$.
* $(a_{i+1}-a_i)+(a_n-a_i)$ with $1 \leq i \leq n-2$.

Time complexity for each test case: $O(n \log n)$

[1740D. Knowledge Cards](../problems/D._Knowledge_Cards.md)
-----------------------------------------------------------------------

Author: [Nyse](https://codeforces.com/profile/Nyse "Expert Nyse")  
Developer: [steven.novaryo](https://codeforces.com/profile/steven.novaryo "Master steven.novaryo")

 **Tutorial**
### [1740D - Knowledge Cards](../problems/D._Knowledge_Cards.md "Codeforces Round 831 (Div. 1 + Div. 2)")

Let card $c$ be the card with number $c$ written on it. Notice that we must put the cards into the stack in $(n,m)$ in order from card $k$, card $k-1$, card $k-2$, and so on until card $1$.

The key observation for this problem is that, under given constraints, if we ignore cells $(1,1)$ and $(n,m)$ we can always move any card to either $(n-1,m)$ or $(n,m-1)$ if and only if there is at least one empty cell. We can obtain this by considering the fact that an empty cell can "move" to any cell and can be used to rotate any $2 \times 2$ square of cells. Because $3 \leq n, m$, if we ignore cells $(1,1)$ and $(n,m)$, each cell is a part of a $2 \times 2$ square. Moving a desired card to a one of $(n-1,m)$ or $(n,m-1)$ can be done by firstly moving the empty cell to be adjacent to the desired card, and then only doing $2 \times 2$ rotations that simultaneously move the empty cell and the desired card.

Therefore, we can iterate the card in the stack $(1, 1)$ from top to bottom. While iterating, one should maintain all of the cards in the board that are not in cell $(1, 1)$ or $(n, m)$. We define those group of cards as active cards. Each time we put a move a card out of $(1, 1)$, we add the card to the active cards. Before finishing the iteration we will try to move one or more cards from the active cards to $(n, m)$ as long as there is a card we can move. We can maintain the active cards with a priority queue or a set.

The active cards can be moved around freely if and only if there is at least one empty cell in the grid if we ignore $(1,1)$ and $(n,m)$. Therefore, to check whether or not we can solve the puzzle, we just need to check whether or not there exists a moment where the number of active cards exceed $nm-3$.

There also exists a solution with a time complexity of $O(k)$ just by iterating the positions of each card number, but it will not be explained here.

Time complexity for each test case: $O(k\log k)$ or $O(k)$

[1740E. Hanging Hearts](../problems/E._Hanging_Hearts.md)
----------------------------------------------------------------------

Author: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")  
Developer: [yz_](https://codeforces.com/profile/yz_ "Master yz_") 

 **Tutorial**
### [1740E - Hanging Hearts](../problems/E._Hanging_Hearts.md "Codeforces Round 831 (Div. 1 + Div. 2)")

The cards form a rooted tree with card $i$ being the root, where for each $i$ ($i>1$), the parent of card $i$ is $p_i$.

Let $w_i$ be the number on card $i$ when it is about to get removed. To remove card $i$, we must previously remove all cards in the subtree of $i$ other than $i$ itself. Thus, we can see that $w_i$ is the minimum value of $a$ out of all cards in the subtree of $i$.

Let the sequence $[v_1,v_2,v_3,\ldots]$ mean that the $i$-th element of the longest non-decreasing subsequence comes from card $v_i$. Then, we can get the following observations: 

* We can only remove card $i$ if all other cards in the subtree of $i$ have been removed. Hence, for each $v_i$, every $v_j$ with $j>i$ must not be in the subtree of $v_i$.
* We can make $v_{i+1}$ to be the ancestor of $v_i$ by making $w_{v_{i+1}}=w_{v_i}$. This can be done by making it such that the minimum value of $a$ in the subtree of $v_i$ is simultaneously the minimum value of $a$ in the subtree of $v_{i+1}$.
* If $v_{i+1}$ is not the ancestor of $v_i$, then $w_{v_{i+1}} \neq w_{v_i}$ must hold. Because $v$ forms a non-decreasing sequence, then $w_{v_{i+1}} > w_{v_i}$ must hold. That means, $w_{v_{i+1}}$ is guaranteed to be larger than the values of $w$ for all ancestors of $v_i$. This means, after $v_{i+1}$, $v$ cannot continue with any ancestors of $v_i$.

From the information above, it means that when constructing $v$, we do one the following operation several times: 

* Append an ancestor of the last card.
* Append a card that is not an ancestor of the last card and not a descendant of any of the previous cards. After this, we cannot choose any ancestor of the card before this new card.

In the optimal configuration, the sequence $v$ resembles the following:

* It consists of several paths of cards where each path is from a card to one of its ancestors.
* For any pair of cards from two different paths, one must not be an ancestor of the other.

We will use dynamic programming on tree. Let $dp[i]$ denote the length of the longest non-decreasing subsequence created from only doing operations to the subtree of $i$. Then, we have two cases: 

* If card $i$ is used in the longest non-decreasing subsequence, then the maximum answer is the maximum number of cards in a path from card $i$ to one of the cards in the subtree of $i$.
* If card $i$ is not used in the longest non-decreasing subsequence, then the maximum answer is the sum of $dp$ values of the children of card $i$.

Time complexity: $O(n)$

[1740F. Conditional Mix](../problems/F._Conditional_Mix.md)
-----------------------------------------------------------------------

Author: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")  
Developer: [errorgorn](https://codeforces.com/profile/errorgorn "International Grandmaster errorgorn") 

 **Tutorial**
### [1740F - Conditional Mix](../problems/F._Conditional_Mix.md "Codeforces Round 831 (Div. 1 + Div. 2)")

Let $cnt_i$ denote the number of occurrences of element $i$ in array $a$.

Claim: A multiset $M$ of size $n$, $M_1,M_2,\ldots,M_n$ where $M_1 \geq M_2 \geq \ldots \geq M_n \geq 0$ is good if and only if $\sum_{i=1}^{n} M_i=n$ and $\sum_{i=1}^k M_i \leq \sum_{i=1}^n \min(k,cnt_i)$ for every $1 \leq k \leq n$.

The proof of that claim has been discussed in the comment section [here](Tutorial_(en).md?#comment-968701).

We proceed with formulating a dynamic programming solution. Let $dp[pos][sum][last]$ denote that we have picked a prefix $P_1,P_2,\ldots,P_{pos}$ such that $\sum_{i=1}^{pos} P_i = sum$ and $P_{pos}=last$. Our transition is going from $dp[pos][sum][last]$ to $dp[pos+1][sum+x][x]$ for all $x \leq last$, this can be easily handled using prefix sums. However, we still have $O(n^3)$ states.

We can cut down the number of states by noting that $n \geq \sum_{i=1}^{pos} P_i \geq last \cdot pos$. That is, for each value of $pos$, there are only $\frac{n}{pos}$ values of $last$. Since $\frac{n}{1}+\frac{n}{2}+\frac{n}{3}+\ldots+\frac{n}{n} \approx n\log n$, the number of states is bounded by $O(n^2 \log n)$.

Time complexity: $O(n^2 \log n)$

[1740G. Dangerous Laser Power](../problems/G._Dangerous_Laser_Power.md)
-----------------------------------------------------------------------------

Author: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")  
Developer: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe") 

 **Tutorial**
### [1740G - Dangerous Laser Power](../problems/G._Dangerous_Laser_Power.md "Codeforces Round 831 (Div. 1 + Div. 2)")

Claim: There is a construction where all portals are good.

We will proceed with the construction.

The key observation of the problem is that for a portal $(i,j)$ to consume energy, the laser must not enter a portal with a strength greater than or equal to $s_{i,j}$ before going through portal $(i,j)$.

Let's say we already have the type settings of all lasers. Consider all possible lasers that at some point enters a certain face of portal $(i,j)$. We can find the paths of those lasers before entering portal $(i,j)$ by backtracking in that direction from portal $(i,j)$.

Consider the first portal in that backtracking path that has a strength greater than or equal to $s_{i,j}$. Notice that all lasers that starts from portals that are located after that portal in the backtracking path must go through that portal before entering portal $(i,j)$. Therefore, those lasers cannot make portal $(i,j)$ use energy, which means they can be ignored.

Using the observation above, we can see that we must only backtrack until we find a portal with a strength greater than or equal to $s_{i,j}$. Observe that to get the path up to that point, the type settings we should know are only the type settings of portals with strengths smaller than $s_{i,j}$.

Therefore, the construction can be generated by calculating the type settings of the portals from the smallest to the largest strengths. In each iteration, we use the type settings of the previous portals to find the backtracking paths of the current portal. If we already know the $4$ backtracking paths for each of the $4$ directions of that portal, we can find the total energy that portal will consume in the end, which means we can find the type setting for that portal that makes it a good portal.

The naive implementation of this has a time complexity of $O(n^2m^2)$. Notice that each backtracking path of the portals are just the merging of smaller paths. We can maintain a disjoint set data structure to handle this while maintaining the essential values needed in the calculation of the total energy consumed for each path.

Time complexity: $O(nm)$

[1740H. MEX Tree Manipulation](../problems/H._MEX_Tree_Manipulation.md)
-----------------------------------------------------------------------------

Author: [steven.novaryo](https://codeforces.com/profile/steven.novaryo "Master steven.novaryo")  
Developer: [steven.novaryo](https://codeforces.com/profile/steven.novaryo "Master steven.novaryo"), [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")

 **Tutorial**
### [1740H - MEX Tree Manipulation](../problems/H._MEX_Tree_Manipulation.md "Codeforces Round 831 (Div. 1 + Div. 2)")

Define $\text{MEX}_i(A)$ of a certain array $A$ as the $i$-th smallest non-negative integer that does not belong to the array.

Let's solve a simpler problem. Imagine that you are given an array $A$, you are asked to append a new element $x$ to the array, and you need to calculate the MEX of the array after the operation. It is easy to see that the new value of MEX is either $\text{MEX}_1(A)$ if $x \neq \text{MEX}_1(A)$ or $\text{MEX}_2(A)$ if $x = \text{MEX}_1(A)$ where $A$ is the array before the operation.

Let $(x, y, z)$ define a relationship between input and output which means: 

* If the input is not $x$, then the output is $y$.
* If the input is $x$, then the output is $z$.

This means the relationship between the new element to be appended to $A$ and the new value of MEX can be expressed as $(\text{MEX}_1(A), \text{MEX}_1(A), \text{MEX}_2(A))$. Define that triple as $\text{MEXtuple}(A)$.

Define the heavy child of vertex $u$ as the child with the largest subtree size. If there are children with the same subtree size, choose one of them. Let's call each child other than the heavy child as a light child. In particular, the edge that connects a vertex to its heavy child is called a heavy edge.

Let $C_u$ be the array that contains the values of the light children of vertex $u$. We can see that if we maintain $\text{MEXtuple}(C_u)$ we can get the relationship between the value of the heavy child and the value of vertex $u$.

Let's consider a path in the tree that traverses through parents while only using heavy edges. Consider the relationship between the value of the vertex at the beginning of the path and the end of the path. Let's calculate the $\text{MEXtuple}$ for each vertex in the path other than the first one. We can see that we can get the relationship between the vertex in the beginning of the path and the end of the path using those $\text{MEXtuple}$ values. In fact, that relationship can also be expressed as a triple $(x, y, z)$ defined above.

Let's decompose the tree into chains of heavy edges. For each chain, construct a segment tree with each node in the segment tree calculating the relationship triple $(x, y, z)$ for a segment of the chain.

Suppose we want to add a new vertex. The vertices that have their values changed are the ones that lie on the path from the new vertex to the root. Observe that that path only traverses through at most $O(\log Q)$ different heavy edge chains. For each chain, we can get the value of the vertex at the end of the chain by doing a point update on the chain's segment tree. When we move between two different chains, we update the $C_u$ for a vertex and recalculate it's $\text{MEXtuple}$ in $O(\log Q)$ time complexity using a set or another segment tree. We repeat this process until we reach the root. We can calculate that the total complexity of a single query is $O(\log^2 Q)$.

To get the sum of the values of the entire tree after an operation, we can store two new variables in each node of the segment tree of each chain that represents the sum of the chain segment for the two possible cases of the input.

Time complexity: $O(Q \log^2 Q)$

[1740I. Arranging Crystal Balls](../problems/I._Arranging_Crystal_Balls.md)
-------------------------------------------------------------------------------

Author: [NeoZap](https://codeforces.com/profile/NeoZap "Expert NeoZap")  
Developer: [errorgorn](https://codeforces.com/profile/errorgorn "International Grandmaster errorgorn"), [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")

 **Tutorial**
### [1740I - Arranging Crystal Balls](../problems/I._Arranging_Crystal_Balls.md "Codeforces Round 831 (Div. 1 + Div. 2)")

Let's simplify the problem such that the only possible operation for each $k$ chosen statues is $a_i := (a_i - 1) \bmod m$.

To solve this, we first define $c_i$ as the number of times we do that operation for the statues $i, (i-1) \bmod n, (i-2) \bmod n, (i-3) \bmod n, \ldots, (i-k+1) \bmod n$. We can see that in the optimal configuration, $0 \leq c_i \leq m-1$ must hold. For it to make each element of $a$ to be $0$, $(c_i+c_{(i+1)\bmod n}+c_{(i+2)\bmod n}+\ldots+c_{(i+k-1)\bmod n})\bmod m=a_i$ must hold. The number of operations is equal to $c_0+c_1+c_2+\ldots+c_{n-1}$.

In order to extend to the original problem, we can see that for a given array $c$, the number of operations that can be made to be equal to $\sum_{i=0}^{n-1}\min(c_i,m-c_i)$. So we need to find an array $c$ satisfying the conditions above such that $\sum_{i=0}^{n-1}\min(c_i,m-c_i)$ is as small as possible.

We can see that $a_{(i+1)\bmod n} - a_i = c_{(i+k) \bmod n} - c_i$. That means, if we have determined the value of $c_i$, the value of $c_{(i+k) \bmod n}$ is forced. If we form an edge for each pair of indices $(i, (i+k) \bmod n)$, we will get $\text{GCD}(n,k)$ connected components. This means if we have determined the value of one vertex for each connected component, the values of the entire array $c$ are forced. However, we must also consider possibility that at least one connected component cannot have assigned values that satisfy all of its edges. In that case, it is impossible to finish the objective of the problem.

Define $d=\text{GCD}(n,k)$. For each $c_i$, we can find the difference relationship between it and $c_{i \bmod d}$. Therefore, to answer the problem, we must find the values of $c_0, c_1, c_2, \ldots, c_{d-1}$ such that $c_0+c_1+c_2+\ldots+c_{k-1}=a_0$ and if all the other values of $c$ are calculated, $\sum_{i=0}^{n-1}\min(c_i,m-c_i)$ is as small as possible.

For the $c_0+c_1+c_2+\ldots+c_{k-1}=a_0$ condition, using simple modular algebra, we can calculate one or more values $b_1,b_2,b_3,\ldots$ such that $c_0+c_1+c_2+\ldots+c_{k-1}=a_0$ if and only if $c_0+c_1+c_2+\ldots+c_{d-1}$ is equal to one of the values of $b$.

Let's consider the connected component $c_i, c_{i+d}, c_{i+2d}, \ldots$. It must have $\frac{n}{d}$ elements. Define $f_i(x)$ as the sum of $\min(c_j,m-c_j)$ for all elements of $c_j$ in that connected component if $c_i=x$. We can easily calculate all values of $f_i(x)$ for all connected components in $O(nm)$.

After this, we must the minimum value of $f_0(c_0)+f_1(c_1)+f_2(c_2)+\ldots+f_{d-1}(c_{d-1})$ such that $c_0+c_1+c_2+\ldots+c_{d-1}$ is equal to one of the values of $b$. This can be solved using modular knapsack dynamic programming, but the time complexity is $O(nm^2)$. We must optimise it further.

Consider the contribution of a single element $c_j$ to the values of $f_i(x)$ of its connected component. Let's say the difference relationship is that $c_i-c_j=w$ must hold. Notice that: 

* It adds $(x-w)\bmod m$ to all values of $f_i(x)$ for each $x$ going up modularly from $w$ to $(w+\lfloor\frac{m}{2}\rfloor)\bmod m$
* It adds $(w-x)\bmod m$ to all values of $f_i(x)$ for each $x$ going up modularly from $(w+\lceil\frac{m}{2}\rceil)\bmod m$ to $w$.

We can see it as "changing slope" at most three times, namely in $x=w$, $x=(w+\lfloor\frac{m}{2}\rfloor)\bmod m$, and $x=(w+\lceil\frac{m}{2}\rceil)\bmod m$.

This means, if we add up all contributions of each element, the number of points the slope changes in one connected component is at most $\frac{3n}{d}$. We will call these points as special points.

Consider an array $c_0, c_1, c_2, \ldots, c_{d-1}$ satisfying the condition that $c_0+c_1+c_2+\ldots+c_{d-1}$ is equal to one of the values of $b$. Consider the case if there exists at least two different indices $i$ such that the value of $c_i$ is not a special point in $f_i$. Suppose the indices are $i_1$ and $i_2$. Since both of them are not special points, the slope between $(c_{i_1}-1)\bmod m$ and $c_{i_1}$ is the same as the slope between $c_{i_1}$ and $(c_{i_1}+1)\bmod m$. The same is true for $i_2$. Let's say $z_1$ is the increase in value of the final answer if we do $c_{i_1}:=(c_{i_1}+1)\bmod m$ and $c_{i_2}:=(c_{i_2}-1)\bmod m$, and $z_2$ is the increase in value of the final answer if we do $c_{i_1}:=(c_{i_1}-1)\bmod m$ and $c_{i_2}:=(c_{i_2}+1)\bmod m$. From the observation above, we can see that $z_1 = -z_2$, which means one of them is non-positive. This means, if this is the case, we can always change the array $c$ into another array with an equal or smaller final answer.

This means, we can always do that operation to get an array $c$ such that there is at most one non-special point. Therefore, we can just consider those cases to find the minimum answer.

We can solve this using divide and conquer. We first call the recursive function $\text{dnc}(0,d-1)$. The moment we call the function $\text{dnc}(l,r)$, we have made the modular knapsack dynamic programming array if we have only considered the indices $i$ with $i<l$ or $r<i$ and only considering their special points. $\text{dnc}(l,r)$ recurses into $\text{dnc}(l,\frac{l+r}{2})$ and $\text{dnc}(\frac{l+r}{2}+1,r)$. Once $l=r$, we will consider that index as the one that can have a non-special point, then we can just iterate the array $b$ and take the answer from the knapsack array.

The depth of the recursion is at most $O(\log d)$. Each depth has insertions of $O(d)$ indices to the knapsack. Because each connected component only has $O(\frac{n}{d})$ special points, each depth does $O(n)$ dynamic programming transitions with each transition having $O(m)$ time complexity.

Time complexity: $O(nm \log (\text{GCD}(n,k)))$

