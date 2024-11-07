# Tutorial_(en)

[1541A - Pretty Permutations](https://codeforces.com/contest/1541/problem/A "Codeforces Round 728 (Div. 2)")

Author: [PurpleCrayon](https://codeforces.com/profile/PurpleCrayon "Master PurpleCrayon")

 **Hint**The parity (whether n is odd or even) matters.

 **Hint**Swapping two adjacent cats keeps both of them close to their original location and changes both of their locations.

 **Hint**If n is even, the optimal distance is n, and if n is odd the optimal distance is n+1.

 **Solution**
### [1541A - Pretty Permutations](https://codeforces.com/contest/1541/problem/A "Codeforces Round 728 (Div. 2)")

There are two cases: 

* if n is even, print: [2,1,4,3,6,5…n,n−1] Formally, you swap every other pair of adjacent elements. This is optimal because the total distance is n, which has to be minimal since the distance of one cat must be ≥1.
* if n is odd, first print [3,1,2] then solve the even case for the remaining elements. This is optimal because the distance is n+1, which has to be minimal since a distance of n is not achievable.
[1541B - Pleasant Pairs](https://codeforces.com/contest/1541/problem/B "Codeforces Round 728 (Div. 2)")

Author: [PurpleCrayon](https://codeforces.com/profile/PurpleCrayon "Master PurpleCrayon")

 **Hint**i+j≤2⋅n

 **Hint**The number of pairs (a,b) such that a⋅b≤x is O(xlogx).

 **Solution**
### [1541B - Pleasant Pairs](https://codeforces.com/contest/1541/problem/B "Codeforces Round 728 (Div. 2)")

Loop over all values of ai and aj. Because i+j≤2⋅n, we only care about pairs (ai,aj) if ai⋅aj≤2⋅n. The number of such pairs is O(nlogn), so you can brute force all pairs.

The reason the total number of pairs is O(nlogn) is because if the first element of the pair is x, there are only 2⋅nx possible values of y. 2⋅n1+2⋅n2+2⋅n3+…2⋅nn=2⋅n(11+12+13…1n)=O(nlogn) by the harmonic series. Thus the solution runs in O(nlogn) time total.

[1540A - Great Graphs](../problems/A._Great_Graphs.md "Codeforces Round 728 (Div. 1)")

Author: [PurpleCrayon](https://codeforces.com/profile/PurpleCrayon "Master PurpleCrayon")

 **Hint**What's the minimum value that an edge from a to b can be?

 **Hint**Use edges with negative value whenever you can.

 **Hint**The sum of the values of edges with positive weight must be ≥ the maximum value in the array.

 **Solution**
### [1540A - Great Graphs](../problems/A._Great_Graphs.md "Codeforces Round 728 (Div. 1)")

Note that if there are two nodes a and b and you want to add an edge between them, the value of the edge must be ≥db−da. Otherwise, the cows could take a path to b that goes through da that's strictly less than db. With this in mind, let's add all edges (a,b) with weight db−da if and only if db≤da. All of these numbers are not positive, which means they can't make our answer worse. They also don't change the shortest paths, from our first observation. Now, let's call the node with the max di node x. You can add a single edge from node 1 to node x with cost dx, and now the graph is good. This is because node x is already connected to all other nodes, which means there is always a shortest path to some node a with the right length by going from 1→x→a. However, naively looping through all pairs is too slow. Instead, you can sort d and calculate the contribution of each node to the answer. The complexity is O(nlogn).

[1540B - Tree Array](../problems/B._Tree_Array.md "Codeforces Round 728 (Div. 1)")

Author: [ijxjdjd](https://codeforces.com/profile/ijxjdjd "Master ijxjdjd")

 **Hint**Fix the initial node chosen and root the tree there, what is the contribution of each pair of nodes?

 **Hint**Nothing matters besides the path from node a to node b, and the initially chosen node r.

 **Hint**You are given two stacks of size a1 and a2. In a single step, you randomly choose a stack to remove a single item from. What is the probability that a1 becomes 0 before a2? Can you extend this argument for an arbitrary probability p to remove from one of the two stacks, and a probability of 1−2p to do nothing?

 **Solution**
### [1540B - Tree Array](../problems/B._Tree_Array.md "Codeforces Round 728 (Div. 1)")

Parsing through the problem statement, the process can be seen as choosing a starting node and "expanding" the subtree of marked nodes to nodes adjacent to the marked component.

Fixing a given root r, the expected value of the entire process is obviously the sum of the expected values for a fixed root divided by n. 

Find the contribution of the inversion of two nodes (a,b) where a<b. The expected contribution for any pair (a,b) is equal to the probability that b appears before a with a given root.

Set l=lca(a,b). Note that, until reaching l, every possible process still has the same probability of reaching b before a as it did when the first node was chosen. Therefore, we can assume that the process has reached l and calculate the probability from there. 

Once l is reached, we now note that the probability that the process "gets closer" to b is always equal to the probability of getting closer to a.

The problem can be rephrased as having two stacks of size dist(l,a) and dist(l,b) with an arbitrary p to remove a node from one of the two stack (and 1−2p to nothing) and finding the probability that dist(l,b) reaches zero before dist(l,a). 

However, it turns out that the actual probability p does not matter. We propose a function F[x][y] that defines the probability that a stack of size y becomes 0 before a stack of size x. In fact a function exists and it is defined as F[x][y]=F[x−1][y]+F[x][y−1]2. Intuitively, this is because the probability of decreasing x or decreasing y is always the same, so the probability of transitioning the state we end up transitioning to is always the same, regardless of p.

So, the solution is clear. Iterate over and root at all nodes. Then at the given root, iterate over all pairs of node a<b and add F[dist(l,a)][dist(l,b)] to the answer. Finally, divide by n. In total, the solution works in O(N3logN) or O(N3).

[1540C2 - Converging Array (Hard Version)](../problems/C2._Converging_Array_(Hard_Version).md "Codeforces Round 728 (Div. 1)")

Author: [ijxjdjd](https://codeforces.com/profile/ijxjdjd "Master ijxjdjd")

 **Hint**What are the invariants? The monovariants?

 **Hint**What is the prefix sum array of the converged array? What is the difference array of the converged array?

 **Hint**What if you conducted the process on a prefix of size 1, then of size 2, and on and on?

 **Hint**How many values x are actually interesting?

 **Solution**
### [1540C2 - Converging Array (Hard Version)](../problems/C2._Converging_Array_(Hard_Version).md "Codeforces Round 728 (Div. 1)")

First, reduce the operations into something more manageable. It turns out operation i sets ai+1−ai=max(bi,ai+1−ai) while keeping ai+1+ai constant. Visually, this is simultaneously moving ai up and ai+1 down until ai+1−a[i]≥bi.

Define f to be the final converged array. 

Let's some observations

1. If ai+1−ai=bi is ever satisfied throughout the process (if an operation ever moves anything), fi+1−fi=bi. Equivalently, if fi+1−fi>bi then no operation i could have ever been conducted
2. If no operation i has been conducted, then [1,i] is independent of [i+1,n].
3. If i is the first operation that has never been conducted, then ∑ij=1aj=∑ij=1fj because no sum could have been exchanged between ai and ai+1.

Let's assume that we know that i is the first observation that hasn't been conducted. We can then restore f1 because we know that f1+f1+b1+f1+b1+b2…=a1+a2+…+ai. To keep the tutorial clean, we refer to the prefix of prefix summation of bi as bpi and the prefix summation of ai as api. Namely, we can solve for f1=api−bpii given that i is the first observation never conducted.

It turns out that f1=min(api−bpii) over all i. This can be shown to be a lower bound on f1 because the answer is obviously in this set as there must be some i that is the first operation never conducted. This can also be shown to be an upperbound on the answer by playing the game on each prefix i. At each prefix i, the term api−bpii is an upperbound because, if it's not equal to that term, there must be some fi+1−fi>bi so f1<api−bpii because f1+f2+…+fi remains the same.

Returning to the actual problem, we need to count arrays min(api−bpii)≥x. In other words, api≥i⋅x+bpi must hold for all i. Let's do dynamic programming on api. Call dp[i][api] the number of prefixes of length i with current prefix sum of api. We can transition to i+1 from i using prefix sums on each valid api.

Define M=max(ai). The current complexity is O(QMN2) The final step is noticing that there are only O(M) valid integer positions that end up being important for f1. Intuitively, this is because in nearly all cases every operation i ends up being used. To rigorously prove, let's find an upperbound on relevant x. If M⋅n<x⋅n+bpi then there are 0 valid arrays. Because x⋅n+bpi is concave and negative on the decreasing portion (i.e. the function goes down immediately into negative if it ever becomes negative, otherwise strictly increases), we can draw the inequality 0≥x⋅n+bpi, otherwise every array ends up being good. Reducing the inequalities, we can realize that there is exactly M different possible solutions. So, we can precalculate in O(M2N2) and answer in O(1).

[1540D - Inverse Inversions](../problems/D._Inverse_Inversions.md "Codeforces Round 728 (Div. 1)")

Author: [PurpleCrayon](https://codeforces.com/profile/PurpleCrayon "Master PurpleCrayon")

 **Hint**The answer is always unique.

 **Hint**Try to figure out what the location of the i-th element would be if you only looked at the first i elements, then the first i+1, etc. to find an O(nq) solution.

 **Hint**Use sqrt decomposition to optimize it.

 **Solution**
### [1540D - Inverse Inversions](../problems/D._Inverse_Inversions.md "Codeforces Round 728 (Div. 1)")

We'll assume the arrays and the final permutation are 0-indexed from this point forward (you can shift values accordingly at the end). 

Let's start with calculating the final array, without any updates. Let ci be the number of indices j such that pj<pi and i<j. It is easy to see that ci=i−bi. Now imagine sweeping from left to right, maintaining the array a. Let's say you're currently at index i, and you have a list of all indices ≤i, where the location of some index j is the value of aj. You know that i must be the ci-th out of those (after inserting it into the list) as the ci smallest values must be before it. This means that you can insert index i at the ci−th position in the list, and you need to find the final location of index i in each query.

 Now, let's support O(1) updates and O(n) queries. The first thing to note is that you don't need the entire array a in each query, you just need to query some specific element. Assume you're querying the i-th element of the array. Let's repeat the algorithm mentioned above except instead of storing the lists, you only store the location of the i-th element for each query. Now, you keep some variable loc which stores the location of the i-th element in the list. It is initialized to ci, as it is first inserted to the ci-th position. Now you sweep through all indices j where j>i, and check if loc is changed by the insert. This is only true if loc≥a[j]. This allows for O(1) updates but O(n) queries, which is still too slow. 

To speed this up, let's use sqrt-decomp. Divide the array into multiple blocks. For each block, let's store an array next where nextloc represents the final value of the variable loc if it passes through the block. If we have this array, you can loop over all of the blocks and "jump" over them using the next array, querying in O(n/B) time, where B is the size of the block. But how do you calculate and update the next array? Initially, you can calculate the next array in O(n⋅B), by going to each index and naively tracking its position. Updating it is harder. One observation to make is that for each index inside a block, there is some value such that if loc≥x it will be changed by the index, otherwise it will not. You can find all of those values for a single block using a binary indexed tree: sweep from left to right, query for the the smallest update loc using a lower bound on the BIT, and increment a suffix. Then, you can increment all of those suffixes in the next array using another BIT, which would lead to O(n√n+q√nlogn), as queries are O((n/B)logn) and updates are O(Blogn), which will probably be too slow.

To make this faster, note that the suffix that each element is responsible changes by at most one for all non-updated elements. This means that you can update the next array in O(1) for these elements. However, the updated element's suffix might change by O(n). To account for this, you can use another square root decomposition on the next array, which allows for O(√n) range updates, O(1) point updates, and O(1) point queries. This means that updates will remain O(Blogn), but queries will become O(1), so the final complexity is O(q√nlogn) with the right blocksize, which is definitely fast enough (the model solution runs in 2 seconds).

If you know of any faster solutions (O(n√n) or even O(n⋅logk) let us know down in the comments).

[1540E - Tasty Dishes](../problems/E._Tasty_Dishes.md "Codeforces Round 728 (Div. 1)")

Author: [ijxjdjd](https://codeforces.com/profile/ijxjdjd "Master ijxjdjd")

 **Hint**How much does each chef's initial dish contribute at time k?

 **Hint**What if you really, really wanted to use matrix exponentiation?

 **Hint**How can you multiply some vectors by a matrix in O(N) time? (go back to linear algebra class)

 **Hint**Decompose into linear combinations of eigenvectors.

 **Solution**Tutorial is loading...