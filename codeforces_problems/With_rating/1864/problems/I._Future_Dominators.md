<h1 style='text-align: center;'> I. Future Dominators</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Dhruvil and amenotiomoi are sitting in different countries and chatting online. Initially, amenotiomoi has an empty board of size $n \times n$, and Dhruvil has a sequence of integers $1, 2, \ldots, n^2$, each number occurring exactly once. The numbers may be placed in the cells of the board, each cell is either empty or contains exactly one number.

The current state of the board is called good, if there is a way of placing the remaining numbers in empty cells so that all numbers except $1$ have a neighbor with a smaller value. Two cells are neighbors if they share an edge.

The rows are numbered from $1$ to $n$ from top to bottom, the columns are numbered from $1$ to $n$ from left to right. The cell at the intersection of the $x$-th row and the $y$-th column is denoted as $(x, y)$.

To chat, amenotiomoi asks $q$ queries to Dhruvil. Each time he provides Dhruvil with an empty cell $(x, y)$. Dhruvil has to place one of the remaining numbers in this cell so that the board is still good. Among all ways to do this, he chooses the largest possible number he can place and sends this number to amenotiomoi as the answer to the query.

Since amenotiomoi knows the correct answer every time, he tells Dhruvil $(x \oplus k,y \oplus k)$ instead of $(x, y)$, where $k$ is the answer for the previous query. If amenotiomoi is sending the first query, he considers $k = 0$. Each time Dhruvil has to decode the query and send the answer to amenotiomoi. Here $\oplus$ denotes the [bitwise XOR operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR).

Help Dhruvil reply to all amenotiomoi's queries.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 100$). The description of the test cases follows.

The first line of each test case contains two integers $n$ and $q$ ($1 \le n \le 10^3$, $1 \le q \le n^2$).

The $i$-th of the following $q$ lines contains two integers $x_i'$ and $y_i'$. The corresponding cell is $(x_i, y_i)$, where $x_i'=x_i \oplus k$ and $y_i' = y_i \oplus k$, where $k$ is the correct answer for the previous query. If $i = 1$, then $k = 0$ is used. It is guaranteed that $1 \le x_i, y_i \le n$ and that $(x_i, y_i)$ is an empty cell at the moment of $i$-th query.

It is guaranteed that the sum of $n^2$ over all test cases does not exceed $10^6$.

### Output

For each test case, output one line, containing the answers to all queries, separated by spaces.

## Example

### Input


```text
32 41 16 63 01 23 92 18 114 44 42 04 411 101 33 21 11 1
```
### Output

```text

4 2 3 1 
9 7 6 3 5 8 2 1 4 
1 

```
## Note

In the first test case, the first query is $(1, 1)$, Dhruvil puts $4$ in that cell.

The second query is $(6, 6)$, Dhruvil decode it as $(2, 2)$ using the previous answer ($2 \oplus 4 = 6$). If Dhruvil places $3$ to the cell $(2, 2)$, the board stops being good. So, Dhruvil places $2$ in this cell.

The third query is $(3, 0)$, Dhruvil decodes it as $(1, 2)$ using the previous answer ($1 \oplus 2 = 3$, $2 \oplus 2 = 0$). Dhruvil can place $3$ in this cell.

The fourth query is $(1, 2)$, Dhruvil decodes it as $(2, 1)$ using the previous answer ($2 \oplus 3 = 1$, $1 \oplus 3 = 2$). Now, only $1$ remains in the sequence, and after Dhruvil places $1$ in this cell, the board becomes full and remains good.

Here you can see the entire history of the board:

 ![](images/8b0c86a4083664ca7c6bd72e103535821b6dabf2.png) In the second test case, the final state of the board is:

 

| $8$ | $7$ | $5$ |
| --- | --- | --- |
| $9$ | $3$ | $4$ |
| $1$ | $2$ | $6$ |

 

#### Tags 

#3500 #NOT OK #graphs #greedy 

## Blogs
- [All Contest Problems](../Harbour.Space_Scholarship_Contest_2023-2024_(Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
