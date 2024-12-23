<h1 style='text-align: center;'> B. Plane of Tanks: Pro</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya has been playing Plane of Tanks with his friends the whole year. Now it is time to divide the participants into several categories depending on their results. 

A player is given a non-negative integer number of points in each round of the Plane of Tanks. Vasya wrote results for each round of the last year. He has *n* records in total.

In order to determine a player's category consider the best result obtained by the player and the best results of other players. The player belongs to category: 

* "noob" — if more than 50% of players have better results;
* "random" — if his result is not worse than the result that 50% of players have, but more than 20% of players have better results;
* "average" — if his result is not worse than the result that 80% of players have, but more than 10% of players have better results;
* "hardcore" — if his result is not worse than the result that 90% of players have, but more than 1% of players have better results;
* "pro" — if his result is not worse than the result that 99% of players have.

 When the percentage is calculated the player himself is taken into account. That means that if two players played the game and the first one gained 100 points and the second one 1000 points, then the first player's result is not worse than the result that 50% of players have, and the second one is not worse than the result that 100% of players have.

Vasya gave you the last year Plane of Tanks results. Help Vasya determine each player's category.

## Input

The first line contains the only integer number *n* (1 ≤ *n* ≤ 1000) — a number of records with the players' results.

Each of the next *n* lines contains a player's name and the amount of points, obtained by the player for the round, separated with a space. The name contains not less than 1 and no more than 10 characters. The name consists of lowercase Latin letters only. It is guaranteed that any two different players have different names. The amount of points, obtained by the player for the round, is a non-negative integer number and does not exceed 1000.

## Output

Print on the first line the number *m* — the number of players, who participated in one round at least.

Each one of the next *m* lines should contain a player name and a category he belongs to, separated with space. Category can be one of the following: "noob", "random", "average", "hardcore" or "pro" (without quotes). The name of each player should be printed only once. Player names with respective categories can be printed in an arbitrary order.

## Examples

## Input


```
5  
vasya 100  
vasya 200  
artem 100  
kolya 200  
igor 250  

```
## Output


```
4  
artem noob  
igor pro  
kolya random  
vasya random  

```
## Input


```
3  
vasya 200  
kolya 1000  
vasya 1000  

```
## Output


```
2  
kolya pro  
vasya pro  

```
## Note

In the first example the best result, obtained by artem is not worse than the result that 25% of players have (his own result), so he belongs to category "noob". vasya and kolya have best results not worse than the results that 75% players have (both of them and artem), so they belong to category "random". igor has best result not worse than the result that 100% of players have (all other players and himself), so he belongs to category "pro".

In the second example both players have the same amount of points, so they have results not worse than 100% players have, so they belong to category "pro".



#### tags 

#1400 #implementation 