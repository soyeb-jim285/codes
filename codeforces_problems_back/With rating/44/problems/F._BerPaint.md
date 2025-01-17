<h1 style='text-align: center;'> F. BerPaint</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Anfisa the monkey got disappointed in word processors as they aren't good enough at reflecting all the range of her emotions, that's why she decided to switch to graphics editors. Having opened the BerPaint, she saw a white rectangle *W* × *H* in size which can be painted on. First Anfisa learnt to navigate the drawing tool which is used to paint segments and quickly painted on that rectangle a certain number of black-colored segments. The resulting picture didn't seem bright enough to Anfisa, that's why she turned her attention to the "fill" tool which is used to find a point on the rectangle to paint and choose a color, after which all the area which is the same color as the point it contains, is completely painted the chosen color. Having applied the fill several times, Anfisa expressed her emotions completely and stopped painting. Your task is by the information on the painted segments and applied fills to find out for every color the total area of the areas painted this color after all the fills.

## Input

The first input line has two integers *W* and *H* (3 ≤ *W*, *H* ≤ 104) — the sizes of the initially white rectangular painting area. The second line contains integer *n* — the number of black segments (0 ≤ *n* ≤ 100). On the next *n* lines are described the segments themselves, each of which is given by coordinates of their endpoints *x*1, *y*1, *x*2, *y*2 (0 < *x*1, *x*2 < *W*, 0 < *y*1, *y*2 < *H*). All segments have non-zero length. The next line contains preset number of fills *m* (0 ≤ *m* ≤ 100). Each of the following *m* lines defines the fill operation in the form of "*x* *y* *color*", where (*x*, *y*) are the coordinates of the chosen point (0 < *x* < *W*, 0 < *y* < *H*), and *color* — a line of lowercase Latin letters from 1 to 15 symbols in length, determining the color. All coordinates given in the input are integers. Initially the rectangle is "white" in color, whereas the segments are drawn "black" in color.

## Output

For every color present in the final picture print on the single line the name of the color and the total area of areas painted that color with an accuracy of 10- 6. Print the colors in any order. 

## Examples

## Input


```
4 5  
6  
1 1 1 3  
1 3 3 3  
3 3 3 1  
3 1 1 1  
1 3 3 1  
1 1 3 3  
2  
2 1 red  
2 2 blue  

```
## Output


```
blue 0.00000000  
white 20.00000000  

```
## Input


```
5 5  
5  
1 1 2 2  
2 2 4 2  
4 2 4 4  
4 4 2 4  
2 4 2 2  
2  
3 3 black  
3 3 green  

```
## Output


```
green 4.00000000  
white 21.00000000  

```
## Input


```
7 4  
9  
1 2 2 3  
2 3 3 2  
3 2 2 1  
2 1 1 2  
3 2 4 2  
4 2 5 3  
5 3 6 2  
6 2 5 1  
5 1 4 2  
2  
2 2 black  
2 2 red  

```
## Output


```
red 2.00000000  
white 26.00000000  

```
## Note

Initially the black segments painted by Anfisa can also be painted a color if any of the chosen points lays on the segment. The segments have areas equal to 0. That is why if in the final picture only parts of segments is painted some color, then the area, painted the color is equal to 0.



#### tags 

#2700 #geometry #graphs 