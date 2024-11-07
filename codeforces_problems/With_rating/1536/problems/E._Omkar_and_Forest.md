<h1 style='text-align: center;'> E. Omkar and Forest</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Omkar's most recent follower, Ajit, has entered the Holy Forest. Ajit realizes that Omkar's forest is an $n$ by $m$ grid ($1 \leq n, m \leq 2000$) of some non-negative integers. Since the forest is blessed by Omkar, it satisfies some special conditions:

1. For any two adjacent (sharing a side) cells, the absolute value of the difference of numbers in them is at most $1$.
2. If the number in some cell is strictly larger than $0$, it should be strictly greater than the number in at least one of the cells adjacent to it.

Unfortunately, Ajit is not fully worthy of Omkar's powers yet. He sees each cell as a "0" or a "#". If a cell is labeled as "0", then the number in it must equal $0$. Otherwise, the number in it can be any nonnegative integer.

Determine how many different assignments of elements exist such that these special conditions are satisfied. Two assignments are considered different if there exists at least one cell such that the numbers written in it in these assignments are different. Since the answer may be enormous, find the answer modulo $10^9+7$.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \leq t \leq 100$). Description of the test cases follows.

The first line of each test case contains two integers $n$ and $m$ ($1 \leq n, m \leq 2000, nm \geq 2$) – the dimensions of the forest.

$n$ lines follow, each consisting of one string of $m$ characters. Each of these characters is either a "0" or a "#".

It is guaranteed that the sum of $n$ over all test cases does not exceed $2000$ and the sum of $m$ over all test cases does not exceed $2000$.

### Output

For each test case, print one integer: the number of valid configurations modulo $10^9+7$.

## Example

### Input


```text
4
3 4
0000
00#0
0000
2 1
#
#
1 2
##
6 29
#############################
#000##0###0##0#0####0####000#
#0#0##00#00##00####0#0###0#0#
#0#0##0#0#0##00###00000##00##
#000##0###0##0#0##0###0##0#0#
#############################
```
### Output


```text
2
3
3
319908071
```
## Note

For the first test case, the two valid assignments are

$0000\\\ 0000\\\ 0000$

and

$0000\\\ 0010\\\ 0000$



#### Tags 

#2300 #NOT OK #combinatorics #graphs #math #shortest_paths 

## Blogs
- [All Contest Problems](../Codeforces_Round_724_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
