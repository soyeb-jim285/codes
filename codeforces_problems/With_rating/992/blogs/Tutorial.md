# Tutorial

All the problems have been prepared by us, — [gop2024](https://codeforces.com/profile/gop2024 "Master gop2024") and [----------](https://codeforces.com/profile/---------- "Master ----------").

(Idea of the problem — [gop2024](https://codeforces.com/profile/gop2024 "Master gop2024"))

 
### [992A - Nastya and an Array](../problems/A._Nastya_and_an_Array.md "Codeforces Round 489 (Div. 2)")

Let's notice that after one second we aren't able to decrease the number of distinct non-zero elements in the array more than by 1. It means that we can't make all elements equal to zero faster than after ![](images/6f09537335a62c5e13d8612b26edea7fccbe59bd.png) seconds, where ![](images/6f09537335a62c5e13d8612b26edea7fccbe59bd.png) is the number of distinct elements in the array initially. And let's notice that we are able to make it surely after ![](images/6f09537335a62c5e13d8612b26edea7fccbe59bd.png) second, if we will subtract every second some number which is in the array, so all elements equal this number in the array will have become zero, and the number of distinct non-zero elements will be decreased.

So the answer is the number of distinct non-zero elements initially. Complexity is ![](images/e8b6f49fcfb62cfc46e50da2e57f70063411dfed.png)

Code — [39423470](https://codeforces.com/contest/992/submission/39423470 "Submission 39423470 by gop2024")

(Idea of the problem — [GreenGrape](https://codeforces.com/profile/GreenGrape "Candidate Master GreenGrape"))

 
### [992B - Nastya Studies Informatics](../problems/B._Nastya_Studies_Informatics.md "Codeforces Round 489 (Div. 2)")

Let's consider some suitable pair ![](images/651b7ce26e7fc3d0328defb65b169f4dda1f9b29.png). As ![](images/0d36d519613716d6dbe799b6698f612d6badfe57.png), we can present number ![](images/afd9302b0f28e76573275a67b1546779a90fa9d1.png) as ![](images/d5fbbb19a61cf3297550b4744753df873129a2d7.png), and number ![](images/d9f7bbdacc5c7c089f7cb434c7ff774662fbacbb.png) as ![](images/3248314d862c7c354f06fed06b1386f75389402c.png), where we know that ![](images/5b52a46df9a4fbf98442e9b0c904cb4d62a19987.png) and ![](images/3cfeb24f8e9110b25c0998d29da59024a8b1dc2b.png).

Let's consider too that from the restriction from the problem ![](images/4138fe26e944e6bced5dbcef26b0e343416ed41a.png) we surely know the restriction for ![](images/d2fdf2b8410c3b6d3a1aefdcc0f47c8b1b5a3f5e.png) and ![](images/f39dc1b0911cd316de5133ccdc09179d1a028969.png), that is ![](images/43bb8ca0fa9b4f478adba5f0f8ee1dd41fa1a2f3.png). 

Let's remember we know that ![](images/47c8cb92981c83e3dd835fd0de19ae8feb423e34.png) (because ![](images/3a0d1ecaf9393b473c00955bd2b536d53dc82d2c.png) is ![](images/b41b6b82d6505e2ee60c9dc968084cc1e5bd5b17.png), ![](images/367f45061dc84511f8ae93d05832a06e535e3777.png) is ![](images/6a7ce9f98ebd69a28850bef08ea101e0bbafb174.png)). Then we can get ![](images/fb8691ffa8a59914fa3426d57a689e4ae1a0c1d4.png). Dividing by ![](images/3a0d1ecaf9393b473c00955bd2b536d53dc82d2c.png):

![](images/09d51ac3552c1c4ac28b7c4b2c4b50428a7ffa3e.png).

![](images/2e4706e8a0bdc132d92266a36cf064bad5f6d433.png).

Now if ![](images/efc215000cc7ab373bb85b200bae237c79b2dd4d.png), answer equals 0.

Else as ![](images/5f9f0936a8f7e854cb0e6e2e85ac9c3aabf79f45.png) is surely less than ![](images/71beaed68437ad7c256320b5e09f3af83b665a00.png), we can just sort out all possible pairs ![](images/10558fa76d2276cf7b8dc0c3877d97ec33e9c663.png) of divisors ![](images/5f9f0936a8f7e854cb0e6e2e85ac9c3aabf79f45.png), such that ![](images/c0517cd5e3a9407eedb7bfa5a1944852d378016c.png) , and then to check that ![](images/3cfeb24f8e9110b25c0998d29da59024a8b1dc2b.png) and ![](images/eadf1eb04ce2c5b986c03a052bdcd91b17fb4a44.png) are in the getting above restrictions. Complexity of this solution is ![](images/4a3459bd68baad0995a748fa3416620b8dd759a1.png).

Code — [39423481](https://codeforces.com/contest/992/submission/39423481 "Submission 39423481 by gop2024")

(Idea of the problem — [----------](https://codeforces.com/profile/---------- "Master ----------"))

 
### [992C - Nastya and a Wardrobe](../problems/C._Nastya_and_a_Wardrobe.md "Codeforces Round 489 (Div. 2)")

Let's present we have initially ![](images/ff22477c025b7c360bae3e696f90ddfd1d773656.png) dresses.

What does occur in the first month? Initially the number of dresses is multiplied by 2, that is becomes ![](images/5a2371405f0c57401cc539312bcb0f896f7c94dc.png). Then with probability ![](images/aeb6020bf32f9dd27b43275a1d6e7a8caf9bf5f6.png) the wardrobe eats a dress, that is expected value of the number of dresses becomes ![](images/301d8bd7c596672faf9a20c15c4a58872defff17.png). The same way after the second month expected value becomes ![](images/bd312caafe4c9301068b1a44c976dc85feef17af.png). It's easy to notice that after ![](images/2ef27ad2497aaac51a6017c18b72756200bbad3f.png)-th month(if ![](images/66ef9f5bd541f1350c167457c96706117a4b1d10.png)) expected value equals ![](images/767f680ba5d7502cd6a6950cb074c9810efe3124.png). Eventually it will be only doubled(as the wardrobe doesn't eat a dress in the last month), that is will be equal ![](images/a2b359367d65a6d586f1dc093e850c6977b65c25.png).

Thus, answer of the problem is ![](images/a2b359367d65a6d586f1dc093e850c6977b65c25.png). Expressing it with ![](images/6f09537335a62c5e13d8612b26edea7fccbe59bd.png), we get:

![](images/ed92c320b0f4f0301afaa2f1d1a1e16736301b46.png) = ![](images/26683126a18c5337b207ea66e23941080a16f894.png).

![](images/ed92c320b0f4f0301afaa2f1d1a1e16736301b46.png) = ![](images/7294f10ffb39a3eace4254538e95364094f5bb2e.png).

Thus, we need to calculate degree of 2 right up to ![](images/155c1fa8156c3303b3a444e3a2e2a6e2512d0326.png). Complexity of the soltion is ![](images/d96c0d6ff683bafd460640cc0b2441ebed1a4fb3.png).

Let's notice that the case ![](images/ba2555a85731b3a1d39d92a40fdb035acfcb6e19.png) we need to calculate separately, because wardrobe can't eat a dress when it doesn't exist. If ![](images/d2d9460b15f329b348d5ff00444e7600bd5552ab.png) it's easy to proof that the number of dresses is never negative, that is the formula works.

Code — [39423497](https://codeforces.com/contest/992/submission/39423497 "Submission 39423497 by gop2024")

(Idea of the problem — [gop2024](https://codeforces.com/profile/gop2024 "Master gop2024"))

 
### [992D - Nastya and a Game](../problems/D._Nastya_and_a_Game.md "Codeforces Round 489 (Div. 2)")

Let's call numbers which are more than 1 as good. Notice the following fact:

If a subsegment is suitable, it contains not more than 60 good numbers.

Indeed, let's assume that a subsegment contains more than 60 good numbers. In this subsegment ![](images/0b3cf493dcc5908ce98ec2a87d8d441088445c86.png). At the same time, as ![](images/d8891b73a392edf875057895dd2c9a39f17f59a9.png), and ![](images/cf95b3ae94489ed646600d7c44a86a97518b574e.png), there is ![](images/30ead0fdf282e576dd43eebd609e7d8e5c78c3a2.png). Therefore, this subsegment can't be suitable due to ![](images/8223c2a8a4fb3eb0490eed96e302bd9f12b7b316.png).

Let's keep all positions of good numbers in a sorted array. We sort out possible left border of a subsegment and then with binary search we find the next good number to the right of this left border. Then let's iterate from this found number to the right by the good numbers(that is we sort out the rightmost good number in a subsegment), until product of all numbers in the subsegment becomes more than ![](images/b78a1873d927a1e2ad3699d92f6bd4be6c5c2da2.png) (it's flag which shows us, that product is too big for a suitable subsgment and we need to finish to iterate). We have shown above the number of iterations isn't more than 60. Now for sorted out the left border and the rightmost good number we only need to know the number of 1's which needs to be added to the right of the rightmost good number, as we can easily maintain sum and product in the subsegment during iterating. Then we need to check whether found number of 1's exists to the right of the rightmost good number. It can be checked if we look at the next good number's position.

Complexity is ![](images/9237229bff1926f9d2e70153863ebf0f162dc7ec.png).

In order to check that ![](images/6df299257eb91157b9b23ad4737bc32f55c20918.png) is more than ![](images/b78a1873d927a1e2ad3699d92f6bd4be6c5c2da2.png), you shouldn't calculate ![](images/afd9302b0f28e76573275a67b1546779a90fa9d1.png) multiply by ![](images/d9f7bbdacc5c7c089f7cb434c7ff774662fbacbb.png), due to overflow. You must only check that ![](images/80095a7c40dc0199c96edb648b534df2b3047291.png).

(Idea of the problem — [gop2024](https://codeforces.com/profile/gop2024 "Master gop2024"))

Code — [39423501](https://codeforces.com/contest/992/submission/39423501 "Submission 39423501 by gop2024")

 
### [992E - Nastya and King-Shamans](../problems/E._Nastya_and_King-Shamans.md "Codeforces Round 489 (Div. 2)")

This problem was inspired by idea which was offered by my unbelievable girlfriend :)

Solution I

In this problem we maintain two segment trees - with maximum and with sum. After every query we recalculate these trees in ![](images/dc4644ddce31aeb07ea9afef5781fa508d2a7e9b.png) for a query. Now we only have to understand, how to answer for a query? Let's call a prefix of the array as good in the case if we surely know that it doesn't contain a king-shaman. So either the first shaman is king and we are able to answer for the query, or we call the prefix with length 1 as good. Then let's repeat the following operation:

* We call ![](images/20fa53e35da8ba80f47e48075fadd587bbc7377e.png) as sum in the good prefix now. We find it using the segment tree with sums.
* We find the leftmost element which may be king-shaman yet. We can realise that it's the leftmost element, which doesn't lie in the good prefix (as there isn't king-shaman according the definition), which have a value at least ![](images/20fa53e35da8ba80f47e48075fadd587bbc7377e.png). It can be done using segment tree with maximums, with descent.
* We check if this found shaman is king. If isn't, we can say that the good prefix finishes in this shaman now, because it was the leftmost shaman who might be king.

Every operation works in ![](images/dc4644ddce31aeb07ea9afef5781fa508d2a7e9b.png). Let's notice, that one operation increases sum in the good prefix at least by two times. So, after ![](images/6cf6647a6f18f8aa2f49685214b85030657d39ae.png) operations sum in the good prefix will become more than a maximal possible number in the array, so that we will be able to finish, because we will be sure that answer will be -1. Complexity of the solution is ![](images/1c46a044e36c48dc8bc35c97f7bfd4635d2d852b.png).

Solution II

Let *p**i* be the prefix sums of *a*. We're gonna introduce *f**i* = *p**i* - 2·*a**i* and reformulate the queries using these new terms.

1. Imagine we wanna change the value at *j* to *val*. Let δ = *val* - *a**j*. Then *f**j* will decrease by δ whereas *f**i* > *j* will increase by δ.
2. Imagine we wanna find the answer. Then it's sufficient to find any *i* satisfying *f**i* = 0.

Split *f* into blocks of size *M*. Each block will be comprised of pairs (*f**i*, *i*) sorted by *f*. At the same time we will maintain *overhead* array responsible for lazy additions to blocks. How does this help?

1. Let *b* = *j* / *M*. The goal is to find the position of *j*, decrease its value and increase values for all *i* > *j* within this block. It can be done in a smart way in *O*(*M*) (actually, this can be represented as merging sorted vectors). You should also take care of the tail, i.e add δ to *overhead**j* > *b* in *O*(*n* / *M*) time.
2. We're asked to find such *i* that *f**i* + *overhead**j* / *M* = 0. All blocks are sorted, thus we can simply apply binary search in ![](images/36b2ae583240fc9e0a0abf752b6929c7812e5510.png) overall.

The optimal assignment is ![](images/b8bf649a595c0560e8a97eafe5fc1027a264acc8.png) which results into ![](images/ecb05baa499435e8aa6aabbb6a6fefc090e287d7.png) total runtime. 

The huge advantage of this approach is its independency from constraints on *a* (i.e non-negativity). Although we didn't succeed in squeezing this into TL :)

Solution III

Group the numbers according to their highest bits (with groups of the form [2*k*... 2*k* + 1] and separately for zeros). Inside each groups (no more than ![](images/185f6ea3a0e9717f05e194b5bf8e6cc98daa6969.png) of them) we maintain elements in increasing order of indexes. 

It's easy to see that each group contains no more than two candidates for answer (since their sum is guaranteed to be greater than any of the remaining ones). This observation leads to an easy solution in ![](images/e406f4ecf465a98bc4860b2d30a6b468c937d505.png) — we iterate over groups and check prefix sums for these candidates.

There's actually further space for optimizations. Let's maintain prefix sums for our candidates — this allows us to get rid of the extra log when quering the tree. Almost everything we need at this step is to somehow process additions and deletions — change the order inside two blocks and probably recalculate prefix sums. The only thing left is to stay aware of prefix sum changes for the remaining blocks. Luckily, they can be fixed in *O*(1) per block (if *i* > *j* then the sum increases by *val* - *a**j* and stays the same otherwise). 

The resulting comlexity is ![](images/8ee8ab538b5f744da223ccdae10ed7146bc62ffd.png).

Code of the solution I — [39423519](https://codeforces.com/contest/992/submission/39423519 "Submission 39423519 by gop2024")

Code of the solution II — [39418926](https://codeforces.com/contest/992/submission/39418926 "Submission 39418926 by GreenGrape"). Try to optimize :)

Thank you [tfg](https://codeforces.com/profile/tfg "Master tfg") for the idea and the code of the solution III. Very good job!

Code of the solution III — [39392321](https://codeforces.com/contest/992/submission/39392321 "Submission 39392321 by tfg")

