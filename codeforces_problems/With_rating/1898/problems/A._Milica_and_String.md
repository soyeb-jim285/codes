<h1 style='text-align: center;'> A. Milica and String</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Milica has a string $s$ of length $n$, consisting only of characters A and B. She wants to modify $s$ so it contains exactly $k$ instances of B. In one operation, she can do the following:

* Select an integer $i$ ($1 \leq i \leq n$) and a character $c$ ($c$ is equal to either A or B).
* Then, replace each of the first $i$ characters of string $s$ (that is, characters $s_1, s_2, \ldots, s_i$) with $c$.

Milica does not want to perform too many operations in order not to waste too much time on them.

She asks you to find the minimum number of operations required to modify $s$ so it contains exactly $k$ instances of B. She also wants you to find these operations (that is, integer $i$ and character $c$ selected in each operation).

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \leq t \leq 500$). The description of test cases follows.

The first line of each test case contains two integers $n$ and $k$ ($3 \leq n \leq 100$, $0 \leq k \leq n$) — the length of the string $s$ and the number of characters B Milica wants to appear in $s$ in the end.

The second line of each test case contains the string $s$ of length $n$, consisting only of characters A and B.

### Output

For each test case, in the first line output a single integer $m$ — the minimum number of operations Milica should perform.

In the $j$-th of the next $m$ lines output an integer $i$ ($1 \le i \le n$) and a character $c$ ($c$ is 'A' or 'B') — the parameters of the $j$-th operation as described in the statement.

If there are multiple solutions with the minimum possible number of operations, output any of them.

## Example

### Input


```text
5
5 2
AAABB
5 3
AABAB
5 0
BBBBB
3 0
BAA
10 3
BBBABBBBAB
```
### Output


```text
0
1
1 B
1
5 A
1
2 A
1
6 A
```
## Note

In the first test case, there are already $2$ characters B in $s$, so Milica does not have to perform any operations.

In the second test case, the only way to achieve $3$ characters B in $s$ in one operation is to replace the first character of $s$ by B on the first operation: AABAB $\rightarrow$ BABAB.

In the third test case, the only way to achieve $0$ characters B in $s$ in one operation is to replace the first $5$ characters of $s$ by A on the first operation: BBBBB $\rightarrow$ AAAAA.

In the fourth test case, one of the ways to achieve $0$ characters B in $s$ in one operation is to replace the first $2$ characters of $s$ by A on the first operation: BAA $\rightarrow$ AAA. 
## Note

 that "1 A" and "3 A" are also correct one-operation solutions.



#### Tags 

#800 #NOT OK #brute_force #implementation #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_910_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
