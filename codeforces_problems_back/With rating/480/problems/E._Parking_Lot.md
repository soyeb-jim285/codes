<h1 style='text-align: center;'> E. Parking Lot</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Petya's been bored at work and he is killing the time by watching the parking lot at the office. The parking lot looks from above like an *n* × *m* table (a cell of the table corresponds to a single parking spot). Some spots in the parking lot are taken, others are empty.

Petya watches cars riding into the parking lot one by one. After a car settles down at the parking spot, Petya amuzes himself by counting what maximum square of empty spots (i.e. a square subtable) can be seen on the parking lot if we look at it from above. Also, he takes notes of the square's size (side length) in his notebook. 

You task is: given the state of the parking lot at the initial moment of time and the information about where the arriving cars park, restore what Petya wrote in his notebook. It is midday, so nobody leaves the lot.

## Input

The first line contains three integers *n*, *m* and *k* — the sizes of the parking lot and the number of arriving cars after Petya started his watch (1 ≤ *n*, *m*, *k* ≤ 2000). Each of the following *n* lines contains *m* characters 'X' and '.', where 'X' means a taken spot and '.' means an empty spot. Each of the next *k* lines contains a pair of integers *x**i*, *y**i* — the number of row and column of the spot the corresponding car takes (1 ≤ *x**i* ≤ *n*, 1 ≤ *y**i* ≤ *m*). It is guaranteed that this place was empty. You can assume that a car enters a parking lot only after the previous car successfully finds a spot.

## Output

Print *k* integers — the length of the side of the maximum square of empty spots after the corresponding car has entered the parking lot.

## Examples

## Input


```
7 8 4  
........  
X.....X.  
........  
........  
.X......  
........  
........  
1 5  
6 4  
3 5  
4 6  

```
## Output


```
5  
4  
4  
3  

```


#### tags 

#2800 #data_structures #divide_and_conquer 