<h1 style='text-align: center;'> I. Tenzing and Necklace</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

bright, sunny and innocent......Tenzing has a beautiful necklace. The necklace consists of $n$ pearls numbered from $1$ to $n$ with a string connecting pearls $i$ and $(i \text{ mod } n)+1$ for all $1 \leq i \leq n$.

One day Tenzing wants to cut the necklace into several parts by cutting some strings. But for each connected part of the necklace, there should not be more than $k$ pearls. The time needed to cut each string may not be the same. Tenzing needs to spend $a_i$ minutes cutting the string between pearls $i$ and $(i \text{ mod } n)+1$.

Tenzing wants to know the minimum time in minutes to cut the necklace such that each connected part will not have more than $k$ pearls.

## Input

Each test contains multiple test cases. The first line of input contains a single integer $t$ ($1 \le t \le 10^5$) — the number of test cases. The description of test cases follows.

The first line of each test case contains two integers $n$ and $k$ ($2\leq n\leq 5\cdot 10^5$, $1\leq k <n$).

The second line of each test case contains $n$ integers $a_1,a_2,\ldots,a_n$ ($1\leq a_i\leq 10^9$).

It is guaranteed that the sum of $n$ of all test cases does not exceed $5 \cdot 10^5$.

## Output

For each test case, output the minimum total time in minutes required.

## Example

## Input


```

45 21 1 1 1 15 21 2 3 4 56 34 2 5 1 3 310 32 5 6 5 2 1 7 9 7 2
```
## Output


```

3
7
5
15

```
## Note

In the first test case, the necklace will be cut into $3$ parts: $[1,2][3,4][5]$, so the total time is $3$.

In the second test case, the necklace will be cut into $3$ parts: $[5,1][2][3,4]$, Tenzing will cut the strings connecting $(1,2), (2,3)$ and $(4,5)$, so the total time is $a_1+a_2+a_4=7$.



#### tags 

#3500 #divide_and_conquer #dp #greedy 