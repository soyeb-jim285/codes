<h1 style='text-align: center;'> C. Relay Race</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Furik and Rubik take part in a relay race. The race will be set up on a large square with the side of *n* meters. The given square is split into *n* × *n* cells (represented as unit squares), each cell has some number.

At the beginning of the race Furik stands in a cell with coordinates (1, 1), and Rubik stands in a cell with coordinates (*n*, *n*). Right after the start Furik runs towards Rubik, besides, if Furik stands at a cell with coordinates (*i*, *j*), then he can move to cell (*i* + 1, *j*) or (*i*, *j* + 1). After Furik reaches Rubik, Rubik starts running from cell with coordinates (*n*, *n*) to cell with coordinates (1, 1). If Rubik stands in cell (*i*, *j*), then he can move to cell (*i* - 1, *j*) or (*i*, *j* - 1). Neither Furik, nor Rubik are allowed to go beyond the boundaries of the field; if a player goes beyond the boundaries, he will be disqualified. 

To win the race, Furik and Rubik must earn as many points as possible. The number of points is the sum of numbers from the cells Furik and Rubik visited. Each cell counts only once in the sum.

Print the maximum number of points Furik and Rubik can earn on the relay race.

## Input

The first line contains a single integer (1 ≤ *n* ≤ 300). The next *n* lines contain *n* integers each: the *j*-th number on the *i*-th line *a**i*, *j* ( - 1000 ≤ *a**i*, *j* ≤ 1000) is the number written in the cell with coordinates (*i*, *j*).

## Output

On a single line print a single number — the answer to the problem. 

## Examples

## Input


```
1  
5  

```
## Output


```
5  

```
## Input


```
2  
11 14  
16 12  

```
## Output


```
53  

```
## Input


```
3  
25 16 25  
12 18 19  
11 13 8  

```
## Output


```
136  

```
## Note

Comments to the second sample: The profitable path for Furik is: (1, 1), (1, 2), (2, 2), and for Rubik: (2, 2), (2, 1), (1, 1). 

Comments to the third sample: The optimal path for Furik is: (1, 1), (1, 2), (1, 3), (2, 3), (3, 3), and for Rubik: (3, 3), (3, 2), (2, 2), (2, 1), (1, 1). The figure to the sample: 

 ![](images/a95b8b7561e9821854bc6eb6f66f52124a86f180.png)  Furik's path is marked with yellow, and Rubik's path is marked with pink.

#### tags 

#2000 #dp 