<h1 style='text-align: center;'> B. Datatypes</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Tattah's youngest brother, Tuftuf, is new to programming.

Since his older brother is such a good programmer, his biggest dream is to outshine him. Tuftuf is a student at the German University in Cairo (GUC) where he learns to write programs in Gava.

Today, Tuftuf was introduced to Gava's unsigned integer datatypes. Gava has *n* unsigned integer datatypes of sizes (in bits) *a*1, *a*2, ... *a**n*. The *i*-th datatype have size *a**i* bits, so it can represent every integer between 0 and 2*a**i* - 1 inclusive. 

Tuftuf is thinking of learning a better programming language. If there exists an integer *x*, such that *x* fits in some type *i* (in *a**i* bits) and *x*·*x* does not fit in some other type *j* (in *a**j* bits) where *a**i* < *a**j*, then Tuftuf will stop using Gava.

Your task is to determine Tuftuf's destiny.

## Input

The first line contains integer *n* (2 ≤ *n* ≤ 105) — the number of Gava's unsigned integer datatypes' sizes. The second line contains a single-space-separated list of *n* integers (1 ≤ *a**i* ≤ 109) — sizes of datatypes in bits. Some datatypes may have equal sizes.

## Output

Print "YES" if Tuftuf will stop using Gava, and "NO" otherwise.

## Examples

## Input


```
3  
64 16 32  

```
## Output


```
NO  

```
## Input


```
4  
4 2 1 3  

```
## Output


```
YES  

```
## Note

In the second example, *x* = 7 (1112) fits in 3 bits, but *x*2 = 49 (1100012) does not fit in 4 bits.



#### tags 

#1400 #math #sortings 