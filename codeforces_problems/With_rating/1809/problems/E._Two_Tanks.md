<h1 style='text-align: center;'> E. Two Tanks</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are two water tanks, the first one fits $a$ liters of water, the second one fits $b$ liters of water. The first tank has $c$ ($0 \le c \le a$) liters of water initially, the second tank has $d$ ($0 \le d \le b$) liters of water initially.

You want to perform $n$ operations on them. The $i$-th operation is specified by a single non-zero integer $v_i$. If $v_i > 0$, then you try to pour $v_i$ liters of water from the first tank into the second one. If $v_i < 0$, you try to pour $-v_i$ liters of water from the second tank to the first one.

When you try to pour $x$ liters of water from the tank that has $y$ liters currently available to the tank that can fit $z$ more liters of water, the operation only moves $\min(x, y, z)$ liters of water.

For all pairs of the initial volumes of water $(c, d)$ such that $0 \le c \le a$ and $0 \le d \le b$, calculate the volume of water in the first tank after all operations are performed.

#### Input

The first line contains three integers $n, a$ and $b$ ($1 \le n \le 10^4$; $1 \le a, b \le 1000$) — the number of operations and the capacities of the tanks, respectively.

The second line contains $n$ integers $v_1, v_2, \dots, v_n$ ($-1000 \le v_i \le 1000$; $v_i \neq 0$) — the volume of water you try to pour in each operation.

#### Output

For all pairs of the initial volumes of water $(c, d)$ such that $0 \le c \le a$ and $0 \le d \le b$, calculate the volume of water in the first tank after all operations are performed.

Print $a + 1$ lines, each line should contain $b + 1$ integers. The $j$-th value in the $i$-th line should be equal to the answer for $c = i - 1$ and $d = j - 1$.

## Examples

#### Input


```text
3 4 4
-2 1 2
```
#### Output


```text
0 0 0 0 0 
0 0 0 0 1 
0 0 1 1 2 
0 1 1 2 3 
1 1 2 3 4 
```
#### Input


```text
3 9 5
1 -2 2
```
#### Output


```text
0 0 0 0 0 0 
0 0 0 0 0 1 
0 1 1 1 1 2 
1 2 2 2 2 3 
2 3 3 3 3 4 
3 4 4 4 4 5 
4 5 5 5 5 6 
5 6 6 6 6 7 
6 7 7 7 7 8 
7 7 7 7 8 9 
```
## Note

Consider $c = 3$ and $d = 2$ from the first example: 

* The first operation tries to move $2$ liters of water from the second tank to the first one, the second tank has $2$ liters available, the first tank can fit $1$ more liter. Thus, $\min(2, 2, 1) = 1$ liter is moved, the first tank now contains $4$ liters, the second tank now contains $1$ liter.
* The second operation tries to move $1$ liter of water from the first tank to the second one. $\min(1, 4, 3) = 1$ liter is moved, the first tank now contains $3$ liters, the second tank now contains $2$ liter.
* The third operation tries to move $2$ liter of water from the first tank to the second one. $\min(2, 3, 2) = 2$ liters are moved, the first tank now contains $1$ liter, the second tank now contains $4$ liters.

There's $1$ liter of water in the first tank at the end. Thus, the third value in the fourth row is $1$.



#### Tags 

#2400 #NOT OK #binary_search #dp #implementation #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_145_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
