<h1 style='text-align: center;'> B. Guess the Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Bob has a permutation of integers from 1 to *n*. Denote this permutation as *p*. The *i*-th element of *p* will be denoted as *p**i*. For all pairs of distinct integers *i*, *j* between 1 and *n*, he wrote the number *a**i*, *j* = *min*(*p**i*, *p**j*). He writes *a**i*, *i* = 0 for all integer *i* from 1 to *n*.

Bob gave you all the values of *a**i*, *j* that he wrote down. Your job is to reconstruct any permutation that could have generated these values. The input will be formed so that it is guaranteed that there is at least one solution that is consistent with the information given.

## Input

The first line of the input will contain a single integer *n* (2 ≤ *n* ≤ 50).

The next *n* lines will contain the values of *a**i*, *j*. The *j*-th number on the *i*-th line will represent *a**i*, *j*. The *i*-th number on the *i*-th line will be 0. It's guaranteed that *a**i*, *j* = *a**j*, *i* and there is at least one solution consistent with the information given.

## Output

Print *n* space separated integers, which represents a permutation that could have generated these values. If there are multiple possible solutions, print any of them.

## Examples

## Input


```
2  
0 1  
1 0  

```
## Output


```
2 1  

```
## Input


```
5  
0 2 2 1 2  
2 0 4 1 3  
2 4 0 1 3  
1 1 1 0 1  
2 3 3 1 0  

```
## Output


```
2 5 4 1 3  

```
## Note

In the first case, the answer can be {1, 2} or {2, 1}.

In the second case, another possible answer is {2, 4, 5, 1, 3}.



#### tags 

#1100 #constructive_algorithms 