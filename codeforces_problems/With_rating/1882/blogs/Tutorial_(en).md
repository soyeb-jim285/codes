# Tutorial_(en)

[1882A - Increasing Sequence](../problems/A._Increasing_Sequence.md "Codeforces Round 899 (Div. 2)")

 **Tutorial**Greedy solution. Continue constructing b as small as possible.

If a1=1, b1=2. Else, b1=1.

For i≥2, if ai=bi−1+1, bi=bi−1+2. Else, bi=bi−1+1.

bn calculated by this process is the answer.

Time complexity is O(n) per test case.

[1882B - Sets and Union](../problems/B._Sets_and_Union.md "Codeforces Round 899 (Div. 2)")

 **Something to say**Sorry for everyone who got FSTs :( We tried our best to make pretest strong especially for this problem, but it wasn't enough.

 **Hint 1**Denote T=S1∪S2∪⋯∪Sn, then S⊂T. Since S≠T, i∈T and i∉S for some i.

 **Hint 2**Given an integer i, can you calculate the maximum size of S, such that i∉S?

 **Tutorial**i∈T and i∉S for some i. Here 1≤i≤50. 

For fixed i, select of all the sets among S1,S2,⋯,Sn which don't contain i. Size of their union will be the maximum size of S such that i∉S.

If we do this for all i in T, maximum of them is the answer.

Time complexity is O(N⋅max(si,j)2).

[1882C - Card Game](../problems/C._Card_Game.md "Codeforces Round 899 (Div. 2)")

 **Hint 1**Fix the topmost card you'll pick in the initial deck.

 **Tutorial**Let's denote i-th card in the initial deck as card i.

Let the topmost card you'll pick in the initial deck as card i.

For all cards under card i in initial deck, you can choose all and only cards with the positive value at odd index.

Proof: Here is the strategy. Before you pick card i, if positive card(under card i in initial deck) in odd index exists, choose it. Repeat this until all positive cards(under card i in initial deck) are in even index. Then if you choose card i, all index of positive cards(under card i in initial deck) will be decreased by 1, and will become odd. Now, choose them from the bottom to top, so that the choosing won't change the other positive cards' index.

Denote prfj as the sum of positive numbers among aj,aj+1,⋯,an, and prfn+1=0. Since prfj=prfj+1+max(0,aj), prf can be calculated in O(n). 

You should necessarily pick card i in index of i, and can pick all positive cards under card i in initial deck, so your maximum final score will be (i%2==1?ai:0)+prfi+1.

The answer is max((i%2==1?ai:0)+prfi+1|1≤i≤n).

There are lots of other solutions too.

[1882D - Tree XOR](../problems/D._Tree_XOR.md "Codeforces Round 899 (Div. 2)")

 **Hint 1**Try to solve the problem for single root.

 **Hint 2**For any vertex v which isn't the root, denote parv as the parent of v. Then value of av⊕aparv only changes if we perform the operation on v.

 **Hint 3**Since x1⊕x2⊕⋯⊕xm≤x1+x2+⋯+xm for any numbers x1,x2,⋯,xm, we can assume that there is at most operation performed in same vertex.

 **Tutorial**Let's solve the problem for single root first.

Denote the operation in the statement as op(v,c), and size of v's subtree as sv.

The goal is to make av⊕aparv=0 for every non-root vertex v. This value is changed only when we select v. To make av⊕aparv to 0, we should perform op(v,av⊕aparv) (Look Hint 3).

Therefore, the answer sill be ∑i!=rootsi×(ai⊕apari). Now our task is to calculate this for all roots. This can be done by lots of ways, and the following algorithm is one way.

Calculate the answer for 1 as root first in O(n). Now, we will traverse the tree starting at vertex 1 and keep updating the answer. If root changes from q to r (q and r are adjacent), every vertex except q and r will have same parents and subtree size, so will contribute same to the answer, so we only need to consider q and r to calculate the change. Edge connecting q and r will divide the tree into parts: each of size X and Y. If root changes q to r, Y×(aq⊕ar) will be subtracted, and X×(aq⊕ar) will be added to the answer. X and Y can be pre-calculated in O(n), so this update costs O(1).

Since changing root into the adjacent vertex costs O(1), answer for all roots can be calculated in O(n).

[1882E1 - Two Permutations (Easy Version)](../problems/E1._Two_Permutations_(Easy_Version).md "Codeforces Round 899 (Div. 2)")

 **Hint 1**Let's think two permutations independently. The goal is to make sequence of operations for each permutation which have same parity of number of operations.

 **Hint 2**Try to sort single permutation of length N, using at most 3N operations. It is always possible.

 **Hint 3**If the permutation's length is odd, you can perform operation at index 1 for N times and return to the same permutation.

 **Hint 4**If the permutation's length is even, the parity of inversion number changes in each operations.

 **Tutorial**Hints above were the summary of the tutorial. Please check them.

First, let's do Hint 2. There are lots of ways to do this, and I'd like to introduce one which I thought first. It is possible to swap two elements using 3 operations. Let's denote the two elements as x and y, and permutation as [[A]x[B]y[C]] ([A],[B],[C] are subarrays). Then:

 1. Perform the operation at x. Permutation becomes [[B]y[C]x[A]].
2. Perform the operation at y. Permutation becomes [[C]x[A]y[B]].
3. Perform the operation at x. Permutation becomes [[A]y[B]x[C]].

Using this, we can sort the single permutation of length N using at most 3N operations, since we can sort the permutation by N swaps.

If this requires same parity of number of operations for p and q, the problem is solved. At most 3max(m,n) operations are used.

Else, if n or m is odd, we can make the parity equal by method provided in Hint 3. At most 4max(m,n) operations are used.

Else, then n and m is both even. In this case, it's impossible because of Hint 4.

The overall time complexity is O(n+m) in this solution.

Lastly, here is the proof of Hint 4.

Proof: Let's consider the permutation of length N(N is even). Denote the permutation as [[A]x[B]], and the length of [A] and [B] as nA and nB. Here nA+nB=N−1 so one of nA and nB is even and one of them is odd. Permutation becomes [[B]x[A]] after the operation.

First, the parity of inversion number from two elements of [A] or two elements of [B] doesn't change, because their order inside doesn't change.

Second, the parity of inversion number from one element of [A] and one element of [B] doesn't change, because sum of them are nA×nB, which is even.

Third, the parity of inversion number from x and one element of [A] or [B] changes, because sum of them are nA+nB, which is odd.

If we add these three, we can lead to the conclusion that the parity of inversion number must change. The text may look a bit complicated, but it will not be that hard if you write them in your own :)

[1882E2 - Two Permutations (Hard Version)](../problems/E2._Two_Permutations_(Hard_Version).md "Codeforces Round 899 (Div. 2)")

Special thanks to [kizen](https://codeforces.com/profile/kizen "Grandmaster kizen") providing an key idea which motivated me to make this problem!

 **Hint 1**The solution is completely different from E1. A brilliant idea is required. Maybe the fact that checker is implemented in linear time might be the hint.

 **Hint 2**Find a way changing the operation to 'swap'.

 **Hint 3**Add an extra character.

 **Tutorial**Add an extra character 'X' in front of the permutation. Here position of X won't be changed by the operation, and will always locate at left of p1. Then in each operation, the permutation will change as: [X[A]c[B]]→[X[B]c[A]].

Now, let's consider the array made by X and permutation as **circular**. This is possible because X is always in left of 1st element, so it marks the start of the permutation. Then [X[B]c[A]] is equivalent with [c[A]X[B]].

Then the operation is: [X[A]c[B]]→[c[A]X[B]], which is same with swapping X and c.

Now we need to calculate the minimum odd number of swaps and even number of swaps(of X and any element) each, turning [Xp1p2⋯pn] to one of [X12⋯n], [nX12⋯(n−1)], [(n−1)nX1⋯(n−2)], ⋯, [12⋯nX].

To calculate the minimum number of swaps required to turn [Xp1p2⋯pn] to the given array, first renumber the initial array to [X12⋯n], then change the given array in the same correspondence. Do permutation cycle decomposition. Then the answer is (sum of (size + 1) for cycles which have size ≥ 2 and don't contain X) + (X's cycle size − 1). This can be proven easily by counting the number of elements which go into the proper place in each operations.

Calculate this for all [X12⋯n], [nX12⋯(n−1)], [(n−1)nX1⋯(n−2)], ⋯, [12⋯nX]. Since we can't make the same array using different parity of number of swaps, we can achieve the goal by calculating the minimum odd number and minimum even number each.

The overall time complexity is O(n2+m2).

 **Challenge**Try solving E1 in n,m≤105, using at most 1.5×105 operations. It is solvable :)

