# Tutorial


### [1271A - Suits](../problems/A._Suits.md "Codeforces Round 608 (Div. 2)")

There are two ways to approach this problem. The first way is to iterate on the number of suits of one type that we will compose and calculate the number of suits of the second type we can compose from the remaining items.

The second way is to use the fact that if $e > f$, then we have to make as many suits of the first type as possible (and the opposite is true if $f > e$). So we firstly make the maximum possible number of more expensive suits, and use the remaining items to compose cheaper suits.

 
### [1271B - Blocks](../problems/B._Blocks.md "Codeforces Round 608 (Div. 2)")

Suppose we want to make all blocks white (if we want to make them black, the following algorithm still works with a few changes).

The first block has to be white, so if it is black, we have to invert the pair $(1, 2)$ once, otherwise we should not invert it at all (inverting twice is the same as not inverting at all).

Then consider the second block. We need to invert it once if it is black — but if we invert the pair $(1, 2)$, then the first block becomes black. So we can't invert the pair $(1, 2)$, and we have to invert the pair $(2, 3)$ (or don't invert anything if the second block is white now).

And so on: for the $i$-th block, we cannot invert the pair $(i - 1, i)$, since it will affect the color of the previous block. So we don't have much choice in our algorithm.

After that, we arrive at the last block. If it is white, we are done with no more than $n - 1$ actions. If it is black, run the same algorithm, but we have to paint everything black now. If it fails again, then there is no answer.

 
### [1271C - Shawarma Tent](../problems/C._Shawarma_Tent.md "Codeforces Round 608 (Div. 2)")

Suppose that the point $(t_x, t_y)$ is the answer. If the distance between this point $t$ and the school is greater than $1$, then there exists at least one point $(T_x, T_y)$ such that:

* the distance between $T$ and the school is exactly $1$;
* $T$ lies on the shortest path between the school and $t$.

Now we claim that the $T$ can also be the optimal answer. That's because, if there exists a shortest path from the school to some point $i$ going through $t$, the shortest path from $s$ to $t$ going through $T$ can be extended to become the shortest path to $i$.

So we only need to check four points adjacent to the school as possible answers. To check whether a point $(a_x, a_y)$ lies on the shortest path from $(b_x, b_y)$ to $(c_x, c_y)$, we need to verify that $min(b_x, c_x) \le a_x \le max(b_x, c_x)$ and $min(b_y, c_y) \le a_y \le max(b_y, c_y)$.

 
### [1271D - Portals](../problems/D._Portals.md "Codeforces Round 608 (Div. 2)")

Note, that for every castle $i$ there is some list of castles $x$, such that you can defend castle $i$ standing in the castle $x$.

The key observation is that it's always optimal to defend castle $i$ (assuming we decided to defend it) in the latest possible castle. Since it gives you more warriors in between of $i$ and $x$ (more freedom), it's always optimal.

We will prune all other $x$'s except for the maximum one.

Now our process looks like: 

* Conquer next castle,
* Acquire new warriors,
* Decide whether or not you you defend previous castle $i$, such that the current castle is $x$ in terms of the paragraph above. There might be several such $i$ to process for the current castle.

Since in this process we decide on each castle exactly only once, the process can be simulated as a simple dynamic programming with states "number of castles conquered, number of warriors available", it's possible to compute this dp in $\mathcal{O}(n \cdot C)$, where $C$ is the total number of warriors.

Or you can use a greedy approach in $\mathcal{O}(n \log(n))$. Just maintain the process above, defending all the castles you can defend. In case it turns out you are lacking few warriors later, just undo several defended castes. To do so, just maintain undoable castles in a Heap or std::set.

 Tutorial is loading... 
### [1271F - Divide The Students](../problems/F._Divide_The_Students.md "Codeforces Round 608 (Div. 2)")

Suppose we have only students of types $1$, $4$, $6$ and $7$ (all students attend either all subjects or only one subject). We can divide these students into two subgroups in $O(1)$: the first subgroup can accomodate no more than $min(a_1, b_1, c_1)$ students of the first type; the second subgroup can accomodate no more than $min(a_2, b_2, c_2)$ students of the first type; it does not matter how we distribute them into groups, as long as their number does not exceed the limits. After that, it's easy to distribute three other types.

Okay, we can solve the problem with four types in $O(1)$. How to solve the problem with seven types in $O(M^3)$? Let's iterate on $f_2$, $f_3$ and $f_5$, and check whether we can distribute the remaining types! Though it may seem slow, we will do only $10^9$ iterations, and the time limit is generous enough (model solution works in 1.8 seconds without any cutoffs).

Challenge: solve it in quadratic time.

