# Tutorial_(en)

Div2A ("Palindrome Dance") was authored by jury members altogether, development: [darnley](https://codeforces.com/profile/darnley "Grandmaster darnley")

Div2B ("Skewers") was authored by jury members altogether, development: [GlebsHP](https://codeforces.com/profile/GlebsHP "International Grandmaster GlebsHP"), Codeforces hardened version: [KAN](https://codeforces.com/profile/KAN "Grandmaster KAN").

Div1A ("Timetable") was authored by [Zlobober](https://codeforces.com/profile/Zlobober "International Grandmaster Zlobober") and [meshanya](https://codeforces.com/profile/meshanya "Grandmaster meshanya"), development: [kraskevich](https://codeforces.com/profile/kraskevich "International Grandmaster kraskevich").

Div1B ("Subway Pursuit") was authored by [V--o_o--V](https://codeforces.com/profile/V--o_o--V "International Grandmaster V--o_o--V"), development: [wrg0ababd](https://codeforces.com/profile/wrg0ababd "Expert wrg0ababd")

Div1C ("Network Safety") was authored by [V--o_o--V](https://codeforces.com/profile/V--o_o--V "International Grandmaster V--o_o--V"), development: [achulkov2](https://codeforces.com/profile/achulkov2 "Expert achulkov2").

Div1D ("You Are Given a Tree") was authored by [GlebsHP](https://codeforces.com/profile/GlebsHP "International Grandmaster GlebsHP"), development and codeforces edition [cdkrot](https://codeforces.com/profile/cdkrot "Grandmaster cdkrot"), faster model solution: [V--o_o--V](https://codeforces.com/profile/V--o_o--V "International Grandmaster V--o_o--V").

Div1E ("Summer Oenothera Exhibition") was authored by [Zlobober](https://codeforces.com/profile/Zlobober "International Grandmaster Zlobober"), development by [malcolm](https://codeforces.com/profile/malcolm "Master malcolm").

Some editorials are being published, please wait a bit :)

 
### [1040A - Palindrome Dance](https://codeforces.com/contest/1040/problem/A "Codeforces Round 507 (Div. 2, based on Olympiad of Metropolises)")

Consider a pair of dancers located symmetrically with respect to the center of the stage. If they already have different suits, the answer is definitely "impossible". If they both have same suits, they are fine. If one of them doesn't have a suit, buy him a matching one. Finally, if both don't have suits, buy them two same suits of the cheaper color. Also, if $n$ is odd and the central dancer doesn't have a suit, buy him a cheaper one.

 
### [1040B - Shashlik Cooking](https://codeforces.com/contest/1040/problem/B "Codeforces Round 507 (Div. 2, based on Olympiad of Metropolises)")

The funny thing about this problem that it is entirely based on real facts, in the real life the $k$ was equal to $1$ and one skewer really turned two more.

So it is easy to see, that answer is at least $\lceil \frac{n}{2k + 1} \rceil$ (because in smaller number of operations we wouldn't simply able to touch all skewers), where the $\lceil a \rceil$ denotes rounding up.

Set's build an answer with exactly this number of operations. We will make our answer in such way, that each skewer belongs exactly to one operation. That is, we need to put segments of length $2k + 1$ over the array, such that the ends are touching and that the first and last segments don't pop out of the array too much.

Let's define $x = \lceil \frac{n}{2k + 1} \rceil (2k + 1) - n$, $a = min(n, k)$, $b = x - a$.

Note that $0 \le a, b \le k$ and $a + b = x$.

Let's make segments described above in such way, that the first segments outweighs over the array exactly by $a$ and the last one exactly by $b$.

Since $a, b \le k$ it follows, that the centre of this segments stays inside the array.

Some example: $n = 7$, $k = 2$, $x = 3$, $a = 2$, $b = 1$

The answer is then as in follows: [#|#|@|@|@] [@|@|@|@|#], where @ denotes skewer, and one block of square brackets corresponds to one operation.

 
### [1039A - Timetable](../problems/A._Timetable.md "Codeforces Round 507 (Div. 1, based on Olympiad of Metropolises)")

If there is at least one valid ordering $p$'s (and it surely exists since the $x$ is defined), then the ordering $p_i = i$ is also valid. Hence if for some $i$ doesn't hold $x_i \ge i$ then the answer is no. Also, from this follows that $b_i \ge a_i + t$.

Otherwise, what it means that $x_i = c$? It means that there is an ordering $p$, in which the $i$-th bus comes as $c$, where the other buses will come then? It turns out, that the least restricting way to complete the ordering is following:

$i \to c$, $i + 1 \to i$, $i + 2 \to i$, ..., $c \to c - 1$.

Note that since ordering $p_i = i$, it is also allowed for $i$ to go to $c$ (it wouldn't be too fast), but we can doubt whether $i + 1 \to i$, $i + 2 \to i$ and etc are good.

More over, since $x_i = c$ (not, say, $c + 1$), it must hold that $i + 1 \to i$, $i + 2 \to i$, ..., $c \to c - 1$ are "good" (not fast enough), but doesn't hold $c + 1 \to c$ (too fast).

So for each $i$ we can use scanline to calculate whether it is good or not.

And then we can restore $b$'s in negative order.

What conditions must hold on $b$? $b_i \ge a_i + i$, and depending on whether some $i$ is good or not $b_i \ge a_{i + 1} + t$ or $b_i < a_{i + 1} + t$.

We can go in reverse order and select the value of $b_i$ on the basis of the cases above. Also, since $b_i < b_{i + 1}$ if there are many options for $b_i$ it is best to select the largest of them.

 
### [1039B - Subway Pursuit](../problems/B._Subway_Pursuit.md "Codeforces Round 507 (Div. 1, based on Olympiad of Metropolises)")

Notice that we can make segment in which we are located small enough using binary search. Let $[l; r]$ be the last segment about which we knew for sure that train is in it (at the beginning it's $[1; n]$). Let $m = \frac{l + r}{2}$. Let's ask about segment $[l; m]$. If we receive answer «YES», after this query train for sure will be in segment $[l - k; m + k]$, otherwise in $[m - k; r + k]$. So, after each query length of segment is divided by $2$ and increased by $2k$. After segment length becomes irreducible ($4k$), let's ask about some random station in this segment. If we guessed right, let's finish the program, otherwise make the binary search again.

To get the OK let's make one more observation: for all binary searches except the first one initial segment can be made $[l - k; r + k]$ instead of $[1; n]$.

 
### [1039C - Network Safety](../problems/C._Network_Safety.md "Codeforces Round 507 (Div. 1, based on Olympiad of Metropolises)")

Consider a virus containing a fixed number $x$. Let's investigate two servers connected by a data communication channel, denoting their encryption keys equal as $a$ and $b$ respectively. Since $a \neq b$, it follows that $a \oplus x \neq b \oplus x$. Therefore, if the servers are infected simultaneously the channel remains safe. The same can be said if neither of the servers is infected. When the virus infects exactly one of the two servers the channel between them can cease to be safe only when $x = (a \oplus b)$ (since $a \oplus x = b$, it follows that $x = x \oplus (a \oplus a) = (x \oplus a) \oplus a = (a \oplus x) \oplus a = b \oplus a = a \oplus b$). Define $a \oplus b$ as the value of the respective data channel (connecting servers with keys $a$ and $b$). From this it can be inferred that all servers connected by a path of channels with value $x$ can only be infected simultaneously. Thus the answer when the parameter $x$ is fixed is equal to $2^q$, where $q$ is the number of connected components in a graph where servers are considered vertices and data channels with value x are considered edges. This value can be computed in time linearly proportional to the number of edges with value x. When processing the values which are not found on any edge separately this gives us a solution in total time O(E).

 
### [1039D - You Are Given a Tree](../problems/D._You_Are_Given_a_Tree.md "Codeforces Round 507 (Div. 1, based on Olympiad of Metropolises)")

Let's examine a solution in $O(n^2)$ first.

Introudce a dynamic programming on subtree, the dp of the vertex is the number of paths, which can be taken from the subtree and the maximum length of incomplete path, which ends exactly in vertex v.

Notice that this dp can be maximised as pair — the more of complete paths than better, and if the number of complete paths coincides, then it's better to have the incomplete path as long as possible.

This dp allows to get an answer in $O(n)$ for a single $k$

How to calculate this dp for a vertex? We need to sum the number of complete paths over all children and also either take one of the incomplete path of children and attach the current vertex to it or try to form a new path from two longest incomplete paths of children.

It is possible to use $O(n^2)$ solution to get $O(n \sqrt(n) log)$ solution.

Notice, that $f(k) \le \frac{n}{k}$. From this we get, that $f$ takes no more than $O(\sqrt(n))$ values. Indeed, there are values $f(1), f(2), \ldots f(\sqrt(n))$ and for all $m \ge \sqrt{n} f(m) \le \sqrt{n}$.

To find the corresponding bounds we can use binary search — this way we get solution in $O(n \sqrt(n) log)$.

This is already enough to get Accepted on codeforces, however I want to share some more insights about faster, $O(n \log^2(n))$ solution, it wasn't required to get OK, mostly because we found out that writing this solution is really complicated and making it work faster then sqrt-log solution is even more harder.

The funny thing is that we can do a dynamic programming for all $k$ from $1$ to $n$ simultaneously.

In fact, we will use cartesian tree (more precisely, it is better to have segment tree for efficiency).

We will return from subtree of vertex $v$ structure of size size[v], containing the dp values for all $k$ from $1$ to size[v], where $size$ — it the size of the subtree.

So we need to be able to merge results from subtrees. In particular, from the subtree dp's of sizes $s_1, \ldots, s_t$ ($s_1 \ge s_2 \ge \ldots \ge s_t$) we want to get $\sum s_i$.

Let's take the result corresponding to $s_1$ as a basis, new-borned end can be appended naively. Also, more or less naively we can make the merge of prefix part of length $s_2$ (because this work "is paid" by the fact that we will not return the dp structure of size $s_2$).

So we have to deal with a part from $s_2$ to $s_1$.

In the structure we store pairs of numbers — how much complete paths, and the length of the incomplete path. Note that there are two types of relaxation — when we increase the number of complete paths and when we simply relax the length of incomplete path.

Notice, that $f(k) \le \frac{n}{k}$, and hence $\sum f(k) = O(n \log(n))$. This way the number of transitions of first type is small and we can perform them naively, we just need to find all such transitions fast. We can maintain in the above mentioned data structure maximums on the segments and fast pull all such transitions.

Other transitions can be handled with max= on a suffix and +1 on the whole data structure, the latter we store together with the instance of data structures and handle them when we merge one data structure into the other.

The overall complexity is $O(n \log^2)$.

 
### [1039E - Summer Oenothera Exhibition](../problems/E._Summer_Oenothera_Exhibition.md "Codeforces Round 507 (Div. 1, based on Olympiad of Metropolises)")

Let's reconsider this task in terms of segments: we need to split sequence of photos-segments into minimum number of contiguous groups such that there exists a subsegment in each group of length $k$, which contains inside of each segment of the group.

It's easy to see that if we move right edge of each segment to the left by $k$, it's required to find a single point which is inside of each segments of the group. Let's consider $k$ as the length of each segment.

Next, it's always good to include in next group maximum number of segments until they have a on-empty intersection. Therefore, we have solution in $O(n \cdot q)$ — let's iterate through all segments. If we can add current segment to last group, we add it, else — we create a new group with single current segment.

Furthermore, to find next group, we can use segment tree to perform it in $O(\log n)$. Let's store minimum and maximum values of $x_i$, then we descend the tree to find first segment such that maximum left edge is on the right of minimum left edge.

For each $i$ and $x \le n^{1/3}$ let's calculate minimum length of segments such that group that starts at element $i$ contains at least next $x$ segments. Let's sort all requests in increasing order. We will answer requests in exactly this order. Let's maintain $p_i$ — length of group for current $k$, starting at element $i$ (but $p_i \le n^{1/3}$). There are $n^{4/3}$ events of changing this value at most.

Let's also maintain values $log_i$ — minimum number of groups (and last element of last group) required to jump to element $x \ge i + n^{1/3}$ or to jump to element $x$ such that $p_x \ge n^{1/3}$. It's easy to see that when $p_i$ changes, only area of radius $O(n^{1/3})$ is changed for $long$. Therefore $long$ may be recalculated in $O(n^{5/3} \cdot \log n)$ in total.

Now we can simulate requests: we jump using $long_i$ to the right at least on $n^{1/3}$, therefore there will be $O(q \cdot n^{2/3})$ jumps in total.

The solution became $O(n^{5/3} \cdot \log n + n^{5/3})$ for $n = q$.

Let's speed up the solution to $O(n^{5/3})$. Let's change the meaning of $long_i$ — we allow the last group to be not maximal. Therefore we are now allowed not to recalculate where exactly last maximal group ends. During simulation we need to perform request on segment tree to understand where exactly last maximal group ends.

Now let's do the following: after jump $long_i$ we iterate through next elements and try to add it to last non-maximal group. If we already added more than $n^{2/3}$, let's perform a request on tree in $\log n$.

Therefore the solution performs in $O(n^{5/3} + n^{4/3} \cdot \log n)$.

