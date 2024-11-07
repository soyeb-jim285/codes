# Tutorial_(en)


### [1592A - Gamer Hemose](../problems/A._Gamer_Hemose.md "Codeforces Round 746 (Div. 2)")

It's always optimal to use two weapons with the highest damage value and switch between them.

Let x be the highest damage value of a weapon, and y be the second-highest damage value of a weapon. we will decrease monster health by x in the first move, and by y in the second move and so on.

ans={2⋅Hx+y,if H mod (x+y) =02⋅⌊Hx+y⌋+1,if H mod (x+y) ≤x2⋅⌊Hx+y⌋+2,otherwise

 
### [1592B - Hemose Shopping](../problems/B._Hemose_Shopping.md "Codeforces Round 746 (Div. 2)")

The answer is always "YES" If n≥2∗x because you can reorder the array as you want.

Otherwise, You can swap the first n−x elements and the last n−x elements, so you can reorder them as you want but the rest have to stay in their positions in the sorted array.

So if elements in the subarray [n−x+1,x] in the original array are in their same position after sorting the array then the answer is YES, otherwise NO.

 
### [1592C - Bakry and Partitioning](../problems/C._Bakry_and_Partitioning.md "Codeforces Round 746 (Div. 2)")

The most important observation is: If you can partition the tree into m components such that the xor of every component is x, Then you can partition the tree into m−2 components by merging any 3 adjacent components into 1 component, and the xor of the new component will equal x, since x xor x xor x = x.

Notice that the answer is always YES if the xor of the array is 0. Because you can delete any edge in the tree, and the 2 components will have the same xor.

Otherwise, We need to partition the tree into 3 components that have the same xor. Let x be the xor of all node values in the tree, then The xor of every component will equal x.

We need to search for 2 edges to delete from the tree and one of them such that the xor every component equals x and if we found them and K≠2 then the answer is "YES" otherwise "NO".

To search on the 2 edges, We will first root the tree on node 1, then we will search on the deepest subtree such that xor value of subtree equals x, then erase the edge and search again for the 2nd edge. 

 
### [1592D - Hemose in ICPC ?](../problems/D._Hemose_in_ICPC_.md "Codeforces Round 746 (Div. 2)")

The maximum gcd of a path equals the maximum weight of an edge in the tree. Let x be the value of the maximum weight of an edge in the tree, We need to find u, v such that there's an edge between u and v with weight equals x.

Let's find x by putting all the n nodes in the same query, Now we need to find u, v.

If we have an array of edges such that for any consecutive subarray: The component of nodes inside the subarray is connected using the edges inside the subarray. Then we can binary search on this array to find the edge with the maximum weight.

If we put the edges in the array using the order of Euler tour traversal, the array will satisfy the condition above, and we can solve the problem.

Total number of queries is 1+log(2∗(n−1)).

 
### [1592E - Bored Bakry](../problems/E._Bored_Bakry.md "Codeforces Round 746 (Div. 2)")

Let And(l,r) denotes the bitwise and of the elements in subarray [L,R] in the array and Xor(l,r) denotes the bitwise xor of the elements in subarray [L,R] in the array.

If subarray [L,R] length is odd then it can't be a good subarray because And(l,r) is a submask of Xor(l,r) since every bit in And(l,r) occurs odd times so it will be set in Xor(l,r).

If subarray [L,r] length is even then every bit in And(l,r) will be unset in Xor(l,r) so we only care about the most significant bit in And(l,r).

Let's solve for every bit k, Let's call bit m important bit if m>k. For every r in the array, We need to find the minimum l such that [l,r] is even, k is set in And(l,r) and all the important bits are unset in Xor(l,r).

Since we only care about the important bits, We can make a prefix array where prefi is the prefix xor till the index i considering only the important bits.

So for every r, we need to find the minimum l that satisfy these conditions:

1 - r−l+1 is even.

2 - k is set in all elements in subarray [l,r].

3 - prefr xor prefl−1 =0. 

which can be solved easily in O(NlogN).

 
### [1592F1 - Alice and Recoloring 1](../problems/F1._Alice_and_Recoloring_1.md "Codeforces Round 746 (Div. 2)")

We will transform favorite coloring to the all-white coloring instead.

Let's denote W by 0 and B by 1.

First observation is that it doesn't make sense to do operations of type 2 and 3 at all. Indeed, each of them can be replaced with 2 operations of type 1:

Instead of flipping subrectangle [x,n]×[1,y], we can flip subrectangles [1,n]×[1,y] and [1,x−1]×[1,y], and similarly for [1,x]×[y,n]. So, from now on we only consider first and last operations.

Let's create a grid a of n rows and m columns, where a[i][j] denotes the parity of the sum of numbers in those of cells (i,j),(i+1,j),(i,j+1),(i+1,j+1) of favorite coloring, which are present on the grid. Clearly, all numbers in a are 0 if and only if current coloring is all 0, so we will want to just make the grid a all 0.

Let's look at how first and last operations affect the grid a. If we flip the subrectangle [1,x]×[1,y] with the operation of the first type, in grid a the only value that changes is a[x][y]. If we flip the subrectangle [x,n]×[y,m], clearly x,y>1 (otherwise we could have instead used 2 operations of the first type). Then, it's easy to see that the only cells that will change are a[x−1][y−1],a[n][y−1],a[x−1][m],a[n][m].

So, now we have the following problem: we have a binary grid n×m. In one operation, we can change some 1 to 0, with cost of 1 coin, or to select some 1≤x≤n−1,1≤y≤m−1, and flip the numbers in cells a[x][y],a[n][y],a[x][m],a[n][m] with cost of 3 coins. What's the smallest cost to make all numbers 0?

Now, it's easy to see that it doesn't make sense to apply second operation more than once, as instead of doing it twice, we can apply the operation of the first type at most 6 times (as cell a[n][m] will be flipped twice). Moreover, it only makes sense to apply the second operation if there exist such 1≤x≤n−1,1≤y≤m−1 for which all cells a[x][y],a[n][y],a[x][m],a[n][m] are 1. So, the algorithm would be to calculate the grid a, to calculate the total number of ones in it ans, and substract 1 from ans if there exists such 1≤x≤n−1,1≤y≤m−1 for which all cells a[x][y],a[n][y],a[x][m],a[n][m] are 1. 

Complexity O(nm).

 
### [1592F2 - Alice and Recoloring 2](../problems/F2._Alice_and_Recoloring_2.md "Codeforces Round 746 (Div. 2)")

Everything from the editorial of the first part of the problem stays the same, except one thing: now the second operation on the modified grid costs only 2 coins. Sadly, now it's not true that it's not optimal to use the second operation more than once. 

Let's denote the second operation on a by op(x,y) (meaning that we invert numbers at a[x][y],a[n][y],a[x][m],a[n][m]). New claim is that it's not optimal to make operations which have the same x or the same y. 

Indeed, suppose that we made op(x,y1) and op(x,y2). Then cells a[x][m] and a[n][m] haven't changed, so we only flipped 4 cells with cost of 2×2=4 coins. We could have done this with operations of the first type.

Another observation: it doesn't make sense to make op(x,y), unless all the cells a[x][y],a[x][m],a[n][y] are 1. Indeed, no other operation of this type will affect any of these cells. If some cell here is 0, and we still make op(x,y) in 2 coins, then we will have to spend one additional coin on reverting it back to 0 with the operation of the first type. Instead, you could have just flipped 3 other cells from a[x][y],a[x][m],a[n][y],a[n][m] with the operations of the first type in the same 3 coins.

How many such operations can we make then? Let's build a bipartite graph, with parts of sizes n−1 and m−1, and connect node x from the left part with node y from the right part iff a[x][y]=a[x][m]=a[n][y]=1. Find the maximum matching in this graph with your favorite algorithm (for example, in O(mn√m+n) with Hopcroft–Karp), let its size be K. Then, for each 0≤k≤K, we can find the number of ones that will be left in the grid if we make exactly k operations of the second type. Then the answer to the problem is just the minimum of (ones_left+2k) over all k.

