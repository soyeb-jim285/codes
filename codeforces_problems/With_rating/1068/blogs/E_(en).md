# E_(en)


### [1068A - Birthday](../problems/A._Birthday.md "Codeforces Round 518 (Div. 2) [Thanks, Mail.Ru!]")

To get $L$ new coins irrespective of the Ivan's collection he must get not less than $L+K$ coins as a present. Therefore each friend should gift at least $X = \lceil \frac{L+K}{M} \rceil $ coins. But it may be not possible for all friends to gift $X$ coins if $X \cdot M > N$. 

Complexity is $O(1)$.

 Tutorial is loading... Tutorial is loading... 
### [1067A - Array Without Local Maximums](https://codeforces.com/contest/1067/problem/A "Codeforces Round 518 (Div. 1) [Thanks, Mail.Ru!]")

Let's find solution with complexity $O(n \cdot a^2)$. We can count $dp[prefix][a][flag]$ — quantity of ways to restore element from $1$ to $pref$ with last element equalls to $a$, $flag = 0$ means that previous element is less then the last or last element is first, $flag = 1$ — the opposite. So $ dp[pref][a][0] = \sum_{i=1}^{a-1} (dp[pref-1][i][1] + dp[pref-1][i][0]) $, $ dp[pref][a][1] = dp[pref-1][a][0] + \sum_{i=a}^{200} dp[pref-1][i][1] $.

Now let's count $prefix \\_ sums[a][flag] = \sum_{i=1}^{a} dp[pref][i][flag]$ on each prefix before counting all $dp[pref]$, so we can recalculate dp in O(1) time.

Complexity is $O(n \cdot a)$.

 
### [1067B - Multihedgehog](https://codeforces.com/contest/1067/problem/B "Codeforces Round 518 (Div. 1) [Thanks, Mail.Ru!]")

Solution 1: 

Firstly let's find all vertices with degree $1$. Now we can delete them and all, verticies which were incident to them must became verticies with degree $1$. And also for each new veretice with degree $1$ we must have already deleted not less then $3$ verticies. If initial graph was $k$-multihedgehog, after deleting vertices with degree $1$ it would became $k-1$-multihedgehog.

It could be realised using bfs starting from all initial vertices with degree $1$.

Complexity is $O(n)$.

Solution 2: 

First of all let's find diametr of the graph. After that we can find middle vertex in diameter and check if it is a center of $k$-multihedgehog using simple dfs.

Complexity is $O(n)$.

 Tutorial is loading... 
### [1067D - Computer Game](https://codeforces.com/contest/1067/problem/D "Codeforces Round 518 (Div. 1) [Thanks, Mail.Ru!]")

Let's denote max(bipi) as M. Independent of our strategy we cannot get more than M in one second (in expected value). But if we could upgrade one quest, we would upgrade the quest which maximizes bipi and then try to complete only this quest each second, thus getting +M to expected value each second. Therefore, our strategy looks like this: try to complete quests in some order, once we complete one quest we will always get +M to expected value each second.

This observation leads to DP solution. Once we have one quest completed we already know what we will get, so interesting states are only those in which no quests are completed yet. Then it is not important what quests we tried to complete before, the only important parameter is remaining time.

dpt+1=max(pi(ai+tM)+(1−pi)dpt).

If we succeed then we will get ai as a reward and for remaining t seconds we will get M each second, otherwise we get nothing and now only t seconds left. This solution works in O(nT) time which is too slow.

We can slightly rewrite the formula for transition: dpt+1=max(pi(ai+tM)+(1−pi)dpt)=dpt+max(pi(tM−dpt)+piai).

Now we can see that we take maximum value of functions pi⋅x+piai in point xt=tM−dpt. We can build convex hull on these lines thus getting O(nlogn+Tlogn) solution.

But that's not all. We can actually prove that xt≤xt+1 or, after some substitutions and simplifications, dpt+1−dpt≤M. This we will prove by actual meaning of dpt. Take optimal solution for t+1 seconds and do the same for t seconds, except that we don't have last second, so we will just drop our action. But we can't gain more than M in one second, so this drop cannot decrease answer more than M. Thus the inequality is proven.

This means that we only move right along over convex hull, so for each line there will be consecutive seconds in which we are using that line. If we could somehow determine these segments of times for each line and learn how to make many DP transitions at once then we would solve the problem even faster.

Let's start with learning how to make many DP transitions (when we are staying on one line for the whole time). It is more clear using first formula for DP transition: dpt+1=pi(ai+tM)+(1−pi)dpt (we don't have max now because we already know which line to use). We can see that to get vector (dpt+1t+11)T from vector (dptt1)T we can apply linear transformation i.e. multiply by some matrix:

(dpt+1t+11)=(1−pipiMpiai011001)(dptt1)

To apply it k times just use binary exponentiation to get k-th power of transition matrix.

To determine how long we actually have to stay on given line we will use binary search on answer. We know for which value of x we should move to the next line and we know that x increases with each second, so we can try to stay on given line for some time and see if we should actually change the line.

This is already O(n(logn+log2T)) solution, but we can improve it one more time by making binary exponentiation and binary search on power for this exponentiation at the same time.

Final complexity is O(n(logn+logT))

 
### [1067E - Random Forest Rank](https://codeforces.com/contest/1067/problem/E "Codeforces Round 518 (Div. 1) [Thanks, Mail.Ru!]")

I'll try to explain how to come up with this solution rather than just state the fact. For those who are more interested in getting AC, here is your fact: rank of a forest is twice the size of maximal matching.

When we see expected value, we usually want to somehow rewrite the thing under the expected value, apply linearity of expectation and then calculate some independent values. But that's not the case: rank behave strangely and we cannot rewrite it as sum of something, at least I don't know any such solutions (if you do, please write them in the comments). So it looks like we are forced to understand what rank is.

The rank of a matrix is a size of its largest non-vanishing minor. But our matrix is symmetric, maybe we can look only at symmetric minors (in a sense that we use the same set of rows and columns)? This is actually true but it is just a fact from linear algebra (seems to be not very well known) and has little to do with our problem, so I'll drop its proof and if someone is interested, ask me in comments.

Why do we like symmetric minors? Because they correspond to induced subgraphs of our graph. And all induced subgraphs of a forest are forests too! So let's study when a forest has full rank.

To do it, let's calculate determinant of its matrix. Matrix has full rank iff its determinant is non-zero. Let's write a determinant as a sum over all permutations.

$det A = \sum_{\pi} \prod_{i=1}^{n} A_{i \pi_{i}}$

If $A_{i \pi_{i}} \ne 0$ then we have edge $(i, \pi_{i})$ in our forest. Each permutation is a product of independent cycles. So to have non-zero product $\prod_{i=1}^{n} A_{i \pi_{i}}$ all the permutation cycles should be cycles in the forest. But forests have no cycles without repeating vertices! Well, actually they do: each edge generate one cycle of length $2$. And that's all, there are no other cycles in forest ($1$ vertex is not a cycle, because we don't have self-loops). To have non-zero product $\prod_{i=1}^{n} A_{i \pi_{i}}$ all cycles of permutation must have length $2$ and correspond to edges of forest. So we can divide all vertices in pairs, and in each pair there is an edge. That's the definition of perfect matching. Why can't they still result in zero sum? Because if there is a perfect matching in a forest then it is unique, so we actually have no more than one non-zero summand.

OK, forest has full rank is equivalent to forest has perfect matching. Suppose that $m$ is the size of maximal matching of a forest. Then no its induced subgraph of size strictly greater than $2m$ can have perfect matching. And there is a subgraph of size exactly $2m$ which does have perfect matching: the ends of edges in maximal matching.

Cool, we have proven the fact from the beginning. If you just want AC, continue reading from here. Now we have to calculate expected size of maximal matching. That sound much easier: we already have a linear DP which calculates maximal matching, and its values are exactly sizes of current maximal matching. To remind: $dp[v][taken]$ is a size of maximal matching in subtree rooted at $v$ where boolean flag $taken$ means did we already cover vertex $v$ or is it still free. All we have to do is to change the value stored in DP for expected value and also calculate probabilities to actually be in state with given flag $taken$.

Complexity — $O(n)$.

