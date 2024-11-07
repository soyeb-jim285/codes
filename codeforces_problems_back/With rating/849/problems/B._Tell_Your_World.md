<h1 style='text-align: center;'> B. Tell Your World</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Connect the countless points with lines, till we reach the faraway yonder.

There are *n* points on a coordinate plane, the *i*-th of which being (*i*, *y**i*).

Determine whether it's possible to draw two parallel and non-overlapping lines, such that every point in the set lies on exactly one of them, and each of them passes through at least one point in the set.

## Input

The first line of input contains a positive integer *n* (3 ≤ *n* ≤ 1 000) — the number of points.

The second line contains *n* space-separated integers *y*1, *y*2, ..., *y**n* ( - 109 ≤ *y**i* ≤ 109) — the vertical coordinates of each point.

## Output

## Output

 "Yes" (without quotes) if it's possible to fulfill the requirements, and "No" otherwise.

You can print each letter in any case (upper or lower).

## Examples

## Input


```
5  
7 5 8 6 9  

```
## Output


```
Yes  

```
## Input


```
5  
-1 -2 0 0 -5  

```
## Output


```
No  

```
## Input


```
5  
5 4 3 2 1  

```
## Output


```
No  

```
## Input


```
5  
1000000000 0 0 0 0  

```
## Output


```
Yes  

```
## Note

In the first example, there are five points: (1, 7), (2, 5), (3, 8), (4, 6) and (5, 9). It's possible to draw a line that passes through points 1, 3, 5, and another one that passes through points 2, 4 and is parallel to the first one.

In the second example, while it's possible to draw two lines that cover all points, they cannot be made parallel.

In the third example, it's impossible to satisfy both requirements at the same time.



#### tags 

#1600 #brute_force #geometry 