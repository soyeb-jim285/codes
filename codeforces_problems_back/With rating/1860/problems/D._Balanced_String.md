<h1 style='text-align: center;'> D. Balanced String</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a binary string $s$ (a binary string is a string consisting of characters 0 and/or 1).

Let's call a binary string balanced if the number of subsequences 01 (the number of indices $i$ and $j$ such that $1 \le i < j \le n$, $s_i=0$ and $s_j=1$) equals to the number of subsequences 10 (the number of indices $k$ and $l$ such that $1 \le k < l \le n$, $s_k=1$ and $s_l=0$) in it.

For example, the string 1000110 is balanced, because both the number of subsequences 01 and the number of subsequences 10 are equal to $6$. On the other hand, 11010 is not balanced, because the number of subsequences 01 is $1$, but the number of subsequences 10 is $5$. 

You can perform the following operation any number of times: choose two characters in $s$ and swap them. Your task is to calculate the minimum number of operations to make the string $s$ balanced.

## Input

The only line contains the string $s$ ($3 \le |s| \le 100$) consisting of characters 0 and/or 1. 

Additional constraint on the input: the string $s$ can be made balanced.

## Output

Print a single integer — the minimum number of swap operations to make the string $s$ balanced.

## Examples

## Input


```

101

```
## Output


```

0

```
## Input


```

1000110

```
## Output


```

0

```
## Input


```

11010

```
## Output


```

1

```
## Input


```

11001100

```
## Output


```

2

```
## Note

In the first example, the string is already balanced, the number of both 01 and 10 is equal to $1$.

In the second example, the string is already balanced, the number of both 01 and 10 is equal to $6$.

In the third example, one of the possible answers is the following one: 11010 $\rightarrow$ 01110. After that, the number of both 01 and 10 is equal to $3$.

In the fourth example, one of the possible answers is the following one: 11001100 $\rightarrow$ 11001010 $\rightarrow$ 11000011. After that, the number of both 01 and 10 is equal to $8$.



#### tags 

#2200 #dp 