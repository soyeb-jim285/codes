<h1 style='text-align: center;'> C. Swap Game</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice and Bob are playing a game on an array $a$ of $n$ positive integers. Alice and Bob make alternating moves with Alice going first.

In his/her turn, the player makes the following move:

* If $a_1 = 0$, the player loses the game, otherwise:
* Player chooses some $i$ with $2\le i \le n$. Then player decreases the value of $a_1$ by $1$ and swaps $a_1$ with $a_i$.

Determine the winner of the game if both players play optimally.

## Input

The input consists of multiple test cases. The first line contains a single integer $t$ $(1 \leq t \leq 2 \cdot 10^4)$  — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ $(2 \leq n \leq 10^5)$  — the length of the array $a$.

The second line of each test case contains $n$ integers $a_1,a_2 \ldots a_n$ $(1 \leq a_i \leq 10^9)$  — the elements of the array $a$.

It is guaranteed that sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, if Alice will win the game, output "Alice". Otherwise, output "Bob".

You can output each letter in any case. For example, "alIcE", "Alice", "alice" will all be considered identical.

## Example

## Input


```

321 122 135 4 4
```
## Output


```

Bob
Alice
Alice

```
## Note

In the first testcase, in her turn, Alice can only choose $i = 2$, making the array equal $[1, 0]$. Then Bob, in his turn, will also choose $i = 2$ and make the array equal $[0, 0]$. As $a_1 = 0$, Alice loses.

In the second testcase, once again, players can only choose $i = 2$. Then the array will change as follows: $[2, 1] \to [1, 1] \to [1, 0] \to [0, 0]$, and Bob loses.

In the third testcase, we can show that Alice has a winning strategy.



#### tags 

#1200 #games 