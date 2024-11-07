# Tutorial


### [1411A - In-game Chat](../problems/A._In-game_Chat.md "Technocup 2021 - Elimination Round 3")

You should count the number of parentheses at the end of the string, suppose there are $x$ such parentheses. Then if $x > \frac{n}{2}$, message is bad. Note that you should divide $n$ by $2$ without rounding. Or you can compare $2 \cdot x$ and $n$ instead. If $2 \cdot x > n$, the message is bad.

 
### [1411B - Fair Numbers](../problems/B._Fair_Numbers.md "Technocup 2021 - Elimination Round 3")

Let's call a number super-fair if it is divisible by each of the numbers $1..9$. It is fair to say that super-fair numbers are also divisible by $LCM(1..9)$ which is equal to $2520$. The answer isn't larger than the nearest super-fair number, which means that you can increase the original $n$ by one until it becomes fair. We will determine if the number is fair by checking each of its digits separately.

 
### [1411C - Peaceful Rooks](../problems/C._Peaceful_Rooks.md "Technocup 2021 - Elimination Round 3")

Consider rooks as edges in a graph. The position $(x, y)$ will correspond to an edge $(x \to y)$. From the condition that there're at most one edge exits leading from each vertex and at most one edge leading to each vertex, it follows that the graph decomposes into cycles, paths, and loops (edges of type $v \to v$).

What happens to the graph when we move the rook? The edge changes exactly one of its endpoints. By such operations, we must turn all edges into loops, and the constraint on the number of edges going in and out of a vertex must be satisfied. A path is quite easy to turn into loops, just start from one end. A cycle must first be turned into a path, which is always possible. We've only spent one extra move, it's not hard to see that this is optimal.

The answer is the number of rooks minus the number of loops plus the number of cycles.

 
### [1411D - Grime Zoo](../problems/D._Grime_Zoo.md "Technocup 2021 - Elimination Round 3")

Consider two adjacent question marks at positions $l$ and $r$ ($l < r$). Let $c_0$ zeros and $c_1$ ones be on the interval $(l, r)$. In case $s_l = 0$, $s_r = 1$ there will be written $(c_1 + 1) \cdot x + c_0 \cdot x + out = (c_0 + c_1 + 1) \cdot x + out = (r - l) \cdot x + out$ comments, where $out$ is the number of comments for subsequences, at least one element of which is outside $[l, r]$. In the case $s_l = 1$, $s_r = 0$ we get $(c_0 + 1) \cdot y + c_1 \cdot y + out = (c_0 + c_1 + 1) \cdot y + out = (r - l) \cdot y + out$ comments. Subtract the second from the first, we get $(r - l) \cdot (x - y)$. This means the following: if $x \geq y$, it is always better to change $01$ to $10$. That is, there is such an optimal substitution of $?$ by $0$ and $1$ that some prefix of $?$ are replaced by $1$, and the remaining by $0$. In the case of $x < y$, similarly, there will be some prefix of $0$, then suffix of $1$. For $\mathcal{O}(n)$ implementation you can count how many ones and zeros on each prefix and iterate over the separation boundary.

 
### [1411E - Poman Numbers](../problems/E._Poman_Numbers.md "Technocup 2021 - Elimination Round 3")

First, note that the last digit will always be taken with a plus sign, and the one before the last — with a minus sign. It turns out that all other digits may be taken with any sign. Let's prove it.

Suppose we want to get the mask $---++--++---+$. All minuses on the left can be obtained by simply splitting one character at a time. We are left with the $++--++---+$ mask, split it as follows: $(++--++-)(--+)$. That is, we left in the left part only one minus from the last segment of consecutive minuses. Change the signs in the left part: $(--++--+)(--+)$. We reduced it to a smaller problem. Doing this, we will end up with masks of the form $+$.

Now the problem is reduced to whether we can get the number $X$ using the first $n - 2$ letters. Since the weights of the items are powers of two, we can choose them greedily.

Bonus. Can you construct an answer in linear time (i.e. output a binary tree)?

 
### [1411F - The Thorny Path](../problems/F._The_Thorny_Path.md "Technocup 2021 - Elimination Round 3")

The problem boils down to getting an array consisting of threes and a remainder (2 or 2+2 or 4) using split and merge operations. It helps to think that all merge operations are done before split operations.

To solve the problem, you can brute which elements of the array the remainder is subtracted from, then the rest of the operations are done greedily. 

Bonus. Given $k$. We need to get an array consisting of $k$ using these operations. Assume that the sum of the array elements is divisible by $k$. This can be represented as minimum cover of the hypergraph by edges with weights = (number of vertices - 1) + (sum of elements / $k$ - 1). Is there a polynomial solution ($k$ is a parameter)?

 
### [1411G - No Game No Life](../problems/G._No_Game_No_Life.md "Technocup 2021 - Elimination Round 3")

The winner of the game is determined by xor of Grundy values for all chips' vertices. Notice that every Grundy value $\leq\sqrt m$ so xor doesn't exceed 512. Let $P_v$ be a probability of Alice's victory if the current xor is $v$.

$P_v = \sum P_{to}\cdot prob(v \rightarrow to) + [v\neq 0] \cdot\frac{1}{n + 1}$

In the second term, we got $n + 1$ and the process ended. It is clear that $prob(v \rightarrow to) = \frac{cnt[v \oplus to]}{n + 1}$, where $cnt[x]$ is the number of vertices with the Grundy value equal to $x$. Now we have a system of 512 linear equations with variables $P_v$. We can solve it using the Gauss method. The answer is in $P_0$. The proof that Gauss won't break along the way is left to the reader as an exercise.

There is also a solution using the Hadamard transform.

 
### [1464F - My Beautiful Madness](https://codeforces.com/contest/1464/problem/F "Codeforces Round 692 (Div. 1, based on Technocup 2021 Elimination Round 3)")

When I write "a vertex at a distance $d$ up from the given", I mean such a vertex, if it exists; otherwise the root of the tree.

Let's learn how to answer the query of whether the intersection of $d$-neighborhoods of all paths is empty. For a given path poman is a vertex at a distance $d$ up from the LCA of this path.

Lemma: if the intersection is non-empty, then the deepest poman vertex is included in it.

Proof: let the intersection be non-empty, and the deepest poman vertex (let's call it $v$) is not included in the intersection. The path that spawned $v$ is located along with the neighborhood in $v$'s subtree. $v$ is not included in the intersection, so there is some path whose neighborhood does not contain v. Note that it cannot be in the subtree of $v$, since then its poman vertex would be deeper than $v$; hence it lies outside the subtree $v$ with the neighborhood, hence the intersection of all neighborhoods is empty. Contradiction.

This knowledge allows us to check if the intersection is empty by checking if one particular vertex $v$ lies in the intersection (for a query, recognizing $v$ is easy if we maintain a set of LCA of paths from P, ordered by depth). Let $kek$ be a vertex at a distance $d$ above $v$. First, a necessary condition: for each path from $P$, the subtree of $kek$ contains at least one end. Let's implement it like this: when the path $(u, v)$ comes, we do ad[u]++, ad[v]++, ad[LCA(u, v)]--. Now the sum of ad in a subtree of a vertex is the number of ends of different paths in it.

Now we know for sure that there is no path that lies strictly outside the $kek$ subtree, that is, all paths for which LCA is outside the subtree of $kek$ pass through $kek$, and hence $v$ lies in their $d$-neighborhood. The only remaining paths to check are those in the $kek$ subtree. The shortest distance from $v$ to such paths is the distance to their $LCA$ (this is not true if the $LCA$ lies on the path $(v, kek)$, but this path itself has length $d$ and we will definitely reach such $LCA$ from $v$).

We got the following task about processing queries on a tree: 

1. podkek[v]++
2. podkek[v]--
3. among the vertices of the given subtree with $podkek[v] > 0$, find the farthest from the given vertex (also contained in this subtree)

 This one can be solved using HLD in $\mathcal{O}((q + n)\cdot\log^2 n)$, I recommend referring to the code.[Code](https://codeforces.com/contest/1464/submission/101915176)

Btw, congratulations to [Benq](https://codeforces.com/profile/Benq "Legendary Grandmaster Benq") on first-to-solve this problem!

