# Tutorial_(en)

[1917A - Least Product](../problems/A._Least_Product.md "Codeforces Round 917 (Div. 2)")

Author: [zidder](https://codeforces.com/profile/zidder "Grandmaster zidder")   
 Preparation: [_LeMur_](https://codeforces.com/profile/_LeMur_ "Master _LeMur_")   
 Editorial: [zidder](https://codeforces.com/profile/zidder "Grandmaster zidder")   
 Official solution: [238752794](https://codeforces.com/contest/1917/submission/238752794 "Submission 238752794 by _LeMur_")   


 **Hint 1**What is the minimum product that we can get, when one of the given numbers is equal to 0.

 **Hint 2**How is the absolute value of the integer changed, when we apply the given operation on that integer?

 **Hint 3**We can always make the product as small as possible with at most 1 operation.

 **Solution**First, let's find the minimum product we can get. If one of the numbers is or becomes 0, then the product will be 0. Otherwise, all the numbers don't change their sign during the operation. So the initial product won't change its sign as well. Also, we can note that the absolute value will not increase after an operation. That means if the initial product is negative, we cannot decrease it. In this case the necessary number of operations will be 0.

If the initial product is positive, then we know the product won't become negative, therefore we will make it zero with 1 operation, which will be the answer and the operation will be changing any number to 0. If the initial product is zero, then we don't need to change anything, so the number of operations needed is 0.

[1917B - Erase First or Second Letter](../problems/B._Erase_First_or_Second_Letter.md "Codeforces Round 917 (Div. 2)")

Author: [_LeMur_](https://codeforces.com/profile/_LeMur_ "Master _LeMur_")   
 Preparation: [_LeMur_](https://codeforces.com/profile/_LeMur_ "Master _LeMur_")   
 Editorial: [zidder](https://codeforces.com/profile/zidder "Grandmaster zidder")   
 Official solution: [238752759](https://codeforces.com/contest/1917/submission/238752759 "Submission 238752759 by _LeMur_")   


 **Hint 1**Do we need to use the first operation after the second operation?

 **Hint 2**Try to fix the number of the applied first operation. How many different strings can be obtained?

 **Hint 3**When can two reached strings be the same?

 **Hint 4**Try to consider the first occurrence for each letter.

 **Solution**Let's first see, that applying the second operation and then the first is equivalent to applying the first operation twice. In the former case the string will become s1s2s3…sn→s1s3…sn→s3…sn, and in the latter case: s1s2s3…sn→s2s3…sn→s3…sn. As we are concerned with only the number of distinct resulting strings, let's assume that the second operation is never done before the first operation. This means we do op1 first operations (possibly zero) and then op2 second operations (possibly zero).

Let's now find the result of applying i of the first and then j of the second operations. It's easy to see, that the result is si+1si+j+2si+j+3…sn.

The only remaining question is in which cases two sequences of operations such that the first operation always comes before the second result in the same string. Consider for the (i1,j1) pair, the resulting string is the same as for the (i2,j2) pair. We can see that i1+j1=i2+j2, because the number of erased letters should be the same to get strings of the same length. Next, si1+1=si2+1 as those are the first letters of two resulting equal strings. It's easy to see that these conditions are also sufficient for the result to be the same string.

If after applying the first operation op1 times the first letter is not its first occurrence, then any subsequent result could have been achieved by less operations of the first type by removing first character until reaching that letter and then by removing the second character until we reach op1 operations in total. This means we need to consider using the second operation only at the first occurrence of the letter.

The final solution can look like this: for each letter a…z find it's first occurrence. If the letter is found, any number of second type operations lead to a different result. Thus we can just calculate the number of second operations that is valid and add that to the answer.

[1917C - Watering an Array](../problems/C._Watering_an_Array.md "Codeforces Round 917 (Div. 2)")

Author: [IgorI](https://codeforces.com/profile/IgorI "Grandmaster IgorI")   
 Preparation: [IgorI](https://codeforces.com/profile/IgorI "Grandmaster IgorI")   
 Editorial: [IgorI](https://codeforces.com/profile/IgorI "Grandmaster IgorI")   
 Official solution: [238743155](https://codeforces.com/contest/1917/submission/238743155 "Submission 238743155 by IgorI")   


 **Hint 1**Assume that you are starting with array a=[0,0,…,0].

 **Hint 2**Can your score increase by more than 1 in this case?

 **Hint 3**Note that array a is non-increasing after each operation and [1,2,…,n] is strictly increasing.

 **Hint 4**Try fixing the first day you make reset operation on.

 **Hint 5**Can your score increase by more than n on reset operation?

 **Solution**Let's first solve this problem if we start with the array a=[0,0,…,0]. This array is non-increasing and adding 1 to any of its prefixes keeps it non-increasing. On the other hand, array [1,2,…,n] is strictly increasing. This means that if ai=i and aj=j then i=j (because if i<j then ai≥aj and both conditions cannot hold simultaneously). Thus you cannot increase your score by more than 1 in one reset operation. Also you cannot increase your score by 1 in two operations in a row, because array a will be equal to [0,0,…,0] before the second of this operations. Similary, you cannot increase your score on the first day. Thus, the maximum score you can get is ⌊d2⌋. On the other way, you can always achieve this score by alternating operations.

So once we fixed the first day i we are making reset operation on, we can easily compute the maximum total score we will get for all the further days. Trying all d possibilities of the first day i we are making reset operation on is too slow. But do we need to wait for this for more than 2n days? Actually no because then we will get at most n score for waiting for 2n+1 days, but we can get the same (or the greater) score by doing the first reset operation on the first day.

Thus, we can solve this problem in O(nmin.

 **Bonus 1**Find the number of ways to achieve the maximum score.

 **Bonus 2**Solve this problem for the larger n.

[1917D - Yet Another Inversions Problem](../problems/D._Yet_Another_Inversions_Problem.md "Codeforces Round 917 (Div. 2)")

Author: [IgorI](https://codeforces.com/profile/IgorI "Grandmaster IgorI")   
 Preparation: [IgorI](https://codeforces.com/profile/IgorI "Grandmaster IgorI")   
 Editorial: [IgorI](https://codeforces.com/profile/IgorI "Grandmaster IgorI")   
 Official solution: [238743552](https://codeforces.com/contest/1917/submission/238743552 "Submission 238743552 by IgorI")   


 **Hint 1**How to count the number of inversions in the permutation of length n in \mathcal{O}(n \log n)?

 **Hint 2**Consider two arrays x_1, x_2, \ldots, x_k and \alpha x_1, \alpha x_2, \ldots, \alpha x_k for some positive \alpha. How does the number of inversions in one of them correspond to the number of inversions in the other of them?

 **Hint 3**Consider splitting array a into subarrays of the length k.

 **Hint 4**Let's say you have two arrays [11, 22, 44, \ldots, 11 \cdot 2^m] and [13, 26, 52, \ldots, 13 \cdot 2^m] of the same length. How many inversions are there in their concatenation [11, 22, 44, \ldots, 11 \cdot 2^m, 13, 26, 52, \ldots, 13 \cdot 2^m]?

 **Hint 5**Consider the merging process of arrays [11, 22, 44, \ldots, 11 \cdot 2^m] and [13, 26, 52, \ldots, 13 \cdot 2^m] into the sorted array (as in the merge sort).

 **Hint 6**What if the first elements of the arrays you concatenate are not 11 and 13 but some odd positive integers x and y? Merging processes for some pairs (x, y) look quite similar.

 **Hint 7**The number of inversions in the array [x, 2x, 4x, \ldots, 2^m x, y, 2y, 4y, \ldots, 2^m y] depends only on \lfloor \log_2(\frac{y}{x}) \rfloor and m. You don't need to think about rounding of \log_2(\frac{y}{x}) because x and y are odd in this problem. Also, m is the same for all merges.

 **Hint 8**Consider the following \mathcal{O}(n \log n) algorithm to find the number of inversions in the permutation: make a segment tree corresponding to this permutation and fill it with zeroes. For all i from 1 to n find j such that p_j=i, increase the j-th element of this segment tree by 1 and add the sum of elements on the right of the j-th element to the number of inversions. Improve this algorithm to count the number of inversions in array a assuming q=[0,1,\ldots,k-1].

 **Hint 9**The problem can be solved in \mathcal{O}(n \log n \min(\log n, k) + k \log k). The order of elements in q matters only on the inversions inside the blocks of length k you chosen in the hint 2.

 **Solution**Let's split the array a into subarrays of the length k. The relative order of the elements in each of them is the same (as in permutation q), so the number of inversions is the same, too. You can find the number of invesions in one of them as described in the hint 7. By multiplying this number by n, you count all the in-block inversions.

All the remaining inversions are formed by pairs of elements from the distinct blocks. You may assume that q=[0, 1, \ldots, k-1] now for simplicity: it won't change the number of such inversions.

Let's fix two elements x and y of p and count the number of inversions (i, j) such that a_i = x \cdot 2^{\alpha} and a_j = y \cdot 2^{\beta} for some \alpha and \beta. It is equivalent to counting the number of inversions in the array [x, 2x, 4x, \ldots, 2^mx, y, 2y, 4y, \ldots, 2^my].

Consider merging two arrays [x, 2x, 4x, \ldots, 2^mx] and [y, 2y, 4y, \ldots, 2^my] with x < y (x and y are odd) into one sorted subarray:

 * if \color{blue}{x} < \color{red}{y} < \color{blue}{2x}, then the resulting array would look like [\color{blue}{x}, \color{red}{y}, \color{blue}{2x}, \color{red}{2y}, \color{blue}{4x}, \color{red}{4y}, \ldots, \color{blue}{2^mx}, \color{red}{2^my}];
* if \color{blue}{2x} < \color{red}{y} < \color{blue}{4x}, then the resulting array would look like [\color{blue}{x}, \color{blue}{2x}, \color{red}{y}, \color{blue}{4x}, \color{red}{2y}, \color{blue}{8x}, \color{red}{4y}, \ldots, \color{blue}{2^{m-1}x}, \color{red}{2^{m-2}y}, \color{blue}{2^mx}, \color{red}{2^{m-1}y}, \color{red}{2^my}];
* if \color{blue}{4x} < \color{red}{y} < \color{blue}{8x}, then the resulting array would look like [\color{blue}{x}, \color{blue}{2x}, \color{blue}{4x}, \color{red}{y}, \color{blue}{8x}, \color{red}{2y}, \color{blue}{16x}, \color{red}{4y}, \ldots, \color{blue}{2^{m-1}x}, \color{red}{2^{m-3}y}, \color{blue}{2^mx}, \color{red}{2^{m-2}y}, \color{red}{2^{m-1}y}, \color{red}{2^my}];
* ...

You can see several blue elements in the beginning, followed by alternating blue and red elements, which are followed by several red elements. The number of blue elements in the beginning is equal to the number of red elements in the end and equal to the largest z such that 2^z x < y. Furthermore, this z is also limited by \log n + 1 because x and y are both positive integers less than 2n.

If x > y the situation is similar, but the order of colors is reversed.

Going back to inversions, we have some array [\color{blue}{x}, \color{blue}{2x}, \color{blue}{4x}, \ldots, \color{blue}{2^mx}, \color{red}{y}, \color{red}{2y}, \color{red}{4y}, \ldots, \color{red}{2^my}]. Inversions are formed by a large blue element and a small red element.

 * if x < y < 2x, then there are 0+1+2+\ldots+m=\frac{m(m+1)}{2} inversions;
* if 2x < y < 4x, the there are 0+0+1+2+\ldots+(m-1)=\frac{m(m+1)}{2} - m inversions;
* if 4x < y < 8x, the there are 0+0+0+1+2+\ldots+(m-2)=\frac{m(m+1)}{2} - m - (m-1) inversions;
* ...

For x > y the situation is similar, but we will start with 1+2+3+\ldots+m+(m+1)=\frac{(m+1)(m+2)}{2} inversions for y < x < 2y and we will add m, (m-1), \ldots terms instead of substracting them.

Well, now we can solve this problem in \mathcal{O}(n^2 \log n): enumerate pairs (x, y), find \log_2(\frac{y}{x}) and add some value to the answer.

Now let's add the inversion counting algorithm to solve this problem. Again, let's solve the problem for x < y first. Let's enumerate the value of y from 1 to 2n-1.

 * the x-s on the right of y should not be counted in now;
* each of the x-s on the left of y such that x < y adds \frac{m(m+1)}{2} to the answer;
* each of the x-s on the left of y such that 2x < y adds \frac{m(m+1)}{2} - m to the answer;
* each of the x-s on the left of y such that 4x < y adds \frac{m(m+1)}{2} - m - (m-1) to the answer;
* ...

We can maintain a segment tree to compute the sum of the values we should sum up. To update this segment tree let's additionally maintain \Theta(\log n) pointers that maintain the largest x such that 2^z x < y for each z from 0 to \lceil\log n\rceil.

The solution is similar for x > y pairs.

You should be careful when implementing this, because for small k at some moment there becomes 0 elements in the alternating segment of the blue-red array and you shouldn't substract anything further.

 **Bonus 1**You are also given s queries of the following two types:

 * Swap p_i and p_j
* Swap q_i and q_j.

Perform these queries and maintain the answer.

 **Bonus 2**You given three permutations p, q and r of lengths l_1, l_2, l_3 (of the first l_1, l_2 and l_3 positive integers correspondingly) and array a is defined as a[i \cdot l_2 \cdot l_3 + j \cdot l_3 + k] = p[i] \cdot 2^{q[j]} \cdot 2^{2^{r[k]}}. Find the number of inversions in it.

[1917E - Construct Matrix](../problems/E._Construct_Matrix.md "Codeforces Round 917 (Div. 2)")

Author: [_LeMur_](https://codeforces.com/profile/_LeMur_ "Master _LeMur_")   
 Preparation: [_LeMur_](https://codeforces.com/profile/_LeMur_ "Master _LeMur_")   
 Editorial: [_LeMur_](https://codeforces.com/profile/_LeMur_ "Master _LeMur_")   
 Official solution: [238752669](https://codeforces.com/contest/1917/submission/238752669 "Submission 238752669 by _LeMur_")   


 **Hint 1**Does solution exist when k is odd?

 **Hint 2**What can you understand when k = 2 or k = n^2 - 2?

 **Hint 3**How can we easily fill the matrix with 1s, such that all problem conditions are satisfied when k is divisible by 4?

 **Hint 4**How will you solve the problem when k = 6?

 **Hint 5**Try to merge ideas of Hint 3 and Hint 4 together.

 **Solution**First, let's note that when k is odd, the solution doesn't exist. It's obvious since in the solution the xors of all the rows are the same, it follows that the parity of the number of 1s in each row is the same, and let's remember that n is even, and from these conditions get that solution exists only when k is even.

Second, let's note that for k = 2 or k = n^2 - 2, the solution exists only for n = 2.

For all other cases, a solution always exists.

 * when k \equiv 0 \pmod{4}, we can fill \frac{k}{4} submatrices of size 2 \times 2.
* when k \equiv 2 \pmod{4}. Let's note that k \geq 6. Let's write 1 in the following positions: (1, 1), (1, 2), (2, 1), (2, 3), (3, 2), (3, 3). After this, we should fill the remaining (k - 6) ones, and let's note that (k - 6) \equiv 0 \pmod{4}. There are obvious \frac{n^2 - 16}{4} submatrices of size 2 \times 2, which aren't filled yet — outside the top left 4 \times 4 submatrix. If k < n^2 - 6, then we can fill as many of those 2 \times 2 submatrices as necessary, otherwise if k = n^2 - 6, we can also fill with 1s the following 4 positions too: (1, 3), (1, 4), (4, 3), (4, 4).
 **Bonus**Can you solve the problem for **odd** n?

[tourist](https://codeforces.com/profile/tourist "Legendary Grandmaster tourist") solved it!

[1917F - Construct Tree](../problems/F._Construct_Tree.md "Codeforces Round 917 (Div. 2)")

Author: [_LeMur_](https://codeforces.com/profile/_LeMur_ "Master _LeMur_")   
 Preparation: [_LeMur_](https://codeforces.com/profile/_LeMur_ "Master _LeMur_")   
 Editorial: [_LeMur_](https://codeforces.com/profile/_LeMur_ "Master _LeMur_")   
 Official solution: [238752543](https://codeforces.com/contest/1917/submission/238752543 "Submission 238752543 by _LeMur_")   


 **Hint 1**If a solution exists, then we can always construct a tree containing a diameter and edges incident to the vertex v (v is from diameter).

 **Hint 2**Try to consider the maximum of the given lengths.

 **Hint 3**What can we say when there exist two lengths with a sum greater than d?

 **Hint 4**If a solution exists, then there should be a subset of lengths with the sum equal to d.

 **Hint 5**Consider cases when there exists a subset of lengths containing the maximum length with the sum equal to d and doesn't.

 **Hint 6**Knapsack with bitset.

 **Solution**Let's consider the lengths in increasing order: l_1 \leq l_2 \leq \ldots \leq l_n. We will discuss some cases depending on the maximum length l_n:

 * If l_n + l_{n - 1} > d, then the solution doesn't exist since an arbitrary tree will have a diameter greater than d.
* There exists the subset of the given lengths l, such that the sum of the lengths of that subset is equal to d (for making a diameter) and l_n is in that subset. In this case, the solution always exists, since we can construct a tree for example in the following way: let's consider that the size of the found subset is equal to k, then we can connect the vertices from 1 to k + 1, such that the vertices i and i + 1 are connected by edge for each 1 \leq i \leq k and length(1, 2) = l_n. We have some remaining lengths that we haven't used yet, so we can add edges for each length incident to the vertex 2. Added edges will not increase the diameter, since l_n is greater than or equal to all the remaining edges and l_n + l_{n - 1} \leq d. To check if there exists a subset of lengths such that it contains l_n and the sum of elements in the subset is equal to d, can be easily done by the knapsack algorithm.
* Here, we need to find the subset of the given lengths l, such that the sum of the lengths of that subset is equal to d (for making a diameter and we also know that l_n can not be in that subset). Let's consider that diameter consisting of the vertices v_1, v_2, \ldots, v_k, such that v_i and v_{i + 1} are connected by edge for each 1 \leq i \leq k - 1. Now, we need to connect an edge with length l_n to the one vertex v' from diameter, such that both dist(v', v_1) + l_n < d and dist(v', v_k) + l_n < d. All the other not-used lengths we can also connect to the vertex v'. To check this, we should write knapsack but with two states: dist(v', v_1) and dist(v', v_k).

Knapsack can be done using bitset and the final complexity will be O(\frac{n \cdot d^2}{64}). You can also optimize this two times, since we know that the minimum of dist(v', v_1) and dist(v', v_k) is at most \frac{d}{2}.

