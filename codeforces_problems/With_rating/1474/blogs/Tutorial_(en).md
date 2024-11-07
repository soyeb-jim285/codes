# Tutorial_(en)

Thank you for participating in the contest! I hope you enjoyed the tasks. Here is an editorial with hints.

[1474A - Puzzle From the Future](../problems/A._Puzzle_From_the_Future.md "Codeforces Round 696 (Div. 2)")

 **Hint 1**Hint 1: Should we always make first digit of d not equal to 0? How can we do it?

 **Hint 2**Hint 2: Try to choose such a that d will have n digits.

 **Editorial**
### [1474A - Puzzle From the Future](../problems/A._Puzzle_From_the_Future.md "Codeforces Round 696 (Div. 2)")

Hint 1: Should we always make first digit of d not equal to 0? How can we do it?

Hint 2: Try to choose such a that d will have n digits.

At first, we can make the first digit of d not equal to 0 by setting 1 to the first digit of a. Now we say that d doesn't have leading zeroes. In this case, more digits d has — the larger d is. It turns out, we can always construct d of length n if we make each consecutive pair of digits different.

In other words, we want to select ai in order to make ai−1+bi−1≠ai+bi for all i>1. Since we want to maximize ai+bi, if ai=1 satisfies ai−1+bi−1≠ai+bi we take ai=1. Otherwise, ai=0 satisfies this condition.

Time complexity is O(n).

 **Solution**[104840922](https://codeforces.com/contest/1474/submission/104840922)

[1474B - Different Divisors](../problems/B._Different_Divisors.md "Codeforces Round 696 (Div. 2)")

 **Hint 1**Hint 1: Integer have exactly 4 divisors, if it is of form pq or p3 for some primes p and q. In the first case it have divisors 1, p, q, pq. In the second case it have divisors 1, p, p2, p3.

 **Hint 2**Hint 2: Instead of finding integer with at least 4 divisors, find integer with exactly 4 divisors.

 **Hint 3**Hint 3: Let p be the smallest prime factor of a. Then, p≥d+1.

 **Editorial**
### [1474B - Different Divisors](../problems/B._Different_Divisors.md "Codeforces Round 696 (Div. 2)")

Hint 1: Integer have exactly 4 divisors, if it is of form pq or p3 for some primes p and q. In the first case it have divisors 1, p, q, pq. In the second case it have divisors 1, p, p2, p3.

Hint 2: Instead of finding integer with at least 4 divisors, find integer with exactly 4 divisors.

Hint 3: Let p be the smallest prime factor of a. Then, p≥d+1.

Solution:

Suppose, we have integer a with more than 4 divisors (and satisfies the other condition). If a has at least two different prime factors, we can throw out all other prime factors and get a smaller number with at least 4 divisors. Otherwise, a=pk for some k>3. p3 will also have 4 divisors and it will be smaller than a. When we throw out a prime factor, no new divisors will appear, so the difference between any two of them will be at least d.

Let's find smallest integers of form p3 and pq (p<q) independently.

In the first case, p3−p2>p2−p>p−1, because p≥2. If we will find the smallest p≥d+1 all conditions will be satisfied.

In the second case, 1<p<q<pq. Let's find the smallest p≥d+1 and the smallest q≥d+p. In this case it is easy to see that p−1≥d and q−p≥d. Also, pq−q=q(p−1)≥qd≥d since q≥2. It is enough to get OK even without checking case a=p3.

Also we should prove that there cannot exist p′ and q′ such that p′q′<pq. It is true because p′ should be at least d+1 and it should be prime, but p is the smallest prime greater than d, so p′≥p. And q′ should be at least p+d and we can prove that q′≥q in the same way.

Time complexity is O(t⋅gap⋅primecheck), where gap is difference between primes and O(loga) in average and primecheck is complexity of your prime check and usually is O(√a).

Answer for d=10000 is near to 2⋅108, so naive solution with factorization of each number shouldn't pass, but it is possible to precompute answers for all values of d by that solution (in this case, you should run solution once for all values of d, not once for each value of d).

 **Solution**[104840809](https://codeforces.com/contest/1474/submission/104840809)

[1474C - Array Destruction](../problems/C._Array_Destruction.md "Codeforces Round 696 (Div. 2)")

 **Hint 1**Hint 1: How does x changes after each operation?

 **Hint 2**Hint 2: Suppose, that you know x. What pairs of elements can you throw out now?

 **Hint 3**Hint 3: Suppose, that you did some operations. Note, that if you have integer b that is greater or equal to x and b is still in array a, you can't remove b from a, thus you can't throw out all elements of a.

 **Hint 4**Hint 4: You don't know x only before the first operation and n≤1000.

 **Editorial**
### [1474C - Array Destruction](../problems/C._Array_Destruction.md "Codeforces Round 696 (Div. 2)")

Hint 1: How does x changes after each operation?

Hint 2: Suppose, that you know x. What pairs of elements can you throw out now?

Hint 3: Suppose, that you did some operations. Note, that if you have integer b that is greater or equal to x and b is still in array a, you can't remove b from a, thus you can't throw out all elements of a.

Hint 4: You don't know x only before the first operation and n≤1000.

Solution:

Since all integers are positive, x=c+d→c,d<x, thus x decreaces after each operation.

Suppose that we have integers ai≤aj≤ak in our array. If we throw out ai+aj=x, x becomes equal aj≤ak and we can't throw out ak any time later. So, we should throw out the biggest element of array on each operation.

If we know x and the biggest element of array, we can easily determine the second element we throw out on this operation. 

We can try all possibilities of the second element of array we throw out on the first operation. x will become equal the biggest element of initial array. After that we put all other elements in multiset S and just simulate opertations by taking max from S and x−max (if it doesn't exists, we can't throw out all elements) and replacing x with max.

Total time complexity: O(n2⋅logn).

There is also a solution without set, that runs in O(n2+maxA).

 **Solution**[Solution with set](https://codeforces.com/contest/1474/submission/104840760)

[Solution without set](https://codeforces.com/contest/1474/submission/104845408)

[1474D - Cleaning](../problems/D._Cleaning.md "Codeforces Round 696 (Div. 2)")

 **Hint 1**Hint 1: How to solve the promblem if we are not allowed to use a superabilty (in linear time)?

 **Hint 2**Hint 2: Look at the first pile. There is only one way to remove stone from the first pile.

 **Hint 3**Hint 3: If you swap i-th and (i+1)-th piles of stones, nothing changes in way you remove stones from 1-st, 2-nd, …, (i−2)-th piles.

 **Hint 4**Hint 4: Look at the problem from the both sides: from the beginning of a and from the end of a.

 **Editorial**
### [1474D - Cleaning](../problems/D._Cleaning.md "Codeforces Round 696 (Div. 2)")

Hint 1: How to solve the promblem if we are not allowed to use a superabilty (in linear time)? 

Hint 2: Look at the first pile. There is only one way to remove stone from the first pile.

Hint 3: If you swap i-th and (i+1)-th piles of stones, nothing changes in way you remove stones from 1-st, 2-nd, …, (i−2)-th piles.

Hint 4: Look at the problem from the both sides: from the beginning of a and from the end of a.

Solution:

We can check, whether we can remove all stones without a supeability using the following algorithm:

* How can we remove the stones from the 1-st pile? Only with stones from the second pile! If a1>a2, then we can't remove all stones from the 1-st pile.
* Now we have 0 stones in the 1-st pile and a2−a1 stones in the 2-nd pile. We can apply the idea above and get that we should have a2−a1 stones in the 3-rd pile....
* In the end we have only 1 pile. If there are any stones in it, we can't remove all stones. Otherwise, we constructed a solution for removing all stones.

Also, we profed that there can be only one way to remove all stones.

Now we have to improve this algorithm. Let pi be a number of stones in the i-th pile after cleaning piles 1, 2, ..., i−1 using this algorithm (and (i+1)-th, (i+2)-th, ..., n-th piles have the initial amount of stones). Now, let si be a number of stones in the i-th pile, if we removed all stones from the (i+1)-th, ..., n-th piles (using the same algorithm, but we do operations in reversed order).

We compute all pi and all si in O(n). Now, if we try to swap i-th and (i+1)-th piles, we should check, that we can remove stones from four piles: pi−1, ai+1, ai, si+2. If we can do this for any i, answer is YES.

 **Solution**[104840665](https://codeforces.com/contest/1474/submission/104840665)

[1474E - What Is It?](../problems/E._What_Is_It_.md "Codeforces Round 696 (Div. 2)")

 **Hint 1**Hint 1: How many operations will robot make in the worst case?

 **Hint 2**Hint 2: How many times can robot spend (n−1)2 time on 1 operation?

 **Hint 3**Hint 3: How many times can robot spend (n−2)2 time on 1 operation? It is easyer to think about number of operations with time greater or equal to (n−2)2.

 **Hint 4**Hint 4: Instead of operation from the statement we can apply the following operation to q which is initially an identity permutation:

 * Select i such that qi=i and any j and swap qi and qj in (j−i)2 seconds.

Then we make p = q and do operations in reversed order.

 **Editorial**
### [1474E - What Is It?](../problems/E._What_Is_It_.md "Codeforces Round 696 (Div. 2)")

Hint 1: How many operations will robot make in the worst case?

Hint 2: How many times can robot spend (n−1)2 time on 1 operation?

Hint 3: How many times can robot spend (n−2)2 time on 1 operation? It is easyer to think about number of operations with time greater or equal to (n−2)2.

Hint 4: Instead of operation from the statement we can apply the following operation to q which is initially an identity permutation:

* Select i such that qi=i and any j and swap qi and qj in (j−i)2 seconds.

Then we make p = q and do operations in reversed order.

Solution:

If we can select i and j for an operation, pj≠j.

After every operation, there is at least one more element with pi=i, so after n−1 operations at least n−1 elements are on their places. The remaining element can be only on its own place, so we can't do more than n−1 operations.

Let's now count number of operations that takes (n−1)2 time. It is only a swap of 1-st and n-th elements. If we did it, p1=1 or pn=n so we can't use it one more time. Let's generalize it. If we are calculating number of operations that takes (n−k)2 time, let's look at the first k elements and at the last k elements. Any operation that takes greater or equal then (n−k)2 seconds, uses two of this elements. So, after 2k−1 operations 2k−1 of this elements will be on their places and we can't use one more operation of this type. 

So, answer≤(n−1)2+(n−2)2+(n−2)2+(n−3)2+⋯. There are n−1 terms, each (n−k)2 appears 2 times, except (n−1)2 and last term (depends on parity of n−1).

We can construct example, where robot will spend exactly (n−1)2+(n−2)2+(n−2)2+(n−3)2+⋯ second as follows (using idea from hint 4):

* If n is even, answer=(n−1)2+⋯+(n−n/2)2+(n−n/2)2. Let's look at the example with n=6:
	+ Set q=[1,2,3,4,5,6].
	+ Swap q1 and qn in 25 seconds, q=[6,2,3,4,5,1].
	+ Swap q1 and qn−1 in 16 seconds, q=[5,2,3,4,6,1].
	+ Swap q2 and qn in 16 seconds, q=[5,1,3,4,6,2].
	+ Swap q1 and qn−2 in 9 seconds, q=[4,1,3,5,6,2].
	+ Swap q3 and qn in 9 second, q=[4,1,2,5,6,3]. In general, we swap 1-st and n-th elements on the first operation and then move elements 2,n−1,3,n−2,4,n−3,... to the further end of q.
* If n is odd, answer=(n−1)2+⋯+(n−⌈n/2⌉)2. The only difference from even case is element in the center. For example, if n=7 we will do the following operations:
	+ q=[1,2,3,4,5,6,7]. Swap q1 and qn.
	+ q=[7,2,3,4,5,6,1]. Swap q1 and qn−1.
	+ q=[6,2,3,4,5,7,1]. Swap q2 and qn.
	+ q=[6,1,3,4,5,7,2]. Swap q1 and qn−2.
	+ q=[5,1,3,4,6,7,2]. Swap q3 and qn.
	+ q=[5,1,2,4,6,7,3]. Finally, swap q1 and q⌈n/2⌉.
	+ q=[4,1,2,5,6,7,3].
 **Solution**[104840536](https://codeforces.com/contest/1474/submission/104840536)

[1474F - 1 2 3 4 ...](../problems/F._1_2_3_4_....md "Codeforces Round 696 (Div. 2)")

 **Bonus**Can you solve this problem with a bigger n?

 **Editorial**
### [1474F - 1 2 3 4 ...](../problems/F._1_2_3_4_....md "Codeforces Round 696 (Div. 2)")

Solution describes generalized version of algorigthm, corner cases are described later.

It is easy to see that answer doesn't depend on x given in the input, because we can substract x from each element of p and longest incerasing subsequences will remain the same.

Let's look at p as a function. If pi=x and pj=y, for each z∈[x,y] there exists k∈[i,j], such that pk=z (Integer version of intermediate value theorem).

Now look at any longest increasing subsequence L. If there are integers x−1 and x+1 in it (but there is no x), we can find appearence of x in p between them and add it to L, thus making a L longer. So, such x shouldn't exist → correct longest increasing sequence contains all integers between a and b for some a and b.

Let's build array peaks that contains p1, last(p) and all pi such that pi−1<pi>pi+1 or pi−1>pi<pi+1 in order they appear in p. It is easy to see, that |peaks|≤n+1.

Suppose, that the end of L is not a peak. If it lies on increasing interval, than we can take next element into L and increase |L|. If it lies on decreasing interval, we can use previous element of p and using previous facts, find L′, |L′|>|L|. We can apply the same observations to the beginning of p.

Thus, any L begins and ends in peaks. Now, we can find |L| in O(n2).

Suppose, we fixed that peaks and got p′, such that longest increasing subsequence of p′ begins and ends in different ends of p′ (we will not care about other longest increasing subsequences). Let's look at the slow algorithm for finding the amount of longest increasing subsequences: 

* Let waysi be number of ways to build a prefix of longest increasing subsequence, that ends in p′i.
* Set ways1=1.
* For each i in order [1..|p′|], waysi=∑j<i,p′j+1=p′iwaysj. This is correct because p′j+1=p′i means exactly that the length of longest increasing subsequence ends in p′j is smaller than the length of longest increasing subsequence ends in p′i by 1 (because of previous facts).
* The answer is ways|p′|.

The time complexity of this approach is O(|p′|2)

Let's change this algorithm a bit by changing order we iterate over i. We will iterate in order of increasing p′i. Since each value appears in p′ O(n) times, when calculating values of waysi for all i, such that p′i=x, we will need to check only O(n) values of waysj for p′j=x−1, and we will never use values of waysj later, we need only O(n) memory and O(|L|⋅n2) time. We will store this values in array w, where wi,j is a number of ways to end prefix of longest increasing subsequence in value i on the j-th increasing/decreasing segment of p′. Clearly, wi,j is calculated only from wi−1,∗. We can write down transitions between them for each i and see, that we use the same transition for almost all values of i between two "consecutive by value" peaks. There are O(n) intervals between peaks, and almost all transitions on each of this intervals are the same. We can build matrix G of size O(n) and use matrix exponentiation for doing this transitions fast.

Complexity for each p′ is O(n4⋅log|dmax|). We should be careful, because it will take O(n6∗log|dmax|) if we will do it for each p′ we find. We should group p′-s with the same first element into one group and apply the algorithm above for each of the groups. Note, that there can be many groups, but total size (in segments) of all p′-s doesn't exceed n. It gives the total time complexity O(n4⋅log|dmax|).

We can further optimize this solution to get time complexity O(n3⋅log|dmax|). Obiviously, we can through out all from matrix all rows and collumns with zeroes. After this, we can show that the matrix will be of the following form:

1 1 1 1 1

0 0 1 1 1

0 0 1 1 1

0 0 0 0 1

0 0 0 0 1

It happends because ones on the main diagonal correspond to increasing subsegments (between two peaks), and zeroes correspond to decreasing subsegments. Obiviously, we cannot move backwards, so all elements below main diagonal are zeroes. And since this matrix corresponds to placing x+1 after x in longest increasing subsequence, all elements above main diagonal are ones (all subsegments contains both x and x+1). Matrix exponentiation of this matrix can be done in O(n2⋅log|dmax|), because we will care only about distance between i-th and j-th subsegments and parities of i and j.

There are many tricky cases in this problem, such as: 

* Handling zeroes and same sign elements in a row while building peaks.
* If all di are not positive, longest increasing subsequence will have length 1 (last element = first element), so it don't have to begin in one of peaks and end in one of peaks.
* Even though all di can be stored in int, first answer can be up to 5⋅1010+1. Also, degree in matrix exponentiation can don't fit in int.
* There can be many groups of p′-s.
* Algorithm without compessing p′-s in groups can work O(n6⋅log|dmax|) in the worst case.
 **Solution**[104840452](https://codeforces.com/contest/1474/submission/104840452)

Good luck in your future contests!

