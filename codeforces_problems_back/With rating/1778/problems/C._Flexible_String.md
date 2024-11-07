<h1 style='text-align: center;'> C. Flexible String</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have a string $a$ and a string $b$. Both of the strings have length $n$. There are at most $10$ different characters in the string $a$. You also have a set $Q$. Initially, the set $Q$ is empty. You can apply the following operation on the string $a$ any number of times:

* Choose an index $i$ ($1\leq i \leq n$) and a lowercase English letter $c$. Add $a_i$ to the set $Q$ and then replace $a_i$ with $c$.

For example, Let the string $a$ be "$\tt{abecca}$". We can do the following operations: 

* In the first operation, if you choose $i = 3$ and $c = \tt{x}$, the character $a_3 = \tt{e}$ will be added to the set $Q$. So, the set $Q$ will be $\{\tt{e}\}$, and the string $a$ will be "$\tt{ab\underline{x}cca}$".
* In the second operation, if you choose $i = 6$ and $c = \tt{s}$, the character $a_6 = \tt{a}$ will be added to the set $Q$. So, the set $Q$ will be $\{\tt{e}, \tt{a}\}$, and the string $a$ will be "$\tt{abxcc\underline{s}}$".

You can apply any number of operations on $a$, but in the end, the set $Q$ should contain at most $k$ different characters. Under this constraint, you have to maximize the number of integer pairs $(l, r)$ ($1\leq l\leq r \leq n$) such that $a[l,r] = b[l,r]$. Here, $s[l,r]$ means the substring of string $s$ starting at index $l$ (inclusively) and ending at index $r$ (inclusively).

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line contains two integers $n$ and $k$ ($1\leq n \leq 10^5$, $0\leq k\leq 10$) — the length of the two strings and the limit on different characters in the set $Q$. 

The second line contains the string $a$ of length $n$. There is at most $10$ different characters in the string $a$.

The last line contains the string $b$ of length $n$. 

Both of the strings $a$ and $b$ contain only lowercase English letters. The sum of $n$ over all test cases doesn't exceed $10^5$.

## Output

For each test case, print a single integer in a line, the maximum number of pairs $(l, r)$ satisfying the constraints.

## Example

## Input


```

63 1abcabd3 0abcabd3 1xbbxcd4 1abcdaxcb3 10abcabd10 3lkwhbahuqaqoiujoncjb
```
## Output


```

6
3
6
6
6
11

```
## Note

In the first case, we can select index $i = 3$ and replace it with character $c = \tt{d}$. All possible pairs $(l,r)$ will be valid.

In the second case, we can't perform any operation. The $3$ valid pairs $(l,r)$ are: 

1. $a[1,1] = b[1,1] =$ "$\tt{a}$",
2. $a[1,2] = b[1,2] =$ "$\tt{ab}$",
3. $a[2,2] = b[2,2] =$ "$\tt{b}$".

In the third case, we can choose index $2$ and index $3$ and replace them with the characters $\tt{c}$ and $\tt{d}$ respectively. The final set $Q$ will be $\{\tt{b}\}$ having size $1$ that satisfies the value of $k$. All possible pairs $(l,r)$ will be valid.



#### tags 

#1600 #bitmasks #brute_force #strings 