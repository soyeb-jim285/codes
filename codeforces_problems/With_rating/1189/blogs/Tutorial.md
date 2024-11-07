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

ChallengeChallenge

Solve the task in O(n)O(n) (if we suppose that all numbers don't exceed 109109).

Candies!!!
----------

 **Solution 1 (magic)**Claim: f([a1,a2,…,a2k])=⌊a1+a2+…+a2k10⌋f([a1,a2,…,a2k])=⌊a1+a2+…+a2k10⌋. Clearly, using it we can answer queries in O(1)O(1) if we create array prefsumprefsum, in which prefsum[i]=a1+…+aiprefsum[i]=a1+…+ai.

 **Proof of claim**Imagine, that candy is equal to number 1010. Then sum of all numbers doesn't change: when we replace (a,b)→((a+b)mod10)(a,b)→((a+b)mod10) we take 1010 iff a+ba+b exceeds (a+b)mod10(a+b)mod10. Also note, that sum of numbers-candies is divisible by 1010 (because we take only tens). Then, in the end, the remaining digit is equal to the remainder of the division of the initial sum by 1010, so the number of candies is equal to the quotient. 

[code](https://codeforces.com/https://pastebin.com/VFb3M0nw)

Asymptotics is O(n+q)O(n+q).

 **Solution 2 (dp)**It's possible to solve the problem using dynamic programming. 

For each segment [sl,sl+1,…,sr][sl,sl+1,…,sr], length of which is a power of two, we will save pair — digit, which will remain and the number of candies, which we get for this segment. For segment of length 11 this pair is (sl,0)(sl,0).

Note that there are at most lognlog⁡n different lengths of segments, and the number of segments with fixed length is at most nn. It follows that there are at most nlognnlog⁡n segments.

Now solution is similar to building sparse table. We will calculate needed pairs for segments in the order of increasing of their length: firstly for segments of length 22, then for length 44, etc. It turns out that the answer for segment of length 2k2k can be calculated from smaller segments in constant time! Indeed, to get pair (last digit, number of candies) for [sl,sl+1,…,sl+2k−1][sl,sl+1,…,sl+2k−1], it's sufficient to know, how many candies we got in segments [sl,sl+1,…,sl+2k−1−1][sl,sl+1,…,sl+2k−1−1], [sl+2k−1,sl+2k−1+1,…,sl+2k−1][sl+2k−1,sl+2k−1+1,…,sl+2k−1], and also what digits dig1,dig2dig1,dig2 were left last in this segments, then last digit on our segment is equal (dig1+dig2)mod10(dig1+dig2)mod10, also if dig1+dig2≥10dig1+dig2≥10, we get one more candy.

So, transition for one segment is made in O(1)O(1), which gives asymptotics O(nlogn)O(nlog⁡n).

[code](https://codeforces.com/https://pastebin.com/VmDrWjYN)

Add on a tree
-------------

We claim, that the answer is YES iff there is no vertex with degree 2. After this, it's easy to get a solution for first subtask in O(n)O(n).

 **Proof**Proof of necessity

If there is a vertex of degree 2, then after any number of operations numbers which are written on two outcoming edges will be equal. Indeed, any path between two leaves, which passes through one edge, passes through other. Hence, we can't get configuration, where numbers on these two edges are different.

Proof of sufficiency

We will show, that there exists a sequence of operation which adds xx on the path between some vertex vv and leaf uu(and doesn't change numbers on other edges). If this vertex is leaf, than it's obvious. Otherwise, its degree is at least 3. Than, let's look at two leaves l1l1, l2l2, such that l1l1, l2l2, uu lie in different subtrees of vv. Then we will make the following operations:

 1. Add x2x2 on the path u,l1u,l1.
2. Add x2x2 on the path u,l2u,l2.
3. Add −x2−x2 on t he path l1,l2l1,l2.

So, we get, that we've added xx on the path u,vu,v.

Next step is to show how to get any configuration. Let aeae be the number, which is needed to be written on the edge ee after all operations. Let's root the tree from any vertex and recursively solve the task for subtrees in the following way:

solve(vv):

if vv doesn't have sons, then return.

 
```cpp
otherwise, for each son $u$ we wiil find a leaf in subtree of $u$ &mdash; let's name it $w$. Than, add $a_{uv}$ on the path 
$vw$ and recalculate needed numbers on the edge in this path(it means for each edge $e$ on the path make this - $a_e -= a_{uv}$), 
after it, call solve($u$).
```
So, there is an algorithm, which for any configuration gets it from all-zero configuration. Sufficiency is proved.

Because all numbers are different, in the second subtask if we have a vertex with degree 22 then answer is NO. If there is no such then construction also follows from proof. Indeed, if we can add on any path to leaf, then we can add on one edge. So, consider any edge uvuv and suppose we want to add xx on this edge. Let's find any leaf in a subtree of vertex uu, which doesn't contain vv, let's name it ll. If l=ul=u, just add xx on path uvuv. Else, add xx on path vlvl and −x−x on path ulul. It's clear, that after this two operations we've added xx on edge uvuv and didn't add anything on other edges. Then, just add on each edge needed number.

In the end, let's talk about implementation. To add on the path to leaf it's sufficient to find a leaf in the subtree. We can do it naively in O(n)O(n), then complexity is O(n2)O(n2). Also, we can precalculate leaves in each subtree and, for example, root tree at some leaf. Then, it's possible to do all operations in O(1)O(1), and complexity is O(n)O(n), but it wasn't needed.

ChallengeChallenge

Solve task if numbers are not necessary even and different, but all operations should be also with integer xx(now it turns out that sometimes it's possible to solve it in rationals, but not in integers).

[code for 1 subtask](https://codeforces.com/https://pastebin.com/AV0UUUKu) [code for 2 subtask](https://codeforces.com/https://pastebin.com/1sEegKhH)

Count pairs
-----------

Let's transform condtition a ittle bit. ai−aj≢0ai−aj≢0 modmod pp, so condtition is equivalent:

(ai−aj)(ai+aj)(a2i+a2j)≡(ai−aj)k⇔a4i−a4j≡kai−kaj⇔a4i−kai≡a4j−kaj(ai−aj)(ai+aj)(ai2+aj2)≡(ai−aj)k⇔ai4−aj4≡kai−kaj⇔ai4−kai≡aj4−kaj.

That's why we just need to count number of pairs of equal numbers in the array bi=(a4i−kai)bi=(ai4−kai) modmod pp. It's easy to do it, for example, using map. Complexity O(n)O(n) or O(nlog(n))O(nlog(n)).

[code](https://codeforces.com/https://pastebin.com/E12bDQNW)

ChallengeChallenge

Solve the task, if numbers are not necessarily different.

Array beauty
------------

First of all, let's learn how to solve the following subtask:

For given xx how many subsequences of length kk have beauty at least xx? If we know that the answer for xx is pxpx, than the answer for original task is p1+p2+…+pmax(a)p1+p2+…+pmax(a), where max(a)max(a) is maximum in array aa. Let's solve subtask.

Suppose, that array is sorted. We should count subsequence p1<p2,…<pkp1<p2,…<pk, iff:

ap2≥ap1+x,…,apk≥apk−1+xap2≥ap1+x,…,apk≥apk−1+x.

We will solve this task using dp. The slow solution is: 

dp[last][cnt]dp[last][cnt] — number of subsequences of length cntcnt, which end in alastalast. There are transitions from state with last′<last,cnt′=cnt−1last′<last,cnt′=cnt−1, such that alast≥alast′+xalast≥alast′+x. To optimize it we need to note, that suitable last′last′ form some prefix of the array. If we know needed prefixes and prefix sums from the previous layer of dp, then we can make transitions in constant time. We can find needed prefixes using two pointers(because it's obvious, that length of prefixes doesn't decrease). So, we can solve subtask in O(nk)O(nk) time.

And, using solution to subtask, we can solve inital task in O(max(a)nk)O(max(a)nk). And here comes magic:

If x>max(a)k−1x>max(a)k−1, than px=0px=0. Indeed, если ap2≥ap1+x,…,apk≥apk−1+xap2≥ap1+x,…,apk≥apk−1+x, than:

an≥apk≥apk−1+x≥apk−2+2x…≥ap1+(k−1)x≥(k−1)xan≥apk≥apk−1+x≥apk−2+2x…≥ap1+(k−1)x≥(k−1)x. It follows: (k−1)x≤an⇔x≤ank−1(k−1)x≤an⇔x≤ank−1. 

So we can run our dp only for x≤max(a)k−1x≤max(a)k−1. In total our solution works in O(max(a)k−1nk)=O(max(a)n)O(max(a)k−1nk)=O(max(a)n) time, because kk−1≤2kk−1≤2.

ChallengeChallenge

How fast you can solve the task if you need to print answer for all 2≤k≤n2≤k≤n?

[code](https://codeforces.com/https://pastebin.com/CQxyYnR3)

Make equal
----------

We will suppose, that array is sorted. Let xx be the final number. Than x≥anx≥an. Also, if we define bits[c]bits[c] — as number of ones in binary notation of cc, than, to get xx from aiai we will spend at least bits[x−ai]bits[x−ai] moves(it follows from the fact, that minumum number of powers of two, which in sum are equal to the number, corresponds to it binary notation). Let t=x−ant=x−an, than x−ai=t+an−aix−ai=t+an−ai. So we need the following task:

Minimize sum bits[t+an−a1]+bits[t+an−a2]+…+bits[t+an−an]bits[t+an−a1]+bits[t+an−a2]+…+bits[t+an−an], where tt is some nonnegative integer. Also, let's define bibi as an−aian−ai.

We will solve this task using dp — value, which we want to minimize is sum bits[t+bi]bits[t+bi], taken over bits up to (k−1)(k−1). Then, suppose we want to decide something about kk-th bit. Let's understand, which information from the previous bits is needed for us. Imagine, that we sum tt и bibi in vertical format. Clearly, to find kk-th bit in number t+bit+bi it's sufficient to know kk-th bit in number tt and do we have carry from previous digit. Furthermore, if we know this information for the previous bit, we can get it for the next(carry in new digit will occur iff bitk[bi]bitk[bi] + bitk[t]bitk[t] + (didwehavecarry)≥2(didwehavecarry)≥2). But we should save information about carry for all numbers t+bit+bi, so, at first sight, for one bit we have at least 2n2n different states of dp. To reduce the number of states we need to note key fact:

Let t′=tt′=t modmod 2k2k, c′=cc′=c modmod 2k2k. Than, carry in kk-th bit will occur t+ct+c iff t′+c′≥2kt′+c′≥2k. Indeed, carry corresponds to the fact that the sum of "cutoff" numbers is at least 2k2k. 

Using this fact we understand that, if we sort numbers b′i=bibi′=bi modmod 2k2k, than carry in kk-th bit will happen only for some suffix of b′ibi′. That's why, we get n+1n+1 different states for one bit, which is good. So we only need to learn how to make transitions fast. It's useful to note, that we don't need to know numbers bibi, it's sufficient to know do we have a carry and value of kk-th bit of bibi. Then, transition reduces to count the number of 11 and 00 in kk-th bit on some segment of the array sorted by b′ibi′. This can be easily done in constant time if we precalculated prefix sums(for better understanding you can read attached code). So, we can solve the task in nlog(n)Fnlog(n)F time, where FF is bit up to which we'll write dp. So, it' left to show (or to believe :)), that there is no sense to consider big FF. 

 **Not so long proof**Let tt be minimum optimal solution and let's suppose that t>b1t>b1. Because a1a1 is minimum in aa, than b1b1 is maximum in bb. Let ss be the most significant bit of number t+b1t+b1. Than, 2s+1>t+b1≥2s2s+1>t+b1≥2s. Than, 2t>2s2t>2s, from what t>2s−1t>2s−1. It follows, that the most significant bit of numbers t+bit+bi is ss, or s−1s−1. That's why, if we consider t′=t−2s−1t′=t−2s−1 we will get:

bits[t′+bi]=bits[t+bi]−1bits[t′+bi]=bits[t+bi]−1, if at positon s−1s−1 in binary notation t+bit+bi was 1.

bits[t′+bi]=bits[t+bi]bits[t′+bi]=bits[t+bi], if at position s−1s−1 in binary notation t+bit+bi was 0(because in this case the most significant bit of t+bit+bi is ss). 

So, t′t′ gives the answer which is not bigger than tt. So, we can suppose that the optimal solution is not bigger than b1≤anb1≤an. 

Now we can honestly say that complexity of solution is O(nlog(n)log(max(a))O(nlog(n)log(max(a)).

[code](https://codeforces.com/https://pastebin.com/usq1czKq)

ChallengeChallenge

Can you solve task in O(nlog(max(a))O(nlog(max(a))?

Problem from Red Panda.
-----------------------

We'll suppose(as in 3 tasks before), that the array is sorted. Our operation is equivalent to choosing some 1≤i≤k1≤i≤k and increasing aiai by k−1k−1, аnd decreasing remaining aiai by one. To solve the task, we need to make some claims:

Claim 1Claim 1

Difference ai−ajai−aj modmod kk doesn't change for any i,ji,j. Moreover, in one move aiai shifts by 11 modmod kk.

Claim 2Claim 2

If we've made two sequences of moves of length ii and jj, where i<ki<k, j<kj<k, then obtained configurations coincide iff i=ji=j and chosen colors coincide as multisets(orders can be different, but number of times we've chosen each color needs to be equal).

Proof

Because in one side claim is obvious, we will suppose, that obtained configurations are equal and we'll show that multisets of colors are also equal. Let's define number of baloons, which we've got using first sequence, as btbt and ctct for the second. Because bt≡bt−ibt≡bt−i modmod kk, ct≡at−jct≡at−j modmod kk, то i=ji=j. Let's note that bt=at−i+k⋅addB[t]bt=at−i+k⋅addB[t], where addB[t]addB[t] — number of times we've chosen color tt. So, we get that addB[t]=addC[t]addB[t]=addC[t] for each 1≤t≤k1≤t≤k. 

Claim 3Claim 3

If there is ii, such that ai+1<iai+1<i, then we'll not make more than i−1i−1 moves.

Proof

On each move we choose exactly one color, so after ii moves there will be at least one color among first i+1i+1 that we didn't choose. But then, the number of balloons of this color will be less than i−i=0i−i=0, which is not allowed.

Let's call minimum index ii from Claim 3(if it exists) critical.

Claim 4Claim 4

Suppose critical index is equal to ii. Assume, that we decided to make j<kj<k moves and we've fixed number of choices of each color — add[t]add[t]. It's clear, that add[t]≥0,add[1]+add[2]+…add[k]=jadd[t]≥0,add[1]+add[2]+…add[k]=j. Then, there exist correct sequence of moves with this number of choices iff:

 1. j<ij<i
2. If at<jat<j, then add[t]>0add[t]>0.

 **Not so long proof**Proof of necessity

From Claim 3 j<ij<i. If at<jat<j, then we should choose color tt at least one time, so condition 2 is also necessary.

Proof of sufficiency

Let's build this sequence greedily: on each move we will choose such color tt that add[t]>0add[t]>0 and atat is minumum(if we choose color tt, then we change aiai and decrease add[t]add[t] by 1). We will show that this sequence is correct. It's clear that it can be incorrect only if we get that ap<0ap<0 in some moment. Define xx — number of first move after which we have such situation(we'll suppose that pp is index in the inital sorted aa). Note, that because j<i<kj<i<k, if we've chosen color at least one time, than number of balloons in it will not become negative(because after any move it will be at least k−jk−j). That's why(because xx was defined as first "bad" move) ap=x−1ap=x−1. It follows ap<jap<j, so add[p]>0add[p]>0. So, we get that we didn't manage to choose color pp, and that's why in the initial array we had at least xx colors vv, such that av≤apav≤ap, so p≥x+1p≥x+1. So, ax+1≤ap=x−1<xax+1≤ap=x−1<x — contradiction, because ii is critical index(and jj < ii). So we've proved that greedy works and sufficiency is proved.

Using these claims, we can solve the problem if the critical index exists and is equal to ii:

Let's iterate through all possible number of moves between 00 and i−1i−1, suppose it's equal to xx. Then, by Claim 4 we know that, if ap<xap<x, then add[p]>0add[p]>0, else there are no restrictions (except obvious add[p]≥0add[p]≥0). So, we have arrived to the following problem:

Count the number of nonnegative solutions add[1]+…+add[k]=xadd[1]+…+add[k]=x, where fixed numnum numbers should be positive. By Claims 2 and 4 the solutions of this equation correspond to some final configuration, and this is exactly what we need to count.

This is well known task(stars and bars), answer is given by Cx−num+k−1k−1Ck−1x−num+k−1

So, the answer is given by the sum of these values over all xx.

Let's call configuration criticalcritical, if it has critical element (in other words, if there is index ii such that i<k−1i<k−1 and at least i+2i+2 elements of configuration do not exceed ii).

To solve the problem when there is no critical index we need:

Claim 5Claim 5

If configuration is not critical, then configuration bibi is reachable iff ai−bi≡aj−bjai−bi≡aj−bj modmod kk and bi≥0bi≥0, a1+…ak=b1+…bka1+…ak=b1+…bk.

 **Long proof**Proof

It easily follows by Claim 1 that these conditions are indeed necessary. Let's show, that if configuration bibi satisfies all conditions, then we can get it.

First of all, let's go from another end. "Backward operation" in our case is to take one of the bi≥k−1bi≥k−1, substract k−1k−1 from it and increase remaining by one. If we can get this configuration, then by making one more operation we'll get configuration bb.

Now let's try to make backward operations, so that bibi will lie in segment [S,S+k−1][S,S+k−1] for some SS. So, suppose that now maximum number — bmaxbmax and minimum — bminbmin. If bmax≥bmin+kbmax≥bmin+k, then let's do backward for bmaxbmax all numbers will become at least bmin+1bmin+1. Doing this we increase minimum by one, so after finite number of operations we'll stop and all numbers will lie in [S,S+k−1][S,S+k−1] for some SS.

Because aa is not critical, it follows that ai≥i−1ai≥i−1 for all ii. Then, let's choose color 11 and show that after this operation the configuration is critical. Suppose it's not true: so there is i<k−1i<k−1, such that in new configuration at least i+2i+2 numbers do exceed ii. It's not true for i=k−2i=k−2 because a1/gek−1a1/gek−1(in new configuration). For i<k−2i<k−2 it also can't be true, because if at least i+2i+2 numbers do not exceed i+1i+1, then a1a1 will be one of them. After doing operation only these numbers can be not greater than ii, but a1a1 will become bigger than ii. So, there are no more than i+1i+1 numbers which are at most ii, so configuration is indeed not critical.

Note that all numbers decreased by one modulo kk. Because we've shown that applying our operation to the "minimum" color leaves configuration noncritical, we can make some shifts before we get that a1≡b1modka1≡b1modk. From this will follow that ai≡biai≡bi modmod kk for all ii.

Now, let's try to do the following: if the configuration is critical and amax>amin+kamax>amin+k, add kk to aminamin and substract amaxamax by k. We still suppose that the array is sorted, so ai≥i−1ai≥i−1 and ak>a1+kak>a1+k. Then let's make such sequence of operations: choose i=1,…,k−1i=1,…,k−1 in this order(it's easy to see that we can do it because ai≥i−1ai≥i−1). Now we have such configuration: a1+1,a2+1,…,ak−1+1,ak−(k−1)a1+1,a2+1,…,ak−1+1,ak−(k−1). Now, choose 11 one more time, so we get a1+k,a2,a3,…,ak−1,ak−ka1+k,a2,a3,…,ak−1,ak−k. It's easy to see, that it's not critical. Indeed, for each i<k−1i<k−1 no more than i+1i+1 numbers in old configuration were not bigger than ii. Note, that akak wasn't in this list. k−2k−2 numbers in array didn't change, a1+ka1+k is surely not in this list and ak−k>a1ak−k>a1, so number of integers not bigger than ii will not become bigger. 

So, that's why we can substract kk from maximum and add it to the minimum, if the difference between them is at least k+1k+1, and configuration will remain critical.

Let's do it as many times as possible. This process will stop, because sum of squares decreases: a21+a2k>(a1+k)2+(ak−k)2⟺2k(ak−a1)>2k2⟺ak−a1>ka12+ak2>(a1+k)2+(ak−k)2⟺2k(ak−a1)>2k2⟺ak−a1>k, which is true by assumption. So, at some moment we will get configuration whic lies at segment [T,T+k][T,T+k] for some TT.

Note, that for new aiai and bibi it's still true ai≡bimodkai≡bimodk, S≤bi≤S+k−1S≤bi≤S+k−1, T≤ai≤T+kT≤ai≤T+k, a1+a2+…ak=b1+b2+…bka1+a2+…ak=b1+b2+…bk. Let's show, that from this conditions ai=biai=bi for all ii. Indeed, in case S≤TS≤T we get bi≤S+k−1≤T+k−1≤ai+k−1bi≤S+k−1≤T+k−1≤ai+k−1, but ai≡biai≡bi modmod kk, so bi≤aibi≤ai for all ii. Because sum of aa and bb is equal, it follows ai=biai=bi for all ii. Also in other case, if S>TS>T, ai≤T+k≤S+k−1≤bi+k−1ai≤T+k≤S+k−1≤bi+k−1, from what we still get ai=biai=bi for all ii.

So, doing operations with aa and backward operations with bb we get equal configurations. It follows that bb is reachable from aa, the claim is proved.

Now, it only remains to show how to count the number of such bb from Claim 5.

b1,b2,…,bkb1,b2,…,bk should give remainders (a1+t)modk,(a2+t)modk,…,(ak+t)modk(a1+t)modk,(a2+t)modk,…,(ak+t)modk for some tt. We сan calculate configurations with such remainders by the following way: remaining a1+a2+…+ak−(a1+t)modk−(a2+t)modk−…−(ak+t)modka1+a2+…+ak−(a1+t)modk−(a2+t)modk−…−(ak+t)modk are splitted in groups by kk and are distributed in kk elements in any way. So, that's why, for given tt number of configurations(by stars and bars) is given by Ca1+a2+…+ak−(a1+t)modk−(a2+t)modk−…−(ak+t)modkk+k−1k−1Ck−1a1+a2+…+ak−(a1+t)modk−(a2+t)modk−…−(ak+t)modkk+k−1. Sum a1+a2+…+ak−(a1+t)modk−(a2+t)modk−…−(ak+t)modka1+a2+…+ak−(a1+t)modk−(a2+t)modk−…−(ak+t)modk can be calculated for t=0,1,…,k−1t=0,1,…,k−1 in O(1)O(1), if we precalculate number of each remainder among a1,a2,…,aka1,a2,…,ak.

That's why final complexity for each of the cases is O(n+k)O(n+k).

[code](https://codeforces.com/https://pastebin.com/CzXWU4nX)

ChallengeChallenge 

Find all typos in proofs.

