<h1 style='text-align: center;'> E. Anton and Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Anton likes permutations, especially he likes to permute their elements. ## Note

 that a permutation of *n* elements is a sequence of numbers {*a*1, *a*2, ..., *a**n*}, in which every number from 1 to *n* appears exactly once.

One day Anton got a new permutation and started to play with it. He does the following operation *q* times: he takes two elements of the permutation and swaps these elements. After each operation he asks his friend Vanya, how many inversions there are in the new permutation. The number of inversions in a permutation is the number of distinct pairs (*i*, *j*) such that 1 ≤ *i* < *j* ≤ *n* and *a**i* > *a**j*.

Vanya is tired of answering Anton's silly questions. So he asked you to write a program that would answer these questions instead of him.

Initially Anton's permutation was {1, 2, ..., *n*}, that is *a**i* = *i* for all *i* such that 1 ≤ *i* ≤ *n*.

## Input

The first line of the input contains two integers *n* and *q* (1 ≤ *n* ≤ 200 000, 1 ≤ *q* ≤ 50 000) — the length of the permutation and the number of operations that Anton does.

Each of the following *q* lines of the input contains two integers *l**i* and *r**i* (1 ≤ *l**i*, *r**i* ≤ *n*) — the indices of elements that Anton swaps during the *i*-th operation. ## Note

 that indices of elements that Anton swaps during the *i*-th operation can coincide. Elements in the permutation are numbered starting with one.

## Output

## Output

 *q* lines. The *i*-th line of the output is the number of inversions in the Anton's permutation after the *i*-th operation.

## Examples

## Input


```
5 4  
4 5  
2 4  
2 5  
2 2  

```
## Output


```
1  
4  
3  
3  

```
## Input


```
2 1  
2 1  

```
## Output


```
1  

```
## Input


```
6 7  
1 4  
3 5  
2 3  
3 3  
3 6  
2 1  
5 1  

```
## Output


```
5  
6  
7  
7  
10  
11  
8  

```
## Note

Consider the first sample.

After the first Anton's operation the permutation will be {1, 2, 3, 5, 4}. There is only one inversion in it: (4, 5).

After the second Anton's operation the permutation will be {1, 5, 3, 2, 4}. There are four inversions: (2, 3), (2, 4), (2, 5) and (3, 4).

After the third Anton's operation the permutation will be {1, 4, 3, 2, 5}. There are three inversions: (2, 3), (2, 4) and (3, 4).

After the fourth Anton's operation the permutation doesn't change, so there are still three inversions.



#### tags 

#2200 #brute_force #data_structures 