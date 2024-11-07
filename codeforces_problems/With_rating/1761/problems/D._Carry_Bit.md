<h1 style='text-align: center;'> D. Carry Bit</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let $f(x,y)$ be the number of carries of $x+y$ in binary (i. e. $f(x,y)=g(x)+g(y)-g(x+y)$, where $g(x)$ is the number of ones in the binary representation of $x$).

Given two integers $n$ and $k$, find the number of ordered pairs $(a,b)$ such that $0 \leq a,b < 2^n$, and $f(a,b)$ equals $k$. 
## Note

 that for $a\ne b$, $(a,b)$ and $(b,a)$ are considered as two different pairs. 

As this number may be large, output it modulo $10^9+7$.

##### Input

The only line of each test contains two integers $n$ and $k$ ($0\leq k<n\leq 10^6$).

##### Output

##### Output

 a single integer  — the answer modulo $10^9+7$.

## Examples

##### Input


```text
3 1
```
##### Output


```text
15
```
##### Input


```text
3 0
```
##### Output


```text
27
```
##### Input


```text
998 244
```
##### Output


```text
573035660
```
## Note

Here are some examples for understanding carries:

$$ \begin{aligned} &\begin{array}{r} 1_{\ \ }1_{\ \ }1\\\ +\ _{1}1_{\ \ }0_{\ \ }0\\\ \hline \ 1_{\ \ }0_{\ \ }1_{\ \ }1 \end{array} &\begin{array}{r} \ 1_{\ \ }0_{\ \ }1\\\ +\ _{\ \ }0_{\ \ }0_{1}1\\\ \hline \ 0_{\ \ }1_{\ \ }1_{\ \ }0 \end{array} & &\begin{array}{r} \ 1_{\ \ }0_{\ \ }1\\\ +\ _{1}0_{1}1_{1}1\\\ \hline \ 1_{\ \ }0_{\ \ }0_{\ \ }0 \end{array} \end{aligned} $$

So $f(7,4)=1$, $f(5,1)=1$ and $f(5,3)=3$.

In the first test case, all the pairs meeting the constraints are $(1,1),(1,5),(2,2),(2,3),(3,2),(4,4),(4,5),(4,6),(4,7),(5,1),(5,4),(5,6),(6,4),(6,5),(7,4)$.



#### Tags 

#2100 #NOT OK #combinatorics #math 

## Blogs
- [All Contest Problems](../Pinely_Round_1_(Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
