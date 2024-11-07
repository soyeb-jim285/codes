<h1 style='text-align: center;'> C. Increase Subarray Sums</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a_1, a_2, \dots, a_n$, consisting of $n$ integers. You are also given an integer value $x$.

Let $f(k)$ be the maximum sum of a contiguous subarray of $a$ after applying the following operation: add $x$ to the elements on exactly $k$ distinct positions. An empty subarray should also be considered, it has sum $0$.

## Note

 that the subarray doesn't have to include all of the increased elements.

Calculate the maximum value of $f(k)$ for all $k$ from $0$ to $n$ independently.

## Input

The first line contains a single integer $t$ ($1 \le t \le 5000$) — the number of testcases.

The first line of the testcase contains two integers $n$ and $x$ ($1 \le n \le 5000$; $0 \le x \le 10^5$) — the number of elements in the array and the value to add.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($-10^5 \le a_i \le 10^5$).

The sum of $n$ over all testcases doesn't exceed $5000$.

## Output

For each testcase, print $n + 1$ integers — the maximum value of $f(k)$ for all $k$ from $0$ to $n$ independently.

## Example

## Input


```

34 24 1 3 23 5-2 -7 -110 2-6 -1 -2 4 -6 -1 -4 4 -5 -4
```
## Output


```

10 12 14 16 18
0 4 4 5
4 6 6 7 7 7 7 8 8 8 8

```
## Note

In the first testcase, it doesn't matter which elements you add $x$ to. The subarray with the maximum sum will always be the entire array. If you increase $k$ elements by $x$, $k \cdot x$ will be added to the sum.

In the second testcase: 

* For $k = 0$, the empty subarray is the best option.
* For $k = 1$, it's optimal to increase the element at position $3$. The best sum becomes $-1 + 5 = 4$ for a subarray $[3, 3]$.
* For $k = 2$, it's optimal to increase the element at position $3$ and any other element. The best sum is still $4$ for a subarray $[3, 3]$.
* For $k = 3$, you have to increase all elements. The best sum becomes $(-2 + 5) + (-7 + 5) + (-1 + 5) = 5$ for a subarray $[1, 3]$.


#### tags 

#1400 #brute_force #dp #greedy #implementation 