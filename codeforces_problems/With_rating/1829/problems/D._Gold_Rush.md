<h1 style='text-align: center;'> D. Gold Rush</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Initially you have a single pile with $n$ gold nuggets. In an operation you can do the following: 

* Take any pile and split it into two piles, so that one of the resulting piles has exactly twice as many gold nuggets as the other. (All piles should have an integer number of nuggets.)

  ![](images/723dd5ce328f1a04932ecf7a71a71f198294eaa3.png)One possible move is to take a pile of size $6$ and split it into piles of sizes $2$ and $4$, which is valid since $4$ is twice as large as $2$. 

 Can you make a pile with exactly $m$ gold nuggets using zero or more operations?
### Input

The first line contains an integer $t$ ($1 \leq t \leq 1000$) — the number of test cases.

The only line of each test case contains two integers $n$ and $m$ ($1 \leq n, m \leq 10^7$) — the starting and target pile sizes, respectively.

### Output

For each test case, output "YES" if you can make a pile of size exactly $m$, and "NO" otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).

## Example

### Input


```text
116 49 44 218 2727 427 227 101 13 15 1746001 2984004
```
### Output

```text

YES
YES
NO
NO
YES
YES
NO
YES
YES
NO
NO

```
## Note

The first test case is pictured in the statement. We can make a pile of size $4$.

In the second test case, we can perform the following operations: $\{\color{red}{9}\} \to \{\color{red}{6},3\} \to \{4,2,3\}$. The pile that is split apart is colored red before each operation.

In the third test case, we can't perform a single operation.

In the fourth test case, we can't end up with a larger pile than we started with.



#### Tags 

#1000 #NOT OK #brute_force #dfs_and_similar #dp #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_871_(Div._4).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
