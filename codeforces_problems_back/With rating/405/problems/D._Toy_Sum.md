<h1 style='text-align: center;'> D. Toy Sum</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Little Chris is very keen on his toy blocks. His teacher, however, wants Chris to solve more problems, so he decided to play a trick on Chris.

There are exactly *s* blocks in Chris's set, each block has a unique number from 1 to *s*. Chris's teacher picks a subset of blocks *X* and keeps it to himself. He will give them back only if Chris can pick such a non-empty subset *Y* from the remaining blocks, that the equality holds: 

![](images/37b797b8afff1b78d9cef3602665323f470da659.png) "Are you kidding me?", asks Chris.For example, consider a case where *s* = 8 and Chris's teacher took the blocks with numbers 1, 4 and 5. One way for Chris to choose a set is to pick the blocks with numbers 3 and 6, see figure. Then the required sums would be equal: (1 - 1) + (4 - 1) + (5 - 1) = (8 - 3) + (8 - 6) = 7.

 ![](images/dacde6bcbca311af8035fd2b1754fc6fc343f4fa.png) However, now Chris has exactly *s* = 106 blocks. Given the set *X* of blocks his teacher chooses, help Chris to find the required set *Y*!

## Input

The first line of input contains a single integer *n* (1 ≤ *n* ≤ 5·105), the number of blocks in the set *X*. The next line contains *n* distinct space-separated integers *x*1, *x*2, ..., *x**n* (1 ≤ *x**i* ≤ 106), the numbers of the blocks in *X*.

Note: since the size of the input and output could be very large, don't use slow output techniques in your language. For example, do not use input and output streams (cin, cout) in C++.

## Output

In the first line of output print a single integer *m* (1 ≤ *m* ≤ 106 - *n*), the number of blocks in the set *Y*. In the next line output *m* distinct space-separated integers *y*1, *y*2, ..., *y**m* (1 ≤ *y**i* ≤ 106), such that the required equality holds. The sets *X* and *Y* should not intersect, i.e. *x**i* ≠ *y**j* for all *i*, *j* (1 ≤ *i* ≤ *n*; 1 ≤ *j* ≤ *m*). It is guaranteed that at least one solution always exists. If there are multiple solutions, output any of them.

## Examples

## Input


```
3  
1 4 5  

```
## Output


```
2  
999993 1000000
```
## Input


```
1  
1  

```
## Output


```
1  
1000000   

```


#### tags 

#1700 #greedy #implementation #math 