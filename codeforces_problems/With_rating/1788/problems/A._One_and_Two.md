<h1 style='text-align: center;'> A. One and Two</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a sequence $a_1, a_2, \ldots, a_n$. Each element of $a$ is $1$ or $2$.

Find out if an integer $k$ exists so that the following conditions are met. 

* $1 \leq k \leq n-1$, and
* $a_1 \cdot a_2 \cdot \ldots \cdot a_k = a_{k+1} \cdot a_{k+2} \cdot \ldots \cdot a_n$.

If there exist multiple $k$ that satisfy the given condition, print the smallest.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 100$). Description of the test cases follows.

The first line of each test case contains one integer $n$ ($2 \leq n \leq 1000$).

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq 2$).

### Output

For each test case, if there is no such $k$, print $-1$.

Otherwise, print the smallest possible $k$.

## Example

### Input


```text
362 2 1 2 1 231 2 141 1 1 1
```
### Output

```text

2
-1
1

```
## Note

For the first test case, $k=2$ satisfies the condition since $a_1 \cdot a_2 = a_3 \cdot a_4 \cdot a_5 \cdot a_6 = 4$. $k=3$ also satisfies the given condition, but the smallest should be printed.

For the second test case, there is no $k$ that satisfies $a_1 \cdot a_2 \cdot \ldots \cdot a_k = a_{k+1} \cdot a_{k+2} \cdot \ldots \cdot a_n$

For the third test case, $k=1$, $2$, and $3$ satisfy the given condition, so the answer is $1$.



#### Tags 

#800 #OK #brute_force #implementation #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_851_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
