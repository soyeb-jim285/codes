<h1 style='text-align: center;'> B. Circle Game</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Mike and Joe are playing a game with some stones. Specifically, they have $n$ piles of stones of sizes $a_1, a_2, \ldots, a_n$. These piles are arranged in a circle.

The game goes as follows. Players take turns removing some positive number of stones from a pile in clockwise order starting from pile $1$. Formally, if a player removed stones from pile $i$ on a turn, the other player removes stones from pile $((i\bmod n) + 1)$ on the next turn.

If a player cannot remove any stones on their turn (because the pile is empty), they lose. Mike goes first.

If Mike and Joe play optimally, who will win?

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 1000$). Description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 50$)  — the number of piles.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$)  — the size of the piles.

### Output

For each test case print the winner of the game, either "Mike" or "Joe" on its own line (without quotes).

## Example

### Input


```text
21372100 100
```
### Output

```text

Mike
Joe

```
## Note

In the first test case, Mike just takes all $37$ stones on his first turn.

In the second test case, Joe can just copy Mike's moves every time. Since Mike went first, he will hit $0$ on the first pile one move before Joe does so on the second pile.



#### Tags 

#1000 #OK #games #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_801_(Div._2)_and_EPIC_Institute_of_Technology_Round.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
