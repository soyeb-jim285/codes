<h1 style='text-align: center;'> E. New Year and Entity Enumeration</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an integer *m*.

Let *M* = 2*m* - 1.

You are also given a set of *n* integers denoted as the set *T*. The integers will be provided in base 2 as *n* binary strings of length *m*.

A set of integers *S* is called "good" if the following hold. 

1. If ![](images/bdd92a4ea989f8b02242b10d20f3e6651768d36d.png), then ![](images/2b05e10a1bcd048ade555b1e19b7601ab4b57e8f.png).
2. If ![](images/2fedfcf521d51216800061f2361f0f6777c812d6.png), then ![](images/7a9c4a51c69b64343f8136f1f16fb82617af2211.png)
3. ![](images/c9ceda490b02c44459a71f3fcf17855765b850f0.png)
4. All elements of *S* are less than or equal to *M*.

Here, ![](images/710f28a2927ce8a5a35e7f62fe8d16bc2c056701.png) and ![](images/cbf1449cb059fc2e0b4064ebe09922035532005c.png) refer to the bitwise XOR and bitwise AND operators, respectively.

Count the number of good sets *S*, modulo 109 + 7.

## Input

The first line will contain two integers *m* and *n* (1 ≤ *m* ≤ 1 000, 1 ≤ *n* ≤ *min*(2*m*, 50)).

The next *n* lines will contain the elements of *T*. Each line will contain exactly *m* zeros and ones. Elements of *T* will be distinct.

## Output

Print a single integer, the number of good sets modulo 109 + 7. 

## Examples

## Input


```
5 3  
11010  
00101  
11000  

```
## Output


```
4  

```
## Input


```
30 2  
010101010101010010101010101010  
110110110110110011011011011011  

```
## Output


```
860616440  

```
## Note

An example of a valid set *S* is {00000, 00101, 00010, 00111, 11000, 11010, 11101, 11111}.



#### tags 

#2500 #bitmasks #combinatorics #dp #math 