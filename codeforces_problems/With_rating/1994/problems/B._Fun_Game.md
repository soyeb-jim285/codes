<h1 style='text-align: center;'> B. Fun Game</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vova really loves the [XOR](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) operation (denoted as $\oplus$). Recently, when he was going to sleep, he came up with a fun game.

At the beginning of the game, Vova chooses two binary sequences $s$ and $t$ of length $n$ and gives them to Vanya. A binary sequence is a sequence consisting only of the numbers $0$ and $1$. Vanya can choose integers $l, r$ such that $1 \leq l \leq r \leq n$, and for all $l \leq i \leq r$ simultaneously replace $s_i$ with $s_i \oplus s_{i - l + 1}$, where $s_i$ is the $i$-th element of the sequence $s$.

In order for the game to be interesting, there must be a possibility to win. Vanya wins if, with an unlimited number of actions, he can obtain the sequence $t$ from the sequence $s$. Determine if the game will be interesting for the sequences $s$ and $t$.

### Input

Each test consists of multiple test cases. The first line contains an integer $q$ ($1 \le q \le 10^{4}$) — the number of test cases. Then follows the description of the test cases.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 2 \cdot 10^5$) — the length of the sequences $s$ and $t$.

The second line of each test case contains a binary sequence $s$ of length $n$.

The third line of each test case contains a binary sequence $t$ of length $n$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output "Yes" if the game will be interesting, otherwise output "No".

You can output each letter in any case (for example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as a positive answer).

## Example

### Input


```text
6101701101000110100910010101010111111040011101140100000181011011101100000
```
### Output

```text

NO
YES
YES
NO
YES
YES

```
## Note

In the first test case, Vanya will not be able to change the sequence $s$ with the only possible action of choosing $l = r = 1$.

In the second test case, the sequences $s$ and $t$ are already equal.

In the third test case, Vanya can act as follows:

1. Choose $l = 3$ and $r = 5$, then $s$ will become $\mathtt{101101010}$.
2. Choose $l = 5$ and $r = 6$, then $s$ will become $\mathtt{101111010}$.
3. Choose $l = 7$ and $r = 7$, then $s$ will become $\mathtt{101111110}$.


#### Tags 

#1100 #NOT OK #bitmasks #constructive_algorithms #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_959_sponsored_by_NEAR_(Div._1_+_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
- [Editorial (en)](../blogs/Editorial_(en).md)
