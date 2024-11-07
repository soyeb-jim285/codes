# Tutorial


### [1023A - Single Wildcard Pattern Matching](../problems/A._Single_Wildcard_Pattern_Matching.md "Codeforces Round 504 (rated, Div. 1 + Div. 2, based on VK Cup 2018 Final)")

If there is no wildcard character in the string s, the answer is "YES" if and only if strings s and t are equal. In the other case let's do the following thing: while both strings are not empty and their last characters are equal, let's erase them. Then do the same for the first characters, i.e. while both strings are not empty and their first characters are equal, let's erase them. Now if s is empty or s="*" the answer is "YES", otherwise the answer is "NO".

Problem idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov"), [awoo](https://codeforces.com/profile/awoo "Candidate Master awoo"); prepared by: [vovuh](https://codeforces.com/profile/vovuh "Candidate Master vovuh").

 
### [1023B - Pair of Toys](../problems/B._Pair_of_Toys.md "Codeforces Round 504 (rated, Div. 1 + Div. 2, based on VK Cup 2018 Final)")

The problem is to calculate the number of ways to choose two distinct integers from 1 to n with sum equals k.

If k≤n then the answer is ⌊k2⌋ because this is the number of ways to choose two distinct integers from 1 to k−1 with the sum equals k. Otherwise let mn=n−k will be the minimum possible term in the correct pair of integers. Also let mx=n will be the maximum possible term in the correct pair of integers. Then the answer is max(0,⌊mx−mn+12⌋) because this is the number of ways to choose two distinct integers from mn to mx with the sum equals k.

Problem idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov"), prepared by: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov").

 
### [1023C - Bracket Subsequence](../problems/C._Bracket_Subsequence.md "Codeforces Round 504 (rated, Div. 1 + Div. 2, based on VK Cup 2018 Final)")

Let the array used of n boolean values describe if the corresponding bracket of string s is included in answer or not.

The algorithm goes like this: iterate over the string from 1 to n, maintain the stack of positions of currenly unmatched opening brackets st. When opening bracket is met at position i, push i to st, and when closing bracket is met, set used[st.top()]=True, used[i]=True and pop the top of st. When k values are marked True in used then break, iterate from 1 to n and print the brackets at positions where used[i]=True.

Obviously, this algorithm produces a subsequence of s of length k. Why will it be a regular bracket sequence? The requirements for it are:

1. no prefix contains more closing brackets than opening ones;
2. the total number of closing bracket equals the total number of opening brackets.

The first requirement is met by construction, we couldn't pop more elements from the stack than it had. The second requirement is also met as we marked brackets in pairs.

Overall complexity: O(n).

Problem idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov"), prepared by: [awoo](https://codeforces.com/profile/awoo "Candidate Master awoo").

 
### [1023D - Array Restoration](../problems/D._Array_Restoration.md "Codeforces Round 504 (rated, Div. 1 + Div. 2, based on VK Cup 2018 Final)")

Let's firstly solve the problem as if there are no zeroes in the given array. Let li be the leftmost occurrence of i in the array and ri be the rightmost occurrence of i. The main observation is that you can choose segments (li;ri) for the corresponding queries and this sequence will be correct if and only if there exists any answer for the given array. If there is no occurrence of some value in the array then you can put the segment for it under the segment of some greater value. If there is no occurrence of q in the array then the answer doesn't exist.

For sure, segment (li,ri) is the minimum segment you can choose. You can expand it in both directions but it will never matter: these positions either will get covered by the segments of greater values or will replace the smaller values with i (and turn YES to NO if the answer existed). Finally, each position will be covered as each element is a left bound of a segment, a right bound of a segment or just covered by the segment of its value.

That problem can be solved with any data structure that allows you to assign values on segment and get the value of every position (segment tree, sqrt decomposition).

However, all the queries are performed offline (the resulting values are only needed after the queries) and the operation can be replaced with assigning maximum of the current value of element and the value of the query.

This can also be done using set. For each position you should keep the segments which start there and end there. For each segment (li,ri) you push i to the list for li and push i to the list for ri. Now you iterate from 1 to n, when entering i you add all values of opening segments to the set, assign the element at position i the maximum value of the set and remove all the values of closing segments from the set. The complexity of this algorithm is O(nlogq).

This algorithm can be easily applied to the problem with zeroes in the array. At the beginning you fill the resulting array with ones. After you performed the algorithm with set on the values from 1 to q, while constructing the segments from the non-zero elements of the given array, you check if the values you assigned are less or equal than the corresponding values of the given array. If that holds then the resulting array is already the correct one. Otherwise the answer doesn't exist. The only corner case there is if no value q was in array and there were some zeroes. That way you should just change any zero to q.

Overall complexity: O(nlogq).

Problem idea: [vovuh](https://codeforces.com/profile/vovuh "Candidate Master vovuh"), [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov"); prepared by: [awoo](https://codeforces.com/profile/awoo "Candidate Master awoo").

 
### [1023E - Down or Right](../problems/E._Down_or_Right.md "Codeforces Round 504 (rated, Div. 1 + Div. 2, based on VK Cup 2018 Final)")

Hint: Move from (1,1) to the middle by asking queries 'query(row, col, n, n)', starting with row=col=1. Similarly, move from (n,n) to the middle by asking queries 'query(1, 1, row, col)'. How to ensure that we will meet in the same cell in the middle?

The unusual condition in this problem is (r2−r1)+(c2−c1)≥n−1 that must be satisfied in every query. Without it, the following simple code would solve the problem:


```cpp
int row = 1, col = 1;  
while(row < n || col < n) {  
  if(row + 1 <= n && query(row + 1, col, n, n)) row++; // move down  
  else col++; // move right  
}
```
This program starts in (1,1) and greedily moves down if after this move we could still reach the cell (n,n). Otherwise, it must move right.

But in this problem, we can only get half the way this method. We must stop at the antidiagonal (one of cells: (1,n),(2,n−1),…,(n,1)). So maybe it's a good idea to move backward from (n,n) the same way, and meet at the antidiagonal? Not really :(

We indeed can apply the same algorithm starting from (n,n) and going towards (1,1), but possibly we will end in a different cell in the middle. It's possible even for an empty grid, without any blocked cells. We are very close to a correct solution, but let's focus on a thought process for a moment. Analyzing some other possible approach might help with that.

The limitation about the distance at least n−1 is just enough to ask a query between (1,1) and a cell from the antidiagonal, and also that cell and (n,n).


```cpp
for(int row = 1; row <= n; ++row) {  
  int col = n + 1 - row;  
  if(query(1, 1, row, col) && query(row, col, n, n)) {  
    print(row, col);  
  }  
}
```
This pseudocode would print reasonable candidates for a middle cell in our path — a cell reachable from (1,1) and from which the (n,n) is reachable. But after choosing some cell like this, it isn't that easy to find a way to the corner cells.

In our first idea, we were able to get from (1,1) to one of the reasonable candidates and from (n,n) to one of the reasonable candidates, but maybe a different one. Now a very important observation is: the first piece of code in this editorial will reach the leftmost (equivalently: downmost) reasonable candidate, because we always prefer moving down instead of right. For example, in an empty we would reach the bottom left corner. Now we see that we need to guarantee the same when moving from (n,n). So we should prioritize left direction over the up direction:


```cpp
row = n, col = n;  
while(row + col > n + 1) {  
  if(query(1, 1, row, col - 1)) col -= 1; // move left  
  else row -= 1; // move up  
}
```
Problem idea: [Errichto](https://codeforces.com/profile/Errichto "International Grandmaster Errichto"), prepared by: [Errichto](https://codeforces.com/profile/Errichto "International Grandmaster Errichto").

 
### [1023F - Mobile Phone Network](../problems/F._Mobile_Phone_Network.md "Codeforces Round 504 (rated, Div. 1 + Div. 2, based on VK Cup 2018 Final)")

Consider the forest of your edges.

Let's add edges into this forest greedily from our competitor's set in order of increasing weight until we have a spanning tree. Remember, we don't need to sort, the input is already given in sorted order.

Now, consider the competitor's edges one by one by increasing weight. Since we have a spanning tree, each competitor edge spans some path on our tree.

To process a competitor's edge, we can collapse all the nodes in the path into one single large node, and fix the cost of our edges along this path to be equal to the cost of the currently considered competitor's edge. We know this is an upper bound on cost since if any were higher, then by the cycle property of MSTs, the customer can ignore one of the higher cost edge on this cycle and choose the customer's edge instead.

In addition, this still allows us to satisfy the condition of the customer choosing all of our edges, since by Kruskal's algorithm, the customer will try to greedily add our edges first into their spanning tree and won't be able to add the customer edge since it now forms a cycle). This shows that this cost is the maximum possible profit since we have an upper bound on each edge, and this upper bound also gives a valid solution.

To determine if our answer can be unbounded, we can check if any of our edges remains uncollapsed after processing all competitor edges.

To do this efficiently, we can just do it naively (even without needing to compute LCAs!).

To show it's already fast enough, there are only a total of at most n merges overall and each merge can be done in α(n) time, where α(n) is the inverse ackermann function, so the overall complexity is O(m+(n+k)α(n)). Unfortunately, this is too hard to separate from solution with logarithms, so those were also allowed to pass (though TL might have been a bit more strict in those cases).

Problem idea: [Lewin](https://codeforces.com/profile/Lewin "Grandmaster Lewin"), prepared by: [Lewin](https://codeforces.com/profile/Lewin "Grandmaster Lewin").

 
### [1023G - Pisces](../problems/G._Pisces.md "Codeforces Round 504 (rated, Div. 1 + Div. 2, based on VK Cup 2018 Final)")

First, how do we find the answer in any time complexity? Let us construct a partially ordered set where each element is a single fish in one of the observations. For two elements x=(v1,d1) and y=(v2,d2) we put x<y if x and y could possibly be two occurences of the same fish one after the other, that is, there is enough time to get from one observation to another, so that ρ(v1,v2)≤d2−d1, where ρ(v1,v2) is the distance between the tree vertices, and d1 and d2 are respective day numbers of the two observations. We can now see that the answer is the smallest number of chains needed to cover all the vertices (a chain is a set of pairwise comparable elements of a p.o.set). By Dilworth's theorem, this is equal to the size of the largest antichain (a set of pairwise incomparable elements). Clearly, if a largest antichain contains a fish from an observation, than it must include all fish from this observation as well. We can now solve the problem in something like O(2k) time by trying all subsets of observations.

To get a better complexity we need to use the tree structure. To start, how do we check if a set of observations forms an antichain? Here's one criterion that works:

Proposition. A set S of observations is an antichain iff:

* For each subtree of the root v, a subset of S lying in that subtree is an antichain.
* There exists a time moment T such that it is impossible to reach v at time T from any observation in S (possibly travelling back in time).

Indeed, if both of these conditions hold, than for any two observations (v1,d1) and (v2,d2) happening in different subtrees we have ρ(v1,v2)=ρ(v,v1)+ρ(v,v2)>|d1−T|+|d2−T|≥|d1−d2|, hence these observations are incomparable. On the other hand, if S is an antichain, for any observation (vi,di)∈S there is an interval of time moments (li,ri) such that we cannot reach the root at any of times in (li,ri). If two observations i and j are incomparable, then(li,ri)∩(lj,rj)≠∅. But since we have a set of intervals with pairwise non-empty intersections, they must all share a common point, hence our time moment T exists.

Note that in some cases T is necessarily a non-integer: if there are two vertices at distance 1 from the root, and there are observations happening at days 1 and 2 respectively at these vertices, than any T∈(1,2) will suffice. However, T can always be either an integer or a half-integer, hence we can multiply all times and distances by 2 and assume T is integer.

The solution is going to be subtree dynamic programming dpv,t — the total weight of the largest antichain in the subtree of v such that no observation can reach v at time t. Recalculation is a bit tricky, so let's go step by step. First, if we have values of dpv,t, and no observations take place at v, how do we change dpv,t as we travel up the edge to the top of v? If the length of this edge is l, then the new values dp′v,t satisfy dp′v,t=maxt+lt′=t−ldpv,t′. Let's call this procedure "advancing l steps forward".

How do we account for observations at v? For an observation (v,t) with f fishes we cannot simply add f to dpv,t since we can obviously reach v at time t from this observation. Instead, the correct procedure is:

* advance the values 1 step;
* apply dp′v,t=max(dp′v,t,dpv,t+f) for all observations;
* advance the new values l−1 steps.

Finally, to combine the answers from the subtrees u1,…,uk of a vertex v (after the advancements were made in them), we simply add them element-wise for each t: dpv,t=∑uidpui,t.

Of course, we cannot store the DP values themselves since there are too much of them to store. Instead, we will need to use a data structure that will maintain a piecewise constant function. More specifically, let us maintain the positions where the function changes values: for each t such that dpv,t≠dpv,t+1 we store the pair (t,dpv,t+1−dpv,t). How all of the above manipulations look like in terms of this difference structure?

* Element-wise sum of two functions is simply the union of the difference sets. (We may want to combine the differences with the same t value, but for most implementations this is not necessary)
* When we advance l steps forward, the borders with positive differences will more l units to the left, and negative differences will move to the right. When two borders collide, then some of them get eliminated. Consider the function 10,1,5, with two differences (1,−9) and (2,4). After advancing this one step, the new function is 10,10,5, so there is now a single difference (2,−5). If we keep track of when and where these collisions take place, we can make changes to the structure accordingly.

The structure of choice here is a treap of differences. When we add two functions, we insert all elements of the smaller treap into the larger one; a standard argument shows that at most O(klogk) insertions will take place overall. To keep track of collisions, we'll have to maintain collision times for all adjacent border pairs, and store the minimal value in the root of each subtree. This may seem cumbersome, but every adjacent pair of elements occurs either as (the rightmost vertex in the left subtree of v, v), or (v, the leftmost vertex in the right subtree of v), hence the standard relax function in the treap implementation can handle this.

One further detail is that we don't want to change the time values in our treaps. Instead, we'll use "lazy" time shifting, that is, we'll keep an additional value Δ associated with each treap, and assume that for entries (t,d) with d>0 the actual time should be t−Δ, and with d<0 the time should be t+Δ. This way, we won't need to actually change anything in the treap when advancing (apart from resolving collisions).

The total complexity of this solution is O(n+klog2k).

Problem idea: [Endagorion](https://codeforces.com/profile/Endagorion "International Grandmaster Endagorion"), prepared by: [Endagorion](https://codeforces.com/profile/Endagorion "International Grandmaster Endagorion").

