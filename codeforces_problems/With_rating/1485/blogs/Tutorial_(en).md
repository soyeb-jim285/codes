# Tutorial_(en)

[1485A - Add and Divide](../problems/A._Add_and_Divide.md "Codeforces Round 701 (Div. 2)")

Author: [TheScrasse](https://codeforces.com/profile/TheScrasse "Master TheScrasse")  
 Preparation: [MyK_00L](https://codeforces.com/profile/MyK_00L "Master MyK_00L")

 **Hint 1**Suppose that you can use x operations of type 1 and y operations of type 2. Try to reorder the operations in such a way that a becomes the minimum possible.

 **Hint 2**You should use operations of type 2 first, then moves of type 1. How many operations do you need in the worst case? (a=109, b=1)

 **Hint 3**You need at most 30 operations. Iterate over the number of operations of type 2.

 **Solution**Notice how it is never better to increase b after dividing (⌊ab+1⌋≤⌊ab⌋).

So we can try to increase b to a certain value and then divide a by b until it is 0. Being careful as not to do this with b<2, the number of times we divide is going to be O(loga). In particular, if you reach b≥2 (this requires at most 1 move), you need at most ⌊log2(109)⌋=29 moves to finish.

Let y be the number of moves of type 2; we can try all values of y (0≤y≤30) and, for each y, check how many moves of type 1 are necessary.

Complexity: O(log2a).

If we notice that it is never convenient to increase b over 6, we can also achieve a solution with better complexity.

Official solution: [107232596](https://codeforces.com/contest/1485/submission/107232596 "Submission 107232596 by TheScrasse")

[1485B - Replace and Keep Sorted](../problems/B._Replace_and_Keep_Sorted.md "Codeforces Round 701 (Div. 2)")

Author: [TheScrasse](https://codeforces.com/profile/TheScrasse "Master TheScrasse")  
 Preparation: [Kaey](https://codeforces.com/profile/Kaey "Master Kaey")

 **Hint 1**You can make a k-similar array by assigning ai=x for some l≤i≤r and 1≤x≤k. 

 **Hint 2**How many k-similar arrays can you make if x is already equal to some ai (l≤i≤r)?

 **Hint 3**How many k-similar arrays can you make if either x<al or x>ar?

 **Hint 4**How many k-similar arrays can you make if none of the previous conditions holds?

 **Solution**Let's consider each value x from 1 to k.

 * If x<al, you can replace al with x (and you get 1 k-similar array). There are al−1 such values of x.
* If x>ar, you can replace ar with x (and you get 1 k-similar array). There are k−ar such values of x.
* If al<x<ar, and x≠ai for all i in [l,r], you can either replace the rightmost bi which is less than x, or the leftmost bi which is greater than x (and you get 2 k-similar arrays). There are (ar−al+1)−(r−l+1) such values of x.
* If x=ai for some i in [l,r], no k-similar arrays can be made.

The total count is (al−1)+(k−ar)+2((ar−al+1)−(r−l+1)), which simplifies to k+(ar−al+1)−2(r−l+1).

Complexity: O(n+q).

Official solution: [107232462](https://codeforces.com/contest/1485/submission/107232462 "Submission 107232462 by TheScrasse")

[1485C - Floor and Mod](../problems/C._Floor_and_Mod.md "Codeforces Round 701 (Div. 2)")

Authors: [isaf27](https://codeforces.com/profile/isaf27 "International Grandmaster isaf27"), [TheScrasse](https://codeforces.com/profile/TheScrasse "Master TheScrasse")  
 Preparation: [Kaey](https://codeforces.com/profile/Kaey "Master Kaey")

 **Hint 1**Let ⌊ab⌋=a mod b=k. Is there an upper bound for k?

 **Hint 2**k≤√x. For a fixed k, can you count the number of special pairs such that a≤x and b≤y in O(1)?

 **Solution**We can notice that, if ⌊ab⌋=a mod b=k, then a can be written as kb+k (b>k). Since b>k, we have that k2<kb+k=a≤x. Hence k≤√x.

Now let's count special pairs for any fixed k (1≤k≤√x). For each k, you have to count the number of b such that b>k, 1≤b≤y, 1≤kb+k≤x. The second condition is equivalent to 1≤b≤x/k−1.

Therefore, for any fixed k>0, the number of special pairs (a≤x; b≤y) is max(0,min(y,x/k−1)−k). The result is the sum of the number of special pairs for each k.

Complexity: O(√x). 

Official solution: [107232416](https://codeforces.com/contest/1485/submission/107232416 "Submission 107232416 by TheScrasse")

[1485D - Multiples and Power Differences](../problems/D._Multiples_and_Power_Differences.md "Codeforces Round 701 (Div. 2)")

Author: [TheScrasse](https://codeforces.com/profile/TheScrasse "Master TheScrasse")  
 Preparation: [MyK_00L](https://codeforces.com/profile/MyK_00L "Master MyK_00L")

 **Hint 1**Brute force doesn't work (even if you optimize it): there are relatively few solutions.

 **Hint 2**There may be very few possible values of bi,j, if bi−1,j is fixed. The problem arises when you have to find a value for a cell with, e.g., 4 fixed neighbors. Try to find a possible property of the neighbors of (i,j), such that at least a solution for bi,j exists.

 **Hint 3**The least common multiple of all integers from 1 to 16 is less than 106.

 **Solution**Build a matrix with a checkerboard pattern: let bi,j=720720 if i+j is even, and 720720+a4i,j otherwise. The difference between two adjacent cells is obviously a fourth power of an integer. We choose 720720 because it is lcm(1,2,…,16). This ensures that bi,j is a multiple of ai,j, because it is either 720720 itself or the sum of two multiples of ai,j.

Complexity: O(nm).

Official solution: [107232359](https://codeforces.com/contest/1485/submission/107232359 "Submission 107232359 by TheScrasse")

[1485E - Move and Swap](../problems/E._Move_and_Swap.md "Codeforces Round 701 (Div. 2)")

Author: [TheScrasse](https://codeforces.com/profile/TheScrasse "Master TheScrasse")  
 Preparation: [TheScrasse](https://codeforces.com/profile/TheScrasse "Master TheScrasse")

 **Hint 1**What happens if you can't swap coins?

 **Hint 2**Let dpi be the maximum score that you can reach after dist(1,i) moves if there is a red coin on node i after step 3. However, after step 2, the coin on node i may be either red or blue. Try to find transitions for both cases.

 **Hint 3**If you consider only the first case, you solve the problem if there are no swaps. You can greedily check the optimal location for the blue coin: a node j such that dist(1,i)=dist(1,j) and aj is either minimum or maximum.

Instead, if the coin on node i is blue after step 2, the red coin is on node j and you have to calculate max(dpparentj+|aj−ai|) for each i with a fixed dist(1,i). How?

 **Solution**Divide the nodes in groups based on the distance from the root. Then, for each dist(1,i) in increasing order, calculate dpi — the maximum score that you can reach after dist(1,i) moves if there is a red coin on node i after step 3. You can calculate dpi if you know dpj for each j that belongs to the previous group. There are two cases:

 * if after step 2 the coin on node i is red, the previous position of the red coin is fixed, and the blue coin should reach either the minimum or the maximum aj among the j that belong to the same group of i;
* if after step 2 the coin on node i is blue, there is a red coin on node j (dist(1,i)=dist(1,j)), so you have to maximize the score dpparentj+|aj−ai|.  
 This can be done efficiently by sorting the ai in the current group and calculating the answer separately for aj≤ai and aj>ai; for each i in the group, the optimal node j either doesn't change or it's the previous node.  
 Alternatively, you can notice that dpparentj+|aj−ai|=max(dpparentj+aj−ai,dpparentj+ai−aj), and you can maximize both dpparentj+aj−ai and dpparentj+ai−aj greedily (by choosing the maximum dpparentj+aj and dpparentj−aj, respectively). In this solution, you don't need to sort the ai.

The answer is max(dpi).

Complexity: O(n) or O(nlogn).

Official solution: [107232216](https://codeforces.com/contest/1485/submission/107232216 "Submission 107232216 by TheScrasse")

[1485F - Copy or Prefix Sum](../problems/F._Copy_or_Prefix_Sum.md "Codeforces Round 701 (Div. 2)")

Author: [TheScrasse](https://codeforces.com/profile/TheScrasse "Master TheScrasse")  
 Preparation: [TheScrasse](https://codeforces.com/profile/TheScrasse "Master TheScrasse")

 **Hint 1**Why isn't the answer 2n−1? What would you overcount?

 **Hint 2**Find a dp with time complexity O(n2logn).

 **Hint 3**Let dpi,j be the number of hybrid prefixes of length i and sum j. The transitions are dpi,j→dpi+1,j+bi and dpi,j→dpi+1,bi. Can you optimize it to O(nlogn)?

 **Solution**For each i, you can choose either ai=bi or ai=bi−∑i−1k=1ak. If ∑i−1k=1ak=0, the two options coincide and you have to avoid overcounting them.

This leads to an O(n2logn) solution: let dpi be a map such that dpi,j corresponds to the number of ways to create a hybrid prefix [1,i] with sum j. The transitions are dpi,j→dpi+1,j+bi (if you choose bi=ai, and j≠0), dpi,j→dpi+1,bi (if you choose bi=∑ik=1ak).

Let's try to get rid of the first layer of the dp. It turns out that the operations required are

 * move all dpj to dpj+bi
* calculate the sum of all dpj in some moment
* change the value of a dpj

and they can be handled in O(nlogn) with ["Venice technique"](https://codeforces.com/blog/entry/58316).

dp is now a map such that dpj corresponds to the number of ways to create a hybrid prefix [1,i] such that ∑ik=1ak−bk=j. Calculate the dp for all prefixes from left to right. if bi=ai, you don't need to change any value of the dp; if bi=∑ik=1ak, you have to set dp∑ik=1−bk to the total number of hybrid arrays of length i−1.

Complexity: O(nlogn).

Official solution: [107232144](https://codeforces.com/contest/1485/submission/107232144 "Submission 107232144 by TheScrasse")

