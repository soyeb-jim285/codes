<h1 style='text-align: center;'> F. Even Harder</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Gildong is now developing a puzzle game. The puzzle consists of $n$ platforms numbered from $1$ to $n$. The player plays the game as a character that can stand on each platform and the goal of the game is to move the character from the $1$-st platform to the $n$-th platform.

The $i$-th platform is labeled with an integer $a_i$ ($0 \le a_i \le n-i$). When the character is standing on the $i$-th platform, the player can move the character to any of the $j$-th platforms where $i+1 \le j \le i+a_i$. If the character is on the $i$-th platform where $a_i=0$ and $i \ne n$, the player loses the game.

Since Gildong thinks the current game is not hard enough, he wants to make it even harder. He wants to change some (possibly zero) labels to $0$ so that there remains exactly one way to win. He wants to modify the game as little as possible, so he's asking you to find the minimum number of platforms that should have their labels changed. Two ways are different if and only if there exists a platform the character gets to in one way but not in the other way.

## Input

Each test contains one or more test cases. The first line contains the number of test cases $t$ ($1 \le t \le 500$).

Each test case contains two lines. The first line of each test case consists of an integer $n$ ($2 \le n \le 3000$) — the number of platforms of the game.

The second line of each test case contains $n$ integers. The $i$-th integer is $a_i$ ($0 \le a_i \le n-i$) — the integer of the $i$-th platform.

It is guaranteed that: 

* For each test case, there is at least one way to win initially.
* The sum of $n$ in all test cases doesn't exceed $3000$.
## Output

For each test case, print one integer — the minimum number of different labels that should be changed to $0$ so that there remains exactly one way to win.

## Example

## Input


```

3
4
1 1 1 0
5
4 3 2 1 0
9
4 1 4 2 1 0 2 1 0

```
## Output


```

0
3
2

```
## Note

In the first case, the player can only move to the next platform until they get to the $4$-th platform. Since there is already only one way to win, the answer is zero.

In the second case, Gildong can change $a_2$, $a_3$, and $a_4$ to $0$ so that the game becomes $4$ $0$ $0$ $0$ $0$. Now the only way the player can win is to move directly from the $1$-st platform to the $5$-th platform.

In the third case, Gildong can change $a_2$ and $a_8$ to $0$, then the only way to win is to move in the following way: $1$ – $3$ – $7$ – $9$.



#### tags 

#2700 #dp 