# Tutorial_(en)

Thank you for participating, and I hope you enjoyed the problems! Once again, we're sorry about the round being unrated. 

Also, here are video editorials by [BRCode](https://codeforces.com/profile/BRCode "Expert BRCode"):

 * [Problem A and B](https://codeforces.com/https://www.youtube.com/watch?v=Z0JKnlmhVOc)
* [Problem C](https://codeforces.com/https://www.youtube.com/watch?v=A3GVI-nxjLM)
* [Problem D](https://codeforces.com/https://www.youtube.com/watch?v=e1TylJJr6Bw)
* [Problem E](https://codeforces.com/https://www.youtube.com/watch?v=wR_qg1XwAg0)
* [Problem F](https://codeforces.com/https://www.youtube.com/watch?v=KC6S5txBsdE)

 
### [1438A - Specific Tastes of Andre](../problems/A._Specific_Tastes_of_Andre_.md "Codeforces Round 682 (Div. 2)")

The array aa = [1,1,…,1,1][1,1,…,1,1] is perfect since the sum of every subarray is exactly equal to its length, and thus divisible by it. 

 
### [1438B - Valerii Against Everyone](../problems/B._Valerii_Against_Everyone.md "Codeforces Round 682 (Div. 2)")

We claim the answer is NO if and only if the elements are pairwise distinct.

If any element has two occurrences, we can trivially select them as the two subarrays. Otherwise, since all elements are distinct, choosing a subarray is the same as choosing the set bits of a 109109 digit long binary number. Since every number has a unique binary representation, no two subarrays can have the same sum. 

 
### [1438C - Engineer Artem](../problems/C._Engineer_Artem.md "Codeforces Round 682 (Div. 2)")

The increment by one operation essentially allows us to change the parity of any position. Let's color the matrix like a chessboard. Since every pair of adjacent cells consist of cells with different colors, we can make values at all black cells even and values at all white cells odd. 

 
### [1438D - Powerful Ksenia](../problems/D._Powerful_Ksenia.md "Codeforces Round 682 (Div. 2)")

We will first solve the problem for odd nn, and then extend the solution to even nn. 

Note that applying the operation to a,b,ba,b,b makes all of them equal to aa. Thus, we can try making pairs of equal elements. This is easy for odd nn: 

* While at least 33 unpaired elements exist, apply the operation on any 33.
* Pair any two of them and repeat.

 Finally, we will have just one unpaired element left, using which we can make all elements equal as described at the start. The number of operations used is exactly n−1n−1. 

Let us denote XX as the xor of all elements in the original array. 

To solve for even nn, we note that applying the given operation does not change XX. 

Since the xor of an even number of same elements is 00, the answer is impossible for arrays with X≠0X≠0. 

To solve for even nn and X=0X=0, we can just solve the problem for the first n−1n−1 using the odd approach and the last element will magically be equal to the first n−1n−1.

This problem was set by [Anti-Light](https://codeforces.com/profile/Anti-Light "Expert Anti-Light") and prepared by [knightron00](https://codeforces.com/profile/knightron00 "Expert knightron00") 

### [1438E - Yurii Can Do Everything](../problems/E._Yurii_Can_Do_Everything.md "Codeforces Round 682 (Div. 2)")

It's natural to think that the number of good subarrays cannot be very large; this is indeed true.

The following algorithm works: 

* Fix the left endpoint ll. Let kk be the most significant set bit in alal.
* Check every rr in increasing order by bruteforce while sum(l+1,r−1)sum(l+1,r−1) is smaller than 2k+12k+1.
* Reverse the array, and do the same again. Note that we need to be careful here since we might count the same subarray twice.

We, now, prove its correctness and efficiency. 

Consider any good subarray a[l...r]a[l...r], let k1k1 be the most significant set bit in max(al,ar)max(al,ar) and k2k2 the most significant set bit in sum(l+1,r−1)sum(l+1,r−1). We must have k1≥k2k1≥k2 because all bits greater than k1k1 will be unset in al⊕aral⊕ar, but k2k2 is set. Hence, the algorithm counts all possible good subarrays. 

We now prove the number of subarrays our algorithm checks is of the order O(nlogai)O(nlogai). For every rr, let's count the number of ll's it can be reached by. For a particular kk, notice that only the 22 closest ll's to the left with this bit set can reach this rr. For the third one and beyond, the sum will be at least 2∗2k=2k+12∗2k=2k+1 simply due the to the contribution of the closest two. Since there are nn right endpoints and only logailogai possible values of kk, our claim is true.

 

 
### [1438F - Olha and Igor](../problems/F._Olha_and_Igor.md "Codeforces Round 682 (Div. 2)")

The solution is as follows. 

* Query $420$ random triples.
* Let $c_1$ and $c_2$ be the two most frequently returned nodes  — these are the children of the root.
* Query $c_1,c_2$ with every other $i$, and only the root will return $i$.

Firstly, note that a query — $u$, $v$, and $w$ — returns a node $x$ that minimizes the sum of distances from all the three nodes. Thus, the order of the $3$ nodes is irrelevant. You can think of $x$ as the node that lies on the path of every possible pair formed from the $3$ nodes. 

Now, let's calculate the number of triples for which node $u$ is returned as the answer. For this, we will root the tree at $u$, and calculate the subtree sizes of its children  — $s_1$, $s_2$, and $s_3$ ($s_3 = 0$, if $u$ is the actual root). With these values with us, the number of triples is: $$(s_1\times s_2\times s_3)+(s_1\times s_2)+(s_2\times s_3)+(s_3\times s_1)$$

In the above expression, the first term calculates the triples in which $u$ is not present, while the other $3$ terms assume $u$ is one of the nodes in the triple. Nodes at the same depth will, of course, have the same count. 

At this point, we can either observe that this expression is maximum when $u$ is a child of the root or calculate values for every depth and compare them. 

For example, for $h = 5$, each child of the root is the answer to about $23\%$ of the triples. This value converges to $18\%$ per child when $h$ approaches $18$. Thus, when we query $420$ random triples, we can be sure enough that the two most frequently appearing values will be the children of the root. 

Finally, we just note that for all non-root nodes $v$, querying $c_1$, $c_2$, and $v$ gives either $c_1$ or $c_2$. 

Time Complexity: $\mathcal{O}(n)$

