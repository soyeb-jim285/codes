<h1 style='text-align: center;'> A. Good Number</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's call a number *k*-good if it contains all digits not exceeding *k* (0, ..., *k*). You've got a number *k* and an array *a* containing *n* numbers. Find out how many *k*-good numbers are in *a* (count each number every time it occurs in array *a*).

## Input

The first line contains integers *n* and *k* (1 ≤ *n* ≤ 100, 0 ≤ *k* ≤ 9). The *i*-th of the following *n* lines contains integer *a**i* without leading zeroes (1 ≤ *a**i* ≤ 109).

## Output

Print a single integer — the number of *k*-good numbers in *a*.

## Examples

## Input


```
10 6  
1234560  
1234560  
1234560  
1234560  
1234560  
1234560  
1234560  
1234560  
1234560  
1234560  

```
## Output


```
10  

```
## Input


```
2 1  
1  
10  

```
## Output


```
1  

```


#### tags 

#1100 #implementation 