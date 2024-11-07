<h1 style='text-align: center;'> G. Olympiad Training</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Anton decided to get ready for an Olympiad in Informatics. Ilya prepared $n$ tasks for him to solve. It is possible to submit the solution for the $i$-th task in the first $d_{i}$ days only. Anton cannot solve more than one task a day. Ilya estimated the usefulness of the $i$-th tasks as $r_{i}$ and divided the tasks into three topics, the topic of the $i$-th task is $type_{i}$.

Anton wants to solve exactly $a$ tasks on the first topic, $b$ tasks on the second topic and $c$ tasks on the third topic. Tell Anton if it is possible to do so, and if it is, calculate the maximum total usefulness of the tasks he may solve.

### Input

The first line of input contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains four integers $n, a, b, c$ ($1 \le n \le 10^5$, $0 \le a, b, c \le n$).

The following $n$ lines contain three integers each — $r_i, type_i, d_i$ ($0 \le r_i \le 10^{9}$, $1 \le type_i \le 3$, $1 \le d_i \le n$).

The sum of $n$ over all test cases does not exceed $10^5$.

### Output

For each test case print $-1$ if Anton cannot reach his goal; otherwise, print the maximum usefulness of the tasks he will solve.

## Example

### Input


```text
44 1 1 01 2 11 1 10 1 21 2 23 1 1 11 1 27 2 19 3 24 2 1 0100 2 15 2 37 1 25 1 25 1 1 110 3 19 2 320 1 116 1 41 3 4
```
### Output

```text

2
-1
17
35

```
## Note

In the first test case from the sample test Anton can solve tasks $2$ and $4$.

In the second test case from the sample test it is impossible to fulfill Anton's wish.

In the third test case from the sample test it is optimal to solve tasks $2$, $3$ and $4$.

In the last test case from the sample test it is optimal to solve tasks $1$, $2$ and $4$.



#### Tags 

#3500 #NOT OK #binary_search #data_structures #dp #flows #geometry #implementation #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_23.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
