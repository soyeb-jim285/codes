<h1 style='text-align: center;'> A. Satisfying Constraints</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alex is solving a problem. He has $n$ constraints on what the integer $k$ can be. There are three types of constraints:

1. $k$ must be greater than or equal to some integer $x$;
2. $k$ must be less than or equal to some integer $x$;
3. $k$ must be not equal to some integer $x$.

Help Alex find the number of integers $k$ that satisfy all $n$ constraints. It is guaranteed that the answer is finite (there exists at least one constraint of type $1$ and at least one constraint of type $2$). Also, it is guaranteed that no two constraints are the exact same.

### Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 500$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($2 \leq n \leq 100$) — the number of constraints.

The following $n$ lines describe the constraints. Each line contains two integers $a$ and $x$ ($a \in \{1,2,3\}, \, 1 \leq x \leq 10^9$). $a$ denotes the type of constraint. If $a=1$, $k$ must be greater than or equal to $x$. If $a=2$, $k$ must be less than or equal to $x$. If $a=3$, $k$ must be not equal to $x$.

It is guaranteed that there is a finite amount of integers satisfying all $n$ constraints (there exists at least one constraint of type $1$ and at least one constraint of type $2$). It is also guaranteed that no two constraints are the exact same (in other words, all pairs $(a, x)$ are distinct).

### Output

For each test case, output a single integer — the number of integers $k$ that satisfy all $n$ constraints.

## Example

### Input


```text
641 32 103 13 521 52 4103 63 71 21 73 1003 442 1002 981 33 9961 52 101 92 23 23 951 12 23 13 23 361 100002 9000000003 5000000001 1000000003 100003 900000001
```
### Output

```text

7
0
90
0
0
800000000

```
## Note

In the first test case, $k \geq 3$ and $k \leq 10$. Furthermore, $k \neq 1$ and $k \neq 5$. The possible integers $k$ that satisfy the constraints are $3,4,6,7,8,9,10$. So the answer is $7$.

In the second test case, $k \ge 5$ and $k \le 4$, which is impossible. So the answer is $0$.



#### Tags 

#800 #OK #brute_force #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_919_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
