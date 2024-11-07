<h1 style='text-align: center;'> A. Maxmina</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have an array $a$ of size $n$ consisting only of zeroes and ones and an integer $k$. In one operation you can do one of the following:

* Select $2$ consecutive elements of $a$ and replace them with their minimum (that is, let $a := [a_{1}, a_{2}, \ldots, a_{i-1}, \min(a_{i}, a_{i+1}), a_{i+2}, \ldots, a_{n}]$ for some $1 \le i \le n-1$). This operation decreases the size of $a$ by $1$.
* Select $k$ consecutive elements of $a$ and replace them with their maximum (that is, let $a := [a_{1}, a_{2}, \ldots, a_{i-1}, \max(a_{i}, a_{i+1}, \ldots, a_{i+k-1}), a_{i+k}, \ldots, a_{n}]$ for some $1 \le i \le n-k+1$). This operation decreases the size of $a$ by $k-1$.

Determine if it's possible to turn $a$ into $[1]$ after several (possibly zero) operations.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 1000$). The description of the test cases follows.

The first line of each test case contains two integers $n$ and $k$ ($2 \le k \le n \le 50$), the size of array $a$ and the length of segments that you can perform second type operation on.

The second line contains $n$ integers $a_{1}, a_{2}, \ldots, a_{n}$ ($a_i$ is $0$ or $1$), elements of array $a$.

### Output

For each test case, if it is possible to turn $a$ into $[1]$, print "YES", otherwise print "NO".

## Example

### Input


```text
73 20 1 05 31 0 1 1 02 21 14 40 0 0 06 30 0 1 0 0 17 51 1 1 1 1 1 15 30 0 1 0 0
```
### Output

```text

YES
YES
YES
NO
YES
YES
YES

```
## Note

In the first test case, you can perform the second type operation on second and third elements so $a$ becomes $[0, 1]$, then you can perform the second type operation on first and second elements, so $a$ turns to $[1]$.

In the fourth test case, it's obvious to see that you can't make any $1$, no matter what you do.

In the fifth test case, you can first perform a type 2 operation on the first three elements so that $a$ becomes $[1, 0, 0, 1]$, then perform a type 2 operation on the elements in positions two through four, so that $a$ becomes $[1, 1]$, and finally perform the first type operation on the remaining elements, so that $a$ becomes $[1]$.



#### Tags 

#800 #OK #constructive_algorithms #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_23.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
