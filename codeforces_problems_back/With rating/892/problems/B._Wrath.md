<h1 style='text-align: center;'> B. Wrath</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Hands that shed innocent blood!

There are *n* guilty people in a line, the *i*-th of them holds a claw with length *L**i*. The bell rings and every person kills some of people in front of him. All people kill others at the same time. Namely, the *i*-th person kills the *j*-th person if and only if *j* < *i* and *j* ≥ *i* - *L**i*.

You are given lengths of the claws. You need to find the total number of alive people after the bell rings.

## Input

The first line contains one integer *n* (1 ≤ *n* ≤ 106) — the number of guilty people.

Second line contains *n* space-separated integers *L*1, *L*2, ..., *L**n* (0 ≤ *L**i* ≤ 109), where *L**i* is the length of the *i*-th person's claw.

## Output

Print one integer — the total number of alive people after the bell rings.

## Examples

## Input


```
4  
0 1 0 10  

```
## Output


```
1  

```
## Input


```
2  
0 0  

```
## Output


```
2  

```
## Input


```
10  
1 1 3 0 0 0 2 1 0 3  

```
## Output


```
3  

```
## Note

In first sample the last person kills everyone in front of him.



#### tags 

#1200 #greedy #implementation #two_pointers 