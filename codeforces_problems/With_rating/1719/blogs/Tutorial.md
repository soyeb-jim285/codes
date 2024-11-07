# Tutorial

Sorry for not very good samples, and late editorial. It was our first round, so it was wary stressful for us, But we hope you liked the problems despite this!

[1719A - Chip Game](../problems/A._Chip_Game.md "Codeforces Round 814 (Div. 2)")

 **Hint 1**Try to look at the parity of n,m.

 **Hint 2**The player who wins does not depend on player's strategy.

 **Hint 3**The only thing that the winning player depends on is the parity of n,m.

 **Tutorial**Note that the game will end only when the chip is in the upper right corner (otherwise you can move it 1 square to the right or up). For all moves, the chip will move n−1 to the right and m−1 up, which means that the total length of all moves is n+m−2 (the length of the move is how much the chip moved per turn). Since the length of any move is odd, then after any move of Burenka, the sum of the lengths will be odd, and after any move of Tonya is even. So we can find out who made the last move in the game by looking at (n+m−2)mod2=(n+m)mod2. With (n+m)mod2=0, Tonya wins, otherwise Burenka.

The complexity of the solution is O(1).

[1719B - Mathematical Circus](../problems/B._Mathematical_Circus.md "Codeforces Round 814 (Div. 2)")

 **Hint 1**Instead of k, we can consider the remainder of dividing k by 4.

 **Hint 2**There is no answer for the remainder 0.

 **Hint 3**For all other remainders, there is an answer.

 **Tutorial**Note that from the number k we only need the remainder modulo 4, so we take k modulo and assume that 0≤k≤3.

If k=0, then there is no answer, because the product of the numbers in each pair must be divisible by 4=22, that is, the product of all numbers from 1 to n must be divisible by 2n2⋅2=2n, but the degree of occurrence of 2 in this sum is ⌊n2⌋+⌊n4⌋, which is less than n.

If k=1 or k=3, then we will make all pairs of the form (i,i+1), where i is odd. Then a+k will be even in each pair, since a and k are odd, and since b is also even, the product will be divisible by 4. Если k=2, then we will do the same splitting into pairs, but in all pairs where i+1 is not divisible by 4, we will swap the numbers (that is, we will make a=i+1 and b=i). Then in pairs where i+1mod4=0, b is divisible by 4 (therefore the product too), and in the rest a+k is divisible by 4 (since a and k have a remainder 2 modulo 4).

The complexity of the solution is O(n).

[1719C - Fighting Tournament](../problems/C._Fighting_Tournament.md "Codeforces Round 814 (Div. 2)")

 **Hint 1**Who would win duels if the strongest athlete was the first in queue?

 **Hint 2**After what number of rounds is the strongest athlete guaranteed to be at the front of the queue?

 **Hint 3**Simulate the first n rounds and write down their winners so that for each person you can quickly find out the number of wins in rounds with numbers no more than a given number.

 **Tutorial**Note that after the strongest athlete is at the beginning of the queue, only he will win. The strongest athlete will be at the beginning of the queue no more than after the n-th round. Let's simulate the first n rounds, if the j-th athlete won in the i-th round, then we will write down the i number for him. Now, to answer the query (i,k), it is enough to find the number of wins of the i athlete in rounds with numbers j≤k, and if k>n, and the strength of the i athlete is equal to n, then add to the answer another k−n.

The complexity of the solution is O(n+qlog(n)).

[1718A2 - Burenka and Traditions (hard version)](https://codeforces.com/contest/1718/problem/A2 "Codeforces Round 814 (Div. 1)")

 **Hint 1**Segments of length greater than 2 are not needed.

 **Hint for A1 1**For A1 you can use dynamic programming

 **Hint for A1 2**Dynamic programming where dp[i][v] means the minimum time to make aj=0 for j<i and ai=v. (Notice that v can be any number from 0 to 8191)

 **Hint 2**There is an answer in which segments of length 2 does not intersect with segments of length 1.

 **Hint 3**If al⊕al+1⊕…⊕ar=0 is executed for l,r, then we can fill this segment with zeros in r−l seconds using only segments of length 2.

 **Tutorial**There is an answer where the time spent is minimal and the lengths of all the segments taken are 1 and 2. because of the segment l,r,x can be replaced to ⌈r−l+12⌉ of segments of length 2 and 1, or rather [l,l+1,x],[l+2,l+3,x],…,[r,r,x](or [r−1,r,x] if (l−r+1) even).

Note that if al⊕al+1⊕…⊕ar=0 is executed for l,r, then we can fill the l,r subsections with zeros for r−l seconds with queries [l,l+1,al],[l+1,l+2,al⊕al+1],...[r−1,r,al⊕al+1⊕…⊕ar].

Note that if a segment of length 2 intersects with a segment of length 1, they can be changed to 2 segments of length 1.

It follows from all this that the answer consists of segments of length 1 and cover with segments of length 2. Then it is easy to see that the answer is (n minus (the maximum number of disjoint sub-segments with a xor of 0)), because in every sub-segments with a xor of 0 we can spend 1 second less as I waited before. this amount can be calculated by dynamic programming or greedily. Our solution goes greedy with a set and if it finds two equal prefix xors(prefixl=prefixr means that al+1⊕al+2⊕…⊕ar=0), it clears the set. [168724728](https://codeforces.com/contest/1718/submission/168724728 "Submission 168724728 by GoreMneGore")

The complexity of the solution is O(nlog(n)).

[1718B - Fibonacci Strings](https://codeforces.com/contest/1718/problem/B "Codeforces Round 814 (Div. 1)")

 **Common hint**Try to express n(the sum of all ci) as F1+F2+…+Fm=n.

 **The way of mathematicians****Hint for mathematicians 1**Let, n=F1+F2+…+Fm, then try to find the minimum x starting from which if there is ci=x there is no answer.

 **Hint for mathematicians 2**x is (the maximum sum of the Fibonacci numbers, among which there are no neighbors) + 1.

 **Hint for mathematicians 3**x is F1+F3+F5+…+Fm+1 for odd m and F2+F4+F6+…+Fm+1 for even.

 **Hint for mathematicians 4**x is Fm+1+1 for odd m and Fm+1 for even.

 **Hint for mathematicians 5**Try to understand if it can happen that there are two different answers in which the letter forming the block of length Fm differs.

 **Hint for mathematicians 6**The correct answer is: yes if there is ci=Fm and cj=Fm and this is only way.

Now, using everything you have understood, write a greedy solution.

 **The way of programmers****Hint for programmers 1**Try to write a greedy solution.

 **Hint for programmers 2**The programmer does not need a second hint, he wrote a greedy solution after the first one.

 **Tutorial**At the beginning, let's check that the number n (the sum of all ci) is representable as the sum of some prefix of Fibonacci numbers, otherwise we will output the answer NO.

Let's try to type the answer greedily, going from large Fibonacci numbers to smaller ones. For the next Fibonacci number, let's take the letter with the largest number of occurrences in the string from among those that are not equal to the previous letter taken (to avoid the appearance of two adjacent blocks from the same letter, which cannot be). If there are fewer occurrences of this letter than this number, then the answer is NO. Otherwise, we will put the letter on this Fibonacci number and subtract it from the number of occurrences of this letter.If we were able to dial all the Fibonacci numbers, then the answer is YES.

Why does the greedy solution work? Suppose at this step you need to take Fi (I will say take a number from ct, this will mean taking Fi letters t from string), let's look at the maximum cx now, if it cannot be represented as the sum of Fibonacci numbers up to Fi among which there are no neighbors, then the answer is no. It can be proved that if cx>Fi+1, then it is impossible to represent cx.

If there is exactly one number greater than or equal to Fi at the step, then there is only one option to take a number, so the greedy solution works.

If there are two such numbers and they are equal, then the option to take a number is exactly one, up to the permutation of letters. the greedy solution works again.

If there are cj≥Fi,cx≥Fi,j≠x, then we note that the larger of the numbers cj,cx will be greater than Fi, if we don't take it, then at the next step this number will be greater than Fi+1 (i will be 1 less), according to the above proven answer will not be, so, taking the larger of the numbers is always optimal. 

The complexity of the solution is O(klog(n)log(k)).

[1718C - Tonya and Burenka-179](https://codeforces.com/contest/1718/problem/C "Codeforces Round 814 (Div. 1)")

 **Hint 1**The answer for k=x and k=gcd(x,n) is the same.

 **Hint 2**In this problem, a general statement is useful: for any array c of length m, m⋅max(c1,c2,…,cm)≥c1+c2+…+cm is true.

 **Hint 3**Try applying the second hint for k1 and k2 divisible by k1, where k1,k2 are divisors of n.

 **Hint 4**We can consider only k which equals to np, where p is a simple divisor of n.

 **Tutorial**Let's note that the answer for k=x and k=gcd(x,n) is the same.

Indeed, for the number k, we will visit numbers with indices s+ikmodn for i from 0 to n−1 inclusive, from this we can see that the index of the i-th number coincides with the index of i+ngcd(k,n), and if we look at two indexes, the difference between which is l and l<ngcd(k,n), then they are different, since k⋅lmodn≠0, therefore, the answer is (the sum of numbers with indices s+ikmodn for i from 0 to ngcd(k,n)−1) ⋅gcd(k,n).

Now let's prove that the first gcd(k,n) numbers are the same for (s,x) and (s,gcd(x,n)), note that only those indices that have the same remainder as s when divided by gcd(x,n) are suitable, but there are only ngcd(k,n) of such indices, and we proved that we should have ngcd(k,n) of different indices, so they are all represented once, therefore the answer for k=x and k=gcd(x,n) is the same, because the sum consists of the same numbers.

So, we need to consider only k being divisors of n, this is already passes tests if we write, for example, a segment tree, but we don't want to write a segment tree, so we go further, prove that for k1=x, the answer is less or equal than for k2=x⋅y if k1 and k2 are divisors of n, why is this so?

Note that for the number k, the answer beats for gcd(k,n) groups of numbers, so that in each group there is exactly ngcd(k,n) and each number is in exactly one group, and for different s the answer will be (the sum in the group that s belongs to) ⋅gcd(k,n).

Let's look at the answer for the optimal s for k1, let's call the set at which it is reached t, note that in k2 for different s there are m independent sets that are subsets of t. Let mi be the sum in the i-th set. Now note that we need to prove max(m1,m2,…,my)∗y≥m1+m2+…my this is true for any mi, easy to see.

So you need to iterate the divisors which equals to np where p is prime, now it can be passed with a set. Hurray!

For the divisor d, it is proposed to store answers for all pairs (s,d), where s≤nd and the maximum among them, they can be counted initially for O(nlogn) for one d, each request is changing one of the values, this can be done for O(logn).

The complexity of the author's solution is O(6⋅nlog(n)), where 6 is the maximum number of different prime divisors of the number n.

[1718D - Permutation for Burenka](https://codeforces.com/contest/1718/problem/D "Codeforces Round 814 (Div. 1)")

 **Hint 1**Try to reduce the task to a single array and tree.

 **Hint 2**Try to reduce the tree to a match of bipartite graph.

The first part: For each ai=0, a segment of suitable values.

The second part: The set S and the number d.

 **Hint 3**There exist L and R such that the answer to the query is ''YES'' if and only if L≤d≤R.

 **Tutorial**Let's build a tree recursively starting from the segment [1,n], at each step we will choose the root of the subtree v=argmax([pl,pl+1…,pr])+l−1, then recursively construct trees for subtrees [l,v−1],[v+1,r] if they are not empty, then create edges from the root to the roots of these subtrees. What we got is called a Cartesian tree by array. This Cartesian tree will be mentioned further in the analysis.

It is easy to see that Cartesian trees by arrays coincide if and only if these arrays are similar. Then the necessary and sufficient condition for the array a to be similar to p is that for any pair u,v such that u is in the subtree v, av>au is satisfied, in other words av is the maximum among the numbers in the subtree of the vertex v.

Let's call the position i initially empty if initially ai=0.

Let's call an array a almost similar to p if for any pair u,v such that u is in the subtree v, av>au is executed, **or both** positions u, v are initially empty.

Let's prove that if there is a way to fill in the gaps in a to get an array almost similar to p, then there is also a way to fill in the gaps to get a similar to p array a.

Indeed, let's look at the a array almost similar to p. let's walk through the tree recursively starting from the root. At the step with the vertex v, we first start recursively from all the children of v, now it is true for them that the maxima of their subtrees are in them, let's look at the maximum child v, let it be u, then if av>au, then everything is fine, otherwise av<au note that v is initially an empty position, because for all initially non-empty positions it is true that they are maximums in their subtrees (this is easy to see in the definition), but v is not. Note that u is initially an empty position. Otherwise, we have never changed av and au, therefore, in the original array a almost similar to p, av>au contradiction was executed, it is contradiction. so v,u are initially empty, we can perform swap(av,au) and everything will be executed.

After executing this algorithm, we changed only the initially empty elements and got a similar to p. Q.E.D.

How to check the existence of an array almost similar to p? Let's call the number ri the minimum among all the numbers av such that i is in the subtree of v. Let's call the number li the maximum among all the numbers av such that v is in the subtree of i. it is easy to see that a is almost similar to p if and only if for all i, li<ai<ri is satisfied.

That sounds incredibly good. So, all we need is to find a matching of the set S and number d and segments [li,ri] for i that are initially empty. Now it is easy to prove that the suitable d is a continuous segment (let's say the answer is yes for d1, we don't know the answer for d2, try looking at the alternating path from d1 to d2 in good matching for d1, it's easy to see that if there is such a path, then for d2 the answer is yes, otherwise, no. If you look at the structure of the matching of points with segments, you can see that an alternating path exists for a continuous segment of values d2). the boundaries can be found by binary search or by typing greedily twice.

Final complexity is O(nlogn) or O(nlog2n)

[1718E - Impressionism](https://codeforces.com/contest/1718/problem/E "Codeforces Round 814 (Div. 1)")

 **Hint 1**you can notice that a pair of operations 1ij, 2kt and 2kt, 1ij lead to the same result, what does this mean?

 **Hint 2**This means that operations can be represented as two permutations describing which swaps will occur with rows and which swaps will occur with columns.

 **Hint 3**Try to reduce this problem to a graph isomorphism problem.

 **Tutorial**Let's have two permutations: p of length n and q of length m. Initially, both permutations are identical. For operation 1ij, we will execute swap(pi,pj), for operation 2ij we will execute swap(qi,qj). It is easy to see that after performing all operations in the position i,j will be api,qj.

Now we need to find permutations of p,q so that api,qj=bi,j.

Let's look at a bipartite graph where the first part is rows and the second is columns. Let if ai,j≠0, then from i there is an undirected edge in j of the color ai,j. if we construct the same graph for b, then we need to check for isomorphism two bipartite graphs, each edge of which has a color, and as we remember, by the condition of the vertex, 2 edges of the same color cannot be Incidence. Let's call them graph a and graph b.

This problem is largely for implementation, therefore, starting from this moment, the actions that you can observe in the author's solution are described [168728958](https://codeforces.com/contest/1718/submission/168728958 "Submission 168728958 by GoreMneGore").

Let n<m otherwise let's swap n and m in places. Let's try to match the elements of the array a to the elements of the array b. Let's go through the indices from 1 to n. Let's now choose which pair of b to choose for the i-th vertex of the first fraction of the graph a. If we have already found a pair earlier, skip the step, otherwise let's sort out the appropriate option for the pair among all the vertices of the first component b that do not yet have a pair, there are no more than n, after the vertices are matched, the edges are also uniquely matched (because there are no 2 edges of different colors), let's then run the substitution recursively for edges (if we have mapped the vertex v to the vertex u and from v there is an edge of color x in i, and from u there is an edge x in j, then it is easy to prove that in the answer i will be mapped to j), which means we will restore the entire component. Let the sum of the number of vertices and the number of edges in the component be k, then we will perform no more than n⋅k actions to restore the component.

by permutations, getting a sequence of swaps is a matter of technique, I will not explain it, but this is a separate function in the author's solution you will understand.

in total, our solution works for O(n(n⋅m+n+m)) or O(min(n,m)(n⋅m+n+m)), where n⋅m+n+m is the total number of vertices and edges in all components.

feel free to ask any questions

[1718F - Burenka, an Array and Queries](https://codeforces.com/contest/1718/problem/F "Codeforces Round 814 (Div. 1)")

 **Hint**The only one hint to this problem is don't try to solve, it's not worth it.

 **Tutorial**In order to find the number of numbers from 1 to C that are mutually prime with x, we write out its prime divisors (various). Let these be prime numbers a1,a2,…,ak. Then you can find the answer for 2k using the inclusion-exclusion formula.

Because ⌊ab⋅c⌋=⌊⌊ab⌋c⌋, a similar statement is made for k numbers (you can divide completely in any order).

Let's split the primes up to 2×104 into 2 classes — small (≤42) and large (the rest). There are 13 small numbers, and 2249 large ones. Separately, we will write down pairs of large numbers that in the product give a number not exceeding 105. There will be 4904 such pairs.

Let's match each set of small primes with a mask. Let's write dp[mask] — alternating sum over the mask submasks of numbers ⌊Ca1⋅a2⋅…⋅ak⌋, where a1,…,ak — prime numbers from the submask. Similarly, we define dp[mask][big] (in addition to the mask, there is a large prime big) and dp[mask][case] (in addition to the mask, there are a pair of primes from a pair of large primes case). Each dp can be counted for states×bits, where states — is the number of states in dp, and bits — is the mask size (number of bits).

If we write out all the large primes on the segment for which mask — mask of small primes, the answer for this segment will be the sum of dp[mask]+∑dp[mask][bigi]+∑dp[mask][casei] (for big and case lying on the segment). Thus, the request can be answered in 7000 calls to dp.

In order to find a set of prime numbers on a segment, you can use the MO algorithm.

Final complexity is O(n√n+q×(π(m)+casesCount(C)))

It is worth noting that (with a very strong desire) it is possible to further optimize the solution using avx, to speed up the calculation of the amount by submasks in dynamics by 16 times, to speed up the calculation of the amount of dp[mask][big] by 8 times, which will allow you to answer the request in ~5000 (instead of 7000) calls to dp, and the pre-calculation for 4⋅107 instead of 7⋅108 (in fact, the pre-calculation works much faster due to compiler optimizations).

Please rate the problems, it will help us make the problems better next time!

 **Problem Feedback**You can choose one best problem, or not choose if you think there is no such task.

 **div2A*** The best problem 


[*5*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*108*](https://codeforces.com/data/like?action=like "I like this")
* Mid problem 

 
[*22*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*11*](https://codeforces.com/data/like?action=like "I like this")
 **div2B*** The best problem 

 
[*4*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*90*](https://codeforces.com/data/like?action=like "I like this")
* Mid problem 

 
[*35*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*13*](https://codeforces.com/data/like?action=like "I like this")
 **div2C*** The best problem 

 
[*43*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*83*](https://codeforces.com/data/like?action=like "I like this")
* Mid problem 

 
[*22*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*14*](https://codeforces.com/data/like?action=like "I like this")
 **div2D/div1A*** The best problem 

 
[*55*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*94*](https://codeforces.com/data/like?action=like "I like this")
* Mid problem 

 
[*9*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*21*](https://codeforces.com/data/like?action=like "I like this")
 **div2E/div1B*** The best problem 

 
[*12*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*43*](https://codeforces.com/data/like?action=like "I like this")
* Mid problem 

 
[*42*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*21*](https://codeforces.com/data/like?action=like "I like this")
 **div2F/div1C*** The best problem 

 
[*13*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*21*](https://codeforces.com/data/like?action=like "I like this")
* Mid problem 

 
[*22*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*32*](https://codeforces.com/data/like?action=like "I like this")
 **div1D*** The best problem 

 
[*4*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*22*](https://codeforces.com/data/like?action=like "I like this")
* Mid problem 

 
[*2*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*5*](https://codeforces.com/data/like?action=like "I like this")
 **div1E*** The best problem 

 
[*16*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*9*](https://codeforces.com/data/like?action=like "I like this")
* Mid problem 

 
[*1*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*3*](https://codeforces.com/data/like?action=like "I like this")
 **div1F*** The best problem 

 
[*10*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*8*](https://codeforces.com/data/like?action=like "I like this")
* Mid problem 

 
[*5*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*35*](https://codeforces.com/data/like?action=like "I like this")
