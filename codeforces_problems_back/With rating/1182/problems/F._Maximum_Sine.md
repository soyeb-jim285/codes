<h1 style='text-align: center;'> F. Maximum Sine</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have given integers $a$, $b$, $p$, and $q$. Let $f(x) = \text{abs}(\text{sin}(\frac{p}{q} \pi x))$.

Find minimum possible integer $x$ that maximizes $f(x)$ where $a \le x \le b$.

## Input

Each test contains multiple test cases. 

The first line contains the number of test cases $t$ ($1 \le t \le 100$) — the number of test cases.

The first line of each test case contains four integers $a$, $b$, $p$, and $q$ ($0 \le a \le b \le 10^{9}$, $1 \le p$, $q \le 10^{9}$).

## Output

Print the minimum possible integer $x$ for each test cases, separated by newline.

## Example

## Input


```

2
0 3 1 3
17 86 389 995

```
## Output


```

1
55

```
## Note

In the first test case, $f(0) = 0$, $f(1) = f(2) \approx 0.866$, $f(3) = 0$.

In the second test case, $f(55) \approx 0.999969$, which is the largest among all possible values.



#### tags 

#2700 #binary_search #data_structures #number_theory 