# Tutorial_(en)

I hope you enjoyed the round. 

While problem D1B was good for balance in Div1, it was too hard for balance in Div2. I apologize for this.

Problem D1B = D2D is by [dario2994](https://codeforces.com/profile/dario2994 "International Grandmaster dario2994"). Other problems are mine.

 **D2A**
### [1686A - Everything Everywhere All But One](https://codeforces.com/contest/1686/problem/A "Codeforces Round 794 (Div. 2)")

Suppose that we did one operation and not all numbers are equal. Let's say that we have n−1 numbers x and 1 number y now, with x≠y. 

In the next operation, we have two options: to make operation with n−1 numbers x, or with n−2 of x and one y. If we go with the first option, we will still have n−1 of x and one y: numbers won't change. If we go with the second option, we will have one number x and n−1 numbers (n−2)x+yn−1, where (n−2)x+yn−1=x+y−xn−1≠x. So, we again are in a state where we have n−1 copies of one number and one different number. 

So, if after the first operation not all numbers are equal, they will never be all equal. Therefore, it's enough to check each possible operation in O(n2) (which can be clearly optimized to O(n)).

And go watch the movie Everything Everywhere All At Once, it's fantastic!

 **D2B**
### [1686B - Odd Subarrays](https://codeforces.com/contest/1686/problem/B "Codeforces Round 794 (Div. 2)")

Consider any optimal splitting.

Clearly, for any subarray $[b_1, b_2, \ldots, b_m]$ which is not odd, we can just split it into $[b_1], [b_2], \ldots, [b_m]$,

For any odd subarray $[b_1, b_2, \ldots, b_m]$ with $m \ge 3$, there exists an $1 \le i \le m-1$ such that $b_i > b_{i+1}$ (otherwise $b$ is sorted and has no inversions). Then, we can split $b$ into $[b_1], [b_2], \ldots, [b_{i-1}], [b_i, b_{i+1}], [b_{i+2}], \ldots, [b_m]$, where we also have one odd subarray.

So, if we can split $p$ into several subarrays such that there are $k$ odd subarrays, we can split it into several subarrays of length $\le 2$ so that there are $k$ odd subarrays too. Then, let $dp_i$ denote the largest number of odd subarrays we can get from splitting $p[1:i]$. Then, $dp_i = max(dp_{i-1}, dp_{i-2} + (p_{i-1} > p_i))$. This $dp$ can be calculated in $O(n)$.

It's also easy to show that the following greedy algorithm works: traverse the permutation from left to right, whenever you see two elements $p_{i-1}>p_i$, make a subarray $[p_{i-1}, p_i]$, and proceed from $p_{i+1}$.

 **D2C/D1A**
### [1685A - Circular Local MiniMax](../problems/A._Circular_Local_MiniMax.md "Codeforces Round 794 (Div. 1)")

Let's call $b_i$ local minimum if $b_{i-1} > b_i < b_{i+1}$ and local maximum if $b_{i-1} < b_i > b_{i+1}$. It's clear that in the arrangement satisfying the conditions from the statement, if $b_i$ is a local minimum, $b_{i+1}$ is a local maximum, and vice versa. Local minimums and local maximums will be alternating.

Then it's easy to see that such an arrangement can't exist for odd $n$. Indeed, suppose that the conditions from the statement are satisfied for $b_1, b_2, \ldots, b_n$. If we suppose that $b_1$ is local minimum, we get that $b_2$ is local maximum, $b_3$ is local minimum, $\ldots, $, $b_n$ is local minimum, $b_1$ is local maximum. Clearly, $b_1$ can't be a local maximum and a local minimum at the same time, leading to a contradiction.

Let's now consider the case of even $n = 2m$. Sort the array $a$, so that $a_1 \le a_2 \le \ldots \le a_{2m}$. Let's show that if $a_i = a_{i + m - 1} = x$ for some $2 \le i \le m-1$, then there is no arrangement satisfying the conditions from the statement. Indeed, consider such an arrangement: we have $m$ numbers $x$, and no two of them can be adjacent, so they occupy every second position. In addition, as local maximums and local minimums are alternating, we get that all $x$ are local maximums or all $x$ are local minimums. The first would imply that $a_{2m} < x$, which isn't possible. The second would imply that $a_1 > x$, which isn't possible.

It turns out that if there is no such $i$, the arrangement exists. Indeed, we can arrange numbers on the circle in the following order: $(a_1, a_{m+1}, a_2, a_{m+2}, \ldots, a_m, a_{2m})$. Here $a_k < a_{m + k} > a_{k+1}$ for $1 \le k \le m-1$, $a_{m+k} > a_{k+1} < a_{m+k+1}$ for $1 \le k \le m-1$, $a_{2m} > a_1 < a_{m+1}$ and $a_m < a_{2m} > a_1$.

 **D2D/D1B**
### [1685B - Linguistics](../problems/B._Linguistics.md "Codeforces Round 794 (Div. 1)")

For the answer to be $\texttt{YES}$ the frequency of the character $\texttt{A}$ in the $a+b+c+d$ words must coincide with its frequency in the sentence $s$, which is equivalent to the condition $a + c + d = \\#\{i:\, s_i = \texttt{A}\}$. From now on we may assume that this is true.

Notice that the answer to the problem is $\texttt{YES}$ if and only if it is possible to tile the string $s$ with $c$ copies of $\texttt{AB}$ and $d$ copies of $\texttt{BA}$ so that all the $c+d$ substrings are disjoint. Indeed one can simply fill the remaining characters of $s$ with the $a$ copies of $\texttt{A}$ and the $b$ copies of $\texttt{B}$ (we are sure that the number of characters $\texttt{A}$ and $\texttt{B}$ is correct because of the initial check). Moreover, if $s_i = s_{i+1}$, then clearly any tiling with $\texttt{AB}$ and $\texttt{BA}$ of $s$ cannot cover with a single tile both $s_i$ and $s_{i+1}$; therefore we can split the string $s$ between $s_i$ and $s_{i+1}$ and try to tile the two resulting substrings. By repeating this argument we will end up with many alternating strings (a string $t$ is alternating if $t_{i} \not= t_{i+1}$ for all $1\le i < |t|$). So, we have reduced the problem to the following one:

Subproblem: You are given many alternating strings, can you find in these strings $c$ substrings equal to $\texttt{AB}$ and $d$ subtrings equal to $\texttt{BA}$ such that all the $c+d$ substrings are disjoint?

In order to solve the problem let us analyze what happens when only one alternating string is present. Given an alternating string $t$, we say that the pair $(x, y)$ is valid if we can find in $t$ $x$ substrings equal to $\texttt{AB}$ and $y$ substrings equal to $\texttt{BA}$ so that the $x+y$ substrings are disjoint. Let us consider various cases: 

1. If $|t|=2k+1$, then $(x, y)$ is valid if and only if $x + y \le k$. Let $f(k):=\{(x, y):\, 0\le x,y\text{ and } x + y\le k\}$.
2. If $|t|=2k$ and $t_1 = \texttt{A}$, then $(x, y)$ is valid if and only if $x+y\le k-1$ or $(x, y) = (k, 0)$. Let $f_{AB}(k):= \{(k, 0)\}\cup f(k-1)$.
3. If $|t|=2k$ and $t_1 = \texttt{B}$, then $(x, y)$ is valid if and only if $x+y\le k-1$ or $(x, y) = (0, k)$. Let $f_{BA}(k):= \{(0, k)\}\cup f(k-1)$.

 Loosely speaking, the alternating strings of type 2. and 3. have a bonus if they are tiled only with one of the strings $\texttt{AB}$ and $\texttt{BA}$.We will provide a proof for the correcteness of the following greedy algorithm.

Greedy algorithm: Sort the strings of type $2$ by length and fill them, starting from the shortest, only with $\texttt{AB}$ (i.e., find as many disjoint copies of $\texttt{AB}$ as possible) until you reach $c$ or you finish them (a string of length $2k$ is filled with $k$ $\texttt{AB}$). Do the same for the strings of type $3$ for the word $\texttt{BA}$. At this point there are no more bonuses to use and you can just fill the remaining strings with $\texttt{AB}$ and $\texttt{BA}$ in the only reasonable way. If in the end, if you have found $c$ strings $\texttt{AB}$ and $d$ strings $\texttt{BA}$ then the answer is $\texttt{YES}$, otherwise it is $\texttt{NO}$.

Let us provide a proof of the correctness of this algorithm. Let us remark that the proof of the correctness is in fact rather easy, but a bit cumbersome to write down. The strategy of the proof is to start from a solution and to show that the one constructed by the greedy algorithm is "better".

Proof of the correctness of the greedy algorithm: Let $U, V, W$ be the multisets of lengths of strings of the first, second and third type respectively (according to the case division above). Then the problem is equivalent to understanding if $$ (c, d) \in \sum_{u\in U} f(u) + \sum_{v\in V} f_{AB}(v) + \sum_{w\in W} f_{BA}(w). $$

Assume that the answer is $\texttt{YES}$ and consider a solution of the problem, i.e. a choice of a valid pair for each of the $|U|+|V|+|W|$ alternating strings. Let $V = V'\sqcup V' '$ where $V'$ corresponds to the lengths of the strings in $V$ where the valid pair of the solution is given by $(k, 0)$ ($k$ is the length of the string). Partition $W=W'\sqcup W' '$ analogously. Then we have $$ (c, d) \in \sum_{u\in U} f(u) + \sum_{v'\in V'} (v', 0) + \sum_{v' '\in V' '} f(v' ' - 1) + \sum_{w'\in W'} (0, w') + \sum_{w' '\in W' '} f(w' ' - 1) . $$

Let us make a couple of observations: 

* For any $k_1, k_2$ it holds $f(k_1) + f(k_2) = f(k_1 + k_2)$.
* If $k_1\le k_2$, then $f(k_1) + (k_2, 0) \subseteq (k_1, 0) + f(k_2)$ and also $f(k_1) + (0, k_2) \subseteq (0, k_1) + f(k_2)$.

 Thanks to the second observation we know that we may assume (up to changing the solution to a better one) that $V'$ contains the smaller elements of $V$ (i.e., $v'\le v' '$ for each $v'\in V', v' '\in V' '$), and $W'$ contains the smaller elements of $W$. Then, applying the first observation, we reduce the problem to understanding if there is prefix $V'$ of $V$ (prefix in the sorted by length order) and a prefix $W'$ of $W$ such that $$ \tag{$\star$} (c, d) \in f\Bigg(\sum_{u\in U} k + \sum_{v' '\in V\setminus V'} (v' ' - 1) + \sum_{w' '\in W\setminus W'} (w' ' -1)\Bigg) + \bigg(\sum_{v'\in V'} v', 0\bigg) + \bigg(0, \sum_{w'\in W'} w'\bigg). $$ It remains to show that we may assume that $V'$ is the largest prefix so that $\sum V':= \sum_{v'\in V'}v' \le c$ (and the analogous result for $W'$) as this implies the correctness of the greedy algorithm (i.e., if there is a valid solution then the one constructed by the algorithm is a solution). Assume, by contradiction, that there is $v' '\not\in V'$ such that $v' ' + \sum V' \le c$. By $(\star)$ we know $$ \Big(c-\sum V', d-\sum W'\Big) \in f(s),$$ where $s=\sum_{u\in U} k + \sum_{v' '\in V\setminus V'} (v' ' - 1) + \sum_{w' '\in W\setminus W'} (w' ' -1)$. Thus, we deduce $$ \Big(c-(\sum V' + v' '), d-\sum W'\Big) \in f(s-(v' '-1)),$$ which is equivalent to saying that ($\star$) holds also if we replace $V'$ with $V'\cup\{v' '\}$ which is exactly what we wanted to prove **D2E/D1C**
### [1685C - Bring Balance](../problems/C._Bring_Balance.md "Codeforces Round 794 (Div. 1)")

Let's denote ( by $1$ and ) by $-1$. Then we need to achieve a sequence in which all prefix sums are nonnegative.

Let our sequence be $a_1, a_2, \ldots, a_{2n}$, and denote $pref_i = a_1 + a_2 + \ldots + a_i$ for each $0 \le i \le 2n$.

Key observation: It's always possible to get a balanced sequence in at most $2$ operations.

Proof: Let $0 \le i \le 2n$ be the index for which the value of $pref_i$ is the largest (if there are several such $i$, choose any). Let's reverse segments $a[1:i]$ and $a[i+1:2n]$, getting sequence $a_i, a_{i-1}, \ldots, a_1, a_{2n}, a_{2n-1}, \ldots, a_{i+1}$.

It's easy to show that this sequence is balanced. $a_i + a_{i-1} + \ldots + a_j = pref_i - pref_{j-1} \ge 0$ for any $j \le i$, and $a_j + a_{j-1} + \ldots + a_{i+1} = pref_j - pref_i \le 0$ for any $j \ge i$, so $a_i + a_{i-1} + \ldots + a_i + a_{2n} + \ldots + a_{j+1} = -(a_j + a_{j-1} + \ldots + a_{i+1}) \ge 0$ for any $j \ge i$. So, all prefix sums are nonnegative, as desired.

It remains to check if we can make our sequence balanced in less than $2$ operations.

Checking if $0$ operations are enough is trivial: just check if the initial sequence is balanced. Now, let's check if we can make the sequence (which initially isn't balanced) balanced in exactly one operation.

Let $l$ be the smallest index for which $pref_l < 0$, and $r$ be the largest such index. Suppose that we will reverse the segment $a[L:R]$. Clearly, $L \le l$, as otherwise, we would have a negative prefix sum. Similarly $R > r$. After reversing, we need to worry only about the $i$-th prefix sum for each $i$ from $L$ to $R-1$, all others will be nonnegative.

The $i$-th prefix sum for such $i$ will be equal to $pref_{L-1} + (pref_R - pref_{R + L - 1 - i})$. So, segment $[L, R]$ will be good iff $pref_{L-1} + pref_R \ge pref_i$ for all $L -1 \le i \le R$.

It's easy to show that if any such segment $[L, R]$ works, then also the segment $[L_1, R_1]$ works, where $L_1$ is the index from $[0, l]$ for which $pref_{L_1}$ is the largest, and $R_1$ is the index from $[r+1, 2n]$ for which $pref_{R_1}$ is the largest. Indeed, suppose that there is some $L_1 \le i \le R_1$ such that $pref_{L_1} + pref_{R_1} < pref_i$. If $i \le l$, then $pref_i < pref_{L_1}$, contradiction. If $i > r$, then $pref_i < pref_{R_1}$, contradiction. If $l < i \le r$, then $i$ is inside any such segment $[L, R]$, and $pref_i > pref_L + pref_R$ for any choice of $L, R$.

So, it's enough to choose segment $[L_1, R_1]$ and to check if the sequence becomes balanced after reversing it.

 **D2F/D1D1**
### [1685D1 - Permutation Weight (Easy Version)](../problems/D1._Permutation_Weight_(Easy_Version).md "Codeforces Round 794 (Div. 1)")

Let's first understand what is the minimum possible weight of $q$. When can it be $0$?

Only when $q_i = p_{q_{i+1}}$ for each $i$. Clearly, such $q$ exists only when $p$ is just one cycle. This gives a hint that we should look at cycles.

Consider splitting of $p$ into cycles (where a cycle is an array $[a_1, a_2, \ldots, a_m]$ such that $p_{a_i} = a_{i \bmod m +1}$ for $1 \le i \le m$). Let's say there are $k$ of such cycles. I claim that the answer is $2(k-1)$. You can see the proof in the tutorial of the hard version of this problem.

Now, let's provide an example. We will construct a permutation $p'$ as follows: 

* Initially, it's equal to $p$
* Then, for each $x$ from $1$ to $n-1$, if $x$ and $x+1$ are in different cycles in $p'$ currently, swap them.

One such swap reduces the number of cycles by exactly $1$, so we will do exactly $k-1$ such swaps and $p'$ will consist of exactly one cycle. 

Next, construct $q$ by the rule $q_i = p'_{q_{i+1}}$ (it's possible as $p'$ is just one cycle). As $|q_i - p_{q_{i+1}}| = |p'_{q_{i+1}} - p_{q_{i+1}}|$, the weight of $q$ is just the sum of $|p_i - p'_i|$. Clearly, one swap increases this value by at most $2$, so in the end it will be at most $2(k-1)$, as desired.

 **D1D2**
### [1685D2 - Permutation Weight (Hard Version)](../problems/D2._Permutation_Weight_(Hard_Version).md "Codeforces Round 794 (Div. 1)")

We will start by proving that the weight is at least $2(k-1)$ (where $k$ is the number of cycles), and understanding the structure of optimal permutations in the process.

Again, consider splitting of $p$ into cycles (where a cycle is an array $[a_1, a_2, \ldots, a_m]$ such that $p_{a_i} = a_{i \bmod m +1}$ for $1 \le i \le m$). Let's say there are $k$ of such cycles.

Now, consider a graph $G$ on $n$ nodes, and draw an edge from $q_i$ to $p_{q_{i+1}}$ for each $i$ from $1$ to $n$ (there may be self-loops and multi-edges here). Each node has one incoming and outgoing edge, so the entire graph is split into several cycles. Consider any such cycle $(b_1, b_2, \ldots, b_m)$, where all $b_i$ are distinct. Its contribution to the answer is $|b_1 - b_2| + |b_2 - b_3| + \ldots + |b_m - b_1|$. We will show that:

* This value is at least $2(m-1)$.

Proof: Wlog $b_i$ is the smallest among $b$ and $b_j$ is the largest, with $i<j$. Then $|b_1 - b_2| + |b_2 - b_3| + \ldots + |b_m - b_1| = (|b_i - b_{i+1}| + \ldots + |b_{j-1} - b_j|) + (|b_j - b_{j+1}| + \ldots + |b_{i-1} - b_i|) \ge $ $\le 2|b_i - b_j| \ge 2(m-1)$.
* It's $2(m-1)$ only when the numbers on the cycle are some $m$ consecutive numbers and are increasing on the path from the smallest number to the largest and decreasing on the way back.

Proof: It's just the case when all the inequalities in the expression above become equalities.

Now, assign each cycle of $p$ a number from $1$ to $k$ and consider the graph $G_1$ on $k$ nodes, draw an edge between the nodes corresponding to the cycles where $q_i$ and $p_{q_{i+1}}$ belong. As $q_i$ and $p_{q_i}$ are in the same cycle for each $i$, we get that every two consecutive edges we draw share a node. As we will draw an edge from every cycle, the graph is connected.

Each edge in $G_1$ corresponds to an edge in $G$ (edge between $q_i$ and $p_{q_{i+1}}$ in $G$ corresponds to an edge in $G_1$ between the nodes corresponding to the cycles where $q_i$ and $p_{q_{i+1}}$ belong).

Now, consider any spanning tree in graph $G_1$. Clearly, any cycle of length $m$ in $G_1$ can contain at most $m-1$ edges from it (if it contained $m$ edges from it, we would have a cycle in $G_1$). So, the total sum of $(m-1)$ over all cycles in $G$ is at least $k-1$, and therefore the total contribution to the weight is at least $2(k-1)$.

Now let's give a characterization of all permutations $q$ which have the weight $2(k-1)$. It turns out, that they are in correspondence with graphs $G$ on $n$ nodes which satisfy the following conditions: 

* Each node has one incoming and one outgoing edge (and therefore graph is split into cycles).
* In $G$, if a cycle has length $m$, then it consists of $m$ consecutive integers, where numbers go up from the smallest number to the largest and down on the way back
* The sum of $m-1$ over all cycles is precisely $k-1$.
* If we draw an edge between two cycles of $p$ if an element of the first cycle is connected to the element of the second cycle in $G$, this graph on $k$ nodes is connected.

Each such graph is a corresponding graph of some optimal permutation $q$. The proof is left for the reader as an exercise.

Now, how to solve our problem? Let's build $q$ element by element. The weights of all cyclic shifts of the same permutation are the same, so we start with $q_1 = 1$. Now, the only subproblem we have to be able to solve is to check if the current prefix $q$ of length $l$ is a prefix of some permutation with weight $2(k-1)$. So, we have to check if our current $l-1$ edges $q_i \to p_{q_{i+1}}$ can be a subset of some graph $G$ satisfying all the conditions above.

Denote these edges $(u_1, v_1), \ldots, (u_{l-1}, v_{l-1})$. If edge has $u_i<v_i$, consider segment $[l_i, r_i] = [u_i, v_i]$, and call it right segment. If edge has $u_i>v_i$, consider segment $[l_i, r_i] = [v_i, u_i]$, and call it left segment. If $u_i = v_i$, call $u_i$ loop node.

We can show that the following criteria are sufficient:

* No two right segments intersect internally.
* No two left segments intersect internally.
* No right/left segment contains a loop node.
* Consider a graph on $k$ nodes, corresponding to the cycles of $p$. For each $1 \le i \le n-1$, if $[i, i+1]$ is contained in some segment, draw an edge between the corresponding cycles in which $i$, $i+1$ are. Then, this graph can't have a cycle (has to be a forest).
* Consider a graph on $k$ nodes, corresponding to the cycles of $p$. For each $1 \le i \le n-1$, unless $i$ or $i+1$ are loop nodes, or $i$ is the right end of two segments, or $i+1$ is the left end of two segments, draw an edge between the corresponding cycles in which $i$, $i+1$ are. Then, this graph must be connected.

These conditions may sound complicated but they are very simple implications of the conditions on $G$ above. The proof that if these conditions are satisfied then edges form a subset of some valid $G$ is left to the reader as an exercise too (tutorial is already too long, sorry).

Total complexity is $O(n^3)$, as we can do up $O(n^2)$ checks, and each check takes $O(n)$ time.

 **D1E**
### [1685E - The Ultimate LIS Problem](../problems/E._The_Ultimate_LIS_Problem.md "Codeforces Round 794 (Div. 1)")

Consider element $n+1$. Replace for a while $n+1$ by $0$, each element $\le n$ by $-1$, and each element $\ge n+2$ by $1$. It's well-known that for an array of $n$ of $1$ and $n$ of $-1$ there exists a cyclic shift such that all its prefix sums are nonnegative (which is equivalent to the sequence of these $1$s and $-1$s being balanced). Consider such cyclic shift for our array. 

It's easy to see now that in this cycle there is no increasing subsequence of length at $n+1$ of element distinct from $n+1$. Indeed, in such a subsequence we would have $t$ of $-1$s, and then $n + 1 - t$ of $1$s, which would mean that $t$-th $1$ goes after the $t$-th $-1$, meaning that the subsequence isn't balanced. 

So, if there is an increasing subsequence of length $n+1$ in this shift, $n+1$ is in it.

Let's say there are $t$ elements $\le n$ before $n+1$ in this subsequence and $n - t$ elements $\ge n$ after $n+1$ in this subsequence. As $t$-th $1$ goes before $t$-th $-1$ in this shift, we get that there are exactly $t$ elements $\ge n+2$ in this shift before $n+1$, and (similarly) exactly $n-t$ elements $\le n$ in this shift after $n+1$. In addition, these two parts form (as ones and minus ones) two separate balanced sequences.

Now, consider a shift in which $n+1$ is the first element. It's easy to see that if the condition above holds, then in this shift ones and minus ones also form a balanced subsequence. If $LIS$ of this shift is $n+1$, it must be the case that $n+1$ and $n$ ones form it, which implies that elements $n+1, n+2, \ldots, 2n+1$ go clockwise in this permutation.

Similarly, after considering a shift in which $n+1$ is the last element, we get that elements $1, 2, \ldots, n+1$ go clockwise in this permutation.

It turns out that if all the conditions above hold, then all shifts have $LIS \ge n+1$. Indeed, consider any shift, elements to the left of $n+1$ smaller than $n+1$, $n+1$, and elements to the right of $n+1$ larger than $n+1$ form an increasing subsequence. From the fact that $1$s and $-1$s are balanced we get that numbers smaller than $n+1$ take at least half of the space before $n+1$, and larger than $n+1$ take at least half of the space after $n+1$, so its length is at least $n+1$.

With all this knowledge, how do we solve the problem?

We will keep track of all the $1$s and $-1$s with a segment tree, with queries "smallest prefix sum on the subsegment". When we need to provide the answer after the update, we will do the following:

* Check if the circular segment from $n+1$ to $n+1$ is balanced. If not, find the shift that makes $1$s and $-1$s balanced, its $LIS$ is at most $n$.
* Then, check if $n+1, n+2, \ldots, 2n+1$ go clockwise in the permutation. If not, then the shift in which $n+1$ is the first element has $LIS\le n$.
* Then, check if $1, 2, \ldots, n+1$ go clockwise in the permutation. If not, then the shift in which $n+1$ is the last element has $LIS\le n$.
* Otherwise, output $-1$.

We check if $1, 2, \ldots, n+1$ go clockwise by saving the following sum: $$\sum_{i = 1}^{n} (pos(i\bmod (n+1) + 1) - pos(i))\bmod (2n+1)$$

If it's $2n+1$, they go clockwise, else not. We can update this sum in $O(1)$ per query.

Total complexity is $O(\log(n))$ per query.

