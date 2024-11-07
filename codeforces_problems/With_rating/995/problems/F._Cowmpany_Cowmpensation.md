<h1 style='text-align: center;'> F. Cowmpany Cowmpensation</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Allen, having graduated from the MOO Institute of Techcowlogy (MIT), has started a startup! Allen is the president of his startup. He also hires $n-1$ other employees, each of which is assigned a direct superior. If $u$ is a superior of $v$ and $v$ is a superior of $w$ then also $u$ is a superior of $w$. Additionally, there are no $u$ and $v$ such that $u$ is the superior of $v$ and $v$ is the superior of $u$. Allen himself has no superior. Allen is employee number $1$, and the others are employee numbers $2$ through $n$.

Finally, Allen must assign salaries to each employee in the company including himself. Due to budget constraints, each employee's salary is an integer between $1$ and $D$. Additionally, no employee can make strictly more than his superior.

Help Allen find the number of ways to assign salaries. As this number may be large, output it modulo $10^9 + 7$.

##### Input

The first line of the input contains two integers $n$ and $D$ ($1 \le n \le 3000$, $1 \le D \le 10^9$).

The remaining $n-1$ lines each contain a single positive integer, where the $i$-th line contains the integer $p_i$ ($1 \le p_i \le i$). $p_i$ denotes the direct superior of employee $i+1$.

##### Output

##### Output

 a single integer: the number of ways to assign salaries modulo $10^9 + 7$.

## Examples

##### Input


```text
3 2  
1  
1  

```
##### Output


```text
5  

```
##### Input


```text
3 3  
1  
2  

```
##### Output


```text
10  

```
##### Input


```text
2 5  
1  

```
##### Output


```text
15  

```
## Note

In the first sample case, employee 2 and 3 report directly to Allen. The three salaries, in order, can be $(1,1,1)$, $(2,1,1)$, $(2,1,2)$, $(2,2,1)$ or $(2,2,2)$.

In the second sample case, employee 2 reports to Allen and employee 3 reports to employee 2. In order, the possible salaries are $(1,1,1)$, $(2,1,1)$, $(2,2,1)$, $(2,2,2)$, $(3,1,1)$, $(3,2,1)$, $(3,2,2)$, $(3,3,1)$, $(3,3,2)$, $(3,3,3)$.



#### Tags 

#2700 #NOT OK #combinatorics #dp #math #trees 

## Blogs
- [All Contest Problems](../Codeforces_Round_492_(Div._1)_[Thanks,_uDebug!].md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
