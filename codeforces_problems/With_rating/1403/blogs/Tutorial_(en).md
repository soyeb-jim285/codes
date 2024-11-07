# Tutorial_(en)

We hope you enjoyed the whole problemset even though there were some technical difficulties.

 **Problem A**Problem author: [Emarci15](https://codeforces.com/profile/Emarci15 "Candidate Master Emarci15") 

### [1403A - The Potion of Great Power](../problems/A._The_Potion_of_Great_Power.md "Central-European Olympiad in Informatics, CEOI 2020, Day 2 (IOI, Unofficial Mirror Contest, Unrated)")

We denote the maximum number of edges in the graph by $M$. You can see that $U$ is an upper bound for it.

Subtask 2

$Q, U \leq 1000$

We can store each operation, and replay them for each question. We can store all edges in a data structure, or keep neighbours in separate data structures for each node.

When answering a question, find the neighbours of both nodes, and consider the distance of each pair of neighbours, computing the minimum. This yields to a simple solution in $O(QUD + QD^2)$ time, or $O(QU\log(D) + QD^2)$ when using an associative container, like std::set.

Ordering Trick

Although not required for this subtask, we can improve the second part by ordering the neighbour lists by $H$ value, and stepping through them simultaneously, using two pointers. We always step in the list in which the pointer points to the entry with the smaller $H$ value out of the two, and consider the current pair for the minimum computation: 


```cpp
p1 = 0, p2 = 0  
while (p1 < l1.length) and (p2 < l2.length)  
	consider(H[l1[p1]], H[l2[p2]])  
	if (H[l1[p1]] <= H[l2[p2]])  
		then p1++  
		else p2++  

```
The correctness of this is easy to prove.

Subtask 3

$V=U$ for all queries

In this case, each question will refer to the same version (the final one). Hence, we can just apply all updates at the start once (applying updates is done in the same way as in Subtask 2), and then answer questions on this single version (like before). Using an efficient data structure and the ordering trick (we can actually pre-sort, before answering any questions), we can solve this subtask in $O(U\log(D) + M\log(D) + Q D \log(D))$.

Subtask 4

$H[i] \in \{0,1\}$ for all nodes $i$

For a node $u$ and version $V$, we need to be able to tell whether $u$ had a neighbour $u'$ with $H[u'] = f$ for both possible values of $f$ ($0$ or $1$). Once we have obtained this information for both $X$ and $Y$, we can easily work out the answer.

For each node $u$ and possible $f$ value, let us build an ordered list of 'events' of the following types: 

* Node $u$ stopped having any neighbours $u'$ with $H[u'] = f$ in version $V$.
* Node $u$ started having neighbours with $H[u'] = f$ in version $V$.

 These lists can be built in $O(U\log(M))$ time by iterating through all updates (once), and keeping track of the number of neighbours $u'$ with each $f$ value for each node (the logarithmic factor comes in from keeping track of which edges are active). Once built, we can binary search for the last event (or the parity of the number of events) for both $X$ and $Y$, for both $f=0$ and $f=1$ to get all the necessary information to answer the queries.This yields a solution in $O(U\log(M) + Q\log(U))$ time and $O(U)$ space for this special case.

Subtask 5

$U,N \leq 10000$

$\sqrt{U}$ checkpoints

We first apply all updates in order, producing $\sqrt{U}$ checkpoints, evenly spaced, then – for each question – we simulate updates from the closest checkpoint (in the same way as we did for Subtask 1). An efficient implementation of this can achieve $O(U\log(M) + \sqrt{U} M + Q \sqrt{U} \log(M) + Q D \log(D))$ time and $O(\sqrt{U}M)$ memory.

Save neighbour list by node, binary search by version

Another solution is to separate updates by node, and save the neighbour list of the updated node for each update (in a vector of neighbour lists for that node). Then, we can binary search for the neighbour list at version $V$. This can be implemented in $O(UD + Q \log(U) + QD)$ time and $O(UD)$ space.

Self-copying data structures

We can use a self-copying (also known as persistent or copy-on-write) data structure. These data structures are constructed as a (directed) tree, where each node holds some information. When updates are applied, we copy every node that was modified, including nodes whose children are modified, thus each version will have its own root node, from which queries can be performed. There are multiple possibilities here from static binary trees (holding neighbour lists, or neighbours directly) to balanced binary search trees (e.g. treap). These will solve this subtask, but will struggle to gain full marks for the problem due to exceeding memory constraints: the static versions have a high complexity ($O(ND + U\log(ND))$ space, or worse), and the BST version has very high constants (both in space and time).

One segment tree

We need to find when each edge is present in the graph. For each edge, this is the union of contiguous intervals. In total, we have at most $U$ intervals.

Take a segment tree of length $U$, with one leaf per version. Each node will contain a vector of edges, ordered by starting node (edge $e$ is stored in the tree node for $[a,b]$, if edge is present in each version during the interval $[a,b]$ – and not entirely present in the parent's interval). This has a combined space requirement of $O(U\log(U))$. For each question, we look up edges starting from $X$ and $Y$ using binary search in the vector of each of the $\log U$ relevant tree nodes.

This can be implemented in $O(U\log^2(U) + Q\log^2(U) + QD\log(D))$ time and $O(U\log U)$ space. With a few tricks and an efficient implementation, this solution could possibly pass subtask 6.

Subtask 6

No additional constraints

Save neighbour list by node, reduce storage space by constant factor

Clearly, saving each version of the neighbour lists of each node will not fit in memory for these limits. However, since memory limits are very generous, we can cut this down by a reasonably small constant $C$: we only save the neighbour list of node $u$ after every $C$'th update that affects $u$. We also save an ordered list of updates affecting each node. For each question, we only need to replay at most $2C$ updates ($C$ for $X$ and $C$ for $Y$). Choosing $C\approx 50$ will suffice the pass every subtask. The time complexity is $O(U\log D + \frac{UD}{C} + Q(D+C\log C))$, using $O(\frac{UD}{C})$ memory.

We think this solution is interesting in the sense that it demonstrates how big-$O$ complexity can often be misleading for real-world problems: this solution is far simpler than other solutions, some of which do not even gain $100$ marks, and it passes the limits because the constants involved (normally hidden by big-$O$ complexity classes) are far smaller.

Multiple segment trees

We can eliminate the binary search from the previous segment tree solution, by keeping a separate segment tree for each node. Na"ively, this will not fit in the memory limits. However, we can save space by only keeping a leaf for each update where the given node was affected. This yields a solution in $O(U\log(U) + Q\log(U) + QD\log(D))$ time and $O(U\log(U))$ space.

 **Problem B**Problem author: [busamate](https://codeforces.com/profile/busamate "Master busamate") 

### [1403B - Spring cleaning](../problems/B._Spring_cleaning.md "Central-European Olympiad in Informatics, CEOI 2020, Day 2 (IOI, Unofficial Mirror Contest, Unrated)")

Cleanable tree

It is obvious that a tree is not cleanable if it has an odd number of leaves. Also, every tree with an even number of leaves is cleanable.

Subtask 2

$Q = 1$, there is an edge between node $1$ and $i$ for every $i$ $(2 \leq i \leq N)$ Flóra can't add extra leaf to node $1$

If we add 2 extra leaves to an inner node (not a leaf), it's a good strategy to clean the path between these extra leaves. So if we add an even number of extra leaves to an inner node, we can pair all these extra leaves. Otherwise there is an extra leaf without a pair. This leaf will be added to the tree. A similar thing happens if we add leaves to an original leaf. In this subtask we know that every path cleaning will go throw through node $1$ (except those that we already paired). So we just have to add the distances from node $1$.

This subtask can be solved in $O(N + D_1)$

Subtask 3

$Q$ = 1, there is an edge between nodes $i$ and $i+1$ for all $i$ $(1 \leq i < N)$ Flóra can't add extra leaf to node $1$ nor node $N$

It's a good idea to clean the path between node 1 and node N. After this we should just simply pair the extra leaves in an optimal way.

This subtask can be solved in $O(N+sum(D_i))$

Even-odd nodes

It can be proved that in the optimal solution, all edges are cleaned at most twice.

 So our task is to minimize the number of edges cleaned twice. Let's root the tree in an inner node $r$ (It's possible since $N>2$). We denote the parent of a node $u$ by $P(u)$ in this rooted tree. Let's call a node $u$ even if in it's subtree there are even number of leaves. Call it odd otherwise (all leaves are odd nodes). It can be proved that we clean the edge from $u$ to $P(u)$ twice iff $u$ is an even node (where $u \ne r$). Let $E$ be the set of even nodes. In this case, the minimum required cost for the original tree is $N + |E| - 2$ if $r$ is an even node. We can compute which nodes are even in $O(N)$ time with a single dfs.

Subtask 4

$N \leq 20000$, $Q \leq 300$

We can build up every tree variation and calculate the number of even nodes for it.

 This subtask can be solved in $O(N\cdot Q + sum(D_i))$

Path to the root

For every node $u$ let's denote its distance from the root $r$ by $D(u)$. Let $S(u)$ denote the number of even nodes on the path from $u$ to $r$. This means that the number of odd nodes on the path from $u$ to $r$ is $D(u)+1-S(u)$. The previous values can be computed in $O(N)$ time for the original tree using a single dfs.

Subtask 5

The original tree is a perfect binary tree rooted at node $1$

 In this case $D(u) <= logN$ for every $u$. When adding a leaf to node $u$, we change all parities from $u$ to $r$, which takes at most $O(logN)$ time.

This subtask can be solved in $O(N + sum(D_I) \cdot logN)$.

Subtask 6

$D_i = 1$

 We calculate the minimum required cost for the original tree in $O(N)$.

If we add an extra leaf to an original leaf the cleaning cost increases by 1, but nothing else happens. If we add an extra leaf to an inner node $u$, then every node on the path from $u$ to $r$ will change parity. So the answer is $N + |E| - S(u) + (D(u) - S(u))$ if $r$ was and odd node in the original tree.

This subtask can be solved in $O(N + Q)$

Subtask 7

Original constraints.

 Virtual tree approach

Adding an extra leaf to node $u$ may cause parity change on the path from $u$ to $r$. If we add an extra leaf to node $v$ too then the parities from node $LCA(u,v)$ (LCA=lowest common ancestor) to $r$ will change twice, i.e. it doesn't change at all. If we add more leaves then there will be paths where the parity has changed odd times and where it has changed even times. If we added a new leaf to a node $u$ let's call it a critical node. Let's define $L$ as a subset of original nodes where: If we add a node to node $u$, then $u \in L$. If $u,v \in L$ then $LCA(u,v) \in L$ too. It can be proved that $|L| \leq min(N,2\cdot D_i - 1)$ for the $i$th variation. We can form a new tree from the nodes of $L$ in the following way: In this tree, the parent of node $u \in L$ is node $v \in L$ if $v$ is an ancestor of $u$ in the original tree and $D(v)$ is maximal. Let's denote the parent of node $u$ in the new tree by $P_{L}(u)$. In the new tree, for all nodes $u$ we calculate the number of critical nodes in the subtree rooted in $u$. (This can be computed in $O(|L|)$ using a single dfs.) If this number is even then nothing happens. If it's odd, the parity from node $u$ to $P_{L}(u)$ will change in the original tree (but will not change in $P_{L}(u)$. We can say that the parity has changed from $u$ to $r$, and then from $P_{L}(u)$ to $r$. These can be handled by using $S(u)$ and $S(P_{L}(u))$ the same way we described in subtask 5.

Note that we don't have to know the $i+1$th variation before answering the $i$th one. So this solution can solve this problem "online".

This subtask can be solved in $O((N + sum(D_i))logN)$.

We remark that the problem can also be solved by utilizing the Heavy-Light Decomposition (HLD) of the original tree, this solution was also passing if the implementation was not too messy.

Dynamic offline solution

Instead of computing the value changes for every variation online, we can preread and store for each individual node which variations we add leaves to them. Then, using a dfs in a bottom-up DP manner, starting from the leaves for each node we pair the unpaired leaves in its subtree. We can store the unpaired leaves (only the variation's and parent node's identifiers are interesting for us) in some collections (e.g. set/map) and at each node, we merge the collections of all of its children. 

If we encounter two children having an unpaired leaf for the same variation, it means the current node is the LCA for those two additions, and we can compute the change in the cost of cleaning for that variation and store it.

In order to maintain low complexity (i.e. logarithmic in terms of sums of $D_i$, we must make sure to not copy any collections needlessly, and always insert the elements of the smaller into the bigger one.

After computing the cost changes for all variations simultaneously by a single dfs, we can contruct the answer for each variation by checking if it has any unpaired leaves in the final collection, and adding the cost change to the basic cleaning cost of the original tree.

HLD approach

The main idea is that we can calculate $|E|$ directly with heavy-light decomposition.

First root the tree arbitrarily. Then, we need a segment tree that counts the amount of even numbers in a range with lazy range increases. After this, do hld on the input tree ith the inner data structure being the aforementioned segment tree. Then, for every leaf $l$ we increase every edge by $1$ on the path from $l$ up to the root. Now, without any variations we know $|E|$, but it's also clear that for the $i$th variaton we will only do $O(D_i)$ queries on the hld, if we attach the nodes one by one there are two cases: 

* currently we attach a node to a leaf, then that leaf will no longer be a leaf, but attaching a new leaf to it basically cancels this effect so we don't need to do anything.
* we are not attaching to a leaf, then we can simply do the same increasing stuff we did.

 Obviously we can also easily cancel the modifications to this data structure also with $O(D_i)$ hld queries. So we have solved the problem online with a time complexity of $O(N \log^2N + \sum_i D_i \log^2 N)$. **Problem C**Problem author: [birka0](https://codeforces.com/profile/birka0 "Candidate Master birka0") 

### [1403C - Chess Rush](../problems/C._Chess_Rush.md "Central-European Olympiad in Informatics, CEOI 2020, Day 2 (IOI, Unofficial Mirror Contest, Unrated)")

Pawns, Rooks and Queens

If $c_1=c_R$ then there is a unique shortest path, which takes $1$ step for the rook and the queen, and $R-1$ steps for the pawn. Otherwise, it is impossible getting to the exit square for the pawn, and it takes exactly $2$ steps for both the queen and the rook. It is also obvious that the latter can always do it in two different ways.

Therefore, we only have to be careful about enumerating the number of ways to do the required $2$ steps for the queen. She always has the same two paths as the rook available, plus we need to take into account all the options involving one or two diagonal moves. For these, we have to check if any path is blocked by the edges Chess Land, and also note that two diagonal moves are only possible if $1+c_1$ and $R+c_R$ have the same parity.

Bishops

First note that the bishop can reach its destination iff $1+c_1$ and $R+c_R$ have the same parity, otherwise the answer is $0$. For a small number of rows, a carefully implemented bruteforce evaluation can also solve the problem, but if $R$ is large, we need to be more thorough. It is useful to note that we can count the number of steps and paths separately for the cases when the bishops leaves the first row using the left diagonal and the right diagonal, and in the end, if one is shorter than the other then choose that one, and if they take the same number of steps, just sum them to get the answer.

Now, for a given starting direction, we can use a combinatorial argument to find the answer. First, imagine that we move forward in a greedy manner, bouncing between the left and right edges of Chess Land until we reach the last row in some impact column $c_I$. This way, we can jump $C-1$ rows forward before hitting a wall and having to move again, except the first and last moves, which are easy to handle. This gives us an initial guess for the number of steps. It is relatively easy to see that if $c_I=c_R$ then this shortest path is unique and the previously computed length is correct. Otherwise, there are two cases depending on how we arrive at the last row: for example, if we reach the last row while moving from left to right, and the target square is further to the right of $c_I$ (i.e. $c_I<c_R$), then the previous step length is once again correct, as we could have chosen to not go all the way to the edges in one or more previous step, which would increase the vaule of $c_I$ so we ensure $c_I=c_R$. However, if we reach the last row while moving from left to right, and the target square is to the left of $c_I$ (i.e. $c_R<c_I$ and we effectively "jump over" the requred destination), then we need to include one additional step into our path somewhere along the way in order to ensure $c_I=c_R$.

This way, we obtain the number $n$ of required steps, and the number $f$ of diagonal movements we can spare by stopping before hitting an edge, and we need to distribute them arbitrarily over $n-1$ steps, as we cannot stop during the last step. This is equivalent to the well-known combinatorial problem of distributing $f$ balls into $n-1$ boxes, but is also relatively easy to figure out that it is the combination $$ \binom{f+n-2}{f}. $$

Regarding the implementation of the solution, one has to be very careful about handling corner cases such as starting from the first or last column or arriving there, the direction of arrival and so. Note that in the formula above, $n-2$ can be $O(R/C)$ large which makes the evaluation a bit tricky when $C$ is small: notice that $$ \binom{f+n-2}{f} = \frac{(f+n-2)!}{f! (n-2)!} = \frac{(f+n-2)(f+n-3)\cdots (n-1)}{f!}, $$ which only has $O(f)$ terms and $f<C$, so we can answer all queries with $O(QC)$ time complexity. 

We remark that alternately, the answers to all possible queries could be precomputed in $O(C^2)$ time, using the fact that while cycling through all the possible values of $c_R$ for a fixed $c_1$, the values $n$ and $f$ can change by at most $2$, making it possible to adjust the answer in constant time, but this is much more difficult to implement and was not required to pass.

Kings

It is easy to see that the king has to make exactly $R-1$ bottom-up moves, and if $|c_R-c_1|\leq R-1$, we need to advance one row in each step in order to have a shortest path. The other case, when $|c_R-c_1| > R-1$ means we need to advance one column towards the destination each step and have some free maneuverability between rows, can be solved seperately in a similar manner as the easiest case of the bottom-up problem, since this can only occur when $R<C$.

From now on, we assume $R\geq C$, so the king moves one row forward in each step and takes $R-1$ steps total, so we just need to count the number of paths. First, we observe that the number of ways we can reach the $j$-th column of a row is initially ways[c1]=1 and otherwise ways[j]=0 for the first row, and for any further row can be computed dynamically as 

 next_ways[j] = ways[j - 1]+ ways[j] + ways[j + 1], where $j=1,\ldots,C$.  We can repeat this step for every row and then return the $c_R$-th entry, however this will take $O(RC)$ time per query.Next, we have to notice that with the same technique, we can precompute and store the answer for every $(c_1,c_R)$ pair, and answer each query in $O(1)$ time after, by adding another dimension to our dynamic programming: let DP[i][j] denote the number of ways to go from the $i$-th column of the first row to the $j$-th column of some current row, so initially we have DP[i][i] = 1 and every other entry is 0. Now we just repeat 

 next_DP[i][j] = DP[i][j - 1]+ DP[i][j] + DP[i][j + 1]  for all $i,j=1,\ldots,C$ indices $R-1$ times to get all the answer for the $R$-th row. This precomputation has the time complexity $O(RC^2)$.Our next observation is to notice that at each iteration, instead of advancing a sinle row $r\to r+1$, we can choose to compute the answer for $r\to 2r-1$ instead. Indeed, our current DP array stores all the numbers of ways to get from the columns of the first row to the columns of the $r$-th row, or in other words, to advance $r$ rows forward. So if we want to count the number of ways to get from the $i$-th column of the first row to the $j$-th column of the $2r-1$-st row, we can enumerate all the possible paths going through the intermediate $k$-th column of the $r$-th row ($k=1,\ldots,C$) by the formula 

 double_DP[i][j] = $\displaystyle\sum_{k=1}^C$ DP[i][k] $\cdot$ DP[k][j].  Combining the two DP formulas, we can precompute the answer for the $R$-th row based on the binary representation of $R$. Since the last formula takes $O(C^3)$ time to evaluate for all $(i,j)$ pairs, the total time complexity is $O(C^3 \log R)$.Notice that the cost of advancing a single row was $O(C^2)$, so if we could somehow speed up the computation of $r\to 2r-1$ advancements too, then generating all answers for the king could be done in $O(C^2 \log R)$ time. There are multiple ways to do this step, but they all can be a bit tricky to find, so implementing a previous, less efficient approach and studying some of its outputs for small $C$ and different $R$ values could be very useful to figure out the main ideas and guess how a solution works.

First, the entries of double_DP[i][1], i.e. going from any column of the first row to a fixed column $j=0$, can be computed in $O(C^2)$ time, and since reversing the paths from the $i$-th to the $j$-th column gives exactly the paths from the $j$-th to the $i$-th column, double_DP[i][j] is symmetric and we obtain every double_DP[1][j] entry immediately. 

Now suppose $1<i<j<C/2$ holds. The key observation is that we don't have to use the values of DP anymore, as the paths going from the $i$-th to the $j$-th column are almost the same as the paths going from the $i-1$-st column to the $j-1$-st column, shifted by a single column to the right. In fact, the relation 

 double_DP[i][j] = double_DP[i-1][j-1] + double_DP[1][1+i+j]  holds, which we can use to compute missing entries based on the only single column we have evaluated beforehand. For other indices, we can use symmetry properties and even the similar relation  double_DP[i][j] = double_DP[i+1][j-1] + double_DP[1][1+i-j],  for the cases where $1<j<C/2$ but $j\leq i\leq C$. We can verify these formulas by mathematical induction over the rows, but there are other, more beautiful combinatorial arguments to derive them, which we are omitting for the sake of brevity, but nonetheless encourage the interested reader to try and figure them out for his/her own pleasure.