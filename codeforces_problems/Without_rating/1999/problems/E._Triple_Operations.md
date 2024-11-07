<h1 style='text-align: center;'> E. Triple Operations</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

On the board Ivy wrote down all integers from $l$ to $r$, inclusive.

In an operation, she does the following: 

* pick two numbers $x$ and $y$ on the board, erase them, and in their place write the numbers $3x$ and $\lfloor \frac{y}{3} \rfloor$. (Here $\lfloor \bullet \rfloor$ denotes rounding down to the nearest integer).

 What is the minimum number of operations Ivy needs to make all numbers on the board equal $0$? We have a proof that this is always possible.

### Input

The first line contains an integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases.

The only line of each test case contains two integers $l$ and $r$ ($1 \leq l < r \leq 2 \cdot 10^5$).

### Output

For each test case, output a single integer — the minimum number of operations needed to make all numbers on the board equal $0$.

## Example

### Input


```text
41 32 4199999 20000019 84
```
### Output

```text

5
6
36
263

```
## Note

In the first test case, we can perform $5$ operations as follows: $$ 1,2,3 \xrightarrow[x=1,\,y=2]{} 3,0,3 \xrightarrow[x=0,\,y=3]{} 1,0,3 \xrightarrow[x=0,\,y=3]{} 1,0,1 \xrightarrow[x=0,\,y=1]{} 0,0,1 \xrightarrow[x=0,\,y=1]{} 0,0,0 .$$



#### Tags 

#NOT OK #dp #implementation #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_964_(Div._4).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
- [Tutorial #2 (en)](../blogs/Tutorial_2_(en).md)
