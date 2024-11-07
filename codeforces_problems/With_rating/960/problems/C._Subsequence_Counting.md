<h1 style='text-align: center;'> C. Subsequence Counting</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Pikachu had an array with him. He wrote down all the non-empty subsequences of the array on paper. 
## Note

 that an array of size *n* has 2*n* - 1 non-empty subsequences in it. 

Pikachu being mischievous as he always is, removed all the subsequences in which Maximum_element_of_the_subsequence  -  Minimum_element_of_subsequence  ≥ *d*

Pikachu was finally left with *X* subsequences. 

However, he lost the initial array he had, and now is in serious trouble. He still remembers the numbers *X* and *d*. He now wants you to construct any such array which will satisfy the above conditions. All the numbers in the final array should be positive integers less than 1018. 

## Note

 the number of elements in the output array should not be more than 104. If no answer is possible, print  - 1.

#### Input

The only line of input consists of two space separated integers *X* and *d* (1 ≤ *X*, *d* ≤ 109).

#### Output

#### Output

 should consist of two lines.

First line should contain a single integer *n* (1 ≤ *n* ≤ 10 000)— the number of integers in the final array.

Second line should consist of *n* space separated integers — *a*1, *a*2, ... , *a**n* (1 ≤ *a**i* < 1018).

If there is no answer, print a single integer -1. If there are multiple answers, print any of them.

## Examples

#### Input


```text
10 5  

```
#### Output


```text
6  
5 50 7 15 6 100
```
#### Input


```text
4 2  

```
#### Output


```text
4  
10 100 1000 10000
```
## Note

In the output of the first example case, the remaining subsequences after removing those with Maximum_element_of_the_subsequence  -  Minimum_element_of_subsequence  ≥ 5 are [5], [5, 7], [5, 6], [5, 7, 6], [50], [7], [7, 6], [15], [6], [100]. There are 10 of them. Hence, the array [5, 50, 7, 15, 6, 100] is valid.

Similarly, in the output of the second example case, the remaining sub-sequences after removing those with Maximum_element_of_the_subsequence  -  Minimum_element_of_subsequence  ≥ 2 are [10], [100], [1000], [10000]. There are 4 of them. Hence, the array [10, 100, 1000, 10000] is valid.



#### Tags 

#1700 #NOT OK #bitmasks #constructive_algorithms #greedy #implementation 

## Blogs
- [All Contest Problems](../Divide_by_Zero_2018_and_Codeforces_Round_474_(Div._1_+_Div._2,_combined).md)
- [A (en)](../blogs/A_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
