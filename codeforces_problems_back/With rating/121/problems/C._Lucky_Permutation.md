<h1 style='text-align: center;'> C. Lucky Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Petya loves lucky numbers. Everybody knows that lucky numbers are positive integers whose decimal representation contains only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

One day Petya dreamt of a lexicographically *k*-th permutation of integers from 1 to *n*. Determine how many lucky numbers in the permutation are located on the positions whose indexes are also lucky numbers.

## Input

The first line contains two integers *n* and *k* (1 ≤ *n*, *k* ≤ 109) — the number of elements in the permutation and the lexicographical number of the permutation.

## Output

If the *k*-th permutation of numbers from 1 to *n* does not exist, print the single number "-1" (without the quotes). Otherwise, print the answer to the problem: the number of such indexes *i*, that *i* and *a**i* are both lucky numbers.

## Examples

## Input


```
7 4  

```
## Output


```
1  

```
## Input


```
4 7  

```
## Output


```
1  

```
## Note

A permutation is an ordered set of *n* elements, where each integer from 1 to *n* occurs exactly once. The element of permutation in position with index *i* is denoted as *a**i* (1 ≤ *i* ≤ *n*). Permutation *a* is lexicographically smaller that permutation *b* if there is such a *i* (1 ≤ *i* ≤ *n*), that *a**i* < *b**i*, and for any *j* (1 ≤ *j* < *i*) *a**j* = *b**j*. Let's make a list of all possible permutations of *n* elements and sort it in the order of lexicographical increasing. Then the lexicographically *k*-th permutation is the *k*-th element of this list of permutations.

In the first sample the permutation looks like that:

1 2 3 4 6 7 5

The only suitable position is 4.

In the second sample the permutation looks like that:

2 1 3 4

The only suitable position is 4.



#### tags 

#1900 #brute_force #combinatorics #number_theory 