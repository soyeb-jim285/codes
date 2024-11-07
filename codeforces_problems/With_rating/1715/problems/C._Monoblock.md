<h1 style='text-align: center;'> C. Monoblock</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Stanley has decided to buy a new desktop PC made by the company "Monoblock", and to solve captcha on their website, he needs to solve the following task.

The awesomeness of an array is the minimum number of blocks of consecutive identical numbers in which the array could be split. For example, the awesomeness of an array 

* $[1, 1, 1]$ is $1$;
* $[5, 7]$ is $2$, as it could be split into blocks $[5]$ and $[7]$;
* $[1, 7, 7, 7, 7, 7, 7, 7, 9, 9, 9, 9, 9, 9, 9, 9, 9]$ is 3, as it could be split into blocks $[1]$, $[7, 7, 7, 7, 7, 7, 7]$, and $[9, 9, 9, 9, 9, 9, 9, 9, 9]$.

You are given an array $a$ of length $n$. There are $m$ queries of two integers $i$, $x$. A query $i$, $x$ means that from now on the $i$-th element of the array $a$ is equal to $x$.

After each query print the sum of awesomeness values among all subsegments of array $a$. In other words, after each query you need to calculate $$\sum\limits_{l = 1}^n \sum\limits_{r = l}^n g(l, r),$$ where $g(l, r)$ is the awesomeness of the array $b = [a_l, a_{l + 1}, \ldots, a_r]$.

### Input

In the first line you are given with two integers $n$ and $m$ ($1 \leq n, m \leq 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$) — the array $a$.

In the next $m$ lines you are given the descriptions of queries. Each line contains two integers $i$ and $x$ ($1 \leq i \leq n$, $1 \leq x \leq 10^9$).

### Output

Print the answer to each query on a new line.

## Example

### Input


```text
5 5
1 2 3 4 5
3 2
4 2
3 1
2 1
2 2
```
### Output


```text
29
23
35
25
35
```
## Note

After the first query $a$ is equal to $[1, 2, 2, 4, 5]$, and the answer is $29$ because we can split each of the subsegments the following way: 

1. $[1; 1]$: $[1]$, 1 block;
2. $[1; 2]$: $[1] + [2]$, 2 blocks;
3. $[1; 3]$: $[1] + [2, 2]$, 2 blocks;
4. $[1; 4]$: $[1] + [2, 2] + [4]$, 3 blocks;
5. $[1; 5]$: $[1] + [2, 2] + [4] + [5]$, 4 blocks;
6. $[2; 2]$: $[2]$, 1 block;
7. $[2; 3]$: $[2, 2]$, 1 block;
8. $[2; 4]$: $[2, 2] + [4]$, 2 blocks;
9. $[2; 5]$: $[2, 2] + [4] + [5]$, 3 blocks;
10. $[3; 3]$: $[2]$, 1 block;
11. $[3; 4]$: $[2] + [4]$, 2 blocks;
12. $[3; 5]$: $[2] + [4] + [5]$, 3 blocks;
13. $[4; 4]$: $[4]$, 1 block;
14. $[4; 5]$: $[4] + [5]$, 2 blocks;
15. $[5; 5]$: $[5]$, 1 block;

 which is $1 + 2 + 2 + 3 + 4 + 1 + 1 + 2 + 3 + 1 + 2 + 3 + 1 + 2 + 1 = 29$ in total.

#### Tags 

#1700 #NOT OK #combinatorics #data_structures #implementation #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_816_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
