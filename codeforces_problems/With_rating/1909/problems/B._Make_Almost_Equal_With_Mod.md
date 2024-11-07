<h1 style='text-align: center;'> B. Make Almost Equal With Mod</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

[xi - Solar Storm](https://soundcloud.com/yugenero/xi-solar-storm)⠀You are given an array $a_1, a_2, \dots, a_n$ of distinct positive integers. You have to do the following operation exactly once:

* choose a positive integer $k$;
* for each $i$ from $1$ to $n$, replace $a_i$ with $a_i \text{ mod } k^\dagger$.

Find a value of $k$ such that $1 \leq k \leq 10^{18}$ and the array $a_1, a_2, \dots, a_n$ contains exactly $2$ distinct values at the end of the operation. It can be shown that, under the constraints of the problem, at least one such $k$ always exists. If there are multiple solutions, you can print any of them.

$^\dagger$ $a \text{ mod } b$ denotes the remainder after dividing $a$ by $b$. For example: 

* $7 \text{ mod } 3=1$ since $7 = 3 \cdot 2 + 1$
* $15 \text{ mod } 4=3$ since $15 = 4 \cdot 3 + 3$
* $21 \text{ mod } 1=0$ since $21 = 21 \cdot 1 + 0$
### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 500$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($2 \le n \le 100$) — the length of the array $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^{17}$) — the initial state of the array. It is guaranteed that all the $a_i$ are distinct.

## Note

 that there are no constraints on the sum of $n$ over all test cases.

### Output

For each test case, output a single integer: a value of $k$ ($1 \leq k \leq 10^{18}$) such that the array $a_1, a_2, \dots, a_n$ contains exactly $2$ distinct values at the end of the operation.

## Example

### Input


```text
548 15 22 30560 90 98 120 3086328 769 541 986 215 73451000 2000 7000 11000 1600022 1
```
### Output

```text

7
30
3
5000
1000000000000000000
```
## Note

In the first test case, you can choose $k = 7$. The array becomes $[8 \text{ mod } 7, 15 \text{ mod } 7, 22 \text{ mod } 7, 30 \text{ mod } 7] = [1, 1, 1, 2]$, which contains exactly $2$ distinct values ($\{1, 2\}$).

In the second test case, you can choose $k = 30$. The array becomes $[0, 0, 8, 0, 8]$, which contains exactly $2$ distinct values ($\{0, 8\}$). 
## Note

 that choosing $k = 10$ would also be a valid solution.

In the last test case, you can choose $k = 10^{18}$. The array becomes $[2, 1]$, which contains exactly $2$ distinct values ($\{1, 2\}$). 
## Note

 that choosing $k = 10^{18} + 1$ would not be valid, because $1 \leq k \leq 10^{18}$ must be true.



#### Tags 

#1200 #OK #bitmasks #constructive_algorithms #math #number_theory 

## Blogs
- [All Contest Problems](../Pinely_Round_3_(Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
