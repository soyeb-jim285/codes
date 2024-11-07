<h1 style='text-align: center;'> B. Mahmoud and a Triangle</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Mahmoud has *n* line segments, the *i*-th of them has length *a**i*. Ehab challenged him to use exactly 3 line segments to form a non-degenerate triangle. Mahmoud doesn't accept challenges unless he is sure he can win, so he asked you to tell him if he should accept the challenge. Given the lengths of the line segments, check if he can choose exactly 3 of them to form a non-degenerate triangle.

Mahmoud should use exactly 3 line segments, he can't concatenate two line segments or change any length. A non-degenerate triangle is a triangle with positive area.

## Input

The first line contains single integer *n* (3 ≤ *n* ≤ 105) — the number of line segments Mahmoud has.

The second line contains *n* integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 109) — the lengths of line segments Mahmoud has.

## Output

In the only line print "YES" if he can choose exactly three line segments and form a non-degenerate triangle with them, and "NO" otherwise.

## Examples

## Input


```
5  
1 5 3 2 4  

```
## Output


```
YES  

```
## Input


```
3  
4 1 2  

```
## Output


```
NO  

```
## Note

For the first example, he can use line segments with lengths 2, 4 and 5 to form a non-degenerate triangle.



#### tags 

#1000 #constructive_algorithms #geometry #greedy #math #number_theory #sortings 