# Tutorial

Good mood and pure thoughts to everyone who comes here.

[1422A - Fence](../problems/A._Fence.md "Codeforces Round 675 (Div. 2)")  
Author [aropan](https://codeforces.com/profile/aropan "Grandmaster aropan")  
Solution [94875319](https://codeforces.com/contest/1422/submission/94875319 "Submission 94875319 by aropan")

 **Tutorial**
### [1422A - Fence](../problems/A._Fence.md "Codeforces Round 675 (Div. 2)")

A quadrilateral can be built when $ max (a, b, c, d) < a + b + c + d - max (a, b, c, d) $, that is, the sum of the minimum three numbers is greater than the maximum. To do this, you could choose $ max (a, b, c) $ or $ a + b + c - 1 $ as $ d $.

 

---

[1422B - Nice Matrix](../problems/B._Nice_Matrix.md "Codeforces Round 675 (Div. 2)")  
Author [andrew](https://codeforces.com/profile/andrew "Grandmaster andrew")  
Solution [94875245](https://codeforces.com/contest/1422/submission/94875245 "Submission 94875245 by AleXman111")

 **Tutorial**
### [1422B - Nice Matrix](../problems/B._Nice_Matrix.md "Codeforces Round 675 (Div. 2)")

Note, that if the value of $a_{1, 1}$ is equal to some number $x$, then values of $a_{n, 1}$, $a_{1, m}$ and $a_{n, m}$ must also be equal to this number $x$ by the palindrome property.

A similar property holds for all of the following elements $a_{x, y}$ ($a_{x, y}=a_{n - x + 1, y}=a_{1,m - y + 1}=a_{n - x + 1, m - y + 1}$), so the problem is reduced to finding the optimal number for each four of numbers (maybe less for some positions in matrix). This number is the median of these numbers (the average of the sorted set). The answer will be the sum of the differences between the median of the "four" and each number in the "four" for all "fours". 

 

---

[1422C - Bargain](../problems/C._Bargain.md "Codeforces Round 675 (Div. 2)")  
Author [aropan](https://codeforces.com/profile/aropan "Grandmaster aropan")  
Solution [94875502](https://codeforces.com/contest/1422/submission/94875502 "Submission 94875502 by aropan")

 **Tutorial**
### [1422C - Bargain](../problems/C._Bargain.md "Codeforces Round 675 (Div. 2)")

Let's count for each digit how many times it will be included in the final sum and in what place. Let's denote $ m $ as the length of the number $ n $. Consider the digit $ a_i $ at the position $ i $ in the number $ n $ ($ 1 \le i \le m $). If some part of the number to the left of the digit is removed, then the current digit will remain in its place  — and we add the number of ways to remove the subsegment to the left to the answer multiplied by the current digit $ i * (i - 1) / 2 \times 10 ^ {m - i} \times a_i $. If the segment to the right is deleted, then the place of the digit will change – $ (j + 1) \times 10^j \times a_i $ for all $ 0 \le j < m - i $, or $ \sum_ {j = 0 }^{m - i - 1} {(j + 1) \times 10 ^ j} \times a_i $. The $ j $ sum can be pre-calculated for all values.

 

---

[1422D - Returning Home](../problems/D._Returning_Home.md "Codeforces Round 675 (Div. 2)")  
Author [aropan](https://codeforces.com/profile/aropan "Grandmaster aropan")  
Solution [94875536](https://codeforces.com/contest/1422/submission/94875536 "Submission 94875536 by aropan")

 **Tutorial**
### [1422D - Returning Home](../problems/D._Returning_Home.md "Codeforces Round 675 (Div. 2)")

You can build a graph with vertices at the start point and all fast travel points. The distance between the vertices $(x_1, y_1)$ and $(x_2, y_2)$ is calculated as $ min (|x_1 - x_2|, |y_1 - y_2|)$. To avoid drawing all $m * (m + 1) / 2$ edges in the graph, note that for a pair of points $(x_1, y_1)$ and $(x_2, y_2)$ such that $|x_1 - x_2| \le |y_1 - y_2|$, if there is a point with coordinate $x_3$ such that it is between $x_1$ and $x_2$ ($min (x_1, x_2) \le x_3 \le max (x_1, x_2)$), then the distance between the first and second point will be equal to the sum of the distances between the first and third and between the third and second. In this case, the edge between the first and second points does not need to be drawn  – it will be unnecessary. It turns out that for each point of the graph it will be enough to draw the edges to the points nearest along the $x$ axis in both directions. Similarly for $y$. Next, in the constructed graph, we find the minimum distance from the starting point to each point of the graph $(x, y)$ and sum it up with the distance to the end point $(f_x, f_y)$, which is equal to $|x - f_x| + |y - f_y|$. Among all the distances, we choose the minimum one.

 

---

[1422E - Minlexes](../problems/E._Minlexes.md "Codeforces Round 675 (Div. 2)")  
Author [aropan](https://codeforces.com/profile/aropan "Grandmaster aropan")  
Solution [94875558](https://codeforces.com/contest/1422/submission/94875558 "Submission 94875558 by aropan")

 **Tutorial**
### [1422E - Minlexes](../problems/E._Minlexes.md "Codeforces Round 675 (Div. 2)")

Let's find the answer $ans_i$ for all suffixes, starting with the smallest in length. $ ans_n $ is equal to an empty string. Then if $ s_i = s_{i + 1} $ ($ 0 \le i + 1 < n $), then $ ans_i = min (s_i + ans_{i + 1}, ans_{i + 2}) $, and otherwise $ ans_i = s_i + ans_{i + 1} $. To quickly find minimum of two strings, they can be stored as "binary lifts"  – $ next_ {i, j} $ will be equal to the position in the string $s$, on which the $2 ^ j$ character $ ans_i $ will be located, and $ hash_{i, j} $  – hash from the prefix $ ans_i $ of length $ 2 ^ j $. Values for $ (i, j) $ can be obtained from $ (i, j-1) $ and $ (i + 2 ^ {j-1}, j-1) $. To restore the answer, $ next_ {i, j} $ will be enough for us, and for simplicity we can additionally store the length of each answer.

 

---

[1422F - Boring Queries](../problems/F._Boring_Queries.md "Codeforces Round 675 (Div. 2)")  
Author [andrew](https://codeforces.com/profile/andrew "Grandmaster andrew")  
Solution [94875580](https://codeforces.com/contest/1422/submission/94875580 "Submission 94875580 by aropan"), author's solution with persistent segment tree [94875295](https://codeforces.com/contest/1422/submission/94875295 "Submission 94875295 by andrew")

 **Tutorial**
### [1422F - Boring Queries](../problems/F._Boring_Queries.md "Codeforces Round 675 (Div. 2)")

In order to find the LCM of numbers on a segment, you can, for each prime number, find the maximum power with which it enters into any number on the segment and multiply the answer with this power. Let's calculate the LCM for primes less than $ \sqrt {MaxA} $ and greater than $ \sqrt {MaxA} $ separately using the segment tree.

There are $ k = 86 $ prime numbers less than $ \sqrt {MaxA} $. Let's store a sorted list of prime numbers with their maximum power in each subsegment of the tree. The union of two segments can be done in $ O (k) $. Then the construction of the entire tree can be done in $ O (n \cdot k) $. In order to answer the query, we split it into $ O (log (n)) $ subsegments of the segment tree and sequentially combine them in $ O (k) $.

For each number $ a_i $ in the array, there will be no more than one prime divisor $ p_i $ greater than $ \sqrt {MaxA} $. For a query, you need to find the product of unique numbers $ p_i $ on a segment. To do this, for each such simple $ p_i $ number, find $prev_i$  – the closest position to the left in the array of the same prime number (or $-1$ if there is no such number on the left). For a subsegment, we will store a sorted list of $ (prev_i, p_i) $ pairs, and also pre-calculate the product $ p_i $ for each prefix. Now, for each subsegment of the tree that will be included in the query $ (l, r) $, you need to select all such pairs for which $ prev_i <l $ and take product of $p_i$. Since the list is ordered, all these numbers will form a prefix. The prefix can be found using a binary search for $ log (n) $.

Total complexity $ O (n \cdot k + q \cdot log (n) \cdot k + q \cdot log^2 (n)) $, where $ k = \frac {\sqrt {MaxA}} {\ln \sqrt {MaxA}} $ (the number of primes up to the root).

