<h1 style='text-align: center;'> D. Fixed Point Guessing</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

Initially, there is an array $a = [1, 2, \ldots, n]$, where $n$ is an odd positive integer. The jury has selected $\frac{n-1}{2}$ disjoint pairs of elements, and then the elements in those pairs are swapped. For example, if $a=[1,2,3,4,5]$, and the pairs $1 \leftrightarrow 4$ and $3 \leftrightarrow 5$ are swapped, then the resulting array is $[4, 2, 5, 1, 3]$. 

As a result of these swaps, exactly one element will not change position. You need to find this element.

To do this, you can ask several queries. In each query, you can pick two integers $l$ and $r$ ($1 \leq l \leq r \leq n$). In return, you will be given the elements of the subarray $[a_l, a_{l + 1}, \dots, a_r]$ sorted in increasing order. 

Find the element which did not change position. You can make at most $\mathbf{15}$ queries.

The array $a$ is fixed before the interaction and does not change after your queries.

Recall that an array $b$ is a subarray of the array $a$ if $b$ can be obtained from $a$ by deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end.

### Input

Each test contains multiple test cases. The first line contains an integer $t$ ($1 \leq t \leq 500$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer $n$ ($3 \leq n < 10^4$; $n$ is odd) — the length of the array $a$.

After reading the first line of each test case, you should begin the interaction.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^4$.

## Interaction

For each test case, begin the interaction by reading the integer $n$.

To make a query, output "$\texttt{?}\;l\;r$" ($1 \leq l \leq r \leq n$) without quotes. Afterwards, you should read in $r-l+1$ integers — the integers $a_l, a_{l + 1}, \dots, a_r$, in increasing order. You can make at most $15$ such queries in a single test case.

If you receive the integer $-1$ instead of an answer or the integer $n$, it means your program has made an invalid query, has exceed the limit of queries, or has given incorrect answer on the previous test case. Your program must terminate immediately to receive a Wrong Answer verdict. Otherwise you can get an arbitrary verdict because your solution will continue to read from a closed stream.

When you are ready to give the final answer, output "$\texttt{!}\;x$" ($1 \leq x \leq n$) without quotes — the element that did not change position. Giving this answer does not count towards the limit of $15$ queries. Afterwards, your program must continue to solve the remaining test cases, or exit if all test cases have been solved.

After printing a query do not forget to output end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

Hacks

To make a hack, use the following format. The first line must contain an integer $t$ ($1 \leq t \leq 500$) — the number of test cases. The description of the test cases follows.

The first line of each test case must contain an integer $n$ ($3 \leq n < 10^4$; $n$ is odd) — the length of the array $a$.

The second line of each test case must contain $n$ space-separated integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le n$) — the elements of $a$. The array $a$ should be the result of $\frac{n-1}{2}$ disjoint swaps on the array $[1,2,\dots,n]$.

## Example

### Input


```text
2
5

1 2 4 5

1 3 5

3

1
```
#Output
```text



? 1 4

? 3 5

! 2

? 1 1

! 1
```
## Note

In the first test, the interaction proceeds as follows.

 

| Solution | Jury | Explanation |
| --- | --- | --- |
|  | $\texttt{2}$ | There are 2 test cases. |
|  | $\texttt{5}$ | In the first test case, the hidden array is $[4,2,5,1,3]$, with length $5$. |
| $\texttt{? 1 4}$ | $\texttt{1 2 4 5}$ | The solution requests the subarray $[4,2,5,1]$ in increasing order, and the jury responds with $[1,2,4,5]$. |
| $\texttt{? 3 5}$ | $\texttt{1 3 5}$ | The solution requests the subarray $[5,1,3]$ in increasing order, and the jury responds with $[1,3,5]$. |
| $\texttt{! 2}$ |  | The solution has somehow determined that $a_2=2$, and outputs it. Since the output is correct, the jury continues to the next test case. |
|  | $\texttt{3}$ | In the second test case, the hidden array is $[1,3,2]$, with length $3$. |
| $\texttt{? 1 1}$ | $\texttt{1}$ | The solution requests the number $[1]$ only, and the jury responds with $[1]$. |
| $\texttt{! 1}$ |  | The solution has determined that $a_1=1$, and outputs it. Since the output is correct and there are no more test cases, the jury and the solution exit. |

 
## Note

 that the line breaks in the example input and output are for the sake of clarity, and do not occur in the real interaction.



#### Tags 

#1600 #NOT OK #binary_search #constructive_algorithms #interactive 

## Blogs
- [All Contest Problems](../Codeforces_Round_803_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
