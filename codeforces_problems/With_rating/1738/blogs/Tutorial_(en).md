# Tutorial_(en)

[1738A - Glory Addicts](../problems/A._Glory_Addicts.md "Codeforces Global Round 22")

Author: [Milesian](https://codeforces.com/profile/Milesian "Master Milesian")

 **Tutorial**
### [1738A - Glory Addicts](../problems/A._Glory_Addicts.md "Codeforces Global Round 22")

Suppose the first skill to be performed is fixed. Then it is optimal to use the following greedy strategy. 

* If possible, perform a skill of a different type from the last skill. If there are multiple skills of a different type from the last skill, choose the one with the largest initial damage.

Inspired by the above observation, if the type of the first skill is fixed, it is optimal to choose the one with the smallest initial damage. This is because the first skill will be never doubled. 

Therefore, we have the following algorithm. 

1. Try each possible type $a$ (of the first skill).
2. Remove the skill of type $a$ with the smallest intial damage.
3. Alternate the types of the following skills as much as possible.

This algorithm is sufficient to pass this problem. Nevertheless, a slightly more elegant analysis will give a simpler solution. 

1. If the number of skills of type fire is equal to that of skills of type frost, double the damage of all skills except for the one with the smallest initial damage.
2. Otherwise, let $k$ be the smaller number of skills of either type, then double the damage of the largest $k$ skills of both types.

The time complexity is $O(n \log n)$ due to sortings.

 **Solution**[174164839](https://codeforces.com/contest/1738/submission/174164839 "Submission 174164839 by liouzhou_101")

[1738B - Prefix Sum Addicts](../problems/B._Prefix_Sum_Addicts.md "Codeforces Global Round 22")

Author: [liouzhou_101](https://codeforces.com/profile/liouzhou_101 "Grandmaster liouzhou_101")

 **Tutorial**
### [1738B - Prefix Sum Addicts](../problems/B._Prefix_Sum_Addicts.md "Codeforces Global Round 22")

If $k = 1$, it is always possible, so the answer is "YES".

In the following, we assume that $k \geq 2$. Here, we are given $s_{n-k+1}, \dots, s_n$. We can resume $a_{n-k+2}, \dots, a_{n}$ by letting $a_{i} = s_{i} - s_{i-1}$ for every $n-k+2 \leq i \leq n$.

If the known elements of $a_i$ cannot form a sorted array, i.e., it does not hold that $a_{n-k+2} \leq \dots \leq a_n$, the answer is "NO".

Note that the sum of the first $n-k+1$ elements of $a_i$ should satisfy that $s_{n-k+1} = a_1 + \dots + a_{n-k+1} \leq (n-k+1) a_{n-k+2}$. If this does not hold, the answer is "NO".

Having checked that both $a_{n-k+2} \leq \dots \leq a_n$ and $s_{n-k+1} \leq (n-k+1) a_{n-k+2}$ hold, we claim that the answer is "YES". A possible solution could be $$ a_i = \begin{cases} \left\lfloor\dfrac{s_{n-k+1}}{n-k+1}\right\rfloor, & 1 \leq i \leq s_{n-k+1} \bmod (n-k+1), \\\ \left\lceil\dfrac{s_{n-k+1}}{n-k+1}\right\rceil, & s_{n-k+1} \bmod (n-k+1) < i \leq n-k+1. \end{cases} $$

 **Solution**[174164900](https://codeforces.com/contest/1738/submission/174164900 "Submission 174164900 by liouzhou_101")

[1738C - Even Number Addicts](../problems/C._Even_Number_Addicts.md "Codeforces Global Round 22")

Author: [liouzhou_101](https://codeforces.com/profile/liouzhou_101 "Grandmaster liouzhou_101")

 **Tutorial**
### [1738C - Even Number Addicts](../problems/C._Even_Number_Addicts.md "Codeforces Global Round 22")

We only need to consider the case that $a_i =$ 0 or 1.

Suppose there are $a$ 0's and $b$ 1's in total. Consider the following cases:

* $b \equiv 2 \pmod 4$. Bob has a winning strategy: Always choose the number that Alice chooses in her last move. This strategy keeps the invariant that Alice and Bob have the same number of 1's after Bob's each move. The only exception that Bob cannot go on with this strategy is that Alice takes the last 0. In this case, there must be an even number of 1's (and no 0's) remaining. Therefore, each of Alice and Bob will choose half of the remaining 1's. At last, Alice and Bob have the same number $b/2$ of 1's, which is odd.
* $b \equiv 3 \pmod 4$. Alice has a winning strategy: Choose 1 first. After this move, the game is reduced to $a$ 0's and $b-1$ 1's with Bob taking the first turn and Bob wins if he has an even number of 1's at last. This reduced game is indeed the case of $b \equiv 2 \pmod 4$ which we have already proved that Bob always loses.
* $b \equiv 0 \pmod 4$. Alice has a winning strategy: Choose 0 first; after that, choose the number that Bob chooses in his last move. This strategy keeps the invariant that Alice and Bob have the same number of 1's after Alice's each move. The only exception that Alice cannot go on with this strategy is that there is no 0. In this case, there must be an even number of 1's (and no 0's) remaining. Therefore, each of Alice and Bob will choose half of the remaining 1's. At last, Alice and Bob have the same number $b/2$ of 1's, which is even.
* $b \equiv 1 \pmod 4$. If any of Alice and Bob chooses the first 1, the game is reduced to $a$ 0's and $b-1$ 1's with its opponent moving first, resulting in the case of $b \equiv 0 \pmod 4$ and its opponent wins. Therefore, the one who chooses the first 1 loses. With this observation, Alice will lose if there are an even number of $0$'s, i.e., $a \equiv 0 \pmod 2$; and Alice will win if $a \equiv 1 \pmod 2$.
 **Solution**[174164993](https://codeforces.com/contest/1738/submission/174164993 "Submission 174164993 by liouzhou_101")

DP: [174167046](https://codeforces.com/contest/1738/submission/174167046 "Submission 174167046 by liouzhou_101")

[1738D - Permutation Addicts](../problems/D._Permutation_Addicts.md "Codeforces Global Round 22")

Author: [Milesian](https://codeforces.com/profile/Milesian "Master Milesian")

 **Tutorial**Tutorial is loading... **Solution**[174165259](https://codeforces.com/contest/1738/submission/174165259 "Submission 174165259 by liouzhou_101")

[1738E - Balance Addicts](../problems/E._Balance_Addicts.md "Codeforces Global Round 22")

Author: [Milesian](https://codeforces.com/profile/Milesian "Master Milesian")

 **Tutorial**
### [1738E - Balance Addicts](../problems/E._Balance_Addicts.md "Codeforces Global Round 22")

Let $f(i, j)$ be the answer to the problem for the subsequence $a_i, a_{i+1}, \dots, a_j$. And we want to find $f(1, n)$. 

For every $1 \leq i \leq j \leq n$, we consider the following cases. 

1. $a_i = \dots = a_j = 0$. In this case, every partition produces a balanced sequence, thereby $f(i, j) = 2^{j-i}$.
2. $a_i = a_j = 0$. In this case, suppose that there are $x$ prefix $0$'s and $y$ suffix $0$'s in $a_i, \dots, a_j$ with $x, y \geq 1$. There can be at most $\min\{x, y\}$ zeros in both the prefix and suffix of the balanced sequence. There are $$ c_{x,y} = \sum_{k=0}^{\min\{x,y\}} \binom{x}{k} \binom{y}{k} $$ choices in total. So $f(i,j) = c_{x,y} f(i+x, j-y)$.
3. Otherwise, find the leftmost position $i \leq l \leq j$ and the rightmost position $i \leq r \leq j$ such that $a_i + \dots + a_l = a_r + \dots + a_j > 0$.
	1. $l = j$. We have $f(i, j) = 1$.
	2. $a_{l+1} = \dots = a_{r-1} = 0$. There are $2^{r-l}$ possible choices to make the sequence balanced. So $f(i, j) = 2^{r-l}$.
	3. Otherwise, suppose there are $x$ prefix $0$'s and $y$ suffix $0$'s in $a_{l+1}, \dots, a_{r-1}$. One can cut both parts with sum $a_i + \dots + a_l = a_r + \dots + a_j$. The number of choices to cut out $k$ $0$'s in the balanced sequence is $$ \binom{x+1}{k+1} \binom{y+1}{k+1}. $$ With the case of no cut considered, we have $$ f(i, j) = \left( \sum_{k=0}^{\min\{x,y\}} \binom{x+1}{k+1} \binom{y+1}{k+1} + 1 \right) f(l+x+1, r-y-1) = c_{x+1, y+1} f(l+x+1, r-y-1). $$

Since every element is processed once, it is clear that the time complexity is $O(n)$. 

 **Solution**[174165357](https://codeforces.com/contest/1738/submission/174165357 "Submission 174165357 by liouzhou_101")

[1738F - Connectivity Addicts](../problems/F._Connectivity_Addicts.md "Codeforces Global Round 22")

Author: [liouzhou_101](https://codeforces.com/profile/liouzhou_101 "Grandmaster liouzhou_101")

 **Tutorial**
### [1738F - Connectivity Addicts](../problems/F._Connectivity_Addicts.md "Codeforces Global Round 22")

Let's consider the following BFS-like algorithm.

* Repeat the following procedure until all vertices are visited.
	1. Choose an unvisited vertex $u$ with the largest degree. Let $S$ be a set of vertices, initially consisting of the only vertex $u$.
	2. For every neighbor vertex $v$ of vertex $u$,
		+ If vertex $v$ is visited, color all vertices in $S$ with the same color as vertex $v$, and then end the procedure this time;
		+ Otherwise, add vertex $v$ to set $S$.
	3. Color all vertices in $S$ with a new one color.

It is clear that in each repetition of the procedure, the number $k$ of edges visited (i.e., the number of queries) will cause at least $k$ vertices being colored. Since all vertices will be colored exactly once eventually, the number of queries is no more than $n$. A careful analysis will find that the number of queries is no more than $n-C$, where $C$ is the number of different existing colors.

The time complexity of this algorithm can be $O(n)$, $O(n\log n)$, or $O(n^2)$, depending on concrete implementations. Anyway, any implementation of such time complexity can pass. 

It is clear that all vertices with the same color are connected. It remains to see why this algorithm will color all vertices such that $s_c \leq n_c^2$, where $n_c$ is the number of vertices with color $c$, and $s_c$ is the sum of degrees of vertices with color $c$. To see this, it can be shown by induction that after every repetition of the procedure, the number $n_c$ of vertices with an existing color $c$ is always no less than the degree of any vertex with color $c$. Since we enumerate vertices in decreasing order of their degrees, the degree $d_u$ of the current vertex $u$ must hold that $d_u \leq n_c$ for every existing color $c$. We consider two cases: 

* During the procedure, no neighbor vertex $v$ of vertex $u$ is visited. That is, every neighbor vertex of vertex $u$ has degree $\leq d_u$. Then, there are $d_u + 1$ vertices in $S$, and they are assigned with a new color $c$, thereby $s_c \leq (d_u+1) d_u \leq (d_u+1)^2 = n_c^2$.
* During the procedure, we find a neighbor vertex $v$ of vertex $u$ that is visited. Let $c$ be the color of vertex $v$ and $n'_c$ be the number of vertices with color $c$ before coloring all vertices in $S$. We have $|S| \leq d \leq n'_c$. Let $n_c = n'_c+|S|$ be the number of vertices with color $c$ after coloring all vertices in $S$ with color $c$. Then $s_c \leq s'_c + |S|d \leq (n'_c)^2 + |S|n'_c \leq (n'_c+|S|)^2 = n_c^2$.

 Therefore, it holds that $s_c \leq n_c^2$ for every existing color $c$ after each (and, of course the last) repetition of the procedure. This interesting problem surprisingly comes from non-traditional algorithm scenarios — QUANTUM algorithms.

Further reading: Christoph Dürr, Mark Heiligman, Peter Høyer, and Mehdi Mhalla. Quantum query complexity of some graph problems. SIAM Journal on Computing, 35(6):1310-1328, 2006.

 **Solution**[174165397](https://codeforces.com/contest/1738/submission/174165397 "Submission 174165397 by liouzhou_101")

[1738G - Anti-Increasing Addicts](../problems/G._Anti-Increasing_Addicts.md "Codeforces Global Round 22")

Author: [antontrygubO_o](https://codeforces.com/profile/antontrygubO_o "International Grandmaster antontrygubO_o")

 **Tutorial**
### [1738G - Anti-Increasing Addicts](../problems/G._Anti-Increasing_Addicts.md "Codeforces Global Round 22")

Consider increasing diagonals (sets of cells $(x, y)$ for which $x - y = c$ for some fixed $c$). Clearly, from the diagonal of length $t$, we have to delete at least $\max(0, t - (k-1))$ cells. There are $2$ diagonals of length $i$ for each $i$ from $1$ to $n-1$ and one diagonal of length $n$, so we have to delete at least $2 + 4 + \ldots + 2(n-k) + (n-k+1) = (n-k+1)^2$ cells from them in total. This means that we will delete precisely $\max(0, t - (k-1))$ cells from the diagonal of length $t$.

Now, consider two adjacent diagonals of lengths $t-1$ and $t$ for some $t \ge k$. Let's call diagonal of length $t$ large, and of $t-1$ small. Let's enumerate cells of large diagonal from $1$ to $t$, and of small from $1$ to $t-1$. We have to delete precisely $t-k+1$ cells from large diagonal, and $t-k$ from small. Suppose that the cells deleted from the large diagonal have indexes $1 \le x_1<x_2<\ldots<x_{t-k+1} \le t$. 

For some $1 \le j \le t-k$, consider the path, containing cells from $1$-st to $(x_j-1)$-st in the large diagonal, from $x_j$-th to $(x_{j+1}-1)$-st in the small diagonal, and from $(x_{j+1}+1)$-st to $t$-th in the large diagonal. Note that this is an increasing sequence of cells of length $t-1$, so we have to delete at least $t-k$ cells from it. We deleted precisely $t-k-2$ cells from it in the large diagonal, so we have to delete at least one cell in the small diagonal in the range $[x_j, x_{j+1}-1]$.

Note that the ranges $[x_j, x_{j+1}-1]$ for $1 \le j \le t-k$ don't intersect, and there are $t-k$ of them. So, we have to delete precisely one cell from each such range and not delete any cell outside of $[x_1, x_{t-k+1}-1]$.

Surprisingly, these criteria are sufficient (meaning that for every two adjacent diagonals, the cells in the smaller one are deleted in these ranges determined from the cells deleted in the larger one). Let's first show how to solve the problem based on this and then how to prove that this is sufficient.

If these criteria are indeed sufficient, then let's construct the set of deleted cells one by one (if it exists). 

* How do we choose the first deleted cell on the main diagonal? Just choose the first cell which you can delete.
* How do we choose the first deleted cell on the diagonals adjacent to the main diagonal? Just choose the first cell which you can delete that goes after the deleted cell in the main diagonal.
* How do we choose the second deleted cell on the main diagonal and the first deleted cells on the diagonals of length $n-2$? Again, just choose the first cell that you are allowed to delete which does not violate the conditions.
* (and so on)

You can simulate this greedy in just $O(n^2)$  — just keep for each diagonal the last deleted cell. If at any point there were no allowed cells, then answer is NO, otherwise, we found the construction.

How to prove that this is sufficient? Let's prove the following statement.

Lemma: In each cell $(x, y)$, write the number of non-deleted cells in the diagonal of $(x, y)$, up to the cell $(x, y)$. Denote this number by $a_{x, y}$. Then $a_{x-1, y} \le a_{x, y}$ for any $1 \le x \le n-1$, $1 \le y \le n$, and $a_{x, y-1} \le a_{x, y}$ for any $1 \le x \le n$, $1 \le y \le n-1$ (in other words, $a$ is nondecreasing by rows and columns).

Proof: Almost trivial from our constraints. Let's show that $a_{x-1, y} \le a_{x, y}$, for example. If cell $(x-1, y)$ is on the main diagonal or lower, then cell $(x-1, y)$ is on a larger diagonal than $(x, y)$. We deleted $y - a_{x, y}$ cells in the diagonal of $(x, y)$ up to this cell. Therefore, the $(y - a_{x, y})$-th deleted cell in the larger diagonal has to have $y$ coordinate at most $y$ as well, so we deleted at least $y - a_{x, y}$ cells in the diagonal of $(x-1, y)$ up to that cell, and there are at most $a_{x, y}$ not deleted cells there. The similar argument goes for the case when $(x-1, y)$ is above the main diagonal.

With this lemma, suppose that there is an increasing sequence of not deleted cells $(x_1, y_1), (x_2, y_2), \ldots, (x_k, y_k)$ (with $x_i < x_{i+1}, y_i<y_{i+1}$). Then it's easy to show that $a_{x_i, y_i}<a_{x_{i+1}, y_{i+1}}$. Indeed, $a_{x_i, y_i}\le a_{x_{i+1}-1, y_{i+1}-1} = a_{x_{i+1}, y_{i+1}} - 1$. But then we would get $a_{x_k, y_k} \ge k$, which obviously doesn't hold (there are at most $k-1$ not deleted cells in each diagonal by our construction).

Bonus: It's possible to show that the answer is NO if and only if there is an increasing sequence of $k$ cells, each of which we aren't allowed to delete. Proof is left to the reader as an exercise.

 **Solution**[174165514](https://codeforces.com/contest/1738/submission/174165514 "Submission 174165514 by liouzhou_101")

[1738H - Palindrome Addicts](../problems/H._Palindrome_Addicts.md "Codeforces Global Round 22")

Author: [liouzhou_101](https://codeforces.com/profile/liouzhou_101 "Grandmaster liouzhou_101")

 **Tutorial**
### [1738H - Palindrome Addicts](../problems/H._Palindrome_Addicts.md "Codeforces Global Round 22")

To count the number of distinct palindromic substrings, we adopt the powerful data structure called eertree (also known as palindromic tree or palindromic automaton). The number of distinct palindromic substrings of a string $s$ is related to the number of nodes in the eertree of $s$. See [Wikipedia](https://codeforces.com/https://en.wikipedia.org/wiki/Palindrome_tree) for its standard operations. In the following, we will consider how to maintain the eertree under push and pop queue operations.

It is a standard trick to push a character at the back. So we only need to consider how to pop a character at the front. The key issue is to delete some nodes when they no longer exist. To achieve this, we maintain the following information of each node $v$: 

* $\texttt{link_cnt}$: the number of nodes that link to $v$.
* $\texttt{rightmost_occurrence}$: the rightmost occurrence of $v$.
* $\texttt{second_rightmost_occurrence}$: the second rightmost occurrence of $v$.

 When the front character is being popped, let $v$ be the longest palindromic prefix of the current string $s$ (right before popping the front character). Then $v$ should be deleted if $v$ is unique in $s$. Moreover, we know that $v$ is unique in $s$ if and only if $\texttt{link_cnt}[v] = 0$ and $\texttt{second_rightmost_occurrence}[v]$ does not exist. Now it remains to consider how to maintain $\texttt{rightmost_occurrence}$ and $\texttt{second_rightmost_occurrence}$ in a lazy manner. 

* After a character $c$ has been pushed at the back of the string $s$, let $v$ be the longest palindromic suffix of the current string $sc$. Update $\texttt{rightmost_occurrence}[v]$ and $\texttt{second_rightmost_occurrence}[v]$ immediately with the new occurrence of $v$.
* When a character is being popped from the front of the string $s$, let $v$ be the longest palindromic prefix of the current string (right before the pop operation). If $v$ is unique in $s$, then let $u$ be the node that $v$ links to, and update $\texttt{rightmost_occurrence}[u]$ and $\texttt{second_rightmost_occurrence}[u]$ with the occurrence of $u$ induced by $v$ (which is a suffix of $v$). Here, note that $u$ occurs at least twice in $v$ as its prefix and suffix; and the suffix $u$ of $v$ is desired as induced by $v$.

In this way, we can maintain the eertree under push and pop queue operations in $O(\Sigma n)$ time, where $\Sigma = 26$ is the size of alphabet. 

Further reading: Takuya Mieno, Kiichi Watanabe, Yuto Nakashima, Shunsuke Inenaga, Hideo Bannai, and Masayuki Takeda. Palindromic trees for a sliding window and its applications. Information Processing Letters, 173:106174, 2022.

An alternative approach

Answer the queries offline. 

Since we only push characters at the back and remove characters at the front, we can deal with all operations offline and find the whole string $s$ with its characters deleted during the operations (This can be achieved easily by only considering push operations). For example, the whole string of the sample input is "$aaabbaab$". 

In this way, every query of the number of distinct palindromic substrings is a range query of the form $(l, r)$ that asks the number of distinct palindromic substrings in $s[l..r]$. Indeed, this kind of queries can be answered in $O(\log n)$ time per query with $O(n \log n)$ time preprocess. 

Further reading: Mikhail Rubinchik and Arseny M. Shur. Counting palindromes in substrings. In Proceedings of the 24th International Conference on String Processing and Information Retrieval, pages 290–303, 2017.

 **Solution**[174165643](https://codeforces.com/contest/1738/submission/174165643 "Submission 174165643 by liouzhou_101")

