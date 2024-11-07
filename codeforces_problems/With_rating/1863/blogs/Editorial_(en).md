# Editorial_(en)

Thanks for the participation!

[1863A - Channel](../problems/A._Channel.md) was authored by [Endagorion](https://codeforces.com/profile/Endagorion "Legendary Grandmaster Endagorion") and prepared by [irkstepanov](https://codeforces.com/profile/irkstepanov "International Master irkstepanov")

[1863B - Split Sort](../problems/B._Split_Sort.md) was authored by [Endagorion](https://codeforces.com/profile/Endagorion "Legendary Grandmaster Endagorion") and prepared by [ch_egor](https://codeforces.com/profile/ch_egor "International Grandmaster ch_egor")

[1863C - MEX Repetition](../problems/C._MEX_Repetition.md) was authored by [Endagorion](https://codeforces.com/profile/Endagorion "Legendary Grandmaster Endagorion") and prepared by [amethyst0](https://codeforces.com/profile/amethyst0 "International Grandmaster amethyst0")

[1863D - Two-Colored Dominoes](../problems/D._Two-Colored_Dominoes.md) was authored by [Endagorion](https://codeforces.com/profile/Endagorion "Legendary Grandmaster Endagorion") and prepared by [AndreySergunin](https://codeforces.com/profile/AndreySergunin "International Grandmaster AndreySergunin")

[1863E - Speedrun](../problems/E._Speedrun.md) was authored by [Endagorion](https://codeforces.com/profile/Endagorion "Legendary Grandmaster Endagorion") and prepared by [Golovanov399](https://codeforces.com/profile/Golovanov399 "International Grandmaster Golovanov399")

[1863F - Divide, XOR, and Conquer](../problems/F._Divide,_XOR,_and_Conquer.md) was authored by [Endagorion](https://codeforces.com/profile/Endagorion "Legendary Grandmaster Endagorion") and prepared by [ch_egor](https://codeforces.com/profile/ch_egor "International Grandmaster ch_egor")

[1863G - Swaps](../problems/G._Swaps.md) was authored by [Endagorion](https://codeforces.com/profile/Endagorion "Legendary Grandmaster Endagorion") and prepared by [zemen](https://codeforces.com/profile/zemen "International Grandmaster zemen")

[1863H - Goldberg Machine 3](../problems/H._Goldberg_Machine_3.md) was authored by [Endagorion](https://codeforces.com/profile/Endagorion "Legendary Grandmaster Endagorion") and prepared by [Endagorion](https://codeforces.com/profile/Endagorion "Legendary Grandmaster Endagorion"), [irkstepanov](https://codeforces.com/profile/irkstepanov "International Master irkstepanov")

[1863I - Redundant Routes](../problems/I._Redundant_Routes.md) was authored by [Endagorion](https://codeforces.com/profile/Endagorion "Legendary Grandmaster Endagorion") and prepared by [Endagorion](https://codeforces.com/profile/Endagorion "Legendary Grandmaster Endagorion"), [irkstepanov](https://codeforces.com/profile/irkstepanov "International Master irkstepanov")

[1863A - Channel](../problems/A._Channel.md)
-----------------------------------------------------------------

 **Solution**
### [1863A - Channel](../problems/A._Channel.md "Pinely Round 2 (Div. 1 + Div. 2)")

Let $p$ be the total number of + signs in the notification string. If $a + p < n$, then the answer is clearly "NO".

Now let's look at the current number of users online. Initially there are $a$ of them. Each notification either increases this number by $1$, or decreases it by $1$. If at some moment of time the number of users online is $n$, then all users are online, thus, everyone must have read the post. The answer is "YES" in this case.

Otherwise the answer is "MAYBE". Indeed, suppose that the number of users online never hits $n$, but $a + p \ge n$. On the one hand, if the first $(n - a)$ notifications of the + type correspond to new users, then all subscribers will have read the post. On the other hand, a situation when the $n$-th user never log in is also possible.

[1863B - Split Sort](../problems/B._Split_Sort.md)
--------------------------------------------------------------------

 **Solution**
### [1863B - Split Sort](../problems/B._Split_Sort.md "Pinely Round 2 (Div. 1 + Div. 2)")

For every $k$ such that $a_i = k$, $a_j = k + 1$ and $i > j$ we have to choose $x = k + 1$ at least once for these elements to be in the correct order.

It is easy to see that if we choose all such $x = k + 1$ for all such $k$ exactly once in any order, we will get the identity permutation.

[1863C - MEX Repetition](../problems/C._MEX_Repetition.md)
------------------------------------------------------------------------

 **Solution**
### [1863C - MEX Repetition](../problems/C._MEX_Repetition.md "Pinely Round 2 (Div. 1 + Div. 2)")

Append the initial array $a_1, \ldots, a_n$ with $a_{n+1} = \operatorname{MEX}(a_1, \ldots, a_n)$. It is easy to see that $a_1, \ldots, a_{n+1}$ is a permutation of $0, 1, \ldots, n$. In this case setting $a_i = \operatorname{MEX}(a_1, \ldots, a_n)$ is basically equivalent $a_i = a_{n+1}$, but after this the new $\operatorname{MEX}(a_1, \ldots, a_n)$ is changed. In fact, it becomes equal to the old value of $a_i$, since this value is not now present in the array.

In other words, performing the operation on $a_i$ is equivalent to swapping $a_i$ and $a_{n+1}$. Performing the operation on $i = 1, 2, \ldots, n$ can be viewed as $n$ swaps. It means that the array changes from $[a_1, a_2, \ldots, a_{n+1}]$ to $[a_{n+1}, a_1, a_2, \ldots, a_n]$, i. e. we simply perform the cyclic shift to the right.

To finish up the solution, first, calculate $a_{n+1} = \operatorname{MEX}(a_1, \ldots, a_n)$ (you can do so, for example, by setting $a_{n+1} = \frac{n(n+1)}{2} - \sum\limits_{i=1}^{n} a_i$). Second, calculate $k \% (n+1)$ and then perform the cyclic shift in $O(n)$.

[1863D - Two-Colored Dominoes](../problems/D._Two-Colored_Dominoes.md)
-------------------------------------------------------------------------------

 **Solution**
### [1863D - Two-Colored Dominoes](../problems/D._Two-Colored_Dominoes.md "Pinely Round 2 (Div. 1 + Div. 2)")

Let's consider the requirement on the rows. Clearly, all horizontal dominoes (since each of them has $1$ black and $1$ white cell) do not influence the black-white balance for the rows. Thus, we are only interested in vertical dominoes.

Consider the first row and the vertical dominoes that intersect this row. Their number has to be even, otherwise, the first row has an odd number of cells covered by dominoes and the solution is clearly impossible. But if there is an even number of such dominoes, we have to paint half of them black-white, and half of them white-black. What's more, it doesn't actually matter the exact order we paint them in, because vertical dominoes do not affect the columns' balance and we will not influence the balance of the second row anyway. So we can freely paint them however we like. The same logic applies for rows $2, \ldots, n$.

Now we turn to horizontal dominoes. In the first row, there once again has to be an even number of dominoes which intersect this column. And we can paint half them black-white, and half of them white-black, and it doesn't matter which exact way we choose. Do the same for columns $2, \ldots, m$.

[1863E - Speedrun](../problems/E._Speedrun.md)
------------------------------------------------------------------

 **Solution**
### [1863E - Speedrun](../problems/E._Speedrun.md "Pinely Round 2 (Div. 1 + Div. 2)")

First of all, assume that the first quest we complete is at the hour $x$. We can assume that $0\leq x < k$, as increasing it by $k$ just shifts all the times by $k$. In this case one can greedily find the completion times for all the quests: essentially, for every quest $v$, if we know that the quests it depends on are completed at hours $c_1$, ..., $c_d$, then the quest $v$ cannot be completed earlier than $\max(c_1, \ldots, c_d)$. So if we define $f(x, y)$ to be the smallest $z\geq x$ such that $z\equiv y\pmod{k}$, then the completion time of $v$ is $f(\max(c_1, \ldots, c_d), h_v)$. If the quest $v$ does not depend on anything, then, obviously, the time if simply $f(x, h_v)$.

The problem is that we don't know which starting time $x$ is optimal. On the other hand, we know that it can be assumed to be from $[0, k)$. Also, there is no sense in $x$ not being $h_v$ for any quest $v$ without incoming dependencies. So we can do the following: first assume that $x = 0$ and find all the completion times for the quests, denote them by $c_i$. Then consequently increase $x$ until it becomes $k$.

Sometimes $x$ becomes equal to some $h_v$ where $v$ is a quest that could theoretically be completed first. At these moments we know that the answer is no more than $\max c_i - x$. When we increase $x$ again, such quests can no longer have $c_i = x$, and thus some values $c_i$ increase by some multiple of $k$.

However, for $x = k$ all $c_i$ are exactly $k$ more than when $x = 0$. Therefore, each value of $c_i$ in this process increases exactly once and exactly by $k$. Now there are two ways to finish the solution.

1. Sort all events of type "some $c_i$, where quest $i$ doesn't have incoming dependencies, increase by $k$". For each such event, we run DFS from such vertices to see if some the quests depending on them must also be completed $k$ hours later. One can see that this DFS will be run from each vertex exactly once throughout the process, thus resulting in $O(n + m)$ time complexity.
2. When building all $c_i$ the first time, also find for each vertex $v$ the first $x$ when its $c_v$ must change. If we denote it with $w_v$ then it can be expressed as $\max\{w_u\,\colon\,u\to v, c_u + k > c_v\}$. Then sort all events of type "some $c_i$, where quest $i$ may or may not have incoming dependencies, increase by $k$".

In both approaches one can easily maintain $\max c_i$ as this value can only increase.

[1863F - Divide, XOR, and Conquer](../problems/F._Divide,_XOR,_and_Conquer.md)
----------------------------------------------------------------------------------

 **Solution**
### [1863F - Divide, XOR, and Conquer](../problems/F._Divide,_XOR,_and_Conquer.md "Pinely Round 2 (Div. 1 + Div. 2)")

Let $s = a_l \oplus a_{l + 1} \oplus \ldots \oplus a_r$, $x = a_l \oplus a_{l + 1} \oplus \ldots \oplus a_k$, $y = a_{k + 1} \oplus a_{k + 2} \oplus \ldots \oplus a_{r}$.

If $s$ is zero, than we can choose any $k$ and any side because $s = x \oplus y = 0 \implies x = y$.

If $s$ is not zero we can choose such $k$ for the left side that the most significant bit of $s$ is the same as the most significant bit of $x$ because $y = s \oplus x$ does not have this bit, and therefore less than $x$. Same for the right side.

We will iterate over all subarrays in non-increasing order of length and will calculate two set of bits $mask\\_start_i$ and $mask\\_end_i$ for each position of array — bits, one of which must contain the XOR of subarray numbers to start/end at that position.

To check that we can achieve $l$, $r$ we need to check that $s \land mask\\_start_l > 0$ or $s \land mask\\_end_r > 0$ or any segment can start/end in these positions, since there was a segment with zero XOR with such start/end. 

If we can achieve $[l; r]$ than: 

* if $s \neq 0$ add the most significant bit of $s$ to $mask\\_start_l$ and $mask\\_end_r$;
* if $s = 0$ remember that any subarray of shorter length can start/end at these positions.

The time complexity is $O(n^2)$, the space complexity is $O(n)$.

[1863G - Swaps](../problems/G._Swaps.md)
---------------------------------------------------------------

 **Solution**
### [1863G - Swaps](../problems/G._Swaps.md "Pinely Round 2 (Div. 1 + Div. 2)")

Consider a directed graph with $n$ vertices, where for each vertex $i$ there is an edge $i\to a_i$. This is a functional graph, that is, every vertex has exactly one edge outgoing from it. Let's see how our operations affect the graph.

We will write $u\to v$ to illustrate the fact that $a_u = v$. Call the operation $\mathrm{swap}(a_i, a_{a_i})$ picking vertex $i$. We can assume that we never picked such $u$ that the operation didn't change the permutation, that is, $u\to v\to v$.

We will mark some edges in the graph as bold. Initially no edge is bold. When we pick vertex $v$, one of the following can happen:

* If no bold edges pass into $v$, go along the bold edges until we can. Let's say the vertex we reached is $u$. Then mark the edge from $u$ bold.
* If $v$ has an incoming bold edge, do nothing.

At every moment of time, the graph corresponds to the permutation in the following way: if $v$ has an incoming bold edge then $a_v = v$, otherwise, if $u$ is the vertex we reach by going from $v$ along the bold edges, and $u\to w$, then $a_v = w$. Also, one can see that according to the algorithm of making edges bold no vertex ever has more than one incoming bold edge.

It is clear that each valid subset of bold edges corresponds to a unique permutation. However, one can see that the same permutation can correspond to multiple subsets. In particular, for a component of the graph, if $a_v = v$ for all vertices of the cycle in this component, then the boldness of all edges outside the cycle is uniquely determined, but for the edges of the cycle any subset of these edges that doesn't include exactly one of them corresponds to this permutation. To avoid this uncertainty, we say that this permutation will correspond to the subset of bold edges where all the edges from the cycle are bold (this is an invalid subset, because there is no sequence of operations that would mark it bold).

Now we want to calculate the number of possible subsets of bold edges. Each vertex can have either no incoming bold edges (there is $1$ way to do this) or any one of them can be bold ($\mathrm{in}_v$ ways to do this for vertex $v$). So the answer could be just $\prod_{v}(\mathrm{in}_v + 1)$. However, since some of the configurations are invalid, we need to modify the answer.

In particular, consider any cycle $c_1\to\ldots\to c_k\to c_1$. All excluded subsets of edges correspond to exactly one of $c_{i+1}$ having either no bold edge incoming, or any edge except $c_i\to c_{i+1}$. Therefore, the number of ways to choose the bold edges among the ones incoming to this cycle is

$$\prod_{i=1}^k(\mathrm{in}_{c_i} + 1) - \sum_{i=1}^k\mathrm{in}_{c_i}.$$

Thus, the final answer is

$$\prod_{\text{cycles}}\left(\prod_{i=1}^k(\mathrm{in}_{c_i} + 1) - \sum_{i=1}^k\mathrm{in}_{c_i}\right)\cdot\prod_{\text{other }v}(\mathrm{in}_v + 1).$$

[1863H - Goldberg Machine 3](../problems/H._Goldberg_Machine_3.md)
----------------------------------------------------------------------------

 **Solution**
### [1863H - Goldberg Machine 3](../problems/H._Goldberg_Machine_3.md "Pinely Round 2 (Div. 1 + Div. 2)")

Let's consider a dynamic programming approach: for leaves, set $dp_v = a_v$, and for an internal vertex $v$ with children $u$ and $w$, set $dp_v = 2 \max(dp_u, dp_w)−[dp_u \neq dp_w]$ we use an indicator notation $[\ldots]$.

Let $d_v = dp_v - 1$, then the update becomes $d_v = 2 \max(d_u, d_w) + [d_u = d_w]$. Let $h_v$ denote the distance from the root to $v$, and $D_v = d_v \cdot 2^{h_v}$. Then $D_v = \max(D_u, D_w) + 2^{h_v} [D_u = D_w]$.

Notice that the binary representation of $D_v$ contains at most $\log_2 A + \log_2 n$ ones ($A = \max a_i$). This can be easily proven by induction: suppose the minimum size of a tree that can result in $D_v$ having $k$ ones is $f(k)$. Then, $f(k) = 1$ when $k \le \log_2 A$, and $f(k) \ge 2f(k - 1)$ otherwise, since $D_v$ must be constructed from equal $Du$ and $Dw$ from independent subtrees.

We'll maintain a set $S$ of pairs $(v, D)$, where $D$ is a lower bound on $D_v$. Initially, put pairs $(v,(a_v - 1)\cdot 2^{h_v})$ into $S$ for all leaves with $a_v > 0$, and if there are $(v, D)$ and $(u, D)$ in $S$ ($v \neq u$), put $(w, D + 2^{h_w})$ into $S$, where $w = \text{lca}(v, u)$. The answer is $1 +$ the maximum $D$ among all pairs in $S$ (if $S$ is empty, the answer is obviously $0$).

Start with an empty $S$ and add all the leaves to it. A new pair $(v, D)$ can create at most one new lca with pairs $(u, D)$, and at most one new pair $(w, D + 2^k)$, where $k$ is necessarily a new bit. The process of creating new pairs continues, but it will finish in $O(\log A + \log n)$ iterations since there cannot be more bits. Different $D$ values can be stored in a trie based on bit positions from most significant to least significant (or by some hashing), and vertex sets in the trie nodes can be stored in the order of entry time.

To change $a_v$, remove the old pair from $S$ (similarly to adding) and add the new one. All together requires $O(\log n \cdot (\log A + \log n))$ operations.

[1863I - Redundant Routes](../problems/I._Redundant_Routes.md)
--------------------------------------------------------------------------

 **Solution**
### [1863I - Redundant Routes](../problems/I._Redundant_Routes.md "Pinely Round 2 (Div. 1 + Div. 2)")

Let's call two paths adjacent if one can be obtained from the other by adding an edge to one end and removing an edge from the other end.

Proposition. There exists an optimal solution in which each pair of adjacent paths is either simultaneously chosen or simultaneously not chosen.

Proof. Consider an optimal solution that maximizes the total length of paths in it. Let's assume that in such a solution, we have taken some path $ab$, but its adjacent path $cd$ is not included (here, assume $a \not\in cd$ and $d \not\in ab$). Why can't we add $cd$?

* If $cd$ contains a shorter path, it must end at $d$ (since all other paths are also contained in $ab$). In that case, we can extend the shorter path $ed$ to $cd$, which contradicts the maximization of the sum of lengths.
* If $cd$ is contained within a longer path, it must start at $c$ (since all other paths are also contained in $ab$). In this case, we can extend $ab$.

 We will refer to classes of adjacent paths as simply classes. Each class will either be taken in its entirety or not taken at all, and according to the proposition above, an optimal solution can always be found.In the rooted tree, we'll call a class vertical if it contains at least one vertical path. To reduce the number of vertical classes, we'll root the tree by the midpoint of its diameter (if the diameter is of odd length, consider the root as an edge). Now, all vertical paths of the same length are equivalent (since a vertical path can always be moved to another subtree of the root). Thus, for each length, there is at most one vertical class.

How do we determine if a path belongs to some vertical class? We'll attempt to greedily pull the path: first lower one end of the path to the deepest available vertex, then the other end, and so on. In the end, either the path becomes vertical or we encounter an obstacle of the following form: the endpoints are in non-intersecting subtrees of the same depth $h$, whose roots are at distance $d$ apart, and the path length is $h + d$. Moreover, any such pair of subtrees describes a non-vertical class of paths, and no other classes exist, as paths from a non-vertical class must hit such an obstacle.

Note. A class doesn't necessarily consist of all paths between subtrees of length $h + d$. This is because an obstacle might exist lower down for some of these paths. Nonetheless, at least one representative for any pair of subtrees will definitely exist (for instance, the root of one subtree and the deepest leaf of the other).

Let's define non-vertical classes with a pair of root vertices of subtrees $(v, u)$ (with the convention $tin(v) < tin(u)$), and define the class length as $L(v, u) = h + d$. We'll introduce a forest structure on non-vertical classes: a pair $(v, u)$ is an ancestor of $(v', u')$ if $v$ is an ancestor of $v'$ and $u$ is an ancestor of $u'$. All classes, together with this forest, can be constructed using DFS in $O(n^2)$ time, simultaneously traversing $v$ and $u$. Moreover, we can quickly compute the size of each such class. Let $S(v, u)$ denote the number of all paths of length $L(v, u)$ between subtrees $v$ and $u$. Then, the size of class $N(v, u)$ is $S(v, u) - \sum_{(v', u')} N(v', u')$, where the summation is over all classes $(v', u')$ that are proper descendants of $(v, u)$ such that $L(v', u') = L(v, u)$. Thus, we need to compute all $S(v, u)$. If we compute this for each class in $O(h)$ time, the total time will be $O(n^2)$ (exercise for the reader).

Which non-vertical classes can't be taken simultaneously? If between classes $a = (v, u)$ and $b = (v', u')$ neither is an ancestor of the other, then nested paths can't exist in them (due to the construction of the forest, there's a branching somewhere that's common to all paths).

Proposition. Let class $a$ be an ancestor of class $b$. Then, a pair of nested paths between them can exist if and only if for all classes $c$ on the path between $a$ and $b$ (including $b$ but excluding $a$), $L(c) > L(a)$.

Proof. Paths within $b$ cannot come out of subtrees $v', u'$. If $L(a) \leq L(b)$, then a path of length $L(a)$ containing something from $b$ must also go between subtrees $v', u'$, but it can't extend beyond subtrees $v, u$ (since shorter paths from $b$ can't). Thus, it can't belong to $a$. Otherwise, if we attempt to pull a path of length $L(a)$ nested within $b$ upwards until encountering an obstacle at $a$, this can only happen if $a$ is the first significant obstacle.

How do we include vertical classes? Clearly, we can take at most one vertical class. Using similar reasoning as above, if $a$ is a non-vertical class and $\ell$ is the length of a vertical class, then $a$ can be taken with a vertical class if there are no classes $c$ among the ancestors of $a$ (including $a$) with $L(c) \leq \ell$. Constructing a bamboo structure out of all vertical classes (shorter classes on top) and attaching the roots from the forest of non-vertical classes at the bottom of this bamboo, the criterion remains the same as in the proposition. Now we can forget about the original problem and solve a new one: given a rooted tree, with numbers $L_v$ and $N_v$ assigned to each vertex, we need to select a set of vertices to maximize the sum of $N_v$, while satisfying the criterion.

Consider the vertex $v$ with the minimum $L_v$ among all vertices (considering the deepest among such vertices, if there are several options). It's easy to see that: 

* Vertices outside the subtree rooted at $v$ cannot prevent us from choosing vertices within the subtree rooted at $v$.
* If we choose $v$, we can't choose anything else in its subtree.

Divide the set of all vertices $V$ into $T_v - v$ and $V - T_v$, where $T_v$ is the subtree rooted at $v$, and solve the problem independently for them. The final answer will be $ans(V - T_v) + \max(N_v, ans(T_v))$.

This process can be conveniently done in reverse, for instance, using DSU. It's also possible to carefully determine, during the forest construction, which components will merge, and solve the problem in $O(n^2)$ time using just bucket sort without any additional data structures or sorting.

