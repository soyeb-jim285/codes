<h1 style='text-align: center;'> C. Decreasing String</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Recall that string $a$ is lexicographically smaller than string $b$ if $a$ is a prefix of $b$ (and $a \ne b$), or there exists an index $i$ ($1 \le i \le \min(|a|, |b|)$) such that $a_i < b_i$, and for any index $j$ ($1 \le j < i$) $a_j = b_j$.

Consider a sequence of strings $s_1, s_2, \dots, s_n$, each consisting of lowercase Latin letters. String $s_1$ is given explicitly, and all other strings are generated according to the following rule: to obtain the string $s_i$, a character is removed from string $s_{i-1}$ in such a way that string $s_i$ is lexicographically minimal.

For example, if $s_1 = \mathrm{dacb}$, then string $s_2 = \mathrm{acb}$, string $s_3 = \mathrm{ab}$, string $s_4 = \mathrm{a}$.

After that, we obtain the string $S = s_1 + s_2 + \dots + s_n$ ($S$ is the concatenation of all strings $s_1, s_2, \dots, s_n$).

You need to output the character in position $pos$ of the string $S$ (i. e. the character $S_{pos}$).

## Input

The first line contains one integer $t$ — the number of test cases ($1 \le t \le 10^4$).

Each test case consists of two lines. The first line contains the string $s_1$ ($1 \le |s_1| \le 10^6$), consisting of lowercase Latin letters. The second line contains the integer $pos$ ($1 \le pos \le \frac{|s_1| \cdot (|s_1| +1)}{2}$). You may assume that $n$ is equal to the length of the given string ($n = |s_1|$).

Additional constraint on the input: the sum of $|s_1|$ over all test cases does not exceed $10^6$.

## Output

For each test case, print the answer — the character that is at position $pos$ in string $S$. Note that the answers between different test cases are not separated by spaces or line breaks.

## Example

## Input


```

3cab6abcd9x1
```
## Output


```

abx
```


#### tags 

#1600 #implementation #strings 