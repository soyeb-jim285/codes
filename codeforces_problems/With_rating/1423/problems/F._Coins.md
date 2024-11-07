<h1 style='text-align: center;'> F. Coins</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A famous gang of pirates, Sea Dogs, has come back to their hideout from one of their extravagant plunders. They want to split their treasure fairly amongst themselves, that is why You, their trusted financial advisor, devised a game to help them:

All of them take a sit at their round table, some of them with the golden coins they have just stolen. At each iteration of the game if one of them has equal or more than 2 coins, he is eligible to the splitting and he gives one coin to each pirate sitting next to him. If there are more candidates (pirates with equal or more than 2 coins) then You are the one that chooses which one of them will do the splitting in that iteration. The game ends when there are no more candidates eligible to do the splitting. 

Pirates can call it a day, only when the game ends. Since they are beings with a finite amount of time at their disposal, they would prefer if the game that they are playing can end after finite iterations, and if so, they call it a good game. On the other hand, if no matter how You do the splitting, the game cannot end in finite iterations, they call it a bad game. Can You help them figure out before they start playing if the game will be good or bad?

##### Input

The first line of input contains two integer numbers $n$ and $k$ ($1 \le n \le 10^{9}$, $0 \le k \le 2\cdot10^5$), where $n$ denotes total number of pirates and $k$ is the number of pirates that have any coins.

The next $k$ lines of input contain integers $a_i$ and $b_i$ ($1 \le a_i \le n$, $1 \le b_i \le 10^{9}$), where $a_i$ denotes the index of the pirate sitting at the round table ($n$ and $1$ are neighbours) and $b_i$ the total number of coins that pirate $a_i$ has at the start of the game. 

##### Output

Print $1$ if the game is a good game: There is a way to do the splitting so the game ends after finite number of iterations.

Print $-1$ if the game is a bad game: No matter how You do the splitting the game does not end in finite number of iterations.

## Examples

##### Input


```text
4 2
1 2
2 2
```
##### Output


```text
1
```
##### Input

```text

6 2
2 3
4 1

```
##### Output


```text
1
```
##### Input

```text

3 2
1 1
2 2

```
##### Output


```text

-1
```
## Note

In the third example the game has no end, because You always only have only one candidate, after whose splitting you end up in the same position as the starting one. 



#### Tags 

#2700 #NOT OK #math 

## Blogs
- [All Contest Problems](../Bubble_Cup_13_-_Finals_[Online_Mirror,_unrated,_Div._1].md)
- [Announcement (en)](../blogs/Announcement_(en).md)
