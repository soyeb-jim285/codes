# Tutorial


### [1415A - Prison Break](../problems/A._Prison_Break.md "Technocup 2021 - Elimination Round 2")

The problem is equivalent to finding the farthest cell from $( x , y )$. It is easy to see that, if they move optimally, $( i , j )$ can reach $( x , y )$ just by moving in an L shape, and this is equivalent to the Manhattan distance between the two points. The longest distance a prisoner will move on rows is $max( x - 1 , n - x )$, and for the columns it is $( y - 1 , m - y )$. So answer is just $max( x - 1 , n - x ) + max( y - 1 , m - y )$

 
### [1415B - Repainting Street](../problems/B._Repainting_Street.md "Technocup 2021 - Elimination Round 2")

If we want to paint every house on the street with color $x$, it is easy to see that we need to change every house with color different from $x$, and not necessarily repaint houses already painted in color $x$. We can do the following greedy algorithm to minimize the number of days: Find leftmost house not painted in color $x$. Assume this is in position $i$. Then we will paint $[i,i+k-1]$ with color $x$. Repeat this until all houses are painted in color $x$. Why is this optimal? When we find the leftmost house not painted in $x$, we know we need to change it, and as it is the leftmost one, everything before it is painted in $x$. To maximize our chances of changing other houses that need repainting, we choose this as the leftmost position in our painting range. This can be implemented easily with a linear pass. However, we don't know the color $x$ that we will have at the end. Limit of colors are small enough, so we can try all of them and just keep the smallest answer.

Time complexity: $O(n \cdot max(c))$

Space complexity: $O(n)$

 Tutorial is loading... 
### [1415D - XOR-gun](../problems/D._XOR-gun.md "Technocup 2021 - Elimination Round 2")

First let's compute array $b_1, b_2, \ldots, b_n$, where $b_i$ is the index of the highest bit equal to $1$ in the binary notation of $a_i$. The statement says $b_i \le b_{i + 1}$. These values can be computed by dividing the given numbers by $2$ until they are zero.

Note that if for a given $i$ the equality $b_{i - 1} = b_i = b_{i + 1} = t$ holds, then we can apply an operation to $a_i$ and $a_{i + 1}$, and the resulting integer is smaller than $a_{i - 1}$. Indeed, in $a_{i - 1}$ the highest bit set is $t$, but in $a_i \oplus a_{i + 1}$ the $t$-th and higher bits are zeros. That means if there is such an $i$ (it is easy to check in a single linear pass), then the answer is $1$.

Now note that if there is no such $i$, then the size of the array $n$ is not bigger than $2 \cdot \left(\lfloor\log_2{10^9}\rfloor + 1\right) = 60$! Indeed, there are no more than two integers with the same highest bit set. It is much easier to solve the problem in such constraints. 

Consider some solution. In the final array, let's denote it as $c$, there is $i$ such that $c_i > c_{i + 1}$. Note that each element of the final array is equal to XOR of some subsegment of the initial array, and each element of the initial array belongs to exactly one such subsegment. Let this subsegment for $c_i$ be $a_l, a_{l + 1}, \ldots, a_m$, and for $c_{i + 1}$ be $a_{m + 1}, a_{m + 2}, \ldots, a_r$. Then it's clear that to find an optimal solution it is enough to loop through all possible values of $l$, $m$, and $r$ and check whether XOR of all elements of the left subsegment is larger than XOR of all elements of the right subsegment. If this inequality holds, update answer with value $r - l - 1$. The complexity of this part is $O(n^3)$ or $O(n^4)$ depending on implementation.

 Tutorial is loading... Tutorial is loading... 
### [1456E - XOR-ranges](https://codeforces.com/contest/1456/problem/E "Codeforces Round 687 (Div. 1, based on Technocup 2021 Elimination Round 2)")

First, we will make all segments exclusive for convenience.

Assume we have segment $(l, r)$, we gonna analyze the process of forming $x$ from highest bit to lowest bit: Let $hb$ is the highest bit such that $hb$-th bit of $l$ and $r$ are different (Apparently, bits higher than $hb$ of x has to be same with bits of $l$ and $r$). We call $hb$ key bit of the segment. Now we set $hb$-th bit of $x$ off (almost similar if we set on). From now on, we have $x < r$ and continue considering lower bits. If the considered bit is on in $l$, we must set this bit on in $x$, otherwise, we have two choices: 

* Set this bit off in $x$ and consider lower bits.
* Set this bit on in $x$ and don't need to care about lower bits (Because $x > l$ now).

 Let call low bits that we don't need to care free bits.Back to the problem, imagine if we fixed all non-free bits of every element, how should we set other bits in order to minimize the cost? It's quite simple: Consider $i$-th bit, call the pair $(l, r)$ visible if $i$-th bits of $l$ and $r$ are non-free but ones of $A[l+1, l+2, .., r-1]$ are free. For each visible pair such that $i$-th bit of endpoints in this pair are different from each other, we'll add $c_{i}$ to the answer. This thing inspire us to write a dynamic programming function: $dp(i, l, r, state(l), state(r))$ ($state(l)$ is $(f, c)$ with $f$ is how did you set key bit for $l$-th element, and $c$ is where is lowest non-free bit of this element (equal to or lower than $i$), similar to $state(r)$) is minimal cost at $i$-th and higher bits of $A[l..r]$ such that $(l, r)$ is currently visible. We have two types of transition: 

* Make $(l, r)$ really visible by going to $(i+1)$-th bit.
* Make $(l, r)$ invisible by choosing $md (l < md < r)$ and choosing $state(md)$ such that lowest non-free bit of $md$-th element is $i$.

 (Note that if $i$ is the highest bit, first transition only be allowed if $l+1=r$)Our answer is just $dp(0, 0, N+1, (0, 0), (0, 0))$

