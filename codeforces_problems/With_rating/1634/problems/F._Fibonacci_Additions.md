<h1 style='text-align: center;'> F. Fibonacci Additions</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

One of my most productive days was throwing away 1,000 lines of code.— Ken ThompsonFibonacci addition is an operation on an array $X$ of integers, parametrized by indices $l$ and $r$. Fibonacci addition increases $X_l$ by $F_1$, increases $X_{l + 1}$ by $F_2$, and so on up to $X_r$ which is increased by $F_{r - l + 1}$.

$F_i$ denotes the $i$-th Fibonacci number ($F_1 = 1$, $F_2 = 1$, $F_{i} = F_{i - 1} + F_{i - 2}$ for $i > 2$), and all operations are performed modulo $MOD$.

You are given two arrays $A$ and $B$ of the same length. We will ask you to perform several Fibonacci additions on these arrays with different parameters, and after each operation you have to report whether arrays $A$ and $B$ are equal modulo $MOD$.

#### Input

The first line contains 3 numbers $n$, $q$ and $MOD$ ($1 \le n, q \le 3\cdot 10^5, 1 \le MOD \le 10^9+7$) — the length of the arrays, the number of operations, and the number modulo which all operations are performed.

The second line contains $n$ numbers — array $A$ ($0 \le A_i < MOD$).

The third line also contains $n$ numbers — array $B$ ($0 \le B_i < MOD$).

The next $q$ lines contain character $c$ and two numbers $l$ and $r$ ($1 \le l \le r \le n$) — operation parameters. If $c$ is "A", Fibonacci addition is to be performed on array $A$, and if it is is "B", the operation is to be performed on $B$.

#### Output

After each operation, print "YES" (without quotes) if the arrays are equal and "NO" otherwise. Letter case does not matter.

## Examples

#### Input


```text
3 5 3
2 2 1
0 0 0
A 1 3
A 1 3
B 1 1
B 2 2
A 3 3
```
#### Output


```text
YES
NO
NO
NO
YES
```
#### Input


```text
5 3 10
2 5 0 3 5
3 5 8 2 5
B 2 3
B 3 4
A 1 2
```
#### Output


```text
NO
NO
YES
```
## Note

Explanation of the test from the condition:

* Initially $A=[2,2,1]$, $B=[0,0,0]$.
* After operation "A 1 3": $A=[0,0,0]$, $B=[0,0,0]$ (addition is modulo 3).
* After operation "A 1 3": $A=[1,1,2]$, $B=[0,0,0]$.
* After operation "B 1 1": $A=[1,1,2]$, $B=[1,0,0]$.
* After operation "B 2 2": $A=[1,1,2]$, $B=[1,1,0]$.
* After operation "A 3 3": $A=[1,1,0]$, $B=[1,1,0]$.


#### Tags 

#2700 #NOT OK #brute_force #data_structures #hashing #implementation #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_770_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
