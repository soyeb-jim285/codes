<h1 style='text-align: center;'> F. Lamps on a Circle</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

This is an interactive problem.

John and his imaginary friend play a game. There are $n$ lamps arranged in a circle. Lamps are numbered $1$ through $n$ in clockwise order, that is, lamps $i$ and $i + 1$ are adjacent for any $i = 1, \ldots, n - 1$, and also lamps $n$ and $1$ are adjacent. Initially all lamps are turned off.

John and his friend take turns, with John moving first. On his turn John can choose to terminate the game, or to make a move. To make a move, John can choose any positive number $k$ and turn any $k$ lamps of his choosing on. In response to this move, John's friend will choose $k$ consecutive lamps and turn all of them off (the lamps in the range that were off before this move stay off). 
## Note

 that the value of $k$ is the same as John's number on his last move. For example, if $n = 5$ and John have just turned three lamps on, John's friend may choose to turn off lamps $1, 2, 3$, or $2, 3, 4$, or $3, 4, 5$, or $4, 5, 1$, or $5, 1, 2$.

After this, John may choose to terminate or move again, and so on. However, John can not make more than $10^4$ moves.

John wants to maximize the number of lamps turned on at the end of the game, while his friend wants to minimize this number. Your task is to provide a strategy for John to achieve optimal result. Your program will play interactively for John against the jury's interactor program playing for John's friend.

Suppose there are $n$ lamps in the game. Let $R(n)$ be the number of turned on lamps at the end of the game if both players act optimally. Your program has to terminate the game with at least $R(n)$ turned on lamps within $10^4$ moves. Refer to 
## Interaction

 section below for interaction details.

For technical reasons hacks for this problem are disabled.

## Interaction

Initially your program will be fed a single integer $n$ ($1 \leq n \leq 1000$) — the number of lamps in the game. Then the interactor will wait for your actions.

To make a move, print a line starting with an integer $k$ ($1 \leq k \leq n$), followed by $k$ distinct integers $l_1, \ldots, l_k$ ($1 \leq l_i \leq n$) — indices of lamps you want to turn on. The indices may be printed in any order. It is allowed to try to turn on a lamp that is already on (although this will have no effect).

If your move was invalid for any reason, or if you have made more than $10^4$ moves, the interactor will reply with a line containing a single integer $-1$. Otherwise, the reply will be a line containing a single integer $x$ ($1 \leq x \leq n)$, meaning that the response was to turn off $k$ consecutive lamps starting from $x$ in clockwise order.

To terminate the game instead of making a move, print a line containing a single integer $0$. The test will be passed if at this point there are at least $R(n)$ lamps turned on (note that neither $R(n)$, nor the verdict received are not communicated to your program in any way). This action does not count towards the number of moves (that is, it is legal to terminate the game after exactly $10^4$ moves).

To receive the correct verdict, your program should terminate immediately after printing $0$, or after receiving $-1$ as a response.

Don't forget to flush your output after every action.

## Examples

##Input
```text
3
```
##Output
```text

0
```
##Input
```text
4

1
```
##Output
```text


2 1 3

0
```
## Note

When $n = 3$, any John's move can be reversed, thus $R(3) = 0$, and terminating the game immediately is correct.

$R(4) = 1$, and one strategy to achieve this result is shown in the second sample case.

Blank lines in sample interactions are for clarity and should not be printed.



#### Tags 

#2600 #NOT OK #games #implementation #interactive #math 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_8.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
