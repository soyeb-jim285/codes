<h1 style='text-align: center;'> A. Dalton the Teacher</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Dalton is the teacher of a class with $n$ students, numbered from $1$ to $n$. The classroom contains $n$ chairs, also numbered from $1$ to $n$. Initially student $i$ is seated on chair $p_i$. It is guaranteed that $p_1,p_2,\dots, p_n$ is a permutation of length $n$.

A student is happy if his/her number is different from the number of his/her chair. In order to make all of his students happy, Dalton can repeatedly perform the following operation: choose two distinct students and swap their chairs. What is the minimum number of moves required to make all the students happy? One can show that, under the constraints of this problem, it is possible to make all the students happy with a finite number of moves.

A permutation of length $n$ is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array), and $[1,3,4]$ is also not a permutation ($n=3$ but there is $4$ in the array).

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 1000$). The description of the test cases follows.

The first line contains a single integer $n$ ($2 \le n \le 10^5$) — the number of students.

The second line contains $n$ integers $p_1, p_2, \ldots, p_n$ ($1 \le p_i \le n$) — $p_i$ denotes the initial chair of student $i$. It is guaranteed that $p$ is a permutation.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

## Output

For each test case, output the minimum number of moves required.

## Example

## Input


```

522 131 2 351 2 5 4 341 2 4 31010 2 1 3 6 5 4 7 9 8
```
## Output


```

0
2
2
1
1

```
## Note

In the first test case, both students are already happy, so Dalton can perform $0$ moves.

In the second test case, Dalton can swap the chairs of students $1$ and $2$ to get the array $[2, 1, 3]$. Then he can swap chairs of students $2$ and $3$ to get the array $[2, 3, 1]$. At this point all the students are happy, and he performed $2$ moves. It is impossible to perform the task with fewer moves.

In the third test case, by swapping the chairs of students $1$ and $2$ and then swapping the chairs of students $4$ and $5$, Dalton gets the array $[2, 1, 5, 3, 4]$ in $2$ moves.



#### tags 

#800 #greedy #math 