<h1 style='text-align: center;'> B. William the Vigilant</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

 ![](images/924b49cb18b707c41afea87b86ad9e8ed7750b97.png) Before becoming a successful trader William got a university degree. During his education an interesting situation happened, after which William started to listen to homework assignments much more attentively. What follows is the correct formal description of the homework assignment:

You are given a string $s$ of length $n$ only consisting of characters "a", "b" and "c". There are $q$ queries of format ($pos, c$), meaning replacing the element of string $s$ at position $pos$ with character $c$. After each query you must output the minimal number of characters in the string, which have to be replaced, so that the string doesn't contain string "abc" as a substring. A valid replacement of a character is replacing it with "a", "b" or "c".

A string $x$ is a substring of a string $y$ if $x$ can be obtained from $y$ by deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end.

## Input

The first line contains two integers $n$ and $q$ $(1 \le n, q \le 10^5)$, the length of the string and the number of queries, respectively.

The second line contains the string $s$, consisting of characters "a", "b" and "c".

Each of the next $q$ lines contains an integer $i$ and character $c$ $(1 \le i \le n)$, index and the value of the new item in the string, respectively. It is guaranteed that character's $c$ value is "a", "b" or "c".

## Output

For each query output the minimal number of characters that would have to be replaced so that the string doesn't contain "abc" as a substring.

## Example

## Input


```

9 10
abcabcabc
1 a
1 b
2 c
3 a
4 b
5 c
8 a
9 b
1 c
4 a

```
## Output


```

3
2
2
2
1
2
1
1
1
0

```
## Note

Let's consider the state of the string after each query: 

1. $s =$ "abcabcabc". In this case $3$ replacements can be performed to get, for instance, string $s =$ "bbcaccabb". This string does not contain "abc" as a substring.
2. $s =$ "bbcabcabc". In this case $2$ replacements can be performed to get, for instance, string $s =$ "bbcbbcbbc". This string does not contain "abc" as a substring.
3. $s =$ "bccabcabc". In this case $2$ replacements can be performed to get, for instance, string $s =$ "bccbbcbbc". This string does not contain "abc" as a substring.
4. $s =$ "bcaabcabc". In this case $2$ replacements can be performed to get, for instance, string $s =$ "bcabbcbbc". This string does not contain "abc" as a substring.
5. $s =$ "bcabbcabc". In this case $1$ replacements can be performed to get, for instance, string $s =$ "bcabbcabb". This string does not contain "abc" as a substring.
6. $s =$ "bcabccabc". In this case $2$ replacements can be performed to get, for instance, string $s =$ "bcabbcabb". This string does not contain "abc" as a substring.
7. $s =$ "bcabccaac". In this case $1$ replacements can be performed to get, for instance, string $s =$ "bcabbcaac". This string does not contain "abc" as a substring.
8. $s =$ "bcabccaab". In this case $1$ replacements can be performed to get, for instance, string $s =$ "bcabbcaab". This string does not contain "abc" as a substring.
9. $s =$ "ccabccaab". In this case $1$ replacements can be performed to get, for instance, string $s =$ "ccabbcaab". This string does not contain "abc" as a substring.
10. $s =$ "ccaaccaab". In this case the string does not contain "abc" as a substring and no replacements are needed.


#### tags 

#1100 #implementation #strings 