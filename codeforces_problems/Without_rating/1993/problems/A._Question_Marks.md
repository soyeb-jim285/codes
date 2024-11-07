<h1 style='text-align: center;'> A. Question Marks</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Tim is doing a test consisting of $4n$ questions; each question has $4$ options: 'A', 'B', 'C', and 'D'. For each option, there are exactly $n$ correct answers corresponding to that option — meaning there are $n$ questions with the answer 'A', $n$ questions with the answer 'B', $n$ questions with the answer 'C', and $n$ questions with the answer 'D'.

For each question, Tim wrote his answer on the answer sheet. If he could not figure out the answer, he would leave a question mark '?' for that question.

You are given his answer sheet of $4n$ characters. What is the maximum number of correct answers Tim can get?

### Input

The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases.

The first line of each test case contains an integer $n$ ($1 \le n \le 100$).

The second line of each test case contains a string $s$ of $4n$ characters ($s_i \in \{\texttt{A}, \texttt{B}, \texttt{C}, \texttt{D}, \texttt{?}\}$) — Tim's answers for the questions.

### Output

For each test case, print a single integer — the maximum score that Tim can achieve.

## Example

### Input


```text
61ABCD2AAAAAAAA2AAAABBBB2????????3ABCABCABCABC5ACADC??ACAC?DCAABC?C
```
### Output

```text

4
2
4
0
9
13

```
## Note

In the first test case, there is exactly one question with each answer 'A', 'B', 'C', and 'D'; so it's possible that Tim gets all his answers correct.

In the second test case, there are only two correct answers 'A' which makes him get exactly $2$ points in any case.

In the third test case, Tim can get at most $2$ correct answers with option 'A' and $2$ correct answers with option 'B'. For example, he would get $4$ points if the answers were 'AACCBBDD'.

In the fourth test case, he refuses to answer any question at all, which makes him get $0$ points.



#### Tags 

#OK #greedy #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_963_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
