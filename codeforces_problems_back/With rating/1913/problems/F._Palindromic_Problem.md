<h1 style='text-align: center;'> F. Palindromic Problem</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given a string $s$ of length $n$, consisting of lowercase Latin letters.

You are allowed to replace at most one character in the string with an arbitrary lowercase Latin letter.

Print the lexicographically minimal string that can be obtained from the original string and contains the maximum number of palindromes as substrings. Note that if a palindrome appears more than once as a substring, it is counted the same number of times it appears.

The string $a$ is lexicographically smaller than the string $b$ if and only if one of the following holds: 

* $a$ is a prefix of $b$, but $a \ne b$;
* in the first position where $a$ and $b$ are different, the string $a$ contains a letter that appears earlier in the alphabet than the corresponding letter in $b$.
## Input

The first line contains one integer $n$ ($1 \leq n \leq 3 \cdot 10^5$) — the number of characters in the string.

The second line contains the string $s$ itself, consisting of exactly $n$ lowercase Latin letters.

## Output

In the first line, print one integer — the maximum number of palindromic substrings that can be obtained using the operation described in the statement at most once.

In the second line, print the string that can be obtained from $s$ and has the maximum possible number of palindromic substrings. If there are multiple answers, print the lexicographically smallest one.

## Examples

## Input


```

5aabaa
```
## Output


```

15
aaaaa

```
## Input


```

5aaaaa
```
## Output


```

15
aaaaa

```
## Input


```

4awoo
```
## Output


```

7
aooo

```


#### tags 

#2800 #binary_search #data_structures #hashing #string_suffix_structures #strings 