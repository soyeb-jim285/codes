<h1 style='text-align: center;'> E. Sereja and Intervals</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Sereja is interested in intervals of numbers, so he has prepared a problem about intervals for you. An interval of numbers is a pair of integers [*l*, *r*] (1 ≤ *l* ≤ *r* ≤ *m*). Interval [*l*1, *r*1] belongs to interval [*l*2, *r*2] if the following condition is met: *l*2 ≤ *l*1 ≤ *r*1 ≤ *r*2.

Sereja wants to write out a sequence of *n* intervals [*l*1, *r*1], [*l*2, *r*2], ..., [*l**n*, *r**n*] on a piece of paper. At that, no interval in the sequence can belong to some other interval of the sequence. Also, Sereja loves number *x* very much and he wants some (at least one) interval in the sequence to have *l**i* = *x*. Sereja wonders, how many distinct ways to write such intervals are there?

Help Sereja and find the required number of ways modulo 1000000007 (109 + 7).

Two ways are considered distinct if there is such *j* (1 ≤ *j* ≤ *n*), that the *j*-th intervals in two corresponding sequences are not equal.

## Input

The first line contains integers *n*, *m*, *x* (1 ≤ *n*·*m* ≤ 100000, 1 ≤ *x* ≤ *m*) — the number of segments in the sequence, the constraints on the numbers in segments and Sereja's favourite number.

## Output

In a single line print the answer modulo 1000000007 (109 + 7).

## Examples

## Input


```
1 1 1  

```
## Output


```
1  

```
## Input


```
3 5 1  

```
## Output


```
240  

```
## Input


```
2 3 3  

```
## Output


```
6  

```
## Note

In third example next sequences will be correct: {[1, 1], [3, 3]}, {[1, 2], [3, 3]}, {[2, 2], [3, 3]}, {[3, 3], [1, 1]}, {[3, 3], [2, 2]}, {[3, 3], [1, 2]}.



#### tags 

#2700 #combinatorics #dp 