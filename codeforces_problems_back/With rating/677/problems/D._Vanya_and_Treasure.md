<h1 style='text-align: center;'> D. Vanya and Treasure</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vanya is in the palace that can be represented as a grid *n* × *m*. Each room contains a single chest, an the room located in the *i*-th row and *j*-th columns contains the chest of type *a**ij*. Each chest of type *x* ≤ *p* - 1 contains a key that can open any chest of type *x* + 1, and all chests of type 1 are not locked. There is exactly one chest of type *p* and it contains a treasure.

Vanya starts in cell (1, 1) (top left corner). What is the minimum total distance Vanya has to walk in order to get the treasure? Consider the distance between cell (*r*1, *c*1) (the cell in the row *r*1 and column *c*1) and (*r*2, *c*2) is equal to |*r*1 - *r*2| + |*c*1 - *c*2|.

## Input

The first line of the input contains three integers *n*, *m* and *p* (1 ≤ *n*, *m* ≤ 300, 1 ≤ *p* ≤ *n*·*m*) — the number of rows and columns in the table representing the palace and the number of different types of the chests, respectively.

Each of the following *n* lines contains *m* integers *a**ij* (1 ≤ *a**ij* ≤ *p*) — the types of the chests in corresponding rooms. It's guaranteed that for each *x* from 1 to *p* there is at least one chest of this type (that is, there exists a pair of *r* and *c*, such that *a**rc* = *x*). Also, it's guaranteed that there is exactly one chest of type *p*.

## Output

Print one integer — the minimum possible total distance Vanya has to walk in order to get the treasure from the chest of type *p*.

## Examples

## Input


```
3 4 3  
2 1 1 1  
1 1 1 1  
2 1 1 3  

```
## Output


```
5  

```
## Input


```
3 3 9  
1 3 5  
8 9 7  
4 6 2  

```
## Output


```
22  

```
## Input


```
3 4 12  
1 2 3 4  
8 7 6 5  
9 10 11 12  

```
## Output


```
11  

```


#### tags 

#2300 #data_structures #dp #graphs #shortest_paths 