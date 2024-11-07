<h1 style='text-align: center;'> A. Special Characters</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an integer $n$.

Your task is to build a string of uppercase Latin letters. There must be exactly $n$ special characters in this string. Let's call a character special if it is equal to exactly one of its neighbors.

For example, there are $6$ special characters in the AAABAACC string (at positions: $1$, $3$, $5$, $6$, $7$ and $8$).

Print any suitable string or report that there is no such string.

## Input

The first line contains a single integer $t$ ($1 \le t \le 50$) — the number of test cases.

The only line of each test case contains a single integer $n$ ($1 \le n \le 50$).

## Output

For each test case, print the answer as follows: 

* if there is no suitable string, print one line containing the string NO;
* otherwise, print two lines. The first line should contain the string YES; on the second line print a string of length at most $200$ — the answer itself (it can be shown that if some answers exist, then there is an answer of length at most $200$). If there are several solutions, print any of them.
## Example

## Input


```

3612
```
## Output


```

YES
AAABAACC
NO
YES
MM
```


#### tags 

#800 #brute_force #constructive_algorithms 