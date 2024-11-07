# Tutorial_(ru)

Tutorial is loading... 
### [1031B - Curiosity Has No Limits](https://codeforces.com/contest/1031/problem/B "Technocup 2019 - Elimination Round 2")

Let's solve the problem for $0 \leq a_i, b_i, t_i \leq 1$, that is, for binary sequences. There are two options for $t_1$, the remaining part can be determined one number by one after this:

* If $t_1 = 0$ and $a_1 = 0$ and $b_1 = 0$ then $t_2$ = 0;
* If $t_1 = 0$ and $a_1 = 0$ and $b_1 = 1$ then there is no such $t_2$.
* If $t_1 = 0$ and $a_1 = 1$ and $b_1 = 0$ then $t_2$ = 1;
* If $t_1 = 0$ and $a_1 = 1$ and $b_1 = 1$ then $t_2$ = 1;
* If $t_1 = 1$ and $a_1 = 0$ and $b_1 = 0$ then there is no such $t_2$.
* If $t_1 = 1$ and $a_1 = 0$ and $b_1 = 1$ then there is no such $t_2$.
* If $t_1 = 1$ and $a_1 = 1$ and $b_1 = 0$ then $t_2$ = 0;
* If $t_1 = 1$ and $a_1 = 1$ and $b_1 = 1$ then $t_2$ = 1;

One can similarly find all other $t_i$-s ($3 \leq i \leq n$) or get a contradiction.

For bitwise operations from the statement one can solve the problem independently for every bit and restore the original sequence $t_1, t_2, \ldots, t_n$.

 
### [1031C - Cram Time](https://codeforces.com/contest/1031/problem/C "Technocup 2019 - Elimination Round 2")

Consider any answer with maximal $n + m$. If we used numbers $d_1, d_2, \ldots, d_k$ ($d_i \gt n + m$), then we didn't use some numbers $h_1, h_2, \ldots, h_k$ ($h_i \leq n + m$). Replacing all $d_i$ by $h_i$ ($1 \leq i \leq k$) doesn't violate the restriction. That means that we can assume that the answer consists of all numbers from $1$ to $x$, and $x = n + m$. The sum of all numbers from $1$ to $x$ equals $\frac{x(x + 1)}{2}$. It's clear that the following inequality must hold: $\frac{x(x + 1)}{2} \leq a + b$. Let's find the maximal $x$ for which it's true. The answer can't exceed $x$, and we can build the answer for $x$ iteratively. Let's iterate over all lecture notes from $x$ to $1$, and on each step we put it into the first day if we can, otherwise if in the first day we have $w > 0$ free time then we put the lecture note $w < x$ to the first day. All other lecture notes can be read during the second day since the either there are none of them, or the first day is full and hence the second day contains a sufficient amount of hours to read'em all.

 
### [1031D - Minimum path](https://codeforces.com/contest/1031/problem/D "Technocup 2019 - Elimination Round 2")

First, let's find the number of a-s in the beginning of the answer. To do this one can calculate dp[i][j] standing for the minimal number of non-a-s among all paths from the initial corner to (i, j). The number of a-s is simply the greatest $(i + j)$ among all pairs $(i, j)$ such that $dp[i][j]\le k$ (or $0$, if there are no).

Consider all cells where we can go right after obtaining the prefix of a-s. Now we repeat the following: append the minimal symbol in these cells to the answer, choose those cells and go from them in both possible directions to obtain the new set of cells. One can see that the answer we obtain is indeed the required answer.

 Tutorial is loading... Tutorial is loading... 
### [1071E - Rain Protection](../problems/E._Rain_Protection.md "Codeforces Round 517 (Div. 1, based on Technocup 2019 Elimination Round 2)")

First, let's find out if we can catch all raindrops for a fixed speed $v$.

Assume that the endpoints are at $(e_1, 0)$ and $(e_2, h)$ at any moment. Consider the point $(e_1, e_2)$ for this state (we call it the state point for this state). From now on we work with these points. We know that this state point can move with speed at most $v$ in both directions independently, that is, if the state point is $(x, y)$ at the moment $t$, then it'll be in $[x - v\cdot\text{d}t, x + v\cdot\text{d}t]\times[y - v\cdot\text{d}t, y + v\cdot\text{d}t]$ at the moment $t + \text{d}t$.

It turns out that for each $i$ one of the following takes place:

* we cannot catch raindrops from $1$ to $i$;
* we can catch these raindrops and there is exactly one possible option for the state point at the moment $t_i$;
* we can catch these raindrops and there is a segment on the plane such that the state point at the moment $t_i$ can be in any point of this segment and nowhere else.

Indeed, we prove this by induction. Its basis for $t_0 = 0$ is trivial. Let's prove its step.

* If we cannot catch raindrops from $1$ to $i$ then we cannot catch all raindrops from $1$ to $i + 1$.
* If there is some segment where the state point can be at $t_i$ (possibly a segment of length $0$) then at the moment $t_{i+1}$ the state point can be anywhere inside the convex hull of the union of two squares. The squares are $[x - v\cdot\text{d}t, x + v\cdot\text{d}t]\times[y - v\cdot\text{d}t, y + v\cdot\text{d}t]$ for the endpoints $(x, y)$ of the segment at $t_i$, and here $\text{d}t$ is $t_{i + 1} - t_i$.But we also know that the rope must contain one particular point at the moment $t_{i+1}$, which can be expressed as a linear equation of the state point at the moment $t_{i+1}$. So to obtain the required segment for $t_{i+1}$ one should intersect a line with a convex hull of $8$ points (which is in fact no more than a hexagon).

However, it's not all: the endpoints of the rope mustn't leave the rails which means that the convex hull should be first intersected with the rectangle $[0, w]\times[0, w]$. However, it can be done after intersecting with the required line.

So the solution now is the following:

* First we check if the answer is $-1$. This is the case when there is a triple of non-collinear raindrop points which should be on the rope simultaneously or there is a raindrop which is not on the rope at the moment $0$, while it should be. The simplest way to check it is to check if we can catch all raindrops with speed $w$. First, it involves no case handling; second, we will use this function later anyway.
* After this we run a binary search to find the minimal possible value for speed in such a way that it's possible to catch all the raindrops.

That's the idea of the solution. Now let's consider precision issues.

The explanation below contains some notions which may be new for a particular reader. Please don't be afraid of them, I explain what they mean right after introducing them. I refer to them by their names first for readers familiar with these notions to get the point faster and maybe skip the explanation which follows. For anyone who doesn't want to read the full proof and wants to know the summary: long double precision should be enough to get AC with the solution above (handling lines intersections properly).

Define a function $f_i(v)$ as the $\ell_{\infty}$-diameter of the set of possible locations of the state point at the moment $t_i$ for the speed $v$, that is,

* $f_i(v) = 0$ if this set is empty or consists of a single point;
* $f_i(v) = \max\left(|x_1 - x_2|, |y_1 - y_2|\right)$ if this set is a segment between $(x_1, y_1)$ and $(x_2, y_2)$.

In other words, every time we calculate the length of any segment, we do it in this metric, since it'll be convenient for our purposes.

Let $\hat{v}$ be the correct answer, and let $\varepsilon$ be a sufficiently small positive number (but still much bigger than the machine epsilon, of course).

One can see that all $t_i$-s can be divided into two groups which differ a lot by their meaning:

* those for which we must catch one raindrop at this moment (or many equal raindrops, which doesn't matter),
* those for which we must catch more than one raindrop at this moment.

For the first ones we basically need to intersect a polygon with a line, but for the second ones the state point at $t_i$ can be determined and doesn't depend on the speed (or such $t_i$-s force our algorithm to tell that the goal is impossible in the very beginning). Let's call the raindrops with $t_i$ of the first type simple, and the others complicated.

Let's prove the following lemmas:

Lemma 1a. Let $i$ be an index of a simple raindrop. For $v = \hat{v} + \varepsilon$ each $f_i(v)$ is at least $\varepsilon$.

Lemma 1b. Let $i$ be an index of a complicated raindrop. For $v = \hat{v} + \varepsilon$ the corresponding state point position at the moment $t_i$ is at least $\varepsilon$ away from the border of a polygon before intersecting with $[0, w]\times[0, w]$.

Lemma 2. Let $idx$ be the index of the first raindrop we cannot catch for a value of speed which is very close to $\hat{v}$ but is less than it. Then for $v = \hat{v} - \varepsilon$ either our algorithm halts earlier than it handles the $idx$-th raindrop, or the corresponding line to this raindrop (or the corresponding point if the raindrop is complicated) is at least $\varepsilon$ away from the corresponding state points polygon (again, in $\ell_{\infty}$ metric).

One can see that proving these lemmas is sufficient to validate the solution. Indeed, comparing all intersections with quite good precision will move the binary search borders into the $(\hat{v} - \varepsilon, \hat{v} + \varepsilon)$ interval which is enough to stop for some $\varepsilon$.

Proof of lemma 1 (both variations). Fix $i$. We know that the $(i-1)$-th set $S_{i-1}(v)$ of possible state points for $v = \hat{v}$ is not empty (from the definition of $\hat{v}$). It's clear that the $(i-1)$-th set for $v = \hat{v} + \varepsilon$ is a superset of $S_{i-1}(\hat{v})$, because we can move no faster than with the speed of $\hat{v} < \hat{v} + \varepsilon$. To get $S_i$, we move from $S_{i-1}$ no more than $(t_i - t_{i-1})(\hat{v} + \varepsilon) \le (t_i - t_{i-1})\hat{v} + \varepsilon$. This finishes the proof of 1b. Since $S_i(\hat{v})$ is also not empty, $S_i(\hat{v} + \varepsilon)$ is at least the segment $S_i(\hat{v})$ plus all the points on the corresponding line at the distance no more than $\varepsilon$, that is, at least $\varepsilon$ longer than $S_i(\hat{v})$, hence is at least $\varepsilon$ long, qed.

Proof of lemma 2. Assume our algorithm made at least $idx$ iterations. Consider the corresponding polygon at the moment $t_{idx}$. We know that for $v = \hat{v}$

* this polygon intersects the required line/point, but
* its interior doesn't.

That means that each point of the possible set of state points at the moment isn't inside the polygon. That means that if we reduce $v$ by $\varepsilon$ then the distance from every point of this set to the polygon is at least $\varepsilon$, qed.

To summarize, the only precision issue we can meet is when we intersect two or more lines for complicated raindrops. This part can be implemented in integers, but let's dive into this anyway.

One can see that catching raindrop at $(x, y)$ means that

$$\frac{y}{x - e_1} = \frac{h - y}{e_2 - x},$$

or

$$(e_2 - x)y = (x - e_1)(h - y)\Rightarrow e_1(h-y) + e_2y = xh.$$

Since the coefficients of this line equation are of order $h$, the coordinates of its solution are some rationals with the denominator of order $1/h^2$. If we then want to check if such point belongs to another line, we want to compare some integer divided by another integer which is $\le h^2$ with the third integer, so we need an epsilon less than $1/h^2$.

