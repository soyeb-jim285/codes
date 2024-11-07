<h1 style='text-align: center;'> E. Li Hua and Array</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Li Hua wants to solve a problem about $\varphi$ — Euler's totient function. Please recall that $\varphi(x)=\sum\limits_{i=1}^x[\gcd(i,x)=1]$.$^{\dagger,\ddagger}$

He has a sequence $a_1,a_2,\cdots,a_n$ and he wants to perform $m$ operations:

* "1 $l$ $r$" ($1\le l\le r\le n$) — for each $x\in[l,r]$, change $a_x$ into $\varphi(a_x)$.
* "2 $l$ $r$" ($1\le l\le r\le n$) — find out the minimum changes needed to make sure $a_l=a_{l+1}=\cdots=a_r$. In each change, he chooses one $x\in[l,r]$, change $a_x$ into $\varphi(a_x)$. Each operation of this type is independent, which means the array doesn't actually change.

Suppose you were Li Hua, please solve this problem.

$^\dagger$ $\gcd(x,y)$ denotes the [greatest common divisor (GCD)](https://en.wikipedia.org/wiki/Greatest_common_divisor) of integers $x$ and $y$. 

$^\ddagger$ The notation $[\textrm{cond}]$ equals $1$ if the condition $\textrm{cond}$ is true, and $0$ otherwise.

### Input

The first line contains two integers $n$ and $m$ ($1\le n,m\le 10^{5}$) — the number of elements in the array and the number of operations to process, respectively.

The second line contains $n$ integers $a_{1},a_{2},\cdots ,a_{n}$ ($1\le a_{i}\le 5\cdot 10^{6}$) — the elements of the array.

Next $m$ lines, each line contains three integers $t_{i},l_{i},r_{i}$ ($t_i\in\{1,2\},1\le l_i\le r_i\le n$) — the $i$-th operation. 

### Output

For each "2 $l$ $r$", output the answer in an separate line.

## Example

### Input


```text
5 4
8 1 6 3 7
2 1 5
2 3 4
1 1 3
2 3 4
```
### Output


```text
10
2
1
```
## Note

Denote $\varphi^k(x)=\begin{cases}x,&k=0\\\\\varphi(\varphi^{k-1}(x)),&k > 0\end{cases}$.

At first, $a=[8,1,6,3,7]$.

To make sure $a_1=a_2=a_3=a_4=a_5$, we can change $a$ to $a'=[\varphi^3(8),\varphi^0(1),\varphi^2(6),\varphi^2(3),\varphi^3(7)]=[1,1,1,1,1]$, using $3+0+2+2+3=10$ changes.

To make sure $a_3=a_4$, we can change $a$ to $a'=[\varphi^0(8),\varphi^0(1),\varphi^1(6),\varphi^1(3),\varphi^0(7)]=[8,1,2,2,7]$, using $0+0+1+1+0=2$ changes.

After "1 $1$ $3$", $a$ is changed to $a=[\varphi^1(8),\varphi^1(1),\varphi^1(6),\varphi^0(3),\varphi^0(7)]=[4,1,2,3,7]$.

To make sure $a_3=a_4$, we can change $a$ to $a'=[\varphi^0(4),\varphi^0(1),\varphi^0(2),\varphi^1(3),\varphi^0(7)]=[4,1,2,2,7]$, using $0+0+0+1+0=1$ change.



#### Tags 

#2300 #NOT OK #brute_force #data_structures #dsu #math #number_theory #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_864_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
