<h1 style='text-align: center;'> B. Different String</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string $s$ consisting of lowercase English letters.

Rearrange the characters of $s$ to form a new string $r$ that is not equal to $s$, or report that it's impossible.

## Input

The first line contains a single integer $t$ ($1 \leq t \leq 1000$) — the number of test cases.

The only line of each test case contains a string $s$ of length at most $10$ consisting of lowercase English letters.

## Output

For each test case, if no such string $r$ exists as described in the statement, output "NO" (without quotes).

Otherwise, output "YES" (without quotes). Then, output one line — the string $r$, consisting of letters of string $s$.

You can output "YES" and "NO" in any case (for example, strings "yEs", "yes", and "Yes" will be recognized as a positive response).

If multiple answers are possible, you can output any of them.

## Example

## Input


```

8codeforcesaaaaaxxxxycodnutdealermwisththhhhhhhhhh
```
## Output


```

YES
forcodesec
NO
YES
xxyxx
YES
oc
NO
YES
undertale
YES
thtsiwm
NO

```
## Note

In the first test case, another possible answer is $\texttt{forcescode}$.

In the second test case, all rearrangements of $\texttt{aaaaa}$ are equal to $\texttt{aaaaa}$.



#### tags 

#800 #implementation #strings 