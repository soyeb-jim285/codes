<h1 style='text-align: center;'> D. Guess the Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

Jury initially had a sequence $a$ of length $n$, such that $a_i = i$.

The jury chose three integers $i$, $j$, $k$, such that $1 \leq i < j < k \leq n$, $j - i > 1$. After that, Jury reversed subsegments $[i, j - 1]$ and $[j, k]$ of the sequence $a$.

Reversing a subsegment $[l, r]$ of the sequence $a$ means reversing the order of elements $a_l, a_{l+1}, \ldots, a_r$ in the sequence, i. e. $a_l$ is swapped with $a_r$, $a_{l+1}$ is swapped with $a_{r-1}$, etc.

You are given the number $n$ and you should find $i$, $j$, $k$ after asking some questions.

In one question you can choose two integers $l$ and $r$ ($1 \leq l \leq r \leq n$) and ask the number of inversions on the subsegment $[l, r]$ of the sequence $a$. You will be given the number of pairs $(i, j)$ such that $l \leq i < j \leq r$, and $a_i > a_j$.

Find the chosen numbers $i$, $j$, $k$ after at most $40$ questions.

The numbers $i$, $j$, and $k$ are fixed before the start of your program and do not depend on your queries.

### Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 100$) — the number of test cases. Description of the test cases follows.

The single line of each test case contains a single integer $n$ ($4 \leq n \leq 10^9$). After reading it you should start an interaction process by asking questions for that test case. After giving an answer you should:

* Terminate your program if that is the last test case.
* Proceed to the next test case otherwise.
## Interaction

To ask number of inversions on a subsegment $[l, r]$, print "? l r", where ($1 \leq l \leq r \leq n$). You can ask at most $40$ questions in each test case. As a result you should read a single integer $x$.

* If $x = -1$, your program made an invalid question or you exceeded the number of questions for that test case. Your program should terminate immediately (otherwise it can get any verdict instead of "Wrong Answer").
* Otherwise $x$ is equal to the number of inversions on the subsegment $[l, r]$ of the sequence $a$.

To give the answer, print "! i j k", where $i$, $j$, $k$ are the numbers you found. You should continue solving the next test cases or terminate the program after that.

After printing a question or an answer do not forget to print the end of line and flush the output. Otherwise, you will get an "Idleness limit exceeded" verdict. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* See the documentation for other languages.

Hacks

To make a hack, use the following format:

The first line contains a single integer $t$ ($1 \leq t \leq 100$) — the number of test cases.

Each of the next $t$ lines contains four integers $n$, $i$, $j$, $k$ ($4 \leq n \leq 10^9$, $1 \leq i < j < k \leq n$, $j - i > 1$).

## Example

### Input


```text

2 
5 

4 

3 

3 

5 

2 

2 

1 
```
#Output
```text



? 1 5

? 2 5

? 3 5

! 1 3 5

? 1 5

? 2 5

? 3 5

! 2 4 5
```
## Note

In the first test case, $i = 1$, $j = 3$, $k = 5$, so the sequence $a$ is $[2, 1, 5, 4, 3]$.

In the second test case, $i = 2$, $j = 4$, $k = 5$, so the sequence $a$ is $[1, 3, 2, 5, 4]$.



#### Tags 

#2000 #NOT OK #binary_search #combinatorics #interactive #math 

## Blogs
- [All Contest Problems](../Technocup_2022_-_Elimination_Round_2.md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
