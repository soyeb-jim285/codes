# Tutorial_(en)

Problem A is developed by [mejiamejia](https://codeforces.com/profile/mejiamejia "Expert mejiamejia").

#### [1733A - Consecutive Sum](../problems/A._Consecutive_Sum.md "Codeforces Round 821 (Div. 2)")

 **Hints****Hint 1**i-th element moves only to (i+xk)-th position (x is integer).

 **Hint 2**We cannot select ai and ai+xk simultaneously. In other words, if we can swap ai and aj, we cannot select ai and aj simultaneously.

 **Hint 3**Among all elements ai+xk for each i (1≤i≤k), only one element is selected.

 **Solution**For each index i (k+1≤i≤n), there is exactly one element among a1 to ak, which can swap with ai. If ai is greater than that element, swap them. This process perform the operation at most n−k times. After performing operations, select a1 to ak. This is the maximum score we can get.

 **Solution Code**[#172743256](https://codeforces.com/contest/1733/submission/172743256)

 **Challenge**After performing all operations, select p consecutive elements. p can be different from k. Find the maximum score.

#### [1733B - Rule of League](../problems/B._Rule_of_League.md "Codeforces Round 821 (Div. 2)")

 **Hints****Hint 1**Because one of player 1 and player 2 win 0 games and the other win at least 1 game, min(x,y)=0 and max(x,y)>0 must be true in order to generate a valid result.

 **Hint 2**There are one winner and one loser for every match. So the sum of winning count and the sum of losing count are same.

 **Hint 3**The sum of winning count is a multiple of max(x,y). Therefore, the sum of losing count is also a multiple of max(x,y).

 **Hint 4**(The sum of losing count) equals to n−1. So n−1 is a multiple of max(x,y) if there is a valid result. 

 **Solution**According to hints, min(x,y)=0 and max(x,y)>0 and (n−1)modmax(x,y)=0 holds in order to generate a valid result. If so, player 1 and player 2 would play first. Let's consider player 2 wins. Then player 2 should win max(x,y) games, and loses to player max(x,y)+2. Likewise, player max(x,y)+2 wins max(x,y) games and loses to player 2⋅max(x,y)+2. Construct the remaining result in the same way.

 **Solution Code**[#172746518](https://codeforces.com/contest/1733/submission/172746518)

 **Challenge**Expand x, y to x, y, z?

#### [1733C - Parity Shuffle Sorting](../problems/C._Parity_Shuffle_Sorting.md "Codeforces Round 821 (Div. 2)")

 **Hints****Hint 1**If all elements are equal, that array is also non-decreasing.

 **Hint 2**For each operation, one element is changed. Because we have to use at most n operations, an element change occurs at most n times. Considering that the initial array can be decreasing, at least n−1 operations can be needed in some cases.

 **Solution**If n=1, do nothing.

Otherwise, select indices 1 and n to make a1 equal to an first. After that, for each element ai (2≤i<n), select indices 1 and i if a1+ai is odd, and select indices i and n otherwise. This process requires n−1 operations and make all elements equal, which is also non-decreasing.

 **Solution Code**[#172746622](https://codeforces.com/contest/1733/submission/172746622)

 **Challenge**Find the minimum number of operations?

#### [1733D1 - Zero-One (Easy Version)](../problems/D1._Zero-One_(Easy_Version).md "Codeforces Round 821 (Div. 2)")

 **Hints****Hint 1**Consider c is another binary string, in which ci=ai⊕bi. We have to make c equal to 000…000 using the operation.

 **Hint 2**Because the operation does not change the parity of the number of 1 in c, the answer is −1 if c has odd number of 1.

 **Hint 3**If the number of 1 in c is d (now assume that d is even), at least d2 operations are needed. So total cost would be at least d2×y.

 **Hint 4**One x-cost operation can be replaced with two y-cost operations.

 **Solution**Consider another binary string c, in which ci=ai⊕bi (1≤i≤n). So doing an operation means selecting two indices of c and flipping them. Also, let's define d is the number of 1 in c. Because the parity of d never changes, the answer is −1 if d is odd.

If d is even, classify the cases:

[1] If d=2 and two 1-s are adjacent, the answer is min(x,2y). Because n≥5 holds, we can always replace one x-cost operation with two y-cost operations.

[2] If d=2 and two 1-s are not adjacent, the answer is y.

[3] If d≠2, select i-th 1 and (i+d2)-th 1 each (1≤i≤d2). This costs d2×y, and we showed the cost cannot be reduced more in hint 3.

 **Solution Code**[#172746684](https://codeforces.com/contest/1733/submission/172746684)

#### [1733D2 - Zero-One (Hard Version)](../problems/D2._Zero-One_(Hard_Version).md "Codeforces Round 821 (Div. 2)")

 **Hints****Hint 1**Greedy solution used in D1 doesn't work in this version.

 **Hint 2**The restriction accepts normal O(n2) solution.

 **Solution**(Continued from D1 editorial)

If x<y, greedy approach used in D1 doesn't work. Let's use DP. Define z0[i][j] as the minimal cost when there is j 1s in first i elements of c and ci=0, and z1[i][j] as the minimal cost when there is j 1s in first i elements of c and ci=1. Initially all table values are ∞.

First, check c1. If c1=0, set z0[1][0] to 0. Otherwise, set z1[1][1] to 0.

Then, check the following elements from c2 to cn in turn.

[4] If ci=0,

 z0[i][j]=min(z0[i−1][j],z1[i−1][j]),z1[i][j]={min(z0[i−1][j]+y,z1[i−1][j]+x),if j≤1,min(z0[i−1][j]+y,z1[i−1][j]+x,z0[i−1][j−2]+x,z1[i−1][j−2]+y),if j>1,[5] If ci=1,

 z0[i][j]={min(z0[i−1][j+1]+y,z1[i−1][j+1]+x),if j=0,min(z0[i−1][j+1]+y,z1[i−1][j+1]+x,z0[i−1][j−1]+x,z1[i−1][j−1]+y),if 0<j<i,min(z0[i][j],z0[i−1][j−1]+x,z1[i−1][j−1]+y),if j=i,z1[i][j]={∞,if j=0,min(z0[i−1][j−1],z1[i−1][j−1]),if j>0,for 0≤j≤i. The answer is z[n][0].

 **Solution Code**[#172746737](https://codeforces.com/contest/1733/submission/172746737)

 **Challenge**Solve n≤105 version. Some testers found O(n) solution.

#### [1733E - Conveyor](../problems/E._Conveyor.md "Codeforces Round 821 (Div. 2)")

 **Hints****Hint 1**Each second, slime ball moves to next diagonal.

 **Hint 2**Every slime always locates in different diagonal.

 **Hint 3**No two slime ball will merge forever.

 **Hint 4**If t<x+y, the answer should be "NO".

 **Solution**In the conveyor, cells with same (i+j) value consists a diagonal (i is row number, j is column number). Let's call them (i+j)-th diagonal. So there are 239 diagonals, from 0-th to 238-th.

So, we can find every slime ball move to the next diagonal for every second. It means no two slime ball merge forever.

Given t, x, y, cell (x,y) belongs to (x+y)-th diagonal. If t<x+y, the answer is NO because there is no slime ball in (x+y)-th diagonal yet. If t≥x+y, (x+y)-th diagonal contains one slime ball, and the ball is placed on cell (0,0) after (t−x−y) seconds from the start. So (t−x−y) slime balls passed this diagonal before.

Now, find out which cell contains slime ball among the diagonal. To do this, we use following method: simulate with (t−x−y) slime balls to check how many slime reach each cell of the diagonal, and repeat this with (t−x−y+1) slime balls. Exactly one cell will show different result, and this cell is where (t−x−y+1)-th slime ball passes through. If this cell is equal to (x,y), the answer is YES. Otherwise the answer is NO.

Simulation with x slime balls processes as follows:

 * Place x slime balls on cell (0,0).
* Move slime balls to next diagonal. For each cell, if the cell contains k slime balls, ⌈k2⌉ moves to right and ⌊k2⌋ moves to down.
* Repeat the second step. If slime balls reached aimed diagonal, stop and find the result.
 **Solution Code**[#172746768](https://codeforces.com/contest/1733/submission/172746768)

 **Challenge**Increase the conveyor size to 104×104. Solve this version. Query number is same.

