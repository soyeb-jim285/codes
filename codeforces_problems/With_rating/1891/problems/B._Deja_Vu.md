<h1 style='text-align: center;'> B. Deja Vu</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ of length $n$, consisting of positive integers, and an array $x$ of length $q$, also consisting of positive integers.

There are $q$ modification. On the $i$-th modification ($1 \leq i \leq q$), for each $j$ ($1 \leq j \leq n$), such that $a_j$ is divisible by $2^{x_i}$, you add $2^{x_i-1}$ to $a_j$. 
## Note

 that $x_i$ ($1 \leq x_i \leq 30$) is a positive integer not exceeding 30.

After all modification queries, you need to output the final array.

### Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers $n$ and $q$ ($1 \leq n, q \leq 10^5$) —the length of the array $a$ and the number of queries respectively.

The second line of each test case contains $n$ integers $a_1, a_2, a_3, \ldots, a_n$ — the elements of the array $a$ ($1 \leq a_i \leq 10^9$).

The third line of each test case contains $q$ integers $x_1, x_2, x_3, \ldots, x_q$ — the elements of the array $x$ ($1 \leq x_i \leq 30$), which are the modification queries.

It is guaranteed that the sum of $n$ and the sum of $q$ across all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output the array after all of the modification queries.

## Example

### Input


```text
45 31 2 3 4 42 3 47 37 8 12 36 48 6 310 4 25 42 2 2 2 21 1 1 15 51 2 4 8 165 2 3 4 1
```
### Output

```text

1 2 3 6 6 
7 10 14 38 58 6 3 
3 3 3 3 3 
1 3 7 11 19 

```
## Note

In the first test case, the first query will add $2$ to the integers in positions $4$ and $5$. After this addition, the array would be $[1, 2, 3, 6, 6]$. Other operations will not modify the array.

In the second test case, the first modification query does not change the array. The second modification query will add $8$ to the integer in position $5$, so that the array would look like this: $[7, 8, 12, 36, 56, 6, 3]$. The third modification query will add $2$ to the integers in positions $2, 3$, $4$ and $5$. The array would then look like this: $[7, 10, 14, 38, 58, 6, 3]$.



#### Tags 

#1100 #NOT OK #brute_force #math #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_907_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Editorial](../blogs/Editorial.md)
