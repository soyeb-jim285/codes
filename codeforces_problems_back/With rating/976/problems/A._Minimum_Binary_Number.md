<h1 style='text-align: center;'> A. Minimum Binary Number</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

String can be called correct if it consists of characters "0" and "1" and there are no redundant leading zeroes. Here are some examples: "0", "10", "1001".

You are given a correct string *s*.

You can perform two different operations on this string: 

1. swap any pair of adjacent characters (for example, "101" ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) "110");
2. replace "11" with "1" (for example, "110" ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) "10").

Let *val*(*s*) be such a number that *s* is its binary representation.

Correct string *a* is less than some other correct string *b* iff *val*(*a*) < *val*(*b*).

Your task is to find the minimum correct string that you can obtain from the given one using the operations described above. You can use these operations any number of times in any order (or even use no operations at all).

## Input

The first line contains integer number *n* (1 ≤ *n* ≤ 100) — the length of string *s*.

The second line contains the string *s* consisting of characters "0" and "1". It is guaranteed that the string *s* is correct.

## Output

Print one string — the minimum correct string that you can obtain from the given one.

## Examples

## Input


```
4  
1001  

```
## Output


```
100  

```
## Input


```
1  
1  

```
## Output


```
1  

```
## Note

In the first example you can obtain the answer by the following sequence of operations: "1001" ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) "1010" ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) "1100" ![](images/70a0795f45d32287dba0eb83fc4a3f470c6e5537.png) "100".

In the second example you can't obtain smaller answer no matter what operations you use.



#### tags 

#800 #implementation 