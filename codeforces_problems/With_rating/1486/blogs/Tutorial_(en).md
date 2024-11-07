# Tutorial_(en)

[1486A - Shifting Stacks](../problems/A._Shifting_Stacks.md "Codeforces Round 703 (Div. 2)")

 **Hint1**What's the lower bound for the amount of blocks for the answer to be YES?

 **Hint2**Check the predicate for every prefix.

 **Solution**Let's consider the smallest amount of blocks we need to make the first i heights ascending. As heights are non-negative and ascending the heights should look like 0,1,2,3,...,i−1, so the minimum sum is (i−1)⋅i2. It turns out that this is the only requirement. If it's not the case for every prefix the answer is NO because we can't make some prefix ascending. Otherwise the answer is YES because you can move the blocks right till there is at least i blocks in the i-th stack and this would make the heights ascending.

Solution using C++: [107892022](https://codeforces.com/contest/1486/submission/107892022 "Submission 107892022 by okwedook")  
 Solution using Python: [107892053](https://codeforces.com/contest/1486/submission/107892053 "Submission 107892053 by okwedook")

[1486B - Eastern Exhibition](../problems/B._Eastern_Exhibition.md "Codeforces Round 703 (Div. 2)")

 **Hint1**Is problem really two dimensional?

 **Hint2**How to solve the problem if y=0?

 **Solution**At first let's see that the problem is not two dimensional. If we change the x coordinate the sum of distances by y is not changed at all. So we just need to calculate the number of good points on a line with points having coordinates x and then y and multiply the answers.

Now to calculate the answer on a line we could use a known fact: point with the smallest summary distance is between left and right median. So now we only need to sort the array and find the elements on positions ⌊n+12⌋ and ⌊n+22⌋ and return their difference plus one.

Solution using C++: [107892065](https://codeforces.com/contest/1486/submission/107892065 "Submission 107892065 by okwedook")  
 Solution using Python: [107892085](https://codeforces.com/contest/1486/submission/107892085 "Submission 107892085 by okwedook")

[1486C1 - Guessing the Greatest (easy version)](../problems/C1._Guessing_the_Greatest_(easy_version).md "Codeforces Round 703 (Div. 2)")

 **Hint1**Binary search?

 **Hint2**How to check if the maximum element is in the left or the right part of the array in two queries?

 **Solution**Let's solve for some subsegment [l,r) and mid=(l+r)/2. Now let's check if the max element is in [l,mid) or [mid,r). Let's find the second max element in [l,r) and call it smax. Now let's think that smax is less than mid (for symmetrical reasons). Now if we ask [l,mid) and second max is still smax it means that maximum element is in [l,mid), otherwise it's in [mid,r). Now we've shrunk the segment by a factor of two. So the resulting number of queries is 2⋅⌈log2105⌉=34.

Solution using C++: [107892097](https://codeforces.com/contest/1486/submission/107892097 "Submission 107892097 by okwedook")  
 Solution using Python: [107892140](https://codeforces.com/contest/1486/submission/107892140 "Submission 107892140 by okwedook")

[1486C2 - Guessing the Greatest (hard version)](../problems/C2._Guessing_the_Greatest_(hard_version).md "Codeforces Round 703 (Div. 2)")

Kudos to [Aleks5d](https://codeforces.com/profile/Aleks5d "International Grandmaster Aleks5d") for proposing a solution to this subproblem.

 **Hint1**Binary search AGAIN?

 **Hint2**How to solve the problem if the second maximum element is at position 1?

 **Hint3**How to check if the maximum element is to the left or the right of the second maximum in two queries?

 **Solution**Let's find second max smax. Now let's check if the max element is to the left, or to the right. Just ask [1,smax] and see if the answer is different to smax. Now let's suppose that the max element is to the right (for symmetrical reasons). Now we only need to find the smallest m such that the answer to the query [smax,m] is smax. The smallest such m is obviously the position of the maximum element. Now we need to use binary search to find such m. So the resulting number of queries is 2+⌈log2105⌉=19.

Solution using C++: [107892122](https://codeforces.com/contest/1486/submission/107892122 "Submission 107892122 by okwedook")  
 Solution using Python: [107892144](https://codeforces.com/contest/1486/submission/107892144 "Submission 107892144 by okwedook")

[1486D - Max Median](../problems/D._Max_Median.md "Codeforces Round 703 (Div. 2)")

 **Hint1**How to solve the problem if all the values are −1 and 1?

 **Hint2**Binary search ONCE MORE?

 **Hint3**How to check if the answer is at least x?

 **Solution**Let's binary search the answer. Now let's check if the answer is at least x. Replace all values that are at least x with 1 and values that are less than x with −1. Now if for some segment the median is at least x if the sum on this subsegment is positive! Now we only need to check if the array consisting of −1 and 1 has a subsegment of length at least k with positive sum. So let's just calculate prefix sums of this array and for prefix sum at position i choose the minimum prefix sum amongst positions 0,1,...,i−k, which can be done using prefix minimum in linear time.

So the resulting complexity is O(nlogn).

Solution using C++: [107892153](https://codeforces.com/contest/1486/submission/107892153 "Submission 107892153 by okwedook")  
 Solution using Python: [107892163](https://codeforces.com/contest/1486/submission/107892163 "Submission 107892163 by okwedook")

[1486E - Paired Payment](../problems/E._Paired_Payment.md "Codeforces Round 703 (Div. 2)")

 **Hint1**Did you read that w is at most 50?

 **Hint2**How to change the graph for dijkstra algorithm to work with this rule?

 **Hint3**Add some fake vertices and edges to make things work.

 **Solution**Let's think about it this way. For a middle vertex we only care what are the weights of the edges that pass through it. Now for every vertex v let's create some fake vertices (v,w), where w is the weight of the last edge. This would add at most O(M) new vertices. Now for each starting edge (u,v,w) let's make an edge u→(v,w) of weight 0 and for each vertex (u,was) and edge (u,v,w) let's create an edge (u,was)→v with weight (was+w)2. Now running Dijkstra's algorithm from vertex 1 will result for correct answers for all vertices (as we've simulated the paired edge situation with fake vertices and edges). Also we wouldn't create more than O(M⋅maxW) edges cause if some vertex has degree t we would create no more than t⋅maxW edges and sum of all t is 2⋅M.

Carefully implemented this would result in O(M⋅maxW⋅logM) or O(M⋅maxW+MlogM) time and O(M⋅maxW) or O(M) memory. All of those were fine.

Solution using C++: [107892178](https://codeforces.com/contest/1486/submission/107892178 "Submission 107892178 by okwedook")

[1486F - Pairs of Paths](../problems/F._Pairs_of_Paths.md "Codeforces Round 703 (Div. 2)")

 **Hint1**Root the tree.

 **Hint2**After rooting the tree, how does the intersection of two paths look?

 **Hint3**After rooting the tree, what are the two types of intersection?

 **Solution**Let's root the tree at some vertex. Now the intersection vertex is lca for at least one path.

 **Proof**If the vertex wasn't lca for both paths it would mean that there are either two edges going up (which is impossible in a rooted tree) or they are going up by the same edge, but this would mean that this vertex parent is also an intersection point, so the paths are intersecting in at least 2 points, so this is impossible too.

Now there are two types of intersections: with the same lca and different lca. Let's count them independently.

For each path and it's lca let's find the subtrees that path goes to from lca. This would result in a triplet (lca,subtree1,subtree2) (replace subtree with −1 if there is none) with subtree1<subtree2 or both of them are −1.

Now to count the intersections of the first type let's use inclusion-exclusion principle. Remember all paths that have same lca. Now we need to calculate the number of pairs so that they have different subtree1 and subtree2 (or −1). The formula is going to be cntpath⋅(cntpath−1)/2−∑(cnt(subtree1,x)+cnt(x,subtree2)−(cnt(subtree1,subtree2)+1))/2 (from inclusion-exclusion principle) where cntpath is the number of paths with this lca and cnt(x,y) is the number of paths with triplet (lca,x,y). The situation with −1 is pretty similar, left as an exercise to the reader.

Finding the number of intersections of second type is a bit easier. We just need to calculate the number of all intersections between a path with fixed lca and a vertical path which crosses this lca (the path is not neccessarily vertical, but it contains both lca and it's parent) and then subtract cnt(subtree1) and cnt(subtree2), where cnt(x) is the number of vertical paths that go into subtree x.

After that we just have to print out the sum of this two numbers. Counting all the needed functions can be done using some data structure (small-to-large for example) or some subtree dynamic programming.

The resulting complexity is O(Mlog2M) or O(MlogM) or even O(M) if you're strong enough.

Solution using C++: [107892186](https://codeforces.com/contest/1486/submission/107892186 "Submission 107892186 by okwedook")

