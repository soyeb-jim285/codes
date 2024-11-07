<h1 style='text-align: center;'> E. Company</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The company $X$ has $n$ employees numbered from $1$ through $n$. Each employee $u$ has a direct boss $p_u$ ($1 \le p_u \le n$), except for the employee $1$ who has no boss. It is guaranteed, that values $p_i$ form a tree. Employee $u$ is said to be in charge of employee $v$ if $u$ is the direct boss of $v$ or there is an employee $w$ such that $w$ is in charge of $v$ and $u$ is the direct boss of $w$. Also, any employee is considered to be in charge of himself.

In addition, for each employee $u$ we define it's level $lv(u)$ as follow: 

* $lv(1)=0$
* $lv(u)=lv(p_u)+1$ for $u \neq 1$

In the near future, there are $q$ possible plans for the company to operate. The $i$-th plan consists of two integers $l_i$ and $r_i$, meaning that all the employees in the range $[l_i, r_i]$, and only they, are involved in this plan. To operate the plan smoothly, there must be a project manager who is an employee in charge of all the involved employees. To be precise, if an employee $u$ is chosen as the project manager for the $i$-th plan then for every employee $v \in [l_i, r_i]$, $u$ must be in charge of $v$. 
## Note

, that $u$ is not necessary in the range $[l_i, r_i]$. Also, $u$ is always chosen in such a way that $lv(u)$ is as large as possible (the higher the level is, the lower the salary that the company has to pay the employee).

Before any plan is operated, the company has JATC take a look at their plans. After a glance, he tells the company that for every plan, it's possible to reduce the number of the involved employees exactly by one without affecting the plan. Being greedy, the company asks JATC which employee they should kick out of the plan so that the level of the project manager required is as large as possible. JATC has already figured out the answer and challenges you to do the same.

### Input

The first line contains two integers $n$ and $q$ ($2 \le n \le 100\,000$, $1 \le q \le 100\,000$) — the number of employees and the number of plans, respectively.

The second line contains $n-1$ integers $p_2, p_3, \dots, p_n$ ($1 \le p_i \le n$) meaning $p_i$ is the direct boss of employee $i$.

It is guaranteed, that values $p_i$ form a directed tree with the root of $1$.

Each of the following $q$ lines contains two integers $l_i$ and $r_i$ ($1 \le l_i<r_i \le n$) — the range of the employees, involved in the corresponding plan.

### Output

Print $q$ lines, each containing two integers — the number of the employee which should be kicked from the corresponding plan and the maximum possible level of the project manager in that case.

If there are more than one way to choose that employee, print any of them.

## Example

### Input


```text
11 5  
1 1 3 3 3 4 2 7 7 6  
4 6  
4 8  
1 11  
9 11  
8 11  

```
### Output


```text
4 1  
8 1  
1 0  
11 3  
8 1  

```
## Note

In the example: 

 ![](images/c1751fe7d2fdf870673e805dfefc397d65e3d989.png)  In the first query, we can choose whether $4$ or $5$ or $6$ and the project manager will be $3$.In the second query, if we choose any employee other than the employee $8$, the project manager will be $1$. If we choose $8$, the project manager will be $3$. Since $lv(3)=1 > lv(1)=0$, choosing $8$ is the best strategy.

In the third query, no matter how we choose the employee, the project manager will always be $1$.

In the fourth query, if we choose $9$ or $10$ then the project manager will be $3$. If we choose $11$ then the project manager will be $7$. Since $lv(7)=3>lv(3)=1$, we choose $11$ as the answer.



#### Tags 

#2300 #NOT OK #binary_search #data_structures #dfs_and_similar #greedy #trees 

## Blogs
- [All Contest Problems](../Codeforces_Round_520_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
