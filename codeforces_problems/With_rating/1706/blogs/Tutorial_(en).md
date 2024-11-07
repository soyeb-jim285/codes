# Tutorial_(en)

Some stats about the round
--------------------------

 **Pre-contest predictions**

| Person | A | B | C | D1 | D2 | E |
| --- | --- | --- | --- | --- | --- | --- |
| [BucketPotato](https://codeforces.com/profile/BucketPotato "International Master BucketPotato") | 900 | 1200 | 1400 | 1600 | 2000 | 2200 |
| [lunchbox](https://codeforces.com/profile/lunchbox "Master lunchbox") | 800 | 1300 | 1200 | 2000 | 2400 | 2300 |
| [lce4113](https://codeforces.com/profile/lce4113 "Expert lce4113") | 1000 | 1400 | 1400 |  |  |  |
| [lethan3](https://codeforces.com/profile/lethan3 "Master lethan3") | 800 | 1000 | 1200 | 1500 | 2000 |  |
| [Apple_Method](https://codeforces.com/profile/Apple_Method "Master Apple_Method") | 800 | 1200 | 1200 | 2100 | 2500 | 2400 |
| [izhang](https://codeforces.com/profile/izhang "Candidate Master izhang") | 800 | 1200 | 1400 | 1600 | 2200 |  |
| [EnDeRBeaT](https://codeforces.com/profile/EnDeRBeaT "Expert EnDeRBeaT") | 800 | 1300 | 1500 | 1700 | 2000 | 2200 |
| [Runtime-Terr0r](https://codeforces.com/profile/Runtime-Terr0r "Candidate Master Runtime-Terr0r") | 800 | 1200 | 1400 | 1800 |  |  |
| [AlperenT](https://codeforces.com/profile/AlperenT "Master AlperenT") | 800 | 1100 | 1400 | 1900 | 2400 | 2200 |

 

|  | A | B | C | D1 | D2 | E |
| --- | --- | --- | --- | --- | --- | --- |
| Average | 833 | 1211 | 1344 | 1775 | 2214 | 2260 |
| Actual | 800 | 1100 | 1400 | 1700 | 2400 | 2300 |

 **Who did what?**
#### General Credits

First, a huge thanks to [IgorI](https://codeforces.com/profile/IgorI "Grandmaster IgorI")! Working with inexperienced problemsetters over a 10 hour timezone difference is already difficult enough. But due to a wide range of problems with the round, the preparation process took several months. I personally have nothing but admiration for his patience and commitment throughout the entire time. He worked closely with each one of us to prepare every problem, helping us rewrite statements and redo tests over and over again to make sure they were as good as possible. He hasn't been included in this table, otherwise he would appear under every box.

 

| Problem | Author(s) | Preparation | Editorial |
| --- | --- | --- | --- |
| A | [BucketPotato](https://codeforces.com/profile/BucketPotato "International Master BucketPotato") | [BucketPotato](https://codeforces.com/profile/BucketPotato "International Master BucketPotato") | [BucketPotato](https://codeforces.com/profile/BucketPotato "International Master BucketPotato") |
| B | [lce4113](https://codeforces.com/profile/lce4113 "Expert lce4113"), [BucketPotato](https://codeforces.com/profile/BucketPotato "International Master BucketPotato") | [BucketPotato](https://codeforces.com/profile/BucketPotato "International Master BucketPotato") | [BucketPotato](https://codeforces.com/profile/BucketPotato "International Master BucketPotato"), [izhang](https://codeforces.com/profile/izhang "Candidate Master izhang") |
| C | [lce4113](https://codeforces.com/profile/lce4113 "Expert lce4113") | [lce4113](https://codeforces.com/profile/lce4113 "Expert lce4113") | [lce4113](https://codeforces.com/profile/lce4113 "Expert lce4113") |
| D | [BucketPotato](https://codeforces.com/profile/BucketPotato "International Master BucketPotato") | [BucketPotato](https://codeforces.com/profile/BucketPotato "International Master BucketPotato") | [BucketPotato](https://codeforces.com/profile/BucketPotato "International Master BucketPotato") |
| E | [lunchbox](https://codeforces.com/profile/lunchbox "Master lunchbox") | [lunchbox](https://codeforces.com/profile/lunchbox "Master lunchbox") | [lunchbox](https://codeforces.com/profile/lunchbox "Master lunchbox"), [BucketPotato](https://codeforces.com/profile/BucketPotato "International Master BucketPotato") |

#### Polygon Commits

The stats here may be a bit misleading, as many of the commits made were very minor changes (fixing typos in statements, etc.)

 

|  | A | B | C | D1 | D2 | E | Total |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [IgorI](https://codeforces.com/profile/IgorI "Grandmaster IgorI") | 23 | 23 | 22 | 35 | 36 | 30 | 169 |
| [BucketPotato](https://codeforces.com/profile/BucketPotato "International Master BucketPotato") | 46 | 53 | 4 | 85 | 91 | 20 | 299 |
| [lunchbox](https://codeforces.com/profile/lunchbox "Master lunchbox") |  |  |  |  |  | 36 | 36 |
| [lce4113](https://codeforces.com/profile/lce4113 "Expert lce4113") |  |  | 38 |  |  |  | 38 |
| [lethan3](https://codeforces.com/profile/lethan3 "Master lethan3") | 6 | 1 |  |  |  |  | 7 |
| [izhang](https://codeforces.com/profile/izhang "Candidate Master izhang") |  | 1 |  |  |  |  | 1 |
| [codeforces](/profile/codeforces "Headquarters, codeforces") |  | 2 | 3 | 3 | 4 | 5 | 17 |
| Total | 75 | 80 | 67 | 123 | 131 | 91 | 567 |

Solutions
---------

#### Problem A

 **Solution**
### [1706A - Another String Minimization Problem](../problems/A._Another_String_Minimization_Problem.md "Codeforces Round 809 (Div. 2)")

Let's iterate through the elements of $a$. For convenience, we'll make $a_i = \min(a_i, m + 1 - a_i)$. If the $a_i$-th character of $s$ is not currently A, then we should replace it. Otherwise, we replace the $(m+1-a_i)$-th character. This is because if we have the choice between replacing two characters, replacing the one with the smaller index will result in a lexicographically smaller string.

Alternatively, we can keep track of how many times either $x$ or $m + 1 - x$ appears in $a$ for each $1 \le x \le \lceil \frac{m}{2} \rceil$. 

* If they appear $0$ times, neither of these indices in $s$ can become A.
* If they appear $1$ time, it is optimal to set the $x$-th character to A, since this will produce a lexicographically smaller string.
* Otherwise, they appear at least $2$ times, and it is possible to set both the $x$-th and $(m + 1 - x)$-th character to A.
 **Code**Solution 1 ([BucketPotato](https://codeforces.com/profile/BucketPotato "International Master BucketPotato")): [164799099](https://codeforces.com/contest/1706/submission/164799099 "Submission 164799099 by BucketPotato")

Solution 2 ([BucketPotato](https://codeforces.com/profile/BucketPotato "International Master BucketPotato")): [164799196](https://codeforces.com/contest/1706/submission/164799196 "Submission 164799196 by BucketPotato")

#### Problem B

 **Solution**
### [1706B - Making Towers](../problems/B._Making_Towers.md "Codeforces Round 809 (Div. 2)")

When can two blocks of the same color form two consecutive elements of a tower? Formally, if we have two blocks of the same color at indices $i$ and $j$ such that $i < j$, how can we tell if it is possible to place them at $(x_i, y_i)$ and $(x_i, y_i + 1)$ respectively?

As it turns out, they can be placed like this if and only if $i$ and $j$ have different parities. 

First, if they have the same parity, it is impossible to place them this way. Note that $x_i + y_i$ must have a different parity from $x_{i + 1} + y_{i + 1}$, since these sums must differ by exactly $1$. So, if $i$ and $j$ have the same parity, then $x_i + y_i$ must also have the same parity as $x_j + y_j$. But we want them to be vertically adjacent, which is not possible if their parities must be the same. So, it is impossible to make two blocks with indices of the same parity adjacent to each other.

Next, there is a valid construction if you want to put blocks $i$ and $j$ together when they have different parities. Say that block $i$ will go at position $(x_i, y_i)$ and block $j$ goes at position $(x_i, y_{i}+1)$. If $j=i+1$, then we are done. Now, let's say that $j=i+3$. Then, we can place block $i+1$ at $(x_i+1,y_i)$ and block $j-1$ at position $(x_i+1,y_{i}+1)$. What if $j=i+5$? Then we can do the same as the previous case, and then put block $i+2$ at $(x_i+2,y_i)$ and block $j-2$ at $(x_i+2,y_i+1)$. Essentially, we are making the blocks between $i$ and $j$ into a horizontal line extending out for $\frac{j-i-1}{2}$ blocks then coming back in.

If there are already blocks to the right of $(x_i, y_i)$, then we can do the same construction but extending out to the left. Note that since we cannot move down, at least one of the right and left side must be open.

There are two ways we can go from here:

First, there is a DP solution. Let's imagine the naive $\mathcal{O}(n^2)$ dp: We say that $dp[i][c]$ is the maximum size of a tower with color $c$, such that the last block placed was at index $i$. The transitions look like this: $dp[i][c_i] = \max\limits_{j < i, j \not \equiv i \pmod 2}(dp[j][c_i] + 1)$. We check all $j < i$ such that $j$ and $i$ have different parities, then see if adding a block to this tower makes a better solution. To optimize it, we can notice that for the first DP dimension (index), only the parity of the index matters  — for each color, we just need to keep track of the maximum $dp[i][c]$ for even and odd $i$.

We will iterate through all blocks $a_i$, maintaining $dp[p][c]$, which contains the maximum size of a tower with color $c$, where the last block included in the tower had an index with parity $p$ ($p=0$ indicates an even index, $p=1$ indicates an odd index). If the current index is even, we set $dp[0][c_i] = \max(dp[0][c_i], dp[1][c_i] + 1)$. If it is odd, we set $dp[1][c_i] = \max(dp[1][c_i], dp[0][c_i] + 1)$. The solution runs in linear time.

Alternatively, there's a greedy solution. After selecting a block, the next block selected must always have the opposite parity. Therefore, it makes sense to greedily select the first block of the same color with opposite parity, since it will never improve the answer if we select a later block. For each color, we start from the first block and iterate through, adding each block to the sequence if and only if it has a different parity from the last one.

 **Code**Solution 1 ([BucketPotato](https://codeforces.com/profile/BucketPotato "International Master BucketPotato")): [164798955](https://codeforces.com/contest/1706/submission/164798955 "Submission 164798955 by BucketPotato")

Solution 2 ([BucketPotato](https://codeforces.com/profile/BucketPotato "International Master BucketPotato")): [164799024](https://codeforces.com/contest/1706/submission/164799024 "Submission 164799024 by BucketPotato")

#### Problem C

 **Solution**
### [1706C - Qpwoeirut And The City](../problems/C._Qpwoeirut_And_The_City.md "Codeforces Round 809 (Div. 2)")

The first observation to be made is that no two adjacent building can both be cool at the same time. This means that, for odd $n$, there must be $\frac{n-1}{2}$ cool buildings arranged in the following configuration...

 

| 01010...01010 |
| --- |
| (0 — normal (not cool) building, 1 — cool building) |

 For even $n$, there must be $\frac{n-2}{2}$ cool buildings. This means that exactly one pair of adjacent buildings in the city is normal, meaning that the buildings must be arranged in one of the following configurations...

 

| 01010...010100 |
| --- |
| 01010...010010 |
| 01010...001010 |
| $\vdots$ |
| 010100...01010 |
| 010010...01010 |
| 001010...01010 |
| (0 — normal (not cool) building, 1 — cool building) |

 For odd $n$, the solution is relatively simple. Just find the total floors necessary to make each of the alternating buildings (starting from the 2nd building) cool and that is the answer.

For even $n$, the solution is more complex. First, find the number of floors necessary to get to the first of the configurations shown above. Then, loop through each of the subsequent configurations, each time using the previous configuration to get the number of floors necessary for the new configuration in $O(1)$ time. This enables a solution in $O(n)$ time.

For example, in the 4th test case from the example in the problem statement, the possible configurations of cool buildings are...

 

| 4 2 1 3 5 3 6 1 |
| --- |
| 4 2 1 3 5 3 6 1 |
| 4 2 1 3 5 3 6 1 |
| 4 2 1 3 5 3 6 1 |
| (light — normal (not cool) building, bold — cool building) |

 The number of floors necessary to reach each of these configurations are...

* 1st configuration: (5 - 2) + (6 - 3) + (7 - 3) = 10.
* 2nd configuration: 10 - (7 - 3) + (6 - 6) = 6.
* 3rd configuration: 6 - (6 - 3) + (5 - 5) = 3.
* 4th configuration: 3 - (5 - 2) + (4 - 1) = 3.

The answer is the minimum of these values, which is $3$.

For even $n$, the floors necessary for every configuration can also be found in $O(n)$ time using an alternating forward prefix sum array and an alternating backward prefix sum array.

 **Code**Solution ([BucketPotato](https://codeforces.com/profile/BucketPotato "International Master BucketPotato")): [164798817](https://codeforces.com/contest/1706/submission/164798817 "Submission 164798817 by BucketPotato")

#### Problem D1

 **Solution**
### [1706D1 - Chopping Carrots (Easy Version)](../problems/D1._Chopping_Carrots_(Easy_Version).md "Codeforces Round 809 (Div. 2)")

Let's iterate over integers $v = 0, 1, \ldots, a_1$. We'll construct an answer assuming that the minimum value of $\lfloor \frac{a_i}{p_i} \rfloor$ is at least $v$.

For all $1 \le i \le n$, we set $p_i = \min(k, \lfloor \frac{a_i}{v} \rfloor)$: the maximum value $p_i$ such that $1 \le p_i \le k$ and $v \le \lfloor \frac{a_i}{p_i} \rfloor$ (if $v = 0$ we can just set $p_i = k$)). 

Now, we find the value of $\max\limits_{1 \le i \le n}(\lfloor\frac{a_i}{p_i}\rfloor ) - v$. This gives the answer when the minimum value of $\lfloor \frac{a_i}{p_i} \rfloor$ is $v$.

Finally, we compute this for all $0 \le v \le a_1$. This gives a $\mathcal{O}(n \cdot a_1)$ time solution per test case.

 **Code**Solution ([BucketPotato](https://codeforces.com/profile/BucketPotato "International Master BucketPotato")): [164798699](https://codeforces.com/contest/1706/submission/164798699 "Submission 164798699 by BucketPotato")

#### Problem D2

 **Solution**
### [1706D2 - Chopping Carrots (Hard Version)](../problems/D2._Chopping_Carrots_(Hard_Version).md "Codeforces Round 809 (Div. 2)")

Solution 1

Let's fix $v$, the minimum value of $\lfloor \frac{a_i}{p_i} \rfloor$. Then, for all $1 \le i \le n$, we find the maximum value $p_i$ such that $p_i \le k$ and $\lfloor \frac{a_i}{p_i} \rfloor \ge v$.

For some minimum value $v$, let's call the array described above $P(v)$, and let's define $M(v) = \max\limits_{1 \le i \le n} \lfloor \frac{a_i}{P(v)_i} \rfloor$. We can find the answer by taking the minimum of $M(v) - v$ across all $0 \le v \le a_1$, giving a $O(n \cdot a_i)$ solution.

To speed it up, let's consider how some element $a_i$ will affect the values of $M(v)$.

First, notice that $\lfloor \frac{a_i}{q} \rfloor$ (where $1 \le q \le k$) can take on at most $O(\min(k,\sqrt{a_i}))$ distinct values. Let's denote these values (in increasing order) $s_1, s_2, s_3, \ldots, s_x$. Consider what happens when $v \le s_1$. Then, $M(v)$ must be at least $s_1$. What about when $s_1 < v \le s_2$? Then, $M(v)$ must be at least $s_2$. And so on, until $s_{x - 1} < v \le s_x$, where $M(v)$ must be at least $s_x$.

This way, we can get lower bounds on value of $M(v)$. It is easy to see that the highest of these bounds is achievable.

Let's iterate over array $a$. Let $m[v]$ (here, $m = m[0], m[1], m[2], \ldots, m[a_1]$ is an array of length $a_1 + 1$) be the highest of lower bounds on $M(v)$ we already found. Initially, $m[v] = 0$ for all $v$. When we are dealing with $a_i$ we want to do the following: 

* For all $0 \le j \le x - 1$, we want to update $m[y] = \max(m[y], s_{j+1})$ for all $s_{j} + 1 \le y \le s_{j + 1}$ (for convenience we define $s_0 = -1$).

Since $s_0 < s_1 < s_2 < \ldots < s_x$, this can be done without any fancy data structures — instead of updating all these ranges directly, we can set $m[s_j + 1] = \max(m[s_j + 1], s_{j+1}])$, so that $M(v)$ will be equal to $\max(m[0], m[1], \ldots, m[v])$. 

Then, once $m$ is computed, we can sweep through to find all values of $M(v)$ in with prefix maxes.

Once we have $m$ computed, we can find $M(v) - v$ for all $0 \le v \le a_1$ in linear time. This gives a $\mathcal{O}(\sum\limits_{1 \le i \le n}\min(k, \sqrt{a_i}) + a_1)$ solution per test case, with total $\mathcal{O}(n + \max_a)$ memory across all tests.

Solution 2 (AlperenT)

Now, let's fix $v$ as the maximum value of $\lfloor \frac{a_i}{p_i} \rfloor$. We now want to maximize the minimum value of $\lfloor \frac{a_i}{p_i} \rfloor$.

Let's now consider all elements $a_i$ that satisfy $1 \le a_i \le v$. For these elements, it will be optimal to set $p_i = 1$, since we want to maximize them.

How about elements $a_i$ satisfying $v + 1 \le a_i \le 2(v+1) - 1$? We need to have $\lfloor \frac{a_i}{p_i} \rfloor \le v$, so for these elements, we must have $p_i \ge 2$. At the same time, we want to maximize them  — so it will be optimal to set all these $p_i = 2$.

Continuing this logic, for all integers $u = 1, 2, \ldots, k$, we should check the elements $a_i$ satisfying $(u-1)\cdot (v + 1) \le a_i \le u \cdot (v+1)$, and set all these $p_i = u$.

How can we determine the minimum value of $\lfloor \frac{a_i}{p_i} \rfloor$ from this? For a fixed $u$, the minimum $\lfloor \frac{a_i}{u} \rfloor$ will come from the minimum $a_i$. So if we can determine the minimum $a_i$ such that $(u-1)\cdot (v + 1) \le a_i \le u \cdot (v+1)$, and calculate these values across all $u = 1, 2, \ldots, k$, then we will get the answer.

To help us, let's precompute an array $next_1, next_2, \ldots, next_{a_n}$. $next_j$ will store the minimum value of $a_i$ such that $a_i \ge j$. Now, for a fixed $u$, we can check $next_{(u-1) \cdot v + 1}$. If this value is less than or equal to $u \cdot v$, it will be the minimum $a_i$ that we divide by $u$.

Two important details: 

1. If there exists some $a_i \ge (v + 1) \cdot k$, then it is impossible to have the max element as $v$, and we should skip it.
2. For some value $v$, we only need to check $u$ such that $(u-1)\cdot v + 1 \le a_n$.

Using this second detail, the solution runs in $\mathcal{O}\left( \sum\limits_{i = 1}^{a_n}\frac{a_n}{i} \right) = \mathcal{O}(a_n \cdot \log(a_n))$ time per test case. The memory usage is $\mathcal{O}(n + \max_a)$ across all tests.

 **Code**Solution 1 ([BucketPotato](https://codeforces.com/profile/BucketPotato "International Master BucketPotato")): [164798145](https://codeforces.com/contest/1706/submission/164798145 "Submission 164798145 by BucketPotato")

Solution 2 ([AlperenT](https://codeforces.com/profile/AlperenT "Master AlperenT")): [164800445](https://codeforces.com/contest/1706/submission/164800445 "Submission 164800445 by BucketPotato")

#### Problem E

 **Solution**
### [1706E - Qpwoeirut and Vertices](../problems/E._Qpwoeirut_and_Vertices.md "Codeforces Round 809 (Div. 2)")

If $l = r$, answer is $0$. From now on we assume $l < r$.

Say we have a function $f(i)$ that tells us for some $2 \le i \le n$ the answer for the query $[i - 1, i]$. Then for some query $[l, r]$, the answer will be $k = \max(f(l+1), f(l+2), \ldots, f(r-1), f(r))$. This is true because: 

* Since all consecutive nodes are connected, the first $k$ edges will be sufficient to connect all nodes $l, l+1, \ldots, r$.
* Say that it is possible to connect these nodes using the first $k'$ edges ($k' < k$). We know that there is at least $1$ index $l + 1 \le i \le r$ such that $f(i) = k$. But if the answer for this query is $k'$, then it must be true that $f(i) \le k'$ (because we can reach vertex $i - 1$ from vertex $i$ using only the first $k'$ edges then). Then, we have $f(i) \le k' < k = f(i)$, which is a contradiction.

So if we precompute the values of $f(i)$ for all $2 \le i \le n$, we can answer any query efficiently using a range max query structure (for example, a sparse table or segment tree). Here's how to find $f(i)$: 

* Weight the edges, so that the $i$-th edge has a weight $i$.
* Find the unique minimum spanning tree of this weighted graph.
* $f(i)$ will be the maximum weight of an edge on the path from $i - 1$ to $i$.

This will always give the correct value for $f(i)$ since edges not in the MST are useless. Let's imagine building the MST with Kruskal's: if we don't add the $W$-th edge, that means that the first $W-1$ edges are sufficient to connect $u_W$ and $v_W$, and we can use those instead to get a better answer.

On the resulting tree, the optimal way to connect any two nodes is to use the edges on the simple shortest path between them. Finding the max edge weight in a path on a tree can be done, for example, with binary lifting: for each node we store the maximum weight on the path to the root with length $1$, $2$, $4$, $8$, and so on. Then, we can find the max edge weight on the path from any two nodes to their LCA in $\mathcal O(\log(n))$.

Instead of using binary lifting, we can also directly represent the MST in the DSU. After successfully merging two components rooted at $u$ and $v$ in the DSU, we add an edge $(u, v)$ with the weight being the edge number from the input. $f(i)$ will then be the maximum edge from $i-1$ to $i$ in the newly constructed tree. We can just walk up the tree since the maximum depth is at most $\mathcal O(\log n)$ assuming the DSU implementation uses small-to-large merging.

This gives an $\mathcal O((m+q)\log(n))$ or $\mathcal O(m\log(n) + q)$ solution, depending on the implementation.

 **Code**Solution ([lunchbox](https://codeforces.com/profile/lunchbox "Master lunchbox")): [164798181](https://codeforces.com/contest/1706/submission/164798181 "Submission 164798181 by lunchbox")

