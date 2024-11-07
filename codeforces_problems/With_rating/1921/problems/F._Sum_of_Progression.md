<h1 style='text-align: center;'> F. Sum of Progression</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

You are given an array $a$ of $n$ numbers. There are also $q$ queries of the form $s, d, k$.

For each query $q$, find the sum of elements $a_s + a_{s+d} \cdot 2 + \dots + a_{s + d \cdot (k - 1)} \cdot k$. In other words, for each query, it is necessary to find the sum of $k$ elements of the array with indices starting from the $s$-th, taking steps of size $d$, multiplying it by the serial number of the element in the resulting sequence.

### Input

Each test consists of several testcases. The first line contains one integer $t$ ($1 \le t \le 10^4$) — the number of testcases. Next lines contain descriptions of testcases.

The first line of each testcase contains two numbers $n, q$ ($1 \le n \le 10^5, 1 \le q \le 2 \cdot 10^5$) — the number of elements in the array $a$ and the number of queries.

The second line contains $n$ integers $a_1, ... a_n$ ($-10^8 \le a_1, ..., a_n \le 10^8$) — elements of the array $a$.

The next $q$ lines each contain three integers $s$, $d$, and $k$ ($1 \le s, d, k \le n$, $s + d\cdot (k - 1) \le n$ ).

It is guaranteed that the sum of $n$ over all testcases does not exceed $10^5$, and that the sum of $q$ over all testcases does not exceed $2 \cdot 10^5 $.

### Output

For each testcase, print $q$ numbers in a separate line — the desired sums, separated with space.

## Example

### Input


```text
53 31 1 21 2 22 2 11 1 23 1-100000000 -100000000 -1000000001 1 35 31 2 3 4 51 2 32 3 21 1 53 1100000000 100000000 1000000001 1 37 734 87 5 42 -44 66 -322 2 24 3 11 3 26 2 15 2 22 5 26 1 2
```
### Output

```text

5 1 3 
-600000000 
22 12 55 
600000000 
171 42 118 66 -108 23 2 
```


#### Tags 

#1900 #NOT OK #brute_force #data_structures #dp #implementation #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_920_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
