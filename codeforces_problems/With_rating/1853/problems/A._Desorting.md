<h1 style='text-align: center;'> A. Desorting</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Call an array $a$ of length $n$ sorted if $a_1 \leq a_2 \leq \ldots \leq a_{n-1} \leq a_n$.

Ntarsis has an array $a$ of length $n$. 

He is allowed to perform one type of operation on it (zero or more times): 

* Choose an index $i$ ($1 \leq i \leq n-1$).
* Add $1$ to $a_1, a_2, \ldots, a_i$.
* Subtract $1$ from $a_{i+1}, a_{i+2}, \ldots, a_n$.

The values of $a$ can be negative after an operation.

Determine the minimum operations needed to make $a$ not sorted.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 100$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($2 \leq n \leq 500$) — the length of the array $a$.

The next line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq 10^9$) — the values of array $a$.

It is guaranteed that the sum of $n$ across all test cases does not exceed $500$.

### Output

### Output

 the minimum number of operations needed to make the array not sorted.

## Example

### Input


```text
421 141 8 10 1331 3 231 9 14
```
### Output

```text

1
2
0
3

```
## Note

In the first case, we can perform $1$ operation to make the array not sorted: 

* Pick $i = 1$. The array $a$ then becomes $[2, 0]$, which is not sorted.

In the second case, we can perform $2$ operations to make the array not sorted: 

* Pick $i = 3$. The array $a$ then becomes $[2, 9, 11, 12]$.
* Pick $i = 3$. The array $a$ then becomes $[3, 10, 12, 11]$, which is not sorted.

It can be proven that $1$ and $2$ operations are the minimal numbers of operations in the first and second test cases, respectively.

In the third case, the array is already not sorted, so we perform $0$ operations.



#### Tags 

#800 #OK #brute_force #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_887_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
