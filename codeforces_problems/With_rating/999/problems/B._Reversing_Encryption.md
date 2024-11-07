<h1 style='text-align: center;'> B. Reversing Encryption</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A string $s$ of length $n$ can be encrypted by the following algorithm:

* iterate over all divisors of $n$ in decreasing order (i.e. from $n$ to $1$),
* for each divisor $d$, reverse the substring $s[1 \dots d]$ (i.e. the substring which starts at position $1$ and ends at position $d$).

For example, the above algorithm applied to the string $s$="codeforces" leads to the following changes: "codeforces" $\to$ "secrofedoc" $\to$ "orcesfedoc" $\to$ "rocesfedoc" $\to$ "rocesfedoc" (obviously, the last reverse operation doesn't change the string because $d=1$).

You are given the encrypted string $t$. Your task is to decrypt this string, i.e., to find a string $s$ such that the above algorithm results in string $t$. It can be proven that this string $s$ always exists and is unique.

##### Input

The first line of input consists of a single integer $n$ ($1 \le n \le 100$) — the length of the string $t$. The second line of input consists of the string $t$. The length of $t$ is $n$, and it consists only of lowercase Latin letters.

##### Output

Print a string $s$ such that the above algorithm results in $t$.

## Examples

##### Input


```text
10  
rocesfedoc  

```
##### Output


```text
codeforces  

```
##### Input


```text
16  
plmaetwoxesisiht  

```
##### Output


```text
thisisexampletwo  

```
##### Input


```text
1  
z  

```
##### Output


```text
z  

```
## Note

The first example is described in the problem statement.



#### Tags 

#900 #NOT OK #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_490_(Div._3).md)
- [Announcement (ru)](../blogs/Announcement_(ru).md)
- [Tutorial](../blogs/Tutorial.md)
