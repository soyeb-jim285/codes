# Tutorial

Thanks for the participation!

 
### [1884A - Simple Design](../problems/A._Simple_Design.md "Codeforces Round 904 (Div. 2)")

Let yy be the answer to the problem. Note that y−x≤18y−x≤18 and the problem can be solved by brute force. We will prove this fact.

If the difference between two numbers is greater than 1818, then there will definitely be a sequence of 1010 numbers where only the last digit differs. Therefore, if the sum of the digits of a number with the last digit 00 is equal to xx, then there were sums of digits equal to x,x+1,…,x+9x,x+1,…,x+9. Here, there are exactly 1010 consecutive numbers and for each kk from 11 to 1010, there exists a number from this range that is divisible by kk.

 
### [1884B - Haunted House](../problems/B._Haunted_House.md "Codeforces Round 904 (Div. 2)")

In order for a number to be divisible by 2i2i, the last ii bits of its binary representation must be equal to 00. For convenience, let's reverse the binary representation of the number so that our operations aim to zero out the first ii bits. Let zerozero be the number of bits equal to 00 in the original string.

If i>zeroi>zero, it is obvious that the answer is −1−1 since our operations do not change the number of zeros and ones in the number. Otherwise, the answer exists, and we will learn how to calculate the minimum number of operations. Consider all j≤ij≤i, where sj=1sj=1. We need to remove these ones from our prefix by replacing them with the nearest zeros after position ii. We will traverse the string from left to right, keeping track of the number of ones in our prefix (denoted as cntcnt) and the sum of their positions (denoted as sum_onesum_one). We also need to maintain the sum of the nearest cntcnt positions of zeros after our element ii (denoted as sum_zerosum_zero). This can be done using a pointer. The answer is sum_zero−sum_onesum_zero−sum_one. This is both a lower bound estimate and can be greedily shown how to obtain this answer in such a number of operations.

First, let's place all the ones at the end of our prefix. We will place the rightmost one at position ii and so on. This can be done in i∑j=i−cnt+1(j−pos)∑j=i−cnt+1i(j−pos) operations, where pospos is the position of the corresponding one, which in general is actually =−sum_one+i∑j=i−cnt+1j=−sum_one+∑j=i−cnt+1ij. Now we want to place zeros at these positions, and we will do this greedily cntcnt times, performing i∑j=i−cnt+1(pos−j)∑j=i−cnt+1i(pos−j) operations, where pospos is the position of 00. Again, the total is =sum_zero−i∑j=i−cnt+1j=sum_zero−∑j=i−cnt+1ij. Our answer is the sum of these two, which is sum_zero−sum_onesum_zero−sum_one.

 
### [1884C - Medium Design](../problems/C._Medium_Design.md "Codeforces Round 904 (Div. 2)")

Let xx be the position of the maximum element in the array aa in the optimal answer. Notice that in this case, we can select all the segments where l≤x≤rl≤x≤r, because if the position of the minimum element is outside of this segment, we increase the answer by +1+1, and if it is inside, we do not worsen the answer. From this, it follows that the minimum will either occur at position 11 or at position mm.

We can then consider the segments that do not contain position 11 (similarly, we can do the same for mm) and find the position that is covered by the largest number of such segments. This can be done using a line sweep algorithm. A segment (l,r)(l,r) corresponds to two events: (l,0)(l,0) - the segment opens, and (r,1)(r,1) - the segment closes. We sort these events and iterate through them, keeping track of the number of open segments at each moment. The maximum value among these quantities is what we need. The solution works in O(nlogn)O(nlogn) time.

 
### [1884D - Counting Rhyme](../problems/D._Counting_Rhyme.md "Codeforces Round 904 (Div. 2)")

Note that if aiai is divisible by akak and ajaj is divisible by akak, then gcd(ai,aj)gcd(ai,aj) is divisible by akak. Let's calculate the number of pairs from the array for each gg, such that the gcdgcd is equal to gg.

To do this, we will create dpgdpg - the number of pairs in the array with gcdgcd equal to gg. For this, we will need an array of counts - cntxcntx, the number of occurrences of the number xx in the array. To calculate dpgdpg, we need to know how many numbers are divisible by gg, specifically the sum s=cntg+cnt2g+…+cntkgs=cntg+cnt2g+…+cntkg, where kg≤nkg≤n. Therefore, the number of pairs with gcdgcd equal to gg is s⋅(s−1)2s⋅(s−1)2. However, not all of them have gcdgcd equal to gg, it can be equal to a number that is a multiple of gg. Therefore, dpg=s⋅(s−1)2−dp2g−…−dpkgdpg=s⋅(s−1)2−dp2g−…−dpkg. This dynamic programming can be calculated in O(nlogn)O(nlogn) time.

Now let's understand which gcdgcd values are not suitable. If there is a number xx in the array (i.e., cntx>0cntx>0), then all gg multiples of xx are not suitable. This can also be calculated in O(nlogn)O(nlogn) time. Finally, we just need to sum up all the dpgdpg values, where the number gg is not divisible by any number in the array.

 
### [1884E - Hard Design](../problems/E._Hard_Design.md "Codeforces Round 904 (Div. 2)")

Let's learn how to solve a problem for a given array. Notice that we want to make all elements equal to the maximum value in the array. For convenience, let's solve a similar problem that is easier to implement. We'll create an array bi=max(a)−aibi=max(a)−ai. Then, instead of performing an addition operation, we'll perform a subtraction operation by −1−1 on a range, aiming to make all elements of the array equal to 00.

Let pospos be the position of the minimum element in the array bb. We can apply the operation bposbpos times on the entire array, and then recursively solve the problem for the left and right parts relative to the position pospos. However, this doesn't help us solve the problem for all shifts. Let's find the nearest element less than or equal to each element on the left (denoted as lili) and the nearest element less than each element on the right (denoted as riri) - this can be done using linear algorithms. Then, we can observe that when we consider the subarray li+1…ri−1li+1…ri−1 in our recursive solution, we add to the answer a value equal to bi−max(bli,bri)bi−max(bli,bri). We have found a solution to the problem in O(n)O(n) time for a fixed array aa.

If we consider all shifts of the array, the nearest elements on the left/right either remain unchanged or simply do not exist, in which case we consider their values to be 00. Therefore, if we fix the position ii (want to determine how much it affects the answer for each position in the array), we have three shift ranges for which we can add different values. Hence, we have O(n)O(n) ranges on which we need to add certain values. Since we don't have to make these additions immediately, we can create an array addiaddi - the value that needs to be added to all elements starting from position ii. Then, adding the number xx on the range l…rl…r changes this array as follows: addl=addl+xaddl=addl+x, addr+1=addr+1−xaddr+1=addr+1−x. The answer to the problem is ansi=i∑j=1addiansi=∑j=1iaddi. This subproblem can be solved in O(n)O(n) time.

Next, we need to learn how to calculate the total cost. The approach will be similar, but now we need to add a more complex function. If both nearest elements are within a shift range, we will add (ri−li−1)2⋅(bi−max(bli,bri)(ri−li−1)2⋅(bi−max(bli,bri) - a fixed number. If there is no nearest element on the left/right, we will add a value of the form (ri−s+1)2⋅(bi−bri)(ri−s+1)2⋅(bi−bri) or (s+n−i+1)2⋅(bi−bli)(s+n−i+1)2⋅(bi−bli), where ss is the index of the start of the shift position. Both cases can be solved similarly. If we expand the brackets, we get an expression of the form a⋅s2+b⋅s+ca⋅s2+b⋅s+c, where a,b,ca,b,c are known coefficients. Let's represent the answer for a fixed shift in this form, and we need to find the value of each coefficient, which is simply adding a fixed number on a range, as we discussed in the previous paragraph. This can also be solved in O(n)O(n) time.

