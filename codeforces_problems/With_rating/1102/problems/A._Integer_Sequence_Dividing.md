<h1 style='text-align: center;'> A. Integer Sequence Dividing</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an integer sequence $1, 2, \dots, n$. You have to divide it into two sets $A$ and $B$ in such a way that each element belongs to exactly one set and $|sum(A) - sum(B)|$ is minimum possible.

The value $|x|$ is the absolute value of $x$ and $sum(S)$ is the sum of elements of the set $S$.

##### Input

The first line of the input contains one integer $n$ ($1 \le n \le 2 \cdot 10^9$).

##### Output

Print one integer — the minimum possible value of $|sum(A) - sum(B)|$ if you divide the initial sequence $1, 2, \dots, n$ into two sets $A$ and $B$.

## Examples

##### Input


```text
3
```
##### Output


```text
0
```
##### Input


```text
5
```
##### Output


```text
1
```
##### Input


```text
6
```
##### Output


```text
1
```
## Note

Some (not all) possible answers to examples:

In the first example you can divide the initial sequence into sets $A = \{1, 2\}$ and $B = \{3\}$ so the answer is $0$.

In the second example you can divide the initial sequence into sets $A = \{1, 3, 4\}$ and $B = \{2, 5\}$ so the answer is $1$.

In the third example you can divide the initial sequence into sets $A = \{1, 4, 5\}$ and $B = \{2, 3, 6\}$ so the answer is $1$.



#### Tags 

#800 #OK #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_531_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
