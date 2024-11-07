# Tutorial_3_(ru)


### [981A - Antipalindrome](../problems/A._Antipalindrome.md "Avito Code Challenge 2018")

You can just check all substrings on palindromity in $O(n^3)$.

Also you can note that if all characters in the string are same, then answer is $0$, else, if string is not a palindrome, answer is $n$, else you can delete last char and get answer $n-1$, so you can solve the task in $O(n)$.

 
### [981B - Businessmen Problems](../problems/B._Businessmen_Problems.md "Avito Code Challenge 2018")

With $map$ data structure for each chemical element that presents in input find maximal cost that you can get, and then just sum up these costs

 
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

 
### [981E - Addition on Segments](../problems/E._Addition_on_Segments.md "Avito Code Challenge 2018")

Suppose we know the index where the maximum is. Let's examine which requests we decided to take. Surely there is no need to take requests which doesn't contain the index of maximum. Because if you delete them, they will not impact maximum and nothing will change.

This way we can see, that any possible answer is a sum of x's of some set of intersecting segments.

We can go with a sweepline. Then when some request segment opens add new item to the knapsack. And delete one when it closes. The answer it the set of all possible sums we can obtain at some points.

So we need to implement the following operations:

1) Add some number to the multiset. 2) Delete some number from the multiset. 3) Find all sums we can can obtain using the numbers from multiset.

Let's store the following dp: $dp_x$ is the number of ways to get weight $x$.

When we add new element $a$ we should go from the end of dp and recalculate it as $dp_i = dp_i + dp_{i-a}$, 

And when removing, doing the reverse transition: going from the beginning and relaxing as $dp_i = dp_i - dp_{i - a}$.

And to find all achievable sums we should just print all $i$, such that $dp_i \neq 0$.

However the exact values of $dp$ can be really large, so we can resort to a trick: let's cound all the dp values by some prime modulo, to avoid being hacked you should probably randomize it.

Bonus 1: How to hack the solution, if you know the modulo used by the participant?

You can also solve the problem with divide & conquer method.

Let's build a segment tree over the input array. For each given request split it with the segment tree to some nodes.

Let's traverse the tree maintaining some data structure, which will help us to deal with the knapsack, and rolling all modifications back when going up from the node.

What operations this data structure should be able to do? We should be able to add new elements to the knapsack and write all the possible sums.

We can use simple 0-1 knapsack with the overall complexity $O(n^2 \cdot log n)$, or say that the data structure is plain old bitset and implement all operations as bitwise operations. This way complexity is $O(n^2 \cdot log n / 64)$.

Bonus 2: could you solve it in $o(n^2)$？

[Gritukan's D&C](https://codeforces.com/https://pastebin.com/Ugc5frQ8)

[300iq's dp](https://codeforces.com/https://pastebin.com/rj8bsMgH)

 
### [981F - Round Marriage](../problems/F._Round_Marriage.md "Avito Code Challenge 2018")

Key idea is that there there is a cut which is not crossed by anyoner (in other words, it is not profitable if brides will travel whole circle)

So we can solve the problem in $O(n \cdot L)$ — fix the cut, and match $i$-th bridegrom (in increasing order) with $i$-th bride (if we will order brides in the traversal order starting from border), and relax answer with current inconvenience.

Later we can note, that cuts not at brides are useless, so we can just choose cut from brides coordinates and get solution in $O(n^2)$.

Later we can note, that we are just searching for optimal cyclical shift of brides coordinates (of course if we will sort everything in increasing order).

Alright, then we want to find such $x < n$, so that $max(min(|a_i - b_{i + x}|, L - |a_i - b_{i + x}|))$ is minimal. (Where $i+x$ is by modulo $n$, of course).

Let's make binary search on $ans$, then we want to check is there such $x$, so that $min(|a_i - b_{i + x}|, L - |a_i - b_{i + x}|) \leq ans$? If we will fix $i$, then set of good $x$ is just cyclical segment (you can find it with binary search or two pointers), and then we want to check that intersection of these segments is not empty. How to check it? We can split cyclic segment into two non-cyclic, and then just add on the segment offline, and then you need to check that there are some point with value $n$.

So we can solve the problem in $O(n \cdot log L)$.

Bonus: how to solve in $O(n \cdot log n)$?

[300iq's nlogLlogn](https://codeforces.com/https://pastebin.com/Q7LKS1rN)

 
### [981G - Magic multisets](../problems/G._Magic_multisets.md "Avito Code Challenge 2018")

For each value of $x$, let's maintain the set of elements on which this value is present. We will do this by maintaining segments in the set (don't worry, we will get rid of this unpleasant part later). Then you just need to take all the segments crossing $l$ or $r$, cut them into two smaller ones, and then everything inside all the segments inside the segment $[l..r]$ must be multiplied by $2$, and to the rest we must add $1$. How to do that? To do this, we store the segment tree, in each vertex modifiers $a$, $b$, such that all numbers $x$ in the subtree are equal to $a \cdot x + b$, not $x$. We can simply push and recalculate sum with these modifiers (look at the example code for more information about this). Then you need to add segment $[l..r]$ to the set.

So we got the solution in $O((n + q) \cdot log n)$.

But the not very nice part is maintaining the segments in the set. Let's get rid of this, take all the left and right bounds of the queries where it occurs, divide all the numbers into segments where the values will always be equal, and maintain (set? no, DSU!), if the segment does not contain a number, then let $par[i] = i$, otherwise $par[i] = i + 1$, (and, of course, use the path compression heuristics) then you can just start jumping from the left segment of the query, and merge neighboring segments, this solution is with the same asympotitcs, but much nicer for implementation.

[Solution from isaf27](https://codeforces.com/https://pastebin.com/LqzHXKkj)

 
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

