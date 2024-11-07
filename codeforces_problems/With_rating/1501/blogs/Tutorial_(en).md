# Tutorial_(en)

Thanks for the participation!

[1501A - Alexey and Train](../problems/A._Alexey_and_Train.md "Codeforces Round 707 (Div. 2, based on Moscow Open Olympiad in Informatics)") was authored by [Aleks5d](https://codeforces.com/profile/Aleks5d "Grandmaster Aleks5d") and prepared by [4qqqq](https://codeforces.com/profile/4qqqq "Expert 4qqqq")

[1501B - Napoleon Cake](../problems/B._Napoleon_Cake.md "Codeforces Round 707 (Div. 2, based on Moscow Open Olympiad in Informatics)") was authored and prepared by [KAN](https://codeforces.com/profile/KAN "Legendary Grandmaster KAN")

[1500A - Going Home](https://codeforces.com/contest/1500/problem/A "Codeforces Round 707 (Div. 1, based on Moscow Open Olympiad in Informatics)") was authored and prepared by [wrg0ababd](https://codeforces.com/profile/wrg0ababd "Expert wrg0ababd")

[1500B - Two chandeliers](https://codeforces.com/contest/1500/problem/B "Codeforces Round 707 (Div. 1, based on Moscow Open Olympiad in Informatics)") was authored by jury and prepared by [Siberian](https://codeforces.com/profile/Siberian "International Master Siberian")

[1500C - Matrix Sorting](https://codeforces.com/contest/1500/problem/C "Codeforces Round 707 (Div. 1, based on Moscow Open Olympiad in Informatics)") was authored by [Endagorion](https://codeforces.com/profile/Endagorion "Legendary Grandmaster Endagorion") and prepared by [NiceClock](https://codeforces.com/profile/NiceClock "Master NiceClock")

[1500D - Tiles for Bathroom](https://codeforces.com/contest/1500/problem/D "Codeforces Round 707 (Div. 1, based on Moscow Open Olympiad in Informatics)") was authored by [meshanya](https://codeforces.com/profile/meshanya "Grandmaster meshanya") and prepared by [KiKoS](https://codeforces.com/profile/KiKoS "Master KiKoS")

[1500E - Subset Trick](https://codeforces.com/contest/1500/problem/E "Codeforces Round 707 (Div. 1, based on Moscow Open Olympiad in Informatics)") was authored and prepared by [isaf27](https://codeforces.com/profile/isaf27 "International Grandmaster isaf27") 

[1500F - Cupboards Jumps](https://codeforces.com/contest/1500/problem/F "Codeforces Round 707 (Div. 1, based on Moscow Open Olympiad in Informatics)") was authored and prepared by [Akulyat](https://codeforces.com/profile/Akulyat "Grandmaster Akulyat")

 
### [1501A - Alexey and Train](../problems/A._Alexey_and_Train.md "Codeforces Round 707 (Div. 2, based on Moscow Open Olympiad in Informatics)")

The solution of this task is to basically implement what was written in the statement.

Let depi be the moment of train departure from the station i (dep0=0 initially). Then train arrives at the current station i at moment ari=depi−1+(ai−bi−1)+tmi and departure at moment depi=max.

The answer is ar_n.

 
### [1501B - Napoleon Cake](../problems/B._Napoleon_Cake.md "Codeforces Round 707 (Div. 2, based on Moscow Open Olympiad in Informatics)")

The i-th layer is drenched in cream if there is such j \ge i that j - a_j < i. Then we can calculate answers for all layers i in reverse order (from n to 1) and maintain minimum over all values j - a_j as some variable mn.

As a result, when we move from i + 1 to i, we update mn = \min(mn, i - a_i) and then check that mn < i.

 
### [1500A - Going Home](https://codeforces.com/contest/1500/problem/A "Codeforces Round 707 (Div. 1, based on Moscow Open Olympiad in Informatics)")

Let's prove that if there're at least four different pairs indices with the common sum (a_{x_1} + a_{y_1} = a_{x_2} + a_{y_2} = \ldots = a_{x_4} + a_{y_4}), then there necessarily will be two pairs such that all four indices in them are unique.

Let's analyze some cases:

* There're four pairs of the form (x, y_1), (x, y_2), (x, y_3), (x, y_4) with sum S. Then a_x + a_{y_1} = a_x + a_{y_2} = a_x + a_{y_3} = a_x + a_{y_4} = S from which we can conclude that a_{y_1} = a_{y_2} = a_{y_3} = a_{y_4}, and it means that pairs (y_1, y_2) and (y_3, y_4) are suitable as answer.
* There're three pairs of the form (x, y_1), (x, y_2), (x, y_3) and the fourth pair doesn't contain index x. Then whatever the fourth pair (z, w) is, it necessarily doesn't contain index x and at least one of indices y_1, y_2, y_3 which means we can take as answer pairs (z, w) and one of three that contain x.
* Other cases are analyzed in the same way. To make sure that answer always exists among such four pairs, we can imagine graph, where vertices are indices, and there is an edge between two vertices if the corresponding pair of indices has sum S. If such a graph has at least four edges and the degree of all vertices is at most two (we excluded the larger degrees by examining the previous cases), then there will always be two edges with disjoint ends.

How to find answer using this? Let's launch simple \mathcal{O}(n^2) bruteforce which for every sum will save all found pairs with such sum, and for each pair check if there's another already found pair with the same sum and such indices that all four indices in these two pairs are unique. 

Let's notice it works in \mathcal{O}(min(n^2, n + C), because once for some sum we find the fourth pair, we can immediately print the answer. And if the answer is "NO", then we've done no more than \mathcal{O}(C) iterations of bruteforce.

 
### [1500B - Two chandeliers](https://codeforces.com/contest/1500/problem/B "Codeforces Round 707 (Div. 1, based on Moscow Open Olympiad in Informatics)")

A formal statement of the problem: there are two sequences of distinct integers, whose are infinitely cycled. You need to find prefix of minimal length which contains exactly k positions i such that a_i \neq b_i.

Let's notice that we can use binary search. So we need to count number of positions i such that a_i \neq b_i on prefix of length x.

Because all integers in a_i are distinct (and also in b_i), we need to calculate number of non-negative solutions:

\begin{cases} pos \equiv x \pmod{n} \\\ pos \equiv y \pmod{m}\end{cases} 

If n and m are coprime, the value can be calculated with Chinese remainder theorem. Solution's complexity will be O((n + m) \cdot \log(n + m) \cdot \log(k \cdot (n + m)).

If n and m are not coprime, participant can make transition (n, m) \to (\frac{n}{gcd(n, m)}, \frac{m}{gcd(n, m)}), solve new equations, and then make reverse transition.

After that, you need to optimize this solution. There are many ways to do this, for example, you can precalculate solutions of all equations. And complexity becomes O((n + m) \cdot (\log(k) + \log(n + m)))

 
### [1500C - Matrix Sorting](https://codeforces.com/contest/1500/problem/C "Codeforces Round 707 (Div. 1, based on Moscow Open Olympiad in Informatics)")

Let's first learn how to solve with O (n \cdot m^2).

Note that each column can be sorted no more than once.

Now, let's note that if we could turn matrix A into matrix B, then B has a sorted column.

Idea  — we will choose the rows that we will sort from the end. To do this, we can support string equivalence classes. Where and why? If two rows are in the same class, then the columns that we applied had the same values. Then, we need to find a column that does not break the sequence between the rows inside each of the classes. Let's iterate through such a column every time. We don't care if we apply someone extra  — because of the condition of the possibility of application, it will definitely not spoil. Then just apply the column if we could. Each time, the number of equivalence classes does not decrease, so the number of columns that can be applied does not decrease. If it was not possible to sort after all the applications, it means that some of the classes could not be split correctly, which means that it is impossible to get matrix B from matrix A.

Let's learn how to solve it faster than in a cube. Let's not store equivalence classes explicitly. To do this, note that in the final state of B, the equivalence classes are sub-arrays! Then it is enough for us to store for each pair of adjacent rows whether we were able to separate them (swap the lower and upper places)  — let's call it cut. Also, for each column, we will store the number of still unresolved inversions in it, call it cnt. Initially,  — is just the number of inversions in the column. Next, it will be the same number of inversions, but only within the classes. How does this solution differ from a cube? We are able to quickly find which column can be applied - this is the column j for which cnt[j] = 0. Then we just need to learn how to update the cnt. Let's start a queue (we can say that this is bfs, but in fact we do not use anything other than a queue from bfs), to which we will add only columns j in which cnt[j] = 0, apply sorting by column, update cnt and add new columns that have cnt=0. cutwill help us with this. Let's, if we managed to swap the columns (that is, in the current column v, b[i][v] < b[i - 1][v]), set cut[i] = 1 and update all the values of cnt through this row. It is clear that it does not make sense to split rows twice. Since we will apply each column at most once, and the pairs of adjacent rows are O(n), the time complexity is O (n \cdot m). Do not forget that it is not necessary to divide into exactly n equivalence classes, because a smaller number may be enough. So in the end, check transformations(not difficult, but need to be careful).

There is also a solution with time complexity O(nm log), but I think, it is more difficult both in terms of understanding and implementation.

 
### [1500D - Tiles for Bathroom](https://codeforces.com/contest/1500/problem/D "Codeforces Round 707 (Div. 1, based on Moscow Open Olympiad in Informatics)")

Let's denote ans_{i,\,j} as max "good" subsquare side size with left top angle at (i,\,j) cell. It's obvious that every subsquare with side less than ans_{i,\,j} is "good" too. So we need to find ans_{i,\,j} and then print answer for k-size side as \displaystyle \sum_{x=k}^{n} |\{(i,\,j)\ |\ ans_{i,\,j} = k\}. This value can be found with partial sums on count array of ans_{i,\,j}.

Now we need to calculate ans_{i,\,j}. Let's notice that ans_{i,\,j+1} \ge ans_{i,\,j} - 1, because (i, j + 1)-th square is inside of (i, j) square if it's side is longer than 1. So, we can use amortized algorithm of sequential increase square's side. Every time when we can increase ans_{i,\,j} we will do it, then we will go to calculating ans_{i,\,j+1}. Using linear algorithm to check if new square's size is "good", we will get O(n^3) solution, which is not effective enough, but can be optimized.

Now let's use small constraints for q. For each (i,\,j) cell we will precalc array colors_{i,\,j}, which will have (q + 1) nearest colors in line (i',\,j), i' \ge i. For each color, we will keep it's earliest occurrence It can be calculated in O(n^2 q), because colors_{i,\,j} = colors_{i,\,j + 1} \cup c_{i,\,j}. If c_{i,\,j} exists in colors_{i,\,j}, we must change earliest occurrence. If it isn't, we should delete the most far color, then insert the current one. All values can be keeped with increasing left occurrence in O(q) for each cell.

Last step — we can merge colors_{i,\,j},\ \ldots,\ colors_{i + m - 1,\,j} in O(mq) — it will be the array of q + 1 values corresponding for earliest colors in line of width m. Merging two lines is almost like merge of two sorted arrays — it is used to find q + 1 minimal left occurrences. Maximal "good" width can be found as left occurrence of (q+1)-th elementh minus j.

Now we need to unite some rows in a structure and merge lines for current square, then erase first row and repeat the process. The structure can be realized as queue on two stacks, each of whose is keeping merge value of all lines in itself. The algorithm is almost like queue with minimal value (https://cp-algorithms.com/data_structures/stack_queue_modification.html). That's how we get solution with complexity O(n^2q).

 
### [1500E - Subset Trick](https://codeforces.com/contest/1500/problem/E "Codeforces Round 707 (Div. 1, based on Moscow Open Olympiad in Informatics)")

Let S = \{a_1, a_2, \ldots, a_n\}, where a_1 < a_2 < \ldots < a_n.

Let's calculate the number of good numbers from 0 to sum(X) - 1. To get the answer to our problem we should subtract this value from sum(S).

Let's suppose that 0 \leq x < sum(X) is good. It is easy to see that it is equivalent to a_{n - k + 1} + \ldots + a_{n} \leq x < a_{1} + \ldots + a_{k+1} for some 0 \leq k < n.

So to calculate the required number of good numbers we should find the length of the union of intervals [a_{n - k + 1} + \ldots + a_{n}, a_{1} + \ldots + a_{k+1}) for all 0 \leq k < n.

We can note two things:

* some of these intervals are empty
* all non-empty intervals does not intersect with each other

So the number we want to find is just \sum\limits_{k=0}^{n-1} \max{(a_{1} + \ldots + a_{k+1} - a_{n - k + 1} - \ldots - a_{n}, 0)}.

Let's call f(k) = a_{1} + \ldots + a_{k+1} - a_{n - k + 1} - \ldots - a_{n}. Let's note two simply things:

* f(k) = f(n - 1 - k)
* f(x) \geq f(y) if x \leq y \leq \frac{n-1}{2}

Let's use them. First of all let's find \sum\limits_{k=0}^{\frac{n-1}{2}} \max{(f(k), 0)}. We can simply calculate the sum we need from it because we should just multiply this sum by 2 and possibly subtract the number from the middle (if n is odd).

Let's note that in the sum \sum\limits_{k=0}^{\frac{n-1}{2}} \max{(f(k), 0)} some first summands are > 0, others are equal to 0 (because 0 will be bigger in the maximum).

Let's find the minimal l \leq \frac{n-1}{2}, such that f(l) \leq 0 using binary search. After that we should calculate \sum\limits_{k=0}^{l-1} f(k) = \sum\limits_{k=0}^{l-1} (a_{1} + \ldots + a_{k+1} - a_{n - k + 1} - \ldots - a_{n}) = \sum\limits_{i=0}^{l} a_i (l - i) - \sum\limits_{i=n-l+1}^{n} a_i (i + l - n).

So what values we should be able to calculate to solve the problem?

* The sum of numbers on prefix \sum\limits_{i=0}^{k} a_i. Using two queries of this type we can calculate f(k).
* The sum of numbers multiplied by index on prefix \sum\limits_{i=0}^{k} a_i i. We can calculate the final answer using this query.

To answer these queries effectively let's use the segment tree. Initially let's find all numbers that will be in S in some moment (we can do it because we have the list of all queries). We will make a segment tree on this array, where we will write 0, if there is no such number currently in S and 1, otherwise.

For each segment of these segment tree we will store 3 values:

* the number of numbers from this segment, that lie in the current S
* the sum of numbers from this segment, that lie in the current S
* the sum of numbers multiplied by index from this segment, that lie in the current S

These values can be easily recalculated when an update in the segment tree happens.

To calculate two sums required for us we need to make the descent in the segment tree summing the segments on the prefix, where the number of numbers that lie in the current S is equal to k.

In total, we get the O((n+q) \log^2{(n+q)}) solution, because we make the binary search and use queries to the segment tree inside it.

 
### [1500F - Cupboards Jumps](https://codeforces.com/contest/1500/problem/F "Codeforces Round 707 (Div. 1, based on Moscow Open Olympiad in Informatics)")

- Note 1 

 We can change cupboards' heights with differences between following ones: d_i = h_{i + 1} - h_{i}. How to get w using d? 

 w_i = \max(\left|{d_i}\right|, \left|{d_{i + 1}}\right|, \left|{d_i + d_{i + 1}}\right|) 

 \quad 

 - O(n C) 

 dp[i][dif] - can we choose i differences, with the last equal to dif 

 Can be updated with O(1) checks 

 \quad 

 - Note 2 

 If we can get dif difference, then -dif too, because we can invert all differences on prefix and save all conditions. So keep in mind just dif \in [0, C] 

 \quad 

 - O(n^2) 

 Let's keep values on each layer we can get as segments. We show that there will be O(n) of them for each layer. 

* Segment [0; w_i] is full able if previous layer has value w_i
* Each segment [l, r] goes to [\max(w_i - r, 0), w_i - l]
* If some segment had x: x \leq w_i, then we should add: [w_i, w_i]

 So, moving to a new layer, we will get no more than one extra segment.  Restoring the answer: since we keep all segments for each layer, we can check that previous one contains: 

* w_i
* w_i - dif
* anything \leq w_i, if dif = w_i

 We should return signs to differences, because we have started to consider just non-negative values. We can move from left to right ans put them greedy choosing any correct one \quad  - O(n) 

 Segments don't change much. Each layer change is: 

* inversion + shift + truncation with zero ([l, r] \to [\max(w_i - r, 0), w_i - l])
* check for a corner value (w_i \to [0, w_i])
* add corner value (x \leq w_i \to [w_i, w_i])

 All except inversion and shift happen at corners of our segments list(we keep them sorted). Inversion and shift are the same for all segments. Let's keep cf = \pm 1 and shift sh, recalculating them on each layer and keeping list of our segments the same  After recalculating value of cf and sh: let's trunc segments from corners to keep just values in [0, w_i] and add [w_i, w_i](converted) if we need to. Number of truncation will be O(n). 

 Restoring: 

* If w_i was at previous layer - keep it and use
* If dif = w_i, use minimum value from previous layer
* Otherwise we should definitely use w_i - dif
