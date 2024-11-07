<h1 style='text-align: center;'> A. Problem Generator</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vlad is planning to hold $m$ rounds next month. Each round should contain one problem of difficulty levels 'A', 'B', 'C', 'D', 'E', 'F', and 'G'.

Vlad already has a bank of $n$ problems, where the $i$-th problem has a difficulty level of $a_i$. There may not be enough of these problems, so he may have to come up with a few more problems.

Vlad wants to come up with as few problems as possible, so he asks you to find the minimum number of problems he needs to come up with in order to hold $m$ rounds.

For example, if $m=1$, $n = 10$, $a=$ 'BGECDCBDED', then he needs to come up with two problems: one of difficulty level 'A' and one of difficulty level 'F'.

### Input

The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases.

The first line of each test case contains two integers $n$ and $m$ ($1 \le n \le 50$, $1 \le m \le 5$) — the number of problems in the bank and the number of upcoming rounds, respectively.

The second line of each test case contains a string $a$ of $n$ characters from 'A' to 'G' — the difficulties of the problems in the bank.

### Output

For each test case, output a single integer — the minimum number of problems that need to come up with to hold $m$ rounds.

## Example

### Input


```text
310 1BGECDCBDED10 2BGECDCBDED9 1BBCDEFFGG
```
### Output

```text

2
5
1

```


#### Tags 

#800 #NOT OK #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_950_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
