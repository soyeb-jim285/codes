# Tutorial

You can also find video editorials for problems B-D on [ak2006](https://codeforces.com/profile/ak2006 "Specialist ak2006")'s [Youtube channel](https://codeforces.com/https://www.youtube.com/channel/UCnZ5rC2_JY0EuYMGMiAbISg)!

#### [1632A — ABC](../problems/A._ABC.md)

 **Hint 1**Only a few strings have the answer "YES".

 **Hint 2**For n≥3, the answer is "NO".

 **Solution**Let n≥3 and the resulting string be a. For there to be no palindromes of length greater than 1, at least all of these inequalities must be true: a1≠a2, a2≠a3, and a1≠a3. Since our string is binary, this is impossible, so the answer is "NO".

For n≤2, there are 4 strings that have the answer "YES": 0, 1, 01, and 10; as well as 2 strings that have the answer "NO": 00 and 11.

Time complexity: O(n)

 **Solution codes*** [C++ code](https://codeforces.com/problemset/submission/1632/144584864).
* [Python code](https://codeforces.com/problemset/submission/1632/144585149).
#### [1632B — Roof Construction](../problems/B._Roof_Construction.md)

 **Hint 1**The cost of construction is a power of two.

 **Hint 2**The cost of construction is 2k, where k is the highest set bit in n−1.

 **Solution**Let k be the highest set bit in n−1. There will always be a pair of adjacent elements where one of them has the k-th bit set and the other one doesn't, so the cost is at least 2k. A simple construction that reaches it is 2k−1, 2k−2, …, 0, 2k, 2k+1, …, n−1.

Time complexity: O(n)

Bonus: count the number of permutations with the minimum cost.

 **Solution codes*** [C++ code](https://codeforces.com/problemset/submission/1632/144585341).
* [Python code](https://codeforces.com/problemset/submission/1632/144585411).
#### [1632C — Strange Test](../problems/C._Strange_Test.md)

 **Hint**It is optimal to apply the third operation at most once.

 **Solution**It is optimal to apply the third operation at most once, because is does not decrease a and always makes b≤a. This means that after we use it, we can only apply the second operation.

If we don't apply the third operation, the answer is b−a.

Suppose we do apply it. Before that, we used the first and second operations some number of times, let the resulting values of a and b be a′ and b′ respectively (a≤a′,b≤b′). The answer in this case will be (a′−a)+(b′−b)+((a′ | b′)−b′)+1 = a′+(a′ | b′)+(1−a−b). This is equivalent to minimizing a′+(a′ | b′), since (1−a−b) is constant.

To do that, we can iterate a′ from a to b. For a fixed a′, we have to minimize a′ | b′, the optimal b′ can be constructed like this:

Set b′ to zero and iterate over bits from highest to lowest. There are 4 cases:

 * If current bit of a′ is 0 and b is 1, set the current bit of b′ to 1.
* If current bit of a′ is 0 and b is 0, set the current bit of b′ to 0.
* If current bit of a′ is 1 and b is 1, set the current bit of b′ to 1.
* If current bit of a′ is 1 and b is 0, set the current bit of b′ to 1 and stop.

This works in O(logb) and can also be sped up to O(1) using bit manipulation.

Time complexity: O(b) or O(blogb)

Bonus 1: solve the problem in O(logb) or faster.

Bonus 2: prove that is optimal to have either a′=a or b′=b. 

 **Solution codes*** [C++ code](https://codeforces.com/problemset/submission/1632/144585749) with complexity O(blogb).
* [C++ code](https://codeforces.com/problemset/submission/1632/144585575) with complexity O(b).
* [Python code](https://codeforces.com/contest/1632/submission/144585797) with complexity O(blogb).
#### [1632D — New Year Concert](../problems/D._New_Year_Concert.md)

 **Hint 1**Let's call a segment [l,r] bad if gcd(al…ar)=r−l+1. There at most n bad segments.

 **Hint 2**For a fixed l, as r increases, gcd(al…ar) does not increase.

 **Hint 3**Suppose you change ai into a big prime. How does this affect the bad segments?

 **Solution**Read the hints above.

Let's find all of the bad segments. For a fixed l, let's find the largest r that has gcd(al…ar)≥r−l+1. This can be done with binary search and a sparse table / segment tree. If gcd(al…ar)=r−l+1, then the segment [l,r] is bad. 

If we change ai into a big prime, no new bad segments will appear. And all bad segments that have i inside of them will disappear. So we have to find the minimum number of points to cover all of them. This is a standard problem, which can be solved greedily: choose the segment with the smallest r, delete all segments that have r in them, and repeat. In our case, this is easy to do because our segments are not nested.

Time complexity: O(nlognlogA) with a sparse table, where A is the maximum value of ai.

Notes: 

There are many different modifications to the previous solution, some of them use two pointers (since segments are not nested) and some of them update the answer on the fly while searching for the bad segments. Using a segment tree and two pointers you can get the complexity O(n(logn+logA)). 

You can also use the fact that for a prefix, there at most O(logA) different suffix gcd values. This leads to another way to find the bad segments.

 **Solution codes*** [C++ code](https://codeforces.com/contest/1632/submission/144585868) with segment tree and binary search with complexity O(nlogn(logn+logA)).
* [C++ code](https://codeforces.com/contest/1632/submission/144585920) with sparse table and two pointers with complexity O(nlognlogA).
* [Python code](https://codeforces.com/contest/1632/submission/144586001) with segment tree and two pointers with complexity O(n(logn+logA)).
#### [1632E2 — Distance Tree (hard version)](../problems/E2._Distance_Tree_(hard_version).md)

 **Hint 1**It is optimal to add edges of type (1,v).

 **Hint 2**Try to check if for a fixed x the answer is at most ans.

 **Hint 3**For a fixed x and answer ans, find the distance between nodes that have depthv>ans.

 **Hint 4**For each node, find two children with the deepest subtrees.

 **Solution**Read the hints above.

Let fans be the maximum distance between two nodes that have depthv>ans. If for some x the answer is at most ans, then either ans≥depth or ⌈fans2⌉+x≤ans, since we can add an edge (1,u) where u is in the middle of the path connecting the two farthest apart nodes with depthv>ans. Since fans decreases as ans increases, we can use binary search. Also note that we can use two pointers and increase ans as we increase x.

How to calculate fans? Let's find for each node its two children with the deepest subtrees. Let av and bv be the depths of their subtrees (av≥bv). If there are not enough children, set this values to depthv. If bv>0, do fbv−1:=max(fbv−1,av+bv−2⋅depthv). After this, iterate i from n−2 to 0 and do fi=max(fi,fi+1).

Time complexity: O(n) or O(nlogn) with binary search.

Note: To solve E1, it is enough to calculate fans in O(n) or O(nlogn) for each ans. One way to do that is to find the diameter of the resulting tree after repeatedly deleting any leaf that has depthv≤ans (1 is also considered a leaf).

 **Solution codes*** [C++ code](https://codeforces.com/contest/1632/submission/144586133) for E1 with complexity O(n2).
* [Python code](https://codeforces.com/contest/1632/submission/144586223) for E1 with complexity O(n2).
* [C++ code](https://codeforces.com/contest/1632/submission/144586286) for E2 with complexity O(n).
* [Python code](https://codeforces.com/contest/1632/submission/144586358) for E2 with complexity O(n).
P. S. Solution codes will be published a little later.

P. P. S. Do not forget to evaluate the problems in the announcement.

**UPD**: Solution codes have been posted.

