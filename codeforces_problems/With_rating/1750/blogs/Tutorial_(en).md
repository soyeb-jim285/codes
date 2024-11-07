# Tutorial_(en)

[A — Indirect Sort](../problems/A._Indirect_Sort.md)
==================================================================

Authors: [mejiamejia](https://codeforces.com/profile/mejiamejia "Expert mejiamejia"), [Ecrade_](https://codeforces.com/profile/Ecrade_ "Grandmaster Ecrade_")

 **Solution**We claim that we can sort the array if and only if a1=1.

**Necessity**

We can notice that index 1 cannot be affected by any swap operation.

Let's see what happens to the value 1. According to the definition of the operation, it can either increase or be swapped. In order to be increased, there must exist some k such that 1>ak, but since 1 is the minimum possible value, it will never be true as other values in array a can only increse as well. Since index 1 can not be affected by a swap operation and a1>1, we conclude that if a1≠1, the answer is **No**.

**Sufficiency**

Let's focus on the second operation. Since we have a1=1, we can always choose i=1 and the operation then turns into picking some pair 2≤j<k≤n and swapping aj with ak. It's trivial to see we can always sort with such an operation.

 **Code (Ecrade_)**[**Click me**](https://codeforces.com/https://pastebin.com/pgmxzkiq)

 **Rate Problem**Good problem 


[*333*](https://codeforces.com/data/like?action=like "I like this")





Ok problem 

 
[*214*](https://codeforces.com/data/like?action=like "I like this")



Bad problem 

 
[*125*](https://codeforces.com/data/like?action=like "I like this")



Didn't solve it, idk 

 
[*26*](https://codeforces.com/data/like?action=like "I like this")



[B — Maximum Substring](../problems/B._Maximum_Substring.md)
======================================================================

Author: [tibinyte](https://codeforces.com/profile/tibinyte "Pupil tibinyte")

 **Solution**Considering that if we want to find the max value of x⋅y, then the whole string is the best to calculate, for it 0 s and 1 s are the max.

Then considering x⋅x and y⋅y : what we need to do is to calculate the max continuous number of 0 or 1, compare its square to the first condition, then take the bigger one as the answer. 

 **Code (tibinyte)**[**Click me**](https://codeforces.com/https://pastebin.com/jSs8Nvy1)

 **Rate Problem**Good problem 

 
[*256*](https://codeforces.com/data/like?action=like "I like this")



Ok problem 

 
[*287*](https://codeforces.com/data/like?action=like "I like this")



Bad problem 

 
[*30*](https://codeforces.com/data/like?action=like "I like this")



Didn't solve it, idk 

 
[*7*](https://codeforces.com/data/like?action=like "I like this")



[C — Complementary XOR](../problems/C._Complementary_XOR.md)
======================================================================

Author: [tibinyte](https://codeforces.com/profile/tibinyte "Pupil tibinyte")

 **Solution**For each operation, the interval changed by a sequence and b sequence is complementary, so you must judge whether all [ai=bi] are the same at the beginning. If they are different, you can't have a solution.

Now, if a=¬b, we can do an operation on a and have a=b. Now suppose ai=bi=1 for some i and try to make ai=bi=0 without changing anything else. If i>1, then this is very simple, we can just do an operation with (1,i) and an operation on (1,i−1). If i=1 we can make (1,n) and (2,n). Since n>1, this can always be done, thus we found a solution using 2⋅n+O(1) operations. To optimize it to only use n+O(1) operations, note that we only care about the parity of the number of operations did at any index. 

 **Code (tibinyte)**[**Click me**](https://codeforces.com/https://pastebin.com/usNVxyqv)

 **Rate Problem**Good problem 

 
[*509*](https://codeforces.com/data/like?action=like "I like this")



Ok problem 

 
[*109*](https://codeforces.com/data/like?action=like "I like this")



Bad problem 

 
[*478*](https://codeforces.com/data/like?action=like "I like this")



Didn't solve it, idk 

 
[*98*](https://codeforces.com/data/like?action=like "I like this")



[D — Count GCD](../problems/D._Count_GCD.md)
==============================================================

Author: [tibinyte](https://codeforces.com/profile/tibinyte "Pupil tibinyte")

 **Solution**We can notice that if for some 2≤i≤n, ai−1 is not divisible by ai, then the answer is 0. Else, note that all the prime factors of a1 are also prime factors in all the other values. Thus after factorizing a1 we can quickly factorize every other value.

Now let's find the number of ways we can select bi for every i. The answer will be the product of these values since each position is independent. It's easy to see that there is only one way to select b1, that is a1. Now for i>1 we need to find the number of values x such that gcd(ai−1,x)=ai. Let x=ai⋅k, we can rephrase as gcd(ai−1ai⋅ai,ai⋅k)=ai, which is also equivalent to gcd(ai−1ai,k)=1. We have k≤mai, thus the task reduces to a simple principle of inclusion-exclusion problem.

Time complexity O(29⋅9⋅log+√m) per testcase.

 **Code (tibinyte)**[**Click me**](https://codeforces.com/https://pastebin.com/wD9hfrHG)

 **Rate Problem**Good problem 

 
[*639*](https://codeforces.com/data/like?action=like "I like this")



Ok problem 

 
[*69*](https://codeforces.com/data/like?action=like "I like this")



Bad problem 

 
[*102*](https://codeforces.com/data/like?action=like "I like this")



Didn't solve it, idk 

 
[*66*](https://codeforces.com/data/like?action=like "I like this")



[E — Bracket Cost](../problems/E._Bracket_Cost.md)
=================================================================

Author: [tibinyte](https://codeforces.com/profile/tibinyte "Pupil tibinyte")

 **Solution**Let ai=1 if si=(, ai=−1 if si=) and bi be the prefix sum of ai.

Theorem: the cost of s[l+1,r] is max(bl,br)−min(bl,bl+1,...,br)

Necessity: after one operation, max(bl,br)−min(bl,bl+1,...,br) decrease at most one.

Sufficiency: If bl<br, we can do operation 2, add a right bracket at the end of string.

If bl>br, we can do operation 2, add a left bracket at the beginning of string.

If bl=br, assume x be the largest x that bx=min(bl,bl+1,...,br), then sx+1=(, so we can do operation 1, cyclic shift s[l,x+1] to right.

Under any condition, max(bl,br)−min(bl,bl+1,...,br) decrease one after one operation.

We can use binary index tree to calculate max(bl,br) and min(bl,bl+1,...,br).

 **Code (tibinyte)**[**Click me**](https://codeforces.com/https://pastebin.com/cPFBgXLb)

 **Rate Problem**Good problem 

 
[*142*](https://codeforces.com/data/like?action=like "I like this")



Ok problem 

 
[*34*](https://codeforces.com/data/like?action=like "I like this")



Bad problem 

 
[*58*](https://codeforces.com/data/like?action=like "I like this")



Didn't solve it, idk 

 
[*82*](https://codeforces.com/data/like?action=like "I like this")



[F — Majority](../problems/F._Majority.md)
=============================================================

Author: [tibinyte](https://codeforces.com/profile/tibinyte "Pupil tibinyte")

 **Solution**First off, let's try to reduce the given operation to a simpler form. We claim that if it is possible to make the string 111...111 using the specified operation, we can make it 111...111 by doing the following new operation : Select two indices (i,j) such that the substring si...j looks like this 111..100...001...111 and make it all one. The proof is just to show that if we can perform operation (i,j), then it must exist some substring of si...j respecting the propriety of the new operation.

Let dpi,j be the number of binary strings of length i that in the final form ( after no more operations can be made ) begin with a prefix full of ones of length j. For transitions, we have to iterate through the length of the next 0 sequence and the length of the fixable prefix right after it ( such that we cannot perform an operation to make a bigger prefix, because that would break the definition ), but there is one problem -- we cannot compute dpi,i using any recurrence relation. Fortunately, we can compute it by subtracting the ways we get roadblocks, because, by definition dpi,i can be turned into 111...111 which doesn't have any roadblocks at all. This is O(n4) if implemented naively, but one can optimize it to O(n2) by keeping prefix sums over prefix sums.

 **Code (tibinyte)**[**Click me**](https://codeforces.com/https://pastebin.com/EACgp5PX)

 **Rate Problem**Good problem 

 
[*73*](https://codeforces.com/data/like?action=like "I like this")



Ok problem 

 
[*5*](https://codeforces.com/data/like?action=like "I like this")



Bad problem 

 
[*10*](https://codeforces.com/data/like?action=like "I like this")



Didn't solve it, idk 

 
[*59*](https://codeforces.com/data/like?action=like "I like this")



**Challenge: Solve the problem in O(nlog2)O(nlog2) or O(nlog)O(nlog) ( modulo is prime )**

 **Solution**[**Click me**](Tutorial_(en).md?#comment-970900)

[G — Doping](../problems/G._Doping.md)
===========================================================

Author: [tibinyte](https://codeforces.com/profile/tibinyte "Pupil tibinyte")

 **Solution**Consider a permutation p that lexicographically smaller than given permutation, assume the first different position is k, if we fix pk, the remaining numbers ak+1,ak+2,...,an can be arranged in any order. Denote S as the set of remaining numbers. Let m be the number of consecutive pairs, m=|x|x∈S,(x−1)∈S∪pk|, pk is included because it is possible that pk+1=pk+1. Fix the number of positions that pi=pi−1+1, this consumes some consecutive pairs, the remaining consecutive pairs should not increase the number of positions. Define a sequence p good if and only if it has no i that pi=pi−1+1.

Consider dp[i][j] = number of good arrangements of i values with j consecutive pairs. Consider one consecutive pair, if it is the only wrong pair, the number of values decrease by one and this situation should be excluded, otherwise this pair can be ignored, so dp[i][j]=dp[i][j−1]−dp[i−1][j−1], with boundary dp[i][0]=i!. After enumrating k, let S′=ak,ak+1,...,an, pk is chosen from S′ and pk<ak. Assume pk=x, if x−1∈S′, the number of consecutive pairs decrease by one, otherwise it stay the same. Additionally, if x≠pk−1+1, the number of subarrays increase by one. For every situation, count the number of pk and then calculate answer.

Time complexity: O(n2).

 **Solution 2**Since we have to deal with lexicographically smaller condition, it's natural to fix the common prefix i. Now, we can mismatch pi+1 with some of the left values. After that, we are left with permuting the other elements.

Let's say we are trying to find the number of ways to permute the remaining values {a1,a2,a3,...,ak} such that ai≠ai+1−1 for 1≤i<k.

For each i, we define bi to be a boolean value denoting the existence of ai−1 in set a.

We can formulate the following 2 claims:

 * The number of ways to permute array a only depends on k and sum of b
* For some pair (i,j), the number of ways to permute a starting with ai is equal to the number of ways to permute a starting with aj if and only if bi=bj

With these observations, we can formulate a dp solution for counting permutations. Let dpi,j,flag be the number of ways to permute if k=i, j is the sum of b, starting with a value with b value equal to flag. Let's conclude transitions:

 * dpi,1,true=dpi−1,1,false
* dpi,1,false=(dpi−1,1,true+dpi−1,1,false)⋅(i−1) − By claim 2, we can think of ending in the minimum value and we are left with another permutation we can transition 2.
* dpi,j>1,true=(dpi−1,j−1,true+dpi−1,j−1,false)⋅j − By claim 1, we can think of an equivalent array a in which all values with bi=1 are left alone. Combining with claim 2, all distributions are equal, and selecting a single value makes the permutation have j−1 values with bi=1.
* dpi,j>1,false=(dpi−1,j,false+dpi−1,j,true)⋅(i−j) − By claim 2, we can select any value with bi=0 and combining with claim 2, we can select the first value in the last chain.

Let sum be the sum of b.The number of ways to permute a such that it respects the given demands, is dpk,sum,true+dpk,sum,false. Now the number of ways to permute a with t positions such that ai≠ai+1−1 is (k−sumt−sum)⋅(dpk,t,true+dpk,t,false). This is because we can choose the values that contribute, sum of them are always contributing, so we are left with choosing t−sum values out of k−sum possibilities.

Now thinking about the values we missmatch pi+1 with, looking at claim 2, a lot of values are equivalent. We can count each value type separately since there are O(1) types, and have a O(n) complexity to update the results accordingly. Also be careful with the case where a past range of consecutive values is continued after the missmatch. It's easy to handle this because p′i+1 is fixed and we can count it independently in O(n).

Thus we have achieved O(n2) total time complexity

 **Code (tibinyte)**[**Click me**](https://codeforces.com/https://pastebin.com/dWs91GjP)

 **Rate Problem**Good problem 

 
[*23*](https://codeforces.com/data/like?action=like "I like this")



Ok problem 

 
[*5*](https://codeforces.com/data/like?action=like "I like this")



Bad problem 

 
[*7*](https://codeforces.com/data/like?action=like "I like this")



Didn't solve it, idk 

 
[*53*](https://codeforces.com/data/like?action=like "I like this")



[H — BinaryStringForces](../problems/H._BinaryStringForces.md)
=======================================================================

Author: [tibinyte](https://codeforces.com/profile/tibinyte "Pupil tibinyte")

 **Solution**We call a maximal sequence of 0 a 0 block, a maximal sequence of 1 a 1 block. 

For each i, store some disjoint intervals with the following property:

For each j that i<=j and s[j]=1, j is in one of the intervals if and only if (i,j) is a good substring.

We can prove the number of intervals for each i is O(logn).

Let's start from (i,i) to (i,n), and consider when. good substring become bad and bad substring become good.

Assume we are at (i,j).

If it is a good substring and ending with 1, it become bad when it meet a longer 0 block, so we get one interval and go to a bad substring ending with 0.

If it is a bad substring and ending with 0, suppose the next 1 is at k, then the next good intervals start at the smallest j' with three properties: (1) (k,j′) is good

(2) s[j′]=1

(3) (k,j′) is not shorter than the last 0 block.

Proof: Property 2 is obvious because we only care about substrings ending with 1.

If (k,j′) is shorter than the last 0 block, it is impossible to change this 0 block, so (i,j′) is bad. 

If (k,j′) is bad, if it starts with a 1 block (k,j") not shorter than the last 0 block after some operations, then j" is smaller than j′ and has those three properties, otherwise it is impossible to change the last 0 block. 

If it has all three properties, in substring (i,j′), (k,j′) is good and can change the last 0 block 1, and then change (i,j′) to 1, so we go to a good substring ending with 1.

When good substring become bad, the length is doubled, so the number of intervals for each i is O(logn).

To know when good substring become bad ,for every 0 block (j,k),if (j,k) is longer than (i,j−1), then (i,k) is bad, we can preprocess those i in O(n).

To know when bad substring become good, we go with i from n to 1 and for each i, search in O(logn) intervals O(logn) times.

So we get those intervals in O(nlog2n)

Now we can check each substring ending with 1 is good or not. Do the above algorithm on the reversed string, so we can check each substring starting with 1 is good or not. But we can not check substring starting and ending with 0.

Suppose (i′,j′) is the longest 0 block in (i,j), then (i,j) is good if at least one of (i,i′−1) and (j′+1,j) is good and not shorter than (i′,j′).

Proof: After changing the longest 0 block, we can change all other 0 blocks. So for any substring, it is good if and only if we can change its longest 0 block.

If (i,i′−1) is good and not shorter, it can change (i′,j′), so (i,j) is good.

If (i,j) is good assume the longest 0 block is changed from left. So after some operations in (i,i′−1), there is a substring (k,i′−1) become all 1 and not shorter than (i′,j′). Then (k,i′−1) can make (i,i′−1) good as there is no longer 0 block. 

Similarly, we can prove for (j′+1,j).

So for each substring, we consider its longest 0 block (substrings with no 0 are always good). For convenience, if there are multiple maximum, we take the rightmost. 

The longest 0 block in substrings can be either a 0 block in the original string or part of 0 block in the original string. We can ignore substring in one 0 block, so the longest 0 block can only be a prefix or suffix, the number of possible longest 0 block is O(n).

For each possible 0 block (i,j), assume the longest substring that (i,j) is the longest 0 block is (i′,j′), we need to count answer for substring (l,r) that i′≤l≤i,j≤r≤j′, it is equivalent to count the number of l that i′≤l≤i−(j−i+1) and (l,i−1) is good and the number of r that j+(j−i+1)≤r≤j′ and (j+1,r) is good.

Notice that s[i−1]=s[j+1]=1, we can calculate them by above intervals.

We can use persistent segment tree directly or use segment tree or binary index tree after sorting queries. We need O(nlogn) modifications and O(n) queries. Thus we have solved our problem in O(nlog2n).

 **Code (tibinyte)**[**Click me**](https://codeforces.com/https://pastebin.com/epzbTXuY)

 **Rate Problem**Good problem 

 
[*22*](https://codeforces.com/data/like?action=like "I like this")



Ok problem 

 
[*2*](https://codeforces.com/data/like?action=like "I like this")



Bad problem 

 
[*9*](https://codeforces.com/data/like?action=like "I like this")



Didn't solve it, idk 

 
[*97*](https://codeforces.com/data/like?action=like "I like this")



**#LeafTON**

