<h1 style='text-align: center;'> A. Sum</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given three integers $a$, $b$, and $c$. Determine if one of them is the sum of the other two.

## Input

The first line contains a single integer $t$ ($1 \leq t \leq 9261$) — the number of test cases.

The description of each test case consists of three integers $a$, $b$, $c$ ($0 \leq a, b, c \leq 20$).

## Output

For each test case, output "YES" if one of the numbers is the sum of the other two, and "NO" otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).

## Example

## Input


```

71 4 32 5 89 11 200 0 020 20 204 12 315 7 8
```
## Output


```

YES
NO
YES
YES
NO
NO
YES

```
## Note

In the first test case, $1 + 3 = 4$.

In the second test case, none of the numbers is the sum of the other two.

In the third test case, $9 + 11 = 20$.



#### tags 

#800 #implementation 