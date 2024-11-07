<h1 style='text-align: center;'> A. Flip Flop Sum</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array of $n$ integers $a_1, a_2, \ldots, a_n$. The integers are either $1$ or $-1$. You have to perform the following operation exactly once on the array $a$:

* Choose an index $i$ ($1 \leq i < n$) and flip the signs of $a_i$ and $a_{i+1}$. Here, flipping the sign means $-1$ will be $1$ and $1$ will be $-1$.

What is the maximum possible value of $a_1 + a_2 + \ldots + a_n$ after applying the above operation?

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 500$). Description of the test cases follows.

The first line of each test case contains a single integer $n$ ($2 \le n \le 10^5$), the length of the array $a$.

The next line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($a_i = 1$ or $a_i = -1$).

The sum of $n$ over all cases doesn't exceed $10^5$.

## Output

For each test case, print the maximum possible sum of the array $a$ you can get in a separate line.

## Example

## Input


```

45-1 1 1 -1 -151 1 -1 -1 -121 141 -1 -1 1
```
## Output


```

3
3
-2
4

```
## Note

In the first case, we can choose index $4$ and flip the signs of $a_4$ and $a_5$. After this operation, the sum will be $-1+1+1+1+1 = 3$. We can't make the sum larger than this.

In the third case, the only option is to choose the index $1$.



#### tags 

#800 #greedy #implementation 