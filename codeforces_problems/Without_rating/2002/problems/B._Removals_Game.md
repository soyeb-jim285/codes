<h1 style='text-align: center;'> B. Removals Game</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice got a permutation $a_1, a_2, \ldots, a_n$ of $[1,2,\ldots,n]$, and Bob got another permutation $b_1, b_2, \ldots, b_n$ of $[1,2,\ldots,n]$. They are going to play a game with these arrays.

In each turn, the following events happen in order:

* Alice chooses either the first or the last element of her array and removes it from the array;
* Bob chooses either the first or the last element of his array and removes it from the array.

The game continues for $n-1$ turns, after which both arrays will have exactly one remaining element: $x$ in the array $a$ and $y$ in the array $b$.

If $x=y$, Bob wins; otherwise, Alice wins. Find which player will win if both players play optimally.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1\le t\le10^4$). The description of the test cases follows. 

The first line of each test case contains a single integer $n$ ($1\le n\le 3\cdot 10^5$).

The next line contains $n$ integers $a_1,a_2,\ldots,a_n$ ($1\le a_i\le n$, all $a_i$ are distinct) — the permutation of Alice.

The next line contains $n$ integers $b_1,b_2,\ldots,b_n$ ($1\le b_i\le n$, all $b_i$ are distinct) — the permutation of Bob.

It is guaranteed that the sum of all $n$ does not exceed $3\cdot 10^5$.

### Output

For each test case, print a single line with the name of the winner, assuming both players play optimally. If Alice wins, print $\texttt{Alice}$; otherwise, print $\texttt{Bob}$.

## Example

### Input


```text
221 21 231 2 32 3 1
```
### Output

```text

Bob
Alice

```
## Note

In the first test case, Bob can win the game by deleting the same element as Alice did.

In the second test case, Alice can delete $3$ in the first turn, and then in the second turn, delete the element that is different from the one Bob deleted in the first turn to win the game.



#### Tags 

#NOT OK #constructive_algorithms #games 

## Blogs
- [All Contest Problems](../EPIC_Institute_of_Technology_Round_August_2024_(Div._1_+_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
