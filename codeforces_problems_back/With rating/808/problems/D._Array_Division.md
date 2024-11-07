<h1 style='text-align: center;'> D. Array Division</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya has an array *a* consisting of positive integer numbers. Vasya wants to divide this array into two non-empty consecutive parts (the prefix and the suffix) so that the sum of all elements in the first part equals to the sum of elements in the second part. It is not always possible, so Vasya will move some element before dividing the array (Vasya will erase some element and insert it into an arbitrary position).

Inserting an element in the same position he was erased from is also considered moving.

Can Vasya divide the array after choosing the right element to move and its new position?

## Input

The first line contains single integer *n* (1 ≤ *n* ≤ 100000) — the size of the array.

The second line contains *n* integers *a*1, *a*2... *a**n* (1 ≤ *a**i* ≤ 109) — the elements of the array.

## Output

Print YES if Vasya can divide the array after moving one element. Otherwise print NO.

## Examples

## Input


```
3  
1 3 2  

```
## Output


```
YES  

```
## Input


```
5  
1 2 3 4 5  

```
## Output


```
NO  

```
## Input


```
5  
2 2 3 4 5  

```
## Output


```
YES  

```
## Note

In the first example Vasya can move the second element to the end of the array.

In the second example no move can make the division possible.

In the third example Vasya can move the fourth element by one position to the left.



#### tags 

#1900 #binary_search #data_structures #implementation 