# Tutorial_(en)

We really hope you enjoyed the problems! We apologize again for the long queue and unrated round. Just for fun, here's how many of our problems were rejected:

 **Rejection Count**2A: 12

2B: 16

2C: 5

2D: 19

2E: 18

2F: 2

Total: 72

 
### [1372A - Omkar and Completion](../problems/A._Omkar_and_Completion.md "Codeforces Round 655 (Div. 2)")

Notice that since all elements must be positive, $k \neq 2k$. The most simple construction of this problem is to simply make all elements equal to $1$.

Solution: [86603804](https://codeforces.com/contest/1372/submission/86603804 "Submission 86603804 by 655editorial")

Idea: [MagentaCobra](https://codeforces.com/profile/MagentaCobra "Master MagentaCobra")

Preparation: [MagentaCobra](https://codeforces.com/profile/MagentaCobra "Master MagentaCobra"), [qlf9](https://codeforces.com/profile/qlf9 "Candidate Master qlf9") 

### [1372B - Omkar and Last Class of Math](../problems/B._Omkar_and_Last_Class_of_Math.md "Codeforces Round 655 (Div. 2)")

Short Solution: The two integers are $k$ and $n-k$, where $k$ is the largest proper factor of $n$.

Proof: Let the two integers be $k$ and $n-k$. Assume WLOG that $k \leq n-k$. Notice that this implies that $n - k \geq \frac n 2$.

We first claim that $LCM(k, n-k) = n-k < n$ if $k \mid n$, and we prove this as follows: if $k \mid n$, then there exists some integer $m$ such that $m \cdot k = n$. The integer $n-k$ can then be written as $(m-1) \cdot k$, which is a multiple of $k$. Thus, $LCM(k, n-k) = n-k $ if $k \mid n$.

We now show that $LCM(k, n-k) \geq n$ if $k \nmid n$. We show this by using the fact that $LCM(a, b) = b$ iff $a \mid b$, so if $k \nmid n$, $k \nmid n - k$, and so $LCM(k, n-k) \neq n-k$. And since $LCM(k, n - k)$ must be a multiple of both $k$ and $n - k$, it follows that $LCM(k, n-k) \geq 2 \cdot (n-k) \geq 2 \cdot \frac n 2 = n$.

We have now established that to minimize $LCM(k, n-k)$, $k$ must be a factor of $n$. And, since $LCM(k, n-k) = n-k$ when $k$ is a factor of $n$, we need to minimize $n-k$, so we must maximize $k$ by choosing it to be the largest proper factor of $n$ (i. e. the largest factor of $n$ other than $n$).

We then simply need to find $k$, the largest proper factor of $n$. If $p$ is the smallest prime dividing $n$, then $k = \frac n p$, so it suffices to find the smallest prime factor of $n$. We can do this by simply checking all values of $p$ such that $2 \leq p \leq \sqrt n$. If $n$ is not prime, then it must have a prime factor not exceeding $\sqrt{n}$. Furthermore, if we do not find a factor of $n$ between $2$ and $\sqrt n$, then $n$ must be prime so we simply get $p = n$ and $k = \frac n p = 1$.

We're given that $n \leq 10^9$, so $\sqrt n \leq 10^{\frac 9 2} < 10^5$. $t \leq 10$, meaning that we will check less than $10^6$ numbers, which runs well under the time limit.

 Solution: [86603838](https://codeforces.com/contest/1372/submission/86603838 "Submission 86603838 by 655editorial")Idea: [qlf9](https://codeforces.com/profile/qlf9 "Candidate Master qlf9")

Preparation: [qlf9](https://codeforces.com/profile/qlf9 "Candidate Master qlf9") 

### [1372C - Omkar and Baseball](../problems/C._Omkar_and_Baseball.md "Codeforces Round 655 (Div. 2)")

You need at most $2$ special exchanges to sort the permutation. Obviously, $0$ special exchanges are needed if the array is already sorted. Let's look into cases in which you need $1$ special exchange to sort the array.

Refer to i as a matching index if $a_i = i$. If there are no matching indices, then you can just use one special exchange to sort the entire thing. Otherwise, you can use the location of matching indices to determine whether you need more than $1$ special exchange. If all matching indices are located in some prefix of the permutation, you can sort the permutation with one special exchange. The same is true for a suffix. In other words, if you can choose a subarray in the permutation such that all elements contained in the subarray are NOT matching and the elements outside of this subarray are matching, then one special exchange is needed to sort the array.

Otherwise, you need $2$ special exchanges to sort the permutation. Let's prove why you do not need more than $2$ special exchanges. You can quickly check that you need at most $2$ special exchanges for all permutations of length $\leq 3$. For permutations of length $\geq 4$, I claim that we can perform $2$ special exchanges on the whole array; to show this it suffices to construct a permutation $p$ that has no matching indices with either the given permutation or the identity permutation $1, 2, \ldots, n$. We can do this as follows:

For simplicity, assume that $n$ is even. We will assign the numbers $\frac n 2 + 1, \frac n 2 + 2, \ldots, n$ to the first $\frac n 2$ positions of our permutation $p$ and the numbers $1, 2, \ldots, \frac n 2$ to the last $\frac n 2$ positions of $p$. This ensures that $p$ has no matching indices with the identity permutation. Then, for all integers $b$ such that their position $i$ in $a$ (i. e. the $j$ such that $a_j = b$) is in the appropriate half of $p$, assign $p_i = b$; assign other $b$ to arbitrary positions in the appropriate half of $p$. Finally, cyclically rotate each half of $p$ – this ensures that $p$ has no matching indices with $a$.

As an example, let's take $a = [3, 6, 2, 4, 5, 1]$. You can quickly check that this cannot be done in less than $2$ special exchanges. The construction of $p$ goes as follows:

First, we move all numbers to the proper half of $p$, so that $p = [4, 5, 6, 1, 2, 3]$.

Observing that $a_2 = 6$ and $a_6 = 1$, we set $p_2 = 6$ and $p_6 = 1$ then replace the remaining elements arbitrarily into the correct half, so we can get, for example, $p = [4, 6, 5, 2, 3, 1]$.

Finally, we cyclically rotate each half of $p$, obtaining $p = [5, 4, 6, 1, 2, 3]$, which has no matching indexes with either $a = [3, 6, 2, 4, 5, 1]$ or $[1, 2, 3, 4, 5, 6]$.

This can be extended to odd $n$ by first choosing some element other than $1$ and $a_1$ to be $p_1$ (this works for $n \geq 3$ and we must have $n \geq 5$ anyway in this case), and then running the same algorithm on the rest of $p$.

 Solution: [86603857](https://codeforces.com/contest/1372/submission/86603857 "Submission 86603857 by 655editorial")Idea: [MagentaCobra](https://codeforces.com/profile/MagentaCobra "Master MagentaCobra")

Preparation: [MagentaCobra](https://codeforces.com/profile/MagentaCobra "Master MagentaCobra"), [qlf9](https://codeforces.com/profile/qlf9 "Candidate Master qlf9") 

### [1372D - Omkar and Circle](../problems/D._Omkar_and_Circle.md "Codeforces Round 655 (Div. 2)")

First note that any possible circular value consists of the sum of some $(n+1)/2$ elements. Now let's think about how these $(n+1)/2$ values would look like in the circle. 

Let's consider any one move on index $i$. $a_i$ will be replaced with the sum of $a_{i-1}$ and $a_{i+1}$ (wrap around to index $1$ or $n$ if needed). Then let's consider making a move on $i+2$, since it will be adjacent to $i$ after the first move. Then its value will become $a_{i-1}+a_{i+1}+a_{i+3}$. This implies that alternating values play a role in the construction of the $(n+1)/2$ values contained in the final circular value. 

Now let's consider the final move when there's $3$ elements left in the circle. This is the only move that takes the sum of two adjacent elements in the initial circle. With this observation, we can achieve our final construction as follows:

Choose any $(n+1)/2$ elements in the initial circle such that exactly one pair of chosen numbers are adjacent to each other. The answer will be the maximum of the circular value over all possible constructions.

While there are ways involving complicated prefix sums/segment trees, the cleanest implementation is as follows: create an array whose values consists of $[a_1, a_3, ..., a_n, a_2, a_4, ..., a_{n-1}]$. Append this new array to itself to account for the circular structure. Now all you simply have to do is to find the maximum sum over all subarrays of length $(n+1)/2$. This can be done with sliding window in $O(n)$ time.

 Solution: [86603878](https://codeforces.com/contest/1372/submission/86603878 "Submission 86603878 by 655editorial")Idea: [MagentaCobra](https://codeforces.com/profile/MagentaCobra "Master MagentaCobra")

Preparation: [MagentaCobra](https://codeforces.com/profile/MagentaCobra "Master MagentaCobra"), [Tlatoani](https://codeforces.com/profile/Tlatoani "International Grandmaster Tlatoani") 

### [1372E - Omkar and Last Floor](../problems/E._Omkar_and_Last_Floor.md "Codeforces Round 655 (Div. 2)")

Let $dp_{l,r}$ be the answer for the columns from $l$ to $r$.

To solve $dp_{l,r}$, it is optimal to always fill some column within $l$ to $r$ to the max. Let's call this column $k$. The transition is thus $dp_{l,k-1} + ($ number of intervals that are fully within $l$ and $r$ and include $k)^2 + dp_{k+1,r}$. For every $dp_{l,r}$ loop through all possible columns to be $k$ and take the max. 

The answer is $dp_{1,m}$. 

The efficiency is $O(N \cdot M^3)$. There are $M^2$ dp states. For every state, you transition based on $M$ cases of $k$, and it takes $O(N)$ to determine how much the max column contributes.

Proof: Consider an optimal arrangement and the column with the most 1's in that arrangement. If there is an interval intersecting that column whose 1 isn't in that column, then moving the 1 to that column would not decrease (and possibly would increase) the quality of that arrangement. Thus, it's optimal for the column with the most 1s to have all the possible 1s that it can have.

 Solution: [86603896](https://codeforces.com/contest/1372/submission/86603896 "Submission 86603896 by 655editorial")Idea: [golions](https://codeforces.com/profile/golions "Candidate Master golions")

Preparation: [Tlatoani](https://codeforces.com/profile/Tlatoani "International Grandmaster Tlatoani"), [golions](https://codeforces.com/profile/golions "Candidate Master golions") 

### [1372F - Omkar and Modes](../problems/F._Omkar_and_Modes.md "Codeforces Round 655 (Div. 2)")

For both solutions, we must first make the critical observation that because the array is sorted, all occurrences of a value $x$ occur as a single contiguous block.

Solution 1

We will define a recursive function $determine(l, r)$ which will use queries to determine the array. We will also store an auxiliary list of previously returned query values $(x, f)$ – not the queries themselves, but only the values returned, so that we know that if $(x, f)$ is in the list then some previous query revealed that there were $f$ instances of $x$ in some query, and that we haven't already determined exactly where in the array those $f$ instances of $x$ are.

The execution of $determine(l, r)$ will proceed as follows: first, query the interval $[l, r]$, and let the result be $(x_1, f_1)$. 

If there exists some previous query result $(x_1, f_2)$ in our auxiliary list, then we will guarantee by details yet to be explained of $determine(l, r)$ that the interval that produced that result contained $[l, r]$ and that no part of those $f_2$ occurrences of $x_1$ occurred to the left of $[l, r]$. This allows us to exactly determine the location of those $f_2$ occurrences of $x_1$. We mark these occurrences in our answer, and then remove $(x_1, f_2)$ from our auxiliary list and do not add $(x_1, f_1)$. If $[l, r]$ is not entirely composed of occurrences of $x_1$, then the remaineder of the interval must be $[l, r']$ for some $r'$, and in that case we then call $determine(l, r')$.

If there does not exist some previous query result $(x_1, f_2)$ in our auxiliary list, then we add $(x_1, f_1)$ to the list and do as follows: while the exact locations of those $f_1$ occurrences of $x_1$ have not been determined, call $determine(l', l' + f_1 - 1)$, where $l'$ is the leftmost index in $[l, r]$ which has not yet been determined. Once those locations have been determined, call $determine(l', r)$.

To determine the entire array we simply call $determine(1, n)$. It is clear that this will correctly determine the array. We can see that it uses at most $4k$ queries as follows: for each block of integers of the same value represented by a query result $(x, f)$ that we add to our auxiliary list, we use $2$ queries to determine the exact location of those integers: one when added $(x, f)$ to the list, and one when removing $(x, f)$ from the list. 

This does not guarantee that the algorithm uses $2k$ queries because some calls of $determine$ can split a block of integers of the same value into two blocks. However, we can show that any blocks formed by splitting a single block into two cannot be further split as they occur either at the beginning or end of a queried interval (the full proof is left as an exercise to the reader), so each distinct value in the array will produce at most $2$ blocks, each of which will be determined in $2$ queries, meaning that the algorithm uses at most $4k$ queries.

Side note: you can in fact further show that the algorithm always uses at most $4k - 4$ queries and that there exists an array for all $k \geq 2$ which forces the algorithm to use $4k - 4$ queries.

Solution 2

Again, we will define a recursive function $determine(l, r)$, but this time we will only additionally maintain the currently known values in the answer.

The execution of $determine(l, r)$ will proceed as follows: first, query the interval $[l, r]$ and let the result be $(x, f)$. Then, find the largest integer $k$ such that $2^k \leq f$ and then for all $j$ in $[l, r]$ that are multiples of $2^k$, determine the value located at index $j$, either by querying $[j, j]$ or by using already known values.

By the definition of $k$, there will be either one or two such indexes $j$ such that the values at those indexes are equal to $x$.

If there is only one such index, let this index be $j_1$. Make two queries $[j_1 - 2^k + 1, j_1]$ and $[j_1, j_1 + 2^k - 1]$ and let the results of these queries be $(x_1, f_1)$ and $(x_2, f_2)$ respectively. We can show that at least one of $x_1$ and $x_2$ must be equal to $x$. If $x_1 = x$, then we see that the $f$ occurrences of $x$ must be precisely the interval $[j_1 - f_1 + 1, j_1 - f_1 + f]$. If $x_2 = x$, then we see that the $f$ occurrences of $x$ must be precisely the interval $[j_1 + f_2 - f, j_1 + f_2 - 1]$.

If there are two such indexes, let these indexes be $j_1$ and $j_2$ so that $j_1 < j_2$. Note that it must be true that $j_1 + 2^k = j_2$. Make a single query $[j_1 - 2^k + 1, j_2]$ and let the result be $(x_1, f_1)$. We can show that $x_1$ must be equal to $x$, so we can then conclude that the $f$ occurrences fo $x$ must be precisely the interval $[j_2 - f_1 + 1, j_2 - f_1 + f]$.

After the interval containing the $f$ occurrences of $x$ has been determined, mark these occurrences in our answer and then call $determine$ on the remaining not-fully-determined interval to the left if it exists and the remaining not-fully-determined interval to the right if it exists.

To determine the entire array we simply call $determine(1, n)$. It is clear that this will correctly determine the array. We can see that it uses at most $4k$ queries as follows: Each call to $determine$ finds all occurrences of a distinct value $x$. We will refer to the queries of single indexes $j$ that were multiples of some $2^k$ as $j$-queries. For each $x$, we perform the following queries other than $j$-queries: the first query in $determine$, and then either two additional queries if only one $j$-query was found to equal $x$, or a single additional query if two $j$-queries were found to equal $x$. This means that if we group each $j$-query with the value $x$ that it equaled, then we will have performed exactly $4$ queries for each $x$, and so the algorithm must therefore use exactly $4k$ queries.

 Solution 1: [86603917](https://codeforces.com/contest/1372/submission/86603917 "Submission 86603917 by 655editorial")Solution 2: [86603930](https://codeforces.com/contest/1372/submission/86603930 "Submission 86603930 by 655editorial")

Idea: [golions](https://codeforces.com/profile/golions "Candidate Master golions")

Preparation: [Tlatoani](https://codeforces.com/profile/Tlatoani "International Grandmaster Tlatoani"), [golions](https://codeforces.com/profile/golions "Candidate Master golions")

