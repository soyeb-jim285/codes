<h1 style='text-align: center;'> B. Math</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

JATC's math teacher always gives the class some interesting math problems so that they don't get bored. Today the problem is as follows. Given an integer $n$, you can perform the following operations zero or more times:

* mul $x$: multiplies $n$ by $x$ (where $x$ is an arbitrary positive integer).
* sqrt: replaces $n$ with $\sqrt{n}$ (to apply this operation, $\sqrt{n}$ must be an integer).

You can perform these operations as many times as you like. What is the minimum value of $n$, that can be achieved and what is the minimum number of operations, to achieve that minimum value?

Apparently, no one in the class knows the answer to this problem, maybe you can help them?

#### Input

The only line of the input contains a single integer $n$ ($1 \le n \le 10^6$) — the initial number.

#### Output

Print two integers: the minimum integer $n$ that can be achieved using the described operations and the minimum number of operations required.

## Examples

#### Input


```text
20  

```
#### Output


```text
10 2
```
#### Input


```text
5184  

```
#### Output


```text
6 4
```
## Note

In the first example, you can apply the operation mul $5$ to get $100$ and then sqrt to get $10$.

In the second example, you can first apply sqrt to get $72$, then mul $18$ to get $1296$ and finally two more sqrt and you get $6$.

## Note

, that even if the initial value of $n$ is less or equal $10^6$, it can still become greater than $10^6$ after applying one or more operations.



#### Tags 

#1500 #NOT OK #greedy #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_520_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
