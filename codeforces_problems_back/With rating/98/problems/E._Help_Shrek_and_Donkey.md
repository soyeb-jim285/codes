<h1 style='text-align: center;'> E. Help Shrek and Donkey</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Shrek and the Donkey (as you can guess, they also live in the far away kingdom) decided to play a card game called YAGame. The rules are very simple: initially Shrek holds *m* cards and the Donkey holds *n* cards (the players do not see each other's cards), and one more card lies on the table face down so that both players cannot see it as well. Thus, at the beginning of the game there are overall *m* + *n* + 1 cards. Besides, the players know which cards the pack of cards consists of and their own cards (but they do not know which card lies on the table and which ones the other player has). The players move in turn and Shrek starts. During a move a player can:

* Try to guess which card is lying on the table. If he guesses correctly, the game ends and he wins. If his guess is wrong, the game also ends but this time the other player wins.
* Name any card from the pack. If the other player has such card, he must show it and put it aside (so that this card is no longer used in the game). If the other player doesn't have such card, he says about that.

 Recently Donkey started taking some yellow pills and winning over Shrek. Now Shrek wants to evaluate his chances to win if he too starts taking the pills.Help Shrek assuming the pills are good in quality and that both players using them start playing in the optimal manner.

## Input

The first line contains space-separated integers *m* and *n* (0 ≤ *m*, *n* ≤ 1000).

## Output

Print space-separated probabilities that Shrek wins and Donkey wins correspondingly; the absolute error should not exceed 10- 9.

## Examples

## Input


```
0 3  

```
## Output


```
0.25 0.75  

```
## Input


```
1 0  

```
## Output


```
1 0  

```
## Input


```
1 1  

```
## Output


```
0.5 0.5  

```


#### tags 

#2700 #dp #games #math #probabilities 