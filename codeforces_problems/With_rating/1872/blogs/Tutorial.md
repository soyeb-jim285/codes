# Tutorial

Thanks for joining the contest!

[1872A - Two Vessels](../problems/A._Two_Vessels.md "Codeforces Round 895 (Div. 3)")  


  **Tutorial**  
### [1872A - Two Vessels](../problems/A._Two_Vessels.md "Codeforces Round 895 (Div. 3)")

Let $d = a - b$, the difference in masses of water in the vessels. Our goal is to make $d$ equal to $0$. Note that with one pouring, we can add any number from the range $[-2 \cdot c; 2 \cdot c]$ to $d$. Therefore, the answer to the problem will be $\lceil \frac{|d|}{2 \cdot c} \rceil$.

 **Solution**[222362736](https://codeforces.com/contest/1872/submission/222362736 "Submission 222362736 by sevlll777")

[1872B - The Corridor or There and Back Again](../problems/B._The_Corridor_or_There_and_Back_Again.md "Codeforces Round 895 (Div. 3)")  


  **Tutorial**  
### [1872B - The Corridor or There and Back Again](../problems/B._The_Corridor_or_There_and_Back_Again.md "Codeforces Round 895 (Div. 3)")

Let's see when we can reach room $k$ and return back. In this case, the time difference between entering and exiting room $1 \le x \le k$ is equal to $2 \cdot (k - x)$. Therefore, it is necessary for all traps to satisfy: $s_i > 2 \cdot (k - d_i)$. Now we need to find the maximum $k$ that satisfies these conditions. To do this, we can either iterate through all $k$ from $1$ to $300$, or use binary search for the answer, or notice that $$s_i > 2 \cdot (k - d_i) \to s_i + 2 \cdot d_i > 2 \cdot k \to d_i + \frac{s_i}{2} > k \to d_i + \frac{s_i - 1}{2} \geq k$$ Therefore, the maximum suitable $k$ will be $\min(d_i + \lfloor \frac{s_i - 1}{2} \rfloor)$.

 **Solution**[222362772](https://codeforces.com/contest/1872/submission/222362772 "Submission 222362772 by sevlll777")

[1872C - Non-coprime Split](../problems/C._Non-coprime_Split.md "Codeforces Round 895 (Div. 3)")  


  **Tutorial**  
### [1872C - Non-coprime Split](../problems/C._Non-coprime_Split.md "Codeforces Round 895 (Div. 3)")

To begin with, let's learn how to solve the problem when $l = r$. In other words, we need to find a value $1 \le a < l$ such that $\gcd(a, l - a) \neq 1$. Notice that $\gcd(a, l - a) = \gcd(a, l)$. Then it is easy to see that if $l$ is prime, then $\gcd(a, l) = 1$ for any $1 \le a < l$, otherwise any divisor of $l$ (except $1$ and $l$) will work as $a$. Thus, we can solve the problem when $l = r$ using the standard algorithm for primality testing in $O(\sqrt{r})$ time. Next, we can solve the problem in several ways:

1. Sequentially check for primality all numbers from $l$ to $r$, and stop and output the answer as soon as we find the first composite number. This works faster than $O(r \sqrt r)$ because there are no two adjacent prime numbers starting from $3$, so the answer will be found very quickly.
2. Handle the case $l = r$ separately. Also, separately consider the case $r \le 3$, in which the answer is $-1$. Otherwise, notice that since there are at least $2$ numbers in the interval $[l, r]$, there must be an even number in this interval. And for $r \ge 4$, the maximum even number in the interval, $s$, will be $\ge 4$, so for example, $a = \frac{s}{2}, b = \frac{s}{2}$ will be a valid answer. To find the maximum even number in the interval $l < r$, we can use the formula $r - r \% 2$.
 **Solution**[222362796](https://codeforces.com/contest/1872/submission/222362796 "Submission 222362796 by sevlll777")

[1872D - Plus Minus Permutation](../problems/D._Plus_Minus_Permutation.md "Codeforces Round 895 (Div. 3)")  


  **Tutorial**  
### [1872D - Plus Minus Permutation](../problems/D._Plus_Minus_Permutation.md "Codeforces Round 895 (Div. 3)")

Let's call a number red if it is divisible by $x$.

Let's call a number blue if it is divisible by $y$.

Let's call a number purple if it is both red and blue at the same time.

The score of a permutation, by definition, is the sum of $p_i$ for all red numbers $i$ from $1$ to $n$, minus the sum of $p_i$ for all blue numbers $i$ from $1$ to $n$.

It is easy to see that $p_i$ at purple indices $i$ does not affect the score of the permutation: they are included in the sum once with a plus sign and once with a minus sign.

Therefore, the score of the permutation is the sum of $p_i$ for "red but not purple indices" minus the sum of $p_i$ for "blue but not purple indices".

Notice that the set of "red but not purple indices" and the set of "blue but not purple indices" cannot intersect, because if they had a common index, it would be purple.

Therefore, it is obviously optimal to place the largest numbers possible on "red but not purple indices" and the smallest numbers possible on "blue but not purple indices".

To calculate the number of indices that are "red but not purple", we can calculate the number of red indices and subtract the number of purple indices.

The number of red indices is $\lfloor \frac{n}{x} \rfloor$, and the number of blue indices is calculated similarly.

To calculate the number of purple indices, we need to notice that the condition "index is divisible by both $x$ and $y$" is equivalent to "index is divisible by $\operatorname{lcm}(x, y)$", where $\operatorname{lcm}$ denotes the least common multiple. Therefore, the number of purple indices is $\lfloor \frac{n}{\operatorname{lcm}(x, y)} \rfloor$.

Let $R$ be the number of "red but not purple" indices, and let $B$ be the number of "blue but not purple" indices. Then it is not difficult to see that the maximum score is $(n + (n - 1) + \ldots + (n - (R - 1)) - (1 + 2 + \ldots + B)$.

To quickly find this sum, we can use the formula for the sum of an arithmetic progression: $l + (l + 1) + \ldots + r = \frac{(l + r) \cdot (r - l + 1)}{2}$

 **Solution**[222362817](https://codeforces.com/contest/1872/submission/222362817 "Submission 222362817 by sevlll777")

[1872E - Data Structures Fan](../problems/E._Data_Structures_Fan.md "Codeforces Round 895 (Div. 3)")  


  **Tutorial**  
### [1872E - Data Structures Fan](../problems/E._Data_Structures_Fan.md "Codeforces Round 895 (Div. 3)")

Of course this problem has solutions that use data structures. For example, you can use a segment tree with range updates to solve it in $O((n + q) \log n)$ time, or you can use a square root decomposition to solve it in $O((n + q) \sqrt{n})$ time.

However, of course, we do not expect participants in Div3 to have knowledge of these advanced data structures, so there is a simpler solution.

We will store 2 variables: $X_0, X_1$, which represent the XOR of all numbers from group $0$ and group $1$, respectively. When answering a query of type 2, we will simply output either $X_0$ or $X_1$. Now we need to understand how to update $X_0$ and $X_1$ after receiving a query of type 1.

Let's first solve a simplified version: suppose that in type 1 queries, only a single character of the string $s$ is inverted, i.e., $l = r$ in all type 1 queries.

Let's see how $X_0$ and $X_1$ change after this query. If $s_i$ was $0$ and became $1$, then the number $a_i$ will be removed from group $0$. So, we need to invert "XOR $a_i$" from $X_0$. Since XOR is its own inverse operation ($w \oplus w = 0$), we can do this with $X_0 = X_0 \oplus a_i$. And in $X_1$, we need to add the number $a_i$, since now $s_i = 1$. And we can do this with $X_1 = X_1 \oplus a_i$.

The same thing happens if $s_i$ was $1$.

This is the key observation: when we invert $s_i$, $X_0$ and $X_1$ change in the same way, regardless of whether this inversion was from $0$ to $1$ or from $1$ to $0$.

Therefore, to update $X_0$ and $X_1$ after a query of type 1 with parameters $l, r$, we need to do this: $X_0 = X_0 \oplus (a_l \oplus \ldots \oplus a_r)$, and the same for $X_1$.

To quickly find the XOR value on a subsegment of the array $a$, we can use a prefix XOR array. If $p_i = a_1 \oplus \ldots a_i$, then: $a_l \oplus \ldots \oplus a_r = p_r \oplus p_{l-1}$.

 **Solution**[222362852](https://codeforces.com/contest/1872/submission/222362852 "Submission 222362852 by sevlll777")

[1872F - Selling a Menagerie](../problems/F._Selling_a_Menagerie.md "Codeforces Round 895 (Div. 3)")  


  **Tutorial**  
### [1872F - Selling a Menagerie](../problems/F._Selling_a_Menagerie.md "Codeforces Round 895 (Div. 3)")

Simple greedy observation: if at some point in time there exists an animal $i$ such that no one fears it (there is no index $a_j = i$), then it is optimal to sell that animal first.

Let's iteratively sell such animals as long as they exist. After selling animal $i$, we must additionally check if animal $a_i$ has become such that no one fears it, and if so, add it to the list for sale.

What will we get when we sell all such animals? Note that when there are no such animals left, $a_i$ will form a permutation, as each animal must be feared by at least one other animal.

As it is known, a permutation consists of cycles of the form $i \to a_i \to a_{a_i} \to \ldots \to i$.

Obviously, for each cycle we must solve the problem independently, and then combine the answers in any order. Note that if we sell animals in the order of the cycle, we will only receive a single payment for the last animal sold.

At the same time, it is not possible to obtain double payment for all animals in any case: the last animal sold from the cycle will always be sold for a single payment.

Therefore, it is optimal to sell all animals in the order of the cycle so that the animal with the minimum cost ends up being the last in this order.

You can see the implementation details in the code.

 **Solution**[222362879](https://codeforces.com/contest/1872/submission/222362879 "Submission 222362879 by sevlll777")

[1872G - Replace With Product](../problems/G._Replace_With_Product.md "Codeforces Round 895 (Div. 3)")  


  **Tutorial**  
### [1872G - Replace With Product](../problems/G._Replace_With_Product.md "Codeforces Round 895 (Div. 3)")

Key observation: if the product of all elements in the array is sufficiently large, it is always optimal to perform the operation on the entire array, except for a possible prefix/suffix consisting of ones.

You can estimate sufficiently large, for example, with the number $2^{60}$ (in reality, $2 \cdot n$ will be sufficient). There won't be a proof, but that's how it is.

Now the problem reduces to the case where the product of the array is not greater than $2^{60}$. This means that the number of array elements that are $> 1$ is at most $60$.

Notice that in an optimal segment, there won't be a situation where the left/right element is equal to $1$, because then we can move that boundary and the sum will increase by $1$.

Therefore, both the start and end of the segment must be in non-ones elements. This means that there are at most $60^2$ interesting segment options.

We can explicitly iterate through all of them and choose the best one. Use prefix products and sums to quickly estimate the value of a specific segment.

 **Solution**[222437122](https://codeforces.com/contest/1872/submission/222437122 "Submission 222437122 by sevlll777")

