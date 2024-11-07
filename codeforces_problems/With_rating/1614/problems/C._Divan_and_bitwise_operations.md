<h1 style='text-align: center;'> C. Divan and bitwise operations</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Once Divan analyzed a sequence $a_1, a_2, \ldots, a_n$ consisting of $n$ non-negative integers as follows. He considered each non-empty subsequence of the sequence $a$, computed the [bitwise XOR](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) of its elements and added up all the XORs, obtaining the coziness of the sequence $a$.

A sequence $c$ is a subsequence of a sequence $d$ if $c$ can be obtained from $d$ by deletion of several (possibly, zero or all) elements. For example, $[1, \, 2, \, 3, \, 4]$, $[2, \, 4]$, and $[2]$ are subsequences of $[1, \, 2, \, 3, \, 4]$, but $[4, \, 3]$ and $[0]$ are not.

Divan was very proud of his analysis, but now he lost the sequence $a$, and also the coziness value! However, Divan remembers the value of [bitwise OR](https://en.wikipedia.org/wiki/Bitwise_operation#OR) on $m$ contiguous subsegments of the sequence $a$. It turns out that each element of the original sequence is contained in at least one of these $m$ segments.

Divan asks you to help find the coziness of the sequence $a$ using the information he remembers. If several coziness values are possible, print any.

As the result can be very large, print the value modulo $10^9 + 7$.

### Input

The first line contains one integer number $t$ ($1 \le t \le 10^3$) — the number of test cases.

The first line of each test case contains two integer numbers $n$ and $m$ ($1 \le n, m \le 2 \cdot 10^5$) — the length of the sequence and the number of contiguous segments whose bitwise OR values Divan remembers, respectively.

The following $m$ lines describe the segments, one per line.

Each segment is described with three integers $l$, $r$, and $x$ ($1 \le l \le r \le n$, $0 \le x \le 2^{30} - 1$) — the first and last elements of the segment and the bitwise OR of $a_l, a_{l + 1}, \ldots, a_r$, respectively.

It is guaranteed that each element of the sequence is contained in at least one of the segments. It is guaranteed that there exists a sequence that satisfies all constraints.

It is guaranteed that the sum of $n$ and the sum of $m$ over all test cases do not exceed $2 \cdot 10^5$. 

### Output

For each test case print the coziness any suitable sequence $a$ modulo $10^9 + 7$.

## Example

### Input


```text
3
2 1
1 2 2
3 2
1 3 5
2 3 5
5 4
1 2 7
3 3 7
4 4 0
4 5 2
```
### Output


```text
4
20
112
```
## Note

In first example, one of the sequences that fits the constraints is $[0, 2]$. Consider all its non-empty subsequences:

* $[0]$: the bitwise XOR of this subsequence is $0$;
* $[2]$: the bitwise XOR of this subsequence is $2$;
* $[0, 2]$: the bitwise XOR of this subsequence is $2$.

The sum of all results is $4$, so it is the answer.

In second example, one of the sequences that fits the constraints is $[0, \, 5, \, 5]$.

In third example, one of the sequences that fits the constraints is $[5, \, 6, \, 7, \, 0, \, 2]$.



#### Tags 

#1500 #NOT OK #bitmasks #combinatorics #constructive_algorithms #dp #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_757_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
