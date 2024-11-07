<h1 style='text-align: center;'> F. Substrings in a String</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given a string *s*, process *q* queries, each having one of the following forms:

* 1 *i* *c* — Change the *i*-th character in the string to *c*.
* 2 *l* *r* *y* — Consider the substring of *s* starting at position *l* and ending at position *r*. ## Output

 the number of times *y* occurs as a substring in it.
## Input

The first line of the input contains the string *s* (1 ≤ |*s*| ≤ 105) of lowercase English letters.

The second line contains an integer *q* (1 ≤ *q* ≤ 105)  — the number of queries to process.

The next *q* lines describe the queries and may have one of the following forms:

* 1 *i* *c* (1 ≤ *i* ≤ |*s*|)
* 2 *l* *r* *y* (1 ≤ *l* ≤ *r* ≤ |*s*|)

*c* is a lowercase English letter and *y* is a non-empty string consisting of only lowercase English letters.

The sum of |*y*| over all queries of second type is at most 105.

It is guaranteed that there is at least one query of second type.

All strings are 1-indexed.

|*s*| is the length of the string *s*.

## Output

For each query of type 2, output the required answer in a separate line.

## Examples

## Input


```
ababababa  
3  
2 1 7 aba  
1 5 c  
2 1 7 aba  

```
## Output


```
3  
1  

```
## Input


```
abcdcbc  
5  
2 1 7 bc  
1 4 b  
2 4 7 bc  
1 2 a  
2 1 4 aa  

```
## Output


```
2  
2  
1  

```
## Note

Consider the first sample case. Initially, the string aba occurs 3 times in the range [1, 7]. ## Note

 that two occurrences may overlap. 

After the update, the string becomes ababcbaba and now aba occurs only once in the range [1, 7].



#### tags 

#3000 #bitmasks #brute_force #data_structures #string_suffix_structures #strings 