<h1 style='text-align: center;'> C. Complementary XOR</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have two binary strings $a$ and $b$ of length $n$. You would like to make all the elements of both strings equal to $0$. Unfortunately, you can modify the contents of these strings using only the following operation:

* You choose two indices $l$ and $r$ ($1 \le l \le r \le n$);
* For every $i$ that respects $l \le i \le r$, change $a_i$ to the opposite. That is, $a_i := 1 - a_i$;
* For every $i$ that respects either $1 \le i < l$ or $r < i \le n$, change $b_i$ to the opposite. That is, $b_i := 1 - b_i$.

Your task is to determine if this is possible, and if it is, to find such an appropriate chain of operations. The number of operations should not exceed $n + 5$. It can be proven that if such chain of operations exists, one exists with at most $n + 5$ operations. 

### Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^5$) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($2 \le n \le 2 \cdot 10^5$) — the length of the strings.

The second line of each test case contains a binary string $a$, consisting only of characters 0 and 1, of length $n$.

The third line of each test case contains a binary string $b$, consisting only of characters 0 and 1, of length $n$.

It is guaranteed that sum of $n$ over all test cases doesn't exceed $2 \cdot 10^5$.

### Output

For each testcase, print first "YES" if it's possible to make all the elements of both strings equal to $0$. Otherwise, print "NO". If the answer is "YES", on the next line print a single integer $k$ ($0 \le k \le n + 5$) — the number of operations. Then $k$ lines follows, each contains two integers $l$ and $r$ ($1 \le l \le r \le n$) — the description of the operation.

If there are several correct answers, print any of them.

## Example

### Input


```text
5301010121110410000011210103111111
```
### Output

```text

YES
1
2 2
NO
NO
YES
2
1 2
2 2
YES
2
1 1
2 3
```
## Note

In the first test case, we can perform one operation with $l = 2$ and $r = 2$. So $a_2 := 1 - 1 = 0$ and string $a$ became equal to 000. $b_1 := 1 - 1 = 0$, $b_3 := 1 - 1 = 0$ and string $b$ became equal to 000.

In the second and in the third test cases, it can be proven that it's impossible to make all elements of both strings equal to $0$.

In the fourth test case, we can perform an operation with $l = 1$ and $r = 2$, then string $a$ became equal to 01, and string $b$ doesn't change. Then we perform an operation with $l = 2$ and $r = 2$, then $a_2 := 1 - 1 = 0$ and $b_1 = 1 - 1 = 0$. So both of string $a$ and $b$ became equal to 00.

In the fifth test case, we can perform an operation with $l = 1$ and $r = 1$. Then string $a$ became equal to 011 and string $b$ became equal to 100. Then we can perform an operation with $l = 2$ and $r = 3$, so both of string $a$ and $b$ became equal to 000.



#### Tags 

#1400 #NOT OK #constructive_algorithms #implementation 

## Blogs
- [All Contest Problems](../CodeTON_Round_3_(Div._1_+_Div._2,_Rated,_Prizes!).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
