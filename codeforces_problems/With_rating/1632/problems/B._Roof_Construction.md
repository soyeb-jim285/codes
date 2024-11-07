<h1 style='text-align: center;'> B. Roof Construction</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

It has finally been decided to build a roof over the football field in School 179. Its construction will require placing $n$ consecutive vertical pillars. Furthermore, the headmaster wants the heights of all the pillars to form a permutation $p$ of integers from $0$ to $n - 1$, where $p_i$ is the height of the $i$-th pillar from the left $(1 \le i \le n)$.

As the chief, you know that the cost of construction of consecutive pillars is equal to the maximum value of the bitwise XOR of heights of all pairs of adjacent pillars. In other words, the cost of construction is equal to $\max\limits_{1 \le i \le n - 1}{p_i \oplus p_{i + 1}}$, where $\oplus$ denotes the [bitwise XOR operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR).

Find any sequence of pillar heights $p$ of length $n$ with the smallest construction cost.

In this problem, a permutation is an array consisting of $n$ distinct integers from $0$ to $n - 1$ in arbitrary order. For example, $[2,3,1,0,4]$ is a permutation, but $[1,0,1]$ is not a permutation ($1$ appears twice in the array) and $[1,0,3]$ is also not a permutation ($n=3$, but $3$ is in the array).

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). Description of the test cases follows.

The only line for each test case contains a single integer $n$ ($2 \le n \le 2 \cdot 10^5$) — the number of pillars for the construction of the roof.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case print $n$ integers $p_1$, $p_2$, $\ldots$, $p_n$ — the sequence of pillar heights with the smallest construction cost.

If there are multiple answers, print any of them.

## Example

### Input


```text
423510
```
### Output

```text

0 1
2 0 1
3 2 1 0 4
4 6 3 2 0 8 9 1 7 5

```
## Note

For $n = 2$ there are $2$ sequences of pillar heights: 

* $[0, 1]$ — cost of construction is $0 \oplus 1 = 1$.
* $[1, 0]$ — cost of construction is $1 \oplus 0 = 1$.

For $n = 3$ there are $6$ sequences of pillar heights: 

* $[0, 1, 2]$ — cost of construction is $\max(0 \oplus 1, 1 \oplus 2) = \max(1, 3) = 3$.
* $[0, 2, 1]$ — cost of construction is $\max(0 \oplus 2, 2 \oplus 1) = \max(2, 3) = 3$.
* $[1, 0, 2]$ — cost of construction is $\max(1 \oplus 0, 0 \oplus 2) = \max(1, 2) = 2$.
* $[1, 2, 0]$ — cost of construction is $\max(1 \oplus 2, 2 \oplus 0) = \max(3, 2) = 3$.
* $[2, 0, 1]$ — cost of construction is $\max(2 \oplus 0, 0 \oplus 1) = \max(2, 1) = 2$.
* $[2, 1, 0]$ — cost of construction is $\max(2 \oplus 1, 1 \oplus 0) = \max(3, 1) = 3$.


#### Tags 

#1000 #NOT OK #bitmasks #constructive_algorithms 

## Blogs
- [All Contest Problems](../Codeforces_Round_769_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
