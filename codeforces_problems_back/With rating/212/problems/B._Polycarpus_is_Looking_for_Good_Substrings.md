<h1 style='text-align: center;'> B. Polycarpus is Looking for Good Substrings</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

We'll call string *s*[*a*, *b*] = *s**a**s**a* + 1... *s**b* (1 ≤ *a* ≤ *b* ≤ |*s*|) a substring of string *s* = *s*1*s*2... *s*|*s*|, where |*s*| is the length of string *s*.

The trace of a non-empty string *t* is a set of characters that the string consists of. For example, the trace of string "aab" equals {'a', 'b'}.

Let's consider an arbitrary string *s* and the set of its substrings with trace equal to *C*. We will denote the number of substrings from this set that are maximal by inclusion by *r*(*C*, *s*). Substring *s*[*a*, *b*] of length *n* = *b* - *a* + 1 belonging to some set is called maximal by inclusion, if there is no substring *s*[*x*, *y*] in this set with length greater than *n*, such that 1 ≤ *x* ≤ *a* ≤ *b* ≤ *y* ≤ |*s*|. Two substrings of string *s* are considered different even if they are equal but they are located at different positions of *s*.

Polycarpus got a challenging practical task on a stringology exam. He must do the following: given string *s* and non-empty sets of characters *C*1, *C*2, ..., *C**m*, find *r*(*C**i*, *s*) for each set *C**i*. Help Polycarpus to solve the problem as he really doesn't want to be expelled from the university and go to the army!

## Input

The first line contains a non-empty string *s* (1 ≤ |*s*| ≤ 106).

The second line contains a single integer *m* (1 ≤ *m* ≤ 104). Next *m* lines contain descriptions of sets *C**i*. The *i*-th line contains string *c**i* such that its trace equals *C**i*. It is guaranteed that all characters of each string *c**i* are different.

Note that *C**i* are not necessarily different. All given strings consist of lowercase English letters.

## Output

Print *m* integers — the *i*-th integer must equal *r*(*C**i*, *s*).

## Examples

## Input


```
aaaaa  
2  
a  
a  

```
## Output


```
1  
1  

```
## Input


```
abacaba  
3  
ac  
ba  
a  

```
## Output


```
1  
2  
4  

```


#### tags 

#2300 #bitmasks #hashing #implementation 