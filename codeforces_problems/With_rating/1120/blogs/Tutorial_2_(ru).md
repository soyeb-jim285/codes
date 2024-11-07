# Tutorial_2_(ru)

We are sorry for not having controlled the situation about the streamed editorial and also for the broadcast message about an unethical behaviour of someone from community: here is [explanatory comment](A_(en).md?#comment-496450) to the message. When we tried to move the casino problem one position below, something went wrong leading to it being moved one position above (however, [Radewoosh](https://codeforces.com/profile/Radewoosh "International Grandmaster Radewoosh") didn't seem to feel that something was wrong, congratulations!).

Nevertheless, we hope that you liked the problems, and those of you who decided to do something else after you knew that the round was made unrated can solve the problems when convenient (if they wish).

 **Problem A of final/div2 (Technogoblet of Fire)**
### [1121A - Technogoblet of Fire](https://codeforces.com/contest/1121/problem/A "Codeforces Round 543 (Div. 2, based on Technocup 2019 Final Round)")

First of all, each time we move someone to another school the number of schools which contain at least one Chosen One can increase at most by one. Second, if a school contains $c > 0$ Chosen Ones, but the strongest guy in this school is not one of them, then we need to move someone at least $c$ times to make all these chosen ones selected. Combining these two statements one can see that the answer to the problem equals the number of Chosen Ones which are currently not the strongest ones in their schools.

 **Problem B of div2 (Mike and Children)**
### [1121B - Mike and Children](https://codeforces.com/contest/1121/problem/B "Codeforces Round 543 (Div. 2, based on Technocup 2019 Final Round)")

Notice that the sum of sweets each child gets cannot exceed $2\cdot 10^5$, so for each of numbers no more than this threshold we can store the number of ways to obtain it as the sum of two sweets. It can be done just by considering all possible (unordered) pairs of sweets and printing the maximal obtained number (of ways to represent something as sum of two sweets). Indeed, if $x$ can be represented as a sum of two sweets in several ways then no two of them share a sweet since if $a_i + a_j$ = $a_i + a_k$ then $a_j = a_k$ and therefore $j = k$.

 **Problem B of final/C div2 (System Testing)**
### [1121C - System Testing](https://codeforces.com/contest/1121/problem/C "Codeforces Round 543 (Div. 2, based on Technocup 2019 Final Round)")

Let's determine for each solution when it begins being tested. It can be done, for example, by the following algorithm: let's store for each testing process the time when it becomes free to test something (initially all these $k$ numbers are zeroes), then iterate over all solutions in the queue and for each of them we pick a process with minimal time, say that it's the time when this solution begins being tested, and then update the time when this process stops testing.

After we determined this, we can easily know for each moment the number of solutions which are completely tested before this moment, and then for each test of each solution just check the required condition of being interesting on this test.

 **Problem C of final/D div2/A div1 (Diana and Liana)**
### [1120A - Diana and Liana](../problems/A._Diana_and_Liana.md "Codeforces Round 543 (Div. 1, based on Technocup 2019 Final Round)")

First of all, let's learn how to check if a perfect wreath can be obtained from the subsegment $[l, r]$ of our liana (that is, if we can remove some flowers so that the remaining ones on $[l, r]$ represent a perfect wreath, and this whole wreath will be cut). First, the number of other wreaths must be $n - 1$, so the inequality $\left\lfloor\frac{l - 1}{k}\right\rfloor\cdot k + \left\lfloor\frac{m - r}{k}\right\rfloor\cdot k \ge n - 1$ must hold. Second, the segment $[l, r]$ has to contain flowers of all required types. Finally, $r - l + 1$ must be at least $k$. One can see that these conditions also guarantee that $[l, r]$ can become a cut perfect wreath.

Now let's find for every $l$ the minimal possible $r$ for which the second condition holds. It can be done with the two pointers technique: if we iterate for all $l$ from $1$ to $m$ then this $r$ cannot become less than it was, and it's easy to update all counts and the number of insufficient flowers types both when increase $l$ and $r$.

So what remains is to find out if there is any $l$ such that the segment $[l, \max(r, l + k - 1)]$ satisfies the first requirement, and if it does, then print some flowers before $l$ which we delete (we must ensure that what remains before $l$ is divisible by $k$ and does not exceed $(n - 1)k$) and some flowers from $[l, r]$ we delete (without breaking the conditions). It's not necessary to delete anything after $r$, though.

 **Problem D of final/F div2/C div1 (Compress String)**
### [1120C - Compress String](../problems/C._Compress_String.md "Codeforces Round 543 (Div. 1, based on Technocup 2019 Final Round)")

Let's say that $dp[p]$ is the minimal cost to encode the prefix of $s$ with length $p$, the answer is $dp[n]$. If we want to encode the prefix with length $p$ then the last symbol in our encoded string either equals $s_p$, or represents some substring $s_{[l,p]}$ so that it occurs in the prefix of length $l - 1$. Therefore one can see that

$$dp[0] = 0,$$ $$dp[p] = \min\left(a + dp[p - 1], \min\left(b + dp[l - 1]\,\mid\,s_{[l, p]}\text{ is a substring of }s_{[1, l - 1]}\right)\right).$$

One way to implement this is to calculate this $dp$ forward and use hashes, but it may require some efforts to avoid collisions and fit into the time limit. Another way is to find for each $p$ all appropriate $l$'s by calculating z-function on the reverse of $s_{[1, p]}$. The total complexity in this case is $O\left(n^2\right)$.

 **Problem E of final/E div2/B div1 (Once in a casino)**
### [1120B - Once in a casino](../problems/B._Once_in_a_casino.md "Codeforces Round 543 (Div. 1, based on Technocup 2019 Final Round)")

Since each operation saves the alternating series of the digits, if it's different for $a$ and $b$, then the answer is '-1'. Now we prove that otherwise it's possible to win.

Let's imagine that digits can be negative or bigger than 9 (that is, for example, number 19 can become the number with digits 2 and 10). Denote by $a_i$ the $i$-th digit of $a$ (and similarly for $b$). Now there is no difference between any two orders of the same set of operations, so we can do allowed operations from left to right. After we do all operations with first digit (there are at least $|a_1 - b_1|$ such operations), $a_2$ will become equal to $a_2 + b_1 - a_1$. After we do all operations with $a_2$ and $a_3$ (there are at least $|a_2 + b_1 - a_1 - b_2|$ such operations), $a_3$ will be equal to $a_3 + b_2 - a_2 - b_1 + a_1$, and so on. Thus we can calculate the minimal total number of operations and find their set. The goal is to prove that it's possible to perform them in some order and never break the rules about the correctness of intermediate numbers.

Indeed, let's just perform these operations from left to right. Assume that we can't perform the current operation. Without loss of generality assume that we can't decrease two digits: one of $a_k$ and $a_{k + 1}$ is 0 now. It's easy to see that $a_k > 0$ because after we perform the set of our operations ignoring the rules, $a_k$ will become $b_k$, which is nonnegative. Hence $a_{k + 1} = 0$. Then we must increase $a_{k + 1}$ and $a_{k + 2}$ at least once (again because we can ignore the rules and get $b_{k + 1}$ in the end). If we can do it then we do it and then decrease $a_k$ and $a_{k + 1}$ just as planned and then continue performing the operations. Otherwise, $a_{k + 2} = 9$. Reasoning similarly, either we can decrease $a_{k + 2}$ and $a_{k + 3}$, or $a_{k + 3} = 0$, et cetera. As it can't continue infinitely, we can perform some operations from our set and decrease $a_k$ and $a_{k + 1}$, so we can reach the goal doing the minimal number of operations.

 **Problem F of final/D div1 (Power Tree)**
### [1120D - Power Tree](../problems/D._Power_Tree.md "Codeforces Round 543 (Div. 1, based on Technocup 2019 Final Round)")

One can see that the problem doesn't change if we want to be able to obtain any possible combination of numbers in leaves from the all-zero combination.

Solution 1. Let $v_1$, $v_2$, ..., $v_l$ be the indices of all leaves in the order of any Euler tour. Let $a_i$ be the number written in $v_i$. We say that $v_0 = v_{l+1} = 0$. Denote the difference $a_{i + 1} - a_i$ by $d_i$. We want to be able to obtain an arbitrary sequence $d_0$, ..., $d_l$ with zero sum.

Imagine that we bought a vertex $u$ whose subtree contains exactly leaves from $v_i$ to $v_j$. Applying the operation to this vertex with number $x$ means increasing $d_{i-1}$ by $x$ and decreasing $d_j$ by $x$ without affecting all other differences.

Let's build new graph with vertices from $0$ to $l$. Each such vertex $u$ represents an edge connecting vertices $(i - 1)$ and $j$ with weight $c_u$. To be able to get every possible sequence with zero sum it's needed and sufficient for the graph with picked edges be connected. Now we want to know what is the weight of a minimal spanning tree and which edges can be in it. Both can be found by, for example, Kruskal's algorithm.

Solution 2. We say that a vertex $u$ covers a leaf $v$ if it's in $u$'s subtree.

One can see that we can buy a set of vertices iff for each vertex $u$ there is at most one leaf in its subtree which is not covered by any of bought vertices from the subtree. Indeed, if there are at least two such leaves then the difference between their values never change. On the other hand, if this holds, we can set the required values in the bought vertices in the order of increasing depth, performing the needed operation each time we are in vertex whose subtree contains a leaf which is not covered by any bought vertex in the subtree except the one we consider.

So we calculate $ans[v][k]$ where $0\le k\le 1$ where this value means the minimal possible cost where in the subtree of $v$ there are $k$ not covered leaves. It can be shown that these values are enough to calculate the answer.

 **Problem G of final/E div1 (The very same Munchhausen)**Tutorial is loading... **Problem H of final/F div1 (Secret Letters)**
### [1120F - Secret Letters](../problems/F._Secret_Letters.md "Codeforces Round 543 (Div. 1, based on Technocup 2019 Final Round)")

Consider any optimal solution. Consider all letters of W between two times when P visits R. It's clear that

* maybe the first of these messages is sent via R,
* some of the last messages are also sent via R,
* all other messages are sent via O.

The sense behind shipping the first message via R is to obtain all messages which are currently stored there. If the first message is sent via O, and some of the others is sent via R, then we can swap them thus paying less. On the other hand, once we got all these letters, it makes sense to send something through R iff $ct \le d$ where $t$ is the time between the moments when we send this message and when P visits R to obtain it. The same holds if we swap W and P.

Denote by $ans[i]$ the minimal possible cost of the first $(i - 1)$ letters if the $i$-th is sent through R.

Also denote by $ans\\_delay[i]$ the minimal possible cost of the first $(i - 1)$ letters if the $i$-th is sent through R and if R has already kept exaclty one letter. To calculate these values we can each time try every possible number of last letters sent through R. This takes $O(n^2)$ time.

One can observe that if we fix the left bound of letters sent through R then the cost depends linearly on the time $t_i$ which we are calculating this for, and since we need the minimum of linear functions each time then we can use convex-hull trick which gives us $O(n)$ or $O(n\,\log{n})$ complexity.

