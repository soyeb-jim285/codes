# Tutorial_(en)

[1345A - Puzzle Pieces](https://codeforces.com/contest/1345/problem/A "Codeforces Round 639 (Div. 2)")

 **Tutorial**Tutorial is loading...[1345B - Card Constructions](https://codeforces.com/contest/1345/problem/B "Codeforces Round 639 (Div. 2)")

 **Tutorial**Tutorial is loading...[1345C - Hilbert's Hotel](https://codeforces.com/contest/1345/problem/C "Codeforces Round 639 (Div. 2)")

 **Tutorial**Tutorial is loading...[1345D - Monopole Magnets](https://codeforces.com/contest/1345/problem/D "Codeforces Round 639 (Div. 2)")

 **Tutorial**Tutorial is loading...[1345E - Quantifier Question](https://codeforces.com/contest/1345/problem/E "Codeforces Round 639 (Div. 2)")

 **Tutorial**Tutorial is loading...[1345F - Résumé Review](https://codeforces.com/contest/1345/problem/F "Codeforces Round 639 (Div. 2)")

 **Tutorial**Tutorial is loading...[1344E - Train Tracks](../problems/E._Train_Tracks.md "Codeforces Round 639 (Div. 1)")

 **Tutorial**
### [1344E - Train Tracks](../problems/E._Train_Tracks.md "Codeforces Round 639 (Div. 1)")

First, observe that a train can never pass one that enters earlier. So let's consider the trains independently. For a train $i$, look at the path from $1$ to $s_i$. We may need to change the switches of several stations on this path. We must make each switch within a time interval $(L, R]$, where $L$ is the most recent time some other train was directed the other way, and $R$ is the time train $i$ will enter the station. Let's mark all of these switches as changed before processing the next train.

Suppose the total number of switch changes is $k$, and for each station, we know its time intervals. We can manage all events in a priority queue of size $n$, always changing the switch with the earliest deadline that we can. Keep doing this until we are too late for a deadline, in which case an explosion happens, or until we have successfully made every switch change. This part will take $O(k\log n)$ time.

Let's find a nice upper bound on $k$. Note that the switches decompose the tree into a set of disjoint paths. When we process a train $i$, we are changing the switches to make a path from the root to $s_i$. It turns out this is exactly the same as an access operation on a link/cut tree! Because link/cut trees have $O(\log n)$ amortized time per operation, we can guarantee that the total number of switch changes is $k=O(n+m\log n)$.

Now let's consider the problem of finding all time intervals. We could use a link/cut tree, but everyone hates those, so let's discuss other methods. One strategy is to maintain a list of trains that go through a station, for every station. We start at the leaves and merge the lists going up. We can merge the lists efficiently by inserting elements from the smaller list to the larger list. Then a switch only needs to be changed when consecutive trains go to different children.

Unlike some of the testers, I wasn't smart enough to come up with the elegant small-to-large merging idea. So let's discuss an alternate solution using segment trees. When processing a train $i$, we want to do the following:

1. Find the top node $x$ of the path leading to $s_i$.
2. If $x$ is not the root, make the parent of $x$ point to $x$, and record the time interval we must make this switch. Repeat from step $1$ until $x$ is the root.

The queries we want to support are thus: 

1. Find the time the most recent train passed through a node $x$ (ignoring trains with $s_i=x,$ where it only stops at $x$).
2. Find the top node of the path containing node $x$.

Let's handle queries of type $1$ with a segment tree. After processing train $i$, update the value at index $s_i$ to $i$. To answer a query, find the maximum value in the range corresponding to the relevant subtree.

Let's also handle queries of type $2$ with a segment tree. At a segment tree node, store the minimum value on its range. To answer a query, check the range $[x,x]$. Support lazy updates of the form "On a range $[l, r]$, replace all values $X$ with value $Y$, with the precondition that $X$ is currently the minimum value in $[l,r]$ and $Y$ will remain the minimum value after the update". To make a switch change, we only need to do two lazy updates.

Therefore, finding all the time intervals will take $O((m+k)\log n)$ time.

The overall complexity is $O(n\log n+m\log^2 n)$.

[1344F - Piet's Palette](../problems/F._Piet's_Palette.md "Codeforces Round 639 (Div. 1)")

 **Tutorial**
### [1344F - Piet's Palette](../problems/F._Piet's_Palette.md "Codeforces Round 639 (Div. 1)")

Equate an empty cell with the color white, and let's represent the colors as 0/1 vectors: $$W=\begin{bmatrix}0\\\0\end{bmatrix},\ R=\begin{bmatrix}1\\\0\end{bmatrix},\ Y=\begin{bmatrix}0\\\1\end{bmatrix},\ B=\begin{bmatrix}1\\\1\end{bmatrix}.$$

Under this representation, mixing becomes addition $\pmod{2}$. And the operations $\mathrm{RY}$, $\mathrm{RB}$, $\mathrm{YB}$ are linear transformations of the colors. That is, each of these operations is equivalent to multiplying the corresponding matrix by a cell's vector: $$\mathrm{RY}=\begin{bmatrix}0&1\\\1&0\end{bmatrix},\ \mathrm{RB}=\begin{bmatrix}1&0\\\1&1\end{bmatrix},\ \mathrm{YB}=\begin{bmatrix}1&1\\\0&1\end{bmatrix}.$$

We simply have a system of $2k$ linear equations on $2n$ unknowns, which we can solve with Gaussian elimination using bitsets.

Complexity is $O((2k)^2 (2n) / 64).$

