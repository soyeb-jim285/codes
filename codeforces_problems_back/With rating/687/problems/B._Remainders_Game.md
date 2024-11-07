<h1 style='text-align: center;'> B. Remainders Game</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Today Pari and Arya are playing a game called Remainders.

Pari chooses two positive integer *x* and *k*, and tells Arya *k* but not *x*. Arya have to find the value ![](images/fddd3bb34fa9f786754485afa55927f021d74d15.png). There are *n* ancient numbers *c*1, *c*2, ..., *c**n* and Pari has to tell Arya ![](images/fbb55ab61f79d427b1a3d23470b55aa433de55e7.png) if Arya wants. Given *k* and the ancient values, tell us if Arya has a winning strategy independent of value of *x* or not. Formally, is it true that Arya can understand the value ![](images/fddd3bb34fa9f786754485afa55927f021d74d15.png) for any positive integer *x*?

## Note

, that ![](images/f58f159973d4609d919286c1821e69cd34d81118.png) means the remainder of *x* after dividing it by *y*.

## Input

The first line of the input contains two integers *n* and *k* (1 ≤ *n*,  *k* ≤ 1 000 000) — the number of ancient integers and value *k* that is chosen by Pari.

The second line contains *n* integers *c*1, *c*2, ..., *c**n* (1 ≤ *c**i* ≤ 1 000 000).

## Output

Print "Yes" (without quotes) if Arya has a winning strategy independent of value of *x*, or "No" (without quotes) otherwise.

## Examples

## Input


```
4 5  
2 3 5 12  

```
## Output


```
Yes  

```
## Input


```
2 7  
2 3  

```
## Output


```
No  

```
## Note

In the first sample, Arya can understand ![](images/d170efffcde0907ee6bcf32de21051bce0677a2c.png) because 5 is one of the ancient numbers.

In the second sample, Arya can't be sure what ![](images/57b5f6a96f5db073270dd3ed4266c69299ec701d.png) is. For example 1 and 7 have the same remainders after dividing by 2 and 3, but they differ in remainders after dividing by 7.



#### tags 

#1800 #chinese_remainder_theorem #math #number_theory 