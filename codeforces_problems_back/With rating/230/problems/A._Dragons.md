<h1 style='text-align: center;'> A. Dragons</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Kirito is stuck on a level of the MMORPG he is playing now. To move on in the game, he's got to defeat all *n* dragons that live on this level. Kirito and the dragons have strength, which is represented by an integer. In the duel between two opponents the duel's outcome is determined by their strength. Initially, Kirito's strength equals *s*.

If Kirito starts duelling with the *i*-th (1 ≤ *i* ≤ *n*) dragon and Kirito's strength is not greater than the dragon's strength *x**i*, then Kirito loses the duel and dies. But if Kirito's strength is greater than the dragon's strength, then he defeats the dragon and gets a bonus strength increase by *y**i*.

Kirito can fight the dragons in any order. Determine whether he can move on to the next level of the game, that is, defeat all dragons without a single loss.

## Input

The first line contains two space-separated integers *s* and *n* (1 ≤ *s* ≤ 104, 1 ≤ *n* ≤ 103). Then *n* lines follow: the *i*-th line contains space-separated integers *x**i* and *y**i* (1 ≤ *x**i* ≤ 104, 0 ≤ *y**i* ≤ 104) — the *i*-th dragon's strength and the bonus for defeating it.

## Output

On a single line print "YES" (without the quotes), if Kirito can move on to the next level and print "NO" (without the quotes), if he can't.

## Examples

## Input


```
2 2  
1 99  
100 0  

```
## Output


```
YES  

```
## Input


```
10 1  
100 100  

```
## Output


```
NO  

```
## Note

In the first sample Kirito's strength initially equals 2. As the first dragon's strength is less than 2, Kirito can fight it and defeat it. After that he gets the bonus and his strength increases to 2 + 99 = 101. Now he can defeat the second dragon and move on to the next level.

In the second sample Kirito's strength is too small to defeat the only dragon and win.



#### tags 

#1000 #greedy #sortings 