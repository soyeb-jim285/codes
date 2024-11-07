<h1 style='text-align: center;'> G. D-Function</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let $D(n)$ represent the sum of digits of $n$. For how many integers $n$ where $10^{l} \leq n < 10^{r}$ satisfy $D(k \cdot n) = k \cdot D(n)$? ## Output

 the answer modulo $10^9+7$.

## Input

The first line contains an integer $t$ ($1 \leq t \leq 10^4$) – the number of test cases. 

Each test case contains three integers $l$, $r$, and $k$ ($0 \leq l < r \leq 10^9$, $1 \leq k \leq 10^9$).

## Output

For each test case, output an integer, the answer, modulo $10^9 + 7$.

## Example

## Input


```

60 1 40 2 71 2 11 2 3582 74663 30 3 1
```
## Output


```

2
3
90
12
974995667
999

```
## Note

For the first test case, the only values of $n$ that satisfy the condition are $1$ and $2$.

For the second test case, the only values of $n$ that satisfy the condition are $1$, $10$, and $11$.

For the third test case, all values of $n$ between $10$ inclusive and $100$ exclusive satisfy the condition.



#### tags 

#1600 #combinatorics #math #number_theory 