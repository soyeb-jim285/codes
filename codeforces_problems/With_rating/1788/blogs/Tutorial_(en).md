# Tutorial_(en)

[1788A - One and Two](../problems/A._One_and_Two.md "Codeforces Round 851 (Div. 2)")

Problem idea: [azberjibiou](https://codeforces.com/profile/azberjibiou "International Master azberjibiou")

 **Tutorial**
### [1788A - One and Two](../problems/A._One_and_Two.md "Codeforces Round 851 (Div. 2)")

There should be same number of 2 at a1,a2,⋯ak and ak+1,⋯,an.

By checking every k, we can solve the problem at O(N2). By sweeping k from 1 to n−1, we can solve the problem in O(N). Not counting the number of 2 but naively multiplying using sweeping in python was accepted since it has time complexity O(N2).

Checking every k and naively multiplying solutions are O(N3), so those solutions won't fit in time limit.

[1788B - Sum of Two Numbers](../problems/B._Sum_of_Two_Numbers.md "Codeforces Round 851 (Div. 2)")

Problem idea: [azberjibiou](https://codeforces.com/profile/azberjibiou "International Master azberjibiou")

 **Tutorial**
### [1788B - Sum of Two Numbers](../problems/B._Sum_of_Two_Numbers.md "Codeforces Round 851 (Div. 2)")

Let's assume that there is no carry while adding x and y. Denote n=a9⋯a1a0, x=b9⋯b1b0, y=c9⋯c1c0 in decimal system. The condition can be changed as the following condition.

- ai=bi+ci for all 0≤i≤9. - Sum of bi and sum of ci should differ by at most 1.

If ai is even, let bi=ci=ai/2. Otherwise, let bi and ci be ai+12 or ai−12. By alternating between (bi,ci)=(ai+12,ai−12) and (bi,ci)=(ai−12,ai+12), we can satisfy the condition where sum of bi and sum of ci differ by at most 1.

There is an alternative solution. If n is even, divide it into (n2,n2). If remainder of n divided by 10 is not 9, divide it into (n+12,n−12). If remainder of n divided by 10 is 9, recursively find an answer for ⌊n10⌋ which is (x′,y′) and the answer will be (10x′+4,10y′+5) or (10x′+5,10y′+4) depending on what number has a bigger sum of digits.

The following solution has a countertest.

1. Trying to find x and y by bruteforce from (1,n−1). 2. Trying to find x and y by bruteforce from (n+12,n−12)

A solution that randomly finds (x,y) passes.

[1788C - Matching Numbers](../problems/C._Matching_Numbers.md "Codeforces Round 851 (Div. 2)")

Problem idea: [azberjibiou](https://codeforces.com/profile/azberjibiou "International Master azberjibiou")

 **Tutorial**
### [1788C - Matching Numbers](../problems/C._Matching_Numbers.md "Codeforces Round 851 (Div. 2)")

Let's assume that $1$ to $2n$ is paired and each sum of pair is $k, k+1, \cdots, k+n-1$. Sum from $1$ to $2n$ should equal to the sum of $k$ to $k+n-1$. So we obtain $n(2n+1)=\frac{(2k+n-1)n}{2}$, which leads to $4n+2=2k+n-1$. Since $4n+2$ is even, $2k+n-1$ should be even. So if $n$ is even, we cannot find such pairing.

If $n$ is odd, there are various ways to make such pairing. Let $m=\frac{n-1}{2}$. $(1, 3m+3), (2, 3m+4), \ldots (m, 4m+2), (m+1, 2m+2), (m+2, 2m+3), \ldots (2m+1, 3m+2)$ can be such pairing.

[1788D - Moving Dots](../problems/D._Moving_Dots.md "Codeforces Round 851 (Div. 2)")

Problem idea: [azberjibiou](https://codeforces.com/profile/azberjibiou "International Master azberjibiou")

 **Tutorial**
### [1788D - Moving Dots](../problems/D._Moving_Dots.md "Codeforces Round 851 (Div. 2)")

Let's think about the original problem where we do not think about subsets.

We can easily observe that each dot does not change direction during moving. 

Assume that dots gather at coordinate $x$. Rightmost dot of dots that have smaller coordinate than $x$ should move right, and leftmost dot which has bigger coordinate than $x$ should move left. We can observe that the number of adjacent dot where each move toward each other will be the answer.

Now let's solve the problem for subsets. Instead of counting number of adjacent dot that moves toward each other for each subset of dots, we will count the number of subset for each possible $1 \leq i < j \leq N$ where dot $i$ moves right and dot $j$ moves left and there are no dots between $i$ and $j$.

Let the coordinate of a dot in a subset be $k$. We will try to find out which $k$ can be in a subset where dot $i$ and dot $j$ move toward each other.

Since there are no dot between $i$ and $j$, dots satisfying $x_i < k < x_j$ should not be in the subset. Since dot $i$ should move right, dots that satisfy $k<x_i $ and $x_i-k \leq x_j-x_i$ should not be in the subset. As the same way for dot $j$, dots that satisfy $k>x_j$ and $k-x_j < x_j-x_i$ should not be in the subset. Summing these up, dots satisfying $2x_i -- x_j \leq k < 2x_j -- x_i$ should not be in the subset. By using binary search, we can find the number of dots that cannot be in the subset in $O(logN)$.

If there are $p$ dots that can be in the subset, the number of subset where $i$ and $j$ moves toward each other will be $2^p$. Summing all $2^p$ will give us the answer. Since there are $O(N^2)$ pairs of $(i, j)$, we can solve the problem in $O(N^2logN)$.

Instead of using binary search, we can use the monotonicity of $2x_j-x_i$ and $2x_i-x_j$ when $j$ increases, we can solve the range of dots that cannot be in the subset in $O(N^2)$ by sweeping. Both $O(N^2logN)$ and $O(N^2)$ solutions will be accepted.

There were some dynamic programming solutions from some testers.

[1788E - Sum Over Zero](../problems/E._Sum_Over_Zero.md "Codeforces Round 851 (Div. 2)")

Problem idea: [azberjibiou](https://codeforces.com/profile/azberjibiou "International Master azberjibiou")

Problem solver: [YeongTree](https://codeforces.com/profile/YeongTree "Grandmaster YeongTree")

 **Tutorial**
### [1788E - Sum Over Zero](../problems/E._Sum_Over_Zero.md "Codeforces Round 851 (Div. 2)")

Denote p as the prefix sum of a. For a segment [x+1,y] to be an element of S, px≤py should be satisfied.

Let's denote dpi as the maximum value of the sum of length of segment smaller than i in S. Segment [x,y] is smaller than i if y≤i. If there is no segment ending at i, dpi=dpi−1. If there is segment [k+1,i] in S, dpi=maxpk≤pi(dpk+i−k). By summing up, dpi=max(dpi−1,maxpk≤pi(dpk+i−k) With this dp, we get an O(N2) solution.

Now let's try to speed up the dp transition using segment tree. First, use coordinate compression on pi since we only see whether one prefix sum is bigger than the other. We will maintain a segment tree that stores dpk−k in position pk.

Let's find dpi in order of i. dpi=max(dpi−1,maxpk≤pi(dpk−k)+i) We can solve maxpk≤pi(dpk−k) by range query [0,pi] on a segment tree. So we can solve dpi in O(logN) for each i.

The entire problem is solved in O(NlogN).

There is an alternative solution that maintains pair (dpk−k,pk) monotonically with a set. This solution also runs in O(NlogN).

[1788F - XOR, Tree, and Queries](../problems/F._XOR,_Tree,_and_Queries.md "Codeforces Round 851 (Div. 2)")

Problem idea: [azberjibiou](https://codeforces.com/profile/azberjibiou "International Master azberjibiou")

 **Tutorial**
### [1788F - XOR, Tree, and Queries](../problems/F._XOR,_Tree,_and_Queries.md "Codeforces Round 851 (Div. 2)")

Let's denote $p_i$ as xor of edges in path from node $1$ to node $i$. Edges in path from $i$ to $j$ is 

(edges in path from $1$ to $i$) + (edges in path from $1$ to $j$) — $2 \times $(edges in path from $1$ to $lca(i, j)$)

where $lca(i, j)$ denotes the least common ancestor of $i$ and $j$. Since xor of two same number is $0$, we can observe that xor of path from $i$ to $j$ is $p_i \oplus p_j$. 

If we know every $p_i$ for all $i$, weight of edge connecting $i$ and $j$ is $p_i \oplus p_j$, so deciding weight of every edge is equivalent to deciding every $p_i$ for $i \geq 2$.

Let $G$ be the original tree graph. Let's make a undirected weighted graph $G'$ from the given condition. Condition ($u$, $v$, $x$) makes an edge connecting $u$ and $v$ with weight $x$. This edge means that $p_v=p_u \oplus x$. Now if $u$ and $v$ are connected by edges in $G'$, this means that $p_v=p_u \oplus $ (xor of edges in path from $u$ to $v$).

First, let's check if it is possible to make a graph that satisfies the conditions.

If $G'$ is a connected graph, we can solve $p_i$ using dfs from node $1$. For edges not used in dfs (back edges), we have to check if it is valid with the solved $p_i$. Specifically, if there is an edge ($u$, $v$, $x$), we need to check if $p_u \oplus p_v=x$.

Now let's think when $G'$ is not a connected graph. By dividing the graph into connected components, we can solve if it is impossible to make a graph that satisfies the conditions in a same fashion.

Now let's try to minimize $a_1 \oplus a_2 \oplus \cdots \oplus a_{n-1}$. 

For edge $(u, v)$ in $G$, weight of edge is $p_u \oplus p_v$. By substituting $a_i$ into $p_{x_i} \oplus$ $p_{y_i}$, $a_1 \oplus a_2 \oplus \cdots \oplus a_{n-1}$ can be written as xor of $p_i$ where node $i$ has odd degree. Let the connected components of $G'$ be $G_1, G_2, \ldots, G_k$. Pick any vertex $r_k$ in each component $G_k$. For every vertex $i$ in $G_k$, $p_i$ is expressed as $p_{r_k} \oplus $ (xor of edges in path from $r_k$ to $i$).

Let's define a set $L$ as $L= ${$i | G_i$ has odd number of odd degree vertices}.

By substituting $p_i$ into ($p_{r_k} \oplus$ (xor of edges in path in $G'$ from $r_k$ to $i$)), we can rewrite "xor of $p_i$ where node $i$ has odd degree" into $\bigoplus_{k \in L} p_{r_k} \oplus c$ where $c$ is a constant.

If $L$ is empty, the answer is constant and any solution that satisfy the given conditions will be the answer.

If $L$ is not empty, set one of $p_{r_k}$ to $c$ and other $p_{r_k}$ as $0$ so that $a_1 \oplus a_2 \oplus \cdots a_{n-1}$ is $0$.

We can solve the problem in $O(N)$.

Fast $O(NlogX)$ solution might be accepted, including the solution where you divide the weight of edge by bits.

