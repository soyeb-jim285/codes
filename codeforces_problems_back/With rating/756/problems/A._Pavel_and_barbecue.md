<h1 style='text-align: center;'> A. Pavel and barbecue</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Pavel cooks barbecue. There are *n* skewers, they lay on a brazier in a row, each on one of *n* positions. Pavel wants each skewer to be cooked some time in every of *n* positions in two directions: in the one it was directed originally and in the reversed direction.

Pavel has a plan: a permutation *p* and a sequence *b*1, *b*2, ..., *b**n*, consisting of zeros and ones. Each second Pavel move skewer on position *i* to position *p**i*, and if *b**i* equals 1 then he reverses it. So he hope that every skewer will visit every position in both directions.

Unfortunately, not every pair of permutation *p* and sequence *b* suits Pavel. What is the minimum total number of elements in the given permutation *p* and the given sequence *b* he needs to change so that every skewer will visit each of 2*n* placements? ## Note

 that after changing the permutation should remain a permutation as well.

There is no problem for Pavel, if some skewer visits some of the placements several times before he ends to cook. In other words, a permutation *p* and a sequence *b* suit him if there is an integer *k* (*k* ≥ 2*n*), so that after *k* seconds each skewer visits each of the 2*n* placements.

It can be shown that some suitable pair of permutation *p* and sequence *b* exists for any *n*.

## Input

The first line contain the integer *n* (1 ≤ *n* ≤ 2·105) — the number of skewers.

The second line contains a sequence of integers *p*1, *p*2, ..., *p**n* (1 ≤ *p**i* ≤ *n*) — the permutation, according to which Pavel wants to move the skewers.

The third line contains a sequence *b*1, *b*2, ..., *b**n* consisting of zeros and ones, according to which Pavel wants to reverse the skewers.

## Output

Print single integer — the minimum total number of elements in the given permutation *p* and the given sequence *b* he needs to change so that every skewer will visit each of 2*n* placements.

## Examples

## Input


```
4  
4 3 2 1  
0 1 1 1  

```
## Output


```
2  

```
## Input


```
3  
2 3 1  
0 0 0  

```
## Output


```
1  

```
## Note

In the first example Pavel can change the permutation to 4, 3, 1, 2.

In the second example Pavel can change any element of *b* to 1.



#### tags 

#1700 #constructive_algorithms #dfs_and_similar 