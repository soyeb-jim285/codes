<h1 style='text-align: center;'> A. Sasha and the Beautiful Array</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Sasha decided to give his girlfriend an array $a_1, a_2, \ldots, a_n$. He found out that his girlfriend evaluates the beauty of the array as the sum of the values $(a_i - a_{i - 1})$ for all integers $i$ from $2$ to $n$.

Help Sasha and tell him the maximum beauty of the array $a$ that he can obtain, if he can rearrange its elements in any way.

## Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 500$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($2 \leq n \leq 100$) — the length of the array $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq 10^9$) — the elements of the array $a$.

## Output

For each test case, output a single integer — the maximum beauty of the array $a$ that can be obtained.

## Example

## Input


```

532 1 3369 69 695100 54 80 43 9043 4 3 322 1
```
## Output


```

2
0
57
1
1

```
## Note

In the first test case, the elements of the array $a$ can be rearranged to make $a = [1, 2, 3]$. Then its beauty will be equal to $(a_2 - a_1) + (a_3 - a_2) = (2 - 1) + (3 - 2) = 2$.

In the second test case, there is no need to rearrange the elements of the array $a$. Then its beauty will be equal to $0$.



#### tags 

#800 #constructive_algorithms #greedy #math #sortings 