<h1 style='text-align: center;'> B. Mathematical Circus</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A new entertainment has appeared in Buryatia — a mathematical circus! The magician shows two numbers to the audience — $n$ and $k$, where $n$ is even. Next, he takes all the integers from $1$ to $n$, and splits them all into pairs $(a, b)$ (each integer must be in exactly one pair) so that for each pair the integer $(a + k) \cdot b$ is divisible by $4$ (note that the order of the numbers in the pair matters), or reports that, unfortunately for viewers, such a split is impossible.

Burenka really likes such performances, so she asked her friend Tonya to be a magician, and also gave him the numbers $n$ and $k$.

Tonya is a wolf, and as you know, wolves do not perform in the circus, even in a mathematical one. Therefore, he asks you to help him. Let him know if a suitable splitting into pairs is possible, and if possible, then tell it.

### Input

The first line contains one integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. The following is a description of the input data sets.

The single line of each test case contains two integers $n$ and $k$ ($2 \leq n \leq 2 \cdot 10^5$, $0 \leq k \leq 10^9$, $n$ is even) — the number of integers and the number being added $k$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, first output the string "YES" if there is a split into pairs, and "NO" if there is none.

If there is a split, then in the following $\frac{n}{2}$ lines output pairs of the split, in each line print $2$ numbers — first the integer $a$, then the integer $b$.

## Example

### Input


```text
44 12 012 1014 11
```
### Output

```text

YES
1 2
3 4
NO
YES
3 4
7 8
11 12
2 1
6 5
10 9
YES
1 2
3 4
5 6
7 8
9 10
11 12
13 14

```
## Note

In the first test case, splitting into pairs $(1, 2)$ and $(3, 4)$ is suitable, same as splitting into $(1, 4)$ and $(3, 2)$.

In the second test case, $(1 + 0) \cdot 2 = 1 \cdot (2 + 0) = 2$ is not divisible by $4$, so there is no partition.



#### Tags 

#800 #OK #constructive_algorithms #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_814_(Div._2).md)
- [Codeforces Round #814](../blogs/Codeforces_Round_814.md)
- [Tutorial](../blogs/Tutorial.md)
