<h1 style='text-align: center;'> E. Split Into Two Sets</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarp was recently given a set of $n$ (number $n$ — even) dominoes. Each domino contains two integers from $1$ to $n$.

Can he divide all the dominoes into two sets so that all the numbers on the dominoes of each set are different? Each domino must go into exactly one of the two sets.

For example, if he has $4$ dominoes: $\{1, 4\}$, $\{1, 3\}$, $\{3, 2\}$ and $\{4, 2\}$, then Polycarp will be able to divide them into two sets in the required way. The first set can include the first and third dominoes ($\{1, 4\}$ and $\{3, 2\}$), and the second set — the second and fourth ones ($\{1, 3\}$ and $\{4, 2\}$).

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The descriptions of the test cases follow.

The first line of each test case contains a single even integer $n$ ($2 \le n \le 2 \cdot 10^5$) — the number of dominoes.

The next $n$ lines contain pairs of numbers $a_i$ and $b_i$ ($1 \le a_i, b_i \le n$) describing the numbers on the $i$-th domino.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case print:

* YES, if it is possible to divide $n$ dominoes into two sets so that the numbers on the dominoes of each set are different;
* NO if this is not possible.

You can print YES and NO in any case (for example, the strings yEs, yes, Yes and YES will be recognized as a positive answer).

## Example

## Input


```

641 24 32 13 461 24 51 34 62 35 621 12 221 22 182 11 24 34 35 65 78 67 881 22 14 35 35 46 78 67 8
```
## Output


```

YES
NO
NO
YES
YES
NO

```
## Note

In the first test case, the dominoes can be divided as follows: 

* First set of dominoes: $[\{1, 2\}, \{4, 3\}]$
* Second set of dominoes: $[\{2, 1\}, \{3, 4\}]$

 In other words, in the first set we take dominoes with numbers $1$ and $2$, and in the second set we take dominoes with numbers $3$ and $4$.In the second test case, there's no way to divide dominoes into $2$ sets, at least one of them will contain repeated number.



#### tags 

#1600 #dfs_and_similar #dsu #graphs 