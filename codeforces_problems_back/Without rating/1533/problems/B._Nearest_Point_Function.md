<h1 style='text-align: center;'> B. Nearest Point Function</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Your friend has created a nearest point function. For a given array of integer points $x$ (sorted in ascending order, without any duplicates) and a point $y$ it can find the nearest point from $x$ to the point $y$. In other words, it will find such a point $x_i$ that $|y - x_i|$ is the minimum possible, where $|a|$ is the absolute value of $a$.

For example, if $x = [1, 2, 5, 7, 9, 11]$, the answer for $y=3$ will be $2$, the answer for $y=5$ will be $5$ and the answer for $y=100$ will be $11$.

This function is a bit buggy, though. If there are several nearest points to the given one, the function crashes. For example, if $x = [1, 2, 5, 7, 9, 11]$ (as above) and $y=6$, the function will crash, since points $5$ and $7$ are both the nearest points for $6$.

Your task is, for a given array of integer points $x$ (sorted in ascending order, without any duplicates), determine if it is possible to cause the function to crash by choosing some integer point $y$.

You have to answer $t$ independent test cases.

## Input

The first line of the input contains one integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of the test case contains one integer $n$ ($2 \le n \le 2 \cdot 10^5$) — the number of points in the array $x$.

The second line of the test case contains $n$ integers $x_1, x_2, \ldots, x_n$ ($1 \le x_i \le 10^9$), where $x_i$ is the $i$-th point in the array $x$.

All points in the array $x$ are distinct, and the array $x$ is sorted in ascending order (in other words, $x_1 < x_2 < \ldots < x_n$).

The sum of $n$ over the test cases in the input does not exceed $2 \cdot 10^5$ ($\sum n \le 2 \cdot 10^5$).

## Output

For each test case, print YES if it is possible to find some integer point $y$ that will crash the function and NO otherwise.

## Example

## Input


```

7
2
1 3
2
1 100
3
1 50 101
2
1 1000000000
2
1 999999999
6
1 2 5 7 9 11
6
1 2 5 8 9 12

```
## Output


```

YES
NO
NO
NO
YES
YES
NO

```
## Note

In the first test case of the example, the function crashes if $y = 2$ is chosen.

In the fifth test case of the example, the function crashes if $y = 500000000$ is chosen.

In the sixth test case of the example, the function crashes if $y = 10$ is chosen.



#### tags 

#*special #implementation 