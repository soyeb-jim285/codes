# Video_Tutorial_(en)

[1998A - Find K Distinct Points with Fixed Center](../problems/A._Find_K_Distinct_Points_with_Fixed_Center.md "Codeforces Round 965 (Div. 2)")

 **Idea**Chose A1=(K∗XC,K∗YC)A1=(K∗XC,K∗YC).  
The remaining points such that sum of x coordinates and y coordinates is 0.

My submission — [275541733](https://codeforces.com/contest/1998/submission/275541733 "Submission 275541733 by aryanc403")

 **Video editorial**[![Video](https://img.youtube.com/vi/BpJ-bOqOGNU/0.jpg)](https://www.youtube.com/watch?v=BpJ-bOqOGNU)



[1998B - Minimize Equal Sum Subarrays](../problems/B._Minimize_Equal_Sum_Subarrays.md "Codeforces Round 965 (Div. 2)")

 **Hint 1**Sum of all elements will be equal in both permutations.  
So no of such (i,j)(i,j) is atleast 1.  
Can you find a permutation QQ such that this count remains 1?

 **Hint 2**Set Qi=1Qi=1 if Pi=NPi=N,  
Set Qi=1+PiQi=1+Pi if Pi<NPi<N, otherwise 

 **Hint 3**Set Qi=P(i+1)modNQi=P(i+1)modN 

My submission — [275547485](https://codeforces.com/contest/1998/submission/275547485 "Submission 275547485 by aryanc403")

 **Video editorial**[![Video](https://img.youtube.com/vi/BpJ-bOqOGNU/0.jpg)](https://www.youtube.com/watch?v=BpJ-bOqOGNU)



[1998C - Perform Operations to Maximize Score](../problems/C._Perform_Operations_to_Maximize_Score.md "Codeforces Round 965 (Div. 2)")

**My solution is a bit overkill, check out** [neal](https://codeforces.com/profile/neal "International Grandmaster neal") submission [275613185](https://codeforces.com/contest/1998/submission/275613185 "Submission 275613185 by neal")

 **Hint 1**Lets forget about AiAi and focus on CiCi first.  
If we have and array of N−1N−1 elements AiAi and binary array of N−1N−1 elements BiBi.  
What is the maximum median we can get using atmax KK operations?

 **Hint 2**We can binary search for median.  
We can directly count how many elements are more than mid, and how many elements we can make more than median.  
Using segment tree, walk on segment tree and blah blah blah............

My submission — [275635373](https://codeforces.com/contest/1998/submission/275635373 "Submission 275635373 by aryanc403")

 **Video editorial**[![Video](https://img.youtube.com/vi/BpJ-bOqOGNU/0.jpg)](https://www.youtube.com/watch?v=BpJ-bOqOGNU)



[1998E1 - Eliminating Balls With Merging (Easy Version)](../problems/E1._Eliminating_Balls_With_Merging_(Easy_Version).md "Codeforces Round 965 (Div. 2)")

 **Hint 1**Notice that at any point all the elements are sum of continous subarray. 

 **Hint 2**Define a function solve(L,R) which returns true, if we can convert element with weight ∑AL+AL+1+....+AR∑AL+AL+1+....+AR into an element with weight ∑A∑A

 **Hint 3**Use greedy, for fixed index LL and RR, find a minimum nxtLnxtL such that ∑AnxtL+AnxtL+1+...+AL−1≤AL+AL+1+....+AR∑AnxtL+AnxtL+1+...+AL−1≤AL+AL+1+....+AR, make a direct jump to nxtL,RnxtL,R segment. 

 **Hint 4**Do similar for nxtRnxtR, and memorise all the answer of solve function. 

My submission — [275608667](https://codeforces.com/contest/1998/submission/275608667 "Submission 275608667 by aryanc403")

 **Video editorial**[![Video](https://img.youtube.com/vi/BpJ-bOqOGNU/0.jpg)](https://www.youtube.com/watch?v=BpJ-bOqOGNU)



[1998E2 - Eliminating Balls With Merging (Hard Version)](../problems/E2._Eliminating_Balls_With_Merging_(Hard_Version).md "Codeforces Round 965 (Div. 2)")

 **Hint 1**For each element jj there is a range (Lj,Rj)(Lj,Rj) in which it can be present as last elemt.

 **Hint 2**Modify the Solve function to now return what is the minimum index LjLj, instead of boolean earlier.

Basically find minimum LjLj such that element jj can become ∑A1+A2+...ALj∑A1+A2+...ALj

 **Hint 3**Also for each index ii precalcute how much right it can go.  
Use this to calculate RjRj based on LjLj. 

 **Hint 4**Otherway around you can also return this range in your solve function. 

My submission — [275619707](https://codeforces.com/contest/1998/submission/275619707 "Submission 275619707 by aryanc403")

 **Video editorial**[![Video](https://img.youtube.com/vi/BpJ-bOqOGNU/0.jpg)](https://www.youtube.com/watch?v=BpJ-bOqOGNU)



