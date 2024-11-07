<h1 style='text-align: center;'> F. Burenka, an Array and Queries</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Eugene got Burenka an array $a$ of length $n$ of integers from $1$ to $m$ for her birthday. Burenka knows that Eugene really likes coprime integers (integers $x$ and $y$ such that they have only one common factor (equal to $1$)) so she wants to to ask Eugene $q$ questions about the present. 

Each time Burenka will choose a subsegment $a_l, a_{l + 1}, \ldots, a_r$ of array $a$, and compute the product of these numbers $p = a_l \cdot a_{l + 1} \cdot \ldots \cdot a_r$. Then she will ask Eugene to count the number of integers between $1$ and $C$ inclusive which are coprime with $p$. 

Help Eugene answer all the questions!

## Input

In the first line of input there are four integers $n$, $m$, $C$, $q$ ($1 \leq n, q \leq 10^5$, $1 \leq m \leq 2\cdot 10^4$, $1 \leq C \leq 10^5$) — the length of the array $a$, the maximum possible value of $a_{i}$, the value $C$, and the number of queries.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_{i} \leq m$) — the array $a$ .

In the next $q$ lines the queries are given. Each query consists of two integers $l$ and $r$ ($1 \leq l \leq r \leq n$).

## Output

Print $q$ integers — the answers to Burenka's queries.

## Example

## Input


```

5 5 5 3
1 2 3 2 5
1 1
2 4
4 5

```
## Output


```

5
2
2

```
## Note

Here's an explanation for the example:

1. in the first query, the product is equal to $1$, which is coprime with $1,2,3,4,5$.
2. in the second query, the product is equal to $12$, which is coprime with $1$ and $5$.
3. in the third query, the product is equal to $10$, which is coprime with $1$ and $3$.


#### tags 

#3300 #data_structures #math #number_theory 