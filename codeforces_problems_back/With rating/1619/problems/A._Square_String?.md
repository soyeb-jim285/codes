<h1 style='text-align: center;'> A. Square String?</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A string is called square if it is some string written twice in a row. For example, the strings "aa", "abcabc", "abab" and "baabaa" are square. But the strings "aaa", "abaaab" and "abcdabc" are not square.

For a given string $s$ determine if it is square.

## Input

The first line of input data contains an integer $t$ ($1 \le t \le 100$) —the number of test cases.

This is followed by $t$ lines, each containing a description of one test case. The given strings consist only of lowercase Latin letters and have lengths between $1$ and $100$ inclusive.

## Output

For each test case, output on a separate line:

* YES if the string in the corresponding test case is square,
* NO otherwise.

You can output YES and NO in any case (for example, strings yEs, yes, Yes and YES will be recognized as a positive response).

## Example

## Input


```

10
a
aa
aaa
aaaa
abab
abcabc
abacaba
xxyy
xyyx
xyxy

```
## Output


```

NO
YES
NO
YES
YES
YES
NO
NO
NO
YES

```


#### tags 

#800 #implementation #strings 