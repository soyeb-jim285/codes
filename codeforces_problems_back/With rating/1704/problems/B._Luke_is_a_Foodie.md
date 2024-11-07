<h1 style='text-align: center;'> B. Luke is a Foodie</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Luke likes to eat. There are $n$ piles of food aligned in a straight line in front of him. The $i$-th pile contains $a_i$ units of food. 

Luke will walk from the $1$-st pile towards the $n$-th pile, and he wants to eat every pile of food without walking back. When Luke reaches the $i$-th pile, he can eat that pile if and only if $|v - a_i| \leq x$, where $x$ is a fixed integer, and $v$ is Luke's food affinity.

Before Luke starts to walk, he can set $v$ to any integer. Also, for each $i$ ($1 \leq i \leq n$), Luke can change his food affinity to any integer before he eats the $i$-th pile.

Find the minimum number of changes needed to eat every pile of food.

## Note

 that the initial choice for $v$ is not considered as a change.

## Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. The description of test cases follows.

For each test case, the first line contains two integers, $n, x$ ($1 \leq n \leq 2 \cdot 10^5$, $1 \leq x \leq 10^9$) — the number of piles, and the maximum difference between the size of a pile and Luke's food affinity, such that Luke can eat the pile.

The second line contains $n$ integers $a_1, a_2, \ldots , a_n$ ($1 \leq a_i \leq 10^9$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output an integer on a separate line, which is the minimum number of changes needed.

## Example

## Input


```

75 33 8 5 6 75 33 10 9 8 712 825 3 3 17 8 6 1 16 15 25 17 2310 21 2 3 4 5 6 7 8 9 108 22 4 6 8 6 4 12 148 22 7 8 9 6 13 21 2815 511 4 13 23 7 10 5 21 20 11 17 5 29 16 11
```
## Output


```

0
1
2
1
2
4
6

```
## Note

In the first test case, Luke can set $v$ to $5$ before he starts to walk. And he can walk straight to eat every piles of food without changing $v$.

In the second test case, Luke can set $v$ to $3$ before he starts to walk. And he could change $v$ to $10$ before he eats the second pile. After that, he can walk straight to eat remaining food without changing $v$.

In the fourth test case, Luke can set $v$ to $3$ before he starts to walk. And he could change $v$ to $8$ before he eats the sixth pile. After that, he can walk straight to eat remaining food without changing $v$.

In the fifth test case, Luke can set $v$ to $4$ before he starts to walk. And he could change $v$ to $6$ before he eats the fourth pile. Then he could change $v$ to $12$ before he eats the seventh pile. After that, he can walk straight to eat remaining food without changing $v$.



#### tags 

#1000 #brute_force #greedy #implementation 