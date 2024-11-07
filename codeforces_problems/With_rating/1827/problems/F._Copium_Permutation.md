<h1 style='text-align: center;'> F. Copium Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

You are given a permutation $a_1,a_2,\ldots,a_n$ of the first $n$ positive integers. A subarray $[l,r]$ is called copium if we can rearrange it so that it becomes a sequence of consecutive integers, or more formally, if $$\max(a_l,a_{l+1},\ldots,a_r)-\min(a_l,a_{l+1},\ldots,a_r)=r-l$$ For each $k$ in the range $[0,n]$, print out the maximum number of copium subarrays of $a$ over all ways of rearranging the last $n-k$ elements of $a$.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1\le n\le 2\cdot 10^5$).

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le n$). It is guaranteed that the given numbers form a permutation of length $n$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot 10^5$.

### Output

For each test case print $n+1$ integers as the answers for each $k$ in the range $[0,n]$.

## Example

### Input


```text
555 2 1 4 342 1 4 31187 5 8 1 4 2 6 3101 4 5 3 7 8 9 2 10 6
```
### Output

```text

15 15 11 10 9 9 
10 8 8 7 7 
1 1 
36 30 25 19 15 13 12 9 9 
55 55 41 35 35 25 22 22 19 17 17 

```
## Note

In the first test case, the answer permutations for each $k$ are $[1,2,3,4,5]$, $[5,4,3,2,1]$, $[5,2,3,4,1]$, $[5,2,1,3,4]$, $[5,2,1,4,3]$, $[5,2,1,4,3]$.

In the second test case, the answer permutations for each $k$ are $[1,2,3,4]$, $[2,1,3,4]$, $[2,1,3,4]$, $[2,1,4,3]$, $[2,1,4,3]$.



#### Tags 

#3500 #NOT OK #constructive_algorithms #data_structures #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_873_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
