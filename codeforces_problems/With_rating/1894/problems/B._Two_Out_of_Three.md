<h1 style='text-align: center;'> B. Two Out of Three</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given an array $a_1, a_2, \ldots, a_n$. You need to find an array $b_1, b_2, \ldots, b_n$ consisting of numbers $1$, $2$, $3$ such that exactly two out of the following three conditions are satisfied:

1. There exist indices $1 \leq i, j \leq n$ such that $a_i = a_j$, $b_i = 1$, $b_j = 2$.
2. There exist indices $1 \leq i, j \leq n$ such that $a_i = a_j$, $b_i = 1$, $b_j = 3$.
3. There exist indices $1 \leq i, j \leq n$ such that $a_i = a_j$, $b_i = 2$, $b_j = 3$.

If such an array does not exist, you should report it.

### Input

Each test contains multiple test cases. The first line contains a single integer $t$ $(1 \leq t \leq 500)$ — the number of test cases. Each test case is described as follows.

The first line of each test case contains an integer $n$ $(1 \leq n \leq 100)$ — the length of the array $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ $(1 \leq a_i \leq 100)$ — the elements of the array $a$.

### Output

For each test case, print -1 if there is no solution. Otherwise, print $b_1, b_2, \ldots, b_n$ — an array consisting of numbers $1$, $2$, $3$ that satisfies exactly two out of three conditions. If there are multiple possible answers, you can print any of them.

## Example

### Input


```text
961 2 3 2 2 377 7 7 7 7 7 741 1 2 271 2 3 4 5 6 752 3 3 3 231 2 191 1 1 7 7 7 9 9 9111893 84 50 21 88 52 16 50 63 1 30 85 29 67 63 58 37 69
```
### Output

```text

1 2 3 1 1 1 
-1
3 2 2 1 
-1
2 1 2 1 3 
-1
1 1 2 2 1 2 2 3 3
-1
3 2 1 3 3 3 3 2 2 1 1 2 3 1 3 1 1 2

```
## Note

In the first test case, $b = [1, 2, 3, 1, 1, 1]$ satisfies condition $1$ because for $i = 4$, $j = 2$: $a_i = a_j$, $b_i = 1$, and $b_j = 2$. It also satisfies condition $2$ because for $i = 6$, $j = 3$: $a_i = a_j$, $b_i = 1$, and $b_j = 3$. However, it does not satisfy condition $3$. In total, exactly two out of three conditions are satisfied.



#### Tags 

#1000 #OK #constructive_algorithms 

## Blogs
- [All Contest Problems](../Codeforces_Round_908_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
