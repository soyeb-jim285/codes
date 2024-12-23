<h1 style='text-align: center;'> C. Electrification</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

At first, there was a legend related to the name of the problem, but now it's just a formal statement.

You are given $n$ points $a_1, a_2, \dots, a_n$ on the $OX$ axis. Now you are asked to find such an integer point $x$ on $OX$ axis that $f_k(x)$ is minimal possible.

The function $f_k(x)$ can be described in the following way: 

* form a list of distances $d_1, d_2, \dots, d_n$ where $d_i = |a_i - x|$ (distance between $a_i$ and $x$);
* sort list $d$ in non-descending order;
* take $d_{k + 1}$ as a result.

If there are multiple optimal answers you can print any of them.

### Input

The first line contains single integer $T$ ($ 1 \le T \le 2 \cdot 10^5$) — number of queries. Next $2 \cdot T$ lines contain descriptions of queries. All queries are independent. 

The first line of each query contains two integers $n$, $k$ ($1 \le n \le 2 \cdot 10^5$, $0 \le k < n$) — the number of points and constant $k$.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_1 < a_2 < \dots < a_n \le 10^9$) — points in ascending order.

It's guaranteed that $\sum{n}$ doesn't exceed $2 \cdot 10^5$.

### Output

Print $T$ integers — corresponding points $x$ which have minimal possible value of $f_k(x)$. If there are multiple answers you can print any of them.

## Example

### Input


```text
3
3 2
1 2 5
2 1
1 1000000000
1 0
4
```
### Output


```text
3
500000000
4
```


#### Tags 

#1600 #NOT OK #binary_search #brute_force #greedy 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_66_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Editorial (en)](../blogs/Editorial_(en).md)
