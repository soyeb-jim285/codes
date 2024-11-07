<h1 style='text-align: center;'> F. Sorting Problem Again</h1>

<h5 style='text-align: center;'>time limit per test: 2.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have an array $a$ of $n$ elements. There are also $q$ modifications of the array. Before the first modification and after each modification, you would like to know the following:

What is the minimum length subarray that needs to be sorted in non-decreasing order in order for the array $a$ to be completely sorted in non-decreasing order?

More formally, you want to select a subarray of the array $(l, r)$ with the minimum value of $r - l + 1$. After that, you will sort the elements $a_{l}, a_{l + 1}, \ldots, a_{r}$ and want the condition $a_{i} \le a_{i + 1}$ to hold for all $1 \le i < n$. If the array is already sorted in non-decreasing order, then $l$ and $r$ should be considered as equal to $-1$.

## Note

 that finding such $(l, r)$ does not change the array in any way. The modifications themselves take the form: assign $a_{pos} = x$ for given $pos$ and $x$.

## Input

Each test consists of several test cases. The first line contains an integer $t$ ($1 \le t \le 10$) — the number of test cases. Then follows the description of test cases.

The first line of each test case contains a single integer $n$ ($1 \le n \le 5 \cdot 10^{5}$).

The second line of each test case contains $n$ integers $a_{i}$ ($0 \le |a_{i}| \le 10^{9}$) — the initial elements of the array $a$.

The third line of each test case contains a number $q$ ($0 \le q \le 5 \cdot 10^{5}$) — the number of modifications to the array.

The following $q$ lines of each test case contain two integers $pos_{i}$ ($1 \le pos_{i} \le n$) and $val_{i}$ ($0 \le |val_{i}| \le 10^{9}$) — this means that for the $i$-th modification, $a_{pos_{i}}$ is assigned the value $val_{i}$.

It is guaranteed that the sum of $n$ and the sum of $q$ for all test cases does not exceed $5 \cdot 10^{5}$.

## Output

For each test case, output $q + 1$ lines. Each line should contain $2$ integers $l, r$ — the boundaries of the minimum subarray, such that sorting it will make the array $a$ completely sorted. If $a$ is already sorted, then output $l = -1$, $r = -1$.

## Example

## Input


```

252 2 3 4 532 14 11 151 2 3 4 591 42 35 23 11 15 14 13 12 1
```
## Output


```

-1 -1
1 2
1 4
3 4
-1 -1
1 3
1 3
1 5
1 5
2 5
2 5
2 5
2 5
-1 -1

```
## Note

Let's consider the first test case:

* Initially, the array is sorted in non-decreasing order: $[2, 2, 3, 4, 5]$
* After the first query, the array looks like this: $[\color{red}{2}, \color{red}{1}, 3, 4, 5]$.
* After the second query, the array looks like this: $[\color{red}{2}, \color{red}{1}, \color{red}{3}, \color{red}{1}, 5]$.
* After the third query, the array looks like this: $[1, 1, \color{red}{3}, \color{red}{1}, 5]$.

The red segments indicate the subarrays that need to be sorted in order for the entire array to be sorted in non-decreasing order.



#### tags 

#2600 #binary_search #data_structures #sortings 