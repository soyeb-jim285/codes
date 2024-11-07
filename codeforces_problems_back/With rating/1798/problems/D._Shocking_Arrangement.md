<h1 style='text-align: center;'> D. Shocking Arrangement</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a_1, a_2, \ldots, a_n$ consisting of integers such that $a_1 + a_2 + \ldots + a_n = 0$.

You have to rearrange the elements of the array $a$ so that the following condition is satisfied:

$$\max\limits_{1 \le l \le r \le n} \lvert a_l + a_{l+1} + \ldots + a_r \rvert < \max(a_1, a_2, \ldots, a_n) - \min(a_1, a_2, \ldots, a_n),$$ where $|x|$ denotes the absolute value of $x$.

More formally, determine if there exists a permutation $p_1, p_2, \ldots, p_n$ that for the array $a_{p_1}, a_{p_2}, \ldots, a_{p_n}$, the condition above is satisfied, and find the corresponding array.

Recall that the array $p_1, p_2, \ldots, p_n$ is called a permutation if for each integer $x$ from $1$ to $n$ there is exactly one $i$ from $1$ to $n$ such that $p_i = x$.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 50\,000$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 300\,000$) — the length of the array $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($-10^9 \le a_i \le 10^9$) — elements of the array $a$. It is guaranteed that the sum of the array $a$ is zero, in other words: $a_1 + a_2 + \ldots + a_n = 0$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $300\,000$.

## Output

For each test case, if it is impossible to rearrange the elements of the array $a$ in the required way, print "No" in a single line.

If possible, print "Yes" in the first line, and then in a separate line $n$ numbers — elements $a_1, a_2, \ldots, a_n$ rearranged in a valid order ($a_{p_1}, a_{p_2}, \ldots, a_{p_n}$).

If there are several possible answers, you can output any of them.

## Example

## Input


```

7
4
3 4 -2 -5
5
2 2 2 -3 -3
8
-3 -3 1 1 1 1 1 1
3
0 1 -1
7
-3 4 3 4 -4 -4 0
1
0
7
-18 13 -18 -17 12 15 13

```
## Output


```

Yes
-5 -2 3 4
Yes
-3 2 -3 2 2
Yes
1 1 1 -3 1 1 1 -3
Yes
-1 0 1
Yes
4 -4 4 -4 0 3 -3
No
Yes
13 12 -18 15 -18 13 -17

```
## Note

In the first test case $\max(a_1, \ldots, a_n) - \min(a_1, \ldots, a_n) = 9$. Therefore, the elements can be rearranged as $[-5, -2, 3, 4]$. It is easy to see that for such an arrangement $\lvert a_l + \ldots + a_r \rvert$ is always not greater than $7$, and therefore less than $9$.

In the second test case you can rearrange the elements of the array as $[-3, 2, -3, 2, 2]$. Then the maximum modulus of the sum will be reached on the subarray $[-3, 2, -3]$, and will be equal to $\lvert -3 + 2 + -3 \rvert = \lvert -4 \rvert = 4$, which is less than $5$.

In the fourth test example, any rearrangement of the array $a$ will be suitable as an answer, including $[-1, 0, 1]$.



#### tags 

#1600 #constructive_algorithms #greedy #math 