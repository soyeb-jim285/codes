# Tutorial_(en)

Thanks for the participation!

[1754A - Technical Support](../problems/A._Technical_Support.md "Codeforces Round 829 (Div. 2)") was authored by [KAN](https://codeforces.com/profile/KAN "Legendary Grandmaster KAN") and prepared by [DishonoredRighteous](https://codeforces.com/profile/DishonoredRighteous "Grandmaster DishonoredRighteous")

[1754B - Kevin and Permutation](../problems/B._Kevin_and_Permutation.md "Codeforces Round 829 (Div. 2)") was authored and prepared by [KLPP](https://codeforces.com/profile/KLPP "International Master KLPP")

[1753A1 - Make Nonzero Sum (easy version)](https://codeforces.com/contest/1753/problem/A1 "Codeforces Round 829 (Div. 1)") and [1753A2 - Make Nonzero Sum (hard version)](https://codeforces.com/contest/1753/problem/A2 "Codeforces Round 829 (Div. 1)") were authored and prepared by [Artyom123](https://codeforces.com/profile/Artyom123 "Grandmaster Artyom123")

[1753B - Factorial Divisibility](https://codeforces.com/contest/1753/problem/B "Codeforces Round 829 (Div. 1)") was authored and prepared by [sevlll777](https://codeforces.com/profile/sevlll777 "Master sevlll777")

[1753C - Wish I Knew How to Sort](https://codeforces.com/contest/1753/problem/C "Codeforces Round 829 (Div. 1)") was authored and prepared by [TheOneYouWant](https://codeforces.com/profile/TheOneYouWant "International Master TheOneYouWant")

[1753D - The Beach](https://codeforces.com/contest/1753/problem/D "Codeforces Round 829 (Div. 1)") was authored by [Tikhon228](https://codeforces.com/profile/Tikhon228 "Master Tikhon228") and prepared by [Ormlis](https://codeforces.com/profile/Ormlis "Legendary Grandmaster Ormlis")

[1753E - N Machines](https://codeforces.com/contest/1753/problem/E "Codeforces Round 829 (Div. 1)") was authored and prepared by [Tikhon228](https://codeforces.com/profile/Tikhon228 "Master Tikhon228")

[1753F - Minecraft Series](https://codeforces.com/contest/1753/problem/F "Codeforces Round 829 (Div. 1)") was authored and prepared by [teraqqq](https://codeforces.com/profile/teraqqq "International Grandmaster teraqqq")

 
### [1754A - Technical Support](../problems/A._Technical_Support.md "Codeforces Round 829 (Div. 2)")

Let's process each character of the string from left to right and store the number of unanswered questions $cnt$. Initially this value equals to zero. Consider the $i$-th character of the string. If it equals to "Q", increase $cnt$ by one. If it equals to "A", decrease $cnt$ by one. If $cnt$ has become negative, it means that some of the questions was answered several times. In this case let's assign zero to $cnt$.

If $cnt$ will be equal to zero after processing all string, then all questions were answered, and the answer is "Yes". Otherwise, the answer is "No".

Time complexity: $\mathcal{O}(n)$ for each test case.

 
### [1754B - Kevin and Permutation](../problems/B._Kevin_and_Permutation.md "Codeforces Round 829 (Div. 2)")

Let's prove that the minimum difference of consecutive elements is not greater than $\lfloor \frac{n}{2} \rfloor$. To do it, let's prove that larger value is not achievable. Consider element of a permutation with value $\lfloor \frac{n}{2} \rfloor + 1$. It will have at least one adjacent element in the constructed permutation. And the maximum absolute difference of this element with the adjacent elements is at most $\lfloor \frac{n}{2} \rfloor$.

Now we will construct the permutation with the minimum absolute difference of consecutive elements equals to $\lfloor \frac{n}{2} \rfloor$. Assign $x = \lfloor \frac{n}{2} + 1 \rfloor$. Now we can construct such permutation: $x, 1, x + 1, 2, x + 2, \ldots$. It's easy to see that the minimum absolute difference of consecutive elements equals to $x - 1$.

 
### [1753A1 - Make Nonzero Sum (easy version)](https://codeforces.com/contest/1753/problem/A1 "Codeforces Round 829 (Div. 1)")

If the sum of all elements of the array is odd, the partitions does not exist because the partition does not affect the parity of the sum. Otherwise the answer exists.

Let's build such construction. As the sum of all elements is even, $n$ is even too. Consider pairs of elements with indices $(1, 2)$, $(3, 4)$, ..., $(n - 1, n)$. Consider the pair $(2i - 1, 2i)$. If $a_{2i - 1} = a_{2i}$, add the segment $[2i - 1, 2i]$ to the answer. In this case the alternating sum of elements of this segment will be equal to $a_{2i - 1} - a_{2i} = 0$. Otherwise we will add two segments to the answer: $[2i - 1, 2i - 1]$ and $[2i, 2i]$. The sum of the first segment is $a_{2i - 1}$, and the sum of the second segment is $a_{2i}$. The sum of two sums will be equal to zero. So the sum of all alternating sums will be equal to zero.

 
### [1753A2 - Make Nonzero Sum (hard version)](https://codeforces.com/contest/1753/problem/A2 "Codeforces Round 829 (Div. 1)")

If the sum of all numbers in the array is odd, then splitting is impossible, because splitting does not affect the evenness of the sum. Otherwise, we will build the answer constructively. Suppose we have considered some kind of array prefix. Let's keep going until we get exactly $2$ non-zero numbers.

We want to make these two non-zero numbers add up to $0$. Then if on the last segment the sum is already equal to $0$, then just take it as an answer. Otherwise, consider a few cases: 

* If the length of the segment is even, then we simply separate the last number (it will be non-zero) into a separate segment. Then its sign will change and in total these two numbers will give $0$.
* The same can be done if the length of the segment is odd, but its first element is equal to $0$. Separate this $0$ and repeat the algorithm above.
* If the length of the segment is odd and the first element is not equal to $0$, then we separate it. Then the value of the first element will not change, and the last will change to the opposite, and then their sum will be equal to $0$.
 
### [1753B - Factorial Divisibility](https://codeforces.com/contest/1753/problem/B "Codeforces Round 829 (Div. 1)")

Let's create an array $[cnt_1, cnt_2, \ldots, cnt_x]$ where $cnt_i$ equals to number of elements equals to $i$ in the initial array.

Note that $a_1!\ + a_2!\ +\ \ldots\ +\ a_n!$ equals to sum of $k! \cdot cnt_k$ over all $k$ from $1$ to $x - 1$, $cnt_x$ does not affect anything because $x!$ divides $x!$ itself. We have to check if this sum is divisible by $x!$.

Suppose there exists some $k < x$ such that $cnt_k \geq k + 1$. In this case we can make two transformations: $cnt_k \mathrel{-}= (k + 1); cnt_{k+1} \mathrel{+}= 1$ and the sum of $k! \cdot cnt_k$ will not change because $(k+1) \cdot k! = (k+1)!$.

Let's perform this operation until it is possible for all numbers from $1$ to $x - 1$. After all operations the sum of $k! \cdot cnt_k$ will not change and for each $k < x$ the inequality $cnt_k \leq k$ will be satisfied because if $cnt_k \geq k+1$ we could perform an operation with this element.

Let's see what is the maximum value of sum of $k \cdot cnt_k$ over all $k$ from $1$ to $x - 1$ after all operations. We know that $cnt_k \leq k$ for all $k$, so the maximum value of the sum is the sum of $k \cdot k!$ over all $k$.

Note that $k \cdot k! = ((k + 1) - 1) \cdot k! = (k + 1) \cdot k! - k! = (k + 1)! - k!$.

It means that the sum of such values over all $k$ from $1$ to $x - 1$ equals to $(2! - 1!) + (3! - 2!) + \ldots + (x! - (x-1)!)$. Each factorial from $2$ to $x - 1$ will be added and subtracted from the sum. So the result is $x! - 1$.

So the only one case when this sum is divisible by $x!$ is when the sum equals to $0$. It means that $cnt_k$ equals to zero for all $k$ from $1$ to $x - 1$ after performing all operations.

Time complexity: $\mathcal{O}(n + x)$.

 
### [1753C - Wish I Knew How to Sort](https://codeforces.com/contest/1753/problem/C "Codeforces Round 829 (Div. 1)")

Let the number of zeros in the array be $g$. Let $dp[k]$ be the expected number of swaps needed when there are $k$ zeros in the first $g$ positions. Then, we know that $dp[g] = 0$, and we can write down the recurrence equations for $dp[k]$ by considering the case where some element equals to one from the first $g$ positions and some element equals to zero from the last $(n-g)$ positions are swapped.

This is the only case where the $dp$ value will change. Thus, our recurrence is as follows.

Let $p = \frac{2 \cdot (g-k) \cdot (g-k)}{n \cdot (n-1)}$. Then $dp[k] = 1 + dp[k] \cdot (1 - p) + dp[k+1] \cdot p$.

The answer is $dp[o]$, where $o$ is the initial number of zeros in the first $g$ positions.

 
### [1753D - The Beach](https://codeforces.com/contest/1753/problem/D "Codeforces Round 829 (Div. 1)")

Let's paint our field in a chess coloring. 

Now let's consider our operations not as the movement of sunbeds, but as the movement of free cells. Then, a free cell adjacent to the long side of the sunbed can move to a cell of the sunbed that is not adjacent to this one, for $p$ units of discomfort. A free cell adjacent to the short side of the sunbed can move to a cell of the sunbed that is not adjacent to this one, for $q$ units of discomfort. Note that in this cases, the free cell does not change its color (in chess coloring).

Since each sunbed should occupy one black and one white cell, then some two free cells of different colors should move to neighboring ones using operations.

It can be shown that in the optimal answer we use no more than one operation with each sunbed.

Then, for each position, looking at the adjacent sunbeds, we will determine where the free cell can move if it turns out to be in this position. Let's construct a weighted oriented graph on the cells of the field. Edge $(x_1, y_1) \rightarrow (x_2, y_2)$ of weight $w$ (equal to $p$ or $q$) will mean that there is a sunbed such that by moving it with an operation that brings $w$ discomfort, we will free the cell $(x_2, y_2)$ and block the cell $(x_1, y_1)$. 

Note that the graphs on the black and white cells are not connected. Let's run Dijkstra's algorithm from all free cells at once. Then, for each cell $d_{x, y}$ - the minimum distance in this graph from a free cell is equal to the minimum amount of discomfort that must be used to free this cell. 

The answer to the problem is the minimum for all pairs $(x_1, y_1)$, $(x_2, y_2)$ neighboring cells, $d_{x_1, y_1} + d_{x_2, y_2}$. Or $-1$ if there is no pair of adjacent cells, both of which are reachable from the free ones.

Asymptotics of the solution: $\mathcal{O}(n m \cdot\log{(nm))}$

 
### [1753E - N Machines](https://codeforces.com/contest/1753/problem/E "Codeforces Round 829 (Div. 1)")

Let $C$ bi the maximum value of the resulting product before any movements. The problem statement says that it is guaranteed that $C \le 2 \cdot 10^9$.

* Observation 0 — after each movements the value of the resulting product is not greater than $\frac{C^2}{4}$.
* Observation 1 — each machine of kind $(*, a_i)$ should be moved to the end of the sequence, and each machine of kind $(+, a_i)$ — to the beginning of the sequence, and the order of movements does not make sense.
* Observation 2 — there are at most $\log_2{C}$ non-trivial machines of kind $(*, a_i)$ (such machines that $a_i \neq 1$). We will need some more strong observation for machines of kind $(*, a_i)$, but this will be useful too.
* Observation 3 — if there are two machines $(*, a_i)$, $(*, a_j)$, where $i < j$ and $a_i >= a_j$, then in optimal answer machine $j$ may be moved if and only if machine $i$ is moved too. It is true because we could increase the answer otherwise, by moving machine $i$ instead of machine $j$.

The last two observations says that there are not many subsets of machines of kind $(*, a_i)$ (that satisfies the property from observation 3). Let's say that there are $F(C)$ such subsets, in the end of the editorial we will estimate this value.

Let's pick out subsegments of machines of kind $(+, a_i)$ between machines of kind $(*, a_i)$, sort them and count prefix sums. There will be not more than $\log_2{C} + 1$ such segments. In the optimal answer some maximums will be moved from each of the segments.

Let's fix some subset of machines of kind $(*, a_i)$, that will be moved to the end, and count the current value of the output product. Consider some element $(+, a_j)$ in the array. Let the product of machines $(*, a_i)$ to the left of it be $lmul$, and to the right of it — to be $rmul$. Now if we move this element to the beginning of the array, the value of the resulting product will increase by $\frac{lmul-1}{lmul} \cdot rmul \cdot a_j$. Let's call this $profit_j$. Now we have to find the sum of some numbers of maximum values $profit_j$.

Let's use binary search to find some "critical" value $profit$: such value that all elements $profit_j \ge profit$ will be moved to the beginning. $profit_j$ of each element is not greater than $C^2/4$. Inside binary search we have to iterate over all segments of elements $(+, a_i)$ and find the number of elements with $profit_j \ge profit$ inside this segment using binary search. We have to check if we can to move the selected amount of elements to the beginning of the array to understand how to move borders of the external binary search.

After we find the critical value $profit$, let's iterate over all segments $(+, a_i)$ and add the sum of elements that are $profit_j \ge profit$ to the answer. Separately let's consider elements with $profit_j$ = $profit - 1$. We could move some of them to the beginning too. Let's update the answer with this value.

Time complexity: $O(F(C) \log^3_2(C) + n \cdot \log_2(n))$. It should be noted that this estimate is actually higher than in fact.

Let's estimate the value $F(C)$ now:

* Consider some sequence $b_1, b_2, \dots, b_k$, such that $b_1 \cdot b_2 \cdot$ $\dots$ $\cdot b_k \le C$ and $2 \le b_i$
* Sort it by ascending, $b_1 \le b_2 \le \dots \le b_k$ — the product of elements will not change and the number of "interesting" subsets will not become smaller.
* Replace all the smallest elements of the sequence with $2$, the second minimums with $3$ and so on. If there are smaller number of elements equals to $x$ than elements equals to $y$ and $x < y$, let's swap their numbers. Now the number of interesting subsets is not changed, $b_1 \cdot b_2 \cdot$ $\dots$ $\cdot b_k$ is not increased. The sequence looks like $2, 2, \dots, 3, \dots, 4, \dots$ now.
* The number of interesting subsets in the new sequence equals to $(cnt_2 + 1) \cdot (cnt_3 + 1) \cdot \dots$, where $cnt_x$ is the number of elements if sequence equals to $x$.
* (Let's run the code that will brute-force over all sequences of such kind and see that the number of interesting subsets is $4608$, which is achieved on sequence $2, 2, 2, 3, 3, 4, 4, 5, 6, 7, 8, 9, 10, 11$)
* Let's continue estimating this value "fairly": the elements of the sequence do not exceed $12$ because $13! > C$. Let's replace each number with a prime number corresponding to it by order: $p_2 = 2, p_3 = 3, p_4 = 5, p_5 = 7, p_6 = 11, ...$ and replace all elements $x$ with $p_x$. The product of elements will increate in at most $\max\limits_{x}{((\frac{p_x}{x})^{\log_x(C)})}$ times, so the product will not exceed $\max\limits_{x}{(C^{\log_x{(p_x)}})}$. It is easy to check that the maximum is achieved in $x=6$, so the product is not greater than $C^{\log_6{11}}$ $\le 3 \cdot 10^{12}$.
* The number of interesting subsets of our sequence does not exceed the number of divisors of received numbers that can be estimated as $(3 \cdot 10^{12})^{(1/3)}$ $\le 15000$
 
### [1753F - Minecraft Series](https://codeforces.com/contest/1753/problem/F "Codeforces Round 829 (Div. 1)")

Let's formalize the problem condition. It is required to calculate the number of squares $s$ in the table for which we have inequality $A+B \geq T$, where $A$ is a $\text{MEX}$ of positive integers in the sqare and $B$ is a $\text{MEX}$ of absolute values of all negative integers in the square. Then we denote cost of a square as $A+B$. Note that when the square is expanded, its value cannot decrease.

Let's fix the diagonal that contains the upper left and lower right sides of the square. Now, with a fixed lower right cell, we want to maintain the upper left cell of the square that is maximally removed from it so that its cost does not exceed $T-1$. Note that this upper-left boundary can only shift in the direction of moving the right lower one, which means we can use the two pointers technique.

We will also need to maintain a set of numbers that are contained in a square. To do this, we will process each cell separately, which are added and removed from our square. Note that for each cell there are no more than $\min \{ N, M \}$ diagonals on which it is possible to construct a square containing this cell, and also note that due to the structure of our solution for each such diagonal, our cell will be added to the set no more than $1$ time. Thus, the total number of additions of cells to our set does not exceed $M N \cdot \min \{N, M \}$, and accordingly the total number of additions of numbers to the set does not exceed $K \cdot \min \{ N, M \}$.

We will also need to find out the $\text{MEX}$ of all positive integers in the square, as well as the $\text{MEX}$ of absolute values of negative integers in the square. Here we need to make another observation about our algorithm. The number of $\text{MEX}$ queries will not exceed $2MN$. That is, you can use the square roots technique to adding and removing integers in $O(1)$ time, and find out the $\text{MEX}$ values in $O(\sqrt K)$ time.

To summarize, our algorithm will work in asymptotic time:

$$ O((NM + K) \cdot \min \{ N, M \} + NM \sqrt{K}) $$

As the author of the problem, I want to apologize for the very low TL in this problem. Due to the specificity of the task, it was difficult to cut off the wrong solutions. The solution described above, if implemented correctly, fits into TL with a time reserve at least $1$ second. But if suddenly you didn't write it efficiently enough and you have TL, then you can try using the following tips:

* Sort the numbers in each cell. This will help to better in the cache. It does benefit buffering provided by a cache.
* It is more accurate to implement your algorithm without making unnecessary MEX queries.
* Use bit magic and implement the $\text{MEX}$ search in $O(\omega + K/\omega)$ time where $w=64$ is machine word size. Such a solution may have a better time-constant and it is better to be vectorized
