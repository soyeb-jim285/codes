# Tutorial

Thanks for the participation!

 
### [1883A - Morning](../problems/A._Morning.md "Codeforces Round 905 (Div. 3)")

Let's represent our pin code as a set of digits $a$, $b$, $c$, $d$. Replace all $0$s with $10$ and notice that the answer is equal to $|a - 1|$ + $|b - a|$ + $|c - b|$ + $|d - c|$.

 
### [1883B - Chemistry](../problems/B._Chemistry.md "Codeforces Round 905 (Div. 3)")

Let's remember under what conditions we can rearrange the letters of a word to form a palindrome. This can be done if the number of letters with odd occurrences is not greater than $1$.

In our problem, it is sufficient to check that the number of letters with odd occurrences (denoted as $x$) is not greater than $k + 1$. Let's prove this fact.

If $x > k + 1$, then it is definitely impossible to obtain the answer, because with $k$ operations we cannot make the number of letters with odd occurrences not greater than $1$. On the other hand, we can simply remove the character with an odd number of occurrences on each removal iteration and decrease the number of odd occurrences. If there are no such characters, we can choose any character and remove it, thus having $1$ character with an odd occurrence.

 
### [1883C - Raspberries](../problems/C._Raspberries.md "Codeforces Round 905 (Div. 3)")

Let's notice that if $k = 2, 3, 5$, since these are prime numbers, the product of the numbers will be divisible by $k$ if any number in the array is divisible by $k$. From this, we can conclude that it is advantageous to perform operations only on one number.

If $k = 4$, we have several cases, and we need to take the minimum among them. Again, we can perform operations on one number and make it divisible by $4$, or we need to perform operations such that there are two even numbers in the array (there is a special case when $n = 1$). To have two even numbers, let's count the number of even numbers in the original array as $cnt$, and if $2 \leq n$, we can say that the answer is $\max(0, 2 - cnt)$.

 
### [1883D - In Love](../problems/D._In_Love.md "Codeforces Round 905 (Div. 3)")

Let's learn how to solve the problem for a fixed set. The claim is that if the answer exists, we can take the segment with the minimum right boundary and the maximum left boundary (let's denote these boundaries as $r$ and $l$). Therefore, if $r < l$, it is obvious that this pair of segments is suitable for us. Otherwise, all pairs of segments intersect because they have common points in the range $l \ldots r$.

Now let's maintain all our operations. For this, we can simply store a multiset of left and right boundaries. With the help of this multiset, we can find the minimum and maximum elements of any of these sets in $O(1)$. The addition and removal operations are also supported by this container.

 
### [1883E - Look Back](../problems/E._Look_Back.md "Codeforces Round 905 (Div. 3)")

Let's come up with a naive solution — we could go from left to right and multiply the element at index $i$ by $2$ until it is greater than or equal to the previous element. But this solution will take a long time, as the numbers can become on the order of $2^n$ during the operations.

Let's not explicitly multiply our numbers by $2$, but represent each element as the product $a_i \cdot 2^{x_i}$, where $x_i$ is the power to which we multiplied. Let's say we have calculated the value of $x_{i - 1}$, and now we want to calculate $x_i$. We have two cases:

* If $a_{i - 1} \leq a_i$: Then we can say that $x_i = x_{i - 1}$ and subtract $1$ until $x_i > 0$ and $a_{i - 1} \cdot 2 \leq a_i$.
* If $a_{i - 1} > a_i$: Then we can say that $x_i = x_{i - 1}$ and add $1$ until $a_i \cdot 2 < a_{i - 1}$.

 Note that we do not want to change the values of the array $a$ to avoid getting large numbers later, so we use additional variables for this.

 
### [1883F - You Are So Beautiful](../problems/F._You_Are_So_Beautiful.md "Codeforces Round 905 (Div. 3)")

Note that a subarray suits us if $a_l$ is the leftmost occurrence of the number $a_l$ in the array and $a_r$ is the rightmost occurrence of the number $a_r$ in the array. Let's create an array $b_r$ filled with zeros and set $b_r = 1$ if $a_r$ is the rightmost occurrence of the number $a_r$ in the array (this can be done using sets or dictionaries). Now we need to consider all suitable left boundaries and see how many suitable right boundaries we have on the suffix, either by precomputing a suffix sum or by simply maintaining a variable while traversing from left to right.

 
### [1883G2 - Dances (Hard Version)](../problems/G2._Dances_(Hard_Version).md "Codeforces Round 905 (Div. 3)")

Let's learn how to solve the problem for a fixed value of $a_1$. Notice that we can perform a binary search on the answer. Let's learn how to check if we can remove $k$ elements from both arrays such that $a_i < b_i$ holds for the remaining elements. It will be advantageous to sort both arrays, remove the $k$ largest elements from the first array, and the $k$ smallest elements from the second array, and then simply check if the condition holds for our pair of arrays. Thus, for a fixed value of $a_1$, we can solve the problem in $O(n \log n)$.

Let $f(i)$ be the answer to the problem for $a_1 = i$. We make the following observation - there exists a value $x$ such that: $f(1) = f(2) = \ldots = f(x) = f(x + 1) - 1 = f(x + 2) - 1 = \ldots = f(\inf) - 1$. Indeed, changing one element of array $a$ cannot worsen the answer by more than $1$. Then, we can use binary search to find this value $x$. The overall complexity is $O(n \log n \log m)$.

 
### [1887B - Time Travel](https://codeforces.com/contest/1887/problem/B "Codeforces Round 905 (Div. 1)")

Let $d_{v}$ denote the minimum number of moves required to reach vertex $v$. Initially, $d_{v} = \infty$ for all vertices except $1$, where $d_{1} = 0$. We will gradually mark the vertices for which we know the optimal answer. Similar to Dijkstra's algorithm, at each iteration, we will select the vertex $v$ with the minimum value of $d_{v}$ among the unmarked vertices. We will mark it and relax its neighbors: let $(v, u)$ be an edge belonging to record $x$, we will find the minimum index $i$ such that $d_{v} < i$ and $a_{i} = x$, then $d_{u} = \min(d_{u}, i)$. We can find $i$ using binary search, by saving the indices of occurrences in $a$ for each time moments. The time complexity of the solution is $O(m (\log k + \log n))$.

 Tutorial is loading... 
### [1887D - Split](https://codeforces.com/contest/1887/problem/D "Codeforces Round 905 (Div. 1)")

Let's fix element $i$. Let's find all intervals $[l, r]$ for which this element can be the maximum in the left part of a valid cut. Let $x_l$ be the nearest element to the left of $i$ greater than $a_i$, and $x_r$ be the nearest element to the right of $i$ greater than $a_i$. Then, for $i$ to be the maximum element in the left part of the cut, the following conditions must be satisfied: $$ \begin{cases} x_l < l \le i\\\ x_r \le r \end{cases} $$

But these conditions are obviously not enough, as we need to guarantee that all elements in the right part of the cut are greater than all elements in the left part of the cut. However, since $i$ is the maximum element in the left part of the cut, it is sufficient for all elements in the right part of the cut to be greater than $a_i$. Therefore, if $y_r$ is the nearest element to the right of $x_r$ smaller than $a_i$, then $r \le y_r$.

Thus, element $i$ can be the maximum element in the left part of the cut of interval $[l, r]$ $\Longleftrightarrow$ the following conditions are satisfied: $$ \begin{cases} x_l < l \le i\\\ x_r \le r < y \end{cases} $$

For each element $i$, we can find $x_l$, $x_r$, and $y$ in $\mathcal{O}(\log n)$ time. This can be done, for example, using a segment tree or std::set if the elements are iterated in ascending order.

It only remains to notice that if we consider the queries $[l, r]$ as points $(l, r)$, then each element $i$ makes all points in some rectangle good. Thus, the problem reduces to checking whether a point lies in one of the rectangles. This is a classic problem that can be solved using sweep line and, for example, a segment tree. We obtained a solution with a time complexity of $\mathcal{O}(n\log n)$.

 
### [1887E - Good Colorings](https://codeforces.com/contest/1887/problem/E "Codeforces Round 905 (Div. 1)")

Let's consider a bipartite graph with $n$ rows and $n$ columns. The cells will correspond to the edges. According to the problem statement, we need to find a pair of rows $\{ u, v \}$ and a pair of columns $\{ x, y \}$ such that cells $(u,x), (u,y), (v, x), (v, y)$ have different colors. Notice that in graph terms, this means that we need to find a cycle of length $4$ with different colors.

According to the problem statement, we have $2n$ edges with pairwise distinct colors in a graph with $2n$ vertices. This means that there must exist a cycle of length $2k$ with different colors. Let this cycle be $(v_1, v_2, \ldots, v_{2k})$. Mentally construct the edges $(v_2, v_{2k-1}), (v_3, v_{2k-2}), \ldots, (v_{k-1}, v_{k+2})$. These edges divide our cycle into $k-1$ cycles of length $4$ and are part of the complete bipartite graph. It is claimed that one of these cycles will definitely have different colors. To find it, we apply the binary search technique.

Ask for the color of the edge that divides this cycle approximately in half. Its color will either not match any of the edges from the left half or all of the edges from the right half. In each of these cases, we managed to find a cycle with half the length. After $\lceil log_2(k-1) \rceil \le 10$ queries, we will find a cycle of length $4$ with different colors, and therefore the desired set of four cells.

 
### [1887F - Minimum Segments](https://codeforces.com/contest/1887/problem/F "Codeforces Round 905 (Div. 1)")

Let's consider a sequence $a_1, a_2, \ldots, a_n$. Let $nxt_i$ be the smallest $j > i$ such that $a_j = a_i$, or $n+1$ if such $j$ does not exist. It is claimed that the characteristic of the sequence can be uniquely determined from the values of $nxt_1, nxt_2, \ldots, nxt_n$. Let's write down the conditions on $nxt_i$ that we can obtain from the characteristic $r_1, r_2, \ldots, r_n$: 

1. $nxt_n=n+1$.
2. If $r_i=r_{i+1}$, then $nxt_i \in [i+1, r_i]$, since the number $a_i$ appears on the subsegment $[i+1,r_i]$.
3. If $r_i < r_{i+1}$, then $nxt_i = r_{i+1}$, since we need to extend the segment to the nearest occurrence of the number $a_i$.
4. For each $i > r_1$, there exists $j$ such that $nxt_j=i$, since the first occurrence of each number is on the subsegment $[1, r_1]$.
5. All $nxt_i \le n$ are distinct, since each element can have at most one nearest equal element on its left.

 These conditions are sufficient, as they can be used to obtain the characteristic equal to $r$.We want to construct the array $nxt$ that satisfies these conditions.

We have some values of $nxt_i$ that we already know, as well as values of $nxt_i$ that should lie in the intervals $[i+1,r_{i+1}]$. Note that the left and right boundaries of these intervals are non-decreasing, so if condition 4 did not exist, we could greedily assign values to $nxt_i$, moving through the intervals in descending order and assigning the largest unused value of $nxt_i$ that lies in the interval.

Let's fix $k$ as the number of intervals in which we will choose the number $n+1$. Obviously, it is more advantageous to place $n+1$ in the $k$ rightmost intervals, as all intervals in which $n+1$ can be placed are nested within each other. After that, we can greedily assign the largest possible values of $nxt_i$ to the intervals from right to left, thus obtaining an answer with the maximum number of $nxt_i \in [r_1+1, n]$ for a given $k$. If we manage to cover all numbers from $[r_1+1, n]$, then we have found a suitable sequence $nxt$.

Thus, we have a solution with $O(n^2)$ complexity: we iterate over $k$ and solve it greedily. Let's learn how to optimize it.

Let's find the smallest $k$ for which there is an answer without considering condition 4. Note that as $k$ increases, the number of $nxt_i \in [r_1+1, n]$ obtained by the greedy algorithm does not increase, so it is sufficient to run it for the minimum $k$ and check if condition 4 is satisfied for the obtained greedy algorithm answer for this $k$.

After we find the array $nxt$, it is easy to obtain the array $a$ from it.

