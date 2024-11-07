<h1 style='text-align: center;'> A. Timetable</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

There are two bus stops denoted A and B, and there $n$ buses that go from A to B every day. The shortest path from A to B takes $t$ units of time but some buses might take longer paths. Moreover, buses are allowed to overtake each other during the route.

At each station one can find a sorted list of moments of time when a bus is at this station. We denote this list as $a_1 < a_2 < \ldots < a_n$ for stop A and as $b_1 < b_2 < \ldots < b_n$ for stop B. The buses always depart from A and arrive to B according to the timetable, but the order in which the buses arrive may differ. Let's call an order of arrivals valid if each bus arrives at least $t$ units of time later than departs.

It is known that for an order to be valid the latest possible arrival for the bus that departs at $a_i$ is $b_{x_i}$, i.e. $x_i$-th in the timetable. In other words, for each $i$ there exists such a valid order of arrivals that the bus departed $i$-th arrives $x_i$-th (and all other buses can arrive arbitrary), but there is no valid order of arrivals in which the $i$-th departed bus arrives $(x_i + 1)$-th.

Formally, let's call a permutation $p_1, p_2, \ldots, p_n$ valid, if $b_{p_i} \ge a_i + t$ for all $i$. Then $x_i$ is the maximum value of $p_i$ among all valid permutations.

You are given the sequences $a_1, a_2, \ldots, a_n$ and $x_1, x_2, \ldots, x_n$, but not the arrival timetable. Find out any suitable timetable for stop B $b_1, b_2, \ldots, b_n$ or determine that there is no such timetable.

#### Input

The first line of the input contains two integers $n$ and $t$ ($1 \leq n \leq 200\,000$, $1 \leq t \leq 10^{18}$) — the number of buses in timetable for and the minimum possible travel time from stop A to stop B.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_1 < a_2 < \ldots < a_n \leq 10^{18}$), defining the moments of time when the buses leave stop A.

The third line contains $n$ integers $x_1, x_2, \ldots, x_n$ ($1 \leq x_i \leq n$), the $i$-th of them stands for the maximum possible timetable position, at which the $i$-th bus leaving stop A can arrive at stop B. 

#### Output

If a solution exists, print "Yes" (without quotes) in the first line of the output.

In the second line print $n$ integers $b_1, b_2, \ldots, b_n$ ($1 \leq b_1 < b_2 < \ldots < b_n \leq 3 \cdot 10^{18}$). We can show that if there exists any solution, there exists a solution that satisfies such constraints on $b_i$. If there are multiple valid answers you can print any of them.

If there is no valid timetable, print "No" (without quotes) in the only line of the output.

## Examples

#### Input


```text
3 10  
4 6 8  
2 2 3  

```
#### Output


```text
Yes  
16 17 21   

```
#### Input


```text
2 1  
1 2  
2 1  

```
#### Output


```text
No  

```
## Note

Consider the first example and the timetable $b_1, b_2, \ldots, b_n$ from the output.

To get $x_1 = 2$ the buses can arrive in the order $(2, 1, 3)$. To get $x_2 = 2$ and $x_3 = 3$ the buses can arrive in the order $(1, 2, 3)$. $x_1$ is not $3$, because the permutations $(3, 1, 2)$ and $(3, 2, 1)$ (all in which the $1$-st bus arrives $3$-rd) are not valid (sube buses arrive too early), $x_2$ is not $3$ because of similar reasons.



#### Tags 

#2300 #NOT OK #constructive_algorithms #data_structures #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_507_(Div._1,_based_on_Olympiad_of_Metropolises).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
