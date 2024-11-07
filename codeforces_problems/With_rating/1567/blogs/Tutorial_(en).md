# Tutorial_(en)

Thank you for participating in our contest! We hope you enjoyed it. **UPD:** Implementations have been added.

[1567A - Domino Disaster](../problems/A._Domino_Disaster.md "Codeforces Round 742 (Div. 2)")

 **Solution**
### [1567A - Domino Disaster](../problems/A._Domino_Disaster.md "Codeforces Round 742 (Div. 2)")

If there is a vertical domino (either U or D) in the current slot, then the corresponding domino half in the other row must be a D or a U, respectively. Otherwise, we can just fill the rest of the row with copies of LR.

Time complexity: $\mathcal{O}(n)$.

 **Implementation (C++)**[127991325](https://codeforces.com/contest/1567/submission/127991325 "Submission 127991325 by flamestorm")

 **Video Solution**[Link to Video](https://codeforces.com/https://www.youtube.com/watch?v=czwX-f9ifvk)

[1567B - MEXor Mixup](../problems/B._MEXor_Mixup.md "Codeforces Round 742 (Div. 2)")

 **Solution**
### [1567B - MEXor Mixup](../problems/B._MEXor_Mixup.md "Codeforces Round 742 (Div. 2)")

First consider the MEX condition: the shortest array with MEX $a$ is the array $[0, 1, \dots, a - 1]$, which has length $a$. Now we'll consider the XOR condition. Let the XOR of the array $[0, 1, \dots, a - 1]$ be $x$. We have three cases.

Case 1: $x = b$. Then we don't need to add any elements to the array, so the answer is $a$.

Case 2: $x \neq b$ and $x \oplus b \neq a$. Then we can add the element $x \oplus b$ to the array since $x \oplus b \neq a$, so the MEX will still be $a$. The XOR of the array will then be $x \oplus x \oplus b = b$. The answer is $a + 1$.

Case 3: $x \neq b$ and $x \oplus b = a$. Then we cannot add the element $x \oplus b$ to the end of the array. We can just add $x \oplus b \oplus 1$ and $1$, so the XOR of the array will be $x \oplus x \oplus b \oplus 1 \oplus 1 = b$. The answer is $a + 2$.

Time complexity: $\mathcal{O}(n)$ precomputation and $\mathcal{O}(1)$ per test case if you precalculate the XOR of the numbers from $0$ to $n-1$, or $\mathcal{O}(1)$ if [you use the well-known formula](https://codeforces.com/https://www.geeksforgeeks.org/calculate-xor-1-n/) for it.

 **Implementation (C++)**[127991329](https://codeforces.com/contest/1567/submission/127991329 "Submission 127991329 by flamestorm")

 **Video Solution**[Link to Video](https://codeforces.com/https://www.youtube.com/watch?v=8h5loLSCkyQ)

[1567C - Carrying Conundrum](../problems/C._Carrying_Conundrum.md "Codeforces Round 742 (Div. 2)")

 **Solution (Observation)**
### [1567C - Carrying Conundrum](../problems/C._Carrying_Conundrum.md "Codeforces Round 742 (Div. 2)")

Note that in every other column, the addition Alice performs is correct. Therefore, we can take our number, split it into alternating digits, and then find the answer.

For example, consider $n = 12345$. We split it into alternating digits: $1\underline{2}3\underline{4}5 \to 135, 24$. Now the problem is equivalent to find the number of pairs of numbers which add to $135$ multiplied by the number of pairs of numbers which add to $24$. It's clear each pair works: for example, $45 + 90 = 135$ and $\underline{9} + \underline{15} = \underline{24}$, so $4\underline{9}5 + \underline{1}9\underline{5}0$ will be equal to $12345$ according to Alice.

Now, how many ways are there to find a pair of non-negative integers whose sum is $n$? There are clearly $n+1$ ways: $n+0,(n-1)+1,(n-2)+2,\dots,0+n$. 

Therefore, suppose we split $n$ into two numbers $a$ and $b$. Then the answer will be $(a+1)(b+1)$, but we should subtract $2$ because those correspond to either the first or second number in the sum being $0$. As a result, the answer is $(a+1)(b+1)-2$.

Time complexity: $\mathcal{O}(\log_{10}n) = \mathcal{O}(\log n)$.

 **Implementation (C++)**[127991331](https://codeforces.com/contest/1567/submission/127991331 "Submission 127991331 by flamestorm")

 **Video Solution**[Link to Video](https://codeforces.com/https://www.youtube.com/watch?v=7ou1zqT55LQ)

 **Solution (DP)**There exists a dynamic programming solution to this problem. Let x be the length (number of digits) of n, and dpi,j,k be the number of pairs of integers (x,y) that add up to the digits from position i to x−1 (0-indexed), with j carried over from the addition one place to the right, and k carried over from the addition at position i. Notice that 0≤j,k≤1, as the maximum addition value with carry in a single digit's place is 19, and thus the maximum carry value is ⌊1910⌋=1.

Now, we can iterate from rightmost digit to leftmost, i.e. from digit x−1 to 0. We can further iterate over all pairs of digits in the addition for the current column, as well as the carry values from both one and two columns to the right, and thus, we can find the number of states that contribute to our current state.

Our answer can be found in dp0,0,0, however, we must subtract 2 from this as it includes the invalid pairs (0,n) and (n,0).

 **Implementation (C++)**[127990386](https://codeforces.com/contest/1567/submission/127990386 "Submission 127990386 by ScarletS")

[1567D - Expression Evaluation Error](../problems/D._Expression_Evaluation_Error.md "Codeforces Round 742 (Div. 2)")

 **Solution**
### [1567D - Expression Evaluation Error](../problems/D._Expression_Evaluation_Error.md "Codeforces Round 742 (Div. 2)")

Let's greedily construct the largest possible sum for Alice, digit by digit. That is, the leftmost position should have the largest value possible, then the second-leftmost position, and so on. 

The maximum value of the leftmost digit of Alice's sum is clearly equal to the leftmost digit of the number $s$, since it cannot be larger. Similarly, the maximum possible value for the second-leftmost digit in Alice's sum cannot be larger than the corresponding digit in $s$, and so on. In general, Alice's sum cannot be larger than the number $s$ when interpreted as a base-11 number.

So how can we maintain the sum of $s$ when we express it as a sum of $n$ numbers? The idea is to split $s$ into a sum of powers of $10$. For example, if $s=25$, and Bob writes down $[10, 10, 1, 1, 1, 1, 1]$. Then Alice will not have any carries, and so the answer will just be $s$ interpreted as a base-11 number.

But what if we need to write down more numbers than the sum of the digits of $s$? Then, we're forced to split a power ten into units. When we split a power of $10$, it can be seen that we should split the smallest power of $10$ that isn't $1$ (call it $10^k$) as $10^{k-1}$ and $9 \cdot 10^{k-1}$. We can check all powers of $10$, and it can be shown that this is the best way to split.

For example, if $s=21$ and $n=4$, then we do the following process: $[21]$ to $[20, 1]$ to $[10, 10, 1]$ to $[10, 9, 1, 1]$. If $s=110$ and $n=3$, we do the following process: $[110]$ to $[100, 10]$ to $[100, 9, 1]$. Note that, in this last case, splitting $10=9+1$ is better than splitting $100=90+10$, since the sum of $100_{11} + 9_{11} + 1_{11} = 10A_{11}$, and $90_{11} + 10_{11} + 1_{11} = A1_{11}$.

Time complexity: $\mathcal{O}(n^2 \log_{10}(s))$ if you lazily iterate over all currently split numbers, or $\mathcal{O}(n \log{n} \log_{10}(s))$ if you use a priority queue.

 **Implementation (C++)**[127991334](https://codeforces.com/contest/1567/submission/127991334 "Submission 127991334 by flamestorm")

 **Video Solution**[Link to Video](https://codeforces.com/https://www.youtube.com/watch?v=6dAotrkoVCU)

[1567E - Non-Decreasing Dilemma](../problems/E._Non-Decreasing_Dilemma.md "Codeforces Round 742 (Div. 2)")

 **Solution**
### [1567E - Non-Decreasing Dilemma](../problems/E._Non-Decreasing_Dilemma.md "Codeforces Round 742 (Div. 2)")

Note that if there exists a non-decreasing array of length $x$, then it contains $\frac{x(x+1)}{2}$ non-decreasing subarrays. Therefore, we can break our solution down to counting the lengths of the non-decreasing "chains" within the queried subarray.

We can solve this problem using a data structure called a segment tree. On each node of this segment tree, we shall maintain four pieces of information:

$\cdot$ the length of the longest non-decreasing prefix.

$\cdot$ the length of the longest non-decreasing suffix.

$\cdot$ a boolean flag denoting if the entire segment is non-decreasing.

$\cdot$ the total number of nondecreasing subarrays not part of the longest prefix or suffix.

I won't explain the merging process here (you can examine the implementation below), but it is not too complex.

Using this, we can traverse the segment tree, from the left of our queried range to the right, while maintaining the number of non-decreasing subarrays in the prefix of the range and the length of the outgoing non-decreasing suffix to get our answer.

Time complexity: $\mathcal{O}(q\log n)$.

 **Implementation (C++)**[127990755](https://codeforces.com/contest/1567/submission/127990755 "Submission 127990755 by ScarletS")

 **Video Solution**[Link to Video](https://codeforces.com/https://www.youtube.com/watch?v=CIgm0HMJj3M)

[1567F - One-Four Overload](../problems/F._One-Four_Overload.md "Codeforces Round 742 (Div. 2)")

 **Solution**
### [1567F - One-Four Overload](../problems/F._One-Four_Overload.md "Codeforces Round 742 (Div. 2)")

Let's look at the numbers in the grid modulo $5$. $1$ and $4$ are $1$ and $-1$ modulo $5$, and by definition each marked cell must be $0$ modulo $5$. This means that each marked cell must have an even number of unmarked neighbors, and there must be an equal number of $1$s and $4$s among those neighbors.

In other words, the problem is about two-coloring a grid so each marked square has the same number of red and blue neighbors. If each cell is adjacent to 2 or 4 unmarked cells, then they will form a graph whose faces are two-colorable (the proof of this is below), which will satisfy all conditions, since all cells adjacent to 2 unmarked cells will be adjacent to two cells on opposite faces. However, the tricky case is to deal with cells with 0 unmarked neighbors.

The idea is to put a "mask" on top of the grid, which will also allow the cells with no unmarked neighbors to satisfy the condition while not interfering with already placed cells. That is, in the coloring terminology above, we will two color the grid, and then flip some cells according to the "mask" such that 

* all cells with 2 or 4 unmarked neighbors still satisfy the condition, and
* all cells with 0 unmarked neighbors now satisfy the condition.

We claim that we should flip all cells in all even-numbered columns; that is, the mask should contain columns alternately colored red and blue. Let's prove this works.

There are four types of marked cells: 

* a marked cell with no marked neighbors: all four neighbors are in same connected component, so none of them will be "flipped" with respect to the rest, and they will work: they will be the numbers $1,4,1,4$ by the mask. For this to hold true, when we make connected components, we need to DFS/BFS diagonally as well.
* a marked cell with only marked neighors: nothing to check.
* a marked cell with marked neighbors in the shape of an L tromino: again, these unmarked cells must be part of same connected component, so they will work: they will be the numbers $1$ and $4$ by the mask. For this to hold true, when we make connected components, we need to DFS/BFS diagonally as well.
* a marked cell with marked neighbors in the shape of an I tromino: then the cell on one side is necessarily in a different connected component than the other, so one will be flipped by the two-coloring, and they will be the right parities.

It suffices to show that the graph formed by edges between connected components of unmarked cells is bipartite.

 Consider instead the graph formed by the marked cells, with an edge between orthogonally adjacent cells. Consider each connected component of this graph individually. By the condition all vertices have degree 0, 2, or 4, but none can have degree 0 because the graph is connected. Now by a theorem of Euler this graph must have a Eulerian cycle.

Now we have a more general claim: the face-vertex dual of a Eulerian graph is bipartite. Suppose otherwise. Then the dual has some odd cycle. This means that some face of the dual must be bounded by an odd number of edges, since you can never "split" an odd cycle into only even ones. Also, the dual is planar, because our original graph is obviously planar (we are given an explicit planar embedding of it!).

Now some face of the dual has an odd number of edges. This means that in the dual graph of the dual, some vertex has odd degree. But the dual graph of the dual is the original graph. So the original graph is both Eulerian and has odd degree, which is absurd.

Finally, even though there are many connected components, it is clear that they do not interact: just set the infinite outside face to be one color, and the rest of the faces will be colored automatically.

Therefore this graph is bipartite, so we can two-color as desired, and we are done. Time complexity: $\mathcal{O}(mn)$.

 **Implementation (C++)**[127991337](https://codeforces.com/contest/1567/submission/127991337 "Submission 127991337 by flamestorm")

 **Video Solution**[Link to Video](https://codeforces.com/https://www.youtube.com/watch?v=-9ydFKDIKMM)

