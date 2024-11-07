<h1 style='text-align: center;'> C. Dreamoon and Sums</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Dreamoon loves summing up something for no reason. One day he obtains two integers *a* and *b* occasionally. He wants to calculate the sum of all nice integers. Positive integer *x* is called nice if ![](images/747b668d05dce59a14c79f7573cf84d4af25536c.png) and ![](images/f2c3c9a716cef71591af317f816d0d89605de8cd.png), where *k* is some integer number in range [1, *a*].

By ![](images/1e6fb3a33a9e71aae77ea40b847b4751cad6a9b2.png) we denote the quotient of integer division of *x* and *y*. By ![](images/13ccd3404ca33681bef79230f269517728677a3a.png) we denote the remainder of integer division of *x* and *y*. You can read more about these operations here: http://goo.gl/AcsXhT.

The answer may be large, so please print its remainder modulo 1 000 000 007 (109 + 7). Can you compute it faster than Dreamoon?

## Input

The single line of the input contains two integers *a*, *b* (1 ≤ *a*, *b* ≤ 107).

## Output

Print a single integer representing the answer modulo 1 000 000 007 (109 + 7).

## Examples

## Input


```
1 1  

```
## Output


```
0  

```
## Input


```
2 2  

```
## Output


```
8  

```
## Note

For the first sample, there are no nice integers because ![](images/03b1dc6bae5180f8a2d8eb85789e8b393e585970.png) is always zero.

For the second sample, the set of nice integers is {3, 5}.



#### tags 

#1600 #math 