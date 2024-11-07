<h1 style='text-align: center;'> A. Closing The Gap</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are $n$ block towers in a row, where tower $i$ has a height of $a_i$. You're part of a building crew, and you want to make the buildings look as nice as possible. In a single day, you can perform the following operation:

* Choose two indices $i$ and $j$ ($1 \leq i, j \leq n$; $i \neq j$), and move a block from tower $i$ to tower $j$. This essentially decreases $a_i$ by $1$ and increases $a_j$ by $1$.

You think the ugliness of the buildings is the height difference between the tallest and shortest buildings. Formally, the ugliness is defined as $\max(a)-\min(a)$. 

What's the minimum possible ugliness you can achieve, after any number of days?

### Input

The first line contains one integer $t$ ($1 \leq t \leq 1000$) — the number of test cases. Then $t$ cases follow.

The first line of each test case contains one integer $n$ ($2 \leq n \leq 100$) — the number of buildings.

The second line of each test case contains $n$ space separated integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq 10^7$) — the heights of the buildings.

### Output

For each test case, output a single integer — the minimum possible ugliness of the buildings.

## Example

### Input


```text
3
3
10 10 10
4
3 2 1 2
5
1 2 3 1 5
```
### Output


```text
0
0
1
```
## Note

In the first test case, the ugliness is already $0$.

In the second test case, you should do one operation, with $i = 1$ and $j = 3$. The new heights will now be $[2, 2, 2, 2]$, with an ugliness of $0$.

In the third test case, you may do three operations: 

1. with $i = 3$ and $j = 1$. The new array will now be $[2, 2, 2, 1, 5]$,
2. with $i = 5$ and $j = 4$. The new array will now be $[2, 2, 2, 2, 4]$,
3. with $i = 5$ and $j = 3$. The new array will now be $[2, 2, 3, 2, 3]$.

 The resulting ugliness is $1$. It can be proven that this is the minimum possible ugliness for this test.

#### Tags 

#800 #NOT OK #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_18.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
