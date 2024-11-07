<h1 style='text-align: center;'> D. Three Integers</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given three integers $a \le b \le c$.

In one move, you can add $+1$ or $-1$ to any of these integers (i.e. increase or decrease any number by one). You can perform such operation any (possibly, zero) number of times, you can even perform this operation several times with one number. Note that you cannot make non-positive numbers using such operations.

You have to perform the minimum number of such operations in order to obtain three integers $A \le B \le C$ such that $B$ is divisible by $A$ and $C$ is divisible by $B$.

You have to answer $t$ independent test cases. 

### Input

The first line of the input contains one integer $t$ ($1 \le t \le 100$) — the number of test cases.

The next $t$ lines describe test cases. Each test case is given on a separate line as three space-separated integers $a, b$ and $c$ ($1 \le a \le b \le c \le 10^4$).

### Output

For each test case, print the answer. In the first line print $res$ — the minimum number of operations you have to perform to obtain three integers $A \le B \le C$ such that $B$ is divisible by $A$ and $C$ is divisible by $B$. On the second line print any suitable triple $A, B$ and $C$.

## Example

### Input


```text
8
1 2 3
123 321 456
5 10 15
15 18 21
100 100 101
1 22 29
3 19 38
6 30 46
```
### Output


```text
1
1 1 3
102
114 228 456
4
4 8 16
6
18 18 18
1
100 100 100
7
1 22 22
2
1 19 38
8
6 24 48
```


#### Tags 

#2000 #NOT OK #brute_force #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_624_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
