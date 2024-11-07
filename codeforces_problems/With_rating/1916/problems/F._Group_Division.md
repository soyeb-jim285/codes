<h1 style='text-align: center;'> F. Group Division</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In the $31$st lyceum, there were two groups of olympiad participants: computer science and mathematics. The number of computer scientists was $n_1$, and the number of mathematicians was $n_2$. It is not known for certain who belonged to which group, but it is known that there were friendly connections between some pairs of people (these connections could exist between a pair of people from the same group or from different groups).

The connections were so strong that even if one person is removed along with all their friendly connections, any pair of people still remains acquainted either directly or through mutual friends.

$^{\dagger}$ More formally, two people $(x, y)$ are acquainted in the following case: there are people $a_1, a_2, \ldots,a_n$ ($1 \le a_i \le n_1 + n_2$) such that the following conditions are simultaneously met:

$\bullet$ Person $x$ is directly acquainted with $a_1$.

$\bullet$ Person $a_n$ is directly acquainted with $y$.

$\bullet$ Person $a_i$ is directly acquainted with $a_{i + 1}$ for any ($1 \le i \le n - 1$).

The teachers were dissatisfied with the fact that computer scientists were friends with mathematicians and vice versa, so they decided to divide the students into two groups in such a way that the following two conditions are met:

$\bullet$ There were $n_1$ people in the computer science group, and $n_2$ people in the mathematics group.

$\bullet$ Any pair of computer scientists should be acquainted (acquaintance involving mutual friends, who must be from the same group as the people in the pair, is allowed), the same should be true for mathematicians.

Help them solve this problem and find out who belongs to which group.

### Input

Each test consists of several test cases. The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases. Then follows the description of the test cases.

The first line of each test case contains three integers $n_1$, $n_2$, and $m$ ($1 \le n_1, n_2 \le 2000$, $1 \le m \le 5000$). $n_1$, $n_2$ are the sizes of the two groups described in the problem, and $m$ is the number of friendly connections initially.

The following $m$ lines describe the friendly connections: in the $i$-th ($1 \le i \le m$) line, a pair of numbers $(a, b)$ is given, which means that the person with number $a$ is friends with the person with number $b$ (and vice versa).

It is guaranteed that for each test case, all friendly connections are distinct.

It is guaranteed that the sum of $n_1 + n_2$ for all test cases does not exceed $2000$, and the sum of $m$ for all test cases does not exceed $5000$.

It is also guaranteed that for each test case, a solution exists.

If there are several answers, print any of them.

### Output

For each test case, output two lines.

In the first line, output $n_1$ distinct numbers $a_i$ ($1 \le a_i \le n_1 + n_2$) — the people belonging to the first group.

In the second line, output $n_2$ distinct numbers $b_i$ ($1 \le b_i \le n_1 + n_2$) — the people belonging to the second group.

All numbers must be distinct.

If there are several possible answers, print any one.

## Example

### Input


```text
31 2 32 31 31 21 4 72 53 42 41 23 54 51 53 3 71 21 62 32 53 44 54 6
```
### Output

```text

3 
1 2 
5 
1 2 3 4 
4 5 6 
1 2 3 

```
## Note

Consider the third test case. The division into groups looks as follows: 

 ![](images/f8a58758032dc4756237137ce3acf9e527c3765b.png)  The students selected as computer scientists are colored in green, and those selected as mathematicians are colored in blue.Consider all pairs of computer scientists and how they are acquainted:

Pairs $(4, 5), (4, 6)$ are directly acquainted.

Pair $(5, 6)$ is acquainted through the computer scientist with number $4$.

Consider all pairs of mathematicians and how they are acquainted:

Pairs $(1, 2), (2, 3)$ are directly acquainted.

Pair $(1, 3)$ is acquainted through the mathematician with number $2$.

We conclude that any pair of people belonging to the same group is acquainted with each other, thus the division into two groups is correct.



#### Tags 

#2900 #NOT OK #constructive_algorithms #dfs_and_similar #graphs #greedy 

## Blogs
- [All Contest Problems](../Good_Bye_2023.md)
- [Good Bye 2023](../blogs/Good_Bye_2023.md)
- [Good Bye 2023 tutorial (en)](../blogs/Good_Bye_2023_tutorial_(en).md)
