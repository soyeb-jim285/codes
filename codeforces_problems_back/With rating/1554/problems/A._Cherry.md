<h1 style='text-align: center;'> A. Cherry</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given $n$ integers $a_1, a_2, \ldots, a_n$. Find the maximum value of $max(a_l, a_{l + 1}, \ldots, a_r) \cdot min(a_l, a_{l + 1}, \ldots, a_r)$ over all pairs $(l, r)$ of integers for which $1 \le l < r \le n$.

## Input

The first line contains a single integer $t$ ($1 \le t \le 10\,000$)  — the number of test cases.

The first line of each test case contains a single integer $n$ ($2 \le n \le 10^5$).

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^6$).

It is guaranteed that the sum of $n$ over all test cases doesn't exceed $3 \cdot 10^5$.

## Output

For each test case, print a single integer  — the maximum possible value of the product from the statement.

## Example

## Input


```

4
3
2 4 3
4
3 2 3 1
2
69 69
6
719313 273225 402638 473783 804745 323328

```
## Output


```

12
6
4761
381274500335

```
## Note

Let $f(l, r) = max(a_l, a_{l + 1}, \ldots, a_r) \cdot min(a_l, a_{l + 1}, \ldots, a_r)$.

In the first test case, 

* $f(1, 2) = max(a_1, a_2) \cdot min(a_1, a_2) = max(2, 4) \cdot min(2, 4) = 4 \cdot 2 = 8$.
* $f(1, 3) = max(a_1, a_2, a_3) \cdot min(a_1, a_2, a_3) = max(2, 4, 3) \cdot min(2, 4, 3) = 4 \cdot 2 = 8$.
* $f(2, 3) = max(a_2, a_3) \cdot min(a_2, a_3) = max(4, 3) \cdot min(4, 3) = 4 \cdot 3 = 12$.

So the maximum is $f(2, 3) = 12$.

In the second test case, the maximum is $f(1, 2) = f(1, 3) = f(2, 3) = 6$.



#### tags 

#800 #greedy 