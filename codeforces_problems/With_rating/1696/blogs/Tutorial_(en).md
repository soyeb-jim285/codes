# Tutorial_(en)

Thanks for participation!

If your solution to D involves any data structures and is not O(n)O(n) -- please read the "solution 1". I believe it is very interesting, but to make the difficulty suitable for D we allowed not O(n)O(n) solutions.

[1696A - NIT orz!](../problems/A._NIT_orz!.md "Codeforces Global Round 21")

 **Hint 1**How many operations will we perform?

 **Answer**At most one. Why?

 **Solution**Suppose we can only perform exactly one operation. In this case the answer is S=max1≤i≤n(ai or z). In fact, we can prove that this is the answer.

Define a′i as the value of ai after some operations.

It suffices to prove the answer will never exceed S. Note that z will always become a submask of itself after any number of operations, so ai will always be a submask of (ai or z) after any number of operations. This leads to the conclusion that a′i≤(ai or z) for all i. Thus max1≤i≤na′i≤max1≤i≤n(ai or z)=S.

Time complexity is O(n).

[1696B - NIT Destroys the Universe](../problems/B._NIT_Destroys_the_Universe.md "Codeforces Global Round 21")

 **Hint 1**How many operations will we perform?

 **Answer**At most two. Why?

 **Hint 2**How to check if the array can be destroyed in 0 or 1 operations? 

 **Solution**The answer is at most 2, because doing the operation on [1,n] at most twice will always work. (If the array contains at least one zero, we need 2 operations. Otherwise we need 1 operation.)

If the array consists of zeroes, the answer is 0.

If all non-zero elements form a contiguous segment in the array, the answer is $1$​. To check this, you can find the leftmost and rightmost occurrence of non-zero elements and check if elements in the middle of them are also non-zero.

Otherwise the answer is 2.

Time complexity is O(n).

[1696C - Fishingprince Plays With Array](../problems/C._Fishingprince_Plays_With_Array.md "Codeforces Global Round 21")

 **Hint 1**The operation is reversible. (The two operations are reverses of each other.)

 **Hint 2**Try to find a middle state, such that we can turn both a and b into it.

 **Solution**Call the first operation "expand" and the second operation "shrink".

Keep doing expand on both arrays until we can't do expand anymore, call the resulting arrays a′ and b′. It suffices to check if a′=b′. To implement this, you need to compress contiguous equal numbers.

Proof of why this is necessary and sufficient:

 * Sufficiency is obvious, since the operations are reversible. We can do something like a→a′=b′→b.
* Necessity: Let f(a)=a′. It suffices to prove that an operation on a does not affect f(a). An expand operation obviously doesn't affect f(a). A shrink operation shrinks a[i,i+m−1] into one element. When computing f(a′), we will always expand a′i at some time, so the result is the same as $f(a)$​.

Time complexity is O((n+k)logmV), where V=maxai.

[1696D - Permutation Graph](../problems/D._Permutation_Graph.md "Codeforces Global Round 21")

This problem has two different solutions. The first one is more beautiful, but less straight-forward.

 **Hint 1 for solution 1**The solution is O(n). We don't need any data structures.

 **Hint 2 for solution 1**Instead of trying to construct the shortest path from 1 to n, find a "transfer vertex" that we must pass through.

 **Answer**We will always pass through the position of the maximum element in the array.

 **Hint 3 for solution 1**Suppose the maximum element is ak. Solve recursively for dis(1,k) and dis(k,n).

 **Solution 1**Denote dis(x,y) as the length of the shortest path between x and y.

Consider a position i that ai=n. Assume i≠1 and i≠n. For a segment that passes i, its maximum element is always ai. Thus, for x<i<y, x and y will never be directly connected by an edge. This means that when going from 1 to n, we have to pass i. Let us solve recursively for dis(1,i) and dis(i,n). For example, we solve for dis(1,i).

We already know that ai=n, so i is the maximum element in [1,i]. Consider the minimum element in [1,i], suppose it is aj (j<i). From similar arguments, we can solve recursively for dis(1,j) and dis(j,i). However, note that dis(j,i) equals to 1: since j and i are respectively minimum and maximum in [1,i], they have to be minimum and maximum in [j,i] as well. So i,j must be directly connected. Thus, we only need to solve recursively for dis(1,j).

The process with dis(i,n) is similar. Note that we will only call dis(l,r) for l=1 or r=n (if not, the return value is always 1), so it suffices to pre-compute prefix and suffix minimums and maximums.

The time complexity is O(n).

 **Hint 1 for solution 2**Look at the last sample test case. Think of a simple greedy.

 **Answer**Keep going to the rightmost vertex (the vertex with the largest id) works.

 **Hint 2 for solution 2**Use data structures to simulate the process. How?

 **Solution 2**We can prove that keep going to the vertex with the largest index is a correct strategy. The proof is left as an exercise :) Hint: try to prove that the path we will visit is the same as the path we visited in solution 1.

Suppose we are at i. We want to find the largest j>i such that i and j are directly connected. WLOG, assume ai+1<ai. Then, it cannot be the case that aj>ai, since none of ai,aj will be mn(i,j). Thus aj<ai. It follows that all i<k<j satisfies ak<ai, otherwise none of ai,aj will be mx(i,j).

Let ri be the largest p, such that for all t∈[i+1,p], at<ai. From the arguments above we know j∈[i+1,ri]. ri can be pre-computed with a stack, or binary search + some data structures.

Let j0 be the position of the minimum element in [i+1,ri]. Obviously j0 is directly connected with i. For any j0<k≤ri, mn(i,k) will be aj0, showing that all such k is not directly connected with i. Thus, j0 is the desired j.

If we use data structures for range minimum, we get a O(nlogn) solution, which can easily pass (not sure whether O(nlog2n) ones will pass though, the large constraints were intended to cut those).

However, by building the cartesian tree of the array and doing proper pre-computations, we can optimize this solution to O(n).

[1696E - Placing Jinas](../problems/E._Placing_Jinas.md "Codeforces Global Round 21")

 **Hint 1**Try to find out the number of operations we do on a specific cell (i,j), call it f(i,j).

 **Hint 2**Write the recurrence formula for f(i,j). What is f(i,j)?

 **Answer**f(i,j)=(i+jj)

 **Hint 3**The answer is the sum of f(i,j) over all white cells (i,j). Use some combinatorics formula to speed it up.

 **Solution**Let us find out the number of operations we do on a specific cell (i,j), call it f(i,j).

Every operation done on (i−1,j) will lead to one doll on (i,j), thus consuming one operation on (i,j). Similar observation holds for (i,j−1).

Thus, f(i,j)=f(i,j−1)+f(i−1,j) (given that (i,j),(i−1,j),(i,j−1) are all white cells). Note that a is non-increasing: this means that if (i,j) is white, (i−1,j),(i,j−1) will both be white. So we can conclude that f(i,j)=f(i,j−1)+f(i−1,j) always holds as long as (i,j) is white.

Another way to see the formula is f(i,j) is the number of ways to go from (0,0) to (i,j), only going down or right by 1 step. This implies that f(i,j)=(i+jj).

From this, we know that the answer is ∑ni=0∑ai−1j=0(i+ji). With the equation ∑ki=0(n+in)=(n+k+1n+1), we know that the answer is ∑ni=0(i+aii+1).

The time complexity is O(n+V), where V=maxai.

[1696F - Tree Recovery](../problems/F._Tree_Recovery.md "Codeforces Global Round 21")

 **Hint 1**The solution does not contain painful casework and deadly implemention.

 **Hint 2**Suppose we aleady know edge (i,j) exists in the tree. What can we know from it?

 **Answer**We can immediately recover the whole tree.

 **Solution**Read the hints first to understand the solution better.

Construct a graph with (n2) vertices (1,2),(1,3),…,(n−1,n).

If dis(a,b)=dis(b,c), link an undirected edge between (a,b) and (b,c).

Observe that all edges in the tree form a connected component of size exactly n−1 in the graph!

Find all components of size n−1 and try if all vertices in it form a tree that satisfy the input. There are at most n2 such components, so complexity is O(n4). Proper pre-computation and the usage of bitsets can reduce the complexity to O(n4/w).

[1696G - Fishingprince Plays With Array Again](../problems/G._Fishingprince_Plays_With_Array_Again.md "Codeforces Global Round 21")

 **Hint 1**What kind of problem is this problem?

 **Answer**Linear programming.

 **Hint 2**Consider the dual.

 **Hint 3**Consider the case when n=2. Draw the linear programming on a xOy-coordinate. Try to observe what the answer might be.

 **Solution**First we solve the problem with only 1 query on the whole array A.

This is a linear programming problem:

 minimize∑1≤i<nai+biXa1+Yb1≥A1Xai+Ybi+Yai−1+Xbi−1≥Ai (2≤i<n)Yan−1+Xbn−1≥Anai,bi≥0Consider its dual:

 maximize∑1≤i≤nAixiXxi+Yxi+1≤1 (1≤x<n)Yxi+Xxi+1≤1 (1≤x<n)xi≥0Suppose X≤Y. Now we will prove that there exists an optimal solution to the dual problem, in which xi can only take three values: 1/Y,1/(X+Y),0.

The proof is as follows: It is well-known that an optimal solution to a linear programming problem must lie on a vertex of the "multi-dimensional convex polygon" which the restrictions surround. Thus we are only interested in xi that satisfy several "=" restrictions (and the restrictions should really intersect at one point, meaning that those "=" should uniquely determine x). Consider any "sufficient" (that means they uniquely determine x) subset of them. If one restriction is related to xp,xq, we link an undirected edge between p and q. If one restriction is only related to xp (i.e. xp=0), we link a self-loop on p. "Being sufficient" means that all connected components in the graph has exactly one cycle. However, for an edge (u,v), we know that either u=v+1 or u=v. This means that all cycles can only be (i→i+1→i) or i→i. If a cycle is (i→i+1→i), all xi in the component are 1/(X+Y); If a cycle is i→i, all xi in the component are 1/Y or 0 (not 1/X, because it exceeds the constraints).

Thus we can use dp to solve the dual problem. Let dp(i,0/1/2) be the maximum ∑j≤iAjxj when xi is the 0/1/2-th candidate above. Transitions are straight-forward.

For multiple queries, the transitions can be written into multiplying matrices, and we can use segment tree to maintain updates. 

About precision issues: actually we can avoid using floating point numbers completely. Note that all numbers in this problem are fractions with denominator Y(X+Y). Also note that the answer does not exceed (∑ai)/Y. This means that the numerator does not exceed (∑ai)×(X+Y)<1018, so we can use long long-s to only store numerators. If you use double in C++, the relative error of one operation is less than 10−15. 10−15×n<10−9, which means that using doubles is also enough.

Complexity: O(n+qlogn).

[1696H - Maximum Product?](../problems/H._Maximum_Product_.md "Codeforces Global Round 21")

 **Hint 1**Find a way to calculate the maximum product that can be turned into counting.

 **Hint 2**Use monotonicity to reduce the complexity.

 **Solution**First, we describe a strategy to find the answer for a single subset. If the whole subset is negative, the answer is the product of the K maximum numbers in it. Otherwise, take K numbers with the maximum absolute value. If there is an even number of negative numbers in those numbers, we're done. Otherwise, find the smallest positive element and change it to the absolute-value-maximum negative element unchosen, or find the largest negative element and change it to the maximum positive element unchosen. We either do the first change or do the second change.

This gives a direct dp solution. Take all ai and sort them into two arrays consisting of positive and negative ones (0 goes to arbitary one), pos and neg, sorted by absolute values. By calculating fpos(i,k): the sum of the product of the largest K numbers of all subsets of pos[1…i] that contain posi, and fneg(i,k) similarly, and gneg(i,k), the sum of the product of the absolute value smallest K numbers of all subsets of neg[i…|neg|] that contain negi, and enumerating the following, we can solve the original problem in O(n5):

 * the number of positive elements in the K numbers with the maximum absolute value in our calculating subset, p.
* the smallest positive element in the K numbers with the maximum absolute value, posi.
* the greatest negative element in the K numbers with the maximum absolute value, negj.
* (if p is odd) the greatest positive element not in the K numbers with the maximum absolute value, posk.
* (if p is odd) the smallest negative element not in the K numbers with the maximum absolute value, posl.

The contribution to the answer can be represented as the sum of product of fpos,fneg, and powers of two. I left the details as an exercise.

However, notice that the "enumerating k,l" part has nothing to do with p, so we can pre-calculate the contribution of k,l for every pair (i,j), giving an O(n4) algorithm.

What's more, for fixed i,j,k, the l-s that we do the first change is a prefix/suffix of all l, and l-s that we do the second change is a prefix/suffix of all l. So with two pointers and prefix sums, we can pre-calculate the contribution of every (i,j) in O(n3), which is fast enough.

You might be afraid that 6003 is too slow for 1.5 seconds. However, the two O(n3) parts of the algorithm actually run in O(n×cntpos×cntneg) (cntpos,cntneg are the number of positive/negative integers in the array), leading to an at most 1/4 constant factor. Thus, the algorithm actually runs very fast (less than 0.25 seconds). However for similar constant factor reasons, the O(n4) solution only takes about 6.5 seconds on Codeforces, so we had to set a seemingly-tight limit.

