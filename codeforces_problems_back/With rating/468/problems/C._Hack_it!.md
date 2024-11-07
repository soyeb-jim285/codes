<h1 style='text-align: center;'> C. Hack it!</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Little X has met the following problem recently. 

Let's define *f*(*x*) as the sum of digits in decimal representation of number *x* (for example, *f*(1234) = 1 + 2 + 3 + 4). You are to calculate ![](images/3544ececd2159fbc9d8edc9ba99dbbfa79739157.png)

Of course Little X has solved this problem quickly, has locked it, and then has tried to hack others. He has seen the following C++ code: 


```
  
    ans = solve(l, r) % a;  
    if (ans <= 0)  
      ans += a;  
  

```
 This code will fail only on the test with ![](images/4b3d0d465d72291386b3afa4fd8af81c1a6a1a6e.png). You are given number *a*, help Little X to find a proper test for hack.## Input

The first line contains a single integer *a* (1 ≤ *a* ≤ 1018).

## Output

Print two integers: *l*, *r* (1 ≤ *l* ≤ *r* < 10200) — the required test data. Leading zeros aren't allowed. It's guaranteed that the solution exists.

## Examples

## Input


```
46  

```
## Output


```
1 10  

```
## Input


```
126444381000032  

```
## Output


```
2333333 2333333333333  

```


#### tags 

#2500 #binary_search #constructive_algorithms #math 