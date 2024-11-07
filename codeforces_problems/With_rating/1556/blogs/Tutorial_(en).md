# Tutorial_(en)


### [1556A - A Variety of Operations](../problems/A._A_Variety_of_Operations.md "Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)")

Note, that after any of the operations, the parity of the expression $a - b$ does not change, so if the initial difference of the pair $c - d$ is odd, then it is impossible to get this pair. Now, note that if we can get a $(c, d)$ pair, then it can be obtained in no more than $2$ operations. To do this, consider three cases:

* $c = d = 0$  — in this case answer is $0$, because initial pair is $(0, 0)$.
* $c = d$  — in this case answer is $1$. For this, it is enough for us to use the operation of the first type with $k = c = d$.
* $c \neq d$  — in this case answer is $2$. For this we can use the operations of the first type with $k = \frac{c + d}{2}$. After that, it is enough for us to use either an operation of the second type with $k = c - \frac{|c - d|}{2}$ if $c > d$, or an operation of the third type with $k = d - \frac{|c - d|}{2}$ otherwise.
**Prepared by** [AleXman111](https://codeforces.com/profile/AleXman111 "Candidate Master AleXman111"). 

 
### [1556B - Take Your Places!](../problems/B._Take_Your_Places!.md "Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)")

Note that if the condition $|odd - even| > 1$ is satisfied, where $odd$ is the number of odd numbers, and $even$ is the number of even numbers, then it is impossible to get the required array.

Now, note that it is enough to consider two cases and choose the minimum answer from these cases: 

* The first element will be an odd number.
* The first element will be an even number.

Now we will describe the general solution. Suppose we are now at position $i$ and we must put an element with parity $cur$ on it. Then, we need to find the first element with opposite parity $a_j$, where $i \le j$. After we have done this, it is enough to swap $a_i$ and $a_j$ and add $j - i$ to the answer. To quickly search for a suitable element, it is enough to use two pointers, which will point to the current available even and odd numbers.

**Prepared by** [AleXman111](https://codeforces.com/profile/AleXman111 "Candidate Master AleXman111"). 

 
### [1556C - Compressed Bracket Sequence](../problems/C._Compressed_Bracket_Sequence.md "Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)")

Let's examine a compressed sequence and fix two indexes $l < r, l$ % $2 = 0, r$ % $2 = 1$. Note that it makes no sense to examine other indexes because the correct bracket sequence always begins with the opening bracket and ends with the closing one.

Next, we can calculate the minimum bracket balance on the segment from $l + 1$ to $r - 1$. The minimum bracket balance is the minimum number of opening brackets that we must put before the sequence of brackets in order for it to be regular, provided that we can put any number of closing brackets at the end. Let's denote this number as $minBalance$, and denote the sum of $-c_{l + 1} + c_{l + 2} - c_{l + 2} + \dots$ as $balance$.

The next observation is that if we fix the number of opening brackets taken from $c_l$, then we can count the number of brackets that we should take from $c_r$. Using these observations we can calculate the answer for $l..r$ using the following formula: $min(c_l, c_r-balance) - max(1, minBalance) + 1$.

Note that this problem could also be solved in $O(n)$, but this was not required.

**Prepared by** [Vladik](https://codeforces.com/profile/Vladik "Master Vladik"). 

 
### [1556D - Take a Guess](../problems/D._Take_a_Guess.md "Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)")

To solve this problem, we can use the fact that $a+b=(a$ or $b) + (a$ and $b)$.

Then we can determine the first $3$ numbers in $6$ operations using the sums $a_{01} = a_0 + a_1$, $a_{12} = a_1 + a_2$ and $a_{02} = a_0 + a_2$. Using the formula $a_1 = \frac{a_{01}+a_{12}-a_{02}}{2}$, $a_0 = a_{01} - a_1$ and $a_2 = a_{12} - a_1$.

Knowing one of the numbers, it is quite simple to find all the other numbers using the same principle by using $2 \cdot n$ operations. Then we just need to sort the resulting array and output the k-th element.

**Prepared by** [Vladik](https://codeforces.com/profile/Vladik "Master Vladik"). 

 
### [1556E - Equilibrium](../problems/E._Equilibrium.md "Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)")

The first step to solving this problem is to create some array $C$, where $c_i = a_i - b_i$. Then we can select some elements from this array C and do operations $+1, -1, +1, -1 \dots$ for these elements for the corresponding elements. And the challenge is to make this array consist of zeros.

It is argued that this can always be done if the following conditions are met: 1. no prefix with positive-sum and no suffix with negative 2. the sum of all elements is zero

Let us prove the sufficiency of these conditions: we can find the smallest prefix with a negative sum and the smallest suffix with a positive one, do the operation with one $+1$ and one $-1$, and reduce the sum of the absolute values ​​of the elements.

Assertion: the minimum number of operations is the maximum modulus of the sum on the subsegment. This is a lower estimate, since on any segment, the sum changes by at most 1. Let us prove the upper bound by presenting a constructive solution. Let now the array of differences $c_1, c_2, \dots, c_n$, and the maximum modulus of the sum is $M$.

Let's do the following: find the first negative number, there is $+1$, the first positive number after it, there is $-1$, and so on. Statement: the last operation will be $-1$, because otherwise, our last nonzero number is negative, which means it is a negative prefix.

We can reformulate greed as follows: throw out all zeros, put $+1$ in the first element for each negative segment, and $-1$ for each positive one in the first element. Let us prove that on any subsegment with the sum $M$, it has decreased in absolute value. Without loss of generality, consider the segment $[l, r]$ with a positive-sum [the prefix corresponds to the suffix].

Consider again the array obtained by throwing out zeros. It is clear that our segment $[l, r]$ did not cut any segment of negative/positive ones, otherwise, it has no maximum sum. It is also clear that the first and last segments in $[l, r]$ are positive, so we have bet $-1$ more than $+1$. 

**Prepared by** [netman](https://codeforces.com/profile/netman "Candidate Master netman"). 

 
### [1556F - Sports Betting](../problems/F._Sports_Betting.md "Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)")

Let $ALL$ be all teams, and $F(winners)$ be the probability that a set of $winners$ teams are winners, and the rest of $ALL \setminus winners$ teams are not.

Then the answer will be the following value:

$$ \sum_{winners \neq \varnothing, winners \subseteq ALL} F(winners) \cdot |winners| $$

Let's define extra value:

$P(winners)$ — the probability that all teams from the set $winners$ are reachable from each other, that is, they form a cycle.

Then $F$ is calculated as follows: $F(winners) = P(winners) \cdot G(winners, ALL \setminus winners)$.

This is explained as follows: the probability that the set $winners$ will be the set of winners is equal to the probability that the set $winners$ forms a cycle and there is no edge from the set $ALL \setminus winners$ to $winners$.

Where $G(X, Y)$ denotes the probability that all teams from the set $X$ defeat all teams from the set $Y$ directly. More formally speaking, the probability that for every $x$ in $X$, and for every $y$ in $Y$, there is an edge from $x$ to $y$.

It remains to learn how to count $P(winners)$.

It is easy to see that this can be done using the inclusion-exclusion principle:

$$ P(winners) = 1 - \sum_{sub \subset winners, sub \neq winners} P(sub) \cdot G(sub, winners \setminus sub) $$

The formula is explained as follows: we need to know the probability that all teams from the set $winners$ are reachable to each other, initially we set this probability equal to $1$, then subtract all options when only some subset $sub$ of the set $winners$ is reachable to itself.

$G(X, Y)$ is calculated as follows:

$$ G(X, Y) = \prod_{x \in X, y \in Y} \frac{a_x}{a_x + a_y} $$ 

Writing these formulas into the code in the simplest way, you can get a solution with asymptotics $O(3^{N} \cdot N^2)$. Since here $O(3^N)$ pairs $(winners, sub)$ exist, where $winners$ is the set of winners and $sub$ is its subset in the inclusion-exclusion formula. Also, for each such pair, you will have to calculate the value of $G(sub, winners \setminus sub)$ in $O(N^2)$.

But it is possible to calculate $G(X, Y)$ faster.

For example, you can notice that $G(X, Y) = \prod_ {x \in X} H(x, Y)$, where $H(x, Y)$ is the probability that the command $x$ defeated all teams from the set $Y$ directly. $H$ can be pre-calculated in advance for $O(2^N \cdot N)$, which will allow us to calculate $G(X, Y)$ in $O(N)$ instead of $O(N^2)$.

In a similar way, you can learn how to calculate $G(X, Y)$ in $O(1)$, if you pre-calculate the following four values: $G_{left, left}(X, Y)$, $G_{left, right}(X, Y)$, $G_{right, left}(X, Y)$, $G_{right, right}(X, Y)$.

Where $left, right$ is an arbitrary division of teams into two equal (or almost equal) sets, so that $||left| - |right|| \leq 1$ is satisfied.

Where $G_{side_{from}, side_{to}}(X, Y) = G(X, Y)$, only for subsets such that $X \subseteq side_{from}, Y \subseteq side_{to}$.

As a result:

$$ G(X, Y) = \prod_{side_{from} \in \{ left, right \} } \prod_{side_{to} \in \{ left, right \} } G_{side_{from}, side_{to}}(X \cap side_{from}, Y \cap side_{to}) $$

Each of $G_{side_{from}, side_{to}}$ can be pre-calculated in $O(2^N \cdot N)$.

Final asymptotics $O(3^N)$.

**Prepared by** [netman](https://codeforces.com/profile/netman "Candidate Master netman"). 

 
### [1556G - Gates to Another World](../problems/G._Gates_to_Another_World.md "Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)")

Let's change the formulation of the problem: we will execute queries in reverse order, and assign a lifetime to each segment of blocked vertices. Lifetime — until what moment the segment is blocked. Note, if we look through the requests in reverse order, then for each segment it is possible to determine the moment of time after which the vertices from this segment cease to be blocked.

Thus, the problem looks like this: given a graph that is an $n$-dimensional hypercube (each vertex has $n$ edges to adjacent vertices that differ from it by only one coordinate), and there are $m$ blocked vertex segments $[l_i \dots r_i]$ that live up to the time $t_i$.

Consider the following fact:

If we take an $n$-dimensional hypercube and sequences of vertices $0, 1, \dots, 2^{n-1} - 1$ and $2^{n-1}, 2^{n-1} + 1, \dots, 2^{n} - 1$, then the numbers in the corresponding positions from these two sequences are neighbours to each other, since they differ only in the most significant bit, that is, in the $ 2^{n-1}$ bit. For a better understanding, let's depict this for $n = 4$:

* $ 0000 - 1000 $
* $ 0001 - 1001 $
* $ 0010 - 1010 $
* $ 0011 - 1011 $
* $ 0100 - 1100 $
* $ 0101 - 1101 $
* $ 0110 - 1110 $
* $ 0111 - 1111 $

Here $a - b$ denotes that $a$ is a neighbour of $b$, and $a$ is present in the first sequence, and $b$ in the second.

For simplicity, we will only prohibit movement between a blocked vertex and an unblocked one. Let's learn how to get a "compressed" graph, each vertex of which would represent a connected subset of the vertices of the hypercube. Also, this set, which represents a vertex, is a set of consecutive vertices, that is, it is a segment. On each edge of this graph is written the time — when this edge begins to exist. Time makes sense, since an edge can be drawn between a vertex that represents a set of blocked vertices and a vertex that represents a set of unblocked vertices. And the time on this edge there will be a moment in time when the set of vertices is unblocked. Recall that now we are solving a problem in which the vertices are blocked until a certain moment in time. The answer to the reachability request is the reachability request for a given "compressed" graph. It is only necessary to correctly determine the reachability of which two vertices of the "compressed" graph we are interested in.

Let's learn how to recursively build a given compressed graph.

Input data for the construction of this graph are: $n$ — the dimension of the hypercube, $S = \{ (l_i, r_i) \}$ — the set of blocked vertices. If there are no segments worth blocking, then the compressed graph is one vertex, which is responsible for the connected set $ \{0, 1, 2, \dots, 2^{n} - 1 \}$ of hypercube vertices. If there is one segment $(l_i, r_i) = (0, 2^{n} - 1)$, then the compressed graph is one vertex representing all vertices, and they are all blocked.

Otherwise, we can divide the hypercube into two parts: by the most significant bit. That is, into two hypercubes of dimensions $2^{n-1}$. And each segment $l_i, r_i$ can go further, as input, either into two hypercubes, or into one of them. Having received compressed graphs from each of the two hypercubes, we can match the adjacent vertices of these hypercubes, as illustrated above.

It is not difficult to combine two such graphs, since each vertex of the graph describes the set of vertices of the hypercube, and this set is a segment, therefore, if we have the vertices of the first and second graphs, $V_1$ and $V_2$, respectively, in ascending order of the segments for which they answer, then it is possible to combine these two graphs in $O(|V_1| + |V_2|)$ time, and create no more than $O(|V_1| + |V_2|)$ edges and obtain a new graph of size $|V_1| + |V_2|$.

In total, the resulting graph will have a size of $n \times m$, and the final asymptotics will be $O(n^2 \times m \times ACK)$, where $ACK$ is the cost of the operation in the DSU. The DSU is needed to pass queries in reverse order and connect the edges at the right times when the edges begin to exist.

The asymptotics is as follows, since each vertex of the graph may go through all $n$ layers of recursion (as you may have noticed, the solution procedure resembles divide and conquer) and at the same time create a new edge in each layer. And the graph has such a size, since each blocked segment in this procedure can be split into $n$ segments.

For a better understanding, see the author's solution.

**Prepared by** [netman](https://codeforces.com/profile/netman "Candidate Master netman").

 Tutorial is loading...**Prepared by** [300iq](https://codeforces.com/profile/300iq "Legendary Grandmaster 300iq"). 

**P.S.** Editorial for problems **E** and **G** will appear a little later.

