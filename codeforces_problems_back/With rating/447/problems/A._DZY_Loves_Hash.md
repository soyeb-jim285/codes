<h1 style='text-align: center;'> A. DZY Loves Hash</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

DZY has a hash table with *p* buckets, numbered from 0 to *p* - 1. He wants to insert *n* numbers, in the order they are given, into the hash table. For the *i*-th number *x**i*, DZY will put it into the bucket numbered *h*(*x**i*), where *h*(*x*) is the hash function. In this problem we will assume, that *h*(*x*) = *x* *mod* *p*. Operation *a* *mod* *b* denotes taking a remainder after division *a* by *b*.

However, each bucket can contain no more than one element. If DZY wants to insert an number into a bucket which is already filled, we say a "conflict" happens. Suppose the first conflict happens right after the *i*-th insertion, you should output *i*. If no conflict happens, just output -1.

## Input

The first line contains two integers, *p* and *n* (2 ≤ *p*, *n* ≤ 300). Then *n* lines follow. The *i*-th of them contains an integer *x**i* (0 ≤ *x**i* ≤ 109).

## Output

## Output

 a single integer — the answer to the problem.

## Examples

## Input


```
10 5  
0  
21  
53  
41  
53  

```
## Output


```
4  

```
## Input


```
5 5  
0  
1  
2  
3  
4  

```
## Output


```
-1  

```


#### tags 

#800 #implementation 