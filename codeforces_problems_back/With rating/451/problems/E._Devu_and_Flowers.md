<h1 style='text-align: center;'> E. Devu and Flowers</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Devu wants to decorate his garden with flowers. He has purchased *n* boxes, where the *i*-th box contains *f**i* flowers. All flowers in a single box are of the same color (hence they are indistinguishable). Also, no two boxes have flowers of the same color.

Now Devu wants to select exactly *s* flowers from the boxes to decorate his garden. Devu would like to know, in how many different ways can he select the flowers from each box? Since this number may be very large, he asks you to find the number modulo (109 + 7). 

Devu considers two ways different if there is at least one box from which different number of flowers are selected in these two ways.

## Input

The first line of input contains two space-separated integers *n* and *s* (1 ≤ *n* ≤ 20, 0 ≤ *s* ≤ 1014).

The second line contains *n* space-separated integers *f*1, *f*2, ... *f**n* (0 ≤ *f**i* ≤ 1012).

## Output

## Output

 a single integer — the number of ways in which Devu can select the flowers modulo (109 + 7).

## Examples

## Input


```
2 3  
1 3  

```
## Output


```
2  

```
## Input


```
2 4  
2 2  

```
## Output


```
1  

```
## Input


```
3 5  
1 3 2  

```
## Output


```
3  

```
## Note

Sample 1. There are two ways of selecting 3 flowers: {1, 2} and {0, 3}.

Sample 2. There is only one way of selecting 4 flowers: {2, 2}.

Sample 3. There are three ways of selecting 5 flowers: {1, 2, 2}, {0, 3, 2}, and {1, 3, 1}.



#### tags 

#2300 #bitmasks #combinatorics #number_theory 