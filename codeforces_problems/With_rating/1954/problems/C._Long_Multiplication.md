<h1 style='text-align: center;'> C. Long Multiplication</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two integers $x$ and $y$ of the same length, consisting of digits from $1$ to $9$.

You can perform the following operation any number of times (possibly zero): swap the $i$-th digit in $x$ and the $i$-th digit in $y$.

For example, if $x=73$ and $y=31$, you can swap the $2$-nd digits and get $x=71$ and $y=33$.

Your task is to maximize the product of $x$ and $y$ using the aforementioned operation any number of times. If there are multiple answers, print any of them.

### Input

The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases.

The first line of each test case contains a single integer $x$ ($1 \le x < 10^{100}$).

The second line of each test case contains a single integer $y$ ($1 \le y < 10^{100}$).

Additional constraint on input: the integers $x$ and $y$ consist only of digits from $1$ to $9$.

### Output

For each test case, print two lines — the first line should contain the number $x$ after performing the operations; similarly, the second line should contain the number $y$ after performing the operations. If there are multiple answers, print any of them.

## Example

### Input


```text
373312535163982
```
### Output

```text

71
33
5
2
3912
3586

```


#### Tags 

#1200 #NOT OK #greedy #math #number_theory 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_164_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
