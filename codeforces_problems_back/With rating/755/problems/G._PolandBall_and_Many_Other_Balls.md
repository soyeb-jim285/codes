<h1 style='text-align: center;'> G. PolandBall and Many Other Balls</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

PolandBall is standing in a row with Many Other Balls. More precisely, there are exactly *n* Balls. Balls are proud of their home land — and they want to prove that it's strong.

The Balls decided to start with selecting exactly *m* groups of Balls, each consisting either of single Ball or two neighboring Balls. Each Ball can join no more than one group.

The Balls really want to impress their Enemies. They kindly asked you to calculate number of such divisions for all *m* where 1 ≤ *m* ≤ *k*. ## Output

 all these values modulo 998244353, the Enemies will be impressed anyway.

## Input

There are exactly two numbers *n* and *k* (1 ≤ *n* ≤ 109, 1 ≤ *k* < 215), denoting the number of Balls and the maximim number of groups, respectively.

## Output

You should output a sequence of *k* values. The *i*-th of them should represent the sought number of divisions into exactly *i* groups, according to PolandBall's rules.

## Examples

## Input


```
3 3  

```
## Output


```
5 5 1 
```
## Input


```
1 1  

```
## Output


```
1 
```
## Input


```
5 10  

```
## Output


```
9 25 25 9 1 0 0 0 0 0 
```
## Note

In the first sample case we can divide Balls into groups as follows: 

{1}, {2}, {3}, {12}, {23}.

{12}{3}, {1}{23}, {1}{2}, {1}{3}, {2}{3}.

{1}{2}{3}.

Therefore, output is: 5 5 1.



#### tags 

#3200 #combinatorics #divide_and_conquer #dp #fft #math #number_theory 