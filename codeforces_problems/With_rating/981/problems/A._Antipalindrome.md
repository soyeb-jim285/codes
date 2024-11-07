<h1 style='text-align: center;'> A. Antipalindrome</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A string is a palindrome if it reads the same from the left to the right and from the right to the left. For example, the strings "kek", "abacaba", "r" and "papicipap" are palindromes, while the strings "abb" and "iq" are not.

A substring $s[l \ldots r]$ ($1 \leq l \leq r \leq |s|$) of a string $s = s_{1}s_{2} \ldots s_{|s|}$ is the string $s_{l}s_{l + 1} \ldots s_{r}$.

Anna does not like palindromes, so she makes her friends call her Ann. She also changes all the words she reads in a similar way. Namely, each word $s$ is changed into its longest substring that is not a palindrome. If all the substrings of $s$ are palindromes, she skips the word at all.

Some time ago Ann read the word $s$. What is the word she changed it into?

##### Input

The first line contains a non-empty string $s$ with length at most $50$ characters, containing lowercase English letters only.

##### Output

If there is such a substring in $s$ that is not a palindrome, print the maximum length of such a substring. Otherwise print $0$.

## Note

 that there can be multiple longest substrings that are not palindromes, but their length is unique.

## Examples

##### Input


```text
mew  

```
##### Output


```text
3  

```
##### Input


```text
wuffuw  

```
##### Output


```text
5  

```
##### Input


```text
qqqqqqqq  

```
##### Output


```text
0  

```
## Note

"mew" is not a palindrome, so the longest substring of it that is not a palindrome, is the string "mew" itself. Thus, the answer for the first example is $3$.

The string "uffuw" is one of the longest non-palindrome substrings (of length $5$) of the string "wuffuw", so the answer for the second example is $5$.

All substrings of the string "qqqqqqqq" consist of equal characters so they are palindromes. This way, there are no non-palindrome substrings. Thus, the answer for the third example is $0$.



#### Tags 

#900 #NOT OK #brute_force #implementation #strings 

## Blogs
- [All Contest Problems](../Avito_Code_Challenge_2018.md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial #1 (ru)](../blogs/Tutorial_1_(ru).md)
- [Tutorial #2 (en)](../blogs/Tutorial_2_(en).md)
- [Tutorial #3 (ru)](../blogs/Tutorial_3_(ru).md)
