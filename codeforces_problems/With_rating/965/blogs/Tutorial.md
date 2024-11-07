# Tutorial


### [965A - Paper Airplanes](../problems/A._Paper_Airplanes.md "Codeforces Round 476 (Div. 2) [Thanks, Telegram!]")

Each person should receive $\lceil \frac{n}{s} \rceil$ sheets. So, there should be at least $k \cdot \lceil \frac{n}{s} \rceil$ sheets in total, for them $\lceil \frac{k \cdot \lceil \frac{n}{s} \rceil}{p} \rceil$ packs are needed.

[37617481](https://codeforces.com/contest/965/submission/37617481 "Submission 37617481 by KAN")

 
### [965B - Battleship](../problems/B._Battleship.md "Codeforces Round 476 (Div. 2) [Thanks, Telegram!]")

Let's compute for each cell four values: the number of cells where a part of the ship can be located to the right ($r$), to the left ($l$), up ($u$) and down ($d$), including the cell itself. Then, if $k > 1$, then there are $\min(k, \max(0, l + r - k)) + \min(k, \max(0, u + d - k))$ positions of the ship containing this cell, and if $k = 1$ it's easy to check whether this value is $1$ or $0$. After that you should just print the maximum among all cells. This solution works in $O(n^3)$.

[37617515](https://codeforces.com/contest/965/submission/37617515 "Submission 37617515 by KAN")

 
### [965C - Greedy Arkady](../problems/C._Greedy_Arkady.md "Codeforces Round 476 (Div. 2) [Thanks, Telegram!]")

As the limits on $D$ are small, let's try all possible values of $d$ — the number of times Arkady will receive candies. For a given $d$ it's easy to compute $x_{min}$ and $x_{max}$ — the maximum and minimum values of $x$ that suit these $d$ and $M$. Then, with a fixed $d$ it's easy to write the formula of how many candies Arkady gets: it's $x \cdot d$ candies. So it's obvious that we should choose $x_{max}$ for the given $d$ and update the answer.

Bonus 1: can you solve the task when the leftover is not thrown away, but is given to the next person?

Bonus 2: can you solve the task from bonus 1, but without the $D \le 1000$ condition (just $1 \le D \le n$)?

[37617552](https://codeforces.com/contest/965/submission/37617552 "Submission 37617552 by KAN")

 
### [965D - Single-use Stones](../problems/D._Single-use_Stones.md "Codeforces Round 476 (Div. 2) [Thanks, Telegram!]")

This problem can be solved using many different approaches, most of them are based on different greedy solutions. We will discuss a solution with an easy-provable greedy.

First, let's do binary search for the answer. Let it be $k$. Then, assume that the stones are given by their positions $x_1, x_2, \ldots, x_m$, where $m$ is the total number of stones. Also assume $x_0 = 0$ and $x_{m+1} = w$ — the banks. Then, if for some $i$ the condition $x_{i+k} - x_i \le l$ is not satisfied, then $k$ frogs can't cross the river. Indeed, consider the first jump for each frog that ends at a position further than $x_i$. It can't end at $x_{i+k}$ or further because of the length of the jump, so it has to end at some stone at $x_{i+1}$, $x_{i+2}$, ..., or $x_{i+k-1}$. But there are only $k - 1$ such stones, so some stone is used by two frogs which is prohibited. Now, if $x_{i+k} - x_i \le l$ is satisfied, the frogs can easily cross the river by using the route $0 \to x_i \to x_{i+k} \to x_{i + 2k} \to \ldots$ for the $i$-th frog.

So, the solution is to do the binary search for the answer and then compute the maximum distance between stones $x_{i+k}$ and $x_i$. This can be done using two pointers technique.

[37617576](https://codeforces.com/contest/965/submission/37617576 "Submission 37617576 by KAN")

 
### [965E - Short Code](../problems/E._Short_Code.md "Codeforces Round 476 (Div. 2) [Thanks, Telegram!]")

First, let's construct a trie of the names. Now a name is a token on some node in the graph, and we can move the token freely up to the root with the only constraint that no two tokens share the same node. We have to minimize the total depth of the nodes with tokens.

For each subtree let's compute the optimal positions of tokens that were initially in the subtree assuming that no token moves higher than the root of the subtree. It can be done easily with dynamic programming: if the current note has a token initially, then the answer is simply the union of this node and all the answers for the children. Otherwise, one of the tokens from children's answer should be moved to the current node. Obviously, it is the token with the highest depth. We can easily maintaining this using sets and smaller-to-larger optimization. This solution runs in $O(m \log^2{m})$, where $m$ is the total length of the strings.

Also, due to the specific structure of the tree (because it is a trie and there is a constraint on the total length of the strings), we can do the same simulation without any data structures in $O(m)$ time.

[37617599](https://codeforces.com/contest/965/submission/37617599 "Submission 37617599 by KAN")

