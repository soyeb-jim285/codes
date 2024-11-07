<h1 style='text-align: center;'> F. Entangled Substrings</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 mebibytes</h5>

Quantum entanglement is when two particles link together in a certain way no matter how far apart they are in space.You are given a string $s$. A pair of its non-empty substrings $(a, b)$ is called entangled if there is a (possibly empty) link string $c$ such that:

* Every occurrence of $a$ in $s$ is immediately followed by $cb$;
* Every occurrence of $b$ in $s$ is immediately preceded by $ac$.

In other words, $a$ and $b$ occur in $s$ only as substrings of $acb$. Compute the total number of entangled pairs of substrings of $s$.

A string $a$ is a substring of a string $b$ if $a$ can be obtained from $b$ by the deletion of several (possibly zero or all) characters from the beginning and several (possibly zero or all) characters from the end.

###### Input

The first and only line contains a string $s$ of lowercase English letters ($1 \leq |s| \leq 10^5$) — the string for which you should count pairs of entangled substrings.

###### Output

###### Output

 a single integer, the number of entangled pairs of substrings of $s$.

## Examples

###### Input


```text
abba
```
###### Output


```text
1
```
###### Input


```text
abacaba
```
###### Output


```text
0
```
###### Input


```text
abcabcabcabc
```
###### Output


```text
5
```
###### Input


```text
adamant
```
###### Output


```text
82
```
## Note

In the first example, the only entangled pair is (ab,ba). For this pair, the corresponding link string $c$ is empty, as they only occur as substrings of the whole string abba, which doesn't have any characters between ab and ba.

In the second example, there are no entangled pairs.

In the third example, the entangled pairs are (a,b), (b,c), (a,c), (a,bc), and (ab,c). For most pairs, the corresponding link string $c$ is empty, except for the pair (a,c), for which the link string $c$ is b, as a and c only occur as substrings of the string abc.



#### Tags 

#3500 #NOT OK #string_suffix_structures #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_869_(Div._1).md)
- [Codeforces Round #869 (en)](../blogs/Codeforces_Round_869_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
