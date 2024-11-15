<h1 style='text-align: center;'> E. Dima and Kicks</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Dima is a good person. In fact, he's great. But all good things come to an end...

Seryozha is going to kick Dima just few times.. For this reason he divides the room into unit squares. Now the room is a rectangle *n* × *m* consisting of unit squares.

For the beginning, Seryozha put Dima in a center of some square. Then he started to kick Dima (it is known, that he kicks Dima at least once). Each time when Dima is kicked he flyes up and moves into one of four directions (up, left, right, down). On each move Dima passes *k* (*k* > 1) unit of the length in the corresponding direction. Seryozha is really kind, so he kicks Dima in such way that Dima never meets the walls (in other words, Dima never leave the room's space). Seryozha is also dynamic character so Dima never flies above the same segment, connecting a pair of adjacent squares, twice.

Seryozha kicks Dima for a long time, but Dima is not vindictive — Dima writes. Dima marked all squares in which he was staying or above which he was flying. Thanks to kicks, Dima does not remember the *k* value, so he asks you to find all possible values which matches to the Dima's records.

## Input

The first line contains *n* and *m* (1 ≤ *n*, *m* ≤ 103) — size of the room.

Next *n* lines goes, each contains *m* numbers *a**ij* — Dima's notes: *a**ij* = 1, if Dima was staying in the square (*i*, *j*) or was flying above it. Otherwise *a**ij* = 0.

At least one *a**ij* equals 1.

## Output

In a single line in accending order print all *k* (*k* > 1), which matches the Dima's notes. If there are no such *k* and Dima invented this story with kicks, print -1.

## Examples

## Input


```
5 5  
1 1 1 1 1  
1 0 0 0 1  
1 0 0 0 1  
1 0 0 0 1  
1 1 1 1 1  

```
## Output


```
2 4  

```
## Input


```
7 7  
0 0 1 1 1 0 0  
0 0 1 0 1 0 0  
1 1 1 1 1 1 1  
1 0 1 0 1 0 1  
1 1 1 1 1 1 1  
0 0 1 0 1 0 0  
0 0 1 1 1 0 0  

```
## Output


```
2  

```
## Input


```
3 3  
1 1 1  
1 1 1  
1 1 1  

```
## Output


```
-1  

```
## Input


```
4 4  
1 1 1 1  
0 0 0 0  
0 0 0 0  
0 0 0 0  

```
## Output


```
3  

```
## Input


```
5 5  
0 0 1 0 0  
0 0 1 0 0  
1 1 1 1 1  
0 0 1 0 0  
0 0 1 0 0  

```
## Output


```
-1  

```


#### tags 

#2300 #brute_force #dsu #graphs #implementation 