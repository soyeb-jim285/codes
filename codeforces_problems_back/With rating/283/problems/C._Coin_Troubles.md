<h1 style='text-align: center;'> C. Coin Troubles</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In the Isle of Guernsey there are *n* different types of coins. For each *i* (1 ≤ *i* ≤ *n*), coin of type *i* is worth *a**i* cents. It is possible that *a**i* = *a**j* for some *i* and *j* (*i* ≠ *j*). 

Bessie has some set of these coins totaling *t* cents. She tells Jessie *q* pairs of integers. For each *i* (1 ≤ *i* ≤ *q*), the pair *b**i*, *c**i* tells Jessie that Bessie has a strictly greater number of coins of type *b**i* than coins of type *c**i*. It is known that all *b**i* are distinct and all *c**i* are distinct. 

Help Jessie find the number of possible combinations of coins Bessie could have. Two combinations are considered different if there is some *i* (1 ≤ *i* ≤ *n*), such that the number of coins Bessie has of type *i* is different in the two combinations. Since the answer can be very large, output it modulo 1000000007 (109 + 7). 

If there are no possible combinations of coins totaling *t* cents that satisfy Bessie's conditions, output 0.

## Input

The first line contains three space-separated integers, *n*, *q* and *t* (1 ≤ *n* ≤ 300; 0 ≤ *q* ≤ *n*; 1 ≤ *t* ≤ 105). The second line contains *n* space separated integers, *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 105). The next *q* lines each contain two distinct space-separated integers, *b**i* and *c**i* (1 ≤ *b**i*, *c**i* ≤ *n*; *b**i* ≠ *c**i*).

It's guaranteed that all *b**i* are distinct and all *c**i* are distinct.

## Output

A single integer, the number of valid coin combinations that Bessie could have, modulo 1000000007 (109 + 7).

## Examples

## Input


```
4 2 17  
3 1 2 5  
4 2  
3 4  

```
## Output


```
3  

```
## Input


```
3 2 6  
3 1 1  
1 2  
2 3  

```
## Output


```
0  

```
## Input


```
3 2 10  
1 2 3  
1 2  
2 1  

```
## Output


```
0  

```
## Note

For the first sample, the following 3 combinations give a total of 17 cents and satisfy the given conditions: {0 *of* *type* 1, 1 *of* *type* 2, 3 *of* *type* 3, 2 *of* *type* 4}, {0, 0, 6, 1}, {2, 0, 3, 1}.

No other combinations exist. ## Note

 that even though 4 occurs in both *b**i* and *c**i*,  the problem conditions are still satisfied because all *b**i* are distinct and all *c**i* are distinct.



#### tags 

#2100 #dp 