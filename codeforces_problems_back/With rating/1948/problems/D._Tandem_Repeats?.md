<h1 style='text-align: center;'> D. Tandem Repeats?</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string $s$, consisting of lowercase Latin letters and/or question marks.

A tandem repeat is a string of an even length such that its first half is equal to its second half.

A string $a$ is a substring of a string $b$ if $a$ can be obtained from $b$ by the deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end.

Your goal is to replace each question mark with some lowercase Latin letter in such a way that the length of the longest substring that is a tandem repeat is maximum possible.

## Input

The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of testcases.

The only line of each testcase contains a string $s$ ($1 \le |s| \le 5000$), consisting only of lowercase Latin letters and/or question marks.

The total length of the strings over all testcases doesn't exceed $5000$. 

## Output

For each testcase, print a single integer — the maximum length of the longest substring that is a tandem repeat after you replace each question mark in the string with some lowercase Latin letter.

If it's impossible to make any tandem repeat substrings in the string, print $0$.

## Example

## Input


```

4zaabaabz?????code?????scodeforces
```
## Output


```

6
4
10
0

```


#### tags 

#1700 #brute_force #strings #two_pointers 