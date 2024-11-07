<h1 style='text-align: center;'> A. String Building</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given a string $s$. You have to determine whether it is possible to build the string $s$ out of strings aa, aaa, bb and/or bbb by concatenating them. You can use the strings aa, aaa, bb and/or bbb any number of times and in any order.

For example:

* aaaabbb can be built as aa $+$ aa $+$ bbb;
* bbaaaaabbb can be built as bb $+$ aaa $+$ aa $+$ bbb;
* aaaaaa can be built as aa $+$ aa $+$ aa;
* abab cannot be built from aa, aaa, bb and/or bbb.
## Input

The first line contains one integer $t$ ($1 \le t \le 1000$) — the number of test cases.

Each test case consists of one line containing the string $s$ ($1 \le |s| \le 50$), consisting of characters a and/or b.

## Output

For each test case, print YES if it is possible to build the string $s$. Otherwise, print NO.

You may print each letter in any case (for example, YES, yes, Yes will all be recognized as positive answer, NO, no and nO will all be recognized as negative answer).

## Example

## Input


```

8aaaabbbbbaaaaabbbaaaaaaabababaaaabbbaaa
```
## Output


```

YES
YES
YES
NO
NO
NO
NO
YES

```
## Note

The first four test cases of the example are described in the statement.



#### tags 

#800 #implementation 