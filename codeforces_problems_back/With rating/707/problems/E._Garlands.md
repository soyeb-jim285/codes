<h1 style='text-align: center;'> E. Garlands</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Like all children, Alesha loves New Year celebration. During the celebration he and his whole family dress up the fir-tree. Like all children, Alesha likes to play with garlands — chains consisting of a lightbulbs.

Alesha uses a grid field sized *n* × *m* for playing. The rows of the field are numbered from 1 to *n* from the top to the bottom and columns are numbered from 1 to *m* from the left to the right.

Alesha has *k* garlands which he places at the field. He does so in the way such that each lightbulb of each garland lies in the center of some cell in the field, and each cell contains at most one lightbulb. Of course lightbulbs, which are neighbours in some garland, appears in cells neighbouring by a side.

![](images/83084fa5e68ef65bf28663953408adda2c5446b8.png)

The example of garland placing.

Each garland is turned off or turned on at any moment. If some garland is turned on then each of its lightbulbs is turned on, the same applies for garland turned off. Each lightbulb in the whole garland set is unique, and thus, being turned on, brings Alesha some pleasure, described by an integer value. Turned off lightbulbs don't bring Alesha any pleasure.

Alesha can turn garlands on and off and wants to know the sum of pleasure value which the lightbulbs, placed in the centers of the cells in some rectangular part of the field, bring him. Initially all the garlands are turned on.

Alesha is still very little and can't add big numbers. He extremely asks you to help him.

## Input

The first line of the input contains three integers *n*, *m* and *k* (1 ≤ *n*, *m*, *k* ≤ 2000) — the number of field rows, the number of field columns and the number of garlands placed at the field respectively.

Next lines contains garlands set description in the following format:

The first line of a single garland description contains a single integer *len* (1 ≤ *len* ≤ 2000) — the number of lightbulbs in the garland.

Each of the next *len* lines contains three integers *i*, *j* and *w* (1 ≤ *i* ≤ *n*, 1 ≤ *j* ≤ *m*, 1 ≤ *w* ≤ 109) — the coordinates of the cell containing a lightbullb and pleasure value Alesha gets from it if it is turned on. The lightbulbs are given in the order they are forming a chain in the garland. It is guaranteed that neighbouring lightbulbs are placed in the cells neighbouring by a side.

The next line contains single integer *q* (1 ≤ *q* ≤ 106) — the number of events in Alesha's game. The next *q* lines describes events in chronological order. The *i*-th of them describes the *i*-th event in the one of the following formats:

* SWITCH *i* — Alesha turns off *i*-th garland if it is turned on, or turns it on if it is turned off. It is guaranteed that 1 ≤ *i* ≤ *k*.
* ASK *x*1 *y*1 *x*2 *y*2 — Alesha wants to know the sum of pleasure values the lightbulbs, placed in a rectangular part of the field. Top-left cell of a part has coordinates (*x*1, *y*1) and right-bottom cell has coordinates (*x*2, *y*2). It is guaranteed that 1 ≤ *x*1 ≤ *x*2 ≤ *n* and 1 ≤ *y*1 ≤ *y*2 ≤ *m*. There is no more than 2000 events of this type in the input.

All the numbers in the input are integers.

Please note that the input is quite large, so be careful while using some input ways. In particular, it's not recommended to use cin in codes on C++ and class Scanner in codes on Java.

## Output

For each ASK operation print the sum Alesha wants to know in a separate line. Print the answers in chronological order.

## Examples

## Input


```
4 4 3  
5  
1 1 2  
1 2 3  
2 2 1  
2 1 4  
3 1 7  
4  
1 3 1  
2 3 3  
2 4 3  
1 4 1  
7  
4 1 1  
4 2 9  
3 2 8  
3 3 3  
4 3 4  
4 4 1  
3 4 1  
2  
ASK 2 2 3 3  
ASK 1 1 4 4  

```
## Output


```
15  
52  

```
## Input


```
4 4 1  
8  
4 1 1  
3 1 2  
2 1 1  
1 1 7  
1 2 5  
2 2 4  
2 3 1  
1 3 1  
3  
ASK 1 1 3 2  
SWITCH 1  
ASK 1 1 3 2  

```
## Output


```
19  
0  

```
## Note

![](images/9cc050397c0cf5696bf3273599ecbe1a65d3907b.png)

This image illustrates the first sample case.



#### tags 

#2400 #data_structures 