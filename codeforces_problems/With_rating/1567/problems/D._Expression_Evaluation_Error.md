<h1 style='text-align: center;'> D. Expression Evaluation Error</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

On the board, Bob wrote $n$ positive integers in [base](https://en.wikipedia.org/wiki/Positional_notation#Base_of_the_numeral_system) $10$ with sum $s$ (i. e. in decimal numeral system). Alice sees the board, but accidentally interprets the numbers on the board as base-$11$ integers and adds them up (in base $11$).

What numbers should Bob write on the board, so Alice's sum is as large as possible?

### Input

The input consists of multiple test cases. The first line contains an integer $t$ ($1 \leq t \leq 100$) — the number of test cases. The description of the test cases follows.

The only line of each test case contains two integers $s$ and $n$ ($1 \leq s \leq 10^9$; $1 \leq n \leq \min(100, s)$) — the sum and amount of numbers on the board, respectively. Numbers $s$ and $n$ are given in decimal notation (base $10$).

### Output

For each test case, output $n$ positive integers — the numbers Bob should write on the board, so Alice's sum is as large as possible. If there are multiple answers, print any of them.

## Example

### Input


```text
6
97 2
17 1
111 4
100 2
10 9
999999 3
```
### Output


```text
70 27 
17 
3 4 100 4
10 90
1 1 2 1 1 1 1 1 1 
999900 90 9
```
## Note

In the first test case, $70_{10} + 27_{10} = 97_{10}$, and Alice's sum is $$70_{11} + 27_{11} = 97_{11} = 9 \cdot 11 + 7 = 106_{10}.$$ (Here $x_b$ represents the number $x$ in base $b$.) It can be shown that it is impossible for Alice to get a larger sum than $106_{10}$.

In the second test case, Bob can only write a single number on the board, so he must write $17$.

In the third test case, $3_{10} + 4_{10} + 100_{10} + 4_{10} = 111_{10}$, and Alice's sum is $$3_{11} + 4_{11} + 100_{11} + 4_{11} = 110_{11} = 1 \cdot 11^2 + 1 \cdot 11 = 132_{10}.$$ It can be shown that it is impossible for Alice to get a larger sum than $132_{10}$.



#### Tags 

#2000 #NOT OK #constructive_algorithms #greedy #implementation #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_742_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
