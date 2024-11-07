<h1 style='text-align: center;'> A. Maximize the Last Element</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ of $n$ integers, where $n$ is odd.

In one operation, you will remove two adjacent elements from the array $a$, and then concatenate the remaining parts of the array. For example, given the array $[4,7,4,2,9]$, we can obtain the arrays $[4,2,9]$ and $[4,7,9]$ by the operations $[\underline{4,7}, 4,2,9] \to [4,2,9]$ and $[4,7,\underline{4,2},9] \to [4,7,9]$ respectively. However, we cannot obtain the array $[7,2,9]$ as it requires deleting non-adjacent elements $[\underline{4},7,\underline{4},2,9]$.

You will repeatedly perform this operation until exactly one element remains in $a$.

Find the maximum possible value of the remaining element in $a$.

## Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 99$; $n$ is odd) — the length of the array $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 100$) — the elements of the array $a$.

## Note

 that there is no bound on the sum of $n$ over all test cases.

## Output

For each test case, output a single integer — the maximum possible value of the remaining element in $a$.

## Example

## Input


```

41631 3 254 7 4 2 973 1 4 1 5 9 2
```
## Output


```

6
2
9
5

```
## Note

In the first test case, the array $a$ is $[6]$. Since there is only one element, no operations are needed. The maximum possible value of the remaining element is $6$.

In the second test case, the array $a$ is $[1, 3, 2]$. We can remove the first two elements $[\underline{1, 3}, 2] \to [2]$, or remove the last two elements $[1, \underline{3, 2}] \to [1]$. Therefore, the maximum possible value of the remaining element is $2$.

In the third test case, the array $a$ is $[4, 7, 4, 2, 9]$. One way to maximize the remaining element is $[4, \underline{7, 4}, 2, 9] \to [\underline{4, 2}, 9] \to [9]$. Therefore, the maximum possible value of the remaining element is $9$.

In the fourth test case, the array $a$ is $[3, 1, 4, 1, 5, 9, 2]$. It can be shown that the maximum possible value of the remaining element is $5$.



#### tags 

#greedy #implementation 