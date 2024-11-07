<h1 style='text-align: center;'> C. Bubble Strike</h1>

<h5 style='text-align: center;'>time limit per test: 0.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Little Johnny Bubbles enjoys spending hours in front of his computer playing video games. His favorite game is Bubble Strike, fast-paced bubble shooting online game for two players.

Each game is set in one of the N maps, each having different terrain configuration. First phase of each game decides on which map the game will be played. The game system randomly selects three maps and shows them to the players. Each player must pick one of those three maps to be discarded. The game system then randomly selects one of the maps that were not picked by any of the players and starts the game.

Johnny is deeply enthusiastic about the game and wants to spend some time studying maps, thus increasing chances to win games played on those maps. However, he also needs to do his homework, so he does not have time to study all the maps. That is why he asked himself the following question: "What is the minimum number of maps I have to study, so that the probability to play one of those maps is at least $P$"?

Can you help Johnny find the answer for this question? You can assume Johnny's opponents do not know him, and they will randomly pick maps.

## Input

The first line contains two integers $N$ ($3$ $\leq$ $N$ $\leq$ $10^{3}$) and $P$ ($0$ $\leq$ $P$ $\leq$ $1$) – total number of maps in the game and probability to play map Johnny has studied. $P$ will have at most four digits after the decimal point.

## Output

## Output

 contains one integer number – minimum number of maps Johnny has to study.

## Example

## Input


```

7 1.0000

```
## Output


```

6

```


#### tags 

#2000 #combinatorics #math #probabilities #ternary_search 