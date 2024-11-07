<h1 style='text-align: center;'> A. Local Extrema</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array *a*. Some element of this array *a**i* is a local minimum iff it is strictly less than both of its neighbours (that is, *a**i* < *a**i* - 1 and *a**i* < *a**i* + 1). Also the element can be called local maximum iff it is strictly greater than its neighbours (that is, *a**i* > *a**i* - 1 and *a**i* > *a**i* + 1). Since *a*1 and *a**n* have only one neighbour each, they are neither local minima nor local maxima.

An element is called a local extremum iff it is either local maximum or local minimum. Your task is to calculate the number of local extrema in the given array.

## Input

The first line contains one integer *n* (1 ≤ *n* ≤ 1000) — the number of elements in array *a*.

The second line contains *n* integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 1000) — the elements of array *a*.

## Output

Print the number of local extrema in the given array.

## Examples

## Input


```
3  
1 2 3  

```
## Output


```
0  

```
## Input


```
4  
1 5 2 5  

```
## Output


```
2  

```


#### tags 

#800 #brute_force #implementation 