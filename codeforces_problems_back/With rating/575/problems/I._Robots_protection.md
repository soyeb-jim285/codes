<h1 style='text-align: center;'> I. Robots protection</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Company "Robots industries" produces robots for territory protection. Robots protect triangle territories — right isosceles triangles with catheti parallel to North-South and East-West directions.

Owner of some land buys and sets robots on his territory to protect it. From time to time, businessmen want to build offices on that land and want to know how many robots will guard it. You are to handle these queries. 

## Input

The first line contains integer *N* — width and height of the land, and integer *Q* — number of queries to handle.

Next *Q* lines contain queries you need to process.

Two types of queries: 

1. 1 *dir* *x* *y* *len* — add a robot to protect a triangle. Depending on the value of *dir*, the values of *x*, *y* and *len* represent a different triangle:
	* *dir* = 1: Triangle is defined by the points (*x*, *y*), (*x* + *len*, *y*), (*x*, *y* + *len*)
	* *dir* = 2: Triangle is defined by the points (*x*, *y*), (*x* + *len*, *y*), (*x*, *y* - *len*)
	* *dir* = 3: Triangle is defined by the points (*x*, *y*), (*x* - *len*, *y*), (*x*, *y* + *len*)
	* *dir* = 4: Triangle is defined by the points (*x*, *y*), (*x* - *len*, *y*), (*x*, *y* - *len*)
2. 2 *x* *y* — output how many robots guard this point (robot guards a point if the point is inside or on the border of its triangle)
* 1 ≤ *N* ≤ 5000
* 1 ≤ *Q* ≤ 105
* 1 ≤ *dir* ≤ 4
* All points of triangles are within range [1, *N*]
* All numbers are positive integers
## Output

For each second type query output how many robots guard this point. Each answer should be in a separate line.

## Examples

## Input


```
17 10  
1 1 3 2 4  
1 3 10 3 7  
1 2 6 8 2  
1 3 9 4 2  
2 4 4  
1 4 15 10 6  
2 7 7  
2 9 4  
2 12 2  
2 13 8  

```
## Output


```
2  
2  
2  
0  
1  

```


#### tags 

#2800 #data_structures 