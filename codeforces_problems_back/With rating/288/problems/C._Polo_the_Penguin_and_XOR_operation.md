<h1 style='text-align: center;'> C. Polo the Penguin and XOR operation</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Little penguin Polo likes permutations. But most of all he likes permutations of integers from 0 to *n*, inclusive.

For permutation *p* = *p*0, *p*1, ..., *p**n*, Polo has defined its beauty — number ![](images/0c51fe5d835015fdb8b8dbb056e9a83c439c83dc.png).

Expression ![](images/b364f2e04c665b78b924ec10666327a4ef4635bc.png) means applying the operation of bitwise excluding "OR" to numbers *x* and *y*. This operation exists in all modern programming languages, for example, in language C++ and Java it is represented as "^" and in Pascal — as "xor".

Help him find among all permutations of integers from 0 to *n* the permutation with the maximum beauty.

## Input

The single line contains a positive integer *n* (1 ≤ *n* ≤ 106).

## Output

In the first line print integer *m* the maximum possible beauty. In the second line print any permutation of integers from 0 to *n* with the beauty equal to *m*.

If there are several suitable permutations, you are allowed to print any of them.

## Examples

## Input


```
4  

```
## Output


```
20  
0 2 1 4 3  

```


#### tags 

#1700 #implementation #math 