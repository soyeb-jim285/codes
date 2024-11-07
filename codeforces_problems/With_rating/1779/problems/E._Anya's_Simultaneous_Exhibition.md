<h1 style='text-align: center;'> E. Anya's Simultaneous Exhibition</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

Anya has gathered $n$ chess experts numbered from $1$ to $n$ for which the following properties hold:

* For any pair of players one of the players wins every game against the other (and no draws ever occur);
* Transitivity does not necessarily hold — it might happen that $A$ always beats $B$, $B$ always beats $C$ and $C$ always beats $A$.

 Anya does not know, for each pair, who is the player who beats the other.To organize a tournament, Anya hosts $n-1$ games. In each game, she chooses two players. One of them wins and stays, while the other one is disqualified. After all the games are hosted only one player will remain. A player is said to be a candidate master if they can win a tournament (notice that the winner of a tournament may depend on the players selected by Anya in the $n-1$ games).

Since Anya is a curious girl, she is interested in finding the candidate masters. Unfortunately, she does not have much time. To speed up the process, she will organize up to $2n$ simuls (short for "simultaneous exhibition", in which one player plays against many).

In one simul, Anya chooses exactly one player who will play against some (at least one) of the other players. The chosen player wins all games they would win in a regular game, and the same holds for losses. After the simul finishes, Anya is only told the total number of games won by the chosen player (but not which ones). Nobody is disqualified during a simul.

Can you help Anya host simuls and determine the candidate masters?

The winning players in each pair could be changed between the simuls, but only in a way that preserves the results of all previous simuls. These changes may depend on your queries.

## Interaction

Firstly, the jury sends one integer $n$ ($3 \leq n \leq 250$) which should be read — the number of players. After that, your program may ask queries or report an answer.

To ask a query, print "? $i \; s_1 s_2 \ldots s_n$" (without quotes), where $i$ is the index of the player who will play against some of the other players in the simul. $s$ is a binary string that denotes the players they play against. $i$ plays against every player $j$ for which $s_j = 1$ holds (and $s_j = 1$ should hold for at least one $1 \leq j \leq n$). Please note that $s_i = 0$ must hold since a player cannot play against themselves, otherwise, the query is considered to be incorrect.

After this, you should read an integer — the number of games player $i$ has won.

When you have identified the answer, you must print "! $c_1 c_2 \ldots c_n$" (without quotes) and terminate your program. $c$ is a binary string which represents the candidate masters. Player $i$ is a candidate master if $c_i=1$ holds, otherwise, they are not.

If you ask more than $2n$ queries or if one of the queries is malformed, the interaction terminates immediately and your program receives verdict Wrong Answer.

After printing a query do not forget to output the end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use: 

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see the documentation for other languages.

Hacks are disabled in this problem.

## Examples

##Input
```text
3

1

1

1
```
##Output
```text

? 1 010

? 2 001

? 3 100

! 111
```
##Input
```text
5

0

3

4
```
##Output
```text


? 5 10110

? 2 10111

? 1 01111

! 10000
```
## Note

In the first example, the first query describes a simul in which player $1$ plays against player $2$ (and no one else). The answer to the query is $1$, meaning that player $1$ won the only game they played. We can conclude that $1$ beats $2$. Similarly, the second query tells us that $2$ beats $3$ and the third query tells us that $3$ beats $1$. All players are candidate masters in this case as

* Player $1$ can win the tournament if $2$ and $3$ play first. $3$ loses and leaves, while $2$ stays. $1$ then plays against $2$ and wins;
* Other players can win in the same fashion.

In the second example, the third query describes a simul in which player $1$ plays against every other player. The answer to the query is $4$, meaning that they won every game they played. It can be concluded that player $1$ also beats every other player. They can never lose, hence they are the only player who can remain at the end of every possible tournament, and the only possible candidate master. 



#### Tags 

#2400 #NOT OK #constructive_algorithms #graphs #greedy #interactive #sortings 

## Blogs
- [All Contest Problems](../Hello_2023.md)
- [Hello 2023 (en)](../blogs/Hello_2023_(en).md)
- [Editorial for Hello 2023 (en)](../blogs/Editorial_for_Hello_2023_(en).md)
