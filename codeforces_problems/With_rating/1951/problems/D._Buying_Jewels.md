<h1 style='text-align: center;'> D. Buying Jewels</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

[Nightwish feat. Jonsu - Erämaan Viimeinen](https://youtu.be/QYlFn5q_UQk)ඞAlice has $n$ coins and wants to shop at Bob's jewelry store. Today, although Bob has not set up the store yet, Bob wants to make sure Alice will buy exactly $k$ jewels. To set up the store, Bob can erect at most $60$ stalls (each containing an unlimited amount of jewels) and set the price per jewel for each stall to be an integer number of coins between $1$ and $10^{18}$.

Fortunately, Bob knows that Alice buys greedily: and she will go to stall $1$, buy as many jewels as possible, then go to stall $2$, buy as many jewels as possible, and so on until the last stall. Knowing this, Bob can choose the number of stalls to set up, as well as set the price for each stall so that Alice buys exactly $k$ jewels. Help Bob fulfill the task, or determine if it is impossible to do so.

## Note

 that Alice does not need to spend all her coins.

### Input

Each test contains multiple test cases. The first line contains an integer $t$ ($1 \le t \le 1000$) — the number of test cases. The description of the test cases follows.

Each test case contains two positive integers $n$ and $k$ ($1 \le n, k \le 10^{18}$) — the number of coins Alice has and the number of jewels Bob wants Alice to have bought at the end.

### Output

For each test case, print on one line "YES" if Bob can erect at most $60$ stalls and set the prices for the stalls such that Alice buys exactly $k$ jewels, or "NO" if it is impossible to do so.

If the answer is "YES", on the second line, print an integer $s$ ($1 \le s \le 60$) — the number of stalls to be set up by Bob. On the third line, print $s$ positive integers $p_1, p_2, \ldots, p_s$ ($1 \le p_i \le 10^{18})$ that represent such a satisfactory pricing $p$, where $p_i$ is the price per jewel for stall $i$. If there are multiple such $p$'s, print any of them.

## Example

### Input


```text
37 36 4255 8
```
### Output

```text

YES
10
2 3 4 5 6 7 8 9 10 11
NO
YES
8
128 64 32 16 8 4 2 1

```
## Note

In the first test case, at the first stall, Alice buys $3$ jewels and is left with $1$ coin. This is not enough to buy any jewels for any of the remaining stalls, so Alice buys exactly $3$ jewels at the end.

In the third test case, 

* At the first stall, Alice buys $1$ jewel and is left with $127$ coins.
* At the second stall, Alice buys $1$ jewel and is left with $63$ coins.
* At the third stall, Alice buys $1$ jewel and is left with $31$ coins.
* At the fourth stall, Alice buys $1$ jewel and is left with $15$ coins.
* At the fifth stall, Alice buys $1$ jewel and is left with $7$ coins.
* At the sixth stall, Alice buys $1$ jewel and is left with $3$ coins.
* At the seventh stall, Alice buys $1$ jewel and is left with $1$ coin.
* At the eighth stall, Alice buys $1$ jewel and is left with $0$ coins.

 Therefore, Alice buys exactly $8$ jewels in total.

#### Tags 

#2000 #OK #constructive_algorithms #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_25.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
