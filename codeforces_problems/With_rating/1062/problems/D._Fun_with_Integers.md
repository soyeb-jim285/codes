<h1 style='text-align: center;'> D. Fun with Integers</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a positive integer $n$ greater or equal to $2$. For every pair of integers $a$ and $b$ ($2 \le |a|, |b| \le n$), you can transform $a$ into $b$ if and only if there exists an integer $x$ such that $1 < |x|$ and ($a \cdot x = b$ or $b \cdot x = a$), where $|x|$ denotes the absolute value of $x$.

After such a transformation, your score increases by $|x|$ points and you are not allowed to transform $a$ into $b$ nor $b$ into $a$ anymore.

Initially, you have a score of $0$. You can start at any integer and transform it as many times as you like. What is the maximum score you can achieve?

##### Input

A single line contains a single integer $n$ ($2 \le n \le 100\,000$) — the given integer described above.

##### Output

Print an only integer — the maximum score that can be achieved with the transformations. If it is not possible to perform even a single transformation for all possible starting integers, print $0$.

## Examples

##### Input


```text
4  

```
##### Output


```text
8
```
##### Input


```text
6  

```
##### Output


```text
28
```
##### Input


```text
2  

```
##### Output


```text
0
```
## Note

In the first example, the transformations are $2 \rightarrow 4 \rightarrow (-2) \rightarrow (-4) \rightarrow 2$.

In the third example, it is impossible to perform even a single transformation.



#### Tags 

#1800 #NOT OK #dfs_and_similar #graphs #implementation #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_520_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
