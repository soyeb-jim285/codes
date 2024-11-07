# Editorial_(en)

Problems A-G have been created by [isaf27](https://codeforces.com/profile/isaf27 "Grandmaster isaf27"). The idea of the problem A has been offered by [peltorator](https://codeforces.com/profile/peltorator "Grandmaster peltorator").

The problem H has been created by [cdkrot](https://codeforces.com/profile/cdkrot "Grandmaster cdkrot").

 
### [1054A - Elevator or Stairs?](../problems/A._Elevator_or_Stairs_.md "Mail.Ru Cup 2018 Round 1")

The time needed if we use stairs is |x−y|⋅t1|x−y|⋅t1.

The time needed if we use elevator is |z−x|⋅t2+|x−y|⋅t2+3⋅t3|z−x|⋅t2+|x−y|⋅t2+3⋅t3.

We can simply compute this values and compare them.

Time complexity: O(1)O(1).

Jury's solution: [44522356](https://codeforces.com/contest/1054/submission/44522356) 

### [1054B - Appending Mex](../problems/B._Appending_Mex.md "Mail.Ru Cup 2018 Round 1")

Ildar has written an array correctly if there exists numbers 0,1,…,ai−10,1,…,ai−1 to the left of aiai for all ii. This is equivalent to ai≤max(−1,a1,a2,…,ai−1)+1ai≤max(−1,a1,a2,…,ai−1)+1 for all ii. If this condition is false for some ii we made a mistake.

So the solution is to check that ai≤max(−1,a1,a2,…,ai−1)+1ai≤max(−1,a1,a2,…,ai−1)+1 in the increasing order of ii. If it is false ii is answer. If it is always true answer is −1−1.

Time complexity: O(n)O(n).

 Jury's solution: [44522430](https://codeforces.com/contest/1054/submission/44522430) 
### [1054C - Candies Distribution](../problems/C._Candies_Distribution.md "Mail.Ru Cup 2018 Round 1")

Let's note that for any ii, the value of (li+ri)(li+ri) is equal to the number of children who got more candies than ii-th. So, (n−li−ri)(n−li−ri) is equal to the number of children who got less or equal number of candies than ii-th (including himself). So, if there exists an array aa satisfying the conditions, then its numbers are ordered exactly as well as the numbers in the array (n−li−ri)(n−li−ri) (if the numbers at two positions are equal in one of the arrays, then they are equal in the other; if in one of the arrays at one position the number is less than the number at the other position, it is true for the other array). Also 1≤(n−li−ri)≤n1≤(n−li−ri)≤n for any ii. 

Thus, if there exists an array aa satisfying the conditions, then the array ai=(n−li−ri)ai=(n−li−ri) also satisfies the conditions. So, you just need to take the array ai=(n−li−ri)ai=(n−li−ri) and check it. If it satisfies conditions, the answer is this array, otherwise, there are no such arrays at all. The check can be performed using a trivial algorithm that works for O(n2)O(n2) time.

Time complexity: O(n2)O(n2).

 Jury's solution: [44522470](https://codeforces.com/contest/1054/submission/44522470) 
### [1054D - Changing Array](../problems/D._Changing_Array.md "Mail.Ru Cup 2018 Round 1")

We need to maximize the number of segments with XOR-sum of its elements not equal to 00. Let's note that the total number of segments is (n+12)=n⋅(n+1)/2(n+12)=n⋅(n+1)/2 so we need to minimize the number of segments with XOR-sum of its elements equal to 00. Let's call such segments bad. 

Consider the prefix XOR sums of array aa. Let's define pi=a1⊕⋯⊕aipi=a1⊕⋯⊕ai for any 0≤i≤n0≤i≤n. Note that the segment [l,r][l,r] is bad if prl−1=prrprl−1=prr. 

How does an array pp changes in a single operation with an array aa? Let's note that ¯x=x⊕(2k−1)x¯¯¯=x⊕(2k−1). If we do operation with the element ii then in array pp all elements pjpj (j≥ij≥i) will change to pj⊕(2k−1)pj⊕(2k−1) or ¯pjpj¯¯¯¯. So after all operations, element of pp will be either equal to itself before operations or will be equal to itself before operations but with all changed bits. But p0=0p0=0 still. 

On the other hand. Suppose that there are some changes of this kind in the array pp. Let's prove that we could make some operations in the array aa so that pp will be changed and became exactly the same. To prove this, note that ai=pi−1⊕piai=pi−1⊕pi, so all values of aiai have either not changed or have changed to numbers with all changed bits. So let's just assume that we are changing the array pp (all its elements except the element with index 00), not the array aa. 

Let's note that two numbers xx and yy can become equal after all operations with them if they are equal or x=¯yx=y¯¯¯. So we can replace pipi with min(pi,¯pi)min(pi,pi¯¯¯¯) for any ii in the array pp. The answer will be the same if we do this. But it will be impossible to get equal numbers from different numbers in the new array. 

Let's calculate for each number cc the number of its occurrences in the array pp and denote it for kk. Some of this kk numbers we can leave equal to cc, and some of them we change to ¯cc¯¯. Let's change 0≤a≤k0≤a≤k numbers. Then we want to minimize the number of pairs of equal numbers, which is (k−a+12)+(a+12)(k−a+12)+(a+12). To do this, we need to change and not change the approximately equal number of numbers, that is, the minimum is reached at a=⌊k/2⌋a=⌊k/2⌋. It can be proved simply. So we should divide the numbers this way for any cc and sum the answers.

For each number cc, the number of its occurrences in the array can be calculated using the sorting algorithm or the std::map structure into the C++ language.

Time complexity: O(n⋅log(n))O(n⋅log(n)).

 Jury's solution: [44522488](https://codeforces.com/contest/1054/submission/44522488) 
### [1054E - Chips Puzzle](../problems/E._Chips_Puzzle.md "Mail.Ru Cup 2018 Round 1")

Our usual operation — is to move the last character of a string in one cell to the beginning of a string in another cell. If we do the reverse operation — to move the first character of a string in one cell to the end of a string in another cell, then it's like we will do our operation for reversed strings and at the end, we will reverse them again.

Let's learn how to bring a table to a fixed one for ≤2⋅s≤2⋅s operations. After that, to solve our problem, we can bring the initial state to a fixed and final state (we should reverse all the strings in it) to a fixed. After that, if you reverse the second order of operations and add to the first, we get the solution to the problem. 

Our fixed table is a table in which the cell (2,1)(2,1) contains all 11 and the cell (1,2)(1,2) contains all 00. How to make this table from any table using ≤2⋅s≤2⋅s operations? First, we move all the characters of the first column and the first row to the cell (1,1)(1,1). Next, let's move all the characters of the rectangle with angles of (2,2)(2,2) and (n,m)(n,m) to the first column if it is 11, and to the first row if it is 00. This will take ≤s≤s operations. Next, let's move all the characters in the first column (except the (1,1)(1,1)) into the (2,1)(2,1) cell and all the characters in the first row (except the (1,1)(1,1) cell) into the (1,2)(1,2) cell. Finally, let's move the symbols of (1,1)(1,1) to (2,1)(2,1) if it is 11 or (1,2)(1,2) if it is 00.

Time complexity: O(s)O(s).

Bonus: What is the minimum constant cc you can get so that the algorithm always performs ≤c⋅s≤c⋅s operations? (cc may depends on nn, mm)

 Jury's solution: [44522506](https://codeforces.com/contest/1054/submission/44522506) 
### [1054F - Electric Scheme](../problems/F._Electric_Scheme.md "Mail.Ru Cup 2018 Round 1")

Let's reduce this problem to the problem of finding the minimum vertex cover in a bipartite graph.

We need to build the following graph: in one part all horizontal segments between adjacent points by xx from the set of points having the same yy, in the other part all vertical segments between adjacent points by yy from the set of points having the same xx. We will make an edge between segments from different parts if they intersect strictly by internal point. 

It can be proved that the answer is equal to (the number of distinct xx in the set) + (the number of distinct yy in the set) + (the maximum matching in this graph). To prove this, you need to understand how the answer looks like. In any case, for any xx from the set there will be ≥1≥1 vertical segment, with x1=x2=xx1=x2=x and for any yy from the set there will be ≥1≥1 horizontal segment, with y1=y2=yy1=y2=y. If we draw such segments, some of them will intersect at a point that not from the set. In this case, we will have to cut some of these segments. At the same time, we want to cut as little number of segments as possible (cutting — erase part of the segment between adjacent points on this segment's horizontal/vertical). We can see, that all erased segments form a vertex cover (in the graph we built). But if you erase the segments from the minimum vertex cover, you will get the answer, and this answer will have the smallest size.

So, it is necessary to find the minimum vertex cover in the constructed bipartite graph. This can be done by the standard algorithm uses O(V⋅E)=O(n3)O(V⋅E)=O(n3) time. We can prove that E≤n2/4E≤n2/4 and on practice it works very fast even for n=1000n=1000.

Time complexity: O(n3)O(n3).

Bonus: how to solve this problem faster than for O(n3)O(n3)? (if you don't need to find segments, only their number)

 Jury's solution: [44522527](https://codeforces.com/contest/1054/submission/44522527) 
### [1054G - New Road Network](../problems/G._New_Road_Network.md "Mail.Ru Cup 2018 Round 1")

Let us denote for AiAi the set of sets (or secret сomunities, as in our problem), which contains ii-th vertex.

Note that if some set AiAi contains an element that does not belong to any other set AjAj, it can be thrown out and it will not affect to the answer. Let's make this. 

Let the tree exist. Then it has a leaf (let this vertex ii). Let the only edge from ii be to vertex jj. Any element AiAi is contained in ≥2≥2-x sets and in the tree all sets (which secret сomunities) form connected subtrees. This implies that Ai⊂AjAi⊂Aj. So, if in A1,…,AnA1,…,An there are no two sets such that one subset of the other, then the tree does not exist. Otherwise, let us find any pair Ai⊂AjAi⊂Aj. We prove that there exists a tree in which ii is a leaf that has an edge to jj. It is possible to change the edges of any tree-solution that ii becomes a leaf that has an edge to jj, but the tree will still be a solution (it is the exercise for the reader). Let's find a good pair (i,j)(i,j), remove ii and continue the process. At the same time, at each step, it is necessary to remove the elements contained in ≤1≤1 sets. 

If we implement such an algorithm in this form it will work for O(n3⋅m/64)O(n3⋅m/64) time, which is too big. To improve the algorithm's complexity, for each set AiAi, we store a set of indices jj, such that Ai⊂AjAi⊂Aj. Then at each step, you can quickly find the needed pair (i,j)(i,j). At the same time, removing ii, you can quickly update this structure.

In this problem, there is a simpler solution, but it is more difficult to prove it. Let's build a weighted undirected graph on nn vertices with weight wij=|Ai∩Aj|wij=|Ai∩Aj|. Let's construct the maximum spanning tree in this graph. It is can be proved that either it is the answer, or there is no solution. This can be understood from the proof of the previous solution, which essentially simulates the search for such a spanning tree.

Time complexity: O(n2⋅m/64)O(n2⋅m/64).

 Jury's solution: [44522542](https://codeforces.com/contest/1054/submission/44522542)Solution by [Endagorion](https://codeforces.com/profile/Endagorion "International Grandmaster Endagorion"): [44519413](https://codeforces.com/contest/1054/submission/44519413) (maximal spanning tree) 

Tutorial is loading... Jury's solution: [44522571](https://codeforces.com/contest/1054/submission/44522571)