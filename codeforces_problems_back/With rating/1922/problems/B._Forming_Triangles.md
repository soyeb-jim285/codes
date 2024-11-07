<h1 style='text-align: center;'> B. Forming Triangles</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have $n$ sticks, numbered from $1$ to $n$. The length of the $i$-th stick is $2^{a_i}$.

You want to choose exactly $3$ sticks out of the given $n$ sticks, and form a non-degenerate triangle out of them, using the sticks as the sides of the triangle. A triangle is called non-degenerate if its area is strictly greater than $0$.

You have to calculate the number of ways to choose exactly $3$ sticks so that a triangle can be formed out of them. ## Note

 that the order of choosing sticks does not matter (for example, choosing the $1$-st, $2$-nd and $4$-th stick is the same as choosing the $2$-nd, $4$-th and $1$-st stick). 

## Input

The first line contains one integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

Each test case consists of two lines:

* the first line contains one integer $n$ ($1 \le n \le 3 \cdot 10^5$);
* the second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($0 \le a_i \le n$).

Additional constraint on the input: the sum of $n$ over all test cases does not exceed $3 \cdot 10^5$.

## Output

For each test case, print one integer — the number of ways to choose exactly $3$ sticks so that a triangle can be formed out of them.

## Example

## Input


```

471 1 1 1 1 1 143 2 1 331 2 311
```
## Output


```

35
2
0
0

```
## Note

In the first test case of the example, any three sticks out of the given $7$ can be chosen.

In the second test case of the example, you can choose the $1$-st, $2$-nd and $4$-th stick, or the $1$-st, $3$-rd and $4$-th stick.

In the third test case of the example, you cannot form a triangle out of the given sticks with lengths $2$, $4$ and $8$.



#### tags 

#1200 #combinatorics #constructive_algorithms #math #sortings 