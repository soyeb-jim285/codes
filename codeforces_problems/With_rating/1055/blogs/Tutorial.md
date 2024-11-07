# Tutorial

Tutorial is loading... Tutorial is loading... Tutorial is loading... 
### [1055D - Refactoring](../problems/D._Refactoring.md "Mail.Ru Cup 2018 Round 2")

Let's take all variable names that have changed. First observation is that if you trim coinciding prefixes and suffixes from the original variable names and the resulting name, you will find the part that needs to be changed. We will call it "the core" of the replacement. All those parts need to be exactly the same. However we don't want to create string $s$ that matches things that we don't want to get changed, so we will try to expand the pattern to the left and to the right as much as possible. Each time we will check if adjacent symbols coincide, and, if so, expand the pattern.

In the end we will obtain longest possible $s$ and $t$ that may explain the differences. The final part is to check whether they actually work (this can be done with any kind of string search). Overall complexity is proportional to the size of the input.

 
### [1055E - Segments on the Line](../problems/E._Segments_on_the_Line.md "Mail.Ru Cup 2018 Round 2")

Let's find the answer using binary search. Sort segments in the order of increasing right ends. Now we are solving the following problem: how many numbers $\le x$ we cover by $m$ segments. This may be solved with a DP along the scan line. We count how many numbers can we cover using at most $j$ of the first $i$ segments, making sure that we must always take the $i$-th segment. There are two options - either the new segment overlaps with the previous one, or not (we will ignore the case that two segments may be inside each other, because in the end it just means we can choose fewer than $m$ segments). In the case of overlap it's always optimal to choose the previous segment such that it spans as far as possible to the left (i.e. its left end is lowest). Which segment that would be for a given $i$ is easy to precompute. The case when the segments don't overlap can be implemented by a maintaining prefix maximum for all $j$. Overall complexity is $O(1500^2 \cdot \log 10^9)$.

 
### [1055F - Tree and XOR](../problems/F._Tree_and_XOR.md "Mail.Ru Cup 2018 Round 2")

First observation is that we may first assign a number to each vertex that is equal to xor of all values on the path from this vertex to the root (the root itself will be assigned $0$). Then the value of any path will be equal to xor of the values written in its first and last vertices.

Since the order of those values doesn't matter, let's build a binary trie of those numbers. In every node of the trie we will also store the number of values in its subtree. It's relatively easy to solve the reverse problem — to find number of paths having value not exceeding $v$. However the complexity of this is already $O(62 \cdot n)$, so adding binary search on top of it may not work. It's possible though to recover bits of the answer one by one by descending the trie level by level and maintaining the pairs of trie nodes that give us the correct higher bits of the answer (node may be in pair with itself).

At each step let's find the number of paths, whose next bit equals to $0$. In order to do this, we will go over the list of pairs. In every pair there may be two ways of obtaining $0$ as the next bit of the result: the corresponding bits of the values in the trie can be both zeros or both ones. In both cases we may compute number of paths as a product of the number of values in the corresponding subtrees. Then we sum all those numbers up over all the pairs. If the sum is greater or equal to $k$ then the next bit will be equal to $0$, otherwise it will be equal to $1$ (in this case we need to reduce $k$ by this number before proceeding to the next level). The amount of pairs at most doubles when we go one level deeper, but in total we will encounter the same node at most twice in the pairs.

The complexity of this algorithm is $O(62 \cdot n)$.

Since the full trie likely won't fit into memory, so we will build it implicitly — first sort the values first and then represent trie node with a range of indices on the sorted array. This will not change the overall complexity of the solution.

 
### [1055G - Jellyfish Nightmare](../problems/G._Jellyfish_Nightmare.md "Mail.Ru Cup 2018 Round 2")

First of all, we will solve a simpler problem: you need to check if it is possible for Bob to swim along the whole lane without any jellyfish stinging him. The position of Bob is identified by the location of his first vertex. Let's find out what are the prohibited areas for it. If a jellyfish had no activity zone and would only sting Bob only if he was swimming over it, the prohibited areas would look like polygons around every jellyfish. If we add the activity zone of radius $r$, prohibited areas will become "inflated" polygons. To be more precise, if the shape of Bob is a polygon $P$ they would have a shape of [Minkowski sum](https://codeforces.com/https://en.wikipedia.org/wiki/Minkowski_addition) of a polygon $-P$ with a circle of radius $r$. $-P$ here stands for the polygon inverted relative to the origin.

Now, some of the areas will overlap and prohibit passing between two jellyfishes. If those two jellyfishes have activity areas of radii $r_1$ and $r_2$, centered at $(x_1, y_1)$ and $(x_2, y_2)$ respectively, Bob may not swim between them if the vector $(x_1 - x_2, y_1 - y_2)$ belongs to the Minkowski sum of $P$, $-P$ and a circle of radius $r_1 + r_2$. This may be checked by finding the distance from that vector to the polygon $P \oplus -P$ (here $\oplus$ stands for Minkowski sum) and comparing it with $r_1 + r_2$. One thing you need to note here is that at given constraints you can't do those computations in floating point numbers, because the relative difference between $r_1 + r_2$ and the distance from a vector to a polygon may be as low as $10^{-17}$. Therefore, you need to do all calculations in integers.

Once you know pair of jellyfishes between which you cannot pass, you also need to find out if you are able to pass between the boundaries of the lane ($x=0$ and $x=w$) and the jellyfish. This allows you to construct a graph where every jellyfish and both boundaries are vertices, and the is an edge between two vertices if you cannot pass between them. One may notice that if the left boundary and right boundary are in the same connected component, then it's not possible for Bob to swim without being stung by any jellyfish. It's also possible to prove is that if they are not in the same component, then there is a safe path for Bob.

Returning to the original problem, we may rephrase it like this: remove the least possible number of jellyfishes so that Bob can swim without being stung. This can be solved using min-cut by a standard trick of splitting every vertex corresponding to the jellyfish into two and adding an edge of capacity $1$ between them. The rest of the edges will have capacity $+\infty$, left boundary will be the source, and the right boundary will be the target.

