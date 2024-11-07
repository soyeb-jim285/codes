<h1 style='text-align: center;'> B. Odd Swap Sort</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a_1, a_2, \dots, a_n$. You can perform operations on the array. In each operation you can choose an integer $i$ ($1 \le i < n$), and swap elements $a_i$ and $a_{i+1}$ of the array, if $a_i + a_{i+1}$ is odd.

Determine whether it can be sorted in non-decreasing order using this operation any number of times.

## Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^5$) — the number of test cases. Description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 10^5$) — the length of the array.

The second line of each test case contains $n$ integers $a_1,a_2, \dots, a_n$ ($1 \le a_i \le 10^9$) — the elements of the array.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, print "Yes" or "No" depending on whether you can or can not sort the given array.

You may print each letter in any case (for example, "YES", "Yes", "yes", "yEs" will all be recognized as positive answer).

## Example

## Input


```

441 6 31 1424 252 9 6 7 1036 6 6
```
## Output


```

Yes
No
No
Yes

```
## Note

In the first test case, we can simply swap $31$ and $14$ ($31 + 14 = 45$ which is odd) and obtain the non-decreasing array $[1,6,14,31]$.

In the second test case, the only way we could sort the array is by swapping $4$ and $2$, but this is impossible, since their sum $4 + 2 = 6$ is even.

In the third test case, there is no way to make the array non-decreasing.

In the fourth test case, the array is already non-decreasing.



#### tags 

#1100 #data_structures #math #sortings 