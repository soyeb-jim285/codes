<h1 style='text-align: center;'> E. Boxes and Balls</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are $n$ boxes placed in a line. The boxes are numbered from $1$ to $n$. Some boxes contain one ball inside of them, the rest are empty. At least one box contains a ball and at least one box is empty.

In one move, you have to choose a box with a ball inside and an adjacent empty box and move the ball from one box into another. Boxes $i$ and $i+1$ for all $i$ from $1$ to $n-1$ are considered adjacent to each other. Boxes $1$ and $n$ are not adjacent.

How many different arrangements of balls exist after exactly $k$ moves are performed? Two arrangements are considered different if there is at least one such box that it contains a ball in one of them and doesn't contain a ball in the other one.

Since the answer might be pretty large, print its remainder modulo $10^9+7$.

## Input

The first line contains two integers $n$ and $k$ ($2 \le n \le 1500$; $1 \le k \le 1500$) — the number of boxes and the number of moves.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($a_i \in \{0, 1\}$) — $0$ denotes an empty box and $1$ denotes a box with a ball inside. There is at least one $0$ and at least one $1$.

## Output

Print a single integer — the number of different arrangements of balls that can exist after exactly $k$ moves are performed, modulo $10^9+7$.

## Examples

## Input


```

4 1
1 0 1 0

```
## Output


```

3

```
## Input


```

4 2
1 0 1 0

```
## Output


```

2

```
## Input


```

10 6
1 0 0 1 0 0 0 1 1 1

```
## Output


```

69

```
## Note

In the first example, there are the following possible arrangements: 

* 0 1 1 0 — obtained after moving the ball from box $1$ to box $2$;
* 1 0 0 1 — obtained after moving the ball from box $3$ to box $4$;
* 1 1 0 0 — obtained after moving the ball from box $3$ to box $2$.

In the second example, there are the following possible arrangements: 

* 1 0 1 0 — three ways to obtain that: just reverse the operation performed during the first move;
* 0 1 0 1 — obtained from either of the first two arrangements after the first move.


#### tags 

#2500 #dp #implementation #math 