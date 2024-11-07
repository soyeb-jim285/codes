<h1 style='text-align: center;'> C. Beautiful Triple Pairs</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarp was given an array $a$ of $n$ integers. He really likes triples of numbers, so for each $j$ ($1 \le j \le n - 2$) he wrote down a triple of elements $[a_j, a_{j + 1}, a_{j + 2}]$.

Polycarp considers a pair of triples $b$ and $c$ beautiful if they differ in exactly one position, that is, one of the following conditions is satisfied:

* $b_1 \ne c_1$ and $b_2 = c_2$ and $b_3 = c_3$;
* $b_1 = c_1$ and $b_2 \ne c_2$ and $b_3 = c_3$;
* $b_1 = c_1$ and $b_2 = c_2$ and $b_3 \ne c_3$.

Find the number of beautiful pairs of triples among the written triples $[a_j, a_{j + 1}, a_{j + 2}]$.

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($3 \le n \le 2 \cdot 10^5$) — the length of the array $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^6$) — the elements of the array.

It is guaranteed that the sum of the values of $n$ for all test cases in the test does not exceed $2 \cdot 10^5$.

## Output

For each test case, output a single integer — the number of beautiful pairs of triples among the pairs of the form $[a_j, a_{j + 1}, a_{j + 2}]$.

## Note

 that the answer may not fit into 32-bit data types.

## Example

## Input


```

853 2 2 2 351 2 1 2 181 2 3 2 2 3 4 242 1 1 182 1 1 2 1 1 1 172 1 1 1 1 1 162 1 1 1 1 152 1 1 1 1
```
## Output


```

2
0
3
1
8
4
3
2

```
## Note

In the first example, $a = [3, 2, 2, 2, 3]$, Polycarp will write the following triples: 

1. $[3, 2, 2]$;
2. $[2, 2, 2]$;
3. $[2, 2, 3]$.

 The beautiful pairs are triple $1$ with triple $2$ and triple $2$ with triple $3$.In the third example, $a = [1, 2, 3, 2, 2, 3, 4, 2]$, Polycarp will write the following triples: 

1. $[1, 2, 3]$;
2. $[2, 3, 2]$;
3. $[3, 2, 2]$;
4. $[2, 2, 3]$;
5. $[2, 3, 4]$;
6. $[3, 4, 2]$;

 The beautiful pairs are triple $1$ with triple $4$, triple $2$ with triple $5$, and triple $3$ with triple $6$.

#### tags 

#1400 #combinatorics #data_structures 