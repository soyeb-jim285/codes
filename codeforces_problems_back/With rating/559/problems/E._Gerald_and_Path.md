<h1 style='text-align: center;'> E. Gerald and Path</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The main walking trail in Geraldion is absolutely straight, and it passes strictly from the north to the south, it is so long that no one has ever reached its ends in either of the two directions. The Geraldionians love to walk on this path at any time, so the mayor of the city asked the Herald to illuminate this path with a few spotlights. The spotlights have already been delivered to certain places and Gerald will not be able to move them. Each spotlight illuminates a specific segment of the path of the given length, one end of the segment is the location of the spotlight, and it can be directed so that it covers the segment to the south or to the north of spotlight.

The trail contains a monument to the mayor of the island, and although you can walk in either directions from the monument, no spotlight is south of the monument.

You are given the positions of the spotlights and their power. Help Gerald direct all the spotlights so that the total length of the illuminated part of the path is as much as possible.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 100) — the number of spotlights. Each of the *n* lines contains two space-separated integers, *a**i* and *l**i* (0 ≤ *a**i* ≤ 108, 1 ≤ *l**i* ≤ 108). Number *a**i* shows how much further the *i*-th spotlight to the north, and number *l**i* shows the length of the segment it illuminates.

It is guaranteed that all the *a**i*'s are distinct.

## Output

Print a single integer — the maximum total length of the illuminated part of the path.

## Examples

## Input


```
3  
1 1  
2 2  
3 3  

```
## Output


```
5  

```
## Input


```
4  
1 2  
3 3  
4 3  
6 2  

```
## Output


```
9  

```


#### tags 

#3000 #dp #sortings 