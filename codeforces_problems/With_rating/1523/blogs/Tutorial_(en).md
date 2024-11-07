# Tutorial_(en)


### [1523A - Game of Life](../problems/A._Game_of_Life.md "Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)")

Notice that evolution will go on for no more than $n$ iterations, since on each iteration at least one new living cell will appear, and if it doesn't this would mean that we remain in the same state as on the previous step and the simulation is over. Knowing this we can write a simple simulation of the process described in the problem statement, which would process each iteration in $O(n)$.

Final complexity: $O(n^2)$.

**Prepared by** [Vladik](https://codeforces.com/profile/Vladik "Master Vladik"). 

 
### [1523B - Lord of the Values](../problems/B._Lord_of_the_Values.md "Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)")

Notice that for transforming any pair of numbers $(a, b)$ into a pair $(-a, -b)$ a sequence of operations such as $(1, 2, 1, 2, 1, 2)$ can be performed. Since $n$ is even we can apply this sequence of operations for all pairs of numbers $(a_{i \cdot 2 - 1}, a_{i \cdot 2})$ for all $i$ from $1$ to $\frac{n}{2}$.

Final complexity: $O(n)$.

**Prepared by** [AleXman111](https://codeforces.com/profile/AleXman111 "Candidate Master AleXman111"). 

 
### [1523C - Compression and Expansion](../problems/C._Compression_and_Expansion.md "Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)")

Let's maintain the current depth of the list in a stack. Initially the stack is empty. For each new $a_i$ there are two options:

1. $a_i=1$. In this case we just add the given number to the end of the stack and it will point to a new subitem in the list.
2. $a_i > 1$. In this case we need to find the subitem, the last number of which will be one less than $a_i$. To do this we will remove the last elements from a stack until we find this number.

After this at the end of each iteration we will print the resulting stack as a new item in the list. Note that due to outputting the whole list the complexity will be quadratic.

Final complexity: $O(n^2)$.

**Prepared by** [netman](https://codeforces.com/profile/netman "Candidate Master netman"). 

 
### [1523D - Love-Hate](../problems/D._Love-Hate.md "Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)")

Notice that the final answer will be a submask of one of $\lceil \frac{n}{2} \rceil$ friends. Knowing this, random generation may be used to pick a random mask. If we check a randomly-generated index 50 times then the probability of not hitting a single index of a friend from the required group is $(\frac{1}{2})^{50}$. This probability is 1125899906 times smaller than the probability of the contestant being hit by a falling meteorite, i.e. insignificant. 

Now that we have some basis mask $mask$ we can calculate the maximal answer for it. To do this let's "compress" each mask for each friend to a size no larger than $p$ by only keeping those true bits which are also true in $mask$. Now for each mask $s$ of length $p$ we can calculate $cnd_{s}$ which is the number of friends that like this mask. For each mask $cnt_{s}$ is the sum of all $cnt_{msk}$ such that s is a submask of $msk$. We can brute force all submasks in $O(3^p)$ by using an algorithm found $\href{https://cp-algorithms.com/algebra/all-submasks.html}{here}$. Now all we have to do is to pick the $best$ mask for which $\lceil \frac{n}{2} \rceil \le cnt_{best}$ and which has the largest number of true bits in its uncompressed state.

Final complexity: $O(iters \cdot p \cdot (2^p + n))$ or $O(iters \cdot (3^p + n \cdot p))$, depending on the implementation.

**Prepared by** [Vladik](https://codeforces.com/profile/Vladik "Master Vladik"). 

 
### [1523E - Crypto Lights](../problems/E._Crypto_Lights.md "Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)")

Let's consider all states of the device where $p$ lights are turned on, and when at the current moment the algorithm has not yet finished working. We will be checking all values for $p$ from 1 to $n$.

Notice that for a state where $p$ lights are turned on the probability of getting to that state is $\frac{p!}{n \cdot (n - 1) \cdot (n - 2) \dots (n - p - 1)}$. Now for a new value of $p$ we need to calculate the number of fitting states. Without the condition about having a distance of $k$ between the lights this number would be equal to the number of ways to split the lights into $p$ groups, which is $C(n-1, p-1)$.

Next we can notice that each group must also contain $k-1$ elements to provide the necessary distance. Then the number of "free" cells necessary to select an arrangement of groups will be $n - (k - 1) \cdot (p - 1)$. Then the final quantity of arrangements will be $C(n - (k - 1) \cdot (p - 1), p - 1)$. The final sum of these quantities, multiplied by the probability of getting each one will be the answer.

**Prepared by** [AleXman111](https://codeforces.com/profile/AleXman111 "Candidate Master AleXman111"). 

 
### [1523F - Favorite Game](../problems/F._Favorite_Game.md "Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)")

For convenience we will sort quests by time.

Let's make two DP:

$F(mask, done_q)$ — minimum amount of time it takes to visit the set of $mask$ towers and complete $done_q$ quests. William is in one of the towers.

$G(mask, q)$ — maximum number of quests that William can complete if he visited a set of $mask$ towers, and the last completed quest is quest number $q$. It is assumed that the current time for this state is equal to $t_q$ and William is at the coordinate $(xb_q, yb_q)$.

DP transitions will be as follows:

Transition describing a visit to the new tower $tower_{new}$, assumed that William was in the tower before:

$F(mask, done_q) + distance_{tower}(mask, tower_{new}) \underset{minimize}{\rightarrow} F(mask \cup tower_{new}, done_q)$, $tower_{new} \notin mask$,

where $distance_{tower}(mask, tower_{new})$ — minimum distance among all towers from the set $mask$ to the tower $tower_{new}$.

Transition describing a visit to a new quest, assumed that William was in the tower before:

$(done_q + 1) \underset{minimize}{\rightarrow} G(mask, q)$, only if $F(mask, done_q) + distance_{quest}(mask, q) \leq t_q$,

where $distance_{quest}(mask, q)$ — minimum distance among all towers from the set $mask$ to the quest $q$.

Transition describing visiting a new quest immediately after the old one, without visiting new towers:

$G(mask, q) + 1 \underset{minimize}{\rightarrow} G(mask, q_{new})$, only if $t_q + min(distance(q, q_{new}), distance_{quest}(mask, q_{new})) \leq t_{q_{new}}$,

where $distance(q, q_{new})$ — distance between two quests (without instant travel), 

$min(distance(q, q_{new}), distance_{quest}(mask, q_{new}))$ — choosing the optimal route: either directly to the quest, or through the tower.

Transition describing a visit to a new tower, immediately after William visited quest number $q$:

$t_q + min(distance(q, tower_{new}), distance_{tower}(mask, tower_{new}) \underset{minimize}{\rightarrow} F(mask \cup tower_{new}, G(mask, q))$, $tower_{new} \notin mask$,

where $distance(q, tower_{new})$ — distance from quest number $q$ to tower number $tower_{new}$,

$distance_{tower}(mask, tower_{new})$ — minimum distance from one of the towers from the set $mask$ to the tower $tower_{new}$.

Initial states will be:

$G(0, q) = 1$, for each quest $q$ — William can choose any starting coordinate. Therefore, he can choose to start at the coordinate with the quest and wait for it.

All other states initialized as $G = -\infty$.

$F(\{tower\}, 0) = 0$, for each tower $tower$ — William can choose any starting coordinate. Therefore, he can choose the coordinate of the tower and be in it at time $0$.

All other states initialized as $F = \infty$.

Answer:

The answer is the maximum value among all $G(mask, q)$.

Time complexity:

There are $O(2^N \cdot M)$ states in total. From each state there are $O(N + M)$ transitions. Hence the time complexity is $O(2^N \cdot M \cdot (N + M))$.

**Prepared by** [netman](https://codeforces.com/profile/netman "Candidate Master netman"). 

 
### [1523G - Try Booking](../problems/G._Try_Booking.md "Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)")

Note that if you think of the answer as the number accepted offers for rent, the sum of the answers in the worst case will be no more than $\frac{n}{n}+\frac{n}{n - 1}+\ldots+\frac{n}{1}$. This value can be estimated in $n \cdot log (n)$. So for each $i$ we can try to learn how to process only those offers that are actually included in the answer for this $i$.

Let's learn how to solve the problem recursively for a fixed $i$ and assume that all segments have a length of at least $i$. The recursion will contain two parameters $l$ and $r$ — a continuous segment of days on which all days are still free. Now, if we learn how to find an offer with a minimum $id$ for the segment $l$ and $r$ such that $l \le l_{id} \le r_{id} \le r$, then we can solve our problem. We will only need to recursively find the answer for $l..l_{id}-1$ and $r_{id}+1..r$.

To find the minimum $id$ , you can use a 2D data structure that supports the following queries: 

* Get: Minimum on the prefix matrix (one of the corners of the submatrix lies in the cell $(1, 1)$). The minimum can be found on the prefix matrix because we are dealing with segments for which the condition $l \le r$is is satisfied.
* Update: Updates the value in the cell $(x, y)$ by a strictly smaller number than it was there before.

In the author's solution such a data structure was a 2D segments tree.

We can iterate $i$ from $n$ to $1$ so that we only need to add new segments.

Total complexity $O (n \cdot log (n)^3 + m \cdot log(n)^2)$.

**Prepared by** [Vladik](https://codeforces.com/profile/Vladik "Master Vladik").

 
### [1523H - Hopping Around the Array](../problems/H._Hopping_Around_the_Array_.md "Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)")

Let's look into all jumps in the optimal answer except the last one with $k = 0$. Thereafter, from the position $i$ it is most effective to jump at such position $best$ that: $i \le best \le i+a_i$ and $a_{best} + best$ is the maximal possible. For each $i$ we can use a segment tree for maximum to find that optimal $best$.

Let's also notice that if we want to jump from position $i$ having done $x$ removals of cells which indices are from $i+1$ to $a_i+i$, then we want to end up in a cell $a_i+i+x$, because we can do fewer removals otherwise.

These observations are sufficient for us to use the idea of dynamic programming. Let $dp[t][i][k]$ store the maximal pair $(a_j + j, j)$ in which we can end up jumping from position $i$, having performed $2^t$ jumps and removed not greater than $k$ cells. With $t=0$ we can initialize the dynamic with optimal $best$. Now we will iterate over $t$, $i$ and $k$ in increasing order and see how to recalculate the dynamic. Let's iterate over $k1$ — the number of removals for the first $2^{t-1}$ jumps. Then, using the value $dp[t-1][i][k1]$ we know in which position we stopped. Now we need to perform $2^{t-1}$ jumps from that position having done not greater than $k-k1$ removals.

Additionally, let's make another dynamic $imax[t][i][k]$ — stores such maximal position of initial array in which we can end up jumping from position $i$, having performed $2^t$ jumps and removed not greater than $k$ cells. Just like for the previous dynamic we can initialize it using $best$, and then similarly recalculate the value of the dynamic, but using two dynamics this time — $imax$ and $dp$.

It is noteworthy that both dynamics need it to be supposed that when we start in element $i$ we do not remove it.

Let's see how we can answer the query using the calculated dynamics. To begin with, let's consider particular cases. If $l=r$, then the answer is equal to $0$. If $a_l + l + k \ge r$, then the answer is equal to $1$. Farther on, let's make one more dynamic $now_j$, in which we will maintain three numbers $(cnt, a_i + i, i)$. With that the first number is the number of jumps (we minimize it), two following numbers declare our current position $i$, and we maximize these two numbers as a pair $(a_i + i, i)$. Using that dynamic we wish to end up in the last but one cell of the optimal way, having removed not greater than $j$ cells. Initially, the values of dynamic are equal to $(0, a_l + l, l)$. Let's iterate over $t$ in decreasing order (which is to say, we iterate over the $2^t$ jumps). Let's create a dynamic $go$, which we are going to recalculate on the current step, and then make $now=go$ (in other words, we recalculate the dynamic $now$). Let's iterate over $k1$ — the number of removals during the preceding steps and $k2$ — the number of removals we are going to do on the current step. Using the value $now_{k1}$ we know in which position we stopped, and with dynamic $imax$ we can check if we cannot overjump $r$ (or end up in it) having performed $2^t$ jumps. If we cannot overjump $r$, then we will try to update the value $go_{k1+k2}$, otherwise, it's not profitable to perform the jump and thus let's update $go_{k1}$.

As a result, we have the calculated dynamic $now_j$. Let's iterate over it and find $j$-s such that we can jump to $r$ with one jump and take the minimal answer over these $j$-s (don't forget to add $1$, since we jumped to the last by one cell in the dynamic).

We calculate the dynamics in $O(n \cdot k^2 \cdot log(n))$, answer the query in $O(k^2 \cdot log(n))$, thus the solution is in $O((n + q) \cdot k^2 \cdot log(n))$. 

**Prepared by** [74TrAkToR](https://codeforces.com/profile/74TrAkToR "Grandmaster 74TrAkToR"). 

