<h1 style='text-align: center;'> D. Prefix Permutation Sums</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Your friends have an array of $n$ elements, calculated its array of prefix sums and passed it to you, accidentally losing one element during the transfer. Your task is to find out if the given array can matches permutation.

A permutation of $n$ elements is an array of $n$ numbers from $1$ to $n$ such that each number occurs exactly one times in it.

The array of prefix sums of the array $a$ — is such an array $b$ that $b_i = \sum_{j=1}^i a_j, 1 \le i \le n$.

For example, the original permutation was $[1, 5, 2, 4, 3]$. Its array of prefix sums — $[1, 6, 8, 12, 15]$. Having lost one element, you can get, for example, arrays $[6, 8, 12, 15]$ or $[1, 6, 8, 15]$.

It can also be shown that the array $[1, 2, 100]$ does not correspond to any permutation.

## Input

The first line contains a positive number $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of the test cases follows.

The first line of the description of each test case contains a positive number $n$ ($2 \le n \le 2 \cdot 10^5$) — the size of the initial array.

The second line of the description of each test case contains $n - 1$ positive number $a_i$ ($1 \le a_i \le 10^{18}$), $a_{i-1} < a_i$ — elements of the array of prefix sums.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output "YES" if such a permutation exists, and "NO" otherwise.

You can output "YES" and "NO" in any case (for example, the strings "yEs", "yes" and "Yes" will be recognized as a positive response).

## Example

## Input


```

1256 8 12 1551 6 8 1541 2 10041 3 62231 243 7 1055 44 46 5041 9 10513 21 36 4251 2 3 100000000000000000099 11 12 20 25 28 30 33
```
## Output


```

YES
YES
NO
YES
YES
NO
YES
NO
NO
NO
NO
NO

```
## Note

In the fourth example, for example, the permutation $[1, 2, 3, 4]$ is suitable. In the fifth example, for example, the permutation $[2, 1]$ is suitable. In the seventh example, for example, the permutation $[1, 2, 4, 3]$ is suitable.



#### tags 

#1300 #implementation #math 