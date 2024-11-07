# Tutorial_(en)


### [1033A - King Escape](../problems/A._King_Escape.md "Lyft Level 5 Challenge 2018 - Elimination Round")

Imagine a two-dimensional plane with origin positioned on the black queen. We notice that the queen partitions the board into up to four connected components, with each quadrant being one of them. The answer is thus "YES" if and only if the source king position and the target position are in the same quadrant. 

This condition can be checked in O(1) using few simple ifs.

In case you prefer brute force over case analysis, it is also possible to construct the grid graph and find the connected components or use DFS to find the path. This runs in O(n2).

 
### [1033B - Square Difference](../problems/B._Square_Difference.md "Lyft Level 5 Challenge 2018 - Elimination Round")

The task looks simple enough, but there is a problem. The number we want to check might be very large - it might not even fit into 64-bit integer. Checking primality for it certainly cannot be performed naively.

However, the input is no ordinary number. It is of form A2−B2, which can be expressed as (A−B)(A+B). This is prime if and only if A−B=1 and A+B is a prime. Since A+B is at most 2∗1011, we can use trial division to check its primality.

Complexity: O(T√A+B). 

Alternatively, you could cheat and use big integers and test primality using Miller-Rabin algorithm. With Java's BigInteger.isProbablePrime it's not too much work.

 
### [1033C - Permutation Game](../problems/C._Permutation_Game.md "Lyft Level 5 Challenge 2018 - Elimination Round")

The game is finite thanks to the first restriction on possible moves: the number on which the token lies must strictly increase with each turn. More importantly, this means that if we model the cells as vertices of a graph and create a directed edge between i and j if i→j is a valid move, the resulting graph will be acyclic. 

For each vertex we want to know whether it is losing or winning. A vertex is winning if and only if there exists an edge to a losing state. 

This is easily solved on a directed acyclic graph – we process the vertices in reverse topological ordering. Let v denote the current vertex. We already know the outcome of the game for all vertices adjacent to v, hence it is easy to determine whether v is winning.

This process needs O(n+m) time, where m is the number of edges in the graph. In general, this could be quadratic in n, but in this particular graph it's actually much less than that! Thanks to the second restriction on possible moves, there are at most ⌊nai⌋ possible moves from cell with ai written in it. As ai is a permutation, we have at most ∑ni=1⌊ni⌋ potential edges, which is of order O(nlogn).

 
### [1033D - Divisors](../problems/D._Divisors.md "Lyft Level 5 Challenge 2018 - Elimination Round")

Given a prime factorisation a=pe11⋅pe22⋅⋯⋅pekk, one can conclude that the number of divisors of a is ∏(ei+1). Note that we do not need to know the values of pi. Can we perhaps find the exponents, without factorising all inputs? 

A number with between 3 and 5 divisors is of a form pq, p2, p3 or p4, where p and q are primes. We can factorise numbers of all forms except the first easily. How about the rest? We can use Euclidean algorithm to find gcd(ai,aj) for all pairs ai≠aj. If g≠1, we can use it to factorise both ai and aj. 

After this process, some ai all still left unfactorised. We can conclude that they do not share any prime factor with any other number (except the number itself if there are multiple copies). This means that it contributes to the factorisation with two prime factors of multiplicity 1. For all other prime factors, we simply calculate how many times they occur in all factorised ai combined.

This combined, we can evaluate ∏(ei+1). The time complexity is O(n2⋅logmaxai). 

Note that we can factorise all input using Pollard rho algorithm (which has unknown complexity, but it is presumed to be the square root of the smallest prime factor) in O(∑4√ai). This looks good enough, but in practice is very slow and doesn't pass the TL by a large margin.

 
### [1033E - Hidden Bipartite Graph](../problems/E._Hidden_Bipartite_Graph.md "Lyft Level 5 Challenge 2018 - Elimination Round")

Denote by e(A) the number of edges in a vertex set A, and by e(A,B) the number of edges between A and B. Note that e(A,B)=e(A∪B)−e(A)−e(B) can be answered by three queries.

Now we learn how to find an edge in this graph in logarithmic time. Given two sets X and Y, such that e(X,Y)≠0, we can binary search on X, i.e. partition X into disjoint X1 and X2 of roughly equal size. If e(X1,Y)≠0, we continue to find an edge between X1 and Y, otherwise certainly e(X2,Y)=e(X,Y)≠0 and we can search for an edge between X2 and Y. Once |X|=1, we can do a similar binary search on Y. Finally, when both |X|=1 and |Y|=1 while e(X,Y)≠0, we have found an edge in graph G.

How do we use the above construction? We can find a spanning tree of graph G, as follows. Start with S={1} and find an edge between S and V∖S. We remember this edge, add its second endpoint to S and repeat until S=V. 

 ![](images/e34d0524f527422876a3268894f4a45d67e4901d.png) Ugh! Next question? Once we have a spanning tree, the task is much easier. As the knowledge of a spanning tree on a bipartite graph uniquely identifies the partitions (using a simple DFS, for instance), we can use two queries to determine whether the graph is bipartite or not. If it is, we have already found the partition and can report it. Otherwise, we can use similar binary search to find an edge in one of the partitions. Again, we use DFS to find the required cycle of odd length.

The total number of queries is roughly 6NlogN, as for each vertex, we perform two binary searches and each operation of binary search requires 3 queries. This totals up to 36000, which seems like too much. However, most of the time, one or two of the three queries have already been asked before and we can cache the answers. Furthermore, we can avoid asking queries of size 1 - we know that the answer is simply 0. With these optimisations, we can find out that the actual number of queries is actually around 17000 in the worst case.

 
### [1033F - Boolean Computer](../problems/F._Boolean_Computer.md "Lyft Level 5 Challenge 2018 - Elimination Round")

First we count C[i] the number of occurrences of i in the input for each number between 0 and 2w−1. We can then notice that each bit gate G maps between 1 and 3 two-bit patterns to 0 (e.g. for xor gate, this is 00 and 11, for and gate this is 00, 01 and 10). This means that we can calculate the answer for each number gate in O(3w), which yields O(m⋅3w) algorithm, that is clearly too slow. How do we make this faster? There are at least two approaches.

1. Interpret each binary input as if it were ternary. For instance, 11=10112≈10113. Consider two ternary numbers consisting only of digits 0 and 1 and their sum  – e.g. 10013+10103=20113. Since there are no carryovers, the i-th digit of the sum tells us how many of the two summands have the respective digit equal to 1. In the example above, the most significant digit is 2, and we can observe that both inputs have 1 as the most significant digit.Each of the six binary gates in the output behaves identically on two bit patterns 01 and 10. It follows that each number gate G can be expressed as some function G′, such that G(i,j)=G′(i+j), i.e. the outcome of the number gate depends only on their sum. For example, the bit gate AND maps 0, 1 to 0 and 2 to 1, the gate NOT XOR maps 0 and 2 to 1 and 1 to 0. Furthermore, each gate maps between 1 and 2 digits to 0. For each G′, there are thus at most 2w values of x such that G′(x)=0, and those values can be found efficiently.

To find the answer, we need to find for each x∈[0,3w) how many pairs of inputs sum to x in ternary. This amount is equal to the sum ∑i+j=xC[i]∗C[j] where C[i] is the number of occurrences of i in the array A. This can be precomputed once, either by FFT in O(w⋅3w) since it is a convolution, or by brute force in O(4w). The latter has much better constant factor and is in fact slightly faster.

Combined, this yields a O(n+w⋅3w+m⋅2w) algorithm.
2. The second approach was suggested by arsijo. Let's introduce a wildcard in the bit patterns: e.g. 1?0? matches all of 1000, 1001, 1100, 1101. This can be found in O(w⋅3w) from the array C by substituting the bits with the wildcard bit by bit, and denote this array of counts by D.The zero values of each bit gate can be expressed as at most two bit patterns while using wildcards. For instance, the AND gate yields zero with 0? and 10. With the help of the arrays C and D, the answer for each number gate can be found in O(2w).

This also yields a O(n+w⋅3w+m⋅2w) algorithm.
 
### [1033G - Chip Game](../problems/G._Chip_Game.md "Lyft Level 5 Challenge 2018 - Elimination Round")

Let's solve the task for a fixed tuple (a,b). If a=b, this is a very simple symmetric game, where the parity of ∑⌊via⌋ determines the winner (regardless of the players' choices).

Without loss of generality, let a<b as the case where a>b is symmetrical. It is obvious that Bob never has an advantage in this game. Furthermore, the game outcome doesn't change if we set v′i=vimod(a+b). 

To see why this is true, consider a strategy S′ for a winning player in the modified game G′, and build strategy S for the original game: 

* If the winner takes first turn in G′, take the same first turn in G – this is always valid as v′i≤vi.
* If the loser's last turn was valid in the game G′, follow the strategy S′ in the game G. Again, this is valid as v′i≤vi.
* If the loser's last turn was invalid in the game G′, this means that he reduced the state from x1⋅(a+b)+y1 to (x1−1)⋅(a+b)+y2 for some x1>0 and 0≤y1<y2<a+b. The winner can play in the same pile to reduce it to (x1−1)⋅(a+b)+y1, and the corresponding v′i doesn't change. In essence, these two moves are a no-op in the game G′.

 The winner of G′ can always make a move in the game G and hence also wins G.Let's break down the single pile games P based on the number of chips modulo a+b: 

1. 0≤v′i<a: As neither Alice nor Bob can make a move, this is a zero game (P=0).
2. a≤v′i<b: Alice can take at least one move in this pile, and Bob none. This is a strictly positive game (P>0).
3. b≤v′i<2a: If either of the players makes a move, it changes to a zero game. This is thus a fuzzy game (P||0). Note that this interval may be empty.
4. max(2a,b)≤v′i<a+b: If Alice makes a move, she can turn this game into a positive game for her. Bob can turn this into a zero game. This is a fuzzy game (P||0).

As we see, there are no negative games. Hence, in the combined game, we can ignore the zero games in our calculation (type 1) and if there is at least one positive game (type 2), the game is won for Alice. If there is at least one game of type 4 and Alice starts, or at least two games of type 4, Alice can always play one of them to make herself a positive game, thus winning. Otherwise, it is always optimal to play in a game of type 3 or 4 if there is one, and the game is subsequently turned into a zero game. The parity of the number of these games thus determines whether the starting player wins or loses. 

For a fixed (a,b), we are now able to determine the outcome of the game in O(n) time, leading to O(m2n) total runtime, which is too slow.

To make this faster, let's group the games by the sum a+b. For a fixed v′i, define function f(a) which tells us the type of the single-pile game based on the value of a for this particular v′i. We can see that this function is not arbitrary – we can partition the interval [0,a+b) into constantly many intervals on which the function is constant (e.g. if a∈(v′i,a+b), this is a zero game. We simply collect all these intervals for all values of v′i and using a linear sweep determine the outcome of each game. This needs O(nlogn) for sorting and O(n) for the sweep. All combined, this yields a O(mnlogn) algorithm.

Bonus: Can you get rid of the log factor?

