<h1 style='text-align: center;'> C. Strongly Composite</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A prime number is an integer greater than $1$, which has exactly two divisors. For example, $7$ is a prime, since it has two divisors $\{1, 7\}$. A composite number is an integer greater than $1$, which has more than two different divisors.

## Note

 that the integer $1$ is neither prime nor composite.

Let's look at some composite number $v$. It has several divisors: some divisors are prime, others are composite themselves. If the number of prime divisors of $v$ is less or equal to the number of composite divisors, let's name $v$ as strongly composite.

For example, number $12$ has $6$ divisors: $\{1, 2, 3, 4, 6, 12\}$, two divisors $2$ and $3$ are prime, while three divisors $4$, $6$ and $12$ are composite. So, $12$ is strongly composite. Other examples of strongly composite numbers are $4$, $8$, $9$, $16$ and so on.

On the other side, divisors of $15$ are $\{1, 3, 5, 15\}$: $3$ and $5$ are prime, $15$ is composite. So, $15$ is not a strongly composite. Other examples are: $2$, $3$, $5$, $6$, $7$, $10$ and so on.

You are given $n$ integers $a_1, a_2, \dots, a_n$ ($a_i > 1$). You have to build an array $b_1, b_2, \dots, b_k$ such that following conditions are satisfied: 

* Product of all elements of array $a$ is equal to product of all elements of array $b$: $a_1 \cdot a_2 \cdot \ldots \cdot a_n = b_1 \cdot b_2 \cdot \ldots \cdot b_k$;
* All elements of array $b$ are integers greater than $1$ and strongly composite;
* The size $k$ of array $b$ is the maximum possible.

Find the size $k$ of array $b$, or report, that there is no array $b$ satisfying the conditions.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 1000$). The description of the test cases follows.

The first line of each test case contains one integer $n$ ($1 \le n \le 1000$) — the size of the array $a$.

The second line of each test case contains $n$ integer $a_1, a_2, \dots a_n$ ($2 \le a_i \le 10^7$) — the array $a$ itself.

It is guaranteed that the sum of $n$ over all test cases does not exceed $1000$.

## Output

For each test case, print the size $k$ of array $b$, or $0$, if there is no array $b$ satisfying the conditions.

## Example

## Input


```

823 633 4 522 333 10 14225 301108093 3 3 5 5 5 7 7 72012 15 2 2 2 2 2 3 3 3 17 21 21 21 30 6 6 33 31 39
```
## Output


```

1
1
0
2
2
3
4
15

```
## Note

In the first test case, we can get array $b = [18]$: $a_1 \cdot a_2 = 18 = b_1$; $18$ is strongly composite number.

In the second test case, we can get array $b = [60]$: $a_1 \cdot a_2 \cdot a_3 = 60 = b_1$; $60$ is strongly composite number.

In the third test case, there is no array $b$ satisfying the conditions.

In the fourth test case, we can get array $b = [4, 105]$: $a_1 \cdot a_2 \cdot a_3 = 420 = b_1 \cdot b_2$; $4$ and $105$ are strongly composite numbers.



#### tags 

#1300 #greedy #math #number_theory 