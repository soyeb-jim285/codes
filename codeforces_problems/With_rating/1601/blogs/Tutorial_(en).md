# Tutorial_(en)

Thanks for the participation!

[1602A - Two Subsequences](https://codeforces.com/contest/1602/problem/A "Codeforces Round 751 (Div. 2)") was authored and prepared by [napstablook](https://codeforces.com/profile/napstablook "Candidate Master napstablook")

[1602B - Divine Array](https://codeforces.com/contest/1602/problem/B "Codeforces Round 751 (Div. 2)") was authored and prepared by [Anti-Light](https://codeforces.com/profile/Anti-Light "Expert Anti-Light")

[1601A - Array Elimination](../problems/A._Array_Elimination.md "Codeforces Round 751 (Div. 1)") was authored and prepared by [isaf27](https://codeforces.com/profile/isaf27 "International Grandmaster isaf27")

[1601B - Frog Traveler](../problems/B._Frog_Traveler.md "Codeforces Round 751 (Div. 1)") was authored and prepared by [KiKoS](https://codeforces.com/profile/KiKoS "Master KiKoS")

[1601C - Optimal Insertion](../problems/C._Optimal_Insertion.md "Codeforces Round 751 (Div. 1)") was authored and prepared by [isaf27](https://codeforces.com/profile/isaf27 "International Grandmaster isaf27")

[1601D - Difficult Mountain](../problems/D._Difficult_Mountain.md "Codeforces Round 751 (Div. 1)") was authored and prepared by [Tikhon228](https://codeforces.com/profile/Tikhon228 "Master Tikhon228")

[1601E - Phys Ed Online](../problems/E._Phys_Ed_Online.md "Codeforces Round 751 (Div. 1)") was authored by jury and prepared by [fedoseev.timofey](https://codeforces.com/profile/fedoseev.timofey "International Grandmaster fedoseev.timofey")

[1601F - Two Sorts](../problems/F._Two_Sorts.md "Codeforces Round 751 (Div. 1)") was authored by [cdkrot](https://codeforces.com/profile/cdkrot "International Grandmaster cdkrot") and prepared by [cdkrot](https://codeforces.com/profile/cdkrot "International Grandmaster cdkrot"), [LHiC](https://codeforces.com/profile/LHiC "Legendary Grandmaster LHiC")

 
### [1602A - Two Subsequences](https://codeforces.com/contest/1602/problem/A "Codeforces Round 751 (Div. 2)")

Note that taking $a$ as minimum character in $s$ is always optimal ($a$ starts with minimum possible character and is prefix of any other longer string). In such case, $b$ is just all characters from $s$ except character from $a$.

 
### [1602B - Divine Array](https://codeforces.com/contest/1602/problem/B "Codeforces Round 751 (Div. 2)")

It can be shown that after at most $n$ steps of transformation, array $a$ becomes repetitive. There is even a better lower bound: it can be shown that after at most $\log(n)$ steps $a$ becomes repetitive, so we use either of these two facts to simulate the process and answer the queries.

 
### [1601A - Array Elimination](../problems/A._Array_Elimination.md "Codeforces Round 751 (Div. 1)")

Let's note, that in one destruction for any bit $i$ ($0 \leq i < 30$) we either change all $k$-th non-zero bits into zero bits, or nothing changes. So, the number of $i$-th non-zero bits in the array either decreases by $k$ or doesn't change. In the end, all these numbers will be equal to $0$. So, to be able to destruct the array, the number of $i$-th non-zero bits in the array should be divisible by $k$ for all bits $i$.

Let's prove, that it is enough to destruct the array. Let's make operations with non-zero AND, while we can make them. In the end, there is at least one non-zero element, if we have not destructed the array. So, there is at least one bit $i$, for which the number of $i$-th non-zero bits in the array is non-zero, so this number is at least $k$ (because it is divisible by $k$). So we can select $k$ numbers with $i$-th non-zero bit to the next operation and make the new destruction, which is impossible.

So the resulting solution is: for each bit $i$ ($0 \leq i < 30$) let's find the number of array's elements with non-zero $i$-th bit. Let's find all common divisors $k$ ($1 \leq k \leq n$) of these numbers.

Time complexity is $O(n \log{C})$, where $C = 10^9$  — upper limit on all numbers in the array.

 
### [1601B - Frog Traveler](../problems/B._Frog_Traveler.md "Codeforces Round 751 (Div. 1)")

Let's denote sequence of moves $i \Rightarrow i - a_i \dashrightarrow i - a_i + b_{i-a_i}$ as jump.

We will use $dp_i$ — minimal number of moves needed to travel from $i$ to $0$.

It can be calculated $dp_i = 1 + \min (dp_j + b_j)$, with $i - a_i \le j \le i$. We expected calculations to use bfs-style order. So, if there is a jump to $0$, $dp$ is $1$. If there is no jump to $0$, but there is a jump to position with $dp=1$, then $dp$ is $2$, and so on.

What happens, when we know all dp's with values from $0$ to $d$? We'll take position $v$ ($dp_v = d$) and all $u$ with condition $u + b_u = v$. Then all $j$ that has $j - a_j \le u \le j$ we know for sure $dp_j = d + 1$. For every $i$ we will save in minimum segment tree value $i - a_i$. So, all $j$'s are just elements from a suffix with value not greater than $u$.

We can iterate through all $j$'s, because every of them is used only once — right after we know $dp_j$, we can use any neutral value (infinity in our case).

Time complexity is $O(n \log n)$

Bonus. Try to solve it in linear time :)

 
### [1601C - Optimal Insertion](../problems/C._Optimal_Insertion.md "Codeforces Round 751 (Div. 1)")

Let's sort array $b$.

Let's define $p_i$ as the index of the array $a$, before which we should insert $b_i$. If $b_i$ should be inserted at the end of the array $a$, let's make $p_i = n + 1$.

Let's note, that all inserted elements should go in the sorted order in the optimal answer. If it is false and there exists $p_i > p_j$ for $i < j$, let's swap $b_i$ and $b_j$ in the answer. The number of inversions will decrease, a contradiction.

So $p_1 \leq p_2 \leq \ldots \leq p_m$. If we will find their values we will be able to restore an array after inserting elements.

Let's use "Divide and conquer" to find them. Let's write a recursive function $solve(l_i, r_i, l_p, r_p)$, that will find $p_i$ for all $l_i \leq i < r_i$, if it is known, that $p_i \in [l_p, r_p]$ for all such $i$. To find all values of $p$ we should call the function $solve(1, m + 1, 1, n + 1)$.

Realization of $solve(l_i, r_i, l_p, r_p)$:

* If $l_i \geq r_i$, we shouldn't do anything.
* Let $mid = \lfloor \frac{l_i + r_i}{2} \rfloor$. Let's find $p_{mid}$. The number of inversions with $b_{mid}$ will be (the number of $a_i > b_{mid}$ for $i < p_{mid}$) + (the number of $a_i < b_{mid}$ for $i \geq p_{mid}$). This sum differs by a constant from: (the number of $a_i > b_{mid}$ for $l_p \leq i < p_{mid}$) + (the number of $a_i < b_{mid}$ for $p_{mid} \leq i < r_p$). For this sum it is simple to find the minimal optimal $p_{mid}$ in $O(r_p - l_p)$.
* Let's make two recursive calls of $solve(l_i, mid - 1, l_p, p_{mid})$, $solve(mid + 1, r_i, p_{mid}, r_p)$, that will find all remaining values of $p$.

The complexity of this function will be $O((n+m)\log{m})$, because there will be $O(\log{m})$ levels of recursion and we will make $O(n+m)$ operations on each of them.

In the end, using the values $p_i$ we will restore the array and find the number of inversions in it.

Total complexity: $O((n+m)\log{(n+m)})$.

Also, there exist other correct solutions with the same complexity, using segment tree.

 
### [1601D - Difficult Mountain](../problems/D._Difficult_Mountain.md "Codeforces Round 751 (Div. 1)")

First, discard all $ i $ such that $ s_i < d $

Instead of climbers, we will consider pairs $ (s_i, a_i) $, and also say that the set of pairs is correct if there is a permutation $ p_1 \ldots p_n $ such that for every $ i : \max (d, a_ {p_1}, \ldots a_ {p_ {i-1}}) \le s_ {p_i} $, which means that there is an order in which all climbers can climb.

We will call a pair of indices $ i, j $ incompatible if $ i \neq j $ and $ s_j < a_i $ and $ s_i <a_j $. - this means that the $ i $-th climber cannot climb after the $ j $-th and vice versa. Note that if the set does not have an incompatible pair of indices, then it is correct. The suitable order for pairs $ (s_i, a_i) $ can be reached by sorting them in increasing order of pairs $ {min (s_i, a_i), \max (s_i, a_i)} $. After sorting either $ i $-th climber can go after $ (i - 1) $-th or the pair $ (i - 1), i $ is incompatible.

$ \quad $ Let's solve the problem with an additional restriction first, namely: for each $ i : s_i < a_i $, In this case, you can use the following greedy solution:

Let $ D = d $, find among the pairs $ (s_i, a_i) $ such that $ D \le s_i $, and among such pairs - the pair with the smallest $ a_i $ - it will be the next in our order. Replace $ D $ by $ a_i $, increase the answer by 1 and repeat the algorithm. If the pair with $ D \le s_i $ does not exist, terminate the algorithm. The correctness of such an algorithm is proved by induction.

To effectively implement this solution, let's sort all the pairs $ (s_i, a_i) $ in increasing order of $ a_i $

Let's go through the indices $ i $ from 1 to $ n $

$ \quad $ If $ D \le s_i $, then add 1 to the answer and replace $ D $ with $ a_i $.

$ \quad $ Let's get back to the main problem:

Consider a pair of indices $ i, j $ such that $s_i < a_j \le s_j < a_i$

Such a pair of indices is incompatible, and if the optimal answer contains $ i $, then it can be replaced with $ j $ and the sequence will not break.

$ \quad $ $ s_i < s_j \Rightarrow $ for any value of $ D $ that matches $ i $ it matches $ j $. $ \quad $ $ a_j < a_i \Rightarrow $ for any $ D: max (D, a_j) \le max (D, a_i) $

Therefore, for any such pair $ i, j $, the $ i $-th can be excluded from the set of climbers and the answer will not worsen.

$ \quad $ To effectively remove all such $ (s_i, a_i) $ pairs, we use the two-pointer method:

Let's take out all such pairs that $ a_i \le s_i $ into the $ b $ array. Let the remaining pairs be in the $ c $ array. Let's sort the array $ b $ in increasing order of $ a_i $ and the array $ c $ in increasing order of $ s_i $. Let's create an ordered set $ M $, which can store the pairs $ (s_i, a_i) $ in decreasing order of $ a_i $. Let's create a pointer $ j = 0 $.

Let's go through the elements of the $ b $ array with index i.

$ \quad $ For this item:

$ \quad $ While $ c_ {j} .s < b_ {i} .a $ we will add $ c_j $ to the set $ M $

$ \quad $ Now while $ b_ {i} .s < M_ {1} .a $ we will delete the first element M.

Among the elements of the $ b $ array, the $ M $ set and the remaining elements in the $ c $ array, there are no more required pairs.

Note that among the remaining pairs $ (s_i, a_i) $, any pair of indices $ i, j $ such that $ a_i \le s_i $ or $ a_j \le s_j $ is not incompatible.

Now, if we find the maximum correct subset of the pairs $ (s_i, a_i) $, such that $ s_i < a_i $ and combine it with the set of pairs $ (s_i, a_i) $, such that $ a_i \le s_i$, we get the correct set, moreover, for obvious reasons – it has maximum size. Therefore, we will get the answer to the problem.

 
### [1601E - Phys Ed Online](../problems/E._Phys_Ed_Online.md "Codeforces Round 751 (Div. 1)")

Observe that we need to buy a subscription at day one, then we need to buy the cheapest subscricption among first $k + 1$ days, $...$, then the cheapest among the first $tk + 1$ days. Let's denote $b_i$ as a minimum on a segment $[i - k, i - k + 1, ..., i]$, $b_i$ can be calculated in a linear time using monotonic queue. So the answer for query is $a_l + b_{l + k} + \textrm{min}(b_{l + k}, b_{l + 2k}) + ... + \textrm{min}(b_{l + k}, b_{l + 2k} + ... + b_{l + tk})$, where $l + tk \leq r$.

Observe that such a sum is independent of the remainder of the division of $l$ by $k$, so we can solve an easier problem instead: we are given with an array $c$, and we need to calculate a sum of prefix minimums on a segment. To solve this, let's calculate an array $nxt_i$ — the minimum position $nxt_i > i$ such that $c_{nxt_i} < c_i$. Let $dp_i$ be a sum of minimums on prefixes of $i$-th suffix. Observe that $dp_i = dp_{nxt_i} + c_i \cdot (nxt_i - i)$. To calculate a sum of prefix minimums on the segment $[l, r]$, find a position $p$, such that $a_p$ is a minimum on the segment $[l, r]$, then the answer is $dp_l - dp_p + (r - p + 1) \cdot c_p$. 

So we have a solution in $\mathcal{O}(n + q\alpha^{-1}(n))$, where $\alpha^{-1}$ is the inverse Ackermann function, if we use a Tarjan's algorithm for offline rmq. It was enough to use any logarithmic data structure to solve a problem.

 Tutorial is loading...