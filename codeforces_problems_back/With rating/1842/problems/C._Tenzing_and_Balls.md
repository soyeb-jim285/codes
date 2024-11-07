<h1 style='text-align: center;'> C. Tenzing and Balls</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Enjoy erasing Tenzing, identified as Accepted!Tenzing has $n$ balls arranged in a line. The color of the $i$-th ball from the left is $a_i$.

Tenzing can do the following operation any number of times:

* select $i$ and $j$ such that $1\leq i < j \leq |a|$ and $a_i=a_j$,
* remove $a_i,a_{i+1},\ldots,a_j$ from the array (and decrease the indices of all elements to the right of $a_j$ by $j-i+1$).

Tenzing wants to know the maximum number of balls he can remove.

## Input

Each test contains multiple test cases. The first line of input contains a single integer $t$ ($1\leq t\leq 10^3$) — the number of test cases. The description of test cases follows.

The first line contains a single integer $n$ ($1\leq n\leq 2\cdot 10^5$) — the number of balls.

The second line contains $n$ integers $a_1,a_2,\ldots,a_n$ ($1\leq a_i \leq n$) — the color of the balls.

It is guaranteed that sum of $n$ of all test cases will not exceed $2\cdot 10^5$.

## Output

For each test case, output the maximum number of balls Tenzing can remove.

## Example

## Input


```

251 2 2 3 341 2 1 2
```
## Output


```

4
3

```
## Note

In the first example, Tenzing will choose $i=2$ and $j=3$ in the first operation so that $a=[1,3,3]$. Then Tenzing will choose $i=2$ and $j=3$ again in the second operation so that $a=[1]$. So Tenzing can remove $4$ balls in total.

In the second example, Tenzing will choose $i=1$ and $j=3$ in the first and only operation so that $a=[2]$. So Tenzing can remove $3$ balls in total.



#### tags 

#1500 #dp 