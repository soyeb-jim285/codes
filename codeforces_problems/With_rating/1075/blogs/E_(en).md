# E_(en)


### [1075A - The King's Race](../problems/A._The_King's_Race.md "Lyft Level 5 Challenge 2018 - Final Round (Open Div. 2)")

Let's find the minimum time needed for the white king to reach the coin.

It is obvious that it is always optimal to move only towards the coin. In case of white king it means that we should move only up, right or up-right diagonally. During one move we can only add $1$ or $0$ to any of our coordinates (or to both of them), it means that the length of the optimal path can not be smaller than $max(x-1,y-1)$.

Let's show that we can reach the coin with $max(x-1,y-1)$ moves.

First step. Let $z$ be equal to $min(x,y)$. The king does $z-1$ up-right moves, so after that the king will be in the cell $(z,z)$. 

Second step. Let's assume that $x \le y$ (the case when $x > y$ is proved in a similar way). So $z = x$. It means that the king is in the cell $(x,x)$. Now the king can do $y-x$ up moves, after which he would be in the cell $(x,y)$. 

It took him $(x-1)+(y-x)=y-1$ moves to reach the coin. If $x$ was greater than $y$ he would need $x-1$ moves (could be proved the same way). 

So now we proved that it takes $max(x-1,y-1)$ moves for the white king to reach the coin.

In the same way we can prove that it takes $max(n-x,n-y)$ steps for the black king to reach the coin.

The king, which is closer to the coin, wins. If the distances is equal, than the white king wins, because he moves first.

Final description of the algorithm:

If $max(n-x,n-y)<max(x-1,y-1)$ then the answer is "Black", otherwise the answer is "White".

It is also can be proven that instead of comparing minimal distances between the coin and the kings we can compare manhattan distances between them. I will leave the proof as homework task.

Author: [arsijo](https://codeforces.com/profile/arsijo "International Grandmaster arsijo")

Developer: [stanislav.bezkorovainyi](https://codeforces.com/profile/stanislav.bezkorovainyi "Expert stanislav.bezkorovainyi")

 
### [1075B - Taxi drivers and Lyft](../problems/B._Taxi_drivers_and_Lyft.md "Lyft Level 5 Challenge 2018 - Final Round (Open Div. 2)")

Let's find for each rider the taxi driver that will get his call.

To do this we can find for each rider the nearest taxi driver at right and the nearest taxi driver at left. Let's define the nearest taxi driver at left for $i$-th citizen as $l_i$ and at the right as $r_i$.

The computations can be done with the following algorithm:

Let's define $l_0=0$ and $r_{n+m+1}=n+m+1$. And $x_0=-2*10^9$, $x_{n+m+1} = 2*10^{9}$.

In order to find $l_i$ for each $i$ we should iterate through the citizens from $1$ to $n+m$. If the $i$-th citizen is a taxi driver, then he/she is obviously the nearest taxi driver to himself/herself. If the $i$-th citizen is a rider, then $l_i=l_{i-1}$

In order to find $r_i$ for each $i$ we should iterate through the citizens from $n+m$ to $1$. If the $i$-th citizen is a taxi driver, then $r_i=i$, else $r_i=r_{i+1}$.

Now it's time to compute the answer.

Let's denote $b_i$ as the number of citizens, whose calls the $i$-th citizen will get (if the $i$-th citizen is a rider, then $b_i=0$).

In order to do compute the values of array $b$ we should iterate through the citizens from $1$ to $n+m$. If the $i$-th citizen is a rider, then if the $x_{r_i}-x_i<x_i-x_{l_i}$ (distance between the nearest taxi driver at right and the $i$-th citizen is smaller than distance between the nearest taxi driver at the left and the citizen), then taxi driver $r_i$ will get the call, otherwise the taxi driver $l_i$ will get the call. So if $x_{r_i}-x_i<x_i-x_{l_i}$, then $b_{r_i}:=b_{r_i}+1$, else $b_{l_i}:=b_{l_i}+1$. 

In order to print out the answer we iterate through the citizens from $1$ to $n+m$. If the $i$-th citizen is a taxi driver, than we should print $b_i$.

The algorithm iterates through the array four times, so overall complexity is $O(n+m)$

Author: [arsijo](https://codeforces.com/profile/arsijo "International Grandmaster arsijo")

Developer: [stanislav.bezkorovainyi](https://codeforces.com/profile/stanislav.bezkorovainyi "Expert stanislav.bezkorovainyi")

 
### [1074A - The Tower is Going Home](https://codeforces.com/contest/1074/problem/A "Lyft Level 5 Challenge 2018 - Final Round (Open Div. 1)")

Observation 1. If we remove all the horizontal spells, than the rook can move straightforward up to the upper side of the field. So the only purpose of removing the vertical spells is to reduce the number of horizontal spells to be removed.

Observation 2. If we want to remove the $i$-th vertical spell, then we should also remove all such vertical spells $j$, that $x_j<x_i$. It is obvious, because when we delete a vertical spell, we suppose that the rook would be able to outflank some horizontal spells by getting at rows that have greater number than $x_i$. If there remains at least one vertical spell $j$, such that $x_j<x_i$, than we will never be able to move to the rows with number greater than $x_j$, including $x_i$.

Let's find some observations about the horizontal spells:

Let's assume that we deleted $i$ vertical spells. It means, that the rook can move freely left and right at columns between $1$ and $x_{i+1}$ inclusive. Let's say that our rook is on the row $y$. If there is at least one cell which is located at row $y$ at any column between $1$ and $x_{i+1}$, that there is no blocking segment on the top of it, then the rook can move to this cell and move upwards into the row $y+1$. It means that if there is at least one gap in the blocking segments in row $y$ and in columns between $1$ and $x_{i+1}$ incluse, then there is no need to remove any of horizontal spells in the row.

Observation 3. We care only about such horizontal spells, in which $x_1=1$. We have already proved, that we only care about such rows, that there are no gaps in blocking segments in them. If there is no such horizontal spell with $x_1 = 1$, it means that there is a gap in the row at column $1$. If there is such horizontal spell, then if there are more spells in that row, there would be a gap between any pair of neighbouring segments. 

Since we only care only about segments with $x_1 = 1$ and it is guaranteed that no horizontal segments share a common point, it means that we might not care about the $y$ of any horizontal spell, because there is no such pair of segments that both $x_1$ and $y$ of these are equal. 

So now while reading the descriptions of the horizontal spells, if the $x_1$ of $i$-th horizontal spell is not equal to $1$, we can ignore it. Otherwise, we add $x_2$ to some array.

Now we can sort the array of $x_2$-s, and solve the task using the two-pointer technique. 

Here is the final algorithm: 

Add fake vertical spell with $x=10^9$.

Sort all the vertical spells in ascending order.

While reading the descriptions of the horizontal spells, we ignore ones with $x_1$ not equal to $1$. In other case, we add $x_2$ to the array.

Sort the array of $x_2$-s in ascending order. Now we use the two pointer technique in the following way: we iterate $i$ from 0 to n — the number of vertical spells to be deleted and on each step we advance the pointer while the $x_2$ at which the pointer points is less then $x$ of the $(i+1)$-th vertical spell. Let's denote the position of the pointer as $p$. The number of horizontal spells, that we need to remove with $i$ vertical spells removed is $m-p+1$. Let's define the position of the pointer at $i$-th step as $p_i$.

The answer to the problem in minival value of $i + m - p_i + 1$ among all $i$ from $0$ to $n$.

Overall complexity $O(n \log n + m \log m)$

Author: [stanislav.bezkorovainyi](https://codeforces.com/profile/stanislav.bezkorovainyi "Expert stanislav.bezkorovainyi")

Developer: [stanislav.bezkorovainyi](https://codeforces.com/profile/stanislav.bezkorovainyi "Expert stanislav.bezkorovainyi")

 
### [1074B - Intersecting Subtrees](https://codeforces.com/contest/1074/problem/B "Lyft Level 5 Challenge 2018 - Final Round (Open Div. 1)")

I'll split this into two parts, first is the solution, second is why it works.

The intended solution only uses two questions. 

1. Choose an arbitrary $y_j$, and ask "B y_j". Let the response be $R$.
2. Find a node $x_i$ that is the closest to node $R$. This can be done with a BFS or DFS.
3. Ask "A x_i". Let the response be $Q$.
4. If $Q$ is one of $y_1,y_2,\ldots,y_{k_2}$, print "C x_i", otherwise, print "C -1".

Here is why it works. Let's use the fact that if the two subtrees don't intersect, there is an edge in the tree such that if we cut the tree on this edge, it will split it into two components, each containing one of the subtrees.

Suppose we did step 1 and we have $R$. Let's root our tree at $R$. There is a unique node $x_i$ that has lowest depth in this tree which we can find (given that $x_1,x_2,\ldots,x_{k_1}$ form a subtree).

Now, we claim that the two subtrees intersect if and only if Li Chen owns a node that lies in the subtree rooted by $x_i$ (and in particular, we will show it is sufficient to only check node $x_i$).

If none of Li Chen's nodes lie in the subtree rooted by $x_i$, then the edge $x_i$ to its parent cuts the tree into two components with one subtree completely lying in one component and the other in the second, so the two subtrees are disjoint.

Otherwise, there is a node $W$ that is in Li Chen's subtree that lies in the subtree rooted by $x_i$. All nodes in the path of $R$ to $W$ must also belong to Li Chen's subtree, and in particular this includes node $x_i$, so the two trees intersect. This also shows we can just check if $x_i$ belongs in Li Chen's subtree by asking a question about it.

Author: [Lewin](https://codeforces.com/profile/Lewin "International Grandmaster Lewin")

Developer: [Lewin](https://codeforces.com/profile/Lewin "International Grandmaster Lewin")

 
### [1074C - Optimal Polygon Perimeter](https://codeforces.com/contest/1074/problem/C "Lyft Level 5 Challenge 2018 - Final Round (Open Div. 1)")

I will show 2 solutions, both of which work in $\mathcal{O}(n)$ time. First, it is not hard to notice that we can only consider polygons that are convex.

Observation: For a convex polygon, the given definition of "polygon perimeter" is equivalent to the perimeter of the bounding rectangle (aligned with the axis), of our polygon. If we look at some convex polygon, and 4 values $max_x, min_x, max_y, min_y$ representing the maximal $x$ coordinate of a point, minimal $x$, maximal and minimal $y$, then the perimeter of the bounding rectangle is simply $2 * (max_x - min_x + max_y - min_y)$.

This simple rephrase gives us a bonus, and crucial observation: It is enough for us to take 4 points from the input, such that the perimeter of their polygon is the maximal possible (and is equal to the perimeter of the polygon formed from $n$ points). We will consider these the extreme points. Note that after taking the extreme points, it does not matter which other points we take. So, this solves all $f(4), \ldots, f(n)$.

We are left with $f(3)$ to compute (maximal triangle perimeter). Following are 2 solutions to do it:

Solution 1: Let's show that the optimal triangle uses at least 2 of the extreme points. Imagine some optimal triangle, and its bounding rectangle. Notice that since each edge of the bounding rectangle must touch some vertex of the triangle (it is bounding after all), and we have 4 edges and 3 vertices, then there must be some vertex of the triangle that touches 2 edges of the rectangle (so it coincides with a rectangle vertex). If this is the case, we know that in comparison with the 2 other vertices, this vertex has "extremal" X and Y coordinates (minimal/maximal X, and minimal/maximal Y). Without loss of generality, assume this vertex has maximum X and Y. Then to optimize the perimeter, the other two vertices should have smallest possible X and smallest possible Y. We can pick these 2 vertices to be 2 of the extreme points (one with minimal X and one with minimal Y). So, this shows we just need to iterate over every adjacent pair of extreme vertices, and over all other points as the last vertex. This takes $\mathcal{O}(n)$.

Solution 2: This solution is more general, and is an extension of the problem to find the 2 most distant points (manhattan distance). The triangle perimeter is an expression with 6 terms: $|x_1 - x_2| + |y_1 - y_2| + \ldots + |y_3 - y_1|$. We wish the maximize this expression, but the absolute value is troubling us. For each term, there are 2 cases: either it is positive, so the absolute value does nothing, or it is negative, so the absolute value negates it. In total, for the 6 terms we have $2^6 = 64$ options to place signs between them. We will call such option a setting.

For any setting, the advantage now is that we can accumulate terms: For example the setting $++---+$, evaluates the expression to:

 $(2x_1 + 0y_1) + (-2x_2 - 2y_2) + (0x_3 + 2y_3)$ We solve every setting by its own, and over all settings we take the maximal answer.

Please note, that this strategy only works to find the maximal value of the expression, not minimal. The proof of this is left as an exercise to the reader :) (I promise it is not difficult).

Given 6 constants $c_1, c_2, ..., c_6$, we want to find 3 indicies $i < j < k$ to maximize: $c_1 * x_i + c_2 * y_i + ... + c_6 * y_k$. We define 3 arrays: 

* $P_i = c_1 \cdot x_i + c_2 \cdot y_i$
* $Q_i = c_3 \cdot x_i + c_4 \cdot y_i$
* $R_i = c_5 \cdot x_i + c_6 \cdot y_i$

 And so we want to maximize $P_i + Q_j + R_k$. This can be done in $\mathcal{O}(n)$ with simple dynamic programming.So this whole solution is $\mathcal{O}(n)$, with a constant of 64. In general, to compute $f(k)$ this solution takes $\mathcal{O}(n \cdot 4^k \cdot k)$ time, without any observations.

Author: [Noam527](https://codeforces.com/profile/Noam527 "Master Noam527")

Developer: [Noam527](https://codeforces.com/profile/Noam527 "Master Noam527")

 
### [1074D - Deduction Queries](https://codeforces.com/contest/1074/problem/D "Lyft Level 5 Challenge 2018 - Final Round (Open Div. 1)")

First, let's learn how to handle information we have not recieved in updates. Let the function $W(l, r)$ be equal to the xor of the subarray $[l, r]$. Also, we define $W(l, r) = W(r, l)$.

Assume 3 indicies $a \leq b \leq c$. There are 2 rules: 

* $W(a, b) \oplus W(b + 1, c) = W(a, c)$.
* $W(a, c) \oplus W(b, c) = W(a, b - 1)$ (holds when $a < b$).

These rules require a lot of conditions (and also plenty of $\pm$ 1). We can simplify them greatly: Let's index the borders between cells in our array (there are $2^{30} + 1$ of them). Now, instead of defining a subarray $[l, r]$ by its 2 endpoint cells, we will define a subarray by its 2 endpoint borders. Technically it just means, that we should increase $r$ by 1, and then we get the 2 end borders.

From now I will assume that our input is given in such a way, that subarrays are defined by their borders (So I will not mention the addition of 1 to $r$). Notice that the function $W(l, r)$ is also affected by this.

If we take a look at our rules again, they boil down to just 1 rule: 

* $W(a, b) \oplus W(b, c) = W(a, c)$, for any 3 indicies $a,b,c$ ($a \leq b \leq c$ doesn't need to hold now, for instance $W(3, 5) \oplus W(5, 2) = W(3, 2)$).

This transformation also shows an observation; Assume every border is a vertex in a graph, and every update $W(l, r) = x$ describes an undirected edge between the vertices $l, r$ with weight $x$. We let the distance between 2 nodes $a, b$ be the xor of edge weights on the path between them. Notice that this distance is equal to $W(a, b)$. In other words, an update adds an edge and a query asks for some distance.

Another observation is that, we do not care about all the $2^{30} + 1$ nodes, but only about the ones we recieved in queries and updates. Moreover, their order is irrelevant, so we can do an online mapping of new nodes to the next free indicies. Thus, the number of nodes will be worstcase $\mathcal{O}(q)$.

Claim: We can know the answer to some query $[l, r]$, if and only if there exists a path between the nodes $l, r$ (they are in the same connected component).

//start spoiler of proof

There will be some subset of edges we take, to form the xor between nodes $l$ and $r$. Assume every vertex has 2 states, on/off. Initially all vertices are off, and our current answer is $0$. When we take an edge we flip the state of its 2 ends, and xor our answer by its weight. Suppose at some moment of time the nodes with "on" state are {$x_0, x_1, x_2, ..., x_k$} (in sorted order). Observe that our current answer is equal to $W(x_0, x_1) \oplus W(x_2, x_3) \oplus \ldots \oplus W(x_{k-1}, x_k)$. This implies we want our subset of edges to end up having only the nodes {$l, r$} activated. We look at the connected components. Observe that in each connected component, the number of nodes activated at any time is even. If the nodes $l$ and $r$ are in different component, then in our final result we would want to have only 1 activated node in the component of $l$, and same with $r$, but this is impossible.

//end spoiler of proof

First, we need to know whether a query gives us 2 nodes that are in different components (to know whether the answer is $-1$ or not). For this we need to use the Union-Find structure. Also notice, that our Union-Find structure will only need to handle a forest of trees (if an update gives us an edge that creates a cycle, it means there is no contribution, so we ignore it).

Provided that an answer does exist, we need to also handle finding a xor path between 2 nodes in a tree, and to support merging of trees. Generally to find a property over some path in a tree, it is common to use LCA or binary lifting. This turns out very difficult when we also need to merge trees (unless you insist on implementing Link-Cut/ETT). Fortunately, we can still abuse the xor operator. In some tree, mark $x_v$ as the xor of edges on the path from $v$ to some arbitrary root in the tree. The xor path between nodes ($u, v$) turns out to be $x_u \oplus x_v$. So we would like to maintain for each tree some arbitrary root and all those values.

Notice that we can augment our Union-Find structure to support this as well: For each node $v$ in the structure, we maintain $p_v$ as its parent in the structure, and $x_v$ as the xor on the path from $v$ to $p_v$. Notice that $x_v$ can be easily updated together with $p_v$ during the $find()$ operation in the structure.

To summarize, when we are given $W(l, r) = x$ in some update, we transform it to $W(p_l, p_r) = x \oplus x_l \oplus x_r$, and then we add the edge between the parents.

Finally, the complexity is $\mathcal{O}(q \log{q})$, but this is only due to the online mapping if we use a regular map; You can use a hash table and get a running time of $\mathcal{O}(q \times \alpha(q))$, but I suggest being careful with a hash table (you may want to read this: <https://codeforces.com/blog/entry/62393>).

Author: [Noam527](https://codeforces.com/profile/Noam527 "Master Noam527")

Developer: [Noam527](https://codeforces.com/profile/Noam527 "Master Noam527")

 
### [1074E - Grid Sort](https://codeforces.com/contest/1074/problem/E "Lyft Level 5 Challenge 2018 - Final Round (Open Div. 1)")

The solution is more of a coding one than an algorithmic one. There are many different approaches, and it's important to be careful in how it is implemented. I'll explain one of the implementations.

First, we can always move a particular block left, up, down, or right with an appropriate 2x2 square around it. Let's code some functions that let us do that for each direction.

Next is to make sure that these moves don't mess up previous block spaces as we move blocks to the correct place. We can almost place blocks correctly in their spaces one by one in row major order, but there are some special cases.

- We can do all blocks except the last two rows, which we'll handle separately (in paragraph below) - For each row, we can correctly place all blocks except the last one. The last one requires a bit more careful work, but is easy to handle if we have at least two free rows.

For the last two rows, we can fill it in column by column from left to right. This is a similar startegy to fitting in the last column of the previous rows. We can almost do this except for the last 2x2 square.

For the last 2x2 square, we can use the following sequence of moves to swap two blocks:


```cpp
123  
456  
  
413  
526  
  
421  
563  
  
213  
456  

```
Thus, we can shift the last block into the right position, then do at most three swaps (using the above sequence of moves) to fix the remaining blocks.

The number of moves for this strategy can be computed and estimated to be about 50k in the worst case.

Author: [Lewin](https://codeforces.com/profile/Lewin "International Grandmaster Lewin")

Developer: [Lewin](https://codeforces.com/profile/Lewin "International Grandmaster Lewin")

 
### [1074F - DFS](https://codeforces.com/contest/1074/problem/F "Lyft Level 5 Challenge 2018 - Final Round (Open Div. 1)")

Let's consider an arbitrary run of DFS producing some tree. Let's root the tree at the starting vertex. It can be shown that on a directed graph, there are only two types of edges. The first are the tree edges (those are the ones that are used to visit a new vertex). The second are edges which, upon being traversed, lead to a vertex that was already visited. It can be shown that, in the rooted tree, those edges always connect a vertex with one of its ancestors. 

In other words, all the edges that are dynamically added to the tree must connect a vertex with one of their ancestors. This means that the staring vertex must not lie on the path connecting the two endpoints of such edge, or any of the vertices in some of the subtrees. For instance, on the second sample, the edge $\{2,4\}$ disallows the vertex $1$ from being the starting vertex, as it lies on the path from $2$ to $4$, and also vertex $6$.

Each edge thus forbids a certain set of vertices from being the starting point. This yields a straightforward $\mathcal O(n^2)$ solution. To optimize it further, we can root the tree arbitrarily and renumber the vertices using their DFS visit times. When we do this, we notice that the set of a forbidden vertices for each edge is a union of at most three intervals of vertices. This lets us build an $\mathcal O(n \log n)$ solution using a segment tree. The operation is add a constant on interval, and then find the minimum on interval and the number of occurrences of said minimum. We add $1$ to forbid a vertex because of an edge, subtract $1$ to revert that when the edge is subsequently removed. The answer is the number of minimums on the whole tree if that minimum is $0$, and $0$ otherwise.

Author: [_h_](https://codeforces.com/profile/_h_ "International Grandmaster _h_")

Developers: [_h_](https://codeforces.com/profile/_h_ "International Grandmaster _h_") and [majk](https://codeforces.com/profile/majk "International Grandmaster majk")

