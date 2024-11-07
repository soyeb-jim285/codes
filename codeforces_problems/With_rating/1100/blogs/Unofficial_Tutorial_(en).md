# Unofficial_Tutorial_(en)

Just finished this contest in virtual mode and noticed the editorial is missing, so I thought I would share my approaches.

#### [1100A - Roman and Browser](../problems/A._Roman_and_Browser.md "Codeforces Round 532 (Div. 2)")

Loop over all values of *b* and take the sum of all indices that are not equivalent to ![](images/44d20197f57397c2fb9b8254112925c04de5ec74.png). Remember to take the absolute value at the end. Runtime is ![](images/2ea07df0930018e7899f810e5f4842f0e6499e40.png). Code: [48374675](https://codeforces.com/contest/1100/submission/48374675 "Submission 48374675 by neal")

#### [1100B - Build a Contest](../problems/B._Build_a_Contest.md "Codeforces Round 532 (Div. 2)")

Maintain a frequency array of size *n* and track the number of distinct values seen so far as we loop through the array. Once the number of distinct values reaches *n*, we hold a round and decrement each index of the frequency array. Note that this takes *n* time, but this is fine since we can only hold at most ![](images/d55020b73c619d7d3d5de7cb4885afad3f3ef820.png) rounds. Runtime is ![](images/903b18209c3e5f56a8fe043c8e29ec5ded391a8e.png). Code: [48374608](https://codeforces.com/contest/1100/submission/48374608 "Submission 48374608 by neal"). Note that `x++` means use the value of `x` and then increment, whereas `++x` means increment and then use. Similar for `x--` and `--x`.

#### [1100C - NN and the Optical Illusion](../problems/C._NN_and_the_Optical_Illusion.md "Codeforces Round 532 (Div. 2)")

Draw the line segments between the center of the inner circle and the centers of two adjacent outer circles. These three line segments form a triangle. If the inner radius is *r* and the outer radius is *R*, then the sides of the triangle are *r* + *R*, *r* + *R*, and 2*R*. We also know that the angle of the triangle at the center of the inner circle is ![](images/541d5ff66eeb9af50fba45818322fa7e17bc6274.png). Now we can apply the [Law of Cosines](https://codeforces.com/http://mathworld.wolfram.com/LawofCosines.html) and some algebra to solve for *R*. Code: [48374823](https://codeforces.com/contest/1100/submission/48374823 "Submission 48374823 by neal")

Update: for an even easier method, we can realize that we can cut the angle above in half, which results in ![](images/eaba7bddc0e55c1f939cc0ed03d9d98ce85bd654.png).

#### [1100D - Dasha and Chess](../problems/D._Dasha_and_Chess.md "Codeforces Round 532 (Div. 2)")

This problem has a very clean mathematical solution. It turns out 666 rooks is just enough for us to solve the problem.

First, move to the center of the board, (500, 500). We can do this using at most 499 moves. If any rook is on our row or column we're done, so we can assume that's not the case. Then every rook is in one of the four quadrants surrounding us. Notice that by moving diagonally 499 times in a row, we can fully 'sweep' any of the quadrants we choose.

In addition, every rook is accessible by either row or column in exactly three of the four quadrants. Since 3 × 666 = 1998 > 4 × 499, there must be some quadrant where at least 500 rooks are accessible. We can simply sweep this quadrant fully in 499 moves, and there is no way for our opponent to remove all the rooks fast enough. Code: [48378396](https://codeforces.com/contest/1100/submission/48378396 "Submission 48378396 by neal").

Make sure to handle this case correctly to avoid Wrong Answer: "The king cannot move onto the square already occupied by a rook." (In this case we should easily be able to find a move that immediately wins.)

#### [1100E - Andrew and Taxi](../problems/E._Andrew_and_Taxi.md "Codeforces Round 532 (Div. 2)")

First, struggle to solve the problem for a while. Then realize that you didn't pay enough attention to this sentence: "It is allowed to change the directions of roads one by one, meaning that each traffic controller can participate in reversing two or more roads." So in particular, we are not looking for the sum of modified edges' weights but instead the maximum edge weight we need to modify in order to remove all cycles from the graph.

When we want optimize the maximum of a set of things, it's a good idea to binary search. Let's say we are binary searching and we have a number *C*. Then we want to know if it's possible to remove all cycles by only allowing ourselves to reverse edges with *c* ≤ *C*.

This turns out to have an efficient solution. First, consider all of the edges with *c* > *C*. These edges must not contain a cycle, or else we can immediately decide that *C* is not good enough. If they don't contain a cycle then they will form a [directed acyclic graph](https://codeforces.com/https://en.wikipedia.org/wiki/Directed_acyclic_graph) (or DAG), and we can perform a [topological sort](https://codeforces.com/https://en.wikipedia.org/wiki/Topological_sorting) of this graph. Then for every remaining edge (*c* ≤ *C*), since we have the option to reverse it if we like, we can choose to point the edge in the same direction as the topological sort. Since all edges are then ordered according to the topological sort, there cannot be any cycles. Runtime is ![](images/0106d0b350211521a21d6edbc9810ddb6dd49a86.png), which can be improved to ![](images/36c0e6985cd5a61372ea7e19f9d6eceaac369c19.png) if desired by binary searching on the sorted list of edge weights instead. Code: [48376981](https://codeforces.com/contest/1100/submission/48376981 "Submission 48376981 by neal")

#### [1100F - Ivan and Burgers](../problems/F._Ivan_and_Burgers.md "Codeforces Round 532 (Div. 2)")

Except for the very weird cover story, this problem is similar to [1101G - (Zero XOR Subset)-less](https://codeforces.com/contest/1101/problem/G "Educational Codeforces Round 58 (Rated for Div. 2)") (but harder). I recommend solving that problem first before attempting this one. Both problems are made easier with some knowledge of linear algebra.

For this problem, we want to find the maximum number attainable via XOR within subarrays of our given array. The best way to do this is to treat the numbers as vectors in ![](images/2f18e7b7d89790c576e38f15ad4044bb633f48be.png) and compute a basis ([https://en.wikipedia.org/wiki/Basis_(linear_algebra)](https://codeforces.com/https://en.wikipedia.org/wiki/Basis_(linear_algebra))) of the vector space. In other words, we want to find a minimal set of numbers that we can combine together to generate the full vector space. Since the numbers only have ![](images/e08340eaaa53a9911001861bacacb35838e14c0a.png) bits, one can prove that the basis will have a size of at most 20.

My approach was then to create a seg tree on the array where each node stores a basis of its subarray. Note that it helps to store the basis in strictly decreasing order of highest bit. I join two bases in ![](images/7ec1a8b0337b3ca84769b814a30dddd6fb40ac72.png) time, for an overall runtime of ![](images/011e3339a679e6186e0d5a9ffa713fc2ee29683a.png) per query, which barely fits in the time limit at 2.6s. Code for reference: [48396593](https://codeforces.com/contest/1100/submission/48396593 "Submission 48396593 by neal"). Watch out that *c**i* = 0 is allowed!

It is also possible to solve the problem in ![](images/a7711eb7d69a03afaedcebb1ede9bb6c371ea5e5.png) or even ![](images/b9562e522b2890e9a1775862aa916516a127e6f8.png) time per query. One key idea is to compute for each *L* the at most 20 different *R* values that increase the size of the basis for the subarray from *L* to *R*. See the comment section below for discussion.

