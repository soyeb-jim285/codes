<h1 style='text-align: center;'> G. Move by Prime</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Pussycat Sonya has an array consisting of *n* positive integers. There are 2*n* possible subsequences of the array. For each subsequence she counts the minimum number of operations to make all its elements equal. Each operation must be one of two:

* Choose some element of the subsequence and multiply it by some prime number.
* Choose some element of the subsequence and divide it by some prime number. The chosen element must be divisible by the chosen prime number.

What is the sum of minimum number of operations for all 2*n* possible subsequences? Find and print this sum modulo 109 + 7.

## Input

The first line of the input contains a single integer *n* (1 ≤ *n* ≤ 300 000) — the size of the array.

The second line contains *n* integers *t*1, *t*2, ..., *t**n* (1 ≤ *t**i* ≤ 300 000) — elements of the array.

## Output

Print the sum of minimum number of operation for all possible subsequences of the given array modulo 109 + 7.

## Examples

## Input


```
3  
60 60 40  

```
## Output


```
6  

```
## Input


```
4  
1 2 3 4  

```
## Output


```
24  

```
## Note

In the first sample, there are 8 possible subsequences: (60, 60, 40), (60, 60), (60, 40), (60, 40), (60), (60), (40) and () (empty subsequence).

For a subsequence (60, 60, 40) we can make all elements equal by two operations — divide 40 by 2 to get 20, and then multiply 20 by 3 to get 60. It's impossible to achieve the goal using less operations and thus we add 2 to the answer.

There are two subsequences equal to (60, 40) and for each of them the also need to make at least 2 operations.

In each of other subsequences all numbers are already equal, so we need 0 operations for each of them. The sum is equal to 2 + 2 + 2 = 6.



#### tags 

#3100 #combinatorics #math #number_theory 