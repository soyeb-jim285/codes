<h1 style='text-align: center;'> H. Phoenix and Bits</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Phoenix loves playing with bits — specifically, by using the bitwise operations AND, OR, and XOR. He has $n$ integers $a_1, a_2, \dots, a_n$, and will perform $q$ of the following queries:

1. replace all numbers $a_i$ where $l \le a_i \le r$ with $a_i$ AND $x$;
2. replace all numbers $a_i$ where $l \le a_i \le r$ with $a_i$ OR $x$;
3. replace all numbers $a_i$ where $l \le a_i \le r$ with $a_i$ XOR $x$;
4. output how many distinct integers $a_i$ where $l \le a_i \le r$.

For each query, Phoenix is given $l$, $r$, and $x$. 
## Note

 that he is considering the values of the numbers, not their indices.

#### Input

The first line contains two integers $n$ and $q$ ($1 \le n \le 2 \cdot 10^5$; $1 \le q \le 10^5$) — the number of integers and the number of queries, respectively.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($0 \le a_i < 2^{20}$) — the integers that Phoenix starts with.

The next $q$ lines contain the queries. For each query, the first integer of each line is $t$ ($1 \le t \le 4$) — the type of query.

If $t \in \{1, 2, 3\}$, then three integers $l_i$, $r_i$, and $x_i$ will follow ($0 \le l_i, r_i, x_i < 2^{20}$; $l_i \le r_i$).

Otherwise, if $t=4$, two integers $l_i$ and $r_i$ will follow ($0 \le l_i \le r_i < 2^{20}$).

It is guaranteed that there is at least one query where $t=4$.

#### Output

Print the answer for each query where $t=4$.

## Examples

#### Input


```text
5 6
5 4 3 2 1
1 2 3 2
4 2 5
3 2 5 3
4 1 6
2 1 1 8
4 8 10
```
#### Output


```text
3
2
1
```
#### Input


```text
6 7
6 0 2 3 2 7
1 0 4 3
2 6 8 4
4 0 7
3 2 5 3
1 0 1 2
4 0 3
4 2 7
```
#### Output


```text
5
1
2
```
## Note

In the first example: 

* For the first query, $2$ is replaced by $2$ AND $2 = 2$ and $3$ is replaced with $3$ AND $2 = 2$. The set of numbers is $\{1, 2, 4, 5\}$.
* For the second query, there are $3$ distinct numbers between $2$ and $5$: $2$, $4$, and $5$.
* For the third query, $2$ is replaced by $2$ XOR $3 = 1$, $4$ is replaced by $4$ XOR $3 = 7$, and $5$ is replaced by $5$ XOR $3 = 6$. The set of numbers is $\{1, 6, 7\}$.
* For the fourth query, there are $2$ distinct numbers between $1$ and $6$: $1$ and $6$.
* For the fifth query, $1$ is replaced by $1$ OR $8 = 9$. The set of numbers is $\{6, 7, 9\}$.
* For the sixth query, there is one distinct number between $8$ and $10$: $9$.


#### Tags 

#3500 #NOT OK #bitmasks #brute_force #data_structures #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_14.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Editorial (en)](../blogs/Editorial_(en).md)
