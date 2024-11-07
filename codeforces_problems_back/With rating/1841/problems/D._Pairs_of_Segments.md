<h1 style='text-align: center;'> D. Pairs of Segments</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Two segments $[l_1, r_1]$ and $[l_2, r_2]$ intersect if there exists at least one $x$ such that $l_1 \le x \le r_1$ and $l_2 \le x \le r_2$.

An array of segments $[[l_1, r_1], [l_2, r_2], \dots, [l_k, r_k]]$ is called beautiful if $k$ is even, and is possible to split the elements of this array into $\frac{k}{2}$ pairs in such a way that:

* every element of the array belongs to exactly one of the pairs;
* segments in each pair intersect with each other;
* segments in different pairs do not intersect.

For example, the array $[[2, 4], [9, 12], [2, 4], [7, 7], [10, 13], [6, 8]]$ is beautiful, since it is possible to form $3$ pairs as follows:

* the first element of the array (segment $[2, 4]$) and the third element of the array (segment $[2, 4]$);
* the second element of the array (segment $[9, 12]$) and the fifth element of the array (segment $[10, 13]$);
* the fourth element of the array (segment $[7, 7]$) and the sixth element of the array (segment $[6, 8]$).

As you can see, the segments in each pair intersect, and no segments from different pairs intersect.

You are given an array of $n$ segments $[[l_1, r_1], [l_2, r_2], \dots, [l_n, r_n]]$. You have to remove the minimum possible number of elements from this array so that the resulting array is beautiful.

## Input

The first line contains one integer $t$ ($1 \le t \le 1000$) — the number of test cases.

The first line of each test case contains one integer $n$ ($2 \le n \le 2000$) — the number of segments in the array. Then, $n$ lines follow, the $i$-th of them contains two integers $l_i$ and $r_i$ ($0 \le l_i \le r_i \le 10^9$) denoting the $i$-th segment.

Additional constraint on the input: the sum of $n$ over all test cases does not exceed $2000$.

## Output

For each test case, print one integer — the minimum number of elements you have to remove so that the resulting array is beautiful.

## Example

## Input


```

372 49 122 47 74 810 136 852 22 80 101 25 641 12 23 34 4
```
## Output


```

1
3
4

```
## Note

In the first test case of the example, it is enough to delete the $5$-th element of the array of segments. Then you get the array $[[2, 4], [9, 12], [2, 4], [7, 7], [10, 13], [6, 8]]$, which is beautiful.

In the second test case of the example, you can delete the $1$-st, $3$-rd and $4$-th element of the array. Then you get the array $[[2, 8], [5, 6]]$, which is beautiful.

In the third test case of the example, you have to delete the whole array.



#### tags 

#2000 #data_structures #greedy #sortings #two_pointers 