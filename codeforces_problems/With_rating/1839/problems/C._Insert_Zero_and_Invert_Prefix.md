<h1 style='text-align: center;'> C. Insert Zero and Invert Prefix</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have a sequence $a_1, a_2, \ldots, a_n$ of length $n$, each element of which is either $0$ or $1$, and a sequence $b$, which is initially empty.

You are going to perform $n$ operations. On each of them you will increase the length of $b$ by $1$.

* On the $i$-th operation you choose an integer $p$ between $0$ and $i-1$. You insert $0$ in the sequence $b$ on position $p+1$ (after the first $p$ elements), and then you invert the first $p$ elements of $b$.
* More formally: let's denote the sequence $b$ before the $i$-th ($1 \le i \le n$) operation as $b_1, b_2, \ldots, b_{i-1}$. On the $i$-th operation you choose an integer $p$ between $0$ and $i-1$ and replace $b$ with $\overline{b_1}, \overline{b_2}, \ldots, \overline{b_{p}}, 0, b_{p+1}, b_{p+2}, \ldots, b_{i-1}$. Here, $\overline{x}$ denotes the binary inversion. Hence, $\overline{0} = 1$ and $\overline{1} = 0$.

You can find examples of operations in the 
## Note

s section.

Determine if there exists a sequence of operations that makes $b$ equal to $a$. If such sequence of operations exists, find it.

### Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains one integer $n$ ($1 \le n \le 10^5$) — the length of the sequence $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le 1$) — the sequence $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

### Output

For each test case: 

* output "NO", if it is impossible to make $b$ equal to $a$ using the given operations;
* otherwise, output "YES" in the first line and $n$ integers $p_1, p_2, \ldots, p_n$ ($0 \le p_i \le i-1$) in the second line — the description of sequence of operations that makes $b$ equal to $a$. Here, $p_i$ should be the integer you choose on the $i$-th operation. If there are multiple solutions, you can output any of them.
## Example

### Input


```text
451 1 0 0 01130 1 161 0 0 1 1 0
```
### Output

```text

YES
0 0 2 1 3
NO
NO
YES
0 1 0 2 4 2
```
## Note

In the first test case, 

1. Before the first operation, $b = [\,]$. You choose $p = 0$ and replace $b$ with $[\, \underline{0} \,]$
2. On the second operation you choose $p = 0$ and replace $b$ with $[\, \underline{0}, 0 \,]$.
3. On the third operation you choose $p = 2$ and replace $b$ with $[\, 1, 1, \underline{0} \,]$.
4. On the fourth operation you choose $p = 1$ and replace $b$ with $[\, 0, \underline{0}, 1, 0 \,]$.
5. On the fifth operation you choose $p = 3$ and replace $b$ with $[\, 1, 1, 0, \underline{0}, 0 \,]$.

Hence, sequence $b$ changes in the following way: $[\,]$ $\xrightarrow{p \, = \, 0}$ $[\, \underline{0} \,]$ $\xrightarrow{p \, = \, 0}$ $[\, \underline{0}, 0 \,]$ $\xrightarrow{p \, = \, 2}$ $[\, 1, 1, \underline{0} \,]$ $\xrightarrow{p \, = \, 1}$ $[\, 0, \underline{0}, 1, 0 \,]$ $\xrightarrow{p \, = \, 3}$ $[\, 1, 1, 0, \underline{0}, 0 \,]$. In the end the sequence $b$ is equal to the sequence $a$, so this way to perform operations is one of the correct answers.

In the second test case, $n = 1$ and the only achiveable sequence $b$ is $[\, 0 \, ]$.

In the third test case, there are six possible sequences of operations:

1. $[\,]$ $\xrightarrow{p \, = \, 0}$ $[\, \underline{0} \,]$ $\xrightarrow{p \, = \, 0}$ $[\, \underline{0}, 0 \,]$ $\xrightarrow{p \, = \, 0}$ $[\, \underline{0}, 0, 0 \,]$.
2. $[\,]$ $\xrightarrow{p \, = \, 0}$ $[\, \underline{0} \,]$ $\xrightarrow{p \, = \, 0}$ $[\, \underline{0}, 0 \,]$ $\xrightarrow{p \, = \, 1}$ $[\, 1, \underline{0}, 0 \,]$.
3. $[\,]$ $\xrightarrow{p \, = \, 0}$ $[\, \underline{0} \,]$ $\xrightarrow{p \, = \, 0}$ $[\, \underline{0}, 0 \,]$ $\xrightarrow{p \, = \, 2}$ $[\, 1, 1, \underline{0} \,]$.
4. $[\,]$ $\xrightarrow{p \, = \, 0}$ $[\, \underline{0} \,]$ $\xrightarrow{p \, = \, 1}$ $[\, 1, \underline{0} \,]$ $\xrightarrow{p \, = \, 0}$ $[\, \underline{0}, 1, 0 \,]$.
5. $[\,]$ $\xrightarrow{p \, = \, 0}$ $[\, \underline{0} \,]$ $\xrightarrow{p \, = \, 1}$ $[\, 1, \underline{0} \,]$ $\xrightarrow{p \, = \, 1}$ $[\, 0, \underline{0}, 0 \,]$.
6. $[\,]$ $\xrightarrow{p \, = \, 0}$ $[\, \underline{0} \,]$ $\xrightarrow{p \, = \, 1}$ $[\, 1, \underline{0} \,]$ $\xrightarrow{p \, = \, 2}$ $[\, 0, 1, \underline{0} \,]$.

None of them makes $b$ equal to $[\, 0, 1, 1 \,]$, so the answer is "NO".



#### Tags 

#1300 #NOT OK #constructive_algorithms 

## Blogs
- [All Contest Problems](../Codeforces_Round_876_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
