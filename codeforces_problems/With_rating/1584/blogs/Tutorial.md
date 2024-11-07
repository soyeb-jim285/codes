# Tutorial


### [1584A - Mathematical Addition](../problems/A._Mathematical_Addition.md "Technocup 2022 - Elimination Round 2")

We have the equation: $\frac{x}{u} + \frac{y}{v} =\frac{x +y}{u+ v}.$

Let's multiply the left and right parts by $u*v*(u + v)$.

Received: $x * v * (u + v) + y * u * (u + v) = (x + y) * u * v$.

After opening the brackets and simplifying, we have: $x *v^2 + y*u^2 = 0$.

One of the solutions to this equation is $x = -u^2$, $y = v^2$

 
### [1584B - Coloring Rectangles](../problems/B._Coloring_Rectangles.md "Technocup 2022 - Elimination Round 2")

Rectangles after cutting will be painted in a chess coloring. So, if the area is even, then the number of cells of different colors is the same, and if it is odd, then it differs by exactly $1$.

Let's find out what part the colored cells occupy in relation to all of them. For an even area, this ratio is always $\frac{1}{2}$. For odd $\frac{S - 1}{2 \cdot S}$. The smaller the odd area, the smaller the ratio. An area equal to $1$ cannot be obtained, so the best ratio is $\frac{1}{3}$ and is achieved with an area equal to $3$.

Then we get the lower estimate for the answer: $answer \geq n \cdot m \cdot \frac{1}{3}$. Great!

We know that the answer is integer, so if we manage to construct such a cut that it is necessary to color exactly such a $cnt$ of cells that$\frac{n \cdot m}{3} \leq cnt < \frac{n \cdot m}{3} + 1$, then $cnt$ will be the answer. After all, $cnt$ is the minimum integer value satisfying the estimate.

If one of the sides is divisible by $3$, then it is obvious how to cut into $1 \times 3$ rectangles and get the perfect answer.

If the remains of sides $1$ and $1$ or $2$ and $2$, then you can cut into $1 \times 3$ rectangles and one rectangle with an area of $4$, in which you need to paint over $2$ cells. Then the answer also fits the assessment.

If the remains of sides $1$ and $2$, then after cutting into $1 \times 3$ rectangles, a rectangle will remain $1 \times 2$, in which you need to paint one cell. The answer also fits the assessment.

For all pairs of remains, there is a way to construct an answer satisfying the inequality. Therefore, the answer is $ \lceil \frac{n \cdot m}{3} \rceil$

 
### [1584C - Two Arrays](../problems/C._Two_Arrays.md "Technocup 2022 - Elimination Round 2")

Let's sort the arrays first.

Let's check the two smallest elements in the arrays and investigate their behavior. First, obviously, if $a_1 + 1 < b_1$ (as nothing can be matched with $a_1$) or $a_1 > b_1$ (as nothing can be matched with $b_1$) the answer is No. Then, it's possible that $a_1 = b_1 = x$. In this case, we have to have at least one $x$ in the array $a$ at the end. Hence, we can leave $a_1$ untouched, as it already suits to $b_1$. It's also possible that $a_1 + 1 = b_1$. Here we have to increase $a_1$ by $1$. In both cases, the task is reduced to the smallest one.

Going to the exact solution from this logic, we just have to sort both arrays and check that for each $1 \leq i \leq n$ it's $a_i = b_i$ or $a_i + 1 = b_i$.

The complexity of the solution is $O(n log(n))$.

 
### [1584D - Guess the Permutation](../problems/D._Guess_the_Permutation.md "Technocup 2022 - Elimination Round 2")

Note that the number of inversions on decreasing sequence of length $l$ is $(_2^l)$.

As we reversed two non-overlaping subsegments, the number of inversions on each subsegment is equal to sum of number of inversions of parts of reversed subsegments, which are decreasing.

First of all, let's find $A := (_2^{k-j+1}) + (_2^{j-i})$ — total number of inversions in sequence. We use 1 question for that.

Now let's look on the number of inversions on subsegment [$x$, $n$]. If this number is less than A, then not both reversed subsegments fit entirely, so $i < x$, otherwise $i \geq x$.

Now we can apply binnary search to find $i$. We use $log_2(n)$ questions here.

Now let's ask the number of inversions on subsegment [$i+1$, $n$], let's call this number B. We use $1$ question here. From the structure of sequence: $A-B$ = $|\{x | x > i, a_x < a_i\}|$ = $|[i+1, j-1]|$ = $j - i - 1$. 

Now we can find $j - i$, $j$ and $(_2^{j - i})$, due to the definition of A, we find $(_2^{k - j + 1})$.

Finaly, we can solve quadratic equation for $k-j+1$ and get $k$.

Overall, we used $log_2(n) + 2 \leq 32$ questions, but we gave you a bit more, in case your solution uses few more questions on some stage.

 
### [1584E - Game with Stones](../problems/E._Game_with_Stones.md "Technocup 2022 - Elimination Round 2")

This game has greedy strategy: look at first pile, all its stones have to be matched with stones from next pile, because it is its only adjacent pile. If pile is non-empty and there are no next pile, or next pile is smaller than current, Bob loses. Otherwise, Bob makes current pile empty, and remove corresponding number of stones from next pile. Now Bob plays the same game as if had one pile less, we can remove first pile without changing game. Bob wins if at the moment he reduced game to one pile it's already empty.

Now let's iteratively define array $c$, where $c_i$ — number of stones left in the $i$-th after removing $1, \ldots, i - 1$ piles, according to greedy strategy. Let $c_0 = 0$, then $c_i = a_i - c_{i - 1}$. 

If array contains only positive numbers, then it means that Bob is able to remove piles all the way over. Otherwise, let $t$ be the first moment with $c_t < 0$, this means that Bob was able to remove piles until he meet $t$-th pile and $c_{t-1} > a_t$ happened, so Bob loses. To check that last pile is empty, we need to check if $c_n = 0$.

So we have criteria of winning subsequence: $c_i \geq 0$ for all $i$, $c_n = 0$.

Let's expand recursive notation of $c_i$: $c_i = a_i - a_{i - 1} + a_{i - 2} -\ldots + (-1)^{i-1} \cdot a_1$.

We will solve problem separately for different $l$ — left bound of subsegment. Let's define sequence $a^l := a_l, a_{l+1} \ldots a_n$, $a_i^l = a_{l + i - 1}$. It has similar array $c^l$. We will find first position of negative number in $c^l$ —$t$ ($c_t^l < 0$). And then count how may zeros are on prefix [$1$, $t-1$]. This will give us number of winning subsegemtns with form $[l, r]$, sum over all $l$ will give us answer for the problem.

Note, that $c_i^l = a_i^l - a_{i - 1}^l + \ldots + (-1)^{i-1} \cdot a_1^l = a_{l+i-1} - a_{l+i-2} + \ldots + (-1)^{i-1} \cdot a_{l} = c_{l+i-1} + (-1)^{i-1} \cdot c_{l - 1}$. 

Note, that $c_i^l < 0$ if and only if $c_{l + i - 1} < (-1)^{i - 1} \cdot c_{l - 1}$. Let's divide problem by parity of indexes. Now to find first position of negative number in $c^l$ we should find first position of "number less than x" on suffix of $c$. This can be done many ways, for example, by descending through segment tree (segment tree for each parity).

Note, that $c_i^l = 0$, if and only if $c_{l + i - 1} = (-1)^{i - 1} \cdot c_{l - 1}$. Same division of problem by parity. Now to count number of zeros on subsegment of $c_l$ we should count number of "equals to x" on subsegment of $c$. This can be done by storing all positions of each $c_i$ in some container (one for each parity) and binnary search.

Overall complexity of the solution : $\mathcal{O}(n \cdot log(n))$ 

 
### [1584F - Strange LCS](../problems/F._Strange_LCS.md "Technocup 2022 - Elimination Round 2")

Let's define efinegraph with vertexes ($c$, $msk$), where $chr$ denoting some character, ans $mask$ is $n$-bit mask of occasions ($i$-th bit is set to $1$ if and only if we consider second occasion of $c$ in $i$-th string). Not all $mask$ are possible for some $c$ since there could be less than $2$ occasions. Note: vertex define choise of character and positions of this character in all strings. 

Note, that graph has $\mathcal{O}(|\Sigma| \cdot 2^n)$ vertices.

Let's define strict comparison (<) of vertices:($chr1$, $msk1$) < ($char2$, $msk2$) if and only if positions chosen by first vertex are stricly lefter than ones chosen by second (for all strings). Let's define another comparison ($\leq$) the same way, but allow some position to be equal. Note: strict comparison is anti-reflexive, both comparison are transitive and this stands ($a$ $\leq$ $b$ < $c$ $\Rightarrow$ $a$ < $c$).

Graph contains directed edges from one vertex to another, if and only if first is smaller by defined comparison. Note: graph is acyclic, because of transitivity of pair comparison.

Note: that for every common subsequence there is unique corresponding path in defined graph and vice versa. So we need to find longest path in this graph. Vertex-length of path will be equal to the length of corresponding subsequence.

We want to calculate $dp$($c$, $msk$) – length of longest path starting from this vertex. This $dp$ is easy to calulate on DAG, but number of edges is too big. We want to remove some edges without changing values of $dp$. Note: if removal of edge doesn't change $dp$ of its starting point, when it doesn't change $dp$ at all. 

Let's look at arbitrary vertex $(c, msk)$, that has at least one outgoing edge and some longest path starting from it (it has at least one edge): [$(c, msk) \rightarrow (c2, msk2) \rightarrow \ldots$]. Suppose there exists mask $MidMsk \neq msk2$, such that: (c, mask) < ($c2$, $MidMsk$) $\leq$ ($c2$, $msk2$). By the qualities of defined comparisons, we can change second vertex in longest path to ($c2$, $MidMsk$). 

Now let's find mask for fixed $c2$ which correspond to choise of leftmost positions righter than positions chosen by ($c$, $msk$). It can be found in $\mathcal{O}(n)$ time. As we notices earlier, without loss of generality, longest path (with fixed $c2$) goes through this vertex , so we can harmlessly remove all edges going from current vertex to the vertices with character $c2$, but diffrent mask. This can be done for every character.

Now graph each vertex has $\mathcal{O}(|\Sigma|)$ outgoing edges, so $dp$ can be calculated fast enough. Subsequence itself can be easily found now.

Note: there is no need for graph in solution, it's just abstraction for better understanding.

Note: we don't have to calculate $dp$ for all vertices, we only need to find $dp(c, 0)$ for all $c$, it can be proven by applying same logic.

Overall complexity: $\mathcal{O}(n \cdot |\Sigma|^2 \cdot 2^n)$

 
### [1584G - Eligible Segments](../problems/G._Eligible_Segments.md "Technocup 2022 - Elimination Round 2")

The distance from point $P$ to segment $[AB]$ is equal to the maximum of the distance from point $P$ to ray $[AB)$ and the distance from point $P$ to ray $[BA)$. 

Let's fix a point $P_i$. Now we have to find all points $P_j$ such that distance from every point $P_k (1 \le k \le n)$ to the ray $[P_i, P_j)$ is less than $R$.

For every point $P_k$ let's build two tangents from point $P_i$ to the circle with the center in the point $P_k$ and radius $R$. These tangents form an angle $A_k$. The distance from the point $P_k (1 \le k \le n)$ to the ray $[P_i, P_j)$ is less than $R$ iff the ray $[P_i, P_j)$ lies inside the angle $A_k$. So we can build all these angles $A_k$ and intersect them, after that, we only have to check that the ray $[P_i, P_j)$ lies inside the intersection of all angles for all $1 \le j \le n$.

Time complexity: $O(n^2)$.

 
### [1588F - Jumping Through the Array](https://codeforces.com/contest/1588/problem/F "Codeforces Round 755 (Div. 1, based on Technocup 2022 Elimination Round 2)")

Let's call $B = \lfloor \sqrt{n} \rfloor$.

Let's divide an array $a$ into consecutive blocks of size $B$.

To answer the query we will have to sum $O(B)$ $a_i$ near the segment's bounds and $O(\frac{n}{B})$ sums on blocks. Let's try to calculate them fast.

There are two types of cycles:

* small: with length $< B$
* big: with length $\geq B$

If there is a second type query for the small cycle it is easy to make it in $O(B)$ time: let's iterate over cycle's elements and add $x$ into its $a_i$ and into its array's block sum.

It is harder to deal with big cycles. Let's divide each big cycle into blocks, each having the size in $[B, 2B - 1]$. Initially, it is possible. After each query of type $3$ it is possible to reconstruct this division fast:

* Let's split two blocks with $i$ and $j$. After that, it is possible to reconstruct the divisions of each new cycle into blocks.
* After that, we should avoid small blocks (with size $< B$). Let's merge two consecutive blocks if one of them has the size $< B$. After that, if the total block has size $\geq 2B$ let's split it into two equal blocks.
* Someone calls this method split-rebuild.

So, maintaining this structure we will have at most $\frac{n}{B}$ cycle blocks at any moment. If there is a second type query for the big cycle let's add $x$ to the cycle blocks for this cycle. To consider these values while answering the first type query let's maintain the last structure:

* For each cycle block $t$ let's calculate the values $pref_{t,0}, pref_{t,1}, \ldots, pref_{t,\lceil \frac{n}{B} \rceil}$, where $pref_{t,i}$ is the number of elements from the $t$-th cycle block in the first $i$ array's blocks.

Using these values it is easy to consider additions to the cycle blocks in the subsegments sums queries.

And the values of $pref$ can be recalculated during the cycle's updates because we make $O(1)$ splits and merges. During each split or merge we should recalculate $pref$ for $O(1)$ rows (and this can be done in $O(\frac{n}{B})$ for one $t$). Also during each split or merge we should zero additions to blocks in operations just pushing the added value into the elements of the block (their number is smaller than $2B$).

The total complexity of the solution is $O(n \sqrt{n})$.

