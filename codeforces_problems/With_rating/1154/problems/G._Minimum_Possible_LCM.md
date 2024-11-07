<h1 style='text-align: center;'> G. Minimum Possible LCM</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

You are given an array $a$ consisting of $n$ integers $a_1, a_2, \dots, a_n$.

Your problem is to find such pair of indices $i, j$ ($1 \le i < j \le n$) that $lcm(a_i, a_j)$ is minimum possible.

$lcm(x, y)$ is the least common multiple of $x$ and $y$ (minimum positive number such that both $x$ and $y$ are divisors of this number).

##### Input

The first line of the input contains one integer $n$ ($2 \le n \le 10^6$) — the number of elements in $a$.

The second line of the input contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^7$), where $a_i$ is the $i$-th element of $a$.

##### Output

Print two integers $i$ and $j$ ($1 \le i < j \le n$) such that the value of $lcm(a_i, a_j)$ is minimum among all valid pairs $i, j$. If there are multiple answers, you can print any.

## Examples

##### Input


```text
5
2 4 8 3 6
```
##### Output


```text
1 2
```
##### Input


```text
5
5 2 11 3 7
```
##### Output


```text
2 4
```
##### Input


```text
6
2 5 10 1 10 2
```
##### Output


```text
1 4
```


#### Tags 

#2200 #NOT OK #brute_force #greedy #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_552_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
