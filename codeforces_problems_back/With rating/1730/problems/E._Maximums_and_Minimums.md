<h1 style='text-align: center;'> E. Maximums and Minimums</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given an array $a_1, a_2, \ldots, a_n$ of positive integers.

Find the number of pairs of indices $(l, r)$, where $1 \le l \le r \le n$, that pass the check. The check is performed in the following manner: 

1. The minimum and maximum numbers are found among $a_l, a_{l+1}, \ldots, a_r$.
2. The check is passed if the maximum number is divisible by the minimum number.
## Input

The first line contains a single integer $t$ ($1 \le t \le 10$) — the number of test cases. Then the test cases follow.

Each test case consists of two lines.

The first line contains a single integer $n$ ($1 \le n \le 5 \cdot 10^5$) — the size of the array.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^6$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $5 \cdot 10^5$.

## Output

For each test case, print a single integer — the number of pairs of indices that pass the check.

## Example

## Input


```

61122 422 342 4 7 14716 5 18 7 7 12 14616 14 2 6 16 2
```
## Output


```

1
3
2
7
10
19

```
## Note

Below $x \mid y$ denotes that $y$ is divisible by $x$.

In the first test case, there is one pair $(1, 1)$, the maximum for this pair is $1$, the minimum is also $1$, $1 \mid 1$, so the check is passed, and the answer is $1$.

In the second test case, there are $3$ segments: 

* $(1, 1)$: the maximum is $2$, the minimum is $2$, $2 \mid 2$, so the check is passed.
* $(1, 2)$: the maximum is $4$, the minimum is $2$, $2 \mid 4$, so the check is passed.
* $(2, 2)$: the maximum is $4$, the minimum is $4$, $4 \mid 4$, so the check is passed.

In the third test case, there are $3$ segments: 

* $(1, 1)$: the maximum is $2$, the minimum is $2$, $2 \mid 2$, so the check is passed.
* $(1, 2)$: the maximum is $3$, the minimum is $2$, $3$ isn't divisible by $2$, so the check is failed.
* $(2, 2)$: the maximum is $3$, the minimum is $3$, $3 \mid 3$, so the check is passed.


#### tags 

#2700 #combinatorics #data_structures #divide_and_conquer #number_theory 