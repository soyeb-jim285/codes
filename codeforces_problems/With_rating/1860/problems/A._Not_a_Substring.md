<h1 style='text-align: center;'> A. Not a Substring</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A bracket sequence is a string consisting of characters '(' and/or ')'. A regular bracket sequence is a bracket sequence that can be transformed into a correct arithmetic expression by inserting characters '1' and '+' between the original characters of the sequence. For example:

* bracket sequences "()()" and "(())" are regular (they can be transformed into "(1)+(1)" and "((1+1)+1)", respectively);
* bracket sequences ")(", "(" and ")" are not regular.

You are given a bracket sequence $s$; let's define its length as $n$. Your task is to find a regular bracket sequence $t$ of length $2n$ such that $s$ does not occur in $t$ as a contiguous substring, or report that there is no such sequence.

### Input

The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases.

The only line of each test case contains a string $s$ ($2 \le |s| \le 50$), consisting of characters "(" and/or ")".

### Output

For each test case, print the answer to it. If there is no required regular bracket sequence, print NO in a separate line. Otherwise, print YES in the first line, and the required regular bracket sequence $t$ itself in the second line. If there are multiple answers — you may print any of them.

## Example

### Input


```text
4)((()()))()
```
### Output

```text

YES
(())
YES
()()()
NO
YES
()(()())

```


#### Tags 

#900 #NOT OK #constructive_algorithms #strings 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_153_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
