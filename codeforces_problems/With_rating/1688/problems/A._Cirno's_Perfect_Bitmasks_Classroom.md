<h1 style='text-align: center;'> A. Cirno's Perfect Bitmasks Classroom</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Even if it's a really easy question, she won't be able to answer it— Perfect Memento in Strict SenseCirno's perfect bitmasks classroom has just started!

Cirno gave her students a positive integer $x$. As an assignment, her students need to find the minimum positive integer $y$, which satisfies the following two conditions:

$$x\ \texttt{and}\ y > 0$$ $$x\ \texttt{xor}\ y > 0$$

Where $\texttt{and}$ is the [bitwise AND operation](https://en.wikipedia.org/wiki/Bitwise_operation#AND), and $\texttt{xor}$ is the [bitwise XOR operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR).

Among the students was Mystia, who was truly baffled by all these new operators. Please help her!

### Input

The first line of input contains a single integer $t$ ($1 \leq t \leq 10^3$) — the number of input test cases.

For each test case, the only line of input contains one integer $x$ ($1 \leq x \leq 2^{30}$).

### Output

For each test case, print a single integer — the minimum number of $y$.

## Example

### Input


```text
71259161145141000000
```
### Output

```text

3
3
1
1
17
2
64

```
## Note

Test case 1: 

$1\; \texttt{and}\; 3=1>0$, $1\; \texttt{xor}\; 3=2>0$.

Test case 2: 

$2\; \texttt{and}\; 3=2>0$, $2\; \texttt{xor}\; 3=1>0$.



#### Tags 

#800 #OK #bitmasks #brute_force 

## Blogs
- [All Contest Problems](../Codeforces_Round_796_(Div._2).md)
- [Codeforces Round #796 (en)](../blogs/Codeforces_Round_796_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
