<h1 style='text-align: center;'> D. Bitwise Paradox</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

You are given two arrays $a$ and $b$ of size $n$ along with a fixed integer $v$.

An interval $[l, r]$ is called a good interval if $(b_l \mid b_{l+1} \mid \ldots \mid b_r) \ge v$, where $|$ denotes the [bitwise OR operation](https://en.wikipedia.org/wiki/Bitwise_operation#OR). The beauty of a good interval is defined as $\max(a_l, a_{l+1}, \ldots, a_r)$.

You are given $q$ queries of two types:

* "1 i x": assign $b_i := x$;
* "2 l r": find the minimum beauty among all good intervals $[l_0,r_0]$ satisfying $l \le l_0 \le r_0 \le r$. If there is no suitable good interval, output $-1$ instead.

Please process all queries.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^5$). The description of the test cases follows.

The first line of each test case contains two integers $n$ and $v$ ($1 \le n \le 2 \cdot 10^5$, $1 \le v \le 10^9$).

The second line of each testcase contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$).

The third line of each testcase contains $n$ integers $b_1, b_2, \ldots, b_n$ ($1 \le b_i \le 10^9$).

The fourth line of each testcase contains one integer $q$ ($1 \le q \le 2 \cdot 10^5$).

The $i$-th of the following $q$ lines contains the description of queries. Each line is of one of two types:

* "1 i x" ($1 \le i \le n$, $1 \le x \le 10^9)$;
* "2 l r" ($1 \le l \le r \le n$).

It is guaranteed that both the sum of $n$ and the sum of $q$ over all test cases do not exceed $2 \cdot 10^5$.

### Output

For each test case, output the answers for all queries of the second type.

## Example

### Input


```text
33 72 1 32 2 342 1 31 2 52 2 32 1 34 55 1 2 44 2 3 362 1 41 3 152 3 42 2 41 2 132 1 41 56412 1 1
```
### Output

```text

-1 3 2 
5 2 2 1 
-1 

```
## Note

In the first test case, $a = [2, 1, 3]$, $b = [2, 2, 3]$, and $v = 7$.

The first query is of the second type and has $l = 1$ and $r = 3$. The largest interval available is $[1, 3]$, and its bitwise OR is $b_1 \mid b_2 \mid b_3 = 3$ which is less than $v$. Thus, no good interval exists.

The second query asks to change $b_2$ to $5$, so $b$ becomes $[2, 5, 3]$.

The third query is of the second type and has $l = 2$ and $r = 3$. There are three possible intervals: $[2, 2]$, $[3, 3]$, and $[2, 3]$. However, $b_2 = 5 < v$, $b_3 = 3 < v$. So only the last interval is good: it has $b_2 \mid b_3 = 7$. The answer is thus $\max(a_2, a_3) = 3$.

The fourth query is of the second type and has $l = 1$ and $r = 3$. There are three good intervals: $[1, 2]$, $[2, 3]$, and $[1, 3]$. Their beauty is $2$, $3$, $3$ correspondingly. The answer is thus $2$.

In the second test case, $a = [5, 1, 2, 4]$, $b = [4, 2, 3, 3]$, and $v = 5$.

The first query has $l = 1$ and $r = 4$. The only good intervals are: $[1, 2]$, $[1, 3]$, $[1, 4]$. Their beauty is $5$, $5$, $5$ correspondingly. The answer is thus $5$.



#### Tags 

#3100 #NOT OK #binary_search #bitmasks #data_structures #greedy #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_930_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
