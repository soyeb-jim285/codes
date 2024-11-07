<h1 style='text-align: center;'> C. The Sports Festival</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The student council is preparing for the relay race at the sports festival.

The council consists of $n$ members. They will run one after the other in the race, the speed of member $i$ is $s_i$. The discrepancy $d_i$ of the $i$-th stage is the difference between the maximum and the minimum running speed among the first $i$ members who ran. Formally, if $a_i$ denotes the speed of the $i$-th member who participated in the race, then $d_i = \max(a_1, a_2, \dots, a_i) - \min(a_1, a_2, \dots, a_i)$.

You want to minimize the sum of the discrepancies $d_1 + d_2 + \dots + d_n$. To do this, you are allowed to change the order in which the members run. What is the minimum possible sum that can be achieved?

## Input

The first line contains a single integer $n$ ($1 \le n \le 2000$)  — the number of members of the student council.

The second line contains $n$ integers $s_1, s_2, \dots, s_n$ ($1 \le s_i \le 10^9$)  – the running speeds of the members.

## Output

Print a single integer  — the minimum possible value of $d_1 + d_2 + \dots + d_n$ after choosing the order of the members.

## Examples

## Input


```

3
3 1 2

```
## Output


```

3

```
## Input


```

1
5

```
## Output


```

0

```
## Input


```

6
1 6 3 3 6 3

```
## Output


```

11

```
## Input


```

6
104 943872923 6589 889921234 1000000000 69

```
## Output


```

2833800505

```
## Note

In the first test case, we may choose to make the third member run first, followed by the first member, and finally the second. Thus $a_1 = 2$, $a_2 = 3$, and $a_3 = 1$. We have:

* $d_1 = \max(2) - \min(2) = 2 - 2 = 0$.
* $d_2 = \max(2, 3) - \min(2, 3) = 3 - 2 = 1$.
* $d_3 = \max(2, 3, 1) - \min(2, 3, 1) = 3 - 1 = 2$.

The resulting sum is $d_1 + d_2 + d_3 = 0 + 1 + 2 = 3$. It can be shown that it is impossible to achieve a smaller value.

In the second test case, the only possible rearrangement gives $d_1 = 0$, so the minimum possible result is $0$.



#### tags 

#1800 #dp #greedy 