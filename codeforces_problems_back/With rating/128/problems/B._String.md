<h1 style='text-align: center;'> B. String</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

One day in the IT lesson Anna and Maria learned about the lexicographic order.

String *x* is lexicographically less than string *y*, if either *x* is a prefix of *y* (and *x* ≠ *y*), or there exists such *i* (1 ≤ *i* ≤ *min*(|*x*|, |*y*|)), that *x**i* < *y**i*, and for any *j* (1 ≤ *j* < *i*) *x**j* = *y**j*. Here |*a*| denotes the length of the string *a*. The lexicographic comparison of strings is implemented by operator < in modern programming languages​​.

The teacher gave Anna and Maria homework. She gave them a string of length *n*. They should write out all substrings of the given string, including the whole initial string, and the equal substrings (for example, one should write out the following substrings from the string "aab": "a", "a", "aa", "ab", "aab", "b"). The resulting strings should be sorted in the lexicographical order. The cunning teacher doesn't want to check all these strings. That's why she said to find only the *k*-th string from the list. Help Anna and Maria do the homework.

## Input

The first line contains a non-empty string that only consists of small Latin letters ("a"-"z"), whose length does not exceed 105. The second line contains the only integer *k* (1 ≤ *k* ≤ 105).

## Output

Print the string Anna and Maria need — the *k*-th (in the lexicographical order) substring of the given string. If the total number of substrings is less than *k*, print a string saying "No such line." (without the quotes).

## Examples

## Input


```
aa  
2  

```
## Output


```
a  

```
## Input


```
abc  
5  

```
## Output


```
bc  

```
## Input


```
abab  
7  

```
## Output


```
b  

```
## Note

In the second sample before string "bc" follow strings "a", "ab", "abc", "b".



#### tags 

#2100 #brute_force #constructive_algorithms #hashing #implementation #string_suffix_structures #strings 