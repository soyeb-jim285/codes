# T_(en)


### [978A - Remove Duplicates](../problems/A._Remove_Duplicates.md "Codeforces Round 481 (Div. 3)")

We will store integers which we already met in a set $exist$. Let's iterate through the given array from the right to the left. Let the current element is equal to $x$. So, if $x$ does not contain in $exist$ we add $x$ in a vector-answer $ans$ and add $x$ in $exist$.

After we considered all elements the answer sequence contains in the vector $ans$ in reversed order. So we should reverse the vector $ans$ and simply print all its elements. 

 
### [978B - File Name](../problems/B._File_Name.md "Codeforces Round 481 (Div. 3)")

Let's iterate through the given string from the left to the right. In a variable $cnt$ we will store the number of letters "x" which were before the current letter in a row. If the current letter does not equal to "x" we should make $cnt = 0$. In the other case, the current letter equals to "x". If $cnt < 2$, we should increase $cnt$ by one. In the other case, we should add one to the answer because the current letter should be removed.

 Tutorial is loading... 
### [978D - Almost Arithmetic Progression](../problems/D._Almost_Arithmetic_Progression.md "Codeforces Round 481 (Div. 3)")

If $n \le 2$ we can print $0$, because each such sequence is an arithmetic progression.

Note, that an arithmetic progression is uniquely determined by the first two terms. So we should brute $d_1$ from $-1$ to $1$ — the change of the first element of the given sequence, and $d_2$ from $-1$ to $1$ — the change of the second element of the given sequence. Then $a_1 = b_1 + d_1$ and $a_2 = b_2 + d_2$. Also we will store $cnt$ — the number of changed elements in the sequence. 

Initially $cnt = |d_1| + |d_2|$. Now we need to iterate through the sequence from the third element to $n$-th. Let current element in the position $i$. It should be equals to $a_i = a_1 + (i - 1) \cdot (a_2 - a_1)$. If $|a_i - b_i| > 1$, then such arithmetic progression is unreachable. Else, if $a_i \ne b_i$ we should increase $cnt$ on one. 

After we considered all elements we should update the answer with the value of $cnt$, if for all $i$ it was true that $|a_i - b_i| \le 1$.

 
### [978E - Bus Video System](../problems/E._Bus_Video_System.md "Codeforces Round 481 (Div. 3)")

Firstly we should find the minimum and maximum numbers of passengers, which could be in a bus if initially it was empty. Let $b = 0$. We should iterate through the bus stops. For the $i$-th bus stop, we add $a_i$ to $b$ and update with a value of $b$ the minimum number of passengers $minB$ and the maximum number of passengers $maxB$. 

If $maxB > w$, it is an invalid case and we should print 0, because the maximum number of passengers should be less or equal to $w$.

Let $lf$ is a minimum possible number of passengers in the bus before the first stop and $rg$ — maximum possible.

If $minB < 0$ then in the bus initially were at least $-minB$ passengers. Because we should make $lf = -minB$, else, $lf = 0$.

If $maxB \le 0$, then $rg = w$, else, $rg = w - maxB$.

After that we should compare $lf$ and $rg$. If $lf > rg$ — print 0. In the other case, print $rg - lf + 1$, because each of those values is correct.

 
### [978F - Mentors](../problems/F._Mentors.md "Codeforces Round 481 (Div. 3)")

Firstly we should sort all programmers in non-decreasing order of their skills. Also we need to store initially numbers of the programmers (we can user array of pairs — skill and initial number of the programmer).

We will iterate through the programmers from the left to the right. The current programmer can be a mentor of all programmers to the left of him after sort and with who he are not in a quarrel. Let the number of programmers to the left is $x$. Subtract from $x$ the number of already considered programmers, who skill equals to the skill of the current programmer (it can be done, for example, with help of $map$). Also lets brute all programmers with who the current programmer in a quarrel (we can initially save for each programmer the vector of programmers with who he in a quarell; by analogy with the stoe of graphs) and if the skill of the current programmer more than the skill of a programmers, with which he in a quarrel, we should decrease $x$ on one, because this programmer is to the left of the current after sort and has been counted in $x$.

We should store by a number of the current programmer the value $x$ as answer for him.

 
### [978G - Petya's Exams](../problems/G._Petya's_Exams.md "Codeforces Round 481 (Div. 3)")

If in the current day there is no exam, we should prepare for an exam, for which questions already given, for which we prepare less than needed and which will be before other remaining exams.

For this we will use array $cnt$, where $cnt_i$ equals to the number of days, which we already prepared for exam $i$. Initially, array $cnt$ consists of zeroes.

Let's iterate through the days. Suppose exam $x$ is in the current day. If $cnt_x < d_x$, we did not have time to prepare for it and we should print -1. In the other case, in this day we will pass the exam $x$.

In the other case, let iterate through all exams and choose exam $x$, for which we need still to prepare (i. e. $cnt_x < d_x$), for which already given the questions, and which will be before other remaining exams. If there is no such exam, we should relax in this day, else, in this day we should prepare for exam $x$. Also, we should increase $cnt_x$ by one.

