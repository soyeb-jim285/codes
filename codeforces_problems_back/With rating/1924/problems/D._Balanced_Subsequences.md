<h1 style='text-align: center;'> D. Balanced Subsequences</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A sequence of brackets is called balanced if one can turn it into a valid math expression by adding characters '+' and '1'. For example, sequences '(())()', '()', and '(()(()))' are balanced, while ')(', '(()', and '(()))(' are not.

A subsequence is a sequence that can be derived from the given sequence by deleting zero or more elements without changing the order of the remaining elements.

You are given three integers $n$, $m$ and $k$. Find the number of sequences consisting of $n$ '(' and $m$ ')', such that the longest balanced subsequence is of length $2 \cdot k$. Since the answer can be large calculate it modulo $1\,000\,000\,007$ ($10^9 + 7$).

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 3 \cdot 10^3$). Description of the test cases follows.

The first line of each test case contains three integers $n$, $m$ and $k$ ($1 \le n, m, k \le 2 \cdot 10^3$)

## Output

For each test case, print one integer — the answer to the problem.

## Example

## Input


```

32 2 23 2 33 2 1
```
## Output


```

2
0
4

```
## Note

For the first test case "()()", "(())" are the $2$ sequences

For the second test case no sequence is possible.

For the third test case ")((()", ")(()(", ")()((", "())((" are the $4$ sequences.



#### tags 

#2700 #combinatorics #dp #math 