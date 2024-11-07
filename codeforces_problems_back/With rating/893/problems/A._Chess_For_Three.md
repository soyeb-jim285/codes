<h1 style='text-align: center;'> A. Chess For Three</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alex, Bob and Carl will soon participate in a team chess tournament. Since they are all in the same team, they have decided to practise really hard before the tournament. But it's a bit difficult for them because chess is a game for two players, not three.

So they play with each other according to following rules:

* Alex and Bob play the first game, and Carl is spectating;
* When the game ends, the one who lost the game becomes the spectator in the next game, and the one who was spectating plays against the winner.

Alex, Bob and Carl play in such a way that there are no draws.

Today they have played *n* games, and for each of these games they remember who was the winner. They decided to make up a log of games describing who won each game. But now they doubt if the information in the log is correct, and they want to know if the situation described in the log they made up was possible (that is, no game is won by someone who is spectating if Alex, Bob and Carl play according to the rules). Help them to check it!

## Input

The first line contains one integer *n* (1 ≤ *n* ≤ 100) — the number of games Alex, Bob and Carl played.

Then *n* lines follow, describing the game log. *i*-th line contains one integer *a**i* (1 ≤ *a**i* ≤ 3) which is equal to 1 if Alex won *i*-th game, to 2 if Bob won *i*-th game and 3 if Carl won *i*-th game.

## Output

Print YES if the situation described in the log was possible. Otherwise print NO.

## Examples

## Input


```
3  
1  
1  
2  

```
## Output


```
YES  

```
## Input


```
2  
1  
2  

```
## Output


```
NO  

```
## Note

In the first example the possible situation is:

1. Alex wins, Carl starts playing instead of Bob;
2. Alex wins, Bob replaces Carl;
3. Bob wins.

The situation in the second example is impossible because Bob loses the first game, so he cannot win the second one.



#### tags 

#900 #implementation 