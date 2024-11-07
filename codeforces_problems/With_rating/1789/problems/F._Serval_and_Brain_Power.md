<h1 style='text-align: center;'> F. Serval and Brain Power</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Serval loves Brain Power and his brain power problem.

Serval defines that a string $T$ is powerful iff $T$ can be obtained by concatenating some string $T'$ multiple times. Formally speaking, $T$ is powerful iff there exist a string $T'$ and an integer $k\geq 2$ such that $$T=\underbrace{T'+T'+\dots+T'}_{k\text{ times}}$$

For example, gogogo is powerful because it can be obtained by concatenating go three times, but power is not powerful.

Serval has a string $S$ consists of lowercase English letters. He is curious about the longest powerful subsequence of $S$, and he only needs you to find out the length of it. If all the non-empty subsequences of $S$ is not powerful, the answer is considered to be $0$.

A string $a$ is a subsequence of a string $b$ if $a$ can be obtained from $b$ by the deletion of several (possibly, zero or all) characters.

###### Input

The first line contains a single string $S$ ($|S|\leq 80$) consisting of lowercase English letters.

###### Output

Print a single integer — the length of the longest powerful subsequence of $S$. If all the non-empty subsequences of $S$ is not powerful, print $0$.

## Examples

###### Input


```text
buaa
```
###### Output


```text
2
```
###### Input


```text
codeforcesround
```
###### Output


```text
6
```
###### Input


```text
oooooooooooaaaaeaaiaujooooooooooooo
```
###### Output


```text
24
```
###### Input


```text
zero
```
###### Output


```text
0
```
## Note

For the first sample, all of the non-empty subsequences of buaa are listed below:

* b
* u
* a (occurred twice, buaa and buaa)
* bu
* ba (occurred twice, buaa and buaa)
* ua (occurred twice, buaa and buaa)
* aa
* bua (occurred twice, buaa and buaa )
* baa
* uaa
* buaa

Since $\texttt{aa} = \texttt{a} + \texttt{a}$, aa is a powerful subsequence. It can be shown that aa is the only powerful subsequence among them. So the answer is $2$.

For the second sample, the longest powerful subsequence is codcod from codeforcesround. So the answer is $6$.



#### Tags 

#2700 #NOT OK #bitmasks #brute_force #dp #greedy #implementation #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_853_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
