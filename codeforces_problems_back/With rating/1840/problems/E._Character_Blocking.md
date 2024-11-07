<h1 style='text-align: center;'> E. Character Blocking</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two strings of equal length $s_1$ and $s_2$, consisting of lowercase Latin letters, and an integer $t$.

You need to answer $q$ queries, numbered from $1$ to $q$. The $i$-th query comes in the $i$-th second of time. Each query is one of three types: 

* block the characters at position $pos$ (indexed from $1$) in both strings for $t$ seconds;
* swap two unblocked characters;
* determine if the two strings are equal at the time of the query, ignoring blocked characters.

## Note

 that in queries of the second type, the characters being swapped can be from the same string or from $s_1$ and $s_2$.

## Input

The first line of the input contains a single integer $T$ ($1 \le T \le 10^4$) — the number of test cases.

Then follow the descriptions of the test cases.

The first line of each test case contains a string $s_1$ consisting of lowercase Latin letters (length no more than $2 \cdot 10^5$).

The second line of each test case contains a string $s_2$ consisting of lowercase Latin letters (length no more than $2 \cdot 10^5$).

The strings have equal length.

The third line of each test case contains two integers $t$ and $q$ ($1 \le t, q \le 2 \cdot 10^5$). The number $t$ indicates the number of seconds for which a character is blocked. The number $q$ corresponds to the number of queries.

Each of the next $q$ lines of each test case contains a single query. Each query is one of three types: 

* "$1\ \ \ pos$" — block the characters at position $pos$ in both strings for $t$ seconds;
* "$2\ \ \ 1/\;\!2\ \ \ pos_1\ \ \ 1/\;\!2\ \ \ pos_2$" — swap two unblocked characters. The second number in the query indicates the number of the string from which the first character for the swap is taken. The third number in the query indicates the position in that string of that character. The fourth number in the query indicates the number of the string from which the second character for the swap is taken. The fifth number in the query indicates the position in that string of that character;
* "$3$" — determine if the two strings are equal at the time of the query, ignoring blocked characters.

For queries of the first type, it is guaranteed that at the time of the query, the characters at position $pos$ are not blocked.

For queries of the second type, it is guaranteed that the characters being swapped are not blocked.

All values of $pos, pos_1, pos_2$ are in the range from $1$ to the length of the strings.

The sum of the values of $q$ over all test cases, as well as the total length of the strings $s_1$, does not exceed $2 \cdot 10^5$.

## Output

For each query of the third type, output "YES" if the two strings $s_1$ and $s_2$ are equal at the time of the query, ignoring blocked characters, and "NO" otherwise.

You can output each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes" and "YES" will be accepted as a positive answer.

## Example

## Input


```

2codeforcescodeblocks5 731 51 61 71 933coolclub2 52 1 2 2 32 2 2 2 41 233
```
## Output


```

NO
YES
NO
YES
NO

```
## Note

Let's look at the strings $s_1$ and $s_2$ after each of the $q$ queries. Blocked characters will be denoted in red.

First example input:

($codeforces$, $codeblocks$) $\rightarrow$ ($codeforces$, $codeblocks$) $\rightarrow$ ($code\color{red}{f}orces$, $code\color{red}{b}locks$) $\rightarrow$ ($code\color{red}{fo}rces$, $code\color{red}{bl}ocks$) $\rightarrow$ ($code\color{red}{for}ces$, $code\color{red}{blo}cks$) $\rightarrow$ ($code\color{red}{for}c\color{red}{e}s$, $code\color{red}{blo}c\color{red}{k}s$) $\rightarrow$ ($code\color{red}{for}c\color{red}{e}s$, $code\color{red}{blo}c\color{red}{k}s$) $\rightarrow$ ($codef\color{red}{or}c\color{red}{e}s$, $codeb\color{red}{lo}c\color{red}{k}s$)

Second example input:

($cool$, $club$) $\rightarrow$ ($cuol$, $clob$) $\rightarrow$ ($cuol$, $cbol$) $\rightarrow$ ($c\color{red}{u}ol$, $c\color{red}{b}ol$) $\rightarrow$ ($c\color{red}{u}ol$, $c\color{red}{b}ol$) $\rightarrow$ ($cuol$, $cbol$)



#### tags 

#1600 #data_structures #hashing #implementation 