<h1 style='text-align: center;'> A. Little Elephant and Function</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The Little Elephant enjoys recursive functions.

This time he enjoys the sorting function. Let *a* is a permutation of an integers from 1 to *n*, inclusive, and *a**i* denotes the *i*-th element of the permutation. The Little Elephant's recursive function *f*(*x*), that sorts the first *x* permutation's elements, works as follows:

* If *x* = 1, exit the function.
* Otherwise, call *f*(*x* - 1), and then make *swap*(*a**x* - 1, *a**x*) (swap the *x*-th and (*x* - 1)-th elements of *a*).

The Little Elephant's teacher believes that this function does not work correctly. But that-be do not get an F, the Little Elephant wants to show the performance of its function. Help him, find a permutation of numbers from 1 to *n*, such that after performing the Little Elephant's function (that is call *f*(*n*)), the permutation will be sorted in ascending order.

## Input

A single line contains integer *n* (1 ≤ *n* ≤ 1000) — the size of permutation.

## Output

In a single line print *n* distinct integers from 1 to *n* — the required permutation. Numbers in a line should be separated by spaces.

It is guaranteed that the answer exists.

## Examples

## Input


```
1  

```
## Output


```
1 
```
## Input


```
2  

```
## Output


```
2 1 
```


#### tags 

#1000 #implementation #math 