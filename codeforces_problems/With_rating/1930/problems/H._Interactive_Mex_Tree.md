<h1 style='text-align: center;'> H. Interactive Mex Tree</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

Alice has a tree $T$ consisting of $n$ nodes, numbered from $1$ to $n$. Alice will show $T$ to Bob. After observing $T$, Bob needs to tell Alice two permutations $p_1$ and $p_2$ of $[1, 2, \ldots, n]$.

Then, Alice will play $q$ rounds of the following game.

* Alice will create an array $a$ that is a permutation of $[0,1,\ldots,n-1]$. The value of node $v$ will be $a_v$.
* Alice will choose two nodes $u$ and $v$ ($1 \leq u, v \leq n$, $u \neq v$) of $T$ and tell them to Bob. Bob will need to find the $\operatorname{MEX}^\dagger$ of the values on the unique simple path between nodes $u$ and $v$.
* To find this value, Bob can ask Alice at most $5$ queries. In each query, Bob should give three integers $t$, $l$ and $r$ to Alice such that $t$ is either $1$ or $2$, and $1 \leq l \leq r \leq n$. Alice will then tell Bob the value equal to $$\min_{i=l}^{r} a[p_{t,i}].$$

## Note

 that all rounds are independent of each other. In particular, the values of $a$, $u$ and $v$ can be different in different rounds.

Bob is puzzled as he only knows the HLD solution, which requires $O(\log(n))$ queries per round. So he needs your help to win the game. 

$^\dagger$ The $\operatorname{MEX}$ (minimum excludant) of a collection of integers $c_1, c_2, \ldots, c_k$ is defined as the smallest non-negative integer $x$ which does not occur in the collection $c$.

## Interaction

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. Read it. The description of the test cases follows.

The first line of each test case contains two positive integers $n$ and $q$ ($2 \leq n \leq 10^5$, $1 \leq q \leq 10^4$) — the number of nodes in $T$ and the number of rounds respectively.

The following next $n-1$ lines contains two integers $u$ and $v$ ($1 \leq u, v \leq n$, $u \neq v$) — denoting an edge between nodes $u$ and $v$. It is guaranteed that the given edges form a tree.

It is guaranteed that the sum of $n$ and $q$ over all test cases does not exceed $10^5$ and $10^4$ respectively.

It is also guaranteed that the sum of $n \cdot q$ does not exceed $3 \cdot 10^6$.

The interaction for each test case begins by outputting two permutations $p_1$ and $p_2$ of $[1, 2, \ldots, n]$.

On a new line, output $n$ space-separated distinct integers denoting $p_1$. 

In the next line, output $n$ space-separated distinct integers denoting $p_2$. 

Alice will start playing the game.

For each round, you must read two integers, $u$ and $v$ ($1 \leq u, v \leq n$, $u \neq v$). You need to find the $\operatorname{MEX}$ of the values on the unique simple path between nodes $u$ and $v$.

To make a query, output "? $t$ $l$ $r$" without quotes, such that $t$ is either $1$ or $2$, and $1 \leq l \leq r \leq n$. Afterwards, you should read a single integer — the answer to your query $\min_{i=l}^{r} a_{p_{t,i}}$. You can make at most $5$ such queries in each round.

If you want to print the answer, output "! $x$" ($1 \leq x, y \leq n$) without quotes. After doing that, read a single integer, which is normally equal to $1$.

If you receive the integer $-1$ instead of a valid reply, it means your program has made an invalid query, exceeded the query limit, or gave an incorrect answer on the previous test case. Your program must terminate immediately to receive a Wrong Answer verdict. Otherwise, you can get an arbitrary verdict because your solution will continue to read from a closed stream.

After printing a query or the answer, do not forget to output the end of the line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use: 

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

Hacks

To hack, follow the test format below.

The first line should contain a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case should contain two positive integers $n$ and $q$ ($2 \leq n \leq 10^5$; $1 \leq q \leq 10^4$) — the number of nodes in $T$ and the number of rounds respectively.

The following next $n-1$ lines should contain two integers $u$ and $v$ ($1 \leq u, v \leq n$, $u \neq v$) — denoting an edge between nodes $u$ and $v$. The given edges must form a tree.

For each of the $q$ rounds, first print a permutation of $[0, 1, 2, \ldots, n-1]$ on a new line, denoting the array $a$ chosen by Alice during the start of the round.

In the following line, print two distinct nodes $u$ and $v$ ($1 \leq u, v \leq v$, $u \neq v$), representing the endpoints of the path asked by Alice.

The sum of $n$ and $q$ over all test cases should not exceed $10^5$ and $10^4$ respectively.

The sum of $n \cdot q$ should not exceed $3 \cdot 10^6$.

## Example

#Input
```text
1
3 1
1 2
2 3


2 3

1

0

1
```
#Output
```text





1 2 3
2 1 3

? 1 2 3

? 2 1 3

! 0

```
## Note

In the first test, the interaction proceeds as follows.

 

| Solution | Jury | Explanation |
| --- | --- | --- |
|  | 1 | There are 1 test cases. |
|  | 3 1 | The tree $T$ consists of $3$ nodes, and Alice will play for only one round. |
|  | 1 2 | First edge of $T$ |
|  | 2 3 | Second edge of $T$ |
| 1 2 3 |  | The permutation $p_1$ |
| 2 1 3 |  | The permutation $p_2$ |
|  |  | Alice shuffles $a$ to $a=[0,2,1]$ before giving the nodes for the only round. |
|  | 2 3 | Nodes for the round |
| ? 1 2 3 | 1 | $\min(a_{p_{1,2}},a_{p_{1,3}})=\min(a_2,a_3)=1$ |
| ? 2 1 3 | 0 | $\min(a_{p_{2,1}},a_{p_{2,2}},a_{p_{2,3}})=\min(a_2,a_1,a_3)=0$ |
| ! 0 | 1 | Considering the output of queries, it is clear that $\operatorname{MEX}$ is $0$. Since the output is correct, the jury responds with $1$. |

 After each test case, make sure to read $1$ or $-1$.



#### Tags 

#3300 #NOT OK #constructive_algorithms #dfs_and_similar #interactive #trees 

## Blogs
- [All Contest Problems](../think-cell_Round_1.md)
- [think-cell Round 1 (en)](../blogs/think-cell_Round_1_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
- [Discussion (en)](../blogs/Discussion_(en).md)
