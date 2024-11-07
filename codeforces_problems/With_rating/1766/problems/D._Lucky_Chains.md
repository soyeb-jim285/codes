<h1 style='text-align: center;'> D. Lucky Chains</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Let's name a pair of positive integers $(x, y)$ lucky if the greatest common divisor of them is equal to $1$ ($\gcd(x, y) = 1$).

Let's define a chain induced by $(x, y)$ as a sequence of pairs $(x, y)$, $(x + 1, y + 1)$, $(x + 2, y + 2)$, $\dots$, $(x + k, y + k)$ for some integer $k \ge 0$. The length of the chain is the number of pairs it consists of, or $(k + 1)$.

Let's name such chain lucky if all pairs in the chain are lucky.

You are given $n$ pairs $(x_i, y_i)$. Calculate for each pair the length of the longest lucky chain induced by this pair. 
## Note

 that if $(x_i, y_i)$ is not lucky itself, the chain will have the length $0$. 

### Input

The first line contains a single integer $n$ ($1 \le n \le 10^6$) — the number of pairs.

Next $n$ lines contains $n$ pairs — one per line. The $i$-th line contains two integers $x_i$ and $y_i$ ($1 \le x_i < y_i \le 10^7$) — the corresponding pair.

### Output

Print $n$ integers, where the $i$-th integer is the length of the longest lucky chain induced by $(x_i, y_i)$ or $-1$ if the chain can be infinitely long.

## Example

### Input


```text
4
5 15
13 37
8 9
10009 20000
```
### Output


```text
0
1
-1
79
```
## Note

In the first test case, $\gcd(5, 15) = 5 > 1$, so it's already not lucky, so the length of the lucky chain is $0$.

In the second test case, $\gcd(13 + 1, 37 + 1) = \gcd(14, 38) = 2$. So, the lucky chain consists of the single pair $(13, 37)$. 



#### Tags 

#1600 #NOT OK #math #number_theory 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_139_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
