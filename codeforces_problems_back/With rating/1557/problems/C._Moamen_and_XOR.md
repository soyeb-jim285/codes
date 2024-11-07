<h1 style='text-align: center;'> C. Moamen and XOR</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Moamen and Ezzat are playing a game. They create an array $a$ of $n$ non-negative integers where every element is less than $2^k$.

Moamen wins if $a_1 \,\\&\, a_2 \,\\&\, a_3 \,\\&\, \ldots \,\\&\, a_n \ge a_1 \oplus a_2 \oplus a_3 \oplus \ldots \oplus a_n$.

Here $\\&$ denotes the [bitwise AND operation](https://en.wikipedia.org/wiki/Bitwise_operation#AND), and $\oplus$ denotes the [bitwise XOR operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR).

Please calculate the number of winning for Moamen arrays $a$.

As the result may be very large, print the value modulo $1\,000\,000\,007$ ($10^9 + 7$).

## Input

The first line contains a single integer $t$ ($1 \le t \le 5$)— the number of test cases. 

Each test case consists of one line containing two integers $n$ and $k$ ($1 \le n\le 2\cdot 10^5$, $0 \le k \le 2\cdot 10^5$).

## Output

For each test case, print a single value — the number of different arrays that Moamen wins with.

Print the result modulo $1\,000\,000\,007$ ($10^9 + 7$).

## Example

## Input


```

3
3 1
2 1
4 0

```
## Output


```

5
2
1

```
## Note

In the first example, $n = 3$, $k = 1$. As a result, all the possible arrays are $[0,0,0]$, $[0,0,1]$, $[0,1,0]$, $[1,0,0]$, $[1,1,0]$, $[0,1,1]$, $[1,0,1]$, and $[1,1,1]$.

Moamen wins in only $5$ of them: $[0,0,0]$, $[1,1,0]$, $[0,1,1]$, $[1,0,1]$, and $[1,1,1]$.



#### tags 

#1700 #bitmasks #combinatorics #dp #math #matrices 