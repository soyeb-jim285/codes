<h1 style='text-align: center;'> D. Divisible by Twenty-Five</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Mr. Chanek has an integer represented by a string $s$. Zero or more digits have been erased and are denoted by the character _. There are also zero or more digits marked by the character X, meaning they're the same digit.

Mr. Chanek wants to count the number of possible integer $s$, where $s$ is divisible by $25$. Of course, $s$ must not contain any leading zero. He can replace the character _ with any digit. He can also replace the character X with any digit, but it must be the same for every character X.

As a note, a leading zero is any 0 digit that comes before the first nonzero digit in a number string in positional notation. For example, 0025 has two leading zeroes. An exception is the integer zero, (0 has no leading zero, but 0000 has three leading zeroes).

## Input

One line containing the string $s$ ($1 \leq |s| \leq 8$). The string $s$ consists of the characters 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, _, and X.

## Output

## Output

 an integer denoting the number of possible integer $s$.

## Examples

## Input


```

25

```
## Output


```

1

```
## Input


```

_00

```
## Output


```

9

```
## Input


```

_XX

```
## Output


```

9

```
## Input


```

0

```
## Output


```

1

```
## Input


```

0_25

```
## Output


```

0

```
## Note

In the first example, the only possible $s$ is $25$.

In the second and third example, $s \in \{100, 200,300,400,500,600,700,800,900\}$.

In the fifth example, all possible $s$ will have at least one leading zero.



#### tags 

#1800 #brute_force #dfs_and_similar #dp 