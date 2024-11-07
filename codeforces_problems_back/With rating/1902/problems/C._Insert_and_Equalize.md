<h1 style='text-align: center;'> C. Insert and Equalize</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an integer array $a_1, a_2, \dots, a_n$, all its elements are distinct.

First, you are asked to insert one more integer $a_{n+1}$ into this array. $a_{n+1}$ should not be equal to any of $a_1, a_2, \dots, a_n$.

Then, you will have to make all elements of the array equal. At the start, you choose a positive integer $x$ ($x > 0$). In one operation, you add $x$ to exactly one element of the array. ## Note

 that $x$ is the same for all operations.

What's the smallest number of operations it can take you to make all elements equal, after you choose $a_{n+1}$ and $x$?

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of testcases.

The first line of each testcase contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($-10^9 \le a_i \le 10^9$). All $a_i$ are distinct.

The sum of $n$ over all testcases doesn't exceed $2 \cdot 10^5$.

## Output

For each testcase, print a single integer — the smallest number of operations it can take you to make all elements equal, after you choose integers $a_{n+1}$ and $x$.

## Example

## Input


```

331 2 351 -19 17 -3 -15110
```
## Output


```

6
27
1

```
## Note

In the first testcase, you can choose $a_{n+1} = 4$, the array becomes $[1, 2, 3, 4]$. Then choose $x = 1$ and apply the operation $3$ times to the first element, $2$ times to the second element, $1$ time to the third element and $0$ times to the fourth element.

In the second testcase, you can choose $a_{n+1} = 13, x = 4$.

In the third testcase, you can choose $a_{n+1} = 9, x = 1$. Then apply the operation once to $a_{n+1}$.



#### tags 

#1300 #brute_force #constructive_algorithms #greedy #math #number_theory 