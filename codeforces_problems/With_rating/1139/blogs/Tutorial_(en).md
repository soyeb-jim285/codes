# Tutorial_(en)

I hope you guys enjoyed the contest and we hope to host another one soon! The next one will be more balanced :P

With that said, here are the tutorials:

 
### [1139A - Even Substrings](../problems/A._Even_Substrings.md "Codeforces Round 548 (Div. 2)")

Any substring ending in $2, 4, 6, 8$ forms an even substring. Thus, iterate over all positions $i$ of the string $s$, and if the digit represented by character at $i_{th}$ index is even, then add $i+1$ to the answer, since all the substrings starting at $0, 1, ..., i$ and ending at $i$ are even substrings.

Overall Complexity: $O(n)$.

Author: [Ashishgup](https://codeforces.com/profile/Ashishgup "Master Ashishgup")

C++ Code: [51651509](https://codeforces.com/contest/1139/submission/51651509 "Submission 51651509 by Ashishgup")

Java Code: [51651164](https://codeforces.com/contest/1139/submission/51651164 "Submission 51651164 by Jeel_Vaishnav")

 
### [1139B - Chocolates](../problems/B._Chocolates.md "Codeforces Round 548 (Div. 2)")

It is optimal to proceed greedily from the back of the array. If we have taken $x$ candies of the $i+1$ type, then we can only take $\min(x - 1, A_i)$ candies for type $i$. If this value is less than zero, we take $0$ from here.

Overall Complexity: $O(n)$

Author: [Ashishgup](https://codeforces.com/profile/Ashishgup "Master Ashishgup")

C++ Code: [51651887](https://codeforces.com/contest/1139/submission/51651887 "Submission 51651887 by Ashishgup")

Java Code: [51651375](https://codeforces.com/contest/1139/submission/51651375 "Submission 51651375 by Jeel_Vaishnav")

 
### [1139C - Edgy Trees](../problems/C._Edgy_Trees.md "Codeforces Round 548 (Div. 2)")

Let's find the number of bad sequences — Sequences of length $k$ that do not pass through any black edges. Then answer is all possible sequences minus the number of bad sequences.

Thus, we can remove black edges from the tree.

Now the tree would be split into connected components.

For every connected component, if we start with $A_1$ being a node from this component, then we cannot step outside this component, since doing so would mean that we visit a black edge. But we can visit all the nodes in the current connected component in any order. So if the size of the current component is $p$, then we have $p^k$ bad sequences corresponding to this connected component.

Thus, the overall answer is $n^k - \sum p^k$ where $p$ is the size of different connected components, considering only red edges.

Author: [Ashishgup](https://codeforces.com/profile/Ashishgup "Master Ashishgup")

C++ Code: [51652029](https://codeforces.com/contest/1139/submission/51652029 "Submission 51652029 by Ashishgup")

Java Code: [51651756](https://codeforces.com/contest/1139/submission/51651756 "Submission 51651756 by Jeel_Vaishnav")

 
### [1139D - Steps to One](../problems/D._Steps_to_One.md "Codeforces Round 548 (Div. 2)")

Let $dp[x]$ be the expected number of additional steps to get a gcd of 1 if the gcd of the current array is $x$.

Suppose the current gcd of the array $a$ is $x$, after the next iteration of the algorithm, we would append some randomly chosen $j$ with a probability $\frac{1}{m}$, and move to state $gcd(x,j)$ and since the length increases by $1$ on appending, we will make $dp[gcd(x, j)] + 1$ steps for this $j$.

So the recurrence is : $$ dp[x] =1 + \sum_{j=1}^{m}\frac{dp[gcd(j,x)]}{m} $$

I recommend this [Expectation tutorial](https://codeforces.com/https://brilliant.org/wiki/linearity-of-expectation/) to get more understanding of the basics.

We can group together all terms having the same $gcd(j, x)$, move terms having $gcd(j, x) = x$ to the left side of the equation and use that to calculate $dp[x]$.

This is an $O(m^2)$ solution.

Here we notice that $gcd(j,x)$ is a factor of $x$,

So the recurrence could be modified as : $$ dp[x] = 1+\sum_{y \in divisors(x)}{\frac{dp[y] \cdot f(y,x)}{m}} $$ where $f(y,x)$ is the count of integers $1 \le p \le m$, such that $gcd(p,x)=y$

Lets express $x = y \cdot a$, and $p=y \cdot b$ where $a$, $b$ are positive integers,

So we want to find the number of $p$'s where $1 \le p \le m$, $p = y \cdot b$, such that $gcd(b,a) = 1$, i.e. we want to find number of $b$ where $1 \le b \le m/y$ such that $gcd(b,a) = 1$.

Lets find factorization of $a$, so $b$ must not be divisible by any of the prime factors of $a$.

We can find number of $b\le m/y$ such that it isn't divisible by some set of primes by inclusion exclusion.

Since there are at most $6$ primes, we have complexity: $O(m \log{m} \cdot 2^6 \cdot 6)$ 

For an alternate solution using mobius function, refer code 2.

Author: [Vivek1998299](https://codeforces.com/profile/Vivek1998299 "Candidate Master Vivek1998299")

C++ Code (Above Logic): [51652491](https://codeforces.com/contest/1139/submission/51652491 "Submission 51652491 by Vivek1998299")

C++ Code (Mobius Inversion): [51652104](https://codeforces.com/contest/1139/submission/51652104 "Submission 51652104 by Ashishgup")

 
### [1139E - Maximize Mex](../problems/E._Maximize_Mex.md "Codeforces Round 548 (Div. 2)")

Let's reverse the queries so that instead of removal of edges we need to work with the addition of edges. Now consider a bipartite graph with values $0 \ldots m$ on the left side and clubs $1 \ldots m$ on the right side. For an ind $i$, which has not been removed, we add an edge from $p_i$ on the left to $c_i$ on the right. Let's start finding matching for values $0 \ldots m$ in sequence. Let's say we couldn't find matching for $i$-th value after query $x$, so our answer for query $x$ will be $i$. Now, we add the student of query $x$. Let the index of the student be $ind$, then we add an edge from $p_{ind}$ on the left to $c_{ind}$ on the right. Now, we start finding matching from $i \ldots m$, until matching is not possible. We repeat this process until all queries are solved.

Overall Complexity: $O(d \cdot n + m \cdot n)$

Author: [Jeel_Vaishnav](https://codeforces.com/profile/Jeel_Vaishnav "Master Jeel_Vaishnav")

Java Code: [51652167](https://codeforces.com/contest/1139/submission/51652167 "Submission 51652167 by Jeel_Vaishnav")

 
### [1139F - Dish Shopping](../problems/F._Dish_Shopping.md "Codeforces Round 548 (Div. 2)")

Let's consider a matrix where $i$-th row represents price $i$ and $j$-th column represents beauty $j$, such that the value of $c[i][j]$ represents the number of dishes that can be bought by a person having income $i$ and preferred beauty $j$. Then, adding a dish with price $p$, standard $s$ and beauty $b$ is similar to adding $+1$ in each cell in the triangle formed by vertices $P(p, b)$, $Q(s, b - s + p)$ and $R(s, b + s - p)$. Now, we need to update the given triangles with $+1$ in a matrix efficiently. Let's do this offline.

Note that for a triangle with vertices $P(p, b)$, $Q(s, b - s + p)$ and $R(s, b + s - p)$, the column updated in $p$-th row is $b$. The columns updated in $(p + 1)$-th row are $b - 1$, $b$ and $b + 1$. So, if the columns updated in $i$-th row are $x \ldots y$, then the columns updated in $i + 1$-th row will be $(x - 1) \ldots (y + 1)$. For updating a range $l \ldots r$ in a row $i$, we can update $mat[i][l]$ with $+1$ and $mat[i][r + 1]$ with $-1$. And then when we do prefix sum in that row we get actual values for each cell. 

We can use similar approach here. Note that instead of updating $mat[i][l]$ with $+1$, we can update some array $larr[i + l]$ with $+1$, similarly instead of updating $mat[i][r + 1]$ with $-1$, we can update some array $rarr[r + 1 - i]$ with $-1$. In this way, we can provide updates for each row in triangle instead of just one row. The value of a cell $mat[i][j]$ will be addition of prefix sum of $larr$ in range $[0, i+j]$ and prefix sum of $rarr$ in range $[0, j-i]$.

Let's create four events for each triangle. For, a triangle with vertices $P(p, b)$, $Q(s, b - s + p)$ and $R(s, b + s - p)$, the events added will be $larr[p + b] \texttt{+=} 1$ at cell $(p, b)$, $rarr[b + 1 - p] \texttt{-=} 1$ at cell $(p, b + 1)$, $larr[p + b] \texttt{-=} 1$ at cell $(s + 1, b - s - 1 + p)$, $rarr[b + 1 - p] \texttt{-=} 1$ at cell $(s + 1, b + s + 1 - p)$. Also, we add query events for each person $i$ at cell $(inc_i, pb_i)$. Let's sort this events on the basis of rows of the cell and then for the same row we handle triangle events first and then handle query events. For maintaining prefix sum in $larr$ and $rarr$, we can use compression and a datastructure like fenwick tree.

Overall Complexity: $O((n + m) \cdot log(n + m))$

Author: [Jeel_Vaishnav](https://codeforces.com/profile/Jeel_Vaishnav "Master Jeel_Vaishnav")

Java Code: [51652020](https://codeforces.com/contest/1139/submission/51652020 "Submission 51652020 by Jeel_Vaishnav")

