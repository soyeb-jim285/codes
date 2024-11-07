<h1 style='text-align: center;'> A. Juicer</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Kolya is going to make fresh orange juice. He has *n* oranges of sizes *a*1, *a*2, ..., *a**n*. Kolya will put them in the juicer in the fixed order, starting with orange of size *a*1, then orange of size *a*2 and so on. To be put in the juicer the orange must have size not exceeding *b*, so if Kolya sees an orange that is strictly greater he throws it away and continues with the next one.

The juicer has a special section to collect waste. It overflows if Kolya squeezes oranges of the total size strictly greater than *d*. When it happens Kolya empties the waste section (even if there are no more oranges) and continues to squeeze the juice. How many times will he have to empty the waste section?

## Input

The first line of the input contains three integers *n*, *b* and *d* (1 ≤ *n* ≤ 100 000, 1 ≤ *b* ≤ *d* ≤ 1 000 000) — the number of oranges, the maximum size of the orange that fits in the juicer and the value *d*, which determines the condition when the waste section should be emptied.

The second line contains *n* integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 1 000 000) — sizes of the oranges listed in the order Kolya is going to try to put them in the juicer.

## Output

Print one integer — the number of times Kolya will have to empty the waste section.

## Examples

## Input


```
2 7 10  
5 6  

```
## Output


```
1  

```
## Input


```
1 5 10  
7  

```
## Output


```
0  

```
## Input


```
3 10 10  
5 7 7  

```
## Output


```
1  

```
## Input


```
1 1 1  
1  

```
## Output


```
0  

```
## Note

In the first sample, Kolya will squeeze the juice from two oranges and empty the waste section afterwards.

In the second sample, the orange won't fit in the juicer so Kolya will have no juice at all.



#### tags 

#900 #implementation 