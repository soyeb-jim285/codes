# Tutorial_(en)

[1209A — Paint the Numbers](../problems/A._Paint_the_Numbers.md)
==========================================================================

Author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

Consider the smallest element xx in the array. We need to paint it in some color, right?

Observe, that we can paint all elements divisible by xx in that color as well.

So we can perform the following while the array is not empty:

 * find the minimum element xx,
* assign new color and remove all elements divisible by xx

Complexity: O(n2)O(n2).

[1209B — Koala and Lights](../problems/B._Koala_and_Lights.md)
=========================================================================

Author: [FieryPhoenix](https://codeforces.com/profile/FieryPhoenix "Master FieryPhoenix")

Because each individual light flashes periodically, all the lights together are periodic as well.

Therefore, we can simulate the lights up to the period to get the answer.

The actual period can be calculated as follows: 

 **Spoiler*** If a light toggles every t seconds, its period is 2t.
* The overall period is the least common multiple of the individual periods 2,4,6,8,10, which is 120.
* There is also a "pre-period" of 5 since lights can start toggling at time 5 in the worst case, so the time we need to simulate is bounded by 125
However, computing the actual period is not necessary and a very large number will work (like 10001000). 

Challenge: Can we bound the time even more?

[1209C — Paint the Digits](../problems/C._Paint_the_Digits.md)
=========================================================================

Author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

The sequence must split into two non-decreasing where the end of the first ≤≤ start of the second.

Let's bruteforce the value xx, so that all elements <x<x go to the color 11, all elements >x>x go to the color 22, and for =x=x we are not sure.

Actually, we can say that all elements equal to xx, which go before the first element >x>x сan safely go to the color 22, while the rest can only go to the color 11.

So we colored our sequence and we now only need to check whether this coloring is fine.

Complexity is 10⋅n10⋅n.

[1209D — Cow and Snacks](../problems/D._Cow_and_Snacks.md)
=======================================================================

Author: [FieryPhoenix](https://codeforces.com/profile/FieryPhoenix "Master FieryPhoenix")

Since every animal has exactly two favorite snacks, this hints that we should model the problem as a graph. The nodes are the snacks, and the edges are animals with preferences connecting snack nodes.

Let's consider a connected component of the graph with size greater than 11. The first animal (edge) in that component to eat must take two snacks (nodes), all other snack nodes will be eaten by exactly one animal edge. It is always possible to find an order so that no other animals takes two snacks (for example, BFS order). Thus, a connected component with cc vertices can satisfy at most c−1c−1 animals. 

Let NN be the number of snacks, MM be the number of animals, and CC be the number of connected components (including those of size 1). The number of satisfied animals is N−CN−C, so the number of of unhappy animals is M−(N−C)M−(N−C).

Complexity: O(n+m)O(n+m)

[1209E1 — Rotate Columns (easy version)](../problems/E1._Rotate_Columns_(easy_version).md)
========================================================================================

Authors: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov") and [cdkrot](https://codeforces.com/profile/cdkrot "International Grandmaster cdkrot")

There many approaches possible, let's describe one of them.

Let's change the problem to the following:

 * Rotate columns any way you want.
* Select in each row one value, maximizing the sum.

This can be done with a dp, states are (prefix of columns, mask of taken columns). Basically at each step we are rotating the current column and fixing values for some of the rows.

The most simple way to write this makes 3n⋅m⋅n23n⋅m⋅n2 (for every submask->mask transition iterate over all possible shifts and elements to consider in cost function).

But if we precalculate the cost function in advance, we will have O((3n+2nn2)⋅m)O((3n+2nn2)⋅m).

[1209E2 — Rotate Columns (hard version)](../problems/E2._Rotate_Columns_(hard_version).md)
========================================================================================

The previous solution is slightly too slow to pass the large constraints.

Let's sort columns by the maximum element in them. Observe, that it is surely unoptimal to use columns which go after first nn columns in sorted order (we could've replaced them with some unused column).

So we can solve the hard version with previous solution in which we consider only best nn columns.

Complexity O((3n+2n⋅n2)⋅n+T(sort))O((3n+2n⋅n2)⋅n+T(sort))

[1209F — Koala and Notebook](../problems/F._Koala_and_Notebook.md)
===========================================================================

Author: [dragonslayerintraining](https://codeforces.com/profile/dragonslayerintraining "Grandmaster dragonslayerintraining")

First split all edges into directed edges with single digit labels, creating O(mlogm)O(mlogm) dummy vertices if necessary.

Since the first edge will not be zero (no leading zeros), longer paths are always greater. With a BFS, this reduces the problem to finding lexicographical minimal paths in a DAG.

To avoid needing to compare long sequences, we will instead visit all the vertices in order by their lexicographical minimal path. This can be done efficiently by something like BFS/DFS.

The main idea is to visit sets of vertices at a time. If we have a set of vertices whose minimal paths are PP, we can find the set of vertices whose minimal paths are P0P0 by following all outgoing 00 edges. Then, we find the set of vertices whose minimal paths are P1P1 by following all outgoing 11 edges, and so on for all digits. Since we ignore vertices once they are visited, this is O(mlogm)O(mlogm)

[1209G1 — Into Blocks (easy version)](../problems/G1._Into_Blocks_(easy_version).md)
=====================================================================================

Author: [Errichto](https://codeforces.com/profile/Errichto "International Grandmaster Errichto")

Let's solve easier version first (we will reuse core ideas in hard version as well).

Clearly, if some two integers are ``hooked'' like in 1…2…1…21…2…1…2, then they will end up being turned into the same integer.

So when we see integer xx with first occurrence at aa and last at bb, let's mark segment [a;b][a;b] as blocked. E.g. for array [3,3,1,2,1,2][3,3,1,2,1,2] we have not blocked only the bar between 33 and 11, that is we have |3,3|1,2,1,2||3,3|1,2,1,2|.

Now for every such segment we have to change all elements into a common element. So the answer for a segment is segment length minus the number of occurrences of the most frequent element.

One easy implementation is as follows: blocking is "+= 1 on segment" (can be done easily in O(n+operations)O(n+operations) in offline, then for an element xx, put the number of it's occurrences in the position of first occurrences.

Now we only need to compute max on disjoint segments, so it can be done in a naive way.

Complexity: O(n)O(n).

[1209G2 — Into Blocks (hard version)](../problems/G2._Into_Blocks_(hard_version).md)
=====================================================================================

To adjust the solution for many queries we need to create some sophisticated data structure.

E.g. we all know that mentioned above "+= 1 on a segment" is easily done with a segtree. If we maintain for every value aiai the corresponding set of occurrences, it's easy to update mentioned above ``number of occurrences in the first position''.

So what we need to do now? We need to dynamically recalculate the sum of minimums (and the set segments to calculate minimum can change quite much due to updates).

You probably also now that we can design a segtree which supports range increments and query (minimum, number of minimums) on the segment. In a similar way we can build a structure which returns (minimum, number of minimums, the sum of largest stored counts between minimums). Just maintain a few values in each node and do lazy propagation.

Complexity O(qlogn)O(qlogn).

[1209H — Moving Walkways](../problems/H._Moving_Walkways.md)
========================================================================

Author: [Errichto](https://codeforces.com/profile/Errichto "International Grandmaster Errichto")

Some minor tips:

 * Everything is a walkway. When there is no walkway, it is a walkway of speed 00.
* You can increase all speeds by 11 and assume that you own speed is in [−1;+1][−1;+1]
* Energy is an entity which is δδ speed ×× time, which is distance.

Also if you spend xx energy per segment of len ll and speed vv, it is not important how exactly you will distribute it over the walking process. In any way, you will walk by feet l−xl−x meters in time (l−x)/v(l−x)/v.

So it turns out it's better to distribute more energy to low-speeded walkways (because the denominator is smaller).

Assume that you (by default) save up all energy on any non-feet path (for feet path it's always optimal to walk with speed ≥1≥1 (≥0≥0 after speeds hack), so now save up's).

Build an energy graphic where the Ox axis will correspond to the **point** you are in (not time). It will be a piecewise linear function, so it is enough to store it's value only in points corresponding to points between walkways. Iterate over walkways in the order of speed and try to steal as much energy as possible to the current walkway.

What are the limits of stealing energy?

 * there is a restriction based on ll and vv (if you take too much energy, you wouldn't be able to fully walk it up)
* the graphic must still be able above 00 at all points.

The latter condition is just a suffix minima on a segment tree.

Complexity: O(nlogn)O(nlogn). 

