<h1 style='text-align: center;'> F. Halve or Subtract</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have an array of positive integers $a_1, a_2, \ldots, a_n$, of length $n$. You are also given a positive integer $b$.

You are allowed to perform the following operations (possibly several) times in any order: 

1. Choose some $1 \le i \le n$, and replace $a_i$ with $\lceil \frac{a_i}{2} \rceil$. Here, $\lceil x \rceil$ denotes the smallest integer not less than $x$.
2. Choose some $1 \le i \le n$, and replace $a_i$ with $\max(a_i - b, 0)$.

However, you must also follow these rules: 

* You can perform at most $k_1$ operations of type 1 in total.
* You can perform at most $k_2$ operations of type 2 in total.
* For all $1 \le i \le n$, you can perform at most $1$ operation of type 1 on element $a_i$.
* For all $1 \le i \le n$, you can perform at most $1$ operation of type 2 on element $a_i$.

The cost of an array is the sum of its elements. Find the minimum cost of $a$ you can achieve by performing these operations.

### Input

### Input

 consists of multiple test cases. The first line contains a single integer $t$, the number of test cases ($1 \le t \le 5000$).

The first line of each test case contains $n$, $b$, $k_1$, and $k_2$ ($1 \le n \le 5000$, $1 \le b \le 10^9$, $0 \le k_1, k_2 \le n$).

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ describing the array $a$ ($1 \le a_i \le 10^9$).

It is guaranteed the sum of $n$ over all test cases does not exceed $5000$.

### Output

For each test case, print the minimum cost of $a$ you can achieve by performing the operations.

## Example

### Input


```text
73 2 1 19 3 52 1 2 01000000000 15 3 1 12 8 3 19 36 9 4 21 2 3 4 5 63 10 3 31 2 35 1 0 0999999999 999999999 999999999 999999999 9999999995 5 4 35 9 10 7 4
```
### Output

```text

11
500000001
23
6
0
4999999995
6

```
## Note

In the first test case, you can do the following: 

* Perform operation 2 on element $a_3$. It changes from $5$ to $3$.
* Perform operation 1 on element $a_1$. It changes from $9$ to $5$.

After these operations, the array is $a = [5, 3, 3]$ has a cost $5 + 3 + 3 = 11$. We can show that this is the minimum achievable cost.

In the second test case, note that we are not allowed to perform operation 1 more than once on $a_1$. So it is optimal to apply operation 1 once to each $a_1$ and $a_2$. Alternatively we could apply operation 1 only once to $a_1$, since it has no effect on $a_2$.

In the third test case, here is one way to achieve a cost of $23$: 

* Apply operation 1 to $a_4$. It changes from $19$ to $10$.
* Apply operation 2 to $a_4$. It changes from $10$ to $7$.

After these operations, $a = [2, 8, 3, 7, 3]$. The cost of $a$ is $2 + 8 + 3 + 7 + 3 = 23$. We can show that this is the minimum achievable cost.



#### Tags 

#2700 #NOT OK #binary_search #brute_force #dp #greedy #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_854_by_cybercats_(Div._1_+_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
