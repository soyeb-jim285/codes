# Tutorial


### [1151A - Maxim and Biology](../problems/A._Maxim_and_Biology.md "Codeforces Round 553 (Div. 2)")

Check every substring of string ss of length 44 and find the minimum number of operations to transform it into "ACTG" and update the answer.

Complexity is O(n)O(n).

 
### [1151B - Dima and a Bad XOR](../problems/B._Dima_and_a_Bad_XOR.md "Codeforces Round 553 (Div. 2)")

Let's take the first number in each array.

Then, if we have current XOR strictly greater than zero we can output an answer.

And if there is some array, such that it contains at least two distinct numbers, you can change the first number in this array to number, that differs from it, and get XOR 0⊕x>00⊕x>0.

Else, each array consists of the same numbers, so all possible XORs are equal to 00, and there is no answer.

Complexity is O(n⋅m)O(n⋅m).

 
### [1151C - Problem for Nazar](../problems/C._Problem_for_Nazar.md "Codeforces Round 553 (Div. 2)")

At first let's simplify the problem. Let's denote as f(x)f(x) function that returns sum of the elements that are on positions from 11 to xx inclusive.

How to implement function f(x)f(x)?

To find the answer we can find the sum of even and sum of odd numbers and add them. Let's find how many there are even and odd numbers. Let's call them curevencureven and curoddcurodd. Iterate through the powers of two. If current power is even, then add minimum from xx and current power of two to curoddcurodd, otherwise add minimum from xx and current power of two to curevencureven, after that reduce xx by current power of two. If xx becomes less than or equal to 00 break.

Now our task is reduced to twos: for given number nn find the sum of first nn even numbers and for given number mm find the sum of first mm odd numbers. The answer for first task is n⋅(n+1)n⋅(n+1). The answer for second task is m2m2.

Now the answer for the problem is f(r)−f(l−1)f(r)−f(l−1).

Don't forget about modulo :)

Complexity is O(logN)O(log⁡N).

 
### [1151D - Stas and the Queue at the Buffet](../problems/D._Stas_and_the_Queue_at_the_Buffet.md "Codeforces Round 553 (Div. 2)")

Firstly, open the brackets: ai⋅(j−1)+bi⋅(n−j)ai⋅(j−1)+bi⋅(n−j) = (ai−bi)⋅j+bi⋅n−ai(ai−bi)⋅j+bi⋅n−ai. As you can see bi⋅n−aibi⋅n−ai is not depending on jj, so we can sum these values up and consider them as constants. 

Now we must minimize the sum of (ai−bi)⋅j(ai−bi)⋅j. 

Let's denote two integers arrays each of length nn: array cc such that ci=ai−bici=ai−bi and array dd such that di=idi=i (for each ii from 11 to nn). Now we must solve the following task: minimize the value ∑ni=1ci⋅di∑i=1nci⋅di if we can rearrange the elements of array cc as we want. To solve this problem we must sort array cc in non-increasing order. You can use an exchange argument to prove it.

Complexity is O(nlogn)O(nlog⁡n).

 
### [1151E - Number of Components](../problems/E._Number_of_Components.md "Codeforces Round 553 (Div. 2)")

First of all assign 00 to a0a0. 

How to find the value of f(l,r)f(l,r) in O(n)O(n)? 

For each ii from 00 to nn set bibi to 11 if l≤ai≤rl≤ai≤r, otherwise set it to 00. Now we can see that the value of f(l,r)f(l,r) is equal to the number of adjacent pairs (0,1)(0,1) in array bb. 

So now we can find the answer in O(n)O(n) using technique contribution to the sum. For every adjacent pair of elements in array aa (including zero-indexed element) we must find it contribution to the overall answer. Considering the thoughts above about f(l,r)f(l,r), we must find the number of pairs (l,r)(l,r) such that aiai is on the range [l,r][l,r] and ai−1ai−1 is not on the range [l,r][l,r]. There are two cases:

What if aiai is greater than ai−1ai−1? Then ll must be on range from ai−1+1ai−1+1 to aiai and rr must be on range from aiai to nn. The contribution is (ai−ai−1)⋅(n−ai+1)(ai−ai−1)⋅(n−ai+1).

What if aiai is less than ai−1ai−1? Then ll must be on range from 11 to aiai and rr must be on range from aiai to ai−1−1ai−1−1. The contribution is ai⋅(ai−1−ai)ai⋅(ai−1−ai).

Sum up the contributions of all adjacent pairs to find the answer.

Complexity is O(n)O(n).

 
### [1151F - Sonya and Informatics](../problems/F._Sonya_and_Informatics.md "Codeforces Round 553 (Div. 2)")

How to solve this problem in O(n⋅k)O(n⋅k)? 

Let's find the answer using dynamic programming. Denote curcur as the number of zeroes in array aa, and dpi,jdpi,j as the number of rearrangements of array aa after ii operations and jj is equal to the number of zeroes on prefix of length curcur. Denote xx as the number of zeroes on prefix of length curcur. The initial state will be dp0,x=1dp0,x=1. Notice that the answer will be dpk,cur∑curi=0dpk,idpk,cur∑i=0curdpk,i. 

The transitions are not so hard. You must know the following values: the number of ones on prefix of length curcur, the number of zeroes on prefix of length curcur, the number of ones NOT on prefix of length curcur and the number of zeroes NOT on prefix of length curcur. For example, you can find the number of pairs such that after we swap them the number of zeroes on prefix of length curcur is increased by one: the number of ones on prefix of length curcur multiply by the number of zeroes NOT on prefix of length curcur. Also there are transitions when the number of zeroes on prefix of length curcur remains the same, and when it decreased by one (you can find them by yourself).

To solve the original problem we must create the transition matrix and find the answer using matrix multiplication with binary exponentiation.

Also you must know how to find the modular multiplicative inverse to find the answer. 

Complexity is O(n3⋅logk)O(n3⋅log⁡k).

