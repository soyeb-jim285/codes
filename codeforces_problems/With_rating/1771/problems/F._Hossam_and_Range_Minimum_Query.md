<h1 style='text-align: center;'> F. Hossam and Range Minimum Query</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Hossam gives you a sequence of integers $a_1, \, a_2, \, \dots, \, a_n$ of length $n$. Moreover, he will give you $q$ queries of type $(l, \, r)$. For each query, consider the elements $a_l, \, a_{l + 1}, \, \dots, \, a_r$. Hossam wants to know the smallest number in this sequence, such that it occurs in this sequence an odd number of times.

You need to compute the answer for each query before process the next query.

#### Input

The first line of the input contains one integer $n$ ($1 \le n \le 2 \cdot 10^5$), the length of the sequence.

The second line contains $n$ integers $a_1, \, a_2, \, \dots, \, a_n$ ($1 \le a_i \le 10^9$).

The third line contains one integer $q$ ($1 \le q \le 2 \cdot 10^5$), the number of queries.

Each of the next $q$ lines contains two integers $a$ and $b$ ($0 \le a, \, b \le 2 \cdot 10^9$), the numbers used to encode the queries. 

Let $\mathrm{ans}_i$ be the answer on the $i$-th query, and $\mathrm{ans}_0$ be zero. Then $$l_i = a_i \oplus \mathrm{ans}_{i - 1},$$ $$r_i = b_i \oplus \mathrm{ans}_{i - 1},$$ where $l_i, \, r_i$ are parameters of the $i$-th query and $\oplus$ means the [bitwise exclusive or](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) operation. It is guaranteed that $1 \le l \le r \le n$.

#### Output

For each query, print the smallest number that occurs an odd number of times on the given segment of the sequence.

If there is no such number, print $0$.

## Examples

#### Input


```text
5
1 2 1 2 2
6
1 2
0 2
0 6
0 5
2 2
3 7
```
#### Output


```text
1
2
1
0
2
2
```
#### Input


```text
10
51 43 69 48 23 52 48 76 19 55
10
1 1
57 57
54 62
20 27
56 56
79 69
16 21
18 30
25 25
62 61
```
#### Output


```text
51
55
19
48
76
19
23
19
55
19
```
## Note

In the example,

$$l_1 = 1, \, r_1 = 2,$$ $$l_2 = 1, \, r_2 = 3,$$ $$l_3 = 2, \, r_3 = 4,$$ $$l_4 = 1, \, r_4 = 4,$$ $$l_5 = 2, \, r_5 = 2,$$ $$l_6 = 1, \, r_6 = 5.$$



#### Tags 

#2500 #NOT OK #binary_search #bitmasks #data_structures #hashing #probabilities #strings #trees 

## Blogs
- [All Contest Problems](../Codeforces_Round_837_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
