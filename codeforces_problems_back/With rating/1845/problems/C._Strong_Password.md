<h1 style='text-align: center;'> C. Strong Password</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp finally got the courage to register on ForceCoders. He came up with a handle but is still thinking about the password.

He wants his password to be as strong as possible, so he came up with the following criteria: 

* the length of the password should be exactly $m$;
* the password should only consist of digits from $0$ to $9$;
* the password should not appear in the password database (given as a string $s$) as a subsequence (not necessarily contiguous).

Monocarp also came up with two strings of length $m$: $l$ and $r$, both consisting only of digits from $0$ to $9$. He wants the $i$-th digit of his password to be between $l_i$ and $r_i$, inclusive.

Does there exist a password that fits all criteria?

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of testcases.

The first line of each testcase contains a string $s$ ($1 \le |s| \le 3 \cdot 10^5$), consisting only of digits from $0$ to $9$ — the password database.

The second line contains a single integer $m$ ($1 \le m \le 10$) — the required length of the password.

The third line contains a string $l$ ($|l| = m$), consisting only of digits from $0$ to $9$ — the lower restriction on each digit.

The fourth line contains a string $r$ ($|r| = m$), consisting only of digits from $0$ to $9$ — the upper restriction on each digit. $l_i \le r_i$ for all $i$ from $1$ to $m$.

The sum of lengths of $s$ over all testcases doesn't exceed $3 \cdot 10^5$.

## Output

For each testcase, print "YES" if there exists a password that fits all criteria. Print "NO" otherwise.

## Example

## Input


```

5880055535351234562505612341234123431114441234443214321459249590001021011
```
## Output


```

YES
NO
YES
NO
YES

```
## Note

In the first testcase, Monocarp can choose password "50". It doesn't appear in $s$ as a subsequence.

In the second testcase, all combinations of three digits, each of them being from $1$ to $4$, fit the criteria on $l$ and $r$. However, all of them appear in $s$ as subsequences. For example, "314" appears at positions $[3, 5, 12]$ and "222" appears at positions $[2, 6, 10]$.

In the third testcase, Monocarp can choose password "4321". Actually, that is the only password that fits the criteria on $l$ and $r$. Luckily, it doesn't appear in $s$ as a subsequence.

In the fourth testcase, only "49" and "59" fit the criteria on $l$ and $r$. Both of them appear in $s$ as subsequences.

In the fifth testcase, Monocarp can choose password "11".



#### tags 

#1400 #binary_search #dp #greedy #strings 