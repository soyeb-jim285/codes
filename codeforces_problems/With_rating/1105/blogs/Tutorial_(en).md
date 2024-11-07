# Tutorial_(en)

Tutorial is loading... Tutorial is loading... Tutorial is loading... Tutorial is loading... 
### [1105E - Helping Hiasat](../problems/E._Helping_Hiasat_.md "Codeforces Round 533 (Div. 2)")

Let's change this problem to a graph problem first.

Let's say, that each action of the first type is a "border". Consider all friends visiting our profile after this "border" but before the next one. Clearly, we can satisfy at most one of them. Let's change the friends into graph nodes and add edges between every two friends that are between the same borders.

Then it's enough to solve "the maximum independent set of the graph", clearly any possible answer must be an independent set and by any independent set we can always build a way to change our handle.

The maximum independent set can be solved in O(2m) (where m is the number of friends). But since m is up to 40, it is too slow. However, we can apply the meet in the middle approach and then it becomes O(2(m/2)) or O(2(m/2)m).

The simplest way is to do the following (notice, that the independent set is same as clique if all edges are inverted, so we will solve a max clique problem). 

Let's write a bruteforce solve(mask) which returns size of the largest clique, which forms a subset of mask. The answer will be just to run solve of full mask.

How to write solve? Let's find a first bit of mask, let it be vertex v.

There are two cases: 

1. The vertex v is not in an answer. Kick it and run a recursive call.
2. The vertex v is in answer. Hence all other vertices of answers are neighbors of v. Run the recursive call from mask & g[v], where g[v] denotes the mask of neighbors.

Clearly, it works in O(2m). However, if we add memorization (don't calculate for same mask twice) it is magically becomes O(2m/2).

Why? Consider the recursion, there are at most m/2 recursion calls before we arrive into the state, where there are no set bits of the first half.

This part will take at most 2m/2 then. And clearly there are at most 2m/2 states with no set bits in the first half.

