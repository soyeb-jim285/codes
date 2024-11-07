<h1 style='text-align: center;'> C. Points on Plane</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

On a plane are *n* points (*x**i*, *y**i*) with integer coordinates between 0 and 106. The distance between the two points with numbers *a* and *b* is said to be the following value: ![](images/03274f8c977ad3feb5d9f6ede91c69bcaef04972.png) (the distance calculated by such formula is called Manhattan distance).

We call a hamiltonian path to be some permutation *p**i* of numbers from 1 to *n*. We say that the length of this path is value ![](images/2872e932e7cab8f5f7a9c718441f7534261ed638.png).

Find some hamiltonian path with a length of no more than 25 × 108. ## Note

 that you do not have to minimize the path length.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 106).

The *i* + 1-th line contains the coordinates of the *i*-th point: *x**i* and *y**i* (0 ≤ *x**i*, *y**i* ≤ 106).

It is guaranteed that no two points coincide.

## Output

Print the permutation of numbers *p**i* from 1 to *n* — the sought Hamiltonian path. The permutation must meet the inequality ![](images/70f9e4aeb31a2c8d58e32efe76501886a9a44af7.png).

If there are multiple possible answers, print any of them.

It is guaranteed that the answer exists.

## Examples

## Input


```
5  
0 7  
8 10  
3 4  
5 0  
9 12  

```
## Output


```
4 3 1 2 5   

```
## Note

In the sample test the total distance is:

![](images/c772e61c616e1c27114e3facb9e6db6c5cf93b82.png)

(|5 - 3| + |0 - 4|) + (|3 - 0| + |4 - 7|) + (|0 - 8| + |7 - 10|) + (|8 - 9| + |10 - 12|) = 2 + 4 + 3 + 3 + 8 + 3 + 1 + 2 = 26



#### tags 

#2100 #constructive_algorithms #divide_and_conquer #geometry #greedy #sortings 