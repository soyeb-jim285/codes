<h1 style='text-align: center;'> C. Watering an Array</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have an array of integers $a_1, a_2, \ldots, a_n$ of length $n$. On the $i$-th of the next $d$ days you are going to do exactly one of the following two actions:

* Add $1$ to each of the first $b_i$ elements of the array $a$ (i.e., set $a_j := a_j + 1$ for each $1 \le j \le b_i$).
* Count the elements which are equal to their position (i.e., the $a_j = j$). Denote the number of such elements as $c$. Then, you add $c$ to your score, and reset the entire array $a$ to a $0$-array of length $n$ (i.e., set $[a_1, a_2, \ldots, a_n] := [0, 0, \ldots, 0]$).

Your score is equal to $0$ in the beginning. 
## Note

 that on each day you should perform exactly one of the actions above: you cannot skip a day or perform both actions on the same day.

What is the maximum score you can achieve at the end?

Since $d$ can be quite large, the sequence $b$ is given to you in the compressed format: 

* You are given a sequence of integers $v_1, v_2, \ldots, v_k$. The sequence $b$ is a concatenation of infinitely many copies of $v$: $b = [v_1, v_2, \ldots, v_k, v_1, v_2, \ldots, v_k, \ldots]$.
### Input

The first line contains a single integer $t$ ($1 \le t \le 10^3$) — the number of test cases.

The first line of each test case contains three integers $n$, $k$ and $d$ ($1 \le n \le 2000$, $1 \le k \le 10^5$, $k \le d \le 10^9$) — the length of the array $a$, the length of the sequence $v$ and the number of days you are going to perform operations on.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le n$) — the array $a$.

The third line of each test case contains $k$ integers $v_1, v_2, \ldots, v_k$ ($1 \le v_i \le n$) — the sequence $v$.

It is guaranteed that the sum of $n$ over all test cases doesn't exceed $2000$ and the sum of $k$ over all test cases doesn't exceed $10^5$.

### Output

For each test case, output one integer: the maximum score you can achieve at the end of the $d$-th day.

## Example

### Input


```text
53 4 41 2 31 3 2 36 2 36 1 2 4 1 56 65 1 10 5 0 5 051 1 1113 4 61 2 31 3 2 3
```
### Output

```text

4
3
0
1
5

```
## Note

In the first test case, the sequence $b$ is equal to $[1, 3, 2, 3, 1, 3, 2, 3, \ldots]$ and one of the optimal solutions for this case is as follows:

* Perform the operation of the second type on the $1$-st day: your score increases by $3$ and array $a$ becomes equal to $[0, 0, 0]$.
* Perform the operation of the first type on the $2$-nd day: array $a$ becomes equal to $[1, 1, 1]$.
* Perform the operation of the first type on the $3$-rd day: array $a$ becomes equal to $[2, 2, 1]$.
* Perform the operation of the second type on the $4$-th day: your score increases by $1$ and array $a$ becomes equal to $[0, 0, 0]$.

It can be shown that it is impossible to score more than $4$, so the answer is $4$.

In the second test case, the sequence $b$ is equal to $[6, 6, 6, 6, \ldots]$. One of the ways to score $3$ is to perform operations of the first type on the $1$-st and the $3$-rd days and to perform an operation of the second type on the $2$-nd day.



#### Tags 

#1600 #NOT OK #brute_force #greedy #implementation #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_917_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
