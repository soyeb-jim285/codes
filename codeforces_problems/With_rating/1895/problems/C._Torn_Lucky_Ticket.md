<h1 style='text-align: center;'> C. Torn Lucky Ticket</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

A ticket is a non-empty string of digits from $1$ to $9$.

A lucky ticket is such a ticket that: 

* it has an even length;
* the sum of digits in the first half is equal to the sum of digits in the second half.

You are given $n$ ticket pieces $s_1, s_2, \dots, s_n$. How many pairs $(i, j)$ (for $1 \le i, j \le n$) are there such that $s_i + s_j$ is a lucky ticket? Note that it's possible that $i=j$.

Here, the + operator denotes the concatenation of the two strings. For example, if $s_i$ is 13, and $s_j$ is 37, then $s_i + s_j$ is 1337.

##### Input

The first line contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the number of ticket pieces.

The second line contains $n$ non-empty strings $s_1, s_2, \dots, s_n$, each of length at most $5$ and consisting only of digits from $1$ to $9$.

##### Output

Print a single integer — the number of pairs $(i, j)$ (for $1 \le i, j \le n$) such that $s_i + s_j$ is a lucky ticket.

## Examples

##### Input


```text
105 93746 59 3746 593 746 5937 46 59374 6
```
##### Output

```text

20

```
##### Input


```text
52 22 222 2222 22222
```
##### Output

```text

13

```
##### Input


```text
31 1 1
```
##### Output

```text

9

```


#### Tags 

#1400 #NOT OK #brute_force #dp #hashing #implementation #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_157_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
