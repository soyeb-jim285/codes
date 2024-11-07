<h1 style='text-align: center;'> D. Varying Kibibits</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given *n* integers *a*1, *a*2, ..., *a**n*. Denote this list of integers as *T*.

Let *f*(*L*) be a function that takes in a non-empty list of integers *L*.

The function will output another integer as follows: 

* First, all integers in *L* are padded with leading zeros so they are all the same length as the maximum length number in *L*.
* We will construct a string where the *i*-th character is the minimum of the *i*-th character in padded input numbers.
* The output is the number representing the string interpreted in base 10.

For example *f*(10, 9) = 0, *f*(123, 321) = 121, *f*(530, 932, 81) = 30.

Define the function 

![](images/34a509f74cbc53a043710b4c2baed78d6aeb4c3e.png) Here, ![](images/0241ed64f7f754d714cf9b2cef41ae3ac7b2cb35.png) denotes a subsequence.In other words, *G*(*x*) is the sum of squares of sum of elements of nonempty subsequences of *T* that evaluate to *x* when plugged into *f* modulo 1 000 000 007, then multiplied by *x*. The last multiplication is not modded. 

You would like to compute *G*(0), *G*(1), ..., *G*(999 999). To reduce the output size, print the value ![](images/8758e4ee150415656efb78a88beae1c6d7f1c5bb.png), where ![](images/c4b7092c0f7ce6535f2574569c98f7b3c2fe2c5f.png) denotes the bitwise XOR operator.

## Input

The first line contains the integer *n* (1 ≤ *n* ≤ 1 000 000) — the size of list *T*.

The next line contains *n* space-separated integers, *a*1, *a*2, ..., *a**n* (0 ≤ *a**i* ≤ 999 999) — the elements of the list. 

## Output

## Output

 a single integer, the answer to the problem.

## Examples

## Input


```
3  
123 321 555  

```
## Output


```
292711924  

```
## Input


```
1  
999999  

```
## Output


```
997992010006992  

```
## Input


```
10  
1 1 1 1 1 1 1 1 1 1  

```
## Output


```
28160  

```
## Note

For the first sample, the nonzero values of *G* are *G*(121) = 144 611 577, *G*(123) = 58 401 999, *G*(321) = 279 403 857, *G*(555) = 170 953 875. The bitwise XOR of these numbers is equal to 292 711 924.

For example, ![](images/53a1c46c7cd2d3d56e89fe99af6328601758b327.png), since the subsequences [123] and [123, 555] evaluate to 123 when plugged into *f*.

For the second sample, we have ![](images/330ab8a9387bb33a82877190f4439f4e9ccd8e92.png)

For the last sample, we have ![](images/0e0eeb7662af22bf04ea1a2ea669b162d53ad7ba.png), where ![](images/4f42013cbab8c31325f2cf28b60aa2ccc1cf89d3.png) is the binomial coefficient.



#### tags 

#2700 #bitmasks #dp 