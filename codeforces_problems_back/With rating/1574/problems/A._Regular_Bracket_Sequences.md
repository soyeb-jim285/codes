<h1 style='text-align: center;'> A. Regular Bracket Sequences</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

A bracket sequence is a string containing only characters "(" and ")". A regular bracket sequence is a bracket sequence that can be transformed into a correct arithmetic expression by inserting characters "1" and "+" between the original characters of the sequence. For example, bracket sequences "()()" and "(())" are regular (the resulting expressions are: "(1)+(1)" and "((1+1)+1)"), and ")(", "(" and ")" are not.

You are given an integer $n$. Your goal is to construct and print exactly $n$ different regular bracket sequences of length $2n$.

## Input

The first line contains one integer $t$ ($1 \le t \le 50$) — the number of test cases.

Each test case consists of one line containing one integer $n$ ($1 \le n \le 50$).

## Output

For each test case, print $n$ lines, each containing a regular bracket sequence of length exactly $2n$. All bracket sequences you output for a testcase should be different (though they may repeat in different test cases). If there are multiple answers, print any of them. It can be shown that it's always possible.

## Example

## Input


```

3
3
1
3

```
## Output


```

()()()
((()))
(()())
()
((()))
(())()
()(())

```


#### tags 

#800 #constructive_algorithms 