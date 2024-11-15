<h1 style='text-align: center;'> C. Cyclical Quest</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Some days ago, WJMZBMR learned how to answer the query "how many times does a string *x* occur in a string *s*" quickly by preprocessing the string *s*. But now he wants to make it harder.

So he wants to ask "how many consecutive substrings of *s* are cyclical isomorphic to a given string *x*". You are given string *s* and *n* strings *x**i*, for each string *x**i* find, how many consecutive substrings of *s* are cyclical isomorphic to *x**i*.

Two strings are called cyclical isomorphic if one can rotate one string to get the other one. 'Rotate' here means 'to take some consecutive chars (maybe none) from the beginning of a string and put them back at the end of the string in the same order'. For example, string "abcde" can be rotated to string "deabc". We can take characters "abc" from the beginning and put them at the end of "de".

## Input

The first line contains a non-empty string *s*. The length of string *s* is not greater than 106 characters.

The second line contains an integer *n* (1 ≤ *n* ≤ 105) — the number of queries. Then *n* lines follow: the *i*-th line contains the string *x**i* — the string for the *i*-th query. The total length of *x**i* is less than or equal to 106 characters.

In this problem, strings only consist of lowercase English letters.

## Output

For each query *x**i* print a single integer that shows how many consecutive substrings of *s* are cyclical isomorphic to *x**i*. Print the answers to the queries in the order they are given in the input.

## Examples

## Input


```
baabaabaaa  
5  
a  
ba  
baa  
aabaa  
aaba  

```
## Output


```
7  
5  
7  
3  
5  

```
## Input


```
aabbaa  
3  
aa  
aabb  
abba  

```
## Output


```
2  
3  
3  

```


#### tags 

#2700 #data_structures #string_suffix_structures #strings 