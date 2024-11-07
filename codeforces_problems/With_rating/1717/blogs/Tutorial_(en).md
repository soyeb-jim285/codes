# Tutorial_(en)

Problem A. Idea by [Igorbunov](https://codeforces.com/profile/Igorbunov "Grandmaster Igorbunov")

 **Hint 1**Only the following pairs of numbers are possible: (x,x), (x,2⋅x), and (x,3⋅x)

 **Solution**Notice that only the following pairs of numbers are possible: (x,x), (x,2⋅x), and (x,3⋅x).

 **Proof:**Let d=gcd(a,b). Now notice that it's impossible that a=k⋅d for some k>4, because otherwise lcm will be at least k⋅d>3⋅d. Therefore the only possible cases are the pairs listed above and (2⋅d,3⋅d), but in the latter case we have lcm=6⋅d.

The number of the pairs of the first kind is n, of the second kind is 2⋅⌊n2⌋, and of the third kind is 2⋅⌊n3⌋ (the factor 2 in the latter two formulae arises from the fact that pairs are ordered). Therefore, the answer to the problem is n+2⋅(⌊n2⌋+⌊n3⌋).

 

---

Problem B. Idea by [FairyWinx](https://codeforces.com/profile/FairyWinx "Grandmaster FairyWinx")

 **Hint 1**Solve the problem for k=2.

 **Hint 2**Solve the problem without the "(r,c) must be colored" limitation.

 **Hint 3**Try to paint diagonals

 **Hint 4**No, you don't need casework

 **Solution**Notice that the answer to the problem is at least n2k, because you can split the square into so many non-intersecting rectangles of dimensions 1×k. So let's try to paint exactly so many cells and see if maybe it's always possible.

For simplicity, let's first solve the problem without necessarily painting (r,c). In this case, we're looking for something like a chess coloring, which is a diagonal coloring.

Let's number the diagonals from the "lowest" to the "highest". Notice that every 1×k and k×1 subrectangle intersects exactly k consecutive diagonals, so we can paint every k-th diagonal to obtain the required answer: every such subrectangle will contain exactly one painted cell.

To add the (r,c) requirement back, notice that (r,c) lies on the diagonal number r+c. (Because if you trace any path from (0,0) to (r,c) with non-decreasing coordinates, going one cell upwards or rightwards increases exactly one of the coordinates by one, and also increases the number of the diagonal by one). Therefore, all we need to do is paint the cells whose coordinates satisfy (x+y)%k=(r+c)%k

 

---

Problem C. Idea by [FairyWinx](https://codeforces.com/profile/FairyWinx "Grandmaster FairyWinx")

 **Hint 1**We've got a problem if bi>bi+1+1

 **Hint 2**It's alright if ai=bi

 **Hint 3**Programmers aren't mathematicians, you don't need to prove the solution

 **Solution**Firstly, we obviously require ai≤bi to hold for all i. With that out of our way, let's consider non-trivial cases. Also let an+1=a1,bn+1=b1 cyclically.

For each i, we require that either ai=bi or bi≤bi+1+1 holds. That's because if we increment ai at least once, we had ai=bi−1 and ai+1≤bi+1 before the last increment of ai, and from here it's just a matter of simple algebraic transformations.

Now let's prove these two conditions are enough. Let i be the index of the minimal element of a such that ai<bi (i.e. the smallest element that's not ready yet). Notice that in this case we can, in fact, assign ai:=ai+1, because ai≤bi≤bi+1+1 holds, and now we're one step closer to the required array. It's easy to continue this proof by induction.

 

---

Problem D. Idea by [FairyWinx](https://codeforces.com/profile/FairyWinx "Grandmaster FairyWinx")

 **Hint 1**Reformulate this problem in terms of a complete binary tree.

 **Hint 2**It would be strange for the sponsors to changes two nodes of the same depth.

 **Solution**The problem can be reformulated as follows. We've got a complete binary tree with 2n leaves. There's a marked edge from each intermediate node to one of its children. The winner is the leaf reachable from the root via marked edges. Changes modify the outgoing marked edge of a node.

Now it should be fairly obvious that there's no reason to change more than one node per level, because only one node matters per level--the one on the path from the root to the answer node. So, the winner only depends on the subset of levels we perform changes on, and vice versa: different subsets always yield different winners.

Sponsors can change exactly i nodes in (ni) ways. Summing this over i, we get ∑min(n,k)i=0(ni). Call this number m. m is the number of winners the sponsors choose between--let's call them candidates for brevity. It's easy to see that m is the answer to the problem, because a) sponsors can guarantee the winner is at least m, as, independent of the list of candidate winners "provided" by Madoka, at least one of them must be at least m, and b) Madoka can guarantee the winner is at most m by firstly marking edges arbitrarily, *then* computing the list of candidate nodes, and only *then* fill them with numbers from 1 to m (and the other nodes arbitrarily).

 

---

Problem E. Idea by [FairyWinx](https://codeforces.com/profile/FairyWinx "Grandmaster FairyWinx")

 **Hint 1**Bruteforce c

 **Hint 2**gcd(a,b) divides a+b.

 **Hint 3**Recall the existence of the Euler's totient function

 **Solution**Let's bruteforce c, then we have gcd(a,b)=gcd(a,a+b)=gcd(a,n−c). This means that gcd(a,b) divides n−c, so let's just go through all divisors of n−c. For every factor d, the count of pairs (a,b) satisfying a+b=n−c and gcd(a,b)=d is ϕ(n−cd), because we need d to divide a and be coprime with n−cd, so that the gcd is equal to d.

Therefore, the answer to the problem is ∑lcm(c,d)∗ϕn−cd, where 1≤c≤n−2 and d is a factor of n−c.

 

---

Problem F. Idea by [TeaTime](https://codeforces.com/profile/TeaTime "Master TeaTime"), tutorial by [purplesyringa](https://codeforces.com/profile/purplesyringa "International Master purplesyringa")

Editorialist's note: I didn't submit the solution myself, but I proved it theoretically, aggregated solutions of problemsetters as well as participants, so I'm fairly sure it's correct, but you might want to treat it with more suspicion.

 **Hint 1**Try graph theory.

 **Hint 2**Try flow theory.

 **Hint 3**No, that won't work, try again.

 **Solution**Let's reformulate the problem in terms of graphs. We are given an undirected graph and we are asked to determine edge directions, subject to fixed indegree minus outdegree (hereinafter *balance*) values for some vertices. 

It is tempting to think of this as a flow problem: edges indicate pipes with capacity of 1, vertices are producers or consumers of flow, and vertices with fixed differencies produce or consume an exact amount of flow. Except that's not quite an equivalent problem: a maxflow algorithm will find a flow, i.e. an orientation of edges, but it might just ignore some edges if it feels like it.

We need to overcome this somehow by introducing incentive to use all edges. To do this, forget about the "edges are edges, vertices are vertices" idea for a while. Create an imaginary source and add a pipe with capacity 1 to every edge of the original graph. Technically, this is interpreting edges of the original graph as vertices of the flow graph. Non-technically, I like to interpret this like magically spawning flow into the middle of the edge.

Now, the flow appearing in the edge has to actually go somewhere if we want the maxflow algorithm to treat it like a treasure it wants to increase. Let's just add two pipes: from the edge to vertex ui and from the edge to vertex vi, because where else would it go? (technically, any capacity works, but let's use 1 for simplicity) This has a nice side effect of determining the orientation of the edge: if the flow from the edge goes into ui, it's as if it was oriented from vi to ui, and vice versa.

A small problem is that this changes the semantics of the edge orientation somewhat. In the original problem, ui→vi incremented vi and decremented ui. In the new formulation, only vi is incremented, so we need to transform the requirements av on balances into requirements bv on indegrees: bv=av+degv2 (and we need to check that the numerator is even and non-negative, otherwise the answer is NO).

How do we enforce the indegree requirements? For all vertices with sv=1, add a pipe from the vertex v to an imaginary sink with capacity bv. We expect all these pipes to be satiated.

What about vertices with sv=0? Unfortunately, we can't just add a pipe from the vertex v to an imaginary sink with capacity ∞, because if you have an edge with sv=0 and su=1, the maxflow algorithm doesn't have any incentive to let the flow go to u instead of v, so the pipe from u to the sink might not get satiated and we might erroneously report a negative answer.

How do we require certain pipes to be satiated? We could theoretically use a push-relabel algorithm, but in this case we can use something much simpler. The sum of capacities of all pipes from the imaginary source is m. We expect them all to be satiated, so this is the total flow we're expecting. The sum of capacities of all pipes to the imaginary sink we want to satiate is ∑vbv. Therefore, there's a surplus of flow of exactly Δ=m−∑vbv (if it's negative, the answer is NO). So: create an intermediate vertex, add a pipe of capacity ∞ from each vertex with sv=0 to this intermediate vertex, and a pipe from this intermediate vertex to the imaginary sink with capacity Δ. This will stop the algorithm from relying too much on non-fixed vertices.

Run a maxflow algorithm. Check that every pipe from the source to an edge and every pipe from a vertex to the sink is satiated, or, alternatively, the maxflow is exactly m. If this does not hold, the answer is NO. If this holds, the answer is YES and the edge orientation can be restored by checking which of the two pipes from an edge is satiated.

Is this fast? That depends on the algorithm heavily.

Firstly, you can use the Edmonds-Karp algorithm. It works in O(FM), where F is the maxflow and M is the number of pipes. The former is m and the latter is n+m, so we've got O((n+m)m), which is just fine.

Secondly, you can use Dinic's algorithm, which is typically considered an improved version of Edmonds-Karp's, but is worse in some cases. It improves the number of rounds from F to O(N), where N is the number of vertices in the network, which doesn't help in this particular problem, sacrificing the complexity of a single phase, increasing it to O(NM), which is a disaster waiting to happen.

Lots of people submitted Dinic's instead of Edmonds-Karp's. I don't know why, perhaps they just trained themselves to use Dinic's everywhere and didn't notice the unfunny joke here.

Luckily for them, Dinic's algorithm still works. You might've heard it works in O(MN2/3) for unit-capacity networks, where M is the number of pipes and N is the number of vertices, which translates to O((n+m)n2/3) in our case, which would be good enough if the analysis held.

Our network is not unitary, but it's easy to see how to make it into one. We use non-unit capacities in three cases:

 * When we enforce the indegree, we add a pipe with capacity bv from the vertex to the sink. We can replace it with bv pipes of capacity 1. As ∑vbv≤m, this will not increase the number of pipes by more than m, so the complexity holds. Due to how Dinic's algorithm works, replacing a pipe with several pipes of the same total capacity does not slow the algorithm down.
* Similarly, the pipe from the intermediate vertex to the sink has capacity Δ≤m, so we could theoretically replace it with Δ unit pipes and the complexity would hold.
* Finally, when we handle vertices with sv=0, we add pipes from such vertices to the intermediate vertex with capacity ∞. However, for each such vertex, the maximum used capacity is actually the count k of edges incident with v, so the capacity of such pipes could be replaced with k. This would obviously have the same effect, and would not slow Dinic down: even if it tries to push more than k through the corresponding backedge, it will quickly rollback, which affects the time taken by a single phase (non-asymptotically), but not the count of phases. As the sum of k is O(m), we're fine again.
