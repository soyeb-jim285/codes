<h1 style='text-align: center;'> D. Ehab the Xorcist</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given 2 integers $u$ and $v$, find the shortest array such that [bitwise-xor](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) of its elements is $u$, and the sum of its elements is $v$.

## Input

The only line contains 2 integers $u$ and $v$ $(0 \le u,v \le 10^{18})$.

## Output

If there's no array that satisfies the condition, print "-1". Otherwise:

The first line should contain one integer, $n$, representing the length of the desired array. The next line should contain $n$ positive integers, the array itself. If there are multiple possible answers, print any.

## Examples

## Input


```

2 4

```
## Output


```

2
3 1
```
## Input


```

1 3

```
## Output


```

3
1 1 1
```
## Input


```

8 5

```
## Output


```

-1
```
## Input


```

0 0

```
## Output


```

0
```
## Note

In the first sample, $3\oplus 1 = 2$ and $3 + 1 = 4$. There is no valid array of smaller length.

Notice that in the fourth sample the array is empty.



#### tags 

#1700 #bitmasks #constructive_algorithms #greedy #number_theory 