<h1 style='text-align: center;'> E. Jzzhu and Squares</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Jzzhu has two integers, *n* and *m*. He calls an integer point (*x*, *y*) of a plane special if 0 ≤ *x* ≤ *n* and 0 ≤ *y* ≤ *m*. Jzzhu defines a unit square as a square with corners at points (*x*, *y*), (*x* + 1, *y*), (*x* + 1, *y* + 1), (*x*, *y* + 1), where *x* and *y* are some integers.

Let's look at all the squares (their sides not necessarily parallel to the coordinate axes) with corners at the special points. For each such square Jzzhu paints a dot in every unit square that is fully inside it. After that some unit squares can contain several dots. Now Jzzhu wonders, how many dots he has painted on the plane. Find this number modulo 1000000007 (109 + 7).

## Input

The first line contains a single integer *t* (1 ≤ *t* ≤ 105) — the number of tests.

Each of the next *t* lines contains the description of the test: two integers *n* and *m* (1 ≤ *n*, *m* ≤ 106) — the value of variables for the current test.

## Output

For each test output the total number of dots modulo 1000000007 (109 + 7).

## Examples

## Input


```
4  
1 3  
2 2  
2 5  
3 4  

```
## Output


```
3  
8  
26  
58  

```


#### tags 

#2900 #dp #math #number_theory 