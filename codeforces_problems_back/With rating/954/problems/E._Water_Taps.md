<h1 style='text-align: center;'> E. Water Taps</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Consider a system of *n* water taps all pouring water into the same container. The *i*-th water tap can be set to deliver any amount of water from 0 to *a**i* ml per second (this amount may be a real number). The water delivered by *i*-th tap has temperature *t**i*.

If for every ![](images/29cd41d3b7a01103f80f7f1a061fdf146ffa49b1.png) you set *i*-th tap to deliver exactly *x**i* ml of water per second, then the resulting temperature of water will be ![](images/80ff149d627e36b02eb3a7af6ef4c83c177753f1.png) (if ![](images/b3732be77fa6132294370a6abded03dbe6bec83a.png), then to avoid division by zero we state that the resulting water temperature is 0).

You have to set all the water taps in such a way that the resulting temperature is exactly *T*. What is the maximum amount of water you may get per second if its temperature has to be *T*?

## Input

The first line contains two integers *n* and *T* (1 ≤ *n* ≤ 200000, 1 ≤ *T* ≤ 106) — the number of water taps and the desired temperature of water, respectively.

The second line contains *n* integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 106) where *a**i* is the maximum amount of water *i*-th tap can deliver per second.

The third line contains *n* integers *t*1, *t*2, ..., *t**n* (1 ≤ *t**i* ≤ 106) — the temperature of water each tap delivers.

## Output

Print the maximum possible amount of water with temperature exactly *T* you can get per second (if it is impossible to obtain water with such temperature, then the answer is considered to be 0).

Your answer is considered correct if its absolute or relative error doesn't exceed 10- 6.

## Examples

## Input


```
2 100  
3 10  
50 150  

```
## Output


```
6.000000000000000  

```
## Input


```
3 9  
5 5 30  
6 6 10  

```
## Output


```
40.000000000000000  

```
## Input


```
2 12  
1 3  
10 15  

```
## Output


```
1.666666666666667  

```


#### tags 

#2000 #binary_search #greedy #sortings 