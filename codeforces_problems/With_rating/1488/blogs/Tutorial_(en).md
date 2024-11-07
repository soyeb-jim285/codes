# Tutorial_(en)

First of all, I would like to thank all testers of the round: [Um_nik](https://codeforces.com/profile/Um_nik "Legendary Grandmaster Um_nik"), [IlyaLos](https://codeforces.com/profile/IlyaLos "International Master IlyaLos"), [Roms](https://codeforces.com/profile/Roms "Master Roms"), [nuipojaluista](https://codeforces.com/profile/nuipojaluista "Expert nuipojaluista"), [Supermagzzz](https://codeforces.com/profile/Supermagzzz "Master Supermagzzz"), [Stepavly](https://codeforces.com/profile/Stepavly "Master Stepavly"), [hg333](https://codeforces.com/profile/hg333 "Master hg333"). Also huge thanks to co-authors of the contest: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon"), [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic"), [vovuh](https://codeforces.com/profile/vovuh "Master vovuh") and [awoo](https://codeforces.com/profile/awoo "Grandmaster awoo").

I hope you enjoyed participating in the round!

Okay, now for the editorial itself:

[1488A - From Zero To Y](../problems/A._From_Zero_To_Y.md "Kotlin Heroes: Episode 6")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1488A - From Zero To Y](../problems/A._From_Zero_To_Y.md "Kotlin Heroes: Episode 6")

We can represent $y$ as $ax+b$ for some non-negative $a$ and $b$. Such a representation requires $f(a)$ (where $f(x)$ — the sum of the digits in $x$) operations of the first type and $b$ operations of the second type. Using that formula, we can see that it's never optimal to take $b$ greater or equal to $x$, so $a = \left\lfloor \frac{y}{x} \right\rfloor$ and $b = y \bmod x$.

[1488B - RBS Deletion](../problems/B._RBS_Deletion.md "Kotlin Heroes: Episode 6")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1488B - RBS Deletion](../problems/B._RBS_Deletion.md "Kotlin Heroes: Episode 6")

It's quite easy to see that the answer cannot exceed $\frac{n}{2}$ (each action removes at least two characters).

Let's build the balance array for our string $s$ ($bal_i$ is the difference between the count of opening and closing brackets among the first $i$ characters). The first operation allows us to remove some prefix with $bal_i = 0$, so if we were allowed to use only the operations of the first type, the answer would be equal to the number of non-empty prefixes with $bal_i = 0$ (let's call it $c$).

If we want to apply a second operation, let's find a way to do it so the number of prefixes with $bal_i = 0$ doesn't decrease. We can always pair of neighbouring brackets (), and removing it still makes $s$ an RBS. So, let's remove some pair of neighbouring brackets that doesn't decrease the number of $bal_i = 0$, until the string becomes ()()()()..., where each first operation can remove just $2$ characters, or until we run out of operations of type $2$.

So, the answer to our problem can be calculated as $\min(\frac{n}{2}, k + c)$.

[1488C - Two Policemen](../problems/C._Two_Policemen.md "Kotlin Heroes: Episode 6")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh"), preparation: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh")

 **Tutorial**
### [1488C - Two Policemen](../problems/C._Two_Policemen.md "Kotlin Heroes: Episode 6")

The only thing required to solve the problem is to notice that paths of two policemen in the optimal answer can be non-intersecting.

Using this, we can iterate over the length of the prefix the leftmost policeman will visit (let it be $i \in [x; y)$) and calculate the minimum total time to visit all cells in this prefix: $i - 1 + min(x - 1, i - x)$ (at least $i-1$ step is required to visit all $i$ cells and the additional $min(x - 1, i - x)$ steps are required to get to the border of our prefix).

Using similar formulas, we can calculate the time for the rightmost policeman and the corresponding suffix. And then just update the answer as a maximum of these two values.

Time complexity: $O(n)$.

[1488D - Problemsolving Marathon](../problems/D._Problemsolving_Marathon.md "Kotlin Heroes: Episode 6")

Idea: [vovuh](https://codeforces.com/profile/vovuh "Master vovuh"), preparation: [awoo](https://codeforces.com/profile/awoo "Grandmaster awoo")

 **Tutorial**Consider the minimum possible answer. Since you have to do all s problems in n days, you can do ⌊sn⌋ in some of them and then ⌈sn⌉ in the rest of the days. Thus, ⌈sn⌉ is the minimum possible an.

Now it would be great if the function that tells if some x can be the number of problems during the last day was monotonous for all x from ⌈sn⌉ to ∞. So that function first returns true for some prefix of values, then it returns false. Intuitively, it sounds monotonous: the smaller values allow a lot of freedom for the construction and the larger values fail because they require too many problems in total.

The difficulty rises from the fact we not only have to prove that, but we also have to find a way to ask the result of that function quickly.

If we didn't have to, the proof would not be too hard.

 **Proof**Consider some distribution of s problems such that the last element is x>⌈sn⌉. Let's move some problems around to make the last element x−1. So there is a block of days with x problems at the end. There also is a block of days with the number of problems equal to the first day. You can always move the problem from the first day of the ending block to the last day of the beginning block. 

Let's call the first day of the ending block r and the last day of the beginning block l. Observe that the condition between r−1 and r never breaks. Since the difference between ar−1 and ar decreased, if it was two-fold or less then it's still two-fold or less. Same for l and l+1. In the case of l=r−1, the difference between al and ar must have been at least 2, thus, al≤ar after the move. The difference can't be 1 because then it is exactly the same construction we have built for the minimum case, thus x=⌈sn⌉. The condition between r and r+1 also can't break. If r is the last day, then there is no r+1. Otherwise, ar becomes equal to ar+1−1. Since all the values are positive, that difference can't become above two-fold. Same reasoning goes for l and l−1. 

So that move is always valid. That move also decreases the size of the ending block by 1. Thus, at some point the ending block will be of size 1, so making a move from it will decrease the last value by 1. That proves that for any x that can be the last value, x−1 can also be the last value. Thus, the function is indeed monotonous.

Now that we are absolutely sure that the function is monotonous, let's change our approach.

Obviously, we should try binary search on x. So we have the total number of problems s, the number of days n and some fixed number of problems during the last day x.

Our second educated guess can be of the following kind. Given fixed n and x, all the possible values of s that can correspond to some construction are some segment of integers. That can actually be proven in the similar manner.

 **Proof**Consider the smallest value of s that can be obtained: the last day has x problems, the second to last has ⌈x2⌉ and so on.

In any construction there is a block of days with the number of problems equal to the first day. You can always add a problem to the last day of that block, thus increasing the total number of problems by 1. The casework is basically the same as in the first proof.

That construction also implies that the smallest value of s grows as x grows.

So we can binary search for a solution for x from ⌈sn⌉ to s. f(x) can be the smallest total number of problems such that there exists a distribution. Since that value is monotonous, you can look for the largest x such that f(x)≤s.

To calculate the function you can observe that the sequence x, ⌈x2⌉, ⌈⌈x2⌉2⌉, … has only ones after log(x) values.

Overall complexity: O(log2s) per testcase.

[1488E - Palindromic Doubles](../problems/E._Palindromic_Doubles.md "Kotlin Heroes: Episode 6")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [awoo](https://codeforces.com/profile/awoo "Grandmaster awoo")

 **Tutorial**Tutorial is loading...[1488F - Dogecoin](../problems/F._Dogecoin.md "Kotlin Heroes: Episode 6")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest") and [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon"), preparation: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1488F - Dogecoin](../problems/F._Dogecoin.md "Kotlin Heroes: Episode 6")

First, let's solve a problem for a single query. Let's say we sold Dogecoins on days $d_1, d_2, \dots, d_k$, and $d_{i} < d_{i + 1}$. Since all the Dogecoins that we can sell on day $d_i$, we can sell on $d_{i + 1}$ day as well, so if $a_{d_{i}} \le a_{d_{i + 1}}$, then we could not sell Dogecoin on day $d_i$, but sell on day $d_{i + 1}$ and the answer would not decrease. So the values of $a_{d_i}$ should decrease.

Let's maintain a stack in which we will store the days in which we sold Dogecoin. Let the number of the current day be $i$, and the number of the day when we last sold Dogecoin is $j$ (the last value in the stack). If $a_j \le a_i$, then we should remove $j$ from the stack and recalculate the current answer. Note that a single value of $i$ can remove multiple values from the stack. After that, we have to add $(i-j) \cdot a_i$ to the current answer, because we sell all the Dogecoin that accumulated from the last sale.

Now, to quickly answer the ($l, r$) query, note that if we build a stack for the first $r$ days, then all the numbers from the stack that belong to the $[l, r]$ segment will be the optimal set of days to sell Dogecoin on. To get the answer for this set of days, we can maintain the prefix sums array of the array where the values are equal to each day's contribution to the answer (the number of accumulated Dogecoins multiplied by their price on that day).

[1488G - Painting Numbers](../problems/G._Painting_Numbers.md "Kotlin Heroes: Episode 6")

Idea: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon"), preparation: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon")

 **Tutorial**
### [1488G - Painting Numbers](../problems/G._Painting_Numbers.md "Kotlin Heroes: Episode 6")

Note that if some $x$ is red and its multiplier $y$ (i. e., $y = kx$ for some integer $k > 1$) is blue, then we can swap their colors and the answer will not decrease, since all numbers that were divisible by $y$ will be divisible by $x$, and all numbers that were divisors of $x$ will be divisors of $y$. This means that $x$ can only turn red if all its multipliers are already red. So we can estimate in advance the value that $x$ will add to the answer if it is repainted from blue to red. This value is $f(x) - g(x)$, where $f(x)$ is the number of divisors of $x$, and $g(x)$ is the number of multipliers of $x$ not exceeding $n$. Therefore, it is enough to sort all the numbers by the value $f(x) - g(x)$ and take $k$ best ones.

[1488H - Build From Suffixes](../problems/H._Build_From_Suffixes.md "Kotlin Heroes: Episode 6")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [awoo](https://codeforces.com/profile/awoo "Grandmaster awoo")

 **Tutorial**
### [1488H - Build From Suffixes](../problems/H._Build_From_Suffixes.md "Kotlin Heroes: Episode 6")

Let's simplify the problem and at least solve it without the updates. 

Take a look at some string $s$ of length $n$. What does the comparison of some suffixes $i$ and $i+1$ actually imply? If $s_i \neq s_{i+1}$, then you can immediately say the result of the comparison. Otherwise, you can remove the first letter from both these suffixes and the result of comparison doesn't change. However, both suffixes with the first letter removed are actually suffixes $i+1$ and $i+2$. Thus, the result of comparison should be the same.

You can also append $a$ with $0$ to get rid of corner cases. The last suffix is always greater than the empty one.

Now the first thing that comes to mind is some dynamic programming that builds the string from the end and keeps track of the last letter. So let $dp[i][c]$ be the number of strings such that the $i$-th suffix is set, all the conditions from the $i$-th to the $n$-th are satisfied and the last (the $i$-th) letter is $c$. We can iterate on the value of the $(i-1)$-th letter and put it according to the value of $a_{i-1}$ and $a_i$. So far, we have to iterate on both the current and the previous letter to make a transition. However, you can notice that each transition sums up the values of dp from all letters either greater than the current one or smaller than the current one. With some small prefix sum magic we can do that dp in $O(nk)$.

Point updates tell us that the problem can include some data structure. For example, let's try to put that dp inside the segment tree. What information do we have to maintain in dp to be able to merge two segments together? Similar to the case without the updates, we don't really care about the full insides of the string. However, since we can merge from both left and right now, we should store the leftmost and the rightmost letters. Each node can store $dp[c_l][c_r]$ — the number of valid strings on the corresponding segment such that their leftmost letter is $c_l$ and their rightmost letter is $c_r$.

To merge two segments we can iterate over the rightmost letter of the left segment and the leftmost letter of the right segment and multiply the values of their dp if the conditions of $a$ hold. We also have to iterate on the leftmost letter of the left segment and the rightmost letter of the right segment, thus, the merge works in $4^4$ so far. Similar to the $O(nk)$ solution, you can use prefix sums to get rid of one multiplier of $4$.

Overall complexity: $O((n + q) \cdot \log n \cdot |A|^3)$, where $|A|=4$.

[1488I - Demonic Invasion](../problems/I._Demonic_Invasion.md "Kotlin Heroes: Episode 6")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**Tutorial is loading...[1488J - Flower Shop](../problems/J._Flower_Shop.md "Kotlin Heroes: Episode 6")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest"), preparation: [Neon](https://codeforces.com/profile/Neon "Candidate Master Neon") and [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

 **Tutorial**
### [1488J - Flower Shop](../problems/J._Flower_Shop.md "Kotlin Heroes: Episode 6")

This task is a some variation of knapsack problem, so the solution is either based on dp with weight in the state or it uses multiplication of polynomials. The second variant is our choice.

Suppose, there are $cur_i$ flowers of type $i$ at this moment. Let's make for each flower type a polynomial $P_i = c_0 + c_1 x + c_2 x^2 + \dots + c_{(\mathit{MX} - 1)} x^{(\mathit{MX} - 1)}$ where $\mathit{MX} = 2^{13}$ and $c_j$ is $1$ if $j \bmod w_i = 0$ and $j \le cur_i \cdot w_i$ and $0$ otherwise.

Now, if we calculate the product of polynomials $P_l \cdot P_{l + 1} \cdot \ldots \cdot P_r$ we'll get the polynomial such that $c_j$ is exactly the number of different bouquets with cost $j$ we can make using flowers of types from $l$ to $r$.

Note that the degree of polynomial product is less than $\mathit{MX}$. So we can, for example, write divide-and-conquer with integer FFT (NTT) (since module is equal to $998\,244\,353$) but it has complexity $O(\mathit{MX} \cdot \log{\mathit{MX}} \cdot \log{n})$ and, most likely, doesn't pass.

But since all products have degree less than $\mathit{MX}$, we can keep all polynomials as polynomials of degree $\mathit{MX} - 1$ and in transformed form (using FFT). Then, to restore the answer, we need to get products of each coefficient $c_i$ independently and after that transform it back.

Note that to get products of each coefficient $c_i$ on segment $[l, r]$ we can use $\mathit{MX}$ Segment Trees and get all products in $O(\mathit{MX} \log{n})$. So, the complexity of query of the third type is $O(\mathit{MX} (\log{n} + \log{\mathit{MX}}))$.

Processing queries of the first and the second types is straightforward: we can manually calculate new polynomial $P_i$, transform it and update all Segment Trees also in $O(\mathit{MX} (\log{n} + \log{\mathit{MX}}))$ time.

The total complexity is $O(m \cdot \mathit{MX} \cdot (\log{n} + \log{\mathit{MX}}))$.

