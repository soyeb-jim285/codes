<h1 style='text-align: center;'> D. Mike and Fish</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

As everyone knows, bears love fish. But Mike is a strange bear; He hates fish! The even more strange thing about him is he has an infinite number of blue and red fish. 

 ![](images/dbb8dea3074bc8df1ea5d973bc92d77c0a470bfb.png) He has marked *n* distinct points in the plane. *i*-th point is point (*x**i*, *y**i*). He wants to put exactly one fish in each of these points such that the difference between the number of red fish and the blue fish on each horizontal or vertical line is at most 1.

He can't find a way to perform that! Please help him.

## Input

The first line of input contains integer *n* (1 ≤ *n* ≤ 2 × 105).

The next *n* lines contain the information about the points, *i*-th line contains two integers *x**i* and *y**i* (1 ≤ *x**i*, *y**i* ≤ 2 × 105), the *i*-th point coordinates.

It is guaranteed that there is at least one valid answer.

## Output

Print the answer as a sequence of *n* characters 'r' (for red) or 'b' (for blue) where *i*-th character denotes the color of the fish in the *i*-th point.

## Examples

## Input


```
4  
1 1  
1 2  
2 1  
2 2  

```
## Output


```
brrb  

```
## Input


```
3  
1 1  
1 2  
2 1  

```
## Output


```
brr  

```


#### tags 

#2600 #constructive_algorithms #dfs_and_similar #graphs 