<h1 style='text-align: center;'> B. Three matrices</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Chubby Yang is studying linear equations right now. He came up with a nice problem. In the problem you are given an *n* × *n* matrix *W*, consisting of integers, and you should find two *n* × *n* matrices *A* and *B*, all the following conditions must hold: 

* *A**ij* = *A**ji*, for all *i*, *j* (1 ≤ *i*, *j* ≤ *n*);
* *B**ij* =  - *B**ji*, for all *i*, *j* (1 ≤ *i*, *j* ≤ *n*);
* *W**ij* = *A**ij* + *B**ij*, for all *i*, *j* (1 ≤ *i*, *j* ≤ *n*).

Can you solve the problem?

## Input

The first line contains an integer *n* (1 ≤ *n* ≤ 170). Each of the following *n* lines contains *n* integers. The *j*-th integer in the *i*-th line is *W**ij* (0 ≤ |*W**ij*| < 1717).

## Output

The first *n* lines must contain matrix *A*. The next *n* lines must contain matrix *B*. Print the matrices in the format equal to format of matrix *W* in input. It is guaranteed that the answer exists. If there are multiple answers, you are allowed to print any of them.

The answer will be considered correct if the absolute or relative error doesn't exceed 10- 4.

## Examples

## Input


```
2  
1 4  
3 2  

```
## Output


```
1.00000000 3.50000000  
3.50000000 2.00000000  
0.00000000 0.50000000  
-0.50000000 0.00000000  

```
## Input


```
3  
1 2 3  
4 5 6  
7 8 9  

```
## Output


```
1.00000000 3.00000000 5.00000000  
3.00000000 5.00000000 7.00000000  
5.00000000 7.00000000 9.00000000  
0.00000000 -1.00000000 -2.00000000  
1.00000000 0.00000000 -1.00000000  
2.00000000 1.00000000 0.00000000  

```


#### tags 

