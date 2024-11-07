<h1 style='text-align: center;'> D. Vasya And The Matrix</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Now Vasya is taking an exam in mathematics. In order to get a good mark, Vasya needs to guess the matrix that the teacher has constructed!

Vasya knows that the matrix consists of *n* rows and *m* columns. For each row, he knows the xor (bitwise excluding or) of the elements in this row. The sequence *a*1, *a*2, ..., *a**n* denotes the xor of elements in rows with indices 1, 2, ..., *n*, respectively. Similarly, for each column, he knows the xor of the elements in this column. The sequence *b*1, *b*2, ..., *b**m* denotes the xor of elements in columns with indices 1, 2, ..., *m*, respectively.

Help Vasya! Find a matrix satisfying the given constraints or tell him that there is no suitable matrix.

## Input

The first line contains two numbers *n* and *m* (2 ≤ *n*, *m* ≤ 100) — the dimensions of the matrix.

The second line contains *n* numbers *a*1, *a*2, ..., *a**n* (0 ≤ *a**i* ≤ 109), where *a**i* is the xor of all elements in row *i*.

The third line contains *m* numbers *b*1, *b*2, ..., *b**m* (0 ≤ *b**i* ≤ 109), where *b**i* is the xor of all elements in column *i*.

## Output

If there is no matrix satisfying the given constraints in the first line, output "NO".

Otherwise, on the first line output "YES", and then *n* rows of *m* numbers in each *c**i*1, *c**i*2, ... , *c**im* (0 ≤ *c**ij* ≤ 2·109) — the description of the matrix.

If there are several suitable matrices, it is allowed to print any of them.

## Examples

## Input


```
2 3  
2 9  
5 3 13  

```
## Output


```
YES  
3 4 5  
6 7 8  

```
## Input


```
3 3  
1 7 6  
2 15 12  

```
## Output


```
NO  

```


#### tags 

#1800 #constructive_algorithms #flows #math 