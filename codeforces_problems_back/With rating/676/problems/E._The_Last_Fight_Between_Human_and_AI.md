<h1 style='text-align: center;'> E. The Last Fight Between Human and AI</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

100 years have passed since the last victory of the man versus computer in Go. Technologies made a huge step forward and robots conquered the Earth! It's time for the final fight between human and robot that will decide the faith of the planet.

The following game was chosen for the fights: initially there is a polynomial 

*P*(*x*) = *a**n**x**n* + *a**n* - 1*x**n* - 1 + ... + *a*1*x* + *a*0,  with yet undefined coefficients and the integer *k*. Players alternate their turns. At each turn, a player pick some index *j*, such that coefficient *a**j* that stay near *x**j* is not determined yet and sets it to any value (integer or real, positive or negative, 0 is also allowed). Computer moves first. The human will be declared the winner if and only if the resulting polynomial will be divisible by *Q*(*x*) = *x* - *k*.Polynomial *P*(*x*) is said to be divisible by polynomial *Q*(*x*) if there exists a representation *P*(*x*) = *B*(*x*)*Q*(*x*), where *B*(*x*) is also some polynomial.

Some moves have been made already and now you wonder, is it true that human can guarantee the victory if he plays optimally?

## Input

The first line of the input contains two integers *n* and *k* (1 ≤ *n* ≤ 100 000, |*k*| ≤ 10 000) — the size of the polynomial and the integer *k*.

The *i*-th of the following *n* + 1 lines contain character '?' if the coefficient near *x**i* - 1 is yet undefined or the integer value *a**i*, if the coefficient is already known ( - 10 000 ≤ *a**i* ≤ 10 000). Each of integers *a**i* (and even *a**n*) may be equal to 0.

Please note, that it's not guaranteed that you are given the position of the game where it's computer's turn to move.

## Output

Print "Yes" (without quotes) if the human has winning strategy, or "No" (without quotes) otherwise.

## Examples

## Input


```
1 2  
-1  
?  

```
## Output


```
Yes  

```
## Input


```
2 100  
-10000  
0  
1  

```
## Output


```
Yes
```
## Input


```
4 5  
?  
1  
?  
1  
?  

```
## Output


```
No
```
## Note

In the first sample, computer set *a*0 to  - 1 on the first move, so if human can set coefficient *a*1 to 0.5 and win.

In the second sample, all coefficients are already set and the resulting polynomial is divisible by *x* - 100, so the human has won.



#### tags 

#2400 #math 