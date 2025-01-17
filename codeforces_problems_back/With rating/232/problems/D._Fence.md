<h1 style='text-align: center;'> D. Fence</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

John Doe has a crooked fence, consisting of *n* rectangular planks, lined up from the left to the right: the plank that goes *i*-th (1 ≤ *i* ≤ *n*) (from left to right) has width 1 and height *h**i*. We will assume that the plank that goes *i*-th (1 ≤ *i* ≤ *n*) (from left to right) has index *i*.

A piece of the fence from *l* to *r* (1 ≤ *l* ≤ *r* ≤ *n*) is a sequence of planks of wood with indices from *l* to *r* inclusive, that is, planks with indices *l*, *l* + 1, ..., *r*. The width of the piece of the fence from *l* to *r* is value *r* - *l* + 1.

Two pieces of the fence from *l*1 to *r*1 and from *l*2 to *r*2 are called matching, if the following conditions hold:

* the pieces do not intersect, that is, there isn't a single plank, such that it occurs in both pieces of the fence;
* the pieces are of the same width;
* for all *i* (0 ≤ *i* ≤ *r*1 - *l*1) the following condition holds: *h**l*1 + *i* + *h**l*2 + *i* = *h**l*1 + *h**l*2.

John chose a few pieces of the fence and now wants to know how many distinct matching pieces are for each of them. Two pieces of the fence are distinct if there is a plank, which belongs to one of them and does not belong to the other one.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 105) — the number of wood planks in the fence. The second line contains *n* space-separated integers *h*1, *h*2, ..., *h**n* (1 ≤ *h**i* ≤ 109) — the heights of fence planks.

The third line contains integer *q* (1 ≤ *q* ≤ 105) — the number of queries. Next *q* lines contain two space-separated integers *l**i* and *r**i* (1 ≤ *l**i* ≤ *r**i* ≤ *n*) — the boundaries of the *i*-th piece of the fence.

## Output

For each query on a single line print a single integer — the number of pieces of the fence that match the given one. Print the answers to the queries in the order, in which the queries are given in the input.

## Examples

## Input


```
10  
1 2 2 1 100 99 99 100 100 100  
6  
1 4  
1 2  
3 4  
1 5  
9 10  
10 10  

```
## Output


```
1  
2  
2  
0  
2  
9  

```


#### tags 

#2900 #binary_search #data_structures #string_suffix_structures 