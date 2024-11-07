<h1 style='text-align: center;'> E. Common Number</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

At first, let's define function $f(x)$ as follows: $$ \begin{matrix} f(x) & = & \left\{ \begin{matrix} \frac{x}{2} & \mbox{if } x \text{ is even} \\\ x - 1 & \mbox{otherwise } \end{matrix} \right. \end{matrix} $$

We can see that if we choose some value $v$ and will apply function $f$ to it, then apply $f$ to $f(v)$, and so on, we'll eventually get $1$. Let's write down all values we get in this process in a list and denote this list as $path(v)$. For example, $path(1) = [1]$, $path(15) = [15, 14, 7, 6, 3, 2, 1]$, $path(32) = [32, 16, 8, 4, 2, 1]$.

Let's write all lists $path(x)$ for every $x$ from $1$ to $n$. The question is next: what is the maximum value $y$ such that $y$ is contained in at least $k$ different lists $path(x)$?

Formally speaking, you need to find maximum $y$ such that $\left| \{ x ~|~ 1 \le x \le n, y \in path(x) \} \right| \ge k$.

####### Input

The first line contains two integers $n$ and $k$ ($1 \le k \le n \le 10^{18}$).

####### Output

Print the only integer — the maximum value that is contained in at least $k$ paths.

## Examples

####### Input


```text
11 3
```
####### Output


```text
5
```
####### Input


```text
11 6
```
####### Output


```text
4
```
####### Input


```text
20 20
```
####### Output


```text
1
```
####### Input


```text
14 5
```
####### Output


```text
6
```
####### Input


```text
1000000 100
```
####### Output


```text
31248
```
## Note

In the first example, the answer is $5$, since $5$ occurs in $path(5)$, $path(10)$ and $path(11)$.

In the second example, the answer is $4$, since $4$ occurs in $path(4)$, $path(5)$, $path(8)$, $path(9)$, $path(10)$ and $path(11)$.

In the third example $n = k$, so the answer is $1$, since $1$ is the only number occuring in all paths for integers from $1$ to $20$.



#### Tags 

#2100 #NOT OK #binary_search #combinatorics #dp #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_608_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
