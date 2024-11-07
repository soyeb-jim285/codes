<h1 style='text-align: center;'> F. Programming Competition</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

BerSoft is the biggest IT corporation in Berland. There are $n$ employees at BerSoft company, numbered from $1$ to $n$. 

The first employee is the head of the company, and he does not have any superiors. Every other employee $i$ has exactly one direct superior $p_i$.

Employee $x$ is considered to be a superior (direct or indirect) of employee $y$ if one of the following conditions holds: 

* employee $x$ is the direct superior of employee $y$;
* employee $x$ is a superior of the direct superior of employee $y$.

The structure of BerSoft is organized in such a way that the head of the company is superior of every employee.

A programming competition is going to be held soon. Two-person teams should be created for this purpose. However, if one employee in a team is the superior of another, they are uncomfortable together. So, teams of two people should be created so that no one is the superior of the other. 
## Note

 that no employee can participate in more than one team.

Your task is to calculate the maximum possible number of teams according to the aforementioned rules.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($2 \le n \le 2 \cdot 10^5$) — the number of employees.

The second line contains $n-1$ integers $p_2, p_3, \dots, p_n$ ($1 \le p_i \le n$), where $p_i$ is the index of the direct superior of the $i$-th employee.

The sum of $n$ over all test cases doesn't exceed $2 \cdot 10^5$.

### Output

For each test case, print a single integer — the maximum possible number of teams according to the aforementioned rules.

## Example

### Input


```text
641 2 12155 5 5 171 2 1 1 3 371 1 3 2 2 471 2 1 1 1 3
```
### Output

```text

1
0
1
3
3
3

```
## Note

In the first test case, team $(3, 4)$ can be created.

In the second test case, no team can be created, because there are only $2$ employees and one is the superior of another.

In the third test case, team $(2, 3)$ can be created.

In the fourth test case, teams $(2, 4)$, $(3, 5)$ and $(6, 7)$ can be created.

In the fifth test case, teams $(2, 3)$, $(6, 4)$ and $(5, 7)$ can be created.



#### Tags 

#1900 #NOT OK #dfs_and_similar #dp #graph_matchings #greedy #trees 

## Blogs
- [All Contest Problems](../Codeforces_Round_916_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
