<h1 style='text-align: center;'> A. Wallet Exchange</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice and Bob are bored, so they decide to play a game with their wallets. Alice has $a$ coins in her wallet, while Bob has $b$ coins in his wallet.

Both players take turns playing, with Alice making the first move. In each turn, the player will perform the following steps in order:

1. Choose to exchange wallets with their opponent, or to keep their current wallets.
2. Remove $1$ coin from the player's current wallet. The current wallet cannot have $0$ coins before performing this step.

The player who cannot make a valid move on their turn loses. If both Alice and Bob play optimally, determine who will win the game.

### Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 1000$) — the number of test cases. The description of the test cases follows.

The first and only line of each test case contains two integers $a$ and $b$ ($1 \le a, b \le 10^9$) — the number of coins in Alice's and Bob's wallets, respectively.

### Output

For each test case, output "Alice" if Alice will win the game, and "Bob" if Bob will win the game.

## Example

### Input


```text
101 11 45 34 511 983 911032 9307839204 72811000000000 100000000053110 2024
```
### Output

```text

Bob
Alice
Bob
Alice
Bob
Bob
Alice
Alice
Bob
Bob

```
## Note

In the first test case, an example of the game is shown below:

* Alice chooses to not swap wallets with Bob in step 1 of her move. Now, $a=0$ and $b=1$.
* Since Alice's wallet is empty, Bob must choose to not swap their wallets in step 1 of his move. Now, $a=0$ and $b=0$.
* Since both Alice's and Bob's wallets are empty, Alice is unable to make a move. Hence, Bob wins.

In the second test case, an example of the game is shown below:

* Alice chooses to swap wallets with Bob in step 1 of her move. Now, $a=3$ and $b=1$.
* Bob chooses to swap wallets with Alice in step 1 of his move. Now, $a=1$ and $b=2$.
* Alice chooses to not swap wallets with Bob in step 1 of her move. Now, $a=0$ and $b=2$.
* Since Alice's wallet is empty, Bob can only choose to not swap wallets with Alice in step 1 of his move. Now, $a=0$ and $b=1$.
* Since Alice's wallet is empty, Alice can only choose to swap wallets with Bob in step 1 of her move. Now, $a=0$ and $b=0$.
* Since both Alice's wallet and Bob's wallet are empty, Bob is unable to make a move. Hence, Alice wins.


#### Tags 

#800 #NOT OK #games #math 

## Blogs
- [All Contest Problems](../Hello_2024.md)
- [Hello 2024 (en)](../blogs/Hello_2024_(en).md)
- [Editorial for Hello 2024 (en)](../blogs/Editorial_for_Hello_2024_(en).md)
