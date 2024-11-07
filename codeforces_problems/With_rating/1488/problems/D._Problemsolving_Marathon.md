<h1 style='text-align: center;'> D. Problemsolving Marathon</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarp has decided to do a problemsolving marathon. He wants to solve $s$ problems in $n$ days. Let $a_i$ be the number of problems he solves during the $i$-th day. He wants to find a distribution of problems into days such that: 

* $a_i$ is an integer value for all $i$ from $1$ to $n$;
* $a_i \ge 1$ for all $i$ from $1$ to $n$;
* $a_{i + 1} \ge a_i$ for all $i$ from $1$ to $n-1$;
* $a_{i + 1} \le 2 \cdot a_i$ for all $i$ from $1$ to $n-1$;
* $a_n$ is maximized.

## Note

 that $a_1$ can be arbitrarily large.

What is the largest value of $a_n$ Polycarp can obtain?

### Input

The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of testcases.

Then the descriptions of $t$ testcases follow.

The only line of each testcase contains two integers $n$ and $s$ ($1 \le n \le s \le 10^{18}$) — the number of days and the number of problems Polycarp wants to solve.

It's guaranteed that the distribution always exists within the given constraints.

### Output

For each testcase print a single integer — the maximum value of $a_n$.

## Example

### Input


```text
3
1 15
3 9
2 6
```
### Output


```text
15
4
4
```
## Note

In the first testcase there is only one distribution: $[15]$.

In the second testcase the distribution that maximizes $a_n$ is: $[2, 3, 4]$.

In the third testcase the distribution that maximizes $a_n$ is: $[2, 4]$. $[3, 3]$ is a valid distribution but $a_n=3$ which is smaller than $4$. $[1, 5]$ is not a valid distribution because $5 > 2 \cdot 1$.



#### Tags 

#1900 #NOT OK #*special #binary_search #greedy 

## Blogs
- [All Contest Problems](../Kotlin_Heroes:_Episode_6.md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
