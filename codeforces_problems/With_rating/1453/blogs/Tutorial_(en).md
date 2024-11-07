# Tutorial_(en)


### [1453A - Cancel the Trains](../problems/A._Cancel_the_Trains.md "Codeforces Round 688 (Div. 2)")

Let's first determine whether it's possible for two trains that start from (i,0)(i,0) and (0,j)(0,j) to crash into each other. For this to happen, there must be a point where (i,T)=(T,j)(i,T)=(T,j), which means i=Ti=T and j=Tj=T. Therefore, a train that starts from the bottom end can crash into a train that starts from the left end if and only if they have the same train number. We can cancel either one of them to prevent that crash.

Since nn and mm are small, we can brute-force every pair of trains and count the number of pairs of trains that share the same number, and print that value as the answer. The time complexity for this solution is O(nm)O(nm) for each test case.

If we want an asymptotically faster solution, we can put all train numbers into a binary search tree structure (such as std::set in C++), and then find duplicate numbers from the trains of the other side by searching for those values. Another similar solution is to sort the former numbers, then perform binary search for the other values. The time complexity for these solutions is O((n+m)log(n))O((n+m)log(n)).

There is another solution with O(n+m)O(n+m) time complexity taking advantage of the fact that the train numbers are small. Let's make an array XX of length 101101, and set X[i]=trueX[i]=true if and only if there is a train starting from (i,0)(i,0). For each train starting from (0,j)(0,j), we can check if X[j]X[j] is truetrue, and count the total number of duplicates this way.

**Solutions**

 * [O(nm) (C++)](https://codeforces.com/contest/1453/submission/100391763)
* [O(nm) (Java)](https://codeforces.com/contest/1453/submission/100391940)
* [O(nm) (Python 3)](https://codeforces.com/contest/1453/submission/100392003)
* [O((n+m)logn) (C++)](https://codeforces.com/contest/1453/submission/100392039)
* [O(n+m) (C++)](https://codeforces.com/contest/1453/submission/100392086)

 
### [1453B - Suffix Operations](../problems/B._Suffix_Operations.md "Codeforces Round 688 (Div. 2)")

First, let's find the optimal strategy for Gildong to follow to make all elements of the array equal.

It's obvious that there is no need to perform any operation on the suffix starting at a1a1, since that operation changes all the integers in the array. For i=2i=2 to nn, the only way for aiai to have equal value to ai−1ai−1 is to perform one of the operations on the suffix starting at aiai abs(ai−ai−1)abs(ai−ai−1) times. This is because all operations starting at other positions do not change the difference between aiai and ai−1ai−1. Therefore, the minimum number of operations Gildong has to perform is ∑ni=2abs(ai−ai−1)∑ni=2abs(ai−ai−1).

How should we change one element so that we can minimize this value? Let's take care of some special cases first. The optimal way to change a1a1 is to make it equal to a2a2, and then the minimum number of operations Gildong has to perform is decreased by abs(a2−a1)abs(a2−a1). Similarly, the optimal way to change anan is to make it equal to an−1an−1, and then the minimum number of operations Gildong has to perform is decreased by abs(an−an−1)abs(an−an−1).

For the rest of the elements, changing aiai affects both abs(ai−ai−1)abs(ai−ai−1) and abs(ai+1−ai)abs(ai+1−ai). Here, we need to observe an important fact: This value is minimized when aiai is between ai−1ai−1 and ai+1ai+1, inclusive. Intuitively, if ai−1<ai>ai+1ai−1<ai>ai+1, Gildong has to perform one or more 22-nd operations on the suffix starting at aiai, and then one or more 11-st operations on the suffix starting at ai+1ai+1 to compensate for the extra 22-nd operations. This applies to the scenario where ai−1>ai<ai+1ai−1>ai<ai+1 as well. If aiai is between ai−1ai−1 and ai+1ai+1, these additional operations are unnecessary. In fact, the number of operations is decreased from abs(ai−ai−1)+abs(ai+1−ai)abs(ai−ai−1)+abs(ai+1−ai) to abs(ai+1−ai−1)abs(ai+1−ai−1).

Therefore, we can decrease the number of operations needed by:

max{abs(a2−a1)abs(an−an−1)maxi=2..n−1abs(ai−ai−1)+abs(ai+1−ai)−abs(ai+1−ai−1)max⎧⎩⎨abs(a2−a1)abs(an−an−1)maxi=2..n−1abs(ai−ai−1)+abs(ai+1−ai)−abs(ai+1−ai−1)

The answer is x−yx−y where xx is the minimum number of operations Gildong needs to perform on the initial array, and yy is the maximum number of operations we can decrease by changing exactly one element.

Time complexity: O(n)O(n).

**Solutions** - [C++](https://codeforces.com/contest/1453/submission/100392210) - [Java](https://codeforces.com/contest/1453/submission/100392250) - [Python 3](https://codeforces.com/contest/1453/submission/100392309)

 
### [1453C - Triangles](../problems/C._Triangles.md "Codeforces Round 688 (Div. 2)")

Let's consider each dd separately. For each cell that has the digit dd, we'll check the case where this cell is used as a vertex of the end of a horizontal or vertical side (i.e. the base) of the triangle, and change the digit of another cell and use it as the other end of that side. Let's say the position for this cell is (i,j)(i,j), and we change the cell at (p,q)(p,q). Then there are two cases:

* i=pi=p: Since we always want to maximize the length of the base, qq can be either 11 or nn, depending on whether j−1>n−jj−1>n−j or not. The length of the base will be max(j−1,n−j)max(j−1,n−j).
* j=qj=q: Similarly, pp can be either 11 or nn, depending on whether i−1>n−ii−1>n−i or not. The length of the base will be max(i−1,n−i)max(i−1,n−i).

In the first case, since the base is horizontal, the area of the triangle will be determined only by the remaining vertex's row component. Therefore, we only need the maximum / minimum row position of dd. Let's say they are max_rowmax_row and min_rowmin_row, respectively. We can easily pre-calculate them in advance. Assuming that bb is the length of the base, the maximum area will be b×max(max_row−i,i−min_row)2b×max(max_row−i,i−min_row)2. We can get rid of the 1212 part as we will print the area multiplied by 22.

Thankfully, we don't need to check the case where we change a cell that is not used as an end of a base separately, since we can always move it around so that they will eventually be horizontal / vertical to one of the other vertices without changing the area, which becomes a case that we already took care of.

The same process can be applied to the second case as well. Summarizing the whole process, for each dd, the maximum area (multiplied by 22) is:

max(i,j)=d{max(j−1,n−j)×max(max_row−i,i−min_row)max(i−1,n−i)×max(max_column−j,j−min_column))max(i,j)=d{max(j−1,n−j)×max(max_row−i,i−min_row)max(i−1,n−i)×max(max_column−j,j−min_column))

Since we check each cell exactly once, and pre-calculating max_rowmax_row, min_rowmin_row, max_columnmax_column, and min_columnmin_column takes O(n2)O(n2), the total time complexity is O(n2)O(n2) for each test case.

**Solutions** - [C++](https://codeforces.com/contest/1453/submission/100392381) - [Java](https://codeforces.com/contest/1453/submission/100392413) - [Python 3](https://codeforces.com/contest/1453/submission/100392463)

 
### [1453D - Checkpoints](../problems/D._Checkpoints.md "Codeforces Round 688 (Div. 2)")

As already explained in the notes (and is quite obvious), the expected number of tries to beat stage ii with a checkpoint where stage i+1i+1 also has a checkpoint (or is the end of the game) is 22. What if stage i+1i+1 doesn't have a checkpoint and stage i+2i+2 has a checkpoint?

We can think of it like this. It takes 22 tries in expectation to get to stage i+1i+1, and the player needs to add one more try, trying 33 times in total. But this also has a probability of 1212 to succeed, so the expected number of tries to actually get to stage i+2i+2 is multiplied by 22 – making it 66 in total.

This can be extended indefinitely. Let's say xixi is the expected number of tries to beat ii consecutive stages with only one checkpoint at the beginning. If we extend it to i+1i+1 consecutive stages, it takes xi+1=2⋅(xi+1)xi+1=2⋅(xi+1) tries. If this is not intuitive, we can always use Monte Carlo method to simulate how many tries each takes. The general term for this sequence is xi=2i+1−2xi=2i+1−2, and it is introduced in [OEIS A000918](https://codeforces.com/http://oeis.org/A000918) with a similar example.

As each checkpoint makes the stages after that checkpoint independent of the previous stages, we can just add up appropriate xixi's to make it equal to kk. Using xixi means we append the stages in 11 00 00 00 ... form where the number of 00's is i−1i−1.

As every term of the sequence is even, the answer is −1−1 if kk is odd. Otherwise, we can show that there always exists an answer for all even k≤1018k≤1018. There are two simple strategies to make it with at most 20002000 stages.

The first strategy is to greedily take the greatest xi≤yxi≤y where yy is the remaining number, then append xixi and subtract it from yy. This works because either yy can be exactly 2⋅xi2⋅xi, or we can use xixi once and repeat the process with y−xiy−xi. The worst case for this strategy is to use all of x57x57, x56x56, x55x55, ..., x1x1 and another x1x1, which sums up to total of 16541654 stages.

Another strategy is to use xixi and x1x1 if bit i+1i+1 (00-indexed) is 11. Since there can be at most 5858 11-bits, the worst case for this strategy is still far less than 20002000.

Time complexity: O(log2k)O(log2k)

**Solutions** - [C++](https://codeforces.com/contest/1453/submission/100392587) - [Java](https://codeforces.com/contest/1453/submission/100392655)

 
### [1453E - Dog Snacks](../problems/E._Dog_Snacks.md "Codeforces Round 688 (Div. 2)")

It is obvious that the problem can be modeled as a tree rooted at the 11-st vertex. Given a large enough kk, we can see that Badugi will always 'clear out' each subtree and then move back to its parent. This is because if there exists an unvisited child for a vertex, the distance between them is 11, while any unvisited vertex at the parent's side has distance of at least 22. Therefore, Badugi's moves will look like a preorder tree traversal.

This implies another fact. Let's say the jj-th vertex is a child of the ii-th vertex. After visiting the last vertex of a subtree rooted at the jj-th vertex, Badugi has to move a longer distance when it was the last child of the ii-th vertex than when the ii-th vertex has another unvisited child. The only important rule for Badugi is to choose the child that has the shortest 'moving back' distance as the last child he will visit. This distance can be sent back to its parent so that the parent can choose between the candidates. Let's say the minimum among the candidates is mnmn, and the maximum is mxmx. It is optimal to use mn+1mn+1 as the 'moving back' distance, and the maximum of the 'child-to-child' distances will be mx+1mx+1.

There is one exception for this strategy – the root. Unlike the others, there is no need to move any further after visiting all vertices and then getting back to the root. This means choosing mxmx as the 'moving back' distance is optimal, because we don't need to add anything to it. Then we can use the sub-maximum of the candidates as the maximum of 'child-to-child' distances.

Along these processes we can update the answer whenever we find the maximum of 'child-to-child' distances, along with the last move back to the root.

Time complexity: O(n)O(n) for each test case, but it's too boring to find the sub-maximum in linear time, so just sort the candidates and it will be O(nlogn)O(nlogn) for each test case.

**Solutions** - [C++](https://codeforces.com/contest/1453/submission/100392718) - [Java](https://codeforces.com/contest/1453/submission/100392748)

 
### [1453F - Even Harder](../problems/F._Even_Harder.md "Codeforces Round 688 (Div. 2)")

Since there is at least one way to win initially, every platform is reachable from the start. Note that this condition should still hold after we achieve what Gildong wants. Because of this, if there are multiple jj's where j+aj≥ij+aj≥i, there are at least two ways that can get to the ii-th platform. Therefore, in order to leave only one way to get to the ii-th platform, we need to change all ajaj's where j+aj>=ij+aj>=i into 00 except for one of them. We'll call this process cleaning, and the platforms where we set aj=0aj=0 are the cleaned platforms.

Let dp[i][x]dp[i][x] (i≤xi≤x) be the minimum number of platforms that should be cleaned to leave only one way to get to the ii-th platform, where the only platform kk that can directly move to the ii-th platform (i.e. the predecessor) has a value at most x−kx−k. In other words, dp[i][x]dp[i][x] only considers all kk's where k<i≤k+ak≤xk<i≤k+ak≤x, and choose the one that requires minimum number of cleaned platforms so far. We'll determine dp[i][i..n]dp[i][i..n] in increasing order of ii.

Now let cntcnt be the number of yy's where j<y<ij<y<i and y+ay≥iy+ay≥i. Initially cntcnt is 00. Now for each jj from i−1i−1 to 11 (downwards), if j+aj>=ij+aj>=i, minimize dp[i][j+aj]dp[i][j+aj] with dp[j][i−1]+cntdp[j][i−1]+cnt and then increase cntcnt by 11. This means we clean all platforms between j+1j+1 and i−1i−1 to let the jj-th platform be the predecessor of the ii-th platform, while it has possibility to reach the j+ajj+aj-th platform. Note that all kk's where k<jk<j and k+ak≥ik+ak≥i are already cleaned when calculating dp[j][i−1]dp[j][i−1], so we only need to count the cleaned platforms between j+1j+1 and i−1i−1 for cntcnt.

Then we can prefix-minimize dp[i][i..n]dp[i][i..n] because the actual meaning of the dp[i][x]dp[i][x] is the minimum number of platforms that should be cleaned for the predecessor of the ii-th platform can reach at most the xx-th platform; i.e. it should consider all cases where j+a[j]<xj+a[j]<x as well.

After we repeat these processes for all ii's, the answer is dp[n][n]dp[n][n]. Though the explanation is quite complicated, the code turns out to be very short.

Time complexity: O(n2)O(n2).

**Solutions** - [C++](https://codeforces.com/contest/1453/submission/100392800) - [Java](https://codeforces.com/contest/1453/submission/100392832) - [Python 3](https://codeforces.com/contest/1453/submission/100392864)

