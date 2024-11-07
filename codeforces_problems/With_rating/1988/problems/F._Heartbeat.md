<h1 style='text-align: center;'> F. Heartbeat</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

For an array $u_1, u_2, \ldots, u_n$, define 

* a prefix maximum as an index $i$ such that $u_i>u_j$ for all $j<i$;
* a suffix maximum as an index $i$ such that $u_i>u_j$ for all $j>i$;
* an ascent as an index $i$ ($i>1$) such that $u_i>u_{i-1}$.

You are given three cost arrays: $[a_1, a_2, \ldots, a_n]$, $[b_1, b_2, \ldots, b_n]$, and $[c_0, c_1, \ldots, c_{n-1}]$.

Define the cost of an array that has $x$ prefix maximums, $y$ suffix maximums, and $z$ ascents as $a_x\cdot b_y\cdot c_z$.

Let the sum of costs of all permutations of $1,2,\ldots,n$ be $f(n)$. Find $f(1)$, $f(2)$, ..., $f(n)$ modulo $998\,244\,353$.

##### Input

The first line contains an integer $n$ ($1\le n\le 700$).

The second line contains $n$ integers $a_1,\ldots,a_n$ ($0\le a_i<998\,244\,353$).

The third line contains $n$ integers $b_1,\ldots,b_n$ ($0\le b_i<998\,244\,353$).

The fourth line contains $n$ integers $c_0,\ldots,c_{n-1}$ ($0\le c_i<998\,244\,353$).

##### Output

Print $n$ integers: the $i$-th one is $f(i)$ modulo $998\,244\,353$.

## Examples

##### Input


```text
31 1 11 1 11 1 1
```
##### Output

```text

1 2 6 
```
##### Input


```text
31 2 32 3 13 1 2
```
##### Output

```text

6 13 34 
```
##### Input


```text
51 4 2 5 32 5 1 3 4300000000 100000000 500000000 400000000 200000000
```
##### Output

```text

600000000 303511294 612289529 324650937 947905622 
```
## Note

In the second example:

* Consider permutation $[1,2,3]$. Indices $1,2,3$ are prefix maximums. Index $3$ is the only suffix maximum. Indices $2,3$ are ascents. In conclusion, it has $3$ prefix maximums, $1$ suffix maximums, and $2$ ascents. Therefore, its cost is $a_3b_1c_2=12$.
* Permutation $[1,3,2]$ has $2$ prefix maximums, $2$ suffix maximums, and $1$ ascent. Its cost is $6$.
* Permutation $[2,1,3]$ has $2$ prefix maximums, $1$ suffix maximum, and $1$ ascent. Its cost is $4$.
* Permutation $[2,3,1]$ has $2$ prefix maximums, $2$ suffix maximums, and $1$ ascent. Its cost is $6$.
* Permutation $[3,1,2]$ has $1$ prefix maximum, $2$ suffix maximums, and $1$ ascent. Its cost is $3$.
* Permutation $[3,2,1]$ has $1$ prefix maximum, $3$ suffix maximums, and $0$ ascents. Its cost is $3$.

The sum of all permutations' costs is $34$, so $f(3)=34$.



#### Tags 

#3000 #NOT OK #combinatorics #dp #fft #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_958_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
- [Tutorial #2 (en)](../blogs/Tutorial_2_(en).md)
