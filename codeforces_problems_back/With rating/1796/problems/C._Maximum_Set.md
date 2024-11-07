<h1 style='text-align: center;'> C. Maximum Set</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

A set of positive integers $S$ is called beautiful if, for every two integers $x$ and $y$ from this set, either $x$ divides $y$ or $y$ divides $x$ (or both).

You are given two integers $l$ and $r$. Consider all beautiful sets consisting of integers not less than $l$ and not greater than $r$. You have to print two numbers:

* the maximum possible size of a beautiful set where all elements are from $l$ to $r$;
* the number of beautiful sets consisting of integers from $l$ to $r$ with the maximum possible size.

Since the second number can be very large, print it modulo $998244353$.

## Input

The first line contains one integer $t$ ($1 \le t \le 2 \cdot 10^4$) — the number of test cases.

Each test case consists of one line containing two integers $l$ and $r$ ($1 \le l \le r \le 10^6$).

## Output

For each test case, print two integers — the maximum possible size of a beautiful set consisting of integers from $l$ to $r$, and the number of such sets with maximum possible size. Since the second number can be very large, print it modulo $998244353$.

## Example

## Input


```

43 1113 371 224 100
```
## Output


```

2 4
2 6
5 1
5 7

```
## Note

In the first test case, the maximum possible size of a beautiful set with integers from $3$ to $11$ is $2$. There are $4$ such sets which have the maximum possible size:

* $\{ 3, 6 \}$;
* $\{ 3, 9 \}$;
* $\{ 4, 8 \}$;
* $\{ 5, 10 \}$.


#### tags 

#1600 #binary_search #math 