<h1 style='text-align: center;'> E. Alternative Reality</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In the year of 3000 travelling around parallel realities became a routine thing. However one has to take into consideration that travelling like that is highly dangerous as you never know beforehand where you're gonna get...

Little Vasya, for instance, found himself in a gaming reality and now he has to successfully complete all levels of a very weird game to get back. The gaming reality is a three-dimensional space where *n* points are given. The game has *m* levels and at the beginning of the *i*-th level the player is positioned at some plane *Q**i* that passes through the origin. On each level Vasya has to use special robots to construct and activate *n* powerful energy spheres of the equal radius with centers at the given points. The player chooses the radius of the spheres himself. The player has to spend *R* units of money to construct spheres whose radius equals *R* (consequently, one can construct spheres whose radius equals zero for free). Besides, once for each level a player can choose any point in space and release a laser ray from there, perpendicular to plane *Q**i* (this action costs nothing). The ray can either be directed towards the plane or from the plane. The spheres that share at least one point with the ray will be immediately activated. The level is considered completed if the player has managed to activate all spheres. Note that the centers of the spheres are the same for all *m* levels but the spheres do not remain: the player should construct them anew on each new level.

Help Vasya find out what minimum sum of money will be enough to complete each level.

## Input

The first line contains two integers *n* and *m* (1 ≤ *n* ≤ 900, 1 ≤ *m* ≤ 100) — the number of energetic spheres and the number of levels in the game correspondingly. 

Each of the following *n* lines contains three integers *x**i*, *y**i*, *z**i* (0 ≤ *x**i*, *y**i*, *z**i* ≤ 104) — the coordinates of the center of the *i*-th sphere. Assume that these points do not change their positions throughout the game.

Then follow *m* lines, each containing three integers *a**i*, *b**i*, *c**i* (0 ≤ *a**i*, *b**i*, *c**i* ≤ 100, *a**i*2 + *b**i*2 + *c**i*2 > 0). These numbers are the coefficients in the equation of plane *Q**i* (*a**i**x* + *b**i**y* + *c**i**z* = 0), where the player is positioned at the beginning of the *i*-th level.

## Output

Print *m* numbers, one per line: the *i*-th line should contain the minimum sum of money needed to complete the *i*-th level. The absolute or relative error should not exceed 10- 6.

## Examples

## Input


```
4 1  
0 0 0  
0 1 0  
1 0 0  
1 1 0  
0 0 1  

```
## Output


```
0.7071067812  

```
## Input


```
5 3  
0 1 0  
1 0 1  
1 2 1  
2 0 1  
1 3 0  
1 1 1  
1 2 3  
3 0 3  

```
## Output


```
1.6329931619  
1.6366341768  
1.5411035007  

```
## Input


```
2 1  
0 20 0  
0 0 0  
0 10 0  

```
## Output


```
0.0000000000  

```


#### tags 

#2400 #geometry 