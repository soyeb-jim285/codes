# Tutorial

Problems were authored and prepared by:

A: [KAN](https://codeforces.com/profile/KAN "Legendary Grandmaster KAN"), [dimatimoshin23](https://codeforces.com/profile/dimatimoshin23 "Master dimatimoshin23"), [kirill.grachoff](https://codeforces.com/profile/kirill.grachoff "Master kirill.grachoff"), [antonis.white](https://codeforces.com/profile/antonis.white "International Master antonis.white")

B: [kirill.grachoff](https://codeforces.com/profile/kirill.grachoff "Master kirill.grachoff")

C: [napstablook](https://codeforces.com/profile/napstablook "Candidate Master napstablook")

D: [antonis.white](https://codeforces.com/profile/antonis.white "International Master antonis.white")

E: [antonis.white](https://codeforces.com/profile/antonis.white "International Master antonis.white")

F: [Denisson](https://codeforces.com/profile/Denisson "International Grandmaster Denisson")

G: [antonis.white](https://codeforces.com/profile/antonis.white "International Master antonis.white")

 
### [1585A - Life of a Flower](../problems/A._Life_of_a_Flower.md "Technocup 2022 - Elimination Round 3")

Iterating through array and looking on our element and previous element, there is possible 4 variants: 

* ai==1ai==1 and ai−1==1ai−1==1 — k += 5
* ai==1ai==1 and ai−1==0ai−1==0 — k += 1
* ai==0ai==0 and ai−1==1ai−1==1 — k += 0
* ai==0ai==0 and ai−1==0ai−1==0 — k = -1, break
 
### [1585B - Array Eversion](../problems/B._Array_Eversion.md "Technocup 2022 - Elimination Round 3")

Lemma: If x is max element of the array then eversion doesn't change the array.

Proof: In spite of the fact that division is stable, all elements will be passed to the left part. Their order won't be changed.

Lemma: The lastest element after eversion is the rightest element of the array which is greater than x and lefter than x in the array.

Proof: Look at all elements that are greater than x. This is the right part of the division. Due to stable division, the right element that is greater will be new x. There're no elements greater than x and righter than x because of eversion definition.

Let's build a sequence xa,xa−1,…x0, where x0=an, xi+1 — the rightest element lefter than xi and greater than xi. The answer is equals to a because {xi} is a sequence of last elements overall eversions.

Example: 6 10 4 17 9 2 8 1

Sequence {xi} — is 1,8,9,17. Answer is 3.

 
### [1585C - Minimize Distance](../problems/C._Minimize_Distance.md "Technocup 2022 - Elimination Round 3")

This problem can be solved with a greedy approach. First, we note that it makes sense to solve positive points xp and negative points xn separately since we would like the minimize the number of times we move across the origin. Second, when we move to the farthest depot to which we haven't delivered a bag yet, we can cover k−1 other depots. Thus we can also deliver bags to the k−1 next farthest depots from the origin. Thus to solve the positive set, we can just sort the positive points and take the sum of the distance of points starting from the farthest point, jumping k points at each step. Thus we can sort xp and xn and find the answer through the following equations:

sumpos=|pos|−ki>=0∑i=0xp|pos|−ki

sumneg=|neg|−ki>=0∑i=0xn|neg|−ki

The final answer will be 2(sumpos+sumneg) minus the maximum distance of a positive or negative depot since we do not have to return to the origin in the end.

 
### [1585D - Yet Another Sorting Problem](../problems/D._Yet_Another_Sorting_Problem.md "Technocup 2022 - Elimination Round 3")

Set of all 3-cycles generates a group of even permuations An. So the answer is "YES" if and only if there is an even permutation that sorts array a.

If all elements of a are distinct, then there is unique sorting permutation that has the same parity as a.

If there are identic elements in a, let's look at arbitrary sorting permutation. If it's odd, then we can add transposition of identic elements to it, after this permutation remains sorting, but becomes even. So in this case, even sorting permutation always exists.

Overall, we need to check if all elements of a are distinct. If it's not true, then answer is "YES". Otherwise, we need to check that permutation a is even. This can be done in many ways, including some with O(n) complexity.

 
### [1585E - Frequency Queries](../problems/E._Frequency_Queries.md "Technocup 2022 - Elimination Round 3")

Let's traverse through the tree with depth-first-search from the root and maintain counting array (cntx := "number of occasions of x in the sequence"). When dfs enters vertex v, it increases cntav by 1, then it proceeds all queries correspondent to v. When dfs leaves the vertex, it decreases cntav by 1.

Let's maintain this quantities: 

* Sorting permuation p of cnt, initially — 1,2,…,n.
* Inverse permuation p−1.
* For each x∈{0,1,…,n}, "lower_bound" lbx in sorted array. More formally, minimal i such that cntpi≥x.

When we want to increase cntx by 1: 

* Move x in the end of block of same values in sorted array. So we need to swap (p−1i)-th and (lbcntx+1−1)-th positions of p.
* Change p−1 accrodingly to the change of p.
* Decrease lbcntx+1 by 1. Note: that's the only lb value that after during this operation.
* Increase cntx.

Operation of decreasing cntx by 1 can be done symmetrically.

Note: if answer exists, then one of possible answers is plbl+k−1.

Total complexity: O(n+q).

 
### [1585F - Non-equal Neighbours](../problems/F._Non-equal_Neighbours.md "Technocup 2022 - Elimination Round 3")

Let's solve the problem using the inclusion-exclusion formula. Let the i-th property mean that the elements bi and bi+1 are the same. Then for each k=1,…,n−1 the array is divided into n−k consecutive segments, where all the numbers in each of the segments are equal. 

Next, we will use the dynamic programming method dp[i][j] − we have already split the prefix of the array b of length i into a number of segments, where j denotes the parity of the number of segments.

We will iterate over the index i=1,…,n. Now for each j (1≤j<i) we have to make an update dp[i][0]+=dp[j−1][1]⋅f(j,i), where f(j,i) is the minimum of the numbers in the array a on the segment [j,i]. Similar to dp[i][1]+=dp[j−1][0]∗⋅f(j,i). 

We get the solution with time complexity O(n2). To speed it up to O(n), it is enough to maintain a stack of minimums on the prefix and recalculate dp[i][0/1] with it.

 Tutorial is loading...