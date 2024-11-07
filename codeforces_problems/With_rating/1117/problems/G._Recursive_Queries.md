<h1 style='text-align: center;'> G. Recursive Queries</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a permutation $p_1, p_2, \dots, p_n$. You should answer $q$ queries. Each query is a pair $(l_i, r_i)$, and you should calculate $f(l_i, r_i)$.

Let's denote $m_{l, r}$ as the position of the maximum in subsegment $p_l, p_{l+1}, \dots, p_r$.

Then $f(l, r) = (r - l + 1) + f(l, m_{l,r} - 1) + f(m_{l,r} + 1, r)$ if $l \le r$ or $0$ otherwise.

### Input

The first line contains two integers $n$ and $q$ ($1 \le n \le 10^6$, $1 \le q \le 10^6$) — the size of the permutation $p$ and the number of queries.

The second line contains $n$ pairwise distinct integers $p_1, p_2, \dots, p_n$ ($1 \le p_i \le n$, $p_i \neq p_j$ for $i \neq j$) — permutation $p$.

The third line contains $q$ integers $l_1, l_2, \dots, l_q$ — the first parts of the queries.

The fourth line contains $q$ integers $r_1, r_2, \dots, r_q$ — the second parts of the queries.

It's guaranteed that $1 \le l_i \le r_i \le n$ for all queries.

### Output

Print $q$ integers — the values $f(l_i, r_i)$ for the corresponding queries.

## Example

### Input


```text
4 5
3 1 4 2
2 1 1 2 1
2 3 4 4 1
```
### Output


```text
1 6 8 5 1 
```
## Note

Description of the queries: 

1. $f(2, 2) = (2 - 2 + 1) + f(2, 1) + f(3, 2) = 1 + 0 + 0 = 1$;
2. $f(1, 3) = (3 - 1 + 1) + f(1, 2) + f(4, 3) = 3 + (2 - 1 + 1) + f(1, 0) + f(2, 2) = 3 + 2 + (2 - 2 + 1) = 6$;
3. $f(1, 4) = (4 - 1 + 1) + f(1, 2) + f(4, 4) = 4 + 3 + 1 = 8$;
4. $f(2, 4) = (4 - 2 + 1) + f(2, 2) + f(4, 4) = 3 + 1 + 1 = 5$;
5. $f(1, 1) = (1 - 1 + 1) + 0 + 0 = 1$.


#### Tags 

#2500 #NOT OK #data_structures 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_60_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
