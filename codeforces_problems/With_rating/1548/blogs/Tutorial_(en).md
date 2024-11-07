# Tutorial_(en)

All the division 2 problems were created by [Agnimandur](https://codeforces.com/profile/Agnimandur "Master Agnimandur"). [1548E - Gregor and the Two Painters](../problems/E._Gregor_and_the_Two_Painters.md "Codeforces Round 736 (Div. 1)") was created by [Benq](https://codeforces.com/profile/Benq "Legendary Grandmaster Benq"). I hope that this hint-based editorial helps you, no matter what your rating is! Solution code is provided in both C++, Java, and Kotlin when available.

### [Solution Code Repository](https://codeforces.com/https://github.com/Agnimandur/Round736Solutions)

  


[1549A - Gregor and Cryptography](https://codeforces.com/contest/1549/problem/A "Codeforces Round 736 (Div. 2)")
-----------------------------------------------------------------------------------------------------------------

 **Hint 1**Fix a into a convenient constant.

 **Solution**Since P≥5 and is also a prime number, we know that P−1 is an even composite number. A even composite number is guaranteed to have at least 2 unique divisors greater than 1. Let two of these divisors be a and b. It is guaranteed that Pmoda=Pmodb=1, and thus this selection is valid.

For example, we can simply pick a=2 and b=P−1, and we will get a correct solution.

The time complexity is O(Q).

[1549B - Gregor and the Pawn Game](https://codeforces.com/contest/1549/problem/B "Codeforces Round 736 (Div. 2)")
------------------------------------------------------------------------------------------------------------------

#### Solution 1

 **Hint 1**There a very limited number of squares where each of Gregor's pawns could end up.

 **Hint 2**Identify a greedy strategy to maximize the answer.

 **Solution**The key insight is that due to the fact that there is only one row of enemy pawns, and those pawns never move, there are only 3 possible columns where one of Gregor's pawns can end up in.

We can solve this problem greedily, going from column 1 to column N. At the current column j, if Gregor has a pawn in this column, then we greedily consider 3 cases. 

 * If there is an uncaptured enemy pawn in column j−1, mark that pawn as captured and increment the answer. Column j−1 will never be looked at again, so this decision is optimal.
* If there is no pawn in column j, just move Gregor's pawn forward, and increment the answer.
* If there is an uncaptured enemy pawn in column j+1, mark that pawn as captured and increment the answer.
* Otherwise, this pawn will not reach the first row.

This greedy solution is guaranteed to produce the maximum possible answer.

The time complexity is O(N).

#### Solution 2

 **Hint 1**Write the problem as a graph problem.

 **Hint 2**Valid captures or valid forward moves represent edges in the graph.

 **Hint 3**We have two sets: Gregor's pawns, and destination squares. We also have some edges between these two sets.

 **Hint 4**Maximum Matching.

 **Solution**Each of Gregor's pawns can end up in one of 3 possible squares. If Gregor has a pawn in column i, it can end up in column i−1 or i+1 if there is an enemy pawn in those columns. Furthermore, it can remain in column i if there is no enemy pawn in that column.

Let's build a graph G, where each edge connects one of Gregor's pawns to a valid destination cell. Since every edge goes from a cell in the bottom row to a cell in the top row, G is clearly bipartite. It's now clear that moving as many pawns to the end is equivalent to finding a maximum matching in G.

The time complexity is O(N√N) using the HKK algorithm for maximum matching. (G has at most 2N vertices, and 6N edges)

[1549C - Web of Lies](https://codeforces.com/contest/1549/problem/C "Codeforces Round 736 (Div. 2)")
-----------------------------------------------------------------------------------------------------

 **Hint 1**For various graphs, try and simulate the process. Determine a rule to figure out whether a noble survives or not.

 **Hint 2**When you add or remove a single edge, how much can the answer change by? Try and recalculate the answer in O(1).

 **Solution**Due to the queries, actually simulating the process each time will be too expensive.

Proof that the Process will End: Assume after round x, xi nobles are killed. If xi=0, then the state of the graph doesn't change, so the process will have ended. If xi>0, then the number of nobles decreases. Thus, the maximum number of rounds the process can last is N, so it must end.

Lemma 1: At the end of the process, no two nobles will still be friends.

Proof by Contradiction: Assume that nobles u and v (assume WLOG that u<v) are still friends and the process is over. In order for u to avoid being killed, there must be a noble w weaker than u that is also a friend of u. The same logic then applies to w, and we have an infinite descent argument. There are only a finite number of nobles weaker than u, so there will be a contradiction.

Lemma 2: If all of a noble's friends are weaker than it, that noble cannot be killed.

Direct Proof: Since none of the noble's friends are stronger than it, it is impossible for all of them to be stronger at any point in the process.

Final Idea: By combining Lemmas 1 and 2, we can prove that if ALL of a noble's friends are weaker than it, that noble survives, otherwise it will die. This leads to the solution.

Maintain in an array the number of nobles weaker than noble i. Since the updates guarantee that the edge being removed/added does/doesn't exist respectively, we only need to keep track of the number of edges of each noble. Essentially, a noble survives if and only if `weaker[i]==edges[i]`. After linear precomputation, updates and queries take constant time.

The time complexity is O(N+M+Q).

[1549D - Integers Have Friends](https://codeforces.com/contest/1549/problem/D "Codeforces Round 736 (Div. 2)")
---------------------------------------------------------------------------------------------------------------

 **Hint 1**Let's say the subarray Ai…Aj is all congruent to nmodm. What does that imply about the subarray?

 **Hint 2**What does the previous hint imply about the difference array generated by D[i]=A[i+1]−A[i]?

 **Hint 3**GCD

 **Solution**The key observation is to construct the difference array D of size N−1, where D[i]=abs(A[i+1]−A[i]). If a given subarray is a friend group, then every difference is a multiple of some m. Since every element of A is distinct, the case when D[i]=0 can be ignored.

We can now convert this into a GCD (greatest common divisor) problem. It follows that A[i…j] is a friend group if and only if gcd(D[i…j−1])>1. Indeed, the value m that we want is equal to this GCD.

To solve the problem, we can use a sparse table or a segment tree to find the largest possible subarray beginning at i, and then max over all subarray answers to get the final answer.

The time complexity is O(NlogNlog1018). The first log is for the sparse table, the second is for computing GCDs.

Note that the de facto time complexity may be closer to O(NlogN+Nlog1018), due to the [insights from this blog post](https://codeforces.com/blog/entry/63771).

[1549E - The Three Little Pigs](https://codeforces.com/contest/1549/problem/E "Codeforces Round 736 (Div. 2)")
---------------------------------------------------------------------------------------------------------------

#### Solution 1

 **Hint 1**Convert the word problem into a combinatorics equation.

 **Hint 2**Write the equation for some x. Write the equation for x+1. How can we easily transition from the first to the second equation?

 **Hint 3**For a given x, we want to calculate every third term in the sequence (ix) for i∈[1,3N]. Think about how computing the entire summation ∑3Ni=1(ix) will help.

 **Solution**For a given x, we want to compute ∑Ni=1(3ix), which can be solved with a combinatorial dynamic programming.

Define the array `dp[x][m]` (dimensions: N+1×3), which computes the sum ∑N−1i=0(3i+mx). Under this definition, ans[x]=dp[x][0]+(3Nx), where `ans` is what we want to find.

Under the definition of the dp, we can make the following mathematical observations.

dp[x][0]+dp[x][1]+dp[x][2]=∑3N−1i=0(ix), since term i belongs to the array with m=imod3. This summation can be condensed with the Hockey Stick Identity into (3Nx+1).

By repeated uses of Pascal's Identity, we get equations (2) and (3), giving us a system of 3 equations with 3 new unknowns, which can easily be solved.

 1. ∑2m=0dp[x][m]=(3Nx+1).
2. dp[x][1]=dp[x][0]+dp[x−1][0]
3. dp[x][2]=dp[x][1]+dp[x−1][1]

The base case is that dp[0][0]=dp[0][1]=dp[0][2]=N. Each query can now be answered trivially.

The time complexity is O(N+Q) with combinatorial precomputation.

#### Solution 2

 **Hint 1**Convert the word problem into a combinatorics equation.

 **Hint 2**How will the Binomial Theorem be helpful?

 **Hint 3**Try and construct a polynomial P(k) such as the coefficient kx in that polynomial represents the number of attack plans if the wolf wants to eat x pigs.

 **Hint 4**Notice that P(k) is a geometric series, so FFT is unnecessary.

 **Solution**Define the polynomial P(k)=(1+k)3+(1+k)6+⋅+(1+k)3N.

The coefficient of kx in P(k) is, by the Binomial theorem on each term of the polynomial, equal to (3x)+(6x)+⋯+(3Nx). This is equal to `ans[x]` from the previous solution.

The only thing left to do is quickly calculate P(k). Due to the tight time limit, calculating the polynomial using FFT in O(NlogN) is probably too slow.

Instead, we notice that P(k) is a geometric series. Using the geometric series formula, we get that P(k)=(1+k)3N+3−(1+k)3(1+k)3−1.

The numerator and denominator of this fraction can be expanded in linear time. Then all we have to do is a polynomial long division. Once we have P(k), we can answer all the queries trivially.

The time complexity is O(N) with combinatorial precomputation.

[1549F1 - Gregor and the Odd Cows (Easy)](https://codeforces.com/contest/1549/problem/F1 "Codeforces Round 736 (Div. 2)")
--------------------------------------------------------------------------------------------------------------------------

 **Hint 1**"Enclosed cows" are just interior points. It's clear that Pick's Theorem will be useful.

 **Hint 2**Manipulate Pick's Theorem into a modular equation.

 **Hint 3**The number of boundary points between (x1,y1) and (x2,y2) is gcd(x1−x2,y1−y2).

 **Hint 4**Working with relevant formulas, find a simple condition between two points, such that they can be treated as equivalent.

 **Solution**Every set of 3 fenceposts forms a lattice triangle We want to find the number of such lattice triangles that have an odd number of interior points. Since all the coordinates are even, the area is automatically even as well. By Pick's Theorem, area=I+B2−1, so 2⋅area=2I+B−2. I is the number of interior points, and B is the number of boundary points, for an arbitrary triangle formed by 3 fenceposts.

Let A=2⋅area, so A=2I+B−2. Since I is odd, taking both sides modulo 4 we get that A≡Bmod4. Since the area is an even integer, A is a multiple of 4, so we get that A≡B≡0mod4.

Let's define the boundary count of a segment to be the number of lattice points on it, minus 1. It can be proven that the boundary count of the segment connecting (x1,y1) and (x2,y2) is gcd(|x2−x1|,|y2−y1|).

In this problem, we only care about what the boundary count is modulo 4. Since all the coordinates are even, the GCD is guaranteed to be even, so the boundary count is either 0 or 2 mod 4. For the segment connecting (x1,y1) and (x2,y2) call its boundary count b.

 * b≡0mod4 IFF x1≡x2mod4 AND y1≡y2mod4.
* b≡2mod4 in all other situations.

Key Idea: Turn fence post (x,y) into (xmod4,ymod4).

Writing the area of a triangle via the shoelace formula, it becomes obvious that the area mod 4 won't change when the coordinates are modded by 4. Additionally, by our work above, B (the sum of the boundary counts for the 3 sides of the triangle) is entirely dependent on the coordinates mod 4.

Let `cnt[x][y]` be an array counting the number of points that fall into each category based on the key idea above. Since all coordinates are even, only 4 elements in the cnt array will be nonzero. We can fix each point of the triangle into one of the categories, quickly calculuate A and B, and solve the problem. Be careful not to overcount triangles.

The time complexity is O(N), with a small constant for the counting.

[1549F2 - Gregor and the Odd Cows (Hard)](https://codeforces.com/contest/1549/problem/F2 "Codeforces Round 736 (Div. 2)")
--------------------------------------------------------------------------------------------------------------------------

 **Hint 1**Solve the easy version of the problem.

 **Hint 2**Taking each coordinate modulo 4 no longer works. This is because if Δx or Δy are odd, there's no way to predict whether the boundary count (see editorial of the easy version) is 1 or 3 mod 4.

 **Hint 3**By playing with Pick's Theorem, you should find that B (the total number of boundary points) has to be even. Let b1, b2, and b3 be the boundary count of the three sides of a lattice triangle.

 **Hint 4**Lets count the answer. Fix a point. Fix the boundary count mod 4 of the two sides adjacent to that point. Fix more things.

 **Hint 5**In Hint 4, we fixed a point. It's critical that you fix the boundary count of the side opposite that point to be even.

 **Solution**First read (and understand!) the editorial for the easy version of the problem.

 * Definition: The modularity of a point `(x,y)` is `(x%4,y%4)`.
* Definition: The boundary count of a segment is the number of lattice points on that segment, minus 1.

Lets precompute the array `cnt[i][x][y][b]` (dimensions N×4×4×4), which equals the number of other points respective to `points[i]` with modularity (x,y) and with a boundary count mod 4 equal to b. This precomputation can be done in O(N2log107) time, by iterating over every pair of points. The boundary count of the segment (x1,y1) to (x2,y2) is gcd(|x2−x1|,|y2−y1|).

Consider the number of boundary points on the three sides of a triangle, and call them b1,b2,b3. Clearly, B=b1+b2+b3. The key idea is that since B is even, wlog we can assume that b3 is even, and that b1≡b2mod2. The other key idea is that it is easy to figure out if the boundary count is congruent to 0 or 2 mod 4 based on the modularities of the coordinates alone, but it's impossible if the boundary count is odd.

Let's fix a point, and count the number of triangles that involve this point. Let's also iterate over all the relevant modularities of the other two points in the triangle, which range from (0,0) up to (3,3). Let's also make sure that there are an even number of boundary points on the side opposite the fixed point, which we know almost nothing about. It can be shown that b3≡0mod4 IFF (x1,y1)=(x2,y2), and that b3≡2mod4 IFF x1,x2 have the same parity, and y1,y2 have the same parity, and the previous case doesn't apply. Finally, make sure that the parity of the boundary count of the two sides next to the fixed point are the same.

Using the precomputed array cnt and the formula for b3, we can quickly find B in this case. Using the Shoelace Formula, we can quickly find what A is modulo 4. If A is even and equal to B, then we know that I must be odd (in the easy version of the problem, we found that A≡Bmod4 IFF I is odd), so all triangles in this class are interesting. Thus, we add to the answer a number roughly equal to cnt[i][x1][y1][b1]⋅cnt[i][x2][y2][b2] (it could be lower due to the potential overcount, if two points fall into the same bucket of the array).

Lastly, be sure not to overcount triangles! In my code, I count each of the `EEE` triangles (b1,b2,b3 all even) 3 times, and the `OOE` triangles once.

The time complexity is O(N2log107) (the main part of the solution is approximately O(512N)).

Implementation Note: The bottleneck of the algorithm is computing the GCDs. The simplest optimization that is sufficient for AC is to only calculate N22 GCDs instead of all N2 (since the GCD is commutative). Java requires additional optimizations, such as precomputing small GCDs.

[1548E - Gregor and the Two Painters](../problems/E._Gregor_and_the_Two_Painters.md "Codeforces Round 736 (Div. 1)")
---------------------------------------------------------------------------------------------------------------------

 **Hint 1**Let's give each component a "representative" cell. Then our task is now to count the number of representatives.

 **Hint 2**Let the cell with the smallest amount of paint in a component be the representative. How can we find if a given cell (i,j) is a representative or not? 

 **Solution**This editorial was written by [Benq](https://codeforces.com/profile/Benq "Legendary Grandmaster Benq"), and inspired by [1392I - Kevin and Grid](https://codeforces.com/contest/1392/problem/I "Codeforces Global Round 10").

For simplicity let's assume that all ai are distinct (and similarly, all bj). If this is not the case, we may break ties arbitrarily.

Say that two badly painted cells are directly reachable from each other if they are in the same row or column and all cells in between them are also badly painted. Also, define the value of the cell at (i,j) to be ai+bj. Call a badly painted cell a representative if no cell directly reachable from it has a smaller value than it.

Claim: Every connected component of badly painted cells contains exactly one representative.

Proof: Clearly every connected component contains at least one representative; consider the cell(s) with the minimum value contained within it. To show that every connected component contains \textit{exactly} one representative, suppose that we are given a representative (i,j) that is directly reachable from (i′,j) for all il≤i′≤ir and (i,j′) for all jl≤j′≤jr, where ai=minil≤i′≤ir(ai′) and bj=minjl≤j′≤jr(bj′). Then the connected component containing (i,j) is completely contained within the rectangle [il,ir]×[jl,jr], and (i,j) is the unique cell with the minimum value within that rectangle. This implies that a representative is always the unique cell with the minimum value within its connected component.

It remains to count the number of representatives. For each i, let loi be the maximum index less than hii such that aloi<ai and hii be the minimum index greater than i such that ahii<ai. Then define nai to be min(maxi′∈[loi,i]ai′,maxi′∈[i,hii]ai′). Any path from a cell in row i to a cell in the same column with lower value must pass through a row with value at least nai. Define nbj for each j similarly. It can be shown that (i,j) is a representative if and only if the following conditions hold:

 * ai+bj≤X
* nai+bj>X
* ai+nbj>X

Computing na and nb can be done in O(NlogN+MlogM) with any data structure supporting range min/max queries (e.g. sparse tables), or in O(N+M) with a stack. 

It remains to count the number of pairs (i,j) that satisfy these conditions given a, na, b, and nb. First initialize two binary indexed trees Ta and Tb. Then sort the pairs (nai−ai,ai),(nbj−bj,bj) in decreasing order. Now for every pair in the order, if it is of the form (nai−ai,ai), then add to the answer the number of elements of Tb that are in the range (X−nai,X−ai], and add ai to Ta. The reasoning for the case (nbj−bj,bj) is similar (query Ta, update Tb).

The time complexity is O(NlogN+MlogM) for sorting the pairs and working with the two BITs.

