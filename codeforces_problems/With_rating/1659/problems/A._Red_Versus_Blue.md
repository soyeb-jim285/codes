<h1 style='text-align: center;'> A. Red Versus Blue</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Team Red and Team Blue competed in a competitive FPS. Their match was streamed around the world. They played a series of $n$ matches.

In the end, it turned out Team Red won $r$ times and Team Blue won $b$ times. Team Blue was less skilled than Team Red, so $b$ was strictly less than $r$.

You missed the stream since you overslept, but you think that the match must have been neck and neck since so many people watched it. So you imagine a string of length $n$ where the $i$-th character denotes who won the $i$-th match  — it is R if Team Red won or B if Team Blue won. You imagine the string was such that the maximum number of times a team won in a row was as small as possible. For example, in the series of matches RBBRRRB, Team Red won $3$ times in a row, which is the maximum.

You must find a string satisfying the above conditions. If there are multiple answers, print any.

#### Input

The first line contains a single integer $t$ ($1 \le t \le 1000$)  — the number of test cases.

Each test case has a single line containing three integers $n$, $r$, and $b$ ($3 \leq n \leq 100$; $1 \leq b < r \leq n$, $r+b=n$).

#### Output

For each test case, output a single line containing a string satisfying the given conditions. If there are multiple answers, print any.

## Examples

#### Input


```text
37 4 36 5 119 13 6
```
#### Output

```text

RBRBRBR
RRRBRR
RRBRRBRRBRRBRRBRRBR

```
#### Input


```text
63 2 110 6 411 6 510 9 110 8 211 9 2
```
#### Output

```text

RBR
RRBRBRBRBR
RBRBRBRBRBR
RRRRRBRRRR
RRRBRRRBRR
RRRBRRRBRRR

```
## Note

The first test case of the first example gives the optimal answer for the example in the statement. The maximum number of times a team wins in a row in RBRBRBR is $1$. We cannot minimize it any further.

The answer for the second test case of the second example is RRBRBRBRBR. The maximum number of times a team wins in a row is $2$, given by RR at the beginning. We cannot minimize the answer any further.



#### Tags 

#1000 #OK #constructive_algorithms #greedy #implementation #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_782_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
