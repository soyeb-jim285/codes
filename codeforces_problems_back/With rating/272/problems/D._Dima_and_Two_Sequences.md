<h1 style='text-align: center;'> D. Dima and Two Sequences</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Little Dima has two sequences of points with integer coordinates: sequence (*a*1, 1), (*a*2, 2), ..., (*a**n*, *n*) and sequence (*b*1, 1), (*b*2, 2), ..., (*b**n*, *n*).

Now Dima wants to count the number of distinct sequences of points of length 2·*n* that can be assembled from these sequences, such that the *x*-coordinates of points in the assembled sequence will not decrease. Help him with that. ## Note

 that each element of the initial sequences should be used exactly once in the assembled sequence.

Dima considers two assembled sequences (*p*1, *q*1), (*p*2, *q*2), ..., (*p*2·*n*, *q*2·*n*) and (*x*1, *y*1), (*x*2, *y*2), ..., (*x*2·*n*, *y*2·*n*) distinct, if there is such *i* (1 ≤ *i* ≤ 2·*n*), that (*p**i*, *q**i*) ≠ (*x**i*, *y**i*).

As the answer can be rather large, print the remainder from dividing the answer by number *m*.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 105). The second line contains *n* integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 109). The third line contains *n* integers *b*1, *b*2, ..., *b**n* (1 ≤ *b**i* ≤ 109). The numbers in the lines are separated by spaces.

The last line contains integer *m* (2 ≤ *m* ≤ 109 + 7).

## Output

In the single line print the remainder after dividing the answer to the problem by number *m*. 

## Examples

## Input


```
1  
1  
2  
7  

```
## Output


```
1  

```
## Input


```
2  
1 2  
2 3  
11  

```
## Output


```
2  

```
## Note

In the first sample you can get only one sequence: (1, 1), (2, 1). 

In the second sample you can get such sequences : (1, 1), (2, 2), (2, 1), (3, 2); (1, 1), (2, 1), (2, 2), (3, 2). Thus, the answer is 2.



#### tags 

#1600 #combinatorics #math #sortings 