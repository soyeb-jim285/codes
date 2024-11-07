# Tutorial

Thanks for the participation!

[1649A - Game](../problems/A._Game.md "Codeforces Round 775 (Div. 2, based on Moscow Open Olympiad in Informatics)") was authored by [Jeffrey](https://codeforces.com/profile/Jeffrey "Grandmaster Jeffrey") and prepared by [gop2024](https://codeforces.com/profile/gop2024 "International Grandmaster gop2024")

[1649B - Game of Ball Passing](../problems/B._Game_of_Ball_Passing.md "Codeforces Round 775 (Div. 2, based on Moscow Open Olympiad in Informatics)") was authored by [low_](https://codeforces.com/profile/low_ "Master low_") and prepared by [low_](https://codeforces.com/profile/low_ "Master low_") and [gop2024](https://codeforces.com/profile/gop2024 "International Grandmaster gop2024")

[1648A - Weird Sum](https://codeforces.com/contest/1648/problem/A "Codeforces Round 775 (Div. 1, based on Moscow Open Olympiad in Informatics)") was authored and prepared by [cookiedoth](https://codeforces.com/profile/cookiedoth "International Grandmaster cookiedoth")

[1648B - Integral Array](https://codeforces.com/contest/1648/problem/B "Codeforces Round 775 (Div. 1, based on Moscow Open Olympiad in Informatics)") was authored by [grphil](https://codeforces.com/profile/grphil "Master grphil") and prepared by [shishyando](https://codeforces.com/profile/shishyando "Expert shishyando")

[1648C - Tyler and Strings](https://codeforces.com/contest/1648/problem/C "Codeforces Round 775 (Div. 1, based on Moscow Open Olympiad in Informatics)") was authored and prepared by [Tikhon228](https://codeforces.com/profile/Tikhon228 "Master Tikhon228")

[1648D - Serious Business](https://codeforces.com/contest/1648/problem/D "Codeforces Round 775 (Div. 1, based on Moscow Open Olympiad in Informatics)") was authored and prepared by [ligaydima](https://codeforces.com/profile/ligaydima "Master ligaydima")

[1648E - Air Reform](https://codeforces.com/contest/1648/problem/E "Codeforces Round 775 (Div. 1, based on Moscow Open Olympiad in Informatics)") was authored and prepared by [grphil](https://codeforces.com/profile/grphil "Master grphil")

[1648F - Two Avenues](https://codeforces.com/contest/1648/problem/F "Codeforces Round 775 (Div. 1, based on Moscow Open Olympiad in Informatics)") was authored by [I_love_myself](https://codeforces.com/profile/I_love_myself "Master I_love_myself") and prepared by [isaf27](https://codeforces.com/profile/isaf27 "International Grandmaster isaf27")

 
### [1649A - Game](../problems/A._Game.md "Codeforces Round 775 (Div. 2, based on Moscow Open Olympiad in Informatics)")

It is easy to see that if there are no water locations, the answer is 00. Otherwise, we should jump from the last accessible from the start land location to the first land location from which the finish is accessible. In order to find these locations, one can use two consecutive while loops, one increasing ll from 1 until al+1=0, and the other one decreasing r from n until ar−1=0. After the loops finish, we know that we should jump from the l-th location to the r-th at the cost of r−l.

 
### [1649B - Game of Ball Passing](../problems/B._Game_of_Ball_Passing.md "Codeforces Round 775 (Div. 2, based on Moscow Open Olympiad in Informatics)")

If max(a)⋅2≤sum(a), we can always prove that we can only use one ball.

For other cases, the number of balls is determined by 2⋅max(a)−sum(a).

 
### [1648A - Weird Sum](https://codeforces.com/contest/1648/problem/A "Codeforces Round 775 (Div. 1, based on Moscow Open Olympiad in Informatics)")

We note that the manhattan distance between cells (r1,c1) and (r2,c2) is equal to |r1−r2|+|c1−c2|. For each color we will compose a list of all cells (r0,c0),…,(rk−1,ck−1) of this color, compute the target sum for this color, and sum up the answers for all colors. The sum is equal:

k−1∑i=0k−1∑j=i+1|ri−rj|+|ci−cj|=(k−1∑i=0k−1∑j=i+1|ri−rj|)+(k−1∑i=0k−1∑j=i+1|ci−cj|)

We will compute the first sum, the second sum is analogous. Let an array s be equal to r, but sorted in increasing order. Then:

k−1∑i=0k−1∑j=i+1|ri−rj|=k−1∑i=0k−1∑j=i+1sj−si=(k−1∑i=0k−1∑j=i+1sj)+(k−1∑i=0k−1∑j=i+1−si)

The value sj occurs in the first double sum exactly j times, the value −si occurs in the second sum exactly k−1−i times. Then, the value is equal to:

k−1∑j=0jsj+k−1∑i=0−(k−1−i)si=k−1∑i=0(2i+1−k)si

The last sum can be computed in O(k), the time complexity to sort an array is O(klogk). The overall complexity is O(nmlog(nm)). We can also sort arrays of coordinates by adding cells to lists in the right order. This yields an O(nm) solution.

 
### [1648B - Integral Array](https://codeforces.com/contest/1648/problem/B "Codeforces Round 775 (Div. 1, based on Moscow Open Olympiad in Informatics)")

Let's consider x,y∈a and r∉a. If y⋅r≤x<y⋅(r+1) then ⌊xy⌋=r, but r is not in a, so the answer is "No". Let's suggest that y and r are already given. We can check if there exists such x∈a from the mentioned segment in O(1). It is done by considering array cntx — the amount of occurrences of x in a, and prefix sums for that array. Now we only need to run this check for each r and y. To do that we can iterate through all r∉a and y∈a in increasing order. If r⋅y>c then there is definitely no such x so we can consider the next r. This optimization speeds up the process and makes the whole solution work in O(ClogC).

 
### [1648C - Tyler and Strings](https://codeforces.com/contest/1648/problem/C "Codeforces Round 775 (Div. 1, based on Moscow Open Olympiad in Informatics)")

Let K be the size of the alphabet, that is, the number of the maximum letter that occurs in it.

First, let's calculate how many different strings can be composed if we have c1 letters of the 1th type, c2 letters of the 2th type, …, cK letters of the K type. This is the school formula:

P(c1,c2,…,cK)=(c1+c2+…+cK)!c1!⋅c2!⋅…⋅cK!

to quickly calculate it for different c1,c2,…,ck pre-calculate all factorials and their reciprocals modulo C=998244353 in O(n⋅logC)

In order for the string x to be less than the string t, they must have the same prefix. Let's iterate over the length of this matching prefix from 0 to min(n,m). If strings x and t have the same first i characters, then we know exactly how many letters we have left. To support this, let's create an array cnt, at the i-th position of which there will be the number of remaining letters of type i.

Let's iterate over the letter that will appear immediately after the matching prefix. For the resulting string to be less than t, this letter must be strictly less than the corresponding letter in t, and all subsequent letters can be arranged in any order. Let's calculate the number of rows x considered in this way according to the formula above.

The only case where the resulting string x can be lexicographically less than t, which we will not count, is when it is a prefix of the string t, but has a shorter length. We will separately check whether we can get such a string, and if so, add 1 to the answer.

Since at each of at most min(n,m) steps we need to go through at most K options for the next letter, and we calculate each option in O(K) - we get the asymptotics O(min(n,m)⋅K2+n⋅logC)

To speed up the resulting solution, let's create an array add, in the i-th cell of which we store how many ways it will be possible to arrange the remaining letters if the letter i is put in the current position. In fact addi=(cnt1+cnt2+…+cntK−1)!cnt1!⋅cnt2!⋅…⋅(cnti−1)!⋅…⋅cntK!

If we learn how to maintain this array, then at each step we only need to take the sum of the elements at some of its prefix. Let's see how it changes if the next letter in the string t is i, i.e. cnti should decrease by 1.

For all cells j≠i addj is replaced by addj⋅cnticnt1+cnt2+…+cntK−1. To apply modifications to the entire array, let's create a separate variable modify, by which we need to multiply the value in the cell to get the value that should be there.

For cell i, addi will be replaced by addi⋅cnti−1cnt1+cnt2+…+cntK−1. And taking into account the fact that we applied a modifier to all cells, it is enough to multiply the value of addi by cnti−1cnti

With this optimization, we now spend only O(K) actions at each step to calculate the prefix sum, and O(log(C)) to calculate what to multiply the array cells by. We get the asymptotics O(min(n,m)⋅(K+log(C))) To get rid of K asymptotically, note that the only thing we want to do with the add array is take the sum at the prefix and change the value at the point. This can be done in O(log(K) using the Fenwick Tree or the Segment Tree. Applying them, we get the final asymptotic O(min(n,m)⋅(log(K)+log(C))).

In fact, log(C) in the asymptotics can be eliminated by precalculating modulo reciprocals for all numbers from 1 to n faster than O(n⋅log(C)), but in this task was not required.

 
### [1648D - Serious Business](https://codeforces.com/contest/1648/problem/D "Codeforces Round 775 (Div. 1, based on Moscow Open Olympiad in Informatics)")

Let's denote pref[i][j]:=∑j−1k=0a[i][k]. Then define s and t as follows:

s[i]=pref[0][i+1]−pref[1][i]

f[i]=pref[1][i+1]−pref[2][i]+pref[2][n]

Now we can transform the problem to following: compute max0≤i≤j<ns[i]+f[j]−cost(i,j) where cost(i,j) is the minimal cost of unlocking segment [i,j]. 

Let's define dp[i] as the maximum profit for going from (1,1) to (2,i), if the rightmost segment that we have used ends in i (so it's s[j] for some j minus cost of covering segment [i,j], when we know that there's a segment ending at i).

The calculation of dp is as follows: for all i look through each segment, which ends at i, and relax dp[i] with maxl−1≤j<idp[j]−k. It can be calculated using segment tree.

Now consider the optimal usage of segments. Fix the rightmost segment. The profit for this segment usage should be dp[i]+f[j]+k for some i,j on this segment. So we can bruteforce the rightmost segment in our answer and relax the overall answer with maxl≤i≤j≤rdp[i]+f[j]−k. Also there's a case where taking only 1 segment is optimal, then we should relax the answer with maxl≤i≤j≤rs[i]+f[j]−k. We can calculate all of this using segment tree.

Overall complexity is O(qlogn).

 
### [1648E - Air Reform](https://codeforces.com/contest/1648/problem/E "Codeforces Round 775 (Div. 1, based on Moscow Open Olympiad in Informatics)")

The formal statement of this problem is that we have a weighted graph, for which we build it's complement, where the weight of an edge between A and B equals to minimal maximum on path from A to B in initial graph. The same way we calculate edge weights of initial graph, and we have to output them.

We can notice, that the path where maximum wight is minimal goes directly through the minumum spanning tree. That means that in order to get the final edges weights we need to calculate the minimum spanning tree on the graph complement and to get the final weights of initial edges we need to get the maximum on the tree path, which we can do in O(mlogn) time with binary jumping pointers.

In order to build the minimum spanning tree of graph complement, we will do something like Kruskal algorithm. We will sort the edges of initial graph by their weights and store sets of connected vertices by edges of weights less than last added. The same way we will store the sets of connected vertices in graph complement by edges of weights less than last added. These complement components will form subsets of initial components. 

While adding a new edge, some connected components of initial graph can be merged. That means that some complement components can be merged. We can merge only those complement components, that are subsets of different initial components that became merged after adding an edge. These complement components become merged only if there exists some edge between two vertices of complement components in complement graph. In other words, between some pair of vertices in different complement components there is no edge in initial graph.

So when two initial components S and T become merged, we can iterate over all pair of complement components, such that first one is subset of S and second one is subset of T. For each two vertices in them we should check that there is an edge between them in initial graph. Only in this case we can not merge these two complement components. For each of this unsuccessful attempt of merging two complement components, we do as much iterations, as there are edges between them in initial graph. So the total number of iterations in unsuccessful merges is O(m). And for successful merges the complement components are merged and a new edge is added to complement minimum spanning tree. So the total number of successful merges is O(n) and the total time if O(mlogm) for edges sorting and O(m) for complement MST build. After that we can find weights of initial edges in O(mlogn) time.

 
### [1648F - Two Avenues](https://codeforces.com/contest/1648/problem/F "Codeforces Round 775 (Div. 1, based on Moscow Open Olympiad in Informatics)")

Let's consider two edges from the answer e1, e2. At least one of them should lie on dfs tree, otherwise the graph will be connected after removing e1, e2 and the answer will be 0.

Let the answer be e1, e2, where e1 lies on dfs tree. What cases can be for edges e1, e2? The edge e2 should be a bridge of the graph without edge e1 (otherwise e2 can be any). Using this we can highlight possible cases:

1. Both edges e1, e2 are bridges of the graph.
2. The edge e1 is the bridge of the graph, the edge e2 does not matter.
3. The edge e1 lies on dfs tree, the edge e2 is the only outer edge covering the edge e1.
4. Both edges e1, e2 lies on dfs tree, sets of outer edges covering e1, and covering e2 are equal.

For each case let's find the maximum answer.

For each of k pairs of vertices let's consider the path between vertices in the pair.

For each edge e of dfs tree let's calculate three values:

* ce — the number of paths, containing the edge e.
* fe — the number of outer edges, covering the edge e.
* he — the hash of all outer edges, covering the edge e. For each outer edge let's give random 64-bit integer, the hash will be equal to the sum of values.

In the first case, the answer for two bridges e1, e2 is equal to ce1+ce2. So we should find two brides with maximum value ce.

In the second case, the answer for one bridge e1 is equal to ce1. So we should find the bridge with maximum value ce.

In the third case, we consider edges e1, such that fe1=1. The answer is ce1. So we should find edge e1 of dfs tree, such that fe1=1 with maximum value ce1.

The fourth case is very hard. We consider two edges e1, e2, such that he1=he2. The answer is equal to the number of paths, containing exactly one edge from e1, e2. We can divide each path into two vertical paths, the answer won't change.

The plan of the solution will be: let's make a dfs of the dfs tree and maintain the segment tree with operations add on segment, and maximum on segment. The prefix of the segment tree corresponds to edges on the path from the root to the current edge e2. The value in the cell corresponding to the edge e1 is equal to the answer for the pair of edges e1, e2.

It is possible to recalculate this segment tree with O(n+k) updates during the dfs tree traversal.

The unsolved problem now is how to consider only edges e1, such that he1=he2 in the maximum on segment. Let's call a cluster all edges with equal hash. All edges from one cluster lie on the vertical path. Let's consider the vertical path for each cluster: from the first occurrence of edge from the cluster to the last occurrence of edge from the cluster. Any two paths for two clusters either do not intersect or nested into each other.

When making a traversal let's add −∞ on the segment from the last edge with hash he2 to the edge e2. This move will exclude edges from the maximum. This won't interfere the values, because all hashes from the segment won't be found later in the traversal (due to the clusters structure). After that, let's find the maximum on the segment from the first edge with hash he2 to the edge e2. In that maximum all edges with the hash he2 will participate.

The total solution has the complexity O(m+(n+k)logn).

