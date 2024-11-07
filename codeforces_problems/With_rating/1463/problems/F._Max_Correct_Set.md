<h1 style='text-align: center;'> F. Max Correct Set</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's call the set of positive integers $S$ correct if the following two conditions are met: 

* $S \subseteq \{1, 2, \dots, n\}$;
* if $a \in S$ and $b \in S$, then $|a-b| \neq x$ and $|a-b| \neq y$.

For the given values $n$, $x$, and $y$, you have to find the maximum size of the correct set.

###### Input

A single line contains three integers $n$, $x$ and $y$ ($1 \le n \le 10^9$; $1 \le x, y \le 22$). 

###### Output

Print one integer — the maximum size of the correct set.

## Examples

###### Input


```text
10 2 5
```
###### Output


```text
5
```
###### Input


```text
21 4 6
```
###### Output


```text
9
```
###### Input


```text
1337 7 7
```
###### Output


```text
672
```
###### Input


```text
455678451 22 17
```
###### Output


```text
221997195
```


#### Tags 

#3100 #NOT OK #bitmasks #dp #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_100_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
