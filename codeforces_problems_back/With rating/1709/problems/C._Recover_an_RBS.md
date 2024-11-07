<h1 style='text-align: center;'> C. Recover an RBS</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A bracket sequence is a string containing only characters "(" and ")". A regular bracket sequence (or, shortly, an RBS) is a bracket sequence that can be transformed into a correct arithmetic expression by inserting characters "1" and "+" between the original characters of the sequence. For example:

* bracket sequences "()()" and "(())" are regular (the resulting expressions are: "(1)+(1)" and "((1+1)+1)");
* bracket sequences ")(", "(" and ")" are not.

There was an RBS. Some brackets have been replaced with question marks. Is it true that there is a unique way to replace question marks with brackets, so that the resulting sequence is an RBS?

## Input

The first line contains a single integer $t$ ($1 \le t \le 5 \cdot 10^4$) — the number of testcases.

The only line of each testcase contains an RBS with some brackets replaced with question marks. Each character is either '(', ')' or '?'. At least one RBS can be recovered from the given sequence.

The total length of the sequences over all testcases doesn't exceed $2 \cdot 10^5$.

## Output

For each testcase, print "YES" if the way to replace question marks with brackets, so that the resulting sequence is an RBS, is unique. If there is more than one way, then print "NO".

## Example

## Input


```

5(?))??????()???(?)()?)
```
## Output


```

YES
NO
YES
YES
NO

```
## Note

In the first testcase, the only possible original RBS is "(())".

In the second testcase, there are multiple ways to recover an RBS.

In the third and the fourth testcases, the only possible original RBS is "()".

In the fifth testcase, the original RBS can be either "((()()))" or "(())()()".



#### tags 

#1800 #constructive_algorithms #greedy #implementation #strings 