# Tutorial

Thanks for the participation!

[1649A - Game](https://codeforces.com/contest/1649/problem/A "Codeforces Round 775 (Div. 2, based on Moscow Open Olympiad in Informatics)") was authored by [Jeffrey](https://codeforces.com/profile/Jeffrey "Grandmaster Jeffrey") and prepared by [gop2024](https://codeforces.com/profile/gop2024 "International Grandmaster gop2024")

[1649B - Game of Ball Passing](https://codeforces.com/contest/1649/problem/B "Codeforces Round 775 (Div. 2, based on Moscow Open Olympiad in Informatics)") was authored by [low_](https://codeforces.com/profile/low_ "Master low_") and prepared by [low_](https://codeforces.com/profile/low_ "Master low_") and [gop2024](https://codeforces.com/profile/gop2024 "International Grandmaster gop2024")

[1648A - Weird Sum](../problems/A._Weird_Sum.md "Codeforces Round 775 (Div. 1, based on Moscow Open Olympiad in Informatics)") was authored and prepared by [cookiedoth](https://codeforces.com/profile/cookiedoth "International Grandmaster cookiedoth")

[1648B - Integral Array](../problems/B._Integral_Array.md "Codeforces Round 775 (Div. 1, based on Moscow Open Olympiad in Informatics)") was authored by [grphil](https://codeforces.com/profile/grphil "Master grphil") and prepared by [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando")

[1648C - Tyler and Strings](../problems/C._Tyler_and_Strings.md "Codeforces Round 775 (Div. 1, based on Moscow Open Olympiad in Informatics)") was authored and prepared by [Tikhon228](https://codeforces.com/profile/Tikhon228 "Master Tikhon228")

[1648D - Serious Business](../problems/D._Serious_Business.md "Codeforces Round 775 (Div. 1, based on Moscow Open Olympiad in Informatics)") was authored and prepared by [ligaydima](https://codeforces.com/profile/ligaydima "Master ligaydima")

[1648E - Air Reform](../problems/E._Air_Reform.md "Codeforces Round 775 (Div. 1, based on Moscow Open Olympiad in Informatics)") was authored and prepared by [grphil](https://codeforces.com/profile/grphil "Master grphil")

[1648F - Two Avenues](../problems/F._Two_Avenues.md "Codeforces Round 775 (Div. 1, based on Moscow Open Olympiad in Informatics)") was authored by [I_love_myself](https://codeforces.com/profile/I_love_myself "Master I_love_myself") and prepared by [isaf27](https://codeforces.com/profile/isaf27 "International Grandmaster isaf27")

 
### [1649A - Game](https://codeforces.com/contest/1649/problem/A "Codeforces Round 775 (Div. 2, based on Moscow Open Olympiad in Informatics)")

It is easy to see that if there are no water locations, the answer is 00. Otherwise, we should jump from the last accessible from the start land location to the first land location from which the finish is accessible. In order to find these locations, one can use two consecutive while loops, one increasing ll from 11 until al+1=0al+1=0, and the other one decreasing rr from nn until ar−1=0ar−1=0. After the loops finish, we know that we should jump from the ll-th location to the rr-th at the cost of r−lr−l.

 
### [1649B - Game of Ball Passing](https://codeforces.com/contest/1649/problem/B "Codeforces Round 775 (Div. 2, based on Moscow Open Olympiad in Informatics)")

If $max(a) \cdot 2 \leq sum(a)$, we can always prove that we can only use one ball.

For other cases, the number of balls is determined by $2 \cdot max(a) - sum(a)$.

 
### [1648A - Weird Sum](../problems/A._Weird_Sum.md "Codeforces Round 775 (Div. 1, based on Moscow Open Olympiad in Informatics)")

We note that the manhattan distance between cells $(r_1, c_1)$ and $(r_2, c_2)$ is equal to $|r_1-r_2|+|c_1-c_2|$. For each color we will compose a list of all cells $(r_0, c_0), \ldots, (r_{k-1}, c_{k-1})$ of this color, compute the target sum for this color, and sum up the answers for all colors. The sum is equal:

$$ \sum_{i=0}^{k-1} \sum_{j=i+1}^{k-1} |r_i - r_j| + |c_i - c_j| = \left(\sum_{i=0}^{k-1} \sum_{j=i+1}^{k-1} |r_i - r_j|\right) + \left(\sum_{i=0}^{k-1} \sum_{j=i+1}^{k-1} |c_i - c_j|\right) $$

We will compute the first sum, the second sum is analogous. Let an array $s$ be equal to $r$, but sorted in increasing order. Then:

$$ \sum_{i=0}^{k-1} \sum_{j=i+1}^{k-1} |r_i - r_j| = \sum_{i=0}^{k-1} \sum_{j=i+1}^{k-1} s_j - s_i = \left(\sum_{i=0}^{k-1} \sum_{j=i+1}^{k-1} s_j\right) + \left(\sum_{i=0}^{k-1} \sum_{j=i+1}^{k-1} -s_i\right) $$

The value $s_j$ occurs in the first double sum exactly $j$ times, the value $-s_i$ occurs in the second sum exactly $k-1-i$ times. Then, the value is equal to:

$$ \sum_{j=0}^{k-1} js_j + \sum_{i=0}^{k-1} -(k-1-i)s_i = \sum_{i=0}^{k-1} (2i+1-k)s_i $$

The last sum can be computed in $O(k)$, the time complexity to sort an array is $O(k \log k)$. The overall complexity is $O(nm\log(nm))$. We can also sort arrays of coordinates by adding cells to lists in the right order. This yields an $O(nm)$ solution.

 
### [1648B - Integral Array](../problems/B._Integral_Array.md "Codeforces Round 775 (Div. 1, based on Moscow Open Olympiad in Informatics)")

Let's consider $x, y \in a$ and $r \notin a$. If $y \cdot r \le x < y \cdot (r + 1)$ then $\left \lfloor \frac{x}{y} \right \rfloor = r$, but $r$ is not in $a$, so the answer is "No". Let's suggest that $y$ and $r$ are already given. We can check if there exists such $x \in a$ from the mentioned segment in $O(1)$. It is done by considering array $cnt_x$ — the amount of occurrences of $x$ in $a$, and prefix sums for that array. Now we only need to run this check for each $r$ and $y$. To do that we can iterate through all $r \notin a$ and $y \in a$ in increasing order. If $r \cdot y > c$ then there is definitely no such $x$ so we can consider the next $r$. This optimization speeds up the process and makes the whole solution work in $O(C \log C)$.

 
### [1648C - Tyler and Strings](../problems/C._Tyler_and_Strings.md "Codeforces Round 775 (Div. 1, based on Moscow Open Olympiad in Informatics)")

Let $K$ be the size of the alphabet, that is, the number of the maximum letter that occurs in it.

First, let's calculate how many different strings can be composed if we have $c_1$ letters of the $1$th type, $c_2$ letters of the $2$th type, $\ldots$, $c_K$ letters of the $K$ type. This is the school formula:

$P(c_1, c_2, \ldots, c_K) = \frac{(c_1 + c_2 + \ldots + c_K)!}{c_1! \cdot c_2! \cdot \ldots \cdot c_K!} $

to quickly calculate it for different $c_1, c_2, \ldots, c_k$ pre-calculate all factorials and their reciprocals modulo $C = 998244353$ in O($n \cdot \log{C}$)

In order for the string $x$ to be less than the string t, they must have the same prefix. Let's iterate over the length of this matching prefix from $0$ to $\min(n, m)$. If strings $x$ and $t$ have the same first $i$ characters, then we know exactly how many letters we have left. To support this, let's create an array cnt, at the $i$-th position of which there will be the number of remaining letters of type $i$.

Let's iterate over the letter that will appear immediately after the matching prefix. For the resulting string to be less than $t$, this letter must be strictly less than the corresponding letter in $t$, and all subsequent letters can be arranged in any order. Let's calculate the number of rows $x$ considered in this way according to the formula above.

The only case where the resulting string $x$ can be lexicographically less than $t$, which we will not count, is when it is a prefix of the string $t$, but has a shorter length. We will separately check whether we can get such a string, and if so, add 1 to the answer.

Since at each of at most $\min(n, m)$ steps we need to go through at most $K$ options for the next letter, and we calculate each option in O($K$) - we get the asymptotics O($\min (n, m) \cdot K^2 + n \cdot \log{C}$)

To speed up the resulting solution, let's create an array $add$, in the $i$-th cell of which we store how many ways it will be possible to arrange the remaining letters if the letter $i$ is put in the current position. In fact $add_i = \frac{(cnt_1 + cnt_2 + \ldots + cnt_K - 1)!}{cnt_1! \cdot cnt_2! \cdot \ldots \cdot (cnt_i - 1)! \cdot \ldots \cdot cnt_K!}$

If we learn how to maintain this array, then at each step we only need to take the sum of the elements at some of its prefix. Let's see how it changes if the next letter in the string $t$ is $i$, i.e. $cnt_i$ should decrease by 1.

For all cells $j \neq i$ $add_j$ is replaced by $add_j \cdot \frac{cnt_i}{cnt_1 + cnt_2 + \ldots + cnt_K - 1}$. To apply modifications to the entire array, let's create a separate variable $modify$, by which we need to multiply the value in the cell to get the value that should be there.

For cell $i$, $add_i$ will be replaced by $add_i \cdot \frac{cnt_i - 1}{cnt_1 + cnt_2 + \ldots + cnt_K - 1}$. And taking into account the fact that we applied a modifier to all cells, it is enough to multiply the value of $add_i$ by $\frac{cnt_i - 1}{cnt_i}$

With this optimization, we now spend only O(K) actions at each step to calculate the prefix sum, and O($\log(C)$) to calculate what to multiply the array cells by. We get the asymptotics O($\min(n, m) \cdot (K + \log(C))$) To get rid of $K$ asymptotically, note that the only thing we want to do with the $add$ array is take the sum at the prefix and change the value at the point. This can be done in O($log(K)$ using the Fenwick Tree or the Segment Tree. Applying them, we get the final asymptotic O($\min(n, m) \cdot (\log(K) + \log(C)) $).

In fact, $\log(C)$ in the asymptotics can be eliminated by precalculating modulo reciprocals for all numbers from $1$ to $n$ faster than O($n \cdot \log(C)$), but in this task was not required.

 
### [1648D - Serious Business](../problems/D._Serious_Business.md "Codeforces Round 775 (Div. 1, based on Moscow Open Olympiad in Informatics)")

Let's denote $pref[i][j] := \sum_{k = 0}^{j - 1} a[i][k]$. Then define $s$ and $t$ as follows:

$$ s[i] = pref[0][i + 1] - pref[1][i] $$

$$ f[i] = pref[1][i + 1] - pref[2][i] + pref[2][n] $$

Now we can transform the problem to following: compute $\max\limits_{0\leq i\leq j < n} s[i] + f[j] - cost(i, j)$ where $cost(i, j)$ is the minimal cost of unlocking segment $[i, j]$. 

Let's define $dp[i]$ as the maximum profit for going from $(1, 1)$ to $(2, i)$, if the rightmost segment that we have used ends in $i$ (so it's $s[j]$ for some $j$ minus cost of covering segment $[i, j]$, when we know that there's a segment ending at $i$).

The calculation of $dp$ is as follows: for all $i$ look through each segment, which ends at $i$, and relax $dp[i]$ with $\max\limits_{l - 1\leq j < i} dp[j] - k$. It can be calculated using segment tree.

Now consider the optimal usage of segments. Fix the rightmost segment. The profit for this segment usage should be $dp[i] + f[j] + k$ for some $i, j$ on this segment. So we can bruteforce the rightmost segment in our answer and relax the overall answer with $\max\limits_{l\leq i\leq j\leq r} dp[i] + f[j] - k$. Also there's a case where taking only 1 segment is optimal, then we should relax the answer with $\max\limits_{l\leq i\leq j\leq r} s[i] + f[j] - k$. We can calculate all of this using segment tree.

Overall complexity is $O(q\, log\, n)$.

 
### [1648E - Air Reform](../problems/E._Air_Reform.md "Codeforces Round 775 (Div. 1, based on Moscow Open Olympiad in Informatics)")

The formal statement of this problem is that we have a weighted graph, for which we build it's complement, where the weight of an edge between $A$ and $B$ equals to minimal maximum on path from $A$ to $B$ in initial graph. The same way we calculate edge weights of initial graph, and we have to output them.

We can notice, that the path where maximum wight is minimal goes directly through the minumum spanning tree. That means that in order to get the final edges weights we need to calculate the minimum spanning tree on the graph complement and to get the final weights of initial edges we need to get the maximum on the tree path, which we can do in $O(m \log n)$ time with binary jumping pointers.

In order to build the minimum spanning tree of graph complement, we will do something like Kruskal algorithm. We will sort the edges of initial graph by their weights and store sets of connected vertices by edges of weights less than last added. The same way we will store the sets of connected vertices in graph complement by edges of weights less than last added. These complement components will form subsets of initial components. 

While adding a new edge, some connected components of initial graph can be merged. That means that some complement components can be merged. We can merge only those complement components, that are subsets of different initial components that became merged after adding an edge. These complement components become merged only if there exists some edge between two vertices of complement components in complement graph. In other words, between some pair of vertices in different complement components there is no edge in initial graph.

So when two initial components $S$ and $T$ become merged, we can iterate over all pair of complement components, such that first one is subset of $S$ and second one is subset of $T$. For each two vertices in them we should check that there is an edge between them in initial graph. Only in this case we can not merge these two complement components. For each of this unsuccessful attempt of merging two complement components, we do as much iterations, as there are edges between them in initial graph. So the total number of iterations in unsuccessful merges is $O(m)$. And for successful merges the complement components are merged and a new edge is added to complement minimum spanning tree. So the total number of successful merges is $O(n)$ and the total time if $O(m \log m)$ for edges sorting and $O(m)$ for complement MST build. After that we can find weights of initial edges in $O(m \log n)$ time.

 
### [1648F - Two Avenues](../problems/F._Two_Avenues.md "Codeforces Round 775 (Div. 1, based on Moscow Open Olympiad in Informatics)")

Let's consider two edges from the answer $e_1$, $e_2$. At least one of them should lie on dfs tree, otherwise the graph will be connected after removing $e_1$, $e_2$ and the answer will be $0$.

Let the answer be $e_1$, $e_2$, where $e_1$ lies on dfs tree. What cases can be for edges $e_1$, $e_2$? The edge $e_2$ should be a bridge of the graph without edge $e_1$ (otherwise $e_2$ can be any). Using this we can highlight possible cases:

1. Both edges $e_1$, $e_2$ are bridges of the graph.
2. The edge $e_1$ is the bridge of the graph, the edge $e_2$ does not matter.
3. The edge $e_1$ lies on dfs tree, the edge $e_2$ is the only outer edge covering the edge $e_1$.
4. Both edges $e_1$, $e_2$ lies on dfs tree, sets of outer edges covering $e_1$, and covering $e_2$ are equal.

For each case let's find the maximum answer.

For each of $k$ pairs of vertices let's consider the path between vertices in the pair.

For each edge $e$ of dfs tree let's calculate three values:

* $c_e$ — the number of paths, containing the edge $e$.
* $f_e$ — the number of outer edges, covering the edge $e$.
* $h_e$ — the hash of all outer edges, covering the edge $e$. For each outer edge let's give random $64$-bit integer, the hash will be equal to the sum of values.

In the first case, the answer for two bridges $e_1$, $e_2$ is equal to $c_{e_1} + c_{e_2}$. So we should find two brides with maximum value $c_e$.

In the second case, the answer for one bridge $e_1$ is equal to $c_{e_1}$. So we should find the bridge with maximum value $c_e$.

In the third case, we consider edges $e_1$, such that $f_{e_1} = 1$. The answer is $c_{e_1}$. So we should find edge $e_1$ of dfs tree, such that $f_{e_1} = 1$ with maximum value $c_{e_1}$.

The fourth case is very hard. We consider two edges $e_1$, $e_2$, such that $h_{e_1} = h_{e_2}$. The answer is equal to the number of paths, containing exactly one edge from $e_1$, $e_2$. We can divide each path into two vertical paths, the answer won't change.

The plan of the solution will be: let's make a dfs of the dfs tree and maintain the segment tree with operations add on segment, and maximum on segment. The prefix of the segment tree corresponds to edges on the path from the root to the current edge $e_2$. The value in the cell corresponding to the edge $e_1$ is equal to the answer for the pair of edges $e_1$, $e_2$.

It is possible to recalculate this segment tree with $O(n + k)$ updates during the dfs tree traversal.

The unsolved problem now is how to consider only edges $e_1$, such that $h_{e_1} = h_{e_2}$ in the maximum on segment. Let's call a cluster all edges with equal hash. All edges from one cluster lie on the vertical path. Let's consider the vertical path for each cluster: from the first occurrence of edge from the cluster to the last occurrence of edge from the cluster. Any two paths for two clusters either do not intersect or nested into each other.

When making a traversal let's add $-\infty$ on the segment from the last edge with hash $h_{e_2}$ to the edge $e_2$. This move will exclude edges from the maximum. This won't interfere the values, because all hashes from the segment won't be found later in the traversal (due to the clusters structure). After that, let's find the maximum on the segment from the first edge with hash $h_{e_2}$ to the edge $e_2$. In that maximum all edges with the hash $h_{e_2}$ will participate.

The total solution has the complexity $O(m + (n + k) \log{n})$.

