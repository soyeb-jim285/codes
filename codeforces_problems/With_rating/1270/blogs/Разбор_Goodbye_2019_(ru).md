# Разбор_Goodbye_2019_(ru)

We hope you liked problems!

We are sorry for some passing wrong solutions for problems G & H.

 
### [1270A - Card Game](../problems/A._Card_Game.md "Good Bye 2019")

We can show that the player who has the largest card (the one with value $n$) has the winning strategy! Indeed, if a player has the card with value $n$, he can choose to play it every time, taking the card from the opponent every time (as every other card has a value smaller than $n$). In at most $n-1$ moves, the opponent will be out of cards (and he will lose).

[Solution](https://codeforces.com/https://pastebin.com/EsZDxZ7g)

 
### [1270B - Interesting Subarray](../problems/B._Interesting_Subarray.md "Good Bye 2019")

We will show that if some interesting nonempty subarray exists, then also exists some interesting subarray of length $2$. Indeed, let $a[l..r]$ be some interesting nonempty subarray, let $a_{max}$ be the maximal element, $a_{min}$ — minimal, without loss of generality, $max > min$. Then $a_{max} - a_{min} \ge r - l + 1 \ge max - min + 1$, or $(a_{max} - a_{max - 1}) + (a_{max - 1} - a_{max - 2}) + \dots + (a_{min+1} - a_{min}) \ge max - min + 1$, so at least one of the terms had to be $\ge 2$. Therefore, for some $i$ holds $a_{i+1} - a_i \ge 2$, so subarray $[i, i+1]$ is interesting!

Therefore, the solution is as follows: for each $i$ from $1$ to $n-1$ check if $|a_{i+1} - a_i|\ge 2$ holds. If this is true for some $i$, we have found an interesting subarray of length $2$, else such subarray doesn't exist.

Asymptotic $O(n)$.

[Solution](https://codeforces.com/https://pastebin.com/xfZSjjF5)

 
### [1270C - Make Good](../problems/C._Make_Good.md "Good Bye 2019")

Let the sum of numbers be $S$, and their $\oplus$ be $X$. 

Solution 1: If $S\le 2X$ and $S$ was even, it would be enough to add into the array $2$ numbers $\frac{2X-S}{2}, \frac{2X-S}{2}$: $X$ wouldn't change, and the sum would become $2X$.

How to achieve this? Let's add to the array number $2^{50} + (S\bmod 2)$. If new sum and $\oplus$ of all numbers are $S_1$ and $X_1$ correspondently, then we know, that $S_1\le 2\cdot 2^{50} \le 2X_1$, and $S_1$ is even. We spent $3$ numbers.

Solution 2: It's enough to add to the array numbers $X$ and $S + X$. Indeed, $S + X + (S+X) = 2(S+X)$, and $X\oplus X \oplus (S+X) = (S+X)$. We spent only $2$ numbers!

Both solutions have asymptotic $O(n)$ — to calculate $S$ and $X$.

Challenge: What is the smallest possible number of integers that we can add to the given array to make it good?

[Solution 1](https://codeforces.com/https://pastebin.com/pR3HvE4a)

[Solution 2](https://codeforces.com/https://pastebin.com/E7xJzFAJ)

 
### [1270D - Strange Device](../problems/D._Strange_Device.md "Good Bye 2019")

We will show how to guess $m$ with $k+1\le n$ queries.

Let's leave only first $k+1$ elements of the array. We will ask $k+1$ queries: $i$-th question — about all elements from $1$-th to $k+1$-th, except $i$-th. Denote elements from $1$-th to $k+1$-th in decreasing order as $b_1 < b_2 < \dots < b_{k+1}$. Then, if we throw out element which is larger than $b_m$, then $b_m$ is the $m$-th largest among remaining elements. If we throw out element which is smaller of equal to $b_m$, then $b_{m+1}$ is the $m$-th largest among remaining elements.

Therefore, among answers to our $k+1$ queries we will have $m$ times element $b_{m+1}$ and $k+1-m$ times element $b_m$. As $b_{m+1}>b_m$, we can first find $b_{m+1}$ (as the largest of all answers to the queries), and after that we can find $m$ as the number of times $b_{m+1}$ meets among these answers! 

[Solution](https://codeforces.com/https://pastebin.com/084Q6P0s)

 
### [1270E - Divide Points](../problems/E._Divide_Points.md "Good Bye 2019")

Let's divide all points into $4$ groups by parity of their coordinates: $A_{00}$ — (even, even), $A_{01}$ — (even, odd), $A_{10}$ —(odd, even), $A_{11}$ — (odd, odd). 

If all points belong to one group, for example, $A_{00}$, let's divide all coordinates by $2$ and start again. We just scaled down the image in $2$ times, and all distances between points also got smaller in exactly $2$ times, so any valid partition for new points remains valid for old points.

Note that this division by $2$ can't last long: as every division by $2$ decreases the distance between points in $2$ times, all the initial distances don't exceed $4\cdot 10^6$, and distances can't get smaller than $1$, we can't have more than $\log{4\cdot 10^6}$ such divisions.

From now on we suppose that at least two groups are nonempty. 

If there is at least one point with the odd sum of coordinates, and at least one point with even sum of coordinates, we can put to $A$ all points with even sum of coordinates, and to $B$ — all with odd. Then for any two points $(x_1, y_1), (x_2, y_2)$, the square of distance between them $(x_1 - x_2)^2 + (y_1 - y_2)^2$ will be even if these points are from the same group, and odd if they are from different groups. As square of every yellow number will be even, and of every blue odd, no blue number will be equal to any yellow, and the partition would be valid.

If all points have even sum of coordinates, then only points $A_{00}$ and $A_{11}$ will be nonempty. Then we can set $A = A_{00}, B = A_{11}$: in this case for any two points $(x_1, y_1), (x_2, y_2)$, the square of distance between them $(x_1 - x_2)^2 + (y_1 - y_2)^2$ will be divisible by $4$, if these points are from the same group, and will give remainder $2$ under division by $4$, if from different.

Similarly, if all points have odd sum of coordinates, then only points $A_{01}$ and $A_{10}$ will be nonempty. Then we can set $A = A_{01}, B = A_{10}$: in this case for any two points $(x_1, y_1), (x_2, y_2)$, the square of distance between them $(x_1 - x_2)^2 + (y_1 - y_2)^2$ will be divisible by $4$, if these points are from the same group, and will give remainder $2$ under division by $4$, if from different.

[Solution](https://codeforces.com/https://pastebin.com/r7LUrMa4)

 
### [1270F - Awesome Substrings](../problems/F._Awesome_Substrings.md "Good Bye 2019")

It will be easier for us to think that string is actually an array of ones and zeroes. Let's calculate array of preffix sums  — $pref[]$. It's easy to see that, substring $[l;r]$ will be awesome, iff $r - l + 1 = k \cdot (pref[r] - pref[l - 1])$ for some integer $k$. It's equivalent to $r - k \cdot pref[r] = l - 1 - k \cdot pref[l - 1]$. So, we must calculate number of pairs of equal integer in array $t[i] = i - k \cdot pref[i]$ for each $k$ from $1$ to $n$. Let's fix some number $T$ and note, that if $k > T$, then $pref[r] - pref[l - 1] = \frac{r - l + 1}{k} \le \frac{n}{T}$. In other words, in awesome substring number of ones or $k$ is not big. For $k \le T$ we can calculate number of pairs of equal integers in $O(nT)$. To do this, note that $-nT \le i - k \cdot pref[i] \le n$, so, independently for each $k$ we can put all numbers into one array and then calculate number of equal integers. After this, we can fix $l$ and iterate how many number of ones our string will contain(using this, we get bounds for $r$). Knowing number of ones, we'll know which remainder should give $r$. So, task comes down to calculate how many integeres on some segment give some fixed remainder if we divide them by some fixed integer. This can be calculated in constant time(but you should remember to count only such $r$ for whic $k > T$. This part works in $O(n \cdot \frac{n}{T})$. If we choose $T = \sqrt{n}$,we will get that our solution works in $O(n\sqrt{n})$(on practice, this solution easily fits in TL for $T$ from $300$ to $500$)

Also note, that if you use some data structures for the first part(like map or unordered_map in C++) and choose big $T$, your solution can get TL. TL wasn't big because of fast bruteforces.

P.S. I'm writing this one day before round and hope [user:MrDindows] will solve this task without bruteforce.

[Solution](https://codeforces.com/https://pastebin.com/hShfjtvN)

 
### [1270G - Subset with Zero Sum](../problems/G._Subset_with_Zero_Sum.md "Good Bye 2019")

Note that the condition $i-n \le a_i \le i-1$ is equivalent to $1 \le i - a_i \le n$.

Let's build an oriented graph $G$ on $n$ nodes with the following principle: for each $i$ from $1$ to $n$, draw an oriented edge from vertex $i$ to vertex $i - a_i$. In this graph, there is an outgoing edge from every vertex, so it has an oriented cycle. Let vertices of this cycle be — $i_1, i_2, \dots, i_k$.

Then:

$i_1 - a_{i_1} = i_2$

$i_2 - a_{i_2} = i_3$

$\vdots$

$i_n - a_{i_n} = i_1$

After adding all these equalities, we get $a_{i_1} + a_{i_2} + \dots + a_{i_k} = 0$

We can find some oriented cycle in $O(n)$ (just go by an available edge until you get to previously visited vertex).

[Solution](https://codeforces.com/https://pastebin.com/sBAJLSKG)

 
### [1270H - Number of Components](../problems/H._Number_of_Components.md "Good Bye 2019")

Firstly, note that all connected components form segments of sequential indexes. Indeed, let numbers $i$ and $j$ lie in one component and let's consider $i < x < j$. Because $i$ and $j$ lie in one component, there exists a path, which connects them: $v_1 = i, \ldots, v_t = j$, such that $v_k$ and $v_{k+1}$ are connected with an edge for any $k$. Then there exists $p$, such that $v_p < x < v_{p+1}$.But if $a_{v_p} < a_x$, then there exists an edge $xv_p$, otherwise there exists an edge between $x$ and $a_{v_{p+1}}$(because $a_x < a_{v_p} < a_{v_{p+1}}$).

So, because components are non-intersecting segments, there is no edge between $[l_1;r_1]$ and $[l_2;r_2]$, $l_1 \le r_1 < l_2 \le r_2$, iff $min_{x \in [l_1;r_1]}(a) > max_{x \in [l_2;r_2]}(a)$. That's why number of components is equal to number of $i$, such that $min_{x \in [1;i]}(a) > max_{x \in [i + 1; n]}(a)$, increased by $1$. So, our task is to calculate number of prefix minimums which are strictly greater than corresponding suffix maximums. To do this, let's set $a[0] = \infty$ and $a[n + 1] = 0$. After this let's consider some number $h$ and build new array $b$, such that $b[i] = 1$ iff $a[i] \ge h$. Then if $h = min_{x \in [1;i]}(a)$ for some suitable $i$, array $b$ looks like $11\ldots00$. On the other hand, if $b$ looks like $11..00$ for some $h = a[t]$, there exists a unique $i$ for which prefix minimum is greater than suffix maximum. So, we need to calculate number of $h$ for which array $b$ looks in a such way. Note, that array looks like this, iff number of adjacent pair of integers $b[t] \ne b[t + 1]$ is equal to one. Moreover, for any $h$ this number is at least one. Thus, we just need to maintain $f[h]$ (number of adjacent non-equal integers in array $b$) for all $h$ and calculate number of $h$ that have $f[h]$ equal to minimum. It can be done with segment tree, if we note that, if we change one position in array $a$, value $f[h]$ can change only because of integers $a[i - 1], a[i], a[i + 1]$. Then, changing $f[h]$ is addition of $\pm1$ on some segments. But we also need to remember, that we should count only values of $h$, which are equal to some integer in $a[]$(so if have query $pos, x$ we need to activate $h=x$ and deactivate $h=a[pos]$ in segment tree).

We are sorry for rather strict TL. This was done because with aim to cut off $O(n\sqrt{nlog(n)})$ solutions(not sure if we succeed), which worked not slower than solutions on Java with set.

[Solution](https://codeforces.com/https://pastebin.com/cCDyCz1K)

 
### [1270I - Xor on Figures](../problems/I._Xor_on_Figures.md "Good Bye 2019")

Let's fix first cell of fiqure  — $(x_1, y_1)$. Then if figure is lied in a such way, that first cell will be cell $(p,q)$ of the original board, other figure cells will be in the cells $(a + x_i - x_1, b + y_i - y_1)$ of the original board. Let's name such shifts $(x_i - x_1, y_i - y_1)$ as $(c_i, d_i)$. Then let's compute value $f[p, q] = \oplus a_{p - c_i, q - d_i}$ for $i = 1 \ldots t$(all additions are done modulo $2^k$). 

$\textbf{Lemma 1}$

If all numbers $f[p, q] = 0$, then all numbers in original array are zero too.

It will be proved in the end.

So our aim is to get zero array $f$.

$\textbf{Lemma 2}$

Assume, that we use operation in a such way that, that first figure cell is in $(p, q)$. Then values of $f$ will change in a such way:

For all $p', q'$ of the form $p + 2\cdot c_i, q + 2\cdot d_i$ $f[p', q']$ values will xor with $x$, for other it will not change.

Consider cell $(p', q')$. Then $f'[p', q'] = f[p', q'] \oplus (x \oplus x \ldots \oplus x)$, where we xor with $x$ for all pair $i, j$ such that $(p' - c_i, q' - d_i) = (p + c_j, q + d_j)$. Note, that if pair $i, j$ is suitable, then pair $j, i$ is suitable too. So, because $x \oplus x = 0$, we can only have non-xored pairs $i, i$ in the end, but then $p', q'$ looks like $p + 2\cdot c_i, q + 2\cdot d_i$ for some $i$.

We get that task for array $a$ is equivalent for task with array $f$ with figure scaled two times. Note that in this case, if we xor on some figure we change only cells with one parity of coordinates, so we can solve this task independently for $4$ boards of size $2^(k-1)$ (also, some cells of figure can map to the same one, then we should not use them). 

It's only left to show that if $f$ is zero, then $a$ is also zero.It's sufficient to show that for any values of $f$ we can get zero array(follow from linear algebra, both facts are equivalent to fact that $f$ is non-degenerate transform). But this statement can be easily proved using induction on $k$, because if we get all zeroes for problem with $k - 1$, then they will be zeroes in array $f$ too. In the end we get $k=0$ and figure with one cell(because $t$ is odd). We can get zero in one operation.

Also, from non-degenerativity it follow that answer is unique(if we xor on each figure at most once).

[Solution](https://codeforces.com/https://pastebin.com/gXdE8vAf)

You can also check [ivan100sic](https://codeforces.com/profile/ivan100sic "International Grandmaster ivan100sic") [comment](Goodbye_2019_(en).md?#comment-569752) for other variant of this solution 

