# Tutorial_2_(en)

Here are my approaches to the problems today:

#### [1418A - Buying Torches](../problems/A._Buying_Torches.md "Educational Codeforces Round 95 (Rated for Div. 2)")

Since the second trade is the only way to get coal, we clearly need to perform the second trade kk times. So how many times do we need to do the first trade? We can see that in order to end up with enough sticks and coal by the end, we need to obtain ky+kky+k sticks (kyky to convert to coal and kk to save as sticks). Since the first trade really just gives us x−1x−1 new sticks each time, we'll need to make ⌈ky+k−1x−1⌉ first trades ([reference to floor and ceiling functions](https://codeforces.com/https://en.wikipedia.org/wiki/Floor_and_ceiling_functions) for anyone unfamiliar).

For implementation details, note that for positive integers a and b, ⌈ab⌉=⌊a+b−1b⌋. Code: [92851684](https://codeforces.com/contest/1418/submission/92851684 "Submission 92851684 by neal")

#### [1418B - Negative Prefixes](../problems/B._Negative_Prefixes.md "Educational Codeforces Round 95 (Rated for Div. 2)")

We can think about the problem as follows: we want to order the ai to create the longest possible nonnegative prefix of pn,pn−1,…,p1 (in other words, the smallest possible k such that pn≥0,pn−1≥0,…,pk≥0).

Notice that pn=a1+⋯+an is fixed. We can also see pn−1=pn−an, pn−2=pn−an−an−1, etc. So we should make an as small as possible (assuming it is unlocked), then an−1, and so on. In other words the unlocked ai should be sorted in decreasing order from left to right. To prove this, you can use an exchange argument: if you consider an arrangement of the ai where two consecutive unlocked values are not in decreasing order, we can swap them with each other. This swap does not make any of the pi smaller (it can only make some pi bigger). Thus we can start with the optimal ordering and repeatedly apply swaps until the unlocked values are sorted, without making anything worse.

Code: [92797816](https://codeforces.com/contest/1418/submission/92797816 "Submission 92797816 by neal")

#### [1418C - Mortal Kombat Tower](../problems/C._Mortal_Kombat_Tower.md "Educational Codeforces Round 95 (Rated for Div. 2)")

This is a DP where the state is the prefix of the bosses we've fought and the person whose turn it is next; the DP value is the number of hard bosses our friend had to fight, which we want to minimize. For each state we can simply consider both options of fighting one boss or fighting two bosses to progress to a future state.

See the code for details: [92798564](https://codeforces.com/contest/1418/submission/92798564 "Submission 92798564 by neal"). In this solution, `dp[i][who]` represents the minimum number of hard bosses for our friend given that we've finished the first `i` bosses and that it is `who`'s turn to go next (0 is us, 1 is our friend). In the code I use a little trick that `who * hard` cancels out the hard bosses for us but includes them for our friend.

#### [1418D - Trash Problem](../problems/D._Trash_Problem.md "Educational Codeforces Round 95 (Rated for Div. 2)")

Note that we can move multiple piles together at the same cost as moving a single pile. This means that if we have a group of piles we want to collect together, as long as we bring them together somewhere between `min(x_i)` and `max(x_i)`, the cost of doing this will be `max(x_i) - min(x_i)`.

In particular, since we can end up with two piles, we'll want to create two segments like the following in order to collect everything (* means pile, — means segment):

 
```cpp
*----*-*-------*    *-----*---*
```
We want to minimize the combined length of the segments, but notice that this combined length is equal to `max(x_i) - min(x_i) - the gap in between the segments`. So we just need to maximize the gap, by taking the maximum value of xi+1−xi.

In order to do this and handle queries, we can store all of the positions in a set and all of the gaps in a multiset. Then when we add/erase a position xi, we only have to adjust three gaps: xi+1−xi, xi−xi−1, and xi+1−xi−1.

Code: [92847621](https://codeforces.com/contest/1418/submission/92847621 "Submission 92847621 by neal"). Be careful that when erasing from a multiset, `ms.erase(key)` [removes ALL occurrences](https://codeforces.com/https://en.cppreference.com/w/cpp/container/multiset/erase) of `key` from the multiset. Instead, we want `ms.erase(ms.find(key))`.

#### [1418E - Expected Damage](../problems/E._Expected_Damage.md "Educational Codeforces Round 95 (Rated for Div. 2)")

Given a and b, let's define big monsters as monsters with d≥b, and small monsters as monsters with d<b. We will only take damage from monsters that come after the a-th big monster. In particular, if a is larger than big (the number of big monsters), we know the answer is immediately 0.

Otherwise, every big monster has a 1−abig chance of doing damage (the chance it is not one of the first a big monsters). For small monsters, they are equally likely to be in any of the big+1 gaps before/between/after the big monsters. In the first a gaps, they will not do any damage, and after that they will. So each small monster has a 1−abig+1 chance of doing damage.

So the answer we want is 1−abig times the sum of every big monster, plus 1−abig+1 times the sum of every small monster. We can use prefix sums to quickly get the sum of all small monsters / all big monsters for each query. Code: [92809090](https://codeforces.com/contest/1418/submission/92809090 "Submission 92809090 by neal")

#### [1418F - Equal Product](../problems/F._Equal_Product.md "Educational Codeforces Round 95 (Rated for Div. 2)")

Given a particular value for x1, we can determine the range of y1 that would be valid based on the two constraints 1≤y1≤m and Lx1≤y1≤Rx1. Let's call it [ylow,yhigh].

Let's say there exists a valid (x2,y2) that fits the desired constraints such that x1y1=x2y2. Then if we write x2x1=ab as a reduced fraction, we must have that a>b and that b is a factor of x1. Moreover, since x1y1=x2y2 means that y1y2=ab, we must also have that a is a factor of y1.

If given x1 we can find y1, a, and b that satisfy the above constraints, we are almost done. The only remaining constraint is to ensure that x2=x1ab≤n. So in particular, given values for x1 and b (such that b is a factor of x1), we want to find the smallest value of a such that a>b and a is a factor of at least one number in our desired y-range [ylow,yhigh].

In-contest, I then found two separate algorithms that should be fast in different scenarios and decided to use whichever of the two I guessed to be faster for each value of x1. The first algorithm is to iterate all of the factors of x1 as b and find all of the corresponding valid choices for a. Then loop up those choices for a from smallest to largest, and for each it just takes a quick O(1) check to determine whether any number in [ylow,yhigh] is divisible by a. This has a worst case of O(n) per x1 but often returns early (as soon as it finds a solution).

In most cases where the first algorithm takes a long time, it's due to the range [ylow,yhigh] being very narrow. In this case, a separate algortihm is possible by iterating y from ylow to yhigh, then iterating the factors of y as a, and then checking whether an appropriate value for b exists among the factors of x1.

This was able to pass the tests in about half of the time limit: [92840659](https://codeforces.com/contest/1418/submission/92840659 "Submission 92840659 by neal"). I don't have a solid proof for the efficiency of this solution though. Maybe someone can find a way to hack it?

Instead by using a segment tree, you can end up with a clean O((n+m)log2m) solution. The main idea is that since ylow and yhigh are bounded by [1,m], we are really doing a 2D range query on ylow, yhigh, and b where we want to find the smallest factor a of any y in [ylow,yhigh] such that a>b. We can do a sweep on a and b instead to just handle these queries with a 1D seg tree instead (query minimum in range, update individual element). See the code for more details: [92847130](https://codeforces.com/contest/1418/submission/92847130 "Submission 92847130 by neal")

#### [1418G - Three Occurrences](../problems/G._Three_Occurrences.md "Educational Codeforces Round 95 (Rated for Div. 2)")

First let's try to count the number of subarrays where the number of times every integer occurs is a *multiple* of 3. We can think about creating a 'signature' for each prefix of the array, where the signature tells us how many times each value a occurs in the prefix of the array, modulo 3. So if the prefix is [3, 2, 1, 2, 2], our signature should be [1, 0, 1], since 1 occurs once, 2 occurs three times (0 mod 3), and 3 occurs once.

Now a subarray satisfies our condition iff the prefix for its start and the prefix for its end have the same signature. But we don't have time to actually store every signature, so instead we'll compute a hash of every signature and count equal pairs using a hash map.

We need a hash which we can update quickly after updating a single element. One obvious option is the polynomial string hash, but there's something even better: generate a random 64-bit number for every index `random[i]`, and then we define our hash as the sum of `freq[i] * random[i]` where `freq[i]` is in {0, 1, 2}. We can show that if two frequency arrays are different, their hashes collide with probability at most 1263.

Now the only thing left to handle is the "exactly thrice" condition. The way we do this is by iterating over the end point from left to right and keeping track of the last three locations of every value. We can then ensure that we only consider start points that are large enough so that our subarray will never contain more than three of any value. To remove invalid prefixes, we can simply subtract them out from our hash map. The final solution is very short and O(n): [92855419](https://codeforces.com/contest/1418/submission/92855419 "Submission 92855419 by neal")

