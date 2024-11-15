<h1 style='text-align: center;'> A. Chores</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Petya and Vasya are brothers. Today is a special day for them as their parents left them home alone and commissioned them to do *n* chores. Each chore is characterized by a single parameter — its complexity. The complexity of the *i*-th chore equals *h**i*.

As Petya is older, he wants to take the chores with complexity larger than some value *x* (*h**i* > *x*) to leave to Vasya the chores with complexity less than or equal to *x* (*h**i* ≤ *x*). The brothers have already decided that Petya will do exactly *a* chores and Vasya will do exactly *b* chores (*a* + *b* = *n*).

In how many ways can they choose an integer *x* so that Petya got exactly *a* chores and Vasya got exactly *b* chores?

## Input

The first input line contains three integers *n*, *a* and *b* (2 ≤ *n* ≤ 2000; *a*, *b* ≥ 1; *a* + *b* = *n*) — the total number of chores, the number of Petya's chores and the number of Vasya's chores.

The next line contains a sequence of integers *h*1, *h*2, ..., *h**n* (1 ≤ *h**i* ≤ 109), *h**i* is the complexity of the *i*-th chore. The numbers in the given sequence are not necessarily different.

All numbers on the lines are separated by single spaces.

## Output

Print the required number of ways to choose an integer value of *x*. If there are no such ways, print 0.

## Examples

## Input


```
5 2 3  
6 2 3 100 1  

```
## Output


```
3  

```
## Input


```
7 3 4  
1 1 9 1 1 1 1  

```
## Output


```
0  

```
## Note

In the first sample the possible values of *x* are 3, 4 or 5.

In the second sample it is impossible to find such *x*, that Petya got 3 chores and Vasya got 4.



#### tags 

#800 #sortings 