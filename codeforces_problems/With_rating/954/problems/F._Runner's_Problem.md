<h1 style='text-align: center;'> F. Runner's Problem</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are running through a rectangular field. This field can be represented as a matrix with 3 rows and *m* columns. (*i*, *j*) denotes a cell belonging to *i*-th row and *j*-th column.

You start in (2, 1) and have to end your path in (2, *m*). From the cell (*i*, *j*) you may advance to:

* (*i* - 1, *j* + 1) — only if *i* > 1,
* (*i*, *j* + 1), or
* (*i* + 1, *j* + 1) — only if *i* < 3.

However, there are *n* obstacles blocking your path. *k*-th obstacle is denoted by three integers *a**k*, *l**k* and *r**k*, and it forbids entering any cell (*a**k*, *j*) such that *l**k* ≤ *j* ≤ *r**k*.

You have to calculate the number of different paths from (2, 1) to (2, *m*), and print it modulo 109 + 7.

### Input

The first line contains two integers *n* and *m* (1 ≤ *n* ≤ 104, 3 ≤ *m* ≤ 1018) — the number of obstacles and the number of columns in the matrix, respectively.

Then *n* lines follow, each containing three integers *a**k*, *l**k* and *r**k* (1 ≤ *a**k* ≤ 3, 2 ≤ *l**k* ≤ *r**k* ≤ *m* - 1) denoting an obstacle blocking every cell (*a**k*, *j*) such that *l**k* ≤ *j* ≤ *r**k*. Some cells may be blocked by multiple obstacles.

### Output

Print the number of different paths from (2, 1) to (2, *m*), taken modulo 109 + 7. If it is impossible to get from (2, 1) to (2, *m*), then the number of paths is 0.

## Example

### Input


```text
2 5  
1 3 4  
2 2 3  

```
### Output


```text
2  

```


#### Tags 

#2100 #NOT OK #dp #matrices #sortings 