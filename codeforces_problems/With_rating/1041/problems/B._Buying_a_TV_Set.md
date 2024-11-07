<h1 style='text-align: center;'> B. Buying a TV Set</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp has decided to buy a new TV set and hang it on the wall in his flat. The wall has enough free space so Monocarp can buy a TV set with screen width not greater than $a$ and screen height not greater than $b$. Monocarp is also used to TV sets with a certain aspect ratio: formally, if the width of the screen is $w$, and the height of the screen is $h$, then the following condition should be met: $\frac{w}{h} = \frac{x}{y}$.

There are many different TV sets in the shop. Monocarp is sure that for any pair of positive integers $w$ and $h$ there is a TV set with screen width $w$ and height $h$ in the shop.

Monocarp isn't ready to choose the exact TV set he is going to buy. Firstly he wants to determine the optimal screen resolution. He has decided to try all possible variants of screen size. But he must count the number of pairs of positive integers $w$ and $h$, beforehand, such that $(w \le a)$, $(h \le b)$ and $(\frac{w}{h} = \frac{x}{y})$.

In other words, Monocarp wants to determine the number of TV sets having aspect ratio $\frac{x}{y}$, screen width not exceeding $a$, and screen height not exceeding $b$. Two TV sets are considered different if they have different screen width or different screen height.

###### Input

The first line contains four integers $a$, $b$, $x$, $y$ ($1 \le a, b, x, y \le 10^{18}$) — the constraints on the screen width and height, and on the aspect ratio.

###### Output

Print one integer — the number of different variants to choose TV screen width and screen height so that they meet the aforementioned constraints.

## Examples

###### Input


```text
17 15 5 3  

```
###### Output


```text
3  

```
###### Input


```text
14 16 7 22  

```
###### Output


```text
0  

```
###### Input


```text
4 2 6 4  

```
###### Output


```text
1  

```
###### Input


```text
1000000000000000000 1000000000000000000 999999866000004473 999999822000007597  

```
###### Output


```text
1000000063  

```
## Note

In the first example, there are $3$ possible variants: $(5, 3)$, $(10, 6)$, $(15, 9)$.

In the second example, there is no TV set meeting the constraints.

In the third example, there is only one variant: $(3, 2)$.



#### Tags 

#1000 #NOT OK #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_509_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial #1 (en)](../blogs/Tutorial_1_(en).md)
- [Tutorial #2 (ru)](../blogs/Tutorial_2_(ru).md)
- [Tutorial #3 (en)](../blogs/Tutorial_3_(en).md)
- [Tutorial #4 (ru)](../blogs/Tutorial_4_(ru).md)
