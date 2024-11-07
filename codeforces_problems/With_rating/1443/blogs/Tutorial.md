# Tutorial


### [1443A - Kids Seating](../problems/A._Kids_Seating.md "Codeforces Round 681 (Div. 2, based on VK Cup 2019-2020 - Final)")

Note that this seating arrangement for children satisfies all conditions: $4n, 4n-2, 4n-4, \ldots, 2n+2$.

 
### [1443B - Saving the City](../problems/B._Saving_the_City.md "Codeforces Round 681 (Div. 2, based on VK Cup 2019-2020 - Final)")

Since the activation of any mine explodes the entire segment of mines, which it is, you can immediately replace the input string with an array of mine segments. We now have two operations. We can delete any segment by $a$ coins, or turn two adjacent segments $[l_1, r_1]$, $[l_2, r_2]$ ($r_1 < l_2$) into one segment for $b \cdot (l_2-r_1)$. That is, two segments can be deleted for a cost of $2 \cdot a$ or $a + b \cdot (l_2-r_1)$. This means that you need to merge two segments while $b \cdot (l_2-r_1) \le a$. You need to go through all adjacent segments and check this condition.

 
### [1443C - The Delivery Dilemma](../problems/C._The_Delivery_Dilemma.md "Codeforces Round 681 (Div. 2, based on VK Cup 2019-2020 - Final)")

If we order a courier with time $x$, then all couriers with time $y < x$ can also be ordered, since they do not change the answer (all couriers work in parallel). Therefore, you can sort the array, couriers always bring the prefix of the array, and Petya will go for the suffix. The time prefix is the maximum $b[i]$, and the suffix is the sum $a[i]$. Therefore, you need to calculate the suffix amounts and go through all the options.

 
### [1443D - Extreme Subtraction](https://codeforces.com/contest/1443/problem/D "Codeforces Round 681 (Div. 2, based on VK Cup 2019-2020 - Final)")

The problem sounds like this — check that there are increasing and decreasing arrays, the element-wise sum of which is equal to the given array.

This problem can be solved greedily. Let's maximize each element of the decreasing array (let's call this array $a$, and the increasing one $b$). Suppose initial array is $v$ and we have solved the problem on a prefix of length $i-1$. Then, for the element $a[i]$, $a[i] \le a[i - 1]$ and $v[i] - a[i] \ge b[i - 1]$ must be fulfilled. Rewriting the second inequality and combining with the first one, we get $a[i] \le min(a[i - 1], v[i] - b[i - 1])$. It is clear that taking $a[i] = min(a[i - 1], v[i] - b[i - 1])$ is best by construction.

 
### [1443E - Long Permutation](../problems/E._Long_Permutation.md "Codeforces Round 681 (Div. 2, based on VK Cup 2019-2020 - Final)")

Let's notice that most of the elements in the original permutation will not change during all queries. Since the maximum permutation number does not exceed $10^{10}$, only the last $15$ elements of the permutation will change.

Thus, after each query of the second type, you need to generate a permutation with the corresponding number.

To answer the query of the first type, you need to split the segment into two parts: we sum the part of the segment that fell in the last $15$ elements in a simple cycle and calculate the other part of the segment using the formula of an arithmetic progression.

 
### [1442B - Identify the Operations](https://codeforces.com/contest/1442/problem/B "Codeforces Round 681 (Div. 1, based on VK Cup 2019-2020 - Final)")

Consider element with index $i$ that has value $b_1$ in the array $a$ — $a_i$. There are three options:

* Both $a_{i-1}$ and $a_{i+1}$ are present in the array $b$. Then both of them should stay in the array $a$ after the first operation  — we will write them down later on. However, $a_i$ can only be added to the array b while removing one of the neighbors. We have reached a contradiction, so the answer is 0.
* One of the numbers $a_{i-1}$, $a_{i+1}$ is present in the array $b$, another is not. Then we have to remove the one that is not present in $b$ and continue solving the problem.
* Neither $a_{i-1}$ nor $a_{i+1}$ is present in $b$. $a_i$ is not present in any other place in $b$ (because all number in $b$ are unique), and $a_{i-1}$, $a_i$ and $a_{i+1}$ are indistinguishable by the following operations. Let us then remove any one of them (say, left) and "remove" all remaining tags. In this case, we can multiply answer by 2 and continue solving the problem.

Now we know that the answer is either 0 or a power of 2. To calculate the answer we only need to implement the above-mentioned algorithm. Let us store a set of available numbers in the array $a$, and a set of numbers that are yet to appear in the array $b$ to implement necessary checks. The solution will have $\mathcal{O}(n \log n)$ complexity (that can be optimized to $\mathcal{O}(n)$ with help of arrays and double-linked lists, but it was not necessary for this particular problem).

 
### [1442C - Graph Transpositions](https://codeforces.com/contest/1442/problem/C "Codeforces Round 681 (Div. 1, based on VK Cup 2019-2020 - Final)")

Consider a sequence of actions that moves the token from vertex $1$ to vertex $n$. Let us say it has $A$ token movements and $B$ graph transpositions. This sequence takes $A + 2^{B} - 1$ seconds.

Note that the optimal path does not visit any edge twice. That means we need to consider only paths with $A \le m$. Consider another sequence consisting of $A'$ token movements and $B'$ graph transpositions. Let $lm = \lceil\log_2 m\rceil$. Note the following. If $B < lm < B'$ then $A + 2^{B} - 1$ < $A' + 2^{B'} - 1$. This is true because the difference between $A$ and $A'$ does not exceed $m$ and $2^{B'} - 2^{B} > m$. This gives us the following: if there is any sequence of actions with $B < lm$ that moves the token from vertex $1$ to vertex $n$ then optimal path's $B$ is less than $lm$ too. Let us check this with the following algorithm, and if it is so, find the optimal sequence of actions.

We can now build a new graph that consists of $lm$ copies of the original graph: 

* Reverse all the edges in every even graph copy.
* For every vertex $u$ add new edge between $k$-th and $k+1$-th copies of vertex $u$ with weight $2^{k-1}$ for $k = 1 \ldots lm - 1$.

We can find optimal paths from the first copy of vertex $1$ to all the copies of vertex $n$ using Dijkstra algorithm. Shortest of these paths would correspond to the answer: movement along a copy of original edge denotes token movement; movement along a new edge denotes graph transposition.

If the algorithm found no paths, then the sequence of actions that moves the token to from vertex 1 to vertex $n$ consists of at least $lm + 1$ transpositions. Note that if $lm < B < B'$ then $A + 2^{B} - 1$ < $A' + 2^{B'} - 1$. It means that all sequences of actions can be compared using ordered vector $(B, A)$ lexicographically.

Let us build another graph consisting of $2$ copies of the original graph: 

* Reverse all the edges in the second copy of the graph.
* Assign $(0, 1)$ to weights of all of these edges.
* For every vertex $u$ add two new edges between copies of $u$: from the first to the second copy and back. Weights of both edges is $(1, 0)$.

Let us find optimal paths from the first copy of vertex $1$ to both copies of vertex $n$ using Dijkstra algorithm. Let $(B, A)$ be the length of the shortest one. New graph allows us to restore the optimal sequence of actions that moves the token from vertex $1$ to vertex $n$ that will take $A + 2^{B} - 1$ seconds.

 
### [1442D - Sum](https://codeforces.com/contest/1442/problem/D "Codeforces Round 681 (Div. 1, based on VK Cup 2019-2020 - Final)")

Straightforward dp solution, where $s(i, j)$ – max possible sum after $j$ operations on first $i$ arrays and transition in $O(k)$, has complexity of $O(nk^2)$ or precisely $O(k \cdot min(nk, \sum\limits_{i=1}^n t_i))$ and doesn't fit into the time limit.

Taking into account the fact that the arrays are sorted helps to optimize it.

Consider the optimal solution. Let's denote as $x_i$ number of operations on $i$-th array. Let's call the array partially removed if we applied at least one operation to that array, but the array is not yet empty.

Consider two partially removed arrays within the optimal solution and integers $p$ and $q$ where $0 < x_p < t_p$ and $0 < x_q < t_q$. Assume, without loss of generality, $a_{p, x_p+1} \le a_{q, x_q+1}$. Let $y = min(x_p, t_q - x_q) \ge 1$. If we replace $y$ operations on $p$-th array with $y$ operations on $q$-th array, total sum will increase by $\sum\limits_{i=1}^y a_{q, x_q + i} - \sum\limits_{i=1}^y a_{p, x_p + 1 - i} \ge y \cdot a_{q, x_q + 1} - y \cdot a_{p, x_p + 1} \ge 0$, but the number of partially removed arrays will lower by 1. We can repeat that substitution until we get a single partially removed array.

Now we need to identify the single partially removed array in the final solution. Every other array can either all be Vasya's pocket, or remain as is. We can solve the knapsack problem with $(n-1)$ items, with array sizes as weights and sum of array's elements as value. For each $0 \le w \le k$ we need to find $g(w)$ – max possible total value of items with total weight $w$. The only remaining step is to brute force the size of prefix, Vasya removed from the single partially removed array and combine it with $g(w)$.

Solving each knapsack problem independently results in $O(n^2k + \sum\limits_{i=1}^n t_i)$ complexity, but the similarities between the problems allows to optimize down to $O(kn\log n)$ using divide and conquer approach.

Let's split the items into two halves of approximately similar size. Before going in recursively into the first half we will relax dp values with each element of the second half (just like in usual knapsack problem) and undo the changes after.

This way as soon as we reach the subset with just one piece we have already calculated dp for every other piece. Adding each piece into dp takes $O(\log n)$, each relaxation takes $O(k)$, final complexity is $O(kn\log n + \sum\limits_{i=1}^n t_i)$.

 
### [1442E - Black, White and Grey Tree](https://codeforces.com/contest/1442/problem/E "Codeforces Round 681 (Div. 1, based on VK Cup 2019-2020 - Final)")

Let's solve the task step by step:

1. Suppose that tree is a bamboo without the grey vertices. Such a tree can be viewed as an array of colors $1$ and $2$. We can see that if there are two adjacent vertices of equal color, we can always delete them together in one operation. We can merge adjacent vertices of the same color, and get an array of colors $b_1, b_2, \ldots, b_k$, such that $b_i \in \{1, 2\}; b_i \ne b_{i+1}$. Such an array can be defined by two numbers — $b_1, k$.We can see that such an array $b$ of length $k$ can not be deleted in less than $\lfloor {k \over 2} \rfloor + 1$ removals. It can be proved by induction. Also, you can delete all elements in this number of removals by deleting opposite leaves (after the first removal opposite leaves will have the same color).
2. Let's solve the task for a general tree without grey vertices. Let's assign the edge $uv$ with weight $0$ if $a_u=a_v$, and $1$ otherwise. Let's find the longest path (diameter) in this weighted tree, and let it be the vertices $v_1, v_2, \ldots, v_m$. We can see this path as bamboo from the previous paragraph, and find the corresponding value $k$ for this path (it is equal to diameter + 1). It is obvious that we can't delete the tree in less than $\lfloor {k \over 2} \rfloor + 1$ removals (otherwise we would be able to delete the bamboo in a smaller number of removals). Turns out that we can delete all vertices in this number of removals. We can do the same algorithm — let's delete the opposite leaves of diameter, and also let's delete all leaves in the tree that have the same color (why not). After one such removal, our path will still be a diameter (if another path becomes the diameter, then one of its leaves should have the same color, and was going to be deleted).

We can find the diameter in such a 0/1 tree in linear time, or we can solve the task even simpler. We can see that we alternate the removal of black and white vertices, and we delete all the leaves with the same color. So, we can choose the first operation (delete black or white), and at each iteration just delete all corresponding leaves. It works in linear time.
3. Let's solve the task without additional constraints. Now there are the grey vertices. How do they change the solution? Let's see at the last removal — suppose we deleted vertex $v$, which was not grey. Then we can imagine that we make $v$ the root of the tree, and paint all the grey vertices in the color of their parents. Then we have a tree without grey vertices, which we can solve. Obviously, the answer for such a colored tree is not less than the answer for the initial tree (because we can make the same removals as in a colored tree). But we can see that we can't get the smaller answer, as by coloring grey vertices we effectively removed them from the tree, and the value $\lfloor {k \over 2} \rfloor + 1$ (over subsequences of black and white vertices) hasn't changed.

So, overall, the solution is to choose the first removal (1 or 2), and alternate removals of black and white vertices. For removal of $c \in \{ 1, 2 \}$ we delete all the leaves with color $0$ or $c$. Also, we can note that the tree remains connected in this process.

 
### [1442F - Differentiating Games](https://codeforces.com/contest/1442/problem/F "Codeforces Round 681 (Div. 1, based on VK Cup 2019-2020 - Final)")

Let's first solve the problem for an empty graph. To do this we need to build a construction with not too many edges, where all vertices are pairwise not equivalent. 

For acyclic graph, there is not such construction. All Grundy functions of vertices should be different, so they must be integers from 0 to $n-1$. The only such graph is full, and it has quadratic number of edges. Moreover, if there is a part from which no cycles are reachable, it must be full acyclic graph, so it can't be too big. 

So, how can other graph look? No vertices can be equivalent to any of vertices in acyclic part. The easiest way to achieve it is to add a loop to every vertex. Let's note, that after doing so all this vertices can't be losing in sum with any other game, because we can just go through loop and don't change anything. So, this games differ from each other be set of games in sum with which they would be winning, not draw. One can see, that such a game would be winning with any acyclic game, it have a move to, because we can go to it, and this will be move to acyclic game with Grundy function 0. The game would be draw with any other acyclic game (and with not acyclic too, but this is not important for solution). This is true, because if we don't move in game with loop, resulting position is not winning. Therefore, to win we must go out from loop vertex. But than we come into acyclic game with non-zero Grundy function, and it's winning, so we can't win. And we can go through loop, achieving a draw. 

So, we need to build a graph, with acyclic part of full graph on $k$ vertices, and all other vertices should have a loop and some edges to this $k$ vertices, and all vertices should have different set of edges. If done, all vertices would be pairwise distinguishable by $k$ queries for each acyclic part vertex. If any of them is lost, this vertex is chosen. If all of them is winning or draw, than the vertex with loop, which have an edge if and only if sum with this vertex is winning, is chosen. In opposite to acyclic case, we can distinguish exponentially many vertices. 

Returning to the initial problem, one can get $k = 20$, and get all subsets of size 0, 1 and 2, and required part of subsets of size $3$. In such a graph there would be $190 + 980 + 1 \cdot 0 + 20 \cdot 1 + 190 \cdot 2 + 769 \cdot 3 = 3877$ edges. The only remaining part is to understand what to do with existing edges. 

One can not, then in built construction any edges between vertices with loops can be added, because they change nothing. If position is winning, then after first move they become unreachable, and doesn't change anything. If it was draw, they can't change anything too, because they are led to vertex with loop, which can't be losing. 

Let's use 20 vertices, which have no edges outside of this set as vertices of acyclic part. Initial graph was acyclic, so we can find such vertices. Let's add loop to all other vertices. Now, we need to modify graph in a way that all sets of edges to acyclic part would be different. Let's go through vertices in any order, and change minimal possible number of edges, so, that this vertex set would not be equal to any of previous. For first vertex we won't do anything. For next 20 vertices, we would need to change at most 1 edge. For next 190 vertices, we would need to change at most 2 edges, and at most 3 for others. This led us to the same 3877 edges to change. 

In general case we can do either $O(nlogn)$ edges changes and $O(logn)$ queries or $O((d+1)*n)$ edges changes and $O(\sqrt[d]{d!n})$ queries. For this problem we need d = 3. 

