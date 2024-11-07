<h1 style='text-align: center;'> B. Coin Games</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are $n$ coins on the table forming a circle, and each coin is either facing up or facing down. Alice and Bob take turns to play the following game, and Alice goes first.

In each operation, the player chooses a facing-up coin, removes the coin, and flips the two coins that are adjacent to it. If (before the operation) there are only two coins left, then one will be removed and the other won't be flipped (as it would be flipped twice). If (before the operation) there is only one coin left, no coins will be flipped. If (before the operation) there are no facing-up coins, the player loses.

Decide who will win the game if they both play optimally. It can be proved that the game will end in a finite number of operations, and one of them will win.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1\le t\le 100$). The description of the test cases follows.

The first line of each test case contains only one positive integer $n$ ($1 \leq n \leq 100$), representing the number of the coins.

A string $s$ of length $n$ follows on the second line of each test case, containing only "U" and "D", representing that each coin is facing up or facing down.

### Output

For each test case, print "YES" if Alice will win the game, and "NO" otherwise.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

## Example

### Input


```text
35UUDUD5UDDUD2UU
```
### Output

```text

YES
NO
NO

```
## Note

In the first test case, the game may go as follows.

* Alice chooses the first coin and $s$ becomes "DDUU".
* Bob chooses the last coin and $s$ becomes "UDD".
* Alice chooses the first coin and $s$ becomes "UU".
* Bob chooses the first coin and $s$ becomes "U".
* Alice chooses the only coin and $s$ becomes empty.
* Bob can't choose any coin now, and he loses the game.

It can be proved that Bob will always lose if they both play optimally.



#### Tags 

#900 #OK #games 

## Blogs
- [All Contest Problems](../Codeforces_Round_942_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
