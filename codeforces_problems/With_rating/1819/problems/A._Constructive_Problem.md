<h1 style='text-align: center;'> A. Constructive Problem</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

As you know, any problem that does not require the use of complex data structures is considered constructive. You are offered to solve one of such problems.

You are given an array $a$ of $n$ non-negative integers. You are allowed to perform the following operation exactly once: choose some non-empty subsegment $a_l, a_{l+1}, \ldots, a_r$ of the array $a$ and a non-negative integer $k$, and assign value $k$ to all elements of the array on the chosen subsegment.

The task is to find out whether $\operatorname{MEX}(a)$ can be increased by exactly one by performing such an operation. In other words, if before the operation $\operatorname{MEX}(a) = m$ held, then after the operation it must hold that $\operatorname{MEX}(a) = m + 1$.

Recall that $\operatorname{MEX}$ of a set of integers $c_1, c_2, \ldots, c_k$ is defined as the smallest non-negative integer $x$ which does not occur in the set $c$.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 50\,000$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 200\,000$) — the number of elements of array $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le 10^9$) — elements of array $a$.

It is guaranteed that the sum $n$ over all test cases does not exceed $200\,000$.

### Output

For each test case, print "Yes" if you can increase $\operatorname{MEX}(a)$ by exactly one by performing the operation from the statement exactly once, otherwise print "No".

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

## Example

### Input


```text
431 2 140 2 2 043 2 0 210
```
### Output

```text

Yes
Yes
No
No

```
## Note

In the first test case, $\operatorname{MEX}(a) = 0$. If you set all elements of $a$ to $0$, then $\operatorname{MEX}$ of the resulting array will be $1$, and thus will increase by one.

In the second test case, $\operatorname{MEX}(a) = 1$. If we assign a value of $1$ to the elements of $a$ on a subsegment from $2$ to $3$, we get an array $[0, 1, 1, 0]$ for which $\operatorname{MEX}$ is $2$, and thus is increased by one compared to the original.

It can be shown that in the third and fourth test cases it is impossible to perform an operation so that the value of $\operatorname{MEX}(a)$ increases by exactly one.



#### Tags 

#1300 #NOT OK #brute_force #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_866_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
