<h1 style='text-align: center;'> B. Masha and geometric depression</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Masha really loves algebra. On the last lesson, her strict teacher Dvastan gave she new exercise.

You are given geometric progression *b* defined by two integers *b*1 and *q*. Remind that a geometric progression is a sequence of integers *b*1, *b*2, *b*3, ..., where for each *i* > 1 the respective term satisfies the condition *b**i* = *b**i* - 1·*q*, where *q* is called the common ratio of the progression. Progressions in Uzhlyandia are unusual: both *b*1 and *q* can equal 0. Also, Dvastan gave Masha *m* "bad" integers *a*1, *a*2, ..., *a**m*, and an integer *l*.

Masha writes all progression terms one by one onto the board (including repetitive) while condition |*b**i*| ≤ *l* is satisfied (|*x*| means absolute value of *x*). There is an exception: if a term equals one of the "bad" integers, Masha skips it (doesn't write onto the board) and moves forward to the next term.

But the lesson is going to end soon, so Masha has to calculate how many integers will be written on the board. In order not to get into depression, Masha asked you for help: help her calculate how many numbers she will write, or print "inf" in case she needs to write infinitely many integers.

## Input

The first line of input contains four integers *b*1, *q*, *l*, *m* (-109 ≤ *b*1, *q* ≤ 109, 1 ≤ *l* ≤ 109, 1 ≤ *m* ≤ 105) — the initial term and the common ratio of progression, absolute value of maximal number that can be written on the board and the number of "bad" integers, respectively.

The second line contains *m* distinct integers *a*1, *a*2, ..., *a**m* (-109 ≤ *a**i* ≤ 109) — numbers that will never be written on the board.

## Output

Print the only integer, meaning the number of progression terms that will be written on the board if it is finite, or "inf" (without quotes) otherwise.

## Examples

## Input


```
3 2 30 4  
6 14 25 48  

```
## Output


```
3
```
## Input


```
123 1 2143435 4  
123 11 -5453 141245  

```
## Output


```
0
```
## Input


```
123 1 2143435 4  
54343 -13 6 124  

```
## Output


```
inf
```
## Note

In the first sample case, Masha will write integers 3, 12, 24. Progression term 6 will be skipped because it is a "bad" integer. Terms bigger than 24 won't be written because they exceed *l* by absolute value.

In the second case, Masha won't write any number because all terms are equal 123 and this is a "bad" integer.

In the third case, Masha will write infinitely integers 123. 



#### tags 

#1700 #brute_force #implementation #math 