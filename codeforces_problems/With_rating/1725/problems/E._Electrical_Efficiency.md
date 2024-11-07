<h1 style='text-align: center;'> E. Electrical Efficiency</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

In the country of Dengkleknesia, there are $N$ factories numbered from $1$ to $N$. Factory $i$ has an electrical coefficient of $A_i$. There are also $N-1$ power lines with the $j$-th power line connecting factory $U_j$ and factory $V_j$. It can be guaranteed that each factory in Dengkleknesia is connected to all other factories in Dengkleknesia through one or more power lines. In other words, the collection of factories forms a tree. Each pair of different factories in Dengkleknesia can use one or more existing power lines to transfer electricity to each other. However, each power line needs to be turned on first so that electricity can pass through it.

Define $f(x, y, z)$ as the minimum number of power lines that need to be turned on so that factory $x$ can make electrical transfers to factory $y$ and factory $z$. Also define $g(x, y, z)$ as the number of distinct prime factors of $\text{GCD}(A_x, A_y, A_z)$.

To measure the electrical efficiency, you must find the sum of $f(x, y, z) \times g(x, y, z)$ for all combinations of $(x, y, z)$ such that $1 \leq x < y < z \leq N$. Because the answer can be very large, you just need to output the answer modulo $998\,244\,353$.

## Note

: $\text{GCD}(k_1, k_2, k_3)$ is the greatest common divisor of $k_1$, $k_2$, and $k_3$, which is the biggest integer that simultaneously divides $k_1$, $k_2$, and $k_3$.

#### Input

The first line contains a single integer $N$ ($1 \le N \le 2 \cdot 10^5$) — the number of factories in Dengkleknesia.

The second line contains $N$ integers $A_1, A_2, \dots, A_N$ ($1 \leq A_i \leq 2 \cdot 10^5$) — the electrical coefficients of the factories.

The $j$-th of the next $N-1$ lines contains two integers $U_j$ and $V_j$ ($1 \le U_j, V_j \le N$) — a power line that connects cities $U_j$ and $V_j$. The collection of factories forms a tree.

#### Output

An integer representing the sum of $f(x, y, z) \times g(x, y, z)$ for all combinations of $(x, y, z)$ such that $1 \leq x < y < z \leq N$, modulo $998\,244\,353$

## Examples

#### Input


```text
3
1 2 3
1 2
2 3
```
#### Output


```text
0
```
#### Input


```text
4
6 14 6 6
1 2
2 3
2 4
```
#### Output


```text
12
```
## Note

In the first example, the only $(x, y, z)$ possible is $(1, 2, 3)$. Because $\text{GCD}(A_1, A_2, A_3) = \text{GCD}(1, 2, 3) = 1$ has $0$ distinct prime factors, therefore $f(x, y, z) \times g(x, y, z) = 2 \times 0 = 0$.

In the second example, all triples $(x, y, z)$ that satisfy the condition are as follows: 

* $(1, 2, 3) \rightarrow f(1, 2, 3) \times g(1, 2, 3) = 2 \times 1 = 2$
* $(1, 2, 4) \rightarrow f(1, 2, 4) \times g(1, 2, 4) = 2 \times 1 = 2$
* $(1, 3, 4) \rightarrow f(1, 3, 4) \times g(1, 3, 4) = 3 \times 2 = 6$
* $(2, 3, 4) \rightarrow f(2, 3, 4) \times g(2, 3, 4) = 2 \times 1 = 2$

So the electrical efficiency is $2 + 2 + 6 + 2 = 12$.



#### Tags 

#2500 #NOT OK #combinatorics #data_structures #dp #math #number_theory #trees 

## Blogs
- [All Contest Problems](../COMPFEST_14_-_Preliminary_Online_Mirror_(Unrated,_ICPC_Rules,_Teams_Preferred).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
