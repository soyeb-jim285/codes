<h1 style='text-align: center;'> B. Playing in a Casino</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

 ![](images/39aaedd509046ad98511f0817fc7b2e985487828.png) Galaxy Luck, a well-known casino in the entire solar system, introduces a new card game.

In this game, there is a deck that consists of $n$ cards. Each card has $m$ numbers written on it. Each of the $n$ players receives exactly one card from the deck.

Then all players play with each other in pairs, and each pair of players plays exactly once. Thus, if there are, for example, four players in total, then six games are played: the first against the second, the first against the third, the first against the fourth, the second against the third, the second against the fourth and the third against the fourth.

Each of these games determines the winner in some way, but the rules are quite complicated, so we will not describe them here. All that matters is how many chips are paid out to the winner. Let the first player's card have the numbers $a_1, a_2, \dots, a_m$, and the second player's card — $b_1, b_2, \dots, b_m$. Then the winner of the game gets $|a_1 - b_1| + |a_2 - b_2| + \dots + |a_m - b_m|$ chips from the total pot, where $|x|$ denotes the absolute value of $x$.

To determine the size of the total pot, it is necessary to calculate the winners' total winnings for all games. Since there can be many cards in a deck and many players, you have been assigned to write a program that does all the necessary calculations.

### Input

Each test consists of several test cases. The first line contains one integer $t$ ($1 \le t \le 1000$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers $n$ and $m$ ($1 \le n \cdot m \le 3\cdot 10^5$) — the number of cards in the deck and the count of numbers on the one card.

Each of the following $n$ lines of the test case set contains $m$ integers $c_{i,j}$ ($1 \le c_{i,j} \le 10^6$) — a description of the $i$-th card.

It is guaranteed that the total $n \cdot m$ in all tests does not exceed $3 \cdot 10^5$.

### Output

For each test case, print one number — the total amount of winnings from all games.

## Example

### Input


```text
33 51 4 2 8 57 9 2 1 43 8 5 3 11 44 15 1 104 31 2 33 2 11 2 14 2 7
```
### Output

```text

50
0
31

```
## Note

Consider the first test case.

In the game between the first and second player, the winner receives $|1-7| + |4-9| + |2-2| + |8-1| + |5-4| = 19$ chips.

In the game between the first and third player, the winner receives $|1-3| + |4-8| + |2-5| + |8-3| + |5-1| = 18$ in chips.

In the game between the second and third player, the winner receives $|7-3| + |9-8| + |2-5| + |1-3| + |4-1| = 13$ chips.

The total is $19 + 18 + 13 = 50$ chips.



#### Tags 

#1200 #OK #math #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_861_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
