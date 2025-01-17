<h1 style='text-align: center;'> B. Boring Partition</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This problem is the most boring one you've ever seen. 

Given a sequence of integers *a*1, *a*2, ..., *a**n* and a non-negative integer *h*, our goal is to partition the sequence into two subsequences (not necessarily consist of continuous elements). Each element of the original sequence should be contained in exactly one of the result subsequences. ## Note

, that one of the result subsequences can be empty.

Let's define function *f*(*a**i*, *a**j*) on pairs of distinct elements (that is *i* ≠ *j*) in the original sequence. If *a**i* and *a**j* are in the same subsequence in the current partition then *f*(*a**i*, *a**j*) = *a**i* + *a**j* otherwise *f*(*a**i*, *a**j*) = *a**i* + *a**j* + *h*. 

Consider all possible values of the function *f* for some partition. We'll call the goodness of this partiotion the difference between the maximum value of function *f* and the minimum value of function *f*.

Your task is to find a partition of the given sequence *a* that have the minimal possible goodness among all possible partitions.

## Input

The first line of input contains integers *n* and *h* (2 ≤ *n* ≤ 105, 0 ≤ *h* ≤ 108). In the second line there is a list of *n* space-separated integers representing *a*1, *a*2, ..., *a**n* (0 ≤ *a**i* ≤ 108).

## Output

The first line of output should contain the required minimum goodness. 

The second line describes the optimal partition. You should print *n* whitespace-separated integers in the second line. The *i*-th integer is 1 if *a**i* is in the first subsequence otherwise it should be 2.

If there are several possible correct answers you are allowed to print any of them.

## Examples

## Input


```
3 2  
1 2 3  

```
## Output


```
1  
1 2 2   

```
## Input


```
5 10  
0 1 0 2 1  

```
## Output


```
3  
2 2 2 2 2   

```
## Note

In the first sample the values of *f* are as follows: *f*(1, 2) = 1 + 2 + 2 = 5, *f*(1, 3) = 1 + 3 + 2 = 6 and *f*(2, 3) = 2 + 3 = 5. So the difference between maximum and minimum values of *f* is 1.

In the second sample the value of *h* is large, so it's better for one of the sub-sequences to be empty.



#### tags 

#1800 #constructive_algorithms 