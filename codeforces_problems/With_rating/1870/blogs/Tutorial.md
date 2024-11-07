# Tutorial

We apologize for the technical difficulties in Task B. We hope you enjoyed the rest of the contest. We will add hints soon.

[1870A - MEXanized Array](../problems/A._MEXanized_Array.md)

 **Tutorial**Note that if min(n,x+1)<k, then the answer is −1.

Otherwise, there are two cases:

 * If k=x, then the suitable array looks like [0,1,2,…,k−1,…,k−1].
* If k≠x, then the suitable array looks like [0,1,2,…,k−1,x,…,x].

In both cases, we can construct the array and calculate its sum in linear time. The overall complexity is O(n⋅t).

[1870B - Friendly Arrays](../problems/B._Friendly_Arrays.md)

 **Tutorial**Note that after performing the operation on bj, which has some bit set to 1, this bit will become 1 for all numbers in a (and will remain so, as a bit cannot change from 1 to 0 in the result of an OR operation). If n is even, then in the final XOR, this bit will become 0, as it will be equal to the XOR of an even number of ones. If n is odd, then this bit will be 1 in the final XOR.

Therefore, if n is even, by performing the operation on bj, we set all the bits that are 1 in bj to 0 in the final XOR. If n is odd, we do the opposite and set these bits to 1. So, if n is even, the XOR does not increase when applying the operation, which means that to obtain the minimum possible XOR, we need to apply the operation to all the numbers in b, and the maximum XOR will be the original XOR. For odd n, it is the opposite: the minimum is the original XOR, and the maximum is obtained after applying the operation to all elements in b.

To apply the operation to all elements in b, it is sufficient to calculate their bitwise OR and apply the operation to the array a with it.

[1870C - Colorful Table](../problems/C._Colorful_Table.md)

 **Tutorial**Let's fix the color x for which we will calculate the answer. If there is no ai=x, then there will be no cells of color x, and the answer is 0. Otherwise, there is at least one cell of color x.

To find the minimum rectangle containing all cells of this color, we need to find the topmost, bottommost, leftmost, and rightmost cells of this color in the array b. Let's find the prefix in a of the maximum length, where all numbers are strictly less than x. Let the length of this prefix be L. Then in the first L rows and columns of the array b, there will be no cells of color x, because for all these cells, the formula bi,j=min(ai,aj) will have a number from the prefix, and all numbers on it are less than x. In the L+1-th row and L+1-th column, there will be cells of color x, because aL+1≥x. Thus, we have found the topmost and leftmost cells of color x. To find the bottom and right cells, we need to find the longest suffix where all numbers are less than x.

Now we need to learn how to quickly find prefixes and suffixes for all colors. Notice that the prefix for color x is not shorter than the prefix for color x+1, so all prefixes can be calculated in just one pass through the array, similarly for suffixes.

[1870D - Prefix Purchase](../problems/D._Prefix_Purchase.md)

 **Tutorial**Note that if there is a prefix for which there is a longer prefix that costs less, then it is useless to buy the shorter prefix. All its purchases can be replaced with purchases of the longer prefix, and the answer will only improve. Therefore, we can replace each ci with the minimum cj among i≤j≤n (the minimum price of a prefix of length at least i). After this, we will have ci≤ci+1.

Now let's solve the problem greedily. We want to maximize the first element of the resulting array. It will be equal to k/c1, since we cannot buy more prefixes of length 1 (c1 is the smallest price). After buying k/c1 prefixes of length 1, we will have some coins left. Now we can replace some purchases of c1 with purchases of longer prefixes to improve the answer.

How much will it cost to replace c1 with ci? It will cost ci−c1 coins. Moreover, note that to replace c1 with ci, we can sequentially replace c1 with c2, c2 with c3, …, ci−1 with ci (since c1≤c2≤…≤ci). This means that we can make only replacements of purchases of ci−1 with purchases of ci.

Let's say we have maximized the first i−1 elements of the answer, and we have x coins left. Now we want to replace some purchases of ci−1 with ci. How many replacements can we make? We can afford to make no more than xci−ci−1 replacements (if ci−1=ci, then we can replace all ci−1), and we cannot replace more purchases than we have made, so no more than ai−1 replacements (this is the number of purchases of ci−1). Therefore, ai=min(ai−1,xci−ci−1), as we want to maximize ai. Finally, subtract the cost of replacements from the number of coins and move on to ci+1.

[1870E - Another MEX Problem](../problems/E._Another_MEX_Problem.md)

 **Tutorial**Let's solve the problem using dynamic programming, let's store dp[i][j] such that dp[i][j]=1 if it is possible to obtain an XOR of MEX values from the prefix up to i (excluding i) equal to j, and 0 otherwise. Notice that the answer cannot be greater than n. Therefore, the size of this two-dimensional array is O(n2).

Let's learn how to solve this in O(n3):

We iterate over l from 1 to n, and inside that, we iterate over r from l to n, maintaining the value x=MEX([al,al+1,…,ar]). Then, for all j from 0 to n, we update dp[r+1][j⊕x]=1 if dp[l][j]=1. This way, we update based on the case when the resulting set includes the set [al,al+1,…,ar].

We also need to update if dp[l][x]=1, we assign dp[l+1][x]=1. This accounts for the case when we do not include al in the answer.

Let's define MEX(l,r)=MEX([al,al+1,…,ar]), this will make the following text clearer.

Let's consider the segment l,r. Notice that if there exist l2 and r2 (l≤l2≤r2≤r) such that l2≠l or r2≠r and MEX(l,r)=MEX(l2,r2), then we can take the segment l2,r2 instead of the segment l,r in the set of MEX values, and the answer will remain the same. If, however, there is no such segment l2,r2 for the segment l,r, then we call this segment l,r irreplaceable.

Now let's prove that there are no more than n⋅2 irreplaceable segments. For each irreplaceable segment, let's look at the larger element of the pair al,ar, let's assume al is larger (the other case is symmetric). Now, let's prove that there is at most one segment where al is the left element and al≥ar, by contradiction:

Suppose there are at least 2 such segments, let's call their right boundaries r1,r2 (r1<r2). Notice that MEX(l,r1)>al, otherwise the segment l,r1 would not be irreplaceable (we could remove al). Since al≥ar2, then MEX(l,r1)>ar2. It is obvious that ar2 appears among the elements [al,…,ar1], and therefore MEX(l,r2−1)=MEX(l,r2), which means that the segment l,r2 is not irreplaceable, contradiction.

For each ai, there is at most one irreplaceable segment where it is the smaller of the two extremes, and at most one where it is the larger. Therefore, the total number of irreplaceable segments is no more than 2⋅n.

Let's update the DP only through the irreplaceable segments, then the solution works in O(n2+n⋅C) time, where C is the number of irreplaceable segments. However, we have already proven that C≤2n, so the overall time complexity is O(n2).

[1870F - Lazy Numbers](../problems/F._Lazy_Numbers.md)

 **Tutorial**Let's store all the number entries in a trie. Consider two traversals of this trie — depth-first search (DFS) and breadth-first search (BFS). In both traversals, we go to the children of a node in ascending order of the number on the edge (in the trie). Let the index of the node representing the number x in the DFS traversal be dfs(x), and in the BFS traversal be bfs(x). Then notice that x=bfs(x), as in BFS on the trie, we simply look at all the number entries with a certain length in order (lengths are concidered in increasing order). On the other hand, dfs(x) is the index of the number entry x in the sorted array. Therefore, we want to calculate the number of x for which dfs(x)=bfs(x).

Let's fix a layer in the trie, meaning we only consider numbers with a fixed, equal length of representation. Then let's look at dfs(x)−bfs(x) for the numbers in this layer. Notice that for two numbers y and y+1 in this layer, it holds that bfs(y+1)−bfs(y)=1, and dfs(y+1)−dfs(y)≥1. This means that for a fixed layer, the function dfs(x)−bfs(x) is non-decreasing. Therefore, we can find the 0 of this function using binary search on each layer.

Now let's learn how to calculate dfs(x)−bfs(x). bfs(x)=x, which we can calculate. To find dfs(x), we can traverse up from the trie node corresponding to x, and at each step, add the sizes of the subtrees that we have traversed in DFS before the subtree with the node x.

The trie has a depth of O(log(n)), binary search takes the same time, so the overall asymptotic complexity of the solution is O(log3(n)).

I apologize for the issues some participants faced with the time limit, if they implemented the author's idea suboptimally.

[1870G - MEXanization](../problems/G._MEXanization.md)

 **Tutorial**Let's start by introducing a more convenient way to store numbers — an array cnt, where cnt[x] represents the number of occurrences of x in the prefix for which we are finding the answer. All x such that x>n will be added to cnt[0] because applying the operation to x in such cases is optimal.

Let's introduce a few array operations that will be sufficient to solve the problem.

 * Create the number x. Apply the operation to the set of numbers 0,1,2,…,x−1. In terms of the array cnt, this is equivalent to subtracting 1 from the range 0 to x−1 and adding 1 to cnt[x].

 * Turn the number x into 0. To do this, apply the operation to x. In terms of the array cnt, this is equivalent to subtracting 1 from cnt[x] and adding 1 to cnt[0].

 * Create the number x and clear the multiset. This is the same as creating the number x, but we apply the operation to all other numbers, leaving only the single number x (or a larger number) in the set.

It can be proven that by using only operations of this kind, we can always obtain the optimal answer.

Now we can forget about the original condition and solve the problem for the array.

Let's learn how to check if it is possible to create the number k and clear the multiset:

First, let's try to create the number k. If it is possible, the answer is yes. Otherwise, we look at the rightmost number that is missing (or in other words, the rightmost 0). We try to create it, and now we need to find the rightmost element ≤1 to the left of it, and so on. To implement this, we need to maintain a number p such that we subtract p from all elements in the prefix (initially p=1), iterate through the array from right to left, and if cnt[i]<p, assign p+=(p−cnt[i]). When we reach zero, p may be greater than cnt[0], in which case we need to use the operation to turn any number into 0. To do this, simply check that the remaining number of elements in the array is greater than or equal to p.

This currently works in O(k) time, which is not very efficient.

Optimization techniques:

First, let's maintain the sum of elements sm and as soon as it becomes negative, terminate the process. To achieve this, when subtracting p−cnt[i] from p, let's subtract (p−cnt[i])⋅(i−1) from sm. Now let's use a bottom-up segment tree to find the nearest number smaller than p to the left in O(log(i)) time.

Now let's notice that when we update through cnt[i], we subtract at least i−1 from sm, so there can't be more than O(√n) different values of i through which we will update.

Now we can answer for a specific k in O(√n⋅log(n)) time, but in reality, the complexity is O(√n) (due to the peculiarities of the bottom-up segment tree), and the authors have a proof for this, but they are afraid that you will find an error in it, so they decided not to provide it(we will add proof later).

Now let's see how to solve the full problem:

Initially, the answer is 0, and we notice that it does not decrease. So after each addition, we will check if it is possible to increase the answer and increase it as long as possible. The answer cannot exceed n, so we will perform no more than 2⋅n checks.

Overall, the solution works in O(n⋅√n) time. That's how it is. 

 **Proof of asymptotic complexity for the query**Let's consider that in our query, the segment tree processed k nodes [x1,x2,…,xk] from the bottom.

Then, the number of operations is the sum of dist(xi,xi+1) for i from 1 to k−1, and dist(0,x1), where dist represents the length of the path between nodes in the segment tree. Now, let's notice that for the query dist(a,b), we enter the segment tree node responsible for a block of length 2t only if a and b are in different blocks of length 2t−1, which is logical. Also, let's notice that this doesn't happen very often, specifically, the numbers [x1,x2,…,xk] can be part of a maximum of √n2t blocks of length 2t (asymptotically). Therefore, the sum of all queries is asymptotically equal to the sum of √n2t for t from 0 to 20, which is a geometric progression with a ratio of 1√2. Hence, the sum is asymptotically equal to √n. Proof completed.

[1870H - Standard Graph Problem](../problems/H._Standard_Graph_Problem.md)

 **Tutorial**Let's unfold all the edges, now we need to ensure that all regular vertices are reachable from the selected vertices.

First, you should familiarize yourself with the algorithm for finding the ordered minimum spanning tree, also known as the [Edmonds' algorithm](https://codeforces.com/https://en.wikipedia.org/wiki/Edmonds%27_algorithm) (I will refer to his work here and without knowledge of it, the solution cannot be understood). Next, it is worth noting that the compressions in the process of this algorithm (almost) do not depend on the root, and all compressions can be performed as if there is no root (previously creating dummy edges from i to i+1 for i from 1 to n−1 and from vertex n to vertex 1 with a cost of n∗max(ai)+1). Then, after all the compressions, only one vertex will remain. Note that the difference from Edmonds' algorithm is that if at any step of the algorithm the minimum edge from a vertex leads to the root, compression is not necessary.

So, let's maintain a tree in which each vertex corresponds to its corresponding compressed vertex or to the original vertex, and the children of vertex v are all the vertices that we compressed to obtain vertex v. It is implied that with each compression, we create a new vertex.

Let's call the cost of vertex v the minimum cost of an edge leaving vertex v in the process of Edmonds' algorithm (taking into account changes in edge costs during compression in Edmonds' algorithm).

Then we need to maintain the sum of the costs of the vertices in the tree, in the subtrees of which there are no selected vertices (where the selected vertices can only be leaves). This can be easily done using a segment tree.

Please rate the problems, it will help us make the problems better next time!

 **Problem Feedback**You can choose one best problem, or not choose if you think there is no such task.

 **A*** The best problem 


[*11*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*137*](https://codeforces.com/data/like?action=like "I like this")
* Mid problem 

 
[*73*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*14*](https://codeforces.com/data/like?action=like "I like this")
 **B*** The best problem 

 
[*8*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*184*](https://codeforces.com/data/like?action=like "I like this")
* Mid problem 

 
[*30*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*25*](https://codeforces.com/data/like?action=like "I like this")
 **C*** The best problem 

 
[*24*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*142*](https://codeforces.com/data/like?action=like "I like this")
* Mid problem 

 
[*47*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*38*](https://codeforces.com/data/like?action=like "I like this")
 **D*** The best problem 

 
[*51*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*112*](https://codeforces.com/data/like?action=like "I like this")
* Mid problem 

 
[*35*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*51*](https://codeforces.com/data/like?action=like "I like this")
 **E*** The best problem 

 
[*93*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*58*](https://codeforces.com/data/like?action=like "I like this")
* Mid problem 

 
[*12*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*44*](https://codeforces.com/data/like?action=like "I like this")
 **F*** The best problem 

 
[*17*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*14*](https://codeforces.com/data/like?action=like "I like this")
* Mid problem 

 
[*11*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*37*](https://codeforces.com/data/like?action=like "I like this")
 **G*** The best problem 

 
[*8*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*11*](https://codeforces.com/data/like?action=like "I like this")
* Mid problem 

 
[*10*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*20*](https://codeforces.com/data/like?action=like "I like this")
 **H*** The best problem 

 
[*5*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*6*](https://codeforces.com/data/like?action=like "I like this")
* Mid problem 

 
[*5*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*27*](https://codeforces.com/data/like?action=like "I like this")
