# Tutorial_(en)

I hope you enjoyed the contest!

[1615A - Closing The Gap](../problems/A._Closing_The_Gap.md "Codeforces Global Round 18")

Author: [PurpleCrayon](https://codeforces.com/profile/PurpleCrayon "International Master PurpleCrayon")

 **Tutorial**
### [1615A - Closing The Gap](../problems/A._Closing_The_Gap.md "Codeforces Global Round 18")

If max(a)−min(a) is strictly greater than 1, you can apply the operation on the max and the min respectively, which brings them both closer to each other. In other words, it either decreases max(a)−min(a) or leaves it the same. This implies that the answer is always ≤1. Now what remains is determining whether the answer is 0 or 1. The answer can only be 0 if the sum of the array is divisible by n, as the sum of the array can't change after an operation, and if it's not divisible by n you can't make every element equal. This means that the answer is 0 if the sum is divisible by n, and 1 otherwise.

[1615B - And It's Non-Zero](../problems/B._And_It's_Non-Zero.md "Codeforces Global Round 18")

Author: [PurpleCrayon](https://codeforces.com/profile/PurpleCrayon "International Master PurpleCrayon")

 **Tutorial**
### [1615B - And It's Non-Zero](../problems/B._And_It's_Non-Zero.md "Codeforces Global Round 18")

Let's solve the complement problem: find the largest subsequence of the array such that their bitwise AND is non-zero. Let x be the bitwise and of the optimal subsequence. Since x≠0, at least one bit must be set in x. Let's iterate over that bit, call it b, and in each iteration, calculate the largest subsequence whose bitwise and has that bit set. For the b-th bit to be set in the final answer, every element in the chosen subsequence must have that bit set. Since choosing every element with the b-th bit on is a valid subsequence, this implies that the answer for the b-th bit is the number of elements that have the b-th bit set. Thus, the answer to the final problem is n−max1≤b≤30cntb, where cntb is the number of elements who have the b-th bit set.

Note: it doesn't matter if the final answer contains more than one set bit, it's still covered in at least one of the cases, and the bitwise and will still be non-zero. 

All that remains is counting the number of elements in the range [l…r] with the b-th bit set, for all b. This can be done with precomputation, by creating b prefix sum arrays before answering any of the test cases, where the i-th element of the b-th array is the number of integers ≤i that have the b-th bit on. After this, you can use the prefix sum technique to answer queries, as cntb=ab,r−ab,l, if ab is the b-th array. 

Challenge: solve the problem with 1≤l≤r≤109.

[1615C - Menorah](../problems/C._Menorah.md "Codeforces Global Round 18")

Author: [Monogon](https://codeforces.com/profile/Monogon "Grandmaster Monogon")

 **Tutorial**
### [1615C - Menorah](../problems/C._Menorah.md "Codeforces Global Round 18")

First, let's define the "type" of a candle i to be the string aibi. For example, if a candle is currently unlit and must be lit in the end, its type is 01. It's useful to think about the number of candles of each type because the position of a candle is irrelevant in this problem.

Now, let's consider what happens when we do two operations consecutively. All candles except the ones we select will flip twice, so let's focus on what happens to the candles we select. If we select the same candle twice, nothing changes. And if we select two different candles, it's equivalent to swapping a 1 and a 0 in the string.

Since we have a really nice description of two consecutive operations, any sequence of an even number of operations is just a sequence of swaps. So it's possible in an even number of operations as long as the number of 1's in both strings is the same, and the minimum number of operations will be the number of positions where the strings differ.

Now, what about an odd number of operations? Well, it's the same as performing one operation and then reducing it to the case of an even number of operations. There are two types of candles we can select on the first operation: type 10 and type 11. Simply try both options if they're present, and find the minimum number of operations after it's reduced to the even case.

Finally, there are some strings where it's possible to do in either an even or an odd number of operations, so in those cases we have to take the minimum of both options. The total complexity is O(n).

Bonus: Can you prove that in the case of an odd number of operations, it is never necessary to select a candle of type 10?

[1615D - X(or)-mas Tree](../problems/D._X(or)-mas_Tree.md "Codeforces Global Round 18")

Author: [PurpleCrayon](https://codeforces.com/profile/PurpleCrayon "International Master PurpleCrayon")

 **Tutorial**
### [1615D - X(or)-mas Tree](../problems/D._X(or)-mas_Tree.md "Codeforces Global Round 18")

Let count(x) be the number of 1-bits in an integer x. Notice that count(x⊕y)mod2 = count(x)mod2⊕count(y)mod2. This means that you can replace each integer x on the tree with count(x)mod2. Note that you can pretend the initial given edges are also just elves who traveled over the path consisting solely of that edge. After this transformation, each of the edge weights is either 0 or 1, and you're given a set of paths and you are told the XOR of each path.

Root the tree at node 1. Let ri be the XOR of the values on the edges from node i to the root (r1=0). Notice that the XOR of a path (a,b) is ra⊕rb. From this, each constraint of the form (a,b,c) telling you that the XOR of the path (a,b) has to equal c is equivalent to ra⊕rb=c. 

This problem can be solved using a variant of bipartite coloring, where you create a graph and add a bidirectional edge between (a,b) with weight c for each of those constraints. You run dfs through each of the individual connected components. Within a component, choosing the value of a single node uniquely determines the rest. During the dfs, if you're at a node a and are considering traversing the edge (a,b,c), you know that rb=ra⊕c, so you can determine rb from ra.

The final value of an edge between a and p (the parent of a) is ra⊕rp.

[1615E - Purple Crayon](../problems/E._Purple_Crayon.md "Codeforces Global Round 18")

Author: [PurpleCrayon](https://codeforces.com/profile/PurpleCrayon "International Master PurpleCrayon")

 **Tutorial**
### [1615E - Purple Crayon](../problems/E._Purple_Crayon.md "Codeforces Global Round 18")

After expanding the expression given in the statement (by replacing w with n−r−b), it reduces to r⋅(n−r)−b⋅(n−b). This means that in Blue's turn, his only goal is to maximize b⋅(n−b). To maximize the value of that function, it's optimal to pick the value of b that is closest to ⌊n2⌋.

One thing to note is that if it's possible for Blue to color exactly x nodes, for some number x, it is possible for Blue to color exactly x−1 nodes as well. This is because, given some subtree that he has colored, he can also choose to color every node in the subtree except the root. This would reduce the number of Blue nodes by exactly 1. By repeating this process, one can show that if Blue can color exactly x nodes, Blue can also color y nodes if y≤x.

What this implies is that if you know the number of nodes that Red colors, Red's optimal strategy would be to minimize the maximum number of nodes that Blue can color (as it reduces the possible choices that Blue has). If Red chooses node x, it means that Blue can't choose any ancestors (or descendants) of node x. This transforms the problem into the following:

For all i≤k, perform the following operation exactly i times: choose a node v and mark all of the nodes on the path to the root. For each i, calculate the maximum number of nodes that are marked at least once at the end of this process by optimally choosing v at each step. The set of optimally chosen v (for a given i) can be found using the following greedy algorithm:

* Sort all nodes in decreasing order of depth.
* Then, go through the nodes in order, let the current node be v. Go to the root marking nodes until you reach one that has already been marked. Let the number of marked nodes be cv.
* Finally, sort all nodes in decreasing order of cv. Choose the first i nodes from this list.

Proof that the greedy produces the correct answer: We must prove that the greedy algorithm always chooses a subset of nodes that maximizes the number of marked nodes at the end of the process. We can imagine that instead of coloring nodes, we can delete them from the tree to get a forest of rooted trees. Let's prove that there is an optimal solution where the deepest leaf in a forest (say v) is chosen. Consider a configuration in which v is not chosen. Let u be the node that maximizes the depth of LCA(u, v) that is present in the configuration. You can replace the node u with v in the configuration, and the answer won't decrease (as the depth of v is greater than the depth of u). Since the relative order of depths in a tree in the forest at any point is the same as the relative order of depths of its vertices in the original tree, choosing the deepest node in a tree in the forest is equivalent to choosing the vertex in that tree, which has the max depth in the original tree.

Note that the process can be simulated in amortized linear time (not including the sorting), as each node will be colored at most once. All that's left is to iterate over all values of i, and take the maximum value that Red can get.

[1615F - LEGOndary Grandmaster](../problems/F._LEGOndary_Grandmaster.md "Codeforces Global Round 18")

Author: [PurpleCrayon](https://codeforces.com/profile/PurpleCrayon "International Master PurpleCrayon")

 **Tutorial**
### [1615F - LEGOndary Grandmaster](../problems/F._LEGOndary_Grandmaster.md "Codeforces Global Round 18")

First, let's consider a fixed pair of strings s and t, and find a simple way to calculate the amount of time it takes.

Key observation: Flip every bit at an even position in both strings s and t. Now, the operation is equivalent to swapping two adjacent bits of s. This is because the operation is equivalent to flipping two adjacent bits and swapping them. Flipping bits on an even position takes care of the first part of the operation (as any operation includes one bit at an even and one bit at an odd position), so the problem reduces to simple swapping.

Now, for a fixed pair of strings, you want to find the minimum number of swaps to transform one into the other. Obviously, the answer is 0 if the number of 1's in both strings is different. Now, let the number of 1's in each string be k, and the position of the i-th 1 from the left in s be xi, and the i-th 1 from the left in t be yi. The answer for a fixed pair of strings is k∑i=1|xi−yi|, as the i-th 1 in s will always be matched with the i-th 1 in t.

This expression can be transformed into a more convenient one. Let ai be the number of 1's in s in the prefix ending at i, and bi the number of 1's in t in the prefix ending at i. The previous expression is equivalent to n∑i=1|ai−bi|. This is because the i-th index contributes 1 to each 1 in the previous expression if and only if a 1 needs to "cross" the i-th index when moving to it's corresponding location in t. Exactly |ai−bi| 1's will cross over the index, so the answer is the sum over all of the values.

Now going back to the original problem, apply the initial transformation on the strings s and t, where for each even index, you change 0 to 1, 1 to 0, and keep ? the same. Let pi,j be the number of ways, if you only consider indices ≤i, to replace the ?'s with 0's and 1's so that ai−bi=j. si,j is defined similarly, except you only consider indices ≥i. Both of these have O(n2) states and O(1) transitions. The final answer is n−1∑i=1n∑j=−n| j⋅pi,j⋅si+1,−j |.

[1615G - Maximum Adjacent Pairs](../problems/G._Maximum_Adjacent_Pairs.md "Codeforces Global Round 18")

Author: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1615G - Maximum Adjacent Pairs](../problems/G._Maximum_Adjacent_Pairs.md "Codeforces Global Round 18")

Let's consider each segment of zeroes in our sequence. Each of these segments has either odd or even length.

If a segment has length 2m+1 (it is odd), then it can be used to create m pairs of neighboring elements, and an additional pair for either the number right before the segment, or for the number right after the segment.

If a segment has length 2m (it is even), then it can be used either to create m pairs of neighboring elements, or m−1 pairs of any integers and two additional pairs for the elements that are on the borders of the segment. It's never optimal to match only one of the zeroes in an even segment with the element on the border, because we could just use the segment to create m pairs instead.

Let's build an undirected graph which initially has m=nmaxi=1ai vertices (one for each integer from 1 to m). Let's add the following edges and vertices to it:

* For each integer already having a pair of adjacent elements, add an auxiliary vertex and connect it with the vertex representing the integer.
* For each 0-segment of even length, add an edge between vertices representing elements on the borders of this segment (we need at most one of these for each pair of elements on the border).
* For each 0-segment of odd length, add an auxiliary vertex and connect it with vertices representing elements on the borders of this segment (we need at most two of these for each pair of elements on the border).

Let's find the maximum matching in this graph using some maximum matching algorithm (for example, Edmonds' blossom algorithm). Let the size of the maximum matching be M. It can be shown that the sum of M and all values ⌊len2⌋ over all 0-segments (where len is the length of the segment) is equal to the maximum number of integers that can have a pair of neighboring elements: for each segment of even length, the edge representing it will either be in the matching (and the segment will create len2+1 pairs), or the edge won't belong to the matching (and the segment will create len2 pairs). For each odd 0-segment, we either match its vertex with a number on its border (so this segment creates len−12+1 pairs), or won't match its vertex (so this segment creates len−12 pairs). The numbers already having a pair of neighboring elements will be processed by the vertices connected only to them, so they get +1 to the size of the matching "for free" and can't be matched with anything else (or will be matched, but won't add +1 for free). The maximum matching can enforce the constraint that each number is counted in the answer only once.

How fast will this solution work? Unfortunately, it can be too slow. The resulting graph can have up to O(n) edges and up to 6002 vertices, so the standard implementation of Edmonds is not sufficient. But there are many different heuristics you can use in this problem to speed up the solution. We used the following one:

Split all vertices into two "parts", the first part will contain the vertices representing the numbers, and the second part will contain all of the other vertices. The edges can connect only vertices from the first part and the vertices from different parts, and there are only up to 600 vertices in the first part.

Let's ignore the edges between the vertices in the first part and find the maximum matching in this graph using Kuhn's algorithm. Then, we claim that if we find the maximum general matching starting from this bipartite matching and improving it, the augmenting paths cannot both start and end in the vertices of the second part (since the number of matched vertices in the second part cannot exceed the maximum bipartite matching). Then we can search for augmenting paths only starting in vertices of the first part in Edmonds (so we need only 600 phases of Edmonds).

Furthermore, we can speed up each phase of Edmonds as follows: if the current size of the matching is M, then we'll visit no more than 2M+2 vertices while searching for an augmenting path; and if we contract each blossom in linear time of its size, each phase will work in O(M2), where M is the current size of the matching (and it cannot me greater than 600).

[1615H - Reindeer Games](../problems/H._Reindeer_Games.md "Codeforces Global Round 18")

Author: [Monogon](https://codeforces.com/profile/Monogon "Grandmaster Monogon")

 **Tutorial**
### [1615H - Reindeer Games](../problems/H._Reindeer_Games.md "Codeforces Global Round 18")

Let's try to find a nice lower bound for the answer. Let's denote a requirement of two nodes u and v by a directed edge u→v. We can observe that if there are two nodes u and v such that there's a requirement u→v (or a path of requirements from u to v), then we will need to do at least au−av operations on these two nodes. So, if we can create a list of pairs (u1,v1),…,(uk,vk) with all distinct nodes such that there is a path from ui to vi for all i, then a lower bound of the answer is k∑i=1(aui−avi)

Our strategy will be to find the largest possible lower bound of this form, and then construct a solution with exactly that cost (which is therefore the optimal cost). To find an optimal set of pairs, we can set it up as a flow problem. Every directed edge u→v of the original graph will have infinite capacity and a cost of au−av. In addition, we will create two new nodes s and t. For each node u, add an edge s→u with capacity 1 and cost 0, and add an edge u→t with capacity 1 and cost 0.

Compute the maximum cost flow from s to t (the amount of flow doesn't need to be maximized). If there is any node u such that s→u and u→t both have flow, make them both have 0 flow, and this won't change the cost. The flow can be decomposed into paths with distinct endpoints in the original graph. The endpoints are distinct because each node u cannot have flow on both edges s→u and u→t. And the cost of a path beginning in u and ending in v will be au−av (intermediate nodes of the path cancel out when computing the cost). It's also easy to see that any set of pairs has a corresponding flow in the graph with the same cost. So, this flow gives us a way to compute a set of pairs with the maximum lower bound, just like we want.

Now, how do we construct the operations to perform? First, take the edges of the residual flow graph that are not at full capacity. Using only these edges, compute the longest path from s to every node in the graph (where length of a path is the sum of edge costs). Let's say the longest path from s to u is du.

Let's show that bu:=au+du satisfies all requirements. Every requirement u→v is present in the residual graph because it has infinite capacity. So we have that du+(au−av)≤dv, otherwise we could find a longer path from s to v. By moving av to the right side of this inequality, we get au+du≤av+dv, In other words, bu≤bv, meaning this requirement is satisfied.

Let's show that the total number of operations ∑u|bu−au| does not exceed the cost of the flow. It's sufficient to show that for each node u that isn't in one of the pairs, we have bu=au, and for each pair (ui,vi) we have that avi≤bvi=bui≤aui.

For the first part, suppose a node u is unpaired. If du>0, then there is a path from s to u with positive cost, and there is an edge from u to t of 0 cost because it's unpaired, so we've found an augmenting path in the flow graph that will increase the cost. This contradicts the fact that we found the maximum cost flow. On the other hand, if du<0, this contradicts the definition of du since there's an edge s→u of cost 0 which makes a longer path. Therefore, du=0 and bu=au+du=au, as desired.

For the second part, consider a pair (ui,vi). There is a path in the residual graph from vi to ui, so we have dvi+(avi−aui)≤dui. In other words, bvi≤bui. But we already had that bui≤bvi because all requirements are satisfied, therefore bui=bvi. It's impossible to have dvi<0 because there's a longer path with the direct edge s→vi which is present in the residual graph. It's impossible to have dui>0 because it would mean the edge ui→t creates an augmenting path with positive cost. Therefore, avi≤avi+dvi=bvi=bui=aui+dui≤aui, as desired.

In summary, the solution is to build a flow graph, compute the maximum cost flow (which is equivalent to minimum cost flow with all costs negated), and compute the distance values du to construct the solution. The flow can be computed with the potential method in O(nmlogn) time.

