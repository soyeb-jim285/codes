# Good_Bye_2023_tutorial_(en)

Thanks for your participating!

author: [74TrAkToR](https://codeforces.com/profile/74TrAkToR "International Master 74TrAkToR"), developer: [marzipan](https://codeforces.com/profile/marzipan "Expert marzipan"), [zwezdinv](https://codeforces.com/profile/zwezdinv "Grandmaster zwezdinv") 

### [1916A - 2023](../problems/A._2023.md "Good Bye 2023")

Let the product of the numbers in our array be xx. If 20232023 is not divisible by xx, then the answer is NO, otherwise the answer is YES. One of the ways to construct the removed numbers is as follows—11 number 2023x2023x and k−1k−1 numbers 11.

author: [OR_LOVe](https://codeforces.com/profile/OR_LOVe "Expert OR_LOVe"), developer: [marzipan](https://codeforces.com/profile/marzipan "Expert marzipan") 

### [1916B - Two Divisors](../problems/B._Two_Divisors.md "Good Bye 2023")

First case: bmoda=0bmoda=0.

In this case, b=a⋅pb=a⋅p, where pp is the smallest prime factor of xx. Then x=b⋅p=b⋅bax=b⋅p=b⋅ba.

Second case: bmoda≠0bmoda≠0.

In this case, b=xp,a=xqb=xp,a=xq, where p,qp,q are the two smallest prime factors of xx. Then gcd(a,b)=xp⋅q,x=b⋅p=b⋅agcd(a,b)gcd(a,b)=xp⋅q,x=b⋅p=b⋅agcd(a,b).

author: [azureglow](https://codeforces.com/profile/azureglow "Master azureglow"), developer: [marzipan](https://codeforces.com/profile/marzipan "Expert marzipan") 

### [1916C - Training Before the Olympiad](../problems/C._Training_Before_the_Olympiad.md "Good Bye 2023")

Note that our operation replaces two numbers with their sum if they are of the same parity, and with their sum −1−1 otherwise. Therefore, the second player needs to perform as many operations as possible where an even and an odd number are used. Also, note that on any move of the second player, there will be at least one even number that the first player made on the previous move. Then our task for the first player is to remove two odd numbers as often as possible. It can also be observed that the number of odd numbers in the array does not decrease, which means all operations with two odd numbers will go before operations with two even numbers. And after each such move, the second player will remove one odd number from the array. That is, in two moves, the number of odd numbers decreases by 33. Let's consider all possible remainders of the number of odd numbers modulo 33. If the remainder is 00, then the answer is sum−cnt3sum−cnt3, where sumsum is the sum of all numbers. If the remainder modulo is 11, then two situations are possible: when the size of the array is 11 — then the answer is the single number in the array. Otherwise, at the moment when there is 11 odd number left, there will be one more move of player number 22, which means he will reduce the total sum once more, and the answer will be sum−⌊cnt3⌋−1sum−⌊cnt3⌋−1. If the remainder modulo is 22, then the number of moves when the second player reduces the sum does not change, so the answer is sum−⌊cnt3⌋sum−⌊cnt3⌋.

author: [OR_LOVe](https://codeforces.com/profile/OR_LOVe "Expert OR_LOVe"), developer: [zwezdinv](https://codeforces.com/profile/zwezdinv "Grandmaster zwezdinv") 

### [1916D - Mathematical Problem](../problems/D._Mathematical_Problem.md "Good Bye 2023")

1.1. For n=1n=1 the answer is 11.

2.2. For n=3n=3 the answers are 169,961,196169,961,196.

3.3. How to obtain the answer for n+2n+2: multiply each number for the answer of length nn by 100100 (the square of the number 1010), then each number will also remain a square. And we still have 2 numbers left, let's compose them as follows: 9...6...19...6...1, 1...6...91...6...9 where in the gaps between the digits there should be (n−3)/2(n−3)/2 zeros, these will respectively be the squares of numbers 1...3,3...11...3,3...1 with (n−3)/2(n−3)/2 zeros in the gaps between the digits.

Alternative solution:

For n=11n=11 generate 99 such numbers, for n≥11n≥11 pad them with zeros. For n<11n<11 solve in O(√10n)O(10n−−−√)

author: [marzipan](https://codeforces.com/profile/marzipan "Expert marzipan"), developer: [marzipan](https://codeforces.com/profile/marzipan "Expert marzipan") 

### [1916E - Happy Life in University](../problems/E._Happy_Life_in_University.md "Good Bye 2023")

Let's initiate a tree traversal from the first vertex, in which for each color on the path from the root to the current vertex, we will maintain the nearest vertex with that color, or note that it does not exist. This can be maintained using an array that is recalculated in O(1)O(1). Now, for each vertex, let's remember all the vertices for which we are the nearest ancestor with the same color. Build a segment tree on the Euler tour that will support two operations — adding to a segment and finding the maximum. Let's start another traversal of the tree, and for each vertex, we will maintain the count of different colors on the path from it to the vertex we are currently traversing with depth-first search. It is then asserted that we need to add 11 to the entire subtree of this vertex and subtract 11 from the subtrees of all vertices for which we are the nearest ancestor with the same color. After that, we need to find the 22 maximums among all the subtrees of the children and update the answer using them.

author: [zwezdinv](https://codeforces.com/profile/zwezdinv "Grandmaster zwezdinv"), developer: [zwezdinv](https://codeforces.com/profile/zwezdinv "Grandmaster zwezdinv") 

### [1916F - Group Division](../problems/F._Group_Division.md "Good Bye 2023")

We will generate the first set by adding one vertex at a time.

Initially, we will include any vertex. Then, to add a vertex from the second set, it must not be a cut vertex and must be connected to some vertex in the first set.

Statement: such a vertex always exists.

Proof: No cut vertex ⇒⇒ such a vertex exists. Otherwise, consider a cut vertex such that, if removed, at least one of the resulting components will not have any other cut vertices. Then, if none of the vertices in this component is connected to the second component, this cut vertex will be a cut vertex in the original graph. Contradiction.

Time — O(n1⋅(n1+n2+m))O(n1⋅(n1+n2+m))

author: [74TrAkToR](https://codeforces.com/profile/74TrAkToR "International Master 74TrAkToR"), developer: [74TrAkToR](https://codeforces.com/profile/74TrAkToR "International Master 74TrAkToR") 

### [1916G - Optimizations From Chelsu](../problems/G._Optimizations_From_Chelsu.md "Good Bye 2023")

Let's perform centroid decomposition and maintain the current found answer ansans.

* On vertical paths, simply find the value of the function, and we will immediately update the answer,
* We need to learn how to update the answer for a pair of vertical paths, combining pairs (g1,len1)(g1,len1) and (g2,len2)(g2,len2). Let's make several observations.
* First. If len1≥len2len1≥len2, then gcd(g1,g2)=g1gcd(g1,g2)=g1. Because if gcd(g1,g2)gcd(g1,g2) is not equal to g1g1, then it is at least twice smaller than g1g1.
* Second. From the first fact, we conclude that g2=g1⋅kg2=g1⋅k, so in order to make sense to update the answer, we need g1⋅(len1+len2)>g1⋅k⋅len2g1⋅(len1+len2)>g1⋅k⋅len2 and from here we get that len1>len2⋅(k−1)len1>len2⋅(k−1). This means that k≤len1k≤len1.

Let's do the following for a fixed centroid for each component:

* For each gg, we will only keep the largest value of lenlen,
* We will iterate over all such pairs and assume that we have fixed the pair (g1,len1)(g1,len1). For this, we will need to iterate over 1≤k≤len11≤k≤len1.
* Let's make the following optimization—if g⋅(len+d)≤ansg⋅(len+d)≤ans, then there is no need to iterate over kk, because we are guaranteed not to improve the answer. dd—is the farthest distance from the centroid to any vertex.

We have an upper bound estimate for this solution O(n√nlogn)O(nn−−√logn). Let's prove it.

For the pair (leni,gcdi)(leni,gcdi), we iterate over kk such that 1≤k≤ki1≤k≤ki, where ki≤leniki≤leni and we also cut off by the answer. Let's mark kiki edges on the path from the centroid to the vertex from which this pair came. Let's look at some edge, suppose it is marked cc times, the distance from the centroid is LL, and the gcdgcd from the centroid, including this edge, is gg. This means that we also marked it for some gcdi≤gcgcdi≤gc. But we already knew that the answer was at least gg, which means the size of the current graph is at least L⋅cL⋅c. It turns out that we could not have marked an edge at a distance LL from the centroid more than nLnL times.

We need to estimate in the tree the sum of min(ndepth[v],sz[v])min(ndepth[v],sz[v]). It can be estimated as n√nnn−−√. For depth[v]≤√ndepth[v]≤n−−√, we have a total size of subtrees at the level of nn, and then the value ndepth[v]≤√nndepth[v]≤n−−√.

author: [platelet](https://codeforces.com/profile/platelet "International Grandmaster platelet"), developer: [errorgorn](https://codeforces.com/profile/errorgorn "International Grandmaster errorgorn") 

### [1916H2 - Matrix Rank (Hard Version)](../problems/H2._Matrix_Rank_(Hard_Version).md "Good Bye 2023")

Let dpm,kdpm,k denote the number of m×nm×n matrices whose rank is kk.

The recurrence for dpm,k=dpm−1,k⋅pk+dpm−1,k−1⋅(pn−pk−1)dpm,k=dpm−1,k⋅pk+dpm−1,k−1⋅(pn−pk−1) with the base case of dp0,0=1dp0,0=1.

Consider enumerating m×nm×n matrices AA such that rank(A)=krank(A)=k based on a (m−1)×n(m−1)×n matrix BB and a row vector CC such that AA is made by appending CC to BB:

* If rank(B)=rank(A)rank(B)=rank(A), then CC must be inside the span of BB which has size pkpk.
* If rank(B)+1=rank(A)rank(B)+1=rank(A), then CC must be outside the span of BB which has size pn−pk−1pn−pk−1.

The pn−pk−1pn−pk−1 term in our recurrence is annoying to handle. So we will define gm,kgm,k as gm,k=gm−1,k⋅pk+gm−1,k−1gm,k=gm−1,k⋅pk+gm−1,k−1. It should be easy to see that dpm,k=gm,k⋅k−1∏i=0(pn−pi)dpm,k=gm,k⋅∏i=0k−1(pn−pi).

Method 1: Easy Version Only

We will show how to compute g2mg2m from gmgm. I claim that g2m,k=∑a+b=kgm,a⋅gm,b⋅pa(m−b)g2m,k=∑a+b=kgm,a⋅gm,b⋅pa(m−b).

The justification for this is to consider moving the DP state from (0,0)→(m,a)→(2m,a+b)(0,0)→(m,a)→(2m,a+b). 

The contribution of moving (m,a)→(2m,a+b)(m,a)→(2m,a+b) is actually very similar to that of moving (0,a)→(m,a+b)(0,a)→(m,a+b), except every time we multiply the value by pkpk, we have to instead multiply it by pk+apk+a. And conveniently, the number of times we need to additionally multiply by pkpk is m−bm−b.

To convolute these sequences, we will use a technique that is similar to chirp-z transform. Note that ab=(a+b2)−(a2)−(b2)ab=(a+b2)−(a2)−(b2), you can prove this geometrically by looking at (x2)(x2) as a triangle pyramid.

∑a+b=kgm,a⋅gm,b⋅pa(m−b)=∑a+b=kgm,a⋅gm,b⋅pam+(a2)+(b2)−(a+b2)=p−(k2)∑a+b=k(gm,a⋅pam+(a2))⋅(gm,b⋅p(b2))

Therefore, it is we can get g2m from gm by convoluting (gm,i⋅pim+(i2)) and (gm,i⋅p(i2)) in O(klogk) time. By performing a process similar to fast exponentiation, we can compute gn in O(klogklogn).

Method 2: Easy Version Only

Consider the ordinary generating function Gk=∑gm,kxm. Based on the recurrence above, We have Gk=x(pkGk+Gk−1). This gives us Gk=xGk−11−pkx=xkk∏i=011−pix.

We want to find [xn]G0,[xn]G1,…,[xn]Gk. Notice that [xn]Gk=[xn−k]k∏i=011−pix=[xk]xn % (k∏i=0x−pi). Where A % B denotes the unique polynomial C with deg(C)<deg(B) and there exists D such that A=BD+C.

We can compute all required coefficient in a divide and conquer-esque way. Note that A % B=(A % BC) % B.

We want dnc(l,r) to find all the answers for [xn]Gl,[xn]Gl+1,…,[xn]Gr. dnc(l,r) will be provided with P(x)=xn % (r∏i=0x−pi) and Q(x)=l∏i=0x−pi.

Then the pseudocode of the DnC is as follows:


```cpp
  
fun dnc(l,r,P,Q):  
	if (l==r):  
		ans[l] = [x^l]P  
		return  
	m=(l+r)/2  
	Q2=Q * (x-p^(l+1)) * ... (x-p^m)  
	dnc(l,m,P%Q2,Q)  
	dnc(m+1,r,P,Q2)  

```
The above code is at least quadratic. However, we only need to save the last (r−l+1) non-zero coefficients from both P and Q. If implemented properly, this code runs in O(klogklogn).

Method 3: Hard Version

As with the first part of method 2, we want to find [xn]G0,[xn]G1,…,[xn]Gk where Gk=xkk∏i=011−pix. We will try to decompose k∏i=011−pix into partial fractions.

Repeated factors in partial fractions is hard to deal with. It turns out, we do not need to deal with them at all. Suppose ord is the smallest positive integer that such pord=1(mod998244353). Then p0,p1,…,pord−1 are all distinct. Furthermore, dpn,k=0 for k≥ord as dpm,k=gm,k⋅k−1∏i=0(pn−pi).

Therefore, we can safely assume k<ord so that p0,p1,…,pk will be all distinct.

By using the cover-up rule on k∏i=011−pix, we obtain a partial fraction decomposition of k∑i=0ci1−pix where ci=k∏j=0,i≠j11−pj−i.

Let Li=∏ij=111−p−j,Ri=∏ij=111−pj，so that ci=LiRk−i.

Gk=[xn−k]k∏i=011−pix=[xn−k]∑a+b=kLaRb1−pax=∑a+b=kpa(n−k)LaRb=∑a+b=kp(n−b2)−(n−k2)−(a2)LaRb=p−(n−k2)∑a+b=k(La⋅p−(a2))(Rb⋅p(n−b2))

So we can find [xn]G0,[xn]G1,…,[xn]Gk by convoluting (Li⋅p(i2)) and (Ri⋅p(n−i2)).

The final time complexity is O(klogk).

Method 4: Hard Version

Thanks to Endagorion for finding this solution during testing.

For an n-dimensional vector space of Fq, the number of k-dimensional vector subspace is denoted as (nk)q and is known as the [q-analogue of binomial coefficients](https://codeforces.com/https://en.wikipedia.org/wiki/Gaussian_binomial_coefficient).

It is known that (nk)q=(qn−1)…(qn−k+1−1)(1−q)…(1−qk). This fact is not too hard to derive by considering the number of possible independent sets dividing the the number of sets that results in the same span. Here it is helpful to use the form (nk)q=[n!]q[k!]q[n−k!]q where [n!]q=(1)⋅(1+q)…⋅(1+q+…+qn−1). If you want to read more about these series, I recommend checking out Enumerative Combinatorics.

We will proceed with PIE (principle of inclusion-exclusion) on these q-binomials. We want to find the number of ways to choose n vectors that spans exactly some k-dimensional vector space, but this is hard. However, we realize that we are able to count the number of ways to choose to choose n vectors that spans a subset of some k-dimensional vector space. Let fk and gk denote these values respectively.

Then we have gk=k∑i=0fi⋅(ki)q. Note that this is very similar to egf-convolution with the identity sequence. Indeed, if we define the generating functions F=∑fkxk[k!]q, G=∑gkxk[k!]q and the identity sequence I=∑xk[k!]q, we have F⋅I=G.

We are able to calculate I and G, so we can find F=G⋅I−1.

Then, the number of matrices with rank k is simply fk⋅(nk)q.

Of course, a caveat is that division might not be defined when some [n!]q=0, and it is a simple exercise to the reader to figure out why defining 0−1=0, which aligns with our usual definition of aMOD−2=a−1 does not break anything in the solution.

The final time complexity is O(klogk).

