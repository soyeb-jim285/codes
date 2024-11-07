# Tutorial_(en)

Thanks for participating; we hope you enjoyed the tasks! Look at the bottom of this post for some more challenges.

Feel free to ask in the comment if you have any question. If you have a different solution from ours, share it too. :D

#### Our approaches

 **Div2A**
### [1130A - Be Positive](https://codeforces.com/contest/1130/problem/A "Codeforces Round 542 [Alex Lopashev Thanks-Round] (Div. 2)")

*Tutorial is not available*

 **Div2B**
### [1130B - Two Cakes](https://codeforces.com/contest/1130/problem/B "Codeforces Round 542 [Alex Lopashev Thanks-Round] (Div. 2)")

*Tutorial is not available*

 **Div2C**
### [1130C - Соединить](https://codeforces.com/contest/1130/problem/C "Codeforces Round 542 [Alex Lopashev Thanks-Round] (Div. 2)")

Let S be the set of cells accessible from (r1,c1).

Similarly, let T be the set of cells accessible from (r2,c2).

We can find S and T using a search algorithm such as a DFS or a BFS.

If S=T, then a tunnel is not needed, so the answer is 0.

Otherwise, we need to create a tunnel with an endpoint in A and the other in B. Now, we can simply iterate through all possible pairs of cells ((x1,y1),(x2,y2)) where (x1,y1)∈S and (x2,y2)∈T to find one that minimizes the cost (i.e., (x1−x2)2+(y1−y2)2).

The time complexity is O(n4).

 **Div1A / Div2D**
### [1129A2 - Игрушечный поезд](../problems/A2._Toy_Train.md "Codeforces Round 542 [Alex Lopashev Thanks-Round] (Div. 1)")

We can consider the pickup requests from each station individually. The overall answer for some fixed starting station is simply the maximum time needed to fulfill deliveries among all pickup stations.

Suppose the starting station for the train is fixed at some station s (1≤s≤n).

Consider some station i (1≤i≤n). Let out(i) denote the number of candies that need to be picked up from station i. If out(i)=0, we do not consider this station. From now on, we assume out(i)≥1. Each time that the train visits station i to pick up a candy, we can choose which candy it should pick up. Therefore, we should find an order that would minimize the time needed to fulfill all deliveries from pickup station i. It turns out, however, that the only thing that matters is the last candy to be delivered. Suppose the last candy is to be delivered to station e, the total time needed to fulfill all pickup requests from station i would be: dist(s,i)+n∗(out(i)−1)+dist(i,e), where dist(a,b) represents the time needed to travel from station a to station b. Take some time to think why this is the case! With this formulated, it is now clear that we have to choose the last candy to deliver that minimizes dist(i,e).

All of this can be done in O(n) (with an O(n+m) pre-process only once to find the optimal last candy for each pickup station). To find the answer for every starting station for the train, we can simply run the above algorithm n times.

The time complexity is O(n2+m).

 **Div1B / Div2E**
### [1129B - Неправильный ответ](../problems/B._Wrong_Answer.md "Codeforces Round 542 [Alex Lopashev Thanks-Round] (Div. 1)")

Suppose a0=−1 and ai≥1 for each 1≤i<n. Let S=n−1∑i=0ai.

Assume also that n≥2.

It is easy to see that Alice's algorithm produces (n−1)(S+1) as the answer. Meanwhile, there are two possible correct answers: either nS or (n−1)(S+1), whichever is greater.

Assume further that a1≥2. The correct answer for this array is then nS. The difference between these two results is nS−(n−1)(S+1)=S−n+1.

Now, we can easily create array a greedily so that S−n+1=k.

The time complexity is O(n).

 **Div1C**
### [1129C - Азбука Морзе](../problems/C._Morse_Code.md "Codeforces Round 542 [Alex Lopashev Thanks-Round] (Div. 1)")

We will be computing the answers offline instead of doing so immediately after each modification.

Let T=Sreversed. Now, we need to find the number of English sequences that, if considered backward, would translate into some substring of each suffix of T.

Let f(l,r) be the number of English sequences that translate to exactly T[l..r].

Let g(l,r) be sum of f(l,x) over all l≤x≤r. 

Note that f(l,r) can be calculated with dynamic programming for all 1≤l≤r≤m in O(km2) where k denotes the longest length of an English alphabet in Morse code (which is 4). Following that, we can calculate g(l,r) for all 1≤l≤r≤m in O(m2).

The answer for the suffix T[x..m] is simply the sum of g(i,m) over all x≤i≤m subtracted by the number of over-counted English sequences. The number of over-counted sequences can be calculated by considering the suffix array of T. Namely, for each two adjacent suffixes in the list, we over-counted them by g(l,r) with l and r denoting the corresponding indices of their longest common prefix (LCP).

Therefore, the answer for T[1..m] is ∑1≤i≤mg(i,m) subtracted by the sum of g(l,r) of the LCP between each pair of adjacent suffixes.

Transitioning to solve the problem for T[x′..m] where x′=x+1 can be done efficiently, since the removal character of the string affects only one entry in the suffix list.

To sum up, we find g(l,r) for all valid l and r in O(km2). Then, we sort the suffixes naively in O(m2logm), before computing the answer in the final step in O(m2).

The time complexity is O(km2+m2logm).

 **Div1D**
### [1129D - Изоляция](../problems/D._Isolation.md "Codeforces Round 542 [Alex Lopashev Thanks-Round] (Div. 1)")

Let f(l,r) be the number of integers that appear exactly once in the segment a[l..r]. We can use the following recurrence to compute the answer: dp(n)=∑0≤i<n∧f(i+1,n)≤kdp(i), where dp(0)=1.

A naive O(n2) implementation will definitely be too slow. To compute the said recurrence efficiently, we will do as follows.

Preparation

First, let's design an array b so that f(l,r) is the sum of elements in segment b[l..r] for some fixed r. Ideally, it should be easy (i.e., require only a few operations) to transform this array b into another array b′ that would work with r′=r+1 instead.

One design is as follows. First, let each entry of b be 0. This array now works imaginarily when r=0. To make it work for r′=r+1, consider the element ar+1.

* If this value appeared before at least twice, set bi=0 where i is the second-last appearance of ar+1 (not counting the appearance at index r+1).
* If this value appeared before at least once, set bi=−1 where i is the last appearance of ar+1.
* Finally, set br+1=1.

Now, you can see that the sum in the segment b[l..(r+1)] correctly represents f(l,r+1) for any 1≤l≤r+1!

The Real Thing

Let us divide the array into k blocks so that each block contains nk elements (assume for simplicity that k divides n). Each block corresponding to some segment [L..R] should store (1) sum of elements in b[L..R] (i.e., f(L,R)) and (2), for each −nk≤i≤nk, q(i)= sum of dp(x−1) where f(x,R) is less than or equal to i. A modification to bj for some index j will require an O(nk) update.

With array b ready for our r, we are ready to compute dp(r). Let t be a temporary variable initially equal to 0. For each l≤r that belongs to the same block as r, add dp(l−1) to dp(r) if f(l,r)≤k, and also add bl to t. This runs in O(nk). To account for the left possible endpoints from other blocks, for each block, starting from one directly to the left of the block that contains r to the leftmost block:

* Suppose this block corresponds to the segment [L..R].
* Let x=k−t.
* If x<−nk, do nothing.
* If −nk≤x≤nk, add q(x) to dp(r).
* If nk<x, add q(nk) to dp(r).
* Add f(L,R) to t.

The step above runs in O(k). That is, our algorithm takes O(k+nk) time to compute dp(r) for some r.

The time complexity is O(nk+n2k), since there are n values of r that we need to compute dp(r) for.

If we choose k=√n, our solution would run in O(n√n).

 **Div1E**
### [1129E - Легендарное дерево](../problems/E._Legendary_Tree.md "Codeforces Round 542 [Alex Lopashev Thanks-Round] (Div. 1)")

In this analysis, let V be the set of all vertices. We will use tuples of the form (S,T,v) to represent queries. 

First, we will root the tree at vertex 1. The size of each subtree can be found in n−1 queries by asking ({1},{2,3,…,n},i), for each 1≤i≤n.

Suppose sz(i) denotes the size of the subtree rooted at vertex i. Let us sort the vertices (and store the results in v) so that sz(vi)≤sz(vi+1) for each 1≤i<n.

We will find all children of each vertex vi in the ascending order of i. While we do so, we will maintain a set X, initially containing only v1. It will store the processed-so-far vertices whose parents have not been found.

Namely, for each 2≤i≤n:

* Let k=({1},X,vi). This is the number of direct children that vi has.
* Let x1,x2,…,x|X| be the vertices in X in an arbitrary order.
* For k times: binary search to find the smallest m such that querying ({1},{x1,x2,…,xm},vi) returns a non-zero result and remove xm from X. For each such m, we know that there is an edge (xm,vi).
* Add vi to X.

This solution asks at most 2(n−1)+(n−1)log2n queries.

Time complexity: O(n2logn)

#### Challenges

 **Div2C**Can you do better than ![](images/52f5eb64c79099e50853c05d5eeed424185b604b.png)?

There's a nice ![](images/29165e38e9dc2f1300719e31f973634e704eef6c.png) solution, but you could also use a Voronoi diagram for an ![](images/925b67176442b3799c066e54c14485d5ba1f412d.png) runtime too!

 **Div1A / Div2D**Develop from our ![](images/2ea07df0930018e7899f810e5f4842f0e6499e40.png) approach to solve the task in linear time!

 **Div1C**Solve the task when *m* can be up to 105!

