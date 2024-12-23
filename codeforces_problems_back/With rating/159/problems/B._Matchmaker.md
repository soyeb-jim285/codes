<h1 style='text-align: center;'> B. Matchmaker</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarpus has *n* markers and *m* marker caps. Each marker is described by two numbers: *x**i* is the color and *y**i* is the diameter. Correspondingly, each cap is described by two numbers: *a**j* is the color and *b**j* is the diameter. Cap (*a**j*, *b**j*) can close marker (*x**i*, *y**i*) only if their diameters match, that is, *b**j* = *y**i*. Besides, a marker is considered to be beautifully closed, if the cap color and the marker color match, that is, *a**j* = *x**i*.

Find the way to close the maximum number of markers. If there are several such ways, then choose the one that has the maximum number of beautifully closed markers.

## Input

The first input line contains two space-separated integers *n* and *m* (1 ≤ *n*, *m* ≤ 105) — the number of markers and the number of caps, correspondingly. 

Next *n* lines describe the markers. The *i*-th line contains two space-separated integers *x**i*, *y**i* (1 ≤ *x**i*, *y**i* ≤ 1000) — the *i*-th marker's color and diameter, correspondingly.

Next *m* lines describe the caps. The *j*-th line contains two space-separated integers *a**j*, *b**j* (1 ≤ *a**j*, *b**j* ≤ 1000) — the color and diameter of the *j*-th cap, correspondingly.

## Output

Print two space-separated integers *u*, *v*, where *u* is the number of closed markers and *v* is the number of beautifully closed markers in the sought optimal way. Remember that you have to find the way to close the maximum number of markers, and if there are several such ways, you should choose the one where the number of beautifully closed markers is maximum.

## Examples

## Input


```
3 4  
1 2  
3 4  
2 4  
5 4  
2 4  
1 1  
1 2  

```
## Output


```
3 2  

```
## Input


```
2 2  
1 2  
2 1  
3 4  
5 1  

```
## Output


```
1 0  

```
## Note

In the first test sample the first marker should be closed by the fourth cap, the second marker should be closed by the first cap and the third marker should be closed by the second cap. Thus, three markers will be closed, and two of them will be beautifully closed — the first and the third markers.



#### tags 

#1100 #*special #greedy #sortings 