<h1 style='text-align: center;'> C. Berland Traffic</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Berland traffic is very different from traffic in other countries. The capital of Berland consists of *n* junctions and *m* roads. Each road connects a pair of junctions. There can be multiple roads between a pair of junctions. For each road we know its capacity: value *c**i* is the maximum number of cars that can drive along a road in any direction per a unit of time. For each road, the cars can drive along it in one of two direction. That it, the cars can't simultaneously move in both directions. A road's traffic is the number of cars that goes along it per a unit of time. For road (*a**i*, *b**i*) this value is negative, if the traffic moves from *b**i* to *a**i*. A road's traffic can be a non-integer number.

The capital has two special junctions — the entrance to the city (junction 1) and the exit from the city (junction *n*). For all other junctions it is true that the traffic is not lost there. That is, for all junctions except for 1 and *n* the incoming traffic sum equals the outgoing traffic sum.

Traffic has an unusual peculiarity in the capital of Berland — for any pair of junctions (*x*, *y*) the sum of traffics along any path from *x* to *y* doesn't change depending on the choice of the path. Such sum includes traffic along all roads on the path (possible with the "minus" sign, if the traffic along the road is directed against the direction of the road on the path from *x* to *y*).

Your task is to find the largest traffic that can pass trough the city per one unit of time as well as the corresponding traffic for each road. 

## Input

The first line contains a positive integer *n* — the number of junctions (2 ≤ *n* ≤ 100). The second line contains integer *m* (1 ≤ *m* ≤ 5000) — the number of roads. Next *m* lines contain the roads' descriptions. Each road contains a group of three numbers *a**i*, *b**i*, *c**i*, where *a**i*, *b**i* are the numbers of junctions, connected by the given road, and *c**i* (1 ≤ *a**i*, *b**i* ≤ *n*; *a**i* ≠ *b**i*; 0 ≤ *c**i* ≤ 10000) is the largest permissible traffic along this road.

## Output

In the first line print the required largest traffic across the city. Then print *m* lines, on each line print the speed, at which the traffic moves along the corresponding road. If the direction doesn't match the order of the junctions, given in the input, then print the traffic with the minus sign. Print the numbers with accuracy of at least five digits after the decimal point.

If there are many optimal solutions, print any of them.

## Examples

## Input


```
2  
3  
1 2 2  
1 2 4  
2 1 1000  

```
## Output


```
6.00000  
2.00000  
2.00000  
-2.00000  

```
## Input


```
7  
11  
1 2 7  
1 2 7  
1 3 7  
1 4 7  
2 3 7  
2 5 7  
3 6 7  
4 7 7  
5 4 7  
5 6 7  
6 7 7  

```
## Output


```
13.00000  
2.00000  
2.00000  
3.00000  
6.00000  
1.00000  
3.00000  
4.00000  
7.00000  
1.00000  
2.00000  
6.00000  

```


#### tags 

#2700 #math #matrices 