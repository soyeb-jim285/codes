# Tutorial


### [1087A - Right-Left Cipher](https://codeforces.com/contest/1087/problem/A "Codeforces Round 528 (Div. 2, based on Technocup 2019 Elimination Round 4)")

You can simulate the process, maintaining the indices of characters of the initial string. So, like this you can find the value of character of the initial string.

 
### [1087B - Div Times Mod](https://codeforces.com/contest/1087/problem/B "Codeforces Round 528 (Div. 2, based on Technocup 2019 Elimination Round 4)")

$n$ has to be divisible by $p = x \bmod k$, which in turn is less than $k$. We can try all options of $p$ (in $O(p)$ time), and for suitable options restore $x = p \cdot \frac{n - p}{k}$. Choose the smallest possible $x$. Note that $p = 1$ always divides $n$, hence at least one option will always be available.

 
### [1086A - Connect Three](https://codeforces.com/contest/1086/problem/A "Codeforces Round 528 (Div. 1, based on Technocup 2019 Elimination Round 4)")

The smallest possible number of plots required to connect all three plots is at least $\Delta_x + \Delta_y + 1$, where $\Delta_x = x_{max} - x_{min}$ and $\Delta_y = y_{max} - y_{min}$ (here $x_{min}$, $x_{maxn}$, $y_{min}$, $y_{max}$ are extreme coordinate values among the three given plots). It now suffices to find any suitable collection of plots of this size.

Let $x_m$ and $y_m$ be the median values of $(x_A, x_B, x_C)$ and $(y_A, y_B, y_C)$. For each of the plots $A$, $B$, $C$ connect it with the plot $(x_m, y_m)$ with any shortest path (if one of $A$, $B$, $C$ coincides with $(x_m, y_m)$, just do nothing). One can check that the resulting collection has size exactly $\Delta_x + \Delta_y + 1$, and it clearly connects $A$, $B$ and $C$ together.

The above solution has complexity $O(C)$, where $C$ is the largest coordinate value. Given that $C$ is quite small, one could go with slower solutions, for instance, instead of $(x_m, y_m)$ try all $C^2$ plots as the connecting plot.

 
### [1086B - Minimum Diameter Tree](https://codeforces.com/contest/1086/problem/B "Codeforces Round 528 (Div. 1, based on Technocup 2019 Elimination Round 4)")

Let's denote the number of leaves in this tree for $l$.

Let's prove that the answer is $\frac {2s} {l}$.

To construct an example with such diameter, let's put the weight $\frac s l$ to the edge adjacent to the leaf, and let's put the weight $0$ to other edges. It is easy to see that the diameter of this tree is $\frac {2s} {l}$.

To prove that it is the minimal possible diameter we denote leaf numbers for $a_1, \ldots, a_l$. For $dist_{{x}{y}}$ we denote the sum of weights of edges lying on the path between vertices $x$ and $y$. Then $\frac {l(l-1)} 2 \cdot \max\limits_{1 \leq i < j \leq l}dist_{{a_i}{a_j}} \geq \sum\limits_{1 \leq i < j \leq l}dist_{{a_i}{a_j}}$. Note that the contribution to the sum on the right side of the inequality of the weight of each edge will be at least $l-1$, because any edge lies on $\geq l-1$ paths between the leaves of the tree. So, $\sum\limits_{1 \leq i < j \leq l}dist_{{a_i}{a_j}} \geq (l-1) \cdot \sum\limits_{e \in E} weight_e = (l-1) \cdot s$. So, $\frac {l(l-1)} 2 \cdot \max\limits_{1 \leq i < j \leq l}dist_{{a_i}{a_j}} \geq (l-1) \cdot s$ and we get that $\max\limits_{1 \leq i < j \leq l}dist_{{a_i}{a_j}} \geq \frac {2s} l$.

So, to solve this problem you need to calculate the number of leaves in the tree. This can be done in linear time by counting all degrees of vertices.

Time comlexity: $O(n)$.

 Tutorial is loading... 
### [1086D - Rock-Paper-Scissors Champion](https://codeforces.com/contest/1086/problem/D "Codeforces Round 528 (Div. 1, based on Technocup 2019 Elimination Round 4)")

First, let's determine which players can win in a given configuration. If all players have the same shape, then everyone can win. If there are only two kinds of shapes, then one shape always loses, and everyone with the other shape can win. Let's now assume there are all three shapes present. If a player $i$ can win, then they have to independently eliminate everyone to either side. It suffices to determine if $i$ can win everyone to their left (the other side can be treated symmetrically).

Suppose that the player $i$ has the shape R (all the other cases are similar). We will show that $i$ can not eliminate everyone to the left if and only if two conditions hold:

* there is no S to the left of $i$;
* there is at least one P to the left of $i$.

Indeed, if both of these are true, there is nothing stopping a P from eliminating $i$. Otherwise, if there are no P to the left of $i$, he can potentially win everyone there.

Finally, suppose that there is an S to the left of $i$. Here's how $i$ can eliminate everyone to the left. First, eliminate all P's as follows: locate the closest pair of P and S, bring them together by eliminating all R's in between with the P, then eliminate the P. When we've eiliminated all P's this way, we are left with the previous case (no P's).

Now, how to deal with modifications? Assume that there are currently all three shapes present (otherwise we can easily find the answer as described at the start). How many R's can not win (similar for P's and S's)? According to our criterion, all R's losing because they can not eliminate their respective left-hand sides are located between $P_0$ and $S_0$, where $P_0$ and $S_0$ are positions of the first P and S (that is, when $P_0 < S_0$, otherwise there are no R's losing this way). A similar condition applies to the R's losing because of the right-hand side. Now we simply count the number of R's in these ranges and subtract them from the total. Note that we can never subtract an R twice since there is at one S on one of its sides.

It now suffices to use any data structure that supports range summing and finding extreme values in a set, with modifications. For the range summing we may use a Fenwick tree (BIT) or a segment tree, and for extreme values an std::set will suffice. All operations we need take $O(\log n)$ time, hence each modification and answer takes $O(\log n)$ time.

 
### [1086E - Beautiful Matrix](https://codeforces.com/contest/1086/problem/E "Codeforces Round 528 (Div. 1, based on Technocup 2019 Elimination Round 4)")

Calculate the following dp: $dp[n]$ — the number of permutations of length $n$ of elements $1 \dots n$ such that $p_i \ne i$ for every $i = 1 \dots n$

$dp[n] = (n - 1) \cdot (dp[n - 1] + dp[n - 2])$;

Calculate the following dp: $dp2[n][k]$ — the number of permutations of length $n$ of elements $1, 2, \dots, n, n + 1, n + 2, \dots, 2n - k$ such that $p_i \ne i$

$dp2[n][0] = n!$

$dp2[n][k] = dp2[n][k - 1] - dp2[n - 1][k - 1]$;

We can follow the usual process of recovering the lexicographic index. Iterate over the element to put in the current position and add the number of ways to complete the matrix to the answer.

How to calculate the number of ways to complete the matrix?

The current row can be completed the following way:

Look at the elements of the previous row (the same suffix as the one we want to complete), renumerate its elements into $1 \dots t$, where $t$ is the length of suffix. The current row now incudes some elements which appeared in the suffix of the previous row and some which don't. Let's renumerate those that appeared correspondingly. Let there be $k$ of such elements. Then the number of ways to complete the row is $dp2[t][k]$.

The other rows can be completed the following way:

For any row the previous one can be renumerated into permutation of form $1 \dots n$, thus the number of ways to choose the current row is $dp[n]$.

The only thing left is to raise $dp[n]$ to the power of the number of rows to be completed.

That solution is $O(N^3)$ as we were looking into all the candidates for the current position. However, these candidates can be split up into two groups: those that change the value of $k$ by 1 and those that leave it as is. Thus a single cell can be processed in $O(\log N)$ with a couple of data structures.

 
### [1086F - Forest Fires](../problems/F._Forest_Fires.md "Codeforces Round 528 (Div. 1, based on Technocup 2019 Elimination Round 4)")

Let $f(t)$ be the total number of trees burnt during first $t$ seconds. The answer can be represented as $t f(t) - \sum \limits_{i = 0}^{t - 1} f(i)$. Computing one value of $f(t)$ can be done in $O(n^2)$ or $O(n \log n)$ with scanline or something like that.

Let's analyze how the value of this function is changed as time goes. In the beginning, only $n$ initial trees are burnt, then the zones around their position, expand, and so on, until two zones start intersecting. Then again, until another pair of zones starts intersecting. And so on. Let $x_1, x_2, \dots, x_k$ be the sorted sequence of moments when two zones start intersecting (this sequence has no more than $O(n^2)$ elements and can easily be computed in $O(n^2 \log n)$). Let's analyze the behavior of the function $f(t)$ on segments $[0, x_1 - 1], [x_1, x_2 - 1]$ and so on.

Why are we interested in such segments? Because for each such segment, $f(t)$ can be represented as a polynomial. This can be proven with the help of inclusion-exclusion: for each subset of zones, the intersection of zones is either empty or a rectangle. And if we expand the rectangle, then during second $0$ its area is $ab$, during second $1$ — $(a + 2)(b + 2)$, during second $t$ — $(a + 2t)(b + 2t)$, it's a $2$-nd degree polynomial. So if we would try to compute the area of affected land through inclusion-exclusion formula, we would get a sum of no more than $2^n$ polynomials, each having degree no more than $2$, so the result is also a $2$-nd degree polynomial. We can actually compute the coefficients of this polynomial by interpolation or just some pen and paper work. And $f(x_i) + f(x_{i} + 1) + f(x_{i} + 2) + \dots + f(x_{i + 1} - 1)$ is a polynomial of $3$-rd degree, which can be computed using some more pen and paper work.

So, to conclude, the solution consists of two steps:

1. find all the moments when two zones affected by different trees start intersecting;
2. consider the function on the segments when it behaves as a polynomial.
