# T_(en)

We are sorry for not having controlled the situation about the streamed editorial and also for the broadcast message about an unethical behaviour of someone from community: here is [explanatory comment](A_(en).md?#comment-496450) to the message. When we tried to move the casino problem one position below, something went wrong leading to it being moved one position above (however, [Radewoosh](https://codeforces.com/profile/Radewoosh "International Grandmaster Radewoosh") didn't seem to feel that something was wrong, congratulations!).

Nevertheless, we hope that you liked the problems, and those of you who decided to do something else after you knew that the round was made unrated can solve the problems when convenient (if they wish).

 **Problem A of final/div2 (Technogoblet of Fire)**
### [1121A - Technogoblet of Fire](https://codeforces.com/contest/1121/problem/A "Codeforces Round 543 (Div. 2, based on Technocup 2019 Final Round)")

First of all, each time we move someone to another school the number of schools which contain at least one Chosen One can increase at most by one. Second, if a school contains c>0 Chosen Ones, but the strongest guy in this school is not one of them, then we need to move someone at least c times to make all these chosen ones selected. Combining these two statements one can see that the answer to the problem equals the number of Chosen Ones which are currently not the strongest ones in their schools.

 **Problem B of div2 (Mike and Children)**
### [1121B - Mike and Children](https://codeforces.com/contest/1121/problem/B "Codeforces Round 543 (Div. 2, based on Technocup 2019 Final Round)")

Notice that the sum of sweets each child gets cannot exceed 2⋅105, so for each of numbers no more than this threshold we can store the number of ways to obtain it as the sum of two sweets. It can be done just by considering all possible (unordered) pairs of sweets and printing the maximal obtained number (of ways to represent something as sum of two sweets). Indeed, if x can be represented as a sum of two sweets in several ways then no two of them share a sweet since if ai+aj = ai+ak then aj=ak and therefore j=k.

 **Problem B of final/C div2 (System Testing)**
### [1121C - System Testing](https://codeforces.com/contest/1121/problem/C "Codeforces Round 543 (Div. 2, based on Technocup 2019 Final Round)")

Let's determine for each solution when it begins being tested. It can be done, for example, by the following algorithm: let's store for each testing process the time when it becomes free to test something (initially all these k numbers are zeroes), then iterate over all solutions in the queue and for each of them we pick a process with minimal time, say that it's the time when this solution begins being tested, and then update the time when this process stops testing.

After we determined this, we can easily know for each moment the number of solutions which are completely tested before this moment, and then for each test of each solution just check the required condition of being interesting on this test.

 **Problem C of final/D div2/A div1 (Diana and Liana)**
### [1120A - Diana and Liana](../problems/A._Diana_and_Liana.md "Codeforces Round 543 (Div. 1, based on Technocup 2019 Final Round)")

First of all, let's learn how to check if a perfect wreath can be obtained from the subsegment $[l, r]$ of our liana (that is, if we can remove some flowers so that the remaining ones on $[l, r]$ represent a perfect wreath, and this whole wreath will be cut). First, the number of other wreaths must be $n - 1$, so the inequality $\left\lfloor\frac{l - 1}{k}\right\rfloor\cdot k + \left\lfloor\frac{m - r}{k}\right\rfloor\cdot k \ge n - 1$ must hold. Second, the segment $[l, r]$ has to contain flowers of all required types. Finally, $r - l + 1$ must be at least $k$. One can see that these conditions also guarantee that $[l, r]$ can become a cut perfect wreath.

Now let's find for every $l$ the minimal possible $r$ for which the second condition holds. It can be done with the two pointers technique: if we iterate for all $l$ from $1$ to $m$ then this $r$ cannot become less than it was, and it's easy to update all counts and the number of insufficient flowers types both when increase $l$ and $r$.

So what remains is to find out if there is any $l$ such that the segment $[l, \max(r, l + k - 1)]$ satisfies the first requirement, and if it does, then print some flowers before $l$ which we delete (we must ensure that what remains before $l$ is divisible by $k$ and does not exceed $(n - 1)k$) and some flowers from $[l, r]$ we delete (without breaking the conditions). It's not necessary to delete anything after $r$, though.

 **Problem D of final/F div2/C div1 (Compress String)**Tutorial is loading... **Problem E of final/E div2/B div1 (Once in a casino)**
### [1120B - Once in a casino](../problems/B._Once_in_a_casino.md "Codeforces Round 543 (Div. 1, based on Technocup 2019 Final Round)")

Since each operation saves the alternating series of the digits, if it's different for $a$ and $b$, then the answer is '-1'. Now we prove that otherwise it's possible to win.

Let's imagine that digits can be negative or bigger than 9 (that is, for example, number 19 can become the number with digits 2 and 10). Denote by $a_i$ the $i$-th digit of $a$ (and similarly for $b$). Now there is no difference between any two orders of the same set of operations, so we can do allowed operations from left to right. After we do all operations with first digit (there are at least $|a_1 - b_1|$ such operations), $a_2$ will become equal to $a_2 + b_1 - a_1$. After we do all operations with $a_2$ and $a_3$ (there are at least $|a_2 + b_1 - a_1 - b_2|$ such operations), $a_3$ will be equal to $a_3 + b_2 - a_2 - b_1 + a_1$, and so on. Thus we can calculate the minimal total number of operations and find their set. The goal is to prove that it's possible to perform them in some order and never break the rules about the correctness of intermediate numbers.

Indeed, let's just perform these operations from left to right. Assume that we can't perform the current operation. Without loss of generality assume that we can't decrease two digits: one of $a_k$ and $a_{k + 1}$ is 0 now. It's easy to see that $a_k > 0$ because after we perform the set of our operations ignoring the rules, $a_k$ will become $b_k$, which is nonnegative. Hence $a_{k + 1} = 0$. Then we must increase $a_{k + 1}$ and $a_{k + 2}$ at least once (again because we can ignore the rules and get $b_{k + 1}$ in the end). If we can do it then we do it and then decrease $a_k$ and $a_{k + 1}$ just as planned and then continue performing the operations. Otherwise, $a_{k + 2} = 9$. Reasoning similarly, either we can decrease $a_{k + 2}$ and $a_{k + 3}$, or $a_{k + 3} = 0$, et cetera. As it can't continue infinitely, we can perform some operations from our set and decrease $a_k$ and $a_{k + 1}$, so we can reach the goal doing the minimal number of operations.

 **Problem F of final/D div1 (Power Tree)**
### [1120D - Power Tree](../problems/D._Power_Tree.md "Codeforces Round 543 (Div. 1, based on Technocup 2019 Final Round)")

One can see that the problem doesn't change if we want to be able to obtain any possible combination of numbers in leaves from the all-zero combination.

Solution 1. Let v1, v2, ..., vl be the indices of all leaves in the order of any Euler tour. Let ai be the number written in vi. We say that v0=vl+1=0. Denote the difference ai+1−ai by di. We want to be able to obtain an arbitrary sequence d0, ..., dl with zero sum.

Imagine that we bought a vertex u whose subtree contains exactly leaves from vi to vj. Applying the operation to this vertex with number x means increasing di−1 by x and decreasing dj by x without affecting all other differences.

Let's build new graph with vertices from 0 to l. Each such vertex u represents an edge connecting vertices (i−1) and j with weight cu. To be able to get every possible sequence with zero sum it's needed and sufficient for the graph with picked edges be connected. Now we want to know what is the weight of a minimal spanning tree and which edges can be in it. Both can be found by, for example, Kruskal's algorithm.

Solution 2. We say that a vertex u covers a leaf v if it's in u's subtree.

One can see that we can buy a set of vertices iff for each vertex u there is at most one leaf in its subtree which is not covered by any of bought vertices from the subtree. Indeed, if there are at least two such leaves then the difference between their values never change. On the other hand, if this holds, we can set the required values in the bought vertices in the order of increasing depth, performing the needed operation each time we are in vertex whose subtree contains a leaf which is not covered by any bought vertex in the subtree except the one we consider.

So we calculate ans[v][k] where 0≤k≤1 where this value means the minimal possible cost where in the subtree of v there are k not covered leaves. It can be shown that these values are enough to calculate the answer.

 **Problem G of final/E div1 (The very same Munchhausen)**
### [1120E - The very same Munchhausen](../problems/E._The_very_same_Munchhausen.md "Codeforces Round 543 (Div. 1, based on Technocup 2019 Final Round)")

Define the balance of a number x as S(nx)⋅n−S(x). By the balance of a digit string we mean the balance of the corresponding number.

Solution 1. We are gonna do the following:

* Find out if the solution exists. If no, print -1 and exit.
* Find any string with negative balance.
* Find any string with positive balance.
* Take their linear combination with zero balance (maybe we pad the numbers we found by leading zeroes before this). By linear combination of several strings we mean their concatenation where each of them can occur several times.

It is quite clear how to perform the last step. To perform the initial step it's convenient to introduce some lemmas.

Lemma 1. S(a+b)≤S(a)+S(b).

Proof. It's obvious more or less since if we write both numbers one under another and start calculating their sum then the result will have sum of digits being equal to S(a)+S(b) minus 9 times the number of carries.

Lemma 2. S(ab)≤aS(b).

Proof. S(ab)=S(b+b+…+b)≤S(b)+S(b)+…S(b)=aS(b). Here the inequality holds according to Lemma 1.

Lemma 3. S(ab)≤S(a)S(b).

Proof. Let a=¯an−1an−2…a1a0. Then

S(ab)=S(an−1b⋅10n−1+an−2b⋅10n−2+…+a0b)≤S(an−1b⋅10n−1)+S(an−2b⋅10n−2)+…+S(a0b)= =S(an−1b)+S(an−2b)+…+S(a0b)≤(an−1+an−2+…+a0)S(b)=S(a)S(b).

Now consider two cases.

* a=2d1⋅5d2.Let b=10max(d1,d2). One can see that

a⋅S(an)=a⋅S(bnb/a)=aS(b/a)⋅S(b/a)⋅S(bnb/a)≥aS(b/a)⋅S(bn)=aS(b/a)⋅S(n).

That means that if a>S(b/a) then the answer doesn't exist, otherwise the number b/a has non-positive balance. One can easily see that the number 1 always has non-negative balance, so in this case the problem is solved.
* a has a prime divisor which is not 2 and not 5.It turns out that in this case the answer always exists. Indeed, the decimal fraction 1/a is infinite, that means that S(10ka) in nondecreasing and can be sufficiently large; and so can be S(10ka+1) since the number of trailing 9-s of 10ka is bounded. Meanwhile S(a⋅(10ka+1)) is bounded by, say, 1+9⋅len(a), so we always can find a string with negative balance, and, as we mentioned above, the number 1 always has nonnegative balance.

We know two ways to perform the second step.

* Divide 1 by a and find the period. Let's say that the period can be represented as a string s and the part before it by a string t (possibly empty). Let s′ have the same length as s and equal (s+1) when being treated as an integer. We are looking for a string of type tsss…ss′ with negative balance. One can calculate the impact on balance of strings t, s and s′ and therefore find the minimal required number of stings s.
* Construct a weighted directed graph. Its vertices are numbers from 0 to a−1, and for each pair of numbers (c,x)≠(0,0) with 0≤c<a and 0≤x≤9 there is an edge from c to ⌊ax+c10⌋ with weight (ax+c)(mod10) and label x. Informally, if we traverse through some path from 0, and labels of the edges on this path are digits of some number n from right to left, then the sum of weights are the current balance of an (that is, if we consider only last len(n) digits when calculating the balance) and the last vertex represents the current carry. Now we can find a negative cycle in this graph via Ford-Bellman algorithm and then construct a path from 0 to this cycle, go through the cycle required number of times (so that the final sum of weights is negative) and then return to the zero vertex.

This solution has a disadvantage: the final answer can have a length up to S(n)⋅n2. One workaround is to find, say, 300 different possibilities of negative balance (by taking more periods/negative cycles) and find the positive balance string by trying all numbers from 1 to 10000 and constructing a string with a small balance divisible by any of negative balances. It can be done by a sort of knapsack on found positive balances. The idea is to get a big gcd of the two found balances so that we don't need to repeat the negative-balance-string too many times (because among the two found strings it is the one which can have a superlinear length).

Solution 2. Imagine we have infinite time and memory. Then we can say that we have states of kind (carry,balance) similar to the states of the graph from solution 1, where for each state (carry,balance) and each digit x (except state (0,0) and digit 0 at the same time) there is a transition to ((carry+a⋅x)(mod10),balance+a⌊carry+a⋅x10⌋−x). Our goal is to reach (0,0) again. One can bfs over this (infinite) graph with creating new states, when needed. However, traversing over this graph consume too much memory.

It turns out that if we don't consider states with |balance|>a then there always is a solution, and this is relatively easy to come up with (and definitely easier to pass than the previous one).

 **Problem H of final/F div1 (Secret Letters)**
### [1120F - Secret Letters](../problems/F._Secret_Letters.md "Codeforces Round 543 (Div. 1, based on Technocup 2019 Final Round)")

Consider any optimal solution. Consider all letters of W between two times when P visits R. It's clear that

* maybe the first of these messages is sent via R,
* some of the last messages are also sent via R,
* all other messages are sent via O.

The sense behind shipping the first message via R is to obtain all messages which are currently stored there. If the first message is sent via O, and some of the others is sent via R, then we can swap them thus paying less. On the other hand, once we got all these letters, it makes sense to send something through R iff $ct \le d$ where $t$ is the time between the moments when we send this message and when P visits R to obtain it. The same holds if we swap W and P.

Denote by $ans[i]$ the minimal possible cost of the first $(i - 1)$ letters if the $i$-th is sent through R.

Also denote by $ans\\_delay[i]$ the minimal possible cost of the first $(i - 1)$ letters if the $i$-th is sent through R and if R has already kept exaclty one letter. To calculate these values we can each time try every possible number of last letters sent through R. This takes $O(n^2)$ time.

One can observe that if we fix the left bound of letters sent through R then the cost depends linearly on the time $t_i$ which we are calculating this for, and since we need the minimum of linear functions each time then we can use convex-hull trick which gives us $O(n)$ or $O(n\,\log{n})$ complexity.

