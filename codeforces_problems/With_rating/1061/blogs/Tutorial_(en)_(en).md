# Tutorial_(en)_(en)

I hope you guys enjoyed the contest and we hope to host another one soon :)

With that said, here are the tutorials:

 
### [1061A - Coins](../problems/A._Coins.md "Codeforces Round 523 (Div. 2)")

Notice that using maximum value coin whenever possible will be always optimal. Hence, we can use floor(S/n)floor(S/n) coins of value nn. Now, if SmodnSmodn is not equal to 00, then we need to use one more coin of valuation SmodnSmodn. Hence, our answer can be written as ceil(S/n)ceil(S/n).

Overall Complexity: O(1)O(1)

Author: [Ashishgup](https://codeforces.com/profile/Ashishgup "Master Ashishgup")

C++ Code: [46095081](https://codeforces.com/contest/1061/submission/46095081 "Submission 46095081 by Ashishgup")  
 Java Code: [46095332](https://codeforces.com/contest/1061/submission/46095332 "Submission 46095332 by Jeel_Vaishnav")

 
### [1061B - Views Matter](../problems/B._Views_Matter.md "Codeforces Round 523 (Div. 2)")

Let's sort the array in increasing order and find the minimum number of blocks $X$ required to retain the same top and right views. Then, the answer would be $\sum_{i=1}^{n} A_i - X$.

For every $i$ from $1$ to $N$, we need to keep at least $1$ block for this stack to retain the top view. Thus, $X = X + 1$ for every $i$. However, we also need to maintain the maximum height we can cover till now, by keeping $1$ block in this stack. 

Let the previous best height we had be $Y$.

Then, if $A[i] > Y$, then we managed to increase the height $Y$ by $1$, by keeping the block at $Y + 1$. However, if $A[i] = Y$, then we cannot increase the number of blocks in the right view, since we are only allowed to keep the current block in range $[1, Y]$. 

In the end, when we finish processing all the stacks, we also need to keep $max(A_i) - Y$ blocks in the longest stack, to retain the right view as it was originally.

Overall complexity: $O(n \log n)$

Refer to solution code for clarity.

Author: [Jeel_Vaishnav](https://codeforces.com/profile/Jeel_Vaishnav "Master Jeel_Vaishnav")

C++ Code: [46095083](https://codeforces.com/contest/1061/submission/46095083 "Submission 46095083 by Ashishgup")  
 Java Code: [46095337](https://codeforces.com/contest/1061/submission/46095337 "Submission 46095337 by Jeel_Vaishnav")

 
### [1061C - Multiplicity](../problems/C._Multiplicity.md "Codeforces Round 523 (Div. 2)")

Let's introduce the following dynamic programming approach, dp[n][n]dp[n][n], where dp[i][j]dp[i][j] indicates the number of ways to select a good subsequence of size jj from elements a1,a2,...,aia1,a2,...,ai. Our final answer will be ∑ni=1dp[n][i]∑i=1ndp[n][i].

dp[i][j]={dp[i−1][j]+dp[i−1][j−1]dp[i−1][j]if a[i] is a multiple of jotherwisedp[i][j]={dp[i−1][j]+dp[i−1][j−1]if a[i] is a multiple of jdp[i−1][j]otherwise

Now, maintaining a 2-D dp will exceed memory limit, however notice that dp[i]dp[i] is calculated only on the basis of dp[i−1]dp[i−1], hence mainitaining a 1-D dp will work. Also, now dp[j]dp[j] is updated if and only if jj is a divisor of a[i]a[i]. We can find divisors of a number xx in O(x−−√)O(x).

Overall Complexity : O(n⋅(maxD+maxA−−−−−√))O(n⋅(maxD+maxA)). Here, maxDmaxD indicates maximum number of divisors possible and maxAmaxA indicates maximum value of aiai possible.

Also, we can use sieve to compute divisors of each number and achieve complexity of O(maxA⋅log(maxA)+n⋅maxD)O(maxA⋅log(maxA)+n⋅maxD).

Authors: [Jeel_Vaishnav](https://codeforces.com/profile/Jeel_Vaishnav "Master Jeel_Vaishnav"), [Ashishgup](https://codeforces.com/profile/Ashishgup "Master Ashishgup")

C++ Code: [46095097](https://codeforces.com/contest/1061/submission/46095097 "Submission 46095097 by Ashishgup")  
 Java Code: [46095342](https://codeforces.com/contest/1061/submission/46095342 "Submission 46095342 by Jeel_Vaishnav")

 
### [1061D - TV Shows](../problems/D._TV_Shows.md "Codeforces Round 523 (Div. 2)")

Solution: Sort the TV shows on the basis of their starting time. Now, we start allocating TVs greedily to the shows. For any show ii, we allocate a new TV only if there is no old TV where the show ends at roro, such that ro<liro<li and (li−ro)⋅y<=x(li−ro)⋅y<=x. Also, if there are many such old TVs, then we use the TV where roro is maximum.

Proof: Notice that there is a minimal cost of ∑ni=1(ri−li)⋅y∑ni=1(ri−li)⋅y, which will always be added. Hence, the optimal solution completely depends on the rent of new TV and the time wasted on old TVs. 

Now, lets try to prove that allocating an old TV with maximum roro is optimal. Suppose we are allocating a TV to show ii. Let's consider two old TVs o1o1 and o2o2, such that ro1<ro2<liro1<ro2<li and (li−ro1)⋅y<=x(li−ro1)⋅y<=x. In such a case, it is possible to allocate both the TVs to this show. For choosing which TV to be allocated let's consider the three possible cases:

Case I: There is no show j(j>i)j(j>i), such that (lj−ro2)⋅y<=x(lj−ro2)⋅y<=x. In this case, it would be better to allocate TV o2o2 to show ii, since (li−ro2)⋅y<(li−ro1)⋅y(li−ro2)⋅y<(li−ro1)⋅y. Hence, allocating TV o2o2 to show ii is optimal in this case.

Case II: There are shows j(j>i)j(j>i), such that (lj−ro2)⋅y<=x(lj−ro2)⋅y<=x; but there is no show j(j>i)j(j>i), such that (lj−ro1)⋅y<=x(lj−ro1)⋅y<=x. In this case, if we allocate TV o1o1 to show ii and TV o2o2 to show jj, then the cost will be (lj−ro2)⋅y+(li−ro1)⋅y(lj−ro2)⋅y+(li−ro1)⋅y. And, if we allocate TV o2o2 to show ii, then we need to buy a new TV for show jj and our cost will be x+(li−ro2)⋅yx+(li−ro2)⋅y. Now, as (lj−ro1)⋅y>x(lj−ro1)⋅y>x, (lj−ro2)⋅y+(li−ro1)⋅y>x+(li−ro2)⋅y(lj−ro2)⋅y+(li−ro1)⋅y>x+(li−ro2)⋅y. Hence, allocating TV o2o2 instead of TV o1o1 to show ii is optimal in this case.

Case III: There are shows j(j>i)j(j>i), such that (lj−ro1)⋅y<=x(lj−ro1)⋅y<=x. In this case, if we allocate TV o1o1 to show ii, cost will be (li−ro1)⋅y+(lj−ro2)⋅y(li−ro1)⋅y+(lj−ro2)⋅y. If we allocate TV o2o2 to show ii, cost will be (li−ro2)⋅y+(lj−ro1)⋅y(li−ro2)⋅y+(lj−ro1)⋅y. Here, we can see that in both of the allocations, the cost is (li+lj−ro1−ro2)⋅y(li+lj−ro1−ro2)⋅y and so any allocation is optimal here. 

Hence, we can see that if more than one old TVs are available, allocating the one with maximum roro is always optimal.

 Overall Complexity: O(n⋅logn)O(n⋅logn)

Authors: [Jeel_Vaishnav](https://codeforces.com/profile/Jeel_Vaishnav "Master Jeel_Vaishnav"), [Ashishgup](https://codeforces.com/profile/Ashishgup "Master Ashishgup")

C++ Code: [46095154](https://codeforces.com/contest/1061/submission/46095154 "Submission 46095154 by Ashishgup")  
 Java Code: [46095344](https://codeforces.com/contest/1061/submission/46095344 "Submission 46095344 by Jeel_Vaishnav")

 
### [1061E - Politics](../problems/E._Politics.md "Codeforces Round 523 (Div. 2)")

Let's create a graph with a source, sink and two layers. Let the left layer denote the nodes of tree 11 and right layer denote the nodes of tree 22. 

Let's denote xixi as the demand of the ithith node.

 For a demand (k,x)(k,x) in tree 1, we add an edge from source to node kk in the left layer with cost=0cost=0 and capacity=x−∑xjcapacity=x−∑xj, such that jj is not equal to ii and jj belongs to the subtree of ii. 

Similarly for a demand (k,x)(k,x) in tree 2, we add an edge from node kk in the right layer to sink with cost=0cost=0 and capacity=x−∑xjcapacity=x−∑xj, such that jj is not equal to ii and jj belongs to the subtree of ii. 

Now, for every node ii, let col1icol1i be the closest node to ii, such that ii belongs to subtree of col1icol1i and the demand of col1icol1i in tree 11 has been provided. Similarly col2icol2i be the closest node to ii, such that ii belongs to subtree of col2icol2i and the demand of col2icol2i in tree 22 has been provided.

For every node ii, we add an edge from col1icol1i in left layer to col2icol2i in right layer with capacity=1capacity=1 and cost=−aicost=−ai.

Now, when we run min cost max flow on this graph, our answer will be negative of the minimum cost obtained.

Overall Complexity: O(n3)O(n3) using MCMF with bellman ford; O(n2⋅logn)O(n2⋅logn) using MCMF with Dijkstra.

Author: [Jeel_Vaishnav](https://codeforces.com/profile/Jeel_Vaishnav "Master Jeel_Vaishnav")

Java Code: [46095349](https://codeforces.com/contest/1061/submission/46095349 "Submission 46095349 by Jeel_Vaishnav")

A nice explanation of Problem E by [Kognition](https://codeforces.com/profile/Kognition "Master Kognition") in the comment section: [Announcement_(en).md?#comment-473028](Announcement_(en).md?#comment-473028)

 
### [1061F - Lost Root](../problems/F._Lost_Root.md "Codeforces Round 523 (Div. 2)")

This solution had many randomized approaches, some with higher probability of passing and some with lower probability of passing.

The author's solution (there exist better solutions with even lower probability of failure - comment yours below) is as follows:

Part 1: Checking if a node is a leaf node:

It can be done in $O(n)$ queries.

Suppose candidate node is $X$

Generate a random node $Y (!=X)$

For all $Z$, if $Y$ $X$ $Z$ is $false$, then $X$ is a leaf node, otherwise is not. 

Part 2: Finding a leaf node: 

Generate a random node and check if it is a leaf node. Probability of getting a lead node is $>=0.5$. Higher the $K$, higher the probability.

So we can find a leaf node in $O(20\cdot n)$ queries with failure probability $(1/2)^{20}$

Part 3: Generating a leaf node in other subtree of the actual root:

Fix a random node (that is not the same as the leaf node, $L1$, that we found), check if it is a leaf node, and if it is a leaf node and check if $2h-1$ nodes separate Leaf $1$ and this current leaf. If yes, we have found two separate leaf nodes and the $2h-1$ candidate nodes for the root. We can use  $O(40\cdot n)$ queries to ensure a failure probability of $(1/2)^{20}$

Finally: Instead of checking all of them separately in $2H\cdot N$, we can fix their order in $O(H^2)$ by finding each node's appropriate position by placing them incrementally. Let the initial path be $L1$ $L2$, then we add $X$ to get $L1$ $X$ $L2$. Now to find $Y$'s appropriate position, we check if it lies between $L1$, $X$ or $X$, $L2$. And so on. In the final order, the middle node would be the root.

Author: [Ashishgup](https://codeforces.com/profile/Ashishgup "Master Ashishgup")

C++ Code: [46095066](https://codeforces.com/contest/1061/submission/46095066 "Submission 46095066 by Ashishgup")  
 Java Code: [46095373](https://codeforces.com/contest/1061/submission/46095373 "Submission 46095373 by Jeel_Vaishnav")

