<h1 style='text-align: center;'> B. A Trivial Problem</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Mr. Santa asks all the great programmers of the world to solve a trivial problem. He gives them an integer *m* and asks for the number of positive integers *n*, such that the factorial of *n* ends with exactly *m* zeroes. Are you among those great programmers who can solve this problem?

## Input

The only line of input contains an integer *m* (1 ≤ *m* ≤ 100 000) — the required number of trailing zeroes in factorial.

## Output

First print *k* — the number of values of *n* such that the factorial of *n* ends with *m* zeroes. Then print these *k* integers in increasing order.

## Examples

## Input


```
1  

```
## Output


```
5  
5 6 7 8 9 
```
## Input


```
5  

```
## Output


```
0
```
## Note

The factorial of *n* is equal to the product of all integers from 1 to *n* inclusive, that is *n*! = 1·2·3·...·*n*.

In the first sample, 5! = 120, 6! = 720, 7! = 5040, 8! = 40320 and 9! = 362880.



#### tags 

#1300 #brute_force #constructive_algorithms #math #number_theory 