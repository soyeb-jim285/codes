# Tutorial_(en)

[1654A - Maximum Cake Tastiness](../problems/A._Maximum_Cake_Tastiness.md)

Author: [TheScrasse](https://codeforces.com/profile/TheScrasse "Grandmaster TheScrasse")  
 Preparation: [TheScrasse](https://codeforces.com/profile/TheScrasse "Grandmaster TheScrasse")

 **Hint 1**Suppose you want to choose pieces of cake i, j. Can you make them adjacent in 1 move?

 **Solution**The answer is the sum of the 2 maximum weights.

You can always pick the 2 maximum weights: if they are ai and aj (i<j), you can flip the subsegment [i,j−1] to make them adjacent.

The result can't be larger, because the sum of the weights of any 2 pieces of cake is never greater than the sum of the 2 maximum weights.

Iterating over all pairs of pieces of cake is enough to get AC, but you can solve the problem in O(nlogn) by sorting the weights and printing the sum of the last 2 values, or even in O(n) if you calculate the maximum and the second maximum in linear time.

Complexity: O(t⋅n2), O(t⋅nlogn) or O(t⋅n)

Official solution: [150288088](https://codeforces.com/contest/1654/submission/150288088 "Submission 150288088 by emorgan")

[1654B - Prefix Removals](../problems/B._Prefix_Removals.md)

Author: [emorgan](https://codeforces.com/profile/emorgan "International Grandmaster emorgan")  
 Preparation: [TheScrasse](https://codeforces.com/profile/TheScrasse "Grandmaster TheScrasse")

 **Hint 1**Are there any characters that you can never remove?

 **Hint 2**You can't remove the rightmost occurrence of each letter. Can you remove the other characters?

 **Hint 3**If you can remove s1,s2,…,si−1 and si is not the rightmost occurrence of a letter, you can also remove si.

 **Solution**Let a be the initial string. For a string z, let's define z(l,r)=zlzl+1…zr, i.e., the substring of z from l to r. The final string is a(k,n) for some k.

In the final string, x=0, so the first character doesn't appear anywhere else in s. This means that ak≠ak+1,ak+2,…,an. In other words, ak is the rightmost occurrence of a letter in s.

Can you ever remove ai, if ai≠ai+1,ai+2,…,an? Notice that you would need to remove a(l,r) (l≤i≤r): this means that there must exist a(l′,r′)=a(l,r) for some l′>l. So, ai+l′−l=ai, and this is a contradiction.

Therefore, k is the smallest index such that ak≠ak+1,ak+2,…,an.

You can find k by iterating over the string from right to left and updating the frequency of each letter. Indeed ai≠ai+1,ai+2,…,an if and only if the frequency of the letter ai is 0 up to now (in the iteration from right to left we are performing). The value of k is the minimum such index i.

Complexity: O(n)

Official solution: [150288210](https://codeforces.com/contest/1654/submission/150288210 "Submission 150288210 by emorgan")

[1654C - Alice and the Cake](../problems/C._Alice_and_the_Cake.md)

Author: [emorgan](https://codeforces.com/profile/emorgan "International Grandmaster emorgan")  
 Preparation: [TheScrasse](https://codeforces.com/profile/TheScrasse "Grandmaster TheScrasse")

 **Hint 1**Can you find the initial weight which results in a?

 **Hint 2**The initial weight is the sum of the final weights. Let's simulate the division, starting from a new cake. How to choose fast which splits to do?

 **Hint 3**If the largest piece is not in a, you have to split it. How to find the largest piece efficiently?

 **Hint 4**Keep a and the new cake in two multisets or priority queues.

 **Solution**First, let's find the initial weight. When a piece of cake is split, the sum of weights is ⌊w2⌋+⌈w2⌉:

 * if w is even, ⌊w2⌋+⌈w2⌉=w2+w2=w;
* if w is odd, ⌊w2⌋+⌈w2⌉=w−12+w+12=w.

Therefore, the sum of weights is constant, and the initial weight is the sum of the final weights.

Now let's start from a cake b of weight b1=∑ni=1ai, split it (into pieces of weight bi) and try to make it equal to a. At any moment, it's convenient to consider the largest bi, because you can determine if you can split it or not.

More specifically,

 * if bi is not in a, you have to split it;
* if bi=aj for some j, you can only match aj with bi or with a bk such that bk=aj=bi (because there doesn't exist any larger bk): that's equivalent to removing aj and bi from a, b, respectively.

Notice that, if at any moment the maximum element of b is smaller than the maximum element of a, the answer is `NO`.

If can keep a and b in any data structure that supports inserting an integer, asking for the maximum and removing the maximum (e.g., multiset or priority queue), the following algorithm works.

While either a or b is not empty,

 * if the maximum element of b is smaller than the maximum element of a, print `NO` and break;
* if the maximum element of b is equal to the maximum element of a, remove it from both a and b;
* if the maximum element m of b is larger than the maximum element of a, remove it from b and split the piece of cake (i.e., insert ⌊w2⌋ and ⌈w2⌉ into b).

If a or b are both empty at the end, the answer is `YES`.

Complexity: O(nlogn)

Official solution: [150288232](https://codeforces.com/contest/1654/submission/150288232 "Submission 150288232 by emorgan")

[1654D - Potion Brewing Class](../problems/D._Potion_Brewing_Class.md)

Author: [emorgan](https://codeforces.com/profile/emorgan "International Grandmaster emorgan")  
 Preparation: [TheScrasse](https://codeforces.com/profile/TheScrasse "Grandmaster TheScrasse")

 **Hint 1**The n−1 facts make a tree.

 **Hint 2**Assume that the amount of ingredient 1 is 1. For each i, the amount of ingredient i would be ci/di for some integer ci,di>0. How to make an integer amount of each ingredient?

 **Hint 3**The optimal amount of ingredient 1 is lcm(d1,d2,…,dn). 

 **Hint 4**Can you find the exponent of each prime p≤n in lcm(d1,d2,…,dn)?

 **Hint 5**If you visit the nodes in DFS order, each edge changes the exponent of O(logn) primes. At each moment, keep the factorization of ci/di of the current node, i.e., the exponents of each p≤n (they can be negative). For each p, also keep the minimum exponent so far.

 **Solution**Read the hints. The rest is just implementation.

Start a DFS from node 1. Keep an array f such that fp is the exponent of p in the amount of ingredients of the current node. Keep also vi=ci/dimod998244353. At the beginning, the amount of ingredients (of node 1) is 1, so fp=0 for each p. Whenever you move from node i to node j, and ri/rj=x/y,

 * for each pk such that pk∣x and pk+1∤x, decrease fp by k;
* for each pk such that pk∣y and pk+1∤y, increase fp by k.

Notice that there exist O(logn) such values of pk for each edge, and you can find them by precalculating either the smallest prime factor (with the sieve of Eratosthenes) or the whole factorization of every integer in [2,n].

Let gp be the minimum value of fp during the DFS. Then, for every p, you have to multiply the amount of ingredients of node 1 by p−gp.

The answer is the sum of vi, multiplied by the amount of ingredients of node 1.

Complexity: O(nlogn)

Official solution: [150288255](https://codeforces.com/contest/1654/submission/150288255 "Submission 150288255 by emorgan")

[1654E - Arithmetic Operations](../problems/E._Arithmetic_Operations.md)

Author: [emorgan](https://codeforces.com/profile/emorgan "International Grandmaster emorgan")  
 Preparation: [TheScrasse](https://codeforces.com/profile/TheScrasse "Grandmaster TheScrasse")

 **Hint 1**Consider each element of the array as being a point in the plane (i,ai). Then all of the elements that *don't* get affected by an operation lie on a single line in the plane. Find a line that maximizes the number of points on it.

 **Hint 2**Let m be the upper bound on ai. The intended complexity is O(n√m).

 **Hint 3**Let m be the upper bound on ai. Let d be the difference between adjacent elements in the final array. Create a piecewise algorithm for the cases where |d|<√m and |d|≥√m

 **Solution**As explained in the hints, instead of computing the fewest number of operations, we will compute the largest number of elements that don't have an operation on them, and we will create a piecewise algorithm with final complexity O(n√m) , where m is the upper bound on ai.

Let d be the common difference between elements in our final sequence. First of all, I will assume that d≥0, since solving the problem for negative d is as simple as reversing the array and running the solution again. If d is fixed beforehand, we can solve the problem in O(n) by putting element i into bucket ai−d⋅i and returning n minus the size of the biggest bucket.

For d<√m, we can use the above algorithm to handle all of these d in O(n√m) time. We can keep a hashmap from bucket index → number of elements in the bucket, or we can just keep an array since the bucket indices have a range of at most O(n√m) which is not enough to exceed the memory limit.

For d≥√m, we observe that if we have two indices i,j such that j>i+√m, then at least one of them definitely has to have an operation performed on it, because the difference between them would have to be aj−ai≥√m⋅d>m which is not possible. In other words, if we consider the set of elements which are not edited, that set will have gaps between pairs of elements of size at most √m.

So, we can build a graph between indices with an edge i→j with label x if i<j≤i+√m and aj−aij−i=x. This graph has at most n√m edges. Then we just have to find the longest path in the graph where all edges have the same label. You can do this with dynamic programming -- let dpi,d be the length of the longest path ending at index i, where all edges have label d. For each i, we only need to check edges to j where i−√m<j<i. This means the time complexity is O(n√m). To store the values dpi,d sparsely, we can use either a hash map or a rotating buffer (where we only store dpi,d for i in a sliding window of width √m).

Complexity: O(n√m)

Official solution: [150288285](https://codeforces.com/contest/1654/submission/150288285 "Submission 150288285 by emorgan")

[1654F - Minimal String Xoration](../problems/F._Minimal_String_Xoration.md)

Author: [dario2994](https://codeforces.com/profile/dario2994 "International Grandmaster dario2994"), [emorgan](https://codeforces.com/profile/emorgan "International Grandmaster emorgan")  
 Preparation: [dario2994](https://codeforces.com/profile/dario2994 "International Grandmaster dario2994"), [TheScrasse](https://codeforces.com/profile/TheScrasse "Grandmaster TheScrasse")

 **Hint 1**Let f(s,x) be the string t such that ti=si⊕x. The intended solution not only finds the x such that f(s,x) is lexicographically minimized, but produces an array of all 0≤x<2n sorted according the comparator f(s,i)<f(s,j).

 **Hint 2**The solution is similar to the standard method to construct a suffix array.

 **Hint 3**Let ak be an array of the integers 0 through 2n−1, sorted according to the lexicographic ordering of the first 2k characters of f(s,x). The answer to the problem is f(s,an,0). Given the array ak−1, can you compute ak?

 **Solution**Let f(s,x) be the string t such that ti=si⊕x.

The solution is inspired by the standard method to construct a suffix array. Let ak be an array containing the integers 0,1,2,…,2n−1, sorted according to the lexicographic ordering of the prefixes of length 2k of the strings f(s,0),f(s,1),…,f(s,2n−1) (i.e., the prefix of length 2k of f(s,ak[i]) is lexicographically smaller or equal than the prefix of length 2k of f(s,ak[i+1])). We can construct ak using ak−1, and a0 is easy to construct as a base case.

In order to construct ak from ak−1, we will first construct an auxiliary array of integers v using ak−1, where vi<vj iff f(s,i)0..2k−1<f(s,j)0..2k−1. Then, we will sort the array ak according to the comparison of tuples (vi,vi⊕2k−1)<(vj,vj⊕2k−1).

Once we have an, then we just print f(s,an,0). In total, the solution takes O(2nn2) time, which can be optimized to O(2nn) using the fact that tuples of integers in the range [0,m] can be sorted using radix sort in O(m) time. This optimization was not required to get AC.

Official solution: [150288326](https://codeforces.com/contest/1654/submission/150288326 "Submission 150288326 by emorgan")

[1654G - Snowy Mountain](../problems/G._Snowy_Mountain.md)

Author: [emorgan](https://codeforces.com/profile/emorgan "International Grandmaster emorgan")  
 Preparation: [dario2994](https://codeforces.com/profile/dario2994 "International Grandmaster dario2994"), [emorgan](https://codeforces.com/profile/emorgan "International Grandmaster emorgan"), [TheScrasse](https://codeforces.com/profile/TheScrasse "Grandmaster TheScrasse")

 **Hint 1**Let's say that a vertex is "flippable" if it has at least one neighbor of the same height. The optimal strategy for a skier is to ski to a flippable vertex with lowest height, flip back and forth between that vertex and its neighbor until all energy is used, and then ski to a base lodge.

 **Hint 2**Assuming the skier starts at vertex v and chooses vertex u as the flippable vertex to flip back and forth at, this skier will "waste" a total of hu units of kinetic energy for a total path length of 2hv−hu. Note that if no such u exists, then the maximum amount of hv will be wasted as the skier goes straight to a base lodge. Let wv be this "wasted" amount. Instead of computing the maximum path length for the skier starting at vertex v, compute wv. The answer for that vertex is 2hv−wv.

 **Hint 3**Try to solve this seemingly unrelated problem: Let S be the set of flippable vertices. What is the largest possible value of ∑v∈Shv?

 **Hint 4**The largest possible value of ∑v∈Shv is O(n). Therefore, there are at most O(√n) distinct values of wv across all vertices. Solve for each value of wv separately.

 **Solution**Read the hints. The rest is just implementation.

For each set of flippable vertices of the same height, we can calculate the set of starting vertices which are able to reach at least one vertex in that flippable set. To do this, split the graph up into layers of equal height. Let cv be the minimum required energy to reach a vertex in the flippable set. cv can be computed via shortests paths, where edges in the same layer have weight 1 and edges from layer i to i+1 have weight −1. We can use bfs to relax the costs of vertices in a single layer, and then easily transition to the next layer. We do this for O(√n) different starting heights, so the total complexity is O(n√n).

Official solution: [150288345](https://codeforces.com/contest/1654/submission/150288345 "Submission 150288345 by emorgan")

[1654H - Three Minimums](../problems/H._Three_Minimums.md)

Author: [dario2994](https://codeforces.com/profile/dario2994 "International Grandmaster dario2994"), [TheScrasse](https://codeforces.com/profile/TheScrasse "Grandmaster TheScrasse")  
 Preparation: [dario2994](https://codeforces.com/profile/dario2994 "International Grandmaster dario2994"), [TheScrasse](https://codeforces.com/profile/TheScrasse "Grandmaster TheScrasse")

 **Hint 1**If p1,…,pn is good and pi=1, what can you say about p1,p2,…,pi and pi,pi+1,…,pn?

 **Hint 2**Find a quadratic solution ignoring the constraints given by the string s.

 **Hint 3**Find an O(n2+nm) solution taking care of the constraints given by the string s.

 **Hint 4**Optimize the O(n2+nm) solution using generating functions.

 **Hint 5**The solution to the ODE y′(t)=a(t)y(t)+b(t) with y(0)=1 is given by exp(∫a)(1+∫bexp(−∫a))

 **Solution**First of all, let us state the following lemma (which is sufficient to solve the problem in O(n2) if one ignores the constraints given by the string s). We omit the proof as it is rather easy compared to the difficulty of the problem as a whole.

**Lemma**: The following statements hold for a permutation p1,p2,…,pn.

 * p is good if and only if p[1:i] and p[i:n] are good, where pi=1.
* If p1=1, then p is good if and only if p[1:i] and p[i:n] are good, where pi=2.
* If p1=1 and pn=2, then p is good if and only if it is bitonic, i.e., p1<p2<p3<⋯<pi>pi+1>⋯pn−1>pn, where pi=n.

Given 1≤l<r≤n, we say that a permutation q1,q2,…,qr−l+1 of 1,2,…,r−l+1 is *[l,r]-consistent* if for any l≤i≤min(r,m−1):

 * qi−l+1<qi−l+2 if si=<;
* qi−l+1>qi−l+2 if si=>.

Informally speaking, a permutation is [l,r]-consistent if it satisfies the constraints given by s when it is written in the positions [l,r].

For 1≤l<r≤n, let a∗∗(l,r), a1∗(l,r), a∗1(l,r), a12(l,r), a21(l,r) be the the number of good permutations which are [l,r]-consistent and, respectively, 

 * No additional conditions;
* Start with 1;
* End with 1;
* Start with 1 and end with 2;
* Start with 2 and end with 1.

For 1≤i<n and c∈<,>, let q(i,c):=[i>m or si=c]. Informally speaking, q(i,<) is 1 if and only if it can be pi<pi+1 and q(i,>) is 1 if and only if it can be pi>pi+1.

Thanks to the Lemma, one has the following relations:

 * a∗∗(l,r)=∑ri=la∗1(l,i)a1∗(i,r)(r−li−l).
* a1∗(l,l)=1. For l<r, a1∗(l,r)=∑ri=l+1a12(l,i)a1∗(i,r)(r−l−1i−l−1).
* Analogous formula for a∗1.
* a12(l,l)=0 and a12(l,l+1)=q(l,<) and a12(l,l+2)=q(l,<)⋅q(l+1,>). For l<l+1<r, a12(l,r)=q(l,<)a21(l+1,r)+q(r−1,>)a12(l,r−1).
* Analogous formula for a21.

The problem asks to compute a∗∗(1,n). Thanks to the formulas stated above, it is straightforward to implement an O(n2) solution. Now we will tackle the hard task of optimizing it to O(nm+nlog(n)).

In order to compute a∗∗(1,n), we will compute a∗1(1,k) and a1∗(k,n) for all 1≤k≤n.

We have the recurrence relation (for k≥2)

 a∗1(1,k)=∑ki=1a∗1(1,i)a21(i,k)(k−2i−1)Setting xk−1:=a∗1(1,k)/(k−1)!, (1) is equivalent to (for k≥1, and also for k=0!)

 k⋅xk=∑k−1i=0xia21(i+1,k+1)(k−1−i)!.This looks very similar to an identify between generating functions (a derivative on the left, a product on the right); but for the fact that a21 depends on two parameters. To overcome this issue let us proceed as follows.

Notice that, if we set b to any of the functions a∗∗, a∗1, a1∗, a12, a21, it holds b(l,r)=b(l+1,r+1) whenever l>m. Hence, let us define b∗∗(k)=a∗∗(n+1,n+k) and analogously b1∗(k), b∗1(k), b12(k), b21(k).

With these new definitions, (2) becomes (for k≥0)

 k⋅xk=∑k−1i=0xib21((k−1−i)+2)(k−1−i)!+∑min(k−1,m−1)i=0xia21(i+1,k+1)−b21(k+1−i)(k−1−i)!.Let ui:=b21(i+2)i! and vk−1:=∑min(k−1,m−1)i=0xib21(k+1−i)−a21(i+1,k+1)(k−1−i)!. So, (3) simplifies to

 k⋅xk=vk−1+∑k−1i=0xiuk−1−i.We precompute in O(nm) the values of a12(l,r) and a21(l,r) for 1≤l≤m, l<r≤n. We can also precompute in O(n) the values of b12(k),b21(k) for 1≤k≤n. In O(m2) we compute also xi for all 0≤i≤m−1. Thus, in O(nm) we can compute, for all 0≤k<n, the values uk.

It is now time to start working with generating functions. Let X(t):=∑k≥0xktk, U(t):=∑k≥0uktk, V(t):=∑k≥0vktk. We know U(t) and V(t) (at least the first n coefficients) and we want to compute X(t). Since x0=1, we know X(0)=1. Moreover (4) is equivalent to the ordinary differential equation X′=V+U⋅X. This ODE is standard and its (unique) solution is given by

 X=exp(∫U)(1+∫Vexp(−∫U)).Since the product of generating functions and the exponential of a generating function can be computed in O(nlog(n)), we are able to obtain the values of xk for all 0≤k<n and thus the values of a∗1(1,k).

Now, let us see how to compute a1∗(k,n). Since a1∗(k,n)=b1∗(n−k+1) for all m<k≤n, let us first compute b1∗(k) for all 1≤k≤n. By repeating verbatim the reasoning above, we get that the generating function Y(t):=∑k≥0yktk, where yk−1:=b1∗(k)/(k−1)!, is given by (V=0 in this case) Y=exp(∫U). So, it remains only to compute a1∗(k,n) for 1≤k≤m. This can be done naïvely in O(nm).

The overall complexity is O(nm+nlog(n)).

Official solution: [150306974](https://codeforces.com/contest/1654/submission/150306974 "Submission 150306974 by dario2994")

