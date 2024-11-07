# Tutorial_(en)

Thank you for participating, and I hope you enjoyed the problems! 

Also, here are video editorials by [BRCode](https://codeforces.com/profile/BRCode "Expert BRCode"):

 * [Problem A and B](https://codeforces.com/https://www.youtube.com/watch?v=KJVigs8w-gg)
* [Problem C](https://codeforces.com/https://www.youtube.com/watch?v=vWHUmtiPRQw)
* [Problem D](https://codeforces.com/https://www.youtube.com/watch?v=kspzot42-uI)
* [Problem E](https://codeforces.com/https://www.youtube.com/watch?v=y62jjZev3pY)

 
### [1391A - Suborrays](../problems/A._Suborrays.md "Codeforces Round 663 (Div. 2)")

Every permutation is good. 

Proof: We use the fact that for any set of numbers, it's bitwise OR is at least the maximum value in it. Now, we just need to show that any subarray of length $len$ has at least one element greater than or equal to $len$. If the maximum element is $< len$, then, we have $len$ elements all with values in the range $[1,len-1]$. By the pigeonhole principle, at least $2$ of them must be the same contradicting the fact the it's a permutation. 

Time Complexity: $\mathcal{O}(n)$

Code: [89479484](https://codeforces.com/contest/1391/submission/89479484 "Submission 89479484 by SleepyShashwat") 

Tutorial is loading... Code: [89479603](https://codeforces.com/contest/1391/submission/89479603 "Submission 89479603 by SleepyShashwat") 
### [1391C - Cyclic Permutations](../problems/C._Cyclic_Permutations_.md "Codeforces Round 663 (Div. 2)")

The answer is $n!-2^{n-1}$.

Consider an arbitrary cyclic permutation — for example, [4,2,3,1,5,6]; it contains many cycles of length $3$: $[1,2,3]$, $[1,3,5]$, $[3,4,5]$. Note that all the listed cycles contain nodes obtained from just one choice of $i$. We can generalize this to the following. If for any $i$, we make edges on both sides of it, this will create a simple cycle of length $3$. The proof is simple and is an exercise for you. 

Thus, there has to at most one peak that is the element $n$– all acyclic permutations increase, then reach $n$, and, finally, decrease. These are formally called unimodal permutations, and it's easy to see that any unimodal permutation forms a tree, and, thus, contains no simple cycle  — each element, except $n$, has a uniquely defined parent.

We can construct any unimodal permutation by adding the numbers $n, n-1, \ldots, 1$ into a deque in the same order. For example, $[2,3,4,1]$ can be constructed by first pushing $4$, $3$, $2$ to the front, and, finally, $1$ at the back. Thus, for every element, except $n$, we have the choice of pushing it to the front or the back, making the total number of ways equal to $2^{n-1}$. 

Time Complexity: $\mathcal{O}(n)$

 Also, thanks to [shash42](https://codeforces.com/profile/shash42 "Candidate Master shash42") for the construction using deque idea!Code: [89479612](https://codeforces.com/contest/1391/submission/89479612 "Submission 89479612 by SleepyShashwat") 

### [1391D - 505](../problems/D._505.md "Codeforces Round 663 (Div. 2)")

Firstly, if $min(n,m) > 3$, then, no solution exists because this means the grid contains at least one $4\times4$ sub-matrix, which can further be decomposed into four $2\times2$ sub-matrices. Since all four of these $2\times2$ sub-matrices are supposed to have an odd number of ones, the union of them will have an even number of ones.

The problem, now, reduces to changing the least number of cells such that every $2\times2$ sub-matrix has an odd number of ones — this is possible to achieve for every valid grid. For example, for every even-indexed row, alternate the cells, and for every odd-indexed row, make all cells equal to $1$. 

We will solve this reduction using dynamic programming. 

We represent the $i^{th}$ column as a $n$-bit integer — $a_i$; let $dp(i,mask)$ be the minimum cells we have to flip to make the first $i$ columns valid, and the $i^{th}$ column is represented by $mask$. The transition is quite simple: $$dp(i,cmask) = min( dp(i-1,pmask)+bitcount(cmask \oplus a[i]), dp(i,cmask)).$$

The term $bitcount(cmask \oplus a[i])$ is equal to the number of positions where these two masks differ. 

Please note that we only consider those pairs, $\{pmask,cmask\}$, that when put adjacent do not form a $2\times2$ sub-matrix with an even number of ones. To speed up the transition, they can be pre-calculated.

Time Complexity: $\mathcal{O}(m*2^{2n} + n*m)$

 Code: [89479627](https://codeforces.com/contest/1391/submission/89479627 "Submission 89479627 by SleepyShashwat") 
### [1391E - Pairs of Pairs](../problems/E._Pairs_of_Pairs.md "Codeforces Round 663 (Div. 2)")

Let's build the DFS tree of the given graph, and let $dep(u)$ denote the depth of node $u$ in the tree.

If $dep(u) \ge \lceil \frac{n}{2} \rceil$ holds for any node $u$, we have found a path. Otherwise, the maximum depth is at most $\lfloor \frac{n}{2} \rfloor$, and we can find a valid pairing as follows: 

* For every depth $i$ ($1 \le i \le \lfloor \frac{n}{2} \rfloor$), keep pairing nodes at this depth until $0$ or $1$ remain.

Clearly, at most $1$ node from each depth will remain unpaired, so, in total, we have paired at least $n - \lfloor \frac{n}{2} \rfloor = \lceil \frac{n}{2} \rceil$ nodes. 

Finally, let's prove that every subgraph induced from some $2$ pairs has at most $2$ edges. 

Consider $2$ arbitrary pairs, ($a,b$) and ($c,d$), where $dep(a) = dep(b)$ and $dep(c) = dep(d)$. W.L.O.G, let $dep(a) < dep(c)$.

Obviously, the edges ($a,b$) and ($c,d$) cannot exist because edges can only go from a descendant to an ancestor. We can, further, show that each of $c$ and $d$ can have an edge to at most one of $a$ and $b$. For example, if $c$ has an edge to both $a$ and $b$, we can conclude that $a$ and $b$ are ancestor-descendants, which is not possible because both of them are at the same depth. 

Time Complexity: $\mathcal{O}(n+m)$

 Code: [89479649](https://codeforces.com/contest/1391/submission/89479649 "Submission 89479649 by SleepyShashwat")