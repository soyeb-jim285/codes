<h1 style='text-align: center;'> F. Ones</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a positive (greater than zero) integer $n$.

You have to represent $n$ as the sum of integers (possibly negative) consisting only of ones (digits '1'). For example, $24 = 11 + 11 + 1 + 1$ and $102 = 111 - 11 + 1 + 1$. 

Among all possible representations, you have to find the one that uses the minimum number of ones in total.

## Input

The single line contains one integer $n$ ($1 \le n < 10^{50}$).

## Output

Print one integer $x$ — the minimum number of ones, such that there exist a representation of $n$ as the sum of integers (possibly negative) that uses $x$ ones in total.

## Examples

## Input


```

24

```
## Output


```

6

```
## Input


```

102

```
## Output


```

7

```


#### tags 

#2900 #dp #greedy #shortest_paths 