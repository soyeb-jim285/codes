# Editorial_of_Round_569

(Idea of the problem Div2A — [ScreaMood](https://codeforces.com/profile/ScreaMood "Pupil ScreaMood"))

(Developer of the problem Div2A — [gop2024](https://codeforces.com/profile/gop2024 "Grandmaster gop2024"))

 
### [1180A - Alex and a Rhombus](https://codeforces.com/contest/1180/problem/A "Codeforces Round 569 (Div. 2)")

Looking into the picture attentively, one can realize that there are $2$ rows with one cell, $2$ rows with two cells, ..., and $1$ row with $n$ cells. Thus the answer can be easily computed by $O(n)$.

[Code](https://codeforces.com/https://pastebin.com/VBHHSSxH)

(Idea of the problem Div2B — [kirillbogatiy](https://codeforces.com/profile/kirillbogatiy "Expert kirillbogatiy"))

(Developer of the problem Div2B — [gop2024](https://codeforces.com/profile/gop2024 "Grandmaster gop2024"))

 Tutorial is loading...[Code](https://codeforces.com/https://pastebin.com/bhHsLaS5)

(Idea of the problem Div1A — [Mr.Hakimov](https://codeforces.com/profile/Mr.Hakimov "Expert Mr.Hakimov"))

(Developer of the problem Div1A — [Mr.Hakimov](https://codeforces.com/profile/Mr.Hakimov "Expert Mr.Hakimov"))

 
### [1179A - Valeriy and Deque](../problems/A._Valeriy_and_Deque.md "Codeforces Round 569 (Div. 1)")

It can be noted that if the deque has the largest element of the deque in the first position, then during the next operations it will remain in the first position, and the second one will be written to the end each time, that is, all the elements of the deque starting from the second will move cyclically left.

Let's go over the deque and find the largest element by value. We will perform the operation described in the statements until the maximum position is in the first position and save the elements in the first and second positions by the operation number. In order to pre-calculate all pairs until the moment when the maximum position is found, it is enough to make no more than one pass through the deque, since in the worst case, the maximum element can be located at the end of the deque.

Denote as $maxIndex$ the position of the maximum element. Then if $m_j <maxIndex$, simply return a pair of numbers from the pre-calculated array, otherwise $A$ is equal to the maximum element, and $B$ is equal to the deque element with the index $(m_j - (maxIndex + 1)) \% (n - 1) + 1$ in $0$-indexing (since we performed the operations until the moment when the maximum position is in the first position, this maximum element is now recorded in the first position).

[Code](https://codeforces.com/https://pastebin.com/kxKypDbq)

(Idea of the problem Div1B — [gop2024](https://codeforces.com/profile/gop2024 "Grandmaster gop2024"))

(Developer of the problem Div1B — [PeregudovSergey](https://codeforces.com/profile/PeregudovSergey "Candidate Master PeregudovSergey"))

 
### [1179B - Tolik and His Uncle](../problems/B._Tolik_and_His_Uncle.md "Codeforces Round 569 (Div. 1)")

First, we are going to describe how to bypass $1 \cdot m$ strip.

This algorithm is pretty easy — $(1, 1)$ -> $(1, m)$ -> $(1, 2)$ -> $(1, m-1)$ -> $\ldots$. Obviously all jumps have different vectors because their lengths are different.

It turns out that the algorithm for $n \cdot m$ grid is almost the same. Initially, we are going to bypass two uttermost horizontals almost the same way as above — $(1, 1)$ -> $(n, m)$ -> $(1, 2)$ -> $(n, m-1)$ -> $\ldots$ -> $(1, m)$ -> $(n, 1)$. One can realize that all vectors are different because they have different $dy$. Note that all of them have $|dx| = n-1$. Then we will jump to $(2, 1)$ (using $(-(n-2), 0)$ vector). Now we have a smaller task for $(n-2) \cdot m$ grid. One can see that we used only vectors with $|dx| \geq n-2$, so they don't influence now at all. So the task is fully brought down to a smaller one.

[Code](https://codeforces.com/https://pastebin.com/j422DSMn)

(Idea of the problem Div1C — [----------](https://codeforces.com/profile/---------- "Master ----------"))

(Developer of the problem Div1C — [----------](https://codeforces.com/profile/---------- "Master ----------"))

 
### [1179C - Serge and Dining Room](../problems/C._Serge_and_Dining_Room.md "Codeforces Round 569 (Div. 1)")

The main idea of the task is that the answer is minimal $x$ which satisfies the condition that the number of dishes with cost $\geq x$ is strictly more than the number of pupils who have more than $x$ togrogs. 

It can be proved using the fact that we can change every neighbor pair for pupils and we don't change the final set of dishes. Exact prove is left as an exercise.

Now to find the answer we can use a segment tree that maintains a balance between the number of dishes and the number of pupils for all suffices of values. Now change query transforms to add in the segment tree, the answer should be found searching the last element which is less than $0$ (standard descent in the segment tree).

Complexity is $O(n \cdot log(n)$).

[Code](https://codeforces.com/https://pastebin.com/j3QeZZma)

(Idea of the problem Div1D — [gop2024](https://codeforces.com/profile/gop2024 "Grandmaster gop2024"))

(Developers of the problem Div1D — [----------](https://codeforces.com/profile/---------- "Master ----------") и [gop2024](https://codeforces.com/profile/gop2024 "Grandmaster gop2024"))

 
### [1179D - Fedor Runs for President](../problems/D._Fedor_Runs_for_President.md "Codeforces Round 569 (Div. 1)")

We suppose we add an edge $u-v$. Path $u-v$ in the tree contains vertices $t_1, \ldots, t_k$, where $k$ — length of the path, $t_1 = u, t_k = v$. For each vertex $x$ of the tree, we say that $f(x)$ — the closest to $x$ vertex of this path. Finally, we call a component of $t_i$ all vertices $x$ having $f(x) = t_i$. 

One can notice that after adding an edge every pair of vertices may generate not more than two simple paths — the first one had already been in the tree, the second one may be generated using added edge. One can notice that every new path is generated by every pair of vertices lying in different components. Let's consider the sizes of components — $s_1, \ldots, s_k$ respectively. So new path isn't generated for $\sum\limits_{i=1}^k \frac{s_i \cdot (s_i - 1)}{2}$ pairs of vertices. So we have the following problem — to minimize this sum.

Thus, we should minimize $\sum\limits_{i=1}^k \frac{s_i \cdot (s_i - 1)}{2}$, what is the same as, $\sum\limits_{i=1}^k s_i \cdot (s_i - 1)$ = $\sum\limits_{i=1}^k s_i \cdot s_i - s_i$ = $\sum\limits_{i=1}^k s_i^{2}$ (because of $\sum\limits_{i=1}^k s_i$ = $n$).

It's obvious now that $u, v$ are leafs of the tree (else we could decrease this sum increasing the path).

For convenience, we will hang the tree for a non-leaf. We will consider that $t_l = lca(u, v)$ in the path. Then, the desired sum will be:

$A + B + C$, где

$A = sz_{t_1}^{2} + (sz_{t_2} - sz_{t_1})^{2} + \ldots + (sz_{t_l} - sz_{t_{l-1}})^{2}$

$B = (n - sz_{t_{l-1}} - sz_{t_{l+1}})^{2}$

$C = sz_{t_k}^{2} + (sz_{t_{k-1}} - sz_{t_k})^{2} + \ldots + (sz_{t_l} - sz_{t_{l+1}})^{2}$

When we fix $L = t_l$, $p_1 = t_{l+1}$ и $p_2 = t_{l-1}$, one can realize that $A$ doesn't depend on $L$ at all but depends on the subtree of $p_1$, as $C$ depends of the subtree of $p_2$. Thus these sums can easily be calculated using $DP$. Let $dp[x]$ be that optimal sum for vertex $x$. Then, when we fix $L$ — $lca(u, v)$ — we need to calculate the minimum by all different $p_1, p_2$ — children of $L$ — the following sum:

$dp[p_1] + dp[p_2] + (n - sz_{p_1} - sz_{p_2})^{2}$.

We get:

$n^{2} + dp[p1] - 2 \cdot n \cdot sz_{p_1} + dp[p2] - 2 \cdot n \cdot sz_{p_2} + 2 \cdot sz_{p_1} \cdot sz_{p_2}$.

Now one can see that if we sort all vertices by $sz$ in non-increasing order one can use Convex Hull Trick — for the next vertex $p_2$ we find minimum by all $p_1$ which are already processed by functions $2 \cdot sz_{p_1} \cdot sz_{p_2} - 2 \cdot n \cdot sz_{p_1} + dp[p1]$, i.e $k = 2 \cdot sz_{p_1}$, $b = - 2 \cdot n \cdot sz_{p_1} + dp[p1]$. $k$ decreases, thus we write usual CHT.

Complexity is $O(n \cdot log(n))$.

[Code](https://codeforces.com/https://pastebin.com/geB0YuUd)

Read this [comment](Editorial_of_Round_569.md?#comment-521242) of [saketh](https://codeforces.com/profile/saketh "Grandmaster saketh") about another approach for this problem.

(Idea of the problem Div1E — [gop2024](https://codeforces.com/profile/gop2024 "Grandmaster gop2024"))

(Developer of the problem Div1E — [TheWayISteppedOutTheCar](https://codeforces.com/profile/TheWayISteppedOutTheCar "International Master TheWayISteppedOutTheCar"))

 Tutorial is loading...[Code](https://codeforces.com/https://pastebin.com/MBNScSnA)

