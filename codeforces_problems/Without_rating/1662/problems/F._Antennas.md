<h1 style='text-align: center;'> F. Antennas</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are $n$ equidistant antennas on a line, numbered from $1$ to $n$. Each antenna has a power rating, the power of the $i$-th antenna is $p_i$. 

The $i$-th and the $j$-th antenna can communicate directly if and only if their distance is at most the minimum of their powers, i.e., $|i-j| \leq \min(p_i, p_j)$. Sending a message directly between two such antennas takes $1$ second.

What is the minimum amount of time necessary to send a message from antenna $a$ to antenna $b$, possibly using other antennas as relays?

### Input

Each test contains multiple test cases. The first line contains an integer $t$ ($1\le t\le 100\,000$) — the number of test cases. The descriptions of the $t$ test cases follow.

The first line of each test case contains three integers $n$, $a$, $b$ ($1 \leq a, b \leq n \leq 200\,000$) — the number of antennas, and the origin and target antenna. 

The second line contains $n$ integers $p_1, p_2, \dots, p_n$ ($1 \leq p_i \leq n$) — the powers of the antennas.

The sum of the values of $n$ over all test cases does not exceed $200\,000$. 

### Output

For each test case, print the number of seconds needed to trasmit a message from $a$ to $b$. It can be shown that under the problem constraints, it is always possible to send such a message.

## Example

### Input


```text
310 2 94 1 1 1 5 1 1 1 1 51 1 113 1 33 3 1
```
### Output

```text

4
0
2

```
## Note

In the first test case, we must send a message from antenna $2$ to antenna $9$. A sequence of communications requiring $4$ seconds, which is the minimum possible amount of time, is the following: 

* In $1$ second we send the message from antenna $2$ to antenna $1$. This is possible since $|2-1|\le \min(1, 4) = \min(p_2, p_1)$.
* In $1$ second we send the message from antenna $1$ to antenna $5$. This is possible since $|1-5|\le \min(4, 5) = \min(p_1, p_5)$.
* In $1$ second we send the message from antenna $5$ to antenna $10$. This is possible since $|5-10|\le \min(5, 5) = \min(p_5, p_{10})$.
* In $1$ second we send the message from antenna $10$ to antenna $9$. This is possible since $|10-9|\le \min(5, 1) = \min(p_{10}, p_9)$.


#### Tags 

#NOT OK #data_structures #dfs_and_similar #graphs #graphs #implementation #implementation #shortest_paths #shortest_paths 

## Blogs
- [All Contest Problems](../SWERC_2021-2022_-_Online_Mirror_(Unrated,_ICPC_Rules,_Teams_Preferred).md)
- [SWERC 2021-2022 (en)](../blogs/SWERC_2021-2022_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
