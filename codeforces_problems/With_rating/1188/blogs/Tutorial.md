# Tutorial

Codes have been added!

We've added challenges(mostly not hard) to some tasks. Feel free to share solutions and ask any questions in comments!

Keanu Reeves
------------

If the string is good, then answer it's itself. Otherwise, there are at least two strings in answer, and we can print substring without its last symbol and its last symbol separately. Complexity O(n)O(n).

[code](https://codeforces.com/https://pastebin.com/Dc0gtG9n)

Number circle
-------------

Let's suppose that array is sorted. First of all, if an≥an−1+an−2an≥an−1+an−2, than the answer is — NO (because otherwise anan is not smaller than sum of the neighbors). We claim, that in all other cases answer is — YES. One of the possible constructions (if the array is already sorted) is:

an−2,an,an−1,an−4,an−5,…,a1an−2,an,an−1,an−4,an−5,…,a1

It's easy to see, that all numbers except anan will have at least one neighbor which is not smaller than itself. Complexity O(nlog(n))O(nlog(n)).

[code](https://codeforces.com/https://pastebin.com/7EbzzfHF)

Challenge

Solve the task in O(n) (if we suppose that all numbers don't exceed 109).

Candies!!!
----------

 **Solution 1 (magic)**Claim: f([a1,a2,…,a2k])=⌊a1+a2+…+a2k10⌋. Clearly, using it we can answer queries in O(1) if we create array prefsum, in which prefsum[i]=a1+…+ai.

 **Proof of claim**Imagine, that candy is equal to number 10. Then sum of all numbers doesn't change: when we replace (a,b)→((a+b)mod10) we take 10 iff a+b exceeds (a+b)mod10. Also note, that sum of numbers-candies is divisible by 10 (because we take only tens). Then, in the end, the remaining digit is equal to the remainder of the division of the initial sum by 10, so the number of candies is equal to the quotient. 

[code](https://codeforces.com/https://pastebin.com/VFb3M0nw)

Asymptotics is O(n+q).

 **Solution 2 (dp)**It's possible to solve the problem using dynamic programming. 

For each segment [sl,sl+1,…,sr], length of which is a power of two, we will save pair — digit, which will remain and the number of candies, which we get for this segment. For segment of length 1 this pair is (sl,0).

Note that there are at most logn different lengths of segments, and the number of segments with fixed length is at most n. It follows that there are at most nlogn segments.

Now solution is similar to building sparse table. We will calculate needed pairs for segments in the order of increasing of their length: firstly for segments of length 2, then for length 4, etc. It turns out that the answer for segment of length 2k can be calculated from smaller segments in constant time! Indeed, to get pair (last digit, number of candies) for [sl,sl+1,…,sl+2k−1], it's sufficient to know, how many candies we got in segments [sl,sl+1,…,sl+2k−1−1], [sl+2k−1,sl+2k−1+1,…,sl+2k−1], and also what digits dig1,dig2 were left last in this segments, then last digit on our segment is equal (dig1+dig2)mod10, also if dig1+dig2≥10, we get one more candy.

So, transition for one segment is made in O(1), which gives asymptotics O(nlogn).

[code](https://codeforces.com/https://pastebin.com/VmDrWjYN)

Add on a tree
-------------

We claim, that the answer is YES iff there is no vertex with degree 2. After this, it's easy to get a solution for first subtask in O(n).

 **Proof**Proof of necessity

If there is a vertex of degree 2, then after any number of operations numbers which are written on two outcoming edges will be equal. Indeed, any path between two leaves, which passes through one edge, passes through other. Hence, we can't get configuration, where numbers on these two edges are different.

Proof of sufficiency

We will show, that there exists a sequence of operation which adds x on the path between some vertex v and leaf u(and doesn't change numbers on other edges). If this vertex is leaf, than it's obvious. Otherwise, its degree is at least 3. Than, let's look at two leaves l1, l2, such that l1, l2, u lie in different subtrees of v. Then we will make the following operations:

 1. Add x2 on the path u,l1.
2. Add x2 on the path u,l2.
3. Add −x2 on t he path l1,l2.

So, we get, that we've added x on the path u,v.

Next step is to show how to get any configuration. Let ae be the number, which is needed to be written on the edge e after all operations. Let's root the tree from any vertex and recursively solve the task for subtrees in the following way:

solve(v):

if v doesn't have sons, then return.

 
```cpp
otherwise, for each son $u$ we wiil find a leaf in subtree of $u$ &mdash; let's name it $w$. Than, add $a_{uv}$ on the path 
$vw$ and recalculate needed numbers on the edge in this path(it means for each edge $e$ on the path make this - $a_e -= a_{uv}$), 
after it, call solve($u$).
```
So, there is an algorithm, which for any configuration gets it from all-zero configuration. Sufficiency is proved.

Because all numbers are different, in the second subtask if we have a vertex with degree 2 then answer is NO. If there is no such then construction also follows from proof. Indeed, if we can add on any path to leaf, then we can add on one edge. So, consider any edge uv and suppose we want to add x on this edge. Let's find any leaf in a subtree of vertex u, which doesn't contain v, let's name it l. If l=u, just add x on path uv. Else, add x on path vl and −x on path ul. It's clear, that after this two operations we've added x on edge uv and didn't add anything on other edges. Then, just add on each edge needed number.

In the end, let's talk about implementation. To add on the path to leaf it's sufficient to find a leaf in the subtree. We can do it naively in O(n), then complexity is O(n2). Also, we can precalculate leaves in each subtree and, for example, root tree at some leaf. Then, it's possible to do all operations in O(1), and complexity is O(n), but it wasn't needed.

Challenge

Solve task if numbers are not necessary even and different, but all operations should be also with integer x(now it turns out that sometimes it's possible to solve it in rationals, but not in integers).

[code for 1 subtask](https://codeforces.com/https://pastebin.com/AV0UUUKu) [code for 2 subtask](https://codeforces.com/https://pastebin.com/1sEegKhH)

Count pairs
-----------

Let's transform condtition a ittle bit. ai−aj≢0 mod p, so condtition is equivalent:

(ai−aj)(ai+aj)(a2i+a2j)≡(ai−aj)k⇔a4i−a4j≡kai−kaj⇔a4i−kai≡a4j−kaj.

That's why we just need to count number of pairs of equal numbers in the array bi=(a4i−kai) mod p. It's easy to do it, for example, using map. Complexity O(n) or O(nlog(n)).

[code](https://codeforces.com/https://pastebin.com/E12bDQNW)

Challenge

Solve the task, if numbers are not necessarily different.

Array beauty
------------

First of all, let's learn how to solve the following subtask:

For given x how many subsequences of length k have beauty at least x? If we know that the answer for x is px, than the answer for original task is p1+p2+…+pmax(a), where max(a) is maximum in array a. Let's solve subtask.

Suppose, that array is sorted. We should count subsequence p1<p2,…<pk, iff:

ap2≥ap1+x,…,apk≥apk−1+x.

We will solve this task using dp. The slow solution is: 

dp[last][cnt] — number of subsequences of length cnt, which end in alast. There are transitions from state with last′<last,cnt′=cnt−1, such that alast≥alast′+x. To optimize it we need to note, that suitable last′ form some prefix of the array. If we know needed prefixes and prefix sums from the previous layer of dp, then we can make transitions in constant time. We can find needed prefixes using two pointers(because it's obvious, that length of prefixes doesn't decrease). So, we can solve subtask in O(nk) time.

And, using solution to subtask, we can solve inital task in O(max(a)nk). And here comes magic:

If x>max(a)k−1, than px=0. Indeed, если ap2≥ap1+x,…,apk≥apk−1+x, than:

an≥apk≥apk−1+x≥apk−2+2x…≥ap1+(k−1)x≥(k−1)x. It follows: (k−1)x≤an⇔x≤ank−1. 

So we can run our dp only for x≤max(a)k−1. In total our solution works in O(max(a)k−1nk)=O(max(a)n) time, because kk−1≤2.

Challenge

How fast you can solve the task if you need to print answer for all 2≤k≤n?

[code](https://codeforces.com/https://pastebin.com/CQxyYnR3)

Make equal
----------

We will suppose, that array is sorted. Let x be the final number. Than x≥an. Also, if we define bits[c] — as number of ones in binary notation of c, than, to get x from ai we will spend at least bits[x−ai] moves(it follows from the fact, that minumum number of powers of two, which in sum are equal to the number, corresponds to it binary notation). Let t=x−an, than x−ai=t+an−ai. So we need the following task:

Minimize sum bits[t+an−a1]+bits[t+an−a2]+…+bits[t+an−an], where t is some nonnegative integer. Also, let's define bi as an−ai.

We will solve this task using dp — value, which we want to minimize is sum bits[t+bi], taken over bits up to (k−1). Then, suppose we want to decide something about k-th bit. Let's understand, which information from the previous bits is needed for us. Imagine, that we sum t и bi in vertical format. Clearly, to find k-th bit in number t+bi it's sufficient to know k-th bit in number t and do we have carry from previous digit. Furthermore, if we know this information for the previous bit, we can get it for the next(carry in new digit will occur iff bitk[bi] + bitk[t] + (didwehavecarry)≥2). But we should save information about carry for all numbers t+bi, so, at first sight, for one bit we have at least 2n different states of dp. To reduce the number of states we need to note key fact:

Let t′=t mod 2k, c′=c mod 2k. Than, carry in k-th bit will occur t+c iff t′+c′≥2k. Indeed, carry corresponds to the fact that the sum of "cutoff" numbers is at least 2k. 

Using this fact we understand that, if we sort numbers b′i=bi mod 2k, than carry in k-th bit will happen only for some suffix of b′i. That's why, we get n+1 different states for one bit, which is good. So we only need to learn how to make transitions fast. It's useful to note, that we don't need to know numbers bi, it's sufficient to know do we have a carry and value of k-th bit of bi. Then, transition reduces to count the number of 1 and 0 in k-th bit on some segment of the array sorted by b′i. This can be easily done in constant time if we precalculated prefix sums(for better understanding you can read attached code). So, we can solve the task in nlog(n)F time, where F is bit up to which we'll write dp. So, it' left to show (or to believe :)), that there is no sense to consider big F. 

 **Not so long proof**Let t be minimum optimal solution and let's suppose that t>b1. Because a1 is minimum in a, than b1 is maximum in b. Let s be the most significant bit of number t+b1. Than, 2s+1>t+b1≥2s. Than, 2t>2s, from what t>2s−1. It follows, that the most significant bit of numbers t+bi is s, or s−1. That's why, if we consider t′=t−2s−1 we will get:

bits[t′+bi]=bits[t+bi]−1, if at positon s−1 in binary notation t+bi was 1.

bits[t′+bi]=bits[t+bi], if at position s−1 in binary notation t+bi was 0(because in this case the most significant bit of t+bi is s). 

So, t′ gives the answer which is not bigger than t. So, we can suppose that the optimal solution is not bigger than b1≤an. 

Now we can honestly say that complexity of solution is O(nlog(n)log(max(a)).

[code](https://codeforces.com/https://pastebin.com/usq1czKq)

Challenge

Can you solve task in O(nlog(max(a))?

Problem from Red Panda.
-----------------------

We'll suppose(as in 3 tasks before), that the array is sorted. Our operation is equivalent to choosing some 1≤i≤k and increasing ai by k−1, аnd decreasing remaining ai by one. To solve the task, we need to make some claims:

Claim 1

Difference ai−aj mod k doesn't change for any i,j. Moreover, in one move ai shifts by 1 mod k.

Claim 2

If we've made two sequences of moves of length i and j, where i<k, j<k, then obtained configurations coincide iff i=j and chosen colors coincide as multisets(orders can be different, but number of times we've chosen each color needs to be equal).

Proof

Because in one side claim is obvious, we will suppose, that obtained configurations are equal and we'll show that multisets of colors are also equal. Let's define number of baloons, which we've got using first sequence, as bt and ct for the second. Because bt≡bt−i mod k, ct≡at−j mod k, то i=j. Let's note that bt=at−i+k⋅addB[t], where addB[t] — number of times we've chosen color t. So, we get that addB[t]=addC[t] for each 1≤t≤k. 

Claim 3

If there is i, such that ai+1<i, then we'll not make more than i−1 moves.

Proof

On each move we choose exactly one color, so after i moves there will be at least one color among first i+1 that we didn't choose. But then, the number of balloons of this color will be less than i−i=0, which is not allowed.

Let's call minimum index i from Claim 3(if it exists) critical.

Claim 4

Suppose critical index is equal to i. Assume, that we decided to make j<k moves and we've fixed number of choices of each color — add[t]. It's clear, that add[t]≥0,add[1]+add[2]+…add[k]=j. Then, there exist correct sequence of moves with this number of choices iff:

 1. j<i
2. If at<j, then add[t]>0.

 **Not so long proof**Proof of necessity

From Claim 3 j<i. If at<j, then we should choose color t at least one time, so condition 2 is also necessary.

Proof of sufficiency

Let's build this sequence greedily: on each move we will choose such color t that add[t]>0 and at is minumum(if we choose color t, then we change ai and decrease add[t] by 1). We will show that this sequence is correct. It's clear that it can be incorrect only if we get that ap<0 in some moment. Define x — number of first move after which we have such situation(we'll suppose that p is index in the inital sorted a). Note, that because j<i<k, if we've chosen color at least one time, than number of balloons in it will not become negative(because after any move it will be at least k−j). That's why(because x was defined as first "bad" move) ap=x−1. It follows ap<j, so add[p]>0. So, we get that we didn't manage to choose color p, and that's why in the initial array we had at least x colors v, such that av≤ap, so p≥x+1. So, ax+1≤ap=x−1<x — contradiction, because i is critical index(and j < i). So we've proved that greedy works and sufficiency is proved.

Using these claims, we can solve the problem if the critical index exists and is equal to i:

Let's iterate through all possible number of moves between 0 and i−1, suppose it's equal to x. Then, by Claim 4 we know that, if ap<x, then add[p]>0, else there are no restrictions (except obvious add[p]≥0). So, we have arrived to the following problem:

Count the number of nonnegative solutions add[1]+…+add[k]=x, where fixed num numbers should be positive. By Claims 2 and 4 the solutions of this equation correspond to some final configuration, and this is exactly what we need to count.

This is well known task(stars and bars), answer is given by Cx−num+k−1k−1

So, the answer is given by the sum of these values over all x.

Let's call configuration critical, if it has critical element (in other words, if there is index i such that i<k−1 and at least i+2 elements of configuration do not exceed i).

To solve the problem when there is no critical index we need:

Claim 5

If configuration is not critical, then configuration bi is reachable iff ai−bi≡aj−bj mod k and bi≥0, a1+…ak=b1+…bk.

 **Long proof**Proof

It easily follows by Claim 1 that these conditions are indeed necessary. Let's show, that if configuration bi satisfies all conditions, then we can get it.

First of all, let's go from another end. "Backward operation" in our case is to take one of the bi≥k−1, substract k−1 from it and increase remaining by one. If we can get this configuration, then by making one more operation we'll get configuration b.

Now let's try to make backward operations, so that bi will lie in segment [S,S+k−1] for some S. So, suppose that now maximum number — bmax and minimum — bmin. If bmax≥bmin+k, then let's do backward for bmax all numbers will become at least bmin+1. Doing this we increase minimum by one, so after finite number of operations we'll stop and all numbers will lie in [S,S+k−1] for some S.

Because a is not critical, it follows that ai≥i−1 for all i. Then, let's choose color 1 and show that after this operation the configuration is critical. Suppose it's not true: so there is i<k−1, such that in new configuration at least i+2 numbers do exceed i. It's not true for i=k−2 because a1/gek−1(in new configuration). For i<k−2 it also can't be true, because if at least i+2 numbers do not exceed i+1, then a1 will be one of them. After doing operation only these numbers can be not greater than i, but a1 will become bigger than i. So, there are no more than i+1 numbers which are at most i, so configuration is indeed not critical.

Note that all numbers decreased by one modulo k. Because we've shown that applying our operation to the "minimum" color leaves configuration noncritical, we can make some shifts before we get that a1≡b1modk. From this will follow that ai≡bi mod k for all i.

Now, let's try to do the following: if the configuration is critical and amax>amin+k, add k to amin and substract amax by k. We still suppose that the array is sorted, so ai≥i−1 and ak>a1+k. Then let's make such sequence of operations: choose i=1,…,k−1 in this order(it's easy to see that we can do it because ai≥i−1). Now we have such configuration: a1+1,a2+1,…,ak−1+1,ak−(k−1). Now, choose 1 one more time, so we get a1+k,a2,a3,…,ak−1,ak−k. It's easy to see, that it's not critical. Indeed, for each i<k−1 no more than i+1 numbers in old configuration were not bigger than i. Note, that ak wasn't in this list. k−2 numbers in array didn't change, a1+k is surely not in this list and ak−k>a1, so number of integers not bigger than i will not become bigger. 

So, that's why we can substract k from maximum and add it to the minimum, if the difference between them is at least k+1, and configuration will remain critical.

Let's do it as many times as possible. This process will stop, because sum of squares decreases: a21+a2k>(a1+k)2+(ak−k)2⟺2k(ak−a1)>2k2⟺ak−a1>k, which is true by assumption. So, at some moment we will get configuration whic lies at segment [T,T+k] for some T.

Note, that for new ai and bi it's still true ai≡bimodk, S≤bi≤S+k−1, T≤ai≤T+k, a1+a2+…ak=b1+b2+…bk. Let's show, that from this conditions ai=bi for all i. Indeed, in case S≤T we get bi≤S+k−1≤T+k−1≤ai+k−1, but ai≡bi mod k, so bi≤ai for all i. Because sum of a and b is equal, it follows ai=bi for all i. Also in other case, if S>T, ai≤T+k≤S+k−1≤bi+k−1, from what we still get ai=bi for all i.

So, doing operations with a and backward operations with b we get equal configurations. It follows that b is reachable from a, the claim is proved.

Now, it only remains to show how to count the number of such b from Claim 5.

b1,b2,…,bk should give remainders (a1+t)modk,(a2+t)modk,…,(ak+t)modk for some t. We сan calculate configurations with such remainders by the following way: remaining a1+a2+…+ak−(a1+t)modk−(a2+t)modk−…−(ak+t)modk are splitted in groups by k and are distributed in k elements in any way. So, that's why, for given t number of configurations(by stars and bars) is given by Ca1+a2+…+ak−(a1+t)modk−(a2+t)modk−…−(ak+t)modkk+k−1k−1. Sum a1+a2+…+ak−(a1+t)modk−(a2+t)modk−…−(ak+t)modk can be calculated for t=0,1,…,k−1 in O(1), if we precalculate number of each remainder among a1,a2,…,ak.

That's why final complexity for each of the cases is O(n+k).

[code](https://codeforces.com/https://pastebin.com/CzXWU4nX)

Challenge 

Find all typos in proofs.

