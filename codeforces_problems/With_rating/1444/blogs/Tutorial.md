# Tutorial

Thanks for the participation!

[1445A - Array Rearrangment](https://codeforces.com/contest/1445/problem/A "Codeforces Round 680 (Div. 2, based on Moscow Team Olympiad)") was authored by [meshanya](https://codeforces.com/profile/meshanya "Grandmaster meshanya") and prepared by [ch_egor](https://codeforces.com/profile/ch_egor "International Grandmaster ch_egor")

[1445B - Elimination](https://codeforces.com/contest/1445/problem/B "Codeforces Round 680 (Div. 2, based on Moscow Team Olympiad)") was authored by Helen Andreeva and prepared by [ismagilov.code](https://codeforces.com/profile/ismagilov.code "Grandmaster ismagilov.code")

[1444A - Division](../problems/A._Division.md "Codeforces Round 680 (Div. 1, based on Moscow Team Olympiad)") was authored by [vintage_Vlad_Makeev](https://codeforces.com/profile/vintage_Vlad_Makeev "International Grandmaster vintage_Vlad_Makeev") and prepared by [grphil](https://codeforces.com/profile/grphil "Master grphil")

[1444B - Divide and Sum](../problems/B._Divide_and_Sum.md "Codeforces Round 680 (Div. 1, based on Moscow Team Olympiad)") was authored and prepared by [NiceClock](https://codeforces.com/profile/NiceClock "Master NiceClock")

[1444C - Team-Building](../problems/C._Team-Building.md "Codeforces Round 680 (Div. 1, based on Moscow Team Olympiad)") was authored by [V--o_o--V](https://codeforces.com/profile/V--o_o--V "Legendary Grandmaster V--o_o--V") and prepared by [wrg0ababd](https://codeforces.com/profile/wrg0ababd "Expert wrg0ababd")

[1444D - Rectangular Polyline](../problems/D._Rectangular_Polyline.md "Codeforces Round 680 (Div. 1, based on Moscow Team Olympiad)") was authored by [Zlobober](https://codeforces.com/profile/Zlobober "International Grandmaster Zlobober") and prepared by [DebNatkh](https://codeforces.com/profile/DebNatkh "Master DebNatkh")

[1444E - Finding the Vertex](../problems/E._Finding_the_Vertex.md "Codeforces Round 680 (Div. 1, based on Moscow Team Olympiad)") was authored by [V--o_o--V](https://codeforces.com/profile/V--o_o--V "Legendary Grandmaster V--o_o--V") and prepared by [300iq](https://codeforces.com/profile/300iq "Legendary Grandmaster 300iq")

 
### [1445A - Array Rearrangment](https://codeforces.com/contest/1445/problem/A "Codeforces Round 680 (Div. 2, based on Moscow Team Olympiad)")

It's enough to sort aa in non-decreasing order and sort bb in non-increasing order and check, whether ai+bi≤xai+bi≤x for all ii.

Correctness can be proven by induction: let's show that if answer exists, there is a solution with minimum in aa and maximum in bb are paired. Let mama be minimum in aa and mbmb be maximum in bb. Let pp be number paired with mama and qq be number paired with mbmb. Since solution is correct, ma+p≤xma+p≤x and mb+q≤xmb+q≤x. Since ma≤qma≤q, ma+mb≤xma+mb≤x. Since p≤mbp≤mb, p+q≤xp+q≤x. So, mama can be paired with mbmb.

 
### [1445B - Elimination](https://codeforces.com/contest/1445/problem/B "Codeforces Round 680 (Div. 2, based on Moscow Team Olympiad)")

The answer is at least max(a+b,d+c)max(a+b,d+c) because we have at least 100100 participants with the sum of a+ba+b and at least 100100 participants with the sum of d+cd+c. 

If we have 9999 participants with points equal to (a,c)(a,c), and 22 participants with points equal to (a,b)(a,b) and (d,c)(d,c), then the 100th participant will have a total of max(a+b,d+c)max(a+b,d+c) points, and the condition will be met, because a≥da≥d, c≥bc≥b and a+c≥max(a+b,d+c)a+c≥max(a+b,d+c).

 
### [1444A - Division](../problems/A._Division.md "Codeforces Round 680 (Div. 1, based on Moscow Team Olympiad)")

Let y=p/xy=p/x. Let's assume, that there exists prime aa, such that aa divides yy, but qq is not divisible by aa. Then we can multiply xx and aa and the result will still divide pp, but will not be divisible by qq. So for maximal xx there is no such aa.

Let's assume, that there are two primes aa and bb, such that they both divide yy, and both divide qq. Because qq is not divisible by xx, there exists some prime cc (cc can be equal to aa or bb), such that number of occurrences of cc in xx is less than number of occurrences of cc in qq. One of aa and bb is not equal to cc, so if we will multiply xx and such number, the result will not be divisible by qq. So for maximal xx there are no such aa and bb.

That means that x=p/x=p/(power of some primal divisor of qq). So to find maximal xx, we have to find all prime divisors of qq (we have to factorise qq for it in time O(√q)O(q√)) and for each of them divide pp by it until result is not divisible by qq. That will be all our candidates for greatest xx. We will do all of that in time O(√q+logq⋅logp)O(q√+logq⋅logp).

 
### [1444B - Divide and Sum](../problems/B._Divide_and_Sum.md "Codeforces Round 680 (Div. 1, based on Moscow Team Olympiad)")

No matter how we split the array, the cost of a partition will always be the same.

Let's prove it. Without loss of generality we will consider that the array aa sorted and denote for LL the set of elements with indexes from 11 to nn, and for RR the set of elements with indexes from n+1n+1 to 2n2n.

Then split the array aa into any two arrays pp and qq of size nn. Let's sort pp in non-decreasing order and qq by non-increasing order. Any difference |pi−qi||pi−qi| in our sum will be the difference of one element of RR and one element of LL.

If this is not the case, then there is an index ii such that both pipi and qiqi belong to the same set. Let's assume that this is LL.

1. All elements with indexes less than or equal to ii in pp belong to LL (ii elements)
2. All items with indexes greater than or equal to ii in qq belong to LL (n−(i−1)n−(i−1) elements)

Then LL has at least i+n−(i−1)=n+1i+n−(i−1)=n+1 elements, but there must be exactly nn. Contradiction. For the set RR the proof is similar.

Then the answer to the problem is (the sum of the elements of the set RR minus the sum of the elements of the set LL) multiplied by the number of partitions of the array Cn2nCn2n.

Complexity: O(nlogn)O(nlogn) (due to sorting)

 
### [1444C - Team-Building](../problems/C._Team-Building.md "Codeforces Round 680 (Div. 1, based on Moscow Team Olympiad)")

You're given an undirected graph without loops and multiple edges, each vertex has some color from 11 to kk. Count the number of pairs of colors such that graph induced by vertices of these two colors will be bipartite.

Let's check for each color whether the graph induced by it is bipartite (for example, using depth-first search). This can be done in O(n+m)O(n+m). We will not use non-bipartite colors further since they can't be in any pairs.

Now let's construct a slow solution that we will make faster later.

Consider some color xx. There're edges from vertices of this color to vertices of colors y1,y2,…,yky1,y2,…,yk. Let's check whether the graphs induced by pairs (x,y1),(x,y2),…,(x,yk)(x,y1),(x,y2),…,(x,yk) are bipartite (also using depth-first search), thereby finding out which colors cannot be in pair with xx. The others can. After doing this for each color xx, we can find the asnwer.

How fast does this work? Notice that any edge between different colors we will use in DFS only two times. The problem are edges between vertices of the same color, we can use them up to kk times, and there can be a lot of them.

Let's solve this problem and construct a faster solution.

A graph is bipartite if and only if it doesn't contains odd cycles. Consider some connected bipartite component induced by color xx. If a cycle goes through this component, it doesn't matter how exactly it does it. If the path of the cycle in this component ends in the same side where it has started, then it has even length, and odd otherwise. This fact lets us compress this component to two vertices (one for each side) connected by one edge. For each color this way we compress all components formed by it.

Now we have the compressed graph, where all connected components are either one vertex or two vertices connected by one edge. Let's do the same process we did in slow solution and check every connected pair of colors whether the graph induced by it is bipartite. 

To check the pair (x,y)(x,y), for each edge between vertices of colors xx and yy in the original graph add a new edge to the compressed graph between corresponding vertices. After that use DFS to check if graph is bipartite, rollback the changes and do the same for all other pairs. 

How long does this work for one pair (x,y)(x,y)?

Let's start DFS only from components that were connected by added edges, since the others do not affect whether the graph is bipartite or not, but there can be a lot of them. This way DFS will use only added edges and some edges between vertices of the same color xx or yy. However, there will be at most two times more of the latter than the added, because each added edge connects at most two new components, and each new component has at most one edge. So, we check one pair in the time proportional to amount of edges between its colors, and it sums up to O(m)O(m) for all pairs.

So, the whole solution works in O(n+m)O(n+m) or O(mlogn)O(mlogn), depending on the implementation.

 
### [1444D - Rectangular Polyline](../problems/D._Rectangular_Polyline.md "Codeforces Round 680 (Div. 1, based on Moscow Team Olympiad)")

First, note that in a correct polyline, since the horizontal and vertical segments alternate, h=vh=v: if this equality does not hold, the answer is negative. Now let's fix a vertex and go around the polyline in some direction. Then in the process of traversin, we will move in one of four possible directions: up, down, right or left. Since the polyline is closed, this means that we will move to the left in total by the same distance as we will move to the left in total. The same is true for moving up and down.

This means that if we split all the segments into four sets named UpUp, DownDown, LeftLeft, RightRight, then the total length of the segments in UpUp will be equal to the total length of the segments in DownDown, and the total length of the segments in RightRight will be equal to the total length of the segments in LeftLeft. But it means that the set of lengths of all horizontal segments can be divided into two sets with the same sum. The same should hold for vertical segments.

Let's check whether it is possible to divide the set of lengths of horizontal segments into two sets of the same sum. This classic problem can be solved by applying the dynamic programming method to solve the backpack problem. The complexity of this solution will be O(nC2)O(nC2) If it is impossible to split horizontal or vertical lengths into two sets of equal length, the answer is "No". Now we will show how to construct a correct answer if such divisions exist.

Let us divide all horizontal lengths into two sets of equal total length. We denote the smaller set as RR, and the larger set as LL. We will do the same with the set of lengths of vertical segments: we will denote the smaller set as DD, and the larger one as UU. Since |R|≤|L||R|≤|L|, |R|≤h/2=v/2|R|≤h/2=v/2. Similarly, we have v/2≤|U|v/2≤|U|, which follows that |R|≤|U/|R|≤|U/, |D|≤|L||D|≤|L|.

Now let's divide all the segments into pairs as follows: each segment of RR, we match with a segment from UU. All remaining segments of LL are matched with one of the remaining vertical segments. Thus, we have divided all these segments into three sets of pairs: in the first one, a segment from RR is paired with a segment from UU. In the second set a segment from LL is paired with a segment from UU. In the third set a segment from DD is paired with a segment from LL.

 ![](images/f61997399283f5db92cb440810504f848004b33c.png) From the first set of pairs, we make up the set of vectors directed up and to the right (from the pair (r, u), we construct the vector (r, u)). This way we can construct a set of vectors AA. We will do the same with the second set of pairs (constructing a set of vectors BB) and the third set of pairs (constructing a set of vectors CC). for a better understanding, see the picture above. Note that the set BB may be empty, while the other two can not.

Let's make a convex polyline from the vectors of AA. In order to do this, sort them in ascending order by the polar angle and make a polyline from them in this order (see the picture below).

Now we will replace each of the vectors of our polyline with two vectors: one vector directed to the right and one vector directed upwards.

 ![](images/d6ffb056156219d751cec6e84863db135cb3a3c0.png) We will do the same for vectors from CC: sort them in ascending order by the polar angle and make a convex polyline from them:

 ![](images/ed77da6160e261d1798e5cd4a7d1d0df14b4596f.png) Let's combine these two polylines so that the first one goes from the point OO to the point AA and the second one goes from the point BB to the point OO:

 ![](images/b68eff0143d3bb757075f885bd8f03294eab73b1.png) We don't have much left to do: we hate to connect the points AA and BB using vectors from the set BB. Let's take these vectors (directed up and to the left) in any arbitrary order, then, since the sum of all vectors is 0, the resulting polyline, if you draw it with the beginning at the point AA, will end at the point BB. Since the first two polylines were convex, this means that none of the points of the first two polylines will lie strictly inside the angle AOBAOB, which means that if you replace each of the vectors of the third polyline with two vectors, one directed to the left and one directed upwards, the resulting closed polyline will not contain self-intersections.

 ![](images/a14730761eec9f8b32f883216d35037e29650ed0.png) It is easy to show that the resulting polyline will be closed and will satisfy all the conditions of the problem:

 ![](images/43403bdcfcc6f16e4a099933afd44bcf8fa6dac7.png)  
### [1444E - Finding the Vertex](../problems/E._Finding_the_Vertex.md "Codeforces Round 680 (Div. 1, based on Moscow Team Olympiad)")

Consider the optimal strategy.

Some edge will be your first query, mark it with a number 00.

After that, build similar colourings (recursively) for components on both sides of the edge, but increase their weights by one (to have only one zero in total).

This colouring corresponds to the strategy, and if kk is the maximum weight of an edge in it, then this strategy can find a vertex in k+1k+1 queries in the worst case.

This colouring has a wonderful property that helps us identify the vertex: on a path between any two edges with the same colour an edge with the smaller colour presents.

And any colouring with this property corresponds to a proper strategy! (Each time you can ask an edge with the smallest weight in the current component)

To make it easier for us, "invert" all weights in the colouring, mark the first edge with the weight k−1k−1, and then use the same construction as we had before for our colouring, but now subtract 11 from the edges (weights should remain non-negative).

Now our goal is to find colouring with the min weight of the max edge, such that each pair of edges with the same colours have an edge with the larger colour between them.

We will build this colouring using subtree DP.

For the fixed colouring of a subtree of the vertex vv, let's see which colours are visibile if you will look from vv towards the subtree.

The colour is visible, if there is such an edge of this colour, that there are no edges with the larger colour on a path from this edge to vv.

Potential function of our colouring is the sum 2c1+2c2+…+2ck2c1+2c2+…+2ck, where cici are visible colours. Note that this value is a long number! Because our answer can be large.

Lemma: we are interested only in the colouring of our subtree with the smallest potential.

Assume that all subtrees of vertex vv are already coloured into colourings with the smallest potentials.

Then we have to choose some weights of edges outgoing from vv, such that after adding these edges to vv, different subtrees won't have common visible colours (otherwise you will get a bad pair of edges of the same colour). 

You can color an edge from vertex vv to its child uu in a colour cc, if a colour cc is not visible from uu. After that, all weights smaller than cc will disappear from the set of visible colours, but the colour cc will be added.

You have to change colourings of the subtrees in this way, to not have carries during the addition of the potentials (it will correspond to the situation without common visible colours). Under this constraint, we have to minimize the total sum, the potential of vv.

From this setting, the proof of the previous lemma is clear: for larger values of the potential, possible choices are not better.

You have to solve a problem: you are given an array a1,a2,…,aka1,a2,…,ak of long binary numbers. You have to find an array with the smallest sum b1,b2,…,bkb1,b2,…,bk, such that bi>aibi>ai, and no carries will happen during the addition b1+b2+…+bkb1+b2+…+bk.

You can solve this problem with a quite simple greedy algorithm: we will set bits greedily from left to right, and check that we can finish our goal with the fixed prefix. To check that you can get some answer with the fixed prefix of bits and the upper bound on the used bits, you can go from left to right and each time when you have to replace some number to the current bit, replace the number with the largest suffix. You can implement it in a naive way in O(n3)O(n3), but it also can be implemented in O(nlogn)O(nlogn).

You have to solve this subtask nn times, and we will get the solution with complexity O(n⋅T(n))=O(n2logn…n4)O(n⋅T(n))=O(n2logn…n4).

