<h1 style='text-align: center;'> A. Cottage Village</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 64 megabytes</h5>

A new cottage village called «Flatville» is being built in Flatland. By now they have already built in «Flatville» *n* square houses with the centres on the *Оx*-axis. The houses' sides are parallel to the coordinate axes. It's known that no two houses overlap, but they can touch each other.

The architect bureau, where Peter works, was commissioned to build a new house in «Flatville». The customer wants his future house to be on the *Оx*-axis, to be square in shape, have a side *t*, and touch at least one of the already built houses. For sure, its sides should be parallel to the coordinate axes, its centre should be on the *Ox*-axis and it shouldn't overlap any of the houses in the village.

Peter was given a list of all the houses in «Flatville». Would you help him find the amount of possible positions of the new house?

## Input

The first line of the input data contains numbers *n* and *t* (1 ≤ *n*, *t* ≤ 1000). Then there follow *n* lines, each of them contains two space-separated integer numbers: *x**i* *a**i*, where *x**i* — *x*-coordinate of the centre of the *i*-th house, and *a**i* — length of its side ( - 1000 ≤ *x**i* ≤ 1000, 1 ≤ *a**i* ≤ 1000).

## Output

## Output

 the amount of possible positions of the new house.

## Examples

## Input


```
2 2  
0 4  
6 2  

```
## Output


```
4  

```
## Input


```
2 2  
0 4  
5 2  

```
## Output


```
3  

```
## Input


```
2 3  
0 4  
5 2  

```
## Output


```
2  

```
## Note

It is possible for the *x*-coordinate of the new house to have non-integer value.



#### tags 

#1200 #implementation #sortings 