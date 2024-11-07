# Tutorial_(en)


### [1517A - Sum of 2050](../problems/A._Sum_of_2050.md "Contest 2050 and Codeforces Round 718 (Div. 1 + Div. 2)")

First, we need to check whether n is the multiple of 2050. If n is not the multiple of 2050, the answer is always −1.

Then we can divide n by 2050, the problem now is how to represent n as the sum of powers of 10. So the answer is the sum of its digits in decimal representation.

 
### [1517B - Morning Jogging](../problems/B._Morning_Jogging.md "Contest 2050 and Codeforces Round 718 (Div. 1 + Div. 2)")

The minimum sum is the sum of m smallest of all nm numbers.

To construct the answer, we can just mark these m smallest numbers and put them in m different columns. A possible way is that for each row, you can sort all numbers from small to large, and rotate the marked number in this row to unmarked columns.

For example,

1????

?23??

???45

 
### [1517C - Fillomino 2](../problems/C._Fillomino_2.md "Contest 2050 and Codeforces Round 718 (Div. 1 + Div. 2)")

The answer is unique and always exists. There are two ways to construct the answer. 

Construction 1: Start with the main diagonal. There is one cell (x,x) with number 1 on it. That cell must form a region by itself. For each cell (y,y) on the main diagonal that is above (x,x), the cell (y+1,y) belongs to the same region as (y,y). We write the number on (y,y) minus 1 on the cell (y+1,y) and make (y+1,y) belong to the same region as (y,y). For each cell (y,y) on the main diagonal that is below (x,x), the cell (y,y−1) belongs to the same region as (y,y). We write the number on (y,y) minus 1 on the cell (y,y−1) and make (y,y−1) belong to the same region as (y,y). 

Then a permutation of 1,…,n−1 are written on the cells (2,1),(3,2),…,(n,n−1). We can continue this process on this subdiagonal. Then a oermutation of 1,2,…,n−2 will be written on the cells (3,1),(4,2),…,(n,n−2). Repeat until all cells have numbers written on them. Note that the numbers written on the cells are not the output. Put x for the region with size x after constructing the regions.

This construction proves that the solution always exists and is unique.

Construction 2: Construct the region for (1,1),(2,2),…,(n,n) in order. When starting at (i,i), we walk from (i,i) for x steps, where x is the number written on (i,i). For each step, if the cell to the left of your current cell is empty, we go to that cell and write x on it. Otherwise we go down and write x there. 

We can prove that the second construction produces exactly the same answer as the first construction. They only differ in their orders of processing. 

The regions are always paths. 

 
### [1517D - Explorer Space](../problems/D._Explorer_Space.md "Contest 2050 and Codeforces Round 718 (Div. 1 + Div. 2)")

Since the graph is bipartite, when k is odd, it is impossible to go back to the vertex after k steps.

Since the graph is undirected, we can always find a path with length k/2, walk along this path and return.

We can use dynamic programming to compute the shortest path from u with length k. dpu,k=min(u,v)∈E{dpv,k−1+wu,v}.

The time complexity is O(nmk).

 
### [1517E - Group Photo](../problems/E._Group_Photo.md "Contest 2050 and Codeforces Round 718 (Div. 1 + Div. 2)")

There can't be two i's such that ci−ci−1>2, or pi−pi−1 won't be non-increasing. And there can't be two i's such that pi−pi−1>2, or ci−ci−1 won't be non-decreasing. So for any 2≤i<m, ci−ci−1≤2, and for any 2≤i<k, pi−pi−1≤2. Then we can find out that there are only two possible patterns: PP...PCC...C or (C/P)CC...CPCPC...PCPP...P(C/P). You can calculate the first pattern in O(n) and calculate the second pattern in O(n) or O(nlogn) with two-pointers or divide-and-conquer.

 
### [1517F - Reunion](../problems/F._Reunion.md "Contest 2050 and Codeforces Round 718 (Div. 1 + Div. 2)")

Let B(u,r)={v|dis(u,v)≤r}. And a vertex is colored black iff the volunteer is not attend.

First, we enumerate r and count the number of ways that the answer is no larger than r.

That is equivalent to for all black vertices u, the union of B(u,r) will cover all vertices.

So a typical tree dp is to consider for a subtree, the depth of the deepest uncovered vertex, and how long it can extend (the most shallow black vertex whose neighbor can extend out from this subtree).

Here is an observation that if there is an uncovered vertex in the subtree, how long it can extend doesn't matter. The reason is this vertex needs to be covered by the vertex (v) from other subtrees, and v can extend further than one in this subtree.

So if there is an uncovered vertex in the subtree, we only care about the depth of the deepest uncovered one. Otherwise, we care about the depth of the most shallow black vertex. The state of this subtree is O(sizea) (actually is O(depa)). 

Time complexity for each r is O(n2), and overall complexity is O(n3).

It is possible to optimize it to O(n2logn) further.

 
### [1517G - Starry Night Camping](../problems/G._Starry_Night_Camping.md "Contest 2050 and Codeforces Round 718 (Div. 1 + Div. 2)")

We can label all the integer points in the plane as follow:

...2323...

...1010...

...2323...

...1010...

Where all the good points are labeled with 1. If we draw an edge between every adjacent points, all the forbidden patterns form all paths of length 4 with label 0-1-2-3. So we transform the problem to another problem: delete some points with smallest sum of value such that the remaining points doesn't contain a 0-1-2-3 path. It can be solved with a simple min-cut algorithm.

 
### [1517H - Fly Around the World](../problems/H._Fly_Around_the_World.md "Contest 2050 and Codeforces Round 718 (Div. 1 + Div. 2)")

Consider the DP idea: dp[i][x][y] represests whether there exists a sequence b1,…,bi satisfying all the constraints. (Constraints about bi+1,bi+2,… are ignored.) Then R(i)={(x,y)|dp[i][x][y]=true} is a region on the plane. We will prove that it is convex and then show that we can efficiently transform R(i) to R(i+1).

Initially, we can construct R(2). In R(2), x represents b2 and y represents b2−b1. The constraints are x−1≤b1=x−y≤x+1, x−2≤b2=x≤x+2, y−2≤y=b2−b1≤y+2. R(2) is the intersection of these half planes (so it is convex.) 

Calculate R(i+1) by R(i): We should take the new constraints x−i+1≤bi+1≤x+i+1, y−i+1≤bi+1−bi≤y+i+1, z−i+1≤bi+1−bi−(bi−bi−1)≤z+i+1 into account. Let's consider the last constraint first and ignore the first two for now. If (bi+1−bi)−(bi−bi−1)=z, point (x,y) in R(i) (represents bi=x,bi−1=x−y since y=bi−bi−1) will become (bi+1,bi+1−bi)=(bi+(bi−bi−1)+((bi+1−bi)−(bi−bi−1)),(bi−bi−1)+((bi+1−bi)−(bi−bi−1)))=(x+y+z,y+z) in R(i+1) (since (bi+1−bi)−(bi−bi−1)=z). Thus, to transform R(i) to R(i+1), we simply apply the x←x+y tranformation and then move the region by the vector (z,z). x←x+y is a linear transformation. We call the new region R(i)(z).

Now we know that z is between z−i+1 and z+i+1. So we should take the union of all R(i)(z) for z∈[z−i+1,z+i+1].

Finally, we add the first two constraints about x and y back. These constraints correspond to cutting the region by vertical or horizontal half planes.

The answer is yes if and only if R(n) is nonempty. 

By the process above, we can prove (inductively) that the region R(i) is always convex. For each i, we only add vertical and horizontal half planes. These half planes will cut some original edges of the convex polygon and add some new vertical or horizontal edges to it. The transformation x←x+y will change an edge with slope 1/k into an edge with slope 1/(k+1) (vertical edges becomes edges with slope 1/1). So we can also prove inductively that for any i, all the edges of R(i) have slope 0,∞ or 1/k for some integer k≤n. These edges can be written as Ax+By+C=0 for integral A,B and C.

We now know that for any i, the region R(i) is always convex and all edges have slope 0,∞ or 1/k for some integer k≤n. Next we describe how to implement the process described above efficiently. 

We maintain two deques for the vertices on the upper and lower hull of the polygon. Vertical edges are included in the upper hull if they have minimum x coordinate (and lower hull if they have maximum x coordinate.) To cut the polygon by vertical or horizontal half planes, we simply pop some vertices at the end of the deques. (And possibly add some new vertices at the front or back of the deques.) To apply the transformation x←x+y, we apply it to all vertices of the convex polygon. Since we apply the same operation to all vertices, this can be done by tags in constant time (like the tags in segment trees). We will explain the precision issues later. Finally, to take the union of all R(i)(z), we move the upper hull by (z+i+1,z+i+1) and the lower hull by (z−i+1,z−i+1). (These are again transformations applied to all vertices in each deque. We use tags as well.) The new upper hull and new lower hull are not necessarily connected. If they are not, we connect their first and last vertices.

The time complexity is O(n) assuming each arithmetic operation costs constant time.

