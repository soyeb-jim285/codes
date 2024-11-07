<h1 style='text-align: center;'> F. Cities Excursions</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are *n* cities in Berland. Some pairs of them are connected with *m* directed roads. One can use only these roads to move from one city to another. There are no roads that connect a city to itself. For each pair of cities (*x*, *y*) there is at most one road from *x* to *y*.

A path from city *s* to city *t* is a sequence of cities *p*1, *p*2, ... , *p**k*, where *p*1 = *s*, *p**k* = *t*, and there is a road from city *p**i* to city *p**i* + 1 for each *i* from 1 to *k* - 1. The path can pass multiple times through each city except *t*. It can't pass through *t* more than once.

A path *p* from *s* to *t* is ideal if it is the lexicographically minimal such path. In other words, *p* is ideal path from *s* to *t* if for any other path *q* from *s* to *t* *p**i* < *q**i*, where *i* is the minimum integer such that *p**i* ≠ *q**i*.

There is a tourist agency in the country that offers *q* unusual excursions: the *j*-th excursion starts at city *s**j* and ends in city *t**j*. 

For each pair *s**j*, *t**j* help the agency to study the ideal path from *s**j* to *t**j*. Note that it is possible that there is no ideal path from *s**j* to *t**j*. This is possible due to two reasons: 

* there is no path from *s**j* to *t**j*;
* there are paths from *s**j* to *t**j*, but for every such path *p* there is another path *q* from *s**j* to *t**j*, such that *p**i* > *q**i*, where *i* is the minimum integer for which *p**i* ≠ *q**i*.

The agency would like to know for the ideal path from *s**j* to *t**j* the *k**j*-th city in that path (on the way from *s**j* to *t**j*).

For each triple *s**j*, *t**j*, *k**j* (1 ≤ *j* ≤ *q*) find if there is an ideal path from *s**j* to *t**j* and print the *k**j*-th city in that path, if there is any.

## Input

The first line contains three integers *n*, *m* and *q* (2 ≤ *n* ≤ 3000,0 ≤ *m* ≤ 3000, 1 ≤ *q* ≤ 4·105) — the number of cities, the number of roads and the number of excursions.

Each of the next *m* lines contains two integers *x**i* and *y**i* (1 ≤ *x**i*, *y**i* ≤ *n*, *x**i* ≠ *y**i*), denoting that the *i*-th road goes from city *x**i* to city *y**i*. All roads are one-directional. There can't be more than one road in each direction between two cities.

Each of the next *q* lines contains three integers *s**j*, *t**j* and *k**j* (1 ≤ *s**j*, *t**j* ≤ *n*, *s**j* ≠ *t**j*, 1 ≤ *k**j* ≤ 3000).

## Output

In the *j*-th line print the city that is the *k**j*-th in the ideal path from *s**j* to *t**j*. If there is no ideal path from *s**j* to *t**j*, or the integer *k**j* is greater than the length of this path, print the string '-1' (without quotes) in the *j*-th line.

## Example

## Input


```
7 7 5  
1 2  
2 3  
1 3  
3 4  
4 5  
5 3  
4 6  
1 4 2  
2 6 1  
1 7 3  
1 3 2  
1 3 5  

```
## Output


```
2  
-1  
-1  
2  
-1  

```


#### tags 

#2700 #dfs_and_similar #graphs #trees 