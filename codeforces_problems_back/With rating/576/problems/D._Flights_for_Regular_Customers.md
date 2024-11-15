<h1 style='text-align: center;'> D. Flights for Regular Customers</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In the country there are exactly *n* cities numbered with positive integers from 1 to *n*. In each city there is an airport is located.

Also, there is the only one airline, which makes *m* flights. Unfortunately, to use them, you need to be a regular customer of this company, namely, you have the opportunity to enjoy flight *i* from city *a**i* to city *b**i* only if you have already made at least *d**i* flights before that.

Please note that flight *i* flies exactly from city *a**i* to city *b**i*. It can not be used to fly from city *b**i* to city *a**i*. An interesting fact is that there may possibly be recreational flights with a beautiful view of the sky, which begin and end in the same city.

You need to get from city 1 to city *n*. Unfortunately, you've never traveled by plane before. What minimum number of flights you have to perform in order to get to city *n*?

Note that the same flight can be used multiple times.

## Input

The first line contains two integers, *n* and *m* (2 ≤ *n* ≤ 150, 1 ≤ *m* ≤ 150) — the number of cities in the country and the number of flights the company provides.

Next *m* lines contain numbers *a**i*, *b**i*, *d**i* (1 ≤ *a**i*, *b**i* ≤ *n*, 0 ≤ *d**i* ≤ 109), representing flight number *i* from city *a**i* to city *b**i*, accessible to only the clients who have made at least *d**i* flights. 

## Output

Print "Impossible" (without the quotes), if it is impossible to get from city 1 to city *n* using the airways.

But if there is at least one way, print a single integer — the minimum number of flights you need to make to get to the destination point.

## Examples

## Input


```
3 2  
1 2 0  
2 3 1  

```
## Output


```
2  

```
## Input


```
2 1  
1 2 100500  

```
## Output


```
Impossible  

```
## Input


```
3 3  
2 1 0  
2 3 6  
1 2 0  

```
## Output


```
8  

```


#### tags 

#2700 #dp #matrices 