<h1 style='text-align: center;'> C. Heavy Intervals</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

[Shiki - Pure Ruby](https://soundcloud.com/shiki-8/pure-rubyversoundcloud)⠀You have $n$ intervals $[l_1, r_1], [l_2, r_2], \dots, [l_n, r_n]$, such that $l_i < r_i$ for each $i$, and all the endpoints of the intervals are distinct.

The $i$-th interval has weight $c_i$ per unit length. Therefore, the weight of the $i$-th interval is $c_i \cdot (r_i - l_i)$.

You don't like large weights, so you want to make the sum of weights of the intervals as small as possible. It turns out you can perform all the following three operations:

* rearrange the elements in the array $l$ in any order;
* rearrange the elements in the array $r$ in any order;
* rearrange the elements in the array $c$ in any order.

However, after performing all of the operations, the intervals must still be valid (i.e., for each $i$, $l_i < r_i$ must hold).

What's the minimum possible sum of weights of the intervals after performing the operations?

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 10^5$) — the number of intervals.

The second line of each test case contains $n$ integers $l_1, l_2, \ldots, l_n$ ($1 \le l_i \le 2 \cdot 10^5$) — the left endpoints of the initial intervals.

The third line of each test case contains $n$ integers $r_1, r_2, \ldots, r_n$ ($l_i < r_i \le 2 \cdot 10^5$) — the right endpoints of the initial intervals.

It is guaranteed that $\{l_1, l_2, \dots, l_n, r_1, r_2, \dots, r_n\}$ are all distinct.

The fourth line of each test case contains $n$ integers $c_1, c_2, \ldots, c_n$ ($1 \le c_i \le 10^7$) — the initial weights of the intervals per unit length.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

### Output

For each test case, output a single integer: the minimum possible sum of weights of the intervals after your operations.

## Example

### Input


```text
228 312 23100 100420 1 2 530 4 3 102 3 2 3
```
### Output

```text

2400
42

```
## Note

In the first test case, you can make 

* $l = [8, 3]$;
* $r = [23, 12]$;
* $c = [100, 100]$.

In that case, there are two intervals: 

* interval $[8, 23]$ with weight $100$ per unit length, and $100 \cdot (23-8) = 1500$ in total;
* interval $[3, 12]$ with weight $100$ per unit length, and $100 \cdot (12-3) = 900$ in total.

The sum of the weights is $2400$. It can be shown that there is no configuration of final intervals whose sum of weights is less than $2400$.

In the second test case, you can make 

* $l = [1, 2, 5, 20]$;
* $r = [3, 4, 10, 30]$;
* $c = [3, 3, 2, 2]$.

In that case, there are four intervals: 

* interval $[1, 3]$ with weight $3$ per unit length, and $3 \cdot (3-1) = 6$ in total;
* interval $[2, 4]$ with weight $3$ per unit length, and $3 \cdot (4-2) = 6$ in total;
* interval $[5, 10]$ with weight $2$ per unit length, and $2 \cdot (10-5) = 10$ in total;
* interval $[20, 30]$ with weight $2$ per unit length, and $2 \cdot (30-20) = 20$ in total.

The sum of the weights is $42$. It can be shown that there is no configuration of final intervals whose sum of weights is less than $42$.



#### Tags 

#1400 #NOT OK #constructive_algorithms #data_structures #dsu #greedy #math #sortings 

## Blogs
- [All Contest Problems](../Pinely_Round_3_(Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
