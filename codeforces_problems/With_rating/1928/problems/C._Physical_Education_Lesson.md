<h1 style='text-align: center;'> C. Physical Education Lesson</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In a well-known school, a physical education lesson took place. As usual, everyone was lined up and asked to settle in "the first–$k$-th" position.

As is known, settling in "the first–$k$-th" position occurs as follows: the first $k$ people have numbers $1, 2, 3, \ldots, k$, the next $k - 2$ people have numbers $k - 1, k - 2, \ldots, 2$, the next $k$ people have numbers $1, 2, 3, \ldots, k$, and so on. Thus, the settling repeats every $2k - 2$ positions. 
## Example

s of settling are given in the "
## Note

" section.

The boy Vasya constantly forgets everything. For example, he forgot the number $k$ described above. But he remembers the position he occupied in the line, as well as the number he received during the settling. Help Vasya understand how many natural numbers $k$ fit under the given constraints.

## Note

 that the settling exists if and only if $k > 1$. In particular, this means that the settling does not exist for $k = 1$.

### Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 100$) — the number of test cases. This is followed by the description of the test cases.

The only line of each test case contains two integers $n$ and $x$ ($1 \le x < n \le 10^9$) — Vasya's position in the line and the number Vasya received during the settling.

### Output

For each test case, output a single integer — the number of different $k$ that fit under the given constraints.

It can be proven that under the given constraints, the answer is finite.

## Example

### Input


```text
510 23 176 4100 991000000000 500000000
```
### Output

```text

4
1
9
0
1

```
## Note

In the first test case, $k$ equals $2, 3, 5, 6$ are suitable.

An example of settling for these $k$:

 

 

| $k$ / № | $1$ | $2$ | $3$ | $4$ | $5$ | $6$ | $7$ | $8$ | $9$ | $10$ |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| $2$ | $1$ | $2$ | $1$ | $2$ | $1$ | $2$ | $1$ | $2$ | $1$ | $2$ |
| $3$ | $1$ | $2$ | $3$ | $2$ | $1$ | $2$ | $3$ | $2$ | $1$ | $2$ |
| $5$ | $1$ | $2$ | $3$ | $4$ | $5$ | $4$ | $3$ | $2$ | $1$ | $2$ |
| $6$ | $1$ | $2$ | $3$ | $4$ | $5$ | $6$ | $5$ | $4$ | $3$ | $2$ |

  In the second test case, $k = 2$ is suitable.



#### Tags 

#1600 #OK #brute_force #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_924_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
