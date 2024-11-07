<h1 style='text-align: center;'> B. Sort the Subarray</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Monocarp had an array $a$ consisting of $n$ integers. He has decided to choose two integers $l$ and $r$ such that $1 \le l \le r \le n$, and then sort the subarray $a[l..r]$ (the subarray $a[l..r]$ is the part of the array $a$ containing the elements $a_l, a_{l+1}, a_{l+2}, \dots, a_{r-1}, a_r$) in non-descending order. After sorting the subarray, Monocarp has obtained a new array, which we denote as $a'$.

For example, if $a = [6, 7, 3, 4, 4, 6, 5]$, and Monocarp has chosen $l = 2, r = 5$, then $a' = [6, 3, 4, 4, 7, 6, 5]$.

You are given the arrays $a$ and $a'$. Find the integers $l$ and $r$ that Monocarp could have chosen. If there are multiple pairs of values $(l, r)$, find the one which corresponds to the longest subarray.

### Input

The first line contains one integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

Each test case consists of three lines:

* the first line contains one integer $n$ ($2 \le n \le 2 \cdot 10^5$);
* the second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le n$);
* the third line contains $n$ integers $a'_1, a'_2, \dots, a'_n$ ($1 \le a'_i \le n$).

Additional constraints on the input:

* the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$;
* it is possible to obtain the array $a'$ by sorting one subarray of $a$;
* $a' \ne a$ (there exists at least one position in which these two arrays are different).
### Output

For each test case, print two integers — the values of $l$ and $r$ ($1 \le l \le r \le n$). If there are multiple answers, print the values that correspond to the longest subarray. If there are still multiple answers, print any of them.

## Example

### Input


```text
376 7 3 4 4 6 56 3 4 4 7 6 531 2 11 1 232 2 12 1 2
```
### Output

```text

2 5
1 3
2 3

```


#### Tags 

#1100 #NOT OK #brute_force #greedy 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_147_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
