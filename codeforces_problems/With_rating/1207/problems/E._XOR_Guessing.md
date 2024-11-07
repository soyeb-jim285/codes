<h1 style='text-align: center;'> E. XOR Guessing</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem. Remember to flush your output while communicating with the testing program. You may use fflush(stdout) in C++, system.out.flush() in Java, stdout.flush() in Python or flush(output) in Pascal to flush the output. If you use some other programming language, consult its documentation. You may also refer to the guide on interactive problems: <https://codeforces.com/blog/entry/45307>.

The jury picked an integer $x$ not less than $0$ and not greater than $2^{14} - 1$. You have to guess this integer.

To do so, you may ask no more than $2$ queries. Each query should consist of $100$ integer numbers $a_1$, $a_2$, ..., $a_{100}$ (each integer should be not less than $0$ and not greater than $2^{14} - 1$). In response to your query, the jury will pick one integer $i$ ($1 \le i \le 100$) and tell you the value of $a_i \oplus x$ (the bitwise XOR of $a_i$ and $x$). There is an additional constraint on the queries: all $200$ integers you use in the queries should be distinct.

It is guaranteed that the value of $x$ is fixed beforehand in each test, but the choice of $i$ in every query may depend on the integers you send.

### Output

To give the answer, your program should print one line $!$ $x$ with a line break in the end. After that, it should flush the output and terminate gracefully.

## Interaction

Before giving the answer, you may submit no more than $2$ queries. To ask a query, print one line in the following format: $?$ $a_1$ $a_2$ ... $a_{100}$, where every $a_j$ should be an integer from the range $[0, 2^{14} - 1]$. The line should be ended with a line break character. After submitting a query, flush the output and read the answer to your query — the value of $a_i \oplus x$ for some $i \in [1, 100]$. No integer can be used in queries more than once.

If you submit an incorrect query (or ask more than $2$ queries), the answer to it will be one integer $-1$. After receiving such an answer, your program should terminate immediately — otherwise you may receive verdict "Runtime error", "Time limit exceeded" or some other verdict instead of "Wrong answer".

## Example

#Input
```text
0
32
```
### Output

```text

? 3 5 6
? 32 24 37
! 5
```
## Note

The example of interaction is not correct — you should sumbit exactly $100$ integers in each query. Everything else is correct.

Hacks are forbidden in this problem.



#### Tags 

#1900 #NOT OK #bitmasks #interactive #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_71_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
