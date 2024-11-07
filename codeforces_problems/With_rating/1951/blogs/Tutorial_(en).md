# Tutorial_(en)

Hi, we hope you enjoyed our problems! For the playlist of songs used in the problem statements, click [this link](https://codeforces.com/https://www.youtube.com/playlist?list=PLTVdHvnX6LZhAJre49E7M7tpGA30WlBM3).

[1951A - Dual Trigger](../problems/A._Dual_Trigger.md "Codeforces Global Round 25")

Author: [MofK](https://codeforces.com/profile/MofK "Grandmaster MofK")   
 Prepared by [Kuroni](https://codeforces.com/profile/Kuroni "International Grandmaster Kuroni")   
 First solve: [xiachong](https://codeforces.com/profile/xiachong "Grandmaster xiachong") at 00:01

 **Tutorial and Implementation**
### [1951A - Dual Trigger](../problems/A._Dual_Trigger.md "Codeforces Global Round 25")

The answer is obviously "NO" if there is an odd amount of 1 in s. When there are zero 1's, the answer is trivially "YES". When there are exactly two 1's in s, then we also need to check whether the two 1's are adjacent or not.

Otherwise, when there are k≥4 1's in s, let their positions be x1,x2,…,xk. Note that we can always turn on the xi-th and the xi+k/2-th lamp as they are not adjacent. Therefore the answer is "YES" in this case.

[255371605](https://codeforces.com/contest/1951/submission/255371605 "Submission 255371605 by Kuroni")

 **Rate this problem**Yay 


[*293*](https://codeforces.com/data/like?action=like "I like this")





 Meh 

 
[*76*](https://codeforces.com/data/like?action=like "I like this")




 Nay 

 
[*36*](https://codeforces.com/data/like?action=like "I like this")




 Banger song 

 
[*40*](https://codeforces.com/data/like?action=like "I like this")



[1951B - Battle Cows](../problems/B._Battle_Cows.md "Codeforces Global Round 25")

Author: [MofK](https://codeforces.com/profile/MofK "Grandmaster MofK")   
 Prepared by [Kuroni](https://codeforces.com/profile/Kuroni "International Grandmaster Kuroni")   
 First solve: [pavement](https://codeforces.com/profile/pavement "Master pavement") at 00:05

 **Hint 1**What is the condition for your cow to win her first match?

 **Hint 2**If your cow is not already winning her first match, there are at most two candidate positions you can swap her to.

 **Tutorial and Implementation**
### [1951B - Battle Cows](../problems/B._Battle_Cows.md "Codeforces Global Round 25")

It is easy to note that the $i$-th match is between cow $i+1$ and the strongest cow among cows $1, 2, \cdots, i$. Therefore, in order to win any match at all, you cow have to be stronger than every cow before her (and cow $2$ if your cow is cow $1$). Consider the following cases:

* There exists no stronger cow before your cow. Then you should maximize the number of wins by swapping your cow with cow $1$.
* There exists some stronger cows before your cow. Let $i$ be the first such cow. Obviously you want cow $i$ to end up to the right of your cow. There are two ways to achieve this:
	+ Swap your cow before cow $i$. Since your cow will lose to cow $i$ anyway, you should maximize the number of wins by swapping with cow $1$.
	+ Swap your cow with cow $i$.

The answer for the problem is the maximum among all above candidates. Since there are only $2$ of them, the overall time complexity is $O(n)$.

[255371643](https://codeforces.com/contest/1951/submission/255371643 "Submission 255371643 by Kuroni")

 **Comments from the authors**This problem was added after [1951D - Buying Jewels](../problems/D._Buying_Jewels.md "Codeforces Global Round 25") was deemed too hard to be problem B. At first, we decided to hide the case of swapping with the first stronger cow from the sample test. The testers weren't too impressed:

![ ](images/d915ad709a1e6b7ad88880dab0b1966eb0bcbfa1.png)

 **Rate this problem**Yay 

 
[*342*](https://codeforces.com/data/like?action=like "I like this")




 Meh 

 
[*136*](https://codeforces.com/data/like?action=like "I like this")




 Nay 

 
[*80*](https://codeforces.com/data/like?action=like "I like this")




 Banger song 

 
[*48*](https://codeforces.com/data/like?action=like "I like this")



[1951C - Ticket Hoarding](../problems/C._Ticket_Hoarding.md "Codeforces Global Round 25")

Author: [MofK](https://codeforces.com/profile/MofK "Grandmaster MofK")   
 Prepared by [Kuroni](https://codeforces.com/profile/Kuroni "International Grandmaster Kuroni")   
 First solve: [arvindf232](https://codeforces.com/profile/arvindf232 "Legendary Grandmaster arvindf232") at 00:11

 **Hint 1**If there is no additional cost (i.e. buying a ticket at day ii costs only aiai), what is the optimal buying strategy?

 **Hint 2**If there \textit{is} additional cost but ai=1ai=1 for all ii, what is the optimal buying strategy?

 **Hint 3**The above two strategies are the same, and the primary and secondary costs are independent of each other. \textit{Surely} the solution is not just choosing kk cheapest tickets right?

 **Tutorial and Implementation**
### [1951C - Ticket Hoarding](../problems/C._Ticket_Hoarding.md "Codeforces Global Round 25")

Note: we will present the intuitive idea first; the formal proof follows later.

Let's try to find a way to interpret the raised price at day $i$ from buying on earlier days. We know that every ticket bought on an earlier day than $i$ raised the price per ticket $i$ by $1$; in turn, this "additional tax" will be added to our total cost every time a ticket is bought on day $i$. Parsing in a different way, every pair of ticket where one is bought before day $i$ and one is bought on day $i$ adds $1$ additional tax to the total cost, so the final additional tax is exactly "the number of pair of tickets that were bought on different days".

We now try to find a way to optimize both the base cost and the total additional tax. Observe that the same greedy strategy of "take as many cheap tickets as possible" works for both of them (obviously works for the first quantity, and for the second quantity it works because we're limiting the number of pair of tickets bought on different days). Implementing this gives an $O(n \log n)$ solution.

— — —

Formally, suppose we buy $b_1, b_2, \ldots, b_n$ tickets on day $1, 2, \ldots, n$, respectively, then $0 \leq b_i \leq m$, $\sum_{i=1}^{n} b_i = k$ and the price per ticket on day $i$ will be $a_i + b_1 + b_2 + \ldots + b_{i-1} = a_i + \sum_{j=1}^{i-1} b_j$. Thus, the total cost will be:

$\sum_{i=1}^{n} (a_i + \sum_{j=1}^{i-1} b_j)b_i = \sum_{i=1}^{n} a_ib_i + \sum_{1 \leq j < i \leq n} b_ib_j$

Note that if we choose two days $i$, $j$ and swap $(a_i, b_i)$ with $(a_j, b_j)$, the above sum does not change its value. Therefore, we can freely rearrange the sequence $a$ without changing the answer. Let's sort the sequence $a$ in non-decreasing order. It is obvious that the first sum is minimized when we buy the $k$ cheapest tickets, i.e. $b = (m, m, \ldots, k \mod m, 0, 0, \ldots, 0)$. We will prove that the greedy strategy also minimizes the second sum, by noting that the second sum is equal to:

$\frac{1}{2} ((\sum_{i = 1}^{n}b_i)^{2} - \sum_{i = 1}^{n}{b_i^2}) = \frac{1}{2}k^2 - \frac{1}{2} \sum_{i = 1}^{n}{b_i^2}$

If there exists two days $i$, $j$ such that $0 < b_i \leq b_j < m$, then replacing $(b_i, b_j)$ with $(b_i - 1, b_j + 1)$ gives a smaller cost. Hence, the sequence $b = (m, m, \ldots, k \mod m, 0, 0, \ldots, 0)$ minimizes the overall cost.

[255371666](https://codeforces.com/contest/1951/submission/255371666 "Submission 255371666 by Kuroni")

 **Rate this problem**Yay 

 
[*402*](https://codeforces.com/data/like?action=like "I like this")




 Meh 

 
[*55*](https://codeforces.com/data/like?action=like "I like this")




 Nay 

 
[*74*](https://codeforces.com/data/like?action=like "I like this")




 Banger song 

 
[*50*](https://codeforces.com/data/like?action=like "I like this")



[1951D - Buying Jewels](../problems/D._Buying_Jewels.md "Codeforces Global Round 25")

Author: [MofK](https://codeforces.com/profile/MofK "Grandmaster MofK")   
 Prepared by [MofK](https://codeforces.com/profile/MofK "Grandmaster MofK")   
 First solve: [conqueror_of_tourist](https://codeforces.com/profile/conqueror_of_tourist "Legendary Grandmaster conqueror_of_tourist") at 00:14

 **Hint**Perhaps the easiest way of dealing with this problem is writing down small cases and see what happens.

 **Tutorial and Implementation**
### [1951D - Buying Jewels](../problems/D._Buying_Jewels.md "Codeforces Global Round 25")

We first assume that $p_i \leq n$ for $1 \leq i \leq s$, since adding stalls with price greater than $n$ doesn't change the result.

If $n < k$ then the answer is obviously "NO". If $n = k$ then the answer is obviously "YES" — we can set up a single stall of price $1$. 

Otherwise, the first stall should have price $p_1 \geq 2$. Let $n = p_1q + r$ such that $q$, $r$ are integers and $q \geq 1$, $0 \leq r < p_1$. Obviously Alice can buy at most $q + r$ jewels ($q$ from stall $1$, at most $r$ from other stalls). On the other hand:

$n - 2(q+r) = (p_1 - 2)q - r$

$\geq (p_1 - 2)q - p_1 + 1$ (since $r \leq p_1 - 1$)

$\geq (p_1 - 2) - p_1 + 1$ (since $q \geq 1, p_1 \geq 2$)

$= -1$

$\Rightarrow 2(q+r) \leq n + 1$

Thus, if $k < n$ and $2k > n + 1$, the answer is "NO". Otherwise, choosing $p_1 = n - k + 1$ and $p_2 = 1$ solves the problem (you also have the option to print $58$ random integers afterwards to test our checker!)

[255371688](https://codeforces.com/contest/1951/submission/255371688 "Submission 255371688 by Kuroni")

 **Comments from the authors**This problem was originally problem B. It turned out to be too hard and was switched to C, with [1951B - Battle Cows](../problems/B._Battle_Cows.md "Codeforces Global Round 25") inserted, before being further switched to D as it was still too hard.

 **Rate this problem**Yay 

 
[*171*](https://codeforces.com/data/like?action=like "I like this")




 Meh 

 
[*36*](https://codeforces.com/data/like?action=like "I like this")




 Nay 

 
[*328*](https://codeforces.com/data/like?action=like "I like this")




 Banger song 

 
[*30*](https://codeforces.com/data/like?action=like "I like this")



[1951E - No Palindromes](../problems/E._No_Palindromes.md "Codeforces Global Round 25")

Author: [MofK](https://codeforces.com/profile/MofK "Grandmaster MofK")   
 Prepared by [MofK](https://codeforces.com/profile/MofK "Grandmaster MofK")   
 First solve: [DottedCalculator](https://codeforces.com/profile/DottedCalculator "Specialist DottedCalculator") at 00:16

 **Hint**Let ii be the first character that is different from s1s1. Then s1..is1..i is not a palindrome. If si+1..nsi+1..n is also not a palindrome then we are done, but what can we do if it is?

 **Tutorial and Implementation**
### [1951E - No Palindromes](../problems/E._No_Palindromes.md "Codeforces Global Round 25")

If $s$ is not a palindrome then we are done. If $s$ consists of only one type of character then we're also done.

Consider the case when $s$ is a palindrome and there are at least $2$ distinct characters. Let $t$ be the first position where $s_t \neq s_1$, and note that this means $s_{[1, t]}$ is not a palindrome. If $s_{[t + 1, n]}$ isn't a palindrome then we're done.

Otherwise, we note that the string has the form $A\mathtt{b}A\mathtt{b} \dots A\mathtt{b}A$, where $A$ consists of $t-1$ $\mathtt{a}$ characters (from the assumptions that $s$ and $s_{[t + 1, n]}$ are palindromes). We do a case analysis on $t$, observing that $t$ is between $2$ and $\frac{n + 1}{2}$: 

* If $t = \frac{n + 1}{2}$, the string has the form $A\mathtt{b}A$, and we can verify that this is a "NO" case (proof: for every partition, either the substring containing $s_1$ or the substring containing $s_n$ has length at most $\frac{n - 1}{2}$, which means it consists of only character $\mathtt{a}$).
* If $t = 2$, the string has the form $\mathtt{abab\dots aba}$, and we can verify that this is another "NO" case (proof: every partition must have an odd-length substring, which is always a palindrome).
* Otherwise, $s_{[1, t + 1]} = A\mathtt{ba}$ starts with $t - 1$ $\mathtt{a}$ characters and ends with $1$ $\mathtt{a}$ character, and $s_{[t + 2, n]}$ starts with $t - 2$ $\mathtt{a}$ characters and ends with $t - 1$ $\mathtt{a}$ character. Therefore, both substrings are not palindromes, which means this is a valid partition.

Implementing this idea directly gives a time complexity of $O(n)$.

[255371747](https://codeforces.com/contest/1951/submission/255371747 "Submission 255371747 by Kuroni")

 **Comments from the authors**It is rather unfortunate that the solution only uses partitions of at most size 22, therefore one can "solve" the problem by brute forcing every possible partition and check validity using any string matching algorithm. Nevertheless, we tried our hardest to make sure dumber "solutions" won't pass.

 **Rate this problem**Yay 

 
[*108*](https://codeforces.com/data/like?action=like "I like this")




 Meh 

 
[*38*](https://codeforces.com/data/like?action=like "I like this")




 Nay 

 
[*187*](https://codeforces.com/data/like?action=like "I like this")




 Banger song 

 
[*26*](https://codeforces.com/data/like?action=like "I like this")



[1951F - Inversion Composition](../problems/F._Inversion_Composition.md "Codeforces Global Round 25")

Author: [Kuroni](https://codeforces.com/profile/Kuroni "International Grandmaster Kuroni")   
 Prepared by [Kuroni](https://codeforces.com/profile/Kuroni "International Grandmaster Kuroni")   
 First solve: [CeItic](https://codeforces.com/profile/CeItic "Pupil CeItic") at 00:42

 **Hint 1**Let's look at the "inverseness" of (pi,pj)(pi,pj) on qq and (i,j)(i,j) on q⋅pq⋅p. What is their relation to the inverseness of (i,j)(i,j) on pp?

 **Hint 2**They either contribute 00 or 22 if (i,j)(i,j) is not an inverse on pp, or 11 if (i,j)(i,j) is an inverse on pp. We now know the necessary condition for kk if there is an answer. This is also sufficient.

 **Tutorial and Implementation**
### [1951F - Inversion Composition](../problems/F._Inversion_Composition.md "Codeforces Global Round 25")

We say that $(i, j)$ is an inverse on permutation $p$ if $i < j$ and $p_i > p_j$, or $i > j$ and $p_i < p_j$.

For any two integers $1 \le i < j \le n$, let's observe the "inverseness" of $(p_i, p_j)$ on $q$ and $(i, j)$ on $q \cdot p$: 

* If $(i, j)$ is not an inverse on $p$, then the inverseness of $(p_i, p_j)$ on $q$ and $(i, j)$ on $q \cdot p$ is the same. Therefore, this pair contributes either $0$ or $2$ to $\operatorname{inv}(q) + \operatorname{inv}(q \cdot p)$.
* Otherwise, the inverseness of $(p_i, p_j)$ on $q$ and $(i, j)$ on $q \cdot p$ is different. Therefore, this pair always contribute $1$ to $\operatorname{inv}(q) + \operatorname{inv}(q \cdot p)$.

Therefore, the answer is "NO" if $k \notin [\operatorname{inv}(p), n(n - 1) - \operatorname{inv}(p)]$, or if $k$ has different parity from $\operatorname{inv}(p)$. Otherwise, we claim that we can always construct $q$; the following implementation actually constructs $q \cdot p$, but we can easily find one permutation from the other.

Let $k' = \frac{k - \operatorname{inv}(p)}{2}$, then the problem becomes "find $q \cdot p$ with $k'$ special inversions", where an inverse $(i, j)$ on $q \cdot p$ is special if $(i, j)$ is not an inverse on $p$. Let $x_i$ be the number of indices $j < i$ where $p_j < p_i$, which can be easily found via a standard Fenwick tree (note that $\sum_{i=1}^n x_i = \frac{n(n-1)}{2} - \operatorname{inv}(p)$). Then there exists an index $t$ such that $\sum_{i < t} x_i \le k'$, and $\sum_{i \le t} x_i \ge k'$. It's straightforward to see that the permutation $q \cdot p = [t, t - 1, \dots, v + 1, v - 1, v - 2, \dots, 1, v, t + 1, t + 2, \dots, n]$ works for some value $v \in [1, t]$, chosen such that there are exactly $k' - \sum_{i < t} x_i$ indices before $t$ that forms a special inversion with $t$.

Time complexity: $O(n \log n)$.

[255371767](https://codeforces.com/contest/1951/submission/255371767 "Submission 255371767 by Kuroni")

 **Rate this problem**Yay 

 
[*90*](https://codeforces.com/data/like?action=like "I like this")




 Meh 

 
[*9*](https://codeforces.com/data/like?action=like "I like this")




 Nay 

 
[*6*](https://codeforces.com/data/like?action=like "I like this")




 Banger song 

 
[*22*](https://codeforces.com/data/like?action=like "I like this")



[1951G - Clacking Balls](../problems/G._Clacking_Balls.md "Codeforces Global Round 25")

Author: [MofK](https://codeforces.com/profile/MofK "Grandmaster MofK")   
 Prepared by [Kuroni](https://codeforces.com/profile/Kuroni "International Grandmaster Kuroni")   
 First solve: [Little09_love_YCY](https://codeforces.com/profile/Little09_love_YCY "Master Little09_love_YCY") at 00:19

 **Hint 1**We should represent a state as the sequence of distances between each pair of consecutive balls.

 **Hint 2**[This should probably help.](https://codeforces.com/blog/entry/77284#comment-620956)

 **Tutorial and Implementation**
### [1951G - Clacking Balls](../problems/G._Clacking_Balls.md "Codeforces Global Round 25")

Note: there are other (more elegant in our opinion) solutions from some of our testers, which you may or may not find under the comment section. We will present here the original solution here.

Consider a state with $k \leq n$ balls remaining. Let's represent the state as a sequence $S = (d_1, d_2, \cdots, d_k)$ where $d_i$ is the distance between ball $i$ and ball $(i \bmod{k}) + 1$. Note that $\sum_{i=1}^{k} d_i = m$. Then, after a second, one of the following happens:

* $d_i$ is increased by $1$ and $d_{(i \bmod{k}) + 1}$ is decreased by $1$ with probability $\frac{1}{n}$ for each $1 \leq i \leq k$ (if $d_{(i \bmod{k}) + 1} = 0$, we erase it from the sequence). We denote the new sequence as $S + \{i\}$.
* Nothing changes with probability $1 - \frac{k}{n}$.

The terminal state is $(m)$. Therefore, let $f(S)$ be the expected number of seconds to reach the terminal state from state $S = (d_1, d_2, \cdots, d_k)$, then:

* $f((m)) = 0$ (*)
* $f(S) = 1 + \frac{1}{n} \sum_{i=1}^{k} f(S + \{i\}) + (1 - \frac{k}{n}) f(S)$ $\Rightarrow$ $k f(S) = n + \sum_{i=1}^{k} f(S + \{i\})$ (**)

Let $h(S, i) = f(S) - f(S + \{i\})$, condition (**) becomes $\sum_{i=1}^{k} h(S, i) = n$.

To proceed, we will apply [the idea from this comment](https://codeforces.com/blog/entry/77284#comment-620956). If we choose $f(S) = c + \sum_{i=1}^{k} \sum_{x=0}^{d_i} g(x)$ for some constant $c$ and function $g: \mathbb{Z_{\geq 0}} \rightarrow \mathbb{R}$, then:

 $n = \sum_{i=1}^{k} h(S, i)$

 $= \sum_{i=1}^{k} g(d_{(i \bmod{k}) + 1}) - g(d_i + 1)$

 $= \sum_{i=1}^{k} g(d_i) - g(d_i + 1)$

Additionally, since we want $h(S, i) = g(d_{(i \bmod{k}) + 1}) - g(d_i + 1)$ to hold even when $d_{(i \bmod{k}) + 1} = 0$, we need to choose $g$ such that $g(0) = 0$.

Let's choose $g$ such that $g(0) = 0$ and $g(x + 1) - g(x) = -\frac{n}{m}x$ for all $x \geq 0$. Then $\sum_{i=1}^{k} g(d_i) - g(d_i + 1) = \frac{n}{m} \sum_{i=1}^{k} d_i = n$, thus satisfies (**). 

Solving for $g$ gives $g(x) = -\frac{n}{m}\frac{x(x-1)}{2} = -\frac{n}{m} \binom{x}{2}$. 

Finally, $f(S) = c - \frac{n}{m} \sum_{i=1}^{k} \binom{d_i + 1}{3}$.

In order to satisfy (*), we need to choose $c = \frac{n}{m} \binom{m + 1}{3}$.

[255371802](https://codeforces.com/contest/1951/submission/255371802 "Submission 255371802 by Kuroni")

 **Rate this problem**Yay 

 
[*28*](https://codeforces.com/data/like?action=like "I like this")




 Meh 

 
[*1*](https://codeforces.com/data/like?action=like "I like this")




 Nay 

 
[*6*](https://codeforces.com/data/like?action=like "I like this")




 Banger song 

 
[*13*](https://codeforces.com/data/like?action=like "I like this")



[1951H - Thanos Snap](../problems/H._Thanos_Snap.md "Codeforces Global Round 25")

Author: [Kuroni](https://codeforces.com/profile/Kuroni "International Grandmaster Kuroni")   
 Prepared by [Kuroni](https://codeforces.com/profile/Kuroni "International Grandmaster Kuroni")   
 First solve: [ecnerwala](https://codeforces.com/profile/ecnerwala "Legendary Grandmaster ecnerwala") at 01:34

 **Hint 1**Let's binary search the answer. Every element is now either 00 or 11, and Alice tries to get 11.

 **Hint 2**Let's directly construct the strategy for Alice. It can be viewed as a perfect binary game tree.

 **Hint 3**Construct the strategy greedily bottom-up.

 **Tutorial and Implementation**
### [1951H - Thanos Snap](../problems/H._Thanos_Snap.md "Codeforces Global Round 25")

Let $n = 2^k$. Let's see how we can solve for each $t$ first. We binary search on the answer, which results in every element being either $0$ or $1$ depending on if it's larger than the threshold, and we now need to check if the answer is $0$ or $1$.

Let's instead try to directly construct Alice's strategy to achieve $1$; if we cannot construct such a strategy, the answer is $0$. The main idea here is that Alice's strategy can be represented as a perfect binary tree with $t + 1$ layers, where: 

* Every leaf node represents a subarray of $a$ of size $2^{n - t}$.
* Every non-leaf node represents Alice's next action when the game is restricted to the subarray $[l, r]$ covered by this node; such an action is in the form "swap $a_i$ and $a_j$", where $l \le i \le j \le r$.

Some trivial observations: 

* For Alice to win, we would want every leaf node to have at least one value $1$ when the game reaches that leaf node. We say a leaf is deficient if it originally did not satisfy this condition.
* Every leaf node that has more than one value $1$ can "donate" the extra $1$'s via the swapping action.
* If an action can be performed by Alice in a node, it can also be performed in any of its ancestors.

The third observation motivates us to look for a greedy bottom-up construction of Alice's strategy. Combining with the first two observations, we get the following greedy construction: 

* For every node, maintain the number of deficient leaves and the number of extra $1$'s that can be donated from other leaves. At any non-leaf node, we try to match an extra $1$ with a deficient leaf (if both quantities are more than $0$), and we propagate the remaining deficient leaves and extra $1$'s to the node's parent.
* Alice wins if at the root node, the number of deficient leaves remaining is $0$.

This strategy can be implemented in time $O((n + 2^t) \log n)$ or $O(n + 2^t \log n)$ depending on implementation (to get the second complexity, note that while binary searching, the total number of element status changes between $0$ and $1$ is $O(n)$). This gives us a complexity of $O(n \log^2 n)$ or $O(n \log n)$ after looping through all $t$.

[255374619](https://codeforces.com/contest/1951/submission/255374619 "Submission 255374619 by Kuroni")

 **Rate this problem**Yay 

 
[*27*](https://codeforces.com/data/like?action=like "I like this")




 Meh 

 
[*4*](https://codeforces.com/data/like?action=like "I like this")




 Nay 

 
[*0*](https://codeforces.com/data/like?action=like "I like this")




 Banger song 

 
[*7*](https://codeforces.com/data/like?action=like "I like this")



[1951I - Growing Trees](../problems/I._Growing_Trees.md "Codeforces Global Round 25")

Author: [Kuroni](https://codeforces.com/profile/Kuroni "International Grandmaster Kuroni")   
 Prepared by [Kuroni](https://codeforces.com/profile/Kuroni "International Grandmaster Kuroni")   
 First solve: [rainboy](https://codeforces.com/profile/rainboy "Master rainboy") at 02:27

 **Hint 1**[This helps to check if xx satisfies](https://codeforces.com/https://en.wikipedia.org/wiki/Nash-Williams_theorem). Pattern match it to [Hall's marriage theorem](https://codeforces.com/https://en.wikipedia.org/wiki/Hall%27s_marriage_theorem).

 **Hint 2**It is possible to check if xx satisfies with nn flow runs, each flow graph having O(n+m)O(n+m) nodes and edges.

 **Hint 3**Spanning trees are independent sets of the graphic matroid. [Direct sums of kk such matroids is also a matroid.](https://codeforces.com/https://en.wikipedia.org/wiki/Matroid#:~:text=.%5B20%5D-,Sums%20and%20unions,-%5Bedit%5D).

 **Hint 4**We can greedily select to increase xixi with the least increment cost that still satisfies. Quickly simulate this via a binary search.

 **Tutorial and Implementation**
### [1951I - Growing Trees](../problems/I._Growing_Trees.md "Codeforces Global Round 25")

From now on, we say an array $x$ to be good if the graph created by cloning the $i$-th edge $x_i$ times can be partitioned into $k$ forests (this is slightly different from $k$-spanning-tree generators).

Let's first discuss how to check whether an array $x$ is good. Let $G'$ be the graph created by cloning the $i$-th edge $x_i$ times. By [Nash-Williams theorem](https://codeforces.com/https://en.wikipedia.org/wiki/Nash-Williams_theorem), for every subset of vertices $U$, we need the induced subgraph $G'[U]$ to have at most $k(|U| - 1)$ edges, so it suffices to check this condition quickly. Furthermore, this condition can easily be modified to $k$-spanning-tree generators: the only additional condition necessary is to have $\sum_{i=1}^m x_i = k(n - 1)$.

Consider the unweighted bipartite graph $B_{G'}$ where every left node represents a node $u$ of $G'$, every right node represents an edge $(u, v)$ of $G'$, and we connect edges $u - (u, v)$ and $v - (u, v)$ for every right node $(u, v)$, then Hall's marriage theorem states that $B_{G'}$ has a right-saturating matching iff the induced subgraph $G'[U]$ has at most $|U|$ edges for all $U$. We can further extend this idea by making $k$ clones of every left node $u$, which now means that the $B_{G'}$ has a right-saturating matching iff $|G'[U]| \le k |U|$ for all $U$. The big last idea is to try "turning off" a left node $u$: formally, consider $B_{G', u}$ be the same as $B_{G'}$, but all clones of some left node $u$ are deleted, and note that this graph enforces the condition $|G'[U']| \le k(|U'| - 1)$ for every subset $U'$ containing $u$. Therefore, by checking if $B_{G', u}$ has a right-saturating matching matching for all $u$, we can now ensure the Nash-Williams condition. Finally, note that we can quickly check if $B_{G', u}$ has a right-saturating matching by constructing the following directed graph: direct an edge from the source node to every left node $v \neq u$ with capacity $k$, direct an edge from every right node $(u_i, v_i)$ to the sink node with capacity $x_i$, and direct an edge from left node $u_i$ (or $v_i$) to right node $(u_i, v_i)$ with capacity $\infty$; $B_{G', u}$ has a perfect matching iff this new graph has a flow from source to sink that saturates all incoming edges to sink. As the constructed flow graph has $O(n + m)$ nodes and edges, we now know how to check if an array $x$ is good in time complexity $O(n \cdot F(n + m, n + m))$, where $F(N, M)$ is the complexity to run max flow on a graph with $N$ nodes and $M$ edges.

We now return to the original problem. Observe that the cost function is convex on every coordinate $x_i$; hence, one could imagine the following greedy strategy: starts with $x = 0$; until the sum of $x_i$ reaches $k(n - 1)$, try to find a coordinate $i$ and increases $x_i$ by $1$ such that 

* increasing $x_i$ by $1$ doesn't make $x$ bad, and
* increasing $x_i$ by $1$ increases the cost by as little as possible.

It turns out that this strategy works, as the set of all good arrays forms a "matroid", and $k$-spanning-tree generators are the "bases" of this "matroid" (note that the greedy algorithm guarantees to find the min-weight basis of a matroid). To be more formal, consider a set of elements $E$, where each element denoted by a pair $(i, t)$ represents the clone of the edge $i$ with cost $(a_i t^2 + b_i t) - (a_i (t-1)^2 + b_i(t - 1))$, and a subset $E' \subseteq E$ is independent if the multiset edges represented by elements in $E'$ can be partitioned into $k$ forests (here, we let $i \in [1, n]$ and $t \in [1, k]$). Observe that this set $E$ forms a matroid (we can think of $E$ as a "permuted" direct sum of $k$ disjoint versions of the graphic matroids on $G$, and note that direct sums of matroids are themselves matroid). Furthermore, the weight of element $(i, t)$ represents exactly the increment to the cost when we increase $x_i$ from $t - 1$ to $t$. By convexity of the cost on each edge, the weight of $(i, t)$ is less than the weight of $(i, t + 1)$. Hence the min-cost $k$-spanning-tree generator represents exactly the min-weight basis of $E$, as the basis would greedily use $(i, j)$ with $j$ being as small as possible.

Finally, while this greedy algorithm is correct, we still need to optimize it as the number of steps is $k(n - 1)$. Observe that if at some step, increasing a coordinate $i$ makes $x$ bad, we would never consider coordinate $i$ again at later steps of the algorithm. Therefore, we can effectively simulate the greedy algorithm by 1) finding the first step where a coordinate $i$ turns bad, 2) advancing until such step, 3) discarding coordinate $i$ from consideration, and 4) repeating until every coordinate turns bad. Fortunately, step 1) can be quickly implemented by binary searching on the cost of the increment, and the number of iterations is $m$ as every coordinate can only be discarded once. Therefore, the problem has been solved in time complexity of either $O(m \cdot (\log W + m) \cdot n \cdot F(n + m, n + m))$, $O(m \cdot \log mW \cdot n \cdot F(n + m, n + m))$, or $O(m \cdot \log W \cdot n \cdot F(n + m, n + m) + m^2 n^2)$ depending on how you break ties on the same cost increment (note that we can ensure no ties by adding $\epsilon i$ to $x_i$), where $W \le 2 k \cdot \max a + \max b$ is the maximum cost increment.

[255371862](https://codeforces.com/contest/1951/submission/255371862 "Submission 255371862 by Kuroni")

 **Rate this problem**Yay 

 
[*16*](https://codeforces.com/data/like?action=like "I like this")




 Meh 

 
[*1*](https://codeforces.com/data/like?action=like "I like this")




 Nay 

 
[*5*](https://codeforces.com/data/like?action=like "I like this")




 Banger song 

 
[*14*](https://codeforces.com/data/like?action=like "I like this")



**UPD**: Added implementations.

