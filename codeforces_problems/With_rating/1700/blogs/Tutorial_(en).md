# Tutorial_(en)

Thanks for the participation!

[1700A - Optimal Path](../problems/A._Optimal_Path.md "Codeforces Round 802 (Div. 2)") was authored and prepared by [74TrAkToR](https://codeforces.com/profile/74TrAkToR "Grandmaster 74TrAkToR")

[1700B - Palindromic Numbers](../problems/B._Palindromic_Numbers_.md "Codeforces Round 802 (Div. 2)")  was authored by [fedoseev.timofey](https://codeforces.com/profile/fedoseev.timofey "International Grandmaster fedoseev.timofey") and prepared by [_overrated_](https://codeforces.com/profile/_overrated_ "Master _overrated_")

[1700C - Helping the Nature](../problems/C._Helping_the_Nature.md "Codeforces Round 802 (Div. 2)") was authored and prepared by [Igorbunov](https://codeforces.com/profile/Igorbunov "Grandmaster Igorbunov")

[1700D - River Locks](../problems/D._River_Locks.md "Codeforces Round 802 (Div. 2)") was authored and prepared by [Ziware](https://codeforces.com/profile/Ziware "International Master Ziware")

[1700E - Serega the Pirate](../problems/E._Serega_the_Pirate.md "Codeforces Round 802 (Div. 2)") was authored by [fedoseev.timofey](https://codeforces.com/profile/fedoseev.timofey "International Grandmaster fedoseev.timofey") and prepared by [talant](https://codeforces.com/profile/talant "Master talant")

[1700F - Puzzle](../problems/F._Puzzle.md "Codeforces Round 802 (Div. 2)") was authored and prepared by [Olerinskiy](https://codeforces.com/profile/Olerinskiy "Master Olerinskiy")

 
### [1700A - Optimal Path](../problems/A._Optimal_Path.md "Codeforces Round 802 (Div. 2)")

Let's notice that the optimal path looks like the following: (1,1)→(1,2)→…→(1,m)→(2,m)→…→(n,m). The proof is relatively easy — all paths from (1,1) to (n,m) consist of n+m−1 cells and in the optimal path we have minimized all numbers in the path. The cost of such path is equal to 1+2+…+m+2⋅m+…+n⋅m=m−1∑i=1i+m⋅n∑i=1i. This sum can be found in O(n+m) by just summarizing all numbers, or it can be found in O(1) if you remember that n∑i=1=n⋅(n+1)2.

 
### [1700B - Palindromic Numbers](../problems/B._Palindromic_Numbers_.md "Codeforces Round 802 (Div. 2)")

Let X be the number in input. Consider two cases: first digit of X is 9 and not 9.

If the first digit of input number is not 9, we can simply output 9999...999 (n digits) - X. 

If the first digit is 9, we can output 111...1111 (n+1 digits) - X. It is easy to show that this number will be exactly n-digit.

To simplify implementation, we can first find 9999...999 - X by subtracting all digits of X from 9, and than if this number is not n-digit, add 111...1111 - 9999...999 = 11111...1112 to it.

Overall complexity will be O(n).

 
### [1700C - Helping the Nature](../problems/C._Helping_the_Nature.md "Codeforces Round 802 (Div. 2)")

Consider the difference array di=ai+1−ai. Note that for di>0 it is necessary to make di subtractions on the suffix. For di<0, you need to make −di subtractions on the prefix. Let's add them to the answer. Let's calculate the final array using prefix and suffix sums for O(n). Note that it will consist of the same numbers. Add |x| to the answer, where x is the resulting number.

 
### [1700D - River Locks](../problems/D._River_Locks.md "Codeforces Round 802 (Div. 2)")

To begin with, we note that it makes sense to open only some pipe prefix, because we need to fill all the locks, and more left pipes affect the total volume of the baths, which is obviously beneficial. Let's enumerate how many pipes we will open, namely which prefix of pipes we will open and calculate dpi - how long it will take to fill the first i locks if the first i pipes are open. Let's introduce an auxiliary array prefi - the sum of the capacities of the gateways on the prefix i. Then dpi=max(dpi−1, ⌈prefi/i⌉). Let's see why this is so. We need all gateways on prefix i−1 to be filled, and also that the i-th gateway be filled. Note that if the i-th gateway does not have time to fill up in the time dpi−1, then it will fill up in the time ⌈prefi/i⌉ (filling will occur at the time prefi/i, but since in the condition we are asked about integer times, we can round up and not use real arithmetic), it turns out when the required amount of water is poured into all the locks in total from all pipes. Now knowing dpi for all i open we can similarly calculate when all n gateways are full. For i this will be max(dpi, ⌈prefn/i⌉). It is also obvious that when an additional pipe is opened, the time will not increase, therefore we can do a bin search by time and find out the answer for the desired request. If the request t is less than the minimum filling time for the locks (when all pipes are open), then you need to print −1. Total running time O(n+qlog(n)).

 
### [1700E - Serega the Pirate](../problems/E._Serega_the_Pirate.md "Codeforces Round 802 (Div. 2)")

We need to find a simple criteria of a solvable puzzle. It can be shown that for every cell, except cell with value 1, it should have a neighbour with a smaller value. Indeed, if the puzzle is solvable, a cell going before the first occurence of our cell always has the smaller value. Conversely, if each cell has a smaller neighbor, one can list cells one at a time, and there will always be a path to the next cell along already visited cells with lower numbers.

Let's call a cell bad, if it's value is not 1 and it doesn't have a neighbour with a smaller value. Consider any bad cell. Let's notice, that the pair that we swap should contain either the bad cell itself, or its neighbour, otherwise that bad cell will stay bad. That way we have 5nm pairs of candidates, for each of which we'll run a check if the resulting puzzle is solvable.

Now we'll learn how to quickly understand, if the puzzle became solvable after a swap. For this we'll keep the amount of bad cells. After the swap, the state can be changed only for these cells and their neighbours. Let's recalc the amount of bad cells and check if it's zero.

The resulting complexity is O(nm)

 
### [1700F - Puzzle](../problems/F._Puzzle.md "Codeforces Round 802 (Div. 2)")

We are asked to find a minimum cost perfect matching between 1's in the matrices, where the cost between (x1,y1) and (x2,y2) is |x1−x2|+|y1−y2|. Notice that the answer exists only if the number of 1's is equal in both matrices. Consider that this is the case.

Notice that every 1 either stays in its original row or changes it in a single operation. For simplicity let's assume that all operations of that kind are performed in the beginning. Let's denote Δi,j as the difference between the j-th prefix sum in i-th row of the matrices. If the final row for each 1 is fixed, then the answer is equal to S+∑ni=1(|Δ1,i|+|Δ2,i|), where S in the number of 1's that changed its row.

Now let's look at what happens when we change the row of a 1. For simplicity let's assume that it was in a cell (1,j). Then after the swap we have to increment S by 1, decrement all Δ1,j,…Δ1,n by 1, and increment all Δ2,j,…Δ2,n by 1.

Now let's solve the following problem: we are given Δ1,i and Δ2,i and in one operation we can increment some suffix by 1 and decrement the same suffix in the other array by 1. The goal is to minimize S+∑ni=1(|Δ1,i|+|Δ2,i|).

Notice that the following greedy algorithm works: iterate through columns from left to right and while Δ1,i and Δ2,i have different signs, decrement the suffix of one that's greater and increment suffix of one that's lower.

Now let's prove that this algorithm minimizes the target sum. For this consider some optimal sequence of operations. It doesn't matter in which order operations are performed, so let's assume they are performed from left to right, and are accumulated in a single element for the same suffix. If the sequences differ, denote i as the first such position. Note that before that all Δ1,i and Δ2,i are the same in both our answer and the optimal one. Suppose that in the optimal answer we incremented i-th suffix of Δ1 by k and decremented i-th suffix of Δ2 by k. Then the target sum will increase by |k|+|Δ1,i+k|+|Δ1,i−k|.

Consider the following cases: 

* Δ1,i≥0 and Δ2,i≥0 or Δ1,i≤0 and Δ2,i≤0. By triangle inequality |Δ1,i+k|+|Δ2,i−k|≥|Δ1,i+Δ2,i|=|Δ1,i|+|Δ2,i|, which means that those k operations could be performed on the i+1-st suffix and that wouldn't increase the answer.
* Δ1,i<0 and Δ2,i>0. Here if k<0, |Δ1,i+k|+|Δ2,i−k|=2|k|+|Δ1,i|+|Δ2,i|, which means that those k operations could be performed on the i+1-st suffix and that wouldn't increase the answer. Now if k≥0. We can assume that k≤min, otherwise we will perform an operation on values with the same sign, which we already shown can be done later on. Then |k| + |\Delta_{1,i} + k| + |\Delta_{2,i} - k| = k + (-k - \Delta_{1,i}) + (\Delta_{2,i} - k) = -k - \Delta_{1,i} + \Delta_{2,i}. Greedy algorithm suggests doing exactly t = \min(-\Delta_{1,i}, \Delta_{2,i}) operations. Note that if we perform t operations on suffix i and t-k operations on suffix i+1, we will add (-t - \Delta_{1,i} + \Delta_{2,i}) + (t - k) = -k - \Delta_{1,i} + \Delta_{2,i} to the answer and get the same state as the optimal answer. This means that we can do t operations and not increase the answer.
* \Delta_{1,i} > 0 and \Delta_{2,i} < 0. This case can be analyzed in the same way.

 What we showed here is that we can always extend the matching prefix with the optimal answer, which means that the greedy algorithm produces the same answer.Let's come back to the original problem. Described greedy algorithm finds a lower bound on the answer. Let's show that it is always possible to achieve it when the operations are allowed only for moving 1's between rows and the number of 1s in each row at the end should be the same. For this note that we can "perform" operations on 1's from the second matrix, if we reverse their order and append to the end of the sequence for the first matrix. Now note that if on some prefix i \Delta_{1,i} and \Delta_{2,i} have the same sign, but on prefix i+1 the signs differ, there has to be at least a single 1 in column i+1, and we can perform the operation suggested by the greedy algorithm. Finally, if the answer exists it is true that \Delta_{1,n} + \Delta_{2,n} = 0, and if \Delta_{1,n} and \Delta_{2,n} have the same sign at the end this means that they are both 0, which means that the constructed answer is correct.

This solution works in O(n) time.

