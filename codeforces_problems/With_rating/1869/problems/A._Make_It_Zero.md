<h1 style='text-align: center;'> A. Make It Zero</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

During Zhongkao examination, Reycloer met an interesting problem, but he cannot come up with a solution immediately. Time is running out! Please help him.

Initially, you are given an array $a$ consisting of $n \ge 2$ integers, and you want to change all elements in it to $0$.

In one operation, you select two indices $l$ and $r$ ($1\le l\le r\le n$) and do the following:

* Let $s=a_l\oplus a_{l+1}\oplus \ldots \oplus a_r$, where $\oplus$ denotes the [bitwise XOR operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR);
* Then, for all $l\le i\le r$, replace $a_i$ with $s$.

You can use the operation above in any order at most $8$ times in total.

Find a sequence of operations, such that after performing the operations in order, all elements in $a$ are equal to $0$. It can be proven that the solution always exists.

### Input

The first line of input contains a single integer $t$ ($1\le t\le 500$) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($2\le n\le 100$) — the length of the array $a$.

The second line of each test case contains $n$ integers $a_1,a_2,\ldots,a_n$ ($0\le a_i\le 100$) — the elements of the array $a$.

### Output

For each test case, in the first line output a single integer $k$ ($0\le k\le 8$) — the number of operations you use.

Then print $k$ lines, in the $i$-th line output two integers $l_i$ and $r_i$ ($1\le l_i\le r_i\le n$) representing that you select $l_i$ and $r_i$ in the $i$-th operation. 

## Note

 that you do not have to minimize $k$. If there are multiple solutions, you may output any of them.

## Example

### Input


```text
641 2 3 083 1 4 1 5 9 2 661 5 4 1 4 750 0 0 0 071 1 9 9 0 1 83100 100 0
```
### Output

```text

1
1 4
2
4 7
1 8
6
1 2
3 4
5 6
1 3
4 6
1 6
0
4
1 2
6 7
3 4
6 7
1
1 2

```
## Note

In the first test case, since $1\oplus2\oplus3\oplus0=0$, after performing the operation on segment $[1,4]$, all the elements in the array are equal to $0$.

In the second test case, after the first operation, the array becomes equal to $[3,1,4,15,15,15,15,6]$, after the second operation, the array becomes equal to $[0,0,0,0,0,0,0,0]$.

In the third test case:

 

| Operation | $a$ before |  | $a$ after |
| --- | --- | --- | --- |
| $1$ | $[\underline{1,5},4,1,4,7]$ | $\rightarrow$ | $[4,4,4,1,4,7]$ |
| $2$ | $[4,4,\underline{4,1},4,7]$ | $\rightarrow$ | $[4,4,5,5,4,7]$ |
| $3$ | $[4,4,5,5,\underline{4,7}]$ | $\rightarrow$ | $[4,4,5,5,3,3]$ |
| $4$ | $[\underline{4,4,5},5,3,3]$ | $\rightarrow$ | $[5,5,5,5,3,3]$ |
| $5$ | $[5,5,5,\underline{5,3,3}]$ | $\rightarrow$ | $[5,5,5,5,5,5]$ |
| $6$ | $[\underline{5,5,5,5,5,5}]$ | $\rightarrow$ | $[0,0,0,0,0,0]$ |

 In the fourth test case, the initial array contains only $0$, so we do not need to perform any operations with it.



#### Tags 

#900 #OK #constructive_algorithms 

## Blogs
- [All Contest Problems](../Codeforces_Round_896_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
