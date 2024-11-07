<h1 style='text-align: center;'> D. Row Major</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The row-major order of an $r \times c$ grid of characters $A$ is the string obtained by concatenating all the rows, i.e. $$ A_{11}A_{12} \dots A_{1c}A_{21}A_{22} \dots A_{2c} \dots A_{r1}A_{r2} \dots A_{rc}. $$

A grid of characters $A$ is bad if there are some two adjacent cells (cells sharing an edge) with the same character.

You are given a positive integer $n$. Consider all strings $s$ consisting of only lowercase Latin letters such that they are not the row-major order of any bad grid. Find any string with the minimum number of distinct characters among all such strings of length $n$.

It can be proven that at least one such string exists under the constraints of the problem.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The only line of each test case contains a single integer $n$ ($1 \le n \le 10^6$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^6$.

### Output

For each test case, output a string with the minimum number of distinct characters among all suitable strings of length $n$.

If there are multiple solutions, print any of them.

## Example

### Input


```text
44216
```
### Output

```text

that
is
a
tomato

```
## Note

In the first test case, there are $3$ ways $s$ can be the row-major order of a grid, and they are all not bad: 

| t |  | t | h |  | t | h | a | t |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| h |  | a | t |  |  |  |  |  |
| a |  |  |  |  |  |  |  |  |
| t |  |  |  |  |  |  |  |  |

 It can be proven that $3$ distinct characters is the minimum possible.

In the second test case, there are $2$ ways $s$ can be the row-major order of a grid, and they are both not bad: 

| i |  | i | s |
| --- | --- | --- | --- |
| s |  |  |  |

 It can be proven that $2$ distinct characters is the minimum possible.

In the third test case, there is only $1$ way $s$ can be the row-major order of a grid, and it is not bad.

In the fourth test case, there are $4$ ways $s$ can be the row-major order of a grid, and they are all not bad: 

| t |  | t | o |  | t | o | m |  | t | o | m | a | t | o |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| o |  | m | a |  | a | t | o |  |  |  |  |  |  |  |
| m |  | t | o |  |  |  |  |  |  |  |  |  |  |  |
| a |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| t |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
| o |  |  |  |  |  |  |  |  |  |  |  |  |  |  |

 It can be proven that $4$ distinct characters is the minimum possible. 
## Note

 that, for example, the string "orange" is not an acceptable output because it has $6 > 4$ distinct characters, and the string "banana" is not an acceptable output because it is the row-major order of the following bad grid: 

| b | a |
| --- | --- |
| n | a |
| n | a |





#### Tags 

#1400 #OK #constructive_algorithms #greedy #math #number_theory #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_884_(Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
