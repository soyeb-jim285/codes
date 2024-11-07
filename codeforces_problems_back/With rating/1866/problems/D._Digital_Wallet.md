<h1 style='text-align: center;'> D. Digital Wallet</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

There are $N$ arrays, each array has $M$ positive integer elements The $j$-th element of the $i$-th array is $A_{i,j}$.

Initially, Chaneka's digital wallet contains $0$ money. Given an integer $K$. Chaneka will do $M-K+1$ operations. In the $p$-th operation, Chaneka does the following procedure: 

1. Choose any array. Let's say Chaneka chooses the $x$-th array.
2. Choose an index $y$ in that array such that $p \leq y \leq p+K-1$.
3. Add the value of $A_{x, y}$ to the total money in the wallet.
4. Change the value of $A_{x, y}$ into $0$.

Determine the maximum total money that can be earned!

## Input

The first line contains three integers $N$, $M$, and $K$ ($1 \leq N \leq 10$; $1 \leq M \leq 10^5$; $1 \leq K \leq \min(10, M)$) — the number of arrays, the size of each array, and the constant that describes the operation constraints.

The $i$-th of the next $N$ lines contains $M$ integers $A_{i,1}, A_{i,2}, \ldots, A_{i,M}$ ($1 \leq A_{i,j} \leq 10^6$) — the elements of the $i$-th array.

## Output

## Output

 an integer representing the maximum total money that can be earned.

## Examples

## Input


```

3 3 1
10 4 2
8 1 9
4 8 2

```
## Output


```

27

```
## Input


```

3 3 2
5 9 4
1 3 1
2 8 7

```
## Output


```

17

```
## Input


```

3 4 3
5 9 10 1
1 3 1 5
2 5 7 2

```
## Output


```

19

```
## Note

In the first example, the following is a sequence of operations of one optimal strategy:

1. Choosing element $A_{1, 1}$ with a value of $10$.
2. Choosing element $A_{3, 2}$ with a value of $8$.
3. Choosing element $A_{2, 3}$ with a value of $9$.

So the total money earned is $10+8+9=27$.

In the second example, the following is a sequence of operations of one optimal strategy:

1. Choosing element $A_{3, 2}$ with a value of $8$.
2. Choosing element $A_{1, 2}$ with a value of $9$.

So the total money earned is $8+9=17$.

In the third example, the following is a sequence of operations of one optimal strategy:

1. Choosing element $A_{1, 3}$ with a value of $10$.
2. Choosing element $A_{1, 2}$ with a value of $9$.

So the total money earned is $10+9=19$.



#### tags 

#2300 #dp #greedy 