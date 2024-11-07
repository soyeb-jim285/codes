<h1 style='text-align: center;'> B. Coloring</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Cirno_9baka has a paper tape with $n$ cells in a row on it. As he thinks that the blank paper tape is too dull, he wants to paint these cells with $m$ kinds of colors. For some aesthetic reasons, he thinks that the $i$-th color must be used exactly $a_i$ times, and for every $k$ consecutive cells, their colors have to be distinct. 

Help Cirno_9baka to figure out if there is such a way to paint the cells.

### Input

The first line contains a single integer $t$ ($1 \leq t \leq 10\,000$)  — the number of test cases. The description of test cases follows.

The first line of each test case contains three integers $n$, $m$, $k$ ($1 \leq k \leq n \leq 10^9$, $1 \leq m \leq 10^5$, $m \leq n$). Here $n$ denotes the number of cells, $m$ denotes the number of colors, and $k$ means that for every $k$ consecutive cells, their colors have to be distinct.

The second line of each test case contains $m$ integers $a_1, a_2, \cdots , a_m$ ($1 \leq a_i \leq n$)  — the numbers of times that colors have to be used. It's guaranteed that $a_1 + a_2 + \ldots + a_m = n$.

It is guaranteed that the sum of $m$ over all test cases does not exceed $10^5$.

### Output

For each test case, output "YES" if there is at least one possible coloring scheme; otherwise, output "NO".

You may print each letter in any case (for example, "YES", "Yes", "yes", and "yEs" will all be recognized as positive answers).

## Example

### Input


```text
212 6 21 1 1 1 1 712 6 22 2 2 2 2 2
```
### Output

```text

NO
YES

```
## Note

In the first test case, there is no way to color the cells satisfying all the conditions.

In the second test case, we can color the cells as follows: $(1, 2, 1, 2, 3, 4, 3, 4, 5, 6, 5, 6)$. For any $2$ consecutive cells, their colors are distinct.



#### Tags 

#1500 #NOT OK #constructive_algorithms #greedy #math 

## Blogs
- [All Contest Problems](../Polynomial_Round_2022_(Div._1_+_Div._2,_Rated,_Prizes!).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
