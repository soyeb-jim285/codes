<h1 style='text-align: center;'> E. Multitest Generator</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's call an array $b_1, b_2, \ldots, b_m$ a test if $b_1 = m - 1$.

Let's call an array $b_1, b_2, \ldots, b_m$ a multitest if the array $b_2, b_3, \ldots, b_m$ can be split into $b_1$ non-empty subarrays so that each of these subarrays is a test. 
## Note

 that each element of the array must be included in exactly one subarray, and the subarrays must consist of consecutive elements.

Let's define the function $f$ from the array $b_1, b_2, \ldots, b_m$ as the minimum number of operations of the form "Replace any $b_i$ with any non-negative integer $x$", which needs to be done so that the array $b_1, b_2, \ldots, b_m$ becomes a multitest.

You are given an array of positive integers $a_1, a_2, \ldots, a_n$. For each $i$ from $1$ to $n - 1$, find $f([a_i, a_{i+1}, \ldots, a_n])$.

Below are some examples of tests and multitests. 

* Tests: $[\underline{1}, 5]$, $[\underline{2}, 2, 2]$, $[\underline{3}, 4, 1, 1]$, $[\underline{5}, 0, 0, 0, 0, 0]$, $[\underline{7}, 1, 2, 3, 4, 5, 6, 7]$, $[\underline{0}]$. These arrays are tests since their first element (underlined) is equal to the length of the array minus one.
* Multitests: $[1, \underline{\underline{1}, 1}]$, $[2, \underline{\underline{3}, 0, 0, 1}, \underline{\underline{1}, 12}]$, $[3, \underline{\underline{2}, 2, 7}, \underline{\underline{1}, 1}, \underline{\underline{3}, 4, 4, 4}]$, $[4, \underline{\underline{0}}, \underline{\underline{3}, 1, 7, 9}, \underline{\underline{4}, 2, 0, 0, 9}, \underline{\underline{1}, 777}]$. Underlined are the subarrays after the split, and double underlined are the first elements of each subarray.
#### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 300\,000$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($2 \le n \le 300\,000$) — the length of the array $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 300\,000$) — elements of the array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $300\,000$.

#### Output

For each test case print $n - 1$ numbers — $f([a_i, a_{i+1}, \ldots, a_n])$ for each $i$ from $1$ to $n - 1$.

## Examples

#### Input


```text
341 2 1 773 1 3 1 2 1 142 7 1 1
```
#### Output

```text

0 1 1 
0 1 1 0 1 1 
1 1 1 

```
#### Input


```text
1193 4 1 2 1 7 7 3 1 3 1 2 1 1 4 2 7 1 1
```
#### Output

```text

0 0 1 1 1 1 1 1 1 0 1 0 1 0 2 1 1 1 

```
## Note

In the first test case of the first test the array $[1, 2, 1, 7]$ is a multitest since the array $[2, 1, 7]$ is a test. The array $[2, 1, 7]$ is not a multitest, but after replacing the first number with $1$, an array $[1, 1, 7]$ is obtained, which is a multitest. The array $[1, 7]$ is also not a multitest, but the array $[1, 0]$ is, so $f([1, 7]) = 1$.

In the second test case of first test, for $i = 2$, $f([a_i, a_{i+1}, \ldots, a_n]) = f([1, 3, 1, 2, 1, 1]) = 1$, since the array itself is not a multitest, but after replacing the second element with $4$ you get multitest.

In the third test case of first test, for $i = 1$, $f([a_i, a_{i+1}, \ldots, a_n]) = f([2, 7, 1, 1]) = 1$, since the array itself is not a multitest, but after replacing the second element with $0$ you get multitest.

The second test is an array composed of all the numbers of the first test. Therefore $f([a_1, a_2, \ldots, a_n])$ naturally equals to $0$.



#### Tags 

#2300 #NOT OK #brute_force #dp 

## Blogs
- [All Contest Problems](../Codeforces_Round_860_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
