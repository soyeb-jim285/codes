# E_(en)


### [1201A - Important Exam](../problems/A._Important_Exam.md "Codeforces Round 577 (Div. 2)")

For each of the question let's count the number of answers of different type. Let $cnt[i][A]=$The number of A answers to the i-th question. The maximum score for that answer is $a[i]\cdot max(cnt[i][A], cnt[i][B], cnt[i][C], cnt[i][D], cnt[i][E])$. The answer is the sum of the maximum answer for the $m$ questions.

C++ code: [58307249](https://codeforces.com/contest/1201/submission/58307249 "Submission 58307249 by SPatrik")

 
### [1201B - Zero Array](../problems/B._Zero_Array.md "Codeforces Round 577 (Div. 2)")

There are 2 things needed to be possible to make all elements zero:

1: The sum of the elements must be even.

2: The biggest element have to be less or equal than the sum of all the other elements.

If both are true, the answer is "YES", otherwise "NO".

C++ code: [58307265](https://codeforces.com/contest/1201/submission/58307265 "Submission 58307265 by SPatrik")

 
### [1201C - Maximum Median](../problems/C._Maximum_Median.md "Codeforces Round 577 (Div. 2)")

Sort the array in non-decreasing order. In the new array $b_1, b_2, \ldots, b_n$ you can make binary search with the maximum median value. For a given median value ($x$), it is required to make $\sum_{i=(n+1)/2}^{n} max⁡(0,x-b_i)$ operations. If this value is more than $k$, $x$ can't be median, otherwise it can. Time complexity: $O((n/2)⋅log(10^9))$

C++ code: [58307281](https://codeforces.com/contest/1201/submission/58307281 "Submission 58307281 by SPatrik")

 
### [1201D - Treasure Hunting](../problems/D._Treasure_Hunting.md "Codeforces Round 577 (Div. 2)")

Make two arrays: left and right. $left[i]$ is the treasure in the leftmost position in row i (0 if there are no treasures in row $i$). $right[i]$ is the treasure in the rightmost cell in row $i$ (0 if there are no treasures in row $i$).

We can simply take out rows where there is no treasure (and add 1 to the result if there are treasure above that line, because we have to move up there).

For every row, except the last, we have to leave that row at one of the safe columns. Let's notice that the last treasure we collect in the row will be either $left[i]$ or $right[i]$. Let's take a look at both possibilities: If we collect the $left[i]$ treasure last, we have to leave the row either going left or going right to the closest safe column, because going further wouldn't worth it (consider moving up earlier and keep doing the same thing at row $i+1$). The same is true for $right[i]$. For the first row, we start at the first column, we can calculate the moves required to go up the second row at the for cells. For all the other rows, we have 4 possibilities, and we have to calculate how many moves it takes to reach the row $i+1$ at the 4 possible columns. For the last row, we don't have to reach a safe column, we just have to collect all the treasures there. We can count the answer for the problem from the calculated results from the previous row. Time complexity: $O(16*n)$

C++ code: [58307302](https://codeforces.com/contest/1201/submission/58307302 "Submission 58307302 by SPatrik")

 
### [1201E2 - Knightmare (hard)](../problems/E2._Knightmare_(hard).md "Codeforces Round 577 (Div. 2)")

First calculate the number of moves needed to reach (without capturing) positions $(a_1;b_1)$ and $(a_2;b_2)$.

If one of the knights can reach it's goal at least 2 moves faster than the other can and faster than the other can reach it's goal, than there is a winning strategy with it. Just go the shortest path. The other knight won't be able to capture your knight, because after you move you are $x$ moves away from it, than the other knight must be at least $x+2$ far, so it will be at least $x+1$ after it's move.

If one of the knights can reach it's goal at exactly 1 move faster than the other can and faster than the other can reach it's goal, we have to count the moves needed to reach all the positions which is 1 move away from the goal. If there is a position from these which can be reached at least 2 moves faster, than that knight can win.

Let's color the chessboard the regular way with white and black colors. If the 2 knights are in same color, than only the black knight can capture the white, otherwise only the white can capture the black (that is because knights always move to different color than they come from).

In all the other situation there is at least drawing strategy with the knight that can capture the other:

Move to the position that the other knight have to reach and stay there or 1 move away from it. The other knight won't be able to reach that position without getting captured. So we choose that knight and search for the winning strategy. You can win the game in 2 steps:

First: Go to your opponent's target cell in the fastest way (if the opponent could go there faster, you can still outrun him, because there is no position which is 1 move away from the opponents goal and can be reached at least 2 moves faster (we already looked that situation), so you can take away the opponent's possibility to reach the target by threatening with capturing their knight). This is maximum of 333 moves.

Second: Go from there to your target cell on the fastest way. It can be easily shown that it takes 3 moves to go there. When you are in the opponent's target position your opponent can be either exactly 1 move or at least 3 moves away from you (because the distance (in moves) between you and your opponent's knight after your opponent's turn is always odd). If it is 1 move away, you can capture his knight, if at least 3 or moves away from you (and therefore the target position), you can reach your target faster than your opponent.

That's a total of 336 moves.

C++ code: [58307320](https://codeforces.com/contest/1201/submission/58307320 "Submission 58307320 by SPatrik")

O(n4)O(n4) complexity solution for problem E1 by [KAN](https://codeforces.com/profile/KAN "Grandmaster KAN"): [58306483](https://codeforces.com/contest/1201/submission/58306483 "Submission 58306483 by SPatrik")

