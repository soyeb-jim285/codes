<h1 style='text-align: center;'> H. Modest Substrings</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

You are given two integers $l$ and $r$.

Let's call an integer $x$ modest, if $l \le x \le r$.

Find a string of length $n$, consisting of digits, which has the largest possible number of substrings, which make a modest integer. Substring having leading zeros are not counted. If there are many answers, find lexicographically smallest one.

If some number occurs multiple times as a substring, then in the counting of the number of modest substrings it is counted multiple times as well.

##### Input

The first line contains one integer $l$ ($1 \le l \le 10^{800}$).

The second line contains one integer $r$ ($l \le r \le 10^{800}$).

The third line contains one integer $n$ ($1 \le n \le 2\,000$).

##### Output

In the first line, print the maximum possible number of modest substrings.

In the second line, print a string of length $n$ having exactly that number of modest substrings.

If there are multiple such strings, print the lexicographically smallest of them.

## Examples

##### Input


```text
1
10
3
```
##### Output


```text
3
101
```
##### Input


```text
1
11
3
```
##### Output


```text
5
111
```
##### Input


```text
12345
12346
6
```
##### Output


```text
1
012345
```
## Note

In the first example, string «101» has modest substrings «1», «10», «1».

In the second example, string «111» has modest substrings «1» ($3$ times) and «11» ($2$ times).



#### Tags 

#3500 #NOT OK #dp #strings 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_1.md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
