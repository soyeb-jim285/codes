<h1 style='text-align: center;'> F. Clear the String</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string $s$ of length $n$ consisting of lowercase Latin letters. You may apply some operations to this string: in one operation you can delete some contiguous substring of this string, if all letters in the substring you delete are equal. For example, after deleting substring bbbb from string abbbbaccdd we get the string aaccdd.

Calculate the minimum number of operations to delete the whole string $s$.

## Input

The first line contains one integer $n$ ($1 \le n \le 500$) — the length of string $s$.

The second line contains the string $s$ ($|s| = n$) consisting of lowercase Latin letters.

## Output

## Output

 a single integer — the minimal number of operation to delete string $s$.

## Examples

## Input


```

5
abaca

```
## Output


```

3
```
## Input


```

8
abcddcba

```
## Output


```

4
```


#### tags 

#2000 #dp 