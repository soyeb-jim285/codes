# Tutorial_(en)


### [1243A - Maximum Square](../problems/A._Maximum_Square.md "Codeforces Round 599 (Div. 2)")

There are different solutions:

Solution 1: Bruteforce the length of the square $l$ from $1$ to $n$. If you can make a square of side length $l$, then there should be at least $l$ planks of length at least $l$. The complexity of such solution: $O(n^2)$. The parameter $l$ can be also checked using binary search: then the complexity becomes $O(n \log n)$.

Solution 2: Suppose you want to take $i$ planks and cut the largest square from them. Of course, it is always better to take the longest $i$ planks. The side of the largest square that can be cut from them is bounded by the length of the smallest of these $i$ planks and the number of the planks, $i$. Therefore, the solution is: sort the numbers $a_i$ in descending order; then the solution is $\max(\min(i,a_i))$. The complexity: $O(n \log n)$. Since the numbers $a_i$ are at most $n$, we can use counting sort and the complexity becomes $O(n)$.

 
### [1243B1 - Character Swap (Easy Version)](../problems/B1._Character_Swap_(Easy_Version).md "Codeforces Round 599 (Div. 2)")

First, suppose that we make the strings equal by picking some $i$, $j$. Then for all $p \neq i, j$, we must have $s_p = t_p$, since these letters don't change.

Suppose that $i = j$. Since the strings are distinct, we then must have $s_i \neq t_i$. But then the strings are not equal also after the swap; hence, we always need to pick distinct $i$ and $j$.

Now, if $i \neq j$ and the strings are equal after the swap, we must have that $s_i = s_j$, $t_i = t_j$ and $s_i, s_j \neq t_i, t_j$. Therefore, the solution is as follows: if the number of positions where $s$ and $t$ differ is not equal to $2$, the answer is "No". Otherwise we find the two positions $i$, $j$, where $s$ and $t$ differ, and check that the above conditions hold. Then the answer is "Yes". Complexity of the solution: $O(n)$.

 
### [1243B2 - Character Swap (Hard Version)](../problems/B2._Character_Swap_(Hard_Version).md "Codeforces Round 599 (Div. 2)")

We claim that you can make the strings equal if and only if the total number of each character in both of the strings $s$ and $t$ is even.

Proof that this is a necessary condition. If we can make the strings equal, then for each position, the characters of $s$ and $t$ will be the same. Therefore, each character must appear an even number of times in both strings together.

Algorithm, if all characters appear even number of times. Iterate over the index $i$ from $1$ to $n$. If $s_i \neq t_i$, then one of the following cases holds: 

* There is an index $j > i$ such that $s_i = s_j$. Then simply swap $s_j$ with $t_i$ and then the strings will have the same character at position $i$.
* There is an index $j > i$ such that $s_i = t_j$. Then first swap $t_j$ with $s_j$, and then swap $s_j$ with $t_i$. Again, the strings will have the same character at position $i$.

 Since we make at most $2$ swaps for each position, this algorithm produces two equal strings and makes at most $2n$ swaps in total. The complexity of the algorithm: $O(n)$.This problem was introduced by [user:MikeMirzayanov] inspired by the easier version of the problem (with a single swap).

 
### [1242A - Tile Painting](https://codeforces.com/contest/1242/problem/A "Codeforces Round 599 (Div. 1)")

If $n = p^k$ for some prime $p$, then the answer is $p$ colors. Simply color all tiles with indices $i \pmod p$ in color $i$. Since any divisor $d$ of $n$ greater than $1$ is divisible by $p$, then any two tiles $i$ and $i+d$ will have the same color. Also, if the first $p$ tiles are colored in $c$ different colors, then each next $p$ tiles have the same $c$ colors, hence the answer cannot be greater than $p$.

If $n = pq$ for some $p, q > 1$ such that $\gcd(p, q) = 1$ then the answer is $1$. Examine any two distinct indices $i, j$. Let's prove that they must have the same color. By the Chinese Remainder Theorem, there exists such $1 \leq x \leq n$ that $x \equiv i \pmod p$ and $x \equiv j \pmod q$. Therefore, both tiles $i$ and $j$ must be colored in the same color as the tile $x$. Hence, all tiles must have the same color.

To check which case it is, we use the following algorithm: 

* First we check whether $n$ is prime. We use the standard $O(\sqrt n)$ algorithm.
* Otherwise, if $n = p^k$ for $k > 1$, then $p$ must be at most $\sqrt n \leq 10^6$. We can then find the smallest divisor $p$ of $n$ greater than $1$, which is at most $10^6$. Then we try to divide $n$ by the largest power of $p$. If $n = p^k$, then $n$ will become simply $1$; otherwise $n$ will remain greater than $1$, hence it is divisible by some prime other than $p$.

 Complexity: $O(\sqrt n)$. 
### [1242B - 0-1 MST](https://codeforces.com/contest/1242/problem/B "Codeforces Round 599 (Div. 1)")

First examine the given graph where there are only edges of weight $0$: suppose that the number of connected components in this subgraph is $k$. Then the minimum spanning tree of the given graph is equal to $k-1$. Therefore, we need to find the number of such (zero weight) components in the given graph.

The following is a $O(m + n \log n)$ solution. Let's maintain the zero weight components in the disjoint set union, and let's also store the size of each such component. Then we iterate over all vertices $v$ from $1$ to $n$. Put the vertex $v$ in a new component of size $1$. Then we iterate over the weight $1$ edges $\{u, v\}$ such that $u < v$. For each of the zero weight components, we count the number of edges from this component to $v$. If the number of such edges is less than the size of the component of $u$, we should merge the component of $u$ with $v$ (because there is at least one $0$ weight edge between this component and $v$). Otherwise we should not merge the component with $v$. In the end, we get the number of zero weight components.

What is the complexity of such algorithm? In total, $n$ new components are created in the course of the algorithm (a new one for each of the $n$ vertices). When we merge some old component with $v$, the number of components decreases by $1$. Thus the total number of such cases during the algorithm is at most $O(n)$, and for each we have one merge call for DSU. This part has $O(n \log n)$ complexity.

When we don't merge an old component with $v$, there is at least one edge of weight $1$ from this component to $v$. Therefore, the total number of such cases is at most the number of edges, $m$. Thus the complexity of processing these cases is $O(m)$.

Hence, the total complexity of the algorithm is $O(n \log n + m)$.

 
### [1242C - Sum Balance](https://codeforces.com/contest/1242/problem/C "Codeforces Round 599 (Div. 1)")

First, calculate the total average sum $s := (\sum_{i=1}^n a_i)/k$. If the answer is positive, the sum of integers in each box must be equal to $s$ after reordering. If $s$ is not integer, then the answer is immediately negative.

Now, suppose that an integer $x := a_{i,p}$ is taken out of some box $i$. Then we know that it should be replaced by $y := s - \sum_{j = 1}^{n_i} a_{i,j} + a_{i,p}$. We then construct a graph where all of the given integers are vertices, and we draw a directed edge from $x$ to $y$.

Note that we obtain a functional graph. Examine all of the cycles of this graph; since this a functional graph, no two cycles share the same vertex. Let $n := \sum_{i=1}^k n_i$, then the total number of cycles is at most $n \leq 15 \cdot 5000 = 75000$.

Examine any valid reordering. It is easy to see that it is a collection of cycles from the obtained graph such that each box is visited by some cycle exactly once. Therefore, lets extract all of the cycles from our graph such that do not pass through the same box twice. A valid reordering then is some subset of these cycles that visit all of the $k$ boxes exactly once.

We can also reformulate this problem in the following way: each of the extracted cycles $C$ visits some set of boxes $S$. Find all of such subsets $S$; the number of such subsets is at most $2^k$. Now, the problem is reduced to exactly covering the set $\{1,\ldots,k\}$ with some subset of such sets.

This is a classical problem that can be solved in $O(3^n)$ using dynamic programming. For a subset $X$ of $\{1,\ldots,k\}$, define $dp[X]$ to be true if $X$ can be exactly covered, and false otherwise. Firstly, $dp[\varnothing] = true$. To find $dp[X]$ for $X \neq \varnothing$, iterate over all subsets $S$ of $X$, and check whether $S$ is visited by some cycle and $X \setminus S$ can be covered (e.g., $dp[X \setminus S]$ is true). Then the answer is $dp[\{1,\ldots,k\}]$. This algorithm can be implemented with complexity $O(3^k)$, you can read about it here:[https://cp-algorithms.com/algebra/all-submasks.html](https://codeforces.com/https://cp-algorithms.com/algebra/all-submasks.html). The reordering can be restored from this DP table.

The total complexity of the algorithm: $O(k \cdot \sum_{i=1}^k n_i + 3^k)$.

 
### [1242D - Number Discovery](https://codeforces.com/contest/1242/problem/D "Codeforces Round 599 (Div. 1)")

Analysis by [user:McDic].

Let's make some definitions:

* $x$ is non-self number if $x$ is appended into $s$ by summation form. For example, if $k = 2$, then $3, 9, 13, 18, \ldots$ are non-self numbers.
* $x$ is self number if $x$ is not non-self number.
* Let $I_{i} = [(k^2+1) \cdot i + 1, (k^2+1) \cdot i + 2, \ldots, (k^2+1) \cdot (i+1)]$. In other words, $I_{i}$ is $i$-th interval of positive integers with $k^2+1$ size.

Now let me introduce some strong lemma  — Every interval has exactly one non-self number. Furthermore, we can immediately determine the non-self number of $I_{k \cdot i}, I_{k \cdot i + 1}, I_{k \cdot i + 2}, \ldots, I_{k \cdot i + k - 1}$ using non-self number of $I_{i}$.

How is this possible? First, you can prove there is only $1$ non-self number in $I_{0}$. Now let's try induction. Suppose $I_{i}$ has only $1$ non-self number and each $k$ numbers of $k^2$ self numbers form summation, then you can describe generated summations as follows:

$$ \sum_{j=1}^{k} (i \cdot (k^2 + 1) + t \cdot k + j) + offset = (k \cdot i + t) \cdot (k^2 + 1) + \frac{k \cdot (k+1)}{2} - t + offset $$

Where $t$ means index of subintervals in $I_{i}$ ($0 \le t \lt k$) and $offset$ means added offset into $t$-th subinterval ($0 \le offset \le k$) since $I_{i}$'s non-self number can be located at left or inside of $t$-th subinterval.

Using this fact, you can solve this problem in $O(\frac{\log n}{\log k})$ per test case. Some testers solved this problem by detecting pattern of distribution of non-self numbers.

 
### [1242E - Planar Perimeter](https://codeforces.com/contest/1242/problem/E "Codeforces Round 599 (Div. 1)")

If there is just a single face, just output it. Suppose there are at least $2$ faces.

Let's say that we "glue" a cycle to a planar graph along $k$ edges if we place this cycle so that the graph and the cycle share $k$ edges on their perimeters.

First, sort the numbers in decreasing order (then we have $a_1 \geq a_2 \geq \ldots \geq a_n$). By gluing any $a_i$ to the $a_1$ cycle, we can decrease the number of edges by at most $a_i-2$. Also note that the answer is always at least $3$, because there cannot be multiple edges between two vertices. Thus, if $a_1-2 \geq \sum_{i=2}^n (a_i-2)$, then the answer is $a_1 - \sum_{i=2}^n (a_i-2)$ (we subtract $2$ from $a_1$ to keep the perimeter at least $3$: these are the $2$ edges that we don't glue anything to).

Otherwise the answer is either $3$ or $4$ (depending on the parity of $\sum_{i=1}^n a_i$). The algorithm to construct the graph: let $C := a_1$. Iterate $i$ from $2$ to $n$. While $(C-2) + (a_i-2) < \sum_{j=i+1}^n (a_j-2)$, glue the $i$-th cycle with the graph along one edge ($C += (a_i-2)$). For the first $a_i$ such that this does not hold, glue it so that $\sum_{j=i+1}^n (a_j-2) \leq C-2 \leq \sum_{j=i+1}^n (a_j-2) + 1$. Afterwards just glue each remaining cycles $a_j$ along $a_j-1$ edges with the graph.

There is one problem with this algorithm: it can happen that we add multiple edges between two vertices. This situation is as follows: suppose you are at some point of the algorithm with a planar graph that you're building. Suppose there is an edge between some vertices $u$ and $v$ on the current perimeter, and you now happen to glue a cycle $C$ along the edges between $u$ and $v$, and the last edge of the cycle $C$ you're gluing must connect $u$ and $v$. To solve this situation, take the vertex $u'$ adjacent to $u$ to the right on the perimeter, and the vertex $v'$ adjacent to $v$ also to the right on the perimeter. Now, $u'$ and $v'$ cannot be connected by an edge in the current graph, because then it would intersect the edge between $u$ and $v$. This would be a contradiction, because the graph is planar. Then you glue the cycle $C$ along the edges between $u'$ and $v'$.

The complexity of the algorithm: $O(\sum_{i=1}^n a_i)$. You should be careful with the implementation: for example, not to make perimeter equal to $2$ at some point or use some edge in more than two faces.

