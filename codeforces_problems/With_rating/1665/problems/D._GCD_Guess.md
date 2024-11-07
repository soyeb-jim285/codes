<h1 style='text-align: center;'> D. GCD Guess</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

There is a positive integer $1 \le x \le 10^9$ that you have to guess.

In one query you can choose two positive integers $a \neq b$. As an answer to this query you will get $\gcd(x + a, x + b)$, where $\gcd(n, m)$ is the [greatest common divisor](https://en.wikipedia.org/wiki/Greatest common divisor) of the numbers $n$ and $m$.

To guess one hidden number $x$ you are allowed to make no more than $30$ queries.

### Input

The first line of input contains a single integer $t$ ($1 \le t \le 1000$) denoting the number of test cases.

The integer $x$ that you have to guess satisfies the constraints: ($1 \le x \le 10^9$).

## Interaction

The hidden number $x$ is fixed before the start of the interaction and does not depend on your queries.

To guess each $x$ you can make no more than $30$ queries in the following way:

* "? a b" ($1 \le a, b \le 2 \cdot 10^9$, $a \neq b$).

For this query you will get $\gcd(x + a, x + b)$.

When you know $x$, print a single line in the following format.

* "! x" ($1 \le x \le 10^9$).

After that continue to solve the next test case.

If you ask more than $30$ queries for one $x$ or make an invalid query, the interactor will terminate immediately and your program will receive verdict Wrong Answer.

After printing each query do not forget to output end of line and flush the output buffer. Otherwise, you will get the Idleness limit exceeded verdict. To do flush use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* Read documentation for other languages.

Hacks

To use hacks, use the following format of tests:

The first line should contain a single integer $t$ ($1 \le t \le 1000$) — the number of test cases.

The first and only line of each test case should contain a single integer $x$ ($1 \le x \le 10^9$) denoting the integer $x$ that should be guessed.

## Example

### Input


```text
2

1

8


1
```
#Output
```text

? 1 2

? 12 4

! 4
? 2000000000 1999999999

! 1000000000
```
## Note

The first hidden number is $4$, that's why the answers for the queries are:

"? 1 2" — $\gcd(4 + 1, 4 + 2) = \gcd(5, 6) = 1$.

"? 12 4" — $\gcd(4 + 12, 4 + 4) = \gcd(16, 8) = 8$.

The second hidden number is $10^9$, that's why the answer for the query is:

"? 2000000000 1999999999" — $\gcd(3 \cdot 10^9, 3 \cdot 10^9 - 1) = 1$.

These queries are made only for understanding the interaction and are not enough for finding the true $x$.



#### Tags 

#2000 #OK #bitmasks #chinese_remainder_theorem #constructive_algorithms #games #interactive #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_781_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial](../blogs/Tutorial.md)
