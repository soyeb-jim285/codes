# Tutorial_(en)


### [1008A - Romaji](https://codeforces.com/contest/1008/problem/A "Codeforces Round 497 (Div. 2)")

You need to check if after every letter except one of for these "aouien", there goes one of these "aouie". Do not forget to check the last letter.

 
### [1008B - Turn the Rectangles](https://codeforces.com/contest/1008/problem/B "Codeforces Round 497 (Div. 2)")

You need to iterate over the rectangles from left to right and turn each rectangle in such a way that its height is as big as possible but not greater than the height of the previous rectangle (if it's not the first one). If on some iteration there is no such way to place the rectangle, the answer is "NO".

 
### [1007A - Reorder the Array](../problems/A._Reorder_the_Array.md "Codeforces Round 497 (Div. 1)")

The answer is n minus maximal number of equal elements.

Let the maximal number of equals be x. Let's proove that n−x is reachable. It's clear that for every permutation of the array the answer will be the same, so let's sort the array in non-decreasing order. Now we should just make a left shift on x. After it the n−x right elements will move to a position of a smaller element.

Now let's proove that the answer is no more than n−x. Let's consider some permutation. It's known that every permutation breaks into cycles. Let's look at two occurences of the same number in the same cycle. Then there is at least one number between them which will move on a postion of a non-smaller element. Even if it the same occurence and even if the length of the cycle is 1, we can say that for every occurence of this number there is at least one number which moves on a postion of a non-smaller one. So if some number occurs x times, there are at least x bad positions and therefore no more than n−x good positions.

To count the number of equals you can, for instance, use std::map.

 
### [1007B - Pave the Parallelepiped](../problems/B._Pave_the_Parallelepiped.md "Codeforces Round 497 (Div. 1)")

First solution.

First, for every natural number up to 105 we count its number of divisors in O(√n). Also for every unordered set of 3 masks (m1,m2,m3) of length 3 we check if there is а way to enumerate them in such a way that 1∈m1, 2∈m2 and 3∈m3. We will call such sets acceptable.

Now let's consider two parallelepipeds. For each dimension of the second parallelepiped let's construct a mask of length 3 which contains the numbers of the dimensions of the first parallelepiped for which the length of the first parallelepiped along this dimension is divisible by the length of the second parallelepiped along the chosen dimension. Now these three masks form an acceptable set iff we can pave the first parallelepiped with the second one.

Now for a given parallelepiped let's calculate for every mask of length 3 the number of possible lengths of the second parallelepiped which would produce this mask. We can do this by taking the GCD of the lengths of the first parallelepiped along the dimensions whose numbers are in the mask, and subtracting from it the calculated numbers for every submask.

Now let's iterate over acceptable sets of masks. For each different mask from the set which is included into the set k times we need to calculate the number of ways to take k unordered lengths which produce this mask, and multiply these numbers. The sum of these numbers is the answers to the query.

So for every query we need O(2m2) operations, where m=3 is the number of dimensions of the parallelepiped.

Second solution.

First, for every natural number up to 105 we count its number of divisors in O(√n).

Then for every query for every subset of numbers in it we keep their GCD and the number of its divisors. So for every subset of this three numbers we know the number of their common divisors.

Let's look at the parallelepiped (a,b,c). The way we orient it with respect to the large parallelepiped is determined by a permutation of size 3 — that is, which dimension would correspond to every dimension in the large one. Using the inclusion-exclusion principle on this permutations we can count how many there are such parallelepipeds (considering the orientation) that we can orient some way to then pave the large parallelepiped with it. Namely, we fix the set of permutations for which our parallelepiped shall satisfy. Then for every side of the small parallelepiped we know which sides of the large one it shall divide. To find the number of such sides of the small one we shall take the number of common divisors of the corresponding sides of the large one. Now to find the number of such small parallelepipeds we must multiply the three resultant numbers.

In such way every satisfying this criteria parallelepiped (not considering the orientation) with three different side lengths was counted 6 times, with two different lengths was counted 3 times, with one different length was counted 1 time. But it won't be difficult for us to use the same approach in counting such parallelepipeds, but with no less than two same side lengths: let's say the first and the second. To do this when we fix which permutations this parallelepiped shall satisfy we should just add the condition that its first and second side lengths must be equal, this means they both must divide both of the sets corresponding to them, so instead of this two sets we must take their union.

Let's add the resultant number multiplied by three to the answer. Now every parallelepiped with three different side length is still counted 6 times, with two different is now counted also 6 times, and with one different is counted 4 times. The number of satisfying parallelepipeds with equal sides is just the number of common divisors of all the sides of the large parallelepiped. Let's add it multiplied by two, and now every needed parallelepiped is counted 6 times. We divide this number by 6 and get the answer.

So for every query we need O(p(m)⋅2m!⋅m) operations, where p(m) is the number of partitions of m, and m=3 is the number of dimensions of the parallelepiped.

 
### [1007C - Guess two numbers](../problems/C._Guess_two_numbers.md "Codeforces Round 497 (Div. 1)")

First solution:

Let's keep the set of possible answers as a union of three rectangles forming an angle: A=[xl,xm)×[yl,ym), B=[xl,xm)×[ym,yr) and C=[xm,xr)×[yl,ym), where xl<xm≤xr and yl<ym≤yr. Let SA, SB and SC be their areas. We will denote such state as (xl,xm,xr,yl,ym,yr). The initial state is (0,n+1,n+1,0,n+1,n+1).

Now there are three cases. 

1. SB≤SA+SC and SB≤SA+SB, then we will make a query (⌊xl+xm2⌋,⌊yl+ym2⌋).
2. If SB>SA+SC, we will make a query (⌊xl+xm2⌋,ym).
3. Finally, if SC>SA+SB, we will make a query (xm,⌊yl+ym2⌋).

In case of every response to every query, the new set of possible answers will also form an angle.

Now we want to prove that the area of the angle decreases at least by a quarter every two requests.

In case (1) if the answer is 1, then we move to a state (⌊xl+xm2⌋+1,xm,xr,yl,ym,yr). We cut off at least half of A and at least half of B. But SA2+SB2=SA+SB4+SA+SB4≥SA+SB4+SC4=SA+SB+SC4. I.e. We have cut off at least a quarter already within just one request. If the answer is 2, the situation is similar. Finally, if the answer is 3, then we move to a state (xl,⌊xl+xm2⌋,xr,yl,⌊yl+ym2⌋,yr). We cut off at least quarter of A, at least half of B and at least half of C. But SA4+SB2+SC2≥SA4+SB4+SC4=SA+SB+SC4. We also have cut off at least a quarter within just one request. Thus in case (1) we cut off at least a quarter within one request.

In case (2) if the answer is 1, then we move to a state (⌊xl+xm2⌋+1,xm,xr,yl,ym,yr). We cut off at least half of A and at least half of B. But SA2+SB2≥SB2≥SB4+SB4≥SB4+SA+SC4=SA+SB+SC4. We have cut off at least a quarter within just one request. If the answer is 2, then we move to a state (xl,xr,xr,ym+1,yr,yr). But then if will be case (1), thus we will cut off at least a quarter with the next request. Finally, if the answer is 3, then we move to a state (xl,⌊xl+xm2⌋,xr,yl,ym,yr). We cut off at at least half of B. But SB2≥SB4+SB4≥SB4+SA+SC4=SA+SB+SC4. We also have cut off at least a quarter within just one request.

Case (3) is similar to case (2).

Thus the maximal number of requests will be no more than 1+2∗log4/3((1018)2)≈577.

Second solution:

Let's keep the set of possible answers in form of a ladder A. Then lets find minimal X such that S(A∩{x≤X})≥S(A)3. And lets find minimal Y such that S(A∩{y≤Y})≥S(A)3. Then S(A∩{x≥X}∩{y≥Y})=S(A∖(A∩{x≤X−1})∖(A∩{y≤Y−1}))≥ ≥S(A)−S(A∩{x≤X−1})−S(A∩{y≤Y−1})≥S(A)−S(A)3−S(A)3=S(A)3. I.e. we cut off at least third of the area of the ladder on each request.

Thus the maximal number of requests will be no more than 1+log3/2((1018)2)≈205.

 
### [1007D - Ants](../problems/D._Ants.md "Codeforces Round 497 (Div. 1)")

Slow solution.

We need to choose one of two paths for each ant so that they will not contain a common edge. Let's make a 2-SAT, and for each ant, we will create two contrary vertices: one will denote that we take the first path, and another will denote that we take the second path. Then for every two paths which share an edge, we add a condition that they can't be taken together. Now we just need to check that the 2-SAT has a solution.

The complexity is O(nm2).

First solution.

Let's build a binary tree with m leaves for each edge. Each vertex of the tree will be associated with some vertex of the 2-SAT. The vertex of the tree which covers leaves from l to r will be associated with a vertex of the 2-SAT which says if the edge should be painted with a color from l to r. To build a vertex which is associated with a leaf we just need to add for every path of the ant which covers the current edge a condition which tells that if we take this path, then this vertex is true. And for every non-leaf vertex of the tree we need to add three conditions. First and second: if any of the vertices associated with the two sons is true, then the vertex associated with the current vertex is also true (l→v, r→v). And third: both vertices associated with the two sons can't be true (l→!r).

The trees will be persistent, which means that if the vertex we want already exists, we will reuse it.

Now we will build such trees recursively. First for the children, and then for the current edge. To build a tree for a new edge we first take an empty tree, then for each child, we recursively merge its tree with the current. If during the merge one of the vertices is empty, we return the second vertex. Then we add the paths which end in the current vertex.

You have to be careful not to add the edges which will not be present in the final tree. For example, you can first build a tree, and then go through the new vertices one more time and add the edges.

Then as in the previous solution, we check if there is a solution of this 2-SAT.

It can be shown that for a vertex of the binary tree which covers k leaves there will be created no more than 8k instances of this vertex, because there are at most 4k ends of the paths connected with these leaves and at most 8k−1 vertices which are the LCA of some set of these vertices. Now if we summarize it over all the vertices of the binary tree, we get approximately 8mlog(m). 

So the total complexity is O(mlog(m))

Second solution.

Let L=64 be the number of bits in a machine word.

Let's calculate a matrix 2m×2m of ones and zeros, where cell (i,j) is filled with 1 iff the paths i and j have a common edge. We will store this matrix as an array of bitsets.

Let's run a DFS which for every edge will return a set of paths that cover it. We will store such sets in a map from number of block to a bitmask of length L. We recursively calculate the sets for the children. Also for every path which starts in the vertex, we make a set containing only this path. Then if some sets share the same path, we remove it from both. Then we merge them by always adding the smaller map to the larger. While doing so we iterate over the elements of the smaller map and over the blocks of the larger map and add a block of edges to the matrix. For now, it is enough to add each edge to the matrix only in one direction. It can be shown that it works in O(mlog2(m)+m2⋅log(L)L).

Now we want to transpose the matrix and add it to itself to make it complete. To do it we divide it into blocks L×L, and transpose them one by one, then swap the blocks. Here is how we transpose a block.

Assume L=2K. We will make K iterations. On the i−th iteration we will divide the block into subblocks 2i×2i and in each block, we will swap the top right quarter and the bottom left quarter. Each iteration can be performed in O(L). We can prove by induction that after i iterations each subblock 2i×2i will be transposed.

This step works in O(m2⋅log(L)L).

It is easy to get a bitset of straight edges and a bitset of reversed edges of the 2-SAT for every vertex using this matrix. Now if we store the visited vertices in a bitset, we can implement the 2-SAT algorithm in O(m2L).

The total complexity is O(mlog2(m)+m2⋅log(L)L).

 
### [1007E - Mini Metro](../problems/E._Mini_Metro.md "Codeforces Round 497 (Div. 1)")

Let's enumerate the hours and the stations starting from zero. Let's add a station to the end with an infinite number of people and infinite capacity. It is obvious that it will not affect the answer. Also, every train now will be filled completely.

Let's calculate sa[p], sb[p] and sc[p]: the sum of a[i], b[i] and c[i] over the first p stations respectively.

Let d[p][s][z] (0≤p≤n+1, 0≤s≤t, 0≤z≤1) be the minimal number of trains (or ∞, if impossible) needed to hold on for s hours, if there were only the first p stations, so that every train we used would be filled completely. Herewith the initial number of people on the i-th station equals z⋅a[i].

Let g[p][s][z] (0≤p≤n+1, 0≤s≤t, 0≤z≤1)be the minimal number of trains (or ∞, if impossible) needed to hold on for s with a half hours (so that we can send some trains at the end), if there were only the first p stations, so that every train we used would be filled completely and every station except for the last would contain in the end 0 people. Herewith the initial number of people on the i-th station equals z⋅a[i].

Then the answer for the problem is d[n+1][t][1].

Lets calculate d and g using dynamic programming.

In order to calculate d[p][s][z] and g[p][s][z] lets consider the last hour from 0 to s−1 in which some train will take a person from the last station. Notice that in case of g[p][s][z] we do not consider the s-th hour though there could be such trains during this hour.

First case: There were no such trains. In this case we just need to check that the last station won't overflow and that d[p−1][s][z]≠∞. Then we can make transitions: d[p][s][z]←d[p−1][s][z], g[p][s][z]←val=⌈z⋅sa[p−1]+s⋅sb[p−1]k⌉. The second transition is made only if val⋅k≤z⋅sa[p]+s⋅sb[p].

(*) In case of g[p][s][z] it is obvious that such number will be needed in order to set to zero all the stations except for the last one, and this number can be achieved since we can hold on for s hours without taking a person from the last station.

Second case: denote the number of this hour by r. Then the plan is as follows: 

1. First, we need to hold on for r with a half hours and do so that on every station except for the last there will be 0 people.
2. Then we possibly send some more trains during the r-th hour.
3. Then we need to hold on for s−r without the first half hours without sending a train which will take a person from the last station.
4. Then in case of g[p][s][z] we send some more trains during the s-th hour.

 During the phase (1) it is beneficial to send as few trains as possible, be'cause we can always send additional trains during the phase (2) and nothing will change. Thus we send g[p][r][z] trains. If g[p][r][z]=∞, then the transition is impossible.On the phase (2) we cat calculate the initial number of people on the last station: m=z⋅sa[p]+r⋅sb[p]−k⋅g[p][r][z], and then calculate the minimal number of trains we need to send so that the last station doesn't overflow by the end of the(s−1)-th hour: x=⌈max(m+(s−r)⋅b[p−1]−c[p−1],0)k⌉. If x⋅k>m, then the transition is impossible, else it is benificial to send x trains.

During the phase (3) it is beneficial to send as few trains as possible, be'cause in case of d[p][s][z] it is the last phase, and in case of g[p][s][z] we can always send additional trains during the phase (4) and nothing will change. Notice in the beginning of phase (3) the first p−1 are empty and also we can assume we are starting from the beginning of an hour and we need to hold on for s−r hours. Thus we need to send d[p−1][s−r][0] trains. If d[p−1][s−r][0]=∞, then the transition is impossible.

Finally, on the phase (4) we need to send as few trains as possible so that all the stations except for the last one would contain 0 people. As in (*) we can see that on phases (3) and (4) we need to send in total at least val = ⌈(s−r)⋅sb[p−1]k⌉ trains, and we can achieve this number.

We can make transitions: d[p][s][z]←g[p][r][z]+x+d[p−1][s−r][0], g[p][s][z]←g[p][r][z]+x+⌈(s−r)⋅sb[p−1]k⌉. The second transition is made only if val⋅k≤(s−r)⋅sb[p].

Solution time is O(nt2).

