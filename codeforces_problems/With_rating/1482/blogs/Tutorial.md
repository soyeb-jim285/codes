# Tutorial


### [1482A - Prison Break](../problems/A._Prison_Break.md "Технокубок 2021 - Финал")

Each broken wall increases the number of connected regions of the plane at most by one. Since in the end every single cell must be in the same region as the outside of the prison, there has to be only one connected region, hence the answer is at least nmnm (because there were nm+1nm+1 connected regions at the beginning).

To achieve the answer, one can, for example, break the upper wall in every cell.

 
### [1482B - Restore Modulo](../problems/B._Restore_Modulo.md "Технокубок 2021 - Финал")

Handle the case of $c = 0$ separately. For this check whether for every $i$ from $1\leq i < n$ there holds an equality $arr[i] = arr[i + 1]$ (or in other words, all numbers are the same). If this is true then the modulo can be arbitrarily large. Otherwise, if $arr[i] = arr[i + 1]$ holds for at least one $i$, then $c$ must equal zero, but we already know that it's not the case, so the answer is $-1$.

Ok, now $c\neq 0$ and no two consecutive numbers coincide. Note that $x + c\pmod{m}$ is either $x + c$ or $x - (m - c)$. So all positive differences (between pairs of consecutive numbers) must be the same, as well as all negative differences. Otherwise the answer is $-1$.

If there is no positive difference (or similarly if there is no negative difference) then the modulo can be arbitrarily large. Otherwise the modulo has to equal their sum $c + (m - c) = m$. After we find out $m$ and $c$ it only remains to check if they in fact generate our sequence.

 
### [1482C - Basic Diplomacy](../problems/C._Basic_Diplomacy.md "Технокубок 2021 - Финал")

First, for each day we select an arbitrary friend from the list. With this choice, at most one friend will play more than $\left\lceil\dfrac{m}{2}\right\rceil$ times. Let's call him $f$. We want to fix schedule such that $f$ will play exactly $\left\lceil\dfrac{m}{2}\right\rceil$ times. To do this, we go through all the days and, if $f$ is assigned on a certain day and someone else can play this day, then we assign anyone except $f$ for that day. We will make such replacements while $f$ plays more than $\left\lceil\dfrac{m}{2}\right\rceil$ times. There is only one case when this is not possible: if $f$ is the only friend who can play in more than $\left\lceil\dfrac{m}{2}\right\rceil$ days.

 Tutorial is loading... 
### [1482E - Skyline Photo](../problems/E._Skyline_Photo.md "Технокубок 2021 - Финал")

We can solve this problem with DP. A trivial $O(n^2)$ algorithm would look like this: Define $dp_i$ as the maximum beauty that can be achieved if we have a set of photos of buildings from $1$ to $i$. We can check every possible splitting point $j \le i$ for the rightmost picture of the set, and keep the biggest answer. $dp_i = max_{j \le i}(dp_{j - 1} + b_{j..i})$.

Now we just need to optimize this solution. Assume we are calculating $dp_i$ First important thing we need to realize is that, if we find the position of the closest smaller number to the left of $i$, on position $j$, and we choose to add it in the rightmost photo with building $i$, then the best solution would be on $dp_j$, because all numbers after $j$ are bigger than $h_j$, so they would not change the beauty of the picture (this is assuming that $i$ and $j$ are on the same photo). Note that we had already calculated the max beauty of $dp_j$, so it is not necessary to go back any further, as we have the best answer stored at $dp_j$

Having this observation, we are just left to check numbers between $j$ and $i$ as possible splitting points for the rightmost picture (the case where building $j$ and building $i$ are in different pictures). But we now know that every height from $j + 1$ to $i - 1$ is bigger than $h_i$ ( this is because $j$ is the closets smaller height), so the answer will just be $dp_{k - 1}$ + $b_i$ for any $k$ between $j + 1$ and $i$. We want to maximize the answer, so we just want to look for the max $dp_k$ value in this range. To do this, we can keep a max segment tree with dp values, and query it in $O(lgn)$ time. After we calculate $dp_i$, we insert it to the segment tree. This gives un an $O(n*lgn)$ solution, enough to solve the problem.

For the final implementation, we can iterate from 1 to $n$, keeping a stack with height values, to calculate the closest smaller building for each building. We just pop the stack while the current building is smaller than the top value of the stack, and insert the current building on top of the stack. Actually, by using this trick right, a segment tree is not really necessary. We can calculate the minimum answer for the ranges by updating information as we delete or add numbers in the stack. So it is possible to achieve a linear time solution. However, $O(n*lgn)$ is enough to solve the problem, so this optimization is not necessary.

 
### [1482F - Useful Edges](../problems/F._Useful_Edges.md "Технокубок 2021 - Финал")

Find all distances between vertices via Floyd's algorithm for $O(n^3)$. Consider all triples with fixed endpoint, say, $v$. Let's find all useful edges corresponding to such triples.

An edge $(a, b, w)$ is useful, if there is a triple $(v, u_i, l_i)$ with

$$dist(v, a) + w + dist(b, u_i)\leq l_i\Leftrightarrow -l_i + dist(u_i, b)\leq -w - dist(v, a).$$

Note that the right hand side depends only on the fixed vertex $v$ and the edge itself, so we are going to minimize the left hand side over all possible triples. It can be done using Dijkstra in $O(n^2)$ if we initialize the distance to all $u_i$ with $-l_i$. After we are done for all vertices $v$, there only remains to check for each edge whether it has been marked useful for any vertex $v$.

 
### [1482G - Vabank](../problems/G._Vabank.md "Технокубок 2021 - Финал")

Our solution consists of two parts. First of all find an upper bound for $M$. To achieve this, we try to query $1$, $2$, $4$, $8$ and so on until we fail. After the first unsuccessful query we will have $0$ euro and know that the answer is on some segment $[2^k, 2^{k+1})$. It takes at most 47 queries.

Now one could do something like the following binary search: take the left border of our segment of money, then on each query try the left border and then the middle. If the queries are successful then all good, otherwise we lose $L + \frac{R - L}{2}$, where $L$ is taken at the beginning of this iteration, and all $\frac{R - L}{2}$ cannot sum up into something greater than the initial left border we obtained, because initially $R - L = L$, and each time $R - L$ decreases twice. However, this solution requires another $2\log(10^{14})$ queries, which is too much.

Let's divide the segment into two non-equal parts sometimes. Note that if the left side of the partition doesn't exceed half of the segment then that extra $L$ we have is enough to cover all our expenses. Also let's use that we actually get extra $M \approx \frac{L + R}{2}$ after successful middle queries.

We want our algorithm to look something like the following. Let the current segment equal $[l, r]$. and the current balance is at least $l\cdot y + (r - l)$ for some integer $y$. Then if $y = 0$ then we query $l$, and if $y > 1$ then we query whatever we want on the segment. It is easy to see that after an unsuccessful query our balance is at least $l \cdot (y - 1) + (r - l)$ (for new $l$ and $r$), and after a successful query, we will think that our balance is at least $l \cdot (y + 1) + (r - l)$ (for new $l$ or $r$). The latter is not always the case, we will discuss that later.

Now our balance is described by the only integer $y$. Let $dp[x][y]$ equal the maximal $d$ so that it's possible to find the answer on $[l, l + d]$ having $y\cdot l + d$ money initially. Then $dp[x][y] = dp[x - 1][y - 1] + dp[x - 1][y + 1]$, it is easy to compute and follow in the solution. One can show that $dp[k][0] = \binom{k}{[k/2]}$. It implies that $k\leq 49$. This adds up to 97 queries.

Now remember that, if we proceed from $(l, r, y)$ to $(m, r, y + 1)$, then our balance was $y\cdot l + (r - l)$ and became $y\cdot l + m$, while we need $(y + 1)\cdot m$ for our estimations. Hence we need some extra cash to cover such "expenses". It can be proven that they don't exceed three of initial $L$-s, which gives the total of 100 queries.

 
### [1482H - Exam](../problems/H._Exam.md "Технокубок 2021 - Финал")

Fix a particular string $s$ and find all edges outgoing from it. For each position $i$ of the string let's find the value of $left_i$ being the starting position of the longest substring which ends at the position $i$ and is one of the strings $s_j$. It's easy to see that such strings are the only ones where the outgoing edges from $s$ can lead to. What remains is to find out which of them need to be excluded.

A string needs to be excluded if there is an occurrence of it into $s$ which is entirely covered by an occurrence of another substring. So let $ind_i = \min\{left_j\,\mid\,j > i\}$. Then the strings to be excluded are precisely the strings among $s_j$'s which are suffixes of the substring $[ind_i, i]$ for some $i$. This can be found via the Aho-Corasick structure. Since its suffix links represent a tree, one can find the vertices corresponding to the substrings $[ind_i, i]$ and mark the way to the root in the suffix links tree. After this one can just check if the vertices of $[left_i, i]$ are marked. To mark paths efficiently one can use segment trees or std::set. The overall complexity is $O(n\log{n})$.

