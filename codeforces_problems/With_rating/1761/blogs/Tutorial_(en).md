# Tutorial_(en)

The tutorial for problem G will be added soon, we are translating it.

Update #1: OK it's added now.

Update #2: [Chinese editorial with lots of pretty derby anime pictures](https://codeforces.com/https://www.luogu.com.cn/blog/111055/ezec-r13-chinese-editorial)

 
### [1761A - Two Permutations](../problems/A._Two_Permutations.md "Pinely Round 1 (Div. 1 + Div. 2)")

If a+b+2≤na+b+2≤n, we can always find such pair, here is a possible construction: 

A={1,2,⋯,a,n−b,a+1,a+2,⋯,n−b−1,n−b+1,n−b+2,⋯,n}B={1,2,⋯,a,a+1,a+2,⋯,n−b−1,n−b,n−b+1,n−b+2,⋯,n}

The red part is their longest common prefix, and the blue part is their longest common suffix.

Otherwise, the two permutations must be equal, so such pair exists iff a=b=n.

Author: [dXqwq](https://codeforces.com/profile/dXqwq "International Grandmaster dXqwq") 

### [1761B - Elimination of a Ring](../problems/B._Elimination_of_a_Ring.md "Pinely Round 1 (Div. 1 + Div. 2)")

Hint

Do we need more than 3 types of elements? Try to solve the problem with ai≤3.

Solution

First of all, when there're only 2 types of elements appearing in the sequence, the answer would be n2+1.

Otherwise, the conclusion is that we can always reach n operations when there are more than 2 types of elements appearing in the sequence.

The proof is given below: When the length of the sequence is greater than 3, there will always be a pair of positions (i,j), such that ai=aj and ai has two different neighboring elements. Then we can erase ai and then the problem is decomposed into a smaller one. If there do not exist such pairs, then we can infer that there exists at least 1 element which appeared only once in the sequence. If there exists such element b, then we can continuously erase all the elements next to b, then erase b at last. When the length n of the sequence is less than 3, it is clear that there will be exactly n operations as well.

So we only need to check the number of elements that appeared in the sequence of length n. If the number is 2, the answer will be n2+1. Otherwise, the answer equals n.

 Author: [SpaceJellyfish](https://codeforces.com/profile/SpaceJellyfish "Grandmaster SpaceJellyfish") 
### [1761C - Set Construction](../problems/C._Set_Construction.md "Pinely Round 1 (Div. 1 + Div. 2)")

Hint 1: When you are trying to add an element into a set S, you will have to add the element to every set that is meant to include S.

Hint 2: If A does not include B, then A and B are already distinct.

If A does include B, What is the easiest way of making A and B distinct?

Solution: Denote an ancestor to S as a set that is meant to include S.

Denote a descendant to S as a set that is meant to be included by S.

Let all sets be empty from the beginning.

Iterate through the sets. To make set S distinct from its descendants, we can add a new number xS that hasn't been added to any previous sets to S and all of its ancestors.

After the execution above, we will find out that the conditions are all satisfied, since:

- For all descendants of a set S, all the elements they have will be included in S;

- Vice versa for all ancestors of a set S;

- For each set T that is not an ancestor nor a descendant to S, they will not include each other. This is because S does not include T, since S does not have the element xT; and T does not include S for the same reason.

Therefore, the construction above satisfies all given conditions.

Moreover, we can set xS to the index of S for a simpler implementation.

 Author: [Forever_Pursuit](https://codeforces.com/profile/Forever_Pursuit "International Master Forever_Pursuit") 
### [1761D - Carry Bit](../problems/D._Carry_Bit.md "Pinely Round 1 (Div. 1 + Div. 2)")

Hint 1: Try to solve the problem in O(nk) using DP.

Hint 2: There is no need for DP.

Hint 3: You can consider enumerating the bits to carry, and then counting.

Let ai represents the i-th bit of a in binary representation (that is, 2i×ai=a∧2i) and define bi similarly.

If you decide which bits to carry ahead, you will find that every bit of a,b is independent (because whether the previous bit carries or not is decided), so you can use the multiplication principle to count. 

Therefore, in the remaining tutorial, we should determine the carries first and then count the number of options of ai,bi meeting the constraints of carries.

Define array c as our decided carry plan, ci=1 indicates that the i-th bit is carried, and define c−1 as 0.

Notice that ci=ai∨bi∨ci−1.

Ponder each bit, we will notice that if

* ci=ci−1=0, (ai,bi) can be (0,0),(0,1),(1,0).
* ci=ci−1=1, (ai,bi) can be (1,1),(0,1),(1,0).
* ci=1 and ci−1=0, (ai,bi) must be (1,1).
* ci=0 and ci−1=1, (ai,bi) must be (0,0).

That means that pair (ai,bi) has 3 options if ci=ci−1, and pair (ai,bi) has 1 options if ci≠ci−1.

So if array c has q positions that ci≠ci−1 ( 0≤i<n, remember we define c−1 as 0 ), the count of pair (a,b) is 3n−q.

Now we can enumerate q, and count the number of c has q positions that ci≠ci−1.

The new problem equals a typical binomial problem.

Notice that for every q, a valid c should have ⌊q2⌋ segment of consecutive 1s and ⌈q2⌉ segment of consecutive 0s if we seen c−1 as a normal bit (so that we have n−k+1 zeros).

The number of solutions that divide a elements into b segments is (a−1b−1). 

Therefore the answer of each q is 3n−q×(k−1⌊q2⌋−1)×((n−k+1)−1⌈q2⌉−1), and we can calculate it in Θ(1).

Add them all and you can find the answer in Θ(n).

 Author: [unputdownable](https://codeforces.com/profile/unputdownable "Master unputdownable") 
### [1761E - Make It Connected](../problems/E._Make_It_Connected.md "Pinely Round 1 (Div. 1 + Div. 2)")

Hint 1

Try to figure out the conditions where a task can be solved with 1 operation. Then 2 operations, and then even more operations.

Hint 2

The answer could be larger than 2 only when the graph is made up of 2 cliques, where you could only perform the operations on every vertex in the smaller clique to get the minimum number of operations.

Solution

First of all, we need to check if the graph is already connected at the beginning. If so, the answer would be 0.

Otherwise, there will be more than 1 connected component. If there exists a vertex that is the only vertex required to be operated to make the graph connected, we call such a vertex "feasible vertex". We may find out that a feasible vertex can only appear in a connected component that is not a clique.

But actually, there will always be such a vertex in a non-clique component. To prove this, we may figure out the sufficient condition for being a feasible vertex first.

The sufficient condition is that, if a vertex is not a cut vertex, and it is not adjacent to all other vertices in the connected component, then it must be a feasible vertex. We can prove that such a vertex always exists in a non-clique component. Here is the proof: 

* Firstly, if there exist non-cut vertices that are adjacent to all other vertices in the component, we erase them one by one until there don't exist any non-cut vertices which are adjacent to all other vertices (note that a non-cut vertex which is adjacent to all other vertices may become a cut vertex after erasing some of the other vertices). Apparently, the remaining component would still be a non-clique component. Otherwise, the component could only be a clique from the beginning, which contradicts the premise.
* Then, we will find a non-cut vertex in the remaining component, since that vertices in a graph couldn't be all cut vertices. The non-cut vertex we found is the vertex we are searching for.

But implementing it directly (meaning using Tarjan's algorithm to find a non-cut vertex) might not be the easiest way to solve the problem. Actually, the vertex with the least degree in a connected component always satisfy the condition. We would like to leave the proof work of the alternative method to you.

Now we have proven that, if there exists a connected component that is not a clique, then the answer would be at most 1. What if all connected components are cliques?

If there are exactly 2 connected components, then apparently we will have to operate on all vertices in a connected component. So we'll choose the smaller connected component to operate, and the answer is exactly the size of it.

Otherwise, we can arbitrarily choose two vertices from two different connected components and operate on them. The answer is 2.

Note that we also need to deal with isolated vertices (meaning vertices that are not adjacent to any other vertices) separately.

 Author: [SpaceJellyfish](https://codeforces.com/profile/SpaceJellyfish "Grandmaster SpaceJellyfish") 
### [1761F1 - Anti-median (Easy Version)](../problems/F1._Anti-median_(Easy_Version).md "Pinely Round 1 (Div. 1 + Div. 2)")

Let's analyze the structure of anti-median permutations.

First, if for any 2≤i≤n−1 holds ai−1>ai>ai+1, or ai−1<ai<ai+1, then segment p[i−1:i+1] is bad. So, the signs between adjacent elements are alternating. So, consider two cases: all elements on even positions are local maximums, and on odd local minimums, and vice versa.

Let's find the answer for the first case (for the second, you can find the answer similarly). Consider a segment of length 5, [pi−2,pi−1,pi,pi+1,pi+2]. Consider the case when i is even first. Then pi>pi−1,pi+1. For pi to not be median, it has to be larger than one of pi−2,pi+2. So, when we consider only even elements, each element (except the first and last one) has at least one adjacent element smaller than it. It's easy to see that this implies that elements at even positions are first increasing and then decreasing. 

Similarly, we can see that elements at odd positions are first decreasing, then increasing. It's not hard to see that these conditions are sufficient. Indeed, suppose that:

* All elements on even positions are local maximums, and all elements on odd positions are local minimums
* Elements at even positions are first increasing and then decreasing.
* Elements at odd positions are first decreasing, then increasing.

Then, consider any segment of odd length. Denote it by b1,b2,…,b2m+1, and wlog bm+1 is local maximum. If we look at local maximums, at least one of the following two conditions has to hold: all local maximums to the right of bm+1 are smaller than it, or all local maximums to the left of bm+1 are smaller than it. Wlog first case. Then all elements to the right of bm+1 are smaller than it, and bm is also smaller than it, so bm+1 can't be a median.

Now, let's put all elements on the circle in the following order: first, all even elements from left to right, then all odd elements from right to left. 

In this circle, the elements on both paths between n and 1 are decreasing. It follows that for any k, numbers from k to n form a segment (in this cyclic arrangement).

Then, we can write a dp of the form: dp[l][r]: how many ways are there to arrange the largest (r−l+1+n)modn elements so that they end up in the positions from l-th to r-th in this cyclic arrangement. All the transitions and checks are done in O(1), and there are O(n2) states, so we are done.

 Author: [antontrygubO_o](https://codeforces.com/profile/antontrygubO_o "International Grandmaster antontrygubO_o") 
### [1761F2 - Anti-median (Hard Version)](../problems/F2._Anti-median_(Hard_Version).md "Pinely Round 1 (Div. 1 + Div. 2)")

For this version, we have to analyze our dp a bit more.

Once again, how do anti-median permutations look? We consider the order of positions on the cycle, as in F1. We choose the position of n, and then, for i from n−1 to 1, we choose a position of number i among two options: right to the right of the current segment or right to the left.

If we fill this way, do we always get an anti-median permutation? Not really. This way makes sure that elements at even positions are first increasing, then decreasing, and at odd positions, first decreasing, then increasing, but it doesn't make sure that the element at the even position is larger than its neighbors. How do we guarantee that? Well, some segments are just not allowed: those, which contain a prefix of odd positions, prefix of even positions, and the prefix of odd positions is larger (off by ±1, depending on the parity of n), and same for suffixes.

Another observation is that if we know where x is, we only have to options for where can the segment of numbers from x to n be (to the right or to the left of x). 

This reduces our problem to the following subproblem: we start from some segment and have to end in another segment by expanding the current segment by 1 to the right or to the left without ever entering "bad segments." Turns out that we can solve this in O(1)! Indeed, represent expanding segment to the right by a move up in a coordinate plane and to the left by a move to the right. Then, we have to get from point (0,0) to some point (a,b) by moving up or to the right without ever crossing some line of form x=y+c. This is a well-known counting problem.

 Idea: [antontrygubO_o](https://codeforces.com/profile/antontrygubO_o "International Grandmaster antontrygubO_o")Solution: [orzdevinwang](https://codeforces.com/profile/orzdevinwang "Legendary Grandmaster orzdevinwang") 

### [1761G - Centroid Guess](../problems/G._Centroid_Guess.md "Pinely Round 1 (Div. 1 + Div. 2)")

Assuming we have already determined that the centroid of the tree is located on the path between u and v, we may now consider how to locate it.

Let c1,c2,…,ck be the vertices on the path from u to v. Let Ai be the set of vertices reachable from ci (including ci) if we erase all other vertices on the path from u to v. Then we may find that A1,A2,…,Ak are a division of all vertices.

Let si be the size of Ai. Then there must exist a vertex cx on the path satisfying that max{∑x−1i=1si,∑ki=x+1si}≤⌊n2⌋. Notice that the vertices that do not satisfy the condition could not be a centroid, and it is already determined that the centroid is on the path, so cx is exactly the centroid of the tree.

Then we may consider finding out which set each vertex belongs to with 2n queries so that we can calculate the value of si. For each vertex x, we may query disu,x and disv,x. For any two vertices x and y that belong to the same set, disu,x−distv,x should be equal to disu,y−disv,y. Let t1=disu,x−disv,x and t2=disu,v, then x∈A(t1+t2)/2+1. Thus we have found out the sets each vertex belongs to, as well as the value of si, as well as the centroid. This process requires at most 7.5×104×2=1.5×105 queries.

Now the problem remains to find a pair of vertices u and v such that the centroid locates on the path from u to v.

We can pick a constant M satisfying that M(M−1)2≤5×104, then select M vertices on the tree randomly, and query the distances between every pair of selected vertices. This requires M(M−1)2≤5×104 queries.

Let these M vertices be p1,p2,…,pM. We can build a virtual tree with p1 being the root that contains all the LCAs of each pair of vertices. Observe that disx,y+disy,z=disx,z if and only if y is located on the path between x and z. For a vertex px, we can find out all vertices on the path from p1 to px, and then find out the closest vertex to px and connect them. It is exactly the deepest ancestor of px.

Now that we have constructed the virtual tree without the LCAs with p1 being the root, we will then add the LCAs into the virtual tree.

Start DFS from p1. Assume the current vertex is u. Enumerate through the nodes adjacent to u. Assume the current vertex is v. If there exists another vertex x which is adjacent to u satisfying that u is not on the path between x and v, then x and u should be both in the subtree of one of u's child nodes. After finding out all vertices that are in the same subtree as v, it would be easy to calculate the depth of their LCAs as well as the distance between an LCA vertex and all other vertices in the virtual tree. Then, remove the old edge, and then add edges between the LCA and all vertices found in the same subtree as v. Lastly, add an edge between the LCA and u. Then repeat the process above, until any two vertices adjacent to u are not in the same subtree of a child node of u. Then DFS the child nodes of u. We will get the whole virtual tree after all DFS are done.

For the M vertices chosen from the beginning, we assume that their weights are all 1, while other vertices have 0 weight. Then we may find the weighted centroid of the virtual tree (when there are multiple such centroids, arbitrarily pick one), and then make it the root. Then for the two vertices with the largest and second-largest subtree of the root, DFS them, recursively find their child vertex with the largest subtree. We will be resulted with 2 leaf nodes. Then the centroid of the hidden tree is highly possible to be located on the path between these 2 nodes. The number of queries in both parts would not exceed 2×105.

Proof of correctness:

If the centroid is not on the path between u and v, assume the centroid of the virtual tree is in the subtree E of the centroid of the hidden tree. If the subtrees other than E contain at least 13 of the M vertices, then the centroid of the hidden tree must be on the path between u and v. So there will be at most 13 of the M vertices not being in E. In other words, for each of M vertices, it has a possibility greater than 12 of not being in E, and there will be at most 13 of the vertices which are not in E. The possibility of the algorithm being wrong is not greater than ∑M/3i=0CiM/2M, let M=316, then the value would be approximately 6×10−10.

 Author: [orzdevinwang](https://codeforces.com/profile/orzdevinwang "Legendary Grandmaster orzdevinwang")