# Tutorial_1_(en)

Haven't done one of these for a while! Here are my approaches to the problems:

#### [1400A - String Similarity](../problems/A._String_Similarity.md "Educational Codeforces Round 94 (Rated for Div. 2)")

We just need to make sure our string of nn characters matches each of the nn substrings in at least one spot. The easiest way to do this is to take every other character from ss. Code: [90908018](https://codeforces.com/contest/1400/submission/90908018 "Submission 90908018 by neal")

Another fun solution: we can generate random strings and check them until we find one that matches everything. This works because the probability of failing to match any particular substring is 12n12n, so as nn gets bigger the probability of failing gets extremely low. Code: [90999219](https://codeforces.com/contest/1400/submission/90999219 "Submission 90999219 by neal")

#### [1400B - RPG Protagonist](../problems/B._RPG_Protagonist.md "Educational Codeforces Round 94 (Rated for Div. 2)")

First iterate on the number of swords we will personally take. Then we should greedily take as many war axes as we can until we run out of money. At this point, our follower needs to take as many items as possible. They can do this by greedily taking whichever of swords or war axes are cheaper until they run out, followed by taking the more expensive of the two. Code: [90918673](https://codeforces.com/contest/1400/submission/90918673 "Submission 90918673 by neal")

#### [1400C - Binary String Reconstruction](../problems/C._Binary_String_Reconstruction.md "Educational Codeforces Round 94 (Rated for Div. 2)")

Note that si=1si=1 means "either wi−x=1wi−x=1 or wi+x=1wi+x=1," whereas si=0si=0 means "both wi−x=0wi−x=0 and wi+x=0wi+x=0." We can greedily solve this by starting out our string ww with all 1's, then marking i−xi−x and i+xi+x as 0 whenever we are forced to because si=0si=0. Then we can simply check whether all of the si=1si=1 conditions are valid to confirm. Code: [90915688](https://codeforces.com/contest/1400/submission/90915688 "Submission 90915688 by neal")

#### [1400D - Zigzags](../problems/D._Zigzags.md "Educational Codeforces Round 94 (Rated for Div. 2)")

We can rethink this as counting the number of equal pairs (ai,aj)=(ak,al)(ai,aj)=(ak,al) where i<j<k<li<j<k<l. To do this we loop over jj from right to left and make sure we have all (ak,al)(ak,al) pairs where k>jk>j counted in a map. Then we simply iterate over ii and add up the number of occurrences of each (ai,aj)(ai,aj) in the map.

For implementation details, note that we don't actually want to use a map and make our code slower. We can just use an array of size n2n2 and convert the pair (ai,aj)(ai,aj) to the number ai⋅n+ajai⋅n+aj since the aiai are in the range [1,n][1,n]. As a bonus, even if the aiai were larger than nn, we could just compress them down to [1,n][1,n] and repeat the solution above. Code: [91019003](https://codeforces.com/contest/1400/submission/91019003 "Submission 91019003 by neal")

#### [1400E - Clear the Multiset](../problems/E._Clear_the_Multiset.md "Educational Codeforces Round 94 (Rated for Div. 2)")

Notice that we can reorder the operations in any way we want without affecting the result. So let's do all of the first-type operations before the second-type operations. Then it's clear that the number of second-type operations we'll need is the number of nonzero elements left over after the first-type operations. So we just want to choose first-type operations to minimize the number of first-type operations plus the number of nonzero elements left after we're done.

Let's say we have an array aa where amam is the minimum value (if there is a tie, you can pick any tied index). I only have a messy proof for this at the moment, but it turns out we only need to consider two options: either take all nn second-type operations, or use amam first-type operations on the entire array and then recursively solve a1−am,...,am−1−ama1−am,...,am−1−am and am+1−am,...,an−amam+1−am,...,an−am separately. This leads to a simple n2n2 solution: [90999997](https://codeforces.com/contest/1400/submission/90999997 "Submission 90999997 by neal").

Note that by using [RMQ](https://codeforces.com/https://en.wikipedia.org/wiki/Range_minimum_query) we can improve this to O(nlogn)O(nlogn) or even O(n)O(n). The idea is very similar to the solution to problem G [here](https://codeforces.com/blog/entry/64833).

#### [1400F - x-prime Substrings](../problems/F._x-prime_Substrings.md "Educational Codeforces Round 94 (Rated for Div. 2)")

The key observation is that since xx is only up to 20, there can't be that many different xx-prime strings total--turns out there are only about 2400 for the worst case of x=19x=19. So we can generate all of them and perform a DP where our state is represented by the longest prefix of any of the strings we currently match. We can do this by building a trie of all of the xx-prime strings. We then need to be able to transition around in this trie; it turns out this is exactly what [Aho-Corasick](https://codeforces.com/https://en.wikipedia.org/wiki/Aho%E2%80%93Corasick_algorithm) does for us. In particular, knowing which node of the Aho-Corasick tree we are currently at gives us the full information we need to determine whether or not we will match one of the strings after adding more characters later. This leads to a fairly simple DP: [90977148](https://codeforces.com/contest/1400/submission/90977148 "Submission 90977148 by neal")

#### [1400G - Mercenaries](../problems/G._Mercenaries.md "Educational Codeforces Round 94 (Rated for Div. 2)")

In order to take care of the lili and riri constraints, we can iterate on the number of mercenaries we'll choose and find the number of choices for each count. The key constraint in this problem is that mm is at most 20, which means that there can only be a few connected components that aren't just a single node. In particular, the largest possible connected component size is 21 (since a connected graph with mm edges has at most m+1m+1 nodes).

This means that for each connected component we can iterate over all of the subsets of nodes in that component and check whether the subset is a valid choice (i.e., is an independent set). We can then do a DP for each component where dp(mask, k) = the number of submasks of mask that have k ones and represent a valid independent set subset of the component.

Finally we can iterate over the total number of mercenaries we want. We can then do a knapsack over each of the components, making sure to only consider nodes in each component where lili and riri work with our number of mercenaries. Finally we determine how many valid li,rili,ri mercenaries are available outside of our components, and the rest is a simple choose function. Code: [90977154](https://codeforces.com/contest/1400/submission/90977154 "Submission 90977154 by neal")

