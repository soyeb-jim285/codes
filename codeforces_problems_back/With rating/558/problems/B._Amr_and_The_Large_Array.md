<h1 style='text-align: center;'> B. Amr and The Large Array</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Amr has got a large array of size *n*. Amr doesn't like large arrays so he intends to make it smaller.

Amr doesn't care about anything in the array except the beauty of it. The beauty of the array is defined to be the maximum number of times that some number occurs in this array. He wants to choose the smallest subsegment of this array such that the beauty of it will be the same as the original array.

Help Amr by choosing the smallest subsegment possible.

## Input

The first line contains one number *n* (1 ≤ *n* ≤ 105), the size of the array.

The second line contains *n* integers *a**i* (1 ≤ *a**i* ≤ 106), representing elements of the array.

## Output

## Output

 two integers *l*, *r* (1 ≤ *l* ≤ *r* ≤ *n*), the beginning and the end of the subsegment chosen respectively.

If there are several possible answers you may output any of them. 

## Examples

## Input


```
5  
1 1 2 2 1  

```
## Output


```
1 5
```
## Input


```
5  
1 2 2 3 1  

```
## Output


```
2 3
```
## Input


```
6  
1 2 2 1 1 2  

```
## Output


```
1 5
```
## Note

A subsegment *B* of an array *A* from *l* to *r* is an array of size *r* - *l* + 1 where *B**i* = *A**l* + *i* - 1 for all 1 ≤ *i* ≤ *r* - *l* + 1



#### tags 

#1300 #implementation 