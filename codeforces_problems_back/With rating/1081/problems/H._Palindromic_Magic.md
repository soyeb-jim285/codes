<h1 style='text-align: center;'> H. Palindromic Magic</h1>

<h5 style='text-align: center;'>time limit per test: 2.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

After learning some fancy algorithms about palindromes, Chouti found palindromes very interesting, so he wants to challenge you with this problem.

Chouti has got two strings $A$ and $B$. Since he likes [palindromes](https://en.wikipedia.org/wiki/Palindrome), he would like to pick $a$ as some non-empty palindromic substring of $A$ and $b$ as some non-empty palindromic substring of $B$. Concatenating them, he will get string $ab$.

Chouti thinks strings he could get this way are interesting, so he wants to know how many different strings he can get.

## Input

The first line contains a single string $A$ ($1 \le |A| \le 2 \cdot 10^5$).

The second line contains a single string $B$ ($1 \le |B| \le 2 \cdot 10^5$).

Strings $A$ and $B$ contain only lowercase English letters.

## Output

The first and only line should contain a single integer — the number of possible strings.

## Examples

## Input


```
aa  
aba  

```
## Output


```
6  

```
## Input


```
aaba  
abaa  

```
## Output


```
15  

```
## Note

In the first example, attainable strings are 

* "a" + "a" = "aa",
* "aa" + "a" = "aaa",
* "aa" + "aba" = "aaaba",
* "aa" + "b" = "aab",
* "a" + "aba" = "aaba",
* "a" + "b" = "ab".

In the second example, attainable strings are "aa", "aaa", "aaaa", "aaaba", "aab", "aaba", "ab", "abaa", "abaaa", "abaaba", "abab", "ba", "baa", "baba", "bb".

Notice that though "a"+"aa"="aa"+"a"="aaa", "aaa" will only be counted once.



#### tags 

#3500 #data_structures #hashing #strings 