# Tutorial


### [1244A - Pens and Pencils](../problems/A._Pens_and_Pencils.md "Codeforces Round 592 (Div. 2)")

There is a solution with brute force in $O(n^2)$ and a solution with formulas in $O(1)$. I'll describe the latter one.

We should determine the minimum number of pens that we should take to be able to write all of the lectures. It is $\lceil \frac{a}{c} \rceil$, but how to compute it easily? We can use some internal ceiling functions. We can also do something like "compute the integer part of the quotient, and then add $1$ if the remainder is not zero". But the easiest option, in my opinion, is to use the following formula: $\lceil \frac{a}{c} \rceil = \lfloor \frac{a + c - 1}{c} \rfloor$.

The minimum number of pencils can be calculated using the same method. All that's left is to check that $k$ is not less than the total number of writing implements we should take.

 
### [1244B - Rooms and Staircases](../problems/B._Rooms_and_Staircases.md "Codeforces Round 592 (Div. 2)")

If there are no stairs, the best we can do is to visit all the rooms on the same floor, so the answer is $n$.

Otherwise, the best course of action is to choose exactly one stair (let's denote its number by $s$) and do one of the following: either start from the leftmost room on the first floor, then use the stair and move to the leftmost room on the second floor, or do the same, but start and end in rightmost rooms instead of leftmost ones. Then for choosing the stair in room $s$, we get $max(2s, 2(n - s + 1))$ as the answer.

Why is it optimal? Let's denote the leftmost stair as $l$, and the rightmost stair as $r$. There are four special segments of rooms such that if we enter them, we can't leave. These are: rooms $[1 \dots l - 1]$ on the first floor, rooms $[1 \dots l - 1]$ on the second floor, rooms $[r + 1 \dots n]$ on the first floor and rooms $[r + 1 \dots n]$ on the second floor. We can visit only two of them, if one contains the starting room and the other contains the ending room. So the answer cannot be greater than $2n - 2min(l - 1, n - r - 1)$ — and our algorithm will give exactly this value either by choosing stair $l$, or by choosing the stair $r$.

 
### [1244C - The Football Season](../problems/C._The_Football_Season.md "Codeforces Round 592 (Div. 2)")

The crucial observation is that $d$ wins give us the same amount of points as $w$ draws. Let's use them to solve a problem where we want to minimize the total amount of wins and draws giving $p$ points (if it is not greater than $n$, we can just lose all other matches).

If $y \ge w$, then we can subtract $w$ from $y$ and add $d$ to $x$, the number of wins and draws will decrease, and the number of points will stay the same. So we can limit the number of draws to $w - 1$. And the solution is the following: iterate on the number of draws $y$ from $0$ to $w - 1$, and check if the current value of $y$ gives us the result we need ($p - yd$ should be non-negative and divisible by $w$, and $\frac{p - yd}{w} + y$ should be not greater than $n$).

 
### [1244D - Paint the Tree](../problems/D._Paint_the_Tree.md "Codeforces Round 592 (Div. 2)")

The key observation is that if we fix the colors of two adjacent vertices $x$ and $y$, then the color of any vertex adjacent to $x$ or to $y$ can be only $6 - c_x - c_y$. So we can fix the colors of the endpoints of any edge (there are $6$ possibilities to do that), then do a traversal to color all other vertices, then do another traversal to check that we got a good painting.

To avoid checking that the painting we got is good (which can be tricky to code), we can use the fact that, for each vertex, the colors of all its neighbours should be different from each other and from the color of the vertex we fixed. So, if some vertex has degree $3$ or greater, then there is no good painting; otherwise the painting we get is good, since the graph is a chain.

 
### [1244E - Minimizing Difference](../problems/E._Minimizing_Difference.md "Codeforces Round 592 (Div. 2)")

Suppose that the maximum value in the resulting array should be $R$, and the minimum value should be $L$. Let's estimate the required number of operations to make an array with such properties. All elements that are less than $L$ should be increased to $L$, and all elements that are greater than $R$ should be decreased to $R$ — and we don't have to do any operation with remaining elements.

Now we claim that either $L$ or $R$ should belong to the initial array. Why so? Suppose we constructed an answer such that $L \notin A$ and $R \notin A$. If the number of elements we increased to $L$ is not less than the number of elements we decreased to $R$, then we could construct the answer with minimum equal to $L - 1$ and maximum equal to $R - 1$, and it would not require more operations. And if the number of elements we increased to $L$ is less than the number of elements we decreased to $R$, then we construct the answer for $L + 1$ as minimum and $R + 1$ as maximum. So we can shift the range $[L, R]$ so that one of its endpoints belongs to the initial array.

Now we can solve the problem as follows: iterate on the maximum in the resulting array and find the largest minimum we can obtain with binary search, and then do it vice versa: iterate on the minimum in the resulting array and find the largest maximum we can obtain with binary search. To check how many operations we need, for example, to make all values not less than $L$, we can find the number of elements that we have to change with another binary search (let the number of such elements be $m$), and find their sum with prefix sums (let their sum be $S$). Then the required number of operations is exactly $Lm - S$. The same approach can be used to find the number of operations to make all elements not greater than $R$.

This is the way the problem was supposed to solve, but, unfortunately, we failed to find a much easier greedy solution.

 
### [1244F - Chips](../problems/F._Chips.md "Codeforces Round 592 (Div. 2)")

The main observation for this problem is the following: a chip changes its color if and only if both of its neighbours have the opposite colors (so, a W chip changes its color only if both of its neighbours are B, and vice versa). Let's denote such chips as unstable, and also let's denote an unstable segment as a maximum by inclusion sequence of consecutive unstable chips.

Let's analyze each unstable segment. If it covers the whole circle, then the whole circle changes during each iteration, so the answer depends on whether $k$ is odd or even.

Otherwise the unstable segment we analyze is bounded by two stable chips. When the first chip in the unstable segment changes, its color becomes equal to the color of its neighbour that does not belong to the unstable segment. We can also say the same for the last chip. So, during each iteration all chips in the unstable segment change their colors, and after that, the segment shrinks (the first and the last chip become stable and won't change their colors anymore).

All that's left is to find all unstable segments and analyze how they change.

 
### [1244G - Running in Pairs](../problems/G._Running_in_Pairs.md "Codeforces Round 592 (Div. 2)")

First of all, let's understand which values of $sum$ we can obtain at all. Obviously, the minimum possible value of $sum$ is $mn = \frac{n(n+1)}{2}$. The maximum possible value of $sum$ is $mx = (\lceil\frac{n}{2}\rceil + 1 + n) \cdot \lfloor\frac{n}{2}\rfloor + n \% 2 \cdot \lceil\frac{n}{2}\rceil$. We can obtain every possible value of $sum$ between $mn$ and $mx$ and we will show how to do it below.

If $k < mn$ then the answer is -1 (and this is the only such case). Otherwise, the answer exists and we need to construct it somehow. Firstly, suppose that the first permutation is identic permutation ($1, 2, \dots, n$) and the only permutation we change is the second one. Initially, the second permutation is also identic. Now we have $sum = mn$ and we need to change it to $sum = k$ or to the maximum possible number not greater than $k$. To do that, let's learn how to increase $sum$ by one. Let's see what will happen if we swap $n$ and $n-1$. Then the value of $sum$ will increase by one. If we swap $n$ and $n-2$ then the value of $sum$ will increase by $2$, and so on. If we swap $n$ and $1$ then the value of $sum$ will increase by $n-1$. 

So, the following constructive algorithm comes to mind: let's carry the current segment of permutation $[l; r]$ we can change (it is always segment because after some swaps some leftmost and rightmost elements cannot increase our answer because they're will be already placed optimally) and the value $add$ we need to add to $sum$ to obtain the maximum possible sum not greater than $k$. Initially $l=1, r=n, add = k - mn$. Now let's understand the maximum value by which we can increase the value of $sum$. Now it is $r-l$. If this value is greater than $add$ then let's swap $p_r$ and $p_{r - add}$, and break the cycle ($p$ is the second permutation). Otherwise, let's swap $p_l$ and $p_r$, decrease $add$ by $r-l$ and set $l := l + 1, r := r - 1$ . If at some moment $l$ becomes greater than or equal to $r$ then break the cycle.

Now we got the second permutation $p$ with the maximum possible value of $sum$ not greater than $k$, we can calculate the numeric answer (or print $min(mx, k)$), print identic permutation and the permutation $p$.

