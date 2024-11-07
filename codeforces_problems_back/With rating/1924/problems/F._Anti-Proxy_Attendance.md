<h1 style='text-align: center;'> F. Anti-Proxy Attendance</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem!

Mr. 1048576 is one of those faculty who hates wasting his time in taking class attendance. Instead of taking attendance the old-fashioned way, he decided to try out something new today.

There are $n$ students in his class, having roll numbers $1$ to $n$. He knows that exactly $1$ student is absent today. In order to determine who is absent, he can ask some queries to the class. In each query, he can provide two integers $l$ and $r$ ($1\leq l\leq r\leq n$) and all students whose roll numbers are between $l$ and $r$ (inclusive) will raise their hands. He then counts them to determine if the roll number of the absent student lies between these values.

Things seemed fine until his teaching assistant noticed something — the students are dishonest! Some students whose roll numbers lie in the given range may not raise their hands, while some other students whose roll number does not lie in the given range may raise their hands. But the students don't want to raise much suspicion. So, only the following $4$ cases are possible for a particular query $(l,r)$ — 

1. True Positive: $r-l+1$ students are present and $r-l+1$ students raised their hands.
2. True Negative: $r-l$ students are present and $r-l$ students raised their hands.
3. False Positive: $r-l$ students are present but $r-l+1$ students raised their hands.
4. False Negative: $r-l+1$ students are present but $r-l$ students raised their hands.

In the first two cases, the students are said to be answering honestly, while in the last two cases, the students are said to be answering dishonestly. The students can mutually decide upon their strategy, not known to Mr. 1048576. Also, the students do not want to raise any suspicion and at the same time, want to create a lot of confusion. So, their strategy always meets the following two conditions — 

1. The students will never answer honestly $3$ times in a row.
2. The students will never answer dishonestly $3$ times in a row.

Mr. 1048576 is frustrated by this act of students. So, he is willing to mark at most $2$ students as absent (though he knows that only one is). The attendance is said to be successful if the student who is actually absent is among those two. Also, due to limited class time, he can only ask up to $\lceil\log_{1.116}{n}\rceil-1$ queries (weird numbers but okay). Help him complete a successful attendance.

## Interaction

First read a line containing a single integer $t$ ($1\leq t\leq 2048$) denoting the number of independent test cases that you must solve.

For each test case, first read a line containing a single integer $n$ ($3\leq n\leq 10^5$). Then you may ask up to $\lceil\log_{1.116}{n}\rceil-1$ queries.

To ask a query, print a single line in the format "? l r" (without quotes) $(1\leq l\leq r\leq n)$. Then read a single line containing a single integer $x$ ($r-l\leq x\leq r-l+1$) denoting the number of students who raised their hands corresponding to the query.

To mark a student as absent, print a single line in the format "! a" (without quotes) $(1\leq a\leq n)$. Then read a single integer $y$ ($y\in\{0,1\}$). If the student with roll number $a$ was absent, $y=1$, else, $y=0$. ## Note

 that this operation does not count as a query but you can do this operation at most $2$ times.

To end a test case, print a single line in the format "#" (without quotes). Then you must continue solving the remaining test cases.

If you ask more queries than allowed or ask an invalid query, you will get the Wrong answer verdict.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

After printing the answers, do not forget to output end of line and flush the output buffer. Otherwise, you will get the verdict Idleness limit exceeded. To flush the buffer, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* Read documentation for other languages.

## Note

 that the grader for this problem is adaptive meaning that the answer may change depending on your queries but will always remain consistent with the constraints and the answer to the previous queries.

Input format for Hacks

The test cases for this problem use both non-adaptive and adaptive graders. You can use the non-adaptive grader for making hacks.

The first line of input contains a single integer $t$ ($1\leq t\leq 2048$).

The first line of each test case contains three integers $g$, $n$ and $x$ where $g=1$ (to identify that this test case must use the non-adaptive grader), $n$ ($3\leq n\leq 10^5$) represents the number of students in the class and $x$ ($1\leq x\leq n$) represents the roll number of the student who is absent. You must ensure that the sum of $n$ over all test cases does not exceed $10^5$.

The second line of each test case contains a single string $S$ ($1\leq\vert S\vert\leq 120, S_i\in \{\texttt{T},\texttt{F}\}$). This string represents the pattern of the truth sequence. If $S_{(i-1)\bmod \vert S\vert+1}= \texttt{T}$, the students will act honestly during the $i$-th query, otherwise they will act dishonestly. You must also ensure that there is no index $i$ such that $S_{(i-1)\bmod \vert S\vert+1} = S_{i\bmod \vert S\vert+1} = S_{(i+1)\bmod \vert S\vert+1}$.

## Example

Input
```

2
5

3

2

1

2

0

1

0

2

0

1

6

6

2

2

0

1

1

0

0

0

1


```
Output
```



? 1 4

? 3 5

? 2 2

? 1 3

? 3 3

? 3 3

! 3

? 2 4

? 4 4

! 2

#

? 1 6

? 1 3

? 4 6

? 1 1

? 3 3

? 5 5

! 3

? 2 2

? 4 4

! 4

#

```
## Note

For the first test case, the student with roll number $2$ is absent and the truth sequence (see section for hacks) is TFFTFTTF. During execution of your solution, this test case will use a non-adaptive grader.

For the second test case, the student with roll number $4$ is absent, and the truth sequence is FFTFTTFT. During the execution of your solution, in this test case your program will interact with an adaptive grader. So, the actual answer might be different depending on your queries but will always remain consistent with the responses to the previous queries.



#### tags 

#3500 #constructive_algorithms #dp #interactive #ternary_search 