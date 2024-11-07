<h1 style='text-align: center;'> A. Entertainment in MAC</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Congratulations, you have been accepted to the Master's Assistance Center! However, you were extremely bored in class and got tired of doing nothing, so you came up with a game for yourself.

You are given a string $s$ and an even integer $n$. There are two types of operations that you can apply to it:

1. Add the reversed string $s$ to the end of the string $s$ (for example, if $s = $ cpm, then after applying the operation $s = $ cpmmpc).
2. Reverse the current string $s$ (for example, if $s = $ cpm, then after applying the operation $s = $ mpc).

It is required to determine the lexicographically smallest$^{\dagger}$ string that can be obtained after applying exactly $n$ operations. ## Note

 that you can apply operations of different types in any order, but you must apply exactly $n$ operations in total.

$^{\dagger}$A string $a$ is lexicographically smaller than a string $b$ if and only if one of the following holds: 

* $a$ is a prefix of $b$, but $a \ne b$;
* in the first position where $a$ and $b$ differ, the string $a$ has a letter that appears earlier in the alphabet than the corresponding letter in $b$.
## Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 500$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single even integer $n$ ($2 \leq n \leq 10^9$) — the number of operations applied to the string $s$.

The second line of each test case contains a single string $s$ ($1 \leq |s| \leq 100$), consisting of lowercase English letters, — the string to which the operations are applied.

## Output

For each test case, output a single line — the lexicographically smallest string that can be obtained after applying exactly $n$ operations.

## Example

## Input


```

54cpm2grib10kupitimilablodarbuz1000000000capybara6abacaba
```
## Output


```

cpm
birggrib
kupitimilablodarbuz
arabypaccapybara
abacaba

```
## Note

In the first test case, you can apply the operation of the second type (i.e., reverse the string $s$) $4$ times. Then the string $s$ will remain equal to cpm.

In the second test case, you can do the following: 

* Apply the operation of the second type, after which $s$ will become equal to birg.
* Apply operation of the first type (i.e., add the reversed string $s$ to the end of the string $s$), after which $s$ will become equal to birggrib.


#### tags 

#800 #constructive_algorithms #strings 