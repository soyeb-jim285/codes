<h1 style='text-align: center;'> A. Sorting Railway Cars</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

An infinitely long railway has a train consisting of *n* cars, numbered from 1 to *n* (the numbers of all the cars are distinct) and positioned in arbitrary order. David Blaine wants to sort the railway cars in the order of increasing numbers. In one move he can make one of the cars disappear from its place and teleport it either to the beginning of the train, or to the end of the train, at his desire. What is the minimum number of actions David Blaine needs to perform in order to sort the train?

## Input

The first line of the input contains integer *n* (1 ≤ *n* ≤ 100 000) — the number of cars in the train. 

The second line contains *n* integers *p**i* (1 ≤ *p**i* ≤ *n*, *p**i* ≠ *p**j* if *i* ≠ *j*) — the sequence of the numbers of the cars in the train.

## Output

Print a single integer — the minimum number of actions needed to sort the railway cars.

## Examples

## Input


```
5  
4 1 2 5 3  

```
## Output


```
2  

```
## Input


```
4  
4 1 3 2  

```
## Output


```
2  

```
## Note

In the first sample you need first to teleport the 4-th car, and then the 5-th car to the end of the train.



#### tags 

#1600 #constructive_algorithms #greedy 