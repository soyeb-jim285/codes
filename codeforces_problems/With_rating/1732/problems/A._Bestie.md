<h1 style='text-align: center;'> A. Bestie</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ consisting of $n$ integers $a_1, a_2, \ldots, a_n$. Friends asked you to make the [greatest common divisor (GCD)](https://en.wikipedia.org/wiki/Greatest_common_divisor) of all numbers in the array equal to $1$. In one operation, you can do the following:

* Select an arbitrary index in the array $1 \leq i \leq n$;
* Make $a_i = \gcd(a_i, i)$, where $\gcd(x, y)$ denotes the GCD of integers $x$ and $y$. The cost of such an operation is $n - i + 1$.

You need to find the minimum total cost of operations we need to perform so that the GCD of the all array numbers becomes equal to $1$.

### Input

Each test consists of multiple test cases. The first line contains an integer $t$ ($1 \leq t \leq 5\,000$) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 20$) — the length of the array.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq 10^9$) — the elements of the array.

### Output

For each test case, output a single integer — the minimum total cost of operations that will need to be performed so that the GCD of all numbers in the array becomes equal to $1$.

We can show that it's always possible to do so.

## Example

### Input


```text
9111222 433 6 945 10 15 205120 60 80 40 806150 90 180 120 60 3062 4 6 9 12 18630 60 90 120 125 125
```
### Output

```text

0
1
2
2
1
3
3
0
1

```
## Note

In the first test case, the GCD of the entire array is already equal to $1$, so there is no need to perform operations.

In the second test case, select $i = 1$. After this operation, $a_1 = \gcd(2, 1) = 1$. The cost of this operation is $1$.

In the third test case, you can select $i = 1$, after that the array $a$ will be equal to $[1, 4]$. The GCD of this array is $1$, and the total cost is $2$.

In the fourth test case, you can select $i = 2$, after that the array $a$ will be equal to $[3, 2, 9]$. The GCD of this array is $1$, and the total cost is $2$.

In the sixth test case, you can select $i = 4$ and $i = 5$, after that the array $a$ will be equal to $[120, 60, 80, 4, 5]$. The GCD of this array is $1$, and the total cost is $3$.



#### Tags 

#1000 #OK #brute_force #combinatorics #constructive_algorithms #implementation #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_830_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
