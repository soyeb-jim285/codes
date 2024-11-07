# Tutorial

Спасибо за участие!

[1744A - Number Replacement](../problems/A._Number_Replacement.md "Codeforces Round  828 (Div. 3)") придумал [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov"), подготовил [74TrAkToR](https://codeforces.com/profile/74TrAkToR "International Master 74TrAkToR")

[1744B - Even-Odd Increments](../problems/B._Even-Odd_Increments_.md "Codeforces Round  828 (Div. 3)")  придумал и подготовил [74TrAkToR](https://codeforces.com/profile/74TrAkToR "International Master 74TrAkToR")

[1744C - Traffic Light](../problems/C._Traffic_Light.md "Codeforces Round  828 (Div. 3)") придумали [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov") и [74TrAkToR](https://codeforces.com/profile/74TrAkToR "International Master 74TrAkToR"), подготовил [74TrAkToR](https://codeforces.com/profile/74TrAkToR "International Master 74TrAkToR")

[1744D - Divisibility by 2^n](../problems/D._Divisibility_by_2^n.md "Codeforces Round  828 (Div. 3)") придумал и подготовил [74TrAkToR](https://codeforces.com/profile/74TrAkToR "International Master 74TrAkToR")

[1744E2 - Divisible Numbers (hard version)](../problems/E2._Divisible_Numbers_(hard_version).md "Codeforces Round  828 (Div. 3)") придумал и подготовил [74TrAkToR](https://codeforces.com/profile/74TrAkToR "International Master 74TrAkToR")

[1744F - MEX vs MED](../problems/F._MEX_vs_MED.md "Codeforces Round  828 (Div. 3)") придумал и подготовил [74TrAkToR](https://codeforces.com/profile/74TrAkToR "International Master 74TrAkToR")

 
### [1744A - Number Replacement](../problems/A._Number_Replacement.md "Codeforces Round  828 (Div. 3)")

Let's note that if ai=aj, then si must be equal to sj, since we must change the same value to the same letter. If we check this for all pairs of i and j and find no such contradictions, then the answer is "YES", otherwise "NO".

We got the solution for O(n2) for one test case.

 
### [1744B - Even-Odd Increments](../problems/B._Even-Odd_Increments_.md "Codeforces Round  828 (Div. 3)")

Let sum — the initial sum in the array, cnt0 — the number of even numbers, cnt1 — the number of odd numbers.

Let's see how these values ​​change with each action. In fact, we can consider four main options:

* Add an even number x to all even numbers. Then sum will increase by x⋅cnt0, and the number of even and odd numbers will remain the same.
* Add an odd number x to all even numbers. Then sum will increase by x⋅cnt0, the number of even numbers will become 0, all numbers will become odd, so cnt1=n.
* Add an even number x to all odd numbers. Then sum will increase by x⋅cnt1, and the number of even and odd numbers will remain the same.
* Add an odd number x to all odd numbers. Then sum will increase by x⋅cnt1, the number of odd numbers will become 0, all numbers will become even, so cnt0=n.
 
### [1744C - Traffic Light](../problems/C._Traffic_Light.md "Codeforces Round  828 (Div. 3)")

Let's note that for each second of color c in the traffic light, we need to find the rightmost green time, and then find the largest distance between color c and the nearest green. Also, let's not forget that traffic light states are cyclical.

To get rid of cyclicity, you can write the string s twice and for each cell of color c from the first half, find the nearest green color (thus we solved the problem with cyclicity). And now we can just follow this line from right to left and maintain the index of the last occurrence of green. If we encounter color c, then we try to update our answer ans=max(ans,last−i), where ans is our answer, last is the nearest time that green was on color, i — current time.

 
### [1744D - Divisibility by 2^n](../problems/D._Divisibility_by_2^n.md "Codeforces Round  828 (Div. 3)")

Let's notice that if we multiply the numbers a1⋅a2⋅…⋅an, then the power of two of the product is equal to the sum of the powers of two in each of the numbers.

Let's calculate the initial sum of the powers of twos in the product. This can be done as follows: let's take the element ai and divide it by 2 as long as we can, while remembering to increase our counter by the number of occurrences of a power of two.

Now let's move on to operations and note that choosing the index i will increase the degree of occurrence of two by a fixed number (that is, it does not matter when to apply this operation). Choosing an index i will increment the counter by a number x such that i is divisible by 2x but not by 2x+1 — you can find this x, again , by dividing by 2 while we can.

Since we want to minimize the number of operations used, at each moment of time we will try to use an index that increases the counter by the largest number. To do this, it is enough to sort the indices by this index of increase and take them greedily from the largest increase to the smallest.

We get the solution in O(nlogn+nlogA).

 
### [1744E2 - Divisible Numbers (hard version)](../problems/E2._Divisible_Numbers_(hard_version).md "Codeforces Round  828 (Div. 3)")

Let's look at the slow solution first, which will lead us to the full one. Let's iterate over the number x from a+1 to c.

Given a number x, we want to find a y from b+1 to d such that x⋅y is divisible by a⋅b. Since x⋅y must be divisible by a⋅b, the following conclusion can be drawn: y must be divisible by a⋅bgcd(a⋅b,x). Let's denote this number as s. Now our task is to check if there is a multiple of s between b+1 and d. The problem can be solved in many ways, you can simply consider the largest multiple of s that does not exceed d — it is equal to ⌊ds⌋⋅s We compare this number with b+1, and if it matches, then we have found a suitable pair.

Now let's note that we do not need to iterate over all the values ​​of x, because from the number x we are only interested in gcd(x,a⋅b) — and this is one of the divisors of a⋅b!

Even though the product a⋅b can be large, we can still consider all divisors of this number, since a and b themselves are up to 109. Let's find the divisors of a and b separately, then notice that any divisor of a⋅b — is a′⋅b′, where a′ — is some divisor a, and b′ — is some divisor b.

Let's calculate the running time. We need to factorize the numbers a and b into prime factors, this can be done in O(√a). Next, you need to iterate over pairs of divisors a and b. Recall the estimate for the number of divisors of a number ([https://oeis.org/A066150](https://codeforces.com/https://oeis.org/A066150)): the number x up to 109 has no more than 1344 divisors. Therefore, we can sort through the pairs for 13442. We learned how to find the optimal y for O(1). We get that for each test case we have learned to solve the problem in O(√a+(13442)).

 
### [1744F - MEX vs MED](../problems/F._MEX_vs_MED.md "Codeforces Round  828 (Div. 3)")

Let's learn how to count the number of subsegments where mex>mid for a fixed value of mex.

Let's understand on which subsegments mex has such a value. We understand that the numbers 0,1,…,mex−1 should be in this subsegment, the number mex — should not, and then — does not matter . Let ℓ — be the index of the left-most occurrence of the numbers 0,1,…,mex−1, and r — the right-most occurrence. Also, let pos "be the index of the number mex. If ℓ<pos<r, then there is no subsegment with the given mex, otherwise let's think about how many numbers can be in a subsegment.

It is stated that if the length of a segment is ≤2⋅mex, then mex>mid on it, otherwise it is not true. Indeed, if the length of a segment is ≤2⋅mex, then simply by the definition of the median, it will be among the first mex numbers. On the other hand, if the length of the segment becomes longer, then according to the same definition of the median, it will no longer be among the first mex numbers, which are equal to 0,1,…,mex−1.

It turns out that we need to count the number of subsegments of length ≤2⋅mex that contain the subsegment ℓ…r inside themselves, but not pos. This, of course, can be done with large formulas and the like, but one more useful fact can be noticed!

If we iterate over mex in ascending order, and at the same time maintain ℓ and r, then let's see what happens with a fixed mex and a position of pos (for convenience, let's assume that pos<ℓ, since the second case is similar). In fact, you can simply iterate over the left border of our segment from pos+1 to ℓ, and then use a simpler formula to calculate the number of good subsegments with such fixed values.

Why can this left boundary be iterated for each mex if pos<ℓ (correspondingly, if it were pos>r, then we would iterate over the right boundary) ? Let's remember that after this step, ℓ becomes equal to pos. That is, if we iterate over an element, then we move the corresponding border. And we can only move it O(n) times.

