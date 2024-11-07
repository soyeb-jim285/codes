# Tutorial_(en)

[1839A - The Good Array](../problems/A._The_Good_Array.md "Codeforces Round 876 (Div. 2)")

 **Hint**The first and last elements are always equal to 1.

 **Hint**There are at least ⌈n−1k⌉ ones among the first n−1 elements.

 **Solution**
### [1839A - The Good Array](../problems/A._The_Good_Array.md "Codeforces Round 876 (Div. 2)")

Let's find lower bound for answer. In any good array, there are at least ⌈n−1k⌉ ones among the first n−1 elements. Also, an is always 1, as ⌈1k⌉=1. 

So there are at least ⌈n−1k⌉+1 ones in any good array. 

This lower bound can always be achieved by placing ones on position n and on positions 1+k⋅x for all integers x such that 0≤x≤⌊n−2k⌋=⌈n−1k⌉−1.

The answer to the probelm is ⌈n−1k⌉+1.

[1839B - Lamps](../problems/B._Lamps.md "Codeforces Round 876 (Div. 2)")

 **Hint**Try to solve the problem if all ai are equal.

 **Solution**
### [1839B - Lamps](../problems/B._Lamps.md "Codeforces Round 876 (Div. 2)")

Let's denote number of lamps with ai=k as ck. 

If ck≥k and you turn k lamps with ai=k lamps on, all ck of them will break and you will not be able to receive points for the other ck−k lamps. 

If we denote values bi for all i such that ai=k as dk,1,dk,2,…,dk,ck (dk,1≥dk,2≥…≥dk,ck), then you can't get more than sk=dk,1+dk,2+…+dk,min(ck,k) points for lamps with ai=k.

So, the total number of points is not bigger than s1+s2+…+sn.

This bound can always be achieved in the following way: while there is at least one lamp that is not turned on and not broken, turn on the one with minimum ai (if there are multiple lamps with minimum ai, choose the one with maximum bi).

This works because if at least k lamps are turned on, then all lamps with ai<k are already broken.

[1839C - Insert Zero and Invert Prefix](../problems/C._Insert_Zero_and_Invert_Prefix.md "Codeforces Round 876 (Div. 2)")

 **Hint**After every operation, the last element of b is equal to 0.

 **Hint**If the last element of a is 0, then you can always achieve b=a with some sequence of operations.

 **Hint**Try to solve the problem if a consists of k ones followed by single zero.

 **Solution**
### [1839C - Insert Zero and Invert Prefix](../problems/C._Insert_Zero_and_Invert_Prefix.md "Codeforces Round 876 (Div. 2)")

It's easy to see that last element of b is always zero, so if an is 1, then the answer is "NO".

It turns out that if an is 0, then answer is always "YES".

First, let's try to get b equal to array of form [k⏞1,1,…,1,0] for some k≥0. Further in the editorial I will call such arrays simple. We can insert zero before the first element k times and then insert zero after the last element, inverting all previously inserted zeroes into ones.

To get arbitrary b with bn=0, you can notice that such array can always be divided into simple arrays. For example, array [1,1,0,0,1,1,1,1,0,1,0] can be divided into [1,1,0], [0], [1,1,1,1,0], [1,0]. 

Also it's easy to see that if you can get array a1 with sequence of operation p1 and array a2 with sequence of operations p2, then you can get concatenation of arrays a1 and a2 by first performing all the operations from p2 and then performing all the operations from p1.

So, the solution is as follows: 

* If an is 1, output "NO".
* Otherwise, divide array a into simple arrays of lengths s1,s2,…,sm (s1+s2+…+sm=n).
* Then, you can get b=a with sequence of operations p=[sm−1⏞0,0,…,0,sm−1,sm−1−1⏞0,0,…,0,sm−1−1,…,s1−1⏞0,0,…,0,s1−1].
[1839D - Ball Sorting](../problems/D._Ball_Sorting.md "Codeforces Round 876 (Div. 2)")

 **Hint**Consider the set of balls that were never moved by operations of type 2.

 **Hint**The relative order of these balls never changes, so their colors must form an increasing sequence.

 **Solution**
### [1839D - Ball Sorting](../problems/D._Ball_Sorting.md "Codeforces Round 876 (Div. 2)")

Let's solve the problem for some fixed k.

Consider the set S of all balls that were never moved with operation of type 2. Let's call balls from S fixed and balls not from S mobile. 

The relative order of fixed balls never changes, so their colors must form an increasing sequence. 

Let's define f(S) as the number of segments of mobile balls that the fixed balls divide sequence into. For example, if n=6 and S={3,4,6}, then these segments are [1,2],[5,5] and f(S) is equal to 2. 

As every mobile ball has to be moved at least once, there must be at least one zero-colored ball in each such segment, whicn means that f(S)≤k. Also, it means that we will need at least n−|S| operations of type 2. 

In fact, we can always place mobile balls at correct positions with exactly n−|S| operations. The proof is left as exercise for reader.

So the answer for k is equal to minimum value of n−|S| over all sets S of balls such that f(S)≤k and the colors of balls in S form an increasing sequence. This problem can be solved with dynamic programming: let dpi,j be maximum value of |S| if only balls from 1 to i exist, ball i belongs to S and f(S) is equal to j. To perform transitions from dpi,j you need to enumerate t —the next ball from S after i. Then, if t=i+1, you transition to dpt,j, otherwise you transition to dpt,j+1. After each transition |S| increases by 1, so you just update dpt,j/j+1 with value dpi,j+1. 

There are O(n2) states and at most n transitions from each state, so the complexity is O(n3).

Solution can be optimized to O(n2logn) with segment tree, but this was not required.

[1839E - Decreasing Game](../problems/E._Decreasing_Game.md "Codeforces Round 876 (Div. 2)")

 **Hint**Consider the graph with n vertices 1,2,…,n, and on each round of the game, connect vertices i and j. What can you say about this graph?

 **Hint**This graph is a tree.

 **Hint**Vertices of a tree can be divided into two parts, such that all edges connect vertices from different parts.

 **Hint**If the second player won the game, then sums of elements in both parts were equal in initial array a.

 **Solution**
### [1839E - Decreasing Game](../problems/E._Decreasing_Game.md "Codeforces Round 876 (Div. 2)")

I claim that the second player wins if and only if array a can be divided into two sets with equal sum, or, equivalently, there is a subset of a with sum a1+a2+…+an2. 

The strategy for the second player in this case is quite simple: before the game starts, the second player splits a into two parts with equal sum. On each round, if the first player selected i from the first part, the second player selects j from the second part. Otherwise, he selects j from the first part. Before and after every round, sums of elements in both parts are equal, so if there is a positive element in one part, there is also a positive element in the other part. So the second player is always able to make a correct move.

The strategy for the first player in the other case is even simplier: he can just make any correct move on each round. Why? 

Let's suppose the second player won the game, which lasted k rounds, and elements selected by players on each round were (i1,j1),(i2,j2),…,(ik,jk). After k-th round, all elements of a are zeroes, otherwise the first player would still be able to make a correct move. 

Let's consider graph G with set of vertices V={1,2,…,n} and set of edges E={(i1,j1),(i2,j2),…,(ik,jk)}. It's easy to see that this graph is always a tree (proof left as exercise for reader; hint: after each round, at least one of ai and aj becomes zero). If graph is a tree, then it is bipartite, which means that its vertices can be divided into two sets such that each edge connects vertices from different sets. As each operation decreases ai and aj by same value, these two sets have the same sum of elements. So we have a contradiction.

