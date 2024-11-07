# Tutorial_(en)

**[1421A — XORwice](../problems/A._XORwice.md)**

Idea and solution: [flaviu2001](https://codeforces.com/profile/flaviu2001 "Master flaviu2001")

 **Hint**Think about addition in base two. Say a = 10101 and b = 1001. What your operation does is it modifies the bits in your numbers, so if the first bit in a is 1 and the first bit in b is 1 (as is the case above) you can make both 0 by making that bit 1 in x. This is actually the only way you can decrease the resulting sum, so x = 1 is an answer above.

 **Solution**Noticing the hint above we now deduce x = a & b where & is bitwise AND. So just printing (a ⊕ (a & b)) + (b ⊕ (a & b)) works, but there's an even nicer formula. We'll leave it up to you to prove that (a ⊕ (a & b)) + (b ⊕ (a & b)) = a ⊕ b, where ⊕ is the bitwise XOR :)

**[1421B — Putting Bricks in the Wall](../problems/B._Putting_Bricks_in_the_Wall.md)**

Idea: [flaviu2001](https://codeforces.com/profile/flaviu2001 "Master flaviu2001"), solution: [flaviu2001](https://codeforces.com/profile/flaviu2001 "Master flaviu2001") and [stefdasca](https://codeforces.com/profile/stefdasca "Master stefdasca")

 **Hint**It's hard to use the two valuable switches somewhere in the middle of the matrix, a much wiser choice would be to somehow block the S cell or the F cell. Perhaps you can set both neighbours of S to 1 to force Roger to pick 1.

 **Solution**If we pick the neighbours of S to be 1 we can make the neighbours of F 0 and there would be no way to go from S to F. But this requires in the worst case 4 switches, which is not good enough. Luckily, in order to get down to 2 switches we only have to consider the other way around, making the squares neighboring S become 0 and the squares neighboring F 1. There must be a solution of the two with at most two switches and you won't get from S to F since you're forced to pick 1 (or 0) and can't get past the neighbours of F which are opposite.

**[1421C — Palindromifier](../problems/C._Palindromifier.md)**

Idea and solution: [flaviu2001](https://codeforces.com/profile/flaviu2001 "Master flaviu2001")

 **Hint**You're not allowed to just pick the whole string and append its reversed result to the front, but what's the next best thing? We're very close to the answer if we take the whole string except for a letter (so for abcde we make dcbabcde).

 **Solution**The operation above which transformed abcde into dcbabcde is very close, if only we could've somehow append e to the left. Turns out you can set that up, so from abcde first append d to the end, then you have abcded. Now apply the operation from the hint on this string and get edcbabcded. See why we added that d first? We can now append it to the front just like we wanted!. Do the operation L 2 and the job is finished. 

Yep, amazingly just printing

R n−1

L n

L 2

works!

**[1421D — Hexagons](../problems/D._Hexagons.md)**

Idea: [flaviu2001](https://codeforces.com/profile/flaviu2001 "Master flaviu2001"), solution: [flaviu2001](https://codeforces.com/profile/flaviu2001 "Master flaviu2001") and [koala_bear00](https://codeforces.com/profile/koala_bear00 "Expert koala_bear00")

 **Hint**Using too many edges in the solution feels wasteful, the solution surely has some neat line as straight as possible. Perhaps we can prove only two edges are required?

 **Solution**Indeed two edges are required in the solution, so one approach would be picking all combinations of edges and do linear algebra so see how many times each is required (or if it's impossible).

To prove that let's suppose our target is somewhere reachable by only taking C1 and C2 (the upper right sextant, a sixth division of the plane). C4 and C5 will never be used since they contribute in the wrong direction. We can now use C6, C1, C2 or C3 for our solution. If using C1 and C2 is not optimal we can choose C3 or C6, without loss of generality we choose C3. C6 cannot be used because it simply counters C3. Now we either use C1, C2 or C3, but we can further narrow down to just two edges. If we use all three this means we use C1 + C3 which goes the same way as C2, and C2 also goes the same way as C1 + C3. So we can just not use C2 if C1 + C3 < C2, or use C2 instead of C1 + C3 until either of C1 or C3 doesn't appear anymore on our solution.

**[1421E — Swedish Heroes](../problems/E._Swedish_Heroes.md)**

Idea and solution: [flaviu2001](https://codeforces.com/profile/flaviu2001 "Master flaviu2001")

 **Hint**The problem gives us an array and we have to come up with an achievable sequence of pluses and minuses such that summing the numbers after applying the signs we get the largest sum. Intuitively we can probably assign + to most positive numbers and — to most negative numbers somehow, but we should investigate exactly which are possible.

 **Sneaky corner case**Before you try to find patterns you should observe that there is one case that is impossible to reach. You cannot assign alternating + and — to the array, like +−+−+−+− or −+−+−+−+. The reason is very simple, the very first thing you do is apply the operation on two consecutive numbers and make them both −−, and whenever you apply further operations on the both of them they remain the same sign. In the end we decided to give this in the samples but we know from testing many would miss this case.

 **Solution**In order to explain the solution we will add some notations: 

n = the length of the array.

m = the number of elements we multiply by −1 in the solution (put — in front of them).

p = the number of elements we do not multiply by −1 in the solution (put + in front of them).

The mysterious pattern is as follows: (n + m) % 3 = 1

So yes, for n = 7 for example we can put 3 minus signs anywhere, like ++−−+−+, or 6 minus signs like −−+−−−− or full plus signs +++++++. We can arrange the pluses and minuses however we want as long as there are 2 consecutive equal signs and (n + m) % 3 = 1.

The solution now simply requires us to sort the array and multiply by −1 each number one by one and when (n + m) % 3 = 1 update the answer with the current sum. Of course there is one point where all the elements might form the forbidden +−+−+− so you should check that in that case they do not, or if they do pick the next smallest number to turn into — instead of the last one. So for the sample [4,−5,9,−2,1] you sort and get [−5,−2,1,4,9] and when you turn −5 into 5 instead of turning −2 into 2 you turn 1 into −1 and the array will be [5,−2,−1,4,9]. After that undo your modification, turn −2 into 2 and revert −1 to 1.

 **Proof for the pattern**The proof can be done via induction, but I will try to explain why this happens. Suppose your solution looks like +−−+−−−+. What we need to do is to split into two substrings such that their negation is achievable and we are done, they will concatenate and reverse each sign. So we can split into (+−−) and (+−−−+) and notice that their negations are (−++) and (−+++−) which are achievable ((n + m) % 3 = 1 for both and are not alternating). We can always find such a split, start at the left-most point and see if you can split into (+) and (−−+−−−+). You can't, the negation of (+) is just (−) which you can't have. Splitting into (+−) and (+−−−+) won't do either for the same reasons, but (+−−) and (+−−−+) work, actually if the left substring starts with a + the very first time the last two signs are equal is a time where we can make the split, something like (+−+−++) when reversed will always have (n + m) % 3 = 1. So now you see even clearer why the corner case +−+−+ exists, you can never split it into two substrings where the last two signs of the first substring are equal.

You can also see the video solutions on [stefdasca](https://codeforces.com/profile/stefdasca "Master stefdasca")'s [Youtube channel](https://codeforces.com/https://www.youtube.com/channel/UCyTPeByJ_FvAJljtc0svt-Q?view_as=subscriber)

