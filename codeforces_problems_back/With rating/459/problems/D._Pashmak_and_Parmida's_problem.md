<h1 style='text-align: center;'> D. Pashmak and Parmida's problem</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Parmida is a clever girl and she wants to participate in Olympiads this year. Of course she wants her partner to be clever too (although he's not)! Parmida has prepared the following test problem for Pashmak.

There is a sequence *a* that consists of *n* integers *a*1, *a*2, ..., *a**n*. Let's denote *f*(*l*, *r*, *x*) the number of indices *k* such that: *l* ≤ *k* ≤ *r* and *a**k* = *x*. His task is to calculate the number of pairs of indicies *i*, *j* (1 ≤ *i* < *j* ≤ *n*) such that *f*(1, *i*, *a**i*) > *f*(*j*, *n*, *a**j*).

Help Pashmak with the test.

## Input

The first line of the input contains an integer *n* (1 ≤ *n* ≤ 106). The second line contains *n* space-separated integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 109).

## Output

Print a single integer — the answer to the problem.

## Examples

## Input


```
7  
1 2 1 1 2 2 1  

```
## Output


```
8  

```
## Input


```
3  
1 1 1  

```
## Output


```
1  

```
## Input


```
5  
1 2 3 4 5  

```
## Output


```
0  

```


#### tags 

#1800 #data_structures #divide_and_conquer #sortings 