<h1 style='text-align: center;'> C. Thanos Nim</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice and Bob are playing a game with $n$ piles of stones. It is guaranteed that $n$ is an even number. The $i$-th pile has $a_i$ stones.

Alice and Bob will play a game alternating turns with Alice going first.

On a player's turn, they must choose exactly $\frac{n}{2}$ nonempty piles and independently remove a positive number of stones from each of the chosen piles. They can remove a different number of stones from the piles in a single turn. The first player unable to make a move loses (when there are less than $\frac{n}{2}$ nonempty piles).

Given the starting configuration, determine who will win the game.

#### Input

The first line contains one integer $n$ ($2 \leq n \leq 50$) — the number of piles. It is guaranteed that $n$ is an even number.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq 50$) — the number of stones in the piles.

#### Output

Print a single string "Alice" if Alice wins; otherwise, print "Bob" (without double quotes).

## Examples

#### Input


```text
2
8 8
```
#### Output


```text
Bob
```
#### Input


```text
4
3 1 4 1
```
#### Output


```text
Alice
```
## Note

In the first example, each player can only remove stones from one pile ($\frac{2}{2}=1$). Alice loses, since Bob can copy whatever Alice does on the other pile, so Alice will run out of moves first.

In the second example, Alice can remove $2$ stones from the first pile and $3$ stones from the third pile on her first move to guarantee a win.



#### Tags 

#2000 #NOT OK #games 

## Blogs
- [All Contest Problems](../Forethought_Future_Cup_-_Final_Round_(Onsite_Finalists_Only).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
