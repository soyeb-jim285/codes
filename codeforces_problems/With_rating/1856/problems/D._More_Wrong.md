<h1 style='text-align: center;'> D. More Wrong</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

The jury has hidden a permutation$^\dagger$ $p$ of length $n$.

In one query, you can pick two integers $l$ and $r$ ($1 \le l < r \le n$) by paying $(r - l)^2$ coins. In return, you will be given the number of inversions$^\ddagger$ in the subarray $[p_l, p_{l + 1}, \ldots p_r]$.

Find the index of the maximum element in $p$ by spending at most $5 \cdot n^2$ coins.

## Note

: the grader is not adaptive: the permutation is fixed before any queries are made.

$^\dagger$ A permutation of length $n$ is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array), and $[1,3,4]$ is also not a permutation ($n=3$ but there is $4$ in the array).

$^\ddagger$ The number of inversions in an array is the number of pairs of indices $(i,j)$ such that $i < j$ and $a_i > a_j$. For example, the array $[10,2,6,3]$ contains $4$ inversions. The inversions are $(1,2),(1,3),(1,4)$, and $(3,4)$.

### Input

Each test contains multiple test cases. The first line of input contains a single integer $t$ ($1 \le t \le 100$) — the number of test cases.

The only line of each test case contains a single integer $n$ ($2 \le n \le 2000$) — the length of the hidden permutation $p$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2000$.

## Interaction

The interaction for each test case begins by reading the integer $n$.

To make a query, output "? l r" ($1 \le l < r \le n$) without quotes. Afterwards, you should read one single integer — the answer for your query.

If you receive the integer $-1$ instead of an answer or a valid value of $n$, it means your program has made an invalid query, has exceed the limit of queries, or has given an incorrect answer on the previous test case. Your program must terminate immediately to receive a Wrong Answer verdict. Otherwise you can get an arbitrary verdict because your solution will continue to read from a closed stream.

When you are ready to give the final answer, output "! i" ($1 \le i \le n$) without quotes — the index of the maximum of the hidden permutation. After solving a test case, your program should move to the next one immediately. After solving all test cases, your program should be terminated immediately.

After printing a query do not forget to output end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use: 

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

Hacks

To hack, use the following format:

The first line contains an integer $t$ ($1 \le t \le 100$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($2 \le n \le 2000$) — the length of the hidden permutation $p$.

The second line of each test case contains $n$ integers $p_1,p_2,\ldots, p_n$ ($1 \le p_i \le n$), $p$ must be a permutation.

The sum of $n$ over all test cases should not exceed $2000$.

## Example

### Input


```text

2
4

1

0

2

1
```
#Output
```text


? 1 3

? 3 4

! 4

? 1 2

! 1
```
## Note

In the first test, the interaction proceeds as follows:



| Solution | Jury | Explanation |
| --- | --- | --- |
|  | 2 | There are $2$ test cases. |
|  | 4 | In the first test case, the hidden permutation is $[1,3,2,4]$, with length $4$. |
| ? 1 3 | 1 | The solution requests the number of inversions in the subarray $[1,3,2]$ by paying $4$ coins, and the jury responds with $1$. |
| ? 3 4 | 0 | The solution requests the number of inversions in the subarray $[2,4]$ by paying $1$ coin, and the jury responds with $0$. |
| ! 4 |  | The solution has somehow determined that $p_4 = 4$, and outputs it. Since the output is correct, the jury continues to the next test case. |
|  | 2 | In the second test case, the hidden permutation is $[2,1]$, with length $2$. |
| ? 1 2 | 1 | The solution requests the number of inversions in the subarray $[2,1]$ by paying $1$ coin, and the jury responds with $1$. |
| ! 1 |  | The solution has somehow determined that $p_1 = 2$, and outputs it. Since the output is correct and there are no more test cases, the jury and the solution exit. |



## Note

 that the line breaks in the example input and output are for the sake of clarity, and do not occur in the real interaction.



#### Tags 

#2100 #OK #divide_and_conquer #interactive 

## Blogs
- [All Contest Problems](../Codeforces_Round_890_(Div._2)_supported_by_Constructor_Institute.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
