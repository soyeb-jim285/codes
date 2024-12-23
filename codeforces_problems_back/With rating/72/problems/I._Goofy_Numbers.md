<h1 style='text-align: center;'> I. Goofy Numbers</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The non-negative integer *a* is a divisor of the non-negative integer *b* if and only if there exists a positive integer *c* such that *a* × *c* = *b*. 

Some numbers are really interesting. Commander Surena defines some interesting properties for non-negative integers:

* An integer is happy if it is divisible by at least one of its digits and not by all of them.
* An integer is happier if it is divisible by all of its digits.
* An integer is upset if it's divisible by none of its digits.

Surena asks you to find out if a given number is happy, happier or upset.

## Input

## Input

 contains a single non-negative integer *n* (1 ≤ *n* ≤ 108).

## Output

Write on a single line the type of the integer: happy, happier or upset. Print the type in lowercase letters.

## Examples

## Input


```
99  

```
## Output


```
happier  

```
## Input


```
29994  

```
## Output


```
happy  

```
## Input


```
23  

```
## Output


```
upset  

```
## Note

In the second test 29994 is only divisible by 2.

In the third test 23 is a prime number.



#### tags 

#1500 #*special #implementation 