# Tutorial_(en)

Hello, Codeforces!

Hope you enjoyed the round! Editorials for all problems are out now. I hope this editorial be informative and helpful.

[1557A - Ezzat and Two Subsequences](../problems/A._Ezzat_and_Two_Subsequences.md "Codeforces Round 737 (Div. 2)")
--------------------------------------------------------------------------------------------------------------------

 **Hint 1**The average of a group of numbers always has a value between the minimum and maximum numbers in that group.

 **Solution**Since the average of a group of numbers always has a value between the minimum and maximum numbers in that group, it can be proved that the best approach to obtain the maximum sum of averages of two subsequences is to put the maximum number alone into one subsequence, and the rest of the numbers into the other subsequence. A proof by contradiction follows.

Assume a sorted array, so a1≤a2≤…≤an. Assume that there exists a bigger answer if you take the two greatest numbers (instead of only one) in one subsequence. Therefore, we need to prove that:

∑n−1i=1ai/(n−1)+an<∑n−2i=1ai/(n−2)+(an−1+an)/2

By simplifying the inequality:

an<2/(n−1)⋅∑n−2i=1ai/(n−2)+(n−3)/(n−1)⋅an−1

Assume avg1=∑n−2i=1ai/(n−2), so a1≤avg1≤an−2 as stated at the beginning of the tutorial. The inequality becomes:

an<(2⋅avg1+(n−3)⋅an−1)/(n−1)

The right-hand side of the inequality is also an average avg2, such that avg1≤avg2≤an−1 (which can be further simplified to a1≤avg2≤an−1).

This means that an is strictly less than avg2. In other words, it states that an is strictly less than a certain number between a1 and an−1. This is a contradiction as we stated at the beginning of the proof that the array is sorted (an≥an−1≥…≥a1). Summing things up, taking at least one number along with the maximum number will never yield a greater answer.

 **Code**[125412783](https://codeforces.com/contest/1557/submission/125412783 "Submission 125412783 by AhmedEzzatG")

[1557B - Moamen and k-subarrays](../problems/B._Moamen_and_k-subarrays.md "Codeforces Round 737 (Div. 2)")
-----------------------------------------------------------------------------------------------------------------

 **Hint 1**You can ignore the k given in the input, try to find the minimum k you need to sort the array (let call it mnK).

If mnK ≤ k then you can split some subarrays to make it equal k, so the answer is will be "YES". otherwise, the answer will be "NO".

 **Hint 2**You need to split the array into the minimum number of subarrays such that each subarray is sorted.

 **Solution**This problem can be solved for \textbf{at least} k subarrays as it is easy to just add extra subarrays (if needed) to achieve \textbf{exactly} k subarrays. To solve this problem, you need to know what are the numbers that can be grouped into the same subarray. This can be done by maintaining the sorted array along with the non-sorted array.

As the numbers are distinct, we can iterate over the non-sorted array, and just add each element ai to the subarray ending in ai−1 IFF they follow each other in the sorted array, or start a new subarray if they do not follow each other.

For example, if the (non-sorted) array is [ 2, 3, −1, 1], the sorted array will be [ −1, 1, 2, 3 ]. If we iterate over the non-sorted array, we will add 2 to a new subarray, then we will add 3 to the same subarray as they follow each other in the sorted array. After that, we will start a new subarray at −1 as −1 and 3 do not follow each other in the sorted array. Finally, we will add 1 to the subarray containing −1. It should end up like this: { [ 2, 3 ], [ −1, 1 ] }.

Using this approach, you can get the smallest number of subarrays needed. If it is strictly greater than the given k, the answer is ''NO''. Otherwise, it is ''YES''.

 **Code**[125412883](https://codeforces.com/contest/1557/submission/125412883 "Submission 125412883 by AhmedEzzatG")

[1557C - Moamen and XOR](../problems/C._Moamen_and_XOR.md "Codeforces Round 737 (Div. 2)")
--------------------------------------------------------------------------------------------------------

 **Hint 1**We don't care about the values in the array to know it's valid or not, we just need to know for every bit how many numbers have this bit on or off.

 **Hint 2**Try to build the array from the most significant bit (k−1) to the least significant bit 0 using dynamic programming.

 **Hint 3**Can you optimize dynamic programming code with some combinatorics?

 **Solution**From now on, I will use And to describe the result of the bitwise AND operation over all the elements in the array, and Xor to describe the result of the bitwise XOR operation over all the elements in the array.

Let's call the array is valid if the value of And ≥ Xor.

We don't care about the values in the array. We just need to know, for every bit, the number of indices at which this bit is on or off.

So let's build the array from the most significant bit (k−1) to the least significant bit (0) using dynamic programming and combinatorics optimization.

Define an array dp where dpi,equal = the number of ways to build the array from the i-th bit to 0-th bit. equal is true if And = Xor in the previous bits, and false if And > Xor (And < Xor is not a valid state).

Our base case is dp−1,0 = 1, and dp−1,1 = 1.

 * If equal is false at any moment, then you can choose any subset of indices to contain 1 in the i-th bit.

Therefore, dpi,0 = 2n ⋅ dpi−1,0.
* Now if n is odd there are 2 possible choices:


	1. You can make i-th bit = 1 in an even number of indices, then Andi will be 0 and Xori will be 0 too.
	2. You can make i-th bit = 1 in all indices, then Andi will be 1 and Xori will be 1 too.You Don't have any other valid choices. So dpi,1 = dpi−1,1 ⋅ ({number of ways to choose number of indices from n} + 1). (+1 for the second choice).
* If n is even there are 2 possible choices:


	1. You can make i-th bit = 1 in an even number (less than n) of indices, then Andi will be 0 and Xori will be 0 also.
	2. You can make i-th bit = 1 in all indices, then Andi will be 1 and Xori will be 0. and now equal will be false.You Don't have any other valid choices. So dpi,1 = dpi−1,1 ⋅ (number of ways to choose number of indices from n ) + dpi−1,0.

We can precalculate the factorial, to get nCr in O(1), and then calculate the number of ways to choose an even number from n before starting the dp. The total complexity will be O(k+n).

 **Code**[125412943](https://codeforces.com/contest/1557/submission/125412943 "Submission 125412943 by AhmedEzzatG")

[1557D - Ezzat and Grid](../problems/D._Ezzat_and_Grid.md "Codeforces Round 737 (Div. 2)")
--------------------------------------------------------------------------------------------------------

 **Hint 1**Try to count the maximum number of rows that makes a beautiful grid, and remove the others.

 **Hint 2**Can you get some dynamic programming formula, and then optimize it with some ranges data structures?

 **Solution**We can use dynamic programming to get the maximum number of rows that make a beautiful grid.

Define the 2d array, dp, where dpi,j = maximum number of rows (from row 1 to row i) that make a beautiful grid, and has 1 in column j at the last row I have in the biggest beautiful grid. the last row in the biggest beautiful grid is the not necessary to be i

Form the definition:

 * dp0,j = 0.
* dpi,j = 1 + maxk∈Ci {dpi−1,k} if gridi,j = 1.
* Otherwise, if gridi,j ≠ 1, then dpi,j = dpi−1,j .

where Ci is that set of columns that contain 1 in row i.

As you know, the set Ci contains the intervals, so we just search in some intervals for the maximum, or update some intervals in the previous layer in dp. We can do it faster using [Segment tree](https://codeforces.com/https://cp-algorithms.com/data_structures/segment_tree.html).

**So the algorithm will be as follows:**

 * Define an array prev, where previ = the previous row of i in which maximum beautiful grid end with i-th row. We will use it to get the rows that will not be removed.
* Build a segment tree of pairs (value, index) initially with { 0 , −1 }.
* Then for each i from 1 to n:


	+ Get the maximum value in all the ranges [lj,rj] that contains 1 at the i-th row. Let's call it mx.
	+ Store previ = mx.index.
	+ Update all the ranges [lj,rj] of this row like this: segj = max( segj , { mx.value + 1 , i }).
	+ Finally, get the rows that have the maximum value using the prev array, and remove the others.

The total complexity will be O(n+mlog109) or O(n+mlogm) if you make a coordinate compression to the values.

 **Code**[125412981](https://codeforces.com/contest/1557/submission/125412981 "Submission 125412981 by AhmedEzzatG")

[1557E - Assiut Chess](../problems/E._Assiut_Chess.md "Codeforces Round 737 (Div. 2)")
------------------------------------------------------------------------------------------------------

 **Hint 1**Try to force the king to move into one of the corners down.

 **Hint 2**If you put the queen in a row x, move the queen to the left of the row, then start swiping the row right, one square at a time. If you've visited all 8 squares on the row and the king never made a vertical move, it means | current king row − current queen row | ≥2 (if the king were on row (x+1\x−1), he would've been forced to move 1 square (down\up) at some point). 

 **Solution**This is one of many possible solutions. We need to force the king to move into one of the four corners (bottom right or bottom left corner in this solution) to ensure that the king will be trapped (cannot move anymore).

Place the queen on the top row. After the king makes a 1 move, he should be below the queen's row.

Suppose the queen is on the row x with the king below it (row x + i where i > 0).

If i = 1, we cannot move down to the next row as the king may move up and we will not be able to trap it. Otherwise, we can move down by one unit.

To ensure that the king is not on the next row, scan the current row, x, by moving the queen from the leftmost column to the rightmost column one square at a time. Therefore, you can move the queen as follows:

 1. During the scan, if you have visited all 8 squares of the current row and the king never made a vertical or diagonal move, it means that i≥2 and you can go down by one row. It is now guaranteed that the king is still below the queen.
2. If the king were on row x + 1, he would have been forced to move 1 square down at some point. If he ever goes down, move the queen down by one row.
3. If the king moves up, start scanning the row again. This can only happen a limited number of times without the king moving into a check.

In total, the queen needs to apply step 2 up to 8 times. At each row, step 1 needs to be applied, so it takes 8 moves. Step 1 also needs to be applied every time step 3 is applied, which can happen at most 8 times. In total, that is 8 ⋅ (8 + 8) = 128 moves. 

 **Code**[125413044](https://codeforces.com/contest/1557/submission/125413044 "Submission 125413044 by AhmedEzzatG")

