<h1 style='text-align: center;'> E. Product Oriented Recurrence</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let $f_{x} = c^{2x-6} \cdot f_{x-1} \cdot f_{x-2} \cdot f_{x-3}$ for $x \ge 4$.

You have given integers $n$, $f_{1}$, $f_{2}$, $f_{3}$, and $c$. Find $f_{n} \bmod (10^{9}+7)$.

#### Input

The only line contains five integers $n$, $f_{1}$, $f_{2}$, $f_{3}$, and $c$ ($4 \le n \le 10^{18}$, $1 \le f_{1}$, $f_{2}$, $f_{3}$, $c \le 10^{9}$).

#### Output

Print $f_{n} \bmod (10^{9} + 7)$.

## Examples

#### Input


```text
5 1 2 5 3
```
#### Output


```text
72900
```
#### Input


```text
17 97 41 37 11
```
#### Output


```text
317451037
```
## Note

In the first example, $f_{4} = 90$, $f_{5} = 72900$.

In the second example, $f_{17} \approx 2.28 \times 10^{29587}$.



#### Tags 

#2300 #NOT OK #dp #math #matrices #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_566_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
