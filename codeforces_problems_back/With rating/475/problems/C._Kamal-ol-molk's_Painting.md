<h1 style='text-align: center;'> C. Kamal-ol-molk's Painting</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Rumors say that one of Kamal-ol-molk's paintings has been altered. A rectangular brush has been moved right and down on the painting.

Consider the painting as a *n* × *m* rectangular grid. At the beginning an *x* × *y* rectangular brush is placed somewhere in the frame, with edges parallel to the frame, (1 ≤ *x* ≤ *n*, 1 ≤ *y* ≤ *m*). Then the brush is moved several times. Each time the brush is moved one unit right or down. The brush has been strictly inside the frame during the painting. The brush alters every cell it has covered at some moment.

You have found one of the old Kamal-ol-molk's paintings. You want to know if it's possible that it has been altered in described manner. If yes, you also want to know minimum possible area of the brush. 

## Input

The first line of input contains two integers *n* and *m*, (1 ≤ *n*, *m* ≤ 1000), denoting the height and width of the painting.

The next *n* lines contain the painting. Each line has *m* characters. Character 'X' denotes an altered cell, otherwise it's showed by '.'. There will be at least one altered cell in the painting.

## Output

Print the minimum area of the brush in a line, if the painting is possibly altered, otherwise print  - 1.

## Examples

## Input


```
4 4  
XX..  
XX..  
XXXX  
XXXX  

```
## Output


```
4  

```
## Input


```
4 4  
....  
.XXX  
.XXX  
....  

```
## Output


```
2  

```
## Input


```
4 5  
XXXX.  
XXXX.  
.XX..  
.XX..  

```
## Output


```
-1  

```


#### tags 

#2100 #brute_force #constructive_algorithms #greedy 