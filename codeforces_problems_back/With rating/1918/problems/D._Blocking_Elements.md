<h1 style='text-align: center;'> D. Blocking Elements</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array of numbers $a_1, a_2, \ldots, a_n$. Your task is to block some elements of the array in order to minimize its cost. Suppose you block the elements with indices $1 \leq b_1 < b_2 < \ldots < b_m \leq n$. Then the cost of the array is calculated as the maximum of: 

* the sum of the blocked elements, i.e., $a_{b_1} + a_{b_2} + \ldots + a_{b_m}$.
* the maximum sum of the segments into which the array is divided when the blocked elements are removed. That is, the maximum sum of the following ($m + 1$) subarrays: [$1, b_1 − 1$], [$b_1 + 1, b_2 − 1$], [$\ldots$], [$b_{m−1} + 1, b_m - 1$], [$b_m + 1, n$] (the sum of numbers in a subarray of the form [$x,x − 1$] is considered to be $0$).

For example, if $n = 6$, the original array is [$1, 4, 5, 3, 3, 2$], and you block the elements at positions $2$ and $5$, then the cost of the array will be the maximum of the sum of the blocked elements ($4 + 3 = 7$) and the sums of the subarrays ($1$, $5 + 3 = 8$, $2$), which is $\max(7,1,8,2) = 8$. 

You need to output the minimum cost of the array after blocking.

## Input

The first line of the input contains a single integer $t$ ($1 \leq t \leq 30\,000$) — the number of queries.

Each test case consists of two lines. The first line contains an integer $n$ ($1 \leq n \leq 10^5$) — the length of the array $a$. The second line contains $n$ elements $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq 10^9$) — the array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

## Output

For each test case, output a single number — the minimum cost of blocking the array.

## Example

## Input


```

361 4 5 3 3 251 2 3 4 564 1 6 3 10 7
```
## Output


```

7
5
11

```
## Note

The first test case matches with the array from the statement. To obtain a cost of $7$, you need to block the elements at positions $2$ and $4$. In this case, the cost of the array is calculated as the maximum of:

* the sum of the blocked elements, which is $a_2 + a_4 = 7$.
* the maximum sum of the segments into which the array is divided when the blocked elements are removed, i.e., the maximum of $a_1$, $a_3$, $a_5 + a_6 = \max(1,5,5) = 5$.

So the cost is $\max(7,5) = 7$. 

In the second test case, you can block the elements at positions $1$ and $4$.

In the third test case, to obtain the answer $11$, you can block the elements at positions $2$ and $5$. There are other ways to get this answer, for example, blocking positions $4$ and $6$.



#### tags 

#1900 #binary_search #data_structures #dp #implementation #two_pointers 