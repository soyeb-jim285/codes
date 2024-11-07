<h1 style='text-align: center;'> D. XOR Construction</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given $n-1$ integers $a_1, a_2, \dots, a_{n-1}$.

Your task is to construct an array $b_1, b_2, \dots, b_n$ such that:

* every integer from $0$ to $n-1$ appears in $b$ exactly once;
* for every $i$ from $1$ to $n-1$, $b_i \oplus b_{i+1} = a_i$ (where $\oplus$ denotes the bitwise XOR operator).
## Input

The first line contains one integer $n$ ($2 \le n \le 2 \cdot 10^5$).

The second line contains $n-1$ integers $a_1, a_2, \dots, a_{n-1}$ ($0 \le a_i \le 2n$).

Additional constraint on the input: it's always possible to construct at least one valid array $b$ from the given sequence $a$.

## Output

Print $n$ integers $b_1, b_2, \dots, b_n$. If there are multiple such arrays, you may print any of them.

## Examples

## Input


```

42 1 2
```
## Output


```

0 2 3 1 
```
## Input


```

61 6 1 4 1
```
## Output


```

2 3 5 4 0 1 
```


#### tags 

#1900 #bitmasks #constructive_algorithms #data_structures #math #string_suffix_structures #trees 