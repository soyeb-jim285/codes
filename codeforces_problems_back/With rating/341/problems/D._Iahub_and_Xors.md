<h1 style='text-align: center;'> D. Iahub and Xors</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Iahub does not like background stories, so he'll tell you exactly what this problem asks you for.

You are given a matrix *a* with *n* rows and *n* columns. Initially, all values of the matrix are zeros. Both rows and columns are 1-based, that is rows are numbered 1, 2, ..., *n* and columns are numbered 1, 2, ..., *n*. Let's denote an element on the *i*-th row and *j*-th column as *a**i*, *j*.

We will call a submatrix (*x*0, *y*0, *x*1, *y*1) such elements *a**i*, *j* for which two inequalities hold: *x*0 ≤ *i* ≤ *x*1, *y*0 ≤ *j* ≤ *y*1.

Write a program to perform two following operations:

1. Query(*x*0, *y*0, *x*1, *y*1): print the xor sum of the elements of the submatrix (*x*0, *y*0, *x*1, *y*1).
2. Update(*x*0, *y*0, *x*1, *y*1, *v*): each element from submatrix (*x*0, *y*0, *x*1, *y*1) gets xor-ed by value *v*.
## Input

The first line contains two integers: *n* (1 ≤ *n* ≤ 1000) and *m* (1 ≤ *m* ≤ 105). The number *m* represents the number of operations you need to perform. Each of the next *m* lines contains five or six integers, depending on operation type. 

If the *i*-th operation from the input is a query, the first number from *i*-th line will be 1. It will be followed by four integers *x*0, *y*0, *x*1, *y*1. If the *i*-th operation is an update, the first number from the *i*-th line will be 2. It will be followed by five integers *x*0, *y*0, *x*1, *y*1, *v*. 

It is guaranteed that for each update operation, the following inequality holds: 0 ≤ *v* < 262. It is guaranteed that for each operation, the following inequalities hold: 1 ≤ *x*0 ≤ *x*1 ≤ *n*, 1 ≤ *y*0 ≤ *y*1 ≤ *n*.

## Output

For each query operation, output on a new line the result.

## Examples

## Input


```
3 5  
2 1 1 2 2 1  
2 1 3 2 3 2  
2 3 1 3 3 3  
1 2 2 3 3  
1 2 2 3 2  

```
## Output


```
3  
2  

```
## Note

After the first 3 operations, the matrix will look like this: 


```
  
1 1 2  
1 1 2  
3 3 3  

```
The fourth operation asks us to compute 1 xor 2 xor 3 xor 3 = 3.

The fifth operation asks us to compute 1 xor 3 = 2. 



#### tags 

#2500 #data_structures 