# Tutorial

**D2A author**: [300iq](https://codeforces.com/profile/300iq "Grandmaster 300iq"), [cdkrot](https://codeforces.com/profile/cdkrot "International Master cdkrot"), **developer**: [300iq](https://codeforces.com/profile/300iq "Grandmaster 300iq")

 
### [1013A - Piles With Stones](https://codeforces.com/contest/1013/problem/A "Codeforces Round 500 (Div. 2) [based on EJOI]")

It can be simply showed that the answer is «Yes» if and only if the sum in the first visit is not less than the sum in the second visit.

**D2B author**: [isaf27](https://codeforces.com/profile/isaf27 "International Master isaf27"), **developer**: [cdkrot](https://codeforces.com/profile/cdkrot "International Master cdkrot")

 
### [1013B - And](https://codeforces.com/contest/1013/problem/B "Codeforces Round 500 (Div. 2) [based on EJOI]")

Clearly, if it is possible then there are no more than 2 operations needed.

So we basically need to distinguish 4 outcomes —  - 1, 0, 1 and 2.

The answer is zero if there are already equal elements in the array.

To check if the answer is -1 we can apply the operation to each element of the array. If all elements are still distinct, then it couldn't be helped.

To check if the answer is one we can bruteforce the element *a* to apply the operation to, and if this operation changes this element, we can check if there is an *a* & *x* element in the array.

In all other cases answer is two.

**D1A author**: [isaf27](https://codeforces.com/profile/isaf27 "International Master isaf27"), **developer**: [isaf27](https://codeforces.com/profile/isaf27 "International Master isaf27")

 
### [1012A - Photo of The Sky](../problems/A._Photo_of_The_Sky.md "Codeforces Round 500 (Div. 1) [based on EJOI]")

At first let's sort array aa, so we can assume that a1≤a2≤⋯≤a2⋅na1≤a2≤⋯≤a2⋅n.

Note that area of rectangle with bottom-left corner in (x1,y1)(x1,y1), and up-right corner in (x2,y2)(x2,y2) is (x2−x1)⋅(y2−y1)(x2−x1)⋅(y2−y1).

So the task is to partite array aa into 22 multisets (sets with equal elements) XX and YY of size nn, such that (max(X)−min(X))⋅(max(Y)−min(Y))(max(X)−min(X))⋅(max(Y)−min(Y)) is minimal among all such partitions (min(X)min(X) — minimum in multiset XX, max(X)max(X) — maximum in multiset XX). 

Let's look at such partition

There are 22 cases:

* Minimum and maximum are in one multiset. Let's assume that they are both in XX. Then max(X)−min(X)=a2⋅n−a1max(X)−min(X)=a2⋅n−a1. We need to minimize max(Y)−min(Y)max(Y)−min(Y). If index of min(Y)min(Y) in aa is ii, and max(Y)max(Y) is jj, htne j−i≥n−1j−i≥n−1, because there are nn elements in YY. So we can use Y={ai,ai+1,…,ai+n−1}Y={ai,ai+1,…,ai+n−1} and desired difference will not increase. So as YY it is optimial to use some segment of length nn.
* Minimum and maximum are not in one multiset. Let's assume that minimum in XX, and maximum in YY. Then note, that maximum in XX always ≥an≥an, because size of XX is nn. And minimum in YY will be ≤an+1≤an+1, because size of YY is nn. So (max(X)−min(X))⋅(max(Y)−min(Y))≥(an−a1)⋅(a2⋅n−an+1)(max(X)−min(X))⋅(max(Y)−min(Y))≥(an−a1)⋅(a2⋅n−an+1), so you can use prefix of length nn as XX and suffix of length nn as YY.

So answer is minimum of (a2⋅n−a1)⋅(ai+n−1−ai)(a2⋅n−a1)⋅(ai+n−1−ai) for each 2≤i≤n2≤i≤n and (an−a1)⋅(a2⋅n−an+1)(an−a1)⋅(a2⋅n−an+1). That is, you can simply check all contigious subsets as first set and all the remaints as the second one. 

Complexity is O(n⋅log(n))O(n⋅log(n)).

Jury's solution ([isaf27](https://codeforces.com/profile/isaf27 "International Master isaf27")): [40973089](https://codeforces.com/contest/1012/submission/40973089 "Submission 40973089 by isaf27")

**D1B author**: [300iq](https://codeforces.com/profile/300iq "Grandmaster 300iq"), **developer**: [Flyrise](https://codeforces.com/profile/Flyrise "Master Flyrise")

 
### [1012B - Chemical table](../problems/B._Chemical_table.md "Codeforces Round 500 (Div. 1) [based on EJOI]")

One of the way to solve this problem is to interprete the cells in 2d matrix as an edge in the bipartite graph, that is a cell (*i*, *j*) is an edge between *i* of the left part and *j* of the right part.

Note, that each fusion operation (we have edges (*r*1, *c*1), (*r*1, *c*2), (*r*2, *c*1) and get edge (*r*2, *c*2)) doesn't change the connected components of the graph.

Moreover, we can prove, that we can obtain each edge in the connected component by fusion.

Let's examine example edge (*x*, *y*), and some path between *x* and *y* (since they lay in one connected component). Since the graph is bipartite, the length of this path must be odd, and it is  ≥ 3, otherwise the edge already exists.

So we have this path. Take first three edges and make the corresponding fusion, replace this three edges with the brand new fused edge. The length of the path decreased by 2. Repeat until the path is a mere edge.

This way, the number of edges to add (cells to buy) is just number of connected components minus one.

**D1С author**: [pashka](https://codeforces.com/profile/pashka "Grandmaster pashka"), **developer**: [cdkrot](https://codeforces.com/profile/cdkrot "International Master cdkrot")

 
### [1012C - Hills](../problems/C._Hills.md "Codeforces Round 500 (Div. 1) [based on EJOI]")

The problem's short statement is: "we allowed to decrease any element and should create at least *k* local maximums, count the minimum number of operations for all *k*".

Notice, that any set of positions, where no positions are adjacent could be made to be local maximums — we just need to decrease the neighbouring hills to some value.

Let's introduce the following dynamic programming:

dp[prefix][local_maxs] – the minimum cost if we analyze only given prefix, have the specified number of local maximums ("good hills to build on") and we make a local maximum in the last hill of this prefix.

Th dumb implementation of this leads to *O*(*n*2) states and *O*(*n*4) time — in each state we can brute force the previous position of local maximum (*n*) and then calculate the cost of patching the segment from previous local maximum to current one.

A more attentive look says that it is, in fact *O*(*n*3) solution — on the segment only first and last elements need to be decreased (possibly first and last elements are same).

To get the full solution full solution in *O*(*n*2) we need to optimize dp a little bit. As we noticed in the previous paragraph, there is one extreme situation, when the first and elements are same, let's handle this transition by hand in *O*(1) for each state.

Otherwise, funny fact, the cost of the segment strictly between local maximums is the cost of it's left part plus it'cost of it's right part. Seems like something we can decompose, right?

Since our goal is to update state (*prefix*, *local*) now the right part is fixed constant for all such transitions. And we need to select minimum value of *dp*[*i*][*local* - 1] + *cost*(*i*, *i* + 1) where *i* <  = *prefix* - 3.

This can be done by calculating a supplementary dp during the primarily dp calculation — for example we can calculate f[pref][j] = min dp[i][j] + cost(i, i + 1) for *i* ≤ *pref*.

**D1D author**: [tourist](https://codeforces.com/profile/tourist "Legendary Grandmaster tourist"), **developers**: [qoo2p5](https://codeforces.com/profile/qoo2p5 "International Master qoo2p5"), [VArtem](https://codeforces.com/profile/VArtem "International Grandmaster VArtem")

 
### [1012D - AB-Strings](../problems/D._AB-Strings.md "Codeforces Round 500 (Div. 1) [based on EJOI]")

The solution is basically like following:

Note that we can compress equal adjacent letters.

Now we can do a dynamic programming with params (first letter of *s*, length of *s*, first letter of *t*, length of *t*).

However, the amount of transactions and even states is too large. But we can write a slow, but surely correct solution, and examine the transactions, which are made in dp.

Basically, the most typical transaction is to just make a swap of first group in *s* with first group in *t*. However there special cases, like when the first letters are the same or when the lengths are very small.

Running a slow dynamic programming helps to get all the cases for the solution.

Formally, the correctness of this algorithm can be proven by induction and the large cases analyses, which we skip for clarity.

Another approach is to consider different first operations, and then go a greedy after it algorithm. See the second solution for the details. We don't prove it.

The first solution: [40971595](https://codeforces.com/contest/1012/submission/40971595 "Submission 40971595 by qoo2p5") and the second solution: [40971634](https://codeforces.com/contest/1012/submission/40971634 "Submission 40971634 by qoo2p5").

**D1E author**: [isaf27](https://codeforces.com/profile/isaf27 "International Master isaf27"), **developer**: [isaf27](https://codeforces.com/profile/isaf27 "International Master isaf27")

 Tutorial is loading...Jury's solution (by [isaf27](https://codeforces.com/profile/isaf27 "International Master isaf27")): [40973023](https://codeforces.com/contest/1012/submission/40973023 "Submission 40973023 by isaf27")

**D1F author**: [GlebsHP](https://codeforces.com/profile/GlebsHP "International Grandmaster GlebsHP"), **developers**: [demon1999](https://codeforces.com/profile/demon1999 "International Grandmaster demon1999"), [PavelKunyavskiy](https://codeforces.com/profile/PavelKunyavskiy "International Grandmaster PavelKunyavskiy")

 
### [1012F - Passports](../problems/F._Passports.md "Codeforces Round 500 (Div. 1) [based on EJOI]")

Let's solve the *P* = 1 case first. We'll use dynamic programming on subsets. Let's try to add visas to subset in order of application. Notice that if we only have one passport, every visa processing segment should lie between some two consecutive trips. For convenience, let's find all these segments beforehand.

Define *dp*[*A*] as the minimum day, before which all visas from set *A* can be acquired. Try all possible *i* as a visa which Gleb will apply for next. Now we have to find minimum possible day of application *d*, such that *d* ≥ *dp*[*A*], segment [*d*, *d* + *t**i*] does not intersect with any trip, and *d* + *t**i* < *s**i*. Such *d* can be found in *O*(*n*) by a linear search over precalculated free segment. Relax the value of ![](images/6fcc02eb394105bc7236355397d811102ad25b27.png) with *d* + *t**i*. If *dp*[{1..*n*}] <  + ∞ then there is a solution that can be restored using standard techniques. Total time complexity is *O*(2*n* *n*2), that can be too slow for *n* = 22.  

Let's generalize this solution for *P* = 2. Still, Gleb can apply for a visa only when he is in Innopolis. However, the last day of visa processing can be during some trip, but only if all trips between the day of visa application and the day of visa acquisition use another passport. We will slightly change the definition of *dp*[*A*]: now this value is equal to the minimum possible day, by which it's possible to finish processing all visas from set *A* with one passport, assuming all trips not from *A* use another passport. By this definition, calculation of DP transition is a little bit different: when trying to add visa *i* we have to find minimum *d*, such that *d* ≥ *dp*[*A*], during day *d* Gleb is in Innopolis, and segment [*d*, *d* + *t**i*] does not intersect with half-closed intervals [*s**j*, *s**j* + *len**j*) for all ![](images/22e93524f9c692e473e1895cf84518d9664df3f1.png). This can be implemented similarly to the first part in *O*(*n*). Total running time is *O*(2*n* *n*2), that can pass system tests with some optimizations.

We'll optimize the solution down to *O*(2*n* *n*). To do that, we process all transition from set *A* in *O*(*n*) total time. Sort all visas in order of increasing *t**i*. Then the optimal visa application day *d* will be increasing if visa processing time *t**i* increases. Now we can apply two pointers technique to get *O*(*n*) total processing time for one set and *O*(2*n* *n*) for all sets.

After calculating *dp*[*A*] for all subsets, we have to try all partitions of {1..*n*} into two sets *A* and *B* and check if both *A* and *B* can be done with one passport each. This is equivalent to *dp*[*A*] <  + ∞. If there are two such sets that *dp*[*A*] <  + ∞ and *dp*[*B*] <  + ∞, then we have found the answer, otherwise there is no answer.

Credits to all jury members, who contributed to this round and EJOI: [tourist](https://codeforces.com/profile/tourist "Legendary Grandmaster tourist"), [PavelKunyavskiy](https://codeforces.com/profile/PavelKunyavskiy "International Grandmaster PavelKunyavskiy"), [niyaznigmatul](https://codeforces.com/profile/niyaznigmatul "International Grandmaster niyaznigmatul"), [300iq](https://codeforces.com/profile/300iq "Grandmaster 300iq"), [GlebsHP](https://codeforces.com/profile/GlebsHP "International Grandmaster GlebsHP"), [pashka](https://codeforces.com/profile/pashka "Grandmaster pashka"), [qoo2p5](https://codeforces.com/profile/qoo2p5 "International Master qoo2p5"), [VArtem](https://codeforces.com/profile/VArtem "International Grandmaster VArtem"), [demon1999](https://codeforces.com/profile/demon1999 "International Grandmaster demon1999"), [Flyrise](https://codeforces.com/profile/Flyrise "Master Flyrise"), [ifsmirnov](https://codeforces.com/profile/ifsmirnov "Grandmaster ifsmirnov"), [isaf27](https://codeforces.com/profile/isaf27 "International Master isaf27"), [yeputons](https://codeforces.com/profile/yeputons "International Grandmaster yeputons"), [cdkrot](https://codeforces.com/profile/cdkrot "International Master cdkrot").

