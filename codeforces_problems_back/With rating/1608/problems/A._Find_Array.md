<h1 style='text-align: center;'> A. Find Array</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given $n$, find any array $a_1, a_2, \ldots, a_n$ of integers such that all of the following conditions hold: 

* $1 \le a_i \le 10^9$ for every $i$ from $1$ to $n$.
* $a_1 < a_2 < \ldots <a_n$
* For every $i$ from $2$ to $n$, $a_i$ isn't divisible by $a_{i-1}$

It can be shown that such an array always exists under the constraints of the problem.

## Input

The first line contains the number of test cases $t$ ($1 \le t \le 100$). Description of the test cases follows.

The only line of each test case contains a single integer $n$ ($1 \le n \le 1000$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^4$.

## Output

For each test case print $n$ integers $a_1, a_2, \ldots, a_n$ — the array you found. If there are multiple arrays satisfying all the conditions, print any of them.

## Example

## Input


```

3
1
2
7

```
## Output


```

1
2 3
111 1111 11111 111111 1111111 11111111 111111111
```
## Note

In the first test case, array $[1]$ satisfies all the conditions.

In the second test case, array $[2, 3]$ satisfies all the conditions, as $2<3$ and $3$ is not divisible by $2$.

In the third test case, array $[111, 1111, 11111, 111111, 1111111, 11111111, 111111111]$ satisfies all the conditions, as it's increasing and $a_i$ isn't divisible by $a_{i-1}$ for any $i$ from $2$ to $7$.



#### tags 

#800 #constructive_algorithms #math 