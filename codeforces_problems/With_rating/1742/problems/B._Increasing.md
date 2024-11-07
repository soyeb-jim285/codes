<h1 style='text-align: center;'> B. Increasing</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ of $n$ positive integers. Determine if, by rearranging the elements, you can make the array strictly increasing. In other words, determine if it is possible to rearrange the elements such that $a_1 < a_2 < \dots < a_n$ holds.

### Input

The first line contains a single integer $t$ ($1 \leq t \leq 100$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 100$) — the length of the array.

The second line of each test case contains $n$ integers $a_i$ ($1 \leq a_i \leq 10^9$) — the elements of the array.

### Output

For each test case, output "YES" (without quotes) if the array satisfies the condition, and "NO" (without quotes) otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).

## Example

### Input


```text
341 1 1 158 7 1 3 415
```
### Output

```text

NO
YES
YES

```
## Note

In the first test case any rearrangement will keep the array $[1,1,1,1]$, which is not strictly increasing.

In the second test case, you can make the array $[1,3,4,7,8]$.



#### Tags 

#800 #OK #greedy #implementation #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_827_(Div._4).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
