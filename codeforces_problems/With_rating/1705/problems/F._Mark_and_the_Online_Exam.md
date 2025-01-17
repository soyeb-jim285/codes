<h1 style='text-align: center;'> F. Mark and the Online Exam</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Mark is administering an online exam consisting of $n$ true-false questions. However, he has lost all answer keys. He needs a way to retrieve the answers before his client gets infuriated.

Fortunately, he has access to the grading system. Thus, for each query, you can input the answers to all $n$ questions, and the grading system will output how many of them are correct.

He doesn't have much time, so he can use the grading system at most $675$ times. Help Mark determine the answer keys.

## Note

 that answer keys are fixed in advance and will not change depending on your queries.

#### Input

The first line of the input consists of an integer $n$ ($1\leq n\leq 1000$) — the number of questions.

## Interaction

After reading $n$, you can start making queries to the grading system. For each query, print a line containing a string $s$ of length $n$ consisting of only letters 'T' and 'F'. 

* $s_i = $'T' means that you answer the $i$-question true.
* $s_i = $'F' means that you answer the $i$-question false.

After a successful query, you should read an integer $k$ ($0\leq k\leq n$) — the number of correct answers. If you read $n$, then you found the answers, and your program should not make any more queries.

If your program reads $k = -1$ instead of the number of correct answers, it means that you either made an invalid query or exceeded the query limits. Exit immediately after receiving $-1$, and you will see Wrong answer verdict. Otherwise, you can get an arbitrary verdict because your solution will continue to read from a closed stream.

After printing a query do not forget to output end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use: 

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

Hacks

To hack, use the following format:

The first line contains an integer $n$ ($1\leq n\leq 1000$) — the number of questions.

The second line contains a string $s$ of length $n$ consisting of only 'T' and 'F' — the answer key.

## Examples

#### Input


```text
3

1

3
```
##Output
```text


FTT

TTF
```
#### Input


```text
4

0

3

4
```
##Output
```text

FTFF

TTTT

TFTT
```
## Note

The empty lines in the example are just for you to better understand the interaction process. You're not required to print them.

In the first example, there are $3$ questions, and the answer to each question is 'true', 'true', and 'false', respectively. 

* The first query, guessing the answers to be 'false', 'true', and 'true', respectively, guesses only one question — the $2$-nd question — correctly.
* Then, in the second query, the program correctly guesses the answer key. The interaction ends here.

In the second example, there are $4$ questions, and the answer to each question is 'true', 'false', 'true', and 'true', respectively. 

* The first query guessed none of the questions correctly, resulting in the answer $0$.
* The second query guessed the $1$-st, $3$-rd, and $4$-th question correctly, resulting in the answer $3$.
* In the third query, the program correctly guesses the answer key. Then, the interaction ends.


#### Tags 

#2900 #NOT OK #bitmasks #constructive_algorithms #interactive #probabilities 

## Blogs
- [All Contest Problems](../Codeforces_Round_807_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
