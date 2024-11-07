<h1 style='text-align: center;'> A. Countdown</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a digital clock with $n$ digits. Each digit shows an integer from $0$ to $9$, so the whole clock shows an integer from $0$ to $10^n-1$. The clock will show leading zeroes if the number is smaller than $10^{n-1}$.

You want the clock to show $0$ with as few operations as possible. In an operation, you can do one of the following: 

* decrease the number on the clock by $1$, or
* swap two digits (you can choose which digits to swap, and they don't have to be adjacent).

Your task is to determine the minimum number of operations needed to make the clock show $0$.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^3$).

The first line of each test case contains a single integer $n$ ($1 \le n \le 100$) — number of digits on the clock.

The second line of each test case contains a string of $n$ digits $s_1, s_2, \ldots, s_n$ ($0 \le s_1, s_2, \ldots, s_n \le 9$) — the number on the clock.

## Note

: If the number is smaller than $10^{n-1}$ the clock will show leading zeroes.

## Output

For each test case, print one integer: the minimum number of operations needed to make the clock show $0$.

## Example

## Input


```

7
3
007
4
1000
5
00000
3
103
4
2020
9
123456789
30
001678294039710047203946100020

```
## Output


```

7
2
0
5
6
53
115

```
## Note

In the first example, it's optimal to just decrease the number $7$ times.

In the second example, we can first swap the first and last position and then decrease the number by $1$.

In the third example, the clock already shows $0$, so we don't have to perform any operations.



#### tags 

#800 #greedy 