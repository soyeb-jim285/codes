<h1 style='text-align: center;'> G. Pumping Lemma</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

[Tanchiky & Siromaru - Crystal Gravity](https://soundcloud.com/messi-ola/crystal-gravity-tanchiky-vs)⠀You are given two strings $s$, $t$ of length $n$, $m$, respectively. Both strings consist of lowercase letters of the English alphabet.

Count the triples $(x, y, z)$ of strings such that the following conditions are true:

* $s = x+y+z$ (the symbol $+$ represents the concatenation);
* $t = x+\underbrace{ y+\dots+y }_{k \text{ times}} + z$ for some integer $k$.
## Input

The first line contains two integers $n$ and $m$ ($1 \leq n < m \leq 10^7$) — the length of the strings $s$ and $t$, respectively.

The second line contains the string $s$ of length $n$, consisting of lowercase letters of the English alphabet.

The third line contains the string $t$ of length $m$, consisting of lowercase letters of the English alphabet.

## Output

## Output

 a single integer: the number of valid triples $(x, y, z)$.

## Examples

## Input


```

4 8abcdabcbcbcd
```
## Output


```

1

```
## Input


```

3 5aaaaaaaa
```
## Output


```

5

```
## Input


```

12 16abbababacaababbababababacaab
```
## Output


```

8

```
## Note

In the first test case, the only valid triple is $(x, y, z) = (\texttt{"a"}, \texttt{"bc"}, \texttt{"d"})$. In fact, 

* $\texttt{"abcd"} = \texttt{"a"} + \texttt{"bc"} + \texttt{"d"}$;
* $\texttt{"abcbcbcd"} = \texttt{"a"} + \texttt{"bc"} + \texttt{"bc"} + \texttt{"bc"} + \texttt{"d"}$.

In the second test case, there are $5$ valid triples: 

* $(x, y, z) = (\texttt{""}, \texttt{"a"}, \texttt{"aa"})$;
* $(x, y, z) = (\texttt{""}, \texttt{"aa"}, \texttt{"a"})$;
* $(x, y, z) = (\texttt{"a"}, \texttt{"a"}, \texttt{"a"})$;
* $(x, y, z) = (\texttt{"a"}, \texttt{"aa"}, \texttt{""})$;
* $(x, y, z) = (\texttt{"aa"}, \texttt{"a"}, \texttt{""})$.

In the third test case, there are $8$ valid triples: 

* $(x, y, z) = (\texttt{"ab"}, \texttt{"ba"}, \texttt{"babacaab"})$;
* $(x, y, z) = (\texttt{"abb"}, \texttt{"ab"}, \texttt{"abacaab"})$;
* $(x, y, z) = (\texttt{"abba"}, \texttt{"ba"}, \texttt{"bacaab"})$;
* $(x, y, z) = (\texttt{"ab"}, \texttt{"baba"}, \texttt{"bacaab"})$;
* $(x, y, z) = (\texttt{"abbab"}, \texttt{"ab"}, \texttt{"acaab"})$;
* $(x, y, z) = (\texttt{"abb"}, \texttt{"abab"}, \texttt{"acaab"})$;
* $(x, y, z) = (\texttt{"abbaba"}, \texttt{"ba"}, \texttt{"caab"})$;
* $(x, y, z) = (\texttt{"abba"}, \texttt{"baba"}, \texttt{"caab"})$.


#### tags 

#3000 #hashing #strings 