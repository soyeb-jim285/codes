<h1 style='text-align: center;'> F. New Year and Handle Change</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

New Year is getting near. So it's time to change handles on codeforces. Mishka wants to change his handle but in such a way that people would not forget who he is.

To make it work, he only allowed to change letters case. More formally, during one handle change he can choose any segment of his handle $[i; i + l - 1]$ and apply tolower or toupper to all letters of his handle on this segment (more fomally, replace all uppercase letters with corresponding lowercase or vice versa). The length $l$ is fixed for all changes.

Because it is not allowed to change codeforces handle too often, Mishka can perform at most $k$ such operations. What is the minimum value of $min(lower, upper)$ (where $lower$ is the number of lowercase letters, and $upper$ is the number of uppercase letters) can be obtained after optimal sequence of changes?

###### Input

The first line of the input contains three integers $n, k$ and $l$ ($1 \le n, k, l \le 10^6, l \le n)$ — the length of Mishka's handle, the number of changes and the length of the segment.

The second line of the input contains one string $s$, consisting of $n$ lowercase and uppercase Latin letters — Mishka's handle.

###### Output

Print one integer — the minimum value of $min(lower, upper)$ after that Mishka change his handle at most $k$ times in a way described in the problem statement.

## Examples

###### Input


```text
7 1 4
PikMike
```
###### Output


```text
0
```
###### Input


```text
15 2 2
AaAaAAaaAAAAaaA
```
###### Output


```text
2
```
###### Input


```text
14 2 6
aBcdEFGHIJklMn
```
###### Output


```text
0
```
###### Input


```text
9 2 2
aAaAAAaaA
```
###### Output


```text
1
```


#### Tags 

#2800 #NOT OK #binary_search #dp 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_79_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
