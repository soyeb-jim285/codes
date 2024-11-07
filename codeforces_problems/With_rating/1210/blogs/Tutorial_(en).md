# Tutorial_(en)


### [1230A - Dawid and Bags of Candies](https://codeforces.com/contest/1230/problem/A "Codeforces Round 588 (Div. 2)")

Let's firstly sort all the bags in non-decreasing order of capacities. As the order of friends doesn't matter, it turns out that one of them should take only the biggest bag or the biggest and the smallest bag. It's easy to check if any of these possibilities works.

 
### [1230B - Ania and Minimizing](https://codeforces.com/contest/1230/problem/B "Codeforces Round 588 (Div. 2)")

There are a couple of corner cases: if $k=0$, we cannot change $S$. Otherwise, if $n=1$, we can change $S$ into $0$.

Now assume that $n \geq 2$ and $k \geq 1$. A simple greedy approach works here: we can iterate over the digits from left to right and change them to the lowest possible digits as long as we still can change anything. The leftmost digit can be only changed to $1$, and all the remaining digits should be changed to $0$. We need to remember not to fix the digits that are currently the lowest possible.

For instance, if $k=4$, the number $S=450456450$ will be changed to $\color{blue}{\bf 10}0\color{blue}{\bf00}6450$ (the modified digits are marked blue).

The algorithm can be easily implemented in $O(n)$ time.

 
### [1230C - Anadi and Domino](https://codeforces.com/contest/1230/problem/C "Codeforces Round 588 (Div. 2)")

We can imagine writing an integer from $1$ to $6$ in each vertex — if we write an integer $x$ in vertex $v$, then we want each half of the domino directed toward vertex $v$ to have exactly $x$ dots. Then, it's easy to calculate the result — we should place as many different dominoes as possible according to the written numbers so that we won't place any domino multiple times.

If $n \leq 6$, then it's optimal to write different numbers everywhere, so the result will be equal to $m$ (the number of edges).

If $n=7$, then it's optimal to use only two equal numbers and it doesn't matter which number appears twice. Then, we can iterate over the pair of vertices with the same number and then easily calculate the result.

 
### [1229A - Marcin and Training Camp](https://codeforces.com/contest/1229/problem/A "Codeforces Round 588 (Div. 1)")

If there are multiple people with the same set of skills (i.e., the same values of $a$), it's optimal to take each of them to the camp as they won't think they're better than everyone else.

Now consider a person $i$ which has a different set of skills than everyone else. 

* If they have a strictly smaller set of skills than someone already in the group, they can safely be included in the group.
* If they don't, we can prove that they can't ever be included in the group.

This allows us to implement a simple $O(n^2)$ solution: first take all people that have an equal set of skills as someone else, and then include everyone else who has a strictly smaller set of skills than someone already in the group.

 
### [1229B - Kamil and Making a Stream](https://codeforces.com/contest/1229/problem/B "Codeforces Round 588 (Div. 1)")

Let's prove the following observation:

Fix a vertex $v$ (the bottom end of the path), and consider all its ancestors $u$. The number of distinct values of $f(u,v)$ is at most $\log_2(10^{12})$.

To prove this observation, consider the ancestors of $v$ in the order from the bottom-most to top-most: $v=u_0, u_1, u_2, u_3, \dots, u_k=1$. Notice that $f(u_i, v) = \gcd(x_{u_0}, x_{u_1}, x_{u_2}, \dots, x_{u_i})$. Therefore, each consecutive $u_i$ adds another value $x_{u, i}$ to the gcd of all numbers. If a gcd of all numbers changes, it must be a divisor of the previous gcd. Therefore, it's easy to see that it can change at most $\log_2(10^{12})$ times.

We can now implement a depth-first search. If we invoke a recursive call in vertex $v$, we will receive the multiset of values $\{f(u, v) \mid u\text{ is an ancestor of }v\}$. We add all these values to the result and run the recursive calls in the children.

This is currently $O(n^2)$ or $O(n^2\log n)$, but we can improve it by actually using a map from the distinct values in the multiset to the number of their occurrences. Then each map will have no more than $O\log_2(10^{12})$ elements. As we need to compute $\gcd$'s throughout the algorithm, this solution allows us to solve the problem in $O(n\log^2(10^{12}))$ time and in $O(n \log(10^{12}))$ memory.

It's also possible to solve the problem using jump-pointers. Each jump-pointer will additionally hold the greatest common divisor of all the numbers we jump over when following the pointer.

 
### [1229C - Konrad and Company Evaluation](https://codeforces.com/contest/1229/problem/C "Codeforces Round 588 (Div. 1)")

Let's imagine that the graph is directed as in the sample explanation (and edge $u\to v$ exists if $u$ brags to $v$). We have to deal with two kinds of queries: 

* Count the number of three-vertex directed paths.
* Change the direction of a single edge in the graph.

If we remember indegrees $\mathrm{indeg}$ and outdegrees $\mathrm{outdeg}$ for each vertex, then we can see that the result for the first query is $\sum_{v} \mathrm{indeg}(v) \cdot \mathrm{outdeg}(v)$. It's also easy to maintain the in- and outdegrees for each vertex when updating the graph using the second query.

Let's get back to the original problem. If a person $v$ becomes the best-paid employee in the company, we can model it as taking all the edges ending at $v$, and reversing their direction.

It turns out that throughout the whole simulation, this edge-reversal won't happen too many times! Let's sort the vertices from left to right by their degree in the decreasing order. It now turns out that each vertex is adjacent with at most $\sqrt{2m}$ vertices to its left: if there were more, it would mean that there exist more that $\sqrt{2m}$ vertices with their degrees larger than $\sqrt{2m}$. It would mean that the sum of degrees of all the vertices in the graph is more than $\sqrt{2m} \cdot \sqrt{2m} = 2m$ — a contradiction.

Define the potential of the graph as the number of edges which point from left to right. If we revise the salary for employee $v$, we might need to flip many edges, but at most $\sqrt{2m}$ new edges will start pointing from left to right. The remaining edges incident to $v$ will now point from right to left. Therefore, we do the number of swaps proportional to the change of the potential, and the potential at each query can increase at most by $\sqrt{2m}$. The potential at the beginning could be as high as $m$, and therefore the total number of swaps throughout the algorithm is at most $m + q\sqrt{2m}$. 

The algorithm can be therefore implemented in $O(n + m + q\sqrt{m})$ time. Note that we should store the adjacency list of the directed graph in vectors — when we revise the salary of employee $v$, we should process all edges entering $v$ and simply clear the corresponding vector. Storing the graph in sets or hashsets has worse complexity or a huge constant factor and will likely time out.

 
### [1229D - Wojtek and Card Tricks](https://codeforces.com/contest/1229/problem/D "Codeforces Round 588 (Div. 1)")

Let's first enumerate all permutations by integers from $0$ to $k!-1$. Now, we can memoize all possible compositions of two permutations in an $k! \times k!$ array. This will allow us to compose any two permutations in constant time.

Let $l$ and $r$ be the left and right ends of any interval. We'll compute the sum in the problem statement for each $r$ separately. Set some $r$. Notice that if there are multiple occurrences of the same permutation before $r$, only the latest occurrence is important for us — any earlier occurrences won't help us create any new decks. Therefore, for each of $k!$ possible permutations, we can maintain its latest occurrence before $r$. We can also maintain a sorted list of such latest occurrences among all the permutations — from the latest to the earliest. This creates $k!$ intervals of value $l$ where the number of possible decks can't change.

Now, we only need to be able to maintain the set of decks (permutations) we can generate using the tricks we already know. Initially, we can generate only one deck (with the cards in sorted order). When learning a new trick, one of two things can happen:

* If a single application of the new trick generates a deck we can already create using previous tricks, this trick gives us nothing — we can simply simulate this new trick by a sequence of old tricks.
* If this trick $T$ creates a brand-new deck of cards, we need to recalculate the set of achievable permutations. We maintain a set of generators $\{g_1, g_2, \dots, g_a\}$, $g_a = T$ (these are the tricks that have increased the number of decks we can generate). Now, each deck in the new set of decks can be created using this repeatedly applying the generators from this set. We can use BFS/DFS to compute the new decks.

This is obviously a correct algorithm, but why does it work fast enough? If you know some abstract algebra, then you can notice that what we're computing here is a chain of subgroups in a symmetric group $S_k$ (a group of all permutations of $k$ elements). By Lagrange's theorem, if a group $G$ is a subgroup of a finite group $H$, then $|H|$ is a multiple of $|G|$. Therefore, each new set of achievable decks is at least twice as large as the previous one. It means that:

* The set of generators is always at most as large as $\log_2(k!)$,
* The time needed to compute all the subgroups can be bounded by $\log_2(k!)$ times the sizes of all subgroups in the chain. As the sizes are growing exponentially large, the sum of sizes is at most $O(k!)$. Therefore, all the additions take at most $O(k! \log k)$ time.

The time complexity of the intended solution was therefore $O((k!)^2 + nk!k)$.

The solution can be sped up significantly by computing all possible sets of achievable decks (i.e., all subgroups of $S_k$) — for $k = 5$, there are only $156$ of them. Some preprocessing will then allow us to add a single element to the subgroup in constant time. This was however not necessary to get AC.

 
### [1229E1 - Marek and Matching (easy version)](https://codeforces.com/contest/1229/problem/E1 "Codeforces Round 588 (Div. 1)")

Let's first discuss one of possible solutions for the easy subtask.

Let's assume that $n=6$ (all smaller $n$'s can be easily reduced to this case). There are two layers of vertices: left $L = \{\ell_1, \ell_2, \dots, \ell_6\}$ and right $R = \{r_1, r_2, \dots, r_6\}$. Let's do meet-in-the-middle on the right layer: $R_a = \{r_1, r_2, r_3\}$ and $R_b = \{r_4, r_5, r_6\}$.

Consider two parts of the graph: between $L$ and $R_a$, and between $L$ and $R_b$. Each of them has $n \cdot \frac{n}{2} = 18$ edges, so we can try all subsets of edges in each of them separately. For each such subset:

* Compute the probability that we'll generate exactly this subset of edges.
* Find all $3$-element subsets of $L$ which can match perfectly with the currently considered half of $R$.

This can be done easily in $2^{18} \times \mathrm{poly}(n)$ time.

Now, here's a trick — there are only ${6 \choose 3} = 20$ three-element subsets of $L$! Therefore, for each $20$-element mask $M$, we can find: 

* $p_a(M)$ — the probability that the set of three-element subsets of $L$ matching perfectly with $R_a$ is exactly $M$,
* $p_b(M)$ — the probability that the set of three-element subsets of $L$ whose complements match perfectly with $R_b$ is exactly $M$.

Let's find the probability that there is no perfect matching in the graph. We can see that it's $\sum_{A \cap B = \varnothing} p_a(A) p_b(B)$ where $A$ and $B$ are $20$-element masks. This can be solved easily using SOS dynamic programming technique. If we let $q_b(X) := \sum_{Y \subseteq X} p_b(X)$, then the required sum is $\sum_{A \subseteq [20]} p_a(A) q_b([20] \setminus A)$ where $[20] = \{1,2,3,\dots,20\}$.

Therefore, this algorithm allows us to solve the easy version of the problem in $2^{18} \cdot \mathrm{poly}(n) + 2^{20} \cdot 20$ time.

 Tutorial is loading... 
### [1229F - Mateusz and Escape Room](https://codeforces.com/contest/1229/problem/F "Codeforces Round 588 (Div. 1)")

Let's introduce the variables $x_1, x_2, \dots, x_n$ where $x_i$ is the number of coins passed from the $i$-th to the $(i+1)$-th scale (or, $x_i < 0$, it means that $-x_i$ coins are passed from the $(i+1)$-th to the $i$-th scale). We can now create the following conditions regarding the final number of stones on each scale:

$$ a_i - x_i + x_{i - 1} \in [l_i, r_i] \qquad \text{for all } i.$$

It turns out that for any sequence integers $x_1, \dots, x_n$ satisfying the inequalities before, we can create a sequence of $|x_1| + |x_2| + \dots + |x_n|$ moves satisfying all the conditions in the statement! In order to see this, consider a few cases:

* If $x_1, x_2, \dots, x_n > 0$, then we take any coin and make a full lap with it along the circle in the order of increasing $i$'s. We can now decrease each $x_i$ by one.
* If $x_1, x_2, \dots, x_n < 0$, we can do the similar thing, but we're decreasing $i$'s.
* In the remaining cases, we can pick a scale $i$ that won't receive coins anymore (that is, $x_i \geq 0$ and $x_{i-1} \leq 0$) and it still has some coins to distribute ($x_i > 0$ or $x_{i-1} < 0$). If $x_i > 0$, take a single coin, put it on the $(i+1)$-th scale, and decrease $x_i$ by one. If $x_{i-1} < 0$, take a coin, put it on the $(i-1)$-th scale, and increase $x_i$ by one.

By following these operations, we will create the final configuration in $|x_1| + \dots + |x_n|$ moves.

Therefore, we need to minimize this value. Let's try to guess $x_1$ and try to optimize $|x_1| + |x_2| + \dots + |x_n|$ for some fixed $x_1$. The simplest way is to write a dynamic programming: $dp(i, x_i) = $ the minimum value of $|x_1| + |x_2| + \dots + |x_i|$ given a value of $x_i$ and such that the final numbers of stones on the second, third, fourth, $\dots$, $i$-th scale are satisfied. To progress, we iterate over the possible values $x_{i+1}$ such that $a_i - x_i + x_{i - 1} \in [l_i, r_i]$ and compute the best value of $dp(i+1, x_{i+1})$. Notice that the initial state is $dp(1, x_1) = |x_1|$ and $dp(1, \star) = +\infty$ everywhere else. To compute the result, we must take the minimum value $dp(n, x_n)$ for $x_n$ satisfying $a_1 - x_1 + x_n \in [l_1, r_1]$.

How to improve this DP? First of all, we'll try to maintain the $dp(i, x_i)$ as a function on $x_i$. In order to compute $dp(i+1, x)$ from $dp(i, x)$, we'll need to:

* Shift the function (left or right).
* Given a function $f$ and a constant $t$, compute $g(x) := \min_{y \in [x, x+t]} f(x)$.
* Given a function $f$, compute $g(x) := f(x) + |x|$.

It turns out that after each of these operations, the function remains convex. We can therefore say that the function is linear on some segments with increasing slopes. Therefore, we can maintain a function as a set of segments, each segment described by its length and its slope.

How to describe the second operation? We can see that it's actually adding a segment with slope $0$ and length $t$ to the function. Meanwhile, the third operation is splitting the function into two parts: for negative and positive $x$. We need to decrease the slopes in the first part by $1$, and increase the slopes in the second part by $1$.

All these operations can be implemented on any balanced BST in $O(\log n)$ time. Therefore, the whole subproblem (for fixed $x_1$) can be solved in $O(n \log n)$ time.

How to solve the general problem? It turns out that...

Lemma. The function $F$ mapping $x_1$ into the optimal result for a fixed $x_1$ is convex.

Proof will be added if anyone requests it. The basic idea is to prove that: (1) the answer won't change if $x_i$ could be any arbitrary real values, (2) if $(a_1, \dots, a_n)$ and $(b_1, \dots, b_n)$ are good candidates for $(x_1, \dots, x_n)$, so is $\left(\frac{a_1+b_1}{2}, \dots, \frac{a_n+b_n}{2}\right)$. We can use that to show that $\frac{F(a_1) + F(b_1)}{2} \ge F\left(\frac{a_1+b_1}{2}\right)$.

Therefore, we can run a ternary search on $x_1$ to find the optimal result for any $x_1$. This ternary search takes $O(\log(\sum a_i))$ iterations, so the final time complexity is $O(n \log n \log(\sum a_i))$ with a rather large constant.

