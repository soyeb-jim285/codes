# Tutorial_(en)


### [1408A - Circle Coloring](../problems/A._Circle_Coloring.md "Grakn Forces 2020")

At first, set $p_1 = a_1$.

Then for $i \in \{2, \ldots, n-1\}$ if $a_i = p_{i-1}$, then set $p_i = b_i$. Otherwise, set $p_i = a_i$.

 In the end, set $p_n$ to one of $\{a_n, b_n, c_n\}$, which is not equal to $p_1$ or $p_{n-1}$.

 
### [1408B - Arrays Sum](../problems/B._Arrays_Sum.md "Grakn Forces 2020")

Case $k = 1$:

If all $a_i$ are equal the answer is $1$.

Otherwise the answer is $-1$.

Case $k > 1$:

Let's consider an array $a' = (a_2 - a_1, a_3 - a_2, \ldots, a_n - a_{n-1})$ and arrays $b_i' = (b_{i, 2} - b_{i, 1}, b_{i, 3} - b_{i, 2}, \ldots, b_{i, n} - b_{i, n-1})$.

The number of non-zero elements in $b_i'$ is at most $k-1$.

Let's define $c$ as the number of non-zero elements in $a'$ or in the other words the number of indices $i$, such that $a_i \neq a_{i+1}$.

The answer is at least $\lceil \frac{c}{k-1} \rceil$. It's easy to prove that there exists arrays $b_i$ with such number $m$.

 
### [1408C - Discrete Acceleration](../problems/C._Discrete_Acceleration.md "Grakn Forces 2020")

Solution $1$:

Let's make a binary search on the answer. If we have some time $t$ we can calculate the coordinate of each car after $t$ seconds. Let's define them as $x_1$ and $x_2$. If $x_1 \leq x_2$ let's move the left bound of the binary search, otherwise, let's move the right bound.

Time complexity: $O(n \log{\frac{1}{\epsilon}})$.

Solution $2$:

Let's calculate the time for each car and each flag, after which the car will reach this flag. We can find the first flag from left to right, on which the second car was before the first car. Using it we can find the segment between flags, on which the cars will meet. After that the answer can be found by some simple formula using their speed and times, on which they will reach the left and the right bound of this segment.

Time complexity: $O(n)$.

 
### [1408D - Searchlights](../problems/D._Searchlights.md "Grakn Forces 2020")

Let's define as $x$ our move to the right and as $y$ our move to the up. For all pairs $(i, j)$ of (robber, searchlight) at least one of this should be true: $x + a_i > c_j$, $y + b_i > d_j$. So if $x \leq c_j - a_i$ then $y \geq d_j - b_i + 1$.

Let's make an array $r$ of length $C = 10^6$ and write on each position of $x$ the minimum value of $y$. For each $(i, j)$ we should make $r_x = max(r_x, d_j - b_i + 1)$ for all $x \leq c_j - a_i$. So we have $nm$ queries of $max=$ on prefix. We can do it using suffix maximums. After we will calculate all $a_x$ the answer is $\min\limits_{x}{(x + r_x)}$.

Time complexity: $O(nm + C)$.

 
### [1408E - Avoid Rainbow Cycles](../problems/E._Avoid_Rainbow_Cycles.md "Grakn Forces 2020")

Let's make a bipartite graph with $m$ vertices on the left side and $n$ vertices on the right side.

We will connect vertex $i$ from the left side with all elements of $A_i$.

It can be proven, that the graph, which we create using our sets don't have rainbow cycles if and only if our bipartite graph don't have cycles.

So, our task is equivalent of finding the Maximum Spanning Tree of this bipartite graph, where edge between $i$ (from left side) and $j$ (from right side) has weight equal to $a_i + b_j$.

 
### [1408F - Two Different](../problems/F._Two_Different.md "Grakn Forces 2020")

Claim: for each $k$, we can perform operations on $2^k$ elements to make all numbers the same.

You can prove this fact with induction by $k$. For $k=0$ this fact is obvious, For $k>0$, at first change first $2^{k-1}$ and last $2^{k-1}$ points to the same value (assume that those values are $x$ and $y$, respectively). And then, perform operations on points $i$ and $i + 2^{k-1}$, to simultaneously change them to $f(x,y)$. After that, all values will be equal $\blacksquare$.

Using this observation, it is easy to leave only two different values in the array. Find the maximum $2^k \leq n$, and then change first $2^k$ numbers to the same number, and then change last $2^k$ elements to the same number (note that $2^k + 2^k > n$, so in the end there will be only two different elements).

 
### [1408G - Clusterization Counting](../problems/G._Clusterization_Counting.md "Grakn Forces 2020")

Sort all edges by their weights. 

In this order, maintain the DSU. For each connected component, let's maintain $dp_k$: the number of ways to divide this component into $k$ groups. When you merge two connected clusters, you have to recalculate the DP as in the multiplication of two polynomials (of course, if you bound $k$ by the size of the connected component, similarly to the similar tree DP's, it works in $O(n^2)$ total).

Once some connected component becomes a clique, then we obtain a new cluster, and you should increase $dp_1$ for this connected component by $1$.

 
### [1408H - Rainbow Triples](../problems/H._Rainbow_Triples.md "Grakn Forces 2020")

Let's reformulate this problem: you should choose different $i$ with different $a_i > 0$, and for each of them choose one zero to the left and one zero to the right (i.e. for each chosen guy we can assume that we have two vertices in the bipartite graph, and we want to match the left of them with some zero to the left, and the right of them with some zero to the right).

Denote the number of zeroes as $z$.

Observation 1. The answer does not exceed $\frac{z}{2}$.

Observation 2. If the number of zeroes to the right of number is $\geq \frac{z}{2}$, then we will always be able to match it with some zeroes to the right (from Observation 2). You can also make a similar symmetrical observation.

Observation 3. Using observation 2, we can separate non-zero numbers into two groups, s.t. numbers on prefix can always be matched with zero to the right, and numbers on suffix can always be matched with zero to the left. Let's denote those sets as $L$ (prefix) and $R$ suffix.

Observation 4. For each colour only two numbers are interesting: the rightmost in $L$ and the leftmost in $R$. It is easy to show, for example, if you decided to take some colour but not in the rightmost in $L$ position, you can replace it by the rightmost position in $L$ (of course, corresponding zero to the left can be matched with the new position, as you moved it to the right, and you can still match it with some zero to the right). Symmetrical proof holds for $R$.

Observation 5. We derive the following problem: for each colour you want to either choose it in the $L$, choose it in the $R$, or not choose it all. And if you choose it in $L$, then you want to match it with some zeroes on the prefix. If you choose it in $R$, then you want to match it with some zeroes on the suffix. So we can replace each colour to the tuple $(l,r)$ which means that this colour can be matched with either some zero on the prefix of length $l$ of some zero on the suffix of length $r$. And our goal is to find the largest matching.

Observation 6. The maximum matching for this type of graph can be found easily: move $x$ backwards, and each time match $x$ with some unmatched pair $(l, r)$ such that $l \geq x$, and $r$ is minimum among them. 

Observation 7. After you saw observation 6, you can optimize the solution with a priority queue. And don't remember that the real answer is the smaller value of $\frac{z}{2}$ and your matching size.

P.S. You can also formulate this problem as a matroid intersection, and find the answer using the minimax formula for the matroid intersection + segment tree.

 
### [1408I - Bitwise Magic](../problems/I._Bitwise_Magic.md "Grakn Forces 2020")

There are several solutions to this problem, with various complexities. Some of our solutions work in less than half a second. The constraints were set to allow most non-naive solutions.

Solution 1, DP on Trie

Let's look at the bitwise trie. Each node corresponds to some segment $[l, r]$ of possible numbers. Let's note that if you perform operations on numbers in $[l + k, \ldots, r]$, then the resulting numbers for them won't leave the trie node.

So we can come up with the following solution: let's maintain some kind of a DP on this trie. When we took into account numbers from $a$ among $[l + k, \ldots, r]$, and we should store the FWHT for each number of operations (we can assume that we store some kind of an exponential generating functions for each value in FHWT and maintain the product of those genfuncs for numbers with the corresponding signs). Note that in this FWHT you are interested only in $O(r - l)$ values (because all given numbers have equal prefixes, so if you know the parity of the number, you know the prefix of the total XOR).

To recalculate this DP, when we calculated it for children, at first in $O((r - l)k^2)$ you should multiply DP's for the children, and then you should add first $k$ numbers of the right subtree (that you didn't consider yet) to this DP, you can do it for each of them in $O((r - l)k^2)$.

If some details are not clear for you here, probably you are not familiar with FWHT enough.

Deriving the total complexity of $2^c \cdot c \cdot k^3$.

Of course, a lot of different further optimizations possible for this solution.

Solution 2, Observations

The main observation: the number of different tuples $x \oplus x, x \oplus (x-1), x \oplus (x-2), \ldots, x \oplus (x - k)$ is around $O(kc)$.

Why? Because consider how $x$ is changed during the process, usually only $O(\log k)$ bits are changed, but once one block of zeroes of the length $O(\log n)$ is changed to ones. So if we know the last $O(\log k)$ bits of the number and the length of the block of zeroes after them, we can identify s $x \oplus x, x \oplus (x-1), x \oplus (x-2), \ldots, x \oplus (x - k)$.

If you notice this, you can note a lot of other similar observations, and derive another solution with better complexity than naive. And then using DP/FWHT, you can upgrade those ideas to the solution.

For example, QAQautomaton wrote the solution in $2^c \cdot c^2 + c^6$ using this idea.

I will leave all remaining details as an exercise for the reader.

