# Tutorial_(en)

Thank you for participating in our contest! We hope you enjoyed it.

[1698A - XOR Mixup](../problems/A._XOR_Mixup.md "Codeforces Round 803 (Div. 2)")

 **Hint**k⊕k=0.

 **Solution**
### [1698A - XOR Mixup](../problems/A._XOR_Mixup.md "Codeforces Round 803 (Div. 2)")

Any element of the array works. Let's use ⊕ for XOR.

Suppose that the original array is [a1,…,an−1]. Then x=a1⊕⋯⊕an−1.

Let's show that a1 is the XOR of all other elements of the array; that is, a1=a2⊕⋯⊕an−1⊕x. Substituting x=a1⊕⋯⊕an−1, we have a1=a2⊕⋯⊕an−1⊕a2⊕⋯⊕an−1. There are two occurences of a2,…,an on the right-hand side and only one occurrence of a1. Since y⊕y=0 for all y, the a2,…,an−1 all cancel out, leaving only a1. 

More formally, we can write the following. a1?=a2⊕⋯⊕an−1⊕x=a2⊕⋯⊕an−1⊕(a1⊕⋯⊕an−1)=a2⊕⋯⊕an−1⊕(a1⊕a2⊕⋯⊕an−1)=(a2⊕⋯⊕an−1)⊕a1⊕(a2⊕⋯⊕an−1)=a1⊕(a2⊕⋯⊕an−1)⊕(a2⊕⋯⊕an−1)=a1.

The same proof follows for any ai. Hence you can output any element of the array.

The time complexity is O(n).

 **Implementation (C++)**[162159711](https://codeforces.com/contest/1698/submission/162159711 "Submission 162159711 by flamestorm")

 **Implementation (Python)**[162158539](https://codeforces.com/contest/1698/submission/162158539 "Submission 162158539 by ScarletS")

[1698B - Rising Sand](../problems/B._Rising_Sand.md "Codeforces Round 803 (Div. 2)")

 **Hint**What happens when two consecutive piles are increased?

 **Solution**
### [1698B - Rising Sand](../problems/B._Rising_Sand.md "Codeforces Round 803 (Div. 2)")

Note that two piles in a row can't be too tall, since a pile that is too tall has strictly more sand than its neighbours.

If k=1 then we can make every other pile too tall, excluding the ends of the array. For example, if a=[1,2,3,4,5,6], we can make piles 2 and 4 too tall by performing some large number of operations on them (say, by making it into [1,10100,3,10100,5,6].) The answer is ⌊n−12⌋.

If k≥2, then note that for any pile, if we perform the operation on it then we perform on one of its neighbours as well. Therefore, if the pile is not too tall initially, then it will never become too tall as a result of these operations, since both a pile and at least one of its neighbours will gain sand. So in this case, doing operations never improves the answer, and so the answer is the number of too tall piles initially.

The time complexity is O(n).

 **Implementation (C++)**[162159774](https://codeforces.com/contest/1698/submission/162159774 "Submission 162159774 by flamestorm")

 **Implementation (Python)**[162158852](https://codeforces.com/contest/1698/submission/162158852 "Submission 162158852 by ScarletS")

[1698C - 3SUM Closure](../problems/C._3SUM_Closure.md "Codeforces Round 803 (Div. 2)")

 **Hint**What happens if there exist i,j,k such that ai+aj+ak>amax?

 **Solution**
### [1698C - 3SUM Closure](../problems/C._3SUM_Closure.md "Codeforces Round 803 (Div. 2)")

Let's consider some array which is 3SUM-closed.

If the array has at least three positive elements, consider the largest three x, y, and z. Notice that x+y+z is strictly larger than x, y, and z, which means that x+y+z is not an element of the array (since x, y, z were the largest elements). Therefore the array has ≤2 positive elements.

Similarly, if the array has at least three negative elements, consider the smallest three x, y, and z. Notice that x+y+z is strictly smaller than x, y, and z, which means that x+y+z is not an element of the array (since x, y, z were the smallest elements). Therefore the array has ≤2 negative elements.

Finally, note that there is no point in having more than 2 zeroes in the array, since any additional zeroes won't change the sums that can be formed. So if there are more than 2 zeroes, we can remove them until there are exactly 2.

It follows that the resulting array has at most 2+2+2=6 elements. This is small, so we can brute force the condition in the problem in O(64) or O(63) time.

The time complexity is O(n+64) or O(n+63), depending on the implementation.

 **Implementation (C++)**[162159874](https://codeforces.com/contest/1698/submission/162159874 "Submission 162159874 by flamestorm")

[1698D - Fixed Point Guessing](../problems/D._Fixed_Point_Guessing.md "Codeforces Round 803 (Div. 2)")

 **Hint**Binary search.

 **Solution**
### [1698D - Fixed Point Guessing](../problems/D._Fixed_Point_Guessing.md "Codeforces Round 803 (Div. 2)")

Note that ⌈log2104⌉=14, which is less than the number of queries. If we can answer a question of the form "given a subarray, does it contain the fixed point?", then we can binary search on this subarray until we find the fixed point.

Given a subarray [al,…,ar], let's count the number of ai such that l≤ai≤r. We claim that if this count is odd, then the subarray contains the fixed point; otherwise, it does not.

First, let's show that each swapped pair either increases the count by 0 or by 2. Suppose that x↔y are swapped (that is, ax=y and ay=x). If ax is in the range from l to r, then l≤y≤r (since ax=y), so ay is also in the range from l to r. Similarly, if ax is not in the range, then neither is ay. So this pair either increases the count by 0 or 2.

Contrarily, the fixed point increases the count by 0 if it is not in the range and 1 if it is. So we can simply look at the parity of the number of elements satisfying the condition, and run our binary search.

The time complexity is O(n).

 **Implementation (C++)**[162159950](https://codeforces.com/contest/1698/submission/162159950 "Submission 162159950 by flamestorm")

 **Implementation (Python)**[162684743](https://codeforces.com/contest/1698/submission/162684743 "Submission 162684743 by ScarletS")

[1698E - PermutationForces II](../problems/E._PermutationForces_II.md "Codeforces Round 803 (Div. 2)")

 **Hint 1**When can you make a into b?

 **Hint 2**To swap ai with i, we need a strength of at least ai−i. Is it enough?

 **Hint 3**The minimum strength needed is maxni=1ai−bi. How can we count the number of solutions?

 **Solution**
### [1698E - PermutationForces II](../problems/E._PermutationForces_II.md "Codeforces Round 803 (Div. 2)")

Suppose that we know the elements of b. We claim that the minimum strength needed is maxni=1ai−bi. Let's prove it.

Proof. For simplicity let's sort the elements of b from 1 to n, and rearrange the corresponding elements of a in the same way. In other words, we only need to turn this new array a into the identity [1,2,…,n].

First note that on the i-th operation, we need to move the number i to the correct position. This is because of the format of the operations; in any future operation, i will not be in the given range, so it is required to move i in the current operation.

Let's look at the number 1. If a1=1, then we don't need any strength. Otherwise, we need ai−1 strength to swap 1 and ai. Afterwards, we can essentially ignore 1 for the rest of the operations, since there is no need to move it again.

In general, there are two cases for when we need to move i to its correct place: 

* ai≥i. In this case, we'll never move ai until the i-th operation, where we swap i and ai. We need a strength of ai−i for that. This is necessary.
* ai<i. In this case, we will swap ai in an earlier operation (since ai<i, so we must swap it to its correct place in the ai-th operation). If we again end up with some smaller number, we will need to swap that before i, and so on. Suppose that after some time, the current element ai in the i-th position is at least i. Then this element must have been swapped with some other element smaller than i (since we only perform swaps with elements smaller than i before the i-th operation). In particular, this element originally started somewhere to the left of i, say at position j<i. Then in the strength calculation, we counted ai−j, which is more than ai−i, i.e. more than we actually need to swap i and ai. This is sufficient.

Hence we only need to check the inequality s≥ai−bi for all i. Now we proceed to the counting part.

Rewrite this as ai−s≤bi. Suppose that k values of bi are missing. Call them [m1,…,mk] in increasing order. Then note that if some element of m satisfies this inequality, all larger elements of m will. In other words, for each ai whose corresponding element of b is missing, some suffix of [m1,…,mk] will work. We can simply binary search to find this suffix for each ai. Let li denote the length of this suffix.

Afterwards, we need to count the number of ways to assign each missing element to an ai. Process the elements greedily, from the ai with the fewest choices to the one with the most (that is, the largest ai to the smallest). The first ai has li choices, the second li−1 (one element of m was already taken), the third li−2, and so on. We can compute this product straightforwardly.

The time complexity is O(nlogn).

 **Implementation (C++)**[162159984](https://codeforces.com/contest/1698/submission/162159984 "Submission 162159984 by flamestorm")

[1698F - Equal Reversal](../problems/F._Equal_Reversal.md "Codeforces Round 803 (Div. 2)")

 **Hint**What's an invariant of the array?

 **Solution**
### [1698F - Equal Reversal](../problems/F._Equal_Reversal.md "Codeforces Round 803 (Div. 2)")

Consider the following invariants of the array: 

* a1 and an don't change as a result of the operations.
* The set of unordered pairs of adjacent elements doesn't change as a result of the operations. In other words, if you build a graph G whose vertices are labelled 1 to n, and make an edge connecting ai and ai+1 for all 1≤i<n, the graph does not change after operations. This is because the operation can be seen as reversing the order we traverse a cycle in G, which doesn't change the undirected graph.

 It turns out that these conditions are necessary and sufficient to determine if a can be turned into b. Let's prove it by fixing the elements of a one at a time.The first element of a already has to match. Suppose the second element does not match; that is, a1=b1 but a2≠b2. Then there has to be some other copy of b1 later in a next to the element in a equal to b2, by the graph condition mentioned above. If the copy of b1 appears after the element equal to b2, we can reverse the subarray whose endpoints are the two copies of b1. Otherwise, it can be shown that there must exist some subarray with equal endpoints that contains b1 followed by b2, so we can reverse it.

This takes 2n operations, but it requires O(n2) time to construct. So the overall complexity is O(n3).

 **Implementation (C++)**[162160016](https://codeforces.com/contest/1698/submission/162160016 "Submission 162160016 by flamestorm")

[1698G - Long Binary String](../problems/G._Long_Binary_String.md "Codeforces Round 803 (Div. 2)")

 **Hint**Polynomials!

 **Solution**
### [1698G - Long Binary String](../problems/G._Long_Binary_String.md "Codeforces Round 803 (Div. 2)")

Ignore leading zeroes of s. We can add them back at the end.

Let's view the string as a polynomial P(x) in GF(2). Then in an operation we can multiply P(x) by any monomial xk for some k, so after some number of operations we can multiply P(x) by some other polynomial Q(x).

At the end, we have a string with two flipped bits. We can in fact make the first character equal to 1 by finding the smallest k such that P(x)Q(x)=xk+1. Such a k exists, because the constant term of P is 1 and Q is arbitrary. Rewrite this as xk≡1(modP(x)). Now it's clear that the answer is a divisor of the order of x in P(x).

We can use polynomial factoring algorithms or baby-step-giant-step and meet in the middle. The time complexity is O(2|s|/2|s|2) or O(2|s|/2|s|).

 **Implementation (C++)**[162160053](https://codeforces.com/contest/1698/submission/162160053 "Submission 162160053 by flamestorm")

