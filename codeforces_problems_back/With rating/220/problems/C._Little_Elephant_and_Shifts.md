<h1 style='text-align: center;'> C. Little Elephant and Shifts</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The Little Elephant has two permutations *a* and *b* of length *n*, consisting of numbers from 1 to *n*, inclusive. Let's denote the *i*-th (1 ≤ *i* ≤ *n*) element of the permutation *a* as *a**i*, the *j*-th (1 ≤ *j* ≤ *n*) element of the permutation *b* — as *b**j*.

The distance between permutations *a* and *b* is the minimum absolute value of the difference between the positions of the occurrences of some number in *a* and in *b*. More formally, it's such minimum |*i* - *j*|, that *a**i* = *b**j*.

A cyclic shift number *i* (1 ≤ *i* ≤ *n*) of permutation *b* consisting from *n* elements is a permutation *b**i**b**i* + 1... *b**n**b*1*b*2... *b**i* - 1. Overall a permutation has *n* cyclic shifts.

The Little Elephant wonders, for all cyclic shifts of permutation *b*, what is the distance between the cyclic shift and permutation *a*?

## Input

The first line contains a single integer *n* (1 ≤ *n* ≤ 105) — the size of the permutations. The second line contains permutation *a* as *n* distinct numbers from 1 to *n*, inclusive. The numbers are separated with single spaces. The third line contains permutation *b* in the same format.

## Output

In *n* lines print *n* integers — the answers for cyclic shifts. Print the answers to the shifts in the order of the shifts' numeration in permutation *b*, that is, first for the 1-st cyclic shift, then for the 2-nd, and so on.

## Examples

## Input


```
2  
1 2  
2 1  

```
## Output


```
1  
0  

```
## Input


```
4  
2 1 3 4  
3 4 2 1  

```
## Output


```
2  
1  
0  
1  

```


#### tags 

#2100 #data_structures 