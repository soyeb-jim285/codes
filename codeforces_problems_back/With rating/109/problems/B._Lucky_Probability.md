<h1 style='text-align: center;'> B. Lucky Probability</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Petya loves lucky numbers. We all know that lucky numbers are the positive integers whose decimal representations contain only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

Petya and his friend Vasya play an interesting game. Petya randomly chooses an integer *p* from the interval [*p**l*, *p**r*] and Vasya chooses an integer *v* from the interval [*v**l*, *v**r*] (also randomly). Both players choose their integers equiprobably. Find the probability that the interval [*min*(*v*, *p*), *max*(*v*, *p*)] contains exactly *k* lucky numbers.

## Input

The single line contains five integers *p**l*, *p**r*, *v**l*, *v**r* and *k* (1 ≤ *p**l* ≤ *p**r* ≤ 109, 1 ≤ *v**l* ≤ *v**r* ≤ 109, 1 ≤ *k* ≤ 1000).

## Output

On the single line print the result with an absolute error of no more than 10- 9.

## Examples

## Input


```
1 10 1 10 2  

```
## Output


```
0.320000000000  

```
## Input


```
5 6 8 10 1  

```
## Output


```
1.000000000000  

```
## Note

Consider that [*a*, *b*] denotes an interval of integers; this interval includes the boundaries. That is, ![](images/18b4a6012d95ad18891561410f0314497a578d63.png)

In first case there are 32 suitable pairs: (1, 7), (1, 8), (1, 9), (1, 10), (2, 7), (2, 8), (2, 9), (2, 10), (3, 7), (3, 8), (3, 9), (3, 10), (4, 7), (4, 8), (4, 9), (4, 10), (7, 1), (7, 2), (7, 3), (7, 4), (8, 1), (8, 2), (8, 3), (8, 4), (9, 1), (9, 2), (9, 3), (9, 4), (10, 1), (10, 2), (10, 3), (10, 4). Total number of possible pairs is 10·10 = 100, so answer is 32 / 100.

In second case Petya always get number less than Vasya and the only lucky 7 is between this numbers, so there will be always 1 lucky number.



#### tags 

#1900 #brute_force #probabilities 