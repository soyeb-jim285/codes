<h1 style='text-align: center;'> F. Triangle Formation</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given $n$ sticks, numbered from $1$ to $n$. The length of the $i$-th stick is $a_i$.

You need to answer $q$ queries. In each query, you are given two integers $l$ and $r$ ($1 \le l < r \le n$, $r - l + 1 \ge 6$). Determine whether it is possible to choose $6$ distinct sticks from the sticks numbered $l$ to $r$, to form $2$ non-degenerate triangles$^{\text{∗}}$.

$^{\text{∗}}$A triangle with side lengths $a$, $b$, and $c$ is called non-degenerate if: 

* $a < b + c$,
* $b < a + c$, and
* $c < a + b$.
### Input

The first line contains two integers $n$ and $q$ ($6 \le n \le 10^5$, $1 \le q \le 10^5$) — the number of sticks and the number of queries respectively.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$) — $a_i$ denotes the length of the $i$-th stick.

Each of the following $q$ lines contains two integers $l$ and $r$ ($1 \le l < r \le n$, $r - l + 1 \ge 6$) — the parameters of each query.

### Output

For each query, output "YES" (without quotes) if it is possible to form $2$ triangles, and "NO" (without quotes) otherwise.

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

## Example

### Input


```text
10 55 2 2 10 4 10 6 1 5 31 62 72 85 104 10
```
### Output

```text

YES
NO
YES
NO
YES

```
## Note

In the first query, the lengths of the sticks are $[5, 2, 2, 10, 4, 10]$. Two sets of sticks $[2, 4, 5]$ and $[2, 10, 10]$ can be selected to form $2$ non-degenerate triangles.

In the second query, the lengths of the sticks are $[2, 2, 10, 4, 10, 6]$. It can be shown that it is impossible to form $2$ non-degenerate triangles.

In the third query, the lengths of the sticks are $[2, 2, 10, 4, 10, 6, 1]$. Two sets of sticks $[1, 2, 2]$ and $[4, 10, 10]$ can be selected to form $2$ non-degenerate triangles.

In the fourth query, the lengths of the sticks are $[4, 10, 6, 1, 5, 3]$. It can be shown that it is impossible to form $2$ non-degenerate triangles.

In the fifth query, the lengths of the sticks are $[10, 4, 10, 6, 1, 5, 3]$. Two sets of sticks $[1, 10, 10]$ and $[3, 4, 5]$ can be selected to form $2$ non-degenerate triangles.



#### Tags 

#NOT OK #brute_force #greedy #implementation #math #sortings 

## Blogs
- [All Contest Problems](../Pinely_Round_4_(Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial #1 (en)](../blogs/Tutorial_1_(en).md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
