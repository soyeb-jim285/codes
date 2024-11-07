# Tutorial_1_(en)

[1995A - Diagonals](../problems/A._Diagonals.md "Codeforces Round 961 (Div. 2)")
---------------------------------------------------------------------------------------------------

 **Hint**How many described diagonals are there in total? How many cells do they contain?

 **Answer to Hint**In total we have 2n−1 diagonals. There is only one diagonal that contains n cells, two containing n−1 cells, ..., and two containing only one cell each (namely passing through (1,n) and (n,1)).

 **Solution**Obviously, in this case, it is worth filling the largest diagonal with chips, then two that are smaller in size, and so on. The asymptotics turns out to be O(n).

 **Code**[272176453](https://codeforces.com/contest/1995/submission/272176453 "Submission 272176453 by goncharovmike")

[1995B1 - Bouquet (Easy Version)](../problems/B1._Bouquet_(Easy_Version).md "Codeforces Round 961 (Div. 2)")
------------------------------------------------------------------------------------------------------------------

 **Hint**For each number of petals, we can bruteforce the answer for x,x+1

 **Solution**First, we can aggregate number of flowers with x petals into cx (for example, sort the array and then create array of pairs (x,cx), where cx is the length of segment with elements equal to x). 

Note that ∑xcx=n. Also note that for every x we won't need more than ⌊mx⌋ flowers (otherwise total number of petals will exceed m).

Then we iterate through all x. Suppose that we want to assemble a bouquet with x,x+1 petals. We can bruteforce the amount of flowers with x petals in O(cx). If we have 0≤k1≤min(cx,⌊mx⌋) flowers with x petals, we already have k1∗x petals. There are still m−k1∗x coins which we can spend for flowers with x+1 petals. There are at most k2=min(cx+1,⌊m−k1∗xx+1⌋) flowers with x+1 petal we can buy. So we need to find maximum over all such k1∗x+k2∗(x+1). 

Total complexity is O(∑xcx)=O(n) for finding the maximum and O(nlogn) for sorting.

 **Code**[272263831](https://codeforces.com/contest/1995/submission/272263831 "Submission 272263831 by Vitaly503")

[1995B2 - Bouquet (Hard Version)](../problems/B2._Bouquet_(Hard_Version).md "Codeforces Round 961 (Div. 2)")
------------------------------------------------------------------------------------------------------------------

 **Hint**Maybe there is a way to change bruteforce into checking optimal values for counts of x,x+1? Maybe there are only few types of optimal bouquets for x,x+1?

 **Solution**We already have a list of cx. We can use hash map to be able to check for any cx by x.

We again will try to assemble the bouquet only with flowers with x,x+1 petals. We set k1=min(cx,⌊mx⌋). Then we have coins=m−k1∗x. Let's set k2=min(cx+1,⌊coinsx+1⌋). Then we have coins=m−(k1∗x+k2∗(x+1)). Let's substitute flower with x petals with flower with x+1 petals as many times as we can. This can be done r=min(k1,cx+1−k2,coins) times, as each operation will require us 1 coin, 1 flower in the bouquet with x petals and one 1 flower with x+1 petals not in the bouquet. In total we can get (k1−r)∗x+(k2+r)∗(x+1) petals.

This assembling is optimal. Here is why. Suppose that we have 0≤b1≤cx flowers with x petals and 0≤b2≤cx+1 flowers with x+1 petals and greater total value of b1∗x+b2∗(x+1). We already know that b1≤k1 by choosing of k1. If k1−r<b1, then we can ''undo'' our operation r+b1−k1 times, sum is still not greater than m, and we know that now there can't be more than k2+r+b1−k1 flowers with x+1 petals, as otherwise we didn't chose optimal k2. If k2+r<b2, then r≠cx+1−k2, if r=k1 then it is just the case when we have only flowers with x+1 petals which will be considered in case x+1,x+2, if r=coins then m=(k1−r)∗x+(k2+r)∗(x+1) and we already found the maximum. So b2≤k2+r and b1≤k1−r and b1∗x+b2∗(x+1) is not better than optimal.

Total time complexity is O(n).

 **Code**[272263882](https://codeforces.com/contest/1995/submission/272263882 "Submission 272263882 by Vitaly503")

[1995C - Squaring](../problems/C._Squaring.md "Codeforces Round 961 (Div. 2)")
--------------------------------------------------------------------------------------------------

 **Hint**How many times we need to apply the operation to index i, so that a[i−1]≤a[i]? Let's call it op[i]  
It's easy to calculate these values in no time.  
Can we just accumulate them?

 **Answer to Hint**We almost can. But, let's take [4,2,4] as an example. op[2] = 1, but we don't want to do anything with a[3].  
So, sometimes a[i−1]≤a[i] and we may not want touch a[i] at all, even if something was applied before it.  
So, should we consider making op[i]<0 for some i?

 **Solution Integer**Let's set op[i] to the number of operation we need to apply to index i so that a[i−1]≤a[i].  
But, if a[i−1]≪a[i], let's set it to the negative number of times that we can apply the operation to a[i−1] so that a[i−1]≤a[i] still holds.  
Now let's just calculate the prefix sum prefix_op, don't forget to do max(0,prefix_op[i]). The sum of values in prefix_op is the answer.

 **Solution Float**Let's try to go to the logarithmic space to get rid of too big numbers.  
log(x∗x)=2log(x)  
So, if we replace each value with its logarithm, the operation of squaring becomes multiplying by 2.  
But this is not good enough, since we may need to do the operation thousands of times, 21000 is too big, it doesn't fit into any floating point.  
So, let's just repeat our trick and go to the log-log space  
log(2∗y)=log(y)+log(2)  
Now we see that the operation turns into just adding log(2). We can afford doing that thousands and millions of times.  
Let's deine b[i]=logloga[i]  
So now, we can just go with a for-loop and do ⌈b[i]−b[i−1]log(2)⌉ opeartions with i-th element, updating b[i] accordingly.  
Since initially b[i]≤log(106)≤20log(2), we can maintain the invariant that b[i]≤(20+i)log(2) since after applying an operation to b[i] we can't exceed b[i−1] by more than log(2). It means that the final numbers in the log-log space won't exceed (n+20)log(2). We can maintain O(n) arithmetics using double without any problems.

 **Code Integer**[272174772](https://codeforces.com/contest/1995/submission/272174772 "Submission 272174772 by Akulyat")

 **Code Float**[272174825](https://codeforces.com/contest/1995/submission/272174825 "Submission 272174825 by Akulyat")

[1995D - Cases](../problems/D._Cases.md "Codeforces Round 961 (Div. 2)")
-----------------------------------------------------------------------------------------------

 **Hint 1**If letter is chosen as an ending to some case, each occurrence of this letter may in the text can be considered an ending?

 **Hint 2**The length of the word is something too complex. How can you simplify the restriction?

 **Answer to Hint 2**The final letter must be an ending of some case and among any k consecutive letters there must be at least one ending.

 **Hint 3**Now you don't need the text because you can store bitmasks instead of substrings of length k. To calculate the bitmasks you can use prefix sums for each of the characters (it will take O(cn) overall).

 **Hint 4**Now you need to find a bitmask with a minimal number of ones which intersects all the stored bitmasks.

 **Hint 5**Identify "bad" bitmask instead of "good" ones.

 **Solution**(Read the hints.) b is bad if there exists stored a such that a&b=0 which is equivalent to b being a submask of ~a. All such b can be found using simple dp on bitmasks. The rest b are good.

Time complexity: O(cn+c2c)

 **Code**[272218277](https://codeforces.com/contest/1995/submission/272218277 "Submission 272218277 by ikrpprppp")

[1995E1 - Let Me Teach You a Lesson (Easy Version)](../problems/E1._Let_Me_Teach_You_a_Lesson_(Easy_Version).md "Codeforces Round 961 (Div. 2)")
------------------------------------------------------------------------------------------------------------------------------------

 **Hint 1**Consider cases of odd and even n. Which one is simpler?

 **Answer to Hint 1**Even. In this case you can solve the problem for the opposite desks independently. From now on n is odd.

 **Why independently?**Let a desk have knights with intelligence a, b and the opposite one with c, d. Since (a+b)+(c+d)=(a+c)+(b+d), the minimal total intelligence on these desks is greater iff the maximal total intelligence is less. 

 **Hint 2**If you reorder desks/knights in a way that you swap neighbors (i.e. 2 with 3, 4 with 5, ..., 2n with 1) instead of opposite knights, it'll probably become easier to think about this problem. We will use this notation from now on.

 **Hint 3**You're allowed to run in O(n2). Wouldn't it have sense to fix some entity and solve in linear time for fixed entity?

 **Answer to Hint 3**Fix the minimal (maximal) desk and the knights who are sitting at it (if the original knights were swapped or not). You'll need to find the minimal maximum on a desk for 4n such cases.

 **Hint 4**DP.

 **Solution**(Read the hints.) Let the fixed desk have index k. Let dpi,b (where i is the index of the desk and b is 0 / 1 which indicates whether the knight 2i was swapped) be the minimal maximum that can be achieved on a segment from k to i (satisfying bit b and the fact that the desk k is actually minimal). Then you can easily make transitions dpi,0,dpi,1→dpi+1,0,dpi+1,1. In the end you'll just need to check dpk−1,b′ where b′ indicates whether the knight 2∗k−1 was swapped in our choice.

(All the indices for the desks are taken modulo n and all the indices for the knights are taken modulo 2n.)

Time complexity: O(n2), but the constant is large and O(n2logn) solutions with binary search are unlikely to pass.

 **Code**[272207462](https://codeforces.com/contest/1995/submission/272207462 "Submission 272207462 by ikrpprppp")

[1995E2 - Let Me Teach You a Lesson (Hard Version)](../problems/E2._Let_Me_Teach_You_a_Lesson_(Hard_Version).md "Codeforces Round 961 (Div. 2)")
------------------------------------------------------------------------------------------------------------------------------------

 **Hint 0**Read the first two hints to E1.

 **Hint 1**There are 4n possible desks in total. One of them will be the minimal desk and another one will be the maximal. What is the common-used technique for such problems?

 **Answer to Hint 1**Sort them and then use two pointers.

 **Hint 2**The data structure you need is very famous.

 **Solution**(Read the hints.) Assign a boolean matrix 2×2 to each of the desks. Rows correspond to the first knight at the desk (two rows for each of the events "the knight was swapped" / "the knight was not swapped"), columns correspond to the second one. The value in the intersection is true if under current restrictions (minimum and maximum) both events can happen, i.e. the result on the desk is between minimum and maximum.

What is a (boolean) multiplication of matrices from dl to dr?

 **Answer**The matrix where the rows correspond to the knight 2dl−1 and the columns correspond to the knight 2dr.

To determine whether it's possible to swap the knights under current restrictions you can just multiply all the matrices and check if there are ones on the main diagonal. Now using two pointers and a segment tree on these matrices you can solve the problem (basically, when you leave some option for a desk in the sorted array of options, you change one of the values of this matrix from 1 to 0, and vice versa).

 **Code**[272212685](https://codeforces.com/contest/1995/submission/272212685 "Submission 272212685 by ikrpprppp")

