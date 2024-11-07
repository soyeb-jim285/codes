<h1 style='text-align: center;'> C. Sasha and the Casino</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Sasha decided to give his girlfriend the best handbag, but unfortunately for Sasha, it is very expensive. Therefore, Sasha wants to earn it. After looking at earning tips on the internet, he decided to go to the casino.

Sasha knows that the casino operates under the following rules. If Sasha places a bet of $y$ coins (where $y$ is a positive integer), then in case of winning, he will receive $y \cdot k$ coins (i.e., his number of coins will increase by $y \cdot (k - 1)$). And in case of losing, he will lose the entire bet amount (i.e., his number of coins will decrease by $y$).

## Note

 that the bet amount must always be a positive ($> 0$) integer and cannot exceed Sasha's current number of coins.

Sasha also knows that there is a promotion at the casino: he cannot lose more than $x$ times in a row.

Initially, Sasha has $a$ coins. He wonders whether he can place bets such that he is guaranteed to win any number of coins. In other words, is it true that for any integer $n$, Sasha can make bets so that for any outcome that does not contradict the rules described above, at some moment of time he will have at least $n$ coins.

## Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases. The description of the test cases follows.

The single line of each test case contains three integers $k, x$ and $a$ ($2 \leq k \leq 30$, $1 \leq x \leq 100$, $1 \leq a \leq 10^9$) — the number of times the bet is increased in case of a win, the maximum number of consecutive losses, and the initial number of coins Sasha has.

## Output

For each test case, output "YES" (without quotes) if Sasha can achieve it and "NO" (without quotes) otherwise.

You can output "YES" and "NO" in any case (for example, the strings "yEs", "yes" and "Yes" will be recognized as a positive answer).

## Example

## Input


```

92 1 72 1 12 3 153 3 64 4 55 4 74 88 100000000025 69 23113 97 18806
```
## Output


```

YES
NO
YES
NO
NO
YES
NO
NO
NO

```
## Note

In the first test case, Sasha can proceed as follows:

* If Sasha places a bet for the first time or if he won the previous bet, then he places $1$ coin.
* If Sasha lost the previous bet, then he places $2$ coins.

## Note

 that Sasha cannot lose more than once in a row.

It can be proven that with this strategy, Sasha can obtain as many coins as he wants.

In the second test case, Sasha can only place $1$ coin for the first time. But in case of a loss, he will not be able to place any more bets, so he will not be able to guarantee having as many coins as he wants.



#### tags 

#1400 #binary_search #brute_force #constructive_algorithms #games #greedy #math 