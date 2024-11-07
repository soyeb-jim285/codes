<h1 style='text-align: center;'> D. Fixing a Binary String</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a binary string $s$ of length $n$, consisting of zeros and ones. You can perform the following operation exactly once:

1. Choose an integer $p$ ($1 \le p \le n$).
2. Reverse the substring $s_1 s_2 \ldots s_p$. After this step, the string $s_1 s_2 \ldots s_n$ will become $s_p s_{p-1} \ldots s_1 s_{p+1} s_{p+2} \ldots s_n$.
3. Then, perform a cyclic shift of the string $s$ to the left $p$ times. After this step, the initial string $s_1s_2 \ldots s_n$ will become $s_{p+1}s_{p+2} \ldots s_n s_p s_{p-1} \ldots s_1$.

For example, if you apply the operation to the string 110001100110 with $p=3$, after the second step, the string will become 011001100110, and after the third step, it will become 001100110011.

A string $s$ is called $k$-proper if two conditions are met:

* $s_1=s_2=\ldots=s_k$;
* $s_{i+k} \neq s_i$ for any $i$ ($1 \le i \le n - k$).

For example, with $k=3$, the strings 000, 111000111, and 111000 are $k$-proper, while the strings 000000, 001100, and 1110000 are not.

You are given an integer $k$, which is a divisor of $n$. Find an integer $p$ ($1 \le p \le n$) such that after performing the operation, the string $s$ becomes $k$-proper, or determine that it is impossible. ## Note

 that if the string is initially $k$-proper, you still need to apply exactly one operation to it.

## Input

Each test consists of multiple test cases. The first line contains one integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers $n$ and $k$ ($1 \le k \le n$, $2 \le n \le 10^5$) — the length of the string $s$ and the value of $k$. It is guaranteed that $k$ is a divisor of $n$.

The second line of each test case contains a binary string $s$ of length $n$, consisting of the characters 0 and 1.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output a single integer — the value of $p$ to make the string $k$-proper, or $-1$ if it is impossible.

If there are multiple solutions, output any of them.

## Example

## Input


```

78 4111000014 2111012 31110001000115 5000006 11010018 40111000112 2110001100110
```
## Output


```

3
-1
7
5
4
-1
3

```
## Note

In the first test case, if you apply the operation with $p=3$, after the second step of the operation, the string becomes 11100001, and after the third step, it becomes 00001111. This string is $4$-proper.

In the second test case, it can be shown that there is no operation after which the string becomes $2$-proper.

In the third test case, if you apply the operation with $p=7$, after the second step of the operation, the string becomes 100011100011, and after the third step, it becomes 000111000111. This string is $3$-proper.

In the fourth test case, after the operation with any $p$, the string becomes $5$-proper.



#### tags 

#1800 #bitmasks #brute_force #constructive_algorithms #dp #greedy #hashing #strings 