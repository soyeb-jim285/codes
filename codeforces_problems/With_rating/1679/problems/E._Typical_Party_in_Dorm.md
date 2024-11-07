<h1 style='text-align: center;'> E. Typical Party in Dorm</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Today is a holiday in the residence hall — Oleh arrived, in honor of which the girls gave him a string. Oleh liked the gift a lot, so he immediately thought up and offered you, his best friend, the following problem.

You are given a string $s$ of length $n$, which consists of the first $17$ lowercase Latin letters {$a$, $b$, $c$, $\ldots$, $p$, $q$} and question marks. And $q$ queries. Each query is defined by a set of pairwise distinct lowercase first $17$ letters of the Latin alphabet, which can be used to replace the question marks in the string $s$.

The answer to the query is the sum of the number of distinct substrings that are palindromes over all strings that can be obtained from the original string $s$ by replacing question marks with available characters. The answer must be calculated modulo $998\,244\,353$.

Pay attention! Two substrings are different when their start and end positions in the string are different. So, the number of different substrings that are palindromes for the string aba will be $4$: a, b, a, aba.

Consider examples of replacing question marks with letters. For example, from the string aba??ee when querying {$a$, $b$} you can get the strings ababaee or abaaaee but you cannot get the strings pizza,  abaee, abacaba, aba?fee, aba47ee, or abatree.

Recall that a palindrome is a string that reads the same from left to right as from right to left.

#### Input

The first line contains a single integer $n$ ($1 \le n \le 1\,000$) — the length of the string $s$.

The second line contains the string $s$, which consists of $n$ lowercase Latin letters and question marks. It is guaranteed that all letters in the string belong to the set {$a$, $b$, $c$, $\ldots$, $p$, $q$}.

The third line contains a single integer $q$ ($1 \le q \le 2 \cdot 10^5$) — the number of queries.

This is followed by $q$ lines, each containing a single line $t$ — a set of characters that can replace question marks ($1 \le |t| \le 17$). It is guaranteed that all letters in the string belong to the set {$a$, $b$, $c$, $\ldots$, $p$, $q$} and occur at most once.

#### Output

For each query print one number — the total numbers of palindromic substrings in all strings that can be obtained from the string $s$, modulo $998\,244\,353$.

## Examples

#### Input


```text
7
ab??aba
8
a
b
ab
abc
abcd
abcde
abcdef
abcdefg
```
#### Output


```text
14
13
55
105
171
253
351
465
```
#### Input


```text
11
???????????
6
abcdefghijklmnopq
ecpnkhbmlidgfjao
olehfan
codef
glhf
q
```
#### Output


```text
900057460
712815817
839861037
756843750
70840320
66
```
## Note

Consider the first example and the first query in it. We can get only one string as a result of replacing the question marks  — abaaaba. It has the following palindrome substrings: 

1. a  — substring [$1$; $1$].
2. b  — substring [$2$; $2$].
3. a  — substring [$3$; $3$].
4. a  — substring [$4$; $4$].
5. a  — substring [$5$; $5$].
6. b  — substring [$6$; $6$].
7. a  — substring [$7$; $7$].
8. aa  — substring [$3$; $4$].
9. aa  — substring [$4$; $5$].
10. aba  — substring [$1$; $3$].
11. aaa  — substring [$3$; $5$].
12. aba  — substring [$5$; $7$].
13. baaab  — substring [$2$; $6$].
14. abaaaba  — substring [$1$; $7$].

In the third request, we get 4 lines: abaaaba, abababa, abbaaba, abbbaba.



#### Tags 

#2400 #NOT OK #bitmasks #combinatorics #dp #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_791_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
