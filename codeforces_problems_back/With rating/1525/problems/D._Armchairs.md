<h1 style='text-align: center;'> D. Armchairs</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

There are $n$ armchairs, numbered from $1$ to $n$ from left to right. Some armchairs are occupied by people (at most one person per armchair), others are not. The number of occupied armchairs is not greater than $\frac{n}{2}$.

For some reason, you would like to tell people to move from their armchairs to some other ones. If the $i$-th armchair is occupied by someone and the $j$-th armchair is not, you can tell the person sitting in the $i$-th armchair to move to the $j$-th armchair. The time it takes a person to move from the $i$-th armchair to the $j$-th one is $|i - j|$ minutes. You may perform this operation any number of times, but these operations must be done sequentially, i. e. you cannot tell a person to move until the person you asked to move in the last operation has finished moving to their destination armchair.

You want to achieve the following situation: every seat that was initially occupied must be free. What is the minimum time you need to do it?

## Input

The first line contains one integer $n$ ($2 \le n \le 5000$) — the number of armchairs.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($0 \le a_i \le 1$). $a_i = 1$ means that the $i$-th armchair is initially occupied, $a_i = 0$ means that it is initially free. The number of occupied armchairs is at most $\frac{n}{2}$.

## Output

Print one integer — the minimum number of minutes you have to spend to achieve the following situation: every seat that was initially occupied must be free.

## Examples

## Input


```

7
1 0 0 1 0 0 1

```
## Output


```

3

```
## Input


```

6
1 1 1 0 0 0

```
## Output


```

9

```
## Input


```

5
0 0 0 0 0

```
## Output


```

0

```
## Note

In the first test, you can perform the following sequence:

1. ask a person to move from armchair $1$ to armchair $2$, it takes $1$ minute;
2. ask a person to move from armchair $7$ to armchair $6$, it takes $1$ minute;
3. ask a person to move from armchair $4$ to armchair $5$, it takes $1$ minute.

In the second test, you can perform the following sequence:

1. ask a person to move from armchair $1$ to armchair $4$, it takes $3$ minutes;
2. ask a person to move from armchair $2$ to armchair $6$, it takes $4$ minutes;
3. ask a person to move from armchair $4$ to armchair $5$, it takes $1$ minute;
4. ask a person to move from armchair $3$ to armchair $4$, it takes $1$ minute.

In the third test, no seat is occupied so your goal is achieved instantly.



#### tags 

#1800 #dp #flows #graph_matchings #greedy 