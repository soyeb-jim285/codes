# Tutorial_(en)

[1866A. Ambitious Kid](../problems/A._Ambitious_Kid.md)
---------------------------------------------------------------------

Author: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")  
Developer: [nandonathaniel](https://codeforces.com/profile/nandonathaniel "Candidate Master nandonathaniel") 

 **Tutorial**
### [1866A - Ambitious Kid](../problems/A._Ambitious_Kid.md "COMPFEST 15 - Preliminary Online Mirror (Unrated, ICPC Rules, Teams Preferred)")

In order to have the product of all elements be 0, at least one element must be 0. For each element Ai, the minimum number of operations to turn it into 0 is |Ai|. Therefore, the minimum number of operations to turn at least one element into 0 is the minimum value of |Ai| out of all elements.

Time complexity: O(N)

[1866B. Battling with Numbers](../problems/B._Battling_with_Numbers.md)
-----------------------------------------------------------------------------

Author: [KokiCoder](https://codeforces.com/profile/KokiCoder "Expert KokiCoder")  
Developer: [nandonathaniel](https://codeforces.com/profile/nandonathaniel "Candidate Master nandonathaniel") 

 **Tutorial**
### [1866B - Battling with Numbers](../problems/B._Battling_with_Numbers.md "COMPFEST 15 - Preliminary Online Mirror (Unrated, ICPC Rules, Teams Preferred)")

For a prime k, let fk(w) be the exponent of k in the factorisation of w. In particular, if the factorisation of w does not contain k, then fk(w)=0.

We can obtain that for any prime k, it holds that: 

* fk(X)=fk(LCM(p,q))=max(fk(p),fk(q))
* fk(Y)=fk(GCD(p,q))=min(fk(p),fk(q))

For each prime k, there are three cases: 

* If fk(X)<fk(Y), then it is impossible to assign the exponents since max(fk(p),fk(q))<min(fk(p),fk(q)) cannot be satsified.
* If fk(X)=fk(Y), then there is only one way to assign the exponents, which is fk(p)=fk(q)=fk(X).
* If fk(X)>fk(Y), then there are two ways to assign the exponents, which are the following:
	+ fk(p)=fk(X), fk(q)=fk(Y)
	+ fk(p)=fk(Y), fk(q)=fk(X)

This means, if there is at least one prime k such that fk(X)<fk(Y), the answer is 0. Otherwise, the answer is 2 to the power of the number of primes k such that fk(X)>fk(Y).

To maintain the values of fk(X) and fk(Y), you can use two pointers, the map data structure, or other methods.

Time complexity: O(N)

[1866C. Completely Searching for Inversions](../problems/C._Completely_Searching_for_Inversions.md)
-------------------------------------------------------------------------------------------

Author: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe")  
Developer: [gansixeneh](https://codeforces.com/profile/gansixeneh "Candidate Master gansixeneh") 

 **Tutorial**
### [1866C - Completely Searching for Inversions](../problems/C._Completely_Searching_for_Inversions.md "COMPFEST 15 - Preliminary Online Mirror (Unrated, ICPC Rules, Teams Preferred)")

Note that during the entire process, each time we do dfs(x) for the same value of x, the sequence of values appended to the end of Z is always the same. So, for each vertex x, we want to obtain some properties about the sequence of values that will be appended if we do dfs(x). Since we want to calculate the number of inversions in a sequence of 0 and 1 elements, for each x, we want to calculate: 

* f0[x]: the number of 0 elements appended.
* f1[x]: the number of 1 elements appended.
* inv[x]: the number of inversions completely within the sequence appended.

Then, we can solve the problem using dynamic programming on directed acyclic graph. For a vertex x, we iterate each vertex y that it is directed towards (following the order given in the input). If the integer in the current edge is w, then we temporarily add fw[y] by 1 and if w=1, then we temporarily add inv[y] by f0[y]. Then, we do the following transitions: 

* Add inv[x] by inv[y]+f1(x)×f0(y).
* Add f0[x] by f0[y].
* Add f1[x] by f1[y].

The answer is inv[1].

Time complexity: O(N+∑S)

[1866D. Digital Wallet](../problems/D._Digital_Wallet.md)
----------------------------------------------------------------------

Author: [CyberSleeper](https://codeforces.com/profile/CyberSleeper "Expert CyberSleeper")  
Developer: [CyberSleeper](https://codeforces.com/profile/CyberSleeper "Expert CyberSleeper") 

 **Tutorial**
### [1866D - Digital Wallet](../problems/D._Digital_Wallet.md "COMPFEST 15 - Preliminary Online Mirror (Unrated, ICPC Rules, Teams Preferred)")

First, notice that since the initial value of all elements are positive, it is always optimal to always choose an element that has not been chosen before in each operation.

Let's look at the N arrays as a grid of N rows and M columns. We can solve this problem by iterating each column from left to right and using dynamic programming. Define the following: 

* dp[i][j]: the maximum money Chaneka can earn by only taking the elements of the first i columns in j operations.

When we iterate a new column i, we can choose to choose c elements in that column for some value c (0≤c≤N). If we choose to choose c elements in that column, it is always the most optimal to choose the c biggest elements in that column.

Notice that if we only consider the first i columns, in the optimal strategy, we must do a minimum of i−K+1 operations and a maximum of i operations. So there are only a maximum of K different values of j we need to consider when calculating all values of dp[i][j] for each new column i. For each dp[i][j], there are only N+1 possibilities for the number of elements we choose in column i, and each of them can be handled in O(1).

Time complexity: O(NMK)

[1866E. Elevators of Tamem](../problems/E._Elevators_of_Tamem.md)
--------------------------------------------------------------------------

Author: [FreeJinG](https://codeforces.com/profile/FreeJinG "Expert FreeJinG")  
Developer: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe") 

 **Tutorial**
### [1866E - Elevators of Tamem](../problems/E._Elevators_of_Tamem.md "COMPFEST 15 - Preliminary Online Mirror (Unrated, ICPC Rules, Teams Preferred)")

First, let's solve the problem if there are no events of type 2. We can solve this problem using dynamic programming. First, define: 

* enter[e]: the initial floor of the person in the e-th event.
* exit[e]: the desired floor of the person in the e-th event.

Then, define dp[i][j][k] as the minimum electricity fee if: 

* Elevator 1 last moved at the i-th event (last at floor exit[i]).
* Elevator 2 last moved at the j-th event (last at floor exit[j]).
* Elevator 3 last moved at the k-th event (last at floor exit[k]).

Let's say we have handled all events from the 1-st to the (e−1)-th and now we want to handle the e-th event. This means the electricity fee for the the current condition is a value of dp[i][j][k] with max(i,j,k)=e−1 and we want to choose one elevator to handle the e-th event. If we choose elevator 1, then it can move between the i-th day and e-th day to prepare for the person in the e-th event. So the minimum electricity fee for elevator 1 to handle this is |exit[i]−enter[e]|×min(Ai,Ai+1,…,Ae)+|enter[e]−exit[e]|×Ae. So we add that value with dp[i][j][k] for a candidate value of dp[e][j][k]. We do a similar thing for elevators 2 and 3.

Since we can precompute all values of min(Ai,Ai+1,…,Ae) naively, we can do the transition of each state in O(1).

In order to handle the events of type 2, we can just write down the electricity fee for each elevator in each day. If that elevator is off on that day, we set the electricity fee of that elevator to be ∞.

Time complexity: O(Q3)

[1866F. Freak Joker Process](../problems/F._Freak_Joker_Process.md)
---------------------------------------------------------------------------

Author: [nandonathaniel](https://codeforces.com/profile/nandonathaniel "Candidate Master nandonathaniel")  
Developer: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe") 

 **Tutorial**
### [1866F - Freak Joker Process](../problems/F._Freak_Joker_Process.md "COMPFEST 15 - Preliminary Online Mirror (Unrated, ICPC Rules, Teams Preferred)")

We can solve this problem using square root decomposition. First we group the events into $\sqrt Q$ blocks of sizes $\sqrt Q$ and solve for each block independently.

For the start of each block, we can calculate all values of $A$ and $B$ easily. Additionally, we can calculate: 

* $\text{biggerA}[x]$: the number of values of $A$ bigger than $x$.
* $\text{biggerB}[x]$: the number of values of $B$ bigger than $x$.

So, $\text{RankA}(i)=\text{biggerA}[A_i]+1$ and $\text{RankB}(i)=\text{biggerB}[B_i]+1$.

Notice that if we increase or decrease a value of $A$ by $1$, only one value of $\text{biggerA}$ changes. This means, the values of $\text{RankA}$ that change are only the changed $A$ value itself and a group of players with the same value of $A$. The same thing also applies for $B$, $\text{biggerB}$ and $\text{RankB}$.

For a single block, let's simulate the changes in $A$ and $B$ and keep track of which players change value at least once in the block. Additionally, keep track of which indices in $\text{biggerA}$ and $\text{biggerB}$ change at least once in the block and denote these indices as special values in each of $\text{biggerA}$ and $\text{biggerB}$.

For a single block, let's group the players into several types: 

* A blue player is a player that changes value at least once in the block.
* An orange player is a non-blue player that has both of its $A$ and $B$ values as special values in each of $\text{biggerA}$ and $\text{biggerB}$.
* A yellow player is a non-blue player that has exactly one of its $A$ and $B$ values as a special value in $\text{biggerA}$ or $\text{biggerB}$ respectively.
* The rest are white players.

Notice that there are at most $\sqrt Q$ blue players and at most $\sqrt Q$ special values in each of $\text{biggerA}$ and $\text{biggerB}$.

Before simulating the events in the block, we must do some precomputations.

For orange and white players only, calculate the following: 

* $\text{smallerOverall}[x]$: the number of orange and white players with $\text{RankA}+\text{RankB}<x$.

In order to maintain the value above, for orange players, calculate the following: 

* $\text{cnt}[i][j]$: the number of orange players whose values of $A$ and $B$ are the $i$-th and $j$-th special values in $\text{biggerA}$ and $\text{biggerB}$ respectively.

For each special value in $\text{biggerA}$, consider every yellow player that has that value of $A$. Notice that their values of $\text{RankB}$ will not change in the block. So we can precompute their values of $\text{RankB}$ and maintain them in a sorted array. We do a similar thing for the special values in $\text{biggerB}$ and their yellow players.

After doing all those precomputations, we simulate each event in the block. We do each change while maintaining all values of $A$, $B$, $\text{biggerA}$, $\text{biggerB}$, and $\text{smallerOverall}$. To maintain $\text{smallerOverall}$ while considering orange players, notice that we can update it naively using the values of $\text{cnt}$ since there are at most $\sqrt Q$ different values of $\text{RankA}+\text{RankB}$ of orange players that change in each change event (because there are at most $\sqrt Q$ special values) and each change in $\text{RankA}+\text{RankB}$ only changes one value of $\text{smallerOverall}$.

For each query event asking $\text{RankOverall}(k)$, do the following: 

* Calculate $w=\text{RankA}(k)+\text{RankB}(k)$.
* For each blue player, calculate its $\text{RankA}+\text{RankB}$ and check if its value is smaller than $w$.
* For the orange and white players, just use the value of $\text{smallerOverall}(w)$.
* For the yellow players, for each special value, use binary search to find the number of players with $\text{RankA}+\text{RankB}<w$ (use $\text{RankB}<w-\text{RankA}$ for the special values in $\text{biggerA}$).
* The value of $\text{RankOverall}(k)$ can be calculated using all values above.

Notice that there is a log factor for sorting and binary search.

Time complexity: $O((N+Q)\sqrt{Q}\log N)$

Note: There is a $O((N+Q)\sqrt{Q})$ solution but the implementation sounds very heavy and tedious so it is not necessary to get accepted.

[1866G. Grouped Carriages](../problems/G._Grouped_Carriages.md)
-------------------------------------------------------------------------

Author: [ArvinCiu](https://codeforces.com/profile/ArvinCiu "Master ArvinCiu")  
Developer: [ArvinCiu](https://codeforces.com/profile/ArvinCiu "Master ArvinCiu") 

 **Tutorial**
### [1866G - Grouped Carriages](../problems/G._Grouped_Carriages.md "COMPFEST 15 - Preliminary Online Mirror (Unrated, ICPC Rules, Teams Preferred)")

Suppose we set the maximum number of passengers in the same carriage to be at most Z. If there is a valid strategy to fit the constraint, doing the same strategy for every maximum number of passengers in the same carriage that is greater than Z is also possible. Hence, we can try to find the answer by doing binary search the answer.

Note that a passenger from carriage i can move to carriage j as long as i−Di≤j≤i+Di. So for each initial carriage i, create a segment [i−Di,i+Di].

Suppose we try to find a valid strategy for moving the passengers with the constraint that the maximum number of passengers in the same carriage is at most Z. We can solve this greedily. Iterate the destination carriages from left to right to be filled with passengers. The initial carriages that can fill the current carriage are only the ones whose segments contain the current carriage.

Note that it is always optimal to take passengers from the segments with the smallest right endpoints first. We take the passengers until the current destination carriage reaches Z passengers or there are no more segments to take from.

If there exists a non-empty segment of an initial carriage that cannot donate its passengers anywhere, then it is impossible.

We can do something like line sweep and prioritise the segments based on their right endpoints using priority queue or other data structures.

Time complexity: O(NlogNlogmax(A))

[1866H. Happy Sets](../problems/H._Happy_Sets.md)
------------------------------------------------------------------

Author: [Edbert.H](https://codeforces.com/profile/Edbert.H "Expert Edbert.H")  
Developer: [Edbert.H](https://codeforces.com/profile/Edbert.H "Expert Edbert.H") 

 **Tutorial**
### [1866H - Happy Sets](../problems/H._Happy_Sets.md "COMPFEST 15 - Preliminary Online Mirror (Unrated, ICPC Rules, Teams Preferred)")

First, consider all possible arrays S′ (the array of sets after rearranging). For each valid S′, we want to find the number of ways to shuffle it. The answer to the original problem is equal to the sum of ways to shuffle each possible S′, since for each shuffled S′ it can be shown that there is only one way to rearrange it into a valid S′.

Notice that a valid S′ always consists of a group of empty sets and a group of pairwise distinct non-empty sets. That means, if there are e empty sets, then there are N!e! ways to shuffle S′.

From the knowledge above, we can group all possible valid arrays S′ into groups based on the number of empty sets and count the number of valid arrays S′ in each group. Then for each group, multiply the number of valid arrays S′ by the number of ways to shuffle S′ for that number of empty sets, then add it to the answer.

Now, define f(e) as the number of valid arrays S′ with exactly e empty sets. Define g(e) as the number of valid arrays S′ with at least e empty sets. We get that f(e)=g(e)−g(e+1).

Let's calculate g(e). For an array of sets S′, we can consider it as a set of pairs (p,x), where each pair (p,x) denotes that S′p contains x. Notice that for some value x: 

* (N−1,x−1) can only exist if (N,x) exists.
* (N−2,x−2) can only exist if (N−1,x−1) exists.
* (N−3,x−3) can only exist if (N−2,x−2) exists.
* And so on.

Therefore, we can group the possible pairs into groups [(N,x),(N−1,x−1),(N−2,x−2),…] and for every group, if it has c pairs, then there are only c+1 configurations for that group (only the first i pairs exist for every 0≤i≤c). The total number of configurations is the product of c+1 for every group.

Consider the size of each group. There are only K groups, each starts with (N,x) for every 1≤x≤K. The group that starts with (N,x) has min(x,N−e) possible pairs. That means, the size of each group is [1,2,3,…,N−e−2,N−e−1,N−e,N−e,N−e,…]. Therefore, g(e)=(N−e+1)!(N−e+1)(K−(N−e)). We can calculate all values of g(e) using factorial precomputation and binary exponentiation.

Time complexity: O(NlogK)

[1866I. Imagination Castle](../problems/I._Imagination_Castle.md)
--------------------------------------------------------------------------

Author: [CyberSleeper](https://codeforces.com/profile/CyberSleeper "Expert CyberSleeper")  
Developer: [CyberSleeper](https://codeforces.com/profile/CyberSleeper "Expert CyberSleeper") 

 **Tutorial**
### [1866I - Imagination Castle](../problems/I._Imagination_Castle.md "COMPFEST 15 - Preliminary Online Mirror (Unrated, ICPC Rules, Teams Preferred)")

Define a winning tile as a tile where if a player starts a turn with the castle in that tile, she will have a strategy to win. Define a losing tile as a tile where if a player starts a turn with the castle in that tile, no matter what she does, the other player will always have a strategy to win. We can see each special tile as a losing tile.

We can solve the problem by finding which tiles are the losing tiles. We can do that by doing "backtrack" from the bottom right corner of the board. Maintain a pointer (r,c) which means that we have solved all tiles (r′,c′) with r′>r or c′>c. So initially, (r,c)=(N,M) (no tiles are solved).

There are three cases for each iteration of the pointer: 

* If there is at least one special tile (r′,c′) satisfying r′=r and c′≥c, then all non-special tiles (r″,c″) satisfying r″=r and c″<c are winning tiles. Then, move (r,c) one step up.
* If there is at least one special tile (r′,c′) satisfying c′=c and r′≥r, then all non-special tiles (r″,c″) satisfying c″=c and r″<r are winning tiles. Then, move (r,c) one step to the left.
* If neither of the cases above holds, then (r,c) itself is a losing tile and all non-special tiles (r″,c″) satisfying one of the following is a winning tile:
	+ r″=r and c″<c
	+ c″=c and r″<r Then, move (r,c) one step up and to the left.

Chaneka wins if (1,1) is a winning tile. Bhinneka wins if (1,1) is a losing tile.

Time complexity: O(N+M+K)

[1866J. Jackets and Packets](../problems/J._Jackets_and_Packets.md)
---------------------------------------------------------------------------

Author: [asteriskzie](https://codeforces.com/profile/asteriskzie "Specialist asteriskzie")  
Developer: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe") 

 **Tutorial**
### [1866J - Jackets and Packets](../problems/J._Jackets_and_Packets.md "COMPFEST 15 - Preliminary Online Mirror (Unrated, ICPC Rules, Teams Preferred)")

Instead of looking at the two stacks as two separate arrays, consider them as a single array A whose elements are the colours of the jackets in the right stack from bottom to top, then the colours of the jackets in the left stack from top to bottom. Also maintain a pointer that indicates the separation point between the right and left stack parts of the the array (the pointer is located at the gap between two adjacent elements instead of at an element). So, A is initially equal to C with the pointer located directly to the left of the leftmost element.

Notice that a movement operation is equivalent to moving the pointer one step to the left or right. A packing operation is equivalent to erasing a contiguous group of elements of the same value directly to the left or to the right of the pointer.

We can solve this problem using dynamic programming. Define the following values: 

* dp[l][r]: the minimum time to erase all elements if the array is A[l..r] and the pointer is located directly to the left of the leftmost element.

Now, consider the two transition cases for dp[l][r].

If Al does not get erased in the same operation as Ar, then optimally, there must be a prefix of A[l..r] (let's say it is A[l..p]) that gets entirely erased before doing anything with the rest of A[l..r]. For a particular partition of prefix, we must solve for that prefix, then solve for the rest. So to calculate for this case, we must find the minimum of all values of dp[l][p]+dp[p+1][r].

If Al gets erased in the same operation as Ar (can only happen when Al=Ar), then there must be a set of disjoint segments entirely within segment [l,r] where every single one of those segment gets entirely erased before the one single packing operation that simultaneously erases Al and Ar. It must hold that every element outside of the segments has the same value as Al and Ar.

For the case above, notice that in the optimal way, we repeatedly iterate the pointer directly to the left of each segment and completely erase the segment before going for the next segment. After all that, we can choose to move the pointer either directly to the left of Al or to the right of Ar, then erase the rest of A[l..r] in one packing operation.

To handle this, we define two new DP values for the case where Al and Ar get erased in the same operation: 

* dpA[l][r]: the minimum time for this case if after erasing the last segment, the pointer moves to the right of Ar.
* dpB[l][r]: the minimum time for this case if after erasing the last segment, the pointer moves to the left of Al.

The transitions for dpA are: 

* If all elements of A[l..r] have the same value, then dpA[l][r]=Y×(r−l+1)+X (the pointer moves to the very right, then erases all elements).
* Else, then we check every possible index p for the next index in A[l..r] not in the set of segments after l. So dpA[l][r] is the minimum of Y+dpA[l+1][r] and all values of Y+dp[l+1][p−1]+dpA[p][r] for all Ap=Al (the pointer moves one step to the right, then solves A[l+1..p−1], then continues to solve the rest of A[l..r] knowing that Al will get erased along with Ar in the end).

The transitions for dpB are: 

* If all elements of A[l..r] have the same value, then dpB[l][r]=X (the pointer moves to the very left, then erases all elements).
* Else, then we check every possible index p for the next index in A[l..r] not in the set of segments after l. So dpB[l][r] is the minimum of Y×2+dpB[l+1][r] and all values of Y×2+dp[l+1][p−1]+dpB[p][r] for all Ap=Al (the pointer moves one step to the right, then solves A[l+1..p−1], then continues to solve the rest of A[l..r], then moves the pointer all the way to the left passing through Al once again, before erasing the initial Al and Ar in one packing operation).

Time complexity: O(N3)

[1866K. Keen Tree Calculation](../problems/K._Keen_Tree_Calculation.md)
-----------------------------------------------------------------------------

Author: [nandonathaniel](https://codeforces.com/profile/nandonathaniel "Candidate Master nandonathaniel")  
Developer: [Pyqe](https://codeforces.com/profile/Pyqe "International Grandmaster Pyqe") 

 **Tutorial**
### [1866K - Keen Tree Calculation](../problems/K._Keen_Tree_Calculation.md "COMPFEST 15 - Preliminary Online Mirror (Unrated, ICPC Rules, Teams Preferred)")

First, calculate the diameter of the initial tree.

For a question involving some vertex $p$. There are only two cases to consider: 

* The diameter is the same as the diameter of the initial tree.
* The diameter goes through vertex $p$.

If the diameter goes through vertex $p$, then the diameter consists of two paths, each of them is from vertex $p$ to some other vertex, but the vertex immediately next to vertex $p$ in the two paths must be different.

Consider a vertex $p$. Let $q_1,q_2,q_3,\ldots,q_{\text{deg}[p]}$ be the vertices adjacent to $p$ with $\text{deg}[p]$ being the degree of $p$. For each $q_i$, calculate: 

* $m_i$: The length of the edge connecting vertices $p$ and $q_i$.
* $c_i$: The maximum length of a path from $q_i$ to another vertex that does not pass through $p$.

All values of $c_i$ can be calculated using dynamic programming on tree with rerooting.

Notice that for a query involving vertex $p$ with a multiplier of $x$. The diameter that goes through vertex $p$ is the sum of the two biggest values of $m_i\times x+c_i$.

From this knowledge, we can consider each vertex $q_i$ as a line equation of $y=m_i\times x+c_i$. In order to be able to find the biggest value of $m_i\times x+c_i$ for any $x$, we maintain the maximum convex hull out of all those lines and we answer each query using binary search.

In order to be able to find the second biggest value of $m_i\times x+c_i$ for any $x$, we maintain several more convex hulls. Let $h_1,h_2,h_3,\ldots$ be the indices of the lines in the maximum convex hull sorted from the smallest $m$ to the biggest $m$. Then, for each $h_j$, we maintain a new maximum convex hull out of all lines $i$ with $m_{h_{j-1}}\leq m_i\leq m_{h_{j+1}}$ other than line $h_j$. We do that to maintain the candidate lines of the second biggest value if the biggest value is taken from line $h_j$. This can be done because lines $h_{j-1}$ and $h_{j+1}$ are two of the candidate lines, so the only other possible candidate lines that can produce bigger values in this particular location are lines $i$ with $m_{h_{j-1}}\leq m_i\leq m_{h_{j+1}}$.

Each line can only be in at most three different convex hulls, so the total number of lines to be considered in the making of all convex hulls for vertex $p$ is $O(\text{deg}[p]$). So in total, for all vertices $p$, the total number of lines is $O(N)$.

Time complexity: $O((N+Q)\log N)$

[1866L. Lihmuf Balling](../problems/L._Lihmuf_Balling.md)
----------------------------------------------------------------------

Author: [gansixeneh](https://codeforces.com/profile/gansixeneh "Candidate Master gansixeneh")  
Developer: [gansixeneh](https://codeforces.com/profile/gansixeneh "Candidate Master gansixeneh") 

 **Tutorial**
### [1866L - Lihmuf Balling](../problems/L._Lihmuf_Balling.md "COMPFEST 15 - Preliminary Online Mirror (Unrated, ICPC Rules, Teams Preferred)")

To solve this, we just need to find the total number of balls Lihmuf will earn for each possible value of $K$ from $1$ to $M$.

If $K=1$, then Lihmuf gets $0$ balls.

If $K>1$ and $K$ is a factor of $N$, then Lihmuf will get all balls in the boxes with indices that are multiples of $K$.

If $K$ is not coprime to $N$, then Lihmuf can only possibly get the balls in the boxes with indices that are multiples of a factor of $N$ greater than $1$, which is already covered by the case above, so this is always not optimal.

Then, that leaves us with the case where $K>1$ and $K$ is coprime to $N$. Notice that in this case, Lihmuf will access each box exactly once.

For this case, consider the sequence of indices of the boxes accessed by Lihmuf. We can group this sequence into exactly $K$ groups, where each group consists of a sequence of indices $c$, $c+K$, $c+2K$, $c+3K$, and so on for some value $1\leq c\leq K$. For each group, while Lihmuf is accessing the boxes in the group, at the same time, Pak Chanek is accessing boxes $d$, $d+1$, $d+2$, $d+3$, and so on for some value $d$.

For this case, since $K>1$, that means at some point, Lihmuf will overtake Pak Chanek in the index of the box he accesses. That happens once $c+K\times p>d+p$ for some $p\geq0$. From that point on, Lihmuf will get all balls in the boxes he accesses in that group. The number of balls earned by Lihmuf in each group can be calculated in $O(1)$ using simple math and using the formula for the sum of an arithmetic sequence.

The total time complexity to calculate for a single value of $K$ is $O(K)$, so the total time complexity is $O(M^2)$.

Time complexity: $O(M^2)$

[1866M. Mighty Rock Tower](../problems/M._Mighty_Rock_Tower.md)
-------------------------------------------------------------------------

Author: [ArvinCiu](https://codeforces.com/profile/ArvinCiu "Master ArvinCiu")  
Developer: [ArvinCiu](https://codeforces.com/profile/ArvinCiu "Master ArvinCiu") 

 **Tutorial**Tutorial is loading...