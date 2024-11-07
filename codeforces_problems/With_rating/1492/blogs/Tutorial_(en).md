# Tutorial_(en)

Thanks for the participation!

[1492A - Three swimmers](../problems/A._Three_swimmers.md "Codeforces Round 704 (Div. 2)") was authored by [meshanya](https://codeforces.com/profile/meshanya "Grandmaster meshanya") and prepared by [ch_egor](https://codeforces.com/profile/ch_egor "International Grandmaster ch_egor")

[1492B - Card Deck](../problems/B._Card_Deck.md "Codeforces Round 704 (Div. 2)") was authored by [Noam527](https://codeforces.com/profile/Noam527 "International Grandmaster Noam527") and prepared by [ch_egor](https://codeforces.com/profile/ch_egor "International Grandmaster ch_egor"), [adedalic](https://codeforces.com/profile/adedalic "International Master adedalic")

[1492C - Maximum width](../problems/C._Maximum_width.md "Codeforces Round 704 (Div. 2)") was authored and prepared by [Jatana](https://codeforces.com/profile/Jatana "International Grandmaster Jatana")

[1492D - Genius's Gambit](../problems/D._Genius's_Gambit.md "Codeforces Round 704 (Div. 2)") was authored by [voidmax](https://codeforces.com/profile/voidmax "Grandmaster voidmax") and prepared by [rip](https://codeforces.com/profile/rip "Master rip")

[1492E - Almost Fault-Tolerant Database](../problems/E._Almost_Fault-Tolerant_Database.md "Codeforces Round 704 (Div. 2)") was authored by [wrg0ababd](https://codeforces.com/profile/wrg0ababd "Expert wrg0ababd") and prepared by [Sehnsucht](https://codeforces.com/profile/Sehnsucht "Candidate Master Sehnsucht")

 
### [1492A - Three swimmers](../problems/A._Three_swimmers.md "Codeforces Round 704 (Div. 2)")

The answer is just min(⌈pa⌉⋅a,⌈pb⌉⋅b,⌈pc⌉⋅c)−pmin(⌈pa⌉⋅a,⌈pb⌉⋅b,⌈pc⌉⋅c)−p.

Complexity: O(1)O(1).

 
### [1492B - Card Deck](../problems/B._Card_Deck.md "Codeforces Round 704 (Div. 2)")

It's easy to prove that order of a deck differs for different permutations. And more than that order of permutation aa is greater than order of permutation bb if and only if aa is lexicographically greater than bb.

Since we need to build a lexicographic maximum permutation, at each point of time we need to choose such kk that kk-th element from the top of the original deck is the maximum element in this deck. 

Total complexity is O(nlogn)O(nlogn) or O(n)O(n) (depending on the implementation).

 
### [1492C - Maximum width](../problems/C._Maximum_width.md "Codeforces Round 704 (Div. 2)")

For some subsequence of the string ss, let pipi denote the position of the character titi in the string ss. For fixed ii, we can find a subsequence that maximizes pi+1−pipi+1−pi. 

Let lefti and righti be the minimum and maximum possible value of pi among all valid ps. Now, it is easy to see that the maximum possible value of pi+1−pi is equal to righti+1−lefti. 

To calculate lefti we just need to find the first element after lefti−1 which is equal to ti. This can be done by a simple greedy or dp algorithm. righti can be found in the same way. 

So, after finding left and right, the answer is maxi=n−1i=1righti+1−lefti.

Complexity: O(n+m).

 
### [1492D - Genius's Gambit](../problems/D._Genius's_Gambit.md "Codeforces Round 704 (Div. 2)")

This problem has a cute constructive solution. 

If a=0 or b=1 the answer is trivial. In other cases let's fix x as a number in form 111…1100…000. Let y=x, then we will change only y. 

Let's take the last 1 digit from the consecutive prefix of ones, then move it min(k,a) positions to the right. It is easy to see, that the number of ones in x−y has increased by min(k,a). If k≤a we already have the answer. 

If not, let's take the last 1 digit from the consecutive prefix of ones and move it one position to the right. The number of ones in the answer increased by one and if it is less than k, we just repeat this move. With this construction we can easily build an answer for every k≤a+b−2

It's not difficult to prove that the answer does not exist when k>a+b−2. 

 
### [1492E - Almost Fault-Tolerant Database](../problems/E._Almost_Fault-Tolerant_Database.md "Codeforces Round 704 (Div. 2)")

Let's look at the first array. Every possible answer (if there is any) should not differ from this array in more than 2 positions. So we should try to change at most 2 positions in the first array to find a consistent answer.

Let's look at the other arrays. We can ignore each other array that differ with the first array in no more than 2 positions. In particular, if every array doesn't differ in more than 2 position, we can just print the first array as an answer.

If an array differs in 5 (or more) positions, then no answer exists.

Suppose that we selected an array with 3 or 4 diffs. This means that we must change 1 or 2 positions (respectively) in the first array to reduce it to 2 diffs. We have 3 or 6 ways to do this (respectively), and can go through all the options.

After changing, we should look at all arrays again and make changes in the first array again if required (but no more than in 2 positions in total) in a recursive backtracking manner. If we don't get an answer, we should go back and try another option.

The time complexity is O(n⋅m) with a decent constant.

Bonus1: If allowed number of diffs is k, can you solve problem in O(kknm) time?

Bonus2: If allowed number of diffs is k, can you solve problem in O(nm+kk√nm) time?

