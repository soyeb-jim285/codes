<h1 style='text-align: center;'> D. Array and Operations</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given an array $a$ of $n$ integers, and another integer $k$ such that $2k \le n$.

You have to perform exactly $k$ operations with this array. In one operation, you have to choose two elements of the array (let them be $a_i$ and $a_j$; they can be equal or different, but their positions in the array must not be the same), remove them from the array, and add $\lfloor \frac{a_i}{a_j} \rfloor$ to your score, where $\lfloor \frac{x}{y} \rfloor$ is the maximum integer not exceeding $\frac{x}{y}$.

Initially, your score is $0$. After you perform exactly $k$ operations, you add all the remaining elements of the array to the score.

Calculate the minimum possible score you can get.

## Input

The first line of the input contains one integer $t$ ($1 \le t \le 500$) — the number of test cases.

Each test case consists of two lines. The first line contains two integers $n$ and $k$ ($1 \le n \le 100$; $0 \le k \le \lfloor \frac{n}{2} \rfloor$).

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 2 \cdot 10^5$).

## Output

Print one integer — the minimum possible score you can get.

## Example

## Input


```

5
7 3
1 1 1 2 1 3 1
5 1
5 5 5 5 5
4 2
1 3 3 7
2 0
4 2
9 2
1 10 10 1 10 2 7 10 3

```
## Output


```

2
16
0
6
16

```
## Note

Let's consider the example test.

In the first test case, one way to obtain a score of $2$ is the following one:

1. choose $a_7 = 1$ and $a_4 = 2$ for the operation; the score becomes $0 + \lfloor \frac{1}{2} \rfloor = 0$, the array becomes $[1, 1, 1, 1, 3]$;
2. choose $a_1 = 1$ and $a_5 = 3$ for the operation; the score becomes $0 + \lfloor \frac{1}{3} \rfloor = 0$, the array becomes $[1, 1, 1]$;
3. choose $a_1 = 1$ and $a_2 = 1$ for the operation; the score becomes $0 + \lfloor \frac{1}{1} \rfloor = 1$, the array becomes $[1]$;
4. add the remaining element $1$ to the score, so the resulting score is $2$.

In the second test case, no matter which operations you choose, the resulting score is $16$.

In the third test case, one way to obtain a score of $0$ is the following one:

1. choose $a_1 = 1$ and $a_2 = 3$ for the operation; the score becomes $0 + \lfloor \frac{1}{3} \rfloor = 0$, the array becomes $[3, 7]$;
2. choose $a_1 = 3$ and $a_2 = 7$ for the operation; the score becomes $0 + \lfloor \frac{3}{7} \rfloor = 0$, the array becomes empty;
3. the array is empty, so the score doesn't change anymore.

In the fourth test case, no operations can be performed, so the score is the sum of the elements of the array: $4 + 2 = 6$.



#### tags 

#1300 #dp #greedy #math 