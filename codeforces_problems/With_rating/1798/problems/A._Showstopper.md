<h1 style='text-align: center;'> A. Showstopper</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two arrays $a_1, a_2, \ldots, a_n$ and $b_1, b_2, \ldots, b_n$.

In one operation, you can choose any integer $i$ from $1$ to $n$ and swap the numbers $a_i$ and $b_i$.

Determine whether, after using any (possibly zero) number of operations, the following two conditions can be satisfied simultaneously:

* $a_n = \max(a_1, a_2, \ldots, a_n)$,
* $b_n = \max(b_1, b_2, \ldots, b_n)$.

Here $\max(c_1, c_2, \ldots, c_k)$ denotes the maximum number among $c_1, c_2, \ldots, c_k$. For example, $\max(3, 5, 4) = 5$, $\max(1, 7, 7) = 7$, $\max(6, 2) = 6$.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 200$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 100$) — the length of the arrays.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 100$) — elements of the first array.

The third line of each test case contains $n$ integers $b_1, b_2, \ldots, b_n$ ($1 \le b_i \le 100$) — elements of the second array.

### Output

For each test case, print "Yes" if after using any (possibly zero) number of operations the conditions described above are satisfied. Otherwise, print "No".

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

## Example

### Input


```text
737 9 77 6 9410 10 15 1510 16 15 152100 9999 10011191 2 3 4 5 6 7 8 99 9 9 9 9 9 6 6 671 1 2 2 1 1 21 2 1 2 1 2 1230 45 30
```
### Output

```text

Yes
No
Yes
Yes
Yes
No
No

```
## Note

In the first test case, you can swap the numbers $a_3$ and $b_3$, after which the array $a$ becomes equal to $[7, 9, 9]$, and the array $b$ becomes equal to $[7, 6, 7]$, and both conditions are met.

In the second test case, it can be proved that it is impossible to satisfy both conditions.

In the third test case, you can swap the numbers $a_1$ and $b_1$, after which the array $a$ becomes equal to $[99, 99]$, and the array $b$ becomes equal to $[100, 100]$, and both conditions are satisfied.

In fifth test case, you can swap $a_7$ and $b_7$, $a_8$ and $b_8$, $a_9$ and $b_9$, after which the array $a$ becomes equal to $[1, 2, 3, 4, 5, 6, 6, 6, 6]$, and the array $b$ becomes equal to $[9, 9, 9, 9, 9, 9, 7, 8, 9]$, and both conditions are satisfied.



#### Tags 

#800 #OK #greedy #implementation #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_860_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
