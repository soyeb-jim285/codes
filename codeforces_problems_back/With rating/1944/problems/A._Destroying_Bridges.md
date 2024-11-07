<h1 style='text-align: center;'> A. Destroying Bridges</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are $n$ islands, numbered $1, 2, \ldots, n$. Initially, every pair of islands is connected by a bridge. Hence, there are a total of $\frac{n (n - 1)}{2}$ bridges. 

Everule lives on island $1$ and enjoys visiting the other islands using bridges. Dominater has the power to destroy at most $k$ bridges to minimize the number of islands that Everule can reach using (possibly multiple) bridges.

Find the minimum number of islands (including island $1$) that Everule can visit if Dominater destroys bridges optimally.

## Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^3$) — the number of test cases. The description of the test cases follows.

The first and only line of each test case contains two integers $n$ and $k$ ($1 \le n \le 100$, $0 \le k \le \frac{n \cdot (n - 1)}{2}$).

## Output

For each test case, output the minimum number of islands that Everule can visit if Dominater destroys bridges optimally.

## Example

## Input


```

62 02 14 15 105 34 4
```
## Output


```

2
1
4
1
5
1

```
## Note

In the first test case, since no bridges can be destroyed, all the islands will be reachable.

In the second test case, you can destroy the bridge between islands $1$ and $2$. Everule will not be able to visit island $2$ but can still visit island $1$. Therefore, the total number of islands that Everule can visit is $1$.

In the third test case, Everule always has a way of reaching all islands despite what Dominater does. For example, if Dominater destroyed the bridge between islands $1$ and $2$, Everule can still visit island $2$ by traveling by $1 \to 3 \to 2$ as the bridges between $1$ and $3$, and between $3$ and $2$ are not destroyed.

In the fourth test case, you can destroy all bridges since $k = \frac{n \cdot (n - 1)}{2}$. Everule will be only able to visit $1$ island (island $1$).



#### tags 

#800 #graphs #greedy #math 