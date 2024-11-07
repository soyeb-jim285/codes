<h1 style='text-align: center;'> A. Spell Check</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Timur likes his name. As a spelling of his name, he allows any permutation of the letters of the name. For example, the following strings are valid spellings of his name: Timur, miurT, Trumi, mriTu. Note that the correct spelling must have uppercased T and lowercased other letters.

Today he wrote string $s$ of length $n$ consisting only of uppercase or lowercase Latin letters. He asks you to check if $s$ is the correct spelling of his name.

## Input

The first line of the input contains an integer $t$ ($1 \leq t \leq 10^3$) — the number of test cases.

The first line of each test case contains an integer $n$ $(1 \leq n \leq 10)$ — the length of string $s$.

The second line of each test case contains a string $s$ consisting of only uppercase or lowercase Latin characters.

## Output

For each test case, output "YES" (without quotes) if $s$ satisfies the condition, and "NO" (without quotes) otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).

## Example

## Input


```

105Timur5miurT5Trumi5mriTu5timur4Timr6Timuur10codeforces10TimurTimur5TIMUR
```
## Output


```

YES
YES
YES
YES
NO
NO
NO
NO
NO
NO

```


#### tags 

#800 #implementation 