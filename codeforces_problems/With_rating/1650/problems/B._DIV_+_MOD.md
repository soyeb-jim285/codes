<h1 style='text-align: center;'> B. DIV + MOD</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Not so long ago, Vlad came up with an interesting function:

* $f_a(x)=\left\lfloor\frac{x}{a}\right\rfloor + x \bmod a$, where $\left\lfloor\frac{x}{a}\right\rfloor$ is $\frac{x}{a}$, rounded down, $x \bmod a$ — the remainder of the integer division of $x$ by $a$.

For example, with $a=3$ and $x=11$, the value $f_3(11) = \left\lfloor\frac{11}{3}\right\rfloor + 11 \bmod 3 = 3 + 2 = 5$.

The number $a$ is fixed and known to Vlad. Help Vlad find the maximum value of $f_a(x)$ if $x$ can take any integer value from $l$ to $r$ inclusive ($l \le x \le r$).

### Input

The first line of input data contains an integer $t$ ($1 \le t \le 10^4$) — the number of input test cases.

This is followed by $t$ lines, each of which contains three integers $l_i$, $r_i$ and $a_i$ ($1 \le l_i \le r_i \le 10^9, 1 \le a_i \le 10^9$) — the left and right boundaries of the segment and the fixed value of $a$.

### Output

For each test case, output one number on a separate line — the maximum value of the function on a given segment for a given $a$.

## Example

### Input


```text
51 4 35 8 46 10 61 1000000000 100000000010 12 8
```
### Output

```text

2
4
5
999999999
5

```
## Note

In the first sample:

* $f_3(1) = \left\lfloor\frac{1}{3}\right\rfloor + 1 \bmod 3 = 0 + 1 = 1$,
* $f_3(2) = \left\lfloor\frac{2}{3}\right\rfloor + 2 \bmod 3 = 0 + 2 = 2$,
* $f_3(3) = \left\lfloor\frac{3}{3}\right\rfloor + 3 \bmod 3 = 1 + 0 = 1$,
* $f_3(4) = \left\lfloor\frac{4}{3}\right\rfloor + 4 \bmod 3 = 1 + 1 = 2$

As an answer, obviously, $f_3(2)$ and $f_3(4)$ are suitable.



#### Tags 

#900 #OK #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_776_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
