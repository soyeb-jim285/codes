# Tutorial_(en)

**UPD**: Solutions are added.

[1480A - Yet Another String Game](../problems/A._Yet_Another_String_Game.md "Codeforces Round 700 (Div. 2)")

 **Tutorial**
### [1480A - Yet Another String Game](../problems/A._Yet_Another_String_Game.md "Codeforces Round 700 (Div. 2)")

After some observations, we can see that the players should always choose the most significant letter to change, because it coordinates the lexicographical order of the final string most. Therefore, Alice will choose all odd indices while Bob will choose all even indices, and then Alice will change all letters she choose to the smallest possible letters while Bob will change all letters he choose to the largest possible letters. That is, Alice will change letters to "a" if the original letter is not "a" and to "b" otherwise; Bob will change letters to "z" if the original letter is not "z" and to "y" otherwise.

The time complexity is O(n).

 **Solution**[106873602](https://codeforces.com/contest/1480/submission/106873602 "Submission 106873602 by liouzhou_101")

[1480B - The Great Hero](../problems/B._The_Great_Hero.md "Codeforces Round 700 (Div. 2)")

 **Tutorial**
### [1480B - The Great Hero](../problems/B._The_Great_Hero.md "Codeforces Round 700 (Div. 2)")

The hero needs ⌈bi/A⌉ attacks to kill the i-th monster, and he will obtain ⌈bi/A⌉ai damage after that.

Suppose the k-th monster is the last monster killed by the hero. Then the health value of the hero before the last attack is hk=B−n∑i=1⌈biA⌉ai+ak. All monsters can be killed if and only if maxk{hk}>0. This can be checked in O(n) time.

 **Solution**[106873633](https://codeforces.com/contest/1480/submission/106873633 "Submission 106873633 by liouzhou_101")

[1479A - Searching Local Minimum](https://codeforces.com/contest/1479/problem/A "Codeforces Round 700 (Div. 1)")

 **Tutorial**
### [1479A - Searching Local Minimum](https://codeforces.com/contest/1479/problem/A "Codeforces Round 700 (Div. 1)")

We maintain by binary search a range [l,r] which has a local minimum. Moreover, we assume that al−1>al and ar<ar+1. Initially, [l,r]=[1,n].

In each iteration, let m be the midpoint of l and r. 

Case 1. If am<am+1, then the range becomes [l,m].

Case 2. If am>am+1, then the range becomes [m+1,r].

When l=r, we have found a local minimum al.

The number of queries to ai is at most 2⌈log2n⌉≤34<100. 

 **Solution**[106873682](https://codeforces.com/contest/1479/submission/106873682 "Submission 106873682 by liouzhou_101")

[1479B1 - Painting the Array I](https://codeforces.com/contest/1479/problem/B1 "Codeforces Round 700 (Div. 1)")

 **Tutorial**
### [1479B1 - Painting the Array I](https://codeforces.com/contest/1479/problem/B1 "Codeforces Round 700 (Div. 1)")

Formally, for every sequence a1,a2,…,an, and we assume that a1,a2,…,an are positive integers, the number of segments in a is defined to be seg(a)=n∑i=1[ai−1≠ai], where a0=0, and [Boolean expression]=1 if the Boolean expression is true and 0 otherwise.

Let's restate the problem as

Problem. Given a sequence a1,a2,…,an, divide it into two disjoint subsequences s and t such that seg(s)+seg(t) is as large as possible.

Solution. We will construct two disjoint subsequences by scanning through the sequence a1,a2,…,an. 

Initial setting: s and t are two empty sequences, and a1,a2,…,an remains not scanned. 

Move on: Suppose the last elements of s and t are x and y, respectively, and x=0 (resp. y=0) if s (resp. t) is empty. Let z be the current element scanning through a1,a2,…,an. Our greedy strategy is described in two cases: 

* Greedy Strategy I: If z equals to one of x and y, then assign z to the opposite subsequence. That is, if z=x, then append z after y; and if z=y, then append z after x. In particular, if z equals to both x and y, the assignment could be arbitrary.
* Greedy Strategy II: If z differs from both x and y, then append z after the one with the nearest next same value. That is, let next(x) denote the next position where x appears in a1,a2,…,an after z, then append z after x if next(x)<next(y), and after y otherwise.

The greedy strategy is intuitive, and with this strategy, an O(n) algorithm is immediately obtained. However, its proof turns out to be complicated. We append its proof for completeness.

An Intuitive Proof

Consider any optimal assignment b1,b2,…,bn, we will show that our strategy is not worse than it. Let a[l…r]=al,al+1,…,ar be the subarray of a. 

Now suppose we are at some position p, where the optimal assignment conflicts with our strategy. We assume that s=(a[1…p])(0)=s′x ends with x, and t=(a[1…p])(1)=t′y ends with y, and ap+1=z. 

Greedy Strategy I: If b conflicts with Greedy Strategy I, then we must have x≠y and without loss of generality, we assume that x=z. Greedy Strategy I suggests we append z after y but b suggests we append z after x. Suppose b results in the two subarrays s′xzs′′t′yt′′, while there is indeed another optimal assignment that agrees with our strategy and results in s′xt′′t′yzs′′.

Greedy Strategy II: If b conflicts with Greedy Strategy II, then we must have x, y and z are distinct and without loss of generality, we assume that the next occurrence of x goes in front of that of y. Greedy Strategy II suggests we append z after x but b suggests we append z after y. Suppose b results in the two subarrays s′xs′′t′yzt′′. Consider two cases.

Case 1. If s′′ does not start with y, then there is another optimal assignment that agrees with our strategy and results in s′xzt′′t′ys′′.

Case 2. If s′′ starts with y, i.e. s′′=ys1, then since the first occurrence of x is in front of that of y, we have that x must be in t′′, and assume that t′′=t1xt2. The result of b is restated as s′xys1t′yzt1xt2. We find that there is another optimal assignment that agrees with our strategy and results in s′xzt1ys1t′yxt2 (Note that t1 does not contain any x or y in it).

A Formal Proof

The number of alternations in a sequence a starting with x is defined to be segx(a)=n∑i=1[ai−1≠ai], where a0=x. We note that seg0(a)=seg(a).

Let fx,y(a) denote the maximal possible sum of numbers of alternations in the two disjoint subsequences s and t of a, i.e. fx,y(a)=maxs,t{segx(s)+segy(t)}, where s and t ranges over all possible pairs of disjoint subsequences of a. It is obvious that the order of x and y does not matter, i.e. fx,y(a)=fy,x(a). We note that our goal is to compute f0,0(a).

Let next(x) denote the least index k such that ak=x, i.e. next(x)=min{k∈N:ak=x}. In case no such index k exists, next(x) is defined to be ∞.

In fact, our problem can be solved by DP regardless of the time complexity.

Proposition 1 (Dynamic Programming). For n≥1 and every x,y∈N, fx,y(a1,a2,…,an)=max{fa1,y(a2,…,an)+[a1≠x],fx,a1(a2,…,an)+[a1≠y]}. In particular, for empty sequence ϵ, we have fx,y(ϵ)=0.

We can obtain some immediate properties of fx,y(a) by the above DP recurrence.

Proposition 2. For every x,y∈N, fx,0(a)≥fx,y(a)≥fx,x(a). Moreover, if next(y)=∞, then fx,0(a)=fx,y(a).

After some observations, we have

Proposition 3. For every x,y,z∈N and sequence a, fz,x(a)+1≥fz,y(a).

Proof: By induction on the length n of sequence a.

 Basis. It is trivial for the case n=0 since the left hand side is always 1 and the right hand side is always 0.

 Induction. Suppose true for the case n=k(k≥0), i.e. fz,x(a)+1≥fz,y(a) holds for every sequence a of length k. Now consider a sequence a1,a2,…,ak+1 of length k+1.

 Case 1. x=y. It is trivial that fz,x(a)+1≥fz,x(a).

 Case 2. z=x≠y. We should prove that fx,x(a)+1≥fx,y(a). By Proposition 1, we need to prove that {fa1,x(a2,…,ak+1)+[a1≠x]+1≥fa1,y(a2,…,ak+1)+[a1≠x],fa1,x(a2,…,ak+1)+[a1≠x]+1≥fx,a1(a2,…,ak+1)+[a1≠y]. The second inequality is obvious. The first inequality becomes fa1,x(a2,…,ak+1)+1≥fa1,y(a2,…,ak+1), which holds by induction.

 Case 3. x≠y=z. We should prove that fx,y(a)+1≥fx,x(a). By Proposition 1, we only need to prove that fx,a1(a2,…,ak+1)+[a1≠y]+1≥fa1,x(a2,…,ak+1)+[a1≠x], which is obvious.

 Case 4. x≠y,z≠x and z≠y. By Proposition 1, fz,x(a)+1≥fz,y(a) is equivalent to max{fa1,x(a2,…,ak+1)+[a1≠z],fz,a1(a2,…,ak+1)+[a1≠x]}+1≥max{fa1,y(a2,…,ak+1)+[a1≠z],fz,a1(a2,…,ak+1)+[a1≠y]}.

 Case 4.1. a1=z. The left hand side becomes max{fz,x(a2,…,ak+1),fz,z(a2,…,ak+1)+1}+1=fz,z(a2,…,ak+1)+2 by induction that fz,z(a2,…,ak+1)+1≥fz,x(a2,…,ak+1). The right hand side becomes max{fz,y(a2,…,ak+1),fz,z(a2,…,ak+1)+1}=fz,z(a2,…,ak+1)+1 by induction that fz,z(a2,…,ak+1)+1≥fz,y(a2,…,ak+1). The inequality holds immediately.

 Case 4.2. a1=x. The left hand side becomes max{fx,x(a2,…,ak+1)+1,fz,x(a2,…,ak+1)}+1=fx,x(a2,…,ak+1)+2 by induction that fx,x(a2,…,ak+1)+1≥fz,x(a2,…,ak+1). The right hand side becomes max{fx,y(a2,…,ak+1)+1,fz,x(a2,…,ak+1)+1}. By induction that fx,x(a2,…,ak+1)+1≥fx,y(a2,…,ak+1)+1 and fx,x(a2,…,ak+1)+1≥fx,z(a2,…,ak+1)+1, the inequality holds.

 Case 4.3. a1=y. The left hand side becomes max{fy,x(a2,…,ak+1)+1,fz,y(a2,…,ak+1)+1}+1. The right hand side becomes max{fy,y(a2,…,ak+1),fz,y(a2,…,ak+1)+1}=fz,y(a2,…,ak+1)+1 by induction that fy,y(a2,…,ak+1)+1≥fz,y(a2,…,ak+1)+1. The inequality immediately holds as fz,y(a2,…,ak+1) appears in both sides (and can be eliminated together).

 Case 4.4. a1∉{x,y,z}. The left hand side becomes max{fa1,x(a2,…,ak+1)+1,fz,a1(a2,…,ak+1)+1}+1. The right hand side becomes max{fa1,y(a2,…,ak+1)+1,fz,a1(a2,…,ak+1)+1}. By induction that fa1,x(a2,…,ak+1)+1≥max{fa1,y(a2,…,ak+1),fa1,z(a2,…,ak+1)}, the inequality holds.

 The inequality holds for all cases. Therefore, the inequality holds for n=k+1.

 Conclusion. The inequality holds for every n≥0. ◻

Proposition 4. Suppose a1,a2,…,an is a sequence. For every distinct x,y,z∈N, i.e. x≠y,y≠z and z≠x, if next(x)<next(y), then fz,y(a)≥fz,x(a).

Proof: By induction on the length n of sequence a.

 Basis. It is trivial for the case n=0 since the both hand sides are 0.

 Induction. Suppose true for the case n=k(k≥0), i.e. fz,y(a)≥fz,x(a). holds for every sequence a of length k. Now consider a sequence a1,a2,…,ak+1 of length k+1.

 Case 1. a1=z. By Proposition 1 and 3, the left hand side becomes max{fz,y(a2,…,ak+1),fz,z(a2,…,ak+1)+1}=fz,z(a2,…,ak+1)+1, and the right hand side becomes max{fz,x(a2,…,ak+1),fz,z(a2,…,ak+1)+1}=fz,z(a2,…,ak+1)+1 The inequality holds immediately.

 Case 2. a1=x. By Proposition 1, the left hand side becomes max{fx,y(a2,…,ak+1)+1,fz,x(a2,…,ak+1)+1}, and the right hand side becomes max{fx,x(a2,…,ak+1)+1,fz,x(a2,…,ak+1)}. By Proposition 2, we have fz,x(a2,…,ak+1)≥fx,x(a2,…,ak+1), and therefore, the inequality holds.

 Case 3. a1=y. This is impossible because next(x)<next(y), i.e. there is an element of value x in front of the first element of value y.

 Case 4. a1∉{x,y,z}. The left hand side becomes max{fa1,y(a2,…,ak+1)+1,fa1,z(a2,…,ak+1)+1}. The right hand side becomes max{fa1,x(a2,…,ak+1)+1,fa1,z(a2,…,ak+1)+1}.

 Case 4.1. If next(y)>next(z), then by induction we have fa1,y(a2,…,ak+1)≥fa1,z(a2,…,ak+1), and (because next(y)>next(x), ) fa1,y(a2,…,ak+1)≥fa1,x(a2,…,ak+1). The inequality holds.

 Case 4.2. If next(y)<next(z), then by induction we have fa1,z(a2,…,ak+1)≥fa1,y(a2,…,ak+1), and (because next(z)>next(y)>next(x), ) fa1,z(a2,…,ak+1)≥fa1,x(a2,…,ak+1). The inequality holds.

 The inequality holds for all cases. Therefore, the inequality holds for n=k+1.

 Conclusion. The inequality holds for every n≥0.

Proposition 5 (Greedy Strategy I). Suppose a1,a2,…,an is a sequence. For every x,y∈N, if a1=x, then fx,y(a1,…,an)=fx,x(a2,…,an)+1.

Proof: By Proposition 1, we have fx,y(a1,…,an)=max{fx,y(a2,…,an),fx,x(a2,…,an)+1}. By Proposition 3, we have fx,x(a2,…,an)+1≥fx,y(a2,…,an). Combining with the both above yields the proof. ◻

Proposition 6 (Greedy Strategy II). Suppose a1,a2,…,an is a sequence. For every x,y∈N with x≠y, if a1∉{x,y}, then fx,y(a1,…,an)={fa1,y(a2,…,an)+1next(x)<next(y),fx,a1(a2,…,an)+1otherwise. Proof: If next(x)<next(y), by Proposition 4, we have fa1,y(a2,…,an)≥fx,a1(a2,…,an). Therefore, by Proposition 1, we have fx,y(a1,…,an)=fa1,y(a2,…,an)+1.

 The same statement holds for next(x)>next(y). ◻

 **Solution**[106873713](https://codeforces.com/contest/1479/submission/106873713 "Submission 106873713 by liouzhou_101")

[1479B2 - Painting the Array II](https://codeforces.com/contest/1479/problem/B2 "Codeforces Round 700 (Div. 1)")

 **Tutorial**
### [1479B2 - Painting the Array II](https://codeforces.com/contest/1479/problem/B2 "Codeforces Round 700 (Div. 1)")

There are two approaches from different perspectives. 

DP Approach

The first observation is that merging adjacent elements with the same value will not influence the answer. Therefore, without loss of generality, we may assume that there are no adjacent elements with the same value, i.e. ai≠ai+1 for every 1≤i<n.

We can solve this problem by a DP approach. Let f(i) denote the minimal possible number of segments for sub-array a1,a2,…,ai over all assignments b1,b2,…,bi with bi≠bi−1, where b0=−1 for convenience. To obtain the answer, we enumerate the last position 1≤i≤n such that bi−1≠bi, and append all elements ai+1,ai+2,…,an to the end of ai, which implies an arrangement with f(i)+n−i segments. The minimal number of segments will be the minimum among f(i)+n−i over all 1≤i≤n.

It is straightforward to see that f(0)=0 and f(1)=1.

For 2≤i≤n, f(i) can be computed by enumerating every possible position 1≤j<i such that bj−1≠bj=bj+1=⋯=bi−1≠bi. That is, aj,aj+1,…,ai−1 are assigned to the same sub-sequence, and aj−1 and ai are assigned to the other sub-sequence. Since no adjacent elements has the same value (by our assumption), there are (i−j) segments in aj,aj+1,…,ai−1 (we note that the first segment, i.e. the segment of aj, is counted in f(j)). Moreover, there will be zero or one new segment when concatenating aj−1 and ai depending on whether aj−1=ai or not. Hence, for every 2≤j≤n, we have f(i)=min1≤j<i{f(j)+(i−j−1)+[aj−1≠ai]}, where [Boolean expression]=1 if the Boolean expression is true and 0 otherwise. Here, we obtain an O(n2) DP solution.

To optimize the DP recurrence, we fix i, and let g(j)=f(j)+(i−j−1)+[aj−1≠ai], then f(i)=max1≤j<i{g(j)}. We can observe that

Lemma 1. For 2≤i≤n, we have f(i)=min{g(i−1),g(j∗)}, where j∗=max{1≤j<i:aj−1=ai}, max∅=0, and g(0)=+∞.

This lemma is very intuitive, which means we need only to consider two cases: one is to just append ai after ai−1 in the same sub-sequence, and the other is to append ai after the closest aj with the same value, i.e. ai=aj, and then assign the elements between them (not inclusive) to the other sub-sequence. With this observation, we immediately obtain an O(n) DP solution.

The proof is appended below for completeness.

Proof: For every 1≤j<i, we have f(i)≤g(j)=f(j)+(i−j−1)+[aj−1≠ai]≤f(j)+i−j, which implies that f(i)−i≤f(j)−j for every 1≤j≤i≤n. 

Now we consider g(j) for every 1≤j<i in two cases. 

1. aj−1≠ai. We have g(j)=f(j)+(i−j−1)+1=f(j)−j+i≥f(i−1)−(i−1)+i=f(i−1)+1≥g(i−1).
2. aj−1=ai. Suppose there are two different positions j1 and j2 such that 1≤j1<j2<i and aj1−1=aj2−2=ai, then g(j1)=f(j1)+(i−j1−1)=f(j1)−j1+i−1≥f(j2)−j2+i−1=g(j2).

 Combine the two cases, we conclude that f(i)=min{g(i−1),g(j∗)}, where j∗=max{1≤j<i:aj−1=ai}. ◻Greedy Approach

Consider we have a computer whose cache has only two registers. Let's suppose the array a is a sequence of memory access to the computer. The problem is then converted to a more intuitive one that asks the optimal cache replacement. 

Suppose the current two registers contains two memory accesses x and y, and the current requirement memory access is z. 

The greedy strategy is simple: If z matches one of x and y, just do nothing. Otherwise, the register that contains the memory access whose next occurrence is farther than the other will be replaced by z.

This strategy is know as Bélády's algorithm or farthest-in-the-future cache/page replacement policy (see [here](https://codeforces.com/https://en.wikipedia.org/wiki/Cache_replacement_policies) for more information). The complexity is O(n) since we only need to preprocess every element's next occurrence. 

 **Solution**DP: [106873739](https://codeforces.com/contest/1479/submission/106873739 "Submission 106873739 by liouzhou_101") Greedy: [106873763](https://codeforces.com/contest/1479/submission/106873763 "Submission 106873763 by liouzhou_101")

[1479C - Continuous City](https://codeforces.com/contest/1479/problem/C "Codeforces Round 700 (Div. 1)")

 **Tutorial**
### [1479C - Continuous City](https://codeforces.com/contest/1479/problem/C "Codeforces Round 700 (Div. 1)")

The answer is always "YES". For convenience, we write (x,y,z) for a directed road from block x to block y of length z.

Step 1. We can solve the case L=1 and R=2k for k≥0 inductively. The case for k=0 is trivial, i.e. only one edge (1,2,1).

Suppose there is a city of k+2 blocks for L=1 and R=2k for some k≥0, and the induced city from block 1 to block x is (1,2x−2)-continuous for every 2≤x≤k+2. Let block k+3 be a new block, and add (1,k+3,1) and (x,k+3,2x−2) for 2≤x≤k+2. We can see that the new city containing block k+3 is (1,2k+1)-continuous.

Step 2. Suppose L=1 and R>1. Let R−1=∑ki=0Ri2i be the binary representation of R−1, where 0≤Ri≤1. Let Gk be the (1,2k)-continuous city constructed in Step 1. Let block k+3 be a new block. Connect (1,k+3,1), and then for every 0≤i≤k, if Ri=1, then connect (i+2,k+3,1+∑kj=i+1Rj2j). We can see that the new city containing block k+3 is (1,R)-continuous.

Step 3. Suppose 1<L≤R. Consider HR−L+1, where HR denotes the (1,R)-continuous city constructed in Step 2 and there are k blocks in HR−L+1. Connect (k,k+1,L−1). We can see that the new city containing block k+1 is (L,R)-continuous.

We note that there is at most 23 blocks in our constructed city.

 **Solution**[106873798](https://codeforces.com/contest/1479/submission/106873798 "Submission 106873798 by liouzhou_101")

[1479D - Odd Mineral Resource](https://codeforces.com/contest/1479/problem/D "Codeforces Round 700 (Div. 1)")

 **Tutorial**
### [1479D - Odd Mineral Resource](https://codeforces.com/contest/1479/problem/D "Codeforces Round 700 (Div. 1)")

Let s(u,v,c) denote the number of cities between city u and city v, whose mineral resource is c. We restate the problem that for each query u,v,l,r, find an integer c such that l≤c≤r and s(u,v,c)≢0(mod2).

We give a randomized algorithm with success probability extremely high. For every kind of mineral resources 1≤i≤n, we assign a random variable Xi to it. Those random variables Xi are independent and identically uniformly distributed from [0,264−1]. For every city u, we assign its weight to be Xcu. 

For every query u,v,l,r, Let f(u,v,l,r) be the [bitwise XOR](https://codeforces.com/https://en.wikipedia.org/wiki/Bitwise_operation#XOR) of all weights of all cities between city u and city v, whose mineral resources are in [l,r]. We claim that 

1. Pr[f(u,v,l,r)=0∣∀c,s(u,v,c)≡0(mod2)]=1, which means that if a suitable c does not exist then f(u,v,l,r)=0 for certainty, and
2. Pr[f(u,v,l,r)≠0∣∃c,s(u,v,c)≢0(mod2)]=1−2−64, which means that if a suitable c does exist then f(u,v,l,r)≠0 with high probability.

 Let's consider the reverse that 1. Pr[∀c,s(u,v,c)≡0(mod2)∣f(u,v,l,r)=0]=1−2−64, which implies with high probability no suitable mineral resource exists if f(u,v,l,r)=0, and
2. Pr[∃c,s(u,v,c)≢0(mod2)∣f(u,v,l,r)≠0]=1, which implies with certainty at least one suitable mineral resource exists.

 According to the above discussion, our strategy is 1. to report no solution if f(u,v,l,r)=0, and
2. to find a c (l≤c≤r) such that f(u,v,c,c)≠0 if f(u,v,l,r)≠0.

 Our strategy will succeed with probability p≥1−2−64. Now consider there are q queries. Let Ai denote the event that the i-th query succeeds. The i-th query will succeed with probability Pr[Ai]≥1−2−64 (however, they may not be independent). Then we have Pr[q⋀i=1Ai]=1−Pr[q⋁i=1ˉAi]≥1−q∑i=1Pr[ˉAi]=1−q∑i=1(1−Pr[Ai])≥1−q∑i=1(1−(1−2−64))=1−2−64q, which means all queries succeed simultaneously with probability at least 1−2−64q≥1−2−44 if q≤220, which is high enough under constraints of the problem.

To this end, we shall compute f(u,v,l,r) and find a c (l≤c≤r) such that f(u,v,c,c)≠0. This can be solved by consistent segment trees. Let's root the tree (by any vertex, say vertex 1). For every vertex u, we maintain a (consistent) segment tree that for each interval [l,r] computes f(1,u,l,r). Let father(u) be the father of vertex u, and lca(u,v) be the least common ancestor of vertex u and vertex v. Then f(u,v,l,r)=f(1,u,l,r)⊕f(1,v,l,r)⊕f(1,lca(u,v),l,r)⊕f(1,father(lca(u,v)),l,r). For more details, please according to [SPOJ COT](https://codeforces.com/https://www.spoj.com/problems/COT/). Therefore, we have solved this problem with high enough probability in O(nlogn) time and space.

 **Solution**[106873842](https://codeforces.com/contest/1479/submission/106873842 "Submission 106873842 by liouzhou_101")

[1479E - School Clubs](https://codeforces.com/contest/1479/problem/E "Codeforces Round 700 (Div. 1)")

 **Tutorial**
### [1479E - School Clubs](https://codeforces.com/contest/1479/problem/E "Codeforces Round 700 (Div. 1)")

Section 1. The Expected Value of Stopping Time

There may be several ways to deal with the expected value of stopping time. Here, we decide to give an elegant way to derive the expected stopping time inspired by [MiFaFaOvO's comment](https://codeforces.com/blog/entry/77284?#comment-620956). Here, we are going to introduce the mathematical tool we will use in the following description (see [here](https://codeforces.com/https://www.cnblogs.com/TinyWong/p/12887591.html) for a Chinese explanation.)

Consider a random process A0,A1,A2,…, where Ai is called the i-th event of the process, or the event at time i. Let random variable T∈N be its stopping time. That is, for every t∈N, It can be decided whether T=t as long as A0,A1,…,At are given. If there is a function ϕ(⋅) that maps an event to a real number such that 

1. E[ϕ(At+1)−ϕ(At)∣A0,A1,…,At]=−1 for every t∈N, and
2. E[ϕ(AT)] depends on some properties of the events and the stopping time, which is usually a constant in practice.

 Let Xt=ϕ(At)+t, then E[Xt+1−Xt∣A0,A1,…,At]=0. That is, X0,X1,X2,… is a martingale of A0,A1,…. By the optimal stopping theorem, under some ignorable conditions, we have that E[XT]=E[X0]. Therefore, E[T]=E[ϕ(A0)−ϕ(AT)]. Moreover, if ϕ(AT) is a constant, then E[T]=ϕ(A0)−ϕ(AT). We will use the above identity to find the expected value of T, the stopping time. Usually, ϕ(⋅) is called the potential function.To begin our journey, we should first describe an event as something (a number, a tuple, a sequence, or a set) in our problem. We find it naturally to use a (multi-)set A={a1,a2,…,am} to describe it, where m denotes the number of clubs, the i-th of which contains ai students. We see that the explicit order of the clubs does not matter but the number of students in each club. Furthermore, we notice that every club's status is equal, which implies us to define the potential function as the form ϕ(A)=∑a∈Af(a)=m∑i=1f(ai), where m=|A|. It should be noted that the sum of elements in A is a constant, so we let n=∑a∈Aa=m∑i=1ai.

We first consider the corner case for the value of f(0). Since students will never join an empty club, A and A∪{0} denotes the events with the same property. Therefore, we need ϕ(A)=ϕ(A∪{0}), which immediately yields f(0)=0.

We now investigate how the potential function behaves from the t-th event At={a1,a2,…,am} to the (t+1)-th event At+1. We note that the student who gets angry is in the i-th club with probability ain. After that, the angry student will 

1. leave and create a new club with probability 12. In this case, At+1={a1,a2,…,ai−1,ai−1,ai+1,…,am,1}, and we have ϕ(At+1)=ϕ(At)−f(ai)+f(ai−1)+f(1),
2. join the j-th club (j≠i) with probability aj2n. In this case, At+1={a1,a2,…,ai−1,aj+1,…,am}, and we have ϕ(At+1)=ϕ(At)−f(ai)−f(aj)+f(ai−1)+f(aj+1),
3. stay still in the i-th club with probability ai2n. In this case, At+1=At, and we have ϕ(At+1)=ϕ(At).

To sum it up, we get that E[ϕ(At+1)∣At]=m∑i=1ain[12(ϕ(At)−f(ai)+f(ai−1)+f(1))+∑j≠iaj2n(ϕ(At)−f(ai)−f(aj)+f(ai−1)+f(aj+1))+ai2nϕ(At)]. Let E[ϕ(At+1)−ϕ(At)∣A0,A1,…,At]=−1, and then we obtain that f(1)+m∑i=1ain2[(2n−ai)f(ai−1)+(n−ai)f(ai+1)−(3n−2ai)f(ai)]+2=0. Here, we need to find a function f(⋅) that satisfies the above condition with the corner case f(0)=0.

There are several possible ways to assign the value of f(a). We choose the most simple one such that f(1)+2=0, which removes the constant term. Under this assignment, we have f(1)=−2. After this, we have to make that (2n−a)f(a−1)+(n−a)f(a+1)−(3n−2a)f(a)=0, i.e. (n−a)[f(a+1)−f(a)]=(2n−a)[f(a)−f(a−1)]. holds for every a.

We let g(a)=f(a+1)−f(a) for a≥0. Therefore, g(0)=f(1)−f(0)=−2, and g(a)=2n−an−ag(a−1)=2n−an−a⋅2n−(a−1)n−(a−1)g(a−1)=…=2n−1n−1⋅2n−2n−2⋅⋯⋅2n−an−ag(0). We find that f(a)=f(0)+g(0)+g(1)+⋯+g(a−1)=−2[1+P(1)Q(1)+P(2)Q(2)+⋯+P(1)P(2)…P(a−1)Q(1)Q(2)…Q(a−1)], where P(x)=2n−x and Q(x)=n−x. If we can compute f(a) in an efficient way, then the problem is solved. However, it seems not so straightforward.

Section 2. The Trick for the Prefix Sum by Generating Functions

For convenience, we denote S(a)=P(1)Q(1)+P(2)Q(2)+⋯+P(1)P(2)…P(a)Q(1)Q(2)…Q(a), where P(x) and Q(x) are linear functions (polynomials of degree 1). To compute S(a), we use the trick mentioned in [min_25's blog](https://codeforces.com/https://min-25.hatenablog.com/entry/2017/04/10/215046). However, the trick we adopt here can deal with more general cases.

Let N>a be a large enough positive integer. Then we have S(a)=1Q(1)Q(2)…Q(N)[P(1)Q(2)Q(3)…Q(a)Q(a+1)…Q(N)+P(1)P(2)Q(3)…Q(a)Q(a+1)…Q(N)+⋯+P(1)P(2)P(3)…P(a)Q(a+1)…Q(N)]. We only have to compute the inner sum s(a)=S(a)Q(1)Q(2)…Q(N). We now use the SQRT trick here. Let B≈√N be the block size. Let R(z)=P(z+1)Q(z+2)Q(z+3)…Q(z+B)+P(z+1)P(z+2)Q(z+3)…Q(z+B)+⋯+P(z+1)P(z+2)P(z+3)…P(z+B). Then we will see that s(a)=⌊a/B⌋∑k=0P(1)…P(kB)R(kB)Q((k+1)B+1)…Q(N)+a∑i=(⌊a/B⌋+1)B+1P(1)…P(i)Q(i+1)…Q(N). It is more convenient to let P(k)=P(1)…P(kB) and Q(k)=Q(kB+1)…Q(N), then the main summation in s(a) is written as ⌊a/B⌋∑k=0P(k)R(kB)Q(k+1). Now, we have three values needed, which are R(z),P(k),Q(k).

Compute R(z)

 We deal with R(z) first. We note that R(z) is a polynomial of degree B and we want to compute R(kB) for every 0≤k≤N/B. If we can obtain the values of R(0),R(1),…,R(B), then by Lagrange interpolation, we can recover the polynomial R(z). And then, if we know the exact polynomial R(z), then by multi-point evaluation trick, we can compute the values of R(kB) for every k≤N/B. The total time complexity would be O(√Nlog2N).

We can compute R(0) in O(B) time. And then, we note that R(z)=Q(z+B)P(z)R(z−1)−Q(z+1)…Q(z+B)+P(z+1)…P(z+B). Therefore, R(1),…,R(B) can be computed in O(B) time if we simultaneously maintain the values of block product of P(⋅) and Q(⋅) in the above identity.

 Bonus: A "log" in the complexity may be eliminated by some trick similar to [min_25's blog](https://codeforces.com/https://min-25.hatenablog.com/entry/2017/04/10/215046)?

Compute P(k)

 This subproblem is very similar to compute the factorial-like product, which is originally mentioned in [min_25's blog](https://codeforces.com/https://min-25.hatenablog.com/entry/2017/04/10/215046). To solve it, we define fP(z)=P(z+1)P(z+2)…P(z+B). Then P(k)=fP(0)fP(B)…fP((k−1)B). What we need is to compute fP(kB) fast enough. We also note that fP(z) is a polynomial of degree B. We can easily find the values of fP(0),fP(1),…,fP(B) in O(B) time. Therefore, the values of fP(kB) can be obtained by Lagrange interpolation and multi-point evaluation. In particular, we are able to compute P(1)P(2)…P(N) in this way, which is considered to be a general factorial.

compute Q(k)

 This subproblem is more tricky if we are able to compute P(k) fast. Similarly, we define fQ(z) as what we did when computing P(k). Let Q′(k) be the prefix block products of Q(x) as an analog for P(k) and P(x). It can be easily seen that Q(k)=Q(1)Q(2)…Q(N)Q′(k).

 Having computed all values we need in the previous several sections, we are able to compute the value of a single f(a) in O(√N) time. Therefore, the overall complexity is O(√Nlog2N+m√N).

Bonus: Saving logn in Complexity

 Moreover, we can save logn in complexity with an improved interpolation method for shifting evaluation values. See the paper "A. Bostan, P. Gaudry, and E. Schost, Linear recurrences with polynomial coefficients and application to integer factorization and Cartier-Manin operator. SIAM Journal of Computing, 36(6): 1777–1806. 2007".

Shifting evaluation values

 Suppose given are a polynomial f(x) of degree d by a point-value representation f(0),f(1),…,f(d) and a shift δ. It is asked to compute an alternative point-value representation f(δ),f(δ+1),…,f(δ+d). A straightforward way to solve this problem is to directly make use of Lagrange interpolation and multi-point evaluation, which yields an O(dlog2d) arithmetic complexity algorithm. In fact, we can do it better in O(dlogd) time.

Recall the formula of Lagrange interpolation that given n points (xi,yi) where yi=f(xi), then the unique polynomial of degree (n−1) is f(x)=n∑i=1yi∏j≠ix−xjxi−xj. Rewrite this formula in our case that f(0),f(1),…,f(d) are given, then f(x)=d∑i=0f(i)∏j≠ix−ji−j. We assume that δ,δ+1,…,δ+d do not overlap with 0,1,…,d, then for 0≤k≤d, we have f(δ+k)=d∑i=0f(i)∏j≠iδ+k−ji−j=(d∏j=0(δ+k−j))(d∑i=0(−1)d−if(i)i!(d−i)!⋅1δ+k−i). The summation can be computed by FFT. Consider two polynomials: A(x)=d∑i=0(−1)d−if(i)i!(d−i)!xi, B(x)=2d∑i=01δ+i−dxi. We have f(δ+k)=(d∏j=0(δ+k−j))[xd+k]A(x)B(x).

 Therefore, f(δ),f(δ+1),…,f(δ+d) can be computed in O(dlogd) time.

Arithmetic sequence shifting

 Now we consider a modified version: given a polynomial of degree d by a point-value representation f(0),f(s),f(2s),…,f(ds) and a shift δ, compute f(δ),f(δ+s),f(δ+2s),…,f(δ+ds).

 The trick is to let g(x)=f(xs), which is also a polynomial of degree d. Then the problem becomes: given g(0),g(1),…,g(s) and a shift δ′=δ/s, compute g(δ′),g(δ′+1),…,g(δ′+d).

Divide and conquer

 Let's consider how to compute R(z). For convenience, we denote that RB(z)=P(z+1)Q(z+2)Q(z+3)…Q(z+B)+P(z+1)P(z+2)Q(z+3)…Q(z+B)+⋯+P(z+1)P(z+2)P(z+3)…P(z+B), PB(z)=P(z+1)P(z+2)…P(z+B), QB(z)=Q(z+1)Q(z+2)…Q(z+B), where B indicates the number of elements in the product. We need to compute the values of RB(0),RB(s),…,RB(sB),PB(0),PB(s),…,PB(sB),QB(0),QB(s),…,QB(sB).

To compute these values recurrently, we should notice that R2B(z)=RB(z)QB(z+B)+PB(z)RB(z+B), P2B(z)=PB(z)PB(z+B), Q2B(z)=QB(z)QB(z+B). We choose P2B(z) as an example. Here we need to compute P2B(0)=PB(0)PB(B),P2B(s)=PB(s)PB(s+B),…,P2B(sB)=PB(sB)PB(sB+B),P2B(sB+1)=PB(sB+1)PB(sB+B+1),…,P2B(2sB)=PB(2sB)PB(2sB+B). There are 4B values of PB(z) that are needed, which are PB(0),PB(s),…,PB(sB),PB(B),PB(B+s),…,PB(B+sB),PB(sB),PB(sB+s),…,PB(sB+sB),PB(B+sB),PB(B+sB+s),…,PB(B+sB+sB). The first line is our target and the rest three lines can be obtained by shifting the first line by B, sB and B+sB, respectively. Let T(d) be the complexity where d is the degree of our polynomials, then T(d)=T(d/2)+O(dlogd). Hence, T(d)=O(dlogd).

 In our case, d=O(√N), then the complexity is reduced to O(√NlogN+m√N).

Conclusion

 We use the trick, SQRT decomposition, to split summations into blocks, and then use Lagrange interpolation and multi-point evaluation to compute the value in each block. We obtain an algorithm with complexity O(√Nlog2N+m√N).

 A more subtle trick to save a logN is obtained by the shifting technique, which yields a faster algorithm with complexity O(√NlogN+m√N). The constant factor of Lagrange interpolation and multi-point evaluation is very large, so this approach to save a logN brings a significant improvement.

 However, we allow suboptimal solutions that directly use Lagrange interpolation and multi-point evaluation to get AC.

Credits

 Some related problems: 

1. Stopping time: [1349D](https://codeforces.com/problemset/problem/1349/D), [850F](https://codeforces.com/contest/850/problem/F), [1025G](https://codeforces.com/problemset/problem/1025/G).
2. Generating function: [SPOJ FACTMODP](https://codeforces.com/https://www.spoj.com/problems/FACTMODP/), [CodeChef QPOLYSUM](https://codeforces.com/https://www.codechef.com/problems/QPOLYSUM), [1349F2](https://codeforces.com/problemset/problem/1349/F2).
 **Solution**[106873892](https://codeforces.com/contest/1479/submission/106873892 "Submission 106873892 by liouzhou_101")

