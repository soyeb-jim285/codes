<h1 style='text-align: center;'> C. Three Base Stations</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The New Vasjuki village is stretched along the motorway and that's why every house on it is characterized by its shift relative to some fixed point — the *x**i* coordinate. The village consists of *n* houses, the *i*-th house is located in the point with coordinates of *x**i*.

TELE3, a cellular communication provider planned to locate three base stations so as to provide every house in the village with cellular communication. The base station having power *d* located in the point *t* provides with communication all the houses on the segment [*t* - *d*, *t* + *d*] (including boundaries).

To simplify the integration (and simply not to mix anything up) all the three stations are planned to possess the equal power of *d*. Which minimal value of *d* is enough to provide all the houses in the village with cellular communication.

## Input

The first line contains an integer *n* (1 ≤ *n* ≤ 2·105) which represents the number of houses in the village. The second line contains the coordinates of houses — the sequence *x*1, *x*2, ..., *x**n* of integer numbers (1 ≤ *x**i* ≤ 109). It is possible that two or more houses are located on one point. The coordinates are given in a arbitrary order.

## Output

Print the required minimal power *d*. In the second line print three numbers — the possible coordinates of the base stations' location. Print the coordinates with 6 digits after the decimal point. The positions of the stations can be any from 0 to 2·109 inclusively. It is accepted for the base stations to have matching coordinates. If there are many solutions, print any of them.

## Examples

## Input


```
4  
1 2 3 4  

```
## Output


```
0.500000  
1.500000 2.500000 3.500000  

```
## Input


```
3  
10 20 30  

```
## Output


```
0  
10.000000 20.000000 30.000000  

```
## Input


```
5  
10003 10004 10001 10002 1  

```
## Output


```
0.500000  
1.000000 10001.500000 10003.500000  

```


#### tags 

#1800 #binary_search #greedy 