# Tutorial_(en)

[1534A - Colour the Flag](../problems/A._Colour_the_Flag.md)

Author: [crackersamdjam](https://codeforces.com/profile/crackersamdjam "Grandmaster crackersamdjam")

 **Hint 1**Let's say you know the colour of the first square, what colours can you figure out next?

 **Hint 2**Colour it like a chessboard, but there's more than one possible chessboard!

 **Hint 3**Brute force the color of the first square!

 **Tutorial**
### [1534A - Colour the Flag](../problems/A._Colour_the_Flag.md "Codeforces LATOKEN Round 1 (Div. 1 + Div. 2)")

Observe that there are only two valid grids, one where the top left cell is "R" and one where it's "W". We can just test those two grids and see if they conform with the requirements.

Time complexity: $\mathcal{O}(nm)$

 **Solution**[119400830](https://codeforces.com/contest/1534/submission/119400830 "Submission 119400830 by Dormi")

[1534B - Histogram Ugliness](../problems/B._Histogram_Ugliness.md)

Author: [Dormi](https://codeforces.com/profile/Dormi "Grandmaster Dormi")

 **Hint 1**Consider the contribution of each pillar to the answer.

 **Hint 2**How does doing the operation on a pillar change the contribution to the answer?

 **Hint 3**You only want to do an operation on a pillar if the top cell contributes 2 to the answer.

 **Tutorial**
### [1534B - Histogram Ugliness](../problems/B._Histogram_Ugliness.md "Codeforces LATOKEN Round 1 (Div. 1 + Div. 2)")

It's only optimal to decrease a column $i$ if $a_i > a_{i+1}$ and $a_i > a_{i-1}$, as that would reduce the vertical length of the outline by $2$ while only costing $1$ operation. Additionally, observe that decreasing a column will never affect whether it is optimal to decrease any other column, so we can treat the operations as independent.

Thus, our algorithm is as follows: while it is optimal to decrease a column, do it. Once this is no longer the case, calculate the final value of the histogram. This can be sped up to $\mathcal{O}(n)$ with some arithmetic and the observation above.

 **Solution**[119400874](https://codeforces.com/contest/1534/submission/119400874 "Submission 119400874 by Dormi")

[1534C - Little Alawn's Puzzle](../problems/C._Little_Alawn's_Puzzle.md)

Author: [Ninjaclasher](https://codeforces.com/profile/Ninjaclasher "Candidate Master Ninjaclasher")

 **Hint 1**Let's say you know whether you flipped the first cell or not, which new columns must be flipped?

 **Hint 2**Create a graph of n nodes, draw an edge between two values if they both exist in the same column, what structure does this graph have?

 **Hint 3**It is a bunch of disjoint cycles (since each node has an in-degree of 2).

 **Hint 4**Each cycle is independent, and there are 2 ways to flip each cycle.

 **Tutorial**
### [1534C - Little Alawn's Puzzle](../problems/C._Little_Alawn's_Puzzle.md "Codeforces LATOKEN Round 1 (Div. 1 + Div. 2)")

Define the "direction" of a column as the orientation of its numbers. Swapping the numbers in a column will flip its direction.

Let's create a simple, undirected graph where the nodes are the $n$ columns on the puzzle and we draw one edge connecting it to the $2$ other columns that share a number with it. Notice that the degree of every node in this graph is $2$, so the graph must be made of some number of disjoint simple cycles.

Now consider any component in the graph. If we fix the direction of any of the columns in the component, that will fix the direction of the columns adjacent to it, and so on until the direction of every column in the component has been fixed (also note that as the component is a simple cycle, we will never get a contradiction). As there are $2$ possible directions for any column, there are thus $2$ ways to direct the columns in this component.

Lastly, notice that the columns in each component are independent, so the answer is simply $2^k$, where $k$ is the number of components in our graph.

Time Complexity: $\mathcal{O}(n)$ with DFS

 **Solution**[119400885](https://codeforces.com/contest/1534/submission/119400885 "Submission 119400885 by Dormi")

[1534D - Lost Tree](../problems/D._Lost_Tree.md)

Author: [Plasmatic](https://codeforces.com/profile/Plasmatic "Grandmaster Plasmatic")

 **Hint 1**All trees are bipartite.

 **Hint 2**Find a 2-coloring of a tree in one query.

 **Hint 3**You can find all nodes adjacent to one node in one query.

 **Hint 4**The min(number of black, number of white) nodes is ≤⌊n2⌋.

 **Tutorial**
### [1534D - Lost Tree](../problems/D._Lost_Tree.md "Codeforces LATOKEN Round 1 (Div. 1 + Div. 2)")

If we had $n$ queries, solving this problem would be easy as we could just query every single node and add edges when $d_i=1$. However, notice that as long as we make a query for at least $1$ endpoint of every edge, we will be able to find all the edges using this method.

Observe that a tree is bipartite, so we would be able to achieve a bound of $\lceil \frac{n}{2} \rceil$ as long as we only query the smaller bipartite set. To figure out which set is smaller, we can just query any node and look at which nodes have odd depth and which ones have even depth.

Lastly, be careful with your queries so that your worst-case bound is $\lceil \frac{n}{2} \rceil$ rather than $\lfloor \frac{n}{2} \rfloor + 1$. One way to do this is to not include the initial node you query in either bipartite set (so you are effectively working with $n-1$ nodes rather than $n$).

Time complexity: $\mathcal{O}(n^2)$

 **Solution**[119400891](https://codeforces.com/contest/1534/submission/119400891 "Submission 119400891 by Dormi")

[1534E - Lost Array](../problems/E._Lost_Array.md)

Author: [Plasmatic](https://codeforces.com/profile/Plasmatic "Grandmaster Plasmatic")

 **Hint 1**Try to solve this problem for n≤15.

 **Hint 2**Try BFSing on the bitmasks.

 **Hint 3**Do we really care about what elements are in the bitmask?

 **Hint 4**Only the number of nodes in each mask matters.

 **Tutorial**
### [1534E - Lost Array](../problems/E._Lost_Array.md "Codeforces LATOKEN Round 1 (Div. 1 + Div. 2)")

"tl;dr it's pure BFS"

The only information we can obtain from a query is the XOR sum of the subset we queried. We can also try and obtain some frequency information about the bits (whether the number of bits at position $i$ is odd for every bit $i$), but trying to combine frequency information is ultimately analogous to just combining the XOR sums of different subsets. Additionally, trying to combine XOR sums with other operations such as OR and AND will cause us to lose the information about the XOR sum of the combined subsets, and are thus not useful.

Thus, the only way to find the answer is to repeated query different subsets until their XOR sum includes every element in the array.

To find the minimum number of queries, we can run a BFS to find the shortest number of queries to go from the XOR sum of $0$ numbers to the XOR sum of all of them. Observe that only the number of values currently present in the XOR sum matters, as we can query the XOR sum of any subset of numbers in the array as long as it has size $k$. In our graph, we can transition from the XOR sum of a subset of size $i$ by picking $j$ ($0 \le j \le k$) selected numbers and $k-j$ unselected numbers. This changes the size of our subset by $k-2j$.

Time Complexity: $\mathcal{O}(nk)$

 **Solution**[119400897](https://codeforces.com/contest/1534/submission/119400897 "Submission 119400897 by Dormi")

[1534F1 - Falling Sand (Easy Version)](../problems/F1._Falling_Sand_(Easy_Version).md)

Author: [Dormi](https://codeforces.com/profile/Dormi "Grandmaster Dormi")

 **Hint 1**Make a directed graph on the sand.

 **Hint 2**The graph should satisfy the following property: if a node a can reach another node b by a sequence of edges, disturbing a will disturb b.

 **Hint 3**Compress scc's in the graph.

 **Hint 4**You must disturb all nodes with in-degree 0 in the new graph.

 **Tutorial**
### [1534F1 - Falling Sand (Easy Version)](../problems/F1._Falling_Sand_(Easy_Version).md "Codeforces LATOKEN Round 1 (Div. 1 + Div. 2)")

Let's model the grid as a directed graph. Take every block of sand in the puzzle as a node. Now add an edge from a node $A$ to a node $B$ if: 

* $B$ is the first block of sand below $A$.
* $B$ is the first block of sand next to or below $A$ and on the first column to the left of $A$.
* $B$ is the first block of sand next to or below $A$ and on the first column to the right of $A$.
* $B$ is on the cell directly above $A$.

Within this graph, the nodes which are reachable from a node $A$ are identical to the set of blocks of sand which will be disturbed as a result of $A$ being disturbed. 

The question is then converted to, given a directed graph, what is the size of the smallest set of nodes such that all nodes within the graph are reachable from this set.

To solve this, we can compress all strongly connected components in the graph (using Tarjan's Algorithm or Kosaraju's Algorithm), leaving us with a directed acyclic graph. 

From here, it can be observed that all nodes which have an in-degree of $0$ need to be disturbed manually, as no other nodes can disturb them. Moreover, as the graph is acyclic, it can also be proven that all nodes which have an in-degree greater than $0$ are reachable from a node that has an in-degree of $0$. As such, it is minimal and sufficient to disturb all nodes which have an in-degree of $0$.

Proof: Take any node $X$ that does not have an in-degree of $0$. Take a node $Y$ that has an edge connecting it to $X$. This node must exist as $X$ has a positive in-degree. Now all nodes that can reach $Y$ can also reach $X$. Thus, we just need to prove that $Y$ is reachable from a node with in-degree $0$ to prove that $X$ is reachable from a node with in-degree $0$. Repeat this process on the node $Y$, taking it as the new $X$. Continue to do this until $X$ has an in-degree of $0$. This process must end and find such an $X$ because there are only a finite number of nodes in the graph, and any repeated node within this process would indicate that there is a cycle in the graph. However as the graph is acyclic, this can not happen. Once we have found this $X$, we can say that $X$ is reachable from a node with an in-degree of $0$ as it itself is a node within in-degree $0$. We can then follow the graph to prove that the first $X$ is reachable from a node with in-degree $0$.

Thus, the answer is the number of nodes with in-degree $0$ in the compressed graph.

Final Complexity: $\mathcal{O}(nm)$ or $\mathcal{O}(nm \cdot \log(nm))$ depending on implementation. 

 **Solution**[119400903](https://codeforces.com/contest/1534/submission/119400903 "Submission 119400903 by Dormi")

[1534F2 - Falling Sand (Hard Version)](../problems/F2._Falling_Sand_(Hard_Version).md)

Author: [Dormi](https://codeforces.com/profile/Dormi "Grandmaster Dormi")

 **Hint 1**Continued from F1, read that first.

 **Hint 2**The athi nodes from the bottom of each column must eventually be disturbed (call them special).

 **Hint 3**If a special node can reach another special node, you can delete that node.

 **Hint 4**Each node will remove some contiguous subsegment of the remaining special nodes' columns.

 **Hint 5**Find a greedy strategy to cover all of the columns.

 **Tutorial**Tutorial is loading... **Solution**[119400908](https://codeforces.com/contest/1534/submission/119400908 "Submission 119400908 by Dormi")

[1534G - A New Beginning](../problems/G._A_New_Beginning.md)

Author: [Aaeria](https://codeforces.com/profile/Aaeria "Master Aaeria")

 **Tutorial**
### [1534G - A New Beginning](../problems/G._A_New_Beginning.md "Codeforces LATOKEN Round 1 (Div. 1 + Div. 2)")

Observe that for any point $(x,y)$ and some path $A$, the minimum distance from $A$ to $(x,y)$ will occur on the intersection of $A$ and the antidiagonal of $(x,y)$. Here the antidiagonal is defined as a line $y=-x+c$. 

Proof:

Assume $(a,b)$ is the intersection of $A$ and the antidiagonal of $(x,y)$. If $(a,b) = (x,y)$, this distance is obviously minimal as it is equal to 0. 

Now consider the case where $(a,b) \neq (x,y)$. As a result of $(a,b)$ being on the antidiagonal, two properties will be true: 

* $|x-a| = |y-b|$.
* Either $a > x$ and $b < y$ or $a < x$ and $b > y$.

 Without loss of generality, assume $a < x$ and $b > y$. When you move forward on the path, increasing $b$ will only make $|y-b|$ larger. Thus, no matter how you change $a$, $\max(|x-a|,|y-b|)$ will always increase or stay the same. 

When you move backward on the path, decreasing $a$ will only make $|x-a|$ larger. Thus, no matter how you change $b$, $\max(|x-a|,|y-b|)$ will always increase or stay the same. 

Thus, the shortest distance will always occur at $(a,b)$.

Now we rotate the grid $45$ degrees clockwise so that the antidiagonals are now vertical lines on the new grid. Your movements on the grid now go from $(x,y)$ to $(x+1,y+1)$ or $(x+1,y-1)$. Furthermore, it is now optimal to plant a potato when you are on the same x coordinate as the potato. When you are at $(x,a)$, planting a potato at $(x,b)$ costs $\frac{|a-b|}{2}$. 

From here we can observe a slow dp. Define $dp[x][y]$ as the minimum cost of any path that goes from $(0,0)$ to $(x,y)$ and plant all potatoes $(a,b)$ such that $a \leq x$. Note: this function is only defined for when $x$ and $y$ have the same parity. This is as a point $(x,y)$ in the old grid translates to $(x+y,x-y)$ in the new grid and $x+y$ has the same parity as $x-y$. For speed, we also only calculate $dp[x][y]$ when there is a potato with a x-coordinate of $x$.

The transition is then established as $dp[x][y] = (\min{dp[a][b]} \forall y-(x-a) \leq b \leq y+(x-a)) + (\sum{\frac{|y-z|}{2}} \forall potatoes (x,z))$, where $a$ is the last x-coordinate containing a potato.

This runs in $\mathcal{O}(n \cdot 10^9)$.

This dp can then be optimized using slope trick. If you are not familiar with slope trick, we recommend learning it first at [Slope trick explained](https://codeforces.com/blog/entry/77298) and [[Tutorial] Slope Trick](https://codeforces.com/blog/entry/47821). 

Instead of maintaining a $2$ dimensional array, we can maintain functions $f_x$ where $f_x(y) = dp[x][y]$. To transition from $f_i$ to $f_j$, we first set $f_i(a) = \min{f_i(b)} \forall a-(j-i) \leq b \leq a+(j-i)$. This can be done by maintaining the center/minimum of the slope trick function and then offsetting all values in the left priority queue by $-(j-i)$ and offsetting all values in the right priority queue by $j-i$. 

Finally, we have to add the costs of the potatoes. Each of the potatoes $(x,y)$ is just a function $g$ such that $g(a) = \frac{|y-a|}{2}$. These functions can then be added onto $f_i$ finishing the conversion to $f_j$. The final answer is then the minimum of the last function.

Final Complexity: $\mathcal{O}(n \log n)$.

 **Solution**[119400915](https://codeforces.com/contest/1534/submission/119400915 "Submission 119400915 by Dormi")

[Tests generator](https://codeforces.com/https://github.com/zzaria/programming-contest-resources/blob/main/my%20problems/cf1524/g.zip)

[1534H - Lost Nodes](../problems/H._Lost_Nodes.md)

Author: [Ninjaclasher](https://codeforces.com/profile/Ninjaclasher "Candidate Master Ninjaclasher")

 **Tutorial**
### [1534H - Lost Nodes](../problems/H._Lost_Nodes.md "Codeforces LATOKEN Round 1 (Div. 1 + Div. 2)")

Finding the theoretical maximum

For now, let's only look at finding $k$ for fixed $f$. We will expand for all $f$ later.

We know that $f$ is on the path from $a$ to $b$. Let us root the tree at $f$. Thus, we know that the path will pass through the root, and that there are exactly $2$ non-negative length chains beginning at the root. With that in mind, let's take a look at what a question "? r really does. 

* What happens if $r$ is on the path from $a$ to $b$? In this case, we obtain $r$ as the answer.
* What happens if $r$ is not on the path from $a$ to $b$? In this case, we obtain the closest node to $r$ on the path from $a$ to $b$.

Let's try to find one endpoint of one of these chains first. Consider the following dynamic programming structure: 

* Let $dp[u]$ denote the minimum number of questions required to "solve" the subtree rooted at $u$. By "solve", we mean to determine if the endpoint of a chain is in the subtree or not, and if it is in the subtree, the exact node.

The base case is pretty obvious. For a leaf node, it will take exactly $1$ question to solve a leaf node. If the endpoint of the chain does indeed end at the leaf node, then a question will return the leaf node. Otherwise it'll return an ancestor of the leaf.

Let's move on to a non-base case at a node $x$. Let's call the most "expensive" child of $x$ as the child $c$ with the largest $dp[c]$ (i.e. takes the most number of questions to "solve").

For now, assume we know that an endpoint exists in the subtree rooted at $x$, and is not $x$. Thus, we will need to iterate through each child to determine in which child's subtree the endpoint exists. We will need to use one question per child. However, note that not all of these questions count towards our question count. There are two cases: 

1. In the current child we are exploring, the endpoint does exist there. In this case, the question we used does not count towards our question count. We can use a question from the child's question count. This may seem a bit strange, but if we query correctly, then in the same time we check if the endpoint exists in the child's subtree, we also process the most "expensive" child of the child and determine if the endpoint exist in that child of the child's subtree.
2. In the current child we are exploring, the endpoint doesn't exist there. In this case, the question we used must count towards our question count. We could consider this a "wasted" question as we didn't learn anything new about where the endpoint is, just that it's not in this child.

Now, in which order should be explore the children? We can greedy this. Recall that any "wasted" questions count towards our question count. Thus, for more "expensive" children, we want to have wasted less questions when we get to the child, as in the case the endpoint does exist there, we would need even more questions (adding the "wasted" questions to $dp[c]$ where $c$ is the child). This gives us the following idea: 

* To determine if the $i^\text{th}$ ($0$-indexed) child $c$ of $x$ contains the endpoint, we would need to waste $i$ questions. If the endpoint does exist in $c$, we would need to use a total of $dp[c] + i$ questions to "solve" the subtree rooted at $x$. Since we are trying to find the worst case, we want to order the children of $x$ such as to minimize the maximum of all $dp[c] + i$. The optimal ordering is the non-increasing order of $dp[c]$.

The transition is thus:

 $dp[x] = \max\{dp[c_i] + i\} \,\, \forall \,\, 0 \le i < |c|$, where the $dp$ values are sorted in non-increasing order, and $c$ are the children of $x$.

Now wait! We haven't handled the case where the endpoint doesn't exist in $x$ or the case where the endpoint is $x$ yet! Turns out, both of these cases are already handled for us. We only need to be a bit careful when we actually perform the interaction later on. 

* If the endpoint doesn't exist in $x$, we would have already realized when one of the questions to a child of $x$ returns an ancestor of $x$. This question count won't be lost though. It will simply be counted towards a "wasted" question for one of the ancestors of $x$.
* If the endpoint is $x$, then all of the questions to a child of $x$ will return $x$ (not a ancestor of $x$). Thus, we will know that the endpoint is $x$ with exactly $|c|$ wasted questions. Notice, however, that $|c| \le dp[x]$ by the nature of the transition. Thus, this case will never be our worst case, so we can ignore it for the dynamic programming.

We now have the dynamic programming complete, but notice that it's only for the endpoint of one chain. At our root $f$, there are two chains with two endpoints. Thus, our final answer won't be simply taking $dp[f]$. It will require a bit more computation.

For now, assume that both endpoints are not $f$ (i.e. both chains have positive length). Following a similar analysis as the dynamic programming transition, we have that for any child that does not contain either chain endpoint, we would need to "waste" a question. Once again, the optimal ordering is to process in non-increasing order. However, adding $i$ to the $i^\text{th}$ child is no longer correct. Consider the following observations: 

1. When processing a child that doesn't contain a chain, that child only takes one question to determine that both chains are not in that child.
2. For the first child that we know contains a chain, we don't "waste" a question. This question is included in that child's question count.

With observation $1$, we are basically figuring out the first chain's endpoint for free. There are no wasted questions, as all wasted questions will be counted for the second chain. With observation $2$, we have that adding $i$ wasted questions is no longer correct. We only waste $i - 1$ questions for the $i^\text{th}$ child, as one of the processed children contains the first chain (and thus doesn't waste a question).

Thus, for the root, our formula is:

 $ans = \max\{dp[c_j] + dp[c_i] + i - 1\} \,\, \forall \,\, 0 \le j < i < |c|$, where the $dp$ values are sorted in non-increasing order, and $c$ is the children of $f$. Note that this formula has an $\mathcal{O}(n^2)$ worst case for a star graph, so we will need to optimize it.

Our optimized formula is:

 $ans = dp[c_0] + \max\{dp[c_i] + i - 1\} \,\, \forall \,\, 1 \le i < |c|$, where the $dp$ values are sorted in non-increasing order, and $c$ is the children of $f$.

Once again, with a similar analysis as what was done for the $dp$ computation, the case that one (or both) chains have a zero length will never be the worst case, and so we can ignore it for the dynamic programming. However, the case must still be handled during interaction.

Recall that the above was for a fixed $f$. To find the maximum for all $f$, we can perform a tree walk. When transitioning from one root to an adjacent root, use a prefix and suffix max array to compute $\max{dp[c_i] + i}$, ignoring the $c_i$ that is the new root. Both max arrays should store $dp[c_i] + i$, not $dp[c_i]$. Remember to subtract $1$ from the suffix array values, as there is one less wasted question.

——————————————————

Interacting

If you understood the initial dynamic programming computation for determining the theoretical maximum, the interaction should be relatively straightforward, and so we will leave it as an exercise for the reader. Be careful when handling the special cases that were ignored during the dynamic programming.

——————————————————

The final time complexity is $\mathcal{O}(n \log n)$ and memory complexity is $\mathcal{O}(n)$.

 **Solution**[119400928](https://codeforces.com/contest/1534/submission/119400928 "Submission 119400928 by Dormi")

