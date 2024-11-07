# Editorial_(en)

[982A - Row](../problems/A._Row.md "Codeforces Round 484 (Div. 2)")
-------------------------------------------------------------------------------------------

Seating is the maximum when it does not exist two ones or three zeros together. It is also necessary to carefully process the ends of the series — it is necessary to check that you can not put a person on the most right or the most left chairs.

[982B - Bus of Characters](../problems/B._Bus_of_Characters.md "Codeforces Round 484 (Div. 2)")
---------------------------------------------------------------------------------------------------------

Note that the final introvert-extrovert pairs are uniquely determined, and that using the stack, it is possible to recover which extrovert to which introvert will sit (note that the zeros and ones will form the correct bracket sequence). Then one of the solutions may be as follows:

 1. Sort the array of the lengths of the rows in ascending order
2. For each introvert write the number of the next free row and add it to the stack
3. For each extrovert write the last number from the stack and remove it from there

[982C - Cut 'em all!](../problems/C._Cut_'em_all!.md "Codeforces Round 484 (Div. 2)")
----------------------------------------------------------------------------------------------------

Note that if there is an edge that can be removed, we can do it without any problem. Let's consider such edge that in one of the obtained subtrees it is impossible to delete more anything else, and its removal is possible. What happens if we delete it in the tree? Relative to the other end of the edge, the odd-even balance of the subtree has not changed, which means that the edge has not been affected by further deletions. Which means if we remove it, the answer will be better. 

This is followed by a greedy solution: in dfs we count the size of the subtree for each vertex, including the current vertex, and if it is even, then the edge from the parent (if it exists) can be removed.

[982D - Shark](../problems/D._Shark.md "Codeforces Round 484 (Div. 2)")
---------------------------------------------------------------------------------------------

Let's sort the array and insert the numbers in the sort order from smaller to larger. Using the data structure "disjoint set union" we can easily maintain information about the current number of segments, as well as using the map within the function of union, and information about the current size of segments (locations) too. Then it remains only to update the answer when it's needed.

[982E - Billiard](../problems/E._Billiard.md "Codeforces Round 484 (Div. 2)")
------------------------------------------------------------------------------------------------

If you symmetrically reflect a rectangle on the plane relative to its sides, the new trajectory of the ball will be much easier. Linear trajectory if be correct. One possible solution is:

 1. If the vector is directed at an angle of 90 degrees to the axes, then write the if-s.
2. Otherwise, turn the field so that the impact vector becomes (1, 1).
3. Write the equation of the direct motion of the ball:  – 1·*x* + 1·*y* + *C* = 0. If we substitute the initial position of the ball, we find the coefficient *C*.
4. Note that in the infinite tiling of the plane the coordinates of any holes representable in the form (*k*1·*n*, *k*2·*m*).
5. Substitute the coordinates of the points in the equation of the line of the ball. The Diophantine equation *a*·*k*1 + *B*·*k*2 = *C*is obtained. It is solvable if *C* | *gcd*(*A*, *B*). Otherwise, there are no solutions.
6. Of all the solutions of this Diophantine equation, we are interested in the smallest on the positive half-axis.
7. By finding *k*1, *k*2 it is easy to get the coordinates of the corresponding pocket
8. Rotate the field back if required.

[982F - The Meeting Place Cannot Be Changed](../problems/F._The_Meeting_Place_Cannot_Be_Changed.md "Codeforces Round 484 (Div. 2)")
---------------------------------------------------------------------------------------------------------------------------

Let's assume that solution exists and will looking for solution relying on this assumption. At the end will check found "solution" in linear time, and if it is not real solution, then assumption wasn't right.

If solution exists, then intersection (by vertices) of all cycles is not empty. Let's take any one cycle and call it "main cycle". Let's imagine this "main cycle" as circle directed clockwise. And let's mark all required vertices of intersection of all cycles on this circle (this vertices are the answer).

Consider only cycles which leave "main cycle", come back to the "main cycle", and then moves on the "main cycle" to the begining. Every such cycle when comes back to the "main cycle" DOES NOT jump over any marked vertex of the answer, in terms of direction of the "main cycle" (otherwise answer not exists, but we assumed, that it exists) (if cycle comes back to the same vertex, then by definition it jumped over the whole "main cycle", not 0). Draw the arc from the vertex, where cycle comes back to the "main cycle" till the vertex, where it leaves "main cycle", in the direction of the "main cycle". Vertices not covered by this arc can't be the answer. Intersection of all considered cycles is marked by intersection of all such arcs.

Now was not considered only cycles which some times leave "main cycle" and some times comes back to it. But intersection of such cycle with the "main cycle" is the same as intersection of simple cycles from previous paragraph between adjacent leave/comebacks. Therefore such cycles may be ignored.

For searching the answer we must mark arcs between leaves/comebacks of the main cycle. We do this by starting dfs from all vertices of the "main cycle" and trying to come back to it as far as possible (distance measured as the number of vertices of the "main cycle" between leave and comeback). As were noticed early, cycles does not jump over the answer. Therefore dfses started between boundaries of the answer are aspires to this boundary in direction of the "main cycle". Therefore if we selected the most far vertex in one dfs(u) reached from one start point v0, this vertex for dfs(u) reached from other start point v1 will be the most far too. And we can run all dfses with common "used" array, caching the most far vertex in it.

Finally the solution is so: 1) find the "main cycle" and sort vertices in it, 2) start dfses from vertices of the "main cycle" and mark arcs between finish and start, 3) intersect all arcs and take answer from intersection, 4) verify answer by deleting it from graph and trying to find any other cycle, if it founded, then assumption was wrong and solution doesn't exists else print the answer.

