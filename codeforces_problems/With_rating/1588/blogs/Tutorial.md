# Tutorial

Tutorial is loading... 
### [1584B - Coloring Rectangles](https://codeforces.com/contest/1584/problem/B "Technocup 2022 - Elimination Round 2")

Rectangles after cutting will be painted in a chess coloring. So, if the area is even, then the number of cells of different colors is the same, and if it is odd, then it differs by exactly $1$.

Let's find out what part the colored cells occupy in relation to all of them. For an even area, this ratio is always $\frac{1}{2}$. For odd $\frac{S - 1}{2 \cdot S}$. The smaller the odd area, the smaller the ratio. An area equal to $1$ cannot be obtained, so the best ratio is $\frac{1}{3}$ and is achieved with an area equal to $3$.

Then we get the lower estimate for the answer: $answer \geq n \cdot m \cdot \frac{1}{3}$. Great!

We know that the answer is integer, so if we manage to construct such a cut that it is necessary to color exactly such a $cnt$ of cells that$\frac{n \cdot m}{3} \leq cnt < \frac{n \cdot m}{3} + 1$, then $cnt$ will be the answer. After all, $cnt$ is the minimum integer value satisfying the estimate.

If one of the sides is divisible by $3$, then it is obvious how to cut into $1 \times 3$ rectangles and get the perfect answer.

If the remains of sides $1$ and $1$ or $2$ and $2$, then you can cut into $1 \times 3$ rectangles and one rectangle with an area of $4$, in which you need to paint over $2$ cells. Then the answer also fits the assessment.

If the remains of sides $1$ and $2$, then after cutting into $1 \times 3$ rectangles, a rectangle will remain $1 \times 2$, in which you need to paint one cell. The answer also fits the assessment.

For all pairs of remains, there is a way to construct an answer satisfying the inequality. Therefore, the answer is $ \lceil \frac{n \cdot m}{3} \rceil$

 
### [1584C - Two Arrays](https://codeforces.com/contest/1584/problem/C "Technocup 2022 - Elimination Round 2")

Let's sort the arrays first.

Let's check the two smallest elements in the arrays and investigate their behavior. First, obviously, if $a_1 + 1 < b_1$ (as nothing can be matched with $a_1$) or $a_1 > b_1$ (as nothing can be matched with $b_1$) the answer is No. Then, it's possible that $a_1 = b_1 = x$. In this case, we have to have at least one $x$ in the array $a$ at the end. Hence, we can leave $a_1$ untouched, as it already suits to $b_1$. It's also possible that $a_1 + 1 = b_1$. Here we have to increase $a_1$ by $1$. In both cases, the task is reduced to the smallest one.

Going to the exact solution from this logic, we just have to sort both arrays and check that for each $1 \leq i \leq n$ it's $a_i = b_i$ or $a_i + 1 = b_i$.

The complexity of the solution is $O(n log(n))$.

 Tutorial is loading... Tutorial is loading... Tutorial is loading... 
### [1584G - Eligible Segments](https://codeforces.com/contest/1584/problem/G "Technocup 2022 - Elimination Round 2")

The distance from point $P$ to segment $[AB]$ is equal to the maximum of the distance from point $P$ to ray $[AB)$ and the distance from point $P$ to ray $[BA)$. 

Let's fix a point $P_i$. Now we have to find all points $P_j$ such that distance from every point $P_k (1 \le k \le n)$ to the ray $[P_i, P_j)$ is less than $R$.

For every point $P_k$ let's build two tangents from point $P_i$ to the circle with the center in the point $P_k$ and radius $R$. These tangents form an angle $A_k$. The distance from the point $P_k (1 \le k \le n)$ to the ray $[P_i, P_j)$ is less than $R$ iff the ray $[P_i, P_j)$ lies inside the angle $A_k$. So we can build all these angles $A_k$ and intersect them, after that, we only have to check that the ray $[P_i, P_j)$ lies inside the intersection of all angles for all $1 \le j \le n$.

Time complexity: $O(n^2)$.

 
### [1588F - Jumping Through the Array](../problems/F._Jumping_Through_the_Array.md "Codeforces Round 755 (Div. 1, based on Technocup 2022 Elimination Round 2)")

Let's call $B = \lfloor \sqrt{n} \rfloor$.

Let's divide an array $a$ into consecutive blocks of size $B$.

To answer the query we will have to sum $O(B)$ $a_i$ near the segment's bounds and $O(\frac{n}{B})$ sums on blocks. Let's try to calculate them fast.

There are two types of cycles:

* small: with length $< B$
* big: with length $\geq B$

If there is a second type query for the small cycle it is easy to make it in $O(B)$ time: let's iterate over cycle's elements and add $x$ into its $a_i$ and into its array's block sum.

It is harder to deal with big cycles. Let's divide each big cycle into blocks, each having the size in $[B, 2B - 1]$. Initially, it is possible. After each query of type $3$ it is possible to reconstruct this division fast:

* Let's split two blocks with $i$ and $j$. After that, it is possible to reconstruct the divisions of each new cycle into blocks.
* After that, we should avoid small blocks (with size $< B$). Let's merge two consecutive blocks if one of them has the size $< B$. After that, if the total block has size $\geq 2B$ let's split it into two equal blocks.
* Someone calls this method split-rebuild.

So, maintaining this structure we will have at most $\frac{n}{B}$ cycle blocks at any moment. If there is a second type query for the big cycle let's add $x$ to the cycle blocks for this cycle. To consider these values while answering the first type query let's maintain the last structure:

* For each cycle block $t$ let's calculate the values $pref_{t,0}, pref_{t,1}, \ldots, pref_{t,\lceil \frac{n}{B} \rceil}$, where $pref_{t,i}$ is the number of elements from the $t$-th cycle block in the first $i$ array's blocks.

Using these values it is easy to consider additions to the cycle blocks in the subsegments sums queries.

And the values of $pref$ can be recalculated during the cycle's updates because we make $O(1)$ splits and merges. During each split or merge we should recalculate $pref$ for $O(1)$ rows (and this can be done in $O(\frac{n}{B})$ for one $t$). Also during each split or merge we should zero additions to blocks in operations just pushing the added value into the elements of the block (their number is smaller than $2B$).

The total complexity of the solution is $O(n \sqrt{n})$.

