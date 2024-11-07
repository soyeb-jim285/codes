# Tutorial_(en)


### [1355A - Sequence with Digits](../problems/A._Sequence_with_Digits.md "Codeforces Round 643 (Div. 2)")

Let's calculate the sequence for fixed $a_{1} = 1$: $1, 2, 6, 42, 50, 50, 50, \ldots$

We got lucky and the minimal digit has become 0, after that the element has stopped changing because we always add 0.

Actually it is not luck and that will always happen. Note that we add no more than $9 \cdot 9 = 81$ every time, so the difference between two consecutive elements of the sequence is bounded by 81. Assume that we will never have minimal digit equal to 0. Then the sequence will go to infinity. Let's take $X = 1000(\lfloor \frac{a_{1}}{1000} \rfloor + 1)$. All the numbers on segment $[X;X+99]$ have 0 in hundreds digit, so none of them can be element of our sequence. But our sequence should have numbers greater than $X$. Let's take the smallest of them, it should be at least $X + 100$. But then the previous number in the sequence is at least $(X + 100) - 81 = X + 19$. It is greater than $X$ but smaller than the minimal of such numbers. Contradiction.

In the previous paragraph we have actually shown that we have no numbers greater than $X + 100$ in our sequence and we will see the number with 0 among first 1001 elements.

That means that we can build the sequence till we find the first number with 0 and then it will repeat forever.

In reality the maximal index of the first elements with 0 is 54 and minimal $a_{1}$ for that to happen is 28217.

Author's solution: [80407149](https://codeforces.com/contest/1355/submission/80407149 "Submission 80407149 by DishonoredRighteous")

 
### [1355B - Young Explorers](../problems/B._Young_Explorers.md "Codeforces Round 643 (Div. 2)")

Let's sort all the explorers by non-decreasing inexperience. Suppose we have formed some group, how can we check is this group is valid? Inexperience of all the explorers in the group should be not greater than the group size. But we have sorted all the explorers, so the last explorer from the group has the largest inexperience. Therefore, to check the group for validity it is necessary and sufficient to check that inexperience of the last explorer is not greater than the group size.

We can notice that we don't even look at all the explorers except the last one, the only important thing is their number. In fact, we can organize the creation of groups in this way: first choose the explorers that will be the last in their groups, then assign sufficient number of other explorers to corresponding groups. It is not profitable to assign more explorers than needed for this particular last explorer, because we can always leave them at the camp.

So how should we choose the last explorers? We want to make more groups, so the groups themselves should me smaller... It is tempting to use the following greedy algorithm: let's greedily pick the leftmost (which means with the smallest necessary group size) explorer such that they have enough explorers to the left of them to create a valid group. The idea is that we spend the smallest number of explorers and leave the most potential last explorers in the future. Let's strictly prove this greedy:

The solution is defined by positions of the last explorers in their corresponding groups $1 \le p_{1} < p_{2} < \ldots < p_{k} \le n$. Notice that the solution is valid if and only if $e_{p_{1}} + e_{p_{2}} + \ldots + e_{p_{i}} \le p_{i}$ for all $1 \le i \le k$ (we always have enough explorers to form first $i$ groups).

Let $1 \le p_{1} < p_{2} < \ldots < p_{k} \le n$ be the greedy solution and $1 \le q_{1} < q_{2} < \ldots < q_{m} \le n$ be the optimal solution such that it has the largest common prefix with greedy one among all optimal solutions. Let $t$ be the position of first difference in these solutions. $t \le k$ since otherwise the greedy algorithm couldn't add one more group but it was possible. $p_{t} < q_{t}$ since otherwise the greedy algorithm would take $q_{t}$ instead of $p_{t}$. Since the explorers are sorted we have $e_{p_{t}} \le e_{q_{t}}$. But then $1 \le q_{1} < q_{2} < \ldots < q_{t - 1} < p_{t} < q_{t + 1} < \ldots < q_{m} \le n$ is a valid optimal solution and it has strictly larger common prefix with the greedy one which contradicts the choosing of our optimal solution.

To implement this solution it is enough to sort the explorers by the non-decreasing inexperience, then go from left to right and maintain the number of unused explorers. As soon as we encounter the possibility to create a new group, we do it.

Author's solution: [80407200](https://codeforces.com/contest/1355/submission/80407200 "Submission 80407200 by DishonoredRighteous")

 
### [1355C - Count Triangles](../problems/C._Count_Triangles.md "Codeforces Round 643 (Div. 2)")

Since $x \le y \le z$ to be a non-degenerate triangle for given triple it is necessary and sufficient to satisfy $z < x + y$. Let's calculate for all $s = x + y$ how many ways there are to choose $(x, y)$. To do that we will try all $x$ and add 1 on segment $[x + B; x + C]$ offline using prefix sums. Let's calculate prefix sums once more, now we can find in $O(1)$ how many ways there are to choose $(x, y)$ such that their sum if greater than $z$. Try all $z$, calculate the answer. Total complexity — $O(C)$.

Author's solution using formulas: [80407222](https://codeforces.com/contest/1355/submission/80407222 "Submission 80407222 by DishonoredRighteous")

Author's solution using prefix sums: [80407239](https://codeforces.com/contest/1355/submission/80407239 "Submission 80407239 by DishonoredRighteous")

 
### [1355D - Game With Array](../problems/D._Game_With_Array.md "Codeforces Round 643 (Div. 2)")

For $S \ge 2N$ Petya wins: let's take array $[2, 2, \ldots, 2, S - 2(N - 1)]$ and $K = 1$. All the elements are strictly greater than 1, so there are no segment with sum 1 or $S - 1$.

Let's prove that for $S < 2N$ Petya will lose. Suppose it is not true and there exist an array and $K > 0$ (it is obvious that $K = 0$ is bad). Note that the condition that there is a segment with sum $K$ or $S - K$ is equivalent to the condition that there is a segment with sum $K$ in cyclic array. Let's calculate prefix sums for our array, and for prefix sum $M$ let's mark all the numbers of the form $M + TS$ for integer $T \ge 0$. It is easy to see that numbers $X$ and $X + K$ cannot be marked simultaneously: otherwise there is a segment with sum $K$ in a cyclic array. Let's consider half-interval $[0; 2KS)$. It is clear that exactly $2KN$ numbers are marked on this half-interval. On the other hand, we can split all the numbers from this half-interval into $KS$ pairs with difference $K$: $(0, K), (1, K + 1), \ldots, (K - 1, 2K - 1), (2K, 3K), (2K + 1, 3K + 1), \ldots (2KS - K - 1, 2KS - 1)$. In every such pair no more than one number is marked, so the total number of marked numbers is bounded by $KS$. Therefore $2KN \le KS$ which means $2N \le S$. Contradiction.

Author's solution: [80407273](https://codeforces.com/contest/1355/submission/80407273 "Submission 80407273 by DishonoredRighteous")

 
### [1355E - Restorer Distance](../problems/E._Restorer_Distance.md "Codeforces Round 643 (Div. 2)")

First of all let's do $M = \min(M, A + R)$ — this is true since we can emulate moving by adding+removing. After that it is never profitable to add and remove in one solution, since we can always move instead.

Suppose we have fixed $H$ — the resulting height for all pillars. How can we calculate the minimal cost for given $H$? Some pillars have no more than $H$ bricks, let the total number of missing bricks in these pillars be $P$. Other pillars have no less than $H$ bricks, let the total number of extra bricks in these pillars be $Q$. If $P \ge Q$ then we are missing $(P - Q)$ bricks in total, so we have to make $(P - Q)$ additions. There won't be any more additions or removals, and we have to do at least $Q$ moves since we have to somehow get rid of extra bricks from those pillars which have more than $H$ bricks initially. It is clear that $Q$ moves is enough. Therefore the total cost will be $C = A(P - Q) + MQ$. Similarly, if $Q \ge P$ then the total cost will be $C = R(Q - P) + MP$.

Let's now assume that $P \ge Q$, we have exactly $X$ pillars with no more than $H$ bricks and exactly $N - X$ pillars with strictly more than $H$ bricks. Let's try to increase $H$ by 1 and see how the total cost will change. $P' = P + X$, $Q' = Q - (N - X) = Q - N + X$. $C' = A(P' - Q') + MQ' = A(P + X - Q + N - X) + M(Q - N + X) = A(P - Q) + MQ + AN - M(N - X)$. We can see that the total cost has changed by $AN - M(N - X)$. While $X$ is constant the cost change will be constant. What are the moments when $X$ changes? When $H$ is equal to the initial height of some pillar. Therefore the cost as a function of $H$ is piecewise linear with breakpoints in points corresponding to initial heights.

There is a nuance — we have assumed $P \ge Q$. The same thing will be true for $P \le Q$ but there can be additional breakpoints when we change between these two states. This change will happen only once for $H \approx \frac{\sum h_{i}}{N}$ (approximate equality here means that this point can be non-integral so we should add both $\lfloor \frac{\sum h_{i}}{N} \rfloor$ and $\lceil \frac{\sum h_{i}}{N} \rceil$ as breakpoints).

The minima of piecewise linear function are in breakpoints so it is enough to calculate the cost for breakpoints (initial heights and $H \approx \frac{\sum h_{i}}{N}$) and choose minimal of them.

To calculate the cost for given $H$ fast we can sort the initial heights and calculate prefix sums of heights. Then using binary search we can determine which pillars have height less than $H$ and greater than $H$ and then calculate $P$ and $Q$ using prefix sums. We can use two pointers instead of binary searches but it will not improve the total complexity which is $O(N \log N)$ due to sorting (and binary searches if we are using them).

Author's solution: [80407303](https://codeforces.com/contest/1355/submission/80407303 "Submission 80407303 by DishonoredRighteous")

Author's solution using ternary search: [80407326](https://codeforces.com/contest/1355/submission/80407326 "Submission 80407326 by DishonoredRighteous")

 
### [1355F - Guess Divisors Count](../problems/F._Guess_Divisors_Count.md "Codeforces Round 643 (Div. 2)")

If $X = p_{1}^{\alpha_{1}} \cdot p_{2}^{\alpha_{2}} \cdot \ldots \cdot p_{k}^{\alpha_{k}}$ then $d(X) = (\alpha_{1} + 1) \cdot (\alpha_{2} + 1) \cdot \ldots \cdot (\alpha_{k} + 1)$.

If $X$ has prime $p$ in power $\alpha$ and $Q$ has $p$ in power $\beta$ then $gcd(X, Q)$ will have $p$ in power $\gamma = \min (\alpha, \beta)$. If $\gamma < \beta$ then $\alpha = \gamma$, otherwise $\gamma = \beta$ and $\alpha \ge \gamma$. We don't know $X$, but we can choose $Q$. If we'll choose $Q$ with known prime factorization then we'll be able to extract all the information from query fast (in $O(\log Q)$).

After all the queries for each prime $p$ we'll know either the exact power in which $X$ has it, or lower bound for it. We can get upper bound from the fact that $X \le 10^{9}$.

It is clear that we cannot get information about all primes — there are too many of them and too few queries. We want to somehow use the fact that we don't have to find the exact answer...

Suppose we have figured out that $X = X_{1} \cdot X_{2}$ where we know $X_{1}$ exactly and we also know that $X_{2}$ has no more than $t$ prime factors (including multiplicity). Then $d(X_{1}) \le d(X) \le d(X_{1}) \cdot d(X_{2}) \le d(X_{1}) \cdot 2^{t}$. If $t \le 1$ then our answer will have relative error no more than $0.5$...

One of the ways to guarantee that $X_{2}$ has few prime factors is to show that it cannot have small prime factors. That means that we have to calculate the exact power for all small primes. This gives an overall idea for the solution: let's make a query $Q=p^{\beta}$ for all primes $p \le B$ (for some bound $B$) where $\beta$ is chosen in such a way that $p^{\beta} > 10^{9}$. This allows us to know the exact power in which $X$ has $p$.

This basic idea can be improved in several ways:

1. $X$ has no more than 9 different prime factors, so for most primes its power is 0. If we could exclude these redundant primes fast it could speed up the solution significantly. And there is a way: we could make a query $Q = p_{1} p_{2} \ldots p_{s}$ for $s$ different primes, after that we will know which of them are factors of $X$;
2. $\beta$ can be chosen such that $p^{\beta + 1} > 10^{9}$, because even if $\gamma = \beta$ and $\alpha \ge \gamma = \beta$ we will know that $\alpha \le \beta$ since otherwise $X > 10^{9}$;
3. From the previous point follows that we can find the exact power for two primes simultaneously, just make a query with a product of two respective numbers.

How to choose $B$? Apparently we want $B^{2} > 10^{9}$. But actually $t \le 2$ is ok for us: if we know that $L \le d(X) \le 4L$ then we can answer $2L$ and the relative error will be no more than $0.5$. That means we want $B^{3} > 10^{9}$ or $B = 1001$.

We are close: there are 168 primes less than 1001, we can check 6 primes (for being a factor of $X$) in one query since $1000^{6} \le 10^{18}$, so we need 28 queries.

Let's note that if we have found some prime factors of $X$ (let's say their product is $X_{1}$) then $X_{2} \le \frac{10^{9}}{X_{1}}$. Suppose we have checked all the primes not greater than $p$ and $X_{1} \cdot p^{3} > 10^{9}$. That means that $X_{2}$ has no more than 2 prime divisors and we are good.

What is left is to use our right to have absolute error: if $X_{1} \le 3$ we can just print 8! Either $X_{1} \le 3$ and we are fine with $X_{2}$ having 3 prime factors, or $X_{1} \ge 4$ and we have to check all primes up to $\sqrt[3]{10^{9} / 4} < 630$. There are 114 such primes, so we need only 19 queries.

We will also need some queries to find out the exact power for those small prime factors of $X$ we have found. If we have found no more than 2 prime factors, we'll need 1 query, otherwise we'll have to check primes only up to $\sqrt[3]{10^{9} / (2 \cdot 3 \cdot 5)} < 330$, of which there are only 66 so the first part of the solution spends no more than 11 queries.

So we have shown that the solution spends no more than 20 queries. We did some rough estimations, the actual bound for this solution is 17 queries.

Author's solution: [80407360](https://codeforces.com/contest/1355/submission/80407360 "Submission 80407360 by DishonoredRighteous")

