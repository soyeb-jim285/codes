<h1 style='text-align: center;'> E. Meeting Her</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Urpal lives in a big city. He has planned to meet his lover tonight. 

The city has *n* junctions numbered from 1 to *n*. The junctions are connected by *m* directed streets, all the roads have equal length. Urpal lives in junction *a* and the date is planned in a restaurant in junction *b*. He wants to use public transportation to get to junction *b*. There are *k* bus transportation companies. At the beginning of every second, a bus from the *i*-th company chooses a random shortest path between junction *s**i* and junction *t**i* and passes through it. There might be no path from *s**i* to *t**i*. In that case no bus will leave from *s**i* to *t**i*. If a bus passes through a junction where Urpal stands, he can get on the bus. He can also get off the bus at any junction along the path. 

Now Urpal wants to know if it's possible to go to the date using public transportation in a finite amount of time (the time of travel is the sum of length of the traveled roads) and what is the minimum number of buses he should take in the worst case.

At any moment Urpal knows only his own position and the place where the date will be. When he gets on the bus he knows only the index of the company of this bus. Of course Urpal knows the city map and the the pairs (*s**i*, *t**i*) for each company.

Note that Urpal doesn't know buses velocity. 

## Input

The first line of the input contains four integers *n*, *m*, *a*, *b* (2 ≤ *n* ≤ 100; 0 ≤ *m* ≤ *n*·(*n* - 1); 1 ≤ *a*, *b* ≤ *n*; *a* ≠ *b*). 

The next *m* lines contain two integers each *u**i* and *v**i* (1 ≤ *u**i*, *v**i* ≤ *n*; *u**i* ≠ *v**i*) describing a directed road from junction *u**i* to junction *v**i*. All roads in the input will be distinct. 

The next line contains an integer *k* (0 ≤ *k* ≤ 100). There will be *k* lines after this, each containing two integers *s**i* and *t**i* (1 ≤ *s**i*, *t**i* ≤ *n*; *s**i* ≠ *t**i*) saying there is a bus route starting at *s**i* and ending at *t**i*. Please note that there might be no path from *s**i* to *t**i*, this case is described in the problem statement.

## Output

In the only line of output print the minimum number of buses Urpal should get on on his way in the worst case. If it's not possible to reach the destination in the worst case print -1.

## Examples

## Input


```
7 8 1 7  
1 2  
1 3  
2 4  
3 4  
4 6  
4 5  
6 7  
5 7  
3  
2 7  
1 4  
5 7  

```
## Output


```
2  

```
## Input


```
4 4 1 2  
1 2  
1 3  
2 4  
3 4  
1  
1 4  

```
## Output


```
-1  

```


#### tags 

#2600 #dp #graphs #shortest_paths 