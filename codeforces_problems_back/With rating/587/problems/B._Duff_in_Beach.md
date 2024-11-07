<h1 style='text-align: center;'> B. Duff in Beach</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

While Duff was resting in the beach, she accidentally found a strange array *b*0, *b*1, ..., *b**l* - 1 consisting of *l* positive integers. This array was strange because it was extremely long, but there was another (maybe shorter) array, *a*0, ..., *a**n* - 1 that *b* can be build from *a* with formula: *b**i* = *a**i* *mod* *n* where *a* *mod* *b* denoted the remainder of dividing *a* by *b*.

 ![](images/8bd54986ad8c69685742e088fa8f8228ce35984e.png) Duff is so curious, she wants to know the number of subsequences of *b* like *b**i*1, *b**i*2, ..., *b**i**x* (0 ≤ *i*1 < *i*2 < ... < *i**x* < *l*), such that: 

* 1 ≤ *x* ≤ *k*
* For each 1 ≤ *j* ≤ *x* - 1, ![](images/8049e70898b1d8579ee1e94f4c68483c301ddfc5.png)
* For each 1 ≤ *j* ≤ *x* - 1, *b**i**j* ≤ *b**i**j* + 1. i.e this subsequence is non-decreasing.

Since this number can be very large, she want to know it modulo 109 + 7.

Duff is not a programmer, and Malek is unavailable at the moment. So she asked for your help. Please tell her this number.

## Input

The first line of input contains three integers, *n*, *l* and *k* (1 ≤ *n*, *k*, *n* × *k* ≤ 106 and 1 ≤ *l* ≤ 1018).

The second line contains *n* space separated integers, *a*0, *a*1, ..., *a**n* - 1 (1 ≤ *a**i* ≤ 109 for each 0 ≤ *i* ≤ *n* - 1). 

## Output

Print the answer modulo 1 000 000 007 in one line.

## Examples

## Input


```
3 5 3  
5 9 1  

```
## Output


```
10  

```
## Input


```
5 10 3  
1 2 3 4 5  

```
## Output


```
25  

```
## Note

In the first sample case, ![](images/d9d8fe92937aeef2bcddb9d213e5587f0f950087.png). So all such sequences are: ![](images/54d7dd513b50dae3415992b37dcf6f8ff2f24a73.png), ![](images/fcd7414fd5b0b1459adc9dafca95e6d5a23b0d7d.png), ![](images/f6d2e0d0317c10a3c5213068fb1d1e1f53ff26eb.png), ![](images/8f6627cad3dd113f47d84a1226f30fe423939757.png), ![](images/c6db71d99107f752b5caa1ba7e44af1d2302e5db.png), ![](images/a06ffb7bf9126fd634a790703c0bbfda00c60aa1.png), ![](images/b086d545b6c80640ea8558920709e3c51ba3bf43.png), ![](images/661b7811fccac48a9e96733bc99c3dfec93ad6d7.png), ![](images/8756896f0d00888771e69f1a9ccddeee19d4a9ab.png) and ![](images/e771f8119b1b8218c875759aa03e38312514c9a2.png).



#### tags 

#2100 #dp 