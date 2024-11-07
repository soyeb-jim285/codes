<h1 style='text-align: center;'> A. Doremy's Paint 3</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

An array $b_1, b_2, \ldots, b_n$ of positive integers is good if all the sums of two adjacent elements are equal to the same value. More formally, the array is good if there exists a $k$ such that $b_1 + b_2 = b_2 + b_3 = \ldots = b_{n-1} + b_n = k$.

Doremy has an array $a$ of length $n$. Now Doremy can permute its elements (change their order) however she wants. Determine if she can make the array good.

## Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1\le t\le 100$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($2 \le n \le 100$) — the length of the array $a$.

The second line of each test case contains $ n $ integers $ a_1,a_2,\ldots,a_n $ ($1 \le a_i \le 10^5$).

There are no constraints on the sum of $n$ over all test cases.

## Output

For each test case, print "Yes" (without quotes), if it is possible to make the array good, and "No" (without quotes) otherwise.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

## Example

## Input


```

528 931 1 241 1 4 552 3 3 3 34100000 100000 100000 100000
```
## Output


```

Yes
Yes
No
No
Yes

```
## Note

In the first test case, $[8,9]$ and $[9,8]$ are good.

In the second test case, $[1,2,1]$ is good because $a_1+a_2=a_2+a_3=3$.

In the third test case, it can be shown that no permutation is good.



#### tags 

#800 #constructive_algorithms 