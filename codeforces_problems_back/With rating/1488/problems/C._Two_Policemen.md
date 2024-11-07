<h1 style='text-align: center;'> C. Two Policemen</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is a street that can be represented as an array of length $n$.

There are two policemen patrolling a street: the first one is standing at the point $x$ of the street and the second one is standing at the point $y$ of the street.

During one minute, both policemen can decide what to do (independently): move left (if the current position is greater than $1$), move right (if the current position is less than $n$), or do nothing.

The street is considered clear if each point of the street is visited by at least one policeman.

Your task is to find the minimum number of minutes the policemen need to visit each point of the street (again, each point should be visited by at least one of them).

You have to answer $t$ independent test cases.

## Input

The first line of the input contains one integer $t$ ($1 \le t \le 2 \cdot 10^4$) — the number of test cases. Then $t$ test cases follow.

The only line of the test case contains three integers $n$, $x$ and $y$ ($2 \le n \le 10^6$; $1 \le x, y \le n$; $x \ne y$) — the length of the street, the position of the first policeman and the position of the second policeman, respectively.

It is guaranteed that the sum of $n$ does not exceed $10^6$ ($\sum n \le 10^6$).

## Output

For each test case, print one integer — the minimum number of minutes the policemen need to visit each point of the street.

## Example

## Input


```

6
4 1 2
7 7 1
10 2 6
8 5 2
2 1 2
20 4 14

```
## Output


```

2
3
5
4
0
12

```


#### tags 

#1900 #*special #binary_search #brute_force #math 