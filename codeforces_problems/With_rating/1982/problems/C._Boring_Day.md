<h1 style='text-align: center;'> C. Boring Day</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

On another boring day, Egor got bored and decided to do something. But since he has no friends, he came up with a game to play.

Egor has a deck of $n$ cards, the $i$-th card from the top has a number $a_i$ written on it. Egor wants to play a certain number of rounds until the cards run out. In each round, he takes a non-zero number of cards from the top of the deck and finishes the round. If the sum of the numbers on the cards collected during the round is between $l$ and $r$, inclusive, the round is won; otherwise, it is lost. 

Egor knows by heart the order of the cards. Help Egor determine the maximum number of rounds he can win in such a game. 
## Note

 that Egor is not required to win rounds consecutively.

### Input

Each test consists of several test cases. The first line contains an integer $t$ ($1 \le t \le 10^{4}$) — the number of test cases. This is followed by a description of the test cases.

The first line of each test case contains three integers $n$, $l$, and $r$ ($1 \le n \le 10^{5}$, $1 \le l \le r \le 10^9$).

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$) — the numbers on the cards from top to bottom.

It is guaranteed that the sum of $n$ for all test cases does not exceed $2 \cdot 10^{5}$.

### Output

For each test case, output a single number — the maximum number of rounds Egor can win.

## Example

### Input


```text
85 3 102 1 11 3 710 1 517 8 12 11 7 11 21 13 10 83 4 53 4 28 12 2510 7 5 13 8 9 12 72 3 35 29 7 92 10 5 1 3 7 6 2 31 8 1095 5 61 4 2 6 4
```
### Output

```text

3
0
1
4
0
3
1
2

```
## Note

In the first test case, Egor can win $3$ rounds:

* In the first round, take the top $2$ cards with values $2$ and $1$ and win, as their sum is $3$. After this, the deck will look like this: $[11, 3, 7]$.
* In the second round, take the top card and lose, as its value $11$ is greater than $r = 10$. After this, the deck will look like this: $[3, 7]$.
* In the third round, take the top card with value $3$ and win. After this, the deck will look like this: $[7]$.
* After this, in the fourth round, Egor only has to take the last card in the deck with value $7$ and win again.

In the second test case, Egor cannot win any rounds, no matter how hard he tries.

In the third test case, you can take one card in each round, then the first and third rounds will be losing, and the second round will be winning.

In the fourth test case, you can take two cards in each round and always win.



#### Tags 

#1200 #NOT OK #binary_search #data_structures #dp #greedy #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_955_(Div._2,_with_prizes_from_NEAR!).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial](../blogs/Tutorial.md)
