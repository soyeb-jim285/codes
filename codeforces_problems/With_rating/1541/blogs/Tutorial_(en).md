# Tutorial_(en)

[1541A - Pretty Permutations](../problems/A._Pretty_Permutations.md "Codeforces Round 728 (Div. 2)")

Author: [PurpleCrayon](https://codeforces.com/profile/PurpleCrayon "Master PurpleCrayon")

 **Hint**The parity (whether n is odd or even) matters.

 **Hint**Swapping two adjacent cats keeps both of them close to their original location and changes both of their locations.

 **Hint**If n is even, the optimal distance is n, and if n is odd the optimal distance is n+1.

 **Solution**
### [1541A - Pretty Permutations](../problems/A._Pretty_Permutations.md "Codeforces Round 728 (Div. 2)")

There are two cases: 

* if $n$ is even, print: $[2, 1, 4, 3, 6, 5 \ldots n, n-1]$ Formally, you swap every other pair of adjacent elements. This is optimal because the total distance is $n$, which has to be minimal since the distance of one cat must be $ \geq 1$.
* if $n$ is odd, first print $[3, 1, 2]$ then solve the even case for the remaining elements. This is optimal because the distance is $n+1$, which has to be minimal since a distance of $n$ is not achievable.
[1541B - Pleasant Pairs](../problems/B._Pleasant_Pairs.md "Codeforces Round 728 (Div. 2)")

Author: [PurpleCrayon](https://codeforces.com/profile/PurpleCrayon "Master PurpleCrayon")

 **Hint**i+j≤2⋅n

 **Hint**The number of pairs (a,b) such that a⋅b≤x is O(xlogx).

 **Solution**
### [1541B - Pleasant Pairs](../problems/B._Pleasant_Pairs.md "Codeforces Round 728 (Div. 2)")

Loop over all values of $a_i$ and $a_j$. Because $i + j \leq 2 \cdot n$, we only care about pairs $(a_i, a_j)$ if $a_i \cdot a_j \leq 2 \cdot n$. The number of such pairs is $O(n log n)$, so you can brute force all pairs.

The reason the total number of pairs is $O(n log n)$ is because if the first element of the pair is $x$, there are only $\frac{2 \cdot n}{x}$ possible values of $y$. $\frac{2 \cdot n}{1} + \frac{2 \cdot n}{2} + \frac{2 \cdot n}{3} + \ldots \frac{2 \cdot n}{n} = 2 \cdot n (\frac{1}{1} + \frac{1}{2} + \frac{1}{3} \ldots \frac{1}{n}) = O(n log n)$ by the harmonic series. Thus the solution runs in $O(n log n)$ time total.

[1540A - Great Graphs](https://codeforces.com/contest/1540/problem/A "Codeforces Round 728 (Div. 1)")

Author: [PurpleCrayon](https://codeforces.com/profile/PurpleCrayon "Master PurpleCrayon")

 **Hint**What's the minimum value that an edge from a to b can be?

 **Hint**Use edges with negative value whenever you can.

 **Hint**The sum of the values of edges with positive weight must be ≥ the maximum value in the array.

 **Solution**
### [1540A - Great Graphs](https://codeforces.com/contest/1540/problem/A "Codeforces Round 728 (Div. 1)")

Note that if there are two nodes $a$ and $b$ and you want to add an edge between them, the value of the edge must be $\geq d_b - d_a$. Otherwise, the cows could take a path to $b$ that goes through $d_a$ that's strictly less than $d_b$. With this in mind, let's add all edges $(a, b)$ with weight $d_b - d_a$ if and only if $d_b \leq d_a$. All of these numbers are not positive, which means they can't make our answer worse. They also don't change the shortest paths, from our first observation. Now, let's call the node with the max $d_i$ node $x$. You can add a single edge from node $1$ to node $x$ with cost $d_x$, and now the graph is good. This is because node $x$ is already connected to all other nodes, which means there is always a shortest path to some node $a$ with the right length by going from $1 \rightarrow x \rightarrow a$. However, naively looping through all pairs is too slow. Instead, you can sort $d$ and calculate the contribution of each node to the answer. The complexity is $O(n log n)$.

[1540B - Tree Array](https://codeforces.com/contest/1540/problem/B "Codeforces Round 728 (Div. 1)")

Author: [ijxjdjd](https://codeforces.com/profile/ijxjdjd "Master ijxjdjd")

 **Hint**Fix the initial node chosen and root the tree there, what is the contribution of each pair of nodes?

 **Hint**Nothing matters besides the path from node a to node b, and the initially chosen node r.

 **Hint**You are given two stacks of size a1 and a2. In a single step, you randomly choose a stack to remove a single item from. What is the probability that a1 becomes 0 before a2? Can you extend this argument for an arbitrary probability p to remove from one of the two stacks, and a probability of 1−2p to do nothing?

 **Solution**
### [1540B - Tree Array](https://codeforces.com/contest/1540/problem/B "Codeforces Round 728 (Div. 1)")

Parsing through the problem statement, the process can be seen as choosing a starting node and "expanding" the subtree of marked nodes to nodes adjacent to the marked component.

Fixing a given root $r$, the expected value of the entire process is obviously the sum of the expected values for a fixed root divided by $n$. 

Find the contribution of the inversion of two nodes $(a, b)$ where $a<b$. The expected contribution for any pair $(a, b)$ is equal to the probability that $b$ appears before $a$ with a given root.

Set $l = lca(a, b)$. Note that, until reaching $l$, every possible process still has the same probability of reaching $b$ before $a$ as it did when the first node was chosen. Therefore, we can assume that the process has reached $l$ and calculate the probability from there. 

Once $l$ is reached, we now note that the probability that the process "gets closer" to $b$ is always equal to the probability of getting closer to $a$.

The problem can be rephrased as having two stacks of size $dist(l, a)$ and $dist(l, b)$ with an arbitrary $p$ to remove a node from one of the two stack (and $1-2p$ to nothing) and finding the probability that $dist(l, b)$ reaches zero before $dist(l, a)$. 

However, it turns out that the actual probability $p$ does not matter. We propose a function $F[x][y]$ that defines the probability that a stack of size $y$ becomes $0$ before a stack of size $x$. In fact a function exists and it is defined as $F[x][y] = \frac{F[x-1][y]+F[x][y-1]}{2}$. Intuitively, this is because the probability of decreasing $x$ or decreasing $y$ is always the same, so the probability of transitioning the state we end up transitioning to is always the same, regardless of $p$.

So, the solution is clear. Iterate over and root at all nodes. Then at the given root, iterate over all pairs of node $a < b$ and add $F[dist(l, a)][dist(l, b)]$ to the answer. Finally, divide by $n$. In total, the solution works in $O(N^3 \log N)$ or $O(N^3)$.

[1540C2 - Converging Array (Hard Version)](https://codeforces.com/contest/1540/problem/C2 "Codeforces Round 728 (Div. 1)")

Author: [ijxjdjd](https://codeforces.com/profile/ijxjdjd "Master ijxjdjd")

 **Hint**What are the invariants? The monovariants?

 **Hint**What is the prefix sum array of the converged array? What is the difference array of the converged array?

 **Hint**What if you conducted the process on a prefix of size 1, then of size 2, and on and on?

 **Hint**How many values x are actually interesting?

 **Solution**
### [1540C2 - Converging Array (Hard Version)](https://codeforces.com/contest/1540/problem/C2 "Codeforces Round 728 (Div. 1)")

First, reduce the operations into something more manageable. It turns out operation $i$ sets $a_{i+1}-a_i=\max(b_i, a_{i+1}-a_i)$ while keeping $a_{i+1}+a_i$ constant. Visually, this is simultaneously moving $a_i$ up and $a_{i+1}$ down until $a_{i+1}-a[i] \geq b_i$.

Define $f$ to be the final converged array. 

Let's some observations

1. If $a_{i+1}-a_i = b_i$ is ever satisfied throughout the process (if an operation ever moves anything), $f_{i+1}-f_i = b_i$. Equivalently, if $f_{i+1}-f_i > b_i$ then no operation $i$ could have ever been conducted
2. If no operation $i$ has been conducted, then $[1, i]$ is independent of $[i+1, n]$.
3. If $i$ is the first operation that has never been conducted, then $\sum_{j=1}^i a_j = \sum_{j=1}^i f_j$ because no sum could have been exchanged between $a_i$ and $a_{i+1}$.

Let's assume that we know that $i$ is the first observation that hasn't been conducted. We can then restore $f_1$ because we know that $f_1 + f_1+b_1+f_1+b_1+b_2 \ldots = a_1+a_2+\ldots+a_i$. To keep the tutorial clean, we refer to the prefix of prefix summation of $b_i$ as $bp_i$ and the prefix summation of $a_i$ as $ap_i$. Namely, we can solve for $f_1 = \frac{ap_i - bp_i}{i}$ given that $i$ is the first observation never conducted.

It turns out that $f_1 = \min(\frac{ap_i - bp_i}{i})$ over all $i$. This can be shown to be a lower bound on $f_1$ because the answer is obviously in this set as there must be some $i$ that is the first operation never conducted. This can also be shown to be an upperbound on the answer by playing the game on each prefix $i$. At each prefix $i$, the term $\frac{ap_i - bp_i}{i}$ is an upperbound because, if it's not equal to that term, there must be some $f_{i+1}-f_i > b_i$ so $f_1 < \frac{ap_i - bp_i}{i}$ because $f_1+f_2+\ldots+f_i$ remains the same.

Returning to the actual problem, we need to count arrays $\min(\frac{ap_i-bp_i}{i}) \geq x$. In other words, $ap_i \geq i \cdot x + bp_i$ must hold for all $i$. Let's do dynamic programming on $ap_i$. Call $dp[i][ap_i]$ the number of prefixes of length $i$ with current prefix sum of $ap_i$. We can transition to $i+1$ from $i$ using prefix sums on each valid $ap_i$.

Define $M = max(a_i)$. The current complexity is $O(Q M N^2)$ The final step is noticing that there are only $O(M)$ valid integer positions that end up being important for $f_1$. Intuitively, this is because in nearly all cases every operation $i$ ends up being used. To rigorously prove, let's find an upperbound on relevant $x$. If $M\cdot n < x\cdot n + bp_i$ then there are $0$ valid arrays. Because $x\cdot n + bp_i$ is concave and negative on the decreasing portion (i.e. the function goes down immediately into negative if it ever becomes negative, otherwise strictly increases), we can draw the inequality $0 \geq x\cdot n + bp_i$, otherwise every array ends up being good. Reducing the inequalities, we can realize that there is exactly $M$ different possible solutions. So, we can precalculate in $O(M^2N^2)$ and answer in $O(1)$.

[1540D - Inverse Inversions](https://codeforces.com/contest/1540/problem/D "Codeforces Round 728 (Div. 1)")

Author: [PurpleCrayon](https://codeforces.com/profile/PurpleCrayon "Master PurpleCrayon")

 **Hint**The answer is always unique.

 **Hint**Try to figure out what the location of the i-th element would be if you only looked at the first i elements, then the first i+1, etc. to find an O(nq) solution.

 **Hint**Use sqrt decomposition to optimize it.

 **Solution**
### [1540D - Inverse Inversions](https://codeforces.com/contest/1540/problem/D "Codeforces Round 728 (Div. 1)")

We'll assume the arrays and the final permutation are 0-indexed from this point forward (you can shift values accordingly at the end). 

Let's start with calculating the final array, without any updates. Let $c_i$ be the number of indices $j$ such that $p_j < p_i$ and $i < j$. It is easy to see that $c_i = i - b_i$. Now imagine sweeping from left to right, maintaining the array $a$. Let's say you're currently at index $i$, and you have a list of all indices $ \leq i$, where the location of some index $j$ is the value of $a_j$. You know that $i$ must be the $c_i$-th out of those (after inserting it into the list) as the $c_i$ smallest values must be before it. This means that you can insert index $i$ at the $c_i-th$ position in the list, and you need to find the final location of index $i$ in each query.

 Now, let's support $O(1)$ updates and $O(n)$ queries. The first thing to note is that you don't need the entire array $a$ in each query, you just need to query some specific element. Assume you're querying the $i$-th element of the array. Let's repeat the algorithm mentioned above except instead of storing the lists, you only store the location of the $i$-th element for each query. Now, you keep some variable $loc$ which stores the location of the $i$-th element in the list. It is initialized to $c_i$, as it is first inserted to the $c_i$-th position. Now you sweep through all indices $j$ where $j > i$, and check if $loc$ is changed by the insert. This is only true if $loc \geq a[j]$. This allows for $O(1)$ updates but $O(n)$ queries, which is still too slow. 

To speed this up, let's use sqrt-decomp. Divide the array into multiple blocks. For each block, let's store an array $next$ where $next_{loc}$ represents the final value of the variable $loc$ if it passes through the block. If we have this array, you can loop over all of the blocks and "jump" over them using the next array, querying in $O(n/B)$ time, where $B$ is the size of the block. But how do you calculate and update the $next$ array? Initially, you can calculate the next array in $O(n \cdot B)$, by going to each index and naively tracking its position. Updating it is harder. One observation to make is that for each index inside a block, there is some value such that if $loc \geq x$ it will be changed by the index, otherwise it will not. You can find all of those values for a single block using a binary indexed tree: sweep from left to right, query for the the smallest update $loc$ using a lower bound on the BIT, and increment a suffix. Then, you can increment all of those suffixes in the next array using another BIT, which would lead to $O(n \sqrt{n} + q \sqrt{n} \log{n})$, as queries are $O((n/B)\log{n})$ and updates are $O(B \log{n})$, which will probably be too slow.

To make this faster, note that the suffix that each element is responsible changes by at most one for all non-updated elements. This means that you can update the next array in $O(1)$ for these elements. However, the updated element's suffix might change by $O(n)$. To account for this, you can use another square root decomposition on the next array, which allows for $O(\sqrt{n})$ range updates, $O(1)$ point updates, and $O(1)$ point queries. This means that updates will remain $O(B \log{n})$, but queries will become $O(1)$, so the final complexity is $O(q \sqrt{n \log{n}})$ with the right blocksize, which is definitely fast enough (the model solution runs in $2$ seconds).

If you know of any faster solutions ($O(n\sqrt{n})$ or even $O(n \cdot \log^k{})$ let us know down in the comments).

[1540E - Tasty Dishes](https://codeforces.com/contest/1540/problem/E "Codeforces Round 728 (Div. 1)")

Author: [ijxjdjd](https://codeforces.com/profile/ijxjdjd "Master ijxjdjd")

 **Hint**How much does each chef's initial dish contribute at time k?

 **Hint**What if you really, really wanted to use matrix exponentiation?

 **Hint**How can you multiply some vectors by a matrix in O(N) time? (go back to linear algebra class)

 **Hint**Decompose into linear combinations of eigenvectors.

 **Solution**
### [1540E - Tasty Dishes](https://codeforces.com/contest/1540/problem/E "Codeforces Round 728 (Div. 1)")

All operations are conducted under a modulo, it can be proven that each operation we conduct is valid within the modulo.

Key Idea 1 It's optimal to perform each operation if the number being added/multiplied is strictly positive. Specifically, it's optimal to do $a_i := i\cdot a_i$ and $a_i := a_i+a+j$ iif $a_i > 0$ and $a_j > 0$ respectively.

Key Idea 2 A chef's dish $i$ becomes positive after the $d$'th day where $d$ is the closest distance of chef $i$ from a positive element. We call this value $d_i$ for the $i$'th chef. Initial observations, there are only $O(N^2)$ pairs of $(i, d_i)$ where $d_i$ is not infinite (never reaches positive value and thus never changes). 

Key Idea 3 We refer to a vector of length $n$ with $n-1$ zeros and a single $1$ at the $i$'th index as $\vec{e}_i$. If we assume that all chefs are currently positive then every chef takes every opportunity copy and the transition matrix $T$ is well defined and obvious.

We can represent the final array at time $k$ as $a = T^k \sum_{d_i \leq k} T^{-d_i} \vec{e}_i a_i$ + $\sum_{d_i>k} \vec{e}_i a_i$. This immediately offers a $O(QN^2+N^4)$ potential solution with very good constant. Because $T$ is diagonal, its inverse can with respect to a vector $\vec{v}$ be calculated in $O(N^2)$. So, we can precalculate $T^-k \vec{e}_i$ for all valid numbers in $O(N^2)$. In fact, this ends up being $N^4/12$ total operations if optimized. We can then answer each query in $O(N^2)$ by simply iterating over each chef and finding it's contribution to the answer. Multiplying a matrix $O(N^2)$ will be explained later.

With some special hacks, it may even be possible to get this to pass. 

Key Idea 4 An arbitrary matrix $T$ has eigenvalues $\lambda_i$ and their paired eigenvectors $\vec{v}_i$. Ignoring how we find eigenvectors and eigenvalues, the point of the two is that they are pairs such that $T \vec{v}_i = \vec{v}_i \lambda_i$. Notably, given a eigenvector and its respective eigenvalue, we can calculate $T^k \cdot \vec{v}_i$ in $O(N \log k)$. 

In our case, the transition matrix $T$ is a diagonal matrix. A basic result in linear algebra is that the eigenvalues of a diagonal matrix is exactly the numbers on it's diagonal. In our case, this means that $\lambda_i = i$ for $1 \le i \le n$. Finding the eigenvectors is left as an exercise to the reader. We henceforth denote the eigenvector paired with the $i$'th eigenvalue as $\vec{v}_i$.

Key Idea 5 Decompose $\vec{e}_i$ into a linear combination of eigenvectors. This can be precalculated in $O(N^3)$. Let's denote another vector $\vec{c}_i$ as this linear combination i.e. $\vec{c}_i$ satisfies $\vec{e}_i = \sum \vec{v}_i \vec{c}_{i, j}$. In fact, this is almost all we need. Let's return to to $a = T^k \sum_{d_i \leq k} T^{-d_i} \vec{e}_i a_i$ (the second part can be trivially calculated). We can calculate almost "separately" for each eigenvector $j$. In fact, the contribution of the $j$'th eigenvector from the $i$'th chef after the $k$'th day is $\lambda_j^k c_{i, j} a_i \lambda_j^{-d_i}$. Let's store $c_{i,j}a_i \lambda_j^-{d_i}$ in a segment tree/BIT on $d_i$. We can extract in $O(N \log N)$ total or $O(\log N)$ for a single eigenvector then find the total contribution by multiplying by $\lambda_j^k$ and using prefix sums on the eigenvector to extract the relevant range $[l, r]$. We can also process $O(N log N)$ per update if $d_i$ stays constant trivially. This is more than enough to pass, but a further optimization is that the array $d$ only changes at most $O(N)$ time (whenever a new element becomes positive). So, we can simply rebuild our segment tree/BIT in $O(N)$ to reach $O(N^3)$ complexity.

Final complexity: $O(N^3 + QN\log N)$.

It's also worth noting that several nonoptimal solutions can pass. We attempted to cut off any solutions that explicitly use matrix multiplication. However, solutions with complexity such as $O(QN^2)$ can pass in 64 bit C++ if only additions are used. The only way we found to do only additions was by making the same eigenvector reduction, so we were not too worried. It seems impossible to fail such solutions while maintaining a reasonable TL.

