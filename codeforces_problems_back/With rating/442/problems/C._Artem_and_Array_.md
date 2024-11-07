<h1 style='text-align: center;'> C. Artem and Array </h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Artem has an array of *n* positive integers. Artem decided to play with it. The game consists of *n* moves. Each move goes like this. Artem chooses some element of the array and removes it. For that, he gets *min*(*a*, *b*) points, where *a* and *b* are numbers that were adjacent with the removed number. If the number doesn't have an adjacent number to the left or right, Artem doesn't get any points. 

After the element is removed, the two parts of the array glue together resulting in the new array that Artem continues playing with. Borya wondered what maximum total number of points Artem can get as he plays this game.

## Input

The first line contains a single integer *n* (1 ≤ *n* ≤ 5·105) — the number of elements in the array. The next line contains *n* integers *a**i* (1 ≤ *a**i* ≤ 106) — the values of the array elements.

## Output

In a single line print a single integer — the maximum number of points Artem can get.

## Examples

## Input


```
5  
3 1 5 2 6  

```
## Output


```
11  

```
## Input


```
5  
1 2 3 4 5  

```
## Output


```
6  

```
## Input


```
5  
1 100 101 100 1  

```
## Output


```
102  

```


#### tags 

#2500 #data_structures #greedy 