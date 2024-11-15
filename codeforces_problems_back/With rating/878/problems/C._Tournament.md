<h1 style='text-align: center;'> C. Tournament</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Recently a tournament in *k* kinds of sports has begun in Berland. Vasya wants to make money on the bets.

The scheme of the tournament is very mysterious and not fully disclosed. Competitions are held back to back, each of them involves two sportsmen who have not left the tournament yet. Each match can be held in any of the *k* kinds of sport. Loser leaves the tournament. The last remaining sportsman becomes the winner. Apart of this, the scheme can be arbitrary, it is not disclosed in advance.

Vasya knows powers of sportsmen in each kind of sport. He believes that the sportsmen with higher power always wins.

The tournament is held every year, and each year one new participant joins it. In the first tournament, only one sportsman has participated, in the second there were two sportsmen, and so on. Vasya has been watching the tournament for the last *n* years. Help him to find the number of possible winners for each of the *n* tournaments.

## Input

The first line contains two integers *n* and *k* (1 ≤ *n* ≤ 5·104, 1 ≤ *k* ≤ 10) — the number of tournaments and the number of kinds of sport, respectively.

Each of the next *n* lines contains *k* integers *s**i*1, *s**i*2, ..., *s**ik* (1 ≤ *s**ij* ≤ 109), where *s**ij* is the power of the *i*-th sportsman in the *j*-th kind of sport. The sportsman with higher powers always wins. It's guaranteed that for any kind of sport all of these powers are distinct.

## Output

For each of the *n* tournaments output the number of contenders who can win.

## Examples

## Input


```
3 2  
1 5  
5 1  
10 10  

```
## Output


```
1  
2  
1  

```
## Input


```
3 2  
2 2  
3 3  
1 10  

```
## Output


```
1  
1  
3  

```
## Input


```
3 2  
2 3  
1 1  
3 2  

```
## Output


```
1  
1  
2  

```
## Note

In the first sample:

In the first tournament there is only one sportsman, and he is the winner.

In the second tournament, there are two sportsmen, and everyone can defeat another, depending on kind of sports.

In the third tournament, the third sportsman in the strongest in both kinds of sports, so he is the winner regardless of the scheme.



#### tags 

#2700 #data_structures #graphs 