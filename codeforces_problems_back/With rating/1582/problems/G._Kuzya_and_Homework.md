<h1 style='text-align: center;'> G. Kuzya and Homework</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Kuzya started going to school. He was given math homework in which he was given an array $a$ of length $n$ and an array of symbols $b$ of length $n$, consisting of symbols '*' and '/'.

Let's denote a path of calculations for a segment $[l; r]$ ($1 \le l \le r \le n$) in the following way: 

* Let $x=1$ initially. For every $i$ from $l$ to $r$ we will consequently do the following: if $b_i=$ '*', $x=x*a_i$, and if $b_i=$ '/', then $x=\frac{x}{a_i}$. Let's call a path of calculations for the segment $[l; r]$ a list of all $x$ that we got during the calculations (the number of them is exactly $r - l + 1$).

For example, let $a=[7,$ $12,$ $3,$ $5,$ $4,$ $10,$ $9]$, $b=[/,$ $*,$ $/,$ $/,$ $/,$ $*,$ $*]$, $l=2$, $r=6$, then the path of calculations for that segment is $[12,$ $4,$ $0.8,$ $0.2,$ $2]$.

Let's call a segment $[l;r]$ simple if the path of calculations for it contains only integer numbers. 

Kuzya needs to find the number of simple segments $[l;r]$ ($1 \le l \le r \le n$). Since he obviously has no time and no interest to do the calculations for each option, he asked you to write a program to get to find that number!

## Input

The first line contains a single integer $n$ ($2 \le n \le 10^6$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^6$).

The third line contains $n$ symbols without spaces between them — the array $b_1, b_2 \ldots b_n$ ($b_i=$ '/' or $b_i=$ '*' for every $1 \le i \le n$).

## Output

Print a single integer — the number of simple segments $[l;r]$.

## Examples

## Input


```

3
1 2 3
*/*

```
## Output


```

2

```
## Input


```

7
6 4 10 1 2 15 1
*/*/*//

```
## Output


```

8

```


#### tags 

#2600 #data_structures #number_theory 