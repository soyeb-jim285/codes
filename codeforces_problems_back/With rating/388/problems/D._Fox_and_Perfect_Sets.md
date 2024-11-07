<h1 style='text-align: center;'> D. Fox and Perfect Sets</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Fox Ciel studies number theory.

She thinks a non-empty set *S* contains non-negative integers is perfect if and only if for any ![](images/9ef9929d40fa162bdd76a55da469dde6fc13a5f5.png) (*a* can be equal to *b*), ![](images/bba2b10c821617f53f33d4f198ad3dfee0eb6ecd.png). Where operation *xor* means exclusive or operation (http://en.wikipedia.org/wiki/Exclusive_or).

Please calculate the number of perfect sets consisting of integers not greater than *k*. The answer can be very large, so print it modulo 1000000007 (109 + 7).

## Input

The first line contains an integer *k* (0 ≤ *k* ≤ 109).

## Output

Print a single integer — the number of required sets modulo 1000000007 (109 + 7).

## Examples

## Input


```
1  

```
## Output


```
2  

```
## Input


```
2  

```
## Output


```
3  

```
## Input


```
3  

```
## Output


```
5  

```
## Input


```
4  

```
## Output


```
6  

```
## Note

In example 1, there are 2 such sets: {0} and {0, 1}. ## Note

 that {1} is not a perfect set since 1 xor 1 = 0 and {1} doesn't contain zero.

In example 4, there are 6 such sets: {0}, {0, 1}, {0, 2}, {0, 3}, {0, 4} and {0, 1, 2, 3}.



#### tags 

#2700 #math 