# Tutorial_(en)

Thanks for the participation!

[1602A - Two Subsequences](../problems/A._Two_Subsequences.md "Codeforces Round 751 (Div. 2)") was authored and prepared by [napstablook](https://codeforces.com/profile/napstablook "Candidate Master napstablook")

[1602B - Divine Array](../problems/B._Divine_Array.md "Codeforces Round 751 (Div. 2)") was authored and prepared by [Anti-Light](https://codeforces.com/profile/Anti-Light "Expert Anti-Light")

[1601A - Array Elimination](https://codeforces.com/contest/1601/problem/A "Codeforces Round 751 (Div. 1)") was authored and prepared by [isaf27](https://codeforces.com/profile/isaf27 "International Grandmaster isaf27")

[1601B - Frog Traveler](https://codeforces.com/contest/1601/problem/B "Codeforces Round 751 (Div. 1)") was authored and prepared by [KiKoS](https://codeforces.com/profile/KiKoS "Master KiKoS")

[1601C - Optimal Insertion](https://codeforces.com/contest/1601/problem/C "Codeforces Round 751 (Div. 1)") was authored and prepared by [isaf27](https://codeforces.com/profile/isaf27 "International Grandmaster isaf27")

[1601D - Difficult Mountain](https://codeforces.com/contest/1601/problem/D "Codeforces Round 751 (Div. 1)") was authored and prepared by [Tikhon228](https://codeforces.com/profile/Tikhon228 "Master Tikhon228")

[1601E - Phys Ed Online](https://codeforces.com/contest/1601/problem/E "Codeforces Round 751 (Div. 1)") was authored by jury and prepared by [fedoseev.timofey](https://codeforces.com/profile/fedoseev.timofey "International Grandmaster fedoseev.timofey")

[1601F - Two Sorts](https://codeforces.com/contest/1601/problem/F "Codeforces Round 751 (Div. 1)") was authored by [cdkrot](https://codeforces.com/profile/cdkrot "International Grandmaster cdkrot") and prepared by [cdkrot](https://codeforces.com/profile/cdkrot "International Grandmaster cdkrot"), [LHiC](https://codeforces.com/profile/LHiC "Legendary Grandmaster LHiC")

 
### [1602A - Two Subsequences](../problems/A._Two_Subsequences.md "Codeforces Round 751 (Div. 2)")

Note that taking aa as minimum character in ss is always optimal (aa starts with minimum possible character and is prefix of any other longer string). In such case, bb is just all characters from ss except character from aa.

 
### [1602B - Divine Array](../problems/B._Divine_Array.md "Codeforces Round 751 (Div. 2)")

It can be shown that after at most nn steps of transformation, array aa becomes repetitive. There is even a better lower bound: it can be shown that after at most log(n)log(n) steps aa becomes repetitive, so we use either of these two facts to simulate the process and answer the queries.

 
### [1601A - Array Elimination](https://codeforces.com/contest/1601/problem/A "Codeforces Round 751 (Div. 1)")

Let's note, that in one destruction for any bit ii (0≤i<300≤i<30) we either change all kk-th non-zero bits into zero bits, or nothing changes. So, the number of ii-th non-zero bits in the array either decreases by kk or doesn't change. In the end, all these numbers will be equal to 00. So, to be able to destruct the array, the number of ii-th non-zero bits in the array should be divisible by kk for all bits ii.

Let's prove, that it is enough to destruct the array. Let's make operations with non-zero AND, while we can make them. In the end, there is at least one non-zero element, if we have not destructed the array. So, there is at least one bit ii, for which the number of ii-th non-zero bits in the array is non-zero, so this number is at least kk (because it is divisible by kk). So we can select kk numbers with ii-th non-zero bit to the next operation and make the new destruction, which is impossible.

So the resulting solution is: for each bit ii (0≤i<300≤i<30) let's find the number of array's elements with non-zero ii-th bit. Let's find all common divisors kk (1≤k≤n1≤k≤n) of these numbers.

Time complexity is O(nlogC)O(nlogC), where C=109C=109  — upper limit on all numbers in the array.

 
### [1601B - Frog Traveler](https://codeforces.com/contest/1601/problem/B "Codeforces Round 751 (Div. 1)")

Let's denote sequence of moves i⇒i−ai⇢i−ai+bi−ai as jump.

We will use dpi — minimal number of moves needed to travel from i to 0.

It can be calculated dpi=1+min(dpj+bj), with i−ai≤j≤i. We expected calculations to use bfs-style order. So, if there is a jump to 0, dp is 1. If there is no jump to 0, but there is a jump to position with dp=1, then dp is 2, and so on.

What happens, when we know all dp's with values from 0 to d? We'll take position v (dpv=d) and all u with condition u+bu=v. Then all j that has j−aj≤u≤j we know for sure dpj=d+1. For every i we will save in minimum segment tree value i−ai. So, all j's are just elements from a suffix with value not greater than u.

We can iterate through all j's, because every of them is used only once — right after we know dpj, we can use any neutral value (infinity in our case).

Time complexity is O(nlogn)

Bonus. Try to solve it in linear time :)

 
### [1601C - Optimal Insertion](https://codeforces.com/contest/1601/problem/C "Codeforces Round 751 (Div. 1)")

Let's sort array b.

Let's define pi as the index of the array a, before which we should insert bi. If bi should be inserted at the end of the array a, let's make pi=n+1.

Let's note, that all inserted elements should go in the sorted order in the optimal answer. If it is false and there exists pi>pj for i<j, let's swap bi and bj in the answer. The number of inversions will decrease, a contradiction.

So p1≤p2≤…≤pm. If we will find their values we will be able to restore an array after inserting elements.

Let's use "Divide and conquer" to find them. Let's write a recursive function solve(li,ri,lp,rp), that will find pi for all li≤i<ri, if it is known, that pi∈[lp,rp] for all such i. To find all values of p we should call the function solve(1,m+1,1,n+1).

Realization of solve(li,ri,lp,rp):

* If li≥ri, we shouldn't do anything.
* Let mid=⌊li+ri2⌋. Let's find pmid. The number of inversions with bmid will be (the number of ai>bmid for i<pmid) + (the number of ai<bmid for i≥pmid). This sum differs by a constant from: (the number of ai>bmid for lp≤i<pmid) + (the number of ai<bmid for pmid≤i<rp). For this sum it is simple to find the minimal optimal pmid in O(rp−lp).
* Let's make two recursive calls of solve(li,mid−1,lp,pmid), solve(mid+1,ri,pmid,rp), that will find all remaining values of p.

The complexity of this function will be O((n+m)logm), because there will be O(logm) levels of recursion and we will make O(n+m) operations on each of them.

In the end, using the values pi we will restore the array and find the number of inversions in it.

Total complexity: O((n+m)log(n+m)).

Also, there exist other correct solutions with the same complexity, using segment tree.

 
### [1601D - Difficult Mountain](https://codeforces.com/contest/1601/problem/D "Codeforces Round 751 (Div. 1)")

First, discard all i such that si<d

Instead of climbers, we will consider pairs (si,ai), and also say that the set of pairs is correct if there is a permutation p1…pn such that for every i:max(d,ap1,…api−1)≤spi, which means that there is an order in which all climbers can climb.

We will call a pair of indices i,j incompatible if i≠j and sj<ai and si<aj. - this means that the i-th climber cannot climb after the j-th and vice versa. Note that if the set does not have an incompatible pair of indices, then it is correct. The suitable order for pairs (si,ai) can be reached by sorting them in increasing order of pairs min(si,ai),max(si,ai). After sorting either i-th climber can go after (i−1)-th or the pair (i−1),i is incompatible.

 Let's solve the problem with an additional restriction first, namely: for each i:si<ai, In this case, you can use the following greedy solution:

Let D=d, find among the pairs (si,ai) such that D≤si, and among such pairs - the pair with the smallest ai - it will be the next in our order. Replace D by ai, increase the answer by 1 and repeat the algorithm. If the pair with D≤si does not exist, terminate the algorithm. The correctness of such an algorithm is proved by induction.

To effectively implement this solution, let's sort all the pairs (si,ai) in increasing order of ai

Let's go through the indices i from 1 to n

 If D≤si, then add 1 to the answer and replace D with ai.

 Let's get back to the main problem:

Consider a pair of indices i,j such that si<aj≤sj<ai

Such a pair of indices is incompatible, and if the optimal answer contains i, then it can be replaced with j and the sequence will not break.

 si<sj⇒ for any value of D that matches i it matches j.  aj<ai⇒ for any D:max(D,aj)≤max(D,ai)

Therefore, for any such pair i,j, the i-th can be excluded from the set of climbers and the answer will not worsen.

 To effectively remove all such (si,ai) pairs, we use the two-pointer method:

Let's take out all such pairs that ai≤si into the b array. Let the remaining pairs be in the c array. Let's sort the array b in increasing order of ai and the array c in increasing order of si. Let's create an ordered set M, which can store the pairs (si,ai) in decreasing order of ai. Let's create a pointer j=0.

Let's go through the elements of the b array with index i.

 For this item:

 While cj.s<bi.a we will add cj to the set M

 Now while bi.s<M1.a we will delete the first element M.

Among the elements of the b array, the M set and the remaining elements in the c array, there are no more required pairs.

Note that among the remaining pairs (si,ai), any pair of indices i,j such that ai≤si or aj≤sj is not incompatible.

Now, if we find the maximum correct subset of the pairs (si,ai), such that si<ai and combine it with the set of pairs (si,ai), such that ai≤si, we get the correct set, moreover, for obvious reasons – it has maximum size. Therefore, we will get the answer to the problem.

 
### [1601E - Phys Ed Online](https://codeforces.com/contest/1601/problem/E "Codeforces Round 751 (Div. 1)")

Observe that we need to buy a subscription at day one, then we need to buy the cheapest subscricption among first k+1 days, ..., then the cheapest among the first tk+1 days. Let's denote bi as a minimum on a segment [i−k,i−k+1,...,i], bi can be calculated in a linear time using monotonic queue. So the answer for query is al+bl+k+min(bl+k,bl+2k)+...+min(bl+k,bl+2k+...+bl+tk), where l+tk≤r.

Observe that such a sum is independent of the remainder of the division of l by k, so we can solve an easier problem instead: we are given with an array c, and we need to calculate a sum of prefix minimums on a segment. To solve this, let's calculate an array nxti — the minimum position nxti>i such that cnxti<ci. Let dpi be a sum of minimums on prefixes of i-th suffix. Observe that dpi=dpnxti+ci⋅(nxti−i). To calculate a sum of prefix minimums on the segment [l,r], find a position p, such that ap is a minimum on the segment [l,r], then the answer is dpl−dpp+(r−p+1)⋅cp. 

So we have a solution in O(n+qα−1(n)), where α−1 is the inverse Ackermann function, if we use a Tarjan's algorithm for offline rmq. It was enough to use any logarithmic data structure to solve a problem.

 
### [1601F - Two Sorts](https://codeforces.com/contest/1601/problem/F "Codeforces Round 751 (Div. 1)")

Suppose b is an inverse permutation of a, that is abi=bai=i, that is bi is an index of i in the lexicographical sorting. Rewrite desired sum replacing i→bi: ∑i=1…n((i−ai)modp)=∑i=1…n((bi−abi)modp)=∑i=1…n((bi−i)modp).

First, we need to understand how to calculate bi's. Observe that bi equals 1 plus number of integers x (1≤x≤n) so that x<lexi. These integers are of two possible kinds: own prefixes of i (the number of such x depends only on the length of i) and integers x having a common prefix with i of some length t and a smaller digit c in (t+1)-th index.

If we fix values of t, c, length of x, we have a "mask" of the following kind: "123???", and we are interested in the number of x matching this mask. This number almost always depends on the number of "?" with minor exceptions concerning n. E. g. consider n=123456 for the example above.

So in the desired sum, we group summands by the following markers of i (brute force the value of these markers): 

* Length of i,
* Position of first digit different in i and n (cases, where i is an own prefix of n, shall be considered separately).
* The value of this digit.

So we know description of i of the following kind: i=¯c1c2…ckx1…xl, where cj are fixed, and x1,…,xl are arbitrary integer variables in [0,9]. Observe that both bi and i are linear combination of variables xj and 1, so bi−i is also a linear combination of them. The only issue is computing bi−i modulo p.

To do summing over all x1,…,xl we use the meet-in-the-middle method: bruteforce separately the values for the first half and the second half, and then match one with another.

If n≤10L, the solution works in O(10L2poly(L)), or O(√npoly(logn)).

