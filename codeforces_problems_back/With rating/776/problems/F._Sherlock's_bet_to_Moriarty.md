<h1 style='text-align: center;'> F. Sherlock's bet to Moriarty</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Sherlock met Moriarty for a final battle of wits. He gave him a regular *n* sided convex polygon. In addition to it, he gave him certain diagonals to form regions on the polygon. It was guaranteed that the diagonals did not intersect in interior points.

He took each of the region and calculated its importance value. Importance value for a region formed by vertices *a*1, *a*2, ... , *a**x* of the polygon will be given by 2*a*1 + 2*a*2 + ... + 2*a**x*. Then, he sorted these regions on the basis of their importance value in ascending order. After that he assigned each region an index from 1 to *k*, where *k* is the number of regions, and index of region is its position in the sorted array calculated above.

He wants Moriarty to color the regions using not more than 20 colors, such that two regions have same color only if all the simple paths between these two regions have at least one region with color value less than the color value assigned to these regions. Simple path between two regions *f* and *h* is a sequence of regions *r*1, *r*2, ... *r**t* such that *r*1 = *f*, *r**t* = *h*, for each 1 ≤ *i* < *t* regions *r**i* and *r**i* + 1 share an edge, and *r**i* = *r**j* if and only if *i* = *j*.

Moriarty couldn't answer and asks Sherlock to solve it himself. Help Sherlock in doing so.

## Input

First line contains two integers *n* and *m* (3 ≤ *n* ≤ 100000, 0 ≤ *m* ≤ *n* - 3), the number of vertices in the polygon and the number of diagonals added.

Each of the next *m* lines contains two integers *a* and *b* (1 ≤ *a*, *b* ≤ *n*), describing a diagonal between vertices *a* and *b*. It is guaranteed that the diagonals are correct, i. e. *a* and *b* don't coincide and are not neighboring. It is guaranteed that the diagonals do not intersect.

## Output

Let the number of regions be *k*.

## Output

 *k* space-separated integers, each between 1 and 20, representing the colors of the regions in the order of increasing importance.

If there are multiple answers, print any of them. It can be shown that at least one answer exists.

## Examples

## Input


```
4 1  
1 3  

```
## Output


```
1 2  

```
## Input


```
6 3  
1 3  
1 4  
1 5  

```
## Output


```
2 1 2 3  

```
## Note

In 2nd input, regions formed in order after sorting will be (1, 2, 3), (1, 3, 4), (1, 4, 5), (1, 5, 6), i.e, region (1, 2, 3) is first region followed by region (1, 3, 4) and so on.

So, we can color regions 1 and 3 with same color, as region number 2 is on the path from 1 to 3 and it has color 1 which is less than color of 1 and 3, i.e., color number 2.



#### tags 

#2800 #constructive_algorithms #data_structures #divide_and_conquer #geometry #graphs #implementation #trees 