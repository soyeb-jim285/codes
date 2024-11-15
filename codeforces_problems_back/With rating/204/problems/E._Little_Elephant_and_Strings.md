<h1 style='text-align: center;'> E. Little Elephant and Strings</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The Little Elephant loves strings very much. 

He has an array *a* from *n* strings, consisting of lowercase English letters. Let's number the elements of the array from 1 to *n*, then let's denote the element number *i* as *a**i*. For each string *a**i* (1 ≤ *i* ≤ *n*) the Little Elephant wants to find the number of pairs of integers *l* and *r* (1 ≤ *l* ≤ *r* ≤ |*a**i*|) such that substring *a**i*[*l*... *r*] is a substring to at least *k* strings from array *a* (including the *i*-th string).

Help the Little Elephant solve this problem.

If you are not familiar with the basic notation in string problems, you can find the corresponding definitions in the notes.

## Input

The first line contains two space-separated integers — *n* and *k* (1 ≤ *n*, *k* ≤ 105). Next *n* lines contain array *a*. The *i*-th line contains a non-empty string *a**i*, consisting of lowercase English letter. The total length of all strings *a**i* does not exceed 105.

## Output

On a single line print *n* space-separated integers — the *i*-th number is the answer for string *a**i*.

Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

## Examples

## Input


```
3 1  
abc  
a  
ab  

```
## Output


```
6 1 3   

```
## Input


```
7 4  
rubik  
furik  
abab  
baba  
aaabbbababa  
abababababa  
zero  

```
## Output


```
1 0 9 9 21 30 0   

```
## Note

Let's assume that you are given string *a* = *a*1*a*2... *a*|*a*|, then let's denote the string's length as |*a*| and the string's *i*-th character as *a**i*.

A substring *a*[*l*... *r*] (1 ≤ *l* ≤ *r* ≤ |*a*|) of string *a* is string *a**l**a**l* + 1... *a**r*.

String *a* is a substring of string *b*, if there exists such pair of integers *l* and *r* (1 ≤ *l* ≤ *r* ≤ |*b*|), that *b*[*l*... *r*] = *a*.



#### tags 

#2800 #data_structures #implementation #string_suffix_structures #two_pointers 