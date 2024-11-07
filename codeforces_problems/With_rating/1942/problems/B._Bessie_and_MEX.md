<h1 style='text-align: center;'> B. Bessie and MEX</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

[MOOO! - Doja Cat](https://soundcloud.com/amalaofficial/mooo)⠀Farmer John has a permutation $p_1, p_2, \ldots, p_n$, where every integer from $0$ to $n-1$ occurs exactly once. He gives Bessie an array $a$ of length $n$ and challenges her to construct $p$ based on $a$. 

The array $a$ is constructed so that $a_i$ = $\texttt{MEX}(p_1, p_2, \ldots, p_i) - p_i$, where the $\texttt{MEX}$ of an array is the minimum non-negative integer that does not appear in that array. For example, $\texttt{MEX}(1, 2, 3) = 0$ and $\texttt{MEX}(3, 1, 0) = 2$.

Help Bessie construct any valid permutation $p$ that satisfies $a$. The input is given in such a way that at least one valid $p$ exists. If there are multiple possible $p$, it is enough to print one of them.

### Input

The first line contains $t$ ($1 \leq t \leq 10^4$) — the number of test cases.

The first line of each test case contains an integer $n$ ($1 \leq n \leq 2 \cdot 10^5$) — the lengths of $p$ and $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($-n \leq a_i \leq n$) — the elements of array $a$.

It is guaranteed that there is at least one valid $p$ for the given data.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output $n$ integers on a new line, the elements of $p$.

If there are multiple solutions, print any of them.

## Example

### Input


```text
351 1 -2 1 251 1 1 1 13-2 1 2
```
### Output

```text

0 1 4 2 3 
0 1 2 3 4 
2 0 1 

```
## Note

In the first case, $p = [0, 1, 4, 2, 3]$ is one possible output.

$a$ will then be calculated as $a_1 = \texttt{MEX}(0) - 0 = 1$, $a_2 = \texttt{MEX}(0, 1) - 1 = 1$, $a_3 = \texttt{MEX}(0, 1, 4) - 4 = -2$, $a_4 = \texttt{MEX}(0, 1, 4, 2) - 2 = 1$, $a_5 = \texttt{MEX}(0, 1, 4, 2, 3) - 3 = 2$.

So, as required, $a$ will be $[1, 1, -2, 1, 2]$.



#### Tags 

#1100 #OK #constructive_algorithms #math 

## Blogs
- [All Contest Problems](../CodeTON_Round_8_(Div._1_+_Div._2,_Rated,_Prizes!).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
