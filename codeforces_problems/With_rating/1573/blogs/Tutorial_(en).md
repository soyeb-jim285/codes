# Tutorial_(en)


### [1573A - Countdown](../problems/A._Countdown.md "Codeforces Round 743 (Div. 2)")

Let ss be the sum of all digits. In one operation we can decrease ss by at most 1 and we are finished iff s=0. This leads us to a conclusion that it is always unoptimal to decrease the number on the clock, when the least significant digit shows 0, since it will cost us at least 9 more operations.

Using this observation, the following strategy turns out to be optimal: 

* if the least significant digit is positive, decrease the number by 1
* if the least significant digit equals 0, swap it with some positive digit

Let p be the number of digits that are positive and aren't the least significant digit. Our answer will be s+p. This can be computed in O(n).

**Prepared by [Asymmetry](https://codeforces.com/profile/Asymmetry "Master Asymmetry")** 

### [1573B - Swaps](../problems/B._Swaps.md "Codeforces Round 743 (Div. 2)")

Since the array a has odd numbers and array b has even numbers, then they will differ at the first position no matter how we perform the operations. It follows that in order to make the first array lexicographically smaller than the second one we need to make the first element of a smaller than the first element of b. To move the i-th element of an array to the first position we can perform the operation on elements i−1, i−2, ..., 2, 1, which is optimal. The answer is then the minimum of i+j−2 over all ai, bj such that ai<bj.

Now we will think how to calculate this effectively. Let pi be the position of number i in its respective sequence (a for odd and b for even). We will go through the numbers from biggest to smallest. Let l be the position of the leftmost number in sequence b that was already considered. If i is even we will set l to min(l,pi). If i is odd we will set answer to min(answer,pi+l).

Our total time complexity is then O(n).

 **Prepared by [Markadiusz](https://codeforces.com/profile/Markadiusz "International Master Markadiusz")** 
### [1572A - Book](https://codeforces.com/contest/1572/problem/A "Codeforces Round 743 (Div. 1)")

There are two main solutions in this task.

The first solution simulates the process of reading the book. Let ri be the number of chapters that need to be understood in order to understand i-th chapter. We will keep this array updated during the simulation. Now we will simulate the process by keeping a set of chapters that are ready to be understood. Suppose we have just understood chapter x. We will update array r by iterating over all chapters that require x to be understood. If some chapter becomes ready to be understood, we will insert it to the set. Then, we will lowerbound on our set to the next chapter that can be understood and when we hit the end, the answer increases by one and we come back to the beginning.

The entire process runs in O(nlogn).

The second solution is more graph based. We will construct a graph, where there is a directed edge from a to b if chapter b is needed to understand chapter a. This edge has weight 0 if a>b and 1 otherwise. The answer is the length of the longest weighted path in this graph incremented by 1. If there exists a cycle we should output −1. If the graph is a DAG, we can use toposort and a simple DP to calculate the answer.

This solution works in O(n)

 **Prepared by [Asymmetry](https://codeforces.com/profile/Asymmetry "Master Asymmetry")** 
### [1572B - Xor of 3](https://codeforces.com/contest/1572/problem/B "Codeforces Round 743 (Div. 1)")

If the xor of all numbers in the array equals 1 it is impossible to make everything equal to 0, since the parity of all numbers doesn't change after an operation. From now on we will assume that the xor of all numbers equals 0.

Lets consider the case when n is odd. We can perform operations on positions 1,3,...n−4,n−2. After this for every even i, ai−1=ai. Additionally, an=an−1=an−2=0. Second one is true since the xor of all numbers equals 0. Now we can perform operations on positions n−4,n−6,...3,1. This will make the array equal to 0.

In the case of even n we will find a prefix of odd length and even xor of numbers and call the above solution on it and its respective suffix. If there is no such prefix, the solution doesn't exist. Here is a proof of it. Assume that every prefix of odd length has an odd xor. This means that a1=an=1 and for every even i<n, ai=ai+1. Consider an operation on an even position i (odd is analogous). We know that ai=ai+1 so after this operation ai and ai+1 will be set to ai+2. This means that after every operation for every even i<n, ai=ai+1 still holds. Thus we will never be able to make a1 equal to 0 since performing an operation on it won't change it.

Summing up, we perform no more than n operations and our solution runs in O(n)

 **Prepared by [Markadiusz](https://codeforces.com/profile/Markadiusz "International Master Markadiusz"), [Monogon](https://codeforces.com/profile/Monogon "International Grandmaster Monogon") and [Asymmetry](https://codeforces.com/profile/Asymmetry "Master Asymmetry")** 
### [1572C - Paint](https://codeforces.com/contest/1572/problem/C "Codeforces Round 743 (Div. 1)")

Firstly, we can notice that when we modify a segment of the form [a,b,a] and change it to [a,a,a] by performing the operation on the second element, as opposed to performing the operation first on the third element and then on the second element (like so [a,b,a]→[a,b,b]→[a,a,a]) we avoid using one unnecessary operation. In our solution we will try to maximize the number of operations that we didn't have to perform.

Let dp[i][j] be the maximum number of operations that we can avoid on the interval from i to j, while making all of its elements have the same color. Then the answer to the problem will be n−1−dp[1][n]. For i≥j we have dp[i][j]=0 and for i<j dp[i][j] will be the maximum of dp[i+1][j] and max(1+dp[i+1][k−1]+dp[k][j]) over i<k≤j such that a[i]=a[k]. It's because we can either not save any operations on the i-th element and just take the answer from the interval [i+1,j] or we can save one operation while coloring the segment from i to k and take the answer from segments [i+1,k−1] and [k,j]. Because each color occurs in a at most 20 times, we can calculate this dp in O(20n2) which is also our final time complexity.

 **Prepared by [Markadiusz](https://codeforces.com/profile/Markadiusz "International Master Markadiusz")** 
### [1572D - Bridge Club](https://codeforces.com/contest/1572/problem/D "Codeforces Round 743 (Div. 1)")

Let's make a graph in which the vertices are the players and there is an edge of weight ai+aj between the i-th and the j-th player if they can play together. We can notice that the problem can then be solved by finding a matching of size at most k with the biggest sum of weights in this graph.

To solve this problem efficiently we can make the following observations:

1. The graph is bipartite.

This stands from the fact that if two players disagree at exactly 1 topic then the numbers of positive views that they hold have different parities.

2. We can limit ourselves to considering only the (2n−1)(k−1)+1 edges with the biggest weights.

We can prove this with a proof by contradiction. Firstly, we can notice that if we use a particular edge in the matching then we prohibit ourselves from using at most 2(n−1) other edges with each of the matched vertices being incident to exactly n−1 of those edges, because each vertex has degree n in this graph. Now we can see that if we were to use an edge that's not one of those (2n−1)(k−1)+1 best ones, then we can just replace it with one of those best ones, because we know that at least one of them will not be prohibited.

Combining those two observations we are left with a bipartite graph with O(nk) edges and O(nk) vertices in which we can find a matching with maximum cost and size at most k with for example one of the standard min cost max flow algorithms (we can look for a matching of size k because all edges have non-negative weights).

The only problem that's left for us to solve is efficiently selecting those best edges. Because there are O(n2n) edges in total we cannot use a standard sorting algorithm as that would run in O(n22n). Instead we can for example use the quick select algorithm which solves this problem in O(n2n).

Our final time complexity is then O(n2n+nk2log(kn)).

 **Prepared by [Markadiusz](https://codeforces.com/profile/Markadiusz "International Master Markadiusz")** 
### [1572E - Polygon](https://codeforces.com/contest/1572/problem/E "Codeforces Round 743 (Div. 1)")

We are going to binary search the answer.

Lets say that we want to check whether we can obtain k+1 regions with area of at least w. From now on a correct cut means a cut that will cut off a region with area of a least w.

Lets consider some interval of vertices (i,j). We will cut it off virtually using a cut from i to j. We would like to know how many correct regions we can obtain by performing cuts only in this interval. The area next to the virtual cut is considered a leftover. Given two sets of correct cuts in this interval it's always optimal to choose the one with more cuts and if they have the same amount of cuts, the one with the bigger leftover.

This observation leads us to a dynamic programming solution. Let dpi,j be a pair (ri,j,li,j) where ri,j means the biggest amount of regions and li,j the biggest leftover we can obtain by performing cuts in the interval (i,j).

To calculate this dp we will iterate over all vertices k such that i<k<j and consider vertex k as one of the vertices that are included in the leftover region. This is a simple transition from states dpi,k and dpk,j. After we calculate our dp state we can safely cut this interval off if li,j≥w.

Iff r1,n≥k+1 the answer equals at least w.

This solution runs in O(n3log(1016)).

 **Prepared by [Asymmetry](https://codeforces.com/profile/Asymmetry "Master Asymmetry") and [Markadiusz](https://codeforces.com/profile/Markadiusz "International Master Markadiusz")** 
### [1572F - Stations](https://codeforces.com/contest/1572/problem/F "Codeforces Round 743 (Div. 1)")

We will maintain the array b on a range add/sum segment tree. Queries are done then in O(logn) per query.

Now lets focus on the station rebuilds. Lets maintain an array w, which means how far a station can broadcast information including the fact that some stations might block the signal. When a station is rebuild in city ci we need to perform a min operation on interval (1,ci−1) with value ci−1. Next we have to set wci to gi. These are all changes to array w that happen during a single rebuild.

Now we want to keep array b up to date. We need to know what has been changed and a list of changes to array w is all we need. When setting wci to gi we can add 1 on interval (ci,gi). This is fast enough to do with a single operation on array b, since we do this once for every rebuild. Lets say that wj was decreased as a result of the min operation. To update array b accordingly we should subtract 1 on interval (ci,wj).

Sadly, performing a subtraction on b for every value in array w that has changed during the min operation one by one is too slow and we can't afford it. Thankfully, we can speed this up. First, we will think how to keep array w updated. We can use segment tree beats to perform the min operation. Recall that during the min operation we get to know what elements and how many times have changed. This is traditionally used to update the sum over interval information. Now we are going to use it in a different way. Lets say that value r was decreased p times in a node where we perform a tag. To keep array b updated we only need subrtact p from interval (ci,r).

Lets think about the complexity now. Segment tree beats with min and set point operations run in amortized O((n+q)logn) meaning that we will perform at most this many changes on array b. This leads us to our total time complexity of O((n+q)log2n).

 **Prepared by [Asymmetry](https://codeforces.com/profile/Asymmetry "Master Asymmetry")**