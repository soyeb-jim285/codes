# Tutorial_(en)

Preliminary, changes to come possibly.

 
### [996A - Hit the Lottery](../problems/A._Hit_the_Lottery.md "Codeforces Round 492 (Div. 2) [Thanks, uDebug!]")

The problem is to minimize $x_1 + x_2 + x_3 + x_4 + x_5$ given that $x_1 + 5x_2 + 10x_3 + 20x_4 + 100x_5 = n.$ It is pretty simple to see that we can operate greedily: take as many $100$ as we can, then $20$, then $10$, etc.

The solutions works because each number in the sequence $1, 5, 10, 20, 100$ is a divisor of the number after it.

 
### [996B - World Cup](../problems/B._World_Cup.md "Codeforces Round 492 (Div. 2) [Thanks, uDebug!]")

For gate $k$ (where $1 \le k \le n$) we visit the gate at times $k, k+n, k+2n, \cdots$ Therefore, the earliest Allen could enter from gate $k$ is the time $k + tn$ such that $k + tn \ge a_k.$ Now, for each $k$, compute the minimal integer $b_k = k+tn$ such that $k+tn \ge a_k$. Now, find the integer $k$ with minimum $b_k$ and output $k$.

 
### [995A - Tesla](https://codeforces.com/contest/995/problem/A "Codeforces Round 492 (Div. 1) [Thanks, uDebug!]")

First, whenever any cars are directly to their parking spot, we should move them into the correct parking spot.

Now, we can view rows $2$ and $3$ as a cycle. In at most $k$ moves, we can spin the entire cycle of cars counterclockwise. By repeating this $2n$ times, each car will have been adjacent to each parking space, and will have had some chance to park.

The exception to this rule is when there are no empty spaces in rows $2$ and $3$. In this case, no cars can even make a valid move, so the answer is $-1$. (This requires $k = 2n$ and no cars are initially adjacent to their parking space)

This process will can be implemented in $O(nk)$ or $O(n^2)$ time, with at most $2nk + k \le 10100$, which fits below the $20000$ move limit. 

 
### [995B - Suit and Tie](https://codeforces.com/contest/995/problem/B "Codeforces Round 492 (Div. 1) [Thanks, uDebug!]")

We describe a greedy algorithm that achieves the minimum number of swaps.

If the leftmost person is in pair $a$, swap the other person in pair $a$ left, to the second position. Now the first two people are both in pair $a$, and we repeat the process on the remaining $n-1$ pairs of people recursively.

We now prove that this number of swaps is optimal, and we accomplish this by showing that every swap we made is 'necessary'.

For two pairs numbered $a$ and $b$, we can consider the number of times people of pair $a$ and $b$ are swapped by our process. There are $3$ possible relative orderings: $a a b b$, $a b a b$, and $a b b a$.

In the case $a a b b$, our algorithm will never swap $a$ and $b$.

In the case $a b a b$, any correct swap sequence must swap $a$ and $b$ at least once, and our algorithm will swap the second $a$ left of the first $b$ when $a$ is the leftmost person.

In the case $a b b a$, any correct swap sequence must swap $a$ and $b$ at least twice, and our algorithm will swap the second $a$ left of both $b$ when $a$ is the leftmost person.

Therefore every swap in our greedy algorithm is necessary, so it is optimal.

We can directly simulate this algorithm in $O(n^2)$ time. We can also use data structures such as a binary indexed tree, or balanced binary search tree to compute the answer in $O(n \log n)$. (Maybe it can be even done in $O(n)$, anyone?).

 
### [995C - Leaving the Bar](https://codeforces.com/contest/995/problem/C "Codeforces Round 492 (Div. 1) [Thanks, uDebug!]")

We first prove a claim which will help us significantly. The claim is that among any three vectors $\vec{v_1}, \vec{v_2}, \vec{v_3}$ of lengths at most $r$, then some sum $\vec{v_i} + \vec{v_j}$ or difference $\vec{v_i} - \vec{v_j}$ has at length at most $r$.

Draw a circle with radius $r$ centered at the origin. If we plot the vectors $\vec{v_1}, \vec{v_2}, \vec{v_3}, -\vec{v_1}, -\vec{v_2},-\vec{v_3}$ from the origin, two of these will lie in the same $60^{\circ}$ sector. Any two points in this sector will have distance at most $r$.

Therefore, as long as there are at least $3$ vectors, two of them can be combined and the input constraints will still be satisfied. In the final step, we can combine two vectors of length at most $r$ into one of length at most $\sqrt{2} r$.

Implementation can be done in a number of ways: for example, constructing a binary tree with the input vectors as leaves, or maintaining sets of signed vectors and merging small sets to large sets. These approaches can take $O(n)$ or $O(n \log n)$.

 
### [995D - Game](https://codeforces.com/contest/995/problem/D "Codeforces Round 492 (Div. 1) [Thanks, uDebug!]")

One can show by induction that the expected value of the game is $\mathbb{E}[f] = 2^{-n} \sum_{x \in \{0, 1\}^n} f(x)$.

Consider the first turn. For notation, let $v_{i, 0}$ be the expected value of the game when $x_i$ is set to $0$, and let $v_{i, 1}$ be the expected value of the game when $x_i$ is set to $1$. By induction, it is easy to see that $\frac{v_{i, 0} + v_{i, 1}}{2} = \mathbb{E}[f].$

Consider Allen's strategy. If it is Allen's turn, he will set $x_s = t$, where $0 \le s < n, 0 \le t \le 1$ are such that $v_{s, t}$ is maximal. As $\frac{v_{i, 0} + v_{i, 1}}{2} = \mathbb{E}[f]$ for all $i$, it is clear that $v_{s, 1-t}$ is actually minimal among all the $v_{i, j}$. This means that Bessie would have chosen to set $x_s = 1-t$ if it were her turn. Therefore, the expected game value is $\frac{v_{s, t} + v_{s, 1-t}}{2} = \mathbb{E}[f].$

 
### [995E - Number Clicker](https://codeforces.com/contest/995/problem/E "Codeforces Round 492 (Div. 1) [Thanks, uDebug!]")

Our first observation is that the game can be modeled the following way. Construct an undirected graph on $\{0, 1, \dots, p-1\}$ such that $i$ is connected to $i-1, i+1,$ and $i^{p-2} \pmod{p}.$

We want to find a path of length at most 200 between $u$ and $v$ in this graph. Running a BFS will take too long, so we need different techniques. We present two solutions, which both essentially use the fact that the graph is almost "random". This follows from some known number theoretic results on expander graphs (keyword is "Margulis expanders").

Solution 1: Generate $\sqrt{p}$ random paths of length $100$ from vertex $u$. Now, generate random paths from $v$ of length $100$ until some pair of endpoints coincide. By the birthday paradox, assuming that the graph is approximately random, the runtime will be $O(\sqrt{p} \log p).$

Solution 2: We can try running a simultaneous BFS from both directions (starting at $u$ and $v$). When they meet, make that path. If you are careful, it should be possible to cover $\le 10^7$ vertices, which should then run in time.

Additionally, our tester found a different solution. It suffices to find a path from $u \to 1$ of length $100.$ The way we do this is: pick a random $x \pmod{p}.$ Now run the Euclidean algorithm on $(ux \pmod{p}, x)$, using operation $2$ for a normal subtraction step, and a $3$ for the flipping the two entries step. It happens to take a few steps in most cases, but we have no proof.

 
### [995F - Cowmpany Cowmpensation](https://codeforces.com/contest/995/problem/F "Codeforces Round 492 (Div. 1) [Thanks, uDebug!]")

A immediate simple observation is that we can compute the answer in $O(nD)$ with a simple dynamic program. How to speed it up though?

To speed it up, we need the following lemma.

Lemma 1: For a tree with $n$ vertices, the answer is a polynomial in $D$ of degree at most $n$.

We can prove this via induction, and the fact that for any polynomial $p(x)$ of degree $d$, the sum $p(0) + p(1) + \dots + p(n)$ is a polynomial in $n$ of degree $d+1.$

Now the solution is easy: compute the answer for $0 \le D \le n$ and use interpolation to compute the answer for $D > n.$ The complexity is $O(n^2)$ for the initial dp and $O(n)$ for the interpolation step.

