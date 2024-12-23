<h1 style='text-align: center;'> B. Fair Numbers</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

We call a positive integer number fair if it is divisible by each of its nonzero digits. For example, $102$ is fair (because it is divisible by $1$ and $2$), but $282$ is not, because it isn't divisible by $8$. Given a positive integer $n$. Find the minimum integer $x$, such that $n \leq x$ and $x$ is fair.

## Input

The first line contains number of test cases $t$ ($1 \leq t \leq 10^3$). Each of the next $t$ lines contains an integer $n$ ($1 \leq n \leq 10^{18}$).

## Output

For each of $t$ test cases print a single integer — the least fair number, which is not less than $n$.

## Example

## Input


```

4
1
282
1234567890
1000000000000000000

```
## Output


```

1
288
1234568040
1000000000000000000

```
## Note

Explanations for some test cases: 

* In the first test case number $1$ is fair itself.
* In the second test case number $288$ is fair (it's divisible by both $2$ and $8$). None of the numbers from $[282, 287]$ is fair, because, for example, none of them is divisible by $8$.


#### tags 

#1000 #brute_force #number_theory 