<h1 style='text-align: center;'> D. Fibonacci Sums</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Fibonacci numbers have the following form:

*F*1 = 1,  *F*2 = 2,  *F**i* = *F**i* - 1 + *F**i* - 2, *i* > 2.Let's consider some non-empty set *S* = {*s*1, *s*2, ..., *s**k*}, consisting of different Fibonacci numbers. Let's find the sum of values of this set's elements:

![](images/078fe60cbaeb68b0519782c39448778a5dbfe3b7.png)Let's call the set *S* a number *n*'s decomposition into Fibonacci sum. 

It's easy to see that several numbers have several decompositions into Fibonacci sum. For example, for 13 we have 13, 5 + 8, 2 + 3 + 8 — three decompositions, and for 16: 3 + 13, 1 + 2 + 13, 3 + 5 + 8, 1 + 2 + 5 + 8 — four decompositions.

By the given number *n* determine the number of its possible different decompositions into Fibonacci sum.

## Input

The first line contains an integer *t* — the number of tests (1 ≤ *t* ≤ 105). Each of the following *t* lines contains one test.

Each test is an integer *n* (1 ≤ *n* ≤ 1018).

Please do not use the %lld specificator to read or write 64-bit integers in C++. It is preferred to use the cin, cout streams or the %I64d specificator.

## Output

For each input data test print a single number on a single line — the answer to the problem.

## Examples

## Input


```
2  
13  
16  

```
## Output


```
3  
4  

```
## Note

Two decompositions are different if there exists a number that is contained in the first decomposition, but is not contained in the second one. Decompositions that differ only in the order of summands are considered equal.



#### tags 

#2300 #dp #math 