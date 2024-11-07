<h1 style='text-align: center;'> F. Problems for Codeforces</h1>

<h5 style='text-align: center;'>time limit per test: 8 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

XYMXYM and CQXYM will prepare $n$ problems for Codeforces. The difficulty of the problem $i$ will be an integer $a_i$, where $a_i \geq 0$. The difficulty of the problems must satisfy $a_i+a_{i+1}<m$ ($1 \leq i < n$), and $a_1+a_n<m$, where $m$ is a fixed integer. XYMXYM wants to know how many plans of the difficulty of the problems there are modulo $998\,244\,353$.

Two plans of difficulty $a$ and $b$ are different only if there is an integer $i$ ($1 \leq i \leq n$) satisfying $a_i \neq b_i$.

##### Input

A single line contains two integers $n$ and $m$ ($2 \leq n \leq 50\,000$, $1 \leq m \leq 10^9$).

##### Output

Print a single integer — the number of different plans.

## Examples

##### Input


```text
3 2
```
##### Output


```text
4
```
##### Input


```text
5 9
```
##### Output


```text
8105
```
##### Input


```text
21038 3942834
```
##### Output


```text
338529212
```
## Note

In the first test case, the valid $a$ are: $[0,0,0]$, $[0,0,1]$, $[0,1,0]$, $[1,0,0]$.

$[1,0,1]$ is invalid since $a_1+a_n \geq m$.



#### Tags 

#3300 #NOT OK #combinatorics #fft #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_745_(Div._1).md)
- [Codeforces Round #745 (en)](../blogs/Codeforces_Round_745_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
