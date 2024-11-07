# Tutorial


### [1625A - Ancient Civilization](../problems/A._Ancient_Civilization.md "Codeforces Round 765 (Div. 2)")

Note that the problem can be solved independently for each bit, as the bits don't influence each other. Set the ith bit to zero if the numbers in the array contain more zeros than ones in the ith bit. Otherwise, set it to one.

 
### [1625B - Elementary Particles](../problems/B._Elementary_Particles.md "Codeforces Round 765 (Div. 2)")

Note the following fact. For each optimal pair of harmonious strings, it's true that the right string ends on the last character.

Proof: suppose it's wrong. Then, we can expand the strings to the right by one character, and they will remain harmonious.

Now, prove the following statement, that will help us to solve this problem. The statement is as follows: the answer is n−min(v−u) where minimum is over all u and v such that u<v and au=av.

Proof: consider two elements u and v such that u<v and au=av. Suppose that they are on the same position in a pair of harmonious substrings. What maximal length these substring may have?

From what was proved above, we know that we can expand the strings to the right. Take the first string starting in u and the second string starting with v. Then, we get the strings of length n−v+1 after expanding them.

Still, it's not enough. So, we will also expand the strings to the left. So, the total length of the strings will become n−v+u, which is equal to n−(v−u). The smaller v−u, the larger the length.

To solve the problem, we need to find a pair of nearest equal elements quickly. We can do the following: store all the positions of each element (i. e. all the positions with ai=1, with ai=2 etc.), and then we iterate over ai, go through the pairs of neighboring positions and calculate the minimum.

 
### [1625C - Road Optimization](../problems/C._Road_Optimization.md "Codeforces Round 765 (Div. 2)")

First you need to understand that this problem must be solved with dynamic programming. Let dpi,j is the minimum time to drive between the two cities, if we consider first i signs and have already removed j signs. We also assume that the ith sign is taken.

Then, the initial state is: dp0,0=0, dpi,0=dpi−1,0+bi−1⋅(ai−ai−1). So, we don't need to drive to the first sign (as it takes 0 seconds), and if we don't remove any signs, it's easy to calculate the time.

Initially, fill dpi,j=∞ for all i=1…n,j=1…k.

Then, the answer is min(dpn,j) over all j=0…k.

Consider which transitions can we make. Calculate our DP from bottom to top, so we go from smaller states to larger ones. Consider all the i=0…n−1 and all the j=0…k in the loop order, i. e:


```cpp
  
for (int i = 0; i < n; i++)  
  
for (int j = 0; j <= k; j++)  

```
If we see dpi,j=∞, then there's no answer and we'll just skip this state. For example, it may mean that i<j.

Now, iterate over the positions of the next sign we'll put. Call this position pos. The transitions are as follows: dppos,j+pos−i−1=min(dppos,j+pos−i−1,dpi,j+bi∗(apos−ai)).

Why such formula? After removing all the signs between [i+1,pos−1] we will stay on the sign pos, remove pos−i−1 signs, and the time to go from i to pos will depend on the sign i and the distance between i and pos.

So, we get the solution in O(n3).

There also exists a solution in O(n2⋅logn), which uses Convex Hull Trick. We don't describe it here, as it's not required to solve the problem.

 
### [1625D - Binary Spiders](../problems/D._Binary_Spiders.md "Codeforces Round 765 (Div. 2)")

To solve the problem, we need the following well-known fact. Suppose we have a set of numbers and we need to find minimal possible xor over all the pairs. It is true that, if we sort the numbers in non-descending order, the answer will be equal to minimal xor over neighboring numbers.

We need the minimal xor to be not less than k in this problem. For a quadratic solution, we can just sort the numbers and consider dpi — largest good subset such that the greatest element in it is equal to ai. Then, dpi=max(dpj+1), where aj⊕ai≥k. To make this solution faster, we can use a trie over the bits of numbers. In each vertex of the trie, we store the size of the largest good subset whose greatest element lies in this subtree. When we want to get the answer for i, we descend in the tree and get the answer for all the subtrees where we don't go, if the corresponding bit in k is equal to zero.

Time complexity is O(n⋅logmaxai). 

 
### [1625E1 - Cats on the Upgrade (easy version)](../problems/E1._Cats_on_the_Upgrade_(easy_version).md "Codeforces Round 765 (Div. 2)")

First, we need to make the input string an RBS. Consider one of the possible ways to do it.

First, we keep the stack of all the opening brackets. We remove the bracket from the stack if we encounter the corresponding closing bracket. If there is an unpaired closing bracket or an opening bracket which is not removed, they must be replaced with a dot. So, the input string becomes an RBS. It's not hard to see that there are no queries that pass through dots we put in this step.

Now, build a tree from the brackets. We will do it in the following way. Initially, there is one vertex. Then, if we encounter an opening bracket, we go one level below and create a new vertex, and if we encounter a closing bracket, then we go to the parent.

It's now clear that each vertex corresponds to an RBS. The root of the tree corresponds to the entire string, and leaf nodes correspond to empty RBSes.

Now, note that we can obtain all the RBSes if we take all the subsegments from the children of vertices. Each subsegment from the children looks like (RBS)(RBS)...(RBS), i. e. it's a concatenation of RBSes that correspond to children, where each one is put into brackets.

Now, we can make a simple DP. Indeed, the amount of all RBSes in a vertex is the sum of RBSes of its children plus k⋅(k+1)2, where k is the number of children. The amount of RBSes on the segment is calculated in a similar way. When we calculate such DP and can carefully find a vertex in the tree, we can answer the queries on the segment.

The time complexity is O(qlogn) or possibly O(n+q) if we manage to find the vertices corresponding to indices fast.

 
### [1625E2 - Cats on the Upgrade (hard version)](../problems/E2._Cats_on_the_Upgrade_(hard_version).md "Codeforces Round 765 (Div. 2)")

Now, we need to see how to handle removal queries in this task. Build an SQRT decomposition in the following way. We will rebuild the entire tree after each √n queries and recalculate the DP. Between the rebuilds, we hold a list of removed leaves.

Now look how we can recalculate the answer if some leaves are removed.

First suppose that the leaf is not a direct child of the vertex we are interested in. Then the removal of this leaf decreases the answer by q, where q is the number of children of this leaf's parent. Why so? The parent of this leaf had the answer as sum of answers in its children plus q⋅(q+1)2. The answer in the leaf is equal to zero, so the new answer became sum plus q⋅(q+1)2, thus decreased by q.

When we build the DP, the modification of answer in a vertex is passed to its parents unchanged. So, the answer decreases by q on the entire path from this leaf to the root.

We can easily check if we are affected by this removal. It must be applied only if the removed leaf lies strictly inside our query of the second type.

We also need to handle the case where our leaf is a direct child of the vertex we consider, as the removal described above doesn't fully apply to this case. This is an exercise left to the reader.

So, we get the solution in O((n+q)⋅√n).

There is also a solution in O((n+q)logn). We consider it very shortly.

Let's hold just k⋅(k+1)2 in each vertex, not the sum over children plus k⋅(k+1)2, as we did before. Then the answer for each vertex is the sum in the subtree.

We can keep a Fenwick tree, as we can calculate sums in the subtree with it, using Eulerian tour over the tree. It's not hard to see that each update must be applied only once to the direct parent.

