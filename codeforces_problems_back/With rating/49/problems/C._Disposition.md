<h1 style='text-align: center;'> C. Disposition</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya bought the collected works of a well-known Berland poet Petya in *n* volumes. The volumes are numbered from 1 to *n*. He thinks that it does not do to arrange the book simply according to their order. Vasya wants to minimize the number of the disposition’s divisors — the positive integers *i* such that for at least one *j* (1 ≤ *j* ≤ *n*) is true both: *j* *mod* *i* = 0 and at the same time *p*(*j*) *mod* *i* = 0, where *p*(*j*) is the number of the tome that stands on the *j*-th place and *mod* is the operation of taking the division remainder. Naturally, one volume can occupy exactly one place and in one place can stand exactly one volume.

Help Vasya — find the volume disposition with the minimum number of divisors.

## Input

The first line contains number *n* (1 ≤ *n* ≤ 100000) which represents the number of volumes and free places.

## Output

Print *n* numbers — the sought disposition with the minimum divisor number. The *j*-th number (1 ≤ *j* ≤ *n*) should be equal to *p*(*j*) — the number of tome that stands on the *j*-th place. If there are several solutions, print any of them.

## Examples

## Input


```
2  

```
## Output


```
2 1   

```
## Input


```
3  

```
## Output


```
1 3 2   

```


#### tags 

#1700 #constructive_algorithms #math 