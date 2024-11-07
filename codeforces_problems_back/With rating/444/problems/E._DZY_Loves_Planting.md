<h1 style='text-align: center;'> E. DZY Loves Planting</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

DZY loves planting, and he enjoys solving tree problems.

DZY has a weighted tree (connected undirected graph without cycles) containing *n* nodes (they are numbered from 1 to *n*). He defines the function *g*(*x*, *y*) (1 ≤ *x*, *y* ≤ *n*) as the longest edge in the shortest path between nodes *x* and *y*. Specially *g*(*z*, *z*) = 0 for every *z*.

For every integer sequence *p*1, *p*2, ..., *p**n* (1 ≤ *p**i* ≤ *n*), DZY defines *f*(*p*) as ![](images/43f9546e58d8d927384c8167f4683c5de48d9760.png). 

DZY wants to find such a sequence *p* that *f*(*p*) has maximum possible value. But there is one more restriction: the element *j* can appear in *p* at most *x**j* times.

Please, find the maximum possible *f*(*p*) under the described restrictions.

## Input

The first line contains an integer *n* (1 ≤ *n* ≤ 3000).

Each of the next *n* - 1 lines contains three integers *a**i*, *b**i*, *c**i* (1 ≤ *a**i*, *b**i* ≤ *n*; 1 ≤ *c**i* ≤ 10000), denoting an edge between *a**i* and *b**i* with length *c**i*. It is guaranteed that these edges form a tree.

Each of the next *n* lines describes an element of sequence *x*. The *j*-th line contains an integer *x**j* (1 ≤ *x**j* ≤ *n*).

## Output

Print a single integer representing the answer.

## Examples

## Input


```
4  
1 2 1  
2 3 2  
3 4 3  
1  
1  
1  
1  

```
## Output


```
2  

```
## Input


```
4  
1 2 1  
2 3 2  
3 4 3  
4  
4  
4  
4  

```
## Output


```
3  

```
## Note

In the first sample, one of the optimal *p* is [4, 3, 2, 1].



#### tags 

#2700 #binary_search #dsu #trees 