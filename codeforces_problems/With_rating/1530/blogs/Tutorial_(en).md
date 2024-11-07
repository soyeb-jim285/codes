# Tutorial_(en)

Hope you enjoyed the round! Editorials for all problems are out now. Also check out [ecnerwala](https://codeforces.com/profile/ecnerwala "Legendary Grandmaster ecnerwala")'s stream where we went through individual problems and discussed the contest as a whole: [https://www.youtube.com/watch?v=5Q4tGWT7p7I](https://codeforces.com/https://www.youtube.com/watch?v=5Q4tGWT7p7I).

 
### [1530A - Binary Decimal](../problems/A._Binary_Decimal.md "Codeforces Round 733 (Div. 1 + Div. 2, based on VK Cup 2021 - Elimination (Engine))")

Let $d$ be the largest decimal digit of $n$.

Note that we need at least $d$ binary decimals to represent $n$ as a sum. Indeed, if we only use $k < d$ binary decimals, no digit of the sum will ever exceed $k$. However, we need at least one digit equal to $d$.

At the same time, it is easy to construct an answer with exactly $d$ terms. Start with all terms equal to $0$, and consider each digit separately. Let the $i$-th digit of $n$ be $a_i$. Pick any $a_i$ terms out of the $d$ terms we have, and add $1$ to their $i$-th digits.

Therefore, the answer is $d$.

 
### [1530B - Putting Plates](../problems/B._Putting_Plates.md "Codeforces Round 733 (Div. 1 + Div. 2, based on VK Cup 2021 - Elimination (Engine))")

There are many ways to solve this problem and even more ways to get it accepted. Let's consider a provable solution that minimizes the amount of casework.

We'll call a valid solution optimal if it has the largest possible number of plates.

Claim. There exists an optimal solution that contains a plate in every corner of the table.

Proof. Consider any optimal solution, and consider all four corners one-by-one in any order.

If a corner contains a plate, do nothing.

If a corner doesn't contain a plate, but either of its neighbors does, move the plate from the neighbor to the corner. Note that we'll still obtain a valid optimal solution.

If neither a corner nor any of its neighbors contain a plate, we can put a plate into the corner, increasing the number of plates and contradicting the optimality of our solution. Thus, this case is impossible.

After considering all four corners, we'll obtain an optimal solution with a plate in every corner of the table, as desired. $\blacksquare$

Once we put a plate in every corner, four sides of the table don't interact anymore, and we can solve the problem on each side independently. Putting as many plates as possible on one side is easy: just leave one empty cell between neighboring plates, and maybe leave two empty cells at the end if the length of the side is even.

 
### [1530C - Pursuit](../problems/C._Pursuit.md "Codeforces Round 733 (Div. 1 + Div. 2, based on VK Cup 2021 - Elimination (Engine))")

The first thing to notice is that since we're chasing Ilya and we want to reach his score as soon as possible, it only makes sense to add $100$'s to our scores and $0$'s to his.

We can also notice that the answer never exceeds $n$. No matter how bad a stage is for us in terms of points, adding a single stage where we score $100$ and Ilya scores $0$ "compensates" it. In particular, in the worst case, when all $a_i = 0$ and all $b_i = 100$, the answer is exactly $n$.

However, if we just add the $100/0$ stages one-by-one and calculate the overall results from scratch every time, our solution will have $O(n^2)$ complexity and that's too much.

There are many ways to optimize the solution.

One of them is to transform the given $a$ and $b$ arrays into arrays of length $101$, containing the count of each score (since we are not interested in the order of the scores). Let $m = 100$ be the maximum achievable score in a stage. Using the transformed arrays, we can calculate the overall scores in $O(m)$ instead of $O(n)$, to lower the final complexity to $O(mn)$.

Alternatively, notice that when we add $100$ to our scores, it just adds $100$ to our overall score except for the case when the total number of completed stages becomes divisible by $4$, when we also need to subtract the score of the worst currently included stage from the sum. We can similarly handle adding $0$ to Ilya's scores. If we sort all our and Ilya's scores at the beginning and maintain a pointer to the current worst included stage in both scoresheets, we can add a new $100/0$ stage and recalculate the totals in $O(1)$.

Finally, we can also notice that whenever adding $k$ stages works for us, adding $k+1$ stages will work too. Thus, we can use binary search on $k$. We can easily check a single value of $k$ in $O(n)$ or $O(n \log n)$, resulting in $O(n \log n)$ or $O(n \log^2 n)$ time complexity.

 
### [1530D - Secret Santa](../problems/D._Secret_Santa.md "Codeforces Round 733 (Div. 1 + Div. 2, based on VK Cup 2021 - Elimination (Engine))")

Let $m$ be the number of different values among $a_i$ (that is, the number of distinct employees someone wishes to make a gift to).

It's easy to see that the answer, $k$, can not exceed $m$: each employee mentioned in $a_i$ allows us to fulfill at most one wish.

It turns out that $k$ can always be equal to $m$, and here's how.

We can visualize the problem in terms of graphs. We are given a functional graph $G$ (for each $i$, there is an edge from $i$ to $a_i$), and we need to find a directed graph that consists of cycles of length at least $2$ and shares as many edges with $G$ as possible.

For each vertex in $G$ that has at least one incoming edge, keep any of these edges and remove the others. Now every vertex has outdegree at most $1$ and indegree at most $1$. Hence, our graph becomes a collection of paths and cycles (isolated vertices are considered to be paths of length $0$).

Let the paths be $P_1, P_2, \ldots, P_t$. For each $i = 1 \ldots t$, create an edge from the end of path $P_i$ to the beginning of path $P_{i \bmod t + 1}$. That is, we are forming a single loop out of all the paths.

This will always work except for one case: if the new loop we are forming has length $1$. It means that we have a single isolated vertex $v$, and all other vertices form valid cycles.

If we ever arrive at this case, we can pick the initial edge going from $v$ to $a_v$, return it to the graph, and remove the other edge going from some vertex $u$ into $a_v$ that we kept. This will break the cycle containing vertex $a_v$ without changing the number of edges shared with the initial graph. Finally, add an edge from $u$ to $v$ closing the cycle, and that will give us a correct answer.

Alternatively, to not ever arrive at the bad case, we can use the knowledge of our future selves at the earlier stage of choosing the edges to keep and remove, and prioritize keeping edges going from vertices with indegree $0$.

Finally, randomized solutions are also possible. For example, we can select the edges to keep at random, write down the sets of vertices with indegree $0$ and vertices with outdegree $0$, shuffle both sets, and try to create an edge from the $i$-th vertex of one set to the $i$-th vertex of the other one. If we fail, and that can only happen when we try to create an edge from a vertex to self, we just start the process from scratch. With an argument similar to counting [derangements](https://codeforces.com/https://en.wikipedia.org/wiki/Derangement), it can be shown that the expected number of iterations until we find a correct answer is constant.

 Tutorial is loading... 
### [1530F - Bingo](../problems/F._Bingo.md "Codeforces Round 733 (Div. 1 + Div. 2, based on VK Cup 2021 - Elimination (Engine))")

Let $l_1, l_2, \ldots, l_{2n+2}$ denote the $2n+2$ possible lines that can be formed. Let $L_i$ denote the event that line $l_i$ is formed, and $\overline{L_i}$ denote the event that line $l_i$ is not formed (i.e., $P(L_i) + P(\overline{L_i}) = 1$). 

Let's find the probability that our table is not winning. It is equal to $P(\overline{L_1} \cap \overline{L_2} \cap \ldots \cap \overline{L_{2n+2}})$.

Note that the following two statements are true: 

* $P(\overline{L_1} \cap \overline{L_2} \cap \ldots \cap \overline{L_{2n+2}}) + P(L_1 \cap \overline{L_2} \cap \ldots \cap \overline{L_{2n+2}}) = P(\overline{L_2} \cap \ldots \cap \overline{L_{2n+2}})$;
* $P(L_1 \cap \overline{L_2} \cap \ldots \cap \overline{L_{2n+2}}) = P(\overline{L_2} \cap \ldots \cap \overline{L_{2n+2}} | L_1) \cdot P(L_1)$.

The first one follows from the law of total probability, and the second one follows from the definition of conditional probability.

These two statements combined allow us to use the following formula: 

 $P(\overline{L_1} \cap \overline{L_2} \cap \ldots \cap \overline{L_{2n+2}}) = P(\overline{L_2} \cap \ldots \cap \overline{L_{2n+2}}) - P(\overline{L_2} \cap \ldots \cap \overline{L_{2n+2}} | L_1) \cdot P(L_1)$. We can apply this formula recursively. Specifically, we can make a function $f(i, S)$, where $S = \{s_1, s_2, \ldots, s_k\}$ is a subset of $\{1, 2, \ldots, i-1\}$, which calculates $P(\overline{L_i} \cap \overline{L_{i+1}} \cap \ldots \cap \overline{L_{2n+2}} | L_{s_1} \cap \ldots \cap L_{s_k})$. For $i = 2n+3$, $f(i, S) = 1$, and for $i \le 2n+2$ we can generalize the formula above as follows: 

 $f(i, S) = f(i + 1, S) - f(i + 1, S \cup \{i\}) \cdot P(L_i | L_{s_1} \cap \ldots \cap L_{s_k})$. Here, $P(L_i | L_{s_1} \cap \ldots \cap L_{s_k})$ is the probability that line $l_i$ is formed given that lines $l_{s_1}, \ldots, l_{s_k}$ are formed. This is equal to the product of probabilities of all cells belonging to $l_i$ which do not belong to any of $l_{s_1}, \ldots, l_{s_k}$.

The answer to the problem, i.e. the probability that our table is winning, is $1 - f(1, \{\})$.

This allows us to implement an $O(2^{2n} \cdot n)$ solution, which is too slow. In fact, this solution is equivalent to applying inclusion-exclusion principle.

To optimize this solution, note that once it becomes easy to calculate $f(i, S)$, we don't have to make any more recursive calls. Why would it become easy to calculate $f(i, S)$ though?

Let's order the lines in such a way that $l_{n+3}, l_{n+4}, \ldots, l_{2n+2}$ are the horizontal lines of the table. Consider a call of the form $f(n + 3, S)$. This call is basically asking: "what is the probability that none of lines $l_{n+3}, l_{n+4}, \ldots, l_{2n+2}$ are formed, given that lines $l_{s_1}, \ldots, L_{s_k}$ are formed?".

Note that the horizontal lines are independent, and we can actually answer this question in $O(n^2)$. Specifically, for any horizontal line, the probability that it is not formed is $1$ minus the product of probabilities of all its cells not belonging to any of $l_{s_1}, \ldots, l_{s_k}$. The overall value of $f(n + 3, S)$ is the product of probabilities for individual horizontal lines.

This way, we have built an $O(2^n \cdot n^2)$ solution. This might be fast enough depending on your implementation, but there are at least two ways to optimize it to $O(2^n \cdot n)$: 

* The first way is to maintain the products of probabilities of untouched cells for horizontal lines on the fly. For simplicity, assume that $l_1$ and $l_2$ are the diagonal lines. For each $i = 3, 4, \ldots, n+2$, after we process (vertical) line $l_i$, we can update the products for all horizontal lines with the cells of $l_i$ (in $O(n)$), make a recursive call, and roll back the updates (in $O(n)$ again). Once we get to $i = n + 3$, instead of going through every cell of the table in $O(n^2)$, we can just multiply $n$ horizontal line products in $O(n)$.
* The second way is to define $g(i, mask)$ ($1 \le i \le n$; $mask$ is a bitmask of size $n$) to be the product of $a_{i, j}$ over all $j$ belonging to $mask$. All values of $g$ can be calculated in $O(2^n \cdot n)$ using dynamic programming: $g(i, 0) = 1$, and $g(i, mask) = g(i, mask \oplus 2^j) \cdot a_{i, j}$, where $j$ is any bit set in $mask$. When we arrive at a $f(n + 3, S)$ call, for each of the $n$ horizontal lines, instead of going through its cells, we can construct the mask of cells the values in which we want to multiply, and use the corresponding value of $g$ in $O(1)$.
 
### [1530G - What a Reversal](../problems/G._What_a_Reversal.md "Codeforces Round 733 (Div. 1 + Div. 2, based on VK Cup 2021 - Elimination (Engine))")

First of all, the number of 1's in $a$ and $b$ must match. Let $c$ be the number of 1's in $a$.

If $k = 0$ or $k > c$, we can not do a meaningful reversal, so we just check if $a = b$.

If $k = c$, we can not change the contents of $a$ between the leftmost and the rightmost 1's, we can only reverse it and shift with regard to the outside 0's. It's easy to check whether $a$ can become equal to $b$ then, and at most $2$ steps are required if so.

Otherwise, suppose $0 < k < c$. Since our operations are reversible, we'll apply a usual trick: we'll transform both strings into some canonical representations in at most $2n$ steps each. If $a$'s and $b$'s canonical representations don't match, we'll prove that there is no solution. Otherwise, we can transform $a$ into $b$ in at most $4n$ steps: transform $a$ into the canonical representation, and then perform the steps transforming $b$ into the canonical representation, but in reverse order. What representation is canonical is for us to determine later.

We'll focus on one string now. Let's write down the lengths of blocks of consecutive 0's in the string. Formally, let $p_0, p_1, p_2, \ldots, p_c$ be the sequence consisting of the number of 0's: before the first 1, between the first and the second 1's, $\ldots$, after the last 1. Note that some $p_i$ might be equal to $0$.

What does a single reversal do to the sequence of blocks? $k+1$ consecutive blocks get reversed, and additionally, the 0's in the leftmost and the rightmost block of these $k+1$ blocks can be redistributed arbitrarily.

It turns out that we don't need more than $k+2$ blocks to achieve our goal (we'll see that later), so let's start with the following. Let $p_i$ be the rightmost block such that $p_i > 0$. If $i \le k+1$, stop. Otherwise, perform two reversals of blocks $p_{i-k}, p_{i-k+1}, \ldots, p_i$, moving all the 0's from $p_i$ to $p_{i-k}$ in the process, effectively making $p_i$ zero, and repeat. After this process, only $p_0, p_1, \ldots, p_{k+1}$ can still be non-zero.

Now, consider what happens if we reverse $p_0, p_1, \ldots, p_k$, and then reverse $p_1, p_2, \ldots, p_{k+1}$ without changing any values: sequence $p_0, p_1, \ldots, p_{k+1}$ will change to $p_k, p_{k+1}, p_0, p_1, \ldots, p_{k-1}$, that is, will cyclically shift by two positions to the right.

Suppose we repeat this pair of reversals $k+1$ times. The $k$-th ($0$-indexed) position initially contains $p_k$, after the first pair it will contain $p_{k-2}$, then $p_{k-4}$ and so on. Assume that $k$ is odd. Then every block will reach the $k$-th position at some point!

Now, during the first reversal in the pair, let's move all 0's from the $k$-th block to the $0$-th block, and keep the second reversal in the pair as is, without changing the values. Then, after $k+1$ pairs of reversals, all the 0's will move to the $0$-th block, that is, all $p_1, p_2, \ldots, p_{k+1}$ will become zero.

We can for sure call this representation — with all of $p_1, p_2, \ldots, p_c$ zeroed out, and $p_0$ equal to the number of 0's in the original string — canonical. It follows that if the number of 1's in $a$ and $b$ is equal to $c$, $k < c$ and $k$ is odd, a solution always exists.

Let's move on to the case when $k$ is even. In this case, since a pair of reversals makes a cyclic shift by $2$, only even-numbered blocks will appear at the $k$-th position. However, notice that this is not a coincidence: when $k$ is even, whatever reversal we perform, even-numbered blocks only interact with even-numbered blocks, and odd-numbered blocks interact with odd-numbered blocks. In particular, the sum of $p_0, p_2, p_4, \ldots$ can never change, and the sum of $p_1, p_3, p_5, \ldots$ can never change either.

Thus, when $k$ is even, let's call the following representation canonical: $p_0$ contains the sum of all initial values of $p_0, p_2, p_4, \ldots$; $p_{k+1}$ contains the sum of all initial values of $p_1, p_3, p_5, \ldots$; and all the other $p_i$'s are zeros.

We can reach this representation in a similar way to the odd $k$ case, using pairs of reversals.

Note that similar to the $k$-th position which contains blocks $p_k, p_{k-2}, p_{k-4}, \ldots$ during the process, the $1$-st position contains blocks $p_1, p_{k+1}, p_{k-1}, p_{k-3}, \ldots$ during the process.

During the first reversal in each pair, as in the previous case, we'll move all the 0's from the $k$-th block to the $0$-th block. During the second reversal in each pair, we'll move all the 0's from the $1$-st block to the $k+1$-th block. After $k+1$ pairs of reversals (actually just $\frac{k}{2}$ pairs are enough), we'll zero out all the values except for $p_0$ and $p_{k+1}$.

All in all, we have found a way to reach the canonical representation in $2c \le 2n$ steps, as desired.

 
### [1530H - Turing's Award](../problems/H._Turing's_Award.md "Codeforces Round 733 (Div. 1 + Div. 2, based on VK Cup 2021 - Elimination (Engine))")

Let's look at Alan's moves in reverse. The process can be reformulated as follows. Initially, $a_n$ is written down into the cell where Alan is located. Then, for each $i$ from $n-1$ down to $1$, first Alan decides whether to stay or move to a neighboring cell, and then $a_i$ is written down into Alan's cell only if the cell is empty. This way, it's easier to reason about the process since numbers never get overwritten.

The state at any moment can be described by the current sequence $b$ and Alan's position inside this sequence. The only way we can change $b$ is by appending a number to either end.

Suppose we have decided which elements of the permutation appear in the final sequence $b$, and for each element, whether it gets appended to the front or to the back. Let's call these elements useful. As a special case, $a_n$ is always useful. Two things to notice here: 

* We don't care about intermediate Alan's positions, as long as he has enough time to move between consecutive useful elements. For example, suppose $a_i$ gets appended to the front of $b$ (the other case is symmetrical), and there are exactly $k$ useful elements among $a_i, a_{i+1}, \ldots, a_n$. Let $a_j$ be the "next" useful element, that is, $j < i$ and there are no useful elements between $a_j$ and $a_i$.
	+ If $a_j$ should be appended to the front of $b$, Alan can just stay in the same cell for elements $a_{i-1}, a_{i-2}, \ldots, a_{j+1}$, and then move to the left to append $a_j$. Here, Alan is always in time.
	+ If $a_j$ should be appended to the back of $b$, Alan has to move to the other end of $b$, and he needs to make $k$ steps to the right. This is possible if and only if $i - j \ge k$.
* Consider a useful element that neither belongs to the LIS (longest increasing subsequence) of $b$, nor is $a_n$. We can always change this element's status to "not useful", and it won't harm us in any way. Thus, we can assume that all of the useful elements, except for maybe $a_n$, belong to the LIS.

Let's casework on whether $a_n$ belongs to the LIS. From now on, we will assume that $a_n$ does belong to the LIS. However, the other case differs just slightly.

Armed with the above observations, we can solve the problem using dynamic programming: 

* $f_L(k, i)$: suppose $a_i$ is a useful element that gets appended to the front, and there are $k$ useful elements among $a_i, a_{i+1}, \ldots, a_n$. Then $f_L(k, i)$ is the smallest possible value of the element at the back of the LIS.
* $f_R(k, i)$: suppose $a_i$ is a useful element that gets appended to the back, and there are $k$ useful elements among $a_i, a_{i+1}, \ldots, a_n$. Then $f_R(k, i)$ is the largest possible value of the element at the front of the LIS.

Note that some DP states might be unreachable: in this case, we set $f_L(\ldots)$ to $+\infty$ and $f_R(\ldots)$ to $-\infty$.

Consider transitions from $f_L(k, i)$ (transitions from $f_R(k, i)$ are similar): 

* For any $j < i$ such that $a_j < a_i$, we can set $f_L(k + 1, j)$ to $f_L(k, i)$.
* For any $j \le i - k$ such that $a_j > f_L(k, i)$, we can set $f_R(k + 1, j)$ to $a_i$.

 (If we can set $f(\ldots)$ to multiple values, we should choose the smallest one for $f_L$ and the largest one for $f_R$.)Thus, we can transition from $f(k, \ldots)$ to $f(k + 1, \ldots)$ in $O(n^2)$ time. We can optimize it to $O(n \log n)$ if we sweep through the permutation in reverse order ($i = n, n - 1, \ldots, 1$) and maintain a segment tree for minimum/maximum indexed with element values.

The answer to the problem is the largest $k$ such that $f_L(k, i)$ or $f_R(k, i)$ is a reachable state for some $i$. The complexity of our solution is thus $O(kn \log n)$.

Finally, note that the part of $b$ to the left of $a_n$ forms an increasing subsequence of $a$, and the part of $b$ to the right of $a_n$ forms a decreasing subsequence of $a$. It is well-known that the expected length of the longest increasing/decreasing subsequence in a random permutation is $O(\sqrt{n})$. Therefore, our solution works in $O(n^{1.5} \log n)$ on average.

