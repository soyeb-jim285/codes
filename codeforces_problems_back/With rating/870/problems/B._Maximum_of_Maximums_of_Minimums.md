<h1 style='text-align: center;'> B. Maximum of Maximums of Minimums</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array *a*1, *a*2, ..., *a**n* consisting of *n* integers, and an integer *k*. You have to split the array into exactly *k* non-empty subsegments. You'll then compute the minimum integer on each subsegment, and take the maximum integer over the *k* obtained minimums. What is the maximum possible integer you can get?

Definitions of subsegment and array splitting are given in notes.

## Input

The first line contains two integers *n* and *k* (1 ≤ *k* ≤ *n* ≤  105) — the size of the array *a* and the number of subsegments you have to split the array to.

The second line contains *n* integers *a*1,  *a*2,  ...,  *a**n* ( - 109  ≤  *a**i* ≤  109).

## Output

Print single integer — the maximum possible integer you can get if you split the array into *k* non-empty subsegments and take maximum of minimums on the subsegments.

## Examples

## Input


```
5 2  
1 2 3 4 5  

```
## Output


```
5  

```
## Input


```
5 1  
-4 -5 -3 -2 -1  

```
## Output


```
-5  

```
## Note

A subsegment [*l*,  *r*] (*l* ≤ *r*) of array *a* is the sequence *a**l*,  *a**l* + 1,  ...,  *a**r*.

Splitting of array *a* of *n* elements into *k* subsegments [*l*1, *r*1], [*l*2, *r*2], ..., [*l**k*, *r**k*] (*l*1 = 1, *r**k* = *n*, *l**i* = *r**i* - 1 + 1 for all *i* > 1) is *k* sequences (*a**l*1, ..., *a**r*1), ..., (*a**l**k*, ..., *a**r**k*).

In the first example you should split the array into subsegments [1, 4] and [5, 5] that results in sequences (1, 2, 3, 4) and (5). The minimums are *min*(1, 2, 3, 4) = 1 and *min*(5) = 5. The resulting maximum is *max*(1, 5) = 5. It is obvious that you can't reach greater result.

In the second example the only option you have is to split the array into one subsegment [1, 5], that results in one sequence ( - 4,  - 5,  - 3,  - 2,  - 1). The only minimum is *min*( - 4,  - 5,  - 3,  - 2,  - 1) =  - 5. The resulting maximum is  - 5.



#### tags 

#1200 #greedy 