<h1 style='text-align: center;'> F. Mahmoud and Ehab and yet another xor task</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Ehab has an array *a* of *n* integers. He likes the [bitwise-xor operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) and he likes to bother Mahmoud so he came up with a problem. He gave Mahmoud *q* queries. In each of them, he gave Mahmoud 2 integers *l* and *x*, and asked him to find the number of subsequences of the first *l* elements of the array such that their bitwise-xor sum is *x*. Can you help Mahmoud answer the queries?

A subsequence can contain elements that are not neighboring.

## Input

The first line contains integers *n* and *q* (1 ≤ *n*, *q* ≤ 105), the number of elements in the array and the number of queries.

The next line contains *n* integers *a*1, *a*2, ..., *a**n* (0 ≤ *a**i* < 220), the elements of the array.

The next *q* lines, each contains integers *l* and *x* (1 ≤ *l* ≤ *n*, 0 ≤ *x* < 220), representing the queries.

## Output

For each query, output its answer modulo 109 + 7 in a newline.

## Examples

## Input


```
5 5  
0 1 2 3 4  
4 3  
2 0  
3 7  
5 7  
5 8  

```
## Output


```
4  
2  
0  
4  
0  

```
## Input


```
3 2  
1 1 1  
3 1  
2 0  

```
## Output


```
4  
2  

```
## Note

The bitwise-xor sum of the empty set is 0 and the bitwise-xor sum of a set containing one element is that element itself.



#### tags 

#2400 #bitmasks #dp #math #matrices 