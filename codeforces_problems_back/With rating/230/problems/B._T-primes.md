<h1 style='text-align: center;'> B. T-primes</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

We know that prime numbers are positive integers that have exactly two distinct positive divisors. Similarly, we'll call a positive integer *t* Т-prime, if *t* has exactly three distinct positive divisors.

You are given an array of *n* positive integers. For each of them determine whether it is Т-prime or not.

## Input

The first line contains a single positive integer, *n* (1 ≤ *n* ≤ 105), showing how many numbers are in the array. The next line contains *n* space-separated integers *x**i* (1 ≤ *x**i* ≤ 1012).

Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is advised to use the cin, cout streams or the %I64d specifier.

## Output

Print *n* lines: the *i*-th line should contain "YES" (without the quotes), if number *x**i* is Т-prime, and "NO" (without the quotes), if it isn't.

## Examples

## Input


```
3  
4 5 6  

```
## Output


```
YES  
NO  
NO  

```
## Note

The given test has three numbers. The first number 4 has exactly three divisors — 1, 2 and 4, thus the answer for this number is "YES". The second number 5 has two divisors (1 and 5), and the third number 6 has four divisors (1, 2, 3, 6), hence the answer for them is "NO".



#### tags 

#1300 #binary_search #implementation #math #number_theory 