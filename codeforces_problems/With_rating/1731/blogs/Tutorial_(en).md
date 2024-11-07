# Tutorial_(en)

**UPD**: Code links are working now

[1731A - Joey Takes Money](../problems/A._Joey_Takes_Money.md "Codeforces Round 841 (Div. 2) and Divide by Zero 2022")

Idea: [s_jaskaran_s](https://codeforces.com/profile/s_jaskaran_s "Candidate Master s_jaskaran_s")

 **Hint**What is the maximum value of a+b when a⋅b=x?

 **Solution**
### [1731A - Joey Takes Money](../problems/A._Joey_Takes_Money.md "Codeforces Round 841 (Div. 2) and Divide by Zero 2022")

If we take two elements $a_1$ and $a_2$ and do the operation on it as $a_1 \cdot a_2 = x \cdot y$, then it is easy to observe that $x + y$ will attain its maximum value when one of them is equal to $1$. So, the solution for this is $x = 1$ and $y = a_1 \cdot a_2$.

Let $n$ be the total number of elements and $P$ ($P = a_1 \cdot a_2 \cdot \ldots \cdot a_n$) be the product of all elements.

Now if we do the above step for every pair of elements, then the maximum value of the sum is achieved when $a_1 = 1$, $a_2 = 1$, $\dots$, $a_{n-1} = 1$ and $a_n = P$.

In the final array, assign $P$ to $a_1$ and assign $1$ to all the remaining elements $a_2, a_3, \dots a_n$.

So, our answer is simply $P + n - 1$ multiplied by $2022$, of course.

Time complexity: $O(n)$.

 **Code**[186975476](https://codeforces.com/contest/1731/submission/186975476 "Submission 186975476 by adedalic")

[1731B - Kill Demodogs](../problems/B._Kill_Demodogs.md "Codeforces Round 841 (Div. 2) and Divide by Zero 2022")

Idea: [s_jaskaran_s](https://codeforces.com/profile/s_jaskaran_s "Candidate Master s_jaskaran_s")

 **Hint**Check which direction is optimal for the next 2 steps and why? 

 * 2 times Right?
* 2 times Down?
* 1 time Right and 1 time Down?
* 1 time Down 1 time Right?
 **Solution**
### [1731B - Kill Demodogs](../problems/B._Kill_Demodogs.md "Codeforces Round 841 (Div. 2) and Divide by Zero 2022")

To kill the maximum number of demodogs, El can travel in zigzag fashion, i.e. from $(1,1)$ to $(1,2)$ to $(2,2)$ and so on. Thus the answer would be the sum of elements at $(1,1)$, $(1,2)$, $(2,2)$ $\dots$ $(n,n)$. i.e. the answer is $$\sum_{i = 1}^n{i \cdot i} + \sum_{i = 1}^{n-1}{i (i + 1)} = \frac{n(n + 1)(4n - 1)}{6}$$.

And the answer you need to print is $$2022 \frac{n(n + 1)(4n - 1)}{6} = 337 \cdot n(n + 1)(4n - 1) \pmod{10^9 + 7}$$

Proof:

Let $kills_{i,j}$ be the maximum number of kills of all possible paths from $(1,1)$ to $(i,j)$.

$kills_{n-1,n-1} \geq kills_{i,n - 1}$ + number of demodogs from $(i + 1,n - 1)$ to $(n - 1,n - 1)$ $( \forall i \hspace{1.5mm} \in \hspace{1.5mm} [1, n - 2])$.

$$kills_{n-1,n-1} \geq kills_{i,n - 1} + \sum_{j = i + 1}^{n - 1}{j \cdot (n - 1)}$$

$$kills_{n-1,n-1} \geq kills_{i,n - 1} + \frac{(n - 1 - i)((i + 1)(n - 1) + (n - 2 - i)(n - 1))}{2} \text{ (sum of A.P.)}$$

$$kills_{n-1,n-1} \geq kills_{i,n - 1} + \frac{(n - 1 - i)(n - 1)^2}{2} \text{ (1)}$$

Let $killsZ$ be the number of kills if El travels in zigzag fashion, i.e. she goes to $(n,n)$ after passing through $(n - 1,n - 1)$: $$killsZ_{n,n} = kills_{n - 1,n - 1} + n(n - 1) + n \cdot n$$

Let $killsNZ$ be the maximum number of kills If El goes to $(n,n)$ after passing through $(i,n)$ for some $i$ in range of $[1 \dots n - 1]$, i.e. El goes from $(1,1)$ to $(i,n - 1)$ to $(i,n)$ to $(n,n)$: $$killsNZ_{n,n} = kills_{i,n - 1} + \text{no of demigods from } (i,n)\text{ to }(n,n)$$

$$killsNZ_{n,n} = kills_{i,n - 1} + \sum_{j = i}^{n}{j \cdot n}$$

$$killsNZ_{n,n} = kills_{i,n - 1} + \frac{(n + 1 - i)(n + i)n}{2}$$

$$killsZ_{n,n} - killsNZ_{n,n} = kills_{n - 1,n - 1} + n(n - 1) + n \cdot n - kills_{i,n - 1} - \frac{(n + 1 - i)(n + i)n}{2} \text{ from $(1)$}$$

$$killsZ_{n,n} - killsNZ_{n,n} \geq kills_{i,n - 1} + \frac{(n - 1 - i)(n - 1)^2}{2} + n(n - 1) + n \cdot n - kills_{i,n - 1} - \frac{(n + 1 - i)(n + i)n}{2}$$

$$killsZ_{n,n} - killsNZ_{n,n} \geq \frac{2 n^2 - 3 n - n \cdot i - i - 1}{2}$$

$$killsZ_{n,n} - killsNZ_{n,n} \geq 0$$ since $2n^2 - 3 n - n \cdot i - i - 1 \geq 0$ for all $i \in \hspace{1.5mm} [1, n - 2]$.

In other words, $killsZ_{n,n} \geq killsNZ_{n,n}$ Therefore zigzag path guarantees maximum number of demodog kills.

Now, the last thing was taking the modulus. Modulus should always be taken after every multiply operation to avoid the overflow. You can refer to modular arithmetic for more details.

And the main reason we told you to multiply the answer by $2022$ is that we needed to divide it by $6$. For division, we have to take inverse modulo in modular arithmetic. So, in order to avoid that, we gave you a multiple of $6$, which is $2022$.

 **Code**[186975620](https://codeforces.com/contest/1731/submission/186975620 "Submission 186975620 by adedalic")

[1731C - Even Subarrays](../problems/C._Even_Subarrays.md "Codeforces Round 841 (Div. 2) and Divide by Zero 2022")

Idea: [ka_tri](https://codeforces.com/profile/ka_tri "Candidate Master ka_tri")

 **Hint 1**What are the numbers with the odd number of divisors?

 **Hint 2**How many numbers with the odd number of divisors can be there in the range 2⋅105?

 **Hint 3**Try using prefix XOR, iterating through all such numbers.

 **Solution**
### [1731C - Even Subarrays](../problems/C._Even_Subarrays.md "Codeforces Round 841 (Div. 2) and Divide by Zero 2022")

Let's calculate the number of subarrays whose $\operatorname{XOR}$ sum has an odd number of divisors and subtract them from total no of subarrays. 

Note: A number has an odd number of divisors only if it is a perfect square. So we have to calculate number of subarray having $\operatorname{XOR}$ sum a perfect square.

For the given constraints for elements in the array, the maximum possible $\operatorname{XOR}$ sum of any subarray will be less than $2n$, so the number of possible elements with odd divisors $\leq \sqrt{2n}$. Number of subarrays with a given $\operatorname{XOR}$ sum can be calculated in $O(n)$. 

Therefore, calculate the same for each perfect square less than $2n$ and add all these to get the number of subarrays whose $\operatorname{XOR}$ sum has an odd number of divisors. Subtract from total number of subarrays to get the required answer.

Time complexity : $O(n \cdot \sqrt{n})$.

 **Code(C++)**[186975655](https://codeforces.com/contest/1731/submission/186975655 "Submission 186975655 by adedalic")

 **Code(Python)**[186975680](https://codeforces.com/contest/1731/submission/186975680 "Submission 186975680 by adedalic")

[1731D - Valiant's New Map](../problems/D._Valiant's_New_Map.md "Codeforces Round 841 (Div. 2) and Divide by Zero 2022")

Idea: [s_jaskaran_s](https://codeforces.com/profile/s_jaskaran_s "Candidate Master s_jaskaran_s")

 **Hint 1**For a particular size, how to check if there's a cube greater than that?

 **Hint 2**Try Binary search on side length.

 **Hint 3**Let x be the side length. How to check if a square has all its elements ≥x in O(1)?

 **Solution**
### [1731D - Valiant's New Map](../problems/D._Valiant's_New_Map.md "Codeforces Round 841 (Div. 2) and Divide by Zero 2022")

The basic brute force solution for this problem was to just iterate through all the values of sides possible. Note that the value of sides can range only from $1$ to $1000$ as product of $n \cdot m$ can't exceed $10^6$, so there can't be a cube having all sides greater than $1000$. After setting side length (let's say $s$) we look into all possible submatrices of dimensions $s \times s$ and see if we can form a cube from any one of those. This could only be possible if there exists a submatrix with its minimum $\ge s$. 

Now, we need to do all these operations efficiently, looking at the constraints. The main thing that we need to do is Binary search on the answer. As obviously, it is possible to make a cube with a smaller side if it is possible to make the one with the current side length.

Now from here, we have two different approaches -

Sparse Table - For a particular side $s$, check for all submatrices of size $s \times s$, if their minimum is greater than equal to $s$. If you find any such submatrix, then this value of side is possible. A minimum can be calculated in $O(1)$ using sparse tree. You might have tried using segment tree, which takes $\log m \cdot \log n$ time per query. But it may not to pass with these constraints.

So, the time complexity to solve this problem is $O(n \cdot m \cdot \log{(\min{(n, m)})}$). It would pass these constraints. 

Another $O(n \cdot m \cdot \min{(n, m)}$) solution where you don't use binary search is also there but would fail with these constraints. The segment tree solution takes $O(n \cdot m \cdot \log{n} \cdot \log{m} \cdot \log{(\min{(n, m)})}$) . So, only sparse tree can be used.

Prefix Sum - This is a much simpler solution. First, we create another $n\times m$ matrix, let's say $B$. Now, for a particular side length $s$, we take all the indices where the building heights are greater than equal to $s$ and set the elements of $B$ at those indices to $1$. Other elements are set to $0$. 

Now we precalculate the prefix sum for this matrix. Then for each index $(i, j)$ of the matrix $B$, we check if the square starting from that index has a prefix sum equal to $s^2$. If anyone of it does, then this side length for the cube is possible.

Time Complexity is again $O(n \cdot m \cdot \log{(\min{(n, m)})})$.

 **Code(Prefix Sum)**[186975714](https://codeforces.com/contest/1731/submission/186975714 "Submission 186975714 by adedalic")

 **Code(Sparse Table)**[186975738](https://codeforces.com/contest/1731/submission/186975738 "Submission 186975738 by adedalic")

[1731E - Graph Cost](../problems/E._Graph_Cost.md "Codeforces Round 841 (Div. 2) and Divide by Zero 2022")

Idea: [s_jaskaran_s](https://codeforces.com/profile/s_jaskaran_s "Candidate Master s_jaskaran_s")

 **Hint 1**Can you find the number of edges for each possible GCD?

 **Hint 2**Did you try Greedy?

 **Solution**
### [1731E - Graph Cost](../problems/E._Graph_Cost.md "Codeforces Round 841 (Div. 2) and Divide by Zero 2022")

In each step, adding $e$ edges to the graph with weights $e + 1$ costs one more than the number of edges added. So, the total cost of adding $m$ edges in $s$ steps will be $m + s$. Since the number of edges is given, i. e. fixed, to find the minimum cost, we need to minimize the number of steps.

Firstly, let's calculate the number of pairs $(x, y)$ where $1 \le x < y \le n$ with $\gcd(x, y) = k$ for each $k \in [1..n]$ in $O(n \log n)$ time. It can be solved in a standard way using the Möbius function $\mu(x)$ or using Dynamic Programming, where $dp[k]$ is the required number that can be calculated as:

 $ dp[k] = \frac{1}{2} \left\lfloor \frac{n}{k} \right\rfloor ( \left\lfloor \frac{n}{k} \right\rfloor - 1) − dp[2k] − dp[3k] − \dots − dp[\left\lfloor \frac{n}{k} \right\rfloor k]$ Knowing all $dp[k]$ we can calculate the maximum number of steps $s[k]$ we can perform using edges of weight $k$. And $s[k] = \left\lfloor \frac{dp[k]}{k - 1} \right\rfloor$.

Note that array $s[k]$ is non-increasing ($s[k] \ge s[k + 1]$) and if we have at least one pack of size $x$ then we have at least one pack of each size $y$ where $1 \le y < x$. So, our task is an "extension" of the task where you need to take a subset of $1, 2, \dots, n$ of minimum size with sum equal to $m$ and can be solved with the same greedy strategy.

Let's just take packs greedily, starting from weight $n$ down to weight $2$. We'll take packs as many packs as possible. For a fixed weight $k$ we can calculate the maximum number of packs we can take as $\min(s[k], \frac{m'}{k - 1})$.

If $m$ edges can't be constructed, then we return $-1$. Otherwise, we return $m + s$ where $s$ is the total number of packs.

Time Complexity: $O(n \log n)$

 **Code**[186975762](https://codeforces.com/contest/1731/submission/186975762 "Submission 186975762 by adedalic")

[1731F - Function Sum](../problems/F._Function_Sum.md "Codeforces Round 841 (Div. 2) and Divide by Zero 2022")

Idea: [nishkarsh](https://codeforces.com/profile/nishkarsh "Master nishkarsh") and [s_jaskaran_s](https://codeforces.com/profile/s_jaskaran_s "Candidate Master s_jaskaran_s")

 **Solution**
### [1731F - Function Sum](../problems/F._Function_Sum.md "Codeforces Round 841 (Div. 2) and Divide by Zero 2022")

Let's try to write a brute force solution of this using combinatorics. Let's say that $a[i]=t$ now we will try to see that in how many permutations this is contributing towards the answer. Using combinatorics, it can be calculated as $$F(t) = t \cdot {\sum_{i=1}^n \sum_{x=0}^{i-1} \sum_{y = x+1}^{n-i} \left( \binom{i-1}{x} (t-1)^{x} (K+1-t)^{i-1-x} \cdot \binom{n-i}{y} (K-t)^{y} \cdot t^{n-i-y} \right)} $$.

Here $x$ represents $\operatorname{lsl}(i)$ and y represents $\operatorname{grr}(i)$.

Let $$P(u) = {\sum_{t=1}^u F(t)} $$ be a polynomial whose degree will be $\le n+2$. And now our answer will be $P(k)$.

Now, we can evaluate this polynomial for smaller values (by brute force) and will use the technique of polynomial interpolation to find the answer.

 **Code**[186975785](https://codeforces.com/contest/1731/submission/186975785 "Submission 186975785 by adedalic")

