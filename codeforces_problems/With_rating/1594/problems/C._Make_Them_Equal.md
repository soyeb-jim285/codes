<h1 style='text-align: center;'> C. Make Them Equal</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Theofanis has a string $s_1 s_2 \dots s_n$ and a character $c$. He wants to make all characters of the string equal to $c$ using the minimum number of operations.

In one operation he can choose a number $x$ ($1 \le x \le n$) and for every position $i$, where $i$ is not divisible by $x$, replace $s_i$ with $c$. 

Find the minimum number of operations required to make all the characters equal to $c$ and the $x$-s that he should use in his operations.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains the integer $n$ ($3 \le n \le 3 \cdot 10^5$) and a lowercase Latin letter $c$ — the length of the string $s$ and the character the resulting string should consist of.

The second line of each test case contains a string $s$ of lowercase Latin letters — the initial string.

It is guaranteed that the sum of $n$ over all test cases does not exceed $3 \cdot 10^5$.

### Output

For each test case, firstly print one integer $m$ — the minimum number of operations required to make all the characters equal to $c$.

Next, print $m$ integers $x_1, x_2, \dots, x_m$ ($1 \le x_j \le n$) — the $x$-s that should be used in the order they are given.

It can be proved that under given constraints, an answer always exists. If there are multiple answers, print any.

## Example

### Input


```text
3
4 a
aaaa
4 a
baaa
4 b
bzyx
```
### Output


```text
0
1
2
2 
2 3
```
## Note

Let's describe what happens in the third test case: 

1. $x_1 = 2$: we choose all positions that are not divisible by $2$ and replace them, i. e. bzyx $\rightarrow$ bzbx;
2. $x_2 = 3$: we choose all positions that are not divisible by $3$ and replace them, i. e. bzbx $\rightarrow$ bbbb.


#### Tags 

#1200 #NOT OK #brute_force #greedy #math #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_747_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
