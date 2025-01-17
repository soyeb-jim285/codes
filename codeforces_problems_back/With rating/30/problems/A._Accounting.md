<h1 style='text-align: center;'> A. Accounting</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A long time ago in some far country lived king Copa. After the recent king's reform, he got so large powers that started to keep the books by himself.

The total income *A* of his kingdom during 0-th year is known, as well as the total income *B* during *n*-th year (these numbers can be negative — it means that there was a loss in the correspondent year). 

King wants to show financial stability. To do this, he needs to find common coefficient *X* — the coefficient of income growth during one year. This coefficient should satisfy the equation:

*A*·*X**n* = *B*.Surely, the king is not going to do this job by himself, and demands you to find such number *X*.

It is necessary to point out that the fractional numbers are not used in kingdom's economy. That's why all input numbers as well as coefficient *X* must be integers. The number *X* may be zero or negative.

## Input

The input contains three integers *A*, *B*, *n* (|*A*|, |*B*| ≤ 1000, 1 ≤ *n* ≤ 10).

## Output

## Output

 the required integer coefficient *X*, or «No solution», if such a coefficient does not exist or it is fractional. If there are several possible solutions, output any of them.

## Examples

## Input


```
2 18 2  

```
## Output


```
3
```
## Input


```
-1 8 3  

```
## Output


```
-2
```
## Input


```
0 0 10  

```
## Output


```
5
```
## Input


```
1 16 5  

```
## Output


```
No solution
```


#### tags 

#1400 #brute_force #math 