<h1 style='text-align: center;'> D. Gargari and Permutations</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Gargari got bored to play with the bishops and now, after solving the problem about them, he is trying to do math homework. In a math book he have found *k* permutations. Each of them consists of numbers 1, 2, ..., *n* in some order. Now he should find the length of the longest common subsequence of these permutations. Can you help Gargari?

You can read about longest common subsequence there: https://en.wikipedia.org/wiki/Longest_common_subsequence_problem

## Input

The first line contains two integers *n* and *k* (1 ≤ *n* ≤ 1000; 2 ≤ *k* ≤ 5). Each of the next *k* lines contains integers 1, 2, ..., *n* in some order — description of the current permutation.

## Output

Print the length of the longest common subsequence.

## Examples

## Input


```
4 3  
1 4 2 3  
4 1 2 3  
1 2 4 3  

```
## Output


```
3  

```
## Note

The answer for the first test sample is subsequence [1, 2, 3].



#### tags 

#1900 #dfs_and_similar #dp #graphs #implementation 