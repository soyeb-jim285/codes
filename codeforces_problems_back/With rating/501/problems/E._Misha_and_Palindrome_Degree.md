<h1 style='text-align: center;'> E. Misha and Palindrome Degree</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Misha has an array of *n* integers indexed by integers from 1 to *n*. Let's define palindrome degree of array *a* as the number of such index pairs (*l*, *r*)(1 ≤ *l* ≤ *r* ≤ *n*), that the elements from the *l*-th to the *r*-th one inclusive can be rearranged in such a way that the whole array will be a palindrome. In other words, pair (*l*, *r*) should meet the condition that after some rearranging of numbers on positions from *l* to *r*, inclusive (it is allowed not to rearrange the numbers at all), for any 1 ≤ *i* ≤ *n* following condition holds: *a*[*i*] = *a*[*n* - *i* + 1]. 

Your task is to find the palindrome degree of Misha's array.

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 105).

The second line contains *n* positive integers *a*[*i*] (1 ≤ *a*[*i*] ≤ *n*), separated by spaces — the elements of Misha's array.

## Output

In a single line print the answer to the problem.

## Examples

## Input


```
3  
2 2 2  

```
## Output


```
6  

```
## Input


```
6  
3 6 5 3 3 5  

```
## Output


```
0  

```
## Input


```
5  
5 5 2 5 2  

```
## Output


```
4  

```
## Note

In the first sample test any possible pair (*l*, *r*) meets the condition.

In the third sample test following pairs (1, 3), (1, 4), (1, 5), (2, 5) meet the condition.



#### tags 

#2500 #binary_search #combinatorics #implementation 