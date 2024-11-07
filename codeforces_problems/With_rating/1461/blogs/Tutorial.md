# Tutorial


### [1461A - String Generation](../problems/A._String_Generation.md "Codeforces Round 689 (Div. 2, based on Zed Code Competition)")

Let's note that the string like "abcabcabcabc..." has only palindromes of length 1, what means it is suitable for us in all cases.

**Authors:** [AleXman111](https://codeforces.com/profile/AleXman111 "Candidate Master AleXman111"), [sdryapko](https://codeforces.com/profile/sdryapko "Candidate Master sdryapko")

**author's solution:** [100959880](https://codeforces.com/contest/1461/submission/100959880 "Submission 100959880 by AleXman111")

 
### [1461B - Find the Spruce](../problems/B._Find_the_Spruce.md "Codeforces Round 689 (Div. 2, based on Zed Code Competition)")

Let's iterate over the top of the spruce. When we meet the symbol "*", we will start iterating over the height of the current spruce. If for the current height $k$ for each $1 \le i \le k$ all cells with the row number $x+i-1$ and columns in range $[y - i + 1, y + i - 1]$ are "*", then we increase the value of the answer. Otherwise, we stop the increment hight.

**Author:** [Vladik](https://codeforces.com/profile/Vladik "Master Vladik")

**author's solution:** [100960218](https://codeforces.com/contest/1461/submission/100960218 "Submission 100960218 by AleXman111")

 
### [1461C - Random Events](../problems/C._Random_Events.md "Codeforces Round 689 (Div. 2, based on Zed Code Competition)")

Let's first define some variable $R$, which will be equal to the last unsorted number (the largest $i$ for which $r_i != i$).

Now we can see that we are not interested in experiments with $r_i < R$.

To get the answer, we just need to multiply the remaining $(1-p_i)$. This number will indicate the probability that all the remaining experiments failed. Since we need to deduce the probability of success, we can subtract the resulting number from one.

**Author:** [Vladik](https://codeforces.com/profile/Vladik "Master Vladik")

**author's solution:** [100960332](https://codeforces.com/contest/1461/submission/100960332 "Submission 100960332 by AleXman111")

 
### [1461D - Divide and Summarize](../problems/D._Divide_and_Summarize.md "Codeforces Round 689 (Div. 2, based on Zed Code Competition)")

To begin with, you can notice that the cut operation does not depend on the order of the $a$ array. So we can sort it.

Now let's build a tree of transitions from the original array to all its possible states. You can simply prove that the height of this tree does not exceed $log(max)$. Since $max(current_a)-min(current_a)$ after each operation of the section is reduced at least twice.

Having understood this, we can write a simple recursive search over the states $(left, right)$. The state will describe a sub-segment of the $a$ array that is the current array. For each state, we can calculate the current amount (on the segment from left to right) and add it to any convenient collection (set/HashSet).

Next, to respond to requests, we can simply look at our collected collection.

**Author:** [Vladik](https://codeforces.com/profile/Vladik "Master Vladik")

**author's solution:** [100960452](https://codeforces.com/contest/1461/submission/100960452 "Submission 100960452 by AleXman111")

 
### [1461E - Water Level](../problems/E._Water_Level.md "Codeforces Round 689 (Div. 2, based on Zed Code Competition)")

If $y \le x$, it is quite easy to calculate the answer. Note that at each iteration of the algorithm (except, perhaps, the first), the water level will decrease by x-y liters, and we will have to calculate whether it can decrease t times.

Otherwise, lets note, when we use the rise in water level, we change the value of the expression $k$ mod $x$. At each step of the algorithm, we will lower the water level as many times as we can, and then raise the level. Further, we note that if we have already reached the value $k$ mod $x$, then we are in a "cycle", and therefore we will be able to maintain the water level. If the water level is out of bounds, then the answer is No.

**Authors**: [AleXman111](https://codeforces.com/profile/AleXman111 "Candidate Master AleXman111"), [sdryapko](https://codeforces.com/profile/sdryapko "Candidate Master sdryapko")

**author's solution:** [100960607](https://codeforces.com/contest/1461/submission/100960607 "Submission 100960607 by AleXman111")

 
### [1461F - Mathematical Expression](../problems/F._Mathematical_Expression.md "Codeforces Round 689 (Div. 2, based on Zed Code Competition)")

First, let's solve the problem without the multiplication sign. It is always beneficial for us to put a plus or a minus, if there is no plus sign.

Now we will solve the problem when there is a sign to multiply. The case when the plus sign is missing is very easy to solve. We put the sign to multiply to the first zero, then we put a minus sign in front of the zero, and after the multiplication signs. Let's consider the case when there is a plus sign and multiply.

Note that it is never beneficial for us to use the minus sign. If there are zeros in the expression, then we simply put plus signs between them and the expressions are split into other independent expressions.

Now you need to be able to solve an expression that has no zeros. To begin with, we take out all units at the beginning and at the end separately with plus signs. The following solution is now proposed. If the product of numbers is greater than or equal to $10^{16}$, then it is beneficial for us to put the multiplication sign everywhere. Otherwise, we can use dynamic programming, because the number of numbers greater than one is no more than $log_2(10^{16})$. Dynamic programming will be one dimension. $dp_i$ is the most profitable answer if you put signs on the prefix. Let us now stand at $i$ and want to go to $j$, this means that between the numbers at the $i$-th and $j$-th positions there will be a sign to multiply, and after the $j$-th position there will be a sign a plus.

**Author:** [AleXman111](https://codeforces.com/profile/AleXman111 "Candidate Master AleXman111")

**author's solution:** [100960771](https://codeforces.com/contest/1461/submission/100960771 "Submission 100960771 by AleXman111")

