<h1 style='text-align: center;'> A. Dual Trigger</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

[Ngọt - LẦN CUỐI (đi bên em xót xa người ơi)](https://youtu.be/kSjj0LlsqnI)ඞThere are $n$ lamps numbered $1$ to $n$ lined up in a row, initially turned off. You can perform the following operation any number of times (possibly zero): 

* Choose two non-adjacent${}^\dagger$ lamps that are currently turned off, then turn them on.

Determine whether you can reach configuration $s$, where $s_i = 1$ means the $i$-th lamp is turned on, and $s_i = 0$ otherwise.

${}^\dagger$ Only lamp $i$ and $i + 1$ are adjacent for all $1 \le i < n$. 
## Note

 that lamp $n$ and $1$ are not adjacent when $n \ne 2$.

### Input

Each test contains multiple test cases. The first line contains an integer $t$ ($1 \le t \le 1000$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer $n$ ($1 \le n \le 50$) — the number of lamps.

The second line of each test case contains a binary string $s$ of size $n$ — the final desired configuration.

### Output

For each test case, print on one line "YES" if we can reach the configuration $s$ via applying the given operation any number of times. Otherwise, print "NO".

## Example

### Input


```text
510110101011010100100111060000001112111111111111
```
### Output

```text

YES
NO
YES
NO
YES

```
## Note

In the first test case, the sequence of operation could have been as follows (note that initially $s$ is all zero): $\mathtt{0000000000} \to \mathtt{\color{red}{1}0000000\color{red}{1}0} \to \mathtt{1\color{red}{1}00000\color{red}{1}10} \to \mathtt{110\color{red}{1}0\color{red}{1}0110}$.

In the third test case, we don't have to do any operation.

In the fourth test case, we cannot do any operation, but we need the first lamp to be on. Therefore, it is impossible to achieve the desired state.



#### Tags 

#900 #OK #constructive_algorithms #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_25.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
