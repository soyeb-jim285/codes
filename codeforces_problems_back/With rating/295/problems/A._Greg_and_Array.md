<h1 style='text-align: center;'> A. Greg and Array</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Greg has an array *a* = *a*1, *a*2, ..., *a**n* and *m* operations. Each operation looks as: *l**i*, *r**i*, *d**i*, (1 ≤ *l**i* ≤ *r**i* ≤ *n*). To apply operation *i* to the array means to increase all array elements with numbers *l**i*, *l**i* + 1, ..., *r**i* by value *d**i*.

Greg wrote down *k* queries on a piece of paper. Each query has the following form: *x**i*, *y**i*, (1 ≤ *x**i* ≤ *y**i* ≤ *m*). That means that one should apply operations with numbers *x**i*, *x**i* + 1, ..., *y**i* to the array.

Now Greg is wondering, what the array *a* will be after all the queries are executed. Help Greg.

## Input

The first line contains integers *n*, *m*, *k* (1 ≤ *n*, *m*, *k* ≤ 105). The second line contains *n* integers: *a*1, *a*2, ..., *a**n* (0 ≤ *a**i* ≤ 105) — the initial array.

Next *m* lines contain operations, the operation number *i* is written as three integers: *l**i*, *r**i*, *d**i*, (1 ≤ *l**i* ≤ *r**i* ≤ *n*), (0 ≤ *d**i* ≤ 105).

Next *k* lines contain the queries, the query number *i* is written as two integers: *x**i*, *y**i*, (1 ≤ *x**i* ≤ *y**i* ≤ *m*).

The numbers in the lines are separated by single spaces.

## Output

On a single line print *n* integers *a*1, *a*2, ..., *a**n* — the array after executing all the queries. Separate the printed numbers by spaces.

Please, do not use the %lld specifier to read or write 64-bit integers in C++. It is preferred to use the cin, cout streams of the %I64d specifier.

## Examples

## Input


```
3 3 3  
1 2 3  
1 2 1  
1 3 2  
2 3 4  
1 2  
1 3  
2 3  

```
## Output


```
9 18 17  

```
## Input


```
1 1 1  
1  
1 1 1  
1 1  

```
## Output


```
2  

```
## Input


```
4 3 6  
1 2 3 4  
1 2 1  
2 3 2  
3 4 4  
1 2  
1 3  
2 3  
1 2  
1 3  
2 3  

```
## Output


```
5 18 31 20  

```


#### tags 

#1400 #data_structures #implementation 