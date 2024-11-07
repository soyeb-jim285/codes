<h1 style='text-align: center;'> C. Vasya And Array</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya has an array $a_1, a_2, \dots, a_n$.

You don't know this array, but he told you $m$ facts about this array. The $i$-th fact is a triple of numbers $t_i$, $l_i$ and $r_i$ ($0 \le t_i \le 1, 1 \le l_i < r_i \le n$) and it means:

* if $t_i=1$ then subbarray $a_{l_i}, a_{l_i + 1}, \dots, a_{r_i}$ is sorted in non-decreasing order;
* if $t_i=0$ then subbarray $a_{l_i}, a_{l_i + 1}, \dots, a_{r_i}$ is not sorted in non-decreasing order. A subarray is not sorted if there is at least one pair of consecutive elements in this subarray such that the former is greater than the latter.

For example if $a = [2, 1, 1, 3, 2]$ then he could give you three facts: $t_1=1, l_1=2, r_1=4$ (the subarray $[a_2, a_3, a_4] = [1, 1, 3]$ is sorted), $t_2=0, l_2=4, r_2=5$ (the subarray $[a_4, a_5] = [3, 2]$ is not sorted), and $t_3=0, l_3=3, r_3=5$ (the subarray $[a_3, a_5] = [1, 3, 2]$ is not sorted).

You don't know the array $a$. Find any array which satisfies all the given facts.

#### Input

The first line contains two integers $n$ and $m$ ($2 \le n \le 1000, 1 \le m \le 1000$).

Each of the next $m$ lines contains three integers $t_i$, $l_i$ and $r_i$ ($0 \le t_i \le 1, 1 \le l_i < r_i \le n$).

If $t_i = 1$ then subbarray $a_{l_i}, a_{l_i + 1}, \dots , a_{r_i}$ is sorted. Otherwise (if $t_i = 0$) subbarray $a_{l_i}, a_{l_i + 1}, \dots , a_{r_i}$ is not sorted.

#### Output

If there is no array that satisfies these facts in only line print NO (in any letter case).

If there is a solution, print YES (in any letter case). In second line print $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$) — the array $a$, satisfying all the given facts. If there are multiple satisfying arrays you can print any of them.

## Examples

#### Input


```text
7 4
1 1 3
1 2 5
0 5 6
1 6 7
```
#### Output


```text
YES
1 2 2 3 5 4 4
```
#### Input


```text
4 2
1 1 4
0 2 3
```
#### Output


```text
NO
```


#### Tags 

#1800 #NOT OK #constructive_algorithms #greedy #implementation 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_67_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
