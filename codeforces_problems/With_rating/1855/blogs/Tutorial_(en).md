# Tutorial_(en)

The official implementations of all the problems are [here](https://codeforces.com/https://drive.google.com/file/d/1stkidhN_ftTOzK4qcMYxkUAlwWWb3AqF/view?usp=sharing).

[1855A - Учитель Дальтон](../problems/A._Dalton_the_Teacher.md "Codeforces Round 889 (Div. 2)")

Author: [Kaey](https://codeforces.com/profile/Kaey "Мастер Kaey")  
 Preparation: [akifpatel](https://codeforces.com/profile/akifpatel "Международный мастер akifpatel")

 **Hint 1**What's the most efficient way to make the sad students happy?

 **Hint 2**In most cases, you can make 2 sad students happy in 1 move.

 **Solution**Let s be the number of sad students at the beginning. The answer is ⌈s2⌉.

In one move, you can make at most 2 sad students happy (because you can change the position of at most two students), so you need at least ⌈s2⌉ moves.

In fact, you can make everyone happy in exactly ⌈s2⌉ moves:

 * while there are at least 2 sad students, you can swap them and both of them will be happy;
* if there is exactly 1 sad student left, you can swap it with any other student.

Complexity: O(n)

[1855B - Наибольший интервал делителей](../problems/B._Longest_Divisors_Interval.md "Codeforces Round 889 (Div. 2)")

Author: [TheScrasse](https://codeforces.com/profile/TheScrasse "Международный гроссмейстер TheScrasse")  
 Preparation: [TheScrasse](https://codeforces.com/profile/TheScrasse "Международный гроссмейстер TheScrasse")

 **Hint 1**What's the answer if n is odd?

 **Hint 2**Try to generalize Hint 1.

 **Hint 3**What's the answer if n is not a multiple of 3?

 **Hint 4**If the answer is not a multiple of x, the answer is <x. If the answer is a multiple of 1,…,x, the answer is ≥x.

 **Solution**Suppose you find a valid interval [l,r]. Note that the interval [l,r] contains at least one multiple of x for each 1≤x≤r−l+1 (you can find it out by looking at the values in [l,r] modulo x). Then, the interval [1,r−l+1] is also valid and has the same length.

So, it's enough to check intervals with l=1, i.e., find the smallest x that does not divide n. The answer is x−1.

Complexity: O(log(maxn))

[1854A1 - Dual (простая версия)](https://codeforces.com/contest/1854/problem/A1 "Codeforces Round 889 (Div. 1)")

Author: [TheScrasse](https://codeforces.com/profile/TheScrasse "Международный гроссмейстер TheScrasse")  
 Preparation: [akifpatel](https://codeforces.com/profile/akifpatel "Международный мастер akifpatel")

 **Hint 1**There are several solutions to the easy version. In any case, how to get ai≤ai+1?

 **Hint 2**For example, you can try making ai+1 bigger using a positive element.

What to do if all the elements are negative?

 **Hint 3**If all the elements are negative, you can win in n−1 moves.

If there is a positive element, you can try to make a1≤a2, then a2≤a3, etc.

 **Hint 4**Make a big positive element using moves (i,i), then make a2 bigger.

 **Solution**If all the elements are negative, you can make suffix sums (they are nondecreasing) with moves (n−1,n),(n−2,n−1),…

If there is at least one positive element ax,

 * make ax>20 using 5 moves (x,x);
* make a2 the biggest element using 2 moves (2,x);
* make a3 the biggest element using 2 moves (3,2);
* ...

This strategy requires 5+2(n−1)≤43 moves.

Complexity: O(n)

[1854A2 - Dual (сложная версия)](https://codeforces.com/contest/1854/problem/A2 "Codeforces Round 889 (Div. 1)")

Author: [TheScrasse](https://codeforces.com/profile/TheScrasse "Международный гроссмейстер TheScrasse")  
 Preparation: [akifpatel](https://codeforces.com/profile/akifpatel "Международный мастер akifpatel"), [dario2994](https://codeforces.com/profile/dario2994 "Международный гроссмейстер dario2994")

The hints and the solution continue from the easy version.

 **Hint 5**You can win in n−1 moves if all the elements are negative, but also if all the elements are positive.

 **Hint 6**Again, make a big positive / negative element, then use it to make everything positive / negative.

 **Hint 7**In how many moves can you either make everything positive or make everything negative?

 **Hint 8**Assume the positive elements are at least as many as the negative elements. Can you win in 34 moves?

 **Hint 9**The bottleneck is making the big positive element. Is it always necessary? Can you find a better bound on the "best" number of moves?

 **Solution**If you either make everything positive or make everything negative, you can win in n−1≤19 moves by making prefix sums or suffix sums, respectively. So, you have to reach one of these configurations in 12 moves.

How to make everything positive? First, you create a big element with the maximum absolute value (this requires x1 moves), then you add it to every negative element (this requires x2 moves). y1 and y2 are defined similarly in the negative case.

So,

 * one of x1 and y1 is 0 (because the element with the maximum absolute value at the beginning is either positive or negative), and the other one is ≤5 (because you can make |ai|≥32 in 5 moves);
* x2 is the number of negative elements, y2 is the number of positive elements. So, x2+y2≤n≤20.

Therefore, you need additional min(x1+x2,y1+y2) moves. Since x1+x2+y1+y2≤25, min(x1+x2,y1+y2)≤⌊252⌋=12, as we wanted. Now you can simulate the process in both cases (positive and negative), and choose one that requires ≤31 moves in total.

Complexity: O(n)

[1854B - Заработать или разблокировать](https://codeforces.com/contest/1854/problem/B "Codeforces Round 889 (Div. 1)")

Author: [TheScrasse](https://codeforces.com/profile/TheScrasse "Международный гроссмейстер TheScrasse")  
 Preparation: [akifpatel](https://codeforces.com/profile/akifpatel "Международный мастер akifpatel")

 **Hint 1**The order of used cards doesn't matter. So, you can assume you always use the card on the top.

 **Hint 2**Suppose that you unlock x cards in total. How many points can you get?

 **Hint 3**If you unlock x cards, it means you end up making moves with the first x cards. So, you know the total number of (cards + points) that you get.

 **Hint 4**If you unlock x cards, the number of points is uniquely determined. It's convenient to assume that x≤2n and the cards n+1,…,2n have value 0.

 **Hint 5**Now you have to determine the unlockable prefixes of cards (i.e., the values of x you can reach). It looks similar to knapsack.

 **Hint 6**You can optimize the solution using a bitset. Be careful not to use locked cards.

 **Solution**First, note that the order of used cards doesn't matter. If you use at least once a card that is not on the top on the deck, you can prove that using the cards in order (from the top) would give the same number of victory points.

Let's add n cards with value 0 at the end of the deck. Then, it's optimal to unlock x≤2n cards, and use cards 1,…,x, getting a1+⋯+ax−x+1 points.

Let's find the reachable x. Let dpi be a bitset that stores the reachable x after using the first i cards.

 * Base case: dp0,1=1.
* Transitions: first, dpi `|=` dpi−1 `<<` ai. If dpi,i=1, you can update the answer with a1+⋯+ai−i+1, but you can't unlock any other card, so you have to set dpi,i=0 before transitioning to i+1.

Complexity: O(n2/w)

[1854C - Ожидаемое разрушение](https://codeforces.com/contest/1854/problem/C "Codeforces Round 889 (Div. 1)")

Author: [TheScrasse](https://codeforces.com/profile/TheScrasse "Международный гроссмейстер TheScrasse")  
 Preparation: [akifpatel](https://codeforces.com/profile/akifpatel "Международный мастер akifpatel")

 **Hint 1**Consider n blocks in positions S1,S2,…,Sn. After how much time does block x disappear? It may be convenient to put a fake "static" block in position m+1.

 **Hint 2**Block x disappears when it reaches block x+1. But what if block x+1 disappears before block x?

 **Hint 3**From the perspective of block x, it's convenient to assume that block x+1 never disappears: when it touches another block y, it's y that disappears.

 **Hint 4**When you consider the pair of blocks x,x+1, the other blocks don't really matter, and you can use linearity of expectation to calculate the contribution of each pair independently.

A reasonable interpretation is given by considering an (n+1)×(m+1) grid, where the i-th row initially contains a block in column Si. Then, you are calculating the expected time required for the blocks 1,…,m to have another block immediately below them (in the same column).

 **Hint 5**Blocks x,x+1 both move with probability 1/2, unless block x+1 has reached position m+1.

 **Hint 6**dpi,j= expected number of moves of block x before it disappears, if the block x is in position i and the block x+1 is in position j.

 **Solution**Consider an (n+1)×(m+1) grid, where the i-th row initially contains a block in column Si, and row n+1 contains a block in column m+1.

 * The set is empty if all the blocks are in column m+1; i.e., if every block has reached the block in the following row.
* Every "connected component" of blocks (except the last one) represents an element in the set. These components move equiprobably.

Let's calculate the expected time required for the block in row x to "reach" the block in row x+1. If you consider a single pair of blocks, every block moves with probability 1/2, unless block x+1 is in column m+1.

So, you can calculate dpi,j= expected number of moves of the block x before it reaches the block x+1, if the block x is in position i and the block x+1 is in position j.

The base cases are dpi,m+1=(m+1)−i (because only the block x can move) and dpi,i=0 (because block x has already reached block x+1). In the other cases, dpi,j=((dpi+1,j+1)+dpi,j+1)/2.

By linearity of expectation, the answer is the sum of dpSi,Si+1.

Complexity: O(m2)

[1854D - Майкл и отель](https://codeforces.com/contest/1854/problem/D "Codeforces Round 889 (Div. 1)")

Author: [TheScrasse](https://codeforces.com/profile/TheScrasse "Международный гроссмейстер TheScrasse")  
 Preparation: [akifpatel](https://codeforces.com/profile/akifpatel "Международный мастер akifpatel")

 **Hint 1**You can find any ai in 9 queries.

 **Hint 2**Find the nodes in the cycle in the component with node 1. What happens if you know the whole cycle?

 **Hint 3**Suppose you already know some nodes in the cycle. Can you find other nodes faster?

 **Hint 4**Can you "double" the number of nodes in the cycle?

 **Solution**The component with node 1 contains a cycle. If you know the whole cycle (of length x), you can win in n−x queries by asking for each node if it ends up in the cycle after n moves.

You can get a node in the cycle in 9 queries, doing a binary search on the n-th successor of node 1.

How to find the rest of the cycle?

 * First, find k nodes in the cycle, doing a binary search on the successor of the last node found. These nodes make a set C.
* Then, check for each node if it's "sufficiently close" to C, by asking (i,k,C). Now, you know either 2k nodes in the cycle, or the whole cycle.
* Repeat until you get the whole cycle.

If you choose k=63, you spend at most 9⋅63+(500−63)+(500−126)+(500−252)+(500−252)=1874 queries.

[1854E - Комплекты игр](https://codeforces.com/contest/1854/problem/E "Codeforces Round 889 (Div. 1)")

Author: [dario2994](https://codeforces.com/profile/dario2994 "Международный гроссмейстер dario2994")  
 Preparation: [akifpatel](https://codeforces.com/profile/akifpatel "Международный мастер akifpatel"), [dario2994](https://codeforces.com/profile/dario2994 "Международный гроссмейстер dario2994")

 **Hint 1**Go for a randomized approach.

 **Hint 2**Many ones are useful.

 **Hint 3**Either you go for a greedy or for a backpack.

 **Solution**We describe a randomized solution that solves the problem for m up to 1011 (and, with some additional care, may be able to solve also m up to 1012). We decided to give the problem with the smaller constraint m≤1010 to make the problem more accessible and because there may be some rare cases below 1011 for which our solution is too slow (even though we could not find any). We don't know any provably correct solution, if you have one we would be curious to see it. We expect to see many different solutions for this problem.

**Main idea:** Choose suitably the values a1,a2,…,ah that belong to [1,29] and then find ah+1,ah+2,…,ak in [31,60] by solving a backpack-like problem.

Let us describe more precisely the main idea. Assume that a1,a2,…,ah≤30 are fixed and they satisfy a1+a2+⋯+ah<60. For any s=0,1,2,…,29, let f(s) be the number of subsets I⊆1,2,…,h so that ∑i∈Iai=s. If we can find some values 0≤s1,s2,…,sk−h≤29 so that f(s1)+f(s2)+⋯+f(sk−h)=s, then by setting ah+i=60−si for i=1,2,…,k−h we have found a valid solution to the problem.

There are two main difficulties:

 * How can we find s1,s2,…,sk−h?
* How should we choose a1,a2,…,ah?

Since it is important to get a good intuitive understanding of the computational complexity of the algorithm, let us say now that we will choose h≤44 and (accordingly) k−h=16. These values are flexible (the solution would still work with h≤45 and k−h=45 for example). We will say something more about the choice of these values when we will describe how a1,a2,…,ah shall be chosen.

**The backpack problem to find s1,s2,…,sk−h.**

The naive way to find s1,…,sk−h would be to try all of them. There are (k−h+2929) possible ways (up to order, which does not matter). Since k−h=16 this number is ≈2⋅1011 which is too much to fit in the time limit.

To speed up the process, we will do as follows. Partition randomly A∪B=0,1,…,29 into two sets of size 15. We iterate over all possible s1,s2,…,s(k−h)/2∈A and over all possible s(k−h)/2+1,…,sk−h∈B and check whether the sum of one choice from the first group and one choice from the second group yields the result. This is a standard optimization for the subset sum problem. What is its complexity? It can be implemented in linear time in the size of the two groups we have to iterate over, which have size ((k−h)/2+1515)≈5⋅105. Notice that in this faster way we will not visit all the (k−h+2929) possible choices s1,s2,…,sk−h because we are assuming that exactly half of them belong to A and exactly half of them belong to B. This is not a big deal because with sufficiently high probability we will find a solution in any case.

**The choice of a1,a2,…,ah.**

It remains to decide how we should select a1,a2,…,ah. The following choice works:

 * Approximately the first log2(m) values are set equal to 1.
* Five additional values are chosen randomly from [1,6] so that the total sum stays below 60.

One should repeat the whole process until a solution is found.

**Some intuition on the construction.** The choice of a1,…,ah may seem arbitrary; let us try to justify it. The goal is to generate a set of values f(0),f(1),…,f(29) that are simultaneously ``random enough'' and with size smaller but comparable to m. These two conditions are necessary to expect that the backpacking problem finds a solution with high enough probability.

If a1=a2=⋯=ah=1, then f(s)=(k−hs) and these numbers have size comparable to m if 2h is comparable to m. This observation explains why we start with approximately log2(m) ones. The issue is that we need some flexibility in the process as we may need to repeat it many times, this flexibility is provided by the addition of some additional random elements which don't change the magnitude of the values f(0),f(1),…,f(29) but that modify them as much as possible (if we added a large number it would not affect many f(s) and thus it would not be very useful).

[1854F - Марк и космический корабль](https://codeforces.com/contest/1854/problem/F "Codeforces Round 889 (Div. 1)")

Author: [dario2994](https://codeforces.com/profile/dario2994 "Международный гроссмейстер dario2994")  
 Preparation: [akifpatel](https://codeforces.com/profile/akifpatel "Международный мастер akifpatel"), [dario2994](https://codeforces.com/profile/dario2994 "Международный гроссмейстер dario2994")

 **Hint 1**Solve the 2d version first.

 **Hint 2**The 4d version is not too different from the 2d one.

 **Hint 3**Find all the points such that the expected number of necessary moves is wrong.

 **Solution**
### **The 2-dimensional case.**

Let us begin by cpnsidering the 2-dimensional version of the problem. The solution to this simpler version provides the idea of the approach for the 4-dimensional version.

We want to reach (a,b). Can we do it with exactly k moves? Two simple necessary conditions are:

 * |a|+|b|≤1+2+⋯+k,
* a+b and 1+2+⋯+k shall have the same parity.

It turns out that this two conditions are also sufficient! One can prove it by induction on k as follows. If k=0 or k=1 or k=2 the statement is simple, thus we may assume k≥3.

Without loss of generality we may assume 0≤a≤b. If |a|+|b−k|≤1+2+⋯+k−1, then the statement follows by inductive hypothesis. Assume by contradiction that such inequality is false. If b≥k then we have a contradiction because |a|+|b−k|=|a|+|b|−k≤(1+2+⋯+k)−k. Otherwise b<k and the contradiction is |a|+|b−k|=a+k−b≤k≤1+2+⋯+k−1.

Hence, we have shown:

**Lemma 1:** The point (a,b) is reachable with exactly k moves if and only if |a|+|b|≤1+2+⋯+k and a+b has the same parity of 1+2+⋯+k.

### **The 4-dimensional case.**

One may expect statement analogous to the one of Lemma 1 to hold also when there are 4 coordinates. It does not, but it *almost* does and this is the crucial idea of the solution. More precisely, the number of counter examples to such statement is rather small and we can find all of them. This is the intuition behind the following definition.

**Definition:** For k≥0, let Ak be the set of points (a,b,c,d) such that |a|+|b|+|c|+|d|≤1+2+⋯+k and a+b+c+d has the same parity of 1+2+⋯+k but (a,b,c,d) is not reachable with exactly k moves.

As an immediate consequence of the definition, we have

**Observation:** The point (a,b,c,d) is reachable with exactly k moves if and only if |a|+|b|+|c|+|d|≤1+2+⋯+k and a+b+c+d has the same parity of 1+2+⋯+k and (a,b,c,d)∉Ak.

Thanks to this observation, if one is able to efficiently find Ak for all interesting values of k, then solving the problem is (comparatively) easy. The following lemma is our main tool for this purpose.

**Lemma 2:** Assume that (a,b,c,d)∈Ak with 0≤a≤b≤c≤d. Then, either k≤6 or (a,b,c,d−k)∈Ak−1.

**Proof:** The strategy is the same adopted to show Lemma 1. In some sense, we are saying that the inductive step works also in dimension 4, but the base cases don't.

If |a|+|b|+|c|+|d−k|≤1+2+⋯+k−1, then it must be (a,b,c,d−k)∈Ak−1 because if (a,b,c,d−k were reachable with k−1 moves then (a,b,c,d) were reachable with k and we know that this is not true.

Assume by contradiction that |a|+|b|+|c|+|d−k|>1+2+⋯+k−1. If d≥k then we reach the contradiction |a|+|b|+|c|+|d−k|=a+b+c+d−k≤(1+2+⋯+k)−k. Otherwise, d<k and thus we reach the contradiction |a|+|b|+|c|+|d−k|=a+b+c+k−d≤a+b+k≤3k−2≤1+2+⋯+k−1 (for k≥7).

We can now describe the solution. Assume that we know Ak−1. First of all, notice that it is then possible to determine in O(1) whether a point belongs to Ak or not. To generate a list of candidate elements for Ak we proceed as follows:

 * If k≤6, we simply iterate over all points with |a|+|b|+|c|+|d|≤1+2+⋯+k.
* Otherwise, we iterate over the points in Ak−1 and we consider as candidate elements for Ak the points that can be obtained by changing the value of one coordinate by k.

Thanks to Lemma 2, we know that this process finds all the elements in Ak. Once A0,A1,A2,A3,… are known, the problem boils down to a (relatively) simple counting argument that we skip.

One can verify that to handle correctly all points with coordinates up to 1000 it is necessary to compute Ak for 0≤k≤62.

One additional cheap trick is required to make Ak sufficiently small and get a sufficiently fast solution. Given (a,b,c,d), the instance of the problem is equivalent if we change the signs of the coordinates or we change the order of the coordinates. Hence we shall always ``normalize'' the point so that 0≤a≤b≤c≤d. If we do this consistently everywhere in the process, the solution becomes an order of magnitude faster. In particular, this trick guarantees |Ak|≤5000 for all 0≤k≤62.

**Bonus question:** Find an explicit closed form for the elements in Ak for any k. (in this way one can solve the problem also with larger constraints on A,B,C,D; but it is tedious)

