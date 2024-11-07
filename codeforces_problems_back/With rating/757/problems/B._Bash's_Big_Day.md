<h1 style='text-align: center;'> B. Bash's Big Day</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Bash has set out on a journey to become the greatest Pokemon master. To get his first Pokemon, he went to Professor Zulu's Lab. Since Bash is Professor Zulu's favourite student, Zulu allows him to take as many Pokemon from his lab as he pleases.

But Zulu warns him that a group of *k* > 1 Pokemon with strengths {*s*1, *s*2, *s*3, ..., *s**k*} tend to fight among each other if *gcd*(*s*1, *s*2, *s*3, ..., *s**k*) = 1 (see notes for *gcd* definition).

Bash, being smart, does not want his Pokemon to fight among each other. However, he also wants to maximize the number of Pokemon he takes from the lab. Can you help Bash find out the maximum number of Pokemon he can take? 

## Note

: A Pokemon cannot fight with itself.

## Input

The input consists of two lines.

The first line contains an integer *n* (1 ≤ *n* ≤ 105), the number of Pokemon in the lab.

The next line contains *n* space separated integers, where the *i*-th of them denotes *s**i* (1 ≤ *s**i* ≤ 105), the strength of the *i*-th Pokemon.

## Output

Print single integer — the maximum number of Pokemons Bash can take.

## Examples

## Input


```
3  
2 3 4  

```
## Output


```
2  

```
## Input


```
5  
2 3 4 6 7  

```
## Output


```
3  

```
## Note

*gcd* (greatest common divisor) of positive integers set {*a*1, *a*2, ..., *a**n*} is the maximum positive integer that divides all the integers {*a*1, *a*2, ..., *a**n*}.

In the first sample, we can take Pokemons with strengths {2, 4} since *gcd*(2, 4) = 2.

In the second sample, we can take Pokemons with strengths {2, 4, 6}, and there is no larger group with *gcd* ≠ 1.



#### tags 

#1400 #greedy #math #number_theory 