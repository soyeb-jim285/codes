<h1 style='text-align: center;'> A. Soccer</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Dima loves watching soccer. In such a game, the score on the scoreboard is represented as $x$ : $y$, where $x$ is the number of goals of the first team, and $y$ is the number of goals of the second team. At any given time, only one team can score a goal, so the score $x$ : $y$ can change to either $(x + 1)$ : $y$, or $x$ : $(y + 1)$.

While watching a soccer game, Dima was distracted by very important matters, and after some time, he returned to watching the game. Dima remembers the score right before he was distracted, and the score right after he returned. Given these two scores, he wonders the following question. Is it possible that, while Dima was not watching the game, the teams never had an equal score?

It is guaranteed that at neither of the two time points Dima remembers the teams had equal scores. However, it is possible that the score did not change during his absence.

Help Dima and answer the question!

### Input

Each test consists of several test cases. The first line contains an integer $t$ ($1 \le t \le 10^{4}$) — the number of test cases. Then follows the description of the test cases.

The first line of each test case contains two integers $x_{1}, y_{1}$ ($0 \le x_{1}, y_{1} \le 10^{9}$, $x_{1} \neq y_{1}$) — the score before Dima was distracted.

The second line of each test case contains two integers $x_{2}, y_{2}$ ($x_{1} \le x_{2} \le 10^{9}$, $y_{1} \le y_{2} \le 10^{9}$, $x_{2} \neq y_{2}$) — the score when Dima returned.

### Output

For each test case, output "YES" without quotes if it is possible, that the teams never had a tie while Dima was away, otherwise output "NO" without quotes.

You can output each letter in any case (for example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as a positive answer).

## Example

### Input


```text
61 05 01 23 21 24 51 24 31 21 2998244353 01000000000 999999999
```
### Output

```text

YES
NO
YES
NO
YES
YES

```
## Note

In the first test case, the score before Dima left was $1$ : $0$. When he leaves, the first team scores several goals in a row until the score becomes $5$ : $0$, so the answer is YES.

In the second test case, the score could only change as follows:

* $1$ : $2$
* $2$ : $2$
* $3$ : $2$

In this scenario, there is a moment when the teams have an equal score, so the answer is NO.

In the third test case, one of the possible developments is:

* $1$ : $2$
* $1$ : $3$
* $2$ : $3$
* $2$ : $4$
* $2$ : $5$
* $3$ : $5$
* $4$ : $5$

In this scenario, there was no time when the score was equal, so the answer is YES.



#### Tags 

#800 #NOT OK #greedy #implementation #math #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_955_(Div._2,_with_prizes_from_NEAR!).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial](../blogs/Tutorial.md)
