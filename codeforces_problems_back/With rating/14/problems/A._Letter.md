<h1 style='text-align: center;'> A. Letter</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 64 megabytes</h5>

A boy Bob likes to draw. Not long ago he bought a rectangular graph (checked) sheet with *n* rows and *m* columns. Bob shaded some of the squares on the sheet. Having seen his masterpiece, he decided to share it with his elder brother, who lives in Flatland. Now Bob has to send his picture by post, but because of the world economic crisis and high oil prices, he wants to send his creation, but to spend as little money as possible. For each sent square of paper (no matter whether it is shaded or not) Bob has to pay 3.14 burles. Please, help Bob cut out of his masterpiece a rectangle of the minimum cost, that will contain all the shaded squares. The rectangle's sides should be parallel to the sheet's sides.

## Input

The first line of the input data contains numbers *n* and *m* (1 ≤ *n*, *m* ≤ 50), *n* — amount of lines, and *m* — amount of columns on Bob's sheet. The following *n* lines contain *m* characters each. Character «.» stands for a non-shaded square on the sheet, and «*» — for a shaded square. It is guaranteed that Bob has shaded at least one square.

## Output

## Output

 the required rectangle of the minimum cost. Study the output data in the sample tests to understand the output format better.

## Examples

## Input


```
6 7  
.......  
..***..  
..*....  
..***..  
..*....  
..***..  

```
## Output


```
***  
*..  
***  
*..  
***  

```
## Input


```
3 3  
***  
*.*  
***  

```
## Output


```
***  
*.*  
***  

```


#### tags 

#800 #implementation 