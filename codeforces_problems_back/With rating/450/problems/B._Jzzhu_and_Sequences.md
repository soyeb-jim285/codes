<h1 style='text-align: center;'> B. Jzzhu and Sequences</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Jzzhu has invented a kind of sequences, they meet the following property:

![](images/c84e959b7fd00c2ebce39e2b33db6bdb624ba8f3.png)You are given *x* and *y*, please calculate *f**n* modulo 1000000007 (109 + 7).

## Input

The first line contains two integers *x* and *y* (|*x*|, |*y*| ≤ 109). The second line contains a single integer *n* (1 ≤ *n* ≤ 2·109).

## Output

## Output

 a single integer representing *f**n* modulo 1000000007 (109 + 7).

## Examples

## Input


```
2 3  
3  

```
## Output


```
1  

```
## Input


```
0 -1  
2  

```
## Output


```
1000000006  

```
## Note

In the first sample, *f*2 = *f*1 + *f*3, 3 = 2 + *f*3, *f*3 = 1.

In the second sample, *f*2 =  - 1;  - 1 modulo (109 + 7) equals (109 + 6).



#### tags 

#1300 #implementation #math 