# Tutorial_2

Thanks for the participation!

 
### [1986A - X Axis](../problems/A._X_Axis.md "Codeforces Round 954 (Div. 3)")

Let x1≤x2≤x3x1≤x2≤x3. Notice that the answer is at least x3−x1x3−x1, because |x3−a|+|x1−a|≥|x3−x1||x3−a|+|x1−a|≥|x3−x1| for any numbers aa, x1x1, x3x3.

The answer is equal to x3−x1x3−x1, since we can choose a=x2a=x2.

 
### [1986B - Matrix Stabilization](../problems/B._Matrix_Stabilization.md "Codeforces Round 954 (Div. 3)")

Let's consider any two adjacent cells of the matrix. Notice that our algorithm can change at most one value of these two cells.

* If the values in the cells are equal, then neither of these two adjacent cells will ever change its value.
* If the values in the cells are not equal, then the value of the larger cell will never become smaller than the value of the smaller cell.

Let mxmx be the maximum value written in the cells adjacent to (i,j)(i,j). If mx≥aijmx≥aij, then the value of the cell (i,j)(i,j) will not change during the execution of the algorithm; otherwise, it will eventually become equal to mxmx.

 
### [1986C - Update Queries](../problems/C._Update_Queries.md "Codeforces Round 954 (Div. 3)")

Let i1<i2<…<iki1<i2<…<ik be the set of indices of the array indind. Note that the indices of the string ss that are not in this set will simply not change their value.

Then we want to place the smallest character of the string cc at position i1i1, the next smallest at position i2i2, and so on. To achieve this, we can sort all the characters in the string cc. This approach to obtaining the answer is possible because all other operations, except those described above, can be performed first and will not affect the answer.

 
### [1986D - Mathematical Problem](../problems/D._Mathematical_Problem.md "Codeforces Round 954 (Div. 3)")

First, let's iterate through the position ii, such that we do not place a mathematical sign between the ii-th and (i+1)(i+1)-th elements.

Next, we have the following task — we have n−1n−1 numbers and we need to place a ++ or ×× sign between each pair of neighboring numbers to minimize the result. There are three possible cases:

* If there is at least one 00, the answer is 00. We can simply place all signs as ××.
* If all numbers are 11, the answer is 11. We can simply place all signs as ××.
* Otherwise, the answer is the sum of numbers not equal to 11. It is not advantageous to multiply numbers greater than one with each other, and all ones can simply be multiplied by any of the neighbors.
 
### [1986E - Beautiful Array](../problems/E._Beautiful_Array.md "Codeforces Round 954 (Div. 3)")

Notice that we actually want to pair the elements (in the odd case, exactly one element will not have a pair). If numbers x≤yx≤y fall into the same pair, then:

* These two numbers should have the same remainder when divided by kk. This is necessary in order to obtain one from the other.
* To make them equal, we will need y−xk=yk−xky−xk=yk−xk operations.

Consider all numbers from the array aa with the same remainder when divided by kk. Also, immediately divide them by the number kk. Let these numbers be b1≤b2≤…≤bmb1≤b2≤…≤bm. There are two possible cases:

* If mm is even, we need to pair all the numbers. It is best to pair b1b1 and b2b2, b3b3 and b4b4, and so on. Consequently, we will need b2−b1+b4−b3+…+bn−bn−1b2−b1+b4−b3+…+bn−bn−1 operations.
* If mm is odd, one element will remain unpaired. It can be tried and then an even number of elements will remain, and we can apply the idea for the even case. Notice that it is advantageous to remove the element with an odd index (denote it as ii). Then, if we leave the ii-th element unpaired, we will need b2−b1+b4−b3+…+bi−1−bi−2+bi+2−bi+1+…bn−bn−1b2−b1+b4−b3+…+bi−1−bi−2+bi+2−bi+1+…bn−bn−1 operations. To quickly calculate this sum, you can use prefix/suffix sums.

Also, note that if there are two different remainders for which mm is odd, the answer is −1−1.

 
### [1986F - Non-academic Problem](../problems/F._Non-academic_Problem.md "Codeforces Round 954 (Div. 3)")

Notice that if an edge is not a bridge, then after its removal the graph remains connected and all vertices are reachable from each other.

Therefore, we would like to remove some bridge edge (if there are no bridges, the answer is n⋅(n−1)2n⋅(n−1)2). After its removal, the graph will split into two connected components, let their sizes be xx and yy (note that x+y=nx+y=n). Then the number of pairs of vertices reachable from each other will be equal to x⋅(x−1)2+y⋅(y−1)2x⋅(x−1)2+y⋅(y−1)2. Let's find all the bridges in the graph, run a dfsdfs from an arbitrary vertex and calculate for each vertex the size of its subtree in the dfsdfs traversal tree (denote the size of the subtree of vertex vv as szvszv). Thus, for each bridge, we can find xx and yy, knowing the sizes of the subtrees (if the edge (u,v)(u,v) is a bridge, then x=min(szx,szy),y=n−xx=min(szx,szy),y=n−x). For all bridges, output the smallest answer.

 
### [1986G2 - Permutation Problem (Hard Version)](../problems/G2._Permutation_Problem_(Hard_Version).md "Codeforces Round 954 (Div. 3)")

Let ai=pigcd(i,pi)ai=pigcd(i,pi), bi=igcd(i,pi)bi=igcd(i,pi). Notice that we want to calculate the number of index pairs i<ji<j, such that:

* ajaj is divisible by bibi.
* aiai is divisible by bjbj.

Let's iterate through the values of bibi from 11 to nn (note that we are not fixing the element ii, but rather fixing the value of bibi). Now we know that we are interested in all aj=bi⋅kaj=bi⋅k, for some positive integer kk. Let's iterate through all such possible ajaj, and then iterate through all pairs with that value of ajaj. Add all suitable bjbj to the count array.

Now, for a fixed bibi and the constructed count array for it, iterate through all aiai that exist with this bibi. We can iterate through all divisors of aiai and simply add their count from the count array to the answer, because:

* Only those pairs for which ajaj is divisible by bibi are considered in the count array, so we have accounted for the first condition.
* We have accounted for the second condition when iterating through the divisors of aiai.

If the above is implemented correctly, a solution can be obtained in O(nlogn)O(nlogn). For this, we will need to pre-calculate all divisors for each ii from 11 to nn. We can iterate through ii and mark it as a divisor for all numbers of the form k⋅ik⋅i.

Also, everything written above works in O(nlogn)O(nlogn), because: the array aa was obtained from a permutation by dividing some elements, so the total number of divisors of all elements in aa (as well as the array bb) is no more than the total number of divisors of numbers from 11 to nn. And the total number of divisors of numbers from 11 to nn is at most n∑i=1ni=O(nlogn)∑i=1nni=O(nlogn).

