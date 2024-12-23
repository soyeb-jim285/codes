# Tutorial_(en)

Hello! I hope all of you enjoyed my contest!

 
### [1339A - Filling Diamonds](../problems/A._Filling_Diamonds.md "Codeforces Round 633 (Div. 2)")

The key observation of this problem is, wherever you put vertical diamond at some point, all other places are uniquely placed by horizontal diamonds like picture below.

 ![](images/d05132e8bf3b64a20000115b46600a3302c69a9c.png) There are $n$ places you can put vertical diamond, so answer is $n$ for each test case.

**Behind story of A**:

 * I tried to make the easiest Div2A ever. Will it work? :)

 
### [1339B - Sorted Adjacent Differences](../problems/B._Sorted_Adjacent_Differences.md "Codeforces Round 633 (Div. 2)")

Sort the list, and make an oscillation centered on middle element like picture below.

 ![](images/789052e1f8c8408dbe8ed8a9a628b6d6aebb1b11.png) In this way, you will always achieve to make $|a_{i} - a_{i+1}| \le |a_{i+1} - a_{i+2}|$ for all $i$. Time complexity is $O(n \log n)$.

**Behind story of B**:

 * I tried to block various heuristics. There were some critical heuristics which could pass so many cases. Fortunately I blocked them during testing period, so I hope there won't be much FST this time.

 
### [1338A - Powered Addition](https://codeforces.com/contest/1338/problem/A "Codeforces Round 633 (Div. 1)")

First, let's define $b$ as ideal destination of $a$, when we used operations.

Observation 1. Whatever you select any $b$, there is only one way to make it, because there is no more than single way to make specific amount of addition. That means we just have to select optimal destination of $a$.

For example, if you want to make $a_{1}$ from 10 to 21, then you must do $10 \to 11 \to 13 \to 21$. There is no other way to make $10$ to $21$ using given operations.

So now we have to minimize $max(b_{1} - a_{1}, b_{2} - a_{2}, \ldots, b_{n} - a_{n})$, as smaller differences leads to use shorter time to make $a$ nondecreasing.

Observation 2. $b$ is optimal when $b_{i}$ is the maximum value among $b_{1}, b_{2}, \ldots, b_{i-1}$ and $a_{i}$.

Because for each position $i$, we have to make $b_{i} - a_{i}$ as smallest possible. Since $b_{i}$ should be not smaller than previous $b$ values and also $a_{i}$, we derived such formula.

So from position $1, 2, \ldots, n$, greedily find a $b_{i}$, and check how many seconds needed to convert $a_{i}$ to $b_{i}$. The answer is maximum needed seconds among all positions.

Time complexity is $O(n)$, but you can do $O(n \log n)$ with "std::set" or whatever.

**Behind story of D2C/D1A**:

 * Originally, there was a different problem for this position. But it used XOR. As I made new D2E/D1C problem, I threw old D2C/D1A away and put this.

 
### [1338B - Edge Weight Assignment](https://codeforces.com/contest/1338/problem/B "Codeforces Round 633 (Div. 1)")

Let's make an easy and good construction which can solve actual problem. Now reroot this tree at any leaf like picture below;

 ![](images/628a7910673a58df94156e47a2e234c949c64297.png) Our goal in this construction is, we are trying to make $xor(path(l_{1}, lca(l_{1}, l_{2}))) = xor(path(l_{2}, lca(l_{1}, l_{2}))) = xor(path(root, lca(l_{1}, l_{2})))$ for all two leaves $l_{1}$ and $l_{2}$ to satisfy $xor(path(l_{1}, l_{2})) = 0$.

First, let's solve about minimum $f$ value. 

Observation 1. You can prove that minimum value of $f$ is at most $3$, by following construction;

 ![](images/c033147934116eb679ddae1edfb14c83099b0823.png) Since we pick any leaf as root, root is not at the top in this picture. Weight of edges are only determined by degree of two vertices and whether that edge is connected to leaf or not. So answer for minimum value is at most $3$.

Observation 2. If there is any construction such that $f = 2$, then it is always possible to have construction of $f = 1$. Because if $f = 2$ then there should be even number of edges for each weight, and you can simply change all weights them to single value without violating validity of edge weight assignment.

If you want to check validity of $f = 1$ assignment, then you can simply check if all leaves have same parity of distance from root. Because distances between all nodes should be even.

Now let's solve about maximum value. 

Observation 3. You can solve maximum value of $f$ by following construction;

 ![](images/90c9d90bbf253b2f62cf5c85b3142de59f8f5cde.png) So for each non-root vertex $i$, assign weight to edge between $i$ and $p_{i}$ by followings ($p_{i}$ is parent of vertex $i$); 

* If $i$ is not leaf, then assign $2^{i}$ as weight.
* Otherwise, assign $xor(path(root, p_{i}))$ as weight.

This will differentize all edges' weights except for multiple leaves's edges which are connected to single vertex, because every non-leaf vertex have different weights of edge to its parent.

So the answer for maximum value is $e - l + m$, where 

* $e$ is number of edges in this tree.
* $l$ is number of leaves in this tree.
* $m$ is number of non-leaves which has at least one leaf as its neighbor.

Time complexity is $O(n)$.

——————

(Update) There is an another way to approach, provided by Darooha. 

If you label vertices instead of edges where all leaves have same label and none of neighbors have same label, then you can consider edge weight as xor of two vertices' labels, so this is basically equivalent to original problem.

Now for minimum, you can see that labelling $0$ to leaves, and $1, 2$ to non-leaves are enough, so you can prove minimum value of $f$ is at most $3$. In same manner, you can try parity checking to check if $f$ value can be $1$ or not.

For maximum, assign $0$ to all leaves and assign all different values($2^{1}, 2^{2}, \ldots$) to non-leaf vertices, then you can see all edge weights(except leaves connected to same vertex) are different.

**Behind story of D2D/D1B**:

 * This problem is the most popular problem among testers. I also like this problem a lot.

 
### [1338C - Perfect Triples](https://codeforces.com/contest/1338/problem/C "Codeforces Round 633 (Div. 1)")

Let's try mathematical induction.

First, suppose you have fully used numbers only between $1$ and $4^{n} - 1$ inclusive. Now we are going to use all numbers between $4^{n}$ and $4^{n+1} - 1$ inclusive by following methods. Following picture is description of $a$, $b$ and $c$ in bitwise manner;

 ![](images/5f0a24543aeade78709e77fee5a18b0e88206748.png) First row means we have already used all numbers until $4^{n} - 1$. Other $3$ rows mean $a$, $b$ and $c$. Keep in mind that $a$, $b$, and $c$ are the lexicographically smallest triple, so $a \oplus b = c$ and $a < b < c$ should be satisfied at the same time.

Observation 1. $a_{2n} = 1$, $a_{2n+1} = 0$, $b_{2n} = 0$, $b_{2n+1} = 1$, $c_{2n} = c_{2n+1} = 1$. Otherwise, $a < b < c$ condition won't be satisfied, because top two digits of $a$, $b$, $c$ are either $01$, $10$, and $11$.

Then we have more freedom in lower digits, because since the highest $2$ digits are all different, then we can fill lower digits of three numbers independently. Now look at picture below;

 ![](images/0c185d1a6606a7421cc262cc66f2ecdc6d0ada9f.png) This table shows you how to fill each $2$ digits of $a$, $b$ and $c$. Observation 2. For each $2$ digits, $a$, $b$ and $c$ should have form like this. Of course, you can use mathematical induction again here; Try to prove this in only $2$ digits at the first, then expand this lemma to $4$ digits, $6$ digits, ..., $2n$ digits.

Now you know the pattern of digits of $a$, $b$, and $c$. Apply this pattern for each test case. Time complexity is $O(\log n)$.

**Behind story of D2E/D1C**:

 * Feedback for this problem was too different by testers.
* I made this problem by modifying [Number Discovery](https://codeforces.com/contest/1242/problem/D), which is one of my previous problems.
* If you OEIS this, then you may find you can use Nimber Arithmetic to solve this.

 
### [1338D - Nested Rubber Bands](https://codeforces.com/contest/1338/problem/D "Codeforces Round 633 (Div. 1)")

Observation 1. You have to generate optimal sequence which is subsequence of path between some two vertices. Neighbors of vertices in optimal sequence will be used as nested rubber bands.

 ![](images/bf9b765c99b4bd284593421ba5099b40108969de.png) This is an example of conversion. Red vertices are picked sequence, and blue vertices are neighbor of red vertices which are used as nested rubber bands. The reason why black vertices can't be used as nested rubber bands is, basically you have to make a tunnel between any two blue lines, but it's impossible, because in each tunnel there is at least one red vertex which blocks complete connection on tunnel.

Also, this can be described as finding maximum independent set on subtree, which consists of vertices which has at most $1$ distance from the optimal path connection of red vertices. Now your goal is to maximize number of blue vertices.

Observation 2. The distances between two adjacent red vertices are at most $2$. Adjacent in this sentence means adjacent elements in generated optimal sequence. Because if there is some unused

 ![](images/b131a7fcbd2beac850977e85ee384b3f0dda29ac.png) It is always optimal to take more red vertices than abandoning black vertices. Note that if there are two black vertices between two red vertices, then we cannot use both of them as blue vertices.

From those two observations, construct tree DP and run for it. Time complexity is $O(n)$.

**Behind story of D1D**:

 * This problem was supposed to be D2E at first. But all LGM testers failed this problem during VC, so we thought that this problem's difficulty is high. Meanwhile, I found that old D1D problem can be easily googled, so we removed that problem, push this problem to be D1D, and made another D1C problem. I will share old D1D later.

 
### [1338E - JYPnation](https://codeforces.com/contest/1338/problem/E "Codeforces Round 633 (Div. 1)")

The solution contains several tricky observations, but its not hard to prove each of them seperately, so I will mention only the key points of the solution and proof.

Firstly, we should repeatedly remove points that have no in-degree. We can calculate their contribution easily.

For a node $x$, define $in(x)$ to be the set of nodes $u$ that $u \rightarrow x$ exists. 

Lemma 1: $in(x) \cup {x}$ has no cycles for any node $x$.

Let's pick $X$ to be the node with maximum in-degree.

Let $P$ = $in(X) \cup {X}$, and let $Q$ = $Z \setminus P$, where $Z$ is the set of all vertices.

Lemma 2: There exist nodes $U \in Q$,$V \in P$, such that $U \rightarrow V$ exists.

Let $R$ = $in(V) \cap Q$, and let $S$ = $Q \setminus R$

Lemma 3: For all nodes $A \in S$,$B \in R$, $A \rightarrow B$ exists.

Lemma 4: $S$ has no cycles, $R$ has no cycles.

Lemma 5: $P$ has no cycles, $Q$ has no cycles. 

That means we have partitioned the graph into two sets of nodes, where each set is completely ordered.

Lets label the nodes in $P$ by $P_i$ where $i$ is an integer from $1$ to $|P|$, such that for two nodes $P_i$ and $P_j$, $P_j \rightarrow P_i$ exists iff $j>i$.

Label nodes in $Q$ by $Q_i$ in similar manner. 

Define $inP(x)$ to be the set of nodes $u \in P$ that $u \rightarrow x$ exists. 

Define $inQ(x)$ to be the set of nodes $u \in Q$ that $u \rightarrow x$ exists. 

Lemma 6a: If $|inQ(P_i)| = |inQ(P_j)|$ then $inQ(P_i) = inQ(P_j)$. 

Lemma 6b: If $|inP(Q_i)| = |inP(Q_j)|$ then $inP(Q_i) = inP(Q_j)$. 

Final observations:

* $dis(P_i,P_j)=1$ iff $i>j$
* $dis(P_i,P_j)=2$ iff $i<j$ and $|inQ(P_i)| \neq |inQ(P_j)|$
* $dis(P_i,P_j)=3$ iff $i<j$ and $|inQ(P_i)| = |inQ(P_j)|$
* $dis(Q_i,Q_j)=1$ iff $i>j$
* $dis(Q_i,Q_j)=2$ iff $i<j$ and $|inP(Q_i)| \neq |inP(Q_j)|$
* $dis(Q_i,Q_j)=3$ iff $i<j$ and $|inP(Q_i)| = |inP(Q_j)|$
* $dis(P_i,Q_j)+dis(Q_j,P_i)=3$

Finally, we can count the answer in $O(N^2)$ by the above observations.

**Behind story of D1E**:

 * Thanks [tzuyu_chou](https://codeforces.com/profile/tzuyu_chou "Legendary Grandmaster tzuyu_chou") for writing this problem. She is genius in both singing and problemsolving.
