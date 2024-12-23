<h1 style='text-align: center;'> C. Bear and Up-Down</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The life goes up and down, just like nice sequences. Sequence *t*1, *t*2, ..., *t**n* is called nice if the following two conditions are satisfied: 

* *t**i* < *t**i* + 1 for each odd *i* < *n*;
* *t**i* > *t**i* + 1 for each even *i* < *n*.

For example, sequences (2, 8), (1, 5, 1) and (2, 5, 1, 100, 99, 120) are nice, while (1, 1), (1, 2, 3) and (2, 5, 3, 2) are not.

Bear Limak has a sequence of positive integers *t*1, *t*2, ..., *t**n*. This sequence is not nice now and Limak wants to fix it by a single swap. He is going to choose two indices *i* < *j* and swap elements *t**i* and *t**j* in order to get a nice sequence. Count the number of ways to do so. Two ways are considered different if indices of elements chosen for a swap are different.

## Input

The first line of the input contains one integer *n* (2 ≤ *n* ≤ 150 000) — the length of the sequence.

The second line contains *n* integers *t*1, *t*2, ..., *t**n* (1 ≤ *t**i* ≤ 150 000) — the initial sequence. It's guaranteed that the given sequence is not nice.

## Output

Print the number of ways to swap two elements exactly once in order to get a nice sequence.

## Examples

## Input


```
5  
2 8 4 7 7  

```
## Output


```
2  

```
## Input


```
4  
200 150 100 50  

```
## Output


```
1  

```
## Input


```
10  
3 2 1 4 1 4 1 4 1 4  

```
## Output


```
8  

```
## Input


```
9  
1 2 3 4 5 6 7 8 9  

```
## Output


```
0  

```
## Note

In the first sample, there are two ways to get a nice sequence with one swap: 

1. Swap *t*2 = 8 with *t*4 = 7.
2. Swap *t*1 = 2 with *t*5 = 7.

In the second sample, there is only one way — Limak should swap *t*1 = 200 with *t*4 = 50.



#### tags 

#1900 #brute_force #implementation 