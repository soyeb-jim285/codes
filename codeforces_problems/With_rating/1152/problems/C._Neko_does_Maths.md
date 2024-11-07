<h1 style='text-align: center;'> C. Neko does Maths</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Neko loves divisors. During the latest number theory lesson, he got an interesting exercise from his math teacher.

Neko has two integers $a$ and $b$. His goal is to find a non-negative integer $k$ such that the least common multiple of $a+k$ and $b+k$ is the smallest possible. If there are multiple optimal integers $k$, he needs to choose the smallest one.

Given his mathematical talent, Neko had no trouble getting Wrong Answer on this problem. Can you help him solve it?

##### Input

The only line contains two integers $a$ and $b$ ($1 \le a, b \le 10^9$).

##### Output

Print the smallest non-negative integer $k$ ($k \ge 0$) such that the lowest common multiple of $a+k$ and $b+k$ is the smallest possible.

If there are many possible integers $k$ giving the same value of the least common multiple, print the smallest one.

## Examples

##### Input


```text
6 10
```
##### Output


```text
2
```
##### Input

```text

21 31

```
##### Output


```text
9
```
##### Input

```text

5 10

```
##### Output


```text

0
```
## Note

In the first test, one should choose $k = 2$, as the least common multiple of $6 + 2$ and $10 + 2$ is $24$, which is the smallest least common multiple possible.



#### Tags 

#1800 #NOT OK #brute_force #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_554_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [T (en)](../blogs/T_(en).md)
