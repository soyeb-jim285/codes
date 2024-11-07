# Tutorial_(en)

Here's the tutorial. Code can be found in this link (more will be added there soon): [https://www.dropbox.com/sh/xwxn3zrl1icp3i2/AACtYSdYH0KlTEdVgCFFgPrYa?dl=0](https://codeforces.com/https://www.dropbox.com/sh/xwxn3zrl1icp3i2/AACtYSdYH0KlTEdVgCFFgPrYa?dl=0) 

 **Zoning Restrictions Again**
### [1162A - Zoning Restrictions Again](../problems/A._Zoning_Restrictions_Again.md "Codeforces Round 557 (Div. 2) [based on Forethought Future Cup - Final Round]")

This problem can be done by processing the restrictions one by one. Let's keep an array a of length n, where the i-th value in this array represents the maximum possible height for house i.

Initially, we have processed no restrictions, so we fill ai=h for all i.

For a restriction k, we can loop through the elements j between lk and rk and update aj=min(aj,xk). This is because the new house must be at most height xk, and we know previously it had to be at most aj, so we take the min of the two.

After processing all restrictions, we can greedily choose the height of the i-th house to be ai. The answer is the sum of a2i for all i.

The time complexity for processing one restriction is O(n), so the total time complexity is O(nm).

 **Double Matrix**
### [1162B - Double Matrix](../problems/B._Double_Matrix.md "Codeforces Round 557 (Div. 2) [based on Forethought Future Cup - Final Round]")

There are too many possibilities to try a brute force, and a dp solution also might be too slow (e.g. some bitmask dp). There is a solution that uses 2sat but that is a bit hard to code so I won't go into details in this tutorial. Let's instead look at a greedy solution.

First, let's swap $a_{i,j}$ with $b_{i,j}$ if $a_{i,j} > b_{i,j}$. At the end, for every $i$ and $j$, we have $a_{i,j} \leq b_{i,j}$. We now claim that there is a solution if and only if this configuration is valid. We can guess this intuitively and by trying a few examples, or we can do the proof below.

<start of formal proof for why this works>

If this configuration is valid, then obviously this solution works, so we're done with this side of the implication.

The other way is to show if there exists a solution, then this configuration is also valid. We do this by contradiction. We show if this configuration is not valid, then there is no solution. If this configuration is not valid, without loss of generality, let $b_{i,j} \geq b_{i,j+1}$. $b_{i,j}$ must go somewhere in the matrix and it needs to be before either $b_{i,j+1}$ or $a_{i,j+1}$, but we have $a_{i,j+1} \leq b_{i, j+1} \leq b_{i,j}$, so we have nowhere that we can put $b_{i,j}$, thus this shows there is no solution. We can also extend this argument to the other cases.

<end of proof for why this works>

So, given the above claim, the solution is simple. Do the swaps so $a_{ij} \leq b_{ij}$. Then, check if the two matrices are increasing, and print "Possible" if so and "Impossible" otherwise. The runtime is $O(n^2)$ to read in the input, do the swaps, then do the checks that the matrices are valid.

 **Hide and Seek**Tutorial is loading... **Chladni Figure**Tutorial is loading... **Thanos Nim**Tutorial is loading... **Palindrome XOR**
### [1147D - Palindrome XOR](https://codeforces.com/contest/1147/problem/D "Forethought Future Cup - Final Round (Onsite Finalists Only)")

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

 **Rainbow Coins**Tutorial is loading... **Zigzag Game**Tutorial is loading...