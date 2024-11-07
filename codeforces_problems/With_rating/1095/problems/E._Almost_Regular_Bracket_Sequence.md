<h1 style='text-align: center;'> E. Almost Regular Bracket Sequence</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a bracket sequence $s$ consisting of $n$ opening '(' and closing ')' brackets.

A regular bracket sequence is a bracket sequence that can be transformed into a correct arithmetic expression by inserting characters '1' and '+' between the original characters of the sequence. For example, bracket sequences "()()", "(())" are regular (the resulting expressions are: "(1)+(1)", "((1+1)+1)"), and ")(" and "(" are not.

You can change the type of some bracket $s_i$. It means that if $s_i = $ ')' then you can change it to '(' and vice versa.

Your task is to calculate the number of positions $i$ such that if you change the type of the $i$-th bracket, then the resulting bracket sequence becomes regular.

###### Input

The first line of the input contains one integer $n$ ($1 \le n \le 10^6$) — the length of the bracket sequence.

The second line of the input contains the string $s$ consisting of $n$ opening '(' and closing ')' brackets.

###### Output

Print one integer — the number of positions $i$ such that if you change the type of the $i$-th bracket, then the resulting bracket sequence becomes regular.

## Examples

###### Input


```text
6
(((())
```
###### Output


```text
3
```
###### Input


```text
6
()()()
```
###### Output


```text
0
```
###### Input


```text
1
)
```
###### Output


```text
0
```
###### Input


```text
8
)))(((((
```
###### Output


```text
0
```


#### Tags 

#1900 #NOT OK #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_529_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
