<h1 style='text-align: center;'> B. Beautiful Paintings</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are *n* pictures delivered for the new exhibition. The *i*-th painting has beauty *a**i*. We know that a visitor becomes happy every time he passes from a painting to a more beautiful one.

We are allowed to arranged pictures in any order. What is the maximum possible number of times the visitor may become happy while passing all pictures from first to last? In other words, we are allowed to rearrange elements of *a* in any order. What is the maximum possible number of indices *i* (1 ≤ *i* ≤ *n* - 1), such that *a**i* + 1 > *a**i*.

## Input

The first line of the input contains integer *n* (1 ≤ *n* ≤ 1000) — the number of painting.

The second line contains the sequence *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 1000), where *a**i* means the beauty of the *i*-th painting.

## Output

Print one integer — the maximum possible number of neighbouring pairs, such that *a**i* + 1 > *a**i*, after the optimal rearrangement.

## Examples

## Input


```
5  
20 30 10 50 40  

```
## Output


```
4  

```
## Input


```
4  
200 100 100 200  

```
## Output


```
2  

```
## Note

In the first sample, the optimal order is: 10, 20, 30, 40, 50.

In the second sample, the optimal order is: 100, 200, 100, 200.



#### tags 

#1200 #greedy #sortings 