<h1 style='text-align: center;'> B. Resort</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Valera's finally decided to go on holiday! He packed up and headed for a ski resort.

Valera's fancied a ski trip but he soon realized that he could get lost in this new place. Somebody gave him a useful hint: the resort has *n* objects (we will consider the objects indexed in some way by integers from 1 to *n*), each object is either a hotel or a mountain.

Valera has also found out that the ski resort had multiple ski tracks. Specifically, for each object *v*, the resort has at most one object *u*, such that there is a ski track built from object *u* to object *v*. We also know that no hotel has got a ski track leading from the hotel to some object.

Valera is afraid of getting lost on the resort. So he wants you to come up with a path he would walk along. The path must consist of objects *v*1, *v*2, ..., *v**k* (*k* ≥ 1) and meet the following conditions:

1. Objects with numbers *v*1, *v*2, ..., *v**k* - 1 are mountains and the object with number *v**k* is the hotel.
2. For any integer *i* (1 ≤ *i* < *k*), there is exactly one ski track leading from object *v**i*. This track goes to object *v**i* + 1.
3. The path contains as many objects as possible (*k* is maximal).

Help Valera. Find such path that meets all the criteria of our hero!

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 105) — the number of objects.

The second line contains *n* space-separated integers *type*1, *type*2, ..., *type**n* — the types of the objects. If *type**i* equals zero, then the *i*-th object is the mountain. If *type**i* equals one, then the *i*-th object is the hotel. It is guaranteed that at least one object is a hotel.

The third line of the input contains *n* space-separated integers *a*1, *a*2, ..., *a**n* (0 ≤ *a**i* ≤ *n*) — the description of the ski tracks. If number *a**i* equals zero, then there is no such object *v*, that has a ski track built from *v* to *i*. If number *a**i* doesn't equal zero, that means that there is a track built from object *a**i* to object *i*.

## Output

In the first line print *k* — the maximum possible path length for Valera. In the second line print *k* integers *v*1, *v*2, ..., *v**k* — the path. If there are multiple solutions, you can print any of them.

## Examples

## Input


```
5  
0 0 0 0 1  
0 1 2 3 4  

```
## Output


```
5  
1 2 3 4 5  

```
## Input


```
5  
0 0 1 0 1  
0 1 2 2 4  

```
## Output


```
2  
4 5  

```
## Input


```
4  
1 0 0 0  
2 3 4 2  

```
## Output


```
1  
1  

```


#### tags 

#1500 #graphs 