# Tutorial

**Div2A**
### [1321A - Contest for Robots](../problems/A._Contest_for_Robots.md "Codeforces Round 625 (Div. 2, based on Technocup 2020 Final Round)")

Score distribution for problems having $r_i = b_i$ is irrelevant (we can make $p_i = 1$ for all of them). Let's consider the remaining problems.

Suppose we have $x$ problems solved by the first robot (and not solved by the second one), and $y$ problems solved by the second robot (and not solved by the first one). If $x = 0$, then the score of the first robot won't exceed the score of the second robot by any means, so the answer is $-1$.

Otherwise, we can set the score for problems solved by the first robot to some number $p$, and the score for all remaining problems to $1$. Then, the condition $xp > y$ must hold, or $p > \frac{y}{x}$, so $p = \lceil \frac{y + 1}{x} \rceil$ is the answer. Note that the constraints allow us to iterate on $p$ instead of implementing a formula for it.

 **Div2B/Div1A**
### [1320A - Journey Planning](https://codeforces.com/contest/1320/problem/A "Codeforces Round 625 (Div. 1, based on Technocup 2020 Final Round)")

Let's rewrite the equality given in the statement as $c_{i + 1} - b_{c_{i + 1}} = c_i - b_{c_i}$. It means that all cities in our path will have the same value of $i - b_i$; furthermore, all cities with the same such value can always be visited in ascending order.

So we may group cities by $i - b_i$, compute the sum in each group and find the maximum over all groups. For example, this can be done by storing the sum for each $i - b_i$ in an array (be careful with negative values of $i - b_i$, though!)

 **Div2C**
### [1321C - Remove Adjacent](../problems/C._Remove_Adjacent.md "Codeforces Round 625 (Div. 2, based on Technocup 2020 Final Round)")

The optimal answer can be obtained by the following algorithm: choose the maximum possible (alphabetically) letter we can remove and remove it. We can do it naively and it will lead to $O(n^2)$ time complexity.

Why is it always true? Suppose we remove the maximum letter $i$ that can be used to remove some other letter $j$ (it is obvious that $s_i + 1 = s_j$ in such case).

If there are no other letters between $s_i$ and $s_j$ then $s_i$ is not the maximum letter, so we got contradiction with our algorithm.

Now suppose that we can remove all letters between $s_i$ and $s_j$. Then we first choose $s_j$ and only after that $s_i$ by our algorithm.

Consider the last case — there is at least one letter $s_k$ between $s_i$ and $s_j$. Because we cannot remove $s_k$ then there are only two cases: $s_k > s_j + 1$ or $s_k + 1 < s_i$. Then we cannot use $s_i$ to remove $s_j$ at all.

 **Div2D/Div1B**
### [1320B - Navigation System](https://codeforces.com/contest/1320/problem/B "Codeforces Round 625 (Div. 1, based on Technocup 2020 Final Round)")

Let $d_v$ be the length of the shortest path from $v$ to $t$. If we move from vertex $v$ to vertex $u$ on our path, then:

* the rebuild will definitely occur if $d_u > d_v − 1$;
* the rebuild may occur if there exists at least one vertex $w \ne u$ such that $d_w = d_v − 1$ (the navigation system could have built a path through $w$).

We can calculate all values of $d_v$ using BFS from $t$ on a transposed graph. Now for each vertex, we can easily determine whether it should be added to the set of vertices where the route definitely rebuilds and to the set of vertices where a rebuild is possible.

 **Div2E/Div1C**
### [1320C - World of Darkraft: Battle for Azathoth](https://codeforces.com/contest/1320/problem/C "Codeforces Round 625 (Div. 1, based on Technocup 2020 Final Round)")

Let $S_a$ be the set of monsters which may be defeated with a weapon having attack $a$. Then the profit we get, if we use weapon $i$ with attack $a$ and armor $j$ with defense $b$, is $−ca_i−cb_j+( \textrm{the sum of $z_k$ over all monsters $k$ from the set $S_a$ having $y_k < b$})$. 

We will iterate on weapons in non-descending order of their attack values and maintain $S_a$. For each armor option, maintain the value of $D_j = −cb_j+(\textrm{total profit from monsters having attack less than $b_j$})$. If armor sets are sorted by their defense value, adding a new monster into $S_a$ adds some value on the suffix of $D_j$. So we can maintain the values of $D_j$ in a segment tree.

So the solution is: 

* Build a segment tree on values of $−cb_j$, where all armors are sorted by $b_j$.
* Iterate on weapons and monsters in sorted order (sort by $a_i$/$x_k$ in non-descending order). For each new weapon $i$ we should add all monsters $x_k < a_i$ which were not added yet (we can maintain a pointer on the last added monster to find them quickly).
* Adding a monster means adding $z_k$ on suffix of $D_i$.
* After that, for the current weapon $i$ we may try $−ca_i + \max D_j$ as the answer.
 **Div2F/Div1D**
### [1320D - Reachable Strings](https://codeforces.com/contest/1320/problem/D "Codeforces Round 625 (Div. 1, based on Technocup 2020 Final Round)")

How to determine if two strings can be transformed into each other? Obviously, the number of ones in both strings should be the same. Also the following invariant holds: if all pairs of consecutive ones are deleted, the positions of remaining ones are not affected by any operations. 

We can prove that these conditions are sufficient: if we move all pairs of ones to the end of the string, the strings are the same if the positions of ones are the same and the number of characters is the same (moving all pairs of ones to the end of the string is almost the same as deleting them).

One of the possible solutions is the following — build a segment tree, where each vertex should maintain:

* the number of deleted pairs of ones;
* the hash of positions of the remaining ones;
* the characters at the ends of the corresponding segment (we need these to delete pairs of consecutive ones, if they appear as a result of merging the segments).

When merging a pair of vertices, we check if we have to delete a pair of consecutive ones and rebuild the hash for the new vertex.

There are lots of other approaches, including a deterministic one (which uses suffix structures).

 **Div1E**
### [1320E - Treeland and Viruses](https://codeforces.com/contest/1320/problem/E "Codeforces Round 625 (Div. 1, based on Technocup 2020 Final Round)")

When processing a query, the key idea is to build a compressed version of the tree containing only some important vertices. We are not interested in vertices not belonging to any path between some $v_i$ and $u_i$. Furthermore, we can compress all chains in the tree by deleting all vertices with degree $< 2$ not listed in the query. To find all the important vertices in the compressed tree, we may do the following: sort all $v_i$ and $u_i$ by their entry time in DFS traversal of the tree, and then add LCA's of all neighbouring pairs in the sorted list.

To restore the edges, we will consider all important vertices in sorted order and maintain the path to the current vertex in a stack. When we process a vertex, we delete vertices from top of the stack until we get an ancestor of current vertex on top of the stack, then this ancestor is the parent of the current vertex in the compressed tree.

When we have the compressed tree, there are two approaches to determining the virus affecting each node:

* Run Dijkstra's algorithm. The distance for each vertex $v$ is the pair (the time when $v$ becomes infected, the index of a virus infecting $v$). For each initially infected vertex $v_i$ the initial distance is $(0,i)$. When processing a vertex with Dijkstra, we can try to infect all of its neighbours with the same virus.
* Use subtree DP. First of all, for each vertex we determine the virus from its subtree that will infecting it (not taking into account any viruses from above): it's either the virus in this vertex or the virus infecting one of its children. Then we may to the same thing in the other direction: push viruses down the tree and calculate whether they are infecting vertices faster than the viruses from the lower vertices.

In any case, each query is processed in $O((k + m) \log n)$.

 **Div1F**
### [1320F - Blocks and Sensors](https://codeforces.com/contest/1320/problem/F "Codeforces Round 625 (Div. 1, based on Technocup 2020 Final Round)")

Initially fill each cell with a colorless block, and then try to paint blocks and delete them if they definitely contradict the sensor data.

We have to delete a block if:

* it is observed by a sensor which should see no blocks;
* it is observed by at least two sensors that report different block types.

In any of these cases, we delete a block. Then we update all sensors which were looking at it: for each of them, find the next block which they are looking at, and maybe delete it (if the information for it is contradictory). If this results in deleting all blocks for a sensor that should see a block, then the answer is $-1$.

If this process terminates without any contradictions, we can construct the answer. Now all sensors that should not see any blocks don't see them, and each block observed by sensors can be assigned a type that does not contradict the sensor data. If some block is not observed by sensors at all, we may assign any color to it (or even delete it).

To maintain blocks that should be deleted, we may use a BFS-like approach with a queue, or a DFS-like function that deletes a block, updates the sensors looking at it, and maybe calls itself recursively for the blocks that have to be deleted after the updates.

