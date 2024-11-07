# Editorial


### [955A - Feed the cat](../problems/A._Feed_the_cat.md "Codeforces Round 471 (Div. 2)")

It's optimal to buy buns either right after waking up or at 20:00 (if possible) because between the awakening and 20:00 cost doesn't change but cat's hunger does. There was one extra case when Andrew wakes up after 20:00 and has only one possible option of buying everything since he cannot turn back time.

Code: [36605296](https://codeforces.com/contest/955/submission/36605296 "Submission 36605296 by GreenGrape")

 
### [955B - Not simply beatiful strings](../problems/B._Not_simply_beatiful_strings.md "Codeforces Round 471 (Div. 2)")

Since order of letters in adorable strings doesn't matter, it doesn't matter in the initial string as well. Let *d* be the number of distinct letters in *s*. Consider the following cases one after another:

* If |*s*| < 4 answer is «No» since lengths of adorable strings cannot be less than two;
* If *d* is more than 4 answer is also «No» since adorable strings contain two distinct letters;
* If *d* is equal to 4 answer is always «Yes» (we give two types of letters to string one and other two to string two);
* If *d* is equal to three answer is also «Yes» (based on the fact that length of *s* is no less than 4);
* If *d* is equal to two answer depends on whether there's a letter occuring only once (because that means that one of the strings will consist of letters of the same kind);
* If all letters are the same, answer is «No» (same as the previous case).
Code: [36605336](https://codeforces.com/contest/955/submission/36605336 "Submission 36605336 by GreenGrape")

 
### [955C - Sad powers](../problems/C._Sad_powers.md "Codeforces Round 471 (Div. 2)")

Let's fix some power *p*. It's obvious that there are no more than ![](images/707f65cd3eda2b1d064c757ed211409bc59e2fd3.png) numbers *x* such that *x**p* does not exceed 1018. At the same time, only for *p* = 2 this amoung is relatively huge; for all other *p* ≥ 3 the total amount of such numbers will be of the order of 106.

Let's then generate all of them and dispose of all perfect squares among them. Then answer to query (*L*, *R*) is equal to the amount of generated numbers between *L* and *R* plus some perfect squared in range. The first value can be calculated via two binary searches. The second one is ![](images/ed9f5eba2f04a36ef87df231ffeda2a6a0fc3eb7.png). Note that due to precision issues the standard sqrt might produce incorrect values, so you can use additional binary searches instead.

Complexity: ![](images/d3973f4129d371ea23fb8a16fc8ae042eb02097f.png). 

Code: [36605356](https://codeforces.com/contest/955/submission/36605356 "Submission 36605356 by GreenGrape")

 
### [955D - Scissors](../problems/D._Scissors.md "Codeforces Round 471 (Div. 2)")

Denote *lpos*(*x*) — the minimum index in *s* that prefix of *t* of length *x* might start at, provided *lpos*(*x*) + *x* ≥ *k* (so this prefix can be enclosed in some *k*-substring of *s* as a suffix) or  - 1 if there are none.

Denote *rpos*(*x*) in the same manner  — the maximum index in *s* that suffix of *t* of length *x* might end at, under the same conditions (enclosing suffix in some *k*-substring of *s* as a prefix). It's clear that these array allow us to iterate over all possible prefix/suffix partitions of *t* and check their correctness.

Note that *rpos* is calculated as *lpos* on reversed strings. How do we obtain *lpos*? Let's calculate *z*-function of *s* with respect to *t* and say that *z*(*i*) is the maximum prefix of *t* starting at position *i* in *s*.

Which *z*(*i*) might influence *lpos*(*x*)? First of all, they must satisfy *z*(*i*) ≥ *x*. Second, as mentioned above, *i* + *x* ≥ *k*. This allows us to apply all updates naively and achieve *O*(*n*2).

To speed this up we will iterate over *z* in decreasing order and maintain viewed indexes in a set in such a way that at the moment we are up to calculate *lpos*(*x*) all *i*-s such that *z*(*i*) ≥ *x* will be in. Then *lpos*(*x*) will be equal to minimum *j* in the set satisfying *j* ≥ *k* - *x*. This allows us to reduce the complexity to ![](images/2cd1eac556a7b44fe282c5a5fdd92bc1f8fcd187.png).

Reverse both *s* and *t* and calculate *rpos* in the same way. Then the only thing left is to check whether for some *x* ≤ *k* values *lpos*(*x*) and *rpos*(*m* - *x*) can be combined to obtain the answer.

Code: [36605449](https://codeforces.com/contest/955/submission/36605449 "Submission 36605449 by GreenGrape")

 
### [955E - Icicles](../problems/E._Icicles.md "Codeforces Round 471 (Div. 2)")

Fix some point *T* and launch the wave. Icicle at *i* will reach the floor in *f**T*(*i*) = *a**i* + |*T* - *i*| seconds. Krakozyabra will definitely stop at minimum icicle *j* such that *f**T*(*j*) < *j* and wait for something to the left of it to fall. Note that some icicle to the right of *j* might also fall earlier than *j* itself. So the answer for this fixed *T* is *max*(*min*1 ≤ *i* < *j**f**T*(*i*), *min**j* ≤ *i* ≤ *n**f**T*(*i*)). This approach gives us a *O*(*n*2) solution.

How to speed this up? Let's get rid of the absolute value. For *i* ≤ *T* absolute value is unfolded as *f**T*(*i*) = *a**i* + *T* - *i* and for *i* > *T* as *f**T*(*i*) = *a**i* - *T* + *i*.

Rewrite the inequality *f**T*(*i*) < *i* according to the observations above. It's easy to see that for *i* ≤ *T* it is equal to *T* < 2·*i* - *a**i* and for *i* > *T* — *a**i* < *T*. Build some range max/min structure and find *j* assuming *j* < *T*, and if unsuccessfully — assuming *j* ≤ *T* with respect to the given inequalities. The only thing left is to carefully find minimums on suffix/prefix.

Complexity: ![](images/2cd1eac556a7b44fe282c5a5fdd92bc1f8fcd187.png).

Code: [36605502](https://codeforces.com/contest/955/submission/36605502 "Submission 36605502 by GreenGrape")

 
### [955F - Heaps](../problems/F._Heaps.md "Codeforces Round 471 (Div. 2)")

Denote *heap**k*(*u*) as maximum depth of *k*-ary heap rooted at *u*, and *dp**k*(*u*) as maximum depth of *k*-ary heap in the subtree of *u* (including *u*). Let *v**i* — children of vertex *u*; sort them in order of descending *heap**k*{*v**i*}. Then *heap**k*(*u*) = *heap**k*(*v**k*) + 1, and *dp**k*(*u*) = *max*(*heap**k*(*u*), *max**j*(*dp**k*(*v**j*))). So we can calculate dp for fixed *k* in ![](images/2cd1eac556a7b44fe282c5a5fdd92bc1f8fcd187.png) or in *O*(*n*), if we will use *nth*_*element*, so we can solve the problem in *O*(*n*2).

For simplicity, denote *dp**k*(1) as *p**k*. Let's suppose that *k* > 1. Note three facts:

* *p**k* ≤ *log**k*(*n*);
* *dp**k*(*u*) ≤ 2 when ![](images/72cb5535880c879f97b15f0430db624f340cf89b.png).
* *heap**k*(*u*) ≥ *heap**k* + 1(*u*).

So we can solve the problem in ![](images/0c18a224e805d960478a53ca7ac5ae33eaed6dd7.png). Let's solve task in *O*(*n*) when ![](images/1734f20620b928dc452c14b0ae22cfba18851ad6.png). For other *k*'s let's go in descending order, and set the value of dp to 2 and push this value up to the root for each vertices, that have exactly *k* children. 

Note, that the total number of vertices visited in pushes does not exceed *n* (Because if we arrive at vertex with *dp* = 2, it is useless to go up, because everything there has already been updated. Each vertex will be added exactly one time, so complexity of this part is *O*(*n*).

Let's use this idea to solve the problem in ![](images/20d7b1dec50957721c925aabcab5b98abdf88651.png). For each ![](images/6efe35c92cc865edd786db019c3ad279c09817aa.png) let's solve in *O*(*n*), and for ![](images/72cb5535880c879f97b15f0430db624f340cf89b.png) let's use the idea above. And when ![](images/83a74a3fbc5c49f2c751a55b72a60bbebdf58652.png), *dp**k*(*u*) does not exceed 3. Let *f*3(*u*) will be minimal *k*, such that *heap**k*(*u*) is equal to 3. By definition, *u* will have at least *k* children, which are the heaps of depth 2, that is also vertices with at least *k* children. Let's sort *v* by number of their children; Then answer for *u* will be maximal *k*, such that *children*(*v**k*) ≥ *k*. Let's precalculate it, and when let's go in descending order by *k* pushing up value 3 from each *u* with *f*3(*u*) = *k*. The total number of vertices visited in pushes does not exceed 2·*n* (At worst case, in each vertex will be pushed at first with value 2, and then with value 3). So we can solve the problem in ![](images/444592c1fc3d193690a86c2ad4ddc4e8553dd7ad.png), which is better but still not enough. 

Let *val*(*u*, *depth*) — maximal *k* > 1, such that vertex *u* contain *k*-ary heap of depth *depth* (or  - 1, if there are no such vertex). This dp have ![](images/e76c2905f2b64ea579c71bd0af9929449643e037.png) states; To recalculate *val*(*u*, *depth*) we need to sort *val*(*v**i*, *depth* - 1) by descending order, and find maximal *k*, such that *val*(*v**k*, *depth* - 1) ≥ *k*. So, with sort, complexity of this solution will be ![](images/79128871135b4a9fd6ca43fb15b094e9ad056e2b.png).

Let's go in descending order by *k* pushing up value *x* from each *u* with *val*(*u*, *x*) = *k*. The total number of vertices visited in pushes does not exceed *n*·*logn* because *dp**k*(*u*) ≤ *log**k*(*n*). So, the complexity of this solution wil be ![](images/2cd1eac556a7b44fe282c5a5fdd92bc1f8fcd187.png).

Code: [36605519](https://codeforces.com/contest/955/submission/36605519 "Submission 36605519 by GreenGrape")

