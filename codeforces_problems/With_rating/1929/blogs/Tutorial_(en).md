# Tutorial_(en)

Problem A.

 **Solution**a2−a1+a3−a2+…+an−an−1=an−a1. So we just need to maximize this value, which means the answer is the maximum number in the array minus the minimum.

 

---

Problem B.

 **Solution**Let's notice that each cell intersects with no more than two diagonals, so the answer to the problem is at least k+12.

Claim: Let's look at the construction where we color all cells in the first row and leave only two side cells uncolored in the last row. Then each of these cells corresponds to exactly two diagonals. And if k≤(2n−2)∗2, then the answer is exactly k+12.

Now let's notice that if we color 2n−1 or 2n cells, then one or two cells will correspond to exactly one diagonal respectively, because in this case we must color the side cells, as they are the only diagonals not touched, but they are already covered by another diagonal corresponding to another corner cell.

Therefore, the answer in case of 4n−3 remains the same due to parity, and for 4n−2 it is k2+1.

 

---

Problem C.

 **Solution**Let's notice that the condition that we can achieve arbitrarily large values means that we need to guarantee at least a +1 to our coins. At the very first win. In this case, we can repeat this strategy indefinitely.

Also, let's notice that if we have lost a total of z before, then in the next round we need to bet y such that y⋅(k−1)>z, because otherwise the casino can give us a win. In this case, the condition of not losing more than x times in a row will disappear, and we will end up in the negative. Therefore, the tactic is not optimal.

Therefore, the solution is as follows: we bet 1 at first, then we bet the minimum number such that the win covers our loss. And if we have enough to make such a bet for x+1, then the casino must end up in the negative, otherwise we cannot win.

So the solution is in O(x) time complexity, where we simply calculate these values in a loop.

 

---

Problem D.

 **Solution**Let dpv be the number of non-empty sets of vertices in the subtree rooted at v such that there are no pairs of vertices in the set where one vertex is the ancestor of the other.

Then dpv=(dpu1+1)⋅(dpu2+1)⋅…⋅(dpuk+1), where u1,…,uk are the children of vertex v. This is because from each subtree, you can choose either any non-empty set or an empty set. Choosing an empty set from each subtree implies that only the single vertex v is selected (since our dynamic programming state cannot be empty).

Now the claim is: the answer to the problem is dp1+dp2+…+dpn+1. This is because if we consider the case where there is a pair of vertices where vertex v is the ancestor of the other, the answer in this case is dpu1+…+dpuk, as we can select such a set of vertices exactly from one subtree from the dynamic programming states. (And here we are using non-empty sets in the dynamic state, since otherwise, the case where there are no vertices where one is the ancestor of the other would be counted). And dp1+1 (where 1 is the root of the tree) accounts for the scenarios where there is no vertex where one is the ancestor of the other.

 

---

Problem E.

 **Solution**Let's consider each edge i and mark the set of pairs Si that it covers. Then the claim is: we have a total of O(k) different sets. This is because we are only interested in the edges that are present in the compressed tree on these k pairs of vertices. And as it is known, the number of edges in the compressed tree is O(k).

Then we need to find the minimum number of sets among these sets such that each pair is present in at least one of them. This can be achieved by dynamic programming on sets as follows:

Let dp[mask] be the minimum number of edges that need to be removed in order for at least one edge to be removed among the pairs corresponding to the individual set bits in mask.

Then the update is as follows: dp[mask|Si]=min(dp[mask|Si],dp[mask]+1) for all distinct sets S, where Si is the mask corresponding to the pairs passing through the edge. This update is performed because we are adding one more edge to this mask.

As a result, we obtain a solution with a time complexity of O(nk+2kk), where O(nk) is for precomputing the set of pairs removed by each edge for each edge, and O(2kk) is for updating the dynamic programming.

 

---

Problem F.

 **Soloution**Let's list the numbers of vertices in the order of their values. Let it be v1,…,vn. Then it must satisfy valuevi≤valuevi+1.

Then we have some segments in this order for which we do not know the values. For each segment, we know the maximum and minimum value that the values in this segment can take, let's say L and R. Then we need to choose a value from the interval (L,R) for each number in this segment in order to maintain the relative order. This is a known problem, and there are (R−L+lenlen) possible ways to do this, where len is the length of the segment. Then we need to multiply all these binomial coefficients.

Now, notice that R−L+len is large, so for calculation we can simply use the formula (nk)=n⋅(n−1)⋅…⋅(n−k+1)k!, since the sum len does not exceed n. 

