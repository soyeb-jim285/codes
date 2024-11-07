<h1 style='text-align: center;'> B. Jumps</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are standing on the $\mathit{OX}$-axis at point $0$ and you want to move to an integer point $x > 0$.

You can make several jumps. Suppose you're currently at point $y$ ($y$ may be negative) and jump for the $k$-th time. You can: 

* either jump to the point $y + k$
* or jump to the point $y - 1$.

What is the minimum number of jumps you need to reach the point $x$?

### Input

The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases.

The first and only line of each test case contains the single integer $x$ ($1 \le x \le 10^6$) — the destination point.

### Output

For each test case, print the single integer — the minimum number of jumps to reach $x$. It can be proved that we can reach any integer point $x$.

## Example

### Input


```text
5
1
2
3
4
5
```
### Output


```text
1
3
2
3
4
```
## Note

In the first test case $x = 1$, so you need only one jump: the $1$-st jump from $0$ to $0 + 1 = 1$.

In the second test case $x = 2$. You need at least three jumps: 

* the $1$-st jump from $0$ to $0 + 1 = 1$;
* the $2$-nd jump from $1$ to $1 + 2 = 3$;
* the $3$-rd jump from $3$ to $3 - 1 = 2$;

Two jumps are not enough because these are the only possible variants: 

* the $1$-st jump as $-1$ and the $2$-nd one as $-1$ — you'll reach $0 -1 -1 =-2$;
* the $1$-st jump as $-1$ and the $2$-nd one as $+2$ — you'll reach $0 -1 +2 = 1$;
* the $1$-st jump as $+1$ and the $2$-nd one as $-1$ — you'll reach $0 +1 -1 = 0$;
* the $1$-st jump as $+1$ and the $2$-nd one as $+2$ — you'll reach $0 +1 +2 = 3$;

In the third test case, you need two jumps: the $1$-st one as $+1$ and the $2$-nd one as $+2$, so $0 + 1 + 2 = 3$.

In the fourth test case, you need three jumps: the $1$-st one as $-1$, the $2$-nd one as $+2$ and the $3$-rd one as $+3$, so $0 - 1 + 2 + 3 = 4$.



#### Tags 

#1200 #NOT OK #constructive_algorithms #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_99_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
