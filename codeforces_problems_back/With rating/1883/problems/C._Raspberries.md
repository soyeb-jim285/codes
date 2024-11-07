<h1 style='text-align: center;'> C. Raspberries</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array of integers $a_1, a_2, \ldots, a_n$ and a number $k$ ($2 \leq k \leq 5$). In one operation, you can do the following:

* Choose an index $1 \leq i \leq n$,
* Set $a_i = a_i + 1$.

Find the minimum number of operations needed to make the product of all the numbers in the array $a_1 \cdot a_2 \cdot \ldots \cdot a_n$ divisible by $k$.

## Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. Then follows the description of the test cases.

The first line of each test case contains two integers $n$ and $k$ ($2 \leq n \leq 10^5$, $2 \leq k \leq 5$) — the size of the array $a$ and the number $k$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq 10$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output the minimum number of operations needed to make the product of all the numbers in the array divisible by $k$.

## Example

## Input


```

152 57 33 37 4 15 29 7 7 3 95 55 4 1 2 37 49 5 1 5 9 5 13 46 3 63 46 1 53 41 5 94 41 4 1 13 43 5 34 58 9 9 32 51 62 510 104 51 6 1 12 57 7
```
## Output


```

2
2
1
0
2
0
1
2
0
1
1
4
0
4
3

```
## Note

In the first test case, we need to choose the index $i = 2$ twice. After that, the array will be $a = [7, 5]$. The product of all the numbers in the array is $35$.

In the fourth test case, the product of the numbers in the array is $120$, which is already divisible by $5$, so no operations are needed.

In the eighth test case, we can perform two operations by choosing $i = 2$ and $i = 3$ in any order. After that, the array will be $a = [1, 6, 10]$. The product of the numbers in the array is $60$.



#### tags 

#1000 #dp #math 