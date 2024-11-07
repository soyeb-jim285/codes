<h1 style='text-align: center;'> D. Ball Sorting</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are $n$ colorful balls arranged in a row. The balls are painted in $n$ distinct colors, denoted by numbers from $1$ to $n$. The $i$-th ball from the left is painted in color $c_i$. You want to reorder the balls so that the $i$-th ball from the left has color $i$. Additionally, you have $k \ge 1$ balls of color $0$ that you can use in the reordering process.

Due to the strange properties of the balls, they can be reordered only by performing the following operations:

1. Place a ball of color $0$ anywhere in the sequence (between any two consecutive balls, before the leftmost ball or after the rightmost ball) while keeping the relative order of other balls. You can perform this operation no more than $k$ times, because you have only $k$ balls of color $0$.
2. Choose any ball of non-zero color such that at least one of the balls adjacent to him has color $0$, and move that ball (of non-zero color) anywhere in the sequence (between any two consecutive balls, before the leftmost ball or after the rightmost ball) while keeping the relative order of other balls. You can perform this operation as many times as you want, but for each operation you should pay $1$ coin.

 You can perform these operations in any order. After the last operation, all balls of color $0$ magically disappear, leaving a sequence of $n$ balls of non-zero colors.

What is the minimum amount of coins you should spend on the operations of the second type, so that the $i$-th ball from the left has color $i$ for all $i$ from $1$ to $n$ after the disappearance of all balls of color zero? It can be shown that under the constraints of the problem, it is always possible to reorder the balls in the required way. 

Solve the problem for all $k$ from $1$ to $n$.

## Input

The first line contains integer $t$ ($1 \le t \le 500$) — the number of test cases. The descriptions of the test cases follow.

The first line contains one integer $n$ ($1 \le n \le 500$) — the number of balls.

The second line contains $n$ distinct integers $c_1, c_2, \ldots, c_n$ ($1 \le c_i \le n$) — the colors of balls from left to right.

It is guaranteed that sum of $n$ over all test cases doesn't exceed $500$.

## Output

For each test case, output $n$ integers: the $i$-th ($1 \le i \le n$) of them should be equal to the minimum amount of coins you need to spend in order to reorder balls in the required way for $k = i$.

## Example

## Input


```

362 3 1 4 6 531 2 3117 3 4 6 8 9 10 2 5 11 1
```
## Output


```

3 2 2 2 2 2 
0 0 0 
10 5 4 4 4 4 4 4 4 4 4 

```
## Note

In the first test case there are $n = 6$ balls. The colors of the balls from left to right are $[\, 2, 3, 1, 4, 6, 5 \,]$. 

Let's suppose $k = 1$. One of the ways to reorder the balls in the required way for $3$ coins:

$[\, 2, 3, 1, 4, 6, 5 \,]$ $\xrightarrow{\, 1 \,}$ $[\, 2, 3, 1, 4, \color{red}{0}, 6, 5 \,]$ $\xrightarrow{\, 2 \,}$ $[\, 2, 3, \color{blue}{4}, 1, 0, 6, 5 \,]$ $\xrightarrow{\, 2 \,}$ $[\, \color{blue}{1}, 2, 3, 4, 0, 6, 5 \,]$ $\xrightarrow{\, 2\,}$ $[\, 1, 2, 3, 4, 0, 5, \color{blue}{6} \,]$

The number above the arrow is the operation type. Balls inserted on the operations of the first type are highlighted red; balls moved on the operations of second type are highlighted blue.

It can be shown that for $k = 1$ it is impossible to rearrange balls in correct order for less than $3$ coins. 

Let's suppose $k = 2$. One of the ways to reorder the balls in the required way for $2$ coins:

$[\, 2, 3, 1, 4, 6, 5 \,]$ $\xrightarrow{\, 1 \,}$ $[\, 2, 3, 1, 4, 6, \color{red}{0}, 5\,]$ $\xrightarrow{\, 2 \,}$ $[\, 2, 3, 1, 4, 0, 5, \color{blue}{6}\,]$ $\xrightarrow{\, 1 \,}$ $[\, 2, 3, \color{red}{0}, 1, 4, 0, 5, 6 \,]$ $\xrightarrow{\, 2 \,}$ $[\, \color{blue}{1}, 2, 3, 0, 4, 0, 5, 6\,]$

## Note

 that this sequence of operations is also correct for $k$ greater than $2$.

It can be shown that for $k$ from $2$ to $6$ it is impossible to rearrange balls in correct order for less than $2$ coins.

In the second test case the balls are already placed in the correct order, so answers for all $k$ are equal to $0$.



#### tags 

#2100 #data_structures #dp #sortings 