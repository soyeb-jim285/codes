# Tutorial_(en)

Here's the tutorial. Code can be found in this link (more will be added there soon): [https://www.dropbox.com/sh/xwxn3zrl1icp3i2/AACtYSdYH0KlTEdVgCFFgPrYa?dl=0](https://codeforces.com/https://www.dropbox.com/sh/xwxn3zrl1icp3i2/AACtYSdYH0KlTEdVgCFFgPrYa?dl=0) 

 **Zoning Restrictions Again**
### [1162A - Zoning Restrictions Again](https://codeforces.com/contest/1162/problem/A "Codeforces Round 557 (Div. 2) [based on Forethought Future Cup - Final Round]")

This problem can be done by processing the restrictions one by one. Let's keep an array $a$ of length $n$, where the $i$-th value in this array represents the maximum possible height for house $i$.

Initially, we have processed no restrictions, so we fill $a_i = h$ for all $i$.

For a restriction $k$, we can loop through the elements $j$ between $l_k$ and $r_k$ and update $a_j = \min(a_j, x_k)$. This is because the new house must be at most height $x_k$, and we know previously it had to be at most $a_j$, so we take the min of the two.

After processing all restrictions, we can greedily choose the height of the $i$-th house to be $a_i$. The answer is the sum of $a_i^2$ for all $i$.

The time complexity for processing one restriction is $O(n)$, so the total time complexity is $O(nm)$.

 **Double Matrix**
### [1162B - Double Matrix](https://codeforces.com/contest/1162/problem/B "Codeforces Round 557 (Div. 2) [based on Forethought Future Cup - Final Round]")

There are too many possibilities to try a brute force, and a dp solution also might be too slow (e.g. some bitmask dp). There is a solution that uses 2sat but that is a bit hard to code so I won't go into details in this tutorial. Let's instead look at a greedy solution.

First, let's swap $a_{i,j}$ with $b_{i,j}$ if $a_{i,j} > b_{i,j}$. At the end, for every $i$ and $j$, we have $a_{i,j} \leq b_{i,j}$. We now claim that there is a solution if and only if this configuration is valid. We can guess this intuitively and by trying a few examples, or we can do the proof below.

<start of formal proof for why this works>

If this configuration is valid, then obviously this solution works, so we're done with this side of the implication.

The other way is to show if there exists a solution, then this configuration is also valid. We do this by contradiction. We show if this configuration is not valid, then there is no solution. If this configuration is not valid, without loss of generality, let $b_{i,j} \geq b_{i,j+1}$. $b_{i,j}$ must go somewhere in the matrix and it needs to be before either $b_{i,j+1}$ or $a_{i,j+1}$, but we have $a_{i,j+1} \leq b_{i, j+1} \leq b_{i,j}$, so we have nowhere that we can put $b_{i,j}$, thus this shows there is no solution. We can also extend this argument to the other cases.

<end of proof for why this works>

So, given the above claim, the solution is simple. Do the swaps so $a_{ij} \leq b_{ij}$. Then, check if the two matrices are increasing, and print "Possible" if so and "Impossible" otherwise. The runtime is $O(n^2)$ to read in the input, do the swaps, then do the checks that the matrices are valid.

 **Hide and Seek**
### [1147A - Hide and Seek](../problems/A._Hide_and_Seek.md "Forethought Future Cup - Final Round (Onsite Finalists Only)")

Another way to phrase this problem is to count the number of ordered pairs $(p,q)$ that satisfy the following

* $|p-q| \leq 1$
* There exists a number $i$ such that p doesn't appear in $x[0\ldots i]$ and $q$ doesn't appear in $x[i+1\ldots n]$.

There are only $O(n)$ pairs that satisfy the first condition, so we can loop over all these pairs and try to efficiently check the second condition.

If $p=q$, this pair is valid if $p$ doesn't appear in $x$, so we can just check this for all $1\ldots n$ directly with just one sweep through $x$.

For $p,q$ that differ by exactly one, we can check that the first occurrence of $p$ occurs after the last occurrence of $q$. This is because we can start at $p$, wait until the last question about $q$ has been asked, and then swap to $p$. This is guaranteed to avoid all of Bob's questions.

To answer this question efficiently, let's precompute the first and last occurrence of each number. This can be done by sweeping through the array once. Thus, checking if the condition is satisfied is just checking that $first[p] > last[q]$.

The total time complexity is $O(k)$ for pre-computation, and $O(n)$ for answering all the questions.

 **Chladni Figure**
### [1147B - Chladni Figure](../problems/B._Chladni_Figure.md "Forethought Future Cup - Final Round (Onsite Finalists Only)")

Let's brute force the value of $k$ and check if it's possible to rotate the image by $k$ to get the same image. We can do this by iterating through all segments $(a,b)$, and checking that $(a+k,b+k)$ is a segment (the endpoints taken modulo $n$ if needed).

This gives an $O(nm)$ solution, however, you can notice that we only need to check divisors of $n$ rather than all values from $1$ to $n$. This is because the set of segments $(a,b), (a+k,b+k), (a+2k,b+2k), \ldots$ is exactly equal to $(a,b), (a+\gcd(n,k), b+\gcd(n,k)), (a+2\gcd(n,k), b+2\gcd(n,k)), \ldots$. Thus, this take $O(m \cdot d(n))$, where $d(n)$ denotes the number of divisors of $n$, which is fast enough to pass this problem.

There is also a faster linear time solution. We can reduce this to a problem of finding the largest period of a string. For every point, we can sort the length of the segments starting from that point (length in this case refers to clockwise distance). We also add some null character to denote a point. For instance, the first sample case's string might start like $2, -1, -1, 4, 8, 10, -1, \ldots$ that represent the points from $1$ to $3$. Such a string can be computed in $O(m \log m)$ time. Then, after finding this string, we just want to check the period is bigger than $1$. Let $w$ be the length of the string. We can find this by concatenating the string to itself, then use z-algorithm to check if there is any is any index $i$ from $1$ to $w-1$ that is at least $w$.

 **Thanos Nim**
### [1147C - Thanos Nim](../problems/C._Thanos_Nim.md "Forethought Future Cup - Final Round (Onsite Finalists Only)")

The main claim is that if a player is forced to reduce the minimum number of stones over all piles, then they lose. Intuitively, every time a player reduces the minimum, the other player has a move that doesn't reduce the minimum, and if a player isn't forced to reduce the minimum, they have a move that will force the other player to reduce the minimum.

More formally, let $m$ be the minimum number of stones in a pile, and let $x$ be the number of piles with $m$ stones. Alice can win if and only if $x \leq n/2$. Let's call the positions where Alice can win "winning positions", and all other positions "losing positions"

To see why this works, we need to show from a winning position, we can reach some losing position, and if we are at a losing position, we can only reach winning positions.

If we are at a winning position, there are at least $n/2$ piles that have strictly more than $m$ stones, so we can choose any arbitrary subset of them and reduce them to $m$ stones. This is now a losing position.

If we are at a losing position, no matter what we do, we must include a pile of size $m$ in our chosen subset. If $m$ is zero, this means we have no available moves. Otherwise, the minimum will strictly decrease, but only at most $n/2$ piles (from the piles that we chose) can reach that new minimum. Thus, losing positions can only reach winning positions.

The solution is then as follows. Find the min of the array and find the frequency of the min. Print "Alice" if the frequency is less than or equal to $n/2$, otherwise, print "Bob". The time complexity is $O(n)$. Alternatively, you can sort and check the index $0$ and index $n/2$ are the same for a short three line solution.

 **Palindrome XOR**
### [1147D - Palindrome XOR](../problems/D._Palindrome_XOR.md "Forethought Future Cup - Final Round (Onsite Finalists Only)")

Since the leading character of $s$ is a "1", then that means $a < 2^{m-1}$ and $2^{m-1} \leq b < 2^m$. Let's fix the length of $a$ as $k$. I'll describe a more general solution, so there might be simpler solutions that work for this specific problem.

Let's make a graph with $n+k+2$ nodes. The first $n$ nodes represent the $n$ bits of $b$, and the next $k$ nodes represent the $k$ bits of $a$. The last two nodes represent a $0$ node and $1$ node (which we will explain later). We want to find the number of ways to color the graph with two colors $0$ and $1$ such that they satisfy some conditions.

Let's draw two different types of edges $0$-edges and $1$-edges. If two nodes are connected by a $0$-edge, then that means they must be the same color. If two nodes are connected by a $1$-edge, then that means they must be a different color.

We will draw some edges as follows: 

* Draw a $1$ edge between the $0$ node and $1$ node to represent they must be different colors.
* Draw a $0$ edge between $b_i$ and $b_{n-i-1}$ to represent the palindrome conditions (similarly we can do this for $a$).
* For the $i$-th bit, if $s_i$ is "1", draw a $1$ edge between $a_i$ and $b_i$ (if $i > k$, we instead draw an edge from $b_i$ to $1$). If $s_i$ is "0", then draw a $0$ edge between $a_i$ and $b_i$. If $s_i$ is "?", then don't draw any edges, since there are no explicit constraints.

Now, we want to count the number of valid colorings. We want to split the graph into a two colors, which is a bipartite graph. We want all edges that cross the bipartition to be $1$ edges and all edges within the same bipartition to be $0$ edges.

To count this, we first collapse all connected components of $0$ edges, then check if the remaining $1$ edges form a bipartite graph. If there is a non-bipartite graph, return $0$ immediately, since this means it's impossible to fulfill the conditions. Otherwise, let $C$ be the number of connected components. We add $2^{C-1}$ to our answer. The reason we subtract $1$ is that the component containing the $0$ and $1$ node is fixed to be colored $0$, but for other components, we are free to color the components in either of two ways.

There are $n$ different lengths to try, each of which take a linear amount of time to get the count, so the overall time complexity is $O(n^2)$.

 **Rainbow Coins**
### [1147E - Rainbow Coins](../problems/E._Rainbow_Coins.md "Forethought Future Cup - Final Round (Onsite Finalists Only)")

Let's define a new question that takes a list of coins $t_1, t_2, \ldots, t_k$, and returns the answers about all adjacent pairs of coins in this list (e.g. the answers to $(t_1, t_2), (t_2, t_3), (t_3, t_4), \ldots$. We can do this in two questions, one question is $(t_1, t_2), (t_3, t_4), \ldots,$ and the other is $(t_2,t_3), (t_4,t_5), \ldots$, and we can interleave the results to get the answer for all adjacent pairs in order.

We show how to use only three questions of this type to get the answer (so the total number of questions in the original problem is $6$).

First, let's ask about all adjacent pairs in $1, 2, \ldots, n$. This splits the coins into contiguous groups of the same color. Let's take some arbitrary representative from each group and put them in a line, so we now have a problem where all adjacent coins in the line are different colors.

Now, we ask two more questions about adjacent pairs. One for coins $1,3,5,\ldots$ and one for coins $2,4,6,\ldots$.

This is now enough to reconstruct the color of all the coins. WLOG, coin $1$ is red, and coin $2$ is blue. We know coin $3$ cannot be blue (since it must be different from coin $2$), and we compared it with coin $1$, so we know if it is either red or green. We can repeat this for all coins in sequence.

 **Zigzag Game**
### [1147F - Zigzag Game](../problems/F._Zigzag_Game.md "Forethought Future Cup - Final Round (Onsite Finalists Only)")

I first got the idea for this problem from this problem: https://www.codechef.com/problems/HAMILG. There might be an easier version of the problem on a bipartite graph out there somewhere also. Anyways, the solution for the problem is conceptually simple. Find a matching of the graph, and then you can play according to the matching. You don't even need to remember which vertices you've seen before, since the main idea is if your opponent can make a move, then you can too.

The same idea can be extended to this problem. The intuition is to find some matching to show that Bob can always win. It's not clear how to find such a matching directly, so let's look at what properties the matching needs.

Let's call nodes $1$ to $n$ the "left" side of the bipartite graph and nodes $n+1$ to $2n$ the "right" side

Without loss of generality, suppose Alice choose "increasing" and she placed her token somewhere on the left side.

Now, let's consider what properties a matching needs. Let's take any two edges in our matching, one that connects nodes $(w,x)$ ($w$ is on the left, $x$ is on the right), and the other connects $(y,z)$ ($y$ is on the left, $z$ is on the right).

We want it to be the case that if it is legal for Alice to move from $x$ to $y$, then it is legal for Bob to move from $y$ to $z$. This way, Bob always can respond by playing according to the matching.

Let's see what this means in terms of edge weights. If Alice can move from $x$ to $y$, then that means $edge(x,y) > edge(w,x)$, since the last edge traversed was $(w,x)$ and Alice is increasing. We want it to be the case that $edge(x,y) > edge(w,x)$ implies that $edge(x,y) > edge(y,z)$. Thus, the matching is bad if and only if there are two edges in the matching $(w,x)$ and $(y,z)$ such that $edge(x,y) > edge(w,x)$ and $edge(x,y) < edge(y,z)$.

We can solve this with stable marriage. We call the bad case an instability, which happens if $x$ prefers $y$ over $w$ and $y$ prefers $x$ over $z$. We can construct the preference list of the nodes as follows. For each node on the left side, create a preference list of nodes on the right in decreasing order of weight. For each node on the right side, create a preference list of nodes on the left in increasing order of weight.

We now find any stable marriage in $O(n^2)$ time. It is guaranteed that one exists and has no instabilities. Thus, we've found a matching that guarantees Bob's win.

As a followup, can you devise a strategy that guarantees Alice can beat Bob if Bob makes a non-optimal move?

