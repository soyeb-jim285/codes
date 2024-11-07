# Tutorial_(en)


### [1266A - Competitive Programmer](../problems/A._Competitive_Programmer.md "Codeforces Global Round 6")

Thanks to Chinese remainder theorem, a number is divisible by $60$ if and only if it is divisible by $3$ and $20$. 

A number is divisible by $3$ if and only if the sum of its digits is divisible by $3$. Note that as the sum doesn't change if we reorder digits, it applies also to the sum of digits of $s$.

A number is divisible by $20$ if it ends in $20$, $40$, $60$, $80$ or $00$. Hence, it is necessary and sufficient if $s$ contains a $0$ and then at least one additional even digit.

Overall, there are three conditions to check: 

* The digit sum is divisible by $3$.
* There is at least a single $0$.
* There are at least two even digits (including $0$s).
 
### [1266B - Dice Tower](../problems/B._Dice_Tower.md "Codeforces Global Round 6")

Consider a die other than the top-most one. As the sum of numbers on the opposite faces of a die is always $7$, the sum of numbers on the visible faces is always $14$, regardless of its orientation.

For the top-most die, the numbers on the sides also add up to $14$, and there is an additional number on top of the die. The total number of visible pips is thus $14d + t$, where $d$ is the number of dice and $t$ is the number on top. 

For a given $x$, compute $t = x \bmod 14$ and $d = \lfloor \frac{x}{14} \rfloor$. The answer is positive if and only if $d \geq 1$ and $1 \leq t \leq 6$. 

 
### [1266C - Diverse Matrix](../problems/C._Diverse_Matrix.md "Codeforces Global Round 6")

As the example reveals, the case when $r = c = 1$ is impossible. It turns out that this is the only impossible case. We will prove this by providing a construction that always achieves a magnitude of $r + c$. 

If $r = 1$, one optimal solution is $A = (2, 3, \dots, c+1)$. The case where $c = 1$ is similar. 

Assume $r, c \geq 2$ and assign $a_{i,j} = i * (j+r)$. We can now show that the gcd of the $i$-th row equals to $i$:

$$b_i = \mathrm{gcd}\left\{i * (r+1), i * (r+2), \dots i * (r+c)\right\} = i \cdot \mathrm{gcd}\left\{r+1, r+2, \dots, r+c \right\}$$

As $r+1$ and $r+2$ are coprime, $b_i = i$. Similarly, we can show that $b_{r+j}$ = $r + j$. 

To summarise, $b_k = k$ for all $k$, hence all row and column gcds are pairwise distinct, and the maximum is $r + c$. As the magnitude is a maximum of $r + c$ pairwise distinct positive integers, $r + c$ is optimal. 

 
### [1266D - Decreasing Debts](../problems/D._Decreasing_Debts.md "Codeforces Global Round 6")

Consider a solution which minimises the total debt. 

Assume for contradiction that there is a triple of vertices $u \neq v \neq w$, such that $d(u,v) > 0$ and $d(v,w) > 0$. We can use the first rule with $a = u$, $b = c = v$, $d = w$ and $z = min(d(u,v), d(v,w))$ and then the second rule with $a = v$ and the same $z$. We have just reduced the total debt by $z$, which is a contradiction. So, there cannot be such a triple, in particular there cannot be a vertex $v$ that has both incoming and outgoing debt. Hence, every vertex has only outgoing edges or only incoming ones. 

Define $bal(u) = \sum_v d(u,v) - \sum_v d(v,u)$ to be the balance of $u$. Any application of either rule preserves balance of all vertices. It follows that any solution in which every vertex has either outgoing or incoming edges is constructible using finite number of applications of rules. This means that we can just find balances, and greedily match vertices with positive balance to vertices with negative balance. 

The total debt is then $\Sigma_d = \frac{\sum_v |bal(v)|}{2}$ and it is clear that we cannot do better than that. 

 
### [1266E - Spaceship Solitaire](../problems/E._Spaceship_Solitaire.md "Codeforces Global Round 6")

Consider a fixed game. Let $m_i$ be the total number of milestones having $u_j = i$, that is, the maximum possible number of "free" units of resource $i$ that can be obtained. We claim that in optimal solution, we (manually) produce this resource exactly $p_i = \max\left(a_i - m_i, 0\right)$ times.

It is obvious that we cannot do better and this number is necessary. Let's prove that it is also sufficient. 

First remove arbitrary milestones such that $a_i \geq m_i$ for all $i$. This clearly cannot make the production work faster. Now, $p_i + m_i = a_i$ holds for each resource. Let's perform the production of $p_i$ units for all $i$ in arbitrary order and let $c_i$ be the total amount of $i$-th resource after this process finishes. Clearly $c_i \leq a_i$. 

Assume for contradiciton that for a resource $i$ we have $c_i < a_i$, that is, the goal has not been reached. As we performed all $p_i$ manual productions for this resource, it means that we did not reach $a_i - c_i$ milestones claiming this resource. The total number of unclaimed awards is thus: $$\sum (a_i - c_i)$$ 

Where are the milestones corresponding to these awards? Clearly, they can only be of form $(i, j, k)$ for $j > c_i$, otherwise we would have claimed them. There is never an award for reaching the goal, so the total number of positions for unreached milestones is $$\sum \max(0, a_i - c_i - 1)$$ 

As there is always at most one award for reaching a milestone, the number of unclaimed awards is at most the number of milestones not reached: $$\sum (a_i - c_i) \leq \sum \max(0, a_i - c_i - 1)$$

As $a_i \geq c_i$, this is equivalent to $$\sum (a_i - c_i) \leq \sum_{a_i > c_i} (a_i - c_i - 1) + \sum_{a_i = c_i} (a_i - c_i) = \sum (a_i - c_i) - \left|\{i \colon a_i > c_i\}\right|$$

Subtracting $\sum (a_i - c_i)$ from both sides and rearranging yields $$ \left|\{i \colon a_i > c_i\}\right| \leq 0$$

so the number of resources that did not reach their goal is $0$, which is a contradiction.

From here the solution is simple. We need to maintain all $m_i$ and the sum of $p_i$. Each update changes at most two $m_i$, so the total complexity is $\mathcal O(n)$.

 
### [1266F - Almost Same Distance](../problems/F._Almost_Same_Distance.md "Codeforces Global Round 6")

There are three cases of how an almost-$k$-uniform set looks like depending on the value of $k$.

* The first case is when $k = 1$. In this case, any maximal almost-$1$-uniform set is a vertex plus all of its neighbours. We can simply check each vertex and find the one with the highest degree.
* The second case is when $k$ is odd and greater than one: $k = 2l + 1$ for $l \geq 1$. Then any almost-$k$-uniform set looks as follows. There is a middle vertex $v$, and every $w \in W$ has distance of $l$ or $l+1$ from $v$. Additionally, at most one of the vertices is in distance $l$, and each $w$ is in a different subtree of $w$.
* The third case is when $k$ is even: $k = 2l$ for $l \geq 1$. Then any almost-$k$-uniform set can be constructed in one of two ways. The first is similar to the previous case, except that all vertices have to be at distance of exactly $l$ from the middle vertex. The second construction begins by selecting a middle edge $\{u, v\}$, removing it from the tree and then finding a set of vertices $W$ such that each $w \in W$ is in the distance of $l$ from either $u$ or $v$ (depending in which subtree it is) and each $w$ is in a different subtree of $u$ or $v$.

Now we need to figure out how to make these constructions efficiently. We begin by calculating $d_v(u)$ – the depth of a subtree $u$ when the tree is rooted at $v$. We compute this for each edge $\{u, v\}$ by using the standard technique of two DFS traversals. Furthermore we use the fact that the answer is monotone with respect to parity: $Ans[i+2] \leq Ans[i]$ for all $i$ – we only calculate the answer in some "interesting" points and then preserve this inequality in the end by taking suffix maximums.

For the odd case, consider a middle vertex $v$. Sort the depths of subtrees of neighbours of $v$. Then, $Ans[2*l+1] \geq x$ if there are at $x-1$ subtrees of depth at least $l+1$ and one additional subtree of depth $l$ or more. By sorting the depths, we can process each middle vertex in $\mathcal O(\mathrm{deg}_v \log \mathrm{deg}(v))$. In total, we have $\mathcal O(n \log n)$ for this step.

For the even case there are two options. The first of these is very similar to the above construction, we just look for $x$ subtrees of depth at least $l$. The second option is more involved. Consider a middle edge $\{u,v\}$. Let $x$ be the number of $d_u(w) \geq l$ for $w \neq v$ and $y$ be the number of $d_v(w) \geq l$ for $w \neq u$. Then we can conclude that $Ans[2*l] \geq x + y$. 

However, we cannot directly calculate the above quantity for each edge, as the processing of each vertex would take time quadratic in its degree. We will do a series of steps to improve upon this.

The first optimization is that in the process of finding $x$ and $y$ above, we also consider $d_v(u)$ and $d_u(v)$, but then subtract $2$ from the answer. Why can we do that? First see that this case is only important if both $x \geq 1$ and $y \geq 1$ – otherwise this is the middle vertex case that is already processed. This means that $\max d_v(w) \geq l$ and hence $d_u(v) \geq l+1 \geq l$. This means that adding $d_u(v)$ to the set increases $x$ by one. The same argument shows that $y$ increases by $1$. 

How does this modification help us? There are two ways of proceeding now.

* We can fix $v$ as one of the endpoints of the middle edge and merge the subtree depths from individual subtrees by taking the maximum and process all neighbours of $u$ at the same time. This alone still does not change the complexity, because we still process each vertex once for each of its neighbours, and this processing takes time at least linear in the degree. Now comes the final step.Perform a centroid decomposition of the tree. When processing $v$ as the fixed end of the middle vertex, consider all $d_v(w)$ for the almost-$k$-universal set, but as the other endpoint of the middle edge we consider only the vertices in the tree where $v$ is the centroid. 

This way, each middle edge is processed exactly once. Each individual vertex is processed once when it is centroid and then once within each centroid tree it belongs to. Since the depth of centroid decomposition is $\mathcal O(\log n)$, we only process each vertex $\mathcal O(\log n)$ times. A single processing every vertex costs $\mathcal O(\mathrm{deg}_v \log \mathrm{deg}_v)$ time (because of sorting the degrees). Thus the total running time is $\mathcal O(n \log^2 n)$, which is the most expensive part of the algorithm. We can also replace the sort with parallel counting sort, and this makes the time $\mathcal O(n \log n)$, but that doesn't run faster in practice.
* For each vertex $u$, store the histogram of $d_u(v)$ in a map. Now, consider each edge separately, and merge calculate the answer naively, using a linear pass through $d_v(u)$ and $d_u(v)$. Why does it work fast? The sum of all $d_u(v)$ for a fixed $u$ equals to $n-1$, so there are at most $\mathcal O(\sqrt n)$ different values in the histogram, which makes the solution $\mathcal O(n \sqrt n)$ in total, and quite fast in practice.
 
### [1266G - Permutation Concatenation](../problems/G._Permutation_Concatenation.md "Codeforces Global Round 6")

Let $LCP$ be the longest-common-prefix array associated with a suffix tree of the sequence $p$. The answer is $|p| \cdot (|p| + 1) - \sum_{i=1}^{p} LCP[i]$.

Let's calculate $c_i$ – the number of positions for which $LCP[j] = i$. 

The following holds: 

* $c_0 = n$
* $c_i = \frac{n!}{(n-i+1)!} * ((n-i) * (n-i) + 1)$ for all $i$ between $1$ and $n-1$
* $c_i = n! - c_{i-n}$ for all $i$ between $n$ and $2n-1$
* $c_i = 0$ for all $i \geq 2n$

Using the above formulas, we can calculate the answer in $\mathcal O(n)$.

Below follows a proof of the above statement. Beware that it is neither 

* complete,
* polished, nor
* interesting

It is just case bashing that I used to convince myself that the pattern I observed during problem preparation is correct, an incomplete transript of my scribbles. Apologies to everybody who expected something nice here. 

Proof

Construct the suffix array such that the terminator is strictly larger than $n$. This doesn't change the answer nor the LCP histogram, and it's easier to reason about.

Here $LCP_n[i]$ denotes the longest-common-prefix of the suffix starting at position $i$ with the next suffix in lexicographic order. We will build the knowledge about the LCP values guided by induction over $n$.

Lemma 1: For every $i$ between $1$ and $n-1$, and for every $k$ between $1$ and $n!$, it holds 

$$LCP_n[k \cdot n + i] = LCP_n[k \cdot n + i - 1] - 1$$

In other words, the LCP value is largest for the suffix aligned on permutation boundary, and shortening the suffix by one decreases the LCP by one. It is obvious that it can't decrease it more. Why does it always decrease by one? TODO

For the above reason, we only need to consider positions divisible by $n$ (if we number from $0$), which we will do in the rest of the text.

Lemma 2: Let $i$ be between $1$ and $n$ and $p = [n, n-1, \dots, i+1, i-1, \dots, 2, 1, i]$. Then $LCP_n[indexof(p)] = n-1$. We call such permutation semidecreasing.

Proof: First, let's see that there is no position which has LCP of $n$ or more (even one that would be lexicographically smaller. Such position needs to have a permutation boundary somewhere, let it be after the number $j$: $[n, n-1, \dots, j] + [j-1, j-2, \dots, 2, 1, i]$. Note that the suffix of the left permutation is in decreasing order and it's first element is $n$. When this happens, the next permutation in must swap $n$ with the preceding element, and hence the prefix of the right permutation cannot be complemetary to the suffix of the left permutation.

Next, see that there is a subarray of $P$ that has common prefix of exactly $n-1$ with this permutation, and the next element is larger. There are two cases: 

* $i = n$, that is, the permutation is $[n-1, n-2, \dots, 2, 1, n]$. Then there is a suffix $[n-1, n-2, \dots, 2, 1, \$]$ at the end of $P$.
* $i \neq n$, a permutation of form $[n, n-1, \dots, i+1, i-1, \dots, 2, 1, i]$. Then there is lexicographically larger string with common prefix of length $n-1$ on the boundary of permutations $[i, n, n-1, \dots, i+1, i-1, \dots, 2, 1]$ and $[i+1, 1, 2, \dots, i-1, i+1, \dots, n-1, n]$

Definition (enlarged permutations)

Consider a permutation on $n$ elements. There are $n+1$ permutation on $n+1$ elements that can be obtained from it by prefixing it with a number from set $\{0.5, 1.5, \dots, n+0.5\}$ and renumbering. 

For example, from $p = [3,1,2,4]$ we obtain $q = \{[1,4,2,3,5], [2,4,1,3,5], [3,4,1,2,5], [4,3,1,2,5], [5,3,1,2,4]\}$. These enlarged permutations will be of great use within the proofs, as we will see soon. Their LCP values will be closely related.

Lemma 3 (enlarging non-semidecreasing permutations): Let $LCP_n[k \cdot n] \geq n$. Then $LCP_{n+1}[(k + m \cdot n!) \cdot (n+1)] + 2$. 

In other words, the LCP of enlarged permutations is two more than that of the original permutation, provided the original permutation was having LCP large enough.

Proof: The permutation with corresponding LCP $n$ and the following one are enlarged with the same number $e$ (because the last permutation of $P_{n-1}$ has $LCP = n-2$ as shown by Lemma 2). The lexicographically following permutation in $P_{n-1}$ can also be found in $P_n$, subject to insertion of element $e$ and renumbering. We will just demonstrate this fact informally.

For example, consider permutation $p = [1,2,4,3]$. The lexicographically following suffix is on the boundary of permutations $q_1 = [3,1,2,4]$ and $q_2 = [3,1,4,2]$. Say we enlarge $p$ to $p' = [3,1,2,5,4]$. Then the boundary of permutations $q'_1 = [4,3,1,2,5]$ and $q'_2 = [4,3,1,5,2]$ contains the subarray $[3,1,2,5,4,3,1]$, which is longer than the original LCP by two. Here, we inserted $[3]$ after the first element and renumbered the old $3$ to $4$ and $4$ to $5$.

Let's characterize the indices where $LCP_n[k \cdot n] < n$. 

Lemma 4 (enlarging semidecreasing permutations): Let $p$ be a semidecreasing permutation on $n$ elements. Consider its enlargement $p^{+}$ – a permutation on $n+1$ elements. There are three cases: 

* $p^{+}$ is also semidecreasing. Then $LCP_{n+1}[indexof(p^{+})] = n$.
* $p$ is the last permutation and the enlargement element is neither $0.5$ nor $n+0.5$. Then $LCP_{n+1}[indexof(p^{+})] = n+2$.
* Otherwise, $LCP_{n+1}[indexof(p^{+})] = n+1$.

Proof: The first case is obvious. 

In the third case, the enlarged permutation is $p^{+} = [i, n+1, n, \dots, i+1, i-1, \dots, 2, 1]$. The lexicographically next permutation is on the boundary of $[1, i, n+1, n, \dots, i+1, i-1, \dots, 2]$ and $[1, i+1, 2, 3, \dots, i, i+2, \dots, n, n+1]$ and the LCP has length $n+2$. This is because there is an extra match of $i$ at the beginning, and $1$ and $i+1$ at the end. 

The second case is similar to the Lemma 3.

Combined the above and induction on $n$ yields:

Lemma 5: For all $k$ it holds $LCP_n[k \cdot n] < 2n$. 

Using induction, we can also count the number of permutations $p_n$ for which $LCP_n[indexof(p_n)] = k$. Thanks to Lemma 1 this is extendable to suffices not aligned with a permutation, yielding the $c_i$ values in the statement. 

 
### [1266H - Red-Blue Graph](../problems/H._Red-Blue_Graph.md "Codeforces Global Round 6")

Consider a fixed query $\{s_i\}_{i=1}^{n-1}$ and $v$. 

Let $x_i$ be the number of times the red arc from $i$ was traversed, and $y_i$ the number of times the blue arc was traversed. The answer for a given query, should the $x_i$ and $y_i$ exist, is the sum of all of them. Let's try to find these values.

When the blue arc going from $i$ is active, we have $x_i = y_i$. Otherwise, $x_i = y_i + 1$. In both cases 

$$x_i = y_i + [s_i = \text{'R'}]\,.$$

Let's denote $B_i$ the set of blue arcs going to $i$, and $R_i$ the set of red arcs going to $i$. For every vertex other than $1$ and the current vertex $v$, the sum of traversals of incoming edges must equal the sum of traversals of outgoing edges. For the current vertex, the sum of incoming traversals is one more than the outgoing, and for vertex $1$ it is the opposite. This gives us 

$$\sum_{r \in R_i} x_r + \sum_{b \in B_i} y_b + [ i = 1 ] = x_i + y_i + [ i = v ]\,.$$

Substituting the $y$s and rearranging yields:

$$2x_i - \sum_{r \in R_i} x_r - \sum_{b \in B_i} x_b = [ s_i = \text{'R'} ] - \sum_{b \in B_i} [s_b = \text{'R'}] + [ i = 1] - [ i = v ]\,.$$

Consider this equality for each $i$ from $1$ to $n-1$. We have $n-1$ equalities for $n-1$ unknowns, written in matrix form $Ax = z$. The value of $A$ does not depend on the actual query – it is determined by the structure of the graph. Let's look at the matrix in more detail. 

On the main diagonal, each value is $2$ – because each vertex has outdegree $2$. Then there are some negative values for incoming edges. Those values are either $-1$, or $-2$ when both the red and blue edge have the same endpoint. In each column, the sum of negative entries is between $0$ and $-2$, because each $-1$ corresponds to and outgoing edge, and because some of the edges may end in $n$, for which we don't have equation.

This combined yields an important observation: the matrix $A$ is irreducibly diagonally dominant. That is, in each column it holds $|a_{ii}| \geq \sum_{i\neq j}|a_{ij}|$, and there is at least one column for which there is strict inequality (because vertex $n$ is reachable). An interesting property of such matrix is that it is non-singular. For every right side $z$ there is thus exactly one solution for $x$.

There are $2^{n-1} \cdot (n - 1)$ possible queries, and each of them corresponds to some pair of vectors $(x, y)$. Clearly, every reachable state corresponds to exactly one pair that describes the process that led to this state. However, it is evident that there are input graphs in which the target vertex is reached in fewer moves, hence some $(x, y)$ pairs must correspond to invalid states. Let's look at which states are invalid.

First, every element of $x$ must be non-negative and integer. Consider a graph on three vertices, where each arc, red or blue, goes to the vertex with higher ID ($1 \rightarrow 2$ and $2 \rightarrow 3$), $v = 2$ and $s = \text{"BB"}$. The solution of this linear system is $x = \left(\frac{1}{2}, 0\right)$. This is clearly not a valid state.

There is one more situation that is invalid. Consider again a graph on three vertices where each red arc goes to the vertex with higher ID as before, but each blue arc is a loop. In this graph, the token moves to the last vertex in two moves, making both red edges active in the process. For query $v = 2$ and $s = \text{"RR"}$, we get a solution $x = \left(1, 0\right)$ and $y = \left(1, 0\right)$. This is not a valid state. The reason for this is the fact that the active arc from $i$ speaks truth about a simple fact – where did the token go the last time it left vertex $i$. The active edge in vertex $1$ is blue, which leads to itself, meaning that the token never left the vertex. But this is a contradiction, because we know it is in vertex $2$. This condition can be phrased as follows:

For every vertex that had the token at least once, the vertex containing the token must be reachable via the active arcs.

These two conditions are in fact necessary and sufficient. 

Let's summarise what we have so far: 

1. Build a system of linear equations and solve for $x$.
2. Check whether all $x$ are non-negative and integer.
3. Verify that the current vertex is reachable from all visited vertices using active edges.
4. If both conditions are true, calculate $y$ and sum all $x$ and $y$ to get the answer. Otherwise, the answer is negative.

There are some technical details left to be solved.

Firstly, as we already noticed, the matrix $A$ doesn't depend on the actual query, only on the graph structure. We can thus precompute its inverse and solve each query as a matrix vector implementation, reducing time per query from $\mathcal O(n^3)$ to $\mathcal O(n^2)$.

Secondly, how do we compute $x$ precisely to check whether they are integers? There are two ways – either we use exact fractions with big integers, or compute everything in modular arithmetic and verify the solution on integers. Since $128$-bit integers are not a thing on codeforces, we either use Schrage's method for the modular multiplication, or use two moduli and Chinese remainder theorem. 

The total complexity is $\mathcal O(n^3 + q \cdot n^2)$.

