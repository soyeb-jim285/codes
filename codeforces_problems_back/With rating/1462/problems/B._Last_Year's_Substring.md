<h1 style='text-align: center;'> B. Last Year's Substring</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarp has a string $s[1 \dots n]$ of length $n$ consisting of decimal digits. Polycarp performs the following operation with the string $s$ no more than once (i.e. he can perform operation $0$ or $1$ time): 

* Polycarp selects two numbers $i$ and $j$ ($1 \leq i \leq j \leq n$) and removes characters from the $s$ string at the positions $i, i+1, i+2, \ldots, j$ (i.e. removes substring $s[i \dots j]$). More formally, Polycarp turns the string $s$ into the string $s_1 s_2 \ldots s_{i-1} s_{j+1} s_{j+2} \ldots s_{n}$.

For example, the string $s = $"20192020" Polycarp can turn into strings: 

* "2020" (in this case $(i, j)=(3, 6)$ or $(i, j)=(1, 4)$);
* "2019220" (in this case $(i, j)=(6, 6)$);
* "020" (in this case $(i, j)=(1, 5)$);
* other operations are also possible, only a few of them are listed above.

Polycarp likes the string "2020" very much, so he is wondering if it is possible to turn the string $s$ into a string "2020" in no more than one operation? ## Note

 that you can perform zero operations.

## Input

The first line contains a positive integer $t$ ($1 \leq t \leq 1000 $) — number of test cases in the test. Then $t$ test cases follow.

The first line of each test case contains an integer $n$ ($4 \leq n \leq 200$) — length of the string $s$. The next line contains a string $s$ of length $n$ consisting of decimal digits. It is allowed that the string $s$ starts with digit 0.

## Output

For each test case, output on a separate line: 

* "YES" if Polycarp can turn the string $s$ into a string "2020" in no more than one operation (i.e. he can perform $0$ or $1$ operation);
* "NO" otherwise.

You may print every letter of "YES" and "NO" in any case you want (so, for example, the strings yEs, yes, Yes and YES will all be recognized as positive answer).

## Example

## Input


```

6
8
20192020
8
22019020
4
2020
5
20002
6
729040
6
200200

```
## Output


```

YES
YES
YES
NO
NO
NO

```
## Note

In the first test case, Polycarp could choose $i=3$ and $j=6$.

In the second test case, Polycarp could choose $i=2$ and $j=5$.

In the third test case, Polycarp did not perform any operations with the string.



#### tags 

#800 #dp #implementation #strings 