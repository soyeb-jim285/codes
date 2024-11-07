<h1 style='text-align: center;'> F. Vasilije Loves Number Theory</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasilije is a smart student and his discrete mathematics teacher Sonja taught him number theory very well.

He gave Ognjen a positive integer $n$.

Denote $d(n)$ as the number of positive integer divisors of $n$, and denote $gcd(a, b)$ as the largest integer $g$ such that $a$ is divisible by $g$ and $b$ is divisible by $g$.

After that, he gave Ognjen $q$ queries, and there are $2$ types of queries. 

* $1$, $x$ — set $n$ to $n \cdot x$, and then answer the following question: does there exist a positive integer $a$ such that $gcd(a, n) = 1$, and $d(n \cdot a) = n$?
* $2$ — reset $n$ to its initial value (before any queries).

## Note

 that $n$ does not get back to its initial value after the type 1 query.

Since Ognjen is afraid of number theory, Vasilije promised him that after each query, $d(n) \le 10^9$, however, even with that constraint, he still needs your help with this problem.

## Input

The first line contains a positive integer $t$, ($1 \le t \le 100$) — the number of test cases.

The first line of each test case contains $2$ integers, $n$ and $q$ ($1 \le n \le 10^{6}$, $1\le q \le 1000$) — the number $n$ and the number of queries.

The following $q$ lines contain an integer $k$ ($1 \le k \le 2$), if $k=1$ then there is another integer in this line $x$ ($1 \le x \le 10^6$) — the description of the queries.

It is guaranteed that, for the given input, $d(n)$ does not exceed $10^9$ at any point.

It is guaranteed that the sum of $q$ over all test cases doesn't exceed $10^3$.

## Output

For each type 1 query, you should output "YES" if there exist such positive integer $a$ that $gcd(a, n) = 1$ and $d(n \cdot a)=n$, and "NO" if he can't.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as a positive answer).

## Example

## Input


```

71 51 11 221 81 920 41 321 71 1216 101 61 61 101 91 11 91 71 31 21 109 11 38 11 28 31 51 81 1011 51 81 21 11 31 1
```
## Output


```

YES
YES
YES
YES

YES
NO
YES

YES
NO
YES
YES
YES
NO
YES
NO
YES
YES

NO

NO

YES
NO
NO

YES
NO
NO
NO
NO

```
## Note

In the first test case, we initially have $n=1$.

After the first query: $n=1$, $d(n)=1$, so by taking $a = 1$, $d(n \cdot a) = n$, and the answer to this query is "YES".

After the second query: $n=2$, $d(n)=2$, we can, again, take $a = 1$, $d(n \cdot a) = n$, and the answer to this query is "YES".

After the third query $n=1$, and this is a type $2$ query so we don't answer it.

After the fourth query: $n=8$, and by taking $a=3$, $d(n \cdot a) = d(24) = 8 = n$, so the answer is "YES".

After the fifth query: $n=72$, now we can take $a=637$ to get $n \cdot a = 45864$, and $d(n \cdot a) = 72 = n$, so the answer is "YES".

In the second test case, we initially have $n=20$.

After the first query: $n=60$, and the answer is "YES".

After the second query: $n=20$, this is a type $2$ query, so we don't answer it.

After the third query: $n=140$, and it can be proven that no matter which positive integer $a$ we take, $d(n \cdot a)$ will never be equal to $n$, so the answer to this query is "NO".

After the fourth query: $n=1680$. It can be proven that there exists a positive integer $a$, such that $d(n \cdot a) = n$, so the answer is "YES".



#### tags 

#1900 #brute_force #math #number_theory 