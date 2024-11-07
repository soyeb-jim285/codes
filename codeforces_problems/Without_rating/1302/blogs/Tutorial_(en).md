# Tutorial_(en)

We hope that no difficulties, misunderstanding and "wtf am i asked to do" thoughts ruined your fun!

 **Problem A: Nash equilibrium**
### [1302A - Nash equilibrium](../problems/A._Nash_equilibrium.md "AIM Tech Poorly Prepared Contest (unrated, funny, Div. 1 preferred)")

The solution itself is straightforward: for each row we mark all elements but the only maximal element (if exists) as not suitable for being the Nash equilibria, then do similarly for columns, then output the lexicographically minimal unmarked cell. The bug was reading $m$ and $n$ instead of $n$ and $m$ respectively, we hoped that the fact that the only two samples were square and a table filled with equal elements should be a hint for everyone who have made this mistake at least once in their life.

 **Problem B: DAG**
### [1302B - DAG](../problems/B._DAG.md "AIM Tech Poorly Prepared Contest (unrated, funny, Div. 1 preferred)")

To solve this problem one can update a bitset of all reachable vertices from every vertex $v$ in the topological sorted order and then calculate the sum of sqr(reachable[v].count()). The bug was, maybe, less obvious than in the previous problem, but still quite common (at least we thought so): instead of creating an edge $u\to v$ we created edges $v\to u$. Again, the first two samples contained a path and a set of isolated edges, while the third one has an incorrect answer.

However, bitset sometimes doesn't fit into memory, so one can, for example, calculate $n/64$ times for each vertex the number of reachable vertices with indices from $64k$ to $64(k+1) - 1$ and then sum up all the reachable counts.

 **Problem C: Segment tree or Fenwick?**
### [1302C - Segment tree or Fenwick?](../problems/C._Segment_tree_or_Fenwick_.md "AIM Tech Poorly Prepared Contest (unrated, funny, Div. 1 preferred)")

Well, the problem itself is a standard segment tree/fenwick tree exercise. So where could one mess up here?

We expected participants to notice that this is the only problem with several test cases here, so the common bug used here is not clearing the global data structure between tests. One can see that both Fenwick tree and Segment tree without clearing produce same answers.

 **Problem D: Dijkstra**Tutorial is loading... **Problem E: Amazing bitset**
### [1302E - Amazing bitset](../problems/E._Amazing_bitset.md "AIM Tech Poorly Prepared Contest (unrated, funny, Div. 1 preferred)")

First of all, we claim that a bitset is amazing iff it has distinct elements. Indeed, if all its elements are equal, then we cannot do a single operation. Otherwise, if there are $a$ zero bits and $b$ one bits (wlog $a\leq b$), then we can do $(a - 1)$ operations to flip one 0-bit and one 1-bit per operation, and then flip all the remaining bits using the last operation.

So it can be seen that the probability for a bitset not to be amazing is $p^n + (1 - p)^n$. This can be calculated using fast exponentiation, and then subtracted from $1$.

The problem is that if we calculate both summands in ints, then their sum can exceed INT_MAX, because $1\,234\,567\,891 > 2^{30}$, so int overflow is the bug here.

*In problems F, G and J we don't mention in the editorial that we assume you to have parsed the statement into a convenient programming-friendly format.*

 **Problem F: Keep talking and nobody explodes -- easy**
### [1302F - Keep talking and nobody explodes -- easy](../problems/F._Keep_talking_and_nobody_explodes_--_easy.md "AIM Tech Poorly Prepared Contest (unrated, funny, Div. 1 preferred)")

One could guess that if we are asked not to mix up if and else statements then the problem is actually to choose which statements to mix up. A simple bruteforce of all mix-up-masks does the trick.

 **Problem G: Keep talking and nobody explodes -- medium**
### [1302G - Keep talking and nobody explodes -- medium](../problems/G._Keep_talking_and_nobody_explodes_--_medium.md "AIM Tech Poorly Prepared Contest (unrated, funny, Div. 1 preferred)")

Here bruteforce takes way too long to finish, so the idea here is meet-in-the-middle: all operations are reversible, so if we iterate over all first-25-mix-up-masks and last-25-mix-up-masks, we can sort the obtained middle images and use a two-pointers technique to get the intersection. It may turn out that one test is not enough here (maybe because of somewhat similar to the birthdays paradox), so one should do mitm for a pair of tests, not for a single one.

 **Problem H: Who needs suffix structures?**Tutorial is loading... **Problem I: Deja vu**Tutorial is loading... **Problem J: Keep talking and nobody explodes -- hard**
### [1302J - Keep talking and nobody explodes -- hard](../problems/J._Keep_talking_and_nobody_explodes_--_hard.md "AIM Tech Poorly Prepared Contest (unrated, funny, Div. 1 preferred)")

A freaking ton of if-else operators strikes back.

In this problem one could use some sort of heuristics, like define $f(mask)$ being the hamming distance between the desired string and the obtained one, and then do some simulated annealing or maybe gradient descent or something else (we didn't manage to make the gradient descent work, but simulated annealing did the job). Feel free to share your approaches in comments!

