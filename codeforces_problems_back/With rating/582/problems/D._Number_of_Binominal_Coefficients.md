<h1 style='text-align: center;'> D. Number of Binominal Coefficients</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

For a given prime integer *p* and integers α, *A* calculate the number of pairs of integers (*n*, *k*), such that 0 ≤ *k* ≤ *n* ≤ *A* and ![](images/a4b0ae77c1b1e95e3cba7276cfb7fecdb99b4221.png) is divisible by *p*α. 

As the answer can be rather large, print the remainder of the answer moduly 109 + 7.

Let us remind you that ![](images/a4b0ae77c1b1e95e3cba7276cfb7fecdb99b4221.png) is the number of ways *k* objects can be chosen from the set of *n* objects.

## Input

The first line contains two integers, *p* and α (1 ≤ *p*, α ≤ 109, *p* is prime). 

The second line contains the decimal record of integer *A* (0 ≤ *A* < 101000) without leading zeroes.

## Output

In the single line print the answer to the problem.

## Examples

## Input


```
2 2  
7  

```
## Output


```
3  

```
## Input


```
3 1  
9  

```
## Output


```
17  

```
## Input


```
3 3  
9  

```
## Output


```
0  

```
## Input


```
2 4  
5000  

```
## Output


```
8576851  

```
## Note

In the first sample three binominal coefficients divisible by 4 are ![](images/a4c2b94fb12d1298dafcd1d14d7e1f6a47500264.png), ![](images/80436d3bb1008bf8943b41f46211501e7fea05e9.png) and ![](images/bb01b873c593007ca5b10a8897a71c4b0d7dabae.png).



#### tags 

#3300 #dp #math #number_theory 