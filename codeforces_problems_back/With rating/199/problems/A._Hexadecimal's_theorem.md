<h1 style='text-align: center;'> A. Hexadecimal's theorem</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Recently, a chaotic virus Hexadecimal advanced a new theorem which will shake the Universe. She thinks that each Fibonacci number can be represented as sum of three not necessary different Fibonacci numbers.

Let's remember how Fibonacci numbers can be calculated. *F*0 = 0, *F*1 = 1, and all the next numbers are *F**i* = *F**i* - 2 + *F**i* - 1.

So, Fibonacci numbers make a sequence of numbers: 0, 1, 1, 2, 3, 5, 8, 13, ...

If you haven't run away from the PC in fear, you have to help the virus. Your task is to divide given Fibonacci number *n* by three not necessary different Fibonacci numbers or say that it is impossible.

## Input

The input contains of a single integer *n* (0 ≤ *n* < 109) — the number that should be represented by the rules described above. It is guaranteed that *n* is a Fibonacci number.

## Output

## Output

 three required numbers: *a*, *b* and *c*. If there is no answer for the test you have to print "I'm too stupid to solve this problem" without the quotes.

If there are multiple answers, print any of them.

## Examples

## Input


```
3  

```
## Output


```
1 1 1  

```
## Input


```
13  

```
## Output


```
2 3 8  

```


#### tags 

#900 #brute_force #constructive_algorithms #implementation #number_theory 