<h1 style='text-align: center;'> L. Project Manager</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

There are $n$ employees at Bersoft company, numbered from $1$ to $n$. Each employee works on some days of the week and rests on the other days. You are given the lists of working days of the week for each employee.

There are regular days and holidays. On regular days, only those employees work that have the current day of the week on their list. On holidays, no one works. You are provided with a list of days that are holidays. The days are numbered from $1$ onwards, day $1$ is Monday.

The company receives $k$ project offers they have to complete. The projects are numbered from $1$ to $k$ in the order of decreasing priority. 

Each project consists of multiple parts, where the $i$-th part must be completed by the $a_i$-th employee. The parts must be completed in order (i. e. the $(i+1)$-st part can only be started when the $i$-th part is completed). Each part takes the corresponding employee a day to complete.

The projects can be worked on simultaneously. However, one employee can complete a part of only one project during a single day. If they have a choice of what project to complete a part on, they always go for the project with the highest priority (the lowest index).

For each project, output the day that project will be completed on.

### Input

The first line contains three integers $n, m$ and $k$ ($1 \le n, m, k \le 2 \cdot 10^5$) — the number of employees, the number of holidays and the number of projects.

The $i$-th of the next $n$ lines contains the list of working days of the $i$-th employee. First, a single integer $t$ ($1 \le t \le 7$) — the number of working days. Then $t$ days of the week in the increasing order. The possible days are: "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday".

The next line contains $m$ integers $h_1, h_2, \dots, h_m$ ($1 \le h_1 < h_2 < \dots < h_m \le 10^9$) — the list of holidays.

The $j$-th of the next $k$ lines contains a description of the $j$-th project. It starts with an integer $p$ ($1 \le p \le 2 \cdot 10^5$) — the number of parts in the project. Then $p$ integers $a_1, a_2, \dots, a_p$ ($1 \le a_x \le n$) follow, where $p_i$ is the index of the employee that must complete the $i$-th part.

The total number of parts in all projects doesn't exceed $2 \cdot 10^5$.

### Output

Print $k$ integers — the $j$-th value should be equal to the day the $j$-th project is completed on.

## Example

### Input


```text
3 5 4
2 Saturday Sunday
2 Tuesday Thursday
4 Monday Wednesday Friday Saturday
4 7 13 14 15
5 1 1 3 3 2
3 2 3 2
5 3 3 3 1 1
8 3 3 3 3 3 3 3 3
```
### Output


```text
25 9 27 27 
```


#### Tags 

#2400 #NOT OK #brute_force #data_structures #implementation 

## Blogs
- [All Contest Problems](../2022-2023_ICPC,_NERC,_Southern_and_Volga_Russian_Regional_Contest_(Online_Mirror,_ICPC_Rules,_Preferably_Teams).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
