<h1 style='text-align: center;'> B. New Year and Old Property</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The year 2015 is almost over.

Limak is a little polar bear. He has recently learnt about the binary system. He noticed that the passing year has exactly one zero in its representation in the binary system — 201510 = 111110111112. ## Note

 that he doesn't care about the number of zeros in the decimal representation.

Limak chose some interval of years. He is going to count all years from this interval that have exactly one zero in the binary representation. Can you do it faster?

Assume that all positive integers are always written without leading zeros.

## Input

The only line of the input contains two integers *a* and *b* (1 ≤ *a* ≤ *b* ≤ 1018) — the first year and the last year in Limak's interval respectively.

## Output

Print one integer – the number of years Limak will count in his chosen interval.

## Examples

## Input


```
5 10  

```
## Output


```
2  

```
## Input


```
2015 2015  

```
## Output


```
1  

```
## Input


```
100 105  

```
## Output


```
0  

```
## Input


```
72057594000000000 72057595000000000  

```
## Output


```
26  

```
## Note

In the first sample Limak's interval contains numbers 510 = 1012, 610 = 1102, 710 = 1112, 810 = 10002, 910 = 10012 and 1010 = 10102. Two of them (1012 and 1102) have the described property.



#### tags 

#1300 #bitmasks #brute_force #implementation 