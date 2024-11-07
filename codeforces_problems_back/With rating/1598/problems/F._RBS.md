<h1 style='text-align: center;'> F. RBS</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

A bracket sequence is a string containing only characters "(" and ")". A regular bracket sequence (or, shortly, an RBS) is a bracket sequence that can be transformed into a correct arithmetic expression by inserting characters "1" and "+" between the original characters of the sequence. For example:

* bracket sequences "()()" and "(())" are regular (the resulting expressions are: "(1)+(1)" and "((1+1)+1)");
* bracket sequences ")(", "(" and ")" are not.

Let's denote the concatenation of two strings $x$ and $y$ as $x+y$. For example, "()()" $+$ ")(" $=$ "()())(".

You are given $n$ bracket sequences $s_1, s_2, \dots, s_n$. You can rearrange them in any order (you can rearrange only the strings themselves, but not the characters in them).

Your task is to rearrange the strings in such a way that the string $s_1 + s_2 + \dots + s_n$ has as many non-empty prefixes that are RBS as possible.

## Input

The first line contains a single integer $n$ ($1 \le n \le 20$).

Then $n$ lines follow, the $i$-th of them contains $s_i$ — a bracket sequence (a string consisting of characters "(" and/or ")". All sequences $s_i$ are non-empty, their total length does not exceed $4 \cdot 10^5$.

## Output

Print one integer — the maximum number of non-empty prefixes that are RBS for the string $s_1 + s_2 + \dots + s_n$, if the strings $s_1, s_2, \dots, s_n$ can be rearranged arbitrarily.

## Examples

## Input


```

2
(
)

```
## Output


```

1

```
## Input


```

4
()()())
(
(
)

```
## Output


```

4

```
## Input


```

1
(())

```
## Output


```

1

```
## Input


```

1
)(()

```
## Output


```

0

```
## Note

In the first example, you can concatenate the strings as follows: "(" $+$ ")" $=$ "()", the resulting string will have one prefix, that is an RBS: "()".

In the second example, you can concatenate the strings as follows: "(" $+$ ")" $+$ "()()())" $+$ "(" $=$ "()()()())(", the resulting string will have four prefixes that are RBS: "()", "()()", "()()()", "()()()()".

The third and the fourth examples contain only one string each, so the order is fixed.



#### tags 

#2400 #binary_search #bitmasks #brute_force #data_structures #dp 