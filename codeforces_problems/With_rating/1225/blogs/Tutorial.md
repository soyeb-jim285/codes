# Tutorial


### [1225A - Forgetting Things](../problems/A._Forgetting_Things.md "Technocup 2020 - Elimination Round 2")

The answer exists only if $d_a = d_b$, $d_b = d_a + 1$, or $d_a = 9$ and $d_b = 1$. Alternatively, one could simply check all $a$ up to 100 (or another reasoable bound).

 
### [1225B1 - TV Subscriptions (Easy Version)](../problems/B1._TV_Subscriptions_(Easy_Version).md "Technocup 2020 - Elimination Round 2")

We are looking for a segment of length $d$ with the smallest number of distinct values. In small limitations one could just try all segments and count the number of distinct elements naively (for example, by sorting or with an std::set).

 
### [1225B2 - TV Subscriptions (Hard Version)](../problems/B2._TV_Subscriptions_(Hard_Version).md "Technocup 2020 - Elimination Round 2")

In larger limitations we have to use two pointers to maintain the number of distinct elements between segments. We can store a map or an array that counts the number of occurences of each element, as well as the number of distinct elements (i.e. the number of non-zero entries in the map). Moving the segment to the right involves changing two entries of the map, keeping track of which entries become/cease to be non-zero. The complexity is $O(n \log n)$ or $O(n)$ (both are acceptable).

 
### [1225C - p-binary](../problems/C._p-binary.md "Technocup 2020 - Elimination Round 2")

Suppose we want to represent $n$ as the sum of $k$ $p$-binary numbers. We must have $n = \sum_{i = 1}^k (2^{x_i} + p)$ for a suitable choice of $x_1, \ldots, x_k$. Moving all $p$'s to the left-hand side, we must have $n - kp = \sum_{i=1}^k 2^{x_i}$. In particular, $n - kp$ has to be at least $k$.

Consider the binary representation of $n - kp$. If it has more than $k$ bits equal to $1$, there is no way we can split it into $k$ powers of two. Otherwise, we can start by taking the binary representation, and if it contains less than $k$ powers, we can always split larger powers into two smaller ones.

We can now check all values of $k$ starting from the smallest. If $n \geq 31p + 31$, then the answer will not exceed $31$ since $n - 31p$ is less than $2^{31}$, hence is always representable with $31$ powers. Otherwise, we have $n - 31(p + 1) < 0$. Since $n > 0$, it means that $p + 1 < 0$, and $n - kp < k$ for all $k > 31$, thus the answer does not exist.

 
### [1225D - Power Products](../problems/D._Power_Products.md "Technocup 2020 - Elimination Round 2")

Suppose that $x \cdot y$ is a $k$-th power. The sufficient and necessary condition for that is: for any prime $p$, the total number of times it divides $x$ and $y$ must be divisible by $k$.

Let us factorize each number $a_i = p_1^{b_1} \ldots p_m^{b_m}$, and associate the list of pairs $L_i ((p_1, b_1 \bmod k), \ldots, (p_m, b_m \bmod k))$, omitting the entries with $b_i \bmod k = 0$. For example, for $360 = 2^3 2^2 5^1$ and $k = 2$, the corresponding list would be $((2, 1), (5, 1))$.

If $a_i \cdot a_j$ is a $k$-th power the the primes in the respective lists should match, and $b_i \bmod k$ add up to $k$ for corresponding primes. Indeed, if a prime is absent from one of the lists (i.e. the exponent is divisible by $k$), then it should be absent from the other list too. Otherwise, the total exponent for this prime should be divisible by $k$, hence the remainders should add up to $k$.

We now have that for every $a_i$ there is a unique possible list $L'_i$ for the other number that would give a $k$-th power product. We can now maintain the count for each of the occuring lists (e.g. with std::map), and every number we meet we add the number of occurences of $L'_i$ to the answer, and increase the count for $L_i$ by one.

The total complexity comprises of factoring all the input numbers (in $O(\sqrt{max a_i})$ or in $O(\log \max a_i)$ with precomputed sieve), and maintaining a map from vectors to numbers. The total size of all vectors is roughly $O(n \log n)$, so the complexity of maintaining a map is $O(n \log ^2 n)$, or $O(n \log n)$ with a hashmap.

 
### [1225E - Rock Is Push](../problems/E._Rock_Is_Push.md "Technocup 2020 - Elimination Round 2")

Let us compute $R_{i, j}$ and $D_{i, j}$ – the number of legal ways to reach the goal assuming:

* we've arrived at the cell $(i, j)$;
* our next move is right/down respectively;
* our previous move (if there was a previous move) was not in the same direction.

By definition, let us put $D_{n, m} = R_{n, m} = 1$.

We can see that all rocks reachable from $(i, j)$ in these assumptions should be in their original places, thus the answer is independent of the way we've reached the cell $(i, j)$ in the first place.

Recalculation is fairly straightforward. For example, for $D_{i, j}$ let $k$ be the number of stones directly below $(i, j)$. We can make at most $n - k - i$ moves before we make the turn to the right, thus we have $D_{i, j} = \sum_{t = 1}^{n - k - i} R_{i + t, j}$. This allows to compute $R_{i, j}$ and $D_{i, j}$ with dynamic programming starting from the cells with larger coordinates.

The formula hints at some range summing techniques, like computing prefix sums or maintaing a more sophisticated RSQ structure. However, these are not needed in this problem. Indeed, as we consider summation ranges for $D_{i, j}$ and $D_{i + 1, j}$, we can see that they differ by at most one entry on each side. It follows that to compute $D_{i, j}$, we can take $D_{i, j}$ and add/subtract at most two values of $R_{i + t, j}$. The values near the goal cell may need some extra treatment since they are not always a proper range sum. Also, the case $n = m = 1$ need to be treated separately.

The total complexity is $O(nm)$ (additional $\log$ for RSQ should be fine though).

 
### [1225F - Tree Factory](../problems/F._Tree_Factory.md "Technocup 2020 - Elimination Round 2")

Let's solve the problem backwards: given a tree, transform it into a bamboo with reverse operations. A reverse operation in this context looks like this: given a vertex $v$ and its two distinct children $u$ and $w$, make $w$ the parent of $u$.

What's the lower bound on the number of operations we need to make? We can see that the depth of the tree, i.e. the length of the longest vertical path starting from the root, can increase by at most one per operation. On the other hand, the depth of the bamboo is $n - 1$. Therefore, we'll need to make at least $n - 1 - (\text{initial depth of the tree})$ operations.

This number would always be enough if for any non-bamboo tree we could find an operation that would increase its depth. And indeed we can: consider a longest path starting from the root. If all its vertices have at most one children, the tree is a bamboo and we are done. Otherwise, take any vertex $v$ on the path with at least two children, its child $u$ on the longest path, and any other child $w$, then make $w$ the parent of $u$. One can see that there is a longer path now.

One efficient way to do these operations successively is to keep track of the lowest candidate for $u$. After applying an operation, the candidate is either $u$ again, or one of its ancestors. With standard amortized analysis, we can now perform all these operations in $O(n)$ time.

To output the answer, print the labelling of the final bamboo you obtain, followed by the reverse sequence of the operations you've made.

 
### [1225G - To Make 1](../problems/G._To_Make_1.md "Technocup 2020 - Elimination Round 2")

An experienced eye will immediately spot a subset dynamic programming solution in roughly $O(3^n \sum a_i)$ time, but the time constraints will not allow this. What to do?

Suppose there is a way to obtain 1 in the end. Looking at how many times each initial number $a_i$ gets divided by $k$ (including the divisions of the subsequent numbers containing it), we can obtain the expression $1 = \sum_{i = 1}^n a_i k^{-b_i}$, where $b_i$ are respective numbers of divisions. What if we were given such an expression to start with? Can we always restore a sequence of operations?

As it turns out, yes! Prove by induction. If there a single number, then it must be $1$ and we are done. Otherwise, let $B = \max b_i$. We argue that there are at least two numbers $a_i$ and $a_j$ with $b_i = b_j = B$. Indeed, assume there was only one such number $a_j$. Multiply both sides of the expression to obtain $k^B = \sum_{i = 1}^n a_i k^{B - b_i}$. The left-hand side, and all but one summand of the right-hand are divisible by $k$. But since $a_j$ is not divisible by $k$, the right-hand side is not divisible by $k$, a contradiction.

Since we have two numbers $a_i$ and $a_j$, let's replace them with $f(a_i + a_j) = a'$, and put $b' = B - (\text{the number of times }(a_i + a_j)\text{ is divisible by }k)$. We can see that the new set of numbers still satisfies the expression above, hence by induction hypothesis we can always finish the operation sequence. Note that this argument can be converted into an answer restoration routine: given the numbers $b_i$, group any pair of numbers $a_i$ and $a_j$ with $b_i = b_j$.

The question now becomes: can we find suitable numbers $b_1, \ldots, b_n$ such that the above expression is satisfied? We can do this with a more refined subset dynamic programming. For a subset $S \subseteq \{1, \ldots, n\}$ and a number $x$, let $dp_{S, x}$ be true if and only if we can have an expression $x = \sum_{i \in S} a_i k^{-b_i}$ for suitable $b_i$. The initial state is $dp_{\varnothing, 0} = 1$. The transitions are as follows:

* include $a_i$ into $S$: $dp_{S, x} \implies dp_{S + a_i, x + a_i}$;
* increase all $b_i$ by 1: if $x$ is divisible by $k$, then $dp_{S, x} \implies dp_{S, x / k}$.

By definition, we can obtain 1 as the final number iff $dp_{\{1, \ldots, n\}, 1}$. Straightforward recalculation requires $O(n 2^n \cdot \sum a_i)$ time. However, the first type of transition can be optimized using bitsets, bringing the complexity down to $O(2^n \sum a_i \cdot (1 + n / w))$, where $w$ is the size of the machine word ($32$ or $64$). To restore $b_i$, trace back from $dp_{\{1, \ldots, n\}, 1}$ to $dp_{\varnothing, 0}$ using reachable states.

 
### [1246F - Cursor Distance](https://codeforces.com/contest/1246/problem/F "Codeforces Round 596 (Div. 1, based on Technocup 2020 Elimination Round 2)")

Again, it's easier to solve the problem backwards. For a character $s_i$, from which characters $s_j$ can we reach $s_i$ in one step? Clearly, $s_j$ should lie in a subsegment of $s$ bounded by adjacent occurences of $s_i$ (inclusive), or by the borders of $s$. Let's denote this subsegment for $s_i$ by $[L_i, R_i)$ (we will use half-open intervals for convenience, as should you).

Which characters can be reached from $s_i$ in $k$ reverse steps? We can see that these characters also form a subsegment, let's denote it $[L_i^{(k)}, R_i^{(k)})$. We have that $[L_i^{(0)}, R_i^{(0)}) = [i, i + 1)$, and $[L_i^{(k)}, R_i^{(k)}) = \displaystyle \cup_{j \in [L_i^{(k - 1)}, R_i^{(k - 1)})} [L_j, R_j)$.

Note that having values of $[L_i^{(k)}, R_i^{(k)})$ can be used to directly compute the answer, for example, with a formula $\sum_{i = 1}^n \sum_{k = 0}^{n - 1} (n - (R_i^{(k)} - L_i^{(k)}))$. This formula is correct since the expression inside the brackets is the number of characters not reachable from $i$ in $k$ reverse steps, hence a position $j$ reachable in exactly $d$ steps will be accounted for $d$ times. Simplifying a bit, we arrive at the formula $n^3 - \sum_{i = 1}^n \sum_{k = 0}^{n - 1} (R_i^{(k)} - L_i^{(k)})$.

Values of $[L_i^{(k)}, R_i^{(k)})$ can be computed in $O(n^2)$ individually by applying the above recurrence and using a sparse table, but that is still way too slow. It's tempting to try and use binary lifting, but as $k$ grows, evolution of $L_i^{(k)}$ and $R_i^{(k)}$ is mutually dependent, and we can't store an $n^2$-sized table. They do, however, become independent at some point, namely, when the range $[L_i^{(k)}, R_i^{(k)})$ contains all distinct letters present in $s$. Indeed, to compute $R_i^{(k + 1)}$ we simply need to take the largest $R_j$, where $j$ ranges over the last occurences of letters a, $\ldots$, z before $R_i^{(k)}$. Slightly more generally, we can treat the evolution of $L_i^{(k)}$ and $R_i^{(k)}$ independently in a range of $k$'s where the number of distinct characters in the segment doesn't change. And it can only change at most $\alpha = 26$ times...

Time to put this together. For each $i$, we will store $k_i$ — the number of expansions we've applied to $[L_i^{(k)}, R_i^{(k)})$, as well as the range's endpoints themselves. We will iterate over the parameter $t$ — the number of distinct characters in ranges we're going to expand now. For each right endpoint $r$, let's find $f_r(r)$ as the largest $R_j$ over $t$ closest distinct letters to the left of $r$; define $f_l(l)$ similarly. Additionally, compute binary lifts $f^{2^y}_r(r)$, $f^{2^y}_l(l)$, as well as the sums of $r$ and $l$ visited by each binary lift. Now, for each $i$ we use binary lifting to find the largest number of iterations to apply to $[L_i^{(k)}, R_i^{(k)})$ so that the number of distinct characters in the range stays equal to $t$. Doing this, we can update $k_i$ and endpoints of $[L_i^{(k)}, R_i^{(k)})$ accordingly, as well as add a part of $\sum_{i = 1}^n \sum_{k = 0}^{n - 1} (R_i^{(k)} - L_i^{(k)})$ to the total. Thus, going into the next phase with $t + 1$, we will have all necessary values up-to-date.

How fast does this work? For every $t = 1, \ldots, \alpha = 26$, we'll need $O(n \log n)$ work to construct binary lifts and update everything. The total complexity is thus $O(\alpha n \log n)$.

