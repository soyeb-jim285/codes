<h1 style='text-align: center;'> G. Non-decimal sum</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array of integers written in base *radix*. Calculate their sum and output it written in the same base.

## Input

The first line of the input contains an integer *n* (1 ≤ *n* ≤ 10) — the size of the array. The second line contains an integer *radix* (2 ≤ *radix* ≤ 36) — the base of the numeral system used. Next *n* lines contain the elements of the array, one per line. 

Each element is a non-negative integer written in *radix*-based notation, possibly with leading zeros, which contains between 1 and 5 digits, inclusive. The digits of the notation will be 0, 1, ..., 9, A, B, ..., Z in the given order. 

## Output

## Output

 the sum of array elements in *radix*-based notation. Use the same format as in the input.

## Examples

## Input


```
3  
16  
F0  
20B  
004  

```
## Output


```
2FF  

```
## Input


```
2  
10  
12  
34  

```
## Output


```
46  

```


#### tags 

#2000 #*special 