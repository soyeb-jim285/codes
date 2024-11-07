# Tutorial_(en)

**UPD**: Solutions are added.

[1480A - Yet Another String Game](https://codeforces.com/contest/1480/problem/A "Codeforces Round 700 (Div. 2)")

 **Tutorial**
### [1480A - Yet Another String Game](https://codeforces.com/contest/1480/problem/A "Codeforces Round 700 (Div. 2)")

After some observations, we can see that the players should always choose the most significant letter to change, because it coordinates the lexicographical order of the final string most. Therefore, Alice will choose all odd indices while Bob will choose all even indices, and then Alice will change all letters she choose to the smallest possible letters while Bob will change all letters he choose to the largest possible letters. That is, Alice will change letters to "a" if the original letter is not "a" and to "b" otherwise; Bob will change letters to "z" if the original letter is not "z" and to "y" otherwise.

The time complexity is $O(n)$.

 **Solution**[106873602](https://codeforces.com/contest/1480/submission/106873602 "Submission 106873602 by liouzhou_101")

[1480B - The Great Hero](https://codeforces.com/contest/1480/problem/B "Codeforces Round 700 (Div. 2)")

 **Tutorial**
### [1480B - The Great Hero](https://codeforces.com/contest/1480/problem/B "Codeforces Round 700 (Div. 2)")

The hero needs $\lceil b_i/A \rceil$ attacks to kill the $i$-th monster, and he will obtain $\lceil b_i/A \rceil a_i$ damage after that.

Suppose the $k$-th monster is the last monster killed by the hero. Then the health value of the hero before the last attack is $$ h_k = B - \sum_{i=1}^n \left\lceil \frac {b_i} {A} \right\rceil a_i + a_k. $$ All monsters can be killed if and only if $\max_k\{h_k\} > 0$. This can be checked in $O(n)$ time.

 **Solution**[106873633](https://codeforces.com/contest/1480/submission/106873633 "Submission 106873633 by liouzhou_101")

[1479A - Searching Local Minimum](../problems/A._Searching_Local_Minimum.md "Codeforces Round 700 (Div. 1)")

 **Tutorial**
### [1479A - Searching Local Minimum](../problems/A._Searching_Local_Minimum.md "Codeforces Round 700 (Div. 1)")

We maintain by binary search a range $[l, r]$ which has a local minimum. Moreover, we assume that $a_{l-1} > a_l$ and $a_r < a_{r+1}$. Initially, $[l, r] = [1, n]$.

In each iteration, let $m$ be the midpoint of $l$ and $r$. 

Case 1. If $a_m < a_{m+1}$, then the range becomes $[l, m]$.

Case 2. If $a_m > a_{m+1}$, then the range becomes $[m+1, r]$.

When $l = r$, we have found a local minimum $a_l$.

The number of queries to $a_i$ is at most $2 \lceil \log_2 n \rceil \leq 34 < 100$. 

 **Solution**[106873682](https://codeforces.com/contest/1479/submission/106873682 "Submission 106873682 by liouzhou_101")

[1479B1 - Painting the Array I](../problems/B1._Painting_the_Array_I.md "Codeforces Round 700 (Div. 1)")

 **Tutorial**
### [1479B1 - Painting the Array I](../problems/B1._Painting_the_Array_I.md "Codeforces Round 700 (Div. 1)")

Formally, for every sequence $a_1, a_2, \dots, a_n$, and we assume that $a_1, a_2, \dots, a_n$ are positive integers, the number of segments in $a$ is defined to be $$ \mathit{seg}(a) = \sum_{i=1}^n [ a_{i-1} \neq a_{i} ], $$ where $a_0 = 0$, and $[\text{Boolean expression}] = 1$ if the Boolean expression is true and $0$ otherwise.

Let's restate the problem as

Problem. Given a sequence $a_1, a_2, \dots, a_n$, divide it into two disjoint subsequences $s$ and $t$ such that $\mathit{seg}(s)+\mathit{seg}(t)$ is as large as possible.

Solution. We will construct two disjoint subsequences by scanning through the sequence $a_1, a_2, \dots, a_n$. 

Initial setting: $s$ and $t$ are two empty sequences, and $a_1, a_2, \dots, a_n$ remains not scanned. 

Move on: Suppose the last elements of $s$ and $t$ are $x$ and $y$, respectively, and $x = 0$ (resp. $y = 0$) if $s$ (resp. $t$) is empty. Let $z$ be the current element scanning through $a_1, a_2, \dots, a_n$. Our greedy strategy is described in two cases: 

* Greedy Strategy I: If $z$ equals to one of $x$ and $y$, then assign $z$ to the opposite subsequence. That is, if $z = x$, then append $z$ after $y$; and if $z = y$, then append $z$ after $x$. In particular, if $z$ equals to both $x$ and $y$, the assignment could be arbitrary.
* Greedy Strategy II: If $z$ differs from both $x$ and $y$, then append $z$ after the one with the nearest next same value. That is, let $\mathit{next}(x)$ denote the next position where $x$ appears in $a_1, a_2, \dots, a_n$ after $z$, then append $z$ after $x$ if $\mathit{next}(x) < \mathit{next}(y)$, and after $y$ otherwise.

The greedy strategy is intuitive, and with this strategy, an $O(n)$ algorithm is immediately obtained. However, its proof turns out to be complicated. We append its proof for completeness.

An Intuitive Proof

Consider any optimal assignment $b_1, b_2, \dots, b_n$, we will show that our strategy is not worse than it. Let $a[l \dots r] = a_l, a_{l+1}, \dots, a_r$ be the subarray of $a$. 

Now suppose we are at some position $p$, where the optimal assignment conflicts with our strategy. We assume that $s = (a[1\dots p])^{(0)} = s' x$ ends with $x$, and $t = (a[1\dots p])^{(1)} = t' y$ ends with $y$, and $a_{p+1} = z$. 

Greedy Strategy I: If $b$ conflicts with Greedy Strategy I, then we must have $x \neq y$ and without loss of generality, we assume that $x = z$. Greedy Strategy I suggests we append $z$ after $y$ but $b$ suggests we append $z$ after $x$. Suppose $b$ results in the two subarrays $\begin{aligned} & s'xzs^{\prime \prime} \\\ & t'yt^{\prime \prime} \end{aligned}$, while there is indeed another optimal assignment that agrees with our strategy and results in $\begin{aligned} & s'xt^{\prime \prime} \\\ & t'yzs^{\prime \prime} \end{aligned}$.

Greedy Strategy II: If $b$ conflicts with Greedy Strategy II, then we must have $x$, $y$ and $z$ are distinct and without loss of generality, we assume that the next occurrence of $x$ goes in front of that of $y$. Greedy Strategy II suggests we append $z$ after $x$ but $b$ suggests we append $z$ after $y$. Suppose $b$ results in the two subarrays $\begin{aligned} & s'xs^{\prime \prime} \\\ & t'yzt^{\prime \prime} \end{aligned}$. Consider two cases.

Case 1. If $s^{\prime \prime}$ does not start with $y$, then there is another optimal assignment that agrees with our strategy and results in $\begin{aligned} & s'xzt^{\prime \prime} \\\ & t'ys^{\prime \prime} \end{aligned}$.

Case 2. If $s^{\prime \prime}$ starts with $y$, i.e. $s^{\prime \prime} = y s_1$, then since the first occurrence of $x$ is in front of that of $y$, we have that $x$ must be in $t^{\prime \prime}$, and assume that $t^{\prime \prime} = t_1 x t_2$. The result of $b$ is restated as $\begin{aligned} & s'x y s_1 \\\ & t'yzt_1 x t_2 \end{aligned}$. We find that there is another optimal assignment that agrees with our strategy and results in $\begin{aligned} & s'xz t_1 y s_1 \\\ & t'yx t_2 \end{aligned}$ (Note that $t_1$ does not contain any $x$ or $y$ in it).

A Formal Proof

The number of alternations in a sequence $a$ starting with $x$ is defined to be $$ \mathit{seg}_x(a) = \sum_{i=1}^n [ a_{i-1} \neq a_{i} ], $$ where $a_0 = x$. We note that $\mathit{seg}_0(a) = \mathit{seg}(a)$.

Let $f_{x,y}(a)$ denote the maximal possible sum of numbers of alternations in the two disjoint subsequences $s$ and $t$ of $a$, i.e. $$ f_{x, y}(a) = \max_{s, t} \{\mathit{seg}_x(s)+\mathit{seg}_y(t)\}, $$ where $s$ and $t$ ranges over all possible pairs of disjoint subsequences of $a$. It is obvious that the order of $x$ and $y$ does not matter, i.e. $f_{x,y}(a) = f_{y,x}(a)$. We note that our goal is to compute $f_{0,0}(a)$.

Let $\mathit{next}(x)$ denote the least index $k$ such that $a_k = x$, i.e. $\mathit{next}(x) = \min\{k \in \mathbb{N}: a_k = x\}$. In case no such index $k$ exists, $\mathit{next}(x)$ is defined to be $\infty$.

In fact, our problem can be solved by DP regardless of the time complexity.

Proposition 1 (Dynamic Programming). For $n \geq 1$ and every $x, y \in \mathbb{N}$, $$ f_{x,y}(a_1, a_2, \dots, a_n) = \max \{ f_{a_1, y} (a_2, \dots, a_n) + [a_1 \neq x], f_{x, a_1} (a_2, \dots, a_n) + [a_1 \neq y] \}. $$ In particular, for empty sequence $\epsilon$, we have $f_{x,y}(\epsilon) = 0.$

We can obtain some immediate properties of $f_{x, y}(a)$ by the above DP recurrence.

Proposition 2. For every $x, y \in \mathbb{N}$, $f_{x,0}(a) \geq f_{x,y}(a) \geq f_{x,x}(a)$. Moreover, if $\mathit{next}(y) = \infty$, then $f_{x,0}(a) = f_{x,y}(a)$.

After some observations, we have

Proposition 3. For every $x, y, z \in \mathbb{N}$ and sequence $a$, $f_{z,x}(a)+1 \geq f_{z,y}(a)$.

Proof: By induction on the length $n$ of sequence $a$.

 Basis. It is trivial for the case $n = 0$ since the left hand side is always $1$ and the right hand side is always $0$.

 Induction. Suppose true for the case $n = k (k \geq 0)$, i.e. $$ f_{z,x}(a)+1 \geq f_{z,y}(a) $$ holds for every sequence $a$ of length $k$. Now consider a sequence $a_1, a_2, \dots, a_{k+1}$ of length $k+1$.

 Case 1. $x = y$. It is trivial that $f_{z,x}(a)+1 \geq f_{z,x}(a)$.

 Case 2. $z = x \neq y$. We should prove that $f_{x,x}(a)+1 \geq f_{x,y}(a)$. By Proposition 1, we need to prove that $$ \begin{cases} f_{a_1,x}(a_2,\dots,a_{k+1})+[a_1 \neq x]+1 \geq f_{a_1,y}(a_2,\dots,a_{k+1})+[a_1 \neq x], \\\ f_{a_1,x}(a_2,\dots,a_{k+1})+[a_1 \neq x]+1 \geq f_{x,a_1}(a_2,\dots,a_{k+1})+[a_1 \neq y]. \end{cases} $$ The second inequality is obvious. The first inequality becomes $$ f_{a_1,x}(a_2,\dots,a_{k+1})+1 \geq f_{a_1,y}(a_2,\dots,a_{k+1}), $$ which holds by induction.

 Case 3. $x \neq y = z$. We should prove that $f_{x,y}(a)+1 \geq f_{x,x}(a)$. By Proposition 1, we only need to prove that $$ f_{x,a_1}(a_2,\dots,a_{k+1})+[a_1 \neq y]+1 \geq f_{a_1,x}(a_2,\dots,a_{k+1})+[a_1 \neq x], $$ which is obvious.

 Case 4. $x \neq y, z \neq x$ and $z \neq y$. By Proposition 1, $f_{z,x}(a)+1 \geq f_{z,y}(a)$ is equivalent to $$ \begin{aligned} & \max\{ f_{a_1, x}(a_2,\dots,a_{k+1})+[a_1 \neq z], f_{z, a_1}(a_2,\dots,a_{k+1})+[a_1 \neq x] \} + 1 \\\ & \quad \geq \max\{ f_{a_1, y}(a_2,\dots,a_{k+1})+[a_1 \neq z], f_{z, a_1}(a_2,\dots,a_{k+1})+[a_1 \neq y] \}. \end{aligned} $$

 Case 4.1. $a_1 = z$. The left hand side becomes $$ \max\{ f_{z, x}(a_2,\dots,a_{k+1}), f_{z, z}(a_2,\dots,a_{k+1})+1 \} + 1 = f_{z, z}(a_2,\dots,a_{k+1})+2 $$ by induction that $f_{z,z}(a_2,\dots,a_{k+1})+1 \geq f_{z,x}(a_2,\dots,a_{k+1})$. The right hand side becomes $$ \max\{ f_{z, y}(a_2,\dots,a_{k+1}), f_{z, z}(a_2,\dots,a_{k+1})+1 \} = f_{z, z}(a_2,\dots,a_{k+1})+1 $$ by induction that $f_{z,z}(a_2,\dots,a_{k+1})+1 \geq f_{z,y}(a_2,\dots,a_{k+1})$. The inequality holds immediately.

 Case 4.2. $a_1 = x$. The left hand side becomes $$ \max\{ f_{x, x}(a_2,\dots,a_{k+1})+1, f_{z, x}(a_2,\dots,a_{k+1}) \} + 1 = f_{x,x}(a_2,\dots,a_{k+1})+2 $$ by induction that $f_{x,x}(a_2,\dots,a_{k+1})+1 \geq f_{z,x}(a_2,\dots,a_{k+1})$. The right hand side becomes $$ \max\{ f_{x, y}(a_2,\dots,a_{k+1})+1, f_{z, x}(a_2,\dots,a_{k+1})+1 \}. $$ By induction that $f_{x,x}(a_2,\dots,a_{k+1})+1 \geq f_{x, y}(a_2,\dots,a_{k+1})+1$ and $f_{x,x}(a_2,\dots,a_{k+1})+1 \geq f_{x, z}(a_2,\dots,a_{k+1})+1$, the inequality holds.

 Case 4.3. $a_1 = y$. The left hand side becomes $$ \max\{ f_{y, x}(a_2,\dots,a_{k+1})+1, f_{z, y}(a_2,\dots,a_{k+1})+1 \} + 1. $$ The right hand side becomes $$ \max\{ f_{y, y}(a_2,\dots,a_{k+1}), f_{z, y}(a_2,\dots,a_{k+1})+1 \} = f_{z, y}(a_2,\dots,a_{k+1})+1 $$ by induction that $f_{y,y}(a_2,\dots,a_{k+1})+1 \geq f_{z, y}(a_2,\dots,a_{k+1})+1$. The inequality immediately holds as $f_{z,y}(a_2,\dots,a_{k+1})$ appears in both sides (and can be eliminated together).

 Case 4.4. $a_1 \notin \{x,y,z\}$. The left hand side becomes $$ \max\{ f_{a_1, x}(a_2,\dots,a_{k+1})+1, f_{z, a_1}(a_2,\dots,a_{k+1})+1 \} + 1. $$ The right hand side becomes $$ \max\{ f_{a_1, y}(a_2,\dots,a_{k+1})+1, f_{z, a_1}(a_2,\dots,a_{k+1})+1 \}. $$ By induction that $f_{a_1,x}(a_2,\dots,a_{k+1})+1 \geq \max\{f_{a_1,y}(a_2,\dots,a_{k+1}),f_{a_1,z}(a_2,\dots,a_{k+1})\}$, the inequality holds.

 The inequality holds for all cases. Therefore, the inequality holds for $n = k+1$.

 Conclusion. The inequality holds for every $n \geq 0$. $\Box$

Proposition 4. Suppose $a_1, a_2, \dots, a_n$ is a sequence. For every distinct $x, y, z \in \mathbb{N}$, i.e. $x \neq y, y \neq z$ and $z \neq x$, if $\mathit{next}(x) < \mathit{next}(y)$, then $f_{z,y}(a) \geq f_{z,x}(a)$.

Proof: By induction on the length $n$ of sequence $a$.

 Basis. It is trivial for the case $n = 0$ since the both hand sides are $0$.

 Induction. Suppose true for the case $n = k (k \geq 0)$, i.e. $$ f_{z,y}(a) \geq f_{z,x}(a). $$ holds for every sequence $a$ of length $k$. Now consider a sequence $a_1, a_2, \dots, a_{k+1}$ of length $k+1$.

 Case 1. $a_1 = z$. By Proposition 1 and 3, the left hand side becomes $$ \max\{ f_{z, y}(a_2,\dots,a_{k+1}), f_{z, z}(a_2,\dots,a_{k+1})+1 \} = f_{z, z}(a_2,\dots,a_{k+1})+1, $$ and the right hand side becomes $$ \max\{ f_{z, x}(a_2,\dots,a_{k+1}), f_{z, z}(a_2,\dots,a_{k+1})+1 \} = f_{z, z}(a_2,\dots,a_{k+1})+1 $$ The inequality holds immediately.

 Case 2. $a_1 = x$. By Proposition 1, the left hand side becomes $$ \max\{ f_{x, y}(a_2,\dots,a_{k+1})+1, f_{z, x}(a_2,\dots,a_{k+1})+1 \}, $$ and the right hand side becomes $$ \max\{ f_{x, x}(a_2,\dots,a_{k+1})+1, f_{z, x}(a_2,\dots,a_{k+1}) \}. $$ By Proposition 2, we have $$ f_{z, x}(a_2,\dots,a_{k+1}) \geq f_{x, x}(a_2,\dots,a_{k+1}), $$ and therefore, the inequality holds.

 Case 3. $a_1 = y$. This is impossible because $\mathit{next}(x) < \mathit{next}(y)$, i.e. there is an element of value $x$ in front of the first element of value $y$.

 Case 4. $a_1 \notin \{x,y,z\}$. The left hand side becomes $$ \max\{ f_{a_1, y}(a_2,\dots,a_{k+1})+1, f_{a_1, z}(a_2,\dots,a_{k+1})+1 \}. $$ The right hand side becomes $$ \max\{ f_{a_1, x}(a_2,\dots,a_{k+1})+1, f_{a_1, z}(a_2,\dots,a_{k+1})+1 \}. $$

 Case 4.1. If $\mathit{next}(y) > \mathit{next}(z)$, then by induction we have $$ f_{a_1, y}(a_2,\dots,a_{k+1}) \geq f_{a_1, z}(a_2,\dots,a_{k+1}), $$ and (because $\mathit{next}(y) > \mathit{next}(x)$, ) $$ f_{a_1, y}(a_2,\dots,a_{k+1}) \geq f_{a_1, x}(a_2,\dots,a_{k+1}). $$ The inequality holds.

 Case 4.2. If $\mathit{next}(y) < \mathit{next}(z)$, then by induction we have $$ f_{a_1, z}(a_2,\dots,a_{k+1}) \geq f_{a_1, y}(a_2,\dots,a_{k+1}), $$ and (because $\mathit{next}(z) > \mathit{next}(y) > \mathit{next}(x)$, ) $$ f_{a_1, z}(a_2,\dots,a_{k+1}) \geq f_{a_1, x}(a_2,\dots,a_{k+1}). $$ The inequality holds.

 The inequality holds for all cases. Therefore, the inequality holds for $n = k+1$.

 Conclusion. The inequality holds for every $n \geq 0$.

Proposition 5 (Greedy Strategy I). Suppose $a_1, a_2, \dots, a_n$ is a sequence. For every $x, y \in \mathbb{N}$, if $a_1 = x$, then $$ f_{x,y}(a_1,\dots,a_n) = f_{x,x}(a_2,\dots,a_n)+1. $$

Proof: By Proposition 1, we have $$ f_{x,y}(a_1,\dots,a_n) = \max \{ f_{x, y} (a_2, \dots, a_n), f_{x, x} (a_2, \dots, a_n) + 1 \}. $$ By Proposition 3, we have $$ f_{x,x}(a_2, \dots, a_n) + 1 \geq f_{x, y} (a_2, \dots, a_n). $$ Combining with the both above yields the proof. $\Box$

Proposition 6 (Greedy Strategy II). Suppose $a_1, a_2, \dots, a_n$ is a sequence. For every $x, y \in \mathbb{N}$ with $x \neq y$, if $a_1 \notin \{x,y\}$, then $$ f_{x,y}(a_1,\dots,a_n) = \begin{cases} f_{a_1,y}(a_2,\dots,a_n)+1 & \mathit{next}(x) < \mathit{next}(y), \\\ f_{x,a_1}(a_2,\dots,a_n)+1 & \text{otherwise}. \end{cases} $$ Proof: If $\mathit{next}(x) < \mathit{next}(y)$, by Proposition 4, we have $$ f_{a_1,y}(a_2,\dots,a_n) \geq f_{x,a_1}(a_2,\dots,a_n). $$ Therefore, by Proposition 1, we have $f_{x,y}(a_1,\dots,a_n) = f_{a_1,y}(a_2,\dots,a_n)+1$.

 The same statement holds for $\mathit{next}(x) > \mathit{next}(y)$. $\Box$

 **Solution**[106873713](https://codeforces.com/contest/1479/submission/106873713 "Submission 106873713 by liouzhou_101")

[1479B2 - Painting the Array II](../problems/B2._Painting_the_Array_II.md "Codeforces Round 700 (Div. 1)")

 **Tutorial**
### [1479B2 - Painting the Array II](../problems/B2._Painting_the_Array_II.md "Codeforces Round 700 (Div. 1)")

There are two approaches from different perspectives. 

DP Approach

The first observation is that merging adjacent elements with the same value will not influence the answer. Therefore, without loss of generality, we may assume that there are no adjacent elements with the same value, i.e. $a_{i} \neq a_{i+1}$ for every $1 \leq i < n$.

We can solve this problem by a DP approach. Let $f(i)$ denote the minimal possible number of segments for sub-array $a_1, a_2, \dots, a_i$ over all assignments $b_1, b_2, \dots, b_i$ with $b_i \neq b_{i-1}$, where $b_{0} = -1$ for convenience. To obtain the answer, we enumerate the last position $1 \leq i \leq n$ such that $b_{i-1} \neq b_i$, and append all elements $a_{i+1}, a_{i+2}, \dots, a_n$ to the end of $a_i$, which implies an arrangement with $f(i)+n-i$ segments. The minimal number of segments will be the minimum among $f(i)+n-i$ over all $1 \leq i \leq n$.

It is straightforward to see that $f(0) = 0$ and $f(1) = 1$.

For $2 \leq i \leq n$, $f(i)$ can be computed by enumerating every possible position $1 \leq j < i$ such that $b_{j-1} \neq b_j = b_{j+1} = \dots = b_{i-1} \neq b_i$. That is, $a_j, a_{j+1}, \dots, a_{i-1}$ are assigned to the same sub-sequence, and $a_{j-1}$ and $a_i$ are assigned to the other sub-sequence. Since no adjacent elements has the same value (by our assumption), there are $(i-j)$ segments in $a_j, a_{j+1}, \dots, a_{i-1}$ (we note that the first segment, i.e. the segment of $a_j$, is counted in $f(j)$). Moreover, there will be zero or one new segment when concatenating $a_{j-1}$ and $a_{i}$ depending on whether $a_{j-1} = a_i$ or not. Hence, for every $2 \leq j \leq n$, we have $$ f(i) = \min_{1 \leq j < i} \{ f(j) + (i-j-1) + [a_{j-1} \neq a_i] \}, $$ where $[\text{Boolean expression}] = 1$ if the Boolean expression is true and $0$ otherwise. Here, we obtain an $O(n^2)$ DP solution.

To optimize the DP recurrence, we fix $i$, and let $g(j) = f(j) + (i-j-1) + [a_{j-1} \neq a_i]$, then $f(i) = \max_{1\leq j < i}\{g(j)\}$. We can observe that

Lemma 1. For $2 \leq i \leq n$, we have $$f(i) = \min\{ g(i-1), g(j^*) \},$$ where $j^* = \max\{1 \leq j < i : a_{j-1} = a_i\}$, $\max \emptyset = 0$, and $g(0) = +\infty$.

This lemma is very intuitive, which means we need only to consider two cases: one is to just append $a_i$ after $a_{i-1}$ in the same sub-sequence, and the other is to append $a_i$ after the closest $a_{j}$ with the same value, i.e. $a_i = a_j$, and then assign the elements between them (not inclusive) to the other sub-sequence. With this observation, we immediately obtain an $O(n)$ DP solution.

The proof is appended below for completeness.

Proof: For every $1 \leq j < i$, we have $$ f(i) \leq g(j) = f(j) + (i-j-1) + [a_{j-1} \neq a_i] \leq f(j) + i - j, $$ which implies that $f(i) - i \leq f(j) - j$ for every $1 \leq j \leq i \leq n$. 

Now we consider $g(j)$ for every $1 \leq j < i$ in two cases. 

1. $a_{j-1} \neq a_i$. We have $$\begin{aligned} g(j) & = f(j) + (i-j-1) + 1 \\\ & = f(j)-j+i \\\ & \geq f(i-1)-(i-1) + i \\\ & = f(i-1)+1 \\\ & \geq g(i-1).\end{aligned}$$
2. $a_{j-1} = a_i$. Suppose there are two different positions $j_1$ and $j_2$ such that $1 \leq j_1 < j_2 < i$ and $a_{j_1-1} = a_{j_2-2} = a_i$, then $$\begin{aligned} g(j_1) & = f(j_1) + (i-j_1-1) \\\ & = f(j_1) -j_1 +i-1 \\\ & \geq f(j_2)-j_2+i-1 \\\ & = g(j_2). \end{aligned}$$

 Combine the two cases, we conclude that $f(i) = \min\{ g(i-1), g(j^*) \}$, where $j^* = \max\{1 \leq j < i : a_{j-1} = a_i\}$. $\Box$Greedy Approach

Consider we have a computer whose cache has only two registers. Let's suppose the array $a$ is a sequence of memory access to the computer. The problem is then converted to a more intuitive one that asks the optimal cache replacement. 

Suppose the current two registers contains two memory accesses $x$ and $y$, and the current requirement memory access is $z$. 

The greedy strategy is simple: If $z$ matches one of $x$ and $y$, just do nothing. Otherwise, the register that contains the memory access whose next occurrence is farther than the other will be replaced by $z$.

This strategy is know as Bélády's algorithm or farthest-in-the-future cache/page replacement policy (see [here](https://codeforces.com/https://en.wikipedia.org/wiki/Cache_replacement_policies) for more information). The complexity is $O(n)$ since we only need to preprocess every element's next occurrence. 

 **Solution**DP: [106873739](https://codeforces.com/contest/1479/submission/106873739 "Submission 106873739 by liouzhou_101") Greedy: [106873763](https://codeforces.com/contest/1479/submission/106873763 "Submission 106873763 by liouzhou_101")

[1479C - Continuous City](../problems/C._Continuous_City.md "Codeforces Round 700 (Div. 1)")

 **Tutorial**
### [1479C - Continuous City](../problems/C._Continuous_City.md "Codeforces Round 700 (Div. 1)")

The answer is always "YES". For convenience, we write $(x, y, z)$ for a directed road from block $x$ to block $y$ of length $z$.

Step 1. We can solve the case $L = 1$ and $R = 2^k$ for $k \geq 0$ inductively. The case for $k = 0$ is trivial, i.e. only one edge $(1, 2, 1)$.

Suppose there is a city of $k + 2$ blocks for $L = 1$ and $R = 2^k$ for some $k \geq 0$, and the induced city from block $1$ to block $x$ is $(1, 2^{x-2})$-continuous for every $2 \leq x \leq k + 2$. Let block $k + 3$ be a new block, and add $(1, k+3, 1)$ and $(x, k+3, 2^{x-2})$ for $2 \leq x \leq k+2$. We can see that the new city containing block $k + 3$ is $(1, 2^{k+1})$-continuous.

Step 2. Suppose $L = 1$ and $R > 1$. Let $R - 1 = \sum_{i=0}^k R_i 2^i$ be the binary representation of $R - 1$, where $0 \leq R_i \leq 1$. Let $G_k$ be the $(1, 2^k)$-continuous city constructed in Step 1. Let block $k + 3$ be a new block. Connect $(1, k+3, 1)$, and then for every $0 \leq i \leq k$, if $R_i = 1$, then connect $(i+2, k+3, 1+\sum_{j=i+1}^k R_j 2^j)$. We can see that the new city containing block $k + 3$ is $(1, R)$-continuous.

Step 3. Suppose $1 < L \leq R$. Consider $H_{R-L+1}$, where $H_R$ denotes the $(1, R)$-continuous city constructed in Step 2 and there are $k$ blocks in $H_{R-L+1}$. Connect $(k, k+1, L-1)$. We can see that the new city containing block $k + 1$ is $(L, R)$-continuous.

We note that there is at most $23$ blocks in our constructed city.

 **Solution**[106873798](https://codeforces.com/contest/1479/submission/106873798 "Submission 106873798 by liouzhou_101")

[1479D - Odd Mineral Resource](../problems/D._Odd_Mineral_Resource.md "Codeforces Round 700 (Div. 1)")

 **Tutorial**
### [1479D - Odd Mineral Resource](../problems/D._Odd_Mineral_Resource.md "Codeforces Round 700 (Div. 1)")

Let $s(u, v, c)$ denote the number of cities between city $u$ and city $v$, whose mineral resource is $c$. We restate the problem that for each query $u, v, l, r$, find an integer $c$ such that $l \leq c \leq r$ and $s(u, v, c) \not\equiv 0 \pmod 2$.

We give a randomized algorithm with success probability extremely high. For every kind of mineral resources $1 \leq i \leq n$, we assign a random variable $X_i$ to it. Those random variables $X_i$ are independent and identically uniformly distributed from $[0, 2^{64}-1]$. For every city $u$, we assign its weight to be $X_{c_u}$. 

For every query $u, v, l, r$, Let $f(u, v, l, r)$ be the [bitwise XOR](https://codeforces.com/https://en.wikipedia.org/wiki/Bitwise_operation#XOR) of all weights of all cities between city $u$ and city $v$, whose mineral resources are in $[l, r]$. We claim that 

1. $ \Pr\left[\, f(u, v, l, r) = 0 \mid \forall c, s(u, v, c) \equiv 0 \pmod 2 \,\right] = 1$, which means that if a suitable $c$ does not exist then $f(u, v, l, r) = 0$ for certainty, and
2. $ \Pr\left[\, f(u, v, l, r) \neq 0 \mid \exists c, s(u, v, c) \not\equiv 0 \pmod 2 \,\right] = 1-2^{-64}$, which means that if a suitable $c$ does exist then $f(u, v, l, r) \neq 0$ with high probability.

 Let's consider the reverse that 1. $\Pr\left[\, \forall c, s(u, v, c) \equiv 0 \pmod 2 \mid f(u, v, l, r) = 0 \,\right] = 1-2^{-64}$, which implies with high probability no suitable mineral resource exists if $f(u, v, l, r) = 0$, and
2. $\Pr\left[\, \exists c, s(u, v, c) \not\equiv 0 \pmod 2 \mid f(u, v, l, r) \neq 0 \,\right] = 1$, which implies with certainty at least one suitable mineral resource exists.

 According to the above discussion, our strategy is 1. to report no solution if $f(u, v, l, r) = 0$, and
2. to find a $c$ ($l \leq c \leq r$) such that $f(u, v, c, c) \neq 0$ if $f(u, v, l, r) \neq 0$.

 Our strategy will succeed with probability $p \geq 1-2^{-64}$. Now consider there are $q$ queries. Let $A_i$ denote the event that the $i$-th query succeeds. The $i$-th query will succeed with probability $\Pr[A_i] \geq 1-2^{-64}$ (however, they may not be independent). Then we have $$ \begin{aligned} \Pr\left[ \bigwedge_{i=1}^{q} A_i \right] & = 1 - \Pr\left[ \bigvee_{i=1}^q \bar A_i \right] \\\ & \geq 1 - \sum_{i=1}^q \Pr[\bar A_i] \\\ & = 1 - \sum_{i=1}^q \left( 1 - \Pr[A_i] \right) \\\ & \geq 1 - \sum_{i=1}^q \left( 1 - \left( 1 - 2^{-64} \right) \right) \\\ & = 1 - 2^{-64}q, \end{aligned} $$ which means all queries succeed simultaneously with probability at least $1 - 2^{-64}q \geq 1-2^{-44}$ if $q \leq 2^{20}$, which is high enough under constraints of the problem.

To this end, we shall compute $f(u, v, l, r)$ and find a $c$ ($l \leq c \leq r$) such that $f(u, v, c, c) \neq 0$. This can be solved by consistent segment trees. Let's root the tree (by any vertex, say vertex $1$). For every vertex $u$, we maintain a (consistent) segment tree that for each interval $[l, r]$ computes $f(1, u, l, r)$. Let $\mathit{father}(u)$ be the father of vertex $u$, and $\mathit{lca}(u, v)$ be the least common ancestor of vertex $u$ and vertex $v$. Then $$ f(u, v, l, r) = f(1, u, l, r) \oplus f(1, v, l, r) \oplus f(1, \mathit{lca}(u, v), l, r) \oplus f(1, \mathit{father}(\mathit{lca}(u, v)), l, r). $$ For more details, please according to [SPOJ COT](https://codeforces.com/https://www.spoj.com/problems/COT/). Therefore, we have solved this problem with high enough probability in $O(n \log n)$ time and space.

 **Solution**[106873842](https://codeforces.com/contest/1479/submission/106873842 "Submission 106873842 by liouzhou_101")

[1479E - School Clubs](../problems/E._School_Clubs.md "Codeforces Round 700 (Div. 1)")

 **Tutorial**
### [1479E - School Clubs](../problems/E._School_Clubs.md "Codeforces Round 700 (Div. 1)")

Section 1. The Expected Value of Stopping Time

There may be several ways to deal with the expected value of stopping time. Here, we decide to give an elegant way to derive the expected stopping time inspired by [MiFaFaOvO's comment](https://codeforces.com/blog/entry/77284?#comment-620956). Here, we are going to introduce the mathematical tool we will use in the following description (see [here](https://codeforces.com/https://www.cnblogs.com/TinyWong/p/12887591.html) for a Chinese explanation.)

Consider a random process $A_0, A_1, A_2, \dots$, where $A_i$ is called the $i$-th event of the process, or the event at time $i$. Let random variable $T \in \mathbb{N}$ be its stopping time. That is, for every $t \in \mathbb{N}$, It can be decided whether $T = t$ as long as $A_0, A_1, \dots, A_t$ are given. If there is a function $\phi(\cdot)$ that maps an event to a real number such that 

1. $\mathbb{E}[\,\phi(A_{t+1})-\phi(A_t) \mid A_0, A_1, \dots, A_t \,] = -1$ for every $t \in \mathbb{N}$, and
2. $\mathbb{E}[\phi(A_T)]$ depends on some properties of the events and the stopping time, which is usually a constant in practice.

 Let $X_t = \phi(A_t)+t$, then $\mathbb{E}[\, X_{t+1}-X_t \mid A_0, A_1, \dots, A_t \,] = 0$. That is, $X_0, X_1, X_2, \dots$ is a martingale of $A_0, A_1, \dots$. By the optimal stopping theorem, under some ignorable conditions, we have that $\mathbb{E}[X_T] = \mathbb{E}[X_0]$. Therefore, $\mathbb{E}[T] = \mathbb{E}[\phi(A_0) - \phi(A_T)]$. Moreover, if $\phi(A_T)$ is a constant, then $$ \mathbb{E}[T] = \phi(A_0) - \phi(A_T). $$ We will use the above identity to find the expected value of $T$, the stopping time. Usually, $\phi(\cdot)$ is called the potential function.To begin our journey, we should first describe an event as something (a number, a tuple, a sequence, or a set) in our problem. We find it naturally to use a (multi-)set $A = \{ a_1, a_2, \dots, a_m \}$ to describe it, where $m$ denotes the number of clubs, the $i$-th of which contains $a_i$ students. We see that the explicit order of the clubs does not matter but the number of students in each club. Furthermore, we notice that every club's status is equal, which implies us to define the potential function as the form $$ \phi(A) = \sum_{a \in A} f(a) = \sum_{i=1}^m f(a_i), $$ where $m = |{A}|$. It should be noted that the sum of elements in $A$ is a constant, so we let $$ n = \sum_{a \in A} a = \sum_{i=1}^m a_i. $$

We first consider the corner case for the value of $f(0)$. Since students will never join an empty club, $A$ and $A \cup \{0\}$ denotes the events with the same property. Therefore, we need $\phi(A) = \phi(A \cup \{0\})$, which immediately yields $f(0) = 0$.

We now investigate how the potential function behaves from the $t$-th event $A_t = \{ a_1, a_2, \dots, a_m \}$ to the $(t+1)$-th event $A_{t+1}$. We note that the student who gets angry is in the $i$-th club with probability $\frac {a_i} n$. After that, the angry student will 

1. leave and create a new club with probability $\frac 1 2$. In this case, $A_{t+1} = \{ a_1, a_2, \dots, a_{i-1}, a_i-1, a_{i+1}, \dots, a_m, 1 \}$, and we have $$ \phi(A_{t+1}) = \phi(A_t)-f(a_i)+f(a_i-1)+f(1), $$
2. join the $j$-th club ($j \neq i$) with probability $\frac {a_j} {2n}$. In this case, $A_{t+1} = \{ a_1, a_2, \dots, a_i-1, a_j +1, \dots, a_m\}$, and we have $$ \phi(A_{t+1}) = \phi(A_t)-f(a_i)-f(a_j)+f(a_i-1)+f(a_j+1), $$
3. stay still in the $i$-th club with probability $\frac {a_i} {2n}$. In this case, $A_{t+1} = A_t$, and we have $$ \phi(A_{t+1}) = \phi(A_t). $$

To sum it up, we get that $$ \begin{aligned} \mathbb{E}[\, \phi(A_{t+1}) \mid A_t \,] = \sum_{i=1}^m \frac {a_i} n \Bigg[ & \frac 1 2 \big(\phi(A_t)-f(a_i)+f(a_i-1)+f(1)\big) \\\ &+ \sum_{j \neq i} \frac {a_j} {2n} \big( \phi(A_t)-f(a_i)-f(a_j)+f(a_i-1)+f(a_j+1) \big) + \frac {a_i} {2n} \phi(A_t) \Bigg]. \end{aligned} $$ Let $\mathbb{E}[\,\phi(A_{t+1})-\phi(A_t) \mid A_0, A_1, \dots, A_t \,] = -1$, and then we obtain that $$ f(1) + \sum_{i=1}^m \frac {a_i} {n^2} \left[ (2n - a_i) f(a_i-1) + (n - a_i) f(a_i+1) - (3n - 2a_i) f(a_i) \right] + 2 = 0. $$ Here, we need to find a function $f(\cdot)$ that satisfies the above condition with the corner case $f(0) = 0$.

There are several possible ways to assign the value of $f(a)$. We choose the most simple one such that $f(1)+2 = 0$, which removes the constant term. Under this assignment, we have $f(1) = -2$. After this, we have to make that $$ (2n - a) f(a-1) + (n - a) f(a+1) - (3n - 2a) f(a) = 0, $$ i.e. $$ (n-a) \left[ f(a+1)-f(a) \right] = (2n-a) \left[ f(a)-f(a-1) \right]. $$ holds for every $a$.

We let $g(a) = f(a+1)-f(a)$ for $a \geq 0$. Therefore, $g(0) = f(1)-f(0) = -2$, and $$ \begin{aligned} g(a) & = \frac {2n-a} {n-a} g(a-1) \\\ & = \frac {2n-a} {n-a} \cdot \frac {2n-(a-1)} {n-(a-1)} g(a-1) \\\ & = \dots \\\ & = \frac {2n-1} {n-1} \cdot \frac {2n-2} {n-2} \cdot \dots \cdot \frac {2n-a} {n-a} g(0). \end{aligned} $$ We find that $$ \begin{aligned} f(a) & = f(0) + g(0) + g(1) + \dots + g(a-1) \\\ & = -2 \left[ 1 + \frac {P(1)} {Q(1)} + \frac {P(2)} {Q(2)} + \dots + \frac {P(1)P(2) \dots P(a-1)} {Q(1)Q(2) \dots Q(a-1)} \right], \end{aligned} $$ where $P(x) = 2n-x$ and $Q(x) = n-x$. If we can compute $f(a)$ in an efficient way, then the problem is solved. However, it seems not so straightforward.

Section 2. The Trick for the Prefix Sum by Generating Functions

For convenience, we denote $$ S(a) = \frac {P(1)} {Q(1)} + \frac {P(2)} {Q(2)} + \dots + \frac {P(1)P(2) \dots P(a)} {Q(1)Q(2) \dots Q(a)}, $$ where $P(x)$ and $Q(x)$ are linear functions (polynomials of degree $1$). To compute $S(a)$, we use the trick mentioned in [min_25's blog](https://codeforces.com/https://min-25.hatenablog.com/entry/2017/04/10/215046). However, the trick we adopt here can deal with more general cases.

Let $N > a$ be a large enough positive integer. Then we have $$ \begin{aligned} S(a) = \frac 1 {Q(1)Q(2) \dots Q(N)} \Big[ & P(1)Q(2)Q(3)\dots Q(a)Q(a+1) \dots Q(N) + \\\ & P(1)P(2)Q(3)\dots Q(a)Q(a+1) \dots Q(N) + \\\ & \dots + \\\ & P(1)P(2)P(3)\dots P(a)Q(a+1) \dots Q(N) \Big]. \end{aligned} $$ We only have to compute the inner sum $s(a) = S(a)Q(1)Q(2) \dots Q(N)$. We now use the SQRT trick here. Let $B \approx \sqrt N$ be the block size. Let $$ \begin{aligned} R(z) = & P(z+1)Q(z+2)Q(z+3) \dots Q(z+B) + \\\ & P(z+1)P(z+2)Q(z+3) \dots Q(z+B) + \\\ & \dots + \\\ & P(z+1)P(z+2)P(z+3) \dots P(z+B). \end{aligned} $$ Then we will see that $$ \begin{aligned} s(a) = & \sum_{k=0}^{\lfloor{a/B}\rfloor} P(1)\dots P(kB) R(kB) Q((k+1)B+1) \dots Q(N) \\\ & + \sum_{i=(\lfloor{a/B}\rfloor+1)B+1}^a P(1)\dots P(i) Q(i+1) \dots Q(N). \end{aligned} $$ It is more convenient to let $\mathfrak{P}(k) = P(1)\dots P(kB)$ and $\mathfrak{Q}(k) = Q(kB+1) \dots Q(N)$, then the main summation in $s(a)$ is written as $$ \sum_{k=0}^{\lfloor{a/B}\rfloor} \mathfrak{P}(k) R(kB) \mathfrak{Q}(k+1). $$ Now, we have three values needed, which are $R(z), \mathfrak{P}(k), \mathfrak{Q}(k)$.

Compute $R(z)$

 We deal with $R(z)$ first. We note that $R(z)$ is a polynomial of degree $B$ and we want to compute $R(kB)$ for every $0 \leq k \leq N/B$. If we can obtain the values of $R(0), R(1), \dots, R(B)$, then by Lagrange interpolation, we can recover the polynomial $R(z)$. And then, if we know the exact polynomial $R(z)$, then by multi-point evaluation trick, we can compute the values of $R(kB)$ for every $k \leq N/B$. The total time complexity would be $O(\sqrt{N} \log^2 N)$.

We can compute $R(0)$ in $O(B)$ time. And then, we note that $$ R(z) = \frac {Q(z+B)} {P(z)} R(z-1) - Q(z+1) \dots Q(z+B) + P(z+1) \dots P(z+B). $$ Therefore, $R(1), \dots, R(B)$ can be computed in $O(B)$ time if we simultaneously maintain the values of block product of $P(\cdot)$ and $Q(\cdot)$ in the above identity.

 Bonus: A "log" in the complexity may be eliminated by some trick similar to [min_25's blog](https://codeforces.com/https://min-25.hatenablog.com/entry/2017/04/10/215046)?

Compute $\mathfrak{P}(k)$

 This subproblem is very similar to compute the factorial-like product, which is originally mentioned in [min_25's blog](https://codeforces.com/https://min-25.hatenablog.com/entry/2017/04/10/215046). To solve it, we define $$ f_P(z) = P(z+1)P(z+2) \dots P(z+B). $$ Then $\mathfrak{P}(k) = f_P(0) f_P(B) \dots f_P((k-1)B)$. What we need is to compute $f_P(kB)$ fast enough. We also note that $f_P(z)$ is a polynomial of degree $B$. We can easily find the values of $f_P(0), f_P(1), \dots, f_P(B)$ in $O(B)$ time. Therefore, the values of $f_P(kB)$ can be obtained by Lagrange interpolation and multi-point evaluation. In particular, we are able to compute $P(1)P(2)\dots P(N)$ in this way, which is considered to be a general factorial.

compute $\mathfrak{Q}(k)$

 This subproblem is more tricky if we are able to compute $\mathfrak{P}(k)$ fast. Similarly, we define $f_Q(z)$ as what we did when computing $\mathfrak{P}(k)$. Let $\mathfrak{Q}'(k)$ be the prefix block products of $Q(x)$ as an analog for $\mathfrak{P}(k)$ and $P(x)$. It can be easily seen that $$ \mathfrak{Q}(k) = \frac {Q(1)Q(2)\dots Q(N)} {\mathfrak{Q}'(k)}. $$

 Having computed all values we need in the previous several sections, we are able to compute the value of a single $f(a)$ in $O(\sqrt N)$ time. Therefore, the overall complexity is $O(\sqrt N \log^2 N + m \sqrt N)$.

Bonus: Saving $\log n$ in Complexity

 Moreover, we can save $\log n$ in complexity with an improved interpolation method for shifting evaluation values. See the paper "A. Bostan, P. Gaudry, and E. Schost, Linear recurrences with polynomial coefficients and application to integer factorization and Cartier-Manin operator. SIAM Journal of Computing, 36(6): 1777–1806. 2007".

Shifting evaluation values

 Suppose given are a polynomial $f(x)$ of degree $d$ by a point-value representation $f(0), f(1), \dots, f(d)$ and a shift $\delta$. It is asked to compute an alternative point-value representation $f(\delta), f(\delta+1), \dots, f(\delta+d)$. A straightforward way to solve this problem is to directly make use of Lagrange interpolation and multi-point evaluation, which yields an $O(d \log^2 d)$ arithmetic complexity algorithm. In fact, we can do it better in $O(d \log d)$ time.

Recall the formula of Lagrange interpolation that given $n$ points $(x_i, y_i)$ where $y_i = f(x_i)$, then the unique polynomial of degree $(n-1)$ is $$ f(x) = \sum_{i=1}^n y_{i} \prod_{j \neq i} \frac {x-x_j} {x_i-x_j}. $$ Rewrite this formula in our case that $f(0), f(1), \dots, f(d)$ are given, then $$ f(x) = \sum_{i=0}^d f(i) \prod_{j \neq i} \frac {x-j} {i-j}. $$ We assume that $\delta, \delta+1, \dots, \delta+d$ do not overlap with $0, 1, \dots, d$, then for $0 \leq k \leq d$, we have $$ \begin{aligned} f(\delta+k) & = \sum_{i=0}^d f(i) \prod_{j \neq i} \frac {\delta+k-j} {i-j} \\\ & = \left( \prod_{j=0}^d (\delta+k-j) \right) \left( \sum_{i=0}^d \frac {(-1)^{d-i} f(i)} {i! (d-i)!} \cdot \frac {1} {\delta+k-i} \right). \end{aligned} $$ The summation can be computed by FFT. Consider two polynomials: $$ A(x) = \sum_{i=0}^d \frac {(-1)^{d-i} f(i)} {i! (d-i)!} x^i, $$ $$ B(x) = \sum_{i=0}^{2d} \frac {1} {\delta+i-d} x^i. $$ We have $$ f(\delta+k) = \left( \prod_{j=0}^d (\delta+k-j) \right) [x^{d+k}] A(x)B(x). $$

 Therefore, $f(\delta), f(\delta+1), \dots, f(\delta+d)$ can be computed in $O(d \log d)$ time.

Arithmetic sequence shifting

 Now we consider a modified version: given a polynomial of degree $d$ by a point-value representation $f(0), f(s), f(2s), \dots, f(ds)$ and a shift $\delta$, compute $f(\delta), f(\delta+s), f(\delta+2s), \dots, f(\delta+ds)$.

 The trick is to let $g(x) = f(xs)$, which is also a polynomial of degree $d$. Then the problem becomes: given $g(0), g(1), \dots, g(s)$ and a shift $\delta' = \delta/s$, compute $g(\delta'), g(\delta'+1), \dots, g(\delta'+d)$.

Divide and conquer

 Let's consider how to compute $R(z)$. For convenience, we denote that $$ \begin{aligned} R_B(z) = & P(z+1)Q(z+2)Q(z+3) \dots Q(z+B) + \\\ & P(z+1)P(z+2)Q(z+3) \dots Q(z+B) + \\\ & \dots + \\\ & P(z+1)P(z+2)P(z+3) \dots P(z+B), \end{aligned} $$ $$ P_B(z) = P(z+1)P(z+2) \dots P(z+B), $$ $$ Q_B(z) = Q(z+1)Q(z+2) \dots Q(z+B), $$ where $B$ indicates the number of elements in the product. We need to compute the values of $$ \begin{matrix} R_B(0), & R_B(s), & \dots, & R_B(sB), \\\ P_B(0), & P_B(s), & \dots, & P_B(sB), \\\ Q_B(0), & Q_B(s), & \dots, & Q_B(sB). \end{matrix} $$

To compute these values recurrently, we should notice that $$ R_{2B}(z) = R_B(z) Q_B(z+B) + P_B(z) R_B(z+B), $$ $$ P_{2B}(z) = P_B(z) P_B(z+B), $$ $$ Q_{2B}(z) = Q_B(z) Q_B(z+B). $$ We choose $P_{2B}(z)$ as an example. Here we need to compute $$ \begin{aligned} P_{2B}(0) & = P_B(0) P_B(B), \\\ P_{2B}(s) & = P_B(s) P_B(s+B), \\\ \dots, \\\ P_{2B}(sB) & = P_B(sB) P_B(sB+B), \\\ P_{2B}(sB+1) & = P_B(sB+1) P_B(sB+B+1), \\\ \dots, \\\ P_{2B}(2sB) & = P_B(2sB) P_B(2sB+B). \end{aligned} $$ There are $4B$ values of $P_B(z)$ that are needed, which are $$ \begin{matrix} P_B(0), & P_B(s), & \dots, & P_B(sB), \\\ P_B(B), & P_B(B+s), & \dots, & P_B(B+sB), \\\ P_B(sB), & P_B(sB+s), & \dots, & P_B(sB+sB), \\\ P_B(B+sB), & P_B(B+sB+s), & \dots, & P_B(B+sB+sB). \end{matrix} $$ The first line is our target and the rest three lines can be obtained by shifting the first line by $B$, $sB$ and $B+sB$, respectively. Let $T(d)$ be the complexity where $d$ is the degree of our polynomials, then $$ T(d) = T(d/2) + O(d \log d). $$ Hence, $T(d) = O(d \log d)$.

 In our case, $d = O(\sqrt N)$, then the complexity is reduced to $O(\sqrt N \log N + m \sqrt N)$.

Conclusion

 We use the trick, SQRT decomposition, to split summations into blocks, and then use Lagrange interpolation and multi-point evaluation to compute the value in each block. We obtain an algorithm with complexity $O(\sqrt N \log^2 N + m \sqrt N)$.

 A more subtle trick to save a $\log N$ is obtained by the shifting technique, which yields a faster algorithm with complexity $O(\sqrt N \log N + m \sqrt N)$. The constant factor of Lagrange interpolation and multi-point evaluation is very large, so this approach to save a $\log N$ brings a significant improvement.

 However, we allow suboptimal solutions that directly use Lagrange interpolation and multi-point evaluation to get AC.

Credits

 Some related problems: 

1. Stopping time: [1349D](https://codeforces.com/problemset/problem/1349/D), [850F](https://codeforces.com/contest/850/problem/F), [1025G](https://codeforces.com/problemset/problem/1025/G).
2. Generating function: [SPOJ FACTMODP](https://codeforces.com/https://www.spoj.com/problems/FACTMODP/), [CodeChef QPOLYSUM](https://codeforces.com/https://www.codechef.com/problems/QPOLYSUM), [1349F2](https://codeforces.com/problemset/problem/1349/F2).
 **Solution**[106873892](https://codeforces.com/contest/1479/submission/106873892 "Submission 106873892 by liouzhou_101")

