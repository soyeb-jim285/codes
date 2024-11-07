<h1 style='text-align: center;'> B. Squares and Segments</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Little Sofia is in fourth grade. Today in the geometry lesson she learned about segments and squares. On the way home, she decided to draw $n$ squares in the snow with a side length of $1$. For simplicity, we assume that Sofia lives on a plane and can draw only segments of length $1$, parallel to the coordinate axes, with vertices at integer points.

In order to draw a segment, Sofia proceeds as follows. If she wants to draw a vertical segment with the coordinates of the ends $(x, y)$ and $(x, y+1)$. Then Sofia looks if there is already a drawn segment with the coordinates of the ends $(x', y)$ and $(x', y+1)$ for some $x'$. If such a segment exists, then Sofia quickly draws a new segment, using the old one as a guideline. If there is no such segment, then Sofia has to take a ruler and measure a new segment for a long time. Same thing happens when Sofia wants to draw a horizontal segment, but only now she checks for the existence of a segment with the same coordinates $x$, $x+1$ and the differing coordinate $y$.

For example, if Sofia needs to draw one square, she will have to draw two segments using a ruler: 

 ![](images/26ac7de0c2ac77f962c61a0d860b6f511c7ce1ff.png) After that, she can draw the remaining two segments, using the first two as a guide: 

 ![](images/ae70996cc65f43dd87618da4e127cc62bc4ff759.png) If Sofia needs to draw two squares, she will have to draw three segments using a ruler: 

 ![](images/67fc4924fcbc58105cd38e5f21558e464df4c714.png) After that, she can draw the remaining four segments, using the first three as a guide: 

 ![](images/9ab71c1a21a5a72c86e0463454ebd9ac000ee819.png) Sofia is in a hurry, so she wants to minimize the number of segments that she will have to draw with a ruler without a guide. Help her find this minimum number.

## Input

The only line of input contains a single integer $n$ ($1 \le n \le 10^{9}$), the number of squares that Sofia wants to draw.

## Output

Print single integer, the minimum number of segments that Sofia will have to draw with a ruler without a guide in order to draw $n$ squares in the manner described above.

## Examples

## Input


```

1

```
## Output


```

2

```
## Input


```

2

```
## Output


```

3

```
## Input


```

4

```
## Output


```

4

```


#### tags 

#1100 #binary_search #constructive_algorithms #math 