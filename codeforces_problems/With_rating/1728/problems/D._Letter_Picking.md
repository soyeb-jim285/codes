<h1 style='text-align: center;'> D. Letter Picking</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Alice and Bob are playing a game. Initially, they are given a non-empty string $s$, consisting of lowercase Latin letters. The length of the string is even. Each player also has a string of their own, initially empty.

Alice starts, then they alternate moves. In one move, a player takes either the first or the last letter of the string $s$, removes it from $s$ and prepends (adds to the beginning) it to their own string.

The game ends when the string $s$ becomes empty. The winner is the player with a lexicographically smaller string. If the players' strings are equal, then it's a draw.

A string $a$ is lexicographically smaller than a string $b$ if there exists such position $i$ that $a_j = b_j$ for all $j < i$ and $a_i < b_i$.

What is the result of the game if both players play optimally (e. g. both players try to win; if they can't, then try to draw)?

### Input

The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of testcases.

Each testcase consists of a single line — a non-empty string $s$, consisting of lowercase Latin letters. The length of the string $s$ is even.

The total length of the strings over all testcases doesn't exceed $2000$.

### Output

For each testcase, print the result of the game if both players play optimally. If Alice wins, print "Alice". If Bob wins, print "Bob". If it's a draw, print "Draw".

## Example

### Input


```text
2forcesabba
```
### Output

```text

Alice
Draw

```
## Note

One of the possible games Alice and Bob can play in the first testcase: 

1. Alice picks the first letter in $s$: $s=$"orces", $a=$"f", $b=$"";
2. Bob picks the last letter in $s$: $s=$"orce", $a=$"f", $b=$"s";
3. Alice picks the last letter in $s$: $s=$"orc", $a=$"ef", $b=$"s";
4. Bob picks the first letter in $s$: $s=$"rc", $a=$"ef", $b=$"os";
5. Alice picks the last letter in $s$: $s=$"r", $a=$"cef", $b=$"os";
6. Bob picks the remaining letter in $s$: $s=$"", $a=$"cef", $b=$"ros".

Alice wins because "cef" < "ros". Neither of the players follows any strategy in this particular example game, so it doesn't show that Alice wins if both play optimally.



#### Tags 

#1800 #NOT OK #constructive_algorithms #dp #games #two_pointers 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_135_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
