<h1 style='text-align: center;'> H. Xor-quiz</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an interactive problem.

You are given two integers $c$ and $n$. The jury has a randomly generated set $A$ of distinct positive integers not greater than $c$ (it is generated from all such possible sets with equal probability). The size of $A$ is equal to $n$.

Your task is to guess the set $A$. In order to guess it, you can ask at most $\lceil 0.65 \cdot c \rceil$ queries.

In each query, you choose a single integer $1 \le x \le c$. As the answer to this query you will be given the [bitwise xor sum](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) of all $y$, such that $y \in A$ and $gcd(x, y) = 1$ (i.e. $x$ and $y$ are coprime). If there is no such $y$ this xor sum is equal to $0$.

You can ask all queries at the beginning and you will receive the answers to all your queries. After that, you won't have the possibility to ask queries.

You should find any set $A'$, such that $|A'| = n$ and $A'$ and $A$ have the same answers for all $c$ possible queries.

### Input

Firstly you are given two integers $c$ and $n$ ($100 \le c \le 10^6$, $0 \le n \le c$).

## Interaction

In the first line you should print an integer $q$ $(0 \le q \le \lceil 0.65 \cdot c \rceil)$ — the number of queries you want to ask. After that in the same line print $q$ integers $x_1, x_2, \ldots, x_q$ $(1 \le x_i \le c)$ — the queries.

For these queries you should read $q$ integers, $i$-th of them is the answer to the described query for $x = x_i$.

After that you should print $n$ distinct integers $A'_1, A'_2, \ldots, A'_n$ — the set $A'$ you found.

If there are different sets $A'$ that have the same answers for all possible queries, print any of them.

If you will ask more than $\lceil 0.65 \cdot c \rceil$ queries or if the queries will be invalid, the interactor will terminate immediately and your program will receive verdict Wrong Answer.

After printing the queries and answers do not forget to output end of line and flush the output buffer. Otherwise, you will get the Idleness limit exceeded verdict. To do flush use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* Read documentation for other languages.

Hacks

You cannot make hacks in this problem.

## Example

### Input


```text
10 6

1 4 2 11 4 4 4

```
#Output
```text
7 10 2 3 5 7 1 6

1 4 5 6 8 10
```
## Note

The sample is made only for you to understand the interaction protocol. Your solution will not be tested on the sample.

In the sample $A = \{1, 4, 5, 6, 8, 10\}$. $7$ queries are made, $7 \le \lceil 0.65 \cdot 10 \rceil = 7$, so the query limit is not exceeded.

Answers for the queries: 

* For $10$: $1$ is the only number in the set $A$ coprime with $10$, so the answer is $1$
* For $2$: $1_{10} \oplus 5_{10} = 001_2 \oplus 101_2 = 4_{10}$, where $\oplus$ is the bitwise xor
* For $3$: $1_{10} \oplus 4_{10} \oplus 5_{10} \oplus 8_{10} \oplus 10_{10} = 0001_2 \oplus 0100_2 \oplus 0101_2 \oplus 1000_2 \oplus 1010_2 = 2_{10}$
* For $5$: $1_{10} \oplus 4_{10} \oplus 6_{10} \oplus 8_{10} = 0001_2 \oplus 0100_2 \oplus 0110_2 \oplus 1000_2 = 11_{10}$
* For $7$: $1_{10} \oplus 4_{10} \oplus 5_{10} \oplus 6_{10} \oplus 8_{10} \oplus 10_{10} = 0001_2 \oplus 0100_2 \oplus 0101_2 \oplus 0110_2 \oplus 1000_2 \oplus 1010_2 = 4_{10}$
* For $1$: $1_{10} \oplus 4_{10} \oplus 5_{10} \oplus 6_{10} \oplus 8_{10} \oplus 10_{10} = 0001_2 \oplus 0100_2 \oplus 0101_2 \oplus 0110_2 \oplus 1000_2 \oplus 1010_2 = 4_{10}$
* For $6$: $1_{10} \oplus 5_{10} = 0001_2 \oplus 0101_2 = 4_{10}$


#### Tags 

#3200 #NOT OK #constructive_algorithms #dp #interactive #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_16.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
