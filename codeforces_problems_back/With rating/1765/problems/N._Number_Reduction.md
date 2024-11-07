<h1 style='text-align: center;'> N. Number Reduction</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given a positive integer $x$.

You can apply the following operation to the number: remove one occurrence of any digit in such a way that the resulting number does not contain any leading zeroes and is still a positive integer. For example, $10142$ can be converted to $1142$, $1042$, $1012$ or $1014$ (note that $0142$ is not a valid outcome); $10$ can be converted to $1$ (but not to $0$ since it is not positive).

Your task is to find the minimum positive integer that you can obtain from $x$ if you can apply the aforementioned operation exactly $k$ times.

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^5$) — the number of test cases.

The first line of each test case contains a single integer $x$ ($1 \le x < 10^{500000}$).

The second line contains a single integer $k$ ($0 \le k < |x|$), where $|x|$ is the length of the number $x$.

The sum of $|x|$ over all test cases does not exceed $5 \cdot 10^5$.

## Output

For each test case, print one integer — the minimum positive number that you can obtain from $x$ if you can apply the operation exactly $k$ times.

## Example

## Input


```

510000413370987654321666837494128578086523
```
## Output


```

1
1337
321
344128
7052

```


#### tags 

#1500 #greedy 