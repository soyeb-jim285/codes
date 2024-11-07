# Tutorial_2_(en)

Tutorial is loading... Tutorial is loading... 
### [981C - Useful Decomposition](../problems/C._Useful_Decomposition.md "Avito Code Challenge 2018")

Let's prove that all paths in this decomposition have one intersection vertex.

1)

Any pair of paths have exactly one intersecting vertex, because else there are common edge (so it is not a decomposition) or cycle (so graph is not a tree).

2) 

Let's assume that there are several intersection points.

Let us have three paths $A$, $B$, $C$, and intersecting points are $P(AB), P(AC), P(BC)$.

Then these intersecting points are pairwise different, but $P(AB) \to P(AC) \to P(BC)$ — cycle in the tree, so we get a contradiction.

So we proved that for each triple of paths all intersection points are the same, $\to$ all paths in this decomposition have one intersecting vertex.

So we proved that we can decompose the tree only if the tree looks like a vertex and several paths incoming from it. So you can choose the root in this tree — vertex with degree bigger than two (if there are no such vertex then the tree is bamboo and you can check that case separately or take any vertex as root). If there are several such vertices, when there is no decomposition. And then you can connect root with all leaves.

Bonus: on minimum/maximum number of paths?

[300iq's solution](https://codeforces.com/https://pastebin.com/ybnP74S0)

 
### [981D - Bookshelves](../problems/D._Bookshelves.md "Avito Code Challenge 2018")

Let's build answer from significant bit to least significant bit.

We want to check, is there some partition in $k$ segments, such that all segment's sums have significant bit?

We can check it with $dp_{n, k}$ — is there some partition of first $n$ elements on $k$ segments such that all segment's sums have significant bit?

And then we will do the same with all other bits, we will try set $1$ in the bit, and then we want to check for fixed prefix of bits, is there some partition in $k$ segments, such that all prefixes with same length of all segment's sums are supermasks of current check mask (we will check that with the same dp, $dp_{n, k}$ — is there some partition of first $n$ elements on $k$ segments such that all prefixes of same length of all segment's sums are supermasks of current check mask?)

Bonus 1: Solve the task in $O(n^2 \cdot k / 64)$

Bonus 2: How many distinct answers you can get in worst case?

[solution from cyand1317](https://codeforces.com/https://pastebin.com/hj92UH0B)

 Tutorial is loading... Tutorial is loading... Tutorial is loading... 
### [981H - K Paths](../problems/H._K_Paths.md "Avito Code Challenge 2018")

For each vertex $v$ let's calculate $f_v$ — number of ways to choose $k$ ends for paths in their subtree, such that these paths are edge-intersecting, and $g_v$ — sum of $f_u$ by all vertices $u$ in subtree of $v$. Let $sz_v$ will be number of vertices in subtree of $v$.

Then let $P(x) = (1 + x \cdot sz_{u_{0}}) \cdot (1 + x \cdot sz_{u_{1}}) \ldots \cdot (1 + x \cdot sz_{u_{deg - 1}})$, (where $u_0, u_1, \ldots, u_{deg - 1}$ are the childs of vertex $v$), $ = \sum(a_k \cdot x^k)$

How to calculate $P(x)$? We will use divide and conquer, let's recursively calculate answer for first half of element, for second, and then multiplicate.

$T(n) = 2 T(n / 2) + O(n log n) = O(n log^2 n)$

Note, that degree of polynom is not $n$, but $deg_v$!.

Then $f_v = \sum(a_x \cdot C_k^x \cdot x!)$.

Then for fixed non-vertical path $u \to v$, number of ways to choose $k$ paths, such that their intersection is $u \to v$ is $f_u \cdot f_v$.

We can sum this up for each non-vertical path with simple tree dp.

So we are working in $O(deg_v log^2 n)$ for fixed $v$, summing up for each vertex we can get that this part of solution is working in $O(n log^2 n)$.

Let fix one end of vertical path $v$ and it's son $u$, such that second end of vertical path is inside his subtree, Then let $Q(x) = P(x) \cdot(1 + x \cdot (n - sz_v)) / (1 + x \cdot sz_u) = \sum(b_k \cdot x^k)$, when we need add $\sum(b_x \cdot C_k^x \cdot x!) \cdot g_u$ to answer.

Then we can note, that (for fixed $v$) number of distinct $sz_u$'s — $O(\sqrt{n})$

And for each $sz_u$ we can get $Q(x)$ in $O(deg_v)$, at first we need to calculate (one time!) $P(x) \cdot(1 + x \cdot (n - sz_v)) = \sum(c_k \cdot x^k)$, and then $b_0 = 1$, и $b_x = c_x - b_{x-1} \cdot sz_u$.

So, this part is working in $O(deg_v \cdot \sqrt{n})$ for fixed $v$, summing up for each vertices we can get that this part of solution is working in $O(n \sqrt{n})$, so we solved the task in $O(n log^2 n + n \sqrt{n})$

Bonus: solve in $n log^2 n$.

[300iq's nsqrt](https://codeforces.com/https://pastebin.com/b3h4M9rL) [isaf27's nlog^2](https://codeforces.com/https://pastebin.com/0h3SYJJm)

Thank you for your participation, see you soon (I hope)!

